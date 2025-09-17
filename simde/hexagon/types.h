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
 *   2024      Brian Cain <brian.cain@oss.qualcomm.com> (Qualcomm Technologies,
 *             Inc. and its subsidiaries)
 */

#if !defined(SIMDE_HEXAGON_TYPES_H)
#define SIMDE_HEXAGON_TYPES_H

#include "../simde-common.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

#if defined(SIMDE_HEXAGON_HVX_NATIVE)
#include <hexagon_protos.h>
#include <hexagon_types.h>
#include <hvx_hexagon_protos.h>
#endif

#if !defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#define SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES
#endif

SIMDE_BEGIN_DECLS_

#if defined(SIMDE_VECTOR_SUBSCRIPT)
#define SIMDE_HEXAGON_HVX_DECLARE_VECTOR(Element_Type, Name, Vector_Size) Element_Type Name SIMDE_VECTOR(Vector_Size)
#else
#define SIMDE_HEXAGON_HVX_DECLARE_VECTOR(Element_Type, Name, Vector_Size)                                                   \
  Element_Type Name[(Vector_Size) / sizeof(Element_Type)]
#endif

/* HVX Vector types for 1024-bit mode */
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
typedef HVX_Vector simde_hvx_vector_t;
typedef HVX_VectorPair simde_hvx_vector_pair_t;
typedef HVX_VectorPred simde_hvx_vector_pred_t;
#else
/* For 1024-bit vectors (128 bytes) */
typedef union {
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(int8_t, i8, 128);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(int16_t, i16, 128);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(int32_t, i32, 128);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(int64_t, i64, 128);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint8_t, u8, 128);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint16_t, u16, 128);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint32_t, u32, 128);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint64_t, u64, 128);
#if defined(SIMDE_HAVE_FLOAT16)
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(simde_float16, f16, 128);
#endif
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(simde_float32, f32, 128);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(simde_float64, f64, 128);

#if defined(SIMDE_X86_AVX512F_NATIVE)
  __m512i m512i[2];
  __m512 m512[2];
  __m512d m512d[2];
#endif
} simde_hvx_vector_private;

#if defined(SIMDE_NONALIGNED_STRUCT_) && !defined(SIMDE_BUG_GCC_94482)
typedef struct simde_hvx_vector_t {
  simde_hvx_vector_private private_;
} simde_hvx_vector_t;
#else
typedef simde_hvx_vector_private simde_hvx_vector_t;
#endif

/* Vector pair type (2048 bits / 256 bytes) */
typedef union {
  simde_hvx_vector_t val[2];
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(int8_t, i8, 256);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(int16_t, i16, 256);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(int32_t, i32, 256);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(int64_t, i64, 256);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint8_t, u8, 256);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint16_t, u16, 256);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint32_t, u32, 256);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint64_t, u64, 256);
} simde_hvx_vector_pair_private;

#if defined(SIMDE_NONALIGNED_STRUCT_) && !defined(SIMDE_BUG_GCC_94482)
typedef struct simde_hvx_vector_pair_t {
  simde_hvx_vector_pair_private private_;
} simde_hvx_vector_pair_t;
#else
typedef simde_hvx_vector_pair_private simde_hvx_vector_pair_t;
#endif

/* Predicate type (128 bits for 1024-bit mode) */
typedef union {
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint8_t, u8, 16);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint16_t, u16, 16);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint32_t, u32, 16);
  SIMDE_HEXAGON_HVX_DECLARE_VECTOR(uint64_t, u64, 16);

#if defined(SIMDE_X86_SSE2_NATIVE)
  __m128i m128i;
#endif
} simde_hvx_vector_pred_private;

#if defined(SIMDE_NONALIGNED_STRUCT_) && !defined(SIMDE_BUG_GCC_94482)
typedef struct simde_hvx_vector_pred_t {
  simde_hvx_vector_pred_private private_;
} simde_hvx_vector_pred_t;
#else
typedef simde_hvx_vector_pred_private simde_hvx_vector_pred_t;
#endif
#endif

#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
typedef simde_hvx_vector_t HVX_Vector;
typedef simde_hvx_vector_pair_t HVX_VectorPair;
typedef simde_hvx_vector_pred_t HVX_VectorPred;
#endif

/* Helper functions for type conversion */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_private simde_hvx_vector_to_private(simde_hvx_vector_t a) {
  simde_hvx_vector_private r;
  simde_memcpy(&r, &a, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vector_from_private(simde_hvx_vector_private a) {
  simde_hvx_vector_t r;
  simde_memcpy(&r, &a, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_private simde_hvx_vector_pair_to_private(simde_hvx_vector_pair_t a) {
  simde_hvx_vector_pair_private r;
  simde_memcpy(&r, &a, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_t simde_hvx_vector_pair_from_private(simde_hvx_vector_pair_private a) {
  simde_hvx_vector_pair_t r;
  simde_memcpy(&r, &a, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pred_private simde_hvx_vector_pred_to_private(simde_hvx_vector_pred_t a) {
  simde_hvx_vector_pred_private r;
  simde_memcpy(&r, &a, sizeof(r));
  return r;
}

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pred_t simde_hvx_vector_pred_from_private(simde_hvx_vector_pred_private a) {
  simde_hvx_vector_pred_t r;
  simde_memcpy(&r, &a, sizeof(r));
  return r;
}

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_TYPES_H) */
