/* WARNING, THIS FILE WAS GENERATED, DO NOT EDIT */
#ifndef FSR_UPSCALE_GLSL_GEN_H_RD
#define FSR_UPSCALE_GLSL_GEN_H_RD

#include "servers/rendering/renderer_rd/shader_rd.h"

class FsrUpscaleShaderRD : public ShaderRD {

public:

	FsrUpscaleShaderRD() {

		static const char _compute_code[] = {
R"<!>(
#version 450

#VERSION_DEFINES

#define A_GPU
#define A_GLSL

#ifdef MODE_FSR_UPSCALE_NORMAL

#define A_HALF

#endif






























































































#define A_2PI 6.28318530718














#ifdef A_CPU
 
 #ifndef A_RESTRICT
  #define A_RESTRICT __restrict
 #endif

 #ifndef A_STATIC
  #define A_STATIC static
 #endif

 
 
 typedef uint32_t AP1;
 typedef float AF1;
 typedef double AD1;
 typedef uint8_t AB1;
 typedef uint16_t AW1;
 typedef uint32_t AU1;
 typedef uint64_t AL1;
 typedef int8_t ASB1;
 typedef int16_t ASW1;
 typedef int32_t ASU1;
 typedef int64_t ASL1;

 #define AD1_(a) ((AD1)(a))
 #define AF1_(a) ((AF1)(a))
 #define AL1_(a) ((AL1)(a))
 #define AU1_(a) ((AU1)(a))

 #define ASL1_(a) ((ASL1)(a))
 #define ASU1_(a) ((ASU1)(a))

 A_STATIC AU1 AU1_AF1(AF1 a){union{AF1 f;AU1 u;}bits;bits.f=a;return bits.u;}

 #define A_TRUE 1
 #define A_FALSE 0






















 #define retAD2 AD1 *A_RESTRICT
 #define retAD3 AD1 *A_RESTRICT
 #define retAD4 AD1 *A_RESTRICT
 #define retAF2 AF1 *A_RESTRICT
 #define retAF3 AF1 *A_RESTRICT
 #define retAF4 AF1 *A_RESTRICT
 #define retAL2 AL1 *A_RESTRICT
 #define retAL3 AL1 *A_RESTRICT
 #define retAL4 AL1 *A_RESTRICT
 #define retAU2 AU1 *A_RESTRICT
 #define retAU3 AU1 *A_RESTRICT
 #define retAU4 AU1 *A_RESTRICT

 #define inAD2 AD1 *A_RESTRICT
 #define inAD3 AD1 *A_RESTRICT
 #define inAD4 AD1 *A_RESTRICT
 #define inAF2 AF1 *A_RESTRICT
 #define inAF3 AF1 *A_RESTRICT
 #define inAF4 AF1 *A_RESTRICT
 #define inAL2 AL1 *A_RESTRICT
 #define inAL3 AL1 *A_RESTRICT
 #define inAL4 AL1 *A_RESTRICT
 #define inAU2 AU1 *A_RESTRICT
 #define inAU3 AU1 *A_RESTRICT
 #define inAU4 AU1 *A_RESTRICT

 #define inoutAD2 AD1 *A_RESTRICT
 #define inoutAD3 AD1 *A_RESTRICT
 #define inoutAD4 AD1 *A_RESTRICT
 #define inoutAF2 AF1 *A_RESTRICT
 #define inoutAF3 AF1 *A_RESTRICT
 #define inoutAF4 AF1 *A_RESTRICT
 #define inoutAL2 AL1 *A_RESTRICT
 #define inoutAL3 AL1 *A_RESTRICT
 #define inoutAL4 AL1 *A_RESTRICT
 #define inoutAU2 AU1 *A_RESTRICT
 #define inoutAU3 AU1 *A_RESTRICT
 #define inoutAU4 AU1 *A_RESTRICT

 #define outAD2 AD1 *A_RESTRICT
 #define outAD3 AD1 *A_RESTRICT
 #define outAD4 AD1 *A_RESTRICT
 #define outAF2 AF1 *A_RESTRICT
 #define outAF3 AF1 *A_RESTRICT
 #define outAF4 AF1 *A_RESTRICT
 #define outAL2 AL1 *A_RESTRICT
 #define outAL3 AL1 *A_RESTRICT
 #define outAL4 AL1 *A_RESTRICT
 #define outAU2 AU1 *A_RESTRICT
 #define outAU3 AU1 *A_RESTRICT
 #define outAU4 AU1 *A_RESTRICT

 #define varAD2(x) AD1 x[2]
 #define varAD3(x) AD1 x[3]
 #define varAD4(x) AD1 x[4]
 #define varAF2(x) AF1 x[2]
 #define varAF3(x) AF1 x[3]
 #define varAF4(x) AF1 x[4]
 #define varAL2(x) AL1 x[2]
 #define varAL3(x) AL1 x[3]
 #define varAL4(x) AL1 x[4]
 #define varAU2(x) AU1 x[2]
 #define varAU3(x) AU1 x[3]
 #define varAU4(x) AU1 x[4]

 #define initAD2(x,y) {x,y}
 #define initAD3(x,y,z) {x,y,z}
 #define initAD4(x,y,z,w) {x,y,z,w}
 #define initAF2(x,y) {x,y}
 #define initAF3(x,y,z) {x,y,z}
 #define initAF4(x,y,z,w) {x,y,z,w}
 #define initAL2(x,y) {x,y}
 #define initAL3(x,y,z) {x,y,z}
 #define initAL4(x,y,z,w) {x,y,z,w}
 #define initAU2(x,y) {x,y}
 #define initAU3(x,y,z) {x,y,z}
 #define initAU4(x,y,z,w) {x,y,z,w}










 #ifdef A_GCC
  A_STATIC AD1 AAbsD1(AD1 a){return __builtin_fabs(a);}
  A_STATIC AF1 AAbsF1(AF1 a){return __builtin_fabsf(a);}
  A_STATIC AU1 AAbsSU1(AU1 a){return AU1_(__builtin_abs(ASU1_(a)));}
  A_STATIC AL1 AAbsSL1(AL1 a){return AL1_(__builtin_llabs(ASL1_(a)));}
 #else
  A_STATIC AD1 AAbsD1(AD1 a){return fabs(a);}
  A_STATIC AF1 AAbsF1(AF1 a){return fabsf(a);}
  A_STATIC AU1 AAbsSU1(AU1 a){return AU1_(abs(ASU1_(a)));}
  A_STATIC AL1 AAbsSL1(AL1 a){return AL1_(labs((long)ASL1_(a)));}
 #endif

 #ifdef A_GCC
  A_STATIC AD1 ACosD1(AD1 a){return __builtin_cos(a);}
  A_STATIC AF1 ACosF1(AF1 a){return __builtin_cosf(a);}
 #else
  A_STATIC AD1 ACosD1(AD1 a){return cos(a);}
  A_STATIC AF1 ACosF1(AF1 a){return cosf(a);}
 #endif

 A_STATIC AD1 ADotD2(inAD2 a,inAD2 b){return a[0]*b[0]+a[1]*b[1];}
 A_STATIC AD1 ADotD3(inAD3 a,inAD3 b){return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];}
 A_STATIC AD1 ADotD4(inAD4 a,inAD4 b){return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]+a[3]*b[3];}
 A_STATIC AF1 ADotF2(inAF2 a,inAF2 b){return a[0]*b[0]+a[1]*b[1];}
 A_STATIC AF1 ADotF3(inAF3 a,inAF3 b){return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];}
 A_STATIC AF1 ADotF4(inAF4 a,inAF4 b){return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]+a[3]*b[3];}

 #ifdef A_GCC
  A_STATIC AD1 AExp2D1(AD1 a){return __builtin_exp2(a);}
  A_STATIC AF1 AExp2F1(AF1 a){return __builtin_exp2f(a);}
 #else
  A_STATIC AD1 AExp2D1(AD1 a){return exp2(a);}
  A_STATIC AF1 AExp2F1(AF1 a){return exp2f(a);}
 #endif

 #ifdef A_GCC
  A_STATIC AD1 AFloorD1(AD1 a){return __builtin_floor(a);}
  A_STATIC AF1 AFloorF1(AF1 a){return __builtin_floorf(a);}
 #else
  A_STATIC AD1 AFloorD1(AD1 a){return floor(a);}
  A_STATIC AF1 AFloorF1(AF1 a){return floorf(a);}
 #endif

 A_STATIC AD1 ALerpD1(AD1 a,AD1 b,AD1 c){return b*c+(-a*c+a);}
 A_STATIC AF1 ALerpF1(AF1 a,AF1 b,AF1 c){return b*c+(-a*c+a);}

 #ifdef A_GCC
  A_STATIC AD1 ALog2D1(AD1 a){return __builtin_log2(a);}
  A_STATIC AF1 ALog2F1(AF1 a){return __builtin_log2f(a);}
 #else
  A_STATIC AD1 ALog2D1(AD1 a){return log2(a);}
  A_STATIC AF1 ALog2F1(AF1 a){return log2f(a);}
 #endif

 A_STATIC AD1 AMaxD1(AD1 a,AD1 b){return a>b?a:b;}
 A_STATIC AF1 AMaxF1(AF1 a,AF1 b){return a>b?a:b;}
 A_STATIC AL1 AMaxL1(AL1 a,AL1 b){return a>b?a:b;}
 A_STATIC AU1 AMaxU1(AU1 a,AU1 b){return a>b?a:b;}

 
 A_STATIC AL1 AMaxSL1(AL1 a,AL1 b){return (ASL1_(a)>ASL1_(b))?a:b;}
 A_STATIC AU1 AMaxSU1(AU1 a,AU1 b){return (ASU1_(a)>ASU1_(b))?a:b;}

 A_STATIC AD1 AMinD1(AD1 a,AD1 b){return a<b?a:b;}
 A_STATIC AF1 AMinF1(AF1 a,AF1 b){return a<b?a:b;}
 A_STATIC AL1 AMinL1(AL1 a,AL1 b){return a<b?a:b;}
 A_STATIC AU1 AMinU1(AU1 a,AU1 b){return a<b?a:b;}

 A_STATIC AL1 AMinSL1(AL1 a,AL1 b){return (ASL1_(a)<ASL1_(b))?a:b;}
 A_STATIC AU1 AMinSU1(AU1 a,AU1 b){return (ASU1_(a)<ASU1_(b))?a:b;}

 A_STATIC AD1 ARcpD1(AD1 a){return 1.0/a;}
 A_STATIC AF1 ARcpF1(AF1 a){return 1.0f/a;}

 A_STATIC AL1 AShrSL1(AL1 a,AL1 b){return AL1_(ASL1_(a)>>ASL1_(b));}
 A_STATIC AU1 AShrSU1(AU1 a,AU1 b){return AU1_(ASU1_(a)>>ASU1_(b));}

 #ifdef A_GCC
  A_STATIC AD1 ASinD1(AD1 a){return __builtin_sin(a);}
  A_STATIC AF1 ASinF1(AF1 a){return __builtin_sinf(a);}
 #else
  A_STATIC AD1 ASinD1(AD1 a){return sin(a);}
  A_STATIC AF1 ASinF1(AF1 a){return sinf(a);}
 #endif

 #ifdef A_GCC
  A_STATIC AD1 ASqrtD1(AD1 a){return __builtin_sqrt(a);}
  A_STATIC AF1 ASqrtF1(AF1 a){return __builtin_sqrtf(a);}
 #else
  A_STATIC AD1 ASqrtD1(AD1 a){return sqrt(a);}
  A_STATIC AF1 ASqrtF1(AF1 a){return sqrtf(a);}
 #endif






 A_STATIC AD1 AClampD1(AD1 x,AD1 n,AD1 m){return AMaxD1(n,AMinD1(x,m));}
 A_STATIC AF1 AClampF1(AF1 x,AF1 n,AF1 m){return AMaxF1(n,AMinF1(x,m));}

 A_STATIC AD1 AFractD1(AD1 a){return a-AFloorD1(a);}
 A_STATIC AF1 AFractF1(AF1 a){return a-AFloorF1(a);}

 A_STATIC AD1 APowD1(AD1 a,AD1 b){return AExp2D1(b*ALog2D1(a));}
 A_STATIC AF1 APowF1(AF1 a,AF1 b){return AExp2F1(b*ALog2F1(a));}

 A_STATIC AD1 ARsqD1(AD1 a){return ARcpD1(ASqrtD1(a));}
 A_STATIC AF1 ARsqF1(AF1 a){return ARcpF1(ASqrtF1(a));}

 A_STATIC AD1 ASatD1(AD1 a){return AMinD1(1.0,AMaxD1(0.0,a));}
 A_STATIC AF1 ASatF1(AF1 a){return AMinF1(1.0f,AMaxF1(0.0f,a));}









 A_STATIC retAD2 opAAbsD2(outAD2 d,inAD2 a){d[0]=AAbsD1(a[0]);d[1]=AAbsD1(a[1]);return d;}
 A_STATIC retAD3 opAAbsD3(outAD3 d,inAD3 a){d[0]=AAbsD1(a[0]);d[1]=AAbsD1(a[1]);d[2]=AAbsD1(a[2]);return d;}
 A_STATIC retAD4 opAAbsD4(outAD4 d,inAD4 a){d[0]=AAbsD1(a[0]);d[1]=AAbsD1(a[1]);d[2]=AAbsD1(a[2]);d[3]=AAbsD1(a[3]);return d;}

 A_STATIC retAF2 opAAbsF2(outAF2 d,inAF2 a){d[0]=AAbsF1(a[0]);d[1]=AAbsF1(a[1]);return d;}
 A_STATIC retAF3 opAAbsF3(outAF3 d,inAF3 a){d[0]=AAbsF1(a[0]);d[1]=AAbsF1(a[1]);d[2]=AAbsF1(a[2]);return d;}
 A_STATIC retAF4 opAAbsF4(outAF4 d,inAF4 a){d[0]=AAbsF1(a[0]);d[1]=AAbsF1(a[1]);d[2]=AAbsF1(a[2]);d[3]=AAbsF1(a[3]);return d;}

 A_STATIC retAD2 opAAddD2(outAD2 d,inAD2 a,inAD2 b){d[0]=a[0]+b[0];d[1]=a[1]+b[1];return d;}
 A_STATIC retAD3 opAAddD3(outAD3 d,inAD3 a,inAD3 b){d[0]=a[0]+b[0];d[1]=a[1]+b[1];d[2]=a[2]+b[2];return d;}
 A_STATIC retAD4 opAAddD4(outAD4 d,inAD4 a,inAD4 b){d[0]=a[0]+b[0];d[1]=a[1]+b[1];d[2]=a[2]+b[2];d[3]=a[3]+b[3];return d;}

 A_STATIC retAF2 opAAddF2(outAF2 d,inAF2 a,inAF2 b){d[0]=a[0]+b[0];d[1]=a[1]+b[1];return d;}
 A_STATIC retAF3 opAAddF3(outAF3 d,inAF3 a,inAF3 b){d[0]=a[0]+b[0];d[1]=a[1]+b[1];d[2]=a[2]+b[2];return d;}
 A_STATIC retAF4 opAAddF4(outAF4 d,inAF4 a,inAF4 b){d[0]=a[0]+b[0];d[1]=a[1]+b[1];d[2]=a[2]+b[2];d[3]=a[3]+b[3];return d;}

 A_STATIC retAD2 opAAddOneD2(outAD2 d,inAD2 a,AD1 b){d[0]=a[0]+b;d[1]=a[1]+b;return d;}
 A_STATIC retAD3 opAAddOneD3(outAD3 d,inAD3 a,AD1 b){d[0]=a[0]+b;d[1]=a[1]+b;d[2]=a[2]+b;return d;}
 A_STATIC retAD4 opAAddOneD4(outAD4 d,inAD4 a,AD1 b){d[0]=a[0]+b;d[1]=a[1]+b;d[2]=a[2]+b;d[3]=a[3]+b;return d;}

 A_STATIC retAF2 opAAddOneF2(outAF2 d,inAF2 a,AF1 b){d[0]=a[0]+b;d[1]=a[1]+b;return d;}
 A_STATIC retAF3 opAAddOneF3(outAF3 d,inAF3 a,AF1 b){d[0]=a[0]+b;d[1]=a[1]+b;d[2]=a[2]+b;return d;}
 A_STATIC retAF4 opAAddOneF4(outAF4 d,inAF4 a,AF1 b){d[0]=a[0]+b;d[1]=a[1]+b;d[2]=a[2]+b;d[3]=a[3]+b;return d;}

 A_STATIC retAD2 opACpyD2(outAD2 d,inAD2 a){d[0]=a[0];d[1]=a[1];return d;}
 A_STATIC retAD3 opACpyD3(outAD3 d,inAD3 a){d[0]=a[0];d[1]=a[1];d[2]=a[2];return d;}
 A_STATIC retAD4 opACpyD4(outAD4 d,inAD4 a){d[0]=a[0];d[1]=a[1];d[2]=a[2];d[3]=a[3];return d;}

 A_STATIC retAF2 opACpyF2(outAF2 d,inAF2 a){d[0]=a[0];d[1]=a[1];return d;}
 A_STATIC retAF3 opACpyF3(outAF3 d,inAF3 a){d[0]=a[0];d[1]=a[1];d[2]=a[2];return d;}
 A_STATIC retAF4 opACpyF4(outAF4 d,inAF4 a){d[0]=a[0];d[1]=a[1];d[2]=a[2];d[3]=a[3];return d;}

 A_STATIC retAD2 opALerpD2(outAD2 d,inAD2 a,inAD2 b,inAD2 c){d[0]=ALerpD1(a[0],b[0],c[0]);d[1]=ALerpD1(a[1],b[1],c[1]);return d;}
 A_STATIC retAD3 opALerpD3(outAD3 d,inAD3 a,inAD3 b,inAD3 c){d[0]=ALerpD1(a[0],b[0],c[0]);d[1]=ALerpD1(a[1],b[1],c[1]);d[2]=ALerpD1(a[2],b[2],c[2]);return d;}
 A_STATIC retAD4 opALerpD4(outAD4 d,inAD4 a,inAD4 b,inAD4 c){d[0]=ALerpD1(a[0],b[0],c[0]);d[1]=ALerpD1(a[1],b[1],c[1]);d[2]=ALerpD1(a[2],b[2],c[2]);d[3]=ALerpD1(a[3],b[3],c[3]);return d;}

 A_STATIC retAF2 opALerpF2(outAF2 d,inAF2 a,inAF2 b,inAF2 c){d[0]=ALerpF1(a[0],b[0],c[0]);d[1]=ALerpF1(a[1],b[1],c[1]);return d;}
 A_STATIC retAF3 opALerpF3(outAF3 d,inAF3 a,inAF3 b,inAF3 c){d[0]=ALerpF1(a[0],b[0],c[0]);d[1]=ALerpF1(a[1],b[1],c[1]);d[2]=ALerpF1(a[2],b[2],c[2]);return d;}
 A_STATIC retAF4 opALerpF4(outAF4 d,inAF4 a,inAF4 b,inAF4 c){d[0]=ALerpF1(a[0],b[0],c[0]);d[1]=ALerpF1(a[1],b[1],c[1]);d[2]=ALerpF1(a[2],b[2],c[2]);d[3]=ALerpF1(a[3],b[3],c[3]);return d;}

 A_STATIC retAD2 opALerpOneD2(outAD2 d,inAD2 a,inAD2 b,AD1 c){d[0]=ALerpD1(a[0],b[0],c);d[1]=ALerpD1(a[1],b[1],c);return d;}
 A_STATIC retAD3 opALerpOneD3(outAD3 d,inAD3 a,inAD3 b,AD1 c){d[0]=ALerpD1(a[0],b[0],c);d[1]=ALerpD1(a[1],b[1],c);d[2]=ALerpD1(a[2],b[2],c);return d;}
 A_STATIC retAD4 opALerpOneD4(outAD4 d,inAD4 a,inAD4 b,AD1 c){d[0]=ALerpD1(a[0],b[0],c);d[1]=ALerpD1(a[1],b[1],c);d[2]=ALerpD1(a[2],b[2],c);d[3]=ALerpD1(a[3],b[3],c);return d;}

 A_STATIC retAF2 opALerpOneF2(outAF2 d,inAF2 a,inAF2 b,AF1 c){d[0]=ALerpF1(a[0],b[0],c);d[1]=ALerpF1(a[1],b[1],c);return d;}
 A_STATIC retAF3 opALerpOneF3(outAF3 d,inAF3 a,inAF3 b,AF1 c){d[0]=ALerpF1(a[0],b[0],c);d[1]=ALerpF1(a[1],b[1],c);d[2]=ALerpF1(a[2],b[2],c);return d;}
 A_STATIC retAF4 opALerpOneF4(outAF4 d,inAF4 a,inAF4 b,AF1 c){d[0]=ALerpF1(a[0],b[0],c);d[1]=ALerpF1(a[1],b[1],c);d[2]=ALerpF1(a[2],b[2],c);d[3]=ALerpF1(a[3],b[3],c);return d;}

 A_STATIC retAD2 opAMaxD2(outAD2 d,inAD2 a,inAD2 b){d[0]=AMaxD1(a[0],b[0]);d[1]=AMaxD1(a[1],b[1]);return d;}
 A_STATIC retAD3 opAMaxD3(outAD3 d,inAD3 a,inAD3 b){d[0]=AMaxD1(a[0],b[0]);d[1]=AMaxD1(a[1],b[1]);d[2]=AMaxD1(a[2],b[2]);return d;}
 A_STATIC retAD4 opAMaxD4(outAD4 d,inAD4 a,inAD4 b){d[0]=AMaxD1(a[0],b[0]);d[1]=AMaxD1(a[1],b[1]);d[2]=AMaxD1(a[2],b[2]);d[3]=AMaxD1(a[3],b[3]);return d;}

 A_STATIC retAF2 opAMaxF2(outAF2 d,inAF2 a,inAF2 b){d[0]=AMaxF1(a[0],b[0]);d[1]=AMaxF1(a[1],b[1]);return d;}
 A_STATIC retAF3 opAMaxF3(outAF3 d,inAF3 a,inAF3 b){d[0]=AMaxF1(a[0],b[0]);d[1]=AMaxF1(a[1],b[1]);d[2]=AMaxF1(a[2],b[2]);return d;}
 A_STATIC retAF4 opAMaxF4(outAF4 d,inAF4 a,inAF4 b){d[0]=AMaxF1(a[0],b[0]);d[1]=AMaxF1(a[1],b[1]);d[2]=AMaxF1(a[2],b[2]);d[3]=AMaxF1(a[3],b[3]);return d;}

 A_STATIC retAD2 opAMinD2(outAD2 d,inAD2 a,inAD2 b){d[0]=AMinD1(a[0],b[0]);d[1]=AMinD1(a[1],b[1]);return d;}
 A_STATIC retAD3 opAMinD3(outAD3 d,inAD3 a,inAD3 b){d[0]=AMinD1(a[0],b[0]);d[1]=AMinD1(a[1],b[1]);d[2]=AMinD1(a[2],b[2]);return d;}
 A_STATIC retAD4 opAMinD4(outAD4 d,inAD4 a,inAD4 b){d[0]=AMinD1(a[0],b[0]);d[1]=AMinD1(a[1],b[1]);d[2]=AMinD1(a[2],b[2]);d[3]=AMinD1(a[3],b[3]);return d;}

 A_STATIC retAF2 opAMinF2(outAF2 d,inAF2 a,inAF2 b){d[0]=AMinF1(a[0],b[0]);d[1]=AMinF1(a[1],b[1]);return d;}
 A_STATIC retAF3 opAMinF3(outAF3 d,inAF3 a,inAF3 b){d[0]=AMinF1(a[0],b[0]);d[1]=AMinF1(a[1],b[1]);d[2]=AMinF1(a[2],b[2]);return d;}
 A_STATIC retAF4 opAMinF4(outAF4 d,inAF4 a,inAF4 b){d[0]=AMinF1(a[0],b[0]);d[1]=AMinF1(a[1],b[1]);d[2]=AMinF1(a[2],b[2]);d[3]=AMinF1(a[3],b[3]);return d;}

 A_STATIC retAD2 opAMulD2(outAD2 d,inAD2 a,inAD2 b){d[0]=a[0]*b[0];d[1]=a[1]*b[1];return d;}
 A_STATIC retAD3 opAMulD3(outAD3 d,inAD3 a,inAD3 b){d[0]=a[0]*b[0];d[1]=a[1]*b[1];d[2]=a[2]*b[2];return d;}
 A_STATIC retAD4 opAMulD4(outAD4 d,inAD4 a,inAD4 b){d[0]=a[0]*b[0];d[1]=a[1]*b[1];d[2]=a[2]*b[2];d[3]=a[3]*b[3];return d;}

 A_STATIC retAF2 opAMulF2(outAF2 d,inAF2 a,inAF2 b){d[0]=a[0]*b[0];d[1]=a[1]*b[1];return d;}
 A_STATIC retAF3 opAMulF3(outAF3 d,inAF3 a,inAF3 b){d[0]=a[0]*b[0];d[1]=a[1]*b[1];d[2]=a[2]*b[2];return d;}
 A_STATIC retAF4 opAMulF4(outAF4 d,inAF4 a,inAF4 b){d[0]=a[0]*b[0];d[1]=a[1]*b[1];d[2]=a[2]*b[2];d[3]=a[3]*b[3];return d;}

 A_STATIC retAD2 opAMulOneD2(outAD2 d,inAD2 a,AD1 b){d[0]=a[0]*b;d[1]=a[1]*b;return d;}
 A_STATIC retAD3 opAMulOneD3(outAD3 d,inAD3 a,AD1 b){d[0]=a[0]*b;d[1]=a[1]*b;d[2]=a[2]*b;return d;}
 A_STATIC retAD4 opAMulOneD4(outAD4 d,inAD4 a,AD1 b){d[0]=a[0]*b;d[1]=a[1]*b;d[2]=a[2]*b;d[3]=a[3]*b;return d;}

 A_STATIC retAF2 opAMulOneF2(outAF2 d,inAF2 a,AF1 b){d[0]=a[0]*b;d[1]=a[1]*b;return d;}
 A_STATIC retAF3 opAMulOneF3(outAF3 d,inAF3 a,AF1 b){d[0]=a[0]*b;d[1]=a[1]*b;d[2]=a[2]*b;return d;}
 A_STATIC retAF4 opAMulOneF4(outAF4 d,inAF4 a,AF1 b){d[0]=a[0]*b;d[1]=a[1]*b;d[2]=a[2]*b;d[3]=a[3]*b;return d;}

 A_STATIC retAD2 opANegD2(outAD2 d,inAD2 a){d[0]=-a[0];d[1]=-a[1];return d;}
 A_STATIC retAD3 opANegD3(outAD3 d,inAD3 a){d[0]=-a[0];d[1]=-a[1];d[2]=-a[2];return d;}
 A_STATIC retAD4 opANegD4(outAD4 d,inAD4 a){d[0]=-a[0];d[1]=-a[1];d[2]=-a[2];d[3]=-a[3];return d;}

 A_STATIC retAF2 opANegF2(outAF2 d,inAF2 a){d[0]=-a[0];d[1]=-a[1];return d;}
 A_STATIC retAF3 opANegF3(outAF3 d,inAF3 a){d[0]=-a[0];d[1]=-a[1];d[2]=-a[2];return d;}
 A_STATIC retAF4 opANegF4(outAF4 d,inAF4 a){d[0]=-a[0];d[1]=-a[1];d[2]=-a[2];d[3]=-a[3];return d;}

 A_STATIC retAD2 opARcpD2(outAD2 d,inAD2 a){d[0]=ARcpD1(a[0]);d[1]=ARcpD1(a[1]);return d;}
 A_STATIC retAD3 opARcpD3(outAD3 d,inAD3 a){d[0]=ARcpD1(a[0]);d[1]=ARcpD1(a[1]);d[2]=ARcpD1(a[2]);return d;}
 A_STATIC retAD4 opARcpD4(outAD4 d,inAD4 a){d[0]=ARcpD1(a[0]);d[1]=ARcpD1(a[1]);d[2]=ARcpD1(a[2]);d[3]=ARcpD1(a[3]);return d;}

 A_STATIC retAF2 opARcpF2(outAF2 d,inAF2 a){d[0]=ARcpF1(a[0]);d[1]=ARcpF1(a[1]);return d;}
 A_STATIC retAF3 opARcpF3(outAF3 d,inAF3 a){d[0]=ARcpF1(a[0]);d[1]=ARcpF1(a[1]);d[2]=ARcpF1(a[2]);return d;}
 A_STATIC retAF4 opARcpF4(outAF4 d,inAF4 a){d[0]=ARcpF1(a[0]);d[1]=ARcpF1(a[1]);d[2]=ARcpF1(a[2]);d[3]=ARcpF1(a[3]);return d;}





)<!>" R"<!>(
 
 
 
 
 
 
 A_STATIC AU1 AU1_AH1_AF1(AF1 f){
  static AW1 base[512]={
   0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
   0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
   0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
   0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
   0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
   0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
   0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,0x0100,
   0x0200,0x0400,0x0800,0x0c00,0x1000,0x1400,0x1800,0x1c00,0x2000,0x2400,0x2800,0x2c00,0x3000,0x3400,0x3800,0x3c00,
   0x4000,0x4400,0x4800,0x4c00,0x5000,0x5400,0x5800,0x5c00,0x6000,0x6400,0x6800,0x6c00,0x7000,0x7400,0x7800,0x7bff,
   0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,
   0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,
   0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,
   0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,
   0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,
   0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,
   0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,0x7bff,
   0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
   0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
   0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
   0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
   0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
   0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
   0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8001,0x8002,0x8004,0x8008,0x8010,0x8020,0x8040,0x8080,0x8100,
   0x8200,0x8400,0x8800,0x8c00,0x9000,0x9400,0x9800,0x9c00,0xa000,0xa400,0xa800,0xac00,0xb000,0xb400,0xb800,0xbc00,
   0xc000,0xc400,0xc800,0xcc00,0xd000,0xd400,0xd800,0xdc00,0xe000,0xe400,0xe800,0xec00,0xf000,0xf400,0xf800,0xfbff,
   0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,
   0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,
   0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,
   0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,
   0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,
   0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,
   0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff,0xfbff};
  static AB1 shift[512]={
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0f,
   0x0e,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,
   0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x17,0x16,0x15,0x14,0x13,0x12,0x11,0x10,0x0f,
   0x0e,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,
   0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
   0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18};
  union{AF1 f;AU1 u;}bits;bits.f=f;AU1 u=bits.u;AU1 i=u>>23;return (AU1)(base[i])+((u&0x7fffff)>>shift[i]);}

 
 A_STATIC AU1 AU1_AH2_AF2(inAF2 a){return AU1_AH1_AF1(a[0])+(AU1_AH1_AF1(a[1])<<16);}
#endif














#if defined(A_GLSL) && defined(A_GPU)
 #ifndef A_SKIP_EXT
  #ifdef A_HALF
   #extension GL_EXT_shader_16bit_storage:require
   #extension GL_EXT_shader_explicit_arithmetic_types:require 
  #endif

  #ifdef A_LONG
   #extension GL_ARB_gpu_shader_int64:require
   #extension GL_NV_shader_atomic_int64:require
  #endif

  #ifdef A_WAVE
   #extension GL_KHR_shader_subgroup_arithmetic:require
   #extension GL_KHR_shader_subgroup_ballot:require
   #extension GL_KHR_shader_subgroup_quad:require
   #extension GL_KHR_shader_subgroup_shuffle:require
  #endif
 #endif

 #define AP1 bool
 #define AP2 bvec2
 #define AP3 bvec3
 #define AP4 bvec4

 #define AF1 float
 #define AF2 vec2
 #define AF3 vec3
 #define AF4 vec4

 #define AU1 uint
 #define AU2 uvec2
 #define AU3 uvec3
 #define AU4 uvec4

 #define ASU1 int
 #define ASU2 ivec2
 #define ASU3 ivec3
 #define ASU4 ivec4

 #define AF1_AU1(x) uintBitsToFloat(AU1(x))
 #define AF2_AU2(x) uintBitsToFloat(AU2(x))
 #define AF3_AU3(x) uintBitsToFloat(AU3(x))
 #define AF4_AU4(x) uintBitsToFloat(AU4(x))

 #define AU1_AF1(x) floatBitsToUint(AF1(x))
 #define AU2_AF2(x) floatBitsToUint(AF2(x))
 #define AU3_AF3(x) floatBitsToUint(AF3(x))
 #define AU4_AF4(x) floatBitsToUint(AF4(x))

 AU1 AU1_AH1_AF1_x(AF1 a){return packHalf2x16(AF2(a,0.0));}
 #define AU1_AH1_AF1(a) AU1_AH1_AF1_x(AF1(a))

 #define AU1_AH2_AF2 packHalf2x16
 #define AU1_AW2Unorm_AF2 packUnorm2x16
 #define AU1_AB4Unorm_AF4 packUnorm4x8

 #define AF2_AH2_AU1 unpackHalf2x16
 #define AF2_AW2Unorm_AU1 unpackUnorm2x16
 #define AF4_AB4Unorm_AU1 unpackUnorm4x8

 AF1 AF1_x(AF1 a){return AF1(a);}
 AF2 AF2_x(AF1 a){return AF2(a,a);}
 AF3 AF3_x(AF1 a){return AF3(a,a,a);}
 AF4 AF4_x(AF1 a){return AF4(a,a,a,a);}
 #define AF1_(a) AF1_x(AF1(a))
 #define AF2_(a) AF2_x(AF1(a))
 #define AF3_(a) AF3_x(AF1(a))
 #define AF4_(a) AF4_x(AF1(a))

 AU1 AU1_x(AU1 a){return AU1(a);}
 AU2 AU2_x(AU1 a){return AU2(a,a);}
 AU3 AU3_x(AU1 a){return AU3(a,a,a);}
 AU4 AU4_x(AU1 a){return AU4(a,a,a,a);}
 #define AU1_(a) AU1_x(AU1(a))
 #define AU2_(a) AU2_x(AU1(a))
 #define AU3_(a) AU3_x(AU1(a))
 #define AU4_(a) AU4_x(AU1(a))

 AU1 AAbsSU1(AU1 a){return AU1(abs(ASU1(a)));}
 AU2 AAbsSU2(AU2 a){return AU2(abs(ASU2(a)));}
 AU3 AAbsSU3(AU3 a){return AU3(abs(ASU3(a)));}
 AU4 AAbsSU4(AU4 a){return AU4(abs(ASU4(a)));}

 AU1 ABfe(AU1 src,AU1 off,AU1 bits){return bitfieldExtract(src,ASU1(off),ASU1(bits));}
 AU1 ABfi(AU1 src,AU1 ins,AU1 mask){return (ins&mask)|(src&(~mask));}
 
 AU1 ABfiM(AU1 src,AU1 ins,AU1 bits){return bitfieldInsert(src,ins,0,ASU1(bits));}

 
 AF1 AClampF1(AF1 x,AF1 n,AF1 m){return clamp(x,n,m);}
 AF2 AClampF2(AF2 x,AF2 n,AF2 m){return clamp(x,n,m);}
 AF3 AClampF3(AF3 x,AF3 n,AF3 m){return clamp(x,n,m);}
 AF4 AClampF4(AF4 x,AF4 n,AF4 m){return clamp(x,n,m);}

 
 AF1 AFractF1(AF1 x){return fract(x);}
 AF2 AFractF2(AF2 x){return fract(x);}
 AF3 AFractF3(AF3 x){return fract(x);}
 AF4 AFractF4(AF4 x){return fract(x);}

 AF1 ALerpF1(AF1 x,AF1 y,AF1 a){return mix(x,y,a);}
 AF2 ALerpF2(AF2 x,AF2 y,AF2 a){return mix(x,y,a);}
 AF3 ALerpF3(AF3 x,AF3 y,AF3 a){return mix(x,y,a);}
 AF4 ALerpF4(AF4 x,AF4 y,AF4 a){return mix(x,y,a);}

 
 AF1 AMax3F1(AF1 x,AF1 y,AF1 z){return max(x,max(y,z));}
 AF2 AMax3F2(AF2 x,AF2 y,AF2 z){return max(x,max(y,z));}
 AF3 AMax3F3(AF3 x,AF3 y,AF3 z){return max(x,max(y,z));}
 AF4 AMax3F4(AF4 x,AF4 y,AF4 z){return max(x,max(y,z));}

 AU1 AMax3SU1(AU1 x,AU1 y,AU1 z){return AU1(max(ASU1(x),max(ASU1(y),ASU1(z))));}
 AU2 AMax3SU2(AU2 x,AU2 y,AU2 z){return AU2(max(ASU2(x),max(ASU2(y),ASU2(z))));}
 AU3 AMax3SU3(AU3 x,AU3 y,AU3 z){return AU3(max(ASU3(x),max(ASU3(y),ASU3(z))));}
 AU4 AMax3SU4(AU4 x,AU4 y,AU4 z){return AU4(max(ASU4(x),max(ASU4(y),ASU4(z))));}

 AU1 AMax3U1(AU1 x,AU1 y,AU1 z){return max(x,max(y,z));}
 AU2 AMax3U2(AU2 x,AU2 y,AU2 z){return max(x,max(y,z));}
 AU3 AMax3U3(AU3 x,AU3 y,AU3 z){return max(x,max(y,z));}
 AU4 AMax3U4(AU4 x,AU4 y,AU4 z){return max(x,max(y,z));}

 AU1 AMaxSU1(AU1 a,AU1 b){return AU1(max(ASU1(a),ASU1(b)));}
 AU2 AMaxSU2(AU2 a,AU2 b){return AU2(max(ASU2(a),ASU2(b)));}
 AU3 AMaxSU3(AU3 a,AU3 b){return AU3(max(ASU3(a),ASU3(b)));}
 AU4 AMaxSU4(AU4 a,AU4 b){return AU4(max(ASU4(a),ASU4(b)));}

 
 
 AF1 AMed3F1(AF1 x,AF1 y,AF1 z){return max(min(x,y),min(max(x,y),z));}
 AF2 AMed3F2(AF2 x,AF2 y,AF2 z){return max(min(x,y),min(max(x,y),z));}
 AF3 AMed3F3(AF3 x,AF3 y,AF3 z){return max(min(x,y),min(max(x,y),z));}
 AF4 AMed3F4(AF4 x,AF4 y,AF4 z){return max(min(x,y),min(max(x,y),z));}

 
 AF1 AMin3F1(AF1 x,AF1 y,AF1 z){return min(x,min(y,z));}
 AF2 AMin3F2(AF2 x,AF2 y,AF2 z){return min(x,min(y,z));}
 AF3 AMin3F3(AF3 x,AF3 y,AF3 z){return min(x,min(y,z));}
 AF4 AMin3F4(AF4 x,AF4 y,AF4 z){return min(x,min(y,z));}

 AU1 AMin3SU1(AU1 x,AU1 y,AU1 z){return AU1(min(ASU1(x),min(ASU1(y),ASU1(z))));}
 AU2 AMin3SU2(AU2 x,AU2 y,AU2 z){return AU2(min(ASU2(x),min(ASU2(y),ASU2(z))));}
 AU3 AMin3SU3(AU3 x,AU3 y,AU3 z){return AU3(min(ASU3(x),min(ASU3(y),ASU3(z))));}
 AU4 AMin3SU4(AU4 x,AU4 y,AU4 z){return AU4(min(ASU4(x),min(ASU4(y),ASU4(z))));}

 AU1 AMin3U1(AU1 x,AU1 y,AU1 z){return min(x,min(y,z));}
 AU2 AMin3U2(AU2 x,AU2 y,AU2 z){return min(x,min(y,z));}
 AU3 AMin3U3(AU3 x,AU3 y,AU3 z){return min(x,min(y,z));}
 AU4 AMin3U4(AU4 x,AU4 y,AU4 z){return min(x,min(y,z));}

 AU1 AMinSU1(AU1 a,AU1 b){return AU1(min(ASU1(a),ASU1(b)));}
 AU2 AMinSU2(AU2 a,AU2 b){return AU2(min(ASU2(a),ASU2(b)));}
 AU3 AMinSU3(AU3 a,AU3 b){return AU3(min(ASU3(a),ASU3(b)));}
 AU4 AMinSU4(AU4 a,AU4 b){return AU4(min(ASU4(a),ASU4(b)));}

 
 
 AF1 ANCosF1(AF1 x){return cos(x*AF1_(A_2PI));}
 AF2 ANCosF2(AF2 x){return cos(x*AF2_(A_2PI));}
 AF3 ANCosF3(AF3 x){return cos(x*AF3_(A_2PI));}
 AF4 ANCosF4(AF4 x){return cos(x*AF4_(A_2PI));}

 
 
 AF1 ANSinF1(AF1 x){return sin(x*AF1_(A_2PI));}
 AF2 ANSinF2(AF2 x){return sin(x*AF2_(A_2PI));}
 AF3 ANSinF3(AF3 x){return sin(x*AF3_(A_2PI));}
 AF4 ANSinF4(AF4 x){return sin(x*AF4_(A_2PI));}

 AF1 ARcpF1(AF1 x){return AF1_(1.0)/x;}
 AF2 ARcpF2(AF2 x){return AF2_(1.0)/x;}
 AF3 ARcpF3(AF3 x){return AF3_(1.0)/x;}
 AF4 ARcpF4(AF4 x){return AF4_(1.0)/x;}

 AF1 ARsqF1(AF1 x){return AF1_(1.0)/sqrt(x);}
 AF2 ARsqF2(AF2 x){return AF2_(1.0)/sqrt(x);}
 AF3 ARsqF3(AF3 x){return AF3_(1.0)/sqrt(x);}
 AF4 ARsqF4(AF4 x){return AF4_(1.0)/sqrt(x);}

 AF1 ASatF1(AF1 x){return clamp(x,AF1_(0.0),AF1_(1.0));}
 AF2 ASatF2(AF2 x){return clamp(x,AF2_(0.0),AF2_(1.0));}
 AF3 ASatF3(AF3 x){return clamp(x,AF3_(0.0),AF3_(1.0));}
 AF4 ASatF4(AF4 x){return clamp(x,AF4_(0.0),AF4_(1.0));}

 AU1 AShrSU1(AU1 a,AU1 b){return AU1(ASU1(a)>>ASU1(b));}
 AU2 AShrSU2(AU2 a,AU2 b){return AU2(ASU2(a)>>ASU2(b));}
 AU3 AShrSU3(AU3 a,AU3 b){return AU3(ASU3(a)>>ASU3(b));}
 AU4 AShrSU4(AU4 a,AU4 b){return AU4(ASU4(a)>>ASU4(b));}






 #ifdef A_BYTE
  #define AB1 uint8_t
  #define AB2 u8vec2
  #define AB3 u8vec3
  #define AB4 u8vec4

  #define ASB1 int8_t
  #define ASB2 i8vec2
  #define ASB3 i8vec3
  #define ASB4 i8vec4

  AB1 AB1_x(AB1 a){return AB1(a);}
  AB2 AB2_x(AB1 a){return AB2(a,a);}
  AB3 AB3_x(AB1 a){return AB3(a,a,a);}
  AB4 AB4_x(AB1 a){return AB4(a,a,a,a);}
  #define AB1_(a) AB1_x(AB1(a))
  #define AB2_(a) AB2_x(AB1(a))
  #define AB3_(a) AB3_x(AB1(a))
  #define AB4_(a) AB4_x(AB1(a))
 #endif






 #ifdef A_HALF
  #define AH1 float16_t
  #define AH2 f16vec2
  #define AH3 f16vec3
  #define AH4 f16vec4

  #define AW1 uint16_t
  #define AW2 u16vec2
  #define AW3 u16vec3
  #define AW4 u16vec4

  #define ASW1 int16_t
  #define ASW2 i16vec2
  #define ASW3 i16vec3
  #define ASW4 i16vec4

  #define AH2_AU1(x) unpackFloat2x16(AU1(x))
  AH4 AH4_AU2_x(AU2 x){return AH4(unpackFloat2x16(x.x),unpackFloat2x16(x.y));}
  #define AH4_AU2(x) AH4_AU2_x(AU2(x))
  #define AW2_AU1(x) unpackUint2x16(AU1(x))
  #define AW4_AU2(x) unpackUint4x16(pack64(AU2(x)))

  #define AU1_AH2(x) packFloat2x16(AH2(x))
  AU2 AU2_AH4_x(AH4 x){return AU2(packFloat2x16(x.xy),packFloat2x16(x.zw));}
  #define AU2_AH4(x) AU2_AH4_x(AH4(x))
  #define AU1_AW2(x) packUint2x16(AW2(x))
  #define AU2_AW4(x) unpack32(packUint4x16(AW4(x)))

  #define AW1_AH1(x) halfBitsToUint16(AH1(x))
  #define AW2_AH2(x) halfBitsToUint16(AH2(x))
  #define AW3_AH3(x) halfBitsToUint16(AH3(x))
  #define AW4_AH4(x) halfBitsToUint16(AH4(x))

  #define AH1_AW1(x) uint16BitsToHalf(AW1(x))
  #define AH2_AW2(x) uint16BitsToHalf(AW2(x))
  #define AH3_AW3(x) uint16BitsToHalf(AW3(x))
  #define AH4_AW4(x) uint16BitsToHalf(AW4(x))

  AH1 AH1_x(AH1 a){return AH1(a);}
  AH2 AH2_x(AH1 a){return AH2(a,a);}
  AH3 AH3_x(AH1 a){return AH3(a,a,a);}
  AH4 AH4_x(AH1 a){return AH4(a,a,a,a);}
  #define AH1_(a) AH1_x(AH1(a))
  #define AH2_(a) AH2_x(AH1(a))
  #define AH3_(a) AH3_x(AH1(a))
  #define AH4_(a) AH4_x(AH1(a))

  AW1 AW1_x(AW1 a){return AW1(a);}
  AW2 AW2_x(AW1 a){return AW2(a,a);}
  AW3 AW3_x(AW1 a){return AW3(a,a,a);}
  AW4 AW4_x(AW1 a){return AW4(a,a,a,a);}
  #define AW1_(a) AW1_x(AW1(a))
  #define AW2_(a) AW2_x(AW1(a))
  #define AW3_(a) AW3_x(AW1(a))
  #define AW4_(a) AW4_x(AW1(a))

  AW1 AAbsSW1(AW1 a){return AW1(abs(ASW1(a)));}
  AW2 AAbsSW2(AW2 a){return AW2(abs(ASW2(a)));}
  AW3 AAbsSW3(AW3 a){return AW3(abs(ASW3(a)));}
  AW4 AAbsSW4(AW4 a){return AW4(abs(ASW4(a)));}

  AH1 AClampH1(AH1 x,AH1 n,AH1 m){return clamp(x,n,m);}
  AH2 AClampH2(AH2 x,AH2 n,AH2 m){return clamp(x,n,m);}
  AH3 AClampH3(AH3 x,AH3 n,AH3 m){return clamp(x,n,m);}
  AH4 AClampH4(AH4 x,AH4 n,AH4 m){return clamp(x,n,m);}

  AH1 AFractH1(AH1 x){return fract(x);}
  AH2 AFractH2(AH2 x){return fract(x);}
  AH3 AFractH3(AH3 x){return fract(x);}
  AH4 AFractH4(AH4 x){return fract(x);}
)<!>" R"<!>(
  AH1 ALerpH1(AH1 x,AH1 y,AH1 a){return mix(x,y,a);}
  AH2 ALerpH2(AH2 x,AH2 y,AH2 a){return mix(x,y,a);}
  AH3 ALerpH3(AH3 x,AH3 y,AH3 a){return mix(x,y,a);}
  AH4 ALerpH4(AH4 x,AH4 y,AH4 a){return mix(x,y,a);}

  
  AH1 AMax3H1(AH1 x,AH1 y,AH1 z){return max(x,max(y,z));}
  AH2 AMax3H2(AH2 x,AH2 y,AH2 z){return max(x,max(y,z));}
  AH3 AMax3H3(AH3 x,AH3 y,AH3 z){return max(x,max(y,z));}
  AH4 AMax3H4(AH4 x,AH4 y,AH4 z){return max(x,max(y,z));}

  AW1 AMaxSW1(AW1 a,AW1 b){return AW1(max(ASU1(a),ASU1(b)));}
  AW2 AMaxSW2(AW2 a,AW2 b){return AW2(max(ASU2(a),ASU2(b)));}
  AW3 AMaxSW3(AW3 a,AW3 b){return AW3(max(ASU3(a),ASU3(b)));}
  AW4 AMaxSW4(AW4 a,AW4 b){return AW4(max(ASU4(a),ASU4(b)));}

  
  AH1 AMin3H1(AH1 x,AH1 y,AH1 z){return min(x,min(y,z));}
  AH2 AMin3H2(AH2 x,AH2 y,AH2 z){return min(x,min(y,z));}
  AH3 AMin3H3(AH3 x,AH3 y,AH3 z){return min(x,min(y,z));}
  AH4 AMin3H4(AH4 x,AH4 y,AH4 z){return min(x,min(y,z));}

  AW1 AMinSW1(AW1 a,AW1 b){return AW1(min(ASU1(a),ASU1(b)));}
  AW2 AMinSW2(AW2 a,AW2 b){return AW2(min(ASU2(a),ASU2(b)));}
  AW3 AMinSW3(AW3 a,AW3 b){return AW3(min(ASU3(a),ASU3(b)));}
  AW4 AMinSW4(AW4 a,AW4 b){return AW4(min(ASU4(a),ASU4(b)));}

  AH1 ARcpH1(AH1 x){return AH1_(1.0)/x;}
  AH2 ARcpH2(AH2 x){return AH2_(1.0)/x;}
  AH3 ARcpH3(AH3 x){return AH3_(1.0)/x;}
  AH4 ARcpH4(AH4 x){return AH4_(1.0)/x;}

  AH1 ARsqH1(AH1 x){return AH1_(1.0)/sqrt(x);}
  AH2 ARsqH2(AH2 x){return AH2_(1.0)/sqrt(x);}
  AH3 ARsqH3(AH3 x){return AH3_(1.0)/sqrt(x);}
  AH4 ARsqH4(AH4 x){return AH4_(1.0)/sqrt(x);}

  AH1 ASatH1(AH1 x){return clamp(x,AH1_(0.0),AH1_(1.0));}
  AH2 ASatH2(AH2 x){return clamp(x,AH2_(0.0),AH2_(1.0));}
  AH3 ASatH3(AH3 x){return clamp(x,AH3_(0.0),AH3_(1.0));}
  AH4 ASatH4(AH4 x){return clamp(x,AH4_(0.0),AH4_(1.0));}

  AW1 AShrSW1(AW1 a,AW1 b){return AW1(ASW1(a)>>ASW1(b));}
  AW2 AShrSW2(AW2 a,AW2 b){return AW2(ASW2(a)>>ASW2(b));}
  AW3 AShrSW3(AW3 a,AW3 b){return AW3(ASW3(a)>>ASW3(b));}
  AW4 AShrSW4(AW4 a,AW4 b){return AW4(ASW4(a)>>ASW4(b));}
 #endif






 #ifdef A_DUBL
  #define AD1 double
  #define AD2 dvec2
  #define AD3 dvec3
  #define AD4 dvec4

  AD1 AD1_x(AD1 a){return AD1(a);}
  AD2 AD2_x(AD1 a){return AD2(a,a);}
  AD3 AD3_x(AD1 a){return AD3(a,a,a);}
  AD4 AD4_x(AD1 a){return AD4(a,a,a,a);}
  #define AD1_(a) AD1_x(AD1(a))
  #define AD2_(a) AD2_x(AD1(a))
  #define AD3_(a) AD3_x(AD1(a))
  #define AD4_(a) AD4_x(AD1(a))

  AD1 AFractD1(AD1 x){return fract(x);}
  AD2 AFractD2(AD2 x){return fract(x);}
  AD3 AFractD3(AD3 x){return fract(x);}
  AD4 AFractD4(AD4 x){return fract(x);}

  AD1 ALerpD1(AD1 x,AD1 y,AD1 a){return mix(x,y,a);}
  AD2 ALerpD2(AD2 x,AD2 y,AD2 a){return mix(x,y,a);}
  AD3 ALerpD3(AD3 x,AD3 y,AD3 a){return mix(x,y,a);}
  AD4 ALerpD4(AD4 x,AD4 y,AD4 a){return mix(x,y,a);}

  AD1 ARcpD1(AD1 x){return AD1_(1.0)/x;}
  AD2 ARcpD2(AD2 x){return AD2_(1.0)/x;}
  AD3 ARcpD3(AD3 x){return AD3_(1.0)/x;}
  AD4 ARcpD4(AD4 x){return AD4_(1.0)/x;}

  AD1 ARsqD1(AD1 x){return AD1_(1.0)/sqrt(x);}
  AD2 ARsqD2(AD2 x){return AD2_(1.0)/sqrt(x);}
  AD3 ARsqD3(AD3 x){return AD3_(1.0)/sqrt(x);}
  AD4 ARsqD4(AD4 x){return AD4_(1.0)/sqrt(x);}

  AD1 ASatD1(AD1 x){return clamp(x,AD1_(0.0),AD1_(1.0));}
  AD2 ASatD2(AD2 x){return clamp(x,AD2_(0.0),AD2_(1.0));}
  AD3 ASatD3(AD3 x){return clamp(x,AD3_(0.0),AD3_(1.0));}
  AD4 ASatD4(AD4 x){return clamp(x,AD4_(0.0),AD4_(1.0));}
 #endif






 #ifdef A_LONG
  #define AL1 uint64_t
  #define AL2 u64vec2
  #define AL3 u64vec3
  #define AL4 u64vec4

  #define ASL1 int64_t
  #define ASL2 i64vec2
  #define ASL3 i64vec3
  #define ASL4 i64vec4

  #define AL1_AU2(x) packUint2x32(AU2(x))
  #define AU2_AL1(x) unpackUint2x32(AL1(x))

  AL1 AL1_x(AL1 a){return AL1(a);}
  AL2 AL2_x(AL1 a){return AL2(a,a);}
  AL3 AL3_x(AL1 a){return AL3(a,a,a);}
  AL4 AL4_x(AL1 a){return AL4(a,a,a,a);}
  #define AL1_(a) AL1_x(AL1(a))
  #define AL2_(a) AL2_x(AL1(a))
  #define AL3_(a) AL3_x(AL1(a))
  #define AL4_(a) AL4_x(AL1(a))

  AL1 AAbsSL1(AL1 a){return AL1(abs(ASL1(a)));}
  AL2 AAbsSL2(AL2 a){return AL2(abs(ASL2(a)));}
  AL3 AAbsSL3(AL3 a){return AL3(abs(ASL3(a)));}
  AL4 AAbsSL4(AL4 a){return AL4(abs(ASL4(a)));}

  AL1 AMaxSL1(AL1 a,AL1 b){return AL1(max(ASU1(a),ASU1(b)));}
  AL2 AMaxSL2(AL2 a,AL2 b){return AL2(max(ASU2(a),ASU2(b)));}
  AL3 AMaxSL3(AL3 a,AL3 b){return AL3(max(ASU3(a),ASU3(b)));}
  AL4 AMaxSL4(AL4 a,AL4 b){return AL4(max(ASU4(a),ASU4(b)));}

  AL1 AMinSL1(AL1 a,AL1 b){return AL1(min(ASU1(a),ASU1(b)));}
  AL2 AMinSL2(AL2 a,AL2 b){return AL2(min(ASU2(a),ASU2(b)));}
  AL3 AMinSL3(AL3 a,AL3 b){return AL3(min(ASU3(a),ASU3(b)));}
  AL4 AMinSL4(AL4 a,AL4 b){return AL4(min(ASU4(a),ASU4(b)));}
 #endif






 #ifdef A_WAVE
  
  AF1 AWaveXorF1(AF1 v,AU1 x){return subgroupShuffleXor(v,x);}
  AF2 AWaveXorF2(AF2 v,AU1 x){return subgroupShuffleXor(v,x);}
  AF3 AWaveXorF3(AF3 v,AU1 x){return subgroupShuffleXor(v,x);}
  AF4 AWaveXorF4(AF4 v,AU1 x){return subgroupShuffleXor(v,x);}
  AU1 AWaveXorU1(AU1 v,AU1 x){return subgroupShuffleXor(v,x);}
  AU2 AWaveXorU2(AU2 v,AU1 x){return subgroupShuffleXor(v,x);}
  AU3 AWaveXorU3(AU3 v,AU1 x){return subgroupShuffleXor(v,x);}
  AU4 AWaveXorU4(AU4 v,AU1 x){return subgroupShuffleXor(v,x);}

  #ifdef A_HALF
   AH2 AWaveXorH2(AH2 v,AU1 x){return AH2_AU1(subgroupShuffleXor(AU1_AH2(v),x));}
   AH4 AWaveXorH4(AH4 v,AU1 x){return AH4_AU2(subgroupShuffleXor(AU2_AH4(v),x));}
   AW2 AWaveXorW2(AW2 v,AU1 x){return AW2_AU1(subgroupShuffleXor(AU1_AW2(v),x));}
   AW4 AWaveXorW4(AW4 v,AU1 x){return AW4_AU2(subgroupShuffleXor(AU2_AW4(v),x));}
  #endif
 #endif

#endif














#if defined(A_HLSL) && defined(A_GPU)
 #ifdef A_HLSL_6_2
  #define AP1 bool
  #define AP2 bool2
  #define AP3 bool3
  #define AP4 bool4

  #define AF1 float32_t
  #define AF2 float32_t2
  #define AF3 float32_t3
  #define AF4 float32_t4

  #define AU1 uint32_t
  #define AU2 uint32_t2
  #define AU3 uint32_t3
  #define AU4 uint32_t4

  #define ASU1 int32_t
  #define ASU2 int32_t2
  #define ASU3 int32_t3
  #define ASU4 int32_t4
 #else
  #define AP1 bool
  #define AP2 bool2
  #define AP3 bool3
  #define AP4 bool4

  #define AF1 float
  #define AF2 float2
  #define AF3 float3
  #define AF4 float4

  #define AU1 uint
  #define AU2 uint2
  #define AU3 uint3
  #define AU4 uint4

  #define ASU1 int
  #define ASU2 int2
  #define ASU3 int3
  #define ASU4 int4
 #endif

 #define AF1_AU1(x) asfloat(AU1(x))
 #define AF2_AU2(x) asfloat(AU2(x))
 #define AF3_AU3(x) asfloat(AU3(x))
 #define AF4_AU4(x) asfloat(AU4(x))

 #define AU1_AF1(x) asuint(AF1(x))
 #define AU2_AF2(x) asuint(AF2(x))
 #define AU3_AF3(x) asuint(AF3(x))
 #define AU4_AF4(x) asuint(AF4(x))

 AU1 AU1_AH1_AF1_x(AF1 a){return f32tof16(a);}
 #define AU1_AH1_AF1(a) AU1_AH1_AF1_x(AF1(a))

 AU1 AU1_AH2_AF2_x(AF2 a){return f32tof16(a.x)|(f32tof16(a.y)<<16);}
 #define AU1_AH2_AF2(a) AU1_AH2_AF2_x(AF2(a)) 
 #define AU1_AB4Unorm_AF4(x) D3DCOLORtoUBYTE4(AF4(x))

 AF2 AF2_AH2_AU1_x(AU1 x){return AF2(f16tof32(x&0xFFFF),f16tof32(x>>16));}
 #define AF2_AH2_AU1(x) AF2_AH2_AU1_x(AU1(x))

 AF1 AF1_x(AF1 a){return AF1(a);}
 AF2 AF2_x(AF1 a){return AF2(a,a);}
 AF3 AF3_x(AF1 a){return AF3(a,a,a);}
 AF4 AF4_x(AF1 a){return AF4(a,a,a,a);}
 #define AF1_(a) AF1_x(AF1(a))
 #define AF2_(a) AF2_x(AF1(a))
 #define AF3_(a) AF3_x(AF1(a))
 #define AF4_(a) AF4_x(AF1(a))

 AU1 AU1_x(AU1 a){return AU1(a);}
 AU2 AU2_x(AU1 a){return AU2(a,a);}
 AU3 AU3_x(AU1 a){return AU3(a,a,a);}
 AU4 AU4_x(AU1 a){return AU4(a,a,a,a);}
 #define AU1_(a) AU1_x(AU1(a))
 #define AU2_(a) AU2_x(AU1(a))
 #define AU3_(a) AU3_x(AU1(a))
 #define AU4_(a) AU4_x(AU1(a))

 AU1 AAbsSU1(AU1 a){return AU1(abs(ASU1(a)));}
 AU2 AAbsSU2(AU2 a){return AU2(abs(ASU2(a)));}
 AU3 AAbsSU3(AU3 a){return AU3(abs(ASU3(a)));}
 AU4 AAbsSU4(AU4 a){return AU4(abs(ASU4(a)));}

 AU1 ABfe(AU1 src,AU1 off,AU1 bits){AU1 mask=(1u<<bits)-1;return (src>>off)&mask;}
 AU1 ABfi(AU1 src,AU1 ins,AU1 mask){return (ins&mask)|(src&(~mask));}
 AU1 ABfiM(AU1 src,AU1 ins,AU1 bits){AU1 mask=(1u<<bits)-1;return (ins&mask)|(src&(~mask));}

 AF1 AClampF1(AF1 x,AF1 n,AF1 m){return max(n,min(x,m));}
 AF2 AClampF2(AF2 x,AF2 n,AF2 m){return max(n,min(x,m));}
 AF3 AClampF3(AF3 x,AF3 n,AF3 m){return max(n,min(x,m));}
 AF4 AClampF4(AF4 x,AF4 n,AF4 m){return max(n,min(x,m));}

 AF1 AFractF1(AF1 x){return x-floor(x);}
 AF2 AFractF2(AF2 x){return x-floor(x);}
 AF3 AFractF3(AF3 x){return x-floor(x);}
 AF4 AFractF4(AF4 x){return x-floor(x);}

 AF1 ALerpF1(AF1 x,AF1 y,AF1 a){return lerp(x,y,a);}
 AF2 ALerpF2(AF2 x,AF2 y,AF2 a){return lerp(x,y,a);}
 AF3 ALerpF3(AF3 x,AF3 y,AF3 a){return lerp(x,y,a);}
 AF4 ALerpF4(AF4 x,AF4 y,AF4 a){return lerp(x,y,a);}

 AF1 AMax3F1(AF1 x,AF1 y,AF1 z){return max(x,max(y,z));}
 AF2 AMax3F2(AF2 x,AF2 y,AF2 z){return max(x,max(y,z));}
 AF3 AMax3F3(AF3 x,AF3 y,AF3 z){return max(x,max(y,z));}
 AF4 AMax3F4(AF4 x,AF4 y,AF4 z){return max(x,max(y,z));}

 AU1 AMax3SU1(AU1 x,AU1 y,AU1 z){return AU1(max(ASU1(x),max(ASU1(y),ASU1(z))));}
 AU2 AMax3SU2(AU2 x,AU2 y,AU2 z){return AU2(max(ASU2(x),max(ASU2(y),ASU2(z))));}
 AU3 AMax3SU3(AU3 x,AU3 y,AU3 z){return AU3(max(ASU3(x),max(ASU3(y),ASU3(z))));}
 AU4 AMax3SU4(AU4 x,AU4 y,AU4 z){return AU4(max(ASU4(x),max(ASU4(y),ASU4(z))));}

 AU1 AMax3U1(AU1 x,AU1 y,AU1 z){return max(x,max(y,z));}
 AU2 AMax3U2(AU2 x,AU2 y,AU2 z){return max(x,max(y,z));}
 AU3 AMax3U3(AU3 x,AU3 y,AU3 z){return max(x,max(y,z));}
 AU4 AMax3U4(AU4 x,AU4 y,AU4 z){return max(x,max(y,z));}

 AU1 AMaxSU1(AU1 a,AU1 b){return AU1(max(ASU1(a),ASU1(b)));}
 AU2 AMaxSU2(AU2 a,AU2 b){return AU2(max(ASU2(a),ASU2(b)));}
 AU3 AMaxSU3(AU3 a,AU3 b){return AU3(max(ASU3(a),ASU3(b)));}
 AU4 AMaxSU4(AU4 a,AU4 b){return AU4(max(ASU4(a),ASU4(b)));}

 AF1 AMed3F1(AF1 x,AF1 y,AF1 z){return max(min(x,y),min(max(x,y),z));}
 AF2 AMed3F2(AF2 x,AF2 y,AF2 z){return max(min(x,y),min(max(x,y),z));}
 AF3 AMed3F3(AF3 x,AF3 y,AF3 z){return max(min(x,y),min(max(x,y),z));}
 AF4 AMed3F4(AF4 x,AF4 y,AF4 z){return max(min(x,y),min(max(x,y),z));}

 AF1 AMin3F1(AF1 x,AF1 y,AF1 z){return min(x,min(y,z));}
 AF2 AMin3F2(AF2 x,AF2 y,AF2 z){return min(x,min(y,z));}
 AF3 AMin3F3(AF3 x,AF3 y,AF3 z){return min(x,min(y,z));}
 AF4 AMin3F4(AF4 x,AF4 y,AF4 z){return min(x,min(y,z));}

 AU1 AMin3SU1(AU1 x,AU1 y,AU1 z){return AU1(min(ASU1(x),min(ASU1(y),ASU1(z))));}
 AU2 AMin3SU2(AU2 x,AU2 y,AU2 z){return AU2(min(ASU2(x),min(ASU2(y),ASU2(z))));}
 AU3 AMin3SU3(AU3 x,AU3 y,AU3 z){return AU3(min(ASU3(x),min(ASU3(y),ASU3(z))));}
 AU4 AMin3SU4(AU4 x,AU4 y,AU4 z){return AU4(min(ASU4(x),min(ASU4(y),ASU4(z))));}

 AU1 AMin3U1(AU1 x,AU1 y,AU1 z){return min(x,min(y,z));}
 AU2 AMin3U2(AU2 x,AU2 y,AU2 z){return min(x,min(y,z));}
 AU3 AMin3U3(AU3 x,AU3 y,AU3 z){return min(x,min(y,z));}
 AU4 AMin3U4(AU4 x,AU4 y,AU4 z){return min(x,min(y,z));}

 AU1 AMinSU1(AU1 a,AU1 b){return AU1(min(ASU1(a),ASU1(b)));}
 AU2 AMinSU2(AU2 a,AU2 b){return AU2(min(ASU2(a),ASU2(b)));}
 AU3 AMinSU3(AU3 a,AU3 b){return AU3(min(ASU3(a),ASU3(b)));}
 AU4 AMinSU4(AU4 a,AU4 b){return AU4(min(ASU4(a),ASU4(b)));}

 AF1 ANCosF1(AF1 x){return cos(x*AF1_(A_2PI));}
 AF2 ANCosF2(AF2 x){return cos(x*AF2_(A_2PI));}
 AF3 ANCosF3(AF3 x){return cos(x*AF3_(A_2PI));}
 AF4 ANCosF4(AF4 x){return cos(x*AF4_(A_2PI));}

 AF1 ANSinF1(AF1 x){return sin(x*AF1_(A_2PI));}
 AF2 ANSinF2(AF2 x){return sin(x*AF2_(A_2PI));}
 AF3 ANSinF3(AF3 x){return sin(x*AF3_(A_2PI));}
 AF4 ANSinF4(AF4 x){return sin(x*AF4_(A_2PI));}

 AF1 ARcpF1(AF1 x){return rcp(x);}
 AF2 ARcpF2(AF2 x){return rcp(x);}
 AF3 ARcpF3(AF3 x){return rcp(x);}
 AF4 ARcpF4(AF4 x){return rcp(x);}

 AF1 ARsqF1(AF1 x){return rsqrt(x);}
 AF2 ARsqF2(AF2 x){return rsqrt(x);}
 AF3 ARsqF3(AF3 x){return rsqrt(x);}
 AF4 ARsqF4(AF4 x){return rsqrt(x);}

 AF1 ASatF1(AF1 x){return saturate(x);}
 AF2 ASatF2(AF2 x){return saturate(x);}
 AF3 ASatF3(AF3 x){return saturate(x);}
 AF4 ASatF4(AF4 x){return saturate(x);}

 AU1 AShrSU1(AU1 a,AU1 b){return AU1(ASU1(a)>>ASU1(b));}
 AU2 AShrSU2(AU2 a,AU2 b){return AU2(ASU2(a)>>ASU2(b));}
 AU3 AShrSU3(AU3 a,AU3 b){return AU3(ASU3(a)>>ASU3(b));}
 AU4 AShrSU4(AU4 a,AU4 b){return AU4(ASU4(a)>>ASU4(b));}






 #ifdef A_BYTE
 #endif






 #ifdef A_HALF
  #ifdef A_HLSL_6_2
   #define AH1 float16_t
   #define AH2 float16_t2
   #define AH3 float16_t3
   #define AH4 float16_t4

   #define AW1 uint16_t
   #define AW2 uint16_t2
   #define AW3 uint16_t3
   #define AW4 uint16_t4

   #define ASW1 int16_t
   #define ASW2 int16_t2
   #define ASW3 int16_t3
   #define ASW4 int16_t4
  #else
   #define AH1 min16float
   #define AH2 min16float2
   #define AH3 min16float3
   #define AH4 min16float4

   #define AW1 min16uint
   #define AW2 min16uint2
   #define AW3 min16uint3
   #define AW4 min16uint4

   #define ASW1 min16int
   #define ASW2 min16int2
   #define ASW3 min16int3
   #define ASW4 min16int4
  #endif

  
  
  AH2 AH2_AU1_x(AU1 x){AF2 t=f16tof32(AU2(x&0xFFFF,x>>16));return AH2(t);}
  AH4 AH4_AU2_x(AU2 x){return AH4(AH2_AU1_x(x.x),AH2_AU1_x(x.y));}
  AW2 AW2_AU1_x(AU1 x){AU2 t=AU2(x&0xFFFF,x>>16);return AW2(t);}
  AW4 AW4_AU2_x(AU2 x){return AW4(AW2_AU1_x(x.x),AW2_AU1_x(x.y));}
  #define AH2_AU1(x) AH2_AU1_x(AU1(x))
  #define AH4_AU2(x) AH4_AU2_x(AU2(x))
  #define AW2_AU1(x) AW2_AU1_x(AU1(x))
  #define AW4_AU2(x) AW4_AU2_x(AU2(x))

  AU1 AU1_AH2_x(AH2 x){return f32tof16(x.x)+(f32tof16(x.y)<<16);}
  AU2 AU2_AH4_x(AH4 x){return AU2(AU1_AH2_x(x.xy),AU1_AH2_x(x.zw));}
  AU1 AU1_AW2_x(AW2 x){return AU1(x.x)+(AU1(x.y)<<16);}
  AU2 AU2_AW4_x(AW4 x){return AU2(AU1_AW2_x(x.xy),AU1_AW2_x(x.zw));}
  #define AU1_AH2(x) AU1_AH2_x(AH2(x))
  #define AU2_AH4(x) AU2_AH4_x(AH4(x))
  #define AU1_AW2(x) AU1_AW2_x(AW2(x))
  #define AU2_AW4(x) AU2_AW4_x(AW4(x))

  #if defined(A_HLSL_6_2) && !defined(A_NO_16_BIT_CAST)
   #define AW1_AH1(x) asuint16(x)
   #define AW2_AH2(x) asuint16(x)
   #define AW3_AH3(x) asuint16(x)
   #define AW4_AH4(x) asuint16(x)
  #else
   #define AW1_AH1(a) AW1(f32tof16(AF1(a)))
   #define AW2_AH2(a) AW2(AW1_AH1((a).x),AW1_AH1((a).y))
   #define AW3_AH3(a) AW3(AW1_AH1((a).x),AW1_AH1((a).y),AW1_AH1((a).z))
   #define AW4_AH4(a) AW4(AW1_AH1((a).x),AW1_AH1((a).y),AW1_AH1((a).z),AW1_AH1((a).w))
  #endif

  #if defined(A_HLSL_6_2) && !defined(A_NO_16_BIT_CAST)
   #define AH1_AW1(x) asfloat16(x)
   #define AH2_AW2(x) asfloat16(x)
   #define AH3_AW3(x) asfloat16(x)
   #define AH4_AW4(x) asfloat16(x)
  #else
   #define AH1_AW1(a) AH1(f16tof32(AU1(a)))
   #define AH2_AW2(a) AH2(AH1_AW1((a).x),AH1_AW1((a).y))
   #define AH3_AW3(a) AH3(AH1_AW1((a).x),AH1_AW1((a).y),AH1_AW1((a).z))
   #define AH4_AW4(a) AH4(AH1_AW1((a).x),AH1_AW1((a).y),AH1_AW1((a).z),AH1_AW1((a).w))
  #endif

  AH1 AH1_x(AH1 a){return AH1(a);}
  AH2 AH2_x(AH1 a){return AH2(a,a);}
  AH3 AH3_x(AH1 a){return AH3(a,a,a);}
  AH4 AH4_x(AH1 a){return AH4(a,a,a,a);}
  #define AH1_(a) AH1_x(AH1(a))
  #define AH2_(a) AH2_x(AH1(a))
  #define AH3_(a) AH3_x(AH1(a))
  #define AH4_(a) AH4_x(AH1(a))

  AW1 AW1_x(AW1 a){return AW1(a);}
  AW2 AW2_x(AW1 a){return AW2(a,a);}
  AW3 AW3_x(AW1 a){return AW3(a,a,a);}
  AW4 AW4_x(AW1 a){return AW4(a,a,a,a);}
  #define AW1_(a) AW1_x(AW1(a))
  #define AW2_(a) AW2_x(AW1(a))
  #define AW3_(a) AW3_x(AW1(a))
  #define AW4_(a) AW4_x(AW1(a))

  AW1 AAbsSW1(AW1 a){return AW1(abs(ASW1(a)));}
  AW2 AAbsSW2(AW2 a){return AW2(abs(ASW2(a)));}
  AW3 AAbsSW3(AW3 a){return AW3(abs(ASW3(a)));}
  AW4 AAbsSW4(AW4 a){return AW4(abs(ASW4(a)));}

  AH1 AClampH1(AH1 x,AH1 n,AH1 m){return max(n,min(x,m));}
  AH2 AClampH2(AH2 x,AH2 n,AH2 m){return max(n,min(x,m));}
  AH3 AClampH3(AH3 x,AH3 n,AH3 m){return max(n,min(x,m));}
  AH4 AClampH4(AH4 x,AH4 n,AH4 m){return max(n,min(x,m));}

 
  AH1 AFractH1(AH1 x){return x-floor(x);}
  AH2 AFractH2(AH2 x){return x-floor(x);}
  AH3 AFractH3(AH3 x){return x-floor(x);}
  AH4 AFractH4(AH4 x){return x-floor(x);}

  AH1 ALerpH1(AH1 x,AH1 y,AH1 a){return lerp(x,y,a);}
  AH2 ALerpH2(AH2 x,AH2 y,AH2 a){return lerp(x,y,a);}
  AH3 ALerpH3(AH3 x,AH3 y,AH3 a){return lerp(x,y,a);}
  AH4 ALerpH4(AH4 x,AH4 y,AH4 a){return lerp(x,y,a);}

  AH1 AMax3H1(AH1 x,AH1 y,AH1 z){return max(x,max(y,z));}
  AH2 AMax3H2(AH2 x,AH2 y,AH2 z){return max(x,max(y,z));}
  AH3 AMax3H3(AH3 x,AH3 y,AH3 z){return max(x,max(y,z));}
  AH4 AMax3H4(AH4 x,AH4 y,AH4 z){return max(x,max(y,z));}

  AW1 AMaxSW1(AW1 a,AW1 b){return AW1(max(ASU1(a),ASU1(b)));}
  AW2 AMaxSW2(AW2 a,AW2 b){return AW2(max(ASU2(a),ASU2(b)));}
  AW3 AMaxSW3(AW3 a,AW3 b){return AW3(max(ASU3(a),ASU3(b)));}
  AW4 AMaxSW4(AW4 a,AW4 b){return AW4(max(ASU4(a),ASU4(b)));}
)<!>" R"<!>(
  AH1 AMin3H1(AH1 x,AH1 y,AH1 z){return min(x,min(y,z));}
  AH2 AMin3H2(AH2 x,AH2 y,AH2 z){return min(x,min(y,z));}
  AH3 AMin3H3(AH3 x,AH3 y,AH3 z){return min(x,min(y,z));}
  AH4 AMin3H4(AH4 x,AH4 y,AH4 z){return min(x,min(y,z));}

  AW1 AMinSW1(AW1 a,AW1 b){return AW1(min(ASU1(a),ASU1(b)));}
  AW2 AMinSW2(AW2 a,AW2 b){return AW2(min(ASU2(a),ASU2(b)));}
  AW3 AMinSW3(AW3 a,AW3 b){return AW3(min(ASU3(a),ASU3(b)));}
  AW4 AMinSW4(AW4 a,AW4 b){return AW4(min(ASU4(a),ASU4(b)));}

  AH1 ARcpH1(AH1 x){return rcp(x);}
  AH2 ARcpH2(AH2 x){return rcp(x);}
  AH3 ARcpH3(AH3 x){return rcp(x);}
  AH4 ARcpH4(AH4 x){return rcp(x);}

  AH1 ARsqH1(AH1 x){return rsqrt(x);}
  AH2 ARsqH2(AH2 x){return rsqrt(x);}
  AH3 ARsqH3(AH3 x){return rsqrt(x);}
  AH4 ARsqH4(AH4 x){return rsqrt(x);}

  AH1 ASatH1(AH1 x){return saturate(x);}
  AH2 ASatH2(AH2 x){return saturate(x);}
  AH3 ASatH3(AH3 x){return saturate(x);}
  AH4 ASatH4(AH4 x){return saturate(x);}

  AW1 AShrSW1(AW1 a,AW1 b){return AW1(ASW1(a)>>ASW1(b));}
  AW2 AShrSW2(AW2 a,AW2 b){return AW2(ASW2(a)>>ASW2(b));}
  AW3 AShrSW3(AW3 a,AW3 b){return AW3(ASW3(a)>>ASW3(b));}
  AW4 AShrSW4(AW4 a,AW4 b){return AW4(ASW4(a)>>ASW4(b));}
 #endif






 #ifdef A_DUBL
  #ifdef A_HLSL_6_2
   #define AD1 float64_t
   #define AD2 float64_t2
   #define AD3 float64_t3
   #define AD4 float64_t4
  #else
   #define AD1 double
   #define AD2 double2
   #define AD3 double3
   #define AD4 double4
  #endif

  AD1 AD1_x(AD1 a){return AD1(a);}
  AD2 AD2_x(AD1 a){return AD2(a,a);}
  AD3 AD3_x(AD1 a){return AD3(a,a,a);}
  AD4 AD4_x(AD1 a){return AD4(a,a,a,a);}
  #define AD1_(a) AD1_x(AD1(a))
  #define AD2_(a) AD2_x(AD1(a))
  #define AD3_(a) AD3_x(AD1(a))
  #define AD4_(a) AD4_x(AD1(a))

  AD1 AFractD1(AD1 a){return a-floor(a);}
  AD2 AFractD2(AD2 a){return a-floor(a);}
  AD3 AFractD3(AD3 a){return a-floor(a);}
  AD4 AFractD4(AD4 a){return a-floor(a);}

  AD1 ALerpD1(AD1 x,AD1 y,AD1 a){return lerp(x,y,a);}
  AD2 ALerpD2(AD2 x,AD2 y,AD2 a){return lerp(x,y,a);}
  AD3 ALerpD3(AD3 x,AD3 y,AD3 a){return lerp(x,y,a);}
  AD4 ALerpD4(AD4 x,AD4 y,AD4 a){return lerp(x,y,a);}

  AD1 ARcpD1(AD1 x){return rcp(x);}
  AD2 ARcpD2(AD2 x){return rcp(x);}
  AD3 ARcpD3(AD3 x){return rcp(x);}
  AD4 ARcpD4(AD4 x){return rcp(x);}

  AD1 ARsqD1(AD1 x){return rsqrt(x);}
  AD2 ARsqD2(AD2 x){return rsqrt(x);}
  AD3 ARsqD3(AD3 x){return rsqrt(x);}
  AD4 ARsqD4(AD4 x){return rsqrt(x);}

  AD1 ASatD1(AD1 x){return saturate(x);}
  AD2 ASatD2(AD2 x){return saturate(x);}
  AD3 ASatD3(AD3 x){return saturate(x);}
  AD4 ASatD4(AD4 x){return saturate(x);}
 #endif



 #ifdef A_WAVE
  
  AF1 AWaveXorF1(AF1 v,AU1 x){return WaveReadLaneAt(v,WaveGetLaneIndex()^x);}
  AF2 AWaveXorF2(AF2 v,AU1 x){return WaveReadLaneAt(v,WaveGetLaneIndex()^x);}
  AF3 AWaveXorF3(AF3 v,AU1 x){return WaveReadLaneAt(v,WaveGetLaneIndex()^x);}
  AF4 AWaveXorF4(AF4 v,AU1 x){return WaveReadLaneAt(v,WaveGetLaneIndex()^x);}
  AU1 AWaveXorU1(AU1 v,AU1 x){return WaveReadLaneAt(v,WaveGetLaneIndex()^x);}
  AU2 AWaveXorU1(AU2 v,AU1 x){return WaveReadLaneAt(v,WaveGetLaneIndex()^x);}
  AU3 AWaveXorU1(AU3 v,AU1 x){return WaveReadLaneAt(v,WaveGetLaneIndex()^x);}
  AU4 AWaveXorU1(AU4 v,AU1 x){return WaveReadLaneAt(v,WaveGetLaneIndex()^x);}

  #ifdef A_HALF
   AH2 AWaveXorH2(AH2 v,AU1 x){return AH2_AU1(WaveReadLaneAt(AU1_AH2(v),WaveGetLaneIndex()^x));}
   AH4 AWaveXorH4(AH4 v,AU1 x){return AH4_AU2(WaveReadLaneAt(AU2_AH4(v),WaveGetLaneIndex()^x));}
   AW2 AWaveXorW2(AW2 v,AU1 x){return AW2_AU1(WaveReadLaneAt(AU1_AW2(v),WaveGetLaneIndex()^x));}
   AW4 AWaveXorW4(AW4 v,AU1 x){return AW4_AU1(WaveReadLaneAt(AU1_AW4(v),WaveGetLaneIndex()^x));}
  #endif
 #endif

#endif














#ifdef A_GPU
 
 #define A_INFP_F AF1_AU1(0x7f800000u)
 #define A_INFN_F AF1_AU1(0xff800000u)

 
 AF1 ACpySgnF1(AF1 d,AF1 s){return AF1_AU1(AU1_AF1(d)|(AU1_AF1(s)&AU1_(0x80000000u)));}
 AF2 ACpySgnF2(AF2 d,AF2 s){return AF2_AU2(AU2_AF2(d)|(AU2_AF2(s)&AU2_(0x80000000u)));}
 AF3 ACpySgnF3(AF3 d,AF3 s){return AF3_AU3(AU3_AF3(d)|(AU3_AF3(s)&AU3_(0x80000000u)));}
 AF4 ACpySgnF4(AF4 d,AF4 s){return AF4_AU4(AU4_AF4(d)|(AU4_AF4(s)&AU4_(0x80000000u)));}

 
 
 
 
 
 
 
 
 AF1 ASignedF1(AF1 m){return ASatF1(m*AF1_(A_INFN_F));}
 AF2 ASignedF2(AF2 m){return ASatF2(m*AF2_(A_INFN_F));}
 AF3 ASignedF3(AF3 m){return ASatF3(m*AF3_(A_INFN_F));}
 AF4 ASignedF4(AF4 m){return ASatF4(m*AF4_(A_INFN_F));}

 AF1 AGtZeroF1(AF1 m){return ASatF1(m*AF1_(A_INFP_F));}
 AF2 AGtZeroF2(AF2 m){return ASatF2(m*AF2_(A_INFP_F));}
 AF3 AGtZeroF3(AF3 m){return ASatF3(m*AF3_(A_INFP_F));}
 AF4 AGtZeroF4(AF4 m){return ASatF4(m*AF4_(A_INFP_F));}

 #ifdef A_HALF
  #ifdef A_HLSL_6_2
   #define A_INFP_H AH1_AW1((uint16_t)0x7c00u)
   #define A_INFN_H AH1_AW1((uint16_t)0xfc00u)
  #else
   #define A_INFP_H AH1_AW1(0x7c00u)
   #define A_INFN_H AH1_AW1(0xfc00u)
  #endif


  AH1 ACpySgnH1(AH1 d,AH1 s){return AH1_AW1(AW1_AH1(d)|(AW1_AH1(s)&AW1_(0x8000u)));}
  AH2 ACpySgnH2(AH2 d,AH2 s){return AH2_AW2(AW2_AH2(d)|(AW2_AH2(s)&AW2_(0x8000u)));}
  AH3 ACpySgnH3(AH3 d,AH3 s){return AH3_AW3(AW3_AH3(d)|(AW3_AH3(s)&AW3_(0x8000u)));}
  AH4 ACpySgnH4(AH4 d,AH4 s){return AH4_AW4(AW4_AH4(d)|(AW4_AH4(s)&AW4_(0x8000u)));}

  AH1 ASignedH1(AH1 m){return ASatH1(m*AH1_(A_INFN_H));}
  AH2 ASignedH2(AH2 m){return ASatH2(m*AH2_(A_INFN_H));}
  AH3 ASignedH3(AH3 m){return ASatH3(m*AH3_(A_INFN_H));}
  AH4 ASignedH4(AH4 m){return ASatH4(m*AH4_(A_INFN_H));}

  AH1 AGtZeroH1(AH1 m){return ASatH1(m*AH1_(A_INFP_H));}
  AH2 AGtZeroH2(AH2 m){return ASatH2(m*AH2_(A_INFP_H));}
  AH3 AGtZeroH3(AH3 m){return ASatH3(m*AH3_(A_INFP_H));}
  AH4 AGtZeroH4(AH4 m){return ASatH4(m*AH4_(A_INFP_H));}
 #endif

















 AU1 AFisToU1(AU1 x){return x^(( AShrSU1(x,AU1_(31)))|AU1_(0x80000000));}
 AU1 AFisFromU1(AU1 x){return x^((~AShrSU1(x,AU1_(31)))|AU1_(0x80000000));}

 
 AU1 AFisToHiU1(AU1 x){return x^(( AShrSU1(x,AU1_(15)))|AU1_(0x80000000));}
 AU1 AFisFromHiU1(AU1 x){return x^((~AShrSU1(x,AU1_(15)))|AU1_(0x80000000));}

 #ifdef A_HALF
  AW1 AFisToW1(AW1 x){return x^(( AShrSW1(x,AW1_(15)))|AW1_(0x8000));}
  AW1 AFisFromW1(AW1 x){return x^((~AShrSW1(x,AW1_(15)))|AW1_(0x8000));}

  AW2 AFisToW2(AW2 x){return x^(( AShrSW2(x,AW2_(15)))|AW2_(0x8000));}
  AW2 AFisFromW2(AW2 x){return x^((~AShrSW2(x,AW2_(15)))|AW2_(0x8000));}
 #endif

















 #ifdef A_HALF
  AU1 APerm0E0A(AU2 i){return((i.x    )&0xffu)|((i.y<<16)&0xff0000u);}
  AU1 APerm0F0B(AU2 i){return((i.x>> 8)&0xffu)|((i.y<< 8)&0xff0000u);}
  AU1 APerm0G0C(AU2 i){return((i.x>>16)&0xffu)|((i.y    )&0xff0000u);}
  AU1 APerm0H0D(AU2 i){return((i.x>>24)&0xffu)|((i.y>> 8)&0xff0000u);}

  AU1 APermHGFA(AU2 i){return((i.x    )&0x000000ffu)|(i.y&0xffffff00u);}
  AU1 APermHGFC(AU2 i){return((i.x>>16)&0x000000ffu)|(i.y&0xffffff00u);}
  AU1 APermHGAE(AU2 i){return((i.x<< 8)&0x0000ff00u)|(i.y&0xffff00ffu);}
  AU1 APermHGCE(AU2 i){return((i.x>> 8)&0x0000ff00u)|(i.y&0xffff00ffu);}
  AU1 APermHAFE(AU2 i){return((i.x<<16)&0x00ff0000u)|(i.y&0xff00ffffu);}
  AU1 APermHCFE(AU2 i){return((i.x    )&0x00ff0000u)|(i.y&0xff00ffffu);}
  AU1 APermAGFE(AU2 i){return((i.x<<24)&0xff000000u)|(i.y&0x00ffffffu);}
  AU1 APermCGFE(AU2 i){return((i.x<< 8)&0xff000000u)|(i.y&0x00ffffffu);}

  AU1 APermGCEA(AU2 i){return((i.x)&0x00ff00ffu)|((i.y<<8)&0xff00ff00u);}
  AU1 APermGECA(AU2 i){return(((i.x)&0xffu)|((i.x>>8)&0xff00u)|((i.y<<16)&0xff0000u)|((i.y<<8)&0xff000000u));}
 #endif


























































 
 #define A_BUC_32 (255.0)
 #define A_BUC_16 (255.0/512.0)

 #if 1
  
  
  AU1 ABuc0ToU1(AU1 d,AF1 i){return (d&0xffffff00u)|((min(AU1(i),255u)    )&(0x000000ffu));}
  AU1 ABuc1ToU1(AU1 d,AF1 i){return (d&0xffff00ffu)|((min(AU1(i),255u)<< 8)&(0x0000ff00u));}
  AU1 ABuc2ToU1(AU1 d,AF1 i){return (d&0xff00ffffu)|((min(AU1(i),255u)<<16)&(0x00ff0000u));}
  AU1 ABuc3ToU1(AU1 d,AF1 i){return (d&0x00ffffffu)|((min(AU1(i),255u)<<24)&(0xff000000u));}

  
  AF1 ABuc0FromU1(AU1 i){return AF1((i    )&255u);}
  AF1 ABuc1FromU1(AU1 i){return AF1((i>> 8)&255u);}
  AF1 ABuc2FromU1(AU1 i){return AF1((i>>16)&255u);}
  AF1 ABuc3FromU1(AU1 i){return AF1((i>>24)&255u);}
 #endif

 #ifdef A_HALF
  
  AW2 ABuc01ToW2(AH2 x,AH2 y){x*=AH2_(1.0/32768.0);y*=AH2_(1.0/32768.0);
   return AW2_AU1(APermGCEA(AU2(AU1_AW2(AW2_AH2(x)),AU1_AW2(AW2_AH2(y)))));}

  
  AU2 ABuc0ToU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)));
   return AU2(APermHGFA(AU2(d.x,b)),APermHGFC(AU2(d.y,b)));}
  AU2 ABuc1ToU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)));
   return AU2(APermHGAE(AU2(d.x,b)),APermHGCE(AU2(d.y,b)));}
  AU2 ABuc2ToU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)));
   return AU2(APermHAFE(AU2(d.x,b)),APermHCFE(AU2(d.y,b)));}
  AU2 ABuc3ToU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)));
   return AU2(APermAGFE(AU2(d.x,b)),APermCGFE(AU2(d.y,b)));}

  
  AH2 ABuc0FromU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0E0A(i)))*AH2_(32768.0);}
  AH2 ABuc1FromU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0F0B(i)))*AH2_(32768.0);}
  AH2 ABuc2FromU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0G0C(i)))*AH2_(32768.0);}
  AH2 ABuc3FromU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0H0D(i)))*AH2_(32768.0);}
 #endif






























 
 #define A_BSC_32 (127.0)
 #define A_BSC_16 (127.0/512.0)

 #if 1
  AU1 ABsc0ToU1(AU1 d,AF1 i){return (d&0xffffff00u)|((min(AU1(i+128.0),255u)    )&(0x000000ffu));}
  AU1 ABsc1ToU1(AU1 d,AF1 i){return (d&0xffff00ffu)|((min(AU1(i+128.0),255u)<< 8)&(0x0000ff00u));}
  AU1 ABsc2ToU1(AU1 d,AF1 i){return (d&0xff00ffffu)|((min(AU1(i+128.0),255u)<<16)&(0x00ff0000u));}
  AU1 ABsc3ToU1(AU1 d,AF1 i){return (d&0x00ffffffu)|((min(AU1(i+128.0),255u)<<24)&(0xff000000u));}

  AU1 ABsc0ToZbU1(AU1 d,AF1 i){return ((d&0xffffff00u)|((min(AU1(trunc(i)+128.0),255u)    )&(0x000000ffu)))^0x00000080u;}
  AU1 ABsc1ToZbU1(AU1 d,AF1 i){return ((d&0xffff00ffu)|((min(AU1(trunc(i)+128.0),255u)<< 8)&(0x0000ff00u)))^0x00008000u;}
  AU1 ABsc2ToZbU1(AU1 d,AF1 i){return ((d&0xff00ffffu)|((min(AU1(trunc(i)+128.0),255u)<<16)&(0x00ff0000u)))^0x00800000u;}
  AU1 ABsc3ToZbU1(AU1 d,AF1 i){return ((d&0x00ffffffu)|((min(AU1(trunc(i)+128.0),255u)<<24)&(0xff000000u)))^0x80000000u;}

  AF1 ABsc0FromU1(AU1 i){return AF1((i    )&255u)-128.0;}
  AF1 ABsc1FromU1(AU1 i){return AF1((i>> 8)&255u)-128.0;}
  AF1 ABsc2FromU1(AU1 i){return AF1((i>>16)&255u)-128.0;}
  AF1 ABsc3FromU1(AU1 i){return AF1((i>>24)&255u)-128.0;}

  AF1 ABsc0FromZbU1(AU1 i){return AF1(((i    )&255u)^0x80u)-128.0;}
  AF1 ABsc1FromZbU1(AU1 i){return AF1(((i>> 8)&255u)^0x80u)-128.0;}
  AF1 ABsc2FromZbU1(AU1 i){return AF1(((i>>16)&255u)^0x80u)-128.0;}
  AF1 ABsc3FromZbU1(AU1 i){return AF1(((i>>24)&255u)^0x80u)-128.0;}
 #endif

 #ifdef A_HALF
  
  AW2 ABsc01ToW2(AH2 x,AH2 y){x=x*AH2_(1.0/32768.0)+AH2_(0.25/32768.0);y=y*AH2_(1.0/32768.0)+AH2_(0.25/32768.0);
   return AW2_AU1(APermGCEA(AU2(AU1_AW2(AW2_AH2(x)),AU1_AW2(AW2_AH2(y)))));}

  AU2 ABsc0ToU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)+AH2_(0.25/32768.0)));
   return AU2(APermHGFA(AU2(d.x,b)),APermHGFC(AU2(d.y,b)));}
  AU2 ABsc1ToU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)+AH2_(0.25/32768.0)));
   return AU2(APermHGAE(AU2(d.x,b)),APermHGCE(AU2(d.y,b)));}
  AU2 ABsc2ToU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)+AH2_(0.25/32768.0)));
   return AU2(APermHAFE(AU2(d.x,b)),APermHCFE(AU2(d.y,b)));}
  AU2 ABsc3ToU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)+AH2_(0.25/32768.0)));
   return AU2(APermAGFE(AU2(d.x,b)),APermCGFE(AU2(d.y,b)));}

  AU2 ABsc0ToZbU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)+AH2_(0.25/32768.0)))^0x00800080u;
   return AU2(APermHGFA(AU2(d.x,b)),APermHGFC(AU2(d.y,b)));}
  AU2 ABsc1ToZbU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)+AH2_(0.25/32768.0)))^0x00800080u;
   return AU2(APermHGAE(AU2(d.x,b)),APermHGCE(AU2(d.y,b)));}
  AU2 ABsc2ToZbU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)+AH2_(0.25/32768.0)))^0x00800080u;
   return AU2(APermHAFE(AU2(d.x,b)),APermHCFE(AU2(d.y,b)));}
  AU2 ABsc3ToZbU2(AU2 d,AH2 i){AU1 b=AU1_AW2(AW2_AH2(i*AH2_(1.0/32768.0)+AH2_(0.25/32768.0)))^0x00800080u;
   return AU2(APermAGFE(AU2(d.x,b)),APermCGFE(AU2(d.y,b)));}

  AH2 ABsc0FromU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0E0A(i)))*AH2_(32768.0)-AH2_(0.25);}
  AH2 ABsc1FromU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0F0B(i)))*AH2_(32768.0)-AH2_(0.25);}
  AH2 ABsc2FromU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0G0C(i)))*AH2_(32768.0)-AH2_(0.25);}
  AH2 ABsc3FromU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0H0D(i)))*AH2_(32768.0)-AH2_(0.25);}

  AH2 ABsc0FromZbU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0E0A(i)^0x00800080u))*AH2_(32768.0)-AH2_(0.25);}
  AH2 ABsc1FromZbU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0F0B(i)^0x00800080u))*AH2_(32768.0)-AH2_(0.25);}
  AH2 ABsc2FromZbU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0G0C(i)^0x00800080u))*AH2_(32768.0)-AH2_(0.25);}
  AH2 ABsc3FromZbU2(AU2 i){return AH2_AW2(AW2_AU1(APerm0H0D(i)^0x00800080u))*AH2_(32768.0)-AH2_(0.25);}
 #endif
















 #ifdef A_HALF
  
  
  AH1 APrxLoSqrtH1(AH1 a){return AH1_AW1((AW1_AH1(a)>>AW1_(1))+AW1_(0x1de2));}
  AH2 APrxLoSqrtH2(AH2 a){return AH2_AW2((AW2_AH2(a)>>AW2_(1))+AW2_(0x1de2));}
  AH3 APrxLoSqrtH3(AH3 a){return AH3_AW3((AW3_AH3(a)>>AW3_(1))+AW3_(0x1de2));}
  AH4 APrxLoSqrtH4(AH4 a){return AH4_AW4((AW4_AH4(a)>>AW4_(1))+AW4_(0x1de2));}

  
  
  AH1 APrxLoRcpH1(AH1 a){return AH1_AW1(AW1_(0x7784)-AW1_AH1(a));}
  AH2 APrxLoRcpH2(AH2 a){return AH2_AW2(AW2_(0x7784)-AW2_AH2(a));}
  AH3 APrxLoRcpH3(AH3 a){return AH3_AW3(AW3_(0x7784)-AW3_AH3(a));}
  AH4 APrxLoRcpH4(AH4 a){return AH4_AW4(AW4_(0x7784)-AW4_AH4(a));}

  
  AH1 APrxMedRcpH1(AH1 a){AH1 b=AH1_AW1(AW1_(0x778d)-AW1_AH1(a));return b*(-b*a+AH1_(2.0));}
  AH2 APrxMedRcpH2(AH2 a){AH2 b=AH2_AW2(AW2_(0x778d)-AW2_AH2(a));return b*(-b*a+AH2_(2.0));}
  AH3 APrxMedRcpH3(AH3 a){AH3 b=AH3_AW3(AW3_(0x778d)-AW3_AH3(a));return b*(-b*a+AH3_(2.0));}
  AH4 APrxMedRcpH4(AH4 a){AH4 b=AH4_AW4(AW4_(0x778d)-AW4_AH4(a));return b*(-b*a+AH4_(2.0));}

  
  AH1 APrxLoRsqH1(AH1 a){return AH1_AW1(AW1_(0x59a3)-(AW1_AH1(a)>>AW1_(1)));}
  AH2 APrxLoRsqH2(AH2 a){return AH2_AW2(AW2_(0x59a3)-(AW2_AH2(a)>>AW2_(1)));}
  AH3 APrxLoRsqH3(AH3 a){return AH3_AW3(AW3_(0x59a3)-(AW3_AH3(a)>>AW3_(1)));}
  AH4 APrxLoRsqH4(AH4 a){return AH4_AW4(AW4_(0x59a3)-(AW4_AH4(a)>>AW4_(1)));}
 #endif

















 AF1 APrxLoSqrtF1(AF1 a){return AF1_AU1((AU1_AF1(a)>>AU1_(1))+AU1_(0x1fbc4639));}
 AF1 APrxLoRcpF1(AF1 a){return AF1_AU1(AU1_(0x7ef07ebb)-AU1_AF1(a));}
 AF1 APrxMedRcpF1(AF1 a){AF1 b=AF1_AU1(AU1_(0x7ef19fff)-AU1_AF1(a));return b*(-b*a+AF1_(2.0));}
 AF1 APrxLoRsqF1(AF1 a){return AF1_AU1(AU1_(0x5f347d74)-(AU1_AF1(a)>>AU1_(1)));}

 AF2 APrxLoSqrtF2(AF2 a){return AF2_AU2((AU2_AF2(a)>>AU2_(1))+AU2_(0x1fbc4639));}
 AF2 APrxLoRcpF2(AF2 a){return AF2_AU2(AU2_(0x7ef07ebb)-AU2_AF2(a));}
 AF2 APrxMedRcpF2(AF2 a){AF2 b=AF2_AU2(AU2_(0x7ef19fff)-AU2_AF2(a));return b*(-b*a+AF2_(2.0));}
 AF2 APrxLoRsqF2(AF2 a){return AF2_AU2(AU2_(0x5f347d74)-(AU2_AF2(a)>>AU2_(1)));}

 AF3 APrxLoSqrtF3(AF3 a){return AF3_AU3((AU3_AF3(a)>>AU3_(1))+AU3_(0x1fbc4639));}
 AF3 APrxLoRcpF3(AF3 a){return AF3_AU3(AU3_(0x7ef07ebb)-AU3_AF3(a));}
 AF3 APrxMedRcpF3(AF3 a){AF3 b=AF3_AU3(AU3_(0x7ef19fff)-AU3_AF3(a));return b*(-b*a+AF3_(2.0));}
 AF3 APrxLoRsqF3(AF3 a){return AF3_AU3(AU3_(0x5f347d74)-(AU3_AF3(a)>>AU3_(1)));}

 AF4 APrxLoSqrtF4(AF4 a){return AF4_AU4((AU4_AF4(a)>>AU4_(1))+AU4_(0x1fbc4639));}
 AF4 APrxLoRcpF4(AF4 a){return AF4_AU4(AU4_(0x7ef07ebb)-AU4_AF4(a));}
 AF4 APrxMedRcpF4(AF4 a){AF4 b=AF4_AU4(AU4_(0x7ef19fff)-AU4_AF4(a));return b*(-b*a+AF4_(2.0));}
 AF4 APrxLoRsqF4(AF4 a){return AF4_AU4(AU4_(0x5f347d74)-(AU4_AF4(a)>>AU4_(1)));}









)<!>" R"<!>(
 AF1 Quart(AF1 a) { a = a * a; return a * a;}
 AF1 Oct(AF1 a) { a = a * a; a = a * a; return a * a; }
 AF2 Quart(AF2 a) { a = a * a; return a * a; }
 AF2 Oct(AF2 a) { a = a * a; a = a * a; return a * a; }
 AF3 Quart(AF3 a) { a = a * a; return a * a; }
 AF3 Oct(AF3 a) { a = a * a; a = a * a; return a * a; }
 AF4 Quart(AF4 a) { a = a * a; return a * a; }
 AF4 Oct(AF4 a) { a = a * a; a = a * a; return a * a; }
 
 AF1 APrxPQToGamma2(AF1 a) { return Quart(a); }
 AF1 APrxPQToLinear(AF1 a) { return Oct(a); }
 AF1 APrxLoGamma2ToPQ(AF1 a) { return AF1_AU1((AU1_AF1(a) >> AU1_(2)) + AU1_(0x2F9A4E46)); }
 AF1 APrxMedGamma2ToPQ(AF1 a) { AF1 b = AF1_AU1((AU1_AF1(a) >> AU1_(2)) + AU1_(0x2F9A4E46)); AF1 b4 = Quart(b); return b - b * (b4 - a) / (AF1_(4.0) * b4); }
 AF1 APrxHighGamma2ToPQ(AF1 a) { return sqrt(sqrt(a)); }
 AF1 APrxLoLinearToPQ(AF1 a) { return AF1_AU1((AU1_AF1(a) >> AU1_(3)) + AU1_(0x378D8723)); }
 AF1 APrxMedLinearToPQ(AF1 a) { AF1 b = AF1_AU1((AU1_AF1(a) >> AU1_(3)) + AU1_(0x378D8723)); AF1 b8 = Oct(b); return b - b * (b8 - a) / (AF1_(8.0) * b8); }
 AF1 APrxHighLinearToPQ(AF1 a) { return sqrt(sqrt(sqrt(a))); }
 
 AF2 APrxPQToGamma2(AF2 a) { return Quart(a); }
 AF2 APrxPQToLinear(AF2 a) { return Oct(a); }
 AF2 APrxLoGamma2ToPQ(AF2 a) { return AF2_AU2((AU2_AF2(a) >> AU2_(2)) + AU2_(0x2F9A4E46)); }
 AF2 APrxMedGamma2ToPQ(AF2 a) { AF2 b = AF2_AU2((AU2_AF2(a) >> AU2_(2)) + AU2_(0x2F9A4E46)); AF2 b4 = Quart(b); return b - b * (b4 - a) / (AF1_(4.0) * b4); }
 AF2 APrxHighGamma2ToPQ(AF2 a) { return sqrt(sqrt(a)); }
 AF2 APrxLoLinearToPQ(AF2 a) { return AF2_AU2((AU2_AF2(a) >> AU2_(3)) + AU2_(0x378D8723)); }
 AF2 APrxMedLinearToPQ(AF2 a) { AF2 b = AF2_AU2((AU2_AF2(a) >> AU2_(3)) + AU2_(0x378D8723)); AF2 b8 = Oct(b); return b - b * (b8 - a) / (AF1_(8.0) * b8); }
 AF2 APrxHighLinearToPQ(AF2 a) { return sqrt(sqrt(sqrt(a))); }
 
 AF3 APrxPQToGamma2(AF3 a) { return Quart(a); }
 AF3 APrxPQToLinear(AF3 a) { return Oct(a); }
 AF3 APrxLoGamma2ToPQ(AF3 a) { return AF3_AU3((AU3_AF3(a) >> AU3_(2)) + AU3_(0x2F9A4E46)); }
 AF3 APrxMedGamma2ToPQ(AF3 a) { AF3 b = AF3_AU3((AU3_AF3(a) >> AU3_(2)) + AU3_(0x2F9A4E46)); AF3 b4 = Quart(b); return b - b * (b4 - a) / (AF1_(4.0) * b4); }
 AF3 APrxHighGamma2ToPQ(AF3 a) { return sqrt(sqrt(a)); }
 AF3 APrxLoLinearToPQ(AF3 a) { return AF3_AU3((AU3_AF3(a) >> AU3_(3)) + AU3_(0x378D8723)); }
 AF3 APrxMedLinearToPQ(AF3 a) { AF3 b = AF3_AU3((AU3_AF3(a) >> AU3_(3)) + AU3_(0x378D8723)); AF3 b8 = Oct(b); return b - b * (b8 - a) / (AF1_(8.0) * b8); }
 AF3 APrxHighLinearToPQ(AF3 a) { return sqrt(sqrt(sqrt(a))); }
 
 AF4 APrxPQToGamma2(AF4 a) { return Quart(a); }
 AF4 APrxPQToLinear(AF4 a) { return Oct(a); }
 AF4 APrxLoGamma2ToPQ(AF4 a) { return AF4_AU4((AU4_AF4(a) >> AU4_(2)) + AU4_(0x2F9A4E46)); }
 AF4 APrxMedGamma2ToPQ(AF4 a) { AF4 b = AF4_AU4((AU4_AF4(a) >> AU4_(2)) + AU4_(0x2F9A4E46)); AF4 b4 = Quart(b); return b - b * (b4 - a) / (AF1_(4.0) * b4); }
 AF4 APrxHighGamma2ToPQ(AF4 a) { return sqrt(sqrt(a)); }
 AF4 APrxLoLinearToPQ(AF4 a) { return AF4_AU4((AU4_AF4(a) >> AU4_(3)) + AU4_(0x378D8723)); }
 AF4 APrxMedLinearToPQ(AF4 a) { AF4 b = AF4_AU4((AU4_AF4(a) >> AU4_(3)) + AU4_(0x378D8723)); AF4 b8 = Oct(b); return b - b * (b8 - a) / (AF1_(8.0) * b8); }
 AF4 APrxHighLinearToPQ(AF4 a) { return sqrt(sqrt(sqrt(a))); }









 #if 1
  
  
  AF1 APSinF1(AF1 x){return x*abs(x)-x;} 
  AF2 APSinF2(AF2 x){return x*abs(x)-x;}
  AF1 APCosF1(AF1 x){x=AFractF1(x*AF1_(0.5)+AF1_(0.75));x=x*AF1_(2.0)-AF1_(1.0);return APSinF1(x);} 
  AF2 APCosF2(AF2 x){x=AFractF2(x*AF2_(0.5)+AF2_(0.75));x=x*AF2_(2.0)-AF2_(1.0);return APSinF2(x);}
  AF2 APSinCosF1(AF1 x){AF1 y=AFractF1(x*AF1_(0.5)+AF1_(0.75));y=y*AF1_(2.0)-AF1_(1.0);return APSinF2(AF2(x,y));}
 #endif

 #ifdef A_HALF
  
  
  
  AH1 APSinH1(AH1 x){return x*abs(x)-x;}
  AH2 APSinH2(AH2 x){return x*abs(x)-x;} 
  AH1 APCosH1(AH1 x){x=AFractH1(x*AH1_(0.5)+AH1_(0.75));x=x*AH1_(2.0)-AH1_(1.0);return APSinH1(x);} 
  AH2 APCosH2(AH2 x){x=AFractH2(x*AH2_(0.5)+AH2_(0.75));x=x*AH2_(2.0)-AH2_(1.0);return APSinH2(x);} 
  AH2 APSinCosH1(AH1 x){AH1 y=AFractH1(x*AH1_(0.5)+AH1_(0.75));y=y*AH1_(2.0)-AH1_(1.0);return APSinH2(AH2(x,y));}
 #endif























 #if 1
  AU1 AZolAndU1(AU1 x,AU1 y){return min(x,y);}
  AU2 AZolAndU2(AU2 x,AU2 y){return min(x,y);}
  AU3 AZolAndU3(AU3 x,AU3 y){return min(x,y);}
  AU4 AZolAndU4(AU4 x,AU4 y){return min(x,y);}

  AU1 AZolNotU1(AU1 x){return x^AU1_(1);}
  AU2 AZolNotU2(AU2 x){return x^AU2_(1);}
  AU3 AZolNotU3(AU3 x){return x^AU3_(1);}
  AU4 AZolNotU4(AU4 x){return x^AU4_(1);}

  AU1 AZolOrU1(AU1 x,AU1 y){return max(x,y);}
  AU2 AZolOrU2(AU2 x,AU2 y){return max(x,y);}
  AU3 AZolOrU3(AU3 x,AU3 y){return max(x,y);}
  AU4 AZolOrU4(AU4 x,AU4 y){return max(x,y);}

  AU1 AZolF1ToU1(AF1 x){return AU1(x);}
  AU2 AZolF2ToU2(AF2 x){return AU2(x);}
  AU3 AZolF3ToU3(AF3 x){return AU3(x);}
  AU4 AZolF4ToU4(AF4 x){return AU4(x);}

  
  AU1 AZolNotF1ToU1(AF1 x){return AU1(AF1_(1.0)-x);}
  AU2 AZolNotF2ToU2(AF2 x){return AU2(AF2_(1.0)-x);}
  AU3 AZolNotF3ToU3(AF3 x){return AU3(AF3_(1.0)-x);}
  AU4 AZolNotF4ToU4(AF4 x){return AU4(AF4_(1.0)-x);}

  AF1 AZolU1ToF1(AU1 x){return AF1(x);}
  AF2 AZolU2ToF2(AU2 x){return AF2(x);}
  AF3 AZolU3ToF3(AU3 x){return AF3(x);}
  AF4 AZolU4ToF4(AU4 x){return AF4(x);}

  AF1 AZolAndF1(AF1 x,AF1 y){return min(x,y);}
  AF2 AZolAndF2(AF2 x,AF2 y){return min(x,y);}
  AF3 AZolAndF3(AF3 x,AF3 y){return min(x,y);}
  AF4 AZolAndF4(AF4 x,AF4 y){return min(x,y);}

  AF1 ASolAndNotF1(AF1 x,AF1 y){return (-x)*y+AF1_(1.0);}
  AF2 ASolAndNotF2(AF2 x,AF2 y){return (-x)*y+AF2_(1.0);}
  AF3 ASolAndNotF3(AF3 x,AF3 y){return (-x)*y+AF3_(1.0);}
  AF4 ASolAndNotF4(AF4 x,AF4 y){return (-x)*y+AF4_(1.0);}

  AF1 AZolAndOrF1(AF1 x,AF1 y,AF1 z){return ASatF1(x*y+z);}
  AF2 AZolAndOrF2(AF2 x,AF2 y,AF2 z){return ASatF2(x*y+z);}
  AF3 AZolAndOrF3(AF3 x,AF3 y,AF3 z){return ASatF3(x*y+z);}
  AF4 AZolAndOrF4(AF4 x,AF4 y,AF4 z){return ASatF4(x*y+z);}

  AF1 AZolGtZeroF1(AF1 x){return ASatF1(x*AF1_(A_INFP_F));}
  AF2 AZolGtZeroF2(AF2 x){return ASatF2(x*AF2_(A_INFP_F));}
  AF3 AZolGtZeroF3(AF3 x){return ASatF3(x*AF3_(A_INFP_F));}
  AF4 AZolGtZeroF4(AF4 x){return ASatF4(x*AF4_(A_INFP_F));}

  AF1 AZolNotF1(AF1 x){return AF1_(1.0)-x;}
  AF2 AZolNotF2(AF2 x){return AF2_(1.0)-x;}
  AF3 AZolNotF3(AF3 x){return AF3_(1.0)-x;}
  AF4 AZolNotF4(AF4 x){return AF4_(1.0)-x;}

  AF1 AZolOrF1(AF1 x,AF1 y){return max(x,y);}
  AF2 AZolOrF2(AF2 x,AF2 y){return max(x,y);}
  AF3 AZolOrF3(AF3 x,AF3 y){return max(x,y);}
  AF4 AZolOrF4(AF4 x,AF4 y){return max(x,y);}

  AF1 AZolSelF1(AF1 x,AF1 y,AF1 z){AF1 r=(-x)*z+z;return x*y+r;}
  AF2 AZolSelF2(AF2 x,AF2 y,AF2 z){AF2 r=(-x)*z+z;return x*y+r;}
  AF3 AZolSelF3(AF3 x,AF3 y,AF3 z){AF3 r=(-x)*z+z;return x*y+r;}
  AF4 AZolSelF4(AF4 x,AF4 y,AF4 z){AF4 r=(-x)*z+z;return x*y+r;}

  AF1 AZolSignedF1(AF1 x){return ASatF1(x*AF1_(A_INFN_F));}
  AF2 AZolSignedF2(AF2 x){return ASatF2(x*AF2_(A_INFN_F));}
  AF3 AZolSignedF3(AF3 x){return ASatF3(x*AF3_(A_INFN_F));}
  AF4 AZolSignedF4(AF4 x){return ASatF4(x*AF4_(A_INFN_F));}

  AF1 AZolZeroPassF1(AF1 x,AF1 y){return AF1_AU1((AU1_AF1(x)!=AU1_(0))?AU1_(0):AU1_AF1(y));}
  AF2 AZolZeroPassF2(AF2 x,AF2 y){return AF2_AU2((AU2_AF2(x)!=AU2_(0))?AU2_(0):AU2_AF2(y));}
  AF3 AZolZeroPassF3(AF3 x,AF3 y){return AF3_AU3((AU3_AF3(x)!=AU3_(0))?AU3_(0):AU3_AF3(y));}
  AF4 AZolZeroPassF4(AF4 x,AF4 y){return AF4_AU4((AU4_AF4(x)!=AU4_(0))?AU4_(0):AU4_AF4(y));}
 #endif

 #ifdef A_HALF
  AW1 AZolAndW1(AW1 x,AW1 y){return min(x,y);}
  AW2 AZolAndW2(AW2 x,AW2 y){return min(x,y);}
  AW3 AZolAndW3(AW3 x,AW3 y){return min(x,y);}
  AW4 AZolAndW4(AW4 x,AW4 y){return min(x,y);}

  AW1 AZolNotW1(AW1 x){return x^AW1_(1);}
  AW2 AZolNotW2(AW2 x){return x^AW2_(1);}
  AW3 AZolNotW3(AW3 x){return x^AW3_(1);}
  AW4 AZolNotW4(AW4 x){return x^AW4_(1);}

  AW1 AZolOrW1(AW1 x,AW1 y){return max(x,y);}
  AW2 AZolOrW2(AW2 x,AW2 y){return max(x,y);}
  AW3 AZolOrW3(AW3 x,AW3 y){return max(x,y);}
  AW4 AZolOrW4(AW4 x,AW4 y){return max(x,y);}

  
  AW1 AZolH1ToW1(AH1 x){return AW1_AH1(x*AH1_AW1(AW1_(1)));}
  AW2 AZolH2ToW2(AH2 x){return AW2_AH2(x*AH2_AW2(AW2_(1)));}
  AW3 AZolH3ToW3(AH3 x){return AW3_AH3(x*AH3_AW3(AW3_(1)));}
  AW4 AZolH4ToW4(AH4 x){return AW4_AH4(x*AH4_AW4(AW4_(1)));}

  
  AH1 AZolW1ToH1(AW1 x){return AH1_AW1(x*AW1_AH1(AH1_(1.0)));}
  AH2 AZolW2ToH2(AW2 x){return AH2_AW2(x*AW2_AH2(AH2_(1.0)));}
  AH3 AZolW1ToH3(AW3 x){return AH3_AW3(x*AW3_AH3(AH3_(1.0)));}
  AH4 AZolW2ToH4(AW4 x){return AH4_AW4(x*AW4_AH4(AH4_(1.0)));}

  AH1 AZolAndH1(AH1 x,AH1 y){return min(x,y);}
  AH2 AZolAndH2(AH2 x,AH2 y){return min(x,y);}
  AH3 AZolAndH3(AH3 x,AH3 y){return min(x,y);}
  AH4 AZolAndH4(AH4 x,AH4 y){return min(x,y);}

  AH1 ASolAndNotH1(AH1 x,AH1 y){return (-x)*y+AH1_(1.0);}
  AH2 ASolAndNotH2(AH2 x,AH2 y){return (-x)*y+AH2_(1.0);}
  AH3 ASolAndNotH3(AH3 x,AH3 y){return (-x)*y+AH3_(1.0);}
  AH4 ASolAndNotH4(AH4 x,AH4 y){return (-x)*y+AH4_(1.0);}

  AH1 AZolAndOrH1(AH1 x,AH1 y,AH1 z){return ASatH1(x*y+z);}
  AH2 AZolAndOrH2(AH2 x,AH2 y,AH2 z){return ASatH2(x*y+z);}
  AH3 AZolAndOrH3(AH3 x,AH3 y,AH3 z){return ASatH3(x*y+z);}
  AH4 AZolAndOrH4(AH4 x,AH4 y,AH4 z){return ASatH4(x*y+z);}

  AH1 AZolGtZeroH1(AH1 x){return ASatH1(x*AH1_(A_INFP_H));}
  AH2 AZolGtZeroH2(AH2 x){return ASatH2(x*AH2_(A_INFP_H));}
  AH3 AZolGtZeroH3(AH3 x){return ASatH3(x*AH3_(A_INFP_H));}
  AH4 AZolGtZeroH4(AH4 x){return ASatH4(x*AH4_(A_INFP_H));}

  AH1 AZolNotH1(AH1 x){return AH1_(1.0)-x;}
  AH2 AZolNotH2(AH2 x){return AH2_(1.0)-x;}
  AH3 AZolNotH3(AH3 x){return AH3_(1.0)-x;}
  AH4 AZolNotH4(AH4 x){return AH4_(1.0)-x;}

  AH1 AZolOrH1(AH1 x,AH1 y){return max(x,y);}
  AH2 AZolOrH2(AH2 x,AH2 y){return max(x,y);}
  AH3 AZolOrH3(AH3 x,AH3 y){return max(x,y);}
  AH4 AZolOrH4(AH4 x,AH4 y){return max(x,y);}

  AH1 AZolSelH1(AH1 x,AH1 y,AH1 z){AH1 r=(-x)*z+z;return x*y+r;}
  AH2 AZolSelH2(AH2 x,AH2 y,AH2 z){AH2 r=(-x)*z+z;return x*y+r;}
  AH3 AZolSelH3(AH3 x,AH3 y,AH3 z){AH3 r=(-x)*z+z;return x*y+r;}
  AH4 AZolSelH4(AH4 x,AH4 y,AH4 z){AH4 r=(-x)*z+z;return x*y+r;}

  AH1 AZolSignedH1(AH1 x){return ASatH1(x*AH1_(A_INFN_H));}
  AH2 AZolSignedH2(AH2 x){return ASatH2(x*AH2_(A_INFN_H));}
  AH3 AZolSignedH3(AH3 x){return ASatH3(x*AH3_(A_INFN_H));}
  AH4 AZolSignedH4(AH4 x){return ASatH4(x*AH4_(A_INFN_H));}
 #endif




















































 #if 1
  AF1 ATo709F1(AF1 c){AF3 j=AF3(0.018*4.5,4.5,0.45);AF2 k=AF2(1.099,-0.099);
   return clamp(j.x  ,c*j.y  ,pow(c,j.z  )*k.x  +k.y  );}
  AF2 ATo709F2(AF2 c){AF3 j=AF3(0.018*4.5,4.5,0.45);AF2 k=AF2(1.099,-0.099);
   return clamp(j.xx ,c*j.yy ,pow(c,j.zz )*k.xx +k.yy );}
  AF3 ATo709F3(AF3 c){AF3 j=AF3(0.018*4.5,4.5,0.45);AF2 k=AF2(1.099,-0.099);
   return clamp(j.xxx,c*j.yyy,pow(c,j.zzz)*k.xxx+k.yyy);}

  
  AF1 AToGammaF1(AF1 c,AF1 rcpX){return pow(c,AF1_(rcpX));} 
  AF2 AToGammaF2(AF2 c,AF1 rcpX){return pow(c,AF2_(rcpX));} 
  AF3 AToGammaF3(AF3 c,AF1 rcpX){return pow(c,AF3_(rcpX));} 

  AF1 AToPqF1(AF1 x){AF1 p=pow(x,AF1_(0.159302));
   return pow((AF1_(0.835938)+AF1_(18.8516)*p)/(AF1_(1.0)+AF1_(18.6875)*p),AF1_(78.8438));}
  AF2 AToPqF1(AF2 x){AF2 p=pow(x,AF2_(0.159302));
   return pow((AF2_(0.835938)+AF2_(18.8516)*p)/(AF2_(1.0)+AF2_(18.6875)*p),AF2_(78.8438));}
  AF3 AToPqF1(AF3 x){AF3 p=pow(x,AF3_(0.159302));
   return pow((AF3_(0.835938)+AF3_(18.8516)*p)/(AF3_(1.0)+AF3_(18.6875)*p),AF3_(78.8438));}

  AF1 AToSrgbF1(AF1 c){AF3 j=AF3(0.0031308*12.92,12.92,1.0/2.4);AF2 k=AF2(1.055,-0.055);
   return clamp(j.x  ,c*j.y  ,pow(c,j.z  )*k.x  +k.y  );}
  AF2 AToSrgbF2(AF2 c){AF3 j=AF3(0.0031308*12.92,12.92,1.0/2.4);AF2 k=AF2(1.055,-0.055);
   return clamp(j.xx ,c*j.yy ,pow(c,j.zz )*k.xx +k.yy );}
  AF3 AToSrgbF3(AF3 c){AF3 j=AF3(0.0031308*12.92,12.92,1.0/2.4);AF2 k=AF2(1.055,-0.055);
   return clamp(j.xxx,c*j.yyy,pow(c,j.zzz)*k.xxx+k.yyy);}

  AF1 AToTwoF1(AF1 c){return sqrt(c);}
  AF2 AToTwoF2(AF2 c){return sqrt(c);}
  AF3 AToTwoF3(AF3 c){return sqrt(c);}

  AF1 AToThreeF1(AF1 c){return pow(c,AF1_(1.0/3.0));}
  AF2 AToThreeF2(AF2 c){return pow(c,AF2_(1.0/3.0));}
  AF3 AToThreeF3(AF3 c){return pow(c,AF3_(1.0/3.0));}
 #endif

 #if 1
  
  AF1 AFrom709F1(AF1 c){AF3 j=AF3(0.081/4.5,1.0/4.5,1.0/0.45);AF2 k=AF2(1.0/1.099,0.099/1.099);
   return AZolSelF1(AZolSignedF1(c-j.x  ),c*j.y  ,pow(c*k.x  +k.y  ,j.z  ));}
  AF2 AFrom709F2(AF2 c){AF3 j=AF3(0.081/4.5,1.0/4.5,1.0/0.45);AF2 k=AF2(1.0/1.099,0.099/1.099);
   return AZolSelF2(AZolSignedF2(c-j.xx ),c*j.yy ,pow(c*k.xx +k.yy ,j.zz ));}
  AF3 AFrom709F3(AF3 c){AF3 j=AF3(0.081/4.5,1.0/4.5,1.0/0.45);AF2 k=AF2(1.0/1.099,0.099/1.099);
   return AZolSelF3(AZolSignedF3(c-j.xxx),c*j.yyy,pow(c*k.xxx+k.yyy,j.zzz));}

  AF1 AFromGammaF1(AF1 c,AF1 x){return pow(c,AF1_(x));} 
  AF2 AFromGammaF2(AF2 c,AF1 x){return pow(c,AF2_(x));} 
  AF3 AFromGammaF3(AF3 c,AF1 x){return pow(c,AF3_(x));} 

  AF1 AFromPqF1(AF1 x){AF1 p=pow(x,AF1_(0.0126833));
   return pow(ASatF1(p-AF1_(0.835938))/(AF1_(18.8516)-AF1_(18.6875)*p),AF1_(6.27739));}
  AF2 AFromPqF1(AF2 x){AF2 p=pow(x,AF2_(0.0126833));
   return pow(ASatF2(p-AF2_(0.835938))/(AF2_(18.8516)-AF2_(18.6875)*p),AF2_(6.27739));}
  AF3 AFromPqF1(AF3 x){AF3 p=pow(x,AF3_(0.0126833));
   return pow(ASatF3(p-AF3_(0.835938))/(AF3_(18.8516)-AF3_(18.6875)*p),AF3_(6.27739));}

  
  AF1 AFromSrgbF1(AF1 c){AF3 j=AF3(0.04045/12.92,1.0/12.92,2.4);AF2 k=AF2(1.0/1.055,0.055/1.055);
   return AZolSelF1(AZolSignedF1(c-j.x  ),c*j.y  ,pow(c*k.x  +k.y  ,j.z  ));}
  AF2 AFromSrgbF2(AF2 c){AF3 j=AF3(0.04045/12.92,1.0/12.92,2.4);AF2 k=AF2(1.0/1.055,0.055/1.055);
   return AZolSelF2(AZolSignedF2(c-j.xx ),c*j.yy ,pow(c*k.xx +k.yy ,j.zz ));}
  AF3 AFromSrgbF3(AF3 c){AF3 j=AF3(0.04045/12.92,1.0/12.92,2.4);AF2 k=AF2(1.0/1.055,0.055/1.055);
   return AZolSelF3(AZolSignedF3(c-j.xxx),c*j.yyy,pow(c*k.xxx+k.yyy,j.zzz));}

  AF1 AFromTwoF1(AF1 c){return c*c;}
  AF2 AFromTwoF2(AF2 c){return c*c;}
  AF3 AFromTwoF3(AF3 c){return c*c;}

  AF1 AFromThreeF1(AF1 c){return c*c*c;}
  AF2 AFromThreeF2(AF2 c){return c*c*c;}
  AF3 AFromThreeF3(AF3 c){return c*c*c;}
 #endif

 #ifdef A_HALF
  AH1 ATo709H1(AH1 c){AH3 j=AH3(0.018*4.5,4.5,0.45);AH2 k=AH2(1.099,-0.099);
   return clamp(j.x  ,c*j.y  ,pow(c,j.z  )*k.x  +k.y  );}
  AH2 ATo709H2(AH2 c){AH3 j=AH3(0.018*4.5,4.5,0.45);AH2 k=AH2(1.099,-0.099);
   return clamp(j.xx ,c*j.yy ,pow(c,j.zz )*k.xx +k.yy );}
  AH3 ATo709H3(AH3 c){AH3 j=AH3(0.018*4.5,4.5,0.45);AH2 k=AH2(1.099,-0.099);
   return clamp(j.xxx,c*j.yyy,pow(c,j.zzz)*k.xxx+k.yyy);}

  AH1 AToGammaH1(AH1 c,AH1 rcpX){return pow(c,AH1_(rcpX));}
  AH2 AToGammaH2(AH2 c,AH1 rcpX){return pow(c,AH2_(rcpX));}
  AH3 AToGammaH3(AH3 c,AH1 rcpX){return pow(c,AH3_(rcpX));}

  AH1 AToSrgbH1(AH1 c){AH3 j=AH3(0.0031308*12.92,12.92,1.0/2.4);AH2 k=AH2(1.055,-0.055);
   return clamp(j.x  ,c*j.y  ,pow(c,j.z  )*k.x  +k.y  );}
  AH2 AToSrgbH2(AH2 c){AH3 j=AH3(0.0031308*12.92,12.92,1.0/2.4);AH2 k=AH2(1.055,-0.055);
   return clamp(j.xx ,c*j.yy ,pow(c,j.zz )*k.xx +k.yy );}
  AH3 AToSrgbH3(AH3 c){AH3 j=AH3(0.0031308*12.92,12.92,1.0/2.4);AH2 k=AH2(1.055,-0.055);
   return clamp(j.xxx,c*j.yyy,pow(c,j.zzz)*k.xxx+k.yyy);}

  AH1 AToTwoH1(AH1 c){return sqrt(c);}
  AH2 AToTwoH2(AH2 c){return sqrt(c);}
  AH3 AToTwoH3(AH3 c){return sqrt(c);}

  AH1 AToThreeF1(AH1 c){return pow(c,AH1_(1.0/3.0));}
  AH2 AToThreeF2(AH2 c){return pow(c,AH2_(1.0/3.0));}
  AH3 AToThreeF3(AH3 c){return pow(c,AH3_(1.0/3.0));}
 #endif

 #ifdef A_HALF
  AH1 AFrom709H1(AH1 c){AH3 j=AH3(0.081/4.5,1.0/4.5,1.0/0.45);AH2 k=AH2(1.0/1.099,0.099/1.099);
   return AZolSelH1(AZolSignedH1(c-j.x  ),c*j.y  ,pow(c*k.x  +k.y  ,j.z  ));}
  AH2 AFrom709H2(AH2 c){AH3 j=AH3(0.081/4.5,1.0/4.5,1.0/0.45);AH2 k=AH2(1.0/1.099,0.099/1.099);
   return AZolSelH2(AZolSignedH2(c-j.xx ),c*j.yy ,pow(c*k.xx +k.yy ,j.zz ));}
  AH3 AFrom709H3(AH3 c){AH3 j=AH3(0.081/4.5,1.0/4.5,1.0/0.45);AH2 k=AH2(1.0/1.099,0.099/1.099);
   return AZolSelH3(AZolSignedH3(c-j.xxx),c*j.yyy,pow(c*k.xxx+k.yyy,j.zzz));}

  AH1 AFromGammaH1(AH1 c,AH1 x){return pow(c,AH1_(x));}
  AH2 AFromGammaH2(AH2 c,AH1 x){return pow(c,AH2_(x));}
  AH3 AFromGammaH3(AH3 c,AH1 x){return pow(c,AH3_(x));}
)<!>" R"<!>(
  AH1 AHromSrgbF1(AH1 c){AH3 j=AH3(0.04045/12.92,1.0/12.92,2.4);AH2 k=AH2(1.0/1.055,0.055/1.055);
   return AZolSelH1(AZolSignedH1(c-j.x  ),c*j.y  ,pow(c*k.x  +k.y  ,j.z  ));}
  AH2 AHromSrgbF2(AH2 c){AH3 j=AH3(0.04045/12.92,1.0/12.92,2.4);AH2 k=AH2(1.0/1.055,0.055/1.055);
   return AZolSelH2(AZolSignedH2(c-j.xx ),c*j.yy ,pow(c*k.xx +k.yy ,j.zz ));}
  AH3 AHromSrgbF3(AH3 c){AH3 j=AH3(0.04045/12.92,1.0/12.92,2.4);AH2 k=AH2(1.0/1.055,0.055/1.055);
   return AZolSelH3(AZolSignedH3(c-j.xxx),c*j.yyy,pow(c*k.xxx+k.yyy,j.zzz));}

  AH1 AFromTwoH1(AH1 c){return c*c;}
  AH2 AFromTwoH2(AH2 c){return c*c;}
  AH3 AFromTwoH3(AH3 c){return c*c;}

  AH1 AFromThreeH1(AH1 c){return c*c*c;}
  AH2 AFromThreeH2(AH2 c){return c*c*c;}
  AH3 AFromThreeH3(AH3 c){return c*c*c;}
 #endif






 
 
 
 
 
 AU2 ARmp8x8(AU1 a){return AU2(ABfe(a,1u,3u),ABfiM(ABfe(a,3u,3u),a,1u));}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 AU2 ARmpRed8x8(AU1 a){return AU2(ABfiM(ABfe(a,2u,3u),a,1u),ABfiM(ABfe(a,3u,3u),ABfe(a,1u,2u),2u));}

 #ifdef A_HALF
  AW2 ARmp8x8H(AU1 a){return AW2(ABfe(a,1u,3u),ABfiM(ABfe(a,3u,3u),a,1u));}
  AW2 ARmpRed8x8H(AU1 a){return AW2(ABfiM(ABfe(a,2u,3u),a,1u),ABfiM(ABfe(a,3u,3u),ABfe(a,1u,2u),2u));}
 #endif
#endif



















































































#ifdef A_GPU
 #define A_TRUE true
 #define A_FALSE false
 #define A_STATIC






 #define retAD2 AD2
 #define retAD3 AD3
 #define retAD4 AD4
 #define retAF2 AF2
 #define retAF3 AF3
 #define retAF4 AF4
 #define retAL2 AL2
 #define retAL3 AL3
 #define retAL4 AL4
 #define retAU2 AU2
 #define retAU3 AU3
 #define retAU4 AU4

 #define inAD2 in AD2
 #define inAD3 in AD3
 #define inAD4 in AD4
 #define inAF2 in AF2
 #define inAF3 in AF3
 #define inAF4 in AF4
 #define inAL2 in AL2
 #define inAL3 in AL3
 #define inAL4 in AL4
 #define inAU2 in AU2
 #define inAU3 in AU3
 #define inAU4 in AU4

 #define inoutAD2 inout AD2
 #define inoutAD3 inout AD3
 #define inoutAD4 inout AD4
 #define inoutAF2 inout AF2
 #define inoutAF3 inout AF3
 #define inoutAF4 inout AF4
 #define inoutAL2 inout AL2
 #define inoutAL3 inout AL3
 #define inoutAL4 inout AL4
 #define inoutAU2 inout AU2
 #define inoutAU3 inout AU3
 #define inoutAU4 inout AU4

 #define outAD2 out AD2
 #define outAD3 out AD3
 #define outAD4 out AD4
 #define outAF2 out AF2
 #define outAF3 out AF3
 #define outAF4 out AF4
 #define outAL2 out AL2
 #define outAL3 out AL3
 #define outAL4 out AL4
 #define outAU2 out AU2
 #define outAU3 out AU3
 #define outAU4 out AU4

 #define varAD2(x) AD2 x
 #define varAD3(x) AD3 x
 #define varAD4(x) AD4 x
 #define varAF2(x) AF2 x
 #define varAF3(x) AF3 x
 #define varAF4(x) AF4 x
 #define varAL2(x) AL2 x
 #define varAL3(x) AL3 x
 #define varAL4(x) AL4 x
 #define varAU2(x) AU2 x
 #define varAU3(x) AU3 x
 #define varAU4(x) AU4 x

 #define initAD2(x,y) AD2(x,y)
 #define initAD3(x,y,z) AD3(x,y,z)
 #define initAD4(x,y,z,w) AD4(x,y,z,w)
 #define initAF2(x,y) AF2(x,y)
 #define initAF3(x,y,z) AF3(x,y,z)
 #define initAF4(x,y,z,w) AF4(x,y,z,w)
 #define initAL2(x,y) AL2(x,y)
 #define initAL3(x,y,z) AL3(x,y,z)
 #define initAL4(x,y,z,w) AL4(x,y,z,w)
 #define initAU2(x,y) AU2(x,y)
 #define initAU3(x,y,z) AU3(x,y,z)
 #define initAU4(x,y,z,w) AU4(x,y,z,w)






 #define AAbsD1(a) abs(AD1(a))
 #define AAbsF1(a) abs(AF1(a))

 #define ACosD1(a) cos(AD1(a))
 #define ACosF1(a) cos(AF1(a))

 #define ADotD2(a,b) dot(AD2(a),AD2(b))
 #define ADotD3(a,b) dot(AD3(a),AD3(b))
 #define ADotD4(a,b) dot(AD4(a),AD4(b))
 #define ADotF2(a,b) dot(AF2(a),AF2(b))
 #define ADotF3(a,b) dot(AF3(a),AF3(b))
 #define ADotF4(a,b) dot(AF4(a),AF4(b))

 #define AExp2D1(a) exp2(AD1(a))
 #define AExp2F1(a) exp2(AF1(a))

 #define AFloorD1(a) floor(AD1(a))
 #define AFloorF1(a) floor(AF1(a))

 #define ALog2D1(a) log2(AD1(a))
 #define ALog2F1(a) log2(AF1(a))

 #define AMaxD1(a,b) max(a,b)
 #define AMaxF1(a,b) max(a,b)
 #define AMaxL1(a,b) max(a,b)
 #define AMaxU1(a,b) max(a,b)

 #define AMinD1(a,b) min(a,b)
 #define AMinF1(a,b) min(a,b)
 #define AMinL1(a,b) min(a,b)
 #define AMinU1(a,b) min(a,b)

 #define ASinD1(a) sin(AD1(a))
 #define ASinF1(a) sin(AF1(a))

 #define ASqrtD1(a) sqrt(AD1(a))
 #define ASqrtF1(a) sqrt(AF1(a))






 #define APowD1(a,b) pow(AD1(a),AF1(b))
 #define APowF1(a,b) pow(AF1(a),AF1(b))









 #ifdef A_DUBL
  AD2 opAAbsD2(outAD2 d,inAD2 a){d=abs(a);return d;}
  AD3 opAAbsD3(outAD3 d,inAD3 a){d=abs(a);return d;}
  AD4 opAAbsD4(outAD4 d,inAD4 a){d=abs(a);return d;}

  AD2 opAAddD2(outAD2 d,inAD2 a,inAD2 b){d=a+b;return d;}
  AD3 opAAddD3(outAD3 d,inAD3 a,inAD3 b){d=a+b;return d;}
  AD4 opAAddD4(outAD4 d,inAD4 a,inAD4 b){d=a+b;return d;}

  AD2 opAAddOneD2(outAD2 d,inAD2 a,AD1 b){d=a+AD2_(b);return d;}
  AD3 opAAddOneD3(outAD3 d,inAD3 a,AD1 b){d=a+AD3_(b);return d;}
  AD4 opAAddOneD4(outAD4 d,inAD4 a,AD1 b){d=a+AD4_(b);return d;}

  AD2 opACpyD2(outAD2 d,inAD2 a){d=a;return d;}
  AD3 opACpyD3(outAD3 d,inAD3 a){d=a;return d;}
  AD4 opACpyD4(outAD4 d,inAD4 a){d=a;return d;}

  AD2 opALerpD2(outAD2 d,inAD2 a,inAD2 b,inAD2 c){d=ALerpD2(a,b,c);return d;}
  AD3 opALerpD3(outAD3 d,inAD3 a,inAD3 b,inAD3 c){d=ALerpD3(a,b,c);return d;}
  AD4 opALerpD4(outAD4 d,inAD4 a,inAD4 b,inAD4 c){d=ALerpD4(a,b,c);return d;}

  AD2 opALerpOneD2(outAD2 d,inAD2 a,inAD2 b,AD1 c){d=ALerpD2(a,b,AD2_(c));return d;}
  AD3 opALerpOneD3(outAD3 d,inAD3 a,inAD3 b,AD1 c){d=ALerpD3(a,b,AD3_(c));return d;}
  AD4 opALerpOneD4(outAD4 d,inAD4 a,inAD4 b,AD1 c){d=ALerpD4(a,b,AD4_(c));return d;}

  AD2 opAMaxD2(outAD2 d,inAD2 a,inAD2 b){d=max(a,b);return d;}
  AD3 opAMaxD3(outAD3 d,inAD3 a,inAD3 b){d=max(a,b);return d;}
  AD4 opAMaxD4(outAD4 d,inAD4 a,inAD4 b){d=max(a,b);return d;}

  AD2 opAMinD2(outAD2 d,inAD2 a,inAD2 b){d=min(a,b);return d;}
  AD3 opAMinD3(outAD3 d,inAD3 a,inAD3 b){d=min(a,b);return d;}
  AD4 opAMinD4(outAD4 d,inAD4 a,inAD4 b){d=min(a,b);return d;}

  AD2 opAMulD2(outAD2 d,inAD2 a,inAD2 b){d=a*b;return d;}
  AD3 opAMulD3(outAD3 d,inAD3 a,inAD3 b){d=a*b;return d;}
  AD4 opAMulD4(outAD4 d,inAD4 a,inAD4 b){d=a*b;return d;}

  AD2 opAMulOneD2(outAD2 d,inAD2 a,AD1 b){d=a*AD2_(b);return d;}
  AD3 opAMulOneD3(outAD3 d,inAD3 a,AD1 b){d=a*AD3_(b);return d;}
  AD4 opAMulOneD4(outAD4 d,inAD4 a,AD1 b){d=a*AD4_(b);return d;}

  AD2 opANegD2(outAD2 d,inAD2 a){d=-a;return d;}
  AD3 opANegD3(outAD3 d,inAD3 a){d=-a;return d;}
  AD4 opANegD4(outAD4 d,inAD4 a){d=-a;return d;}

  AD2 opARcpD2(outAD2 d,inAD2 a){d=ARcpD2(a);return d;}
  AD3 opARcpD3(outAD3 d,inAD3 a){d=ARcpD3(a);return d;}
  AD4 opARcpD4(outAD4 d,inAD4 a){d=ARcpD4(a);return d;}
 #endif

 AF2 opAAbsF2(outAF2 d,inAF2 a){d=abs(a);return d;}
 AF3 opAAbsF3(outAF3 d,inAF3 a){d=abs(a);return d;}
 AF4 opAAbsF4(outAF4 d,inAF4 a){d=abs(a);return d;}

 AF2 opAAddF2(outAF2 d,inAF2 a,inAF2 b){d=a+b;return d;}
 AF3 opAAddF3(outAF3 d,inAF3 a,inAF3 b){d=a+b;return d;}
 AF4 opAAddF4(outAF4 d,inAF4 a,inAF4 b){d=a+b;return d;}

 AF2 opAAddOneF2(outAF2 d,inAF2 a,AF1 b){d=a+AF2_(b);return d;}
 AF3 opAAddOneF3(outAF3 d,inAF3 a,AF1 b){d=a+AF3_(b);return d;}
 AF4 opAAddOneF4(outAF4 d,inAF4 a,AF1 b){d=a+AF4_(b);return d;}

 AF2 opACpyF2(outAF2 d,inAF2 a){d=a;return d;}
 AF3 opACpyF3(outAF3 d,inAF3 a){d=a;return d;}
 AF4 opACpyF4(outAF4 d,inAF4 a){d=a;return d;}

 AF2 opALerpF2(outAF2 d,inAF2 a,inAF2 b,inAF2 c){d=ALerpF2(a,b,c);return d;}
 AF3 opALerpF3(outAF3 d,inAF3 a,inAF3 b,inAF3 c){d=ALerpF3(a,b,c);return d;}
 AF4 opALerpF4(outAF4 d,inAF4 a,inAF4 b,inAF4 c){d=ALerpF4(a,b,c);return d;}

 AF2 opALerpOneF2(outAF2 d,inAF2 a,inAF2 b,AF1 c){d=ALerpF2(a,b,AF2_(c));return d;}
 AF3 opALerpOneF3(outAF3 d,inAF3 a,inAF3 b,AF1 c){d=ALerpF3(a,b,AF3_(c));return d;}
 AF4 opALerpOneF4(outAF4 d,inAF4 a,inAF4 b,AF1 c){d=ALerpF4(a,b,AF4_(c));return d;}

 AF2 opAMaxF2(outAF2 d,inAF2 a,inAF2 b){d=max(a,b);return d;}
 AF3 opAMaxF3(outAF3 d,inAF3 a,inAF3 b){d=max(a,b);return d;}
 AF4 opAMaxF4(outAF4 d,inAF4 a,inAF4 b){d=max(a,b);return d;}

 AF2 opAMinF2(outAF2 d,inAF2 a,inAF2 b){d=min(a,b);return d;}
 AF3 opAMinF3(outAF3 d,inAF3 a,inAF3 b){d=min(a,b);return d;}
 AF4 opAMinF4(outAF4 d,inAF4 a,inAF4 b){d=min(a,b);return d;}

 AF2 opAMulF2(outAF2 d,inAF2 a,inAF2 b){d=a*b;return d;}
 AF3 opAMulF3(outAF3 d,inAF3 a,inAF3 b){d=a*b;return d;}
 AF4 opAMulF4(outAF4 d,inAF4 a,inAF4 b){d=a*b;return d;}

 AF2 opAMulOneF2(outAF2 d,inAF2 a,AF1 b){d=a*AF2_(b);return d;}
 AF3 opAMulOneF3(outAF3 d,inAF3 a,AF1 b){d=a*AF3_(b);return d;}
 AF4 opAMulOneF4(outAF4 d,inAF4 a,AF1 b){d=a*AF4_(b);return d;}

 AF2 opANegF2(outAF2 d,inAF2 a){d=-a;return d;}
 AF3 opANegF3(outAF3 d,inAF3 a){d=-a;return d;}
 AF4 opANegF4(outAF4 d,inAF4 a){d=-a;return d;}

 AF2 opARcpF2(outAF2 d,inAF2 a){d=ARcpF2(a);return d;}
 AF3 opARcpF3(outAF3 d,inAF3 a){d=ARcpF3(a);return d;}
 AF4 opARcpF4(outAF4 d,inAF4 a){d=ARcpF4(a);return d;}
#endif

layout(local_size_x = 64, local_size_y = 1, local_size_z = 1) in;

layout(rgba16f, set = 1, binding = 0) uniform restrict writeonly image2D fsr_image;
layout(set = 0, binding = 0) uniform sampler2D source_image;

#define FSR_UPSCALE_PASS_TYPE_EASU 0
#define FSR_UPSCALE_PASS_TYPE_RCAS 1

layout(push_constant, std430) uniform Params {
	float resolution_width;
	float resolution_height;
	float upscaled_width;
	float upscaled_height;
	float sharpness;
	int pass;
}
params;

AU4 Const0, Const1, Const2, Const3;

#ifdef MODE_FSR_UPSCALE_FALLBACK

#define FSR_EASU_F
AF4 FsrEasuRF(AF2 p) {
	AF4 res = textureGather(source_image, p, 0);
	return res;
}
AF4 FsrEasuGF(AF2 p) {
	AF4 res = textureGather(source_image, p, 1);
	return res;
}
AF4 FsrEasuBF(AF2 p) {
	AF4 res = textureGather(source_image, p, 2);
	return res;
}

#define FSR_RCAS_F
AF4 FsrRcasLoadF(ASU2 p) {
	return AF4(texelFetch(source_image, ASU2(p), 0));
}
void FsrRcasInputF(inout AF1 r, inout AF1 g, inout AF1 b) {}

#else

#define FSR_EASU_H
AH4 FsrEasuRH(AF2 p) {
	AH4 res = AH4(textureGather(source_image, p, 0));
	return res;
}
AH4 FsrEasuGH(AF2 p) {
	AH4 res = AH4(textureGather(source_image, p, 1));
	return res;
}
AH4 FsrEasuBH(AF2 p) {
	AH4 res = AH4(textureGather(source_image, p, 2));
	return res;
}

#define FSR_RCAS_H
AH4 FsrRcasLoadH(ASW2 p) {
	return AH4(texelFetch(source_image, ASU2(p), 0));
}
void FsrRcasInputH(inout AH1 r, inout AH1 g, inout AH1 b) {}

#endif




























































































































































A_STATIC void FsrEasuCon(
outAU4 con0,
outAU4 con1,
outAU4 con2,
outAU4 con3,

AF1 inputViewportInPixelsX,
AF1 inputViewportInPixelsY,

AF1 inputSizeInPixelsX,
AF1 inputSizeInPixelsY,

AF1 outputSizeInPixelsX,
AF1 outputSizeInPixelsY){
 
 con0[0]=AU1_AF1(inputViewportInPixelsX*ARcpF1(outputSizeInPixelsX));
 con0[1]=AU1_AF1(inputViewportInPixelsY*ARcpF1(outputSizeInPixelsY));
 con0[2]=AU1_AF1(AF1_(0.5)*inputViewportInPixelsX*ARcpF1(outputSizeInPixelsX)-AF1_(0.5));
 con0[3]=AU1_AF1(AF1_(0.5)*inputViewportInPixelsY*ARcpF1(outputSizeInPixelsY)-AF1_(0.5));
 
 
 con1[0]=AU1_AF1(ARcpF1(inputSizeInPixelsX));
 con1[1]=AU1_AF1(ARcpF1(inputSizeInPixelsY));
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 con1[2]=AU1_AF1(AF1_( 1.0)*ARcpF1(inputSizeInPixelsX));
 con1[3]=AU1_AF1(AF1_(-1.0)*ARcpF1(inputSizeInPixelsY));
 
 con2[0]=AU1_AF1(AF1_(-1.0)*ARcpF1(inputSizeInPixelsX));
 con2[1]=AU1_AF1(AF1_( 2.0)*ARcpF1(inputSizeInPixelsY));
 con2[2]=AU1_AF1(AF1_( 1.0)*ARcpF1(inputSizeInPixelsX));
 con2[3]=AU1_AF1(AF1_( 2.0)*ARcpF1(inputSizeInPixelsY));
 con3[0]=AU1_AF1(AF1_( 0.0)*ARcpF1(inputSizeInPixelsX));
 con3[1]=AU1_AF1(AF1_( 4.0)*ARcpF1(inputSizeInPixelsY));
 con3[2]=con3[3]=0;}


A_STATIC void FsrEasuConOffset(
    outAU4 con0,
    outAU4 con1,
    outAU4 con2,
    outAU4 con3,
    
    AF1 inputViewportInPixelsX,
    AF1 inputViewportInPixelsY,
    
    AF1 inputSizeInPixelsX,
    AF1 inputSizeInPixelsY,
    
    AF1 outputSizeInPixelsX,
    AF1 outputSizeInPixelsY,
    
    AF1 inputOffsetInPixelsX,
    AF1 inputOffsetInPixelsY) {
    FsrEasuCon(con0, con1, con2, con3, inputViewportInPixelsX, inputViewportInPixelsY, inputSizeInPixelsX, inputSizeInPixelsY, outputSizeInPixelsX, outputSizeInPixelsY);
    con0[2] = AU1_AF1(AF1_(0.5) * inputViewportInPixelsX * ARcpF1(outputSizeInPixelsX) - AF1_(0.5) + inputOffsetInPixelsX);
    con0[3] = AU1_AF1(AF1_(0.5) * inputViewportInPixelsY * ARcpF1(outputSizeInPixelsY) - AF1_(0.5) + inputOffsetInPixelsY);
}






#if defined(A_GPU)&&defined(FSR_EASU_F)
 
 AF4 FsrEasuRF(AF2 p);
 AF4 FsrEasuGF(AF2 p);
 AF4 FsrEasuBF(AF2 p);

 
 void FsrEasuTapF(
 inout AF3 aC, 
 inout AF1 aW, 
 AF2 off, 
 AF2 dir, 
 AF2 len, 
 AF1 lob, 
 AF1 clp, 
 AF3 c){ 
  
  AF2 v;
  v.x=(off.x*( dir.x))+(off.y*dir.y);
  v.y=(off.x*(-dir.y))+(off.y*dir.x);
  
  v*=len;
  
  AF1 d2=v.x*v.x+v.y*v.y;
  
  d2=min(d2,clp);
  
  
  
  
  
  
  
  AF1 wB=AF1_(2.0/5.0)*d2+AF1_(-1.0);
  AF1 wA=lob*d2+AF1_(-1.0);
  wB*=wB;
  wA*=wA;
  wB=AF1_(25.0/16.0)*wB+AF1_(-(25.0/16.0-1.0));
  AF1 w=wB*wA;
  
  aC+=c*w;aW+=w;}

 
 void FsrEasuSetF(
 inout AF2 dir,
 inout AF1 len,
 AF2 pp,
 AP1 biS,AP1 biT,AP1 biU,AP1 biV,
 AF1 lA,AF1 lB,AF1 lC,AF1 lD,AF1 lE){
  
  
  
  AF1 w = AF1_(0.0);
  if(biS)w=(AF1_(1.0)-pp.x)*(AF1_(1.0)-pp.y);
  if(biT)w=           pp.x *(AF1_(1.0)-pp.y);
  if(biU)w=(AF1_(1.0)-pp.x)*           pp.y ;
  if(biV)w=           pp.x *           pp.y ;
  
  
  
  
  
  
  AF1 dc=lD-lC;
  AF1 cb=lC-lB;
  AF1 lenX=max(abs(dc),abs(cb));
  lenX=APrxLoRcpF1(lenX);
  AF1 dirX=lD-lB;
  dir.x+=dirX*w;
  lenX=ASatF1(abs(dirX)*lenX);
  lenX*=lenX;
  len+=lenX*w;
  
  AF1 ec=lE-lC;
  AF1 ca=lC-lA;
  AF1 lenY=max(abs(ec),abs(ca));
  lenY=APrxLoRcpF1(lenY);
  AF1 dirY=lE-lA;
  dir.y+=dirY*w;
  lenY=ASatF1(abs(dirY)*lenY);
  lenY*=lenY;
  len+=lenY*w;}

 void FsrEasuF(
 out AF3 pix,
 AU2 ip, 
 AU4 con0, 
 AU4 con1,
 AU4 con2,
 AU4 con3){

  
  AF2 pp=AF2(ip)*AF2_AU2(con0.xy)+AF2_AU2(con0.zw);
  AF2 fp=floor(pp);
  pp-=fp;

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  AF2 p0=fp*AF2_AU2(con1.xy)+AF2_AU2(con1.zw);
  
  AF2 p1=p0+AF2_AU2(con2.xy);
  AF2 p2=p0+AF2_AU2(con2.zw);
  AF2 p3=p0+AF2_AU2(con3.xy);
  AF4 bczzR=FsrEasuRF(p0);
  AF4 bczzG=FsrEasuGF(p0);
  AF4 bczzB=FsrEasuBF(p0);
  AF4 ijfeR=FsrEasuRF(p1);
  AF4 ijfeG=FsrEasuGF(p1);
  AF4 ijfeB=FsrEasuBF(p1);
  AF4 klhgR=FsrEasuRF(p2);
  AF4 klhgG=FsrEasuGF(p2);
  AF4 klhgB=FsrEasuBF(p2);
  AF4 zzonR=FsrEasuRF(p3);
  AF4 zzonG=FsrEasuGF(p3);
  AF4 zzonB=FsrEasuBF(p3);

  
  AF4 bczzL=bczzB*AF4_(0.5)+(bczzR*AF4_(0.5)+bczzG);
  AF4 ijfeL=ijfeB*AF4_(0.5)+(ijfeR*AF4_(0.5)+ijfeG);
  AF4 klhgL=klhgB*AF4_(0.5)+(klhgR*AF4_(0.5)+klhgG);
  AF4 zzonL=zzonB*AF4_(0.5)+(zzonR*AF4_(0.5)+zzonG);
  
  AF1 bL=bczzL.x;
  AF1 cL=bczzL.y;
  AF1 iL=ijfeL.x;
  AF1 jL=ijfeL.y;
  AF1 fL=ijfeL.z;
  AF1 eL=ijfeL.w;
  AF1 kL=klhgL.x;
  AF1 lL=klhgL.y;
  AF1 hL=klhgL.z;
  AF1 gL=klhgL.w;
  AF1 oL=zzonL.z;
  AF1 nL=zzonL.w;
  
  AF2 dir=AF2_(0.0);
  AF1 len=AF1_(0.0);
  FsrEasuSetF(dir,len,pp,true, false,false,false,bL,eL,fL,gL,jL);
  FsrEasuSetF(dir,len,pp,false,true ,false,false,cL,fL,gL,hL,kL);
  FsrEasuSetF(dir,len,pp,false,false,true ,false,fL,iL,jL,kL,nL);
  FsrEasuSetF(dir,len,pp,false,false,false,true ,gL,jL,kL,lL,oL);

  
  AF2 dir2=dir*dir;
  AF1 dirR=dir2.x+dir2.y;
  AP1 zro=dirR<AF1_(1.0/32768.0);
  dirR=APrxLoRsqF1(dirR);
  dirR=zro?AF1_(1.0):dirR;
  dir.x=zro?AF1_(1.0):dir.x;
  dir*=AF2_(dirR);
  
  len=len*AF1_(0.5);
  len*=len;
  
  AF1 stretch=(dir.x*dir.x+dir.y*dir.y)*APrxLoRcpF1(max(abs(dir.x),abs(dir.y)));
  
  
  
  AF2 len2=AF2(AF1_(1.0)+(stretch-AF1_(1.0))*len,AF1_(1.0)+AF1_(-0.5)*len);
  
  
  AF1 lob=AF1_(0.5)+AF1_((1.0/4.0-0.04)-0.5)*len;
  
  AF1 clp=APrxLoRcpF1(lob);
)<!>" R"<!>(
  
  
  
  
  
  AF3 min4=min(AMin3F3(AF3(ijfeR.z,ijfeG.z,ijfeB.z),AF3(klhgR.w,klhgG.w,klhgB.w),AF3(ijfeR.y,ijfeG.y,ijfeB.y)),
               AF3(klhgR.x,klhgG.x,klhgB.x));
  AF3 max4=max(AMax3F3(AF3(ijfeR.z,ijfeG.z,ijfeB.z),AF3(klhgR.w,klhgG.w,klhgB.w),AF3(ijfeR.y,ijfeG.y,ijfeB.y)),
               AF3(klhgR.x,klhgG.x,klhgB.x));
  
  AF3 aC=AF3_(0.0);
  AF1 aW=AF1_(0.0);
  FsrEasuTapF(aC,aW,AF2( 0.0,-1.0)-pp,dir,len2,lob,clp,AF3(bczzR.x,bczzG.x,bczzB.x)); 
  FsrEasuTapF(aC,aW,AF2( 1.0,-1.0)-pp,dir,len2,lob,clp,AF3(bczzR.y,bczzG.y,bczzB.y)); 
  FsrEasuTapF(aC,aW,AF2(-1.0, 1.0)-pp,dir,len2,lob,clp,AF3(ijfeR.x,ijfeG.x,ijfeB.x)); 
  FsrEasuTapF(aC,aW,AF2( 0.0, 1.0)-pp,dir,len2,lob,clp,AF3(ijfeR.y,ijfeG.y,ijfeB.y)); 
  FsrEasuTapF(aC,aW,AF2( 0.0, 0.0)-pp,dir,len2,lob,clp,AF3(ijfeR.z,ijfeG.z,ijfeB.z)); 
  FsrEasuTapF(aC,aW,AF2(-1.0, 0.0)-pp,dir,len2,lob,clp,AF3(ijfeR.w,ijfeG.w,ijfeB.w)); 
  FsrEasuTapF(aC,aW,AF2( 1.0, 1.0)-pp,dir,len2,lob,clp,AF3(klhgR.x,klhgG.x,klhgB.x)); 
  FsrEasuTapF(aC,aW,AF2( 2.0, 1.0)-pp,dir,len2,lob,clp,AF3(klhgR.y,klhgG.y,klhgB.y)); 
  FsrEasuTapF(aC,aW,AF2( 2.0, 0.0)-pp,dir,len2,lob,clp,AF3(klhgR.z,klhgG.z,klhgB.z)); 
  FsrEasuTapF(aC,aW,AF2( 1.0, 0.0)-pp,dir,len2,lob,clp,AF3(klhgR.w,klhgG.w,klhgB.w)); 
  FsrEasuTapF(aC,aW,AF2( 1.0, 2.0)-pp,dir,len2,lob,clp,AF3(zzonR.z,zzonG.z,zzonB.z)); 
  FsrEasuTapF(aC,aW,AF2( 0.0, 2.0)-pp,dir,len2,lob,clp,AF3(zzonR.w,zzonG.w,zzonB.w)); 

  
  pix=min(max4,max(min4,aC*AF3_(ARcpF1(aW))));}
#endif






#if defined(A_GPU)&&defined(A_HALF)&&defined(FSR_EASU_H)

 AH4 FsrEasuRH(AF2 p);
 AH4 FsrEasuGH(AF2 p);
 AH4 FsrEasuBH(AF2 p);

 
 void FsrEasuTapH(
 inout AH2 aCR,inout AH2 aCG,inout AH2 aCB,
 inout AH2 aW,
 AH2 offX,AH2 offY,
 AH2 dir,
 AH2 len,
 AH1 lob,
 AH1 clp,
 AH2 cR,AH2 cG,AH2 cB){
  AH2 vX,vY;
  vX=offX*  dir.xx +offY*dir.yy;
  vY=offX*(-dir.yy)+offY*dir.xx;
  vX*=len.x;vY*=len.y;
  AH2 d2=vX*vX+vY*vY;
  d2=min(d2,AH2_(clp));
  AH2 wB=AH2_(2.0/5.0)*d2+AH2_(-1.0);
  AH2 wA=AH2_(lob)*d2+AH2_(-1.0);
  wB*=wB;
  wA*=wA;
  wB=AH2_(25.0/16.0)*wB+AH2_(-(25.0/16.0-1.0));
  AH2 w=wB*wA;
  aCR+=cR*w;aCG+=cG*w;aCB+=cB*w;aW+=w;}

 
 void FsrEasuSetH(
 inout AH2 dirPX,inout AH2 dirPY,
 inout AH2 lenP,
 AH2 pp,
 AP1 biST,AP1 biUV,
 AH2 lA,AH2 lB,AH2 lC,AH2 lD,AH2 lE){
  AH2 w = AH2_(0.0);
  if(biST)w=(AH2(1.0,0.0)+AH2(-pp.x,pp.x))*AH2_(AH1_(1.0)-pp.y);
  if(biUV)w=(AH2(1.0,0.0)+AH2(-pp.x,pp.x))*AH2_(          pp.y);
  
  AH2 dc=lD-lC;
  AH2 cb=lC-lB;
  AH2 lenX=max(abs(dc),abs(cb));
  lenX=ARcpH2(lenX);
  AH2 dirX=lD-lB;
  dirPX+=dirX*w;
  lenX=ASatH2(abs(dirX)*lenX);
  lenX*=lenX;
  lenP+=lenX*w;
  AH2 ec=lE-lC;
  AH2 ca=lC-lA;
  AH2 lenY=max(abs(ec),abs(ca));
  lenY=ARcpH2(lenY);
  AH2 dirY=lE-lA;
  dirPY+=dirY*w;
  lenY=ASatH2(abs(dirY)*lenY);
  lenY*=lenY;
  lenP+=lenY*w;}

 void FsrEasuH(
 out AH3 pix,
 AU2 ip,
 AU4 con0,
 AU4 con1,
 AU4 con2,
 AU4 con3){

  AF2 pp=AF2(ip)*AF2_AU2(con0.xy)+AF2_AU2(con0.zw);
  AF2 fp=floor(pp);
  pp-=fp;
  AH2 ppp=AH2(pp);

  AF2 p0=fp*AF2_AU2(con1.xy)+AF2_AU2(con1.zw);
  AF2 p1=p0+AF2_AU2(con2.xy);
  AF2 p2=p0+AF2_AU2(con2.zw);
  AF2 p3=p0+AF2_AU2(con3.xy);
  AH4 bczzR=FsrEasuRH(p0);
  AH4 bczzG=FsrEasuGH(p0);
  AH4 bczzB=FsrEasuBH(p0);
  AH4 ijfeR=FsrEasuRH(p1);
  AH4 ijfeG=FsrEasuGH(p1);
  AH4 ijfeB=FsrEasuBH(p1);
  AH4 klhgR=FsrEasuRH(p2);
  AH4 klhgG=FsrEasuGH(p2);
  AH4 klhgB=FsrEasuBH(p2);
  AH4 zzonR=FsrEasuRH(p3);
  AH4 zzonG=FsrEasuGH(p3);
  AH4 zzonB=FsrEasuBH(p3);

  AH4 bczzL=bczzB*AH4_(0.5)+(bczzR*AH4_(0.5)+bczzG);
  AH4 ijfeL=ijfeB*AH4_(0.5)+(ijfeR*AH4_(0.5)+ijfeG);
  AH4 klhgL=klhgB*AH4_(0.5)+(klhgR*AH4_(0.5)+klhgG);
  AH4 zzonL=zzonB*AH4_(0.5)+(zzonR*AH4_(0.5)+zzonG);
  AH1 bL=bczzL.x;
  AH1 cL=bczzL.y;
  AH1 iL=ijfeL.x;
  AH1 jL=ijfeL.y;
  AH1 fL=ijfeL.z;
  AH1 eL=ijfeL.w;
  AH1 kL=klhgL.x;
  AH1 lL=klhgL.y;
  AH1 hL=klhgL.z;
  AH1 gL=klhgL.w;
  AH1 oL=zzonL.z;
  AH1 nL=zzonL.w;
  
  AH2 dirPX=AH2_(0.0);
  AH2 dirPY=AH2_(0.0);
  AH2 lenP=AH2_(0.0);
  FsrEasuSetH(dirPX,dirPY,lenP,ppp,true, false,AH2(bL,cL),AH2(eL,fL),AH2(fL,gL),AH2(gL,hL),AH2(jL,kL));
  FsrEasuSetH(dirPX,dirPY,lenP,ppp,false,true ,AH2(fL,gL),AH2(iL,jL),AH2(jL,kL),AH2(kL,lL),AH2(nL,oL));
  AH2 dir=AH2(dirPX.r+dirPX.g,dirPY.r+dirPY.g);
  AH1 len=lenP.r+lenP.g;

  AH2 dir2=dir*dir;
  AH1 dirR=dir2.x+dir2.y;
  AP1 zro=dirR<AH1_(1.0/32768.0);
  dirR=APrxLoRsqH1(dirR);
  dirR=zro?AH1_(1.0):dirR;
  dir.x=zro?AH1_(1.0):dir.x;
  dir*=AH2_(dirR);
  len=len*AH1_(0.5);
  len*=len;
  AH1 stretch=(dir.x*dir.x+dir.y*dir.y)*APrxLoRcpH1(max(abs(dir.x),abs(dir.y)));
  AH2 len2=AH2(AH1_(1.0)+(stretch-AH1_(1.0))*len,AH1_(1.0)+AH1_(-0.5)*len);
  AH1 lob=AH1_(0.5)+AH1_((1.0/4.0-0.04)-0.5)*len;
  AH1 clp=APrxLoRcpH1(lob);

  
  AH2 bothR=max(max(AH2(-ijfeR.z,ijfeR.z),AH2(-klhgR.w,klhgR.w)),max(AH2(-ijfeR.y,ijfeR.y),AH2(-klhgR.x,klhgR.x)));
  AH2 bothG=max(max(AH2(-ijfeG.z,ijfeG.z),AH2(-klhgG.w,klhgG.w)),max(AH2(-ijfeG.y,ijfeG.y),AH2(-klhgG.x,klhgG.x)));
  AH2 bothB=max(max(AH2(-ijfeB.z,ijfeB.z),AH2(-klhgB.w,klhgB.w)),max(AH2(-ijfeB.y,ijfeB.y),AH2(-klhgB.x,klhgB.x)));
  
  AH2 pR=AH2_(0.0);
  AH2 pG=AH2_(0.0);
  AH2 pB=AH2_(0.0);
  AH2 pW=AH2_(0.0);
  FsrEasuTapH(pR,pG,pB,pW,AH2( 0.0, 1.0)-ppp.xx,AH2(-1.0,-1.0)-ppp.yy,dir,len2,lob,clp,bczzR.xy,bczzG.xy,bczzB.xy);
  FsrEasuTapH(pR,pG,pB,pW,AH2(-1.0, 0.0)-ppp.xx,AH2( 1.0, 1.0)-ppp.yy,dir,len2,lob,clp,ijfeR.xy,ijfeG.xy,ijfeB.xy);
  FsrEasuTapH(pR,pG,pB,pW,AH2( 0.0,-1.0)-ppp.xx,AH2( 0.0, 0.0)-ppp.yy,dir,len2,lob,clp,ijfeR.zw,ijfeG.zw,ijfeB.zw);
  FsrEasuTapH(pR,pG,pB,pW,AH2( 1.0, 2.0)-ppp.xx,AH2( 1.0, 1.0)-ppp.yy,dir,len2,lob,clp,klhgR.xy,klhgG.xy,klhgB.xy);
  FsrEasuTapH(pR,pG,pB,pW,AH2( 2.0, 1.0)-ppp.xx,AH2( 0.0, 0.0)-ppp.yy,dir,len2,lob,clp,klhgR.zw,klhgG.zw,klhgB.zw);
  FsrEasuTapH(pR,pG,pB,pW,AH2( 1.0, 0.0)-ppp.xx,AH2( 2.0, 2.0)-ppp.yy,dir,len2,lob,clp,zzonR.zw,zzonG.zw,zzonB.zw);
  AH3 aC=AH3(pR.x+pR.y,pG.x+pG.y,pB.x+pB.y);
  AH1 aW=pW.x+pW.y;

  
  pix=min(AH3(bothR.y,bothG.y,bothB.y),max(-AH3(bothR.x,bothG.x,bothB.x),aC*AH3_(ARcpH1(aW))));}
#endif



























































#define FSR_RCAS_LIMIT (0.25-(1.0/16.0))







A_STATIC void FsrRcasCon(
outAU4 con,

AF1 sharpness){
 
 sharpness=AExp2F1(-sharpness);
 varAF2(hSharp)=initAF2(sharpness,sharpness);
 con[0]=AU1_AF1(sharpness);
 con[1]=AU1_AH2_AF2(hSharp);
 con[2]=0;
 con[3]=0;}






#if defined(A_GPU)&&defined(FSR_RCAS_F)
 
 AF4 FsrRcasLoadF(ASU2 p);
 void FsrRcasInputF(inout AF1 r,inout AF1 g,inout AF1 b);

 void FsrRcasF(
 out AF1 pixR, 
 out AF1 pixG,
 out AF1 pixB,
 #ifdef FSR_RCAS_PASSTHROUGH_ALPHA
  out AF1 pixA,
 #endif
 AU2 ip, 
 AU4 con){ 
  
  
  
  
  ASU2 sp=ASU2(ip);
  AF3 b=FsrRcasLoadF(sp+ASU2( 0,-1)).rgb;
  AF3 d=FsrRcasLoadF(sp+ASU2(-1, 0)).rgb;
  #ifdef FSR_RCAS_PASSTHROUGH_ALPHA
   AF4 ee=FsrRcasLoadF(sp);
   AF3 e=ee.rgb;pixA=ee.a;
  #else
   AF3 e=FsrRcasLoadF(sp).rgb;
  #endif
  AF3 f=FsrRcasLoadF(sp+ASU2( 1, 0)).rgb;
  AF3 h=FsrRcasLoadF(sp+ASU2( 0, 1)).rgb;
  
  AF1 bR=b.r;
  AF1 bG=b.g;
  AF1 bB=b.b;
  AF1 dR=d.r;
  AF1 dG=d.g;
  AF1 dB=d.b;
  AF1 eR=e.r;
  AF1 eG=e.g;
  AF1 eB=e.b;
  AF1 fR=f.r;
  AF1 fG=f.g;
  AF1 fB=f.b;
  AF1 hR=h.r;
  AF1 hG=h.g;
  AF1 hB=h.b;
  
  FsrRcasInputF(bR,bG,bB);
  FsrRcasInputF(dR,dG,dB);
  FsrRcasInputF(eR,eG,eB);
  FsrRcasInputF(fR,fG,fB);
  FsrRcasInputF(hR,hG,hB);
  
  AF1 bL=bB*AF1_(0.5)+(bR*AF1_(0.5)+bG);
  AF1 dL=dB*AF1_(0.5)+(dR*AF1_(0.5)+dG);
  AF1 eL=eB*AF1_(0.5)+(eR*AF1_(0.5)+eG);
  AF1 fL=fB*AF1_(0.5)+(fR*AF1_(0.5)+fG);
  AF1 hL=hB*AF1_(0.5)+(hR*AF1_(0.5)+hG);
  
  AF1 nz=AF1_(0.25)*bL+AF1_(0.25)*dL+AF1_(0.25)*fL+AF1_(0.25)*hL-eL;
  nz=ASatF1(abs(nz)*APrxMedRcpF1(AMax3F1(AMax3F1(bL,dL,eL),fL,hL)-AMin3F1(AMin3F1(bL,dL,eL),fL,hL)));
  nz=AF1_(-0.5)*nz+AF1_(1.0);
  
  AF1 mn4R=min(AMin3F1(bR,dR,fR),hR);
  AF1 mn4G=min(AMin3F1(bG,dG,fG),hG);
  AF1 mn4B=min(AMin3F1(bB,dB,fB),hB);
  AF1 mx4R=max(AMax3F1(bR,dR,fR),hR);
  AF1 mx4G=max(AMax3F1(bG,dG,fG),hG);
  AF1 mx4B=max(AMax3F1(bB,dB,fB),hB);
  
  AF2 peakC=AF2(1.0,-1.0*4.0);
  
  AF1 hitMinR=min(mn4R,eR)*ARcpF1(AF1_(4.0)*mx4R);
  AF1 hitMinG=min(mn4G,eG)*ARcpF1(AF1_(4.0)*mx4G);
  AF1 hitMinB=min(mn4B,eB)*ARcpF1(AF1_(4.0)*mx4B);
  AF1 hitMaxR=(peakC.x-max(mx4R,eR))*ARcpF1(AF1_(4.0)*mn4R+peakC.y);
  AF1 hitMaxG=(peakC.x-max(mx4G,eG))*ARcpF1(AF1_(4.0)*mn4G+peakC.y);
  AF1 hitMaxB=(peakC.x-max(mx4B,eB))*ARcpF1(AF1_(4.0)*mn4B+peakC.y);
  AF1 lobeR=max(-hitMinR,hitMaxR);
  AF1 lobeG=max(-hitMinG,hitMaxG);
  AF1 lobeB=max(-hitMinB,hitMaxB);
  AF1 lobe=max(AF1_(-FSR_RCAS_LIMIT),min(AMax3F1(lobeR,lobeG,lobeB),AF1_(0.0)))*AF1_AU1(con.x);
  
  #ifdef FSR_RCAS_DENOISE
   lobe*=nz;
  #endif
  
  AF1 rcpL=APrxMedRcpF1(AF1_(4.0)*lobe+AF1_(1.0));
  pixR=(lobe*bR+lobe*dR+lobe*hR+lobe*fR+eR)*rcpL;
  pixG=(lobe*bG+lobe*dG+lobe*hG+lobe*fG+eG)*rcpL;
  pixB=(lobe*bB+lobe*dB+lobe*hB+lobe*fB+eB)*rcpL;
  return;} 
#endif






#if defined(A_GPU)&&defined(A_HALF)&&defined(FSR_RCAS_H)
 
 AH4 FsrRcasLoadH(ASW2 p);
 void FsrRcasInputH(inout AH1 r,inout AH1 g,inout AH1 b);

 void FsrRcasH(
 out AH1 pixR, 
 out AH1 pixG,
 out AH1 pixB,
 #ifdef FSR_RCAS_PASSTHROUGH_ALPHA
  out AH1 pixA,
 #endif
 AU2 ip, 
 AU4 con){ 
  
  
  
  
  ASW2 sp=ASW2(ip);
  AH3 b=FsrRcasLoadH(sp+ASW2( 0,-1)).rgb;
  AH3 d=FsrRcasLoadH(sp+ASW2(-1, 0)).rgb;
  #ifdef FSR_RCAS_PASSTHROUGH_ALPHA
   AH4 ee=FsrRcasLoadH(sp);
   AH3 e=ee.rgb;pixA=ee.a;
  #else
   AH3 e=FsrRcasLoadH(sp).rgb;
  #endif
  AH3 f=FsrRcasLoadH(sp+ASW2( 1, 0)).rgb;
  AH3 h=FsrRcasLoadH(sp+ASW2( 0, 1)).rgb;
  
  AH1 bR=b.r;
  AH1 bG=b.g;
  AH1 bB=b.b;
  AH1 dR=d.r;
  AH1 dG=d.g;
  AH1 dB=d.b;
  AH1 eR=e.r;
  AH1 eG=e.g;
  AH1 eB=e.b;
  AH1 fR=f.r;
  AH1 fG=f.g;
  AH1 fB=f.b;
  AH1 hR=h.r;
  AH1 hG=h.g;
  AH1 hB=h.b;
  
  FsrRcasInputH(bR,bG,bB);
  FsrRcasInputH(dR,dG,dB);
  FsrRcasInputH(eR,eG,eB);
  FsrRcasInputH(fR,fG,fB);
  FsrRcasInputH(hR,hG,hB);
  
  AH1 bL=bB*AH1_(0.5)+(bR*AH1_(0.5)+bG);
  AH1 dL=dB*AH1_(0.5)+(dR*AH1_(0.5)+dG);
  AH1 eL=eB*AH1_(0.5)+(eR*AH1_(0.5)+eG);
  AH1 fL=fB*AH1_(0.5)+(fR*AH1_(0.5)+fG);
  AH1 hL=hB*AH1_(0.5)+(hR*AH1_(0.5)+hG);
  
  AH1 nz=AH1_(0.25)*bL+AH1_(0.25)*dL+AH1_(0.25)*fL+AH1_(0.25)*hL-eL;
  nz=ASatH1(abs(nz)*APrxMedRcpH1(AMax3H1(AMax3H1(bL,dL,eL),fL,hL)-AMin3H1(AMin3H1(bL,dL,eL),fL,hL)));
  nz=AH1_(-0.5)*nz+AH1_(1.0);
  
  AH1 mn4R=min(AMin3H1(bR,dR,fR),hR);
  AH1 mn4G=min(AMin3H1(bG,dG,fG),hG);
  AH1 mn4B=min(AMin3H1(bB,dB,fB),hB);
  AH1 mx4R=max(AMax3H1(bR,dR,fR),hR);
  AH1 mx4G=max(AMax3H1(bG,dG,fG),hG);
  AH1 mx4B=max(AMax3H1(bB,dB,fB),hB);
  
  AH2 peakC=AH2(1.0,-1.0*4.0);
  
  AH1 hitMinR=min(mn4R,eR)*ARcpH1(AH1_(4.0)*mx4R);
  AH1 hitMinG=min(mn4G,eG)*ARcpH1(AH1_(4.0)*mx4G);
  AH1 hitMinB=min(mn4B,eB)*ARcpH1(AH1_(4.0)*mx4B);
  AH1 hitMaxR=(peakC.x-max(mx4R,eR))*ARcpH1(AH1_(4.0)*mn4R+peakC.y);
  AH1 hitMaxG=(peakC.x-max(mx4G,eG))*ARcpH1(AH1_(4.0)*mn4G+peakC.y);
  AH1 hitMaxB=(peakC.x-max(mx4B,eB))*ARcpH1(AH1_(4.0)*mn4B+peakC.y);
  AH1 lobeR=max(-hitMinR,hitMaxR);
  AH1 lobeG=max(-hitMinG,hitMaxG);
  AH1 lobeB=max(-hitMinB,hitMaxB);
  AH1 lobe=max(AH1_(-FSR_RCAS_LIMIT),min(AMax3H1(lobeR,lobeG,lobeB),AH1_(0.0)))*AH2_AU1(con.y).x;
  
  #ifdef FSR_RCAS_DENOISE
   lobe*=nz;
  #endif
  
  AH1 rcpL=APrxMedRcpH1(AH1_(4.0)*lobe+AH1_(1.0));
  pixR=(lobe*bR+lobe*dR+lobe*hR+lobe*fR+eR)*rcpL;
  pixG=(lobe*bG+lobe*dG+lobe*hG+lobe*fG+eG)*rcpL;
  pixB=(lobe*bB+lobe*dB+lobe*hB+lobe*fB+eB)*rcpL;}
#endif






#if defined(A_GPU)&&defined(A_HALF)&&defined(FSR_RCAS_HX2)
 
 AH4 FsrRcasLoadHx2(ASW2 p);
 void FsrRcasInputHx2(inout AH2 r,inout AH2 g,inout AH2 b);

 
 void FsrRcasDepackHx2(out AH4 pix0,out AH4 pix1,AH2 pixR,AH2 pixG,AH2 pixB){
  #ifdef A_HLSL
   
   pix0.a=pix1.a=0.0;
  #endif
  pix0.rgb=AH3(pixR.x,pixG.x,pixB.x);
  pix1.rgb=AH3(pixR.y,pixG.y,pixB.y);}

 void FsrRcasHx2(
 
 
 
 
 out AH2 pixR,
 out AH2 pixG,
 out AH2 pixB,
 #ifdef FSR_RCAS_PASSTHROUGH_ALPHA
  out AH2 pixA,
 #endif
 AU2 ip, 
 AU4 con){ 
  
  ASW2 sp0=ASW2(ip);
  AH3 b0=FsrRcasLoadHx2(sp0+ASW2( 0,-1)).rgb;
  AH3 d0=FsrRcasLoadHx2(sp0+ASW2(-1, 0)).rgb;
  #ifdef FSR_RCAS_PASSTHROUGH_ALPHA
   AH4 ee0=FsrRcasLoadHx2(sp0);
   AH3 e0=ee0.rgb;pixA.r=ee0.a;
  #else
   AH3 e0=FsrRcasLoadHx2(sp0).rgb;
  #endif
  AH3 f0=FsrRcasLoadHx2(sp0+ASW2( 1, 0)).rgb;
  AH3 h0=FsrRcasLoadHx2(sp0+ASW2( 0, 1)).rgb;
  ASW2 sp1=sp0+ASW2(8,0);
  AH3 b1=FsrRcasLoadHx2(sp1+ASW2( 0,-1)).rgb;
  AH3 d1=FsrRcasLoadHx2(sp1+ASW2(-1, 0)).rgb;
  #ifdef FSR_RCAS_PASSTHROUGH_ALPHA
   AH4 ee1=FsrRcasLoadHx2(sp1);
   AH3 e1=ee1.rgb;pixA.g=ee1.a;
  #else
   AH3 e1=FsrRcasLoadHx2(sp1).rgb;
  #endif
  AH3 f1=FsrRcasLoadHx2(sp1+ASW2( 1, 0)).rgb;
  AH3 h1=FsrRcasLoadHx2(sp1+ASW2( 0, 1)).rgb;
  
  AH2 bR=AH2(b0.r,b1.r);
  AH2 bG=AH2(b0.g,b1.g);
  AH2 bB=AH2(b0.b,b1.b);
  AH2 dR=AH2(d0.r,d1.r);
  AH2 dG=AH2(d0.g,d1.g);
  AH2 dB=AH2(d0.b,d1.b);
  AH2 eR=AH2(e0.r,e1.r);
  AH2 eG=AH2(e0.g,e1.g);
  AH2 eB=AH2(e0.b,e1.b);
  AH2 fR=AH2(f0.r,f1.r);
  AH2 fG=AH2(f0.g,f1.g);
  AH2 fB=AH2(f0.b,f1.b);
  AH2 hR=AH2(h0.r,h1.r);
  AH2 hG=AH2(h0.g,h1.g);
  AH2 hB=AH2(h0.b,h1.b);
  
  FsrRcasInputHx2(bR,bG,bB);
  FsrRcasInputHx2(dR,dG,dB);
  FsrRcasInputHx2(eR,eG,eB);
  FsrRcasInputHx2(fR,fG,fB);
  FsrRcasInputHx2(hR,hG,hB);
  
  AH2 bL=bB*AH2_(0.5)+(bR*AH2_(0.5)+bG);
  AH2 dL=dB*AH2_(0.5)+(dR*AH2_(0.5)+dG);
  AH2 eL=eB*AH2_(0.5)+(eR*AH2_(0.5)+eG);
  AH2 fL=fB*AH2_(0.5)+(fR*AH2_(0.5)+fG);
  AH2 hL=hB*AH2_(0.5)+(hR*AH2_(0.5)+hG);
  
  AH2 nz=AH2_(0.25)*bL+AH2_(0.25)*dL+AH2_(0.25)*fL+AH2_(0.25)*hL-eL;
  nz=ASatH2(abs(nz)*APrxMedRcpH2(AMax3H2(AMax3H2(bL,dL,eL),fL,hL)-AMin3H2(AMin3H2(bL,dL,eL),fL,hL)));
  nz=AH2_(-0.5)*nz+AH2_(1.0);
  
  AH2 mn4R=min(AMin3H2(bR,dR,fR),hR);
  AH2 mn4G=min(AMin3H2(bG,dG,fG),hG);
  AH2 mn4B=min(AMin3H2(bB,dB,fB),hB);
  AH2 mx4R=max(AMax3H2(bR,dR,fR),hR);
  AH2 mx4G=max(AMax3H2(bG,dG,fG),hG);
  AH2 mx4B=max(AMax3H2(bB,dB,fB),hB);
  
  AH2 peakC=AH2(1.0,-1.0*4.0);
  
  AH2 hitMinR=min(mn4R,eR)*ARcpH2(AH2_(4.0)*mx4R);
  AH2 hitMinG=min(mn4G,eG)*ARcpH2(AH2_(4.0)*mx4G);
  AH2 hitMinB=min(mn4B,eB)*ARcpH2(AH2_(4.0)*mx4B);
  AH2 hitMaxR=(peakC.x-max(mx4R,eR))*ARcpH2(AH2_(4.0)*mn4R+peakC.y);
  AH2 hitMaxG=(peakC.x-max(mx4G,eG))*ARcpH2(AH2_(4.0)*mn4G+peakC.y);
  AH2 hitMaxB=(peakC.x-max(mx4B,eB))*ARcpH2(AH2_(4.0)*mn4B+peakC.y);
  AH2 lobeR=max(-hitMinR,hitMaxR);
  AH2 lobeG=max(-hitMinG,hitMaxG);
  AH2 lobeB=max(-hitMinB,hitMaxB);
  AH2 lobe=max(AH2_(-FSR_RCAS_LIMIT),min(AMax3H2(lobeR,lobeG,lobeB),AH2_(0.0)))*AH2_(AH2_AU1(con.y).x);
  
  #ifdef FSR_RCAS_DENOISE
   lobe*=nz;
  #endif
  
  AH2 rcpL=APrxMedRcpH2(AH2_(4.0)*lobe+AH2_(1.0));
  pixR=(lobe*bR+lobe*dR+lobe*hR+lobe*fR+eR)*rcpL;
  pixG=(lobe*bG+lobe*dG+lobe*hG+lobe*fG+eG)*rcpL;
  pixB=(lobe*bB+lobe*dB+lobe*hB+lobe*fB+eB)*rcpL;}
#endif


























#if defined(A_GPU)
 
 void FsrLfgaF(inout AF3 c,AF3 t,AF1 a){c+=(t*AF3_(a))*min(AF3_(1.0)-c,c);}
#endif

#if defined(A_GPU)&&defined(A_HALF)
 
 void FsrLfgaH(inout AH3 c,AH3 t,AH1 a){c+=(t*AH3_(a))*min(AH3_(1.0)-c,c);}

 
 void FsrLfgaHx2(inout AH2 cR,inout AH2 cG,inout AH2 cB,AH2 tR,AH2 tG,AH2 tB,AH1 a){
  cR+=(tR*AH2_(a))*min(AH2_(1.0)-cR,cR);cG+=(tG*AH2_(a))*min(AH2_(1.0)-cG,cG);cB+=(tB*AH2_(a))*min(AH2_(1.0)-cB,cB);}
#endif

















#if defined(A_GPU)
 void FsrSrtmF(inout AF3 c){c*=AF3_(ARcpF1(AMax3F1(c.r,c.g,c.b)+AF1_(1.0)));}
 
 void FsrSrtmInvF(inout AF3 c){c*=AF3_(ARcpF1(max(AF1_(1.0/32768.0),AF1_(1.0)-AMax3F1(c.r,c.g,c.b))));}
#endif

#if defined(A_GPU)&&defined(A_HALF)
 void FsrSrtmH(inout AH3 c){c*=AH3_(ARcpH1(AMax3H1(c.r,c.g,c.b)+AH1_(1.0)));}
 void FsrSrtmInvH(inout AH3 c){c*=AH3_(ARcpH1(max(AH1_(1.0/32768.0),AH1_(1.0)-AMax3H1(c.r,c.g,c.b))));}

 void FsrSrtmHx2(inout AH2 cR,inout AH2 cG,inout AH2 cB){
  AH2 rcp=ARcpH2(AMax3H2(cR,cG,cB)+AH2_(1.0));cR*=rcp;cG*=rcp;cB*=rcp;}
 void FsrSrtmInvHx2(inout AH2 cR,inout AH2 cG,inout AH2 cB){
  AH2 rcp=ARcpH2(max(AH2_(1.0/32768.0),AH2_(1.0)-AMax3H2(cR,cG,cB)));cR*=rcp;cG*=rcp;cB*=rcp;}
#endif

























#if defined(A_GPU)
 
 
 
 AF1 FsrTepdDitF(AU2 p,AU1 f){
  AF1 x=AF1_(p.x+f);
  AF1 y=AF1_(p.y);
  
  AF1 a=AF1_((1.0+sqrt(5.0))/2.0);
  
  AF1 b=AF1_(1.0/3.69);
  x=x*a+(y*b);
  return AFractF1(x);}

 
 
 
 void FsrTepdC8F(inout AF3 c,AF1 dit){
  AF3 n=sqrt(c);
  n=floor(n*AF3_(255.0))*AF3_(1.0/255.0);
  AF3 a=n*n;
  AF3 b=n+AF3_(1.0/255.0);b=b*b;
  
  
  
  AF3 r=(c-b)*APrxMedRcpF3(a-b);
  
  
  c=ASatF3(n+AGtZeroF3(AF3_(dit)-r)*AF3_(1.0/255.0));}
)<!>" R"<!>(
 
 
 
 void FsrTepdC10F(inout AF3 c,AF1 dit){
  AF3 n=sqrt(c);
  n=floor(n*AF3_(1023.0))*AF3_(1.0/1023.0);
  AF3 a=n*n;
  AF3 b=n+AF3_(1.0/1023.0);b=b*b;
  AF3 r=(c-b)*APrxMedRcpF3(a-b);
  c=ASatF3(n+AGtZeroF3(AF3_(dit)-r)*AF3_(1.0/1023.0));}
#endif

#if defined(A_GPU)&&defined(A_HALF)
 AH1 FsrTepdDitH(AU2 p,AU1 f){
  AF1 x=AF1_(p.x+f);
  AF1 y=AF1_(p.y);
  AF1 a=AF1_((1.0+sqrt(5.0))/2.0);
  AF1 b=AF1_(1.0/3.69);
  x=x*a+(y*b);
  return AH1(AFractF1(x));}

 void FsrTepdC8H(inout AH3 c,AH1 dit){
  AH3 n=sqrt(c);
  n=floor(n*AH3_(255.0))*AH3_(1.0/255.0);
  AH3 a=n*n;
  AH3 b=n+AH3_(1.0/255.0);b=b*b;
  AH3 r=(c-b)*APrxMedRcpH3(a-b);
  c=ASatH3(n+AGtZeroH3(AH3_(dit)-r)*AH3_(1.0/255.0));}

 void FsrTepdC10H(inout AH3 c,AH1 dit){
  AH3 n=sqrt(c);
  n=floor(n*AH3_(1023.0))*AH3_(1.0/1023.0);
  AH3 a=n*n;
  AH3 b=n+AH3_(1.0/1023.0);b=b*b;
  AH3 r=(c-b)*APrxMedRcpH3(a-b);
  c=ASatH3(n+AGtZeroH3(AH3_(dit)-r)*AH3_(1.0/1023.0));}

 
 AH2 FsrTepdDitHx2(AU2 p,AU1 f){
  AF2 x;
  x.x=AF1_(p.x+f);
  x.y=x.x+AF1_(8.0);
  AF1 y=AF1_(p.y);
  AF1 a=AF1_((1.0+sqrt(5.0))/2.0);
  AF1 b=AF1_(1.0/3.69);
  x=x*AF2_(a)+AF2_(y*b);
  return AH2(AFractF2(x));}

 void FsrTepdC8Hx2(inout AH2 cR,inout AH2 cG,inout AH2 cB,AH2 dit){
  AH2 nR=sqrt(cR);
  AH2 nG=sqrt(cG);
  AH2 nB=sqrt(cB);
  nR=floor(nR*AH2_(255.0))*AH2_(1.0/255.0);
  nG=floor(nG*AH2_(255.0))*AH2_(1.0/255.0);
  nB=floor(nB*AH2_(255.0))*AH2_(1.0/255.0);
  AH2 aR=nR*nR;
  AH2 aG=nG*nG;
  AH2 aB=nB*nB;
  AH2 bR=nR+AH2_(1.0/255.0);bR=bR*bR;
  AH2 bG=nG+AH2_(1.0/255.0);bG=bG*bG;
  AH2 bB=nB+AH2_(1.0/255.0);bB=bB*bB;
  AH2 rR=(cR-bR)*APrxMedRcpH2(aR-bR);
  AH2 rG=(cG-bG)*APrxMedRcpH2(aG-bG);
  AH2 rB=(cB-bB)*APrxMedRcpH2(aB-bB);
  cR=ASatH2(nR+AGtZeroH2(dit-rR)*AH2_(1.0/255.0));
  cG=ASatH2(nG+AGtZeroH2(dit-rG)*AH2_(1.0/255.0));
  cB=ASatH2(nB+AGtZeroH2(dit-rB)*AH2_(1.0/255.0));}

 void FsrTepdC10Hx2(inout AH2 cR,inout AH2 cG,inout AH2 cB,AH2 dit){
  AH2 nR=sqrt(cR);
  AH2 nG=sqrt(cG);
  AH2 nB=sqrt(cB);
  nR=floor(nR*AH2_(1023.0))*AH2_(1.0/1023.0);
  nG=floor(nG*AH2_(1023.0))*AH2_(1.0/1023.0);
  nB=floor(nB*AH2_(1023.0))*AH2_(1.0/1023.0);
  AH2 aR=nR*nR;
  AH2 aG=nG*nG;
  AH2 aB=nB*nB;
  AH2 bR=nR+AH2_(1.0/1023.0);bR=bR*bR;
  AH2 bG=nG+AH2_(1.0/1023.0);bG=bG*bG;
  AH2 bB=nB+AH2_(1.0/1023.0);bB=bB*bB;
  AH2 rR=(cR-bR)*APrxMedRcpH2(aR-bR);
  AH2 rG=(cG-bG)*APrxMedRcpH2(aG-bG);
  AH2 rB=(cB-bB)*APrxMedRcpH2(aB-bB);
  cR=ASatH2(nR+AGtZeroH2(dit-rR)*AH2_(1.0/1023.0));
  cG=ASatH2(nG+AGtZeroH2(dit-rG)*AH2_(1.0/1023.0));
  cB=ASatH2(nB+AGtZeroH2(dit-rB)*AH2_(1.0/1023.0));}
#endif

void fsr_easu_pass(AU2 pos) {
#ifdef MODE_FSR_UPSCALE_NORMAL

	AH3 Gamma2Color = AH3(0, 0, 0);
	FsrEasuH(Gamma2Color, pos, Const0, Const1, Const2, Const3);
	imageStore(fsr_image, ASU2(pos), AH4(Gamma2Color, 1));

#else

	AF3 Gamma2Color = AF3(0, 0, 0);
	FsrEasuF(Gamma2Color, pos, Const0, Const1, Const2, Const3);
	imageStore(fsr_image, ASU2(pos), AF4(Gamma2Color, 1));

#endif
}

void fsr_rcas_pass(AU2 pos) {
#ifdef MODE_FSR_UPSCALE_NORMAL

	AH3 Gamma2Color = AH3(0, 0, 0);
	FsrRcasH(Gamma2Color.r, Gamma2Color.g, Gamma2Color.b, pos, Const0);
	imageStore(fsr_image, ASU2(pos), AH4(Gamma2Color, 1));

#else

	AF3 Gamma2Color = AF3(0, 0, 0);
	FsrRcasF(Gamma2Color.r, Gamma2Color.g, Gamma2Color.b, pos, Const0);
	imageStore(fsr_image, ASU2(pos), AF4(Gamma2Color, 1));

#endif
}

void fsr_pass(AU2 pos) {
	if (params.pass == FSR_UPSCALE_PASS_TYPE_EASU) {
		fsr_easu_pass(pos);
	} else if (params.pass == FSR_UPSCALE_PASS_TYPE_RCAS) {
		fsr_rcas_pass(pos);
	}
}

void main() {
	
	if (params.pass == FSR_UPSCALE_PASS_TYPE_EASU) {
		FsrEasuCon(Const0, Const1, Const2, Const3, params.resolution_width, params.resolution_height, params.resolution_width, params.resolution_height, params.upscaled_width, params.upscaled_height);
	} else if (params.pass == FSR_UPSCALE_PASS_TYPE_RCAS) {
		FsrRcasCon(Const0, params.sharpness);
	}

	AU2 gxy = ARmp8x8(gl_LocalInvocationID.x) + AU2(gl_WorkGroupID.x << 4u, gl_WorkGroupID.y << 4u);

	fsr_pass(gxy);
	gxy.x += 8u;
	fsr_pass(gxy);
	gxy.y += 8u;
	fsr_pass(gxy);
	gxy.x -= 8u;
	fsr_pass(gxy);
}
)<!>"
		};
		setup(nullptr, nullptr, _compute_code, "FsrUpscaleShaderRD");
	}
};

#endif
