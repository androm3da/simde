/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   Qualcomm Technologies, Inc. and/or its subsidiaries.
 */

#if !defined(SIMDE_HEXAGON_HVX_TYPES_H)
#define SIMDE_HEXAGON_HVX_TYPES_H

#include "../../simde-common.h"
#include "../../simde-f16.h"
#include "../../simde-bf16.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* HVX vector size configuration.
 *
 * When compiling natively for Hexagon, auto-detect from __HVX_LENGTH__.
 * Otherwise, default to 128-byte mode for portable emulation.
 * Users may override by defining SIMDE_HEXAGON_HVX_VECTOR_SIZE before
 * including this header. */
#if !defined(SIMDE_HVX_VECTOR_SIZE)
  #if defined(SIMDE_ARCH_HEXAGON_HVX_LENGTH)
    #define SIMDE_HVX_VECTOR_SIZE SIMDE_ARCH_HEXAGON_HVX_LENGTH
  #elif defined(SIMDE_HEXAGON_HVX_VECTOR_SIZE)
    #define SIMDE_HVX_VECTOR_SIZE SIMDE_HEXAGON_HVX_VECTOR_SIZE
  #else
    #define SIMDE_HVX_VECTOR_SIZE 128
  #endif
#endif

#define SIMDE_HVX_PAIR_SIZE (SIMDE_HVX_VECTOR_SIZE * 2)

/* Element counts per vector */
#define SIMDE_HVX_VECTOR_I8_COUNT  (SIMDE_HVX_VECTOR_SIZE)
#define SIMDE_HVX_VECTOR_I16_COUNT (SIMDE_HVX_VECTOR_SIZE / 2)
#define SIMDE_HVX_VECTOR_I32_COUNT (SIMDE_HVX_VECTOR_SIZE / 4)
#define SIMDE_HVX_VECTOR_F32_COUNT (SIMDE_HVX_VECTOR_SIZE / 4)
#define SIMDE_HVX_VECTOR_F16_COUNT (SIMDE_HVX_VECTOR_SIZE / 2)
#define SIMDE_HVX_VECTOR_BF16_COUNT (SIMDE_HVX_VECTOR_SIZE / 2)

/* Private union types for portable fallback paths */

#if defined(SIMDE_VECTOR_SUBSCRIPT)
  #define SIMDE_HVX_DECLARE_VECTOR(Element_Type, Name, Vector_Size) \
    Element_Type Name SIMDE_VECTOR(Vector_Size)
#else
  #define SIMDE_HVX_DECLARE_VECTOR(Element_Type, Name, Vector_Size) \
    Element_Type Name[(Vector_Size) / sizeof(Element_Type)]
#endif

