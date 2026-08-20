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

#if !defined(SIMDE_HEXAGON_HVX_VPREFIXSUM_H)
#define SIMDE_HEXAGON_HVX_VPREFIXSUM_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_prefixsum_Q(simde_hvx_vectorpred_t Qv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_prefixsum_Q(Qv);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private r_;

    /* Loop-carried dependency; do not vectorize. */
    int8_t sum = 0;
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      sum = HEDLEY_STATIC_CAST(int8_t, sum + (q_.u8[i] & 1));
      r_.i8[i] = sum;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_prefixsum_Q
  #define Q6_Vb_prefixsum_Q(Qv) simde_Q6_Vb_prefixsum_Q((Qv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_prefixsum_Q(simde_hvx_vectorpred_t Qv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_prefixsum_Q(Qv);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private r_;

    /* Loop-carried dependency; do not vectorize. */
    int16_t sum = 0;
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      sum = HEDLEY_STATIC_CAST(int16_t, sum + (q_.u8[i * 2] & 1) + (q_.u8[i * 2 + 1] & 1));
      r_.i16[i] = sum;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_prefixsum_Q
  #define Q6_Vh_prefixsum_Q(Qv) simde_Q6_Vh_prefixsum_Q((Qv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_prefixsum_Q(simde_hvx_vectorpred_t Qv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_prefixsum_Q(Qv);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private r_;

    /* Loop-carried dependency; do not vectorize. */
    int32_t sum = 0;
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      sum += (q_.u8[i * 4] & 1) + (q_.u8[i * 4 + 1] & 1)
           + (q_.u8[i * 4 + 2] & 1) + (q_.u8[i * 4 + 3] & 1);
      r_.i32[i] = sum;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_prefixsum_Q
  #define Q6_Vw_prefixsum_Q(Qv) simde_Q6_Vw_prefixsum_Q((Qv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VPREFIXSUM_H) */
