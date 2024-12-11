# NON-COMPLIANT PROTOTRACER BINARY FBX PARSER

import struct
import zlib

# PROTOTRACER CLASS
class Vector3D:
    X: int
    Y: int
    Z: int

class Triangle:
    A: int = 1
    B: int = 2
    C: int = 3

class Object3D:
    # Removed unused `ObjectParameters` class
    VertexCount: int
    TriangleCount: int
    Vertices: list
    Triangles: list

class ShapeKey:
    Name: str
    IndexCount: int
    VertexCount: int
    Indexes = list
    Vertices = list

class MorphObject:
    name: str
    baseMesh: Object3D
    shapeKeys: list

# PARSER CLASS
class Node:
    end_offset: int
    num_properties: int
    property_list_len: int
    name: bytearray
    def is_null(self) -> bool:
        return self.end_offset + self.num_properties + self.property_list_len + len(self.name) == 0

# THE PIPELINE
def GetMorphObject(file: str, name: str, scale: float):
    NODE_UINT_BYTE = ("I", 4)
    morph = MorphObject()
    with open(file, "rb") as file:
        def read_node() -> Node:
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

        def find_node(name: bytearray) -> Node:
            current_node = read_node()
            while current_node.name != name:
                if current_node.is_null():
                    return None
                else:
                    file.seek(current_node.end_offset)
                    current_node = read_node()
            return current_node

        def get_content(byte: int):
            array_len, encoding, compressed_len = struct.unpack("<3I", file.read(12))
            content = b""
            if encoding == 1:
                content = zlib.decompress(file.read(compressed_len))
            else:
                content = file.read(array_len * byte)
            return (array_len, content)

        def read_prop():
            type_code = file.read(1).decode("ascii")
            if type_code == "L":
                return struct.unpack("<Q", file.read(8))[0]
            elif type_code == "S":
                str_len = struct.unpack("<I", file.read(4))[0]
                return file.read(str_len)
            elif type_code == "d":
                array = get_content(8)
                return list(struct.unpack(f"<{array[0]}d", array[1]))
            elif type_code == "i":
                array = get_content(4)
                return list(struct.unpack(f"<{array[0]}i", array[1]))
            else:
                raise NotImplementedError(f"!!!TYPE CODE NOT IMPLEMENTED.TYPE CODE: \"{type_code}\"!!!")

        def get_nodes_prop(nodes):
            out = {}
            current_node = read_node()
            while not current_node.is_null():
                if current_node.name in nodes:
                    out[nodes.index(current_node.name)] = read_prop()
                file.seek(current_node.end_offset)
                current_node = read_node()
            return out

        magic = file.read(23)
        if magic != b"Kaydara FBX Binary  \x00\x1A\x00":
            raise ValueError("!!!FILE MAGIC HEADER IS NOT BINARY FBX FILE!!!")
        version = struct.unpack("<I", file.read(4))[0]
        if version > 7400:
            NODE_UINT_BYTE = ("Q", 8)
            print("===USING UINT64 [VERSION >7.4]===")
        elif version < 7000:
            raise NotImplementedError(f"!!!FBX VERSION {version} IS UNSUPPORTED, UPGRADE TO VERSION 7.4!!!")

        shape_keys = []
        base_mesh = Object3D()
        find_node(b"Objects")
        geometry_node = find_node(b"Geometry")
        while geometry_node:
            infos = []
            for _ in range(geometry_node.num_properties):
                infos.append(read_prop())
            if b"Mesh" in infos:
                props = get_nodes_prop([b"Vertices", b"PolygonVertexIndex"])
                vertices = []
                triangles = []

                for i in range(0, len(props[0]), 3):
                    vertex = Vector3D()
                    vertex.X, vertex.Y, vertex.Z = (
                        props[0][i] * scale, props[0][i+1] * scale, props[0][i+2] * scale
                    )
                    print(f"Vertex: [{vertex.X}, {vertex.Y}, {vertex.Z}]")
                    vertices.append(vertex)
                for i in range(0, len(props[1]), 3):
                    triangle = Triangle()
                    triangle.A, triangle.B, triangle.C = (
                        props[1][i], props[1][i+1], (props[1][i+2] * -1) - 1
                    )
                    print(f"Triangle Vertex Indexes: [{triangle.A}, {triangle.B}, {triangle.C}]")
                    triangles.append(triangle)

                base_mesh.TriangleCount, base_mesh.Triangles = (len(triangles), triangles)
                base_mesh.VertexCount, base_mesh.Vertices = (len(props[0]), vertices)
                print(f"Primary mesh contains {base_mesh.VertexCount} vertices and {base_mesh.TriangleCount} triangles.\nCreated primary mesh.")
            elif b"Shape" in infos:
                shape_key = ShapeKey()
                shape_key.Name = list(
                    filter(lambda i: isinstance(i, bytes) and b"\x00\x01Geometry" in i, infos)
                    )[0][:-10].decode("utf-8")
                props = get_nodes_prop([b"Indexes", b"Vertices"])
                vertices = []

                for i in range(0, len(props[1]), 3):
                    vertex = Vector3D()
                    vertex.X, vertex.Y, vertex.Z = (
                        props[1][i] * scale, props[1][i+1] * scale, props[1][i+2] * scale
                    )
                    vertices.append(vertex)
                    print(f"Vertex: [{vertex.X}, {vertex.Y}, {vertex.Z}]")

                shape_key.IndexCount = len(props[0])
                shape_key.Indexes = props[0]
                shape_key.VertexCount = len(props[1])
                shape_key.Vertices = vertices
                shape_keys.append(shape_key)
                print(f"Created shape key \"{shape_key.Name}\" with {shape_key.IndexCount} modified" +
                f"indices and {shape_key.VertexCount} modified vertex values.")
            file.seek(geometry_node.end_offset)
            geometry_node = find_node(b"Geometry")
        print(f"Created {len(shape_keys)} shape keys.")
        morph.name = name
        morph.baseMesh = base_mesh
        morph.shapeKeys = shape_keys
    return morph