typedef union {
  SIMDE_HVX_DECLARE_VECTOR(int8_t,   i8,  SIMDE_HVX_VECTOR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(int16_t,  i16, SIMDE_HVX_VECTOR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(int32_t,  i32, SIMDE_HVX_VECTOR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(uint8_t,  u8,  SIMDE_HVX_VECTOR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(uint16_t, u16, SIMDE_HVX_VECTOR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(uint32_t, u32, SIMDE_HVX_VECTOR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(simde_float32, f32, SIMDE_HVX_VECTOR_SIZE);
  simde_float16 f16[SIMDE_HVX_VECTOR_F16_COUNT];
  simde_bfloat16 bf16[SIMDE_HVX_VECTOR_BF16_COUNT];

  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    HVX_Vector n;
  #endif

  #if defined(SIMDE_X86_AVX512F_NATIVE) && (SIMDE_HVX_VECTOR_SIZE == 64)
    __m512i m512i;
  #endif
  #if defined(SIMDE_X86_SSE2_NATIVE)
    __m128i m128i[SIMDE_HVX_VECTOR_SIZE / 16];
  #endif
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    int8x16_t  neon_i8[SIMDE_HVX_VECTOR_SIZE / 16];
    int16x8_t  neon_i16[SIMDE_HVX_VECTOR_SIZE / 16];
    int32x4_t  neon_i32[SIMDE_HVX_VECTOR_SIZE / 16];
    uint8x16_t neon_u8[SIMDE_HVX_VECTOR_SIZE / 16];
  #endif
  #if defined(SIMDE_WASM_SIMD128_NATIVE)
    v128_t v128[SIMDE_HVX_VECTOR_SIZE / 16];
  #endif
} simde_hvx_vector_private;

typedef union {
  SIMDE_HVX_DECLARE_VECTOR(int8_t,   i8,  SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(int16_t,  i16, SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(int32_t,  i32, SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(uint8_t,  u8,  SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(uint16_t, u16, SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(uint32_t, u32, SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(simde_float32, f32, SIMDE_HVX_PAIR_SIZE);
  simde_float16 f16[SIMDE_HVX_PAIR_SIZE / sizeof(simde_float16)];
  simde_bfloat16 bf16[SIMDE_HVX_PAIR_SIZE / sizeof(simde_bfloat16)];

  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    HVX_VectorPair n;
  #endif
} simde_hvx_vectorpair_private;

/* Predicate: in HVX a predicate is 1 bit per byte lane,
 * so we represent it as a byte mask (0x00/0xFF per byte) for
 * portable emulation. */
typedef union {
  SIMDE_HVX_DECLARE_VECTOR(uint8_t, u8, SIMDE_HVX_VECTOR_SIZE);

  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    HVX_VectorPred n;
  #endif
} simde_hvx_vectorpred_private;

#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  typedef HVX_Vector     simde_hvx_vector_t;
  typedef HVX_VectorPair simde_hvx_vectorpair_t;
  typedef HVX_VectorPred simde_hvx_vectorpred_t;
#elif defined(SIMDE_VECTOR_SUBSCRIPT)
  typedef int8_t simde_hvx_vector_t     SIMDE_VECTOR(SIMDE_HVX_VECTOR_SIZE) SIMDE_MAY_ALIAS;
  typedef int8_t simde_hvx_vectorpair_t SIMDE_VECTOR(SIMDE_HVX_PAIR_SIZE)   SIMDE_MAY_ALIAS;
  typedef int8_t simde_hvx_vectorpred_t SIMDE_VECTOR(SIMDE_HVX_VECTOR_SIZE) SIMDE_MAY_ALIAS;
#else
  typedef simde_hvx_vector_private     simde_hvx_vector_t;
  typedef simde_hvx_vectorpair_private simde_hvx_vectorpair_t;
  typedef simde_hvx_vectorpred_private simde_hvx_vectorpred_t;
#endif

/* Conversion functions between public and private types */
SIMDE_DEFINE_CONVERSION_FUNCTION_(simde_hvx_vector_to_private,       simde_hvx_vector_private,     simde_hvx_vector_t)
SIMDE_DEFINE_CONVERSION_FUNCTION_(simde_hvx_vector_from_private,     simde_hvx_vector_t,           simde_hvx_vector_private)
SIMDE_DEFINE_CONVERSION_FUNCTION_(simde_hvx_vectorpair_to_private,   simde_hvx_vectorpair_private, simde_hvx_vectorpair_t)
SIMDE_DEFINE_CONVERSION_FUNCTION_(simde_hvx_vectorpair_from_private, simde_hvx_vectorpair_t,       simde_hvx_vectorpair_private)
SIMDE_DEFINE_CONVERSION_FUNCTION_(simde_hvx_vectorpred_to_private,   simde_hvx_vectorpred_private, simde_hvx_vectorpred_t)
SIMDE_DEFINE_CONVERSION_FUNCTION_(simde_hvx_vectorpred_from_private, simde_hvx_vectorpred_t,       simde_hvx_vectorpred_private)

/* ---- f8 E4M3 conversion helpers ---- */

/* Convert an 8-bit E4M3 float to float32. */
SIMDE_FUNCTION_ATTRIBUTES
simde_float32
simde_f8e4m3_to_float32(uint8_t v) {
  uint32_t sign = HEDLEY_STATIC_CAST(uint32_t, v >> 7);
  uint32_t exp8 = (v >> 3) & 0xFu;
  uint32_t man8 = v & 0x7u;
  if (exp8 == 0xFu && man8 == 0x7u) {
    uint32_t bits = 0x7FC00000u | (sign << 31);
    simde_float32 r;
    simde_memcpy(&r, &bits, sizeof(r));
    return r;
  }
  if (exp8 == 0 && man8 == 0) {
    simde_float32 r = 0.0f;
    if (sign) r = -r;
    return r;
  }
  simde_float32 magnitude;
  if (exp8 == 0) {
    magnitude = HEDLEY_STATIC_CAST(simde_float32, man8) * (1.0f / 512.0f);
  } else {
    uint32_t f32_bits = ((exp8 + 120u) << 23) | (man8 << 20);
    simde_memcpy(&magnitude, &f32_bits, sizeof(magnitude));
  }
  return sign ? -magnitude : magnitude;
}

/* Convert float32 to an 8-bit E4M3 float (round to nearest even). */
SIMDE_FUNCTION_ATTRIBUTES
uint8_t
simde_float32_to_f8e4m3(simde_float32 val) {
  uint32_t f32_bits;
  simde_memcpy(&f32_bits, &val, sizeof(f32_bits));
  uint8_t sign = HEDLEY_STATIC_CAST(uint8_t, (f32_bits >> 24) & 0x80u);
  uint32_t f32_exp = (f32_bits >> 23) & 0xFFu;
  uint32_t f32_man = f32_bits & 0x7FFFFFu;
  /* f8e4m3 has no infinity encoding, so +/-inf saturates to max finite,
   * same as any other overflowing magnitude; only a true NaN maps to 0x7F. */
  if (f32_exp == 0xFFu) return (f32_man == 0) ? (sign | 0x7Eu) : (sign | 0x7Fu);
  int32_t exp8 = HEDLEY_STATIC_CAST(int32_t, f32_exp) - 120;
  if (exp8 > 15) {
    return sign | 0x7Eu;
  }
  uint8_t man8;
  if (exp8 <= 0) {
    if (exp8 < -3) return sign;
    uint32_t man_full = (1u << 23) | f32_man;
    int32_t shift = 21 - exp8;
    uint32_t remainder = man_full & ((UINT32_C(1) << shift) - 1);
    uint32_t rounded = man_full >> shift;
    rounded += (remainder > (UINT32_C(1) << (shift - 1))) ||
               ((remainder == (UINT32_C(1) << (shift - 1))) && (rounded & 1u));
    if (rounded == 8u) return sign | 0x08u;
    man8 = HEDLEY_STATIC_CAST(uint8_t, rounded);
  } else {
    uint32_t remainder = f32_man & UINT32_C(0xFFFFF);
    man8 = HEDLEY_STATIC_CAST(uint8_t, f32_man >> 20);
    man8 += (remainder > UINT32_C(0x80000)) ||
            ((remainder == UINT32_C(0x80000)) && (man8 & 1u));
    if (man8 > 7u) {
      man8 = 0u;
      exp8++;
      if (exp8 > 15) return sign | 0x7Eu;
    }
    if ((exp8 == 15) && (man8 == 7u)) return sign | 0x7Eu;
  }
  return sign | (HEDLEY_STATIC_CAST(uint8_t, exp8 > 0 ? exp8 : 0) << 3) | man8;
}

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* SIMDE_HEXAGON_HVX_TYPES_H */
