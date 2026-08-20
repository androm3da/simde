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

#if !defined(SIMDE_HEXAGON_HVX_VCOMBINE_H)
#define SIMDE_HEXAGON_HVX_VCOMBINE_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_hi_W(simde_hvx_vectorpair_t Vss) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_hi_W(Vss);
  #else
    simde_hvx_vectorpair_private p_ = simde_hvx_vectorpair_to_private(Vss);
    simde_hvx_vector_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.i8[i] = p_.i8[SIMDE_HVX_VECTOR_SIZE + i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_hi_W
  #define Q6_V_hi_W(Vss) simde_Q6_V_hi_W((Vss))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_lo_W(simde_hvx_vectorpair_t Vss) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_lo_W(Vss);
  #else
    simde_hvx_vectorpair_private p_ = simde_hvx_vectorpair_to_private(Vss);
    simde_hvx_vector_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.i8[i] = p_.i8[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_lo_W
  #define Q6_V_lo_W(Vss) simde_Q6_V_lo_W((Vss))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_W_vcombine_VV(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_W_vcombine_VV(Vu, Vv);
  #else
    simde_hvx_vector_private
      hi_ = simde_hvx_vector_to_private(Vu),
      lo_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.i8[i] = lo_.i8[i];
      r_.i8[SIMDE_HVX_VECTOR_SIZE + i] = hi_.i8[i];
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_W_vcombine_VV
  #define Q6_W_vcombine_VV(Vu, Vv) simde_Q6_W_vcombine_VV((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vzero(void) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_vzero();
  #else
    simde_hvx_vector_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = 0;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vzero
  #define Q6_V_vzero() simde_Q6_V_vzero()
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_W_vswap_QVV(simde_hvx_vectorpred_t Qt, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_W_vswap_QVV(Qt, Vu, Vv);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qt);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      /* lo = where Qt true: Vv, where false: Vu */
      /* hi = where Qt true: Vu, where false: Vv */
      uint8_t mask = q_.u8[i];
      r_.u8[i]                          = (mask & a_.u8[i]) | (~mask & b_.u8[i]);
      r_.u8[SIMDE_HVX_VECTOR_SIZE + i]  = (mask & b_.u8[i]) | (~mask & a_.u8[i]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_W_vswap_QVV
  #define Q6_W_vswap_QVV(Qt, Vu, Vv) simde_Q6_W_vswap_QVV((Qt), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_equals_V(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_V_equals_V(Vu);
  #else
    return Vu;
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_equals_V
  #define Q6_V_equals_V(Vu) simde_Q6_V_equals_V((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_W_equals_W(simde_hvx_vectorpair_t Vuu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_W_equals_W(Vuu);
  #else
    return Vuu;
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_W_equals_W
  #define Q6_W_equals_W(Vuu) simde_Q6_W_equals_W((Vuu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_W_vzero(void) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_W_vzero();
  #else
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (2 * SIMDE_HVX_VECTOR_SIZE) ; i++) {
      r_.u8[i] = 0;
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_W_vzero
  #define Q6_W_vzero() simde_Q6_W_vzero()
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vfmv_Vw(simde_hvx_vector_t Vu) {
  return Vu;
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vfmv_Vw
  #define Q6_Vw_vfmv_Vw(Vu) simde_Q6_Vw_vfmv_Vw((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vmerge_VVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_V_vmerge_VVw)
    return Q6_V_vmerge_VVw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = (b_.u32[i] & UINT32_C(0xFFFF0000)) | (a_.u32[i] & UINT32_C(0x0000FFFF));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vmerge_VVw
  #define Q6_V_vmerge_VVw(Vu, Vv) simde_Q6_V_vmerge_VVw((Vu), (Vv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VCOMBINE_H) */
