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

#if !defined(SIMDE_HEXAGON_HVX_VUNPACK_H)
#define SIMDE_HEXAGON_HVX_VUNPACK_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vsxt_Vb(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vsxt_Vb(Vu);
  #else
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, a_.i8[2 * i]);
      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(int16_t, a_.i8[2 * i + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vsxt_Vb
  #define Q6_Wh_vsxt_Vb(Vu) simde_Q6_Wh_vsxt_Vb((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vsxt_Vh(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vsxt_Vh(Vu);
  #else
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * i]);
      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] = HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * i + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vsxt_Vh
  #define Q6_Ww_vsxt_Vh(Vu) simde_Q6_Ww_vsxt_Vh((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuh_vzxt_Vub(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuh_vzxt_Vub(Vu);
  #else
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * i]);
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * i + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuh_vzxt_Vub
  #define Q6_Wuh_vzxt_Vub(Vu) simde_Q6_Wuh_vzxt_Vub((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vzxt_Vuh(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuw_vzxt_Vuh(Vu);
  #else
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * i]);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] = HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * i + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vzxt_Vuh
  #define Q6_Wuw_vzxt_Vuh(Vu) simde_Q6_Wuw_vzxt_Vuh((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vunpack_Vb(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vunpack_Vb(Vu);
  #else
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, a_.i8[i]);
      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(int16_t, a_.i8[SIMDE_HVX_VECTOR_I16_COUNT + i]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vunpack_Vb
  #define Q6_Wh_vunpack_Vb(Vu) simde_Q6_Wh_vunpack_Vb((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuh_vunpack_Vub(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuh_vunpack_Vub(Vu);
  #else
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, a_.u8[i]);
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(uint16_t, a_.u8[SIMDE_HVX_VECTOR_I16_COUNT + i]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuh_vunpack_Vub
  #define Q6_Wuh_vunpack_Vub(Vu) simde_Q6_Wuh_vunpack_Vub((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vunpack_Vh(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vunpack_Vh(Vu);
  #else
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, a_.i16[i]);
      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] = HEDLEY_STATIC_CAST(int32_t, a_.i16[SIMDE_HVX_VECTOR_I32_COUNT + i]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vunpack_Vh
  #define Q6_Ww_vunpack_Vh(Vu) simde_Q6_Ww_vunpack_Vh((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vunpack_Vuh(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuw_vunpack_Vuh(Vu);
  #else
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] = HEDLEY_STATIC_CAST(uint32_t, a_.u16[SIMDE_HVX_VECTOR_I32_COUNT + i]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vunpack_Vuh
  #define Q6_Wuw_vunpack_Vuh(Vu) simde_Q6_Wuw_vunpack_Vuh((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vunpackoor_WhVb(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vunpackoor_WhVb(Vxx, Vu);
  #else
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] |= HEDLEY_STATIC_CAST(uint16_t, HEDLEY_STATIC_CAST(uint16_t, a_.u8[i]) << 8);
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + i] |= HEDLEY_STATIC_CAST(uint16_t, HEDLEY_STATIC_CAST(uint16_t, a_.u8[SIMDE_HVX_VECTOR_I16_COUNT + i]) << 8);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vunpackoor_WhVb
  #define Q6_Wh_vunpackoor_WhVb(Vxx, Vu) simde_Q6_Wh_vunpackoor_WhVb((Vxx), (Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vunpackoor_WwVh(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vunpackoor_WwVh(Vxx, Vu);
  #else
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] |= HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]) << 16;
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] |= HEDLEY_STATIC_CAST(uint32_t, a_.u16[SIMDE_HVX_VECTOR_I32_COUNT + i]) << 16;
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vunpackoor_WwVh
  #define Q6_Ww_vunpackoor_WwVh(Vxx, Vu) simde_Q6_Ww_vunpackoor_WwVh((Vxx), (Vu))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VUNPACK_H) */
