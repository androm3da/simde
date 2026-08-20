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

#if !defined(SIMDE_HEXAGON_HVX_VNAVG_H)
#define SIMDE_HEXAGON_HVX_VNAVG_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vnavg_VbVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vnavg_VbVb(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, (HEDLEY_STATIC_CAST(int16_t, a_.i8[i]) - HEDLEY_STATIC_CAST(int16_t, b_.i8[i])) >> 1);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vnavg_VbVb
  #define Q6_Vb_vnavg_VbVb(Vu, Vv) simde_Q6_Vb_vnavg_VbVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vnavg_VubVub(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vnavg_VubVub(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, (HEDLEY_STATIC_CAST(int16_t, a_.u8[i]) - HEDLEY_STATIC_CAST(int16_t, b_.u8[i])) >> 1);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vnavg_VubVub
  #define Q6_Vb_vnavg_VubVub(Vu, Vv) simde_Q6_Vb_vnavg_VubVub((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vnavg_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vnavg_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, (HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) - HEDLEY_STATIC_CAST(int32_t, b_.i16[i])) >> 1);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vnavg_VhVh
  #define Q6_Vh_vnavg_VhVh(Vu, Vv) simde_Q6_Vh_vnavg_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vnavg_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vnavg_VwVw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, (HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) - HEDLEY_STATIC_CAST(int64_t, b_.i32[i])) >> 1);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vnavg_VwVw
  #define Q6_Vw_vnavg_VwVw(Vu, Vv) simde_Q6_Vw_vnavg_VwVw((Vu), (Vv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VNAVG_H) */
