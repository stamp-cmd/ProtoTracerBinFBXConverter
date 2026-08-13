# NON-COMPLIANT PROTOTRACER BINARY FBX PARSER

import struct
import zlib
from typing import TypeAlias
from collections.abc import Iterable

PROPS_TYPE: TypeAlias = int | str | list[int] | list[float]

# PROTOTRACER CLASS
class Vector3D:
    def __init__(self):
        self.X = 0
        self.Y = 0
        self.Z = 0

    X: float
    Y: float
    Z: float

class Triangle:
    A: int = 1
    B: int = 2
    C: int = 3

class Object3D:
    def __init__(self):
        self.VertexCount = 0
        self.TriangleCount = 0
        self.Vertices = []
        self.Triangles = []

    # Removed unused `ObjectParameters` class
    VertexCount: int
    TriangleCount: int
    Vertices: list[Vector3D]
    Triangles: list[Triangle]

class ShapeKey:
    def __init__(self):
        self.Name = ""
        self.IndexCount = 0
        self.Indexes = []
        self.VertexCount = 0
        self.Vertices = []

    Name: str
    IndexCount: int
    VertexCount: int
    Indexes: list[int]
    Vertices: list[Vector3D]

class MorphObject:
    def __init__(self):
        self.name = ""
        self.baseMesh = Object3D()
        self.shapeKeys = []

    name: str
    baseMesh: Object3D
    shapeKeys: list[ShapeKey]

# PARSER CLASS
class Node:
    def __init__(self):
        self.end_offset = 0
        self.num_properties = 0
        self.property_list_len = 0
        self.name = b""

    end_offset: int
    num_properties: int
    property_list_len: int
    name: bytes
    def is_null(self) -> bool:
        # NULL Record
        return self.end_offset + self.num_properties + self.property_list_len + len(self.name) == 0

IGNORE_ERROR = False
BOUND_SIZE = False

""" Brief FBX structure. ImHex can help visualize FBX file structure.
FBX
├── header
│   ├── magic
│   └── version
└── rootRecords
    ├── ... Nodes
    ├── Node: Objects
    │   ├── Node: Geometry
    │   │   ├── Prop: ... (Geometry ID)
    │   │   ├── Prop: "<Name>\x00\x01Geometry"
    │   │   └── Prop: Type (Mesh / Shape)
    │   │       ├── Mesh
    │   │       │   ├── Prop: Vertices
    │   │       │   └── Prop: PolygonVertexIndex
    │   │       └── Shape
    │   │           ├── Prop: Indexes
    │   │           └── Prop: Vertices
    │   ├── Node: Model
    │   │   ├── Prop: Model ID
    │   │   ├── Prop: "<Name>\x00\x01Model"
    │   │   └── Prop: Type (Mesh)
    │   └── ... Nodes
    └── Node: Connections
        └── Node: ... "C"
            ├── Prop: ... "OO"
            ├── Prop: Model ID
            └── Prop: Parent ID
(... means don't care)
"""


