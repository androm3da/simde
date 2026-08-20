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

#if !defined(SIMDE_HEXAGON_HVX_VDELTA_H)
#define SIMDE_HEXAGON_HVX_VDELTA_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vdelta_VV(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vdelta_VV(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    uint8_t tmp[SIMDE_HVX_VECTOR_SIZE];
    uint8_t ctl[SIMDE_HVX_VECTOR_SIZE];
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      tmp[i] = a_.u8[i];
      ctl[i] = b_.u8[i];
    }

    int max_stage = 0;
    { size_t sz = SIMDE_HVX_VECTOR_SIZE; while (sz > 1) { max_stage++; sz >>= 1; } }

    for (int s = max_stage - 1 ; s >= 0 ; s--) {
      uint8_t next[SIMDE_HVX_VECTOR_SIZE];
      for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
        size_t partner = i ^ (HEDLEY_STATIC_CAST(size_t, 1u) << s);
        next[i] = (ctl[i] & (1u << s)) ? tmp[partner] : tmp[i];
      }
      for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
        tmp[i] = next[i];
      }
    }

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = tmp[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vdelta_VV
  #define Q6_V_vdelta_VV(Vu, Vv) simde_Q6_V_vdelta_VV((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vrdelta_VV(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vrdelta_VV(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    uint8_t tmp[SIMDE_HVX_VECTOR_SIZE];
    uint8_t ctl[SIMDE_HVX_VECTOR_SIZE];
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      tmp[i] = a_.u8[i];
      ctl[i] = b_.u8[i];
    }

    int max_stage = 0;
    { size_t sz = SIMDE_HVX_VECTOR_SIZE; while (sz > 1) { max_stage++; sz >>= 1; } }

    for (int s = 0 ; s < max_stage ; s++) {
      uint8_t next[SIMDE_HVX_VECTOR_SIZE];
      for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
        size_t partner = i ^ (HEDLEY_STATIC_CAST(size_t, 1u) << s);
        next[i] = (ctl[i] & (1u << s)) ? tmp[partner] : tmp[i];
      }
      for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
        tmp[i] = next[i];
      }
    }

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = tmp[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vrdelta_VV
  #define Q6_V_vrdelta_VV(Vu, Vv) simde_Q6_V_vrdelta_VV((Vu), (Vv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VDELTA_H) */
