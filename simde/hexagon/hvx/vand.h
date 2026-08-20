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

#if !defined(SIMDE_HEXAGON_HVX_VAND_H)
#define SIMDE_HEXAGON_HVX_VAND_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vand_VV(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vand_VV(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i8 = a_.i8 & b_.i8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
        r_.u8[i] = a_.u8[i] & b_.u8[i];
      }
    #endif

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vand_VV
  #define Q6_V_vand_VV(Vu, Vv) simde_Q6_V_vand_VV((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vand_QV(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vand_QV(Qv, Vu);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = a_.u8[i] & q_.u8[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vand_QV
  #define Q6_V_vand_QV(Qv, Vu) simde_Q6_V_vand_QV((Qv), (Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vand_QnV(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vand_QnV(Qv, Vu);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = a_.u8[i] & HEDLEY_STATIC_CAST(uint8_t, ~q_.u8[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vand_QnV
  #define Q6_V_vand_QnV(Qv, Vu) simde_Q6_V_vand_QnV((Qv), (Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vand_QR(simde_hvx_vectorpred_t Qu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vand_QR(Qu, Rt);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qu);
    simde_hvx_vector_private r_;

    /* For each group of 4 bytes, use the predicate byte mask ANDed with
     * the corresponding byte of Rt. The predicate byte is 0x00 or 0xFF. */
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      uint8_t rt_byte = HEDLEY_STATIC_CAST(uint8_t, (Rt >> ((i & 3) * 8)) & 0xFF);
      r_.u8[i] = q_.u8[i] & rt_byte;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vand_QR
  #define Q6_V_vand_QR(Qu, Rt) simde_Q6_V_vand_QR((Qu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vand_VR(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vand_VR(Vu, Rt);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      uint8_t rt_byte = HEDLEY_STATIC_CAST(uint8_t, (Rt >> ((i & 3) * 8)) & 0xFF);
      r_.u8[i] = (a_.u8[i] & rt_byte) ? 0xFF : 0x00;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vand_VR
  #define Q6_Q_vand_VR(Vu, Rt) simde_Q6_Q_vand_VR((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vandor_QVR(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vandor_QVR(Qx, Vu, Rt);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      uint8_t rt_byte = HEDLEY_STATIC_CAST(uint8_t, (Rt >> ((i & 3) * 8)) & 0xFF);
      r_.u8[i] = q_.u8[i] | ((a_.u8[i] & rt_byte) ? 0xFF : 0x00);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vandor_QVR
  #define Q6_Q_vandor_QVR(Qx, Vu, Rt) simde_Q6_Q_vandor_QVR((Qx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vand_QnR(simde_hvx_vectorpred_t Qu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vand_QnR(Qu, Rt);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qu);
    simde_hvx_vector_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      uint8_t rt_byte = HEDLEY_STATIC_CAST(uint8_t, (Rt >> ((i & 3) * 8)) & 0xFF);
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, ~q_.u8[i]) & rt_byte;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vand_QnR
  #define Q6_V_vand_QnR(Qu, Rt) simde_Q6_V_vand_QnR((Qu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vandor_VQR(simde_hvx_vector_t Vx, simde_hvx_vectorpred_t Qu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vandor_VQR(Vx, Qu, Rt);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qu);
    simde_hvx_vector_private r_ = simde_hvx_vector_to_private(Vx);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      uint8_t rt_byte = HEDLEY_STATIC_CAST(uint8_t, (Rt >> ((i & 3) * 8)) & 0xFF);
      r_.u8[i] = r_.u8[i] | (q_.u8[i] & rt_byte);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vandor_VQR
  #define Q6_V_vandor_VQR(Vx, Qu, Rt) simde_Q6_V_vandor_VQR((Vx), (Qu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vandor_VQnR(simde_hvx_vector_t Vx, simde_hvx_vectorpred_t Qu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vandor_VQnR(Vx, Qu, Rt);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qu);
    simde_hvx_vector_private r_ = simde_hvx_vector_to_private(Vx);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      uint8_t rt_byte = HEDLEY_STATIC_CAST(uint8_t, (Rt >> ((i & 3) * 8)) & 0xFF);
      r_.u8[i] = r_.u8[i] | (HEDLEY_STATIC_CAST(uint8_t, ~q_.u8[i]) & rt_byte);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vandor_VQnR
  #define Q6_V_vandor_VQnR(Vx, Qu, Rt) simde_Q6_V_vandor_VQnR((Vx), (Qu), (Rt))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VAND_H) */