# THE PIPELINE
def GetMorphObject(filename: str, name: str, scale: float):
    NODE_UINT_BYTE = ("I", 4)
    morph = MorphObject()

    min_x = min_y = min_z = float("inf")
    max_x = max_y = max_z = float("-inf")

    with open(filename, "rb") as file:
        def read_node() -> Node:
            """Deserialize bytes to Node class. Stop reading before properties section.

            Returns: Node (on current position)"""
            node = Node()
            node.end_offset, node.num_properties, node.property_list_len = struct.unpack(
                f"<3{NODE_UINT_BYTE[0]}", file.read(3 * NODE_UINT_BYTE[1])
            )
            str_len = struct.unpack("<B", file.read(1))[0]
            if str_len == 0:
                node.name = b""
            else:
                node.name = file.read(str_len)
            return node

        def find_node(name: bytes) -> Node | None:
            """Linear searching for Node with same name.
            
            Returns: Node (with matching name)"""
            current_node = read_node()
            while current_node.name != name:
                if current_node.is_null():
                    return None
                else:
                    _ = file.seek(current_node.end_offset)
                    current_node = read_node()
            return current_node

        def get_array(byte: int) -> tuple[int, bytes]:
            """Deserialize bytes (and decompress) to list.

            Returns: tuple[int (array size), bytes (raw array bytes)]"""
            array_len, encoding, compressed_len = struct.unpack("<3I", file.read(4 * 3))
            content = b""
            if encoding == 1:
                content = zlib.decompress(file.read(compressed_len))
            else:
                content = file.read(array_len * byte)
            return (array_len, content)

        def read_prop() -> PROPS_TYPE:
            """Read a single property. Determined by first byte.
            
            Returns: PROPS_TYPE (single property of current node, after read_node())"""
            type_code = file.read(1).decode("ascii")
            if type_code == "L":
                return struct.unpack("<q", file.read(8))[0]
            elif type_code == "S":
                str_len = struct.unpack("<I", file.read(4))[0]
                return file.read(str_len).decode("ascii")
            elif type_code == "d":
                array = get_array(8)
                return list(struct.unpack(f"<{array[0]}d", array[1]))
            elif type_code == "i":
                array = get_array(4)
                return list(struct.unpack(f"<{array[0]}i", array[1]))
            else:
                raise NotImplementedError(f"!!!TYPE CODE NOT IMPLEMENTED.TYPE CODE: \"{type_code}\"!!!")

        def get_nodes_prop(nodes: list[bytes]) -> dict[int, PROPS_TYPE]:
            """Get a single property insside node, for each node inside nodes list. \\
            Used for extracting properties array of vertices and indexes node.

            Returns: dict[int (node index based on list of names), PROPS_TYPE (single property of matching node)]
            """
            out: dict[int, PROPS_TYPE] = {}
            current_node = read_node()
            while not current_node.is_null():
                if current_node.name in nodes:
                    out[nodes.index(current_node.name)] = read_prop()
                _ = file.seek(current_node.end_offset)
                current_node = read_node()
            return out

        magic = file.read(23)
        if magic != b"Kaydara FBX Binary  \x00\x1A\x00":
            raise ValueError("!!!FILE MAGIC HEADER IS NOT BINARY FBX FILE!!!")
        version = struct.unpack("<I", file.read(4))[0]
        if version >= 7500:
            # FBX version 7.5 uses 24 (instead of 12) bytes for Node's EndOffset, NumsProperties, PropertyLenList
            # https://code.blender.org/2013/08/fbx-binary-file-format-specification/#comment-86500
            NODE_UINT_BYTE = ("Q", 8)
        elif version < 7000:
            raise NotImplementedError(f"!!!FBX VERSION {version} IS UNSUPPORTED, UPGRADE TO VERSION >7!!!")

        models_id: list[int] = []
        models_name: list[str] = []
        rooted = False

        shape_keys: list[ShapeKey] = []
        base_mesh = Object3D()

        _ = find_node(b"Objects")
        object_node = read_node()
        while not object_node.is_null():
            infos: list[str | int] = []
            if object_node.name == b"Geometry":
                for _ in range(object_node.num_properties):
                    _p: PROPS_TYPE = read_prop()
                    assert isinstance(_p, str) or isinstance(_p, int)
                    infos.append(_p)
                
                # Read the primary mesh data
                assert isinstance(infos[2], str)
                if infos[2] == "Mesh":
                    props = get_nodes_prop([b"Vertices", b"PolygonVertexIndex"])
                    vertices: list[Vector3D] = []
                    triangles: list[Triangle] = []
                    assert isinstance(props[0], list) # Pyright stuff
                    for i in range(0, len(props[0]), 3):
                        vertex = Vector3D()
                        vertex.X, vertex.Y, vertex.Z = (
                            props[0][i] * scale, props[0][i+1] * scale, props[0][i+2] * scale
                        )

                        if BOUND_SIZE:
                            min_x = min(props[0][i] * scale, min_x)
                            min_y = min(props[0][i + 1] * scale, min_y)
                            max_z = max(props[0][i + 2] * scale, max_z)
                            max_x = max(props[0][i] * scale, max_x)
                            max_y = max(props[0][i + 1] * scale, max_y)
                            max_z = max(props[0][i + 2] * scale, max_z)

                        print(f"Vertex: [{vertex.X}, {vertex.Y}, {vertex.Z}]")
                        vertices.append(vertex)

                    assert isinstance(props[1], list)
                    assert isinstance(infos[1], str)
                    for i in range(0, len(props[1]), 3):
                        triangle = Triangle()
                        try:
                            triangle.A, triangle.B, triangle.C = (
                                int(props[1][i]), int(props[1][i+1]), int((props[1][i+2] * -1) - 1)
                            )
                        # Detection by IndexError, Index indivisible by 3
                        except IndexError as e:
                            raise ValueError(f"!!!MESH NOT TRIANGULATED. MESH: {infos[1][:-10]}!!!") from e
                        
                        # Dectection by non-negative last vertex (+, +, -)
                        if (not (triangle.A > -1 and triangle.B > -1 and triangle.C > -1)) and (not IGNORE_ERROR):
                            raise ValueError(f"!!!MESH NOT TRIANGULATED. MESH: {infos[1][:-10]}!!!")
                        print(f"Triangle Vertex Indexes: [{triangle.A}, {triangle.B}, {triangle.C}]")
                        triangles.append(triangle)

                    base_mesh.TriangleCount, base_mesh.Triangles = (len(triangles), triangles)
                    base_mesh.VertexCount, base_mesh.Vertices = (len(props[0]), vertices)
                    print(f"Primary mesh contains {base_mesh.VertexCount} vertices and {base_mesh.TriangleCount} triangles.\nCreated primary mesh.")

                # Read mesh's shape key data
                elif infos[2] == "Shape":
                    shape_key = ShapeKey()
                    # shape_key name probably lived in static field
                    # Parse name
                    shape_key.Name = list(filter(lambda i: isinstance(i, str) and "\x00\x01Geometry" in i, infos))[0][:-10]
                    props = get_nodes_prop([b"Indexes", b"Vertices"])
                    vertices = []

                    assert isinstance(props[0], list)
                    assert isinstance(props[1], list)
                    for i in range(0, len(props[1]), 3):
                        vertex = Vector3D()
                        vertex.X, vertex.Y, vertex.Z = (
                            props[1][i] * scale, props[1][i+1] * scale, props[1][i+2] * scale
                        )
                        vertices.append(vertex)
                        if BOUND_SIZE:
                            min_x = min(props[1][i] * scale, min_x)
                            min_y = min(props[1][i + 1] * scale, min_y)
                            min_z = min(props[1][i + 2] * scale, min_z)
                            max_x = max(props[1][i] * scale, max_x)
                            max_y = max(props[1][i + 1] * scale, max_y)
                            max_z = max(props[1][i + 2] * scale, max_z)
                        print(f"Vertex: [{vertex.X}, {vertex.Y}, {vertex.Z}]")

                    shape_key.IndexCount = len(props[0])
                    shape_key.Indexes = props[0]
                    shape_key.VertexCount = len(props[1])
                    shape_key.Vertices = vertices
                    shape_keys.append(shape_key)
                    print(f"Created shape key \"{shape_key.Name}\" with {shape_key.IndexCount} modified" +
                    f"indices and {shape_key.VertexCount} modified vertex values.")

            # Read list of model ID's and name. This was added to detect if there are multiple object.
            # Model's name is only used for debugging.
            elif object_node.name == b"Model":
                model_props: list[int | str] = []
                for i in range(object_node.num_properties):
                    _p: PROPS_TYPE = read_prop()
                    assert isinstance(_p, int) or isinstance(_p, str)
                    model_props.append(_p)
                if isinstance(model_props[2], str) and model_props[2] == "Mesh":
                    assert isinstance(model_props[0], int)
                    assert isinstance(model_props[1], str)
                    models_id.append(model_props[0])
                    models_name.append(model_props[1])
            _ = file.seek(object_node.end_offset)
            object_node = read_node()
        
        # Check if multiple geometry is connected to root (Id: 0)
        _ = find_node(b"Connections")
        conn_node = read_node()
        while not conn_node.is_null():
            conn_props: list[int | str] = []
            for i in range(conn_node.num_properties):
                _p: PROPS_TYPE = read_prop()
                assert isinstance(_p, int) or isinstance(_p, str)
                conn_props.append(_p)
            # If recorded mesh is connected to root
            if (conn_props[1] in models_id) and (conn_props[2] == 0):
                if not rooted:
                    rooted = True
                elif not IGNORE_ERROR:
                    raise ValueError("!!!MULTIPLE MESH DETECTED. MESH: \""
                    + models_name[models_id.index(conn_props[1])][:-7] + "\"!!!")
            conn_node = read_node()
        print(f"Created {len(shape_keys)} shape keys.")

        OFFSET = 1
        STOP = 8
        # OFFSET: 1, STOP 8 | For all corner of 3D bounding box
        # OFFSET: 7, STOP: 8 |  For generating top-left-front vertex and bottom-right-back vertex
        # OFFSET: 1, STOP: 4 |  For generating vertices from top-left-front to bottom-right-front. (i.e. a plane with z = z_max) 

        if BOUND_SIZE:
            # Add bounding box vertices, using bitwise to decide between min/max
            for i in range(0, STOP, OFFSET):
                vtx = Vector3D()
                vtx.X = [min_x, max_x][i & 1]
                vtx.Y = [min_y, max_y][(i & 2) >> 1]
                vtx.Z = [max_z, min_z][(i & 4) >> 2]
                base_mesh.Vertices.append(vtx)
            base_mesh.VertexCount += 24 - 3 * OFFSET + 3 # MorphCreator divide by 3

        morph.name = name
        morph.baseMesh = base_mesh
        morph.shapeKeys = shape_keys
    return morph
