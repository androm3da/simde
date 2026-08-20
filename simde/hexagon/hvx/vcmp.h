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

#if !defined(SIMDE_HEXAGON_HVX_VCMP_H)
#define SIMDE_HEXAGON_HVX_VCMP_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eq_VbVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eq_VbVb(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = (a_.i8[i] == b_.i8[i]) ? 0xFF : 0x00;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eq_VbVb
  #define Q6_Q_vcmp_eq_VbVb(Vu, Vv) simde_Q6_Q_vcmp_eq_VbVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eq_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eq_VhVh(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.i16[i] == b_.i16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = mask;
      r_.u8[i * 2 + 1] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eq_VhVh
  #define Q6_Q_vcmp_eq_VhVh(Vu, Vv) simde_Q6_Q_vcmp_eq_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eq_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eq_VwVw(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.i32[i] == b_.i32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = mask;
      r_.u8[i * 4 + 1] = mask;
      r_.u8[i * 4 + 2] = mask;
      r_.u8[i * 4 + 3] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eq_VwVw
  #define Q6_Q_vcmp_eq_VwVw(Vu, Vv) simde_Q6_Q_vcmp_eq_VwVw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gt_VbVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gt_VbVb(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = (a_.i8[i] > b_.i8[i]) ? 0xFF : 0x00;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gt_VbVb
  #define Q6_Q_vcmp_gt_VbVb(Vu, Vv) simde_Q6_Q_vcmp_gt_VbVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gt_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gt_VhVh(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.i16[i] > b_.i16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = mask;
      r_.u8[i * 2 + 1] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gt_VhVh
  #define Q6_Q_vcmp_gt_VhVh(Vu, Vv) simde_Q6_Q_vcmp_gt_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gt_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gt_VwVw(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.i32[i] > b_.i32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = mask;
      r_.u8[i * 4 + 1] = mask;
      r_.u8[i * 4 + 2] = mask;
      r_.u8[i * 4 + 3] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gt_VwVw
  #define Q6_Q_vcmp_gt_VwVw(Vu, Vv) simde_Q6_Q_vcmp_gt_VwVw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gt_VubVub(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gt_VubVub(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? 0xFF : 0x00;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gt_VubVub
  #define Q6_Q_vcmp_gt_VubVub(Vu, Vv) simde_Q6_Q_vcmp_gt_VubVub((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gt_VuhVuh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gt_VuhVuh(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.u16[i] > b_.u16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = mask;
      r_.u8[i * 2 + 1] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gt_VuhVuh
  #define Q6_Q_vcmp_gt_VuhVuh(Vu, Vv) simde_Q6_Q_vcmp_gt_VuhVuh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gt_VuwVuw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gt_VuwVuw(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.u32[i] > b_.u32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = mask;
      r_.u8[i * 4 + 1] = mask;
      r_.u8[i * 4 + 2] = mask;
      r_.u8[i * 4 + 3] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gt_VuwVuw
  #define Q6_Q_vcmp_gt_VuwVuw(Vu, Vv) simde_Q6_Q_vcmp_gt_VuwVuw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqand_QVbVb(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eqand_QVbVb(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = q_.u8[i] & HEDLEY_STATIC_CAST(uint8_t, (a_.i8[i] == b_.i8[i]) ? 0xFF : 0x00);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqand_QVbVb
  #define Q6_Q_vcmp_eqand_QVbVb(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqand_QVbVb((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqor_QVbVb(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eqor_QVbVb(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = q_.u8[i] | HEDLEY_STATIC_CAST(uint8_t, (a_.i8[i] == b_.i8[i]) ? 0xFF : 0x00);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqor_QVbVb
  #define Q6_Q_vcmp_eqor_QVbVb(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqor_QVbVb((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqxacc_QVbVb(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eqxacc_QVbVb(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = q_.u8[i] ^ HEDLEY_STATIC_CAST(uint8_t, (a_.i8[i] == b_.i8[i]) ? 0xFF : 0x00);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqxacc_QVbVb
  #define Q6_Q_vcmp_eqxacc_QVbVb(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqxacc_QVbVb((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqand_QVhVh(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eqand_QVhVh(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.i16[i] == b_.i16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = q_.u8[i * 2]     & mask;
      r_.u8[i * 2 + 1] = q_.u8[i * 2 + 1] & mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqand_QVhVh
  #define Q6_Q_vcmp_eqand_QVhVh(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqand_QVhVh((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqor_QVhVh(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eqor_QVhVh(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.i16[i] == b_.i16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = q_.u8[i * 2]     | mask;
      r_.u8[i * 2 + 1] = q_.u8[i * 2 + 1] | mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqor_QVhVh
  #define Q6_Q_vcmp_eqor_QVhVh(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqor_QVhVh((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqxacc_QVhVh(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eqxacc_QVhVh(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.i16[i] == b_.i16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = q_.u8[i * 2]     ^ mask;
      r_.u8[i * 2 + 1] = q_.u8[i * 2 + 1] ^ mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqxacc_QVhVh
  #define Q6_Q_vcmp_eqxacc_QVhVh(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqxacc_QVhVh((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqand_QVwVw(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eqand_QVwVw(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.i32[i] == b_.i32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = q_.u8[i * 4]     & mask;
      r_.u8[i * 4 + 1] = q_.u8[i * 4 + 1] & mask;
      r_.u8[i * 4 + 2] = q_.u8[i * 4 + 2] & mask;
      r_.u8[i * 4 + 3] = q_.u8[i * 4 + 3] & mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqand_QVwVw
  #define Q6_Q_vcmp_eqand_QVwVw(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqand_QVwVw((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqor_QVwVw(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eqor_QVwVw(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.i32[i] == b_.i32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = q_.u8[i * 4]     | mask;
      r_.u8[i * 4 + 1] = q_.u8[i * 4 + 1] | mask;
      r_.u8[i * 4 + 2] = q_.u8[i * 4 + 2] | mask;
      r_.u8[i * 4 + 3] = q_.u8[i * 4 + 3] | mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqor_QVwVw
  #define Q6_Q_vcmp_eqor_QVwVw(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqor_QVwVw((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqxacc_QVwVw(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_eqxacc_QVwVw(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.i32[i] == b_.i32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = q_.u8[i * 4]     ^ mask;
      r_.u8[i * 4 + 1] = q_.u8[i * 4 + 1] ^ mask;
      r_.u8[i * 4 + 2] = q_.u8[i * 4 + 2] ^ mask;
      r_.u8[i * 4 + 3] = q_.u8[i * 4 + 3] ^ mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqxacc_QVwVw
  #define Q6_Q_vcmp_eqxacc_QVwVw(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqxacc_QVwVw((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtand_QVbVb(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtand_QVbVb(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = q_.u8[i] & HEDLEY_STATIC_CAST(uint8_t, (a_.i8[i] > b_.i8[i]) ? 0xFF : 0x00);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtand_QVbVb
  #define Q6_Q_vcmp_gtand_QVbVb(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtand_QVbVb((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtor_QVbVb(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtor_QVbVb(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = q_.u8[i] | HEDLEY_STATIC_CAST(uint8_t, (a_.i8[i] > b_.i8[i]) ? 0xFF : 0x00);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtor_QVbVb
  #define Q6_Q_vcmp_gtor_QVbVb(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtor_QVbVb((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtxacc_QVbVb(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtxacc_QVbVb(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = q_.u8[i] ^ HEDLEY_STATIC_CAST(uint8_t, (a_.i8[i] > b_.i8[i]) ? 0xFF : 0x00);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtxacc_QVbVb
  #define Q6_Q_vcmp_gtxacc_QVbVb(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtxacc_QVbVb((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtand_QVhVh(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtand_QVhVh(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.i16[i] > b_.i16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = q_.u8[i * 2]     & mask;
      r_.u8[i * 2 + 1] = q_.u8[i * 2 + 1] & mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtand_QVhVh
  #define Q6_Q_vcmp_gtand_QVhVh(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtand_QVhVh((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtor_QVhVh(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtor_QVhVh(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.i16[i] > b_.i16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = q_.u8[i * 2]     | mask;
      r_.u8[i * 2 + 1] = q_.u8[i * 2 + 1] | mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtor_QVhVh
  #define Q6_Q_vcmp_gtor_QVhVh(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtor_QVhVh((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtxacc_QVhVh(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtxacc_QVhVh(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.i16[i] > b_.i16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = q_.u8[i * 2]     ^ mask;
      r_.u8[i * 2 + 1] = q_.u8[i * 2 + 1] ^ mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtxacc_QVhVh
  #define Q6_Q_vcmp_gtxacc_QVhVh(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtxacc_QVhVh((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtand_QVwVw(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtand_QVwVw(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.i32[i] > b_.i32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = q_.u8[i * 4]     & mask;
      r_.u8[i * 4 + 1] = q_.u8[i * 4 + 1] & mask;
      r_.u8[i * 4 + 2] = q_.u8[i * 4 + 2] & mask;
      r_.u8[i * 4 + 3] = q_.u8[i * 4 + 3] & mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtand_QVwVw
  #define Q6_Q_vcmp_gtand_QVwVw(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtand_QVwVw((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtor_QVwVw(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtor_QVwVw(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.i32[i] > b_.i32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = q_.u8[i * 4]     | mask;
      r_.u8[i * 4 + 1] = q_.u8[i * 4 + 1] | mask;
      r_.u8[i * 4 + 2] = q_.u8[i * 4 + 2] | mask;
      r_.u8[i * 4 + 3] = q_.u8[i * 4 + 3] | mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtor_QVwVw
  #define Q6_Q_vcmp_gtor_QVwVw(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtor_QVwVw((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtxacc_QVwVw(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtxacc_QVwVw(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.i32[i] > b_.i32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = q_.u8[i * 4]     ^ mask;
      r_.u8[i * 4 + 1] = q_.u8[i * 4 + 1] ^ mask;
      r_.u8[i * 4 + 2] = q_.u8[i * 4 + 2] ^ mask;
      r_.u8[i * 4 + 3] = q_.u8[i * 4 + 3] ^ mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtxacc_QVwVw
  #define Q6_Q_vcmp_gtxacc_QVwVw(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtxacc_QVwVw((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtand_QVubVub(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtand_QVubVub(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = q_.u8[i] & HEDLEY_STATIC_CAST(uint8_t, (a_.u8[i] > b_.u8[i]) ? 0xFF : 0x00);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtand_QVubVub
  #define Q6_Q_vcmp_gtand_QVubVub(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtand_QVubVub((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtor_QVubVub(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtor_QVubVub(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = q_.u8[i] | HEDLEY_STATIC_CAST(uint8_t, (a_.u8[i] > b_.u8[i]) ? 0xFF : 0x00);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtor_QVubVub
  #define Q6_Q_vcmp_gtor_QVubVub(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtor_QVubVub((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtxacc_QVubVub(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtxacc_QVubVub(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = q_.u8[i] ^ HEDLEY_STATIC_CAST(uint8_t, (a_.u8[i] > b_.u8[i]) ? 0xFF : 0x00);
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtxacc_QVubVub
  #define Q6_Q_vcmp_gtxacc_QVubVub(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtxacc_QVubVub((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtand_QVuhVuh(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtand_QVuhVuh(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.u16[i] > b_.u16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = q_.u8[i * 2]     & mask;
      r_.u8[i * 2 + 1] = q_.u8[i * 2 + 1] & mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtand_QVuhVuh
  #define Q6_Q_vcmp_gtand_QVuhVuh(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtand_QVuhVuh((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtor_QVuhVuh(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtor_QVuhVuh(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.u16[i] > b_.u16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = q_.u8[i * 2]     | mask;
      r_.u8[i * 2 + 1] = q_.u8[i * 2 + 1] | mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtor_QVuhVuh
  #define Q6_Q_vcmp_gtor_QVuhVuh(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtor_QVuhVuh((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtxacc_QVuhVuh(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtxacc_QVuhVuh(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t mask = (a_.u16[i] > b_.u16[i]) ? 0xFF : 0x00;
      r_.u8[i * 2]     = q_.u8[i * 2]     ^ mask;
      r_.u8[i * 2 + 1] = q_.u8[i * 2 + 1] ^ mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtxacc_QVuhVuh
  #define Q6_Q_vcmp_gtxacc_QVuhVuh(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtxacc_QVuhVuh((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtand_QVuwVuw(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtand_QVuwVuw(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.u32[i] > b_.u32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = q_.u8[i * 4]     & mask;
      r_.u8[i * 4 + 1] = q_.u8[i * 4 + 1] & mask;
      r_.u8[i * 4 + 2] = q_.u8[i * 4 + 2] & mask;
      r_.u8[i * 4 + 3] = q_.u8[i * 4 + 3] & mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtand_QVuwVuw
  #define Q6_Q_vcmp_gtand_QVuwVuw(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtand_QVuwVuw((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtor_QVuwVuw(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtor_QVuwVuw(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.u32[i] > b_.u32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = q_.u8[i * 4]     | mask;
      r_.u8[i * 4 + 1] = q_.u8[i * 4 + 1] | mask;
      r_.u8[i * 4 + 2] = q_.u8[i * 4 + 2] | mask;
      r_.u8[i * 4 + 3] = q_.u8[i * 4 + 3] | mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtor_QVuwVuw
  #define Q6_Q_vcmp_gtor_QVuwVuw(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtor_QVuwVuw((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtxacc_QVuwVuw(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Q_vcmp_gtxacc_QVuwVuw(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_, q_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint8_t mask = (a_.u32[i] > b_.u32[i]) ? 0xFF : 0x00;
      r_.u8[i * 4]     = q_.u8[i * 4]     ^ mask;
      r_.u8[i * 4 + 1] = q_.u8[i * 4 + 1] ^ mask;
      r_.u8[i * 4 + 2] = q_.u8[i * 4 + 2] ^ mask;
      r_.u8[i * 4 + 3] = q_.u8[i * 4 + 3] ^ mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtxacc_QVuwVuw
  #define Q6_Q_vcmp_gtxacc_QVuwVuw(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtxacc_QVuwVuw((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eq_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_eq_VhfVhf)
    return Q6_Q_vcmp_eq_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 af = simde_float16_to_float32(a_.f16[i]);
      simde_float32 bf = simde_float16_to_float32(b_.f16[i]);
      uint8_t mask = (af == bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     = mask;
      r_.u8[2 * i + 1] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eq_VhfVhf
  #define Q6_Q_vcmp_eq_VhfVhf(Vu, Vv) simde_Q6_Q_vcmp_eq_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqand_QVhfVhf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_eqand_QVhfVhf)
    return Q6_Q_vcmp_eqand_QVhfVhf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 af = simde_float16_to_float32(a_.f16[i]);
      simde_float32 bf = simde_float16_to_float32(b_.f16[i]);
      uint8_t mask = (af == bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     &= mask;
      r_.u8[2 * i + 1] &= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqand_QVhfVhf
  #define Q6_Q_vcmp_eqand_QVhfVhf(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqand_QVhfVhf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqor_QVhfVhf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_eqor_QVhfVhf)
    return Q6_Q_vcmp_eqor_QVhfVhf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 af = simde_float16_to_float32(a_.f16[i]);
      simde_float32 bf = simde_float16_to_float32(b_.f16[i]);
      uint8_t mask = (af == bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     |= mask;
      r_.u8[2 * i + 1] |= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqor_QVhfVhf
  #define Q6_Q_vcmp_eqor_QVhfVhf(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqor_QVhfVhf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqxacc_QVhfVhf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_eqxacc_QVhfVhf)
    return Q6_Q_vcmp_eqxacc_QVhfVhf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 af = simde_float16_to_float32(a_.f16[i]);
      simde_float32 bf = simde_float16_to_float32(b_.f16[i]);
      uint8_t mask = (af == bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     ^= mask;
      r_.u8[2 * i + 1] ^= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqxacc_QVhfVhf
  #define Q6_Q_vcmp_eqxacc_QVhfVhf(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqxacc_QVhfVhf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eq_VsfVsf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_eq_VsfVsf)
    return Q6_Q_vcmp_eq_VsfVsf(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      uint8_t mask = (a_.f32[i] == b_.f32[i]) ? 0xFF : 0x00;
      r_.u8[4 * i]     = mask;
      r_.u8[4 * i + 1] = mask;
      r_.u8[4 * i + 2] = mask;
      r_.u8[4 * i + 3] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eq_VsfVsf
  #define Q6_Q_vcmp_eq_VsfVsf(Vu, Vv) simde_Q6_Q_vcmp_eq_VsfVsf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqand_QVsfVsf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_eqand_QVsfVsf)
    return Q6_Q_vcmp_eqand_QVsfVsf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      uint8_t mask = (a_.f32[i] == b_.f32[i]) ? 0xFF : 0x00;
      r_.u8[4 * i]     &= mask;
      r_.u8[4 * i + 1] &= mask;
      r_.u8[4 * i + 2] &= mask;
      r_.u8[4 * i + 3] &= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqand_QVsfVsf
  #define Q6_Q_vcmp_eqand_QVsfVsf(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqand_QVsfVsf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqor_QVsfVsf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_eqor_QVsfVsf)
    return Q6_Q_vcmp_eqor_QVsfVsf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      uint8_t mask = (a_.f32[i] == b_.f32[i]) ? 0xFF : 0x00;
      r_.u8[4 * i]     |= mask;
      r_.u8[4 * i + 1] |= mask;
      r_.u8[4 * i + 2] |= mask;
      r_.u8[4 * i + 3] |= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqor_QVsfVsf
  #define Q6_Q_vcmp_eqor_QVsfVsf(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqor_QVsfVsf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_eqxacc_QVsfVsf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_eqxacc_QVsfVsf)
    return Q6_Q_vcmp_eqxacc_QVsfVsf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      uint8_t mask = (a_.f32[i] == b_.f32[i]) ? 0xFF : 0x00;
      r_.u8[4 * i]     ^= mask;
      r_.u8[4 * i + 1] ^= mask;
      r_.u8[4 * i + 2] ^= mask;
      r_.u8[4 * i + 3] ^= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_eqxacc_QVsfVsf
  #define Q6_Q_vcmp_eqxacc_QVsfVsf(Qx, Vu, Vv) simde_Q6_Q_vcmp_eqxacc_QVsfVsf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gt_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gt_VhfVhf)
    return Q6_Q_vcmp_gt_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 af = simde_float16_to_float32(a_.f16[i]);
      simde_float32 bf = simde_float16_to_float32(b_.f16[i]);
      uint8_t mask = (af > bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     = mask;
      r_.u8[2 * i + 1] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gt_VhfVhf
  #define Q6_Q_vcmp_gt_VhfVhf(Vu, Vv) simde_Q6_Q_vcmp_gt_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtand_QVhfVhf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gtand_QVhfVhf)
    return Q6_Q_vcmp_gtand_QVhfVhf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 af = simde_float16_to_float32(a_.f16[i]);
      simde_float32 bf = simde_float16_to_float32(b_.f16[i]);
      uint8_t mask = (af > bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     &= mask;
      r_.u8[2 * i + 1] &= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtand_QVhfVhf
  #define Q6_Q_vcmp_gtand_QVhfVhf(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtand_QVhfVhf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtor_QVhfVhf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gtor_QVhfVhf)
    return Q6_Q_vcmp_gtor_QVhfVhf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 af = simde_float16_to_float32(a_.f16[i]);
      simde_float32 bf = simde_float16_to_float32(b_.f16[i]);
      uint8_t mask = (af > bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     |= mask;
      r_.u8[2 * i + 1] |= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtor_QVhfVhf
  #define Q6_Q_vcmp_gtor_QVhfVhf(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtor_QVhfVhf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtxacc_QVhfVhf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gtxacc_QVhfVhf)
    return Q6_Q_vcmp_gtxacc_QVhfVhf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 af = simde_float16_to_float32(a_.f16[i]);
      simde_float32 bf = simde_float16_to_float32(b_.f16[i]);
      uint8_t mask = (af > bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     ^= mask;
      r_.u8[2 * i + 1] ^= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtxacc_QVhfVhf
  #define Q6_Q_vcmp_gtxacc_QVhfVhf(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtxacc_QVhfVhf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gt_VsfVsf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gt_VsfVsf)
    return Q6_Q_vcmp_gt_VsfVsf(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      uint8_t mask = (a_.f32[i] > b_.f32[i]) ? 0xFF : 0x00;
      r_.u8[4 * i]     = mask;
      r_.u8[4 * i + 1] = mask;
      r_.u8[4 * i + 2] = mask;
      r_.u8[4 * i + 3] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gt_VsfVsf
  #define Q6_Q_vcmp_gt_VsfVsf(Vu, Vv) simde_Q6_Q_vcmp_gt_VsfVsf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtand_QVsfVsf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gtand_QVsfVsf)
    return Q6_Q_vcmp_gtand_QVsfVsf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      uint8_t mask = (a_.f32[i] > b_.f32[i]) ? 0xFF : 0x00;
      r_.u8[4 * i]     &= mask;
      r_.u8[4 * i + 1] &= mask;
      r_.u8[4 * i + 2] &= mask;
      r_.u8[4 * i + 3] &= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtand_QVsfVsf
  #define Q6_Q_vcmp_gtand_QVsfVsf(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtand_QVsfVsf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtor_QVsfVsf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gtor_QVsfVsf)
    return Q6_Q_vcmp_gtor_QVsfVsf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      uint8_t mask = (a_.f32[i] > b_.f32[i]) ? 0xFF : 0x00;
      r_.u8[4 * i]     |= mask;
      r_.u8[4 * i + 1] |= mask;
      r_.u8[4 * i + 2] |= mask;
      r_.u8[4 * i + 3] |= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtor_QVsfVsf
  #define Q6_Q_vcmp_gtor_QVsfVsf(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtor_QVsfVsf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtxacc_QVsfVsf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gtxacc_QVsfVsf)
    return Q6_Q_vcmp_gtxacc_QVsfVsf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      uint8_t mask = (a_.f32[i] > b_.f32[i]) ? 0xFF : 0x00;
      r_.u8[4 * i]     ^= mask;
      r_.u8[4 * i + 1] ^= mask;
      r_.u8[4 * i + 2] ^= mask;
      r_.u8[4 * i + 3] ^= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtxacc_QVsfVsf
  #define Q6_Q_vcmp_gtxacc_QVsfVsf(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtxacc_QVsfVsf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gt_VbfVbf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gt_VbfVbf)
    return Q6_Q_vcmp_gt_VbfVbf(Vu, Vv);
  #else
    simde_hvx_vectorpred_private r_;
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_BF16_COUNT ; i++) {
      simde_float32 af = simde_bfloat16_to_float32(a_.bf16[i]);
      simde_float32 bf = simde_bfloat16_to_float32(b_.bf16[i]);
      uint8_t mask = (af > bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     = mask;
      r_.u8[2 * i + 1] = mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gt_VbfVbf
  #define Q6_Q_vcmp_gt_VbfVbf(Vu, Vv) simde_Q6_Q_vcmp_gt_VbfVbf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtand_QVbfVbf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gtand_QVbfVbf)
    return Q6_Q_vcmp_gtand_QVbfVbf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_BF16_COUNT ; i++) {
      simde_float32 af = simde_bfloat16_to_float32(a_.bf16[i]);
      simde_float32 bf = simde_bfloat16_to_float32(b_.bf16[i]);
      uint8_t mask = (af > bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     &= mask;
      r_.u8[2 * i + 1] &= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtand_QVbfVbf
  #define Q6_Q_vcmp_gtand_QVbfVbf(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtand_QVbfVbf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtor_QVbfVbf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gtor_QVbfVbf)
    return Q6_Q_vcmp_gtor_QVbfVbf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_BF16_COUNT ; i++) {
      simde_float32 af = simde_bfloat16_to_float32(a_.bf16[i]);
      simde_float32 bf = simde_bfloat16_to_float32(b_.bf16[i]);
      uint8_t mask = (af > bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     |= mask;
      r_.u8[2 * i + 1] |= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtor_QVbfVbf
  #define Q6_Q_vcmp_gtor_QVbfVbf(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtor_QVbfVbf((Qx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Q_vcmp_gtxacc_QVbfVbf(simde_hvx_vectorpred_t Qx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Q_vcmp_gtxacc_QVbfVbf)
    return Q6_Q_vcmp_gtxacc_QVbfVbf(Qx, Vu, Vv);
  #else
    simde_hvx_vectorpred_private
      r_ = simde_hvx_vectorpred_to_private(Qx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_BF16_COUNT ; i++) {
      simde_float32 af = simde_bfloat16_to_float32(a_.bf16[i]);
      simde_float32 bf = simde_bfloat16_to_float32(b_.bf16[i]);
      uint8_t mask = (af > bf) ? 0xFF : 0x00;
      r_.u8[2 * i]     ^= mask;
      r_.u8[2 * i + 1] ^= mask;
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Q_vcmp_gtxacc_QVbfVbf
  #define Q6_Q_vcmp_gtxacc_QVbfVbf(Qx, Vu, Vv) simde_Q6_Q_vcmp_gtxacc_QVbfVbf((Qx), (Vu), (Vv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VCMP_H) */
