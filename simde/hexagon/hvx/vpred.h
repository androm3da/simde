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

#if !defined(SIMDE_HEXAGON_HVX_VPRED_H)
#define SIMDE_HEXAGON_HVX_VPRED_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_and_QQ(simde_hvx_vectorpred_t Qs, simde_hvx_vectorpred_t Qt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_and_QQ(Qs, Qt);
  #else
    simde_hvx_vectorpred_private
      r_,
      a_ = simde_hvx_vectorpred_to_private(Qs),
      b_ = simde_hvx_vectorpred_to_private(Qt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = a_.u8[i] & b_.u8[i];
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_and_QQ
  #define Q6_Q_and_QQ(Qs, Qt) simde_Q6_Q_and_QQ((Qs), (Qt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_and_QQn(simde_hvx_vectorpred_t Qs, simde_hvx_vectorpred_t Qt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_and_QQn(Qs, Qt);
  #else
    simde_hvx_vectorpred_private
      r_,
      a_ = simde_hvx_vectorpred_to_private(Qs),
      b_ = simde_hvx_vectorpred_to_private(Qt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = a_.u8[i] & HEDLEY_STATIC_CAST(uint8_t, ~b_.u8[i]);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_and_QQn
  #define Q6_Q_and_QQn(Qs, Qt) simde_Q6_Q_and_QQn((Qs), (Qt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_or_QQ(simde_hvx_vectorpred_t Qs, simde_hvx_vectorpred_t Qt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_or_QQ(Qs, Qt);
  #else
    simde_hvx_vectorpred_private
      r_,
      a_ = simde_hvx_vectorpred_to_private(Qs),
      b_ = simde_hvx_vectorpred_to_private(Qt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = a_.u8[i] | b_.u8[i];
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_or_QQ
  #define Q6_Q_or_QQ(Qs, Qt) simde_Q6_Q_or_QQ((Qs), (Qt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_or_QQn(simde_hvx_vectorpred_t Qs, simde_hvx_vectorpred_t Qt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_or_QQn(Qs, Qt);
  #else
    simde_hvx_vectorpred_private
      r_,
      a_ = simde_hvx_vectorpred_to_private(Qs),
      b_ = simde_hvx_vectorpred_to_private(Qt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = a_.u8[i] | HEDLEY_STATIC_CAST(uint8_t, ~b_.u8[i]);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_or_QQn
  #define Q6_Q_or_QQn(Qs, Qt) simde_Q6_Q_or_QQn((Qs), (Qt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_xor_QQ(simde_hvx_vectorpred_t Qs, simde_hvx_vectorpred_t Qt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_xor_QQ(Qs, Qt);
  #else
    simde_hvx_vectorpred_private
      r_,
      a_ = simde_hvx_vectorpred_to_private(Qs),
      b_ = simde_hvx_vectorpred_to_private(Qt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = a_.u8[i] ^ b_.u8[i];
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_xor_QQ
  #define Q6_Q_xor_QQ(Qs, Qt) simde_Q6_Q_xor_QQ((Qs), (Qt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_not_Q(simde_hvx_vectorpred_t Qs) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_not_Q(Qs);
  #else
    simde_hvx_vectorpred_private
      r_,
      a_ = simde_hvx_vectorpred_to_private(Qs);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, ~a_.u8[i]);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_not_Q
  #define Q6_Q_not_Q(Qs) simde_Q6_Q_not_Q((Qs))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vsetq_R(int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vsetq_R(Rt);
  #else
    simde_hvx_vectorpred_private r_;
    uint32_t n = HEDLEY_STATIC_CAST(uint32_t, Rt) & (SIMDE_HVX_VECTOR_SIZE - 1);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = (HEDLEY_STATIC_CAST(uint32_t, i) < n) ? 0xFF : 0x00;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vsetq_R
  #define Q6_Q_vsetq_R(Rt) simde_Q6_Q_vsetq_R((Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vsetq2_R(int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vsetq2_R(Rt);
  #else
    simde_hvx_vectorpred_private r_;
    uint32_t n = (HEDLEY_STATIC_CAST(uint32_t, Rt) - 1u) & (SIMDE_HVX_VECTOR_SIZE - 1);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = (HEDLEY_STATIC_CAST(uint32_t, i) <= n) ? 0xFF : 0x00;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vsetq2_R
  #define Q6_Q_vsetq2_R(Rt) simde_Q6_Q_vsetq2_R((Rt))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VPRED_H) */
