#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
//
// Buffer Definitions: 
//
// cbuffer Transform
// {
//
//   float4 buf[256];                   // Offset:    0 Size:  4096
//
// }
//
// cbuffer Time
// {
//
//   float time;                        // Offset:    0 Size:     4
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// Transform                         cbuffer      NA          NA    0        1
// Time                              cbuffer      NA          NA    1        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Position              0   xyzw        0      POS   float       
// TexCoord                 0   xy          1     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_immediateConstantBuffer { { 1.000000, 0, 0, 0},
                              { 0, 1.000000, 0, 0},
                              { 0, 0, 1.000000, 0},
                              { 0, 0, 0, 1.000000} }
dcl_constantbuffer cb0[256], dynamicIndexed
dcl_constantbuffer cb1[1], immediateIndexed
dcl_input_ps linear v1.xy
dcl_output o0.xyzw
dcl_temps 4
add r0.xy, -v1.yxyy, l(1.000000, 1.000000, 0.000000, 0.000000)
mul r0.x, r0.x, l(9.000000)
exp r0.x, r0.x
add r0.x, r0.x, l(-1.000000)
ftou r0.x, r0.x
iadd r0.z, r0.x, l(512)
and r0.w, r0.x, l(3)
ushr r1.xy, r0.xzxx, l(2, 2, 0, 0)
dp4 r0.w, cb0[r1.x + 0].xyzw, icb[r0.w + 0].xyzw
and r1.x, r0.z, l(3)
dp4 r1.x, cb0[r1.y + 0].xyzw, icb[r1.x + 0].xyzw
ult r1.y, l(0), r0.x
ult r1.z, r0.x, l(512)
and r1.y, r1.z, r1.y
if_nz r1.y
  iadd r1.yz, r0.xxxx, l(0, -1, 1, 0)
  and r2.xy, r1.yzyy, l(3, 3, 0, 0)
  ushr r1.yz, r1.yyzy, l(0, 2, 2, 0)
  dp4 r1.y, cb0[r1.y + 0].xyzw, icb[r2.x + 0].xyzw
  dp4 r1.z, cb0[r1.z + 0].xyzw, icb[r2.y + 0].xyzw
  lt r1.yz, r0.wwww, r1.yyzy
  or r1.y, r1.z, r1.y
  movc r0.w, r1.y, l(0), r0.w
else 
  if_z r0.x
    lt r1.y, r0.w, cb0[0].y
    movc r0.w, r1.y, l(0), r0.w
  else 
    ieq r1.y, r0.x, l(512)
    if_nz r1.y
      lt r1.y, r0.w, cb0[127].w
      movc r0.w, r1.y, l(0), r0.w
    endif 
  endif 
endif 
ult r1.y, l(0), r0.z
ult r1.z, r0.z, l(1024)
and r1.y, r1.z, r1.y
if_nz r1.y
  iadd r1.yz, r0.xxxx, l(0, 511, 513, 0)
  and r2.xy, r1.yzyy, l(3, 3, 0, 0)
  ushr r1.yz, r1.yyzy, l(0, 2, 2, 0)
  dp4 r0.x, cb0[r1.y + 0].xyzw, icb[r2.x + 0].xyzw
  dp4 r1.y, cb0[r1.z + 0].xyzw, icb[r2.y + 0].xyzw
  lt r0.x, r1.x, r0.x
  lt r1.y, r1.x, r1.y
  or r0.x, r0.x, r1.y
  movc r1.x, r0.x, l(0), r1.x
else 
  ieq r0.x, r0.z, l(512)
  if_nz r0.x
    lt r0.x, r1.x, cb0[128].y
    movc r1.x, r0.x, l(0), r1.x
  else 
    ieq r0.x, r0.z, l(1024)
    if_nz r0.x
      lt r0.x, r1.x, cb0[255].w
      movc r1.x, r0.x, l(0), r1.x
    endif 
  endif 
endif 
mad r0.x, r0.w, l(10000.000000), l(1.000000)
log r0.x, r0.x
mad r0.z, r1.x, l(10000.000000), l(1.000000)
log r0.z, r0.z
mad r0.x, -r0.x, l(0.015051), v1.x
mul_sat r0.x, r0.x, l(999.999939)
mad r0.w, r0.x, l(-2.000000), l(3.000000)
mul r0.x, r0.x, r0.x
mad r0.y, -r0.z, l(0.015051), r0.y
mul_sat r0.y, r0.y, l(999.999939)
mad r0.z, r0.y, l(-2.000000), l(3.000000)
mul r0.y, r0.y, r0.y
mul r1.xy, r0.xyxx, r0.wzww
mul r1.z, v1.y, l(0.500000)
mul r1.w, cb1[0].x, l(13.404119)
sincos r1.w, null, r1.w
add r1.w, r1.w, l(1.000000)
mul r1.xz, r1.yywy, r1.xxzx
mad r2.x, -r1.z, l(0.500000), l(0.750000)
mov r3.x, v1.y
mov r3.yz, l(0,1.000000,0,0)
mad r0.x, -r0.w, r0.x, l(1.000000)
mov r2.y, l(0)
mul r2.z, v1.x, l(2.000000)
mul r1.yzw, r0.xxxx, r2.xxyz
mad r1.xyz, r1.xxxx, r3.xyzx, r1.yzwy
mad r0.x, -r0.z, r0.y, l(1.000000)
mad r2.w, v1.x, l(-2.000000), l(2.000000)
mad o0.xyz, r0.xxxx, r2.xywx, r1.xyzx
mov o0.w, l(1.000000)
ret 
// Approximately 92 instruction slots used
#endif

