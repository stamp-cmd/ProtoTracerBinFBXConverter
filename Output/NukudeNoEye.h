#pragma once

#include "../Utils/Morph.h"
#include "../../../../Utils/Math/Rotation.h"
#include "../../../../Scene/Materials/Static/SimpleMaterial.h"
#include "../../../../Scene/Objects/Object3D.h"
#include "../../../../Renderer/Utils/IndexGroup.h"

class NukudeNoEye{
public:
    enum Morphs {
        Frown,
        Doubt,
        Surprised,
        Sadness,
        Anger,
        vrc_v_sil,
        vrc_v_th,
        vrc_v_nn,
        vrc_v_ss,
        vrc_v_rr,
        vrc_v_dd,
        vrc_v_kk,
        vrc_v_ff,
        vrc_v_pp,
        vrc_v_ch,
        vrc_v_ou,
        vrc_v_oh,
        vrc_v_ih,
        vrc_v_ee,
        vrc_v_aa,
        LookDown,
        LookUp,
        Blink,
        BiggerNose,
        MoveEye,
        HideBlush
    };

private:
    Vector3D* basisVertices = new Vector3D[40] {Vector3D(114.4961f,100.4348f,38.0390f),Vector3D(-116.2399f,-189.6453f,-157.7461f),Vector3D(-116.2399f,-189.6453f,157.7461f),Vector3D(-13.5575f,83.7609f,100.1844f),Vector3D(-19.7301f,81.3303f,101.3765f),Vector3D(0.5099f,74.5742f,93.8843f),Vector3D(-5.4593f,67.5740f,93.8118f),Vector3D(15.7293f,63.7347f,84.6558f),Vector3D(9.4177f,52.3987f,82.8788f),Vector3D(116.2399f,95.3274f,35.1901f),Vector3D(112.1099f,94.6706f,38.0922f),Vector3D(116.1206f,87.1254f,32.6282f),Vector3D(103.6440f,101.5216f,46.6482f),Vector3D(100.7730f,96.9670f,47.8381f),Vector3D(107.8638f,96.8928f,42.0946f),Vector3D(109.1810f,103.3158f,43.0500f),Vector3D(92.9030f,37.9899f,-0.0001f),Vector3D(107.1882f,50.2625f,-0.0001f),Vector3D(82.7367f,33.0260f,17.4882f),Vector3D(94.1791f,44.5764f,17.1952f),Vector3D(61.8107f,28.2406f,32.4678f),Vector3D(76.5997f,40.4917f,32.2235f),Vector3D(53.6406f,37.4347f,49.0390f),Vector3D(63.4320f,48.6924f,49.0095f),Vector3D(41.8656f,45.4268f,61.3487f),Vector3D(50.9254f,59.2305f,62.7153f),Vector3D(21.2053f,39.8635f,69.2860f),Vector3D(28.5759f,53.4154f,72.6573f),Vector3D(-22.6342f,120.6927f,95.4003f),Vector3D(-15.7318f,136.4694f,95.4003f),Vector3D(-6.3644f,137.4555f,95.4003f),Vector3D(-8.8295f,110.0926f,95.4003f),Vector3D(0.5380f,108.1205f,95.4003f),Vector3D(3.4961f,136.2230f,95.4003f),Vector3D(18.2869f,132.5253f,95.4003f),Vector3D(5.7147f,106.8880f,95.4003f),Vector3D(14.0962f,105.4089f,95.4003f),Vector3D(27.1613f,128.8276f,95.4003f),Vector3D(33.3241f,126.1159f,95.4003f),Vector3D(31.5985f,107.1345f,95.4003f)};
    IndexGroup* basisIndexes = new IndexGroup[28] {IndexGroup(21,23,22),IndexGroup(6,5,3),IndexGroup(8,7,5),IndexGroup(10,11,9),IndexGroup(12,13,14),IndexGroup(15,14,10),IndexGroup(24,25,27),IndexGroup(18,16,17),IndexGroup(19,21,20),IndexGroup(23,25,24),IndexGroup(26,27,7),IndexGroup(20,21,22),IndexGroup(4,6,3),IndexGroup(6,8,5),IndexGroup(0,10,9),IndexGroup(15,12,14),IndexGroup(0,15,10),IndexGroup(26,24,27),IndexGroup(19,18,17),IndexGroup(18,19,20),IndexGroup(22,23,24),IndexGroup(8,26,7),IndexGroup(37,39,36),IndexGroup(35,32,34),IndexGroup(29,30,31),IndexGroup(31,28,29),IndexGroup(39,37,38),IndexGroup(34,32,33)};
    StaticTriangleGroup<40,28> triangleGroup = StaticTriangleGroup<40,28>(&basisVertices[0], &basisIndexes[0]);
    TriangleGroup<40,28> triangleGroupMemory = TriangleGroup<40,28>(&triangleGroup);
    SimpleMaterial simpleMaterial = SimpleMaterial(RGBColor(128, 128, 128));
    Object3D basisObj = Object3D(&triangleGroup, &triangleGroupMemory, &simpleMaterial);

