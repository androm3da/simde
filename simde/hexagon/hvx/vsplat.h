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

#if !defined(SIMDE_HEXAGON_HVX_VSPLAT_H)
#define SIMDE_HEXAGON_HVX_VSPLAT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vsplat_R(int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vsplat_R(Rt);
  #else
    simde_hvx_vector_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = Rt;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vsplat_R
  #define Q6_V_vsplat_R(Rt) simde_Q6_V_vsplat_R((Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vsplat_R(int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vsplat_R(Rt);
  #else
    simde_hvx_vector_private r_;
    int8_t val = HEDLEY_STATIC_CAST(int8_t, Rt & 0xFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.i8[i] = val;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vsplat_R
  #define Q6_Vb_vsplat_R(Rt) simde_Q6_Vb_vsplat_R((Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vsplat_R(int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vsplat_R(Rt);
  #else
    simde_hvx_vector_private r_;
    int16_t val = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = val;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vsplat_R
  #define Q6_Vh_vsplat_R(Rt) simde_Q6_Vh_vsplat_R((Rt))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VSPLAT_H) */