const BYTE LeftRightMaximaPS[] =
{
     68,  88,  66,  67, 190, 107, 
    171, 111, 178,   4,  60, 123, 
     86, 237, 120, 100, 158, 141, 
     27, 150,   1,   0,   0,   0, 
    116,  13,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    220,   1,   0,   0,  52,   2, 
      0,   0, 104,   2,   0,   0, 
    216,  12,   0,   0,  82,  68, 
     69,  70, 160,   1,   0,   0, 
      2,   0,   0,   0, 140,   0, 
      0,   0,   2,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    255, 255,   0,   1,   0,   0, 
    108,   1,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    124,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 134,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0,  84, 114, 
     97, 110, 115, 102, 111, 114, 
    109,   0,  84, 105, 109, 101, 
      0, 171, 124,   0,   0,   0, 
      1,   0,   0,   0, 188,   0, 
      0,   0,   0,  16,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 134,   0,   0,   0, 
      1,   0,   0,   0,  20,   1, 
      0,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 228,   0,   0,   0, 
      0,   0,   0,   0,   0,  16, 
      0,   0,   2,   0,   0,   0, 
    240,   0,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     98, 117, 102,   0, 102, 108, 
    111,  97, 116,  52,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   0,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 232,   0,   0,   0, 
     60,   1,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0,  72,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 116, 105, 
    109, 101,   0, 102, 108, 111, 
     97, 116,   0, 171,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     65,   1,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  54,  46,  51, 
     46,  57,  54,  48,  48,  46, 
     49,  54,  51,  56,  52,   0, 
    171, 171,  73,  83,  71,  78, 
     80,   0,   0,   0,   2,   0, 
      0,   0,   8,   0,   0,   0, 
     56,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
     68,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   3,   3,   0,   0, 
     83,  86,  95,  80, 111, 115, 
    105, 116, 105, 111, 110,   0, 
     84, 101, 120,  67, 111, 111, 
    114, 100,   0, 171, 171, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  84,  97, 114, 103, 101, 
    116,   0, 171, 171,  83,  72, 
     69,  88, 104,  10,   0,   0, 
     80,   0,   0,   0, 154,   2, 
      0,   0, 106,   8,   0,   1, 
     53,  24,   0,   0,  18,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 128,  63, 
     89,   8,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      0,   1,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  98,  16,   0,   3, 
     50,  16,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      4,   0,   0,   0,   0,   0, 
      0,  11,  50,   0,  16,   0, 
      0,   0,   0,   0,  22,  21, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,  16,  65,  25,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128, 191,  28,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     30,   0,   0,   7,  66,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   2,   0,   0,   1,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   3,   0, 
      0,   0,  85,   0,   0,  10, 
     50,   0,  16,   0,   1,   0, 
      0,   0, 134,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     17,   0,   0,  10, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   4,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  70, 158, 
    144,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   7,  18,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   3,   0, 
      0,   0,  17,   0,   0,  10, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   4, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 158, 144,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     79,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  79,   0, 
      0,   7,  66,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   2, 
      0,   0,   1,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     31,   0,   4,   3,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     30,   0,   0,  10,  98,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   1,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,  10,  50,   0,  16,   0, 
      2,   0,   0,   0, 150,   5, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  85,   0,   0,  10, 
     98,   0,  16,   0,   1,   0, 
      0,   0,  86,   6,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
     17,   0,   0,  10,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   4,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  70, 158, 
    144,   0,  10,   0,  16,   0, 
      2,   0,   0,   0,  17,   0, 
      0,  10,  66,   0,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   4,   0,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  70, 158, 144,   0, 
     26,   0,  16,   0,   2,   0, 
      0,   0,  49,   0,   0,   7, 
     98,   0,  16,   0,   1,   0, 
      0,   0, 246,  15,  16,   0, 
      0,   0,   0,   0,  86,   6, 
     16,   0,   1,   0,   0,   0, 
     60,   0,   0,   7,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   1,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  55,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  18,   0, 
      0,   1,  31,   0,   0,   3, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  49,   0,   0,   8, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  55,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  18,   0, 
      0,   1,  32,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   2,   0,   0, 
     31,   0,   4,   3,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     49,   0,   0,   8,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0, 127,   0, 
      0,   0,  55,   0,   0,   9, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  21,   0,   0,   1, 
     21,   0,   0,   1,  21,   0, 
      0,   1,  79,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
     79,   0,   0,   7,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   4,   0,   0,   1,   0, 
      0,   7,  34,   0,  16,   0, 
      1,   0,   0,   0,  42,   0, 
     16,   0,   1,   0,   0,   0, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  31,   0,   4,   3, 
     26,   0,  16,   0,   1,   0, 
      0,   0,  30,   0,   0,  10, 
     98,   0,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
    255,   1,   0,   0,   1,   2, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,  10,  50,   0, 
     16,   0,   2,   0,   0,   0, 
    150,   5,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  85,   0, 
      0,  10,  98,   0,  16,   0, 
      1,   0,   0,   0,  86,   6, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,  17,   0,   0,  10, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   4, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 158, 144,   0,  10,   0, 
     16,   0,   2,   0,   0,   0, 
     17,   0,   0,  10,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   4,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      1,   0,   0,   0,  70, 158, 
    144,   0,  26,   0,  16,   0, 
      2,   0,   0,   0,  49,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  49,   0,   0,   7, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  26,   0, 
     16,   0,   1,   0,   0,   0, 
     60,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      1,   0,   0,   0,  55,   0, 
      0,   9,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,  18,   0, 
      0,   1,  32,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   2,   0,   0, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     49,   0,   0,   8,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0, 128,   0, 
      0,   0,  55,   0,   0,   9, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   1,   0, 
      0,   0,  18,   0,   0,   1, 
     32,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   4,   0,   0,  31,   0, 
      4,   3,  10,   0,  16,   0, 
      0,   0,   0,   0,  49,   0, 
      0,   8,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0, 255,   0,   0,   0, 
     55,   0,   0,   9,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   1,   0,   0,   0, 
     21,   0,   0,   1,  21,   0, 
      0,   1,  21,   0,   0,   1, 
     50,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,  64,  28,  70,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     47,   0,   0,   5,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  50,   0,   0,   9, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,  64,  28,  70, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  47,   0,   0,   5, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  10,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0, 145, 154, 118,  60, 
     10,  16,  16,   0,   1,   0, 
      0,   0,  56,  32,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0, 255, 255, 121,  68, 
     50,   0,   0,   9, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0, 192,   1,  64, 
      0,   0,   0,   0,  64,  64, 
     56,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  10,  34,   0,  16,   0, 
      0,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0, 145, 154, 118,  60, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  56,  32,   0,   7, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0, 255, 255, 121,  68, 
     50,   0,   0,   9,  66,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0, 192,   1,  64, 
      0,   0,   0,   0,  64,  64, 
     56,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7,  50,   0,  16,   0, 
      1,   0,   0,   0,  70,   0, 
     16,   0,   0,   0,   0,   0, 
    182,  15,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   7, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  26,  16,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  63, 
     56,   0,   0,   8, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     10, 128,  32,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,  69, 119, 
     86,  65,  77,   0,   0,   6, 
    130,   0,  16,   0,   1,   0, 
      0,   0,   0, 208,   0,   0, 
     58,   0,  16,   0,   1,   0, 
      0,   0,   0,   0,   0,   7, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     56,   0,   0,   7,  82,   0, 
     16,   0,   1,   0,   0,   0, 
     86,   7,  16,   0,   1,   0, 
      0,   0,   6,   2,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10,  18,   0,  16,   0, 
      2,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,  63, 
      1,  64,   0,   0,   0,   0, 
     64,  63,  54,   0,   0,   5, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  26,  16,  16,   0, 
      1,   0,   0,   0,  54,   0, 
      0,   8,  98,   0,  16,   0, 
      3,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  10,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  54,   0, 
      0,   5,  34,   0,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   2,   0,   0,   0, 
     10,  16,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,  64,  56,   0, 
      0,   7, 226,   0,  16,   0, 
      1,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   9,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,   9, 
    114,   0,  16,   0,   1,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   3,   0,   0,   0, 
    150,   7,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     50,   0,   0,   9, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     10,  16,  16,   0,   1,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0, 192,   1,  64, 
      0,   0,   0,   0,   0,  64, 
     50,   0,   0,   9, 114,  32, 
     16,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70,   3,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     54,   0,   0,   5, 130,  32, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  62,   0,   0,   1, 
     83,  84,  65,  84, 148,   0, 
      0,   0,  92,   0,   0,   0, 
      4,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
     43,   0,   0,   0,   6,   0, 
      0,   0,  15,   0,   0,   0, 
      5,   0,   0,   0,   6,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   6,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};