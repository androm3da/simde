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

#if !defined(SIMDE_HEXAGON_HVX_VRMPY_H)
#define SIMDE_HEXAGON_HVX_VRMPY_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vrmpy_VubRb(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vrmpy_VubRb(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 0]) * HEDLEY_STATIC_CAST(int32_t, rb[0]) +
                  HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[1]) +
                  HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(int32_t, rb[2]) +
                  HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(int32_t, rb[3]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vrmpy_VubRb
  #define Q6_Vw_vrmpy_VubRb(Vu, Rt) simde_Q6_Vw_vrmpy_VubRb((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuw_vrmpy_VubRub(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuw_vrmpy_VubRub(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 0]) * HEDLEY_STATIC_CAST(uint32_t, rub[0]) +
                  HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(uint32_t, rub[1]) +
                  HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(uint32_t, rub[2]) +
                  HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(uint32_t, rub[3]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuw_vrmpy_VubRub
  #define Q6_Vuw_vrmpy_VubRub(Vu, Rt) simde_Q6_Vuw_vrmpy_VubRub((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vrmpy_VubVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vrmpy_VubVb(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 0]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 0]) +
                  HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 1]) +
                  HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 2]) +
                  HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 3]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vrmpy_VubVb
  #define Q6_Vw_vrmpy_VubVb(Vu, Vv) simde_Q6_Vw_vrmpy_VubVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vrmpy_VbVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vrmpy_VbVb(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, a_.i8[4 * i + 0]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 0]) +
                  HEDLEY_STATIC_CAST(int32_t, a_.i8[4 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 1]) +
                  HEDLEY_STATIC_CAST(int32_t, a_.i8[4 * i + 2]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 2]) +
                  HEDLEY_STATIC_CAST(int32_t, a_.i8[4 * i + 3]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 3]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vrmpy_VbVb
  #define Q6_Vw_vrmpy_VbVb(Vu, Vv) simde_Q6_Vw_vrmpy_VbVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuw_vrmpy_VubVub(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuw_vrmpy_VubVub(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 0]) * HEDLEY_STATIC_CAST(uint32_t, b_.u8[4 * i + 0]) +
                  HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(uint32_t, b_.u8[4 * i + 1]) +
                  HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(uint32_t, b_.u8[4 * i + 2]) +
                  HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(uint32_t, b_.u8[4 * i + 3]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuw_vrmpy_VubVub
  #define Q6_Vuw_vrmpy_VubVub(Vu, Vv) simde_Q6_Vuw_vrmpy_VubVub((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vrmpyacc_VwVubRb(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vrmpyacc_VwVubRb(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] += HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 0]) * HEDLEY_STATIC_CAST(int32_t, rb[0]) +
                   HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[1]) +
                   HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(int32_t, rb[2]) +
                   HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(int32_t, rb[3]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vrmpyacc_VwVubRb
  #define Q6_Vw_vrmpyacc_VwVubRb(Vx, Vu, Rt) simde_Q6_Vw_vrmpyacc_VwVubRb((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuw_vrmpyacc_VuwVubRub(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuw_vrmpyacc_VuwVubRub(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] += HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 0]) * HEDLEY_STATIC_CAST(uint32_t, rub[0]) +
                   HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(uint32_t, rub[1]) +
                   HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(uint32_t, rub[2]) +
                   HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(uint32_t, rub[3]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuw_vrmpyacc_VuwVubRub
  #define Q6_Vuw_vrmpyacc_VuwVubRub(Vx, Vu, Rt) simde_Q6_Vuw_vrmpyacc_VuwVubRub((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vrmpyacc_VwVubVb(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vrmpyacc_VwVubVb(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] += HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 0]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 0]) +
                   HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 1]) +
                   HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 2]) +
                   HEDLEY_STATIC_CAST(int32_t, a_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 3]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vrmpyacc_VwVubVb
  #define Q6_Vw_vrmpyacc_VwVubVb(Vx, Vu, Vv) simde_Q6_Vw_vrmpyacc_VwVubVb((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vrmpyacc_VwVbVb(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vrmpyacc_VwVbVb(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] += HEDLEY_STATIC_CAST(int32_t, a_.i8[4 * i + 0]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 0]) +
                   HEDLEY_STATIC_CAST(int32_t, a_.i8[4 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 1]) +
                   HEDLEY_STATIC_CAST(int32_t, a_.i8[4 * i + 2]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 2]) +
                   HEDLEY_STATIC_CAST(int32_t, a_.i8[4 * i + 3]) * HEDLEY_STATIC_CAST(int32_t, b_.i8[4 * i + 3]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vrmpyacc_VwVbVb
  #define Q6_Vw_vrmpyacc_VwVbVb(Vx, Vu, Vv) simde_Q6_Vw_vrmpyacc_VwVbVb((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuw_vrmpyacc_VuwVubVub(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuw_vrmpyacc_VuwVubVub(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] += HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 0]) * HEDLEY_STATIC_CAST(uint32_t, b_.u8[4 * i + 0]) +
                   HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(uint32_t, b_.u8[4 * i + 1]) +
                   HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(uint32_t, b_.u8[4 * i + 2]) +
                   HEDLEY_STATIC_CAST(uint32_t, a_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(uint32_t, b_.u8[4 * i + 3]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuw_vrmpyacc_VuwVubVub
  #define Q6_Vuw_vrmpyacc_VuwVubVub(Vx, Vu, Vv) simde_Q6_Vuw_vrmpyacc_VuwVubVub((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vrmpy_WubRubI(simde_hvx_vectorpair_t Vuu, int32_t Rt, int Iu1) SIMDE_REQUIRE_CONSTANT_RANGE(Iu1, 0, 1) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    switch (Iu1) {
      case 0: return Q6_Wuw_vrmpy_WubRubI(Vuu, Rt, 0);
      case 1: return Q6_Wuw_vrmpy_WubRubI(Vuu, Rt, 1);
    }
    HEDLEY_UNREACHABLE();
  #else
    simde_hvx_vectorpair_private
      r_,
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, p_.u8[(Iu1 ? SIMDE_HVX_VECTOR_SIZE : 0) + 4 * i + 0]) * HEDLEY_STATIC_CAST(uint32_t, rub[(0 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(uint32_t, p_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(uint32_t, rub[(1 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(uint32_t, p_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(uint32_t, rub[(2 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(uint32_t, p_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(uint32_t, rub[(3 - Iu1) & 3]);

      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
                  HEDLEY_STATIC_CAST(uint32_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + 0]) * HEDLEY_STATIC_CAST(uint32_t, rub[(2 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(uint32_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + 1]) * HEDLEY_STATIC_CAST(uint32_t, rub[(3 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(uint32_t, p_.u8[(Iu1 ? SIMDE_HVX_VECTOR_SIZE : 0) + 4 * i + 2]) * HEDLEY_STATIC_CAST(uint32_t, rub[(0 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(uint32_t, p_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(uint32_t, rub[(1 - Iu1) & 3]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vrmpy_WubRubI
  #define Q6_Wuw_vrmpy_WubRubI(Vuu, Rt, Iu1) simde_Q6_Wuw_vrmpy_WubRubI((Vuu), (Rt), (Iu1))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vrmpy_WubRbI(simde_hvx_vectorpair_t Vuu, int32_t Rt, int Iu1) SIMDE_REQUIRE_CONSTANT_RANGE(Iu1, 0, 1) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    switch (Iu1) {
      case 0: return Q6_Ww_vrmpy_WubRbI(Vuu, Rt, 0);
      case 1: return Q6_Ww_vrmpy_WubRbI(Vuu, Rt, 1);
    }
    HEDLEY_UNREACHABLE();
  #else
    simde_hvx_vectorpair_private
      r_,
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, p_.u8[(Iu1 ? SIMDE_HVX_VECTOR_SIZE : 0) + 4 * i + 0]) * HEDLEY_STATIC_CAST(int32_t, rb[(0 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(int32_t, p_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[(1 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(int32_t, p_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(int32_t, rb[(2 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(int32_t, p_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(int32_t, rb[(3 - Iu1) & 3]);

      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
                  HEDLEY_STATIC_CAST(int32_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + 0]) * HEDLEY_STATIC_CAST(int32_t, rb[(2 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(int32_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[(3 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(int32_t, p_.u8[(Iu1 ? SIMDE_HVX_VECTOR_SIZE : 0) + 4 * i + 2]) * HEDLEY_STATIC_CAST(int32_t, rb[(0 - Iu1) & 3]) +
                  HEDLEY_STATIC_CAST(int32_t, p_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(int32_t, rb[(1 - Iu1) & 3]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vrmpy_WubRbI
  #define Q6_Ww_vrmpy_WubRbI(Vuu, Rt, Iu1) simde_Q6_Ww_vrmpy_WubRbI((Vuu), (Rt), (Iu1))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vrmpyacc_WuwWubRubI(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt, int Iu1) SIMDE_REQUIRE_CONSTANT_RANGE(Iu1, 0, 1) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    switch (Iu1) {
      case 0: return Q6_Wuw_vrmpyacc_WuwWubRubI(Vxx, Vuu, Rt, 0);
      case 1: return Q6_Wuw_vrmpyacc_WuwWubRubI(Vxx, Vuu, Rt, 1);
    }
    HEDLEY_UNREACHABLE();
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] += HEDLEY_STATIC_CAST(uint32_t, p_.u8[(Iu1 ? SIMDE_HVX_VECTOR_SIZE : 0) + 4 * i + 0]) * HEDLEY_STATIC_CAST(uint32_t, rub[(0 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(uint32_t, p_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(uint32_t, rub[(1 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(uint32_t, p_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(uint32_t, rub[(2 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(uint32_t, p_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(uint32_t, rub[(3 - Iu1) & 3]);

      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
                   HEDLEY_STATIC_CAST(uint32_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + 0]) * HEDLEY_STATIC_CAST(uint32_t, rub[(2 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(uint32_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + 1]) * HEDLEY_STATIC_CAST(uint32_t, rub[(3 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(uint32_t, p_.u8[(Iu1 ? SIMDE_HVX_VECTOR_SIZE : 0) + 4 * i + 2]) * HEDLEY_STATIC_CAST(uint32_t, rub[(0 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(uint32_t, p_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(uint32_t, rub[(1 - Iu1) & 3]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vrmpyacc_WuwWubRubI
  #define Q6_Wuw_vrmpyacc_WuwWubRubI(Vxx, Vuu, Rt, Iu1) simde_Q6_Wuw_vrmpyacc_WuwWubRubI((Vxx), (Vuu), (Rt), (Iu1))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vrmpyacc_WwWubRbI(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt, int Iu1) SIMDE_REQUIRE_CONSTANT_RANGE(Iu1, 0, 1) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    switch (Iu1) {
      case 0: return Q6_Ww_vrmpyacc_WwWubRbI(Vxx, Vuu, Rt, 0);
      case 1: return Q6_Ww_vrmpyacc_WwWubRbI(Vxx, Vuu, Rt, 1);
    }
    HEDLEY_UNREACHABLE();
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] += HEDLEY_STATIC_CAST(int32_t, p_.u8[(Iu1 ? SIMDE_HVX_VECTOR_SIZE : 0) + 4 * i + 0]) * HEDLEY_STATIC_CAST(int32_t, rb[(0 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(int32_t, p_.u8[4 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[(1 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(int32_t, p_.u8[4 * i + 2]) * HEDLEY_STATIC_CAST(int32_t, rb[(2 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(int32_t, p_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(int32_t, rb[(3 - Iu1) & 3]);

      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
                   HEDLEY_STATIC_CAST(int32_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + 0]) * HEDLEY_STATIC_CAST(int32_t, rb[(2 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(int32_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[(3 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(int32_t, p_.u8[(Iu1 ? SIMDE_HVX_VECTOR_SIZE : 0) + 4 * i + 2]) * HEDLEY_STATIC_CAST(int32_t, rb[(0 - Iu1) & 3]) +
                   HEDLEY_STATIC_CAST(int32_t, p_.u8[4 * i + 3]) * HEDLEY_STATIC_CAST(int32_t, rb[(1 - Iu1) & 3]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vrmpyacc_WwWubRbI
  #define Q6_Ww_vrmpyacc_WwWubRbI(Vxx, Vuu, Rt, Iu1) simde_Q6_Ww_vrmpyacc_WwWubRbI((Vxx), (Vuu), (Rt), (Iu1))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VRMPY_H) */
