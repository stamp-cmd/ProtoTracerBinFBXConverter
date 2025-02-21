# ONLY ONE MODEL
# ONE POSE MORPH mesh with sub shapes
# MUST BE TRIANGULATED MODEL
# Assume 100% weight on each shape key
# input in meters, output in mm
#=================================== (Remove *# to enable default ASCII FBX parser)
from MorphCreator import *
from B_FBXReader import *

name = "NukudeFaceBinary"
origFileName = f"Example/{name}.fbx"
outputName = f"../ProtoTracer/lib/ProtoTracer/Assets/Models/FBX/Commissions/{name}.h"

morphCreator = MorphCreator(GetMorphObject(origFileName, name, 10.0)) #default is centimeters, prototracer uses millimeters

morphCodeString = morphCreator.GenerateMorphCode(name).expandtabs(4)

f = open(outputName, "w")
f.write(morphCodeString)
f.close()
