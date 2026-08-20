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

#if !defined(SIMDE_HEXAGON_HVX_VLALIGN_H)
#define SIMDE_HEXAGON_HVX_VLALIGN_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vlalign_VVR(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vlalign_VVR(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    size_t offset = ((size_t)Rt) & (SIMDE_HVX_VECTOR_SIZE - 1);
    size_t start = SIMDE_HVX_VECTOR_SIZE - offset;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      size_t src = i + start;
      r_.u8[i] = (src < SIMDE_HVX_VECTOR_SIZE) ? b_.u8[src] : a_.u8[src - SIMDE_HVX_VECTOR_SIZE];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vlalign_VVR
  #define Q6_V_vlalign_VVR(Vu, Vv, Rt) simde_Q6_V_vlalign_VVR((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vlalign_VVI(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Iu3) SIMDE_REQUIRE_CONSTANT_RANGE(Iu3, 0, 7) {
  return simde_Q6_V_vlalign_VVR(Vu, Vv, Iu3 & 7);
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vlalign_VVI
  #define Q6_V_vlalign_VVI(Vu, Vv, Iu3) simde_Q6_V_vlalign_VVI((Vu), (Vv), (Iu3))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VLALIGN_H) */
