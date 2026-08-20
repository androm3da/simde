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

#if !defined(SIMDE_HEXAGON_HVX_VILOG2_H)
#define SIMDE_HEXAGON_HVX_VILOG2_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vilog2_Vsf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vw_vilog2_Vsf)
    return Q6_Vw_vilog2_Vsf(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int32_t exponent = HEDLEY_STATIC_CAST(int32_t, (a_.u32[i] >> 23) & UINT32_C(0xFF));
      uint32_t mantissa = a_.u32[i] & UINT32_C(0x7FFFFF);
      if ((exponent == 0) && (mantissa != 0)) {
        exponent = -149;
        while ((mantissa >>= 1) != 0) exponent++;
        r_.i32[i] = exponent;
      } else {
        r_.i32[i] = exponent - 127;
      }
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vilog2_Vsf
  #define Q6_Vw_vilog2_Vsf(Vu) simde_Q6_Vw_vilog2_Vsf((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vilog2_Vhf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vw_vilog2_Vhf)
    return Q6_Vw_vilog2_Vhf(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int32_t exponent = HEDLEY_STATIC_CAST(int32_t, (a_.u16[i] >> 10) & UINT16_C(0x1F));
      uint16_t mantissa = a_.u16[i] & UINT16_C(0x03FF);
      if ((exponent == 0) && (mantissa != 0)) {
        exponent = -24;
        while ((mantissa >>= 1) != 0) exponent++;
        r_.i32[i] = exponent;
      } else {
        r_.i32[i] = exponent - 15;
      }
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vilog2_Vhf
  #define Q6_Vw_vilog2_Vhf(Vu) simde_Q6_Vw_vilog2_Vhf((Vu))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VILOG2_H) */