    static const uint8_t morphCount = 26;
    int* FrownIndexes = new int[4] {3,4,5,6};
    int* DoubtIndexes = new int[28] {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int* SurprisedIndexes = new int[28] {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int* SadnessIndexes = new int[28] {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int* AngerIndexes = new int[28] {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_silIndexes = new int[17] {4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_thIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_nnIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_ssIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_rrIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_ddIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_kkIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_ffIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_ppIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_chIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_ouIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_ohIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_ihIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_eeIndexes = new int[18] {3,4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* vrc_v_aaIndexes = new int[17] {4,5,6,7,8,16,17,18,19,20,21,22,23,24,25,26,27};
    int* LookDownIndexes = new int[28] {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int* LookUpIndexes = new int[28] {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int* BlinkIndexes = new int[28] {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};
    int* BiggerNoseIndexes = new int[8] {0,9,10,11,12,13,14,15};
    int* MoveEyeIndexes = new int[1] {0};
    int* HideBlushIndexes = new int[12] {28,29,30,31,32,33,34,35,36,37,38,39};

    Vector3D* FrownVectors = new Vector3D[4] {Vector3D(0.0000f,-19.4851f,-3.4480f),Vector3D(0.0000f,-23.5129f,-3.9973f),Vector3D(-0.6649f,-9.0778f,-2.1497f),Vector3D(0.0000f,-10.3950f,-2.5070f)};
    Vector3D* DoubtVectors = new Vector3D[28] {Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f),Vector3D(0.0000f,-0.0517f,0.0000f)};
    Vector3D* SurprisedVectors = new Vector3D[28] {Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f),Vector3D(0.0000f,-0.5973f,0.0000f)};
    Vector3D* SadnessVectors = new Vector3D[28] {Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f),Vector3D(0.0000f,-0.0906f,0.0000f)};
    Vector3D* AngerVectors = new Vector3D[28] {Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,-0.0000f),Vector3D(0.0000f,0.1536f,-0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f),Vector3D(0.0000f,0.1536f,0.0000f)};
    Vector3D* vrc_v_silVectors = new Vector3D[17] {Vector3D(0.0000f,-0.0911f,-0.0101f),Vector3D(0.0000f,0.0237f,0.0009f),Vector3D(-0.0515f,-0.0860f,0.0000f),Vector3D(0.0000f,0.0643f,0.0268f),Vector3D(-0.0705f,-0.1041f,-0.0167f),Vector3D(-0.1191f,-0.1434f,0.0000f),Vector3D(0.0508f,0.0410f,0.0000f),Vector3D(-0.1390f,-0.1242f,-0.0032f),Vector3D(0.0597f,0.0469f,0.0000f),Vector3D(-0.0737f,-0.1027f,-0.0173f),Vector3D(0.0677f,0.0590f,0.0096f),Vector3D(-0.0893f,-0.1116f,-0.0309f),Vector3D(0.0780f,0.0645f,0.0000f),Vector3D(-0.0530f,-0.1266f,-0.0494f),Vector3D(0.0726f,0.0424f,-0.0122f),Vector3D(-0.0713f,-0.1144f,-0.0233f),Vector3D(0.0140f,0.0368f,0.0145f)};
    Vector3D* vrc_v_thVectors = new Vector3D[18] {Vector3D(55.7137f,-22.2539f,-30.6447f),Vector3D(57.3329f,-23.1836f,-30.8233f),Vector3D(49.2026f,-12.0649f,-27.9191f),Vector3D(46.8795f,-13.8555f,-27.8181f),Vector3D(44.0447f,-5.3543f,-25.3489f),Vector3D(38.7850f,-7.6427f,-25.5255f),Vector3D(-8.1507f,-7.0605f,0.0000f),Vector3D(-1.5652f,-2.5408f,0.0000f),Vector3D(-1.6069f,-3.8519f,-7.0329f),Vector3D(5.0344f,-0.3199f,-6.8186f),Vector3D(13.2976f,-1.1604f,-11.9691f),Vector3D(15.6842f,0.8370f,-12.3657f),Vector3D(18.4484f,-5.6751f,-19.0777f),Vector3D(27.8347f,-3.1722f,-19.0476f),Vector3D(26.4203f,-8.8531f,-22.8275f),Vector3D(32.1776f,-8.6533f,-22.3755f),Vector3D(34.2168f,-3.3388f,-23.0582f),Vector3D(40.8266f,-2.1968f,-23.3941f)};
    Vector3D* vrc_v_nnVectors = new Vector3D[18] {Vector3D(10.3832f,-4.9453f,-5.7070f),Vector3D(10.3832f,-6.4953f,-6.0773f),Vector3D(9.2577f,-1.5436f,-4.6158f),Vector3D(7.5258f,-5.7149f,-5.6158f),Vector3D(8.4137f,-0.1044f,-4.5801f),Vector3D(5.3768f,-3.8705f,-5.1054f),Vector3D(-5.7003f,-4.9747f,0.0000f),Vector3D(0.9587f,0.5786f,0.0000f),Vector3D(-3.8337f,-3.8842f,-1.1310f),Vector3D(2.0397f,1.1999f,-1.0434f),Vector3D(-1.0585f,-3.0941f,-1.9226f),Vector3D(3.5898f,1.6312f,-1.4451f),Vector3D(0.9537f,-4.1197f,-3.8531f),Vector3D(9.7005f,-0.6937f,-3.1317f),Vector3D(2.9793f,-4.6032f,-5.0208f),Vector3D(6.3255f,-1.0398f,-3.8029f),Vector3D(4.3005f,-3.2232f,-4.8067f),Vector3D(7.4736f,0.0000f,-4.0987f)};
    Vector3D* vrc_v_ssVectors = new Vector3D[18] {Vector3D(55.7137f,-22.2539f,-30.6447f),Vector3D(57.3329f,-23.1836f,-30.8233f),Vector3D(49.2026f,-12.0649f,-27.9191f),Vector3D(46.8795f,-13.8555f,-27.8181f),Vector3D(44.0447f,-5.3543f,-25.3489f),Vector3D(38.7850f,-7.6427f,-25.5255f),Vector3D(-8.1507f,-7.0605f,0.0000f),Vector3D(-1.5652f,-2.5408f,0.0000f),Vector3D(-1.6069f,-3.8519f,-7.0329f),Vector3D(5.0344f,-0.3199f,-6.8186f),Vector3D(13.2976f,-1.1604f,-11.9691f),Vector3D(15.6842f,0.8370f,-12.3657f),Vector3D(18.4484f,-5.6751f,-19.0777f),Vector3D(27.8347f,-3.1722f,-19.0476f),Vector3D(26.4203f,-8.8531f,-22.8275f),Vector3D(32.1776f,-8.6533f,-22.3755f),Vector3D(34.2168f,-3.3388f,-23.0582f),Vector3D(40.8266f,-2.1968f,-23.3941f)};
    Vector3D* vrc_v_rrVectors = new Vector3D[18] {Vector3D(10.3832f,-4.9453f,-5.7070f),Vector3D(10.3832f,-6.4953f,-6.0773f),Vector3D(9.2577f,-1.5436f,-4.6158f),Vector3D(7.5258f,-5.7149f,-5.6158f),Vector3D(8.4137f,-0.1044f,-4.5801f),Vector3D(5.3768f,-3.8705f,-5.1054f),Vector3D(-5.7003f,-4.9747f,0.0000f),Vector3D(0.9587f,0.5786f,0.0000f),Vector3D(-3.8337f,-3.8842f,-1.1310f),Vector3D(2.0397f,1.1999f,-1.0434f),Vector3D(-1.0585f,-3.0941f,-1.9226f),Vector3D(3.5898f,1.6312f,-1.4451f),Vector3D(0.9537f,-4.1197f,-3.8531f),Vector3D(9.7005f,-0.6937f,-3.1317f),Vector3D(2.9793f,-4.6032f,-5.0208f),Vector3D(6.3255f,-1.0398f,-3.8029f),Vector3D(4.3005f,-3.2232f,-4.8067f),Vector3D(7.4736f,0.0000f,-4.0987f)};
    Vector3D* vrc_v_ddVectors = new Vector3D[18] {Vector3D(10.3832f,-4.9453f,-5.7070f),Vector3D(10.3832f,-6.4953f,-6.0773f),Vector3D(9.2577f,-1.5436f,-4.6158f),Vector3D(7.5258f,-5.7149f,-5.6158f),Vector3D(8.4137f,-0.1044f,-4.5801f),Vector3D(5.3768f,-3.8705f,-5.1054f),Vector3D(-5.7003f,-4.9747f,0.0000f),Vector3D(0.9587f,0.5786f,0.0000f),Vector3D(-3.8337f,-3.8842f,-1.1310f),Vector3D(2.0397f,1.1999f,-1.0434f),Vector3D(-1.0585f,-3.0941f,-1.9226f),Vector3D(3.5898f,1.6312f,-1.4451f),Vector3D(0.9537f,-4.1197f,-3.8531f),Vector3D(9.7005f,-0.6937f,-3.1317f),Vector3D(2.9793f,-4.6032f,-5.0208f),Vector3D(6.3255f,-1.0398f,-3.8029f),Vector3D(4.3005f,-3.2232f,-4.8067f),Vector3D(7.4736f,0.0000f,-4.0987f)};
    Vector3D* vrc_v_kkVectors = new Vector3D[18] {Vector3D(10.3832f,-4.9453f,-5.7070f),Vector3D(10.3832f,-6.4953f,-6.0773f),Vector3D(9.2577f,-1.5436f,-4.6158f),Vector3D(7.5258f,-5.7149f,-5.6158f),Vector3D(8.4137f,-0.1044f,-4.5801f),Vector3D(5.3768f,-3.8705f,-5.1054f),Vector3D(-5.7003f,-4.9747f,0.0000f),Vector3D(0.9587f,0.5786f,0.0000f),Vector3D(-3.8337f,-3.8842f,-1.1310f),Vector3D(2.0397f,1.1999f,-1.0434f),Vector3D(-1.0585f,-3.0941f,-1.9226f),Vector3D(3.5898f,1.6312f,-1.4451f),Vector3D(0.9537f,-4.1197f,-3.8531f),Vector3D(9.7005f,-0.6937f,-3.1317f),Vector3D(2.9793f,-4.6032f,-5.0208f),Vector3D(6.3255f,-1.0398f,-3.8029f),Vector3D(4.3005f,-3.2232f,-4.8067f),Vector3D(7.4736f,0.0000f,-4.0987f)};
    Vector3D* vrc_v_ffVectors = new Vector3D[18] {Vector3D(50.5221f,-19.7813f,-27.7912f),Vector3D(53.8863f,-20.9971f,-28.9628f),Vector3D(44.5737f,-11.2931f,-25.6112f),Vector3D(43.1167f,-10.9981f,-25.0102f),Vector3D(39.8379f,-6.9527f,-24.1192f),Vector3D(36.0966f,-5.7074f,-23.6100f),Vector3D(-3.1818f,-2.6147f,0.0000f),Vector3D(-2.0446f,-2.8302f,0.0000f),Vector3D(2.4288f,0.0487f,-6.4674f),Vector3D(4.0145f,-0.9198f,-6.2969f),Vector3D(16.6971f,2.3452f,-11.6713f),Vector3D(13.8893f,0.0214f,-11.6432f),Vector3D(18.1844f,-2.1488f,-17.6998f),Vector3D(22.9845f,-3.4401f,-17.4817f),Vector3D(24.2933f,-6.5516f,-20.3171f),Vector3D(28.7599f,-8.1333f,-20.4741f),Vector3D(32.3730f,-1.7273f,-20.7728f),Vector3D(37.0898f,-3.8473f,-22.1694f)};
    Vector3D* vrc_v_ppVectors = new Vector3D[18] {Vector3D(50.5221f,-19.7813f,-27.7912f),Vector3D(53.8863f,-20.9971f,-28.9628f),Vector3D(44.5737f,-11.2931f,-25.6112f),Vector3D(43.1167f,-10.9981f,-25.0102f),Vector3D(39.8379f,-6.9527f,-24.1192f),Vector3D(36.0966f,-5.7074f,-23.6100f),Vector3D(-3.1818f,-2.6147f,0.0000f),Vector3D(-2.0446f,-2.8302f,0.0000f),Vector3D(2.4288f,0.0487f,-6.4674f),Vector3D(4.0145f,-0.9198f,-6.2969f),Vector3D(16.6971f,2.3452f,-11.6713f),Vector3D(13.8893f,0.0214f,-11.6432f),Vector3D(18.1844f,-2.1488f,-17.6998f),Vector3D(22.9845f,-3.4401f,-17.4817f),Vector3D(24.2933f,-6.5516f,-20.3171f),Vector3D(28.7599f,-8.1333f,-20.4741f),Vector3D(32.3730f,-1.7273f,-20.7728f),Vector3D(37.0898f,-3.8473f,-22.1694f)};
    Vector3D* vrc_v_chVectors = new Vector3D[18] {Vector3D(50.5221f,-19.7813f,-27.7912f),Vector3D(52.1413f,-19.9360f,-27.7846f),Vector3D(44.5737f,-11.2931f,-25.6112f),Vector3D(43.1167f,-10.9981f,-25.0102f),Vector3D(39.8379f,-5.3022f,-23.0589f),Vector3D(36.0966f,-5.7074f,-22.9728f),Vector3D(-5.3006f,-4.5732f,0.0000f),Vector3D(-2.0446f,-2.8302f,0.0000f),Vector3D(0.3100f,-1.9098f,-6.4674f),Vector3D(4.0145f,-0.9198f,-6.2969f),Vector3D(13.8269f,0.3867f,-11.0078f),Vector3D(13.8893f,0.0214f,-11.6432f),Vector3D(17.9716f,-3.6153f,-17.1511f),Vector3D(22.9845f,-2.8253f,-17.4817f),Vector3D(24.9306f,-6.5516f,-20.3171f),Vector3D(29.0149f,-8.1333f,-20.4741f),Vector3D(32.0665f,-1.7273f,-20.6548f),Vector3D(37.0898f,-2.1968f,-21.3447f)};
    Vector3D* vrc_v_ouVectors = new Vector3D[18] {Vector3D(41.5329f,-19.7813f,-22.8279f),Vector3D(49.2123f,-22.8400f,-25.6120f),Vector3D(41.4017f,-9.0964f,-22.2196f),Vector3D(40.1876f,-13.9021f,-22.4630f),Vector3D(39.5621f,-3.9489f,-23.0589f),Vector3D(33.1676f,-8.6115f,-22.9728f),Vector3D(-10.4177f,-9.2525f,0.0000f),Vector3D(4.2162f,2.6211f,0.0000f),Vector3D(-3.7964f,-5.6544f,-6.4674f),Vector3D(10.0717f,5.8024f,-4.1736f),Vector3D(9.7627f,-3.1048f,-10.8375f),Vector3D(20.2069f,7.9198f,-9.0634f),Vector3D(15.4620f,-7.5212f,-18.3048f),Vector3D(21.7707f,-2.0925f,-16.2415f),Vector3D(22.0016f,-9.4557f,-20.4349f),Vector3D(29.2406f,-4.1591f,-17.9281f),Vector3D(30.3579f,-4.6313f,-21.3640f),Vector3D(36.1608f,0.0000f,-20.6379f)};
    Vector3D* vrc_v_ohVectors = new Vector3D[18] {Vector3D(41.5329f,-19.7813f,-22.8279f),Vector3D(41.5329f,-25.9811f,-24.3093f),Vector3D(37.0308f,-6.1748f,-18.4634f),Vector3D(30.1032f,-22.8592f,-22.4630f),Vector3D(33.6550f,-0.4173f,-18.3202f),Vector3D(21.5072f,-15.4820f,-20.4218f),Vector3D(-22.8011f,-19.8990f,0.0000f),Vector3D(3.8350f,2.3145f,0.0000f),Vector3D(-15.3348f,-15.5370f,-4.5241f),Vector3D(8.1590f,4.7995f,-4.1736f),Vector3D(-4.2340f,-12.3763f,-7.6903f),Vector3D(14.3593f,6.5249f,-5.7802f),Vector3D(3.8149f,-16.4784f,-15.4125f),Vector3D(14.9136f,-2.7747f,-12.5269f),Vector3D(11.9171f,-18.4128f,-20.0831f),Vector3D(25.3021f,-4.1591f,-15.2117f),Vector3D(17.2019f,-12.8928f,-19.2269f),Vector3D(29.8943f,0.0000f,-16.3948f)};
    Vector3D* vrc_v_ihVectors = new Vector3D[18] {Vector3D(-1.2097f,-7.5390f,-0.4844f),Vector3D(1.0150f,-10.6264f,-1.0883f),Vector3D(-6.2079f,-2.3909f,1.6494f),Vector3D(-9.0888f,-5.9046f,2.7358f),Vector3D(-7.3105f,1.7397f,5.1746f),Vector3D(-11.1172f,-0.5831f,6.1909f),Vector3D(-11.3047f,-9.8536f,0.0000f),Vector3D(-2.4897f,-3.0050f,0.0000f),Vector3D(-9.1238f,-7.7668f,0.0557f),Vector3D(-1.0489f,-1.8323f,0.0000f),Vector3D(-4.5751f,-5.2331f,1.9684f),Vector3D(-1.5496f,0.0000f,2.0561f),Vector3D(-8.0493f,-5.0303f,0.9413f),Vector3D(1.2997f,0.0000f,-0.3553f),Vector3D(-8.1619f,-3.3666f,1.4302f),Vector3D(-1.8067f,0.0000f,1.5485f),Vector3D(-10.0850f,0.5141f,7.2497f),Vector3D(-6.6223f,2.7824f,5.0436f)};
    Vector3D* vrc_v_eeVectors = new Vector3D[18] {Vector3D(-1.1700f,-14.4306f,-1.3944f),Vector3D(0.0000f,-22.1947f,-4.3495f),Vector3D(2.8776f,-6.0434f,-1.7126f),Vector3D(-8.8729f,-17.7731f,-2.0173f),Vector3D(2.8776f,-0.0088f,0.2740f),Vector3D(-10.2401f,-12.3874f,-1.1393f),Vector3D(-8.8729f,-8.2239f,0.0000f),Vector3D(2.8776f,2.0616f,0.0000f),Vector3D(-8.8729f,-8.2239f,-0.0149f),Vector3D(2.8776f,2.0616f,0.0000f),Vector3D(-8.8729f,-8.2239f,-0.0149f),Vector3D(2.8776f,2.0616f,0.0000f),Vector3D(-8.8729f,-8.2239f,-0.0149f),Vector3D(2.8776f,2.0616f,0.0000f),Vector3D(-8.8729f,-8.2239f,-0.0149f),Vector3D(2.8776f,2.0616f,0.0000f),Vector3D(-8.8729f,-8.2239f,-0.0149f),Vector3D(2.8776f,2.0616f,0.0000f)};
    Vector3D* vrc_v_aaVectors = new Vector3D[17] {Vector3D(0.0000f,-9.1072f,-1.0137f),Vector3D(0.0000f,2.3650f,0.0896f),Vector3D(-5.1450f,-8.5993f,0.0045f),Vector3D(0.0000f,6.4290f,2.6851f),Vector3D(-7.0489f,-10.4099f,-1.6690f),Vector3D(-11.9073f,-14.3399f,0.0000f),Vector3D(5.0838f,4.0978f,0.0000f),Vector3D(-13.8950f,-12.4182f,-0.3235f),Vector3D(5.9699f,4.6809f,0.0000f),Vector3D(-7.3737f,-10.2708f,-1.7323f),Vector3D(6.7721f,5.9013f,0.9566f),Vector3D(-8.9346f,-11.1617f,-3.0909f),Vector3D(7.7971f,6.4411f,0.0000f),Vector3D(-5.3012f,-12.6539f,-4.9366f),Vector3D(7.2642f,4.2376f,-1.2217f),Vector3D(-7.1340f,-11.4447f,-2.3333f),Vector3D(1.3999f,3.6860f,1.4474f)};
    Vector3D* LookDownVectors = new Vector3D[28] {Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f),Vector3D(0.0000f,1.9651f,0.0000f)};
    Vector3D* LookUpVectors = new Vector3D[28] {Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f),Vector3D(0.0000f,-1.1409f,0.0000f)};
    Vector3D* BlinkVectors = new Vector3D[28] {Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(0.0000f,-0.1121f,-0.0101f),Vector3D(0.0000f,0.0027f,0.0009f),Vector3D(-0.0515f,-0.1070f,0.0000f),Vector3D(0.0000f,0.0433f,0.0268f),Vector3D(-0.0705f,-0.1252f,-0.0167f),Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(0.0000f,-0.0210f,0.0000f),Vector3D(-0.1191f,-0.1644f,0.0000f),Vector3D(0.0508f,0.0200f,0.0000f),Vector3D(-0.1390f,-0.1452f,-0.0032f),Vector3D(0.0597f,0.0259f,0.0000f),Vector3D(-0.0737f,-0.1237f,-0.0173f),Vector3D(0.0677f,0.0380f,0.0096f),Vector3D(-0.0893f,-0.1326f,-0.0309f),Vector3D(0.0780f,0.0435f,0.0000f),Vector3D(-0.0530f,-0.1476f,-0.0494f),Vector3D(0.0726f,0.0214f,-0.0122f),Vector3D(-0.0713f,-0.1354f,-0.0233f),Vector3D(0.0140f,0.0158f,0.0145f)};
    Vector3D* BiggerNoseVectors = new Vector3D[8] {Vector3D(8.4117f,22.0785f,0.0000f),Vector3D(9.9468f,17.5824f,0.0000f),Vector3D(6.3111f,17.0042f,0.0000f),Vector3D(9.8417f,10.3621f,0.0000f),Vector3D(-1.1415f,23.0352f,0.0000f),Vector3D(-3.6689f,19.0258f,0.0000f),Vector3D(2.5732f,18.9604f,0.0000f),Vector3D(3.7327f,24.6146f,0.0000f)};
    Vector3D* MoveEyeVectors = new Vector3D[1] {Vector3D(0.0000f,0.0000f,0.0000f)};
    Vector3D* HideBlushVectors = new Vector3D[12] {Vector3D(29.3555f,0.6368f,0.0000f),Vector3D(22.4532f,-15.1400f,0.0000f),Vector3D(13.0857f,-16.1260f,0.0000f),Vector3D(15.5508f,11.2368f,0.0000f),Vector3D(6.1833f,13.2090f,0.0000f),Vector3D(3.2252f,-14.8935f,0.0000f),Vector3D(-11.5655f,-11.1958f,0.0000f),Vector3D(1.0066f,14.4415f,0.0000f),Vector3D(-7.3748f,15.9206f,0.0000f),Vector3D(-20.4400f,-7.4981f,0.0000f),Vector3D(-26.6028f,-4.7864f,0.0000f),Vector3D(-24.8772f,14.1950f,0.0000f)};

    Morph morphs[26] = {
        Morph(4, FrownIndexes, FrownVectors),
        Morph(28, DoubtIndexes, DoubtVectors),
        Morph(28, SurprisedIndexes, SurprisedVectors),
        Morph(28, SadnessIndexes, SadnessVectors),
        Morph(28, AngerIndexes, AngerVectors),
        Morph(17, vrc_v_silIndexes, vrc_v_silVectors),
        Morph(18, vrc_v_thIndexes, vrc_v_thVectors),
        Morph(18, vrc_v_nnIndexes, vrc_v_nnVectors),
        Morph(18, vrc_v_ssIndexes, vrc_v_ssVectors),
        Morph(18, vrc_v_rrIndexes, vrc_v_rrVectors),
        Morph(18, vrc_v_ddIndexes, vrc_v_ddVectors),
        Morph(18, vrc_v_kkIndexes, vrc_v_kkVectors),
        Morph(18, vrc_v_ffIndexes, vrc_v_ffVectors),
        Morph(18, vrc_v_ppIndexes, vrc_v_ppVectors),
        Morph(18, vrc_v_chIndexes, vrc_v_chVectors),
        Morph(18, vrc_v_ouIndexes, vrc_v_ouVectors),
        Morph(18, vrc_v_ohIndexes, vrc_v_ohVectors),
        Morph(18, vrc_v_ihIndexes, vrc_v_ihVectors),
        Morph(18, vrc_v_eeIndexes, vrc_v_eeVectors),
        Morph(17, vrc_v_aaIndexes, vrc_v_aaVectors),
        Morph(28, LookDownIndexes, LookDownVectors),
        Morph(28, LookUpIndexes, LookUpVectors),
        Morph(28, BlinkIndexes, BlinkVectors),
        Morph(8, BiggerNoseIndexes, BiggerNoseVectors),
        Morph(1, MoveEyeIndexes, MoveEyeVectors),
        Morph(12, HideBlushIndexes, HideBlushVectors)
    };

public:
    NukudeNoEye(){}

    Object3D* GetObject(){
        return &basisObj;
    }

    void SetMorphWeight(Morphs morph, float weight){
        morphs[morph].Weight = weight;
    }

    float* GetMorphWeightReference(Morphs morph){
        return &morphs[morph].Weight;
    }

    void Reset(){
        for(int i = 0; i < morphCount; i++){
            morphs[i].Weight = 0.0f;
        }
    }

    void Update(){
        basisObj.ResetVertices();

        for(int i = 0; i < morphCount; i++){
            if(morphs[i].Weight > 0.0f){
                morphs[i].MorphObject3D(basisObj.GetTriangleGroup());
            }
        }

    }
};
