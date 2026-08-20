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

#if !defined(SIMDE_HEXAGON_HVX_VCONDACC_H)
#define SIMDE_HEXAGON_HVX_VCONDACC_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_condacc_QVbVb(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t Vx, simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_condacc_QVbVb(Qv, Vx, Vu);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      if (q_.u8[i])
        r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, r_.u8[i] + a_.u8[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_condacc_QVbVb
  #define Q6_Vb_condacc_QVbVb(Qv, Vx, Vu) simde_Q6_Vb_condacc_QVbVb((Qv), (Vx), (Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_condacc_QnVbVb(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t Vx, simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_condacc_QnVbVb(Qv, Vx, Vu);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      if (!q_.u8[i])
        r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, r_.u8[i] + a_.u8[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_condacc_QnVbVb
  #define Q6_Vb_condacc_QnVbVb(Qv, Vx, Vu) simde_Q6_Vb_condacc_QnVbVb((Qv), (Vx), (Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_condacc_QVhVh(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t Vx, simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_condacc_QVhVh(Qv, Vx, Vu);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vector_private sum_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      sum_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, r_.u16[i] + a_.u16[i]);
    }
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      if (q_.u8[i])
        r_.u8[i] = sum_.u8[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_condacc_QVhVh
  #define Q6_Vh_condacc_QVhVh(Qv, Vx, Vu) simde_Q6_Vh_condacc_QVhVh((Qv), (Vx), (Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_condacc_QnVhVh(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t Vx, simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_condacc_QnVhVh(Qv, Vx, Vu);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vector_private sum_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      sum_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, r_.u16[i] + a_.u16[i]);
    }
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      if (!q_.u8[i])
        r_.u8[i] = sum_.u8[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_condacc_QnVhVh
  #define Q6_Vh_condacc_QnVhVh(Qv, Vx, Vu) simde_Q6_Vh_condacc_QnVhVh((Qv), (Vx), (Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_condacc_QVwVw(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t Vx, simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_condacc_QVwVw(Qv, Vx, Vu);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vector_private sum_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      sum_.u32[i] = r_.u32[i] + a_.u32[i];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      if (q_.u8[i])
        r_.u8[i] = sum_.u8[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_condacc_QVwVw
  #define Q6_Vw_condacc_QVwVw(Qv, Vx, Vu) simde_Q6_Vw_condacc_QVwVw((Qv), (Vx), (Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_condacc_QnVwVw(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t Vx, simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_condacc_QnVwVw(Qv, Vx, Vu);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vector_private sum_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      sum_.u32[i] = r_.u32[i] + a_.u32[i];
    }
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      if (!q_.u8[i])
        r_.u8[i] = sum_.u8[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_condacc_QnVwVw
  #define Q6_Vw_condacc_QnVwVw(Qv, Vx, Vu) simde_Q6_Vw_condacc_QnVwVw((Qv), (Vx), (Vu))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VCONDACC_H) */
