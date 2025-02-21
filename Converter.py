# ONLY ONE MODEL
# ONE POSE MORPH mesh with sub shapes
# MUST BE TRIANGULATED MODEL
# Assume 100% weight on each shape key
# input in meters, output in mm
#=================================== (Remove *# to enable default ASCII FBX parser)
from pathlib import Path
from MorphCreator import *
from B_FBXReader import *


name = "NukudeFaceBinary" # EDIT THE FILE NAME HERE
origFileName = Path(f"Example/{name}.fbx") # EDIT THE MODEL DIRECTORY HERE (IF NEEDED)
outputName = Path(f"../ProtoTracer/lib/ProtoTracer/Assets/Models/FBX/Commissions/{name}.h") # EDIT THE OUTPUT DIRECTORY HERE (IF NEEDED)

morphCreator = MorphCreator(GetMorphObject(origFileName, name, 10.0)) #default is centimeters, prototracer uses millimeters

morphCodeString = morphCreator.GenerateMorphCode(name).expandtabs(4)

try:
    f = open(outputName, "w")
except FileNotFoundError as e:
    print(f"###FILE NOT FOUND: \"{outputName}\". OUTPUT WILL BE PLACED HERE###")
    f = open(f"{name}.h", "w")
f.write(morphCodeString)
f.close()
