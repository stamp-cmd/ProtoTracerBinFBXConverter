# BinaryFBXProtoTracerConverter
Converts Binary FBX files (in native python) to ProtoTracer compatible blendshape files

## Info:
### Supported version
FBX Version 7.4 (7400). Version 7.5 not tested but possible by setting `NODE_UINT_BYTE` to
```python
NODE_UINT_BYTE = ("Q", 8) # Change struct type to double (uses 8 bytes)
```
### Implementation
Based on [Blender Developer's Blog](https://code.blender.org/2013/08/fbx-binary-file-format-specification/)
