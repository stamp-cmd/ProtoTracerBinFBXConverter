# BinaryFBXProtoTracerConverter
[**BRANCH: DEBUGGABLE**] Converts Binary FBX files (in native python) to ProtoTracer compatible blendshape file.
## FBX Model requirements:
- The model **must** be triangulated.
- The file **must** only contain one mesh, or multiple meshes grouped into one.

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

## Info:
### Supported version
FBX Version 7+
### Implementation
FBX Parser: based on [Blender Developer's Blog.](https://code.blender.org/2013/08/fbx-binary-file-format-specification)
Converter: based on [Prototracer-Helper](https://github.com/coelacant1/ProtoTracer-Helpers/tree/main/FBX-Converter)
