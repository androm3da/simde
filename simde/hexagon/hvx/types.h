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
 *   2026      Brian Cain <brian.cain@oss.qualcomm.com> (Copyright owned by Qualcomm Technologies, Inc. and its subsidiaries)
 */

#if !defined(SIMDE_HEXAGON_HVX_TYPES_H)
#define SIMDE_HEXAGON_HVX_TYPES_H

#include "../../simde-common.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* HVX vector size.  Hardware supports 64- and 128-byte vectors; when
 * compiling natively the length comes from __HVX_LENGTH__, otherwise we
 * emulate the 128-byte configuration.
 *
 * Only 128-byte vectors are implemented so far.  The 64-byte
 * configuration needs its own test vectors and CI job before it can be
 * claimed, so reject it here rather than silently building something
 * untested. */
#if !defined(SIMDE_HVX_VECTOR_SIZE)
  #if defined(SIMDE_ARCH_HEXAGON_HVX_LENGTH)
    #define SIMDE_HVX_VECTOR_SIZE SIMDE_ARCH_HEXAGON_HVX_LENGTH
  #else
    #define SIMDE_HVX_VECTOR_SIZE 128
  #endif
#endif

#if SIMDE_HVX_VECTOR_SIZE != 128
  #error "SIMDe supports only 128-byte HVX vectors; build with -mhvx-length=128b."
#endif

#define SIMDE_HVX_PAIR_SIZE (SIMDE_HVX_VECTOR_SIZE * 2)

/* Element counts per vector.  Byte lanes are just SIMDE_HVX_VECTOR_SIZE. */
#define SIMDE_HVX_VECTOR_I16_COUNT (SIMDE_HVX_VECTOR_SIZE / 2)
#define SIMDE_HVX_VECTOR_I32_COUNT (SIMDE_HVX_VECTOR_SIZE / 4)

/* Element counts per vector pair */
#define SIMDE_HVX_PAIR_I16_COUNT (SIMDE_HVX_PAIR_SIZE / 2)
#define SIMDE_HVX_PAIR_I32_COUNT (SIMDE_HVX_PAIR_SIZE / 4)

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

  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    HVX_Vector n;
  #endif
} simde_hvx_vector_private;

typedef union {
  SIMDE_HVX_DECLARE_VECTOR(int8_t,   i8,  SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(int16_t,  i16, SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(int32_t,  i32, SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(uint8_t,  u8,  SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(uint16_t, u16, SIMDE_HVX_PAIR_SIZE);
  SIMDE_HVX_DECLARE_VECTOR(uint32_t, u32, SIMDE_HVX_PAIR_SIZE);

  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    HVX_VectorPair n;
  #endif
} simde_hvx_vectorpair_private;

/* A predicate holds one bit per byte lane.  Materialised into a vector
 * register the hardware writes 0x00 or 0xFF per lane, so the portable
 * representation is a byte mask and the two agree byte for byte. */
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

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* SIMDE_HEXAGON_HVX_TYPES_H */
