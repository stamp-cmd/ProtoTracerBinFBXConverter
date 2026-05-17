# BinaryFBXProtoTracerConverter
[**BRANCH: DEBUGGABLE**. If things break switch to [main branch](https://github.com/stamp-cmd/ProtoTracerBinFBXConverter/tree/main) ]

Converts Binary FBX files (in native python) to ProtoTracer compatible blendshape file.
## FBX Model requirements:
> [!WARNING]
> The model **must** be triangulated.
> 
> The file **must** only contain one mesh, or multiple meshes grouped into one.

> [!TIP]
> Face mesh **should** be under 100 triangles
>
> Recommend workflow is to try to modify NukudeFaceFlat to your liking.

## Instruction:
1. Clone the repository
2. Open `Converter.py`
3. Edit the `name` variable to the FBX file's name
4. Put the FBX file in `Example` folder. Or change `origFileName` to match your fbx file directory
5. Change the `outputName` to
```python
outputName = f"{name}.h" #If your FBX converter folder isn't next to prototracer folder.
```
6. Run
```bash
python Converter.py
```
7. Place the converted file (.h file) inside `/ProtoTracer/lib/ProtoTracer/Assets/Models/FBX/`
8. open `/ProtoTracer/lib/ProtoTracer/Examples/Protogen/ProtogenHUB75Project.h` or `/ProtoTracer/lib/ProtoTracer/Examples/Protogen/ProtogenWS35Project.h` and replace all `NukudeFace` with name of your file
10. change line 5 to
```c
#include "../../Assets/Models/FBX/<filename>.h"
```
> Special thanks to smoluwu for instruction >w<

## Python version
\>= 3.11 (recommended 3.13+)

## Config options
### IGNORE_ERROR
Inside `B_FBXReader.py`. Ignore multiple meshes error and non-triangulated mesh error.

### DONT_USE_POINTERS
Inside `MorphCreator.py`. Change header file from
```cpp
type* Name = new type[SIZE] {}; // from
type Name[SIZE] = {}; // to
```

## Basic converter troubleshooting
### ValueError: !!!MESH NOT TRIANGULATED. MESH: \<Name\>!!!
Triangulate the model.

### ValueError: !!!MULTIPLE MESH DETECTED. MESH: \<Name\>!!!
Join all the mesh to a single mesh.

## Basic model troubleshooting
*Assuming out of the box Prototracer code*

### Very thin line, small dot
#### Export orientation
Make sure you export your FBX file with correct orientation.

Blender default FBX export setting:
 - Scale: 1.00
 - Apply Scalings: All Local
 - Forward: -Z Forward
 - Up: Y Up
 - [x] Apply Unit
 - [x] Use Space Transform
 - [ ] Apply Transform

Default NukudeFaceFlat is on XY Plane, with Z-axis points at you 

#### Model bounds
Prototracer automatically scale face to fit the screen. If there are something larger than the actual face, it might scale the face down.

Check you model bound by selecting your mesh, and going to Object Properties (orange square one).
Go to Viewport Display, and check the "Bounds" option, make sure it is selected as "Box".
Then you'll see a wireframe box, make sure it actually fits the model.

*I don't have actual hardware that can run prototracer, so I cannot test all edge cases sadly.*

## Info:
### Supported version
FBX Version 7+
### Implementation
FBX Parser: based on [Blender Developer's Blog](https://code.blender.org/2013/08/fbx-binary-file-format-specification)

Converter: based on [Prototracer-Helper](https://github.com/coelacant1/ProtoTracer-Helpers/tree/main/FBX-Converter)
