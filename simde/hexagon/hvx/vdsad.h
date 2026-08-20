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

#if !defined(SIMDE_HEXAGON_HVX_VDSAD_H)
#define SIMDE_HEXAGON_HVX_VDSAD_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vdsad_WuhRuh(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuw_vdsad_WuhRuh(Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_,
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    uint16_t ruh[2];
    ruh[0] = HEDLEY_STATIC_CAST(uint16_t, Rt & 0xFFFF);
    ruh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rt >> 16) & 0xFFFF);

    /* Diagonal SAD: v[0] uses straight pairs, v[1] uses crossed halfwords */
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      /* v[0]: |even_h(v0) - even_h(Rt)| + |odd_h(v0) - odd_h(Rt)| */
      uint16_t v0_even = p_.u16[2 * i];
      uint16_t v0_odd  = p_.u16[2 * i + 1];
      uint16_t v1_even = p_.u16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i];

      uint32_t d0 = (v0_even > ruh[0]) ? (uint32_t)(v0_even - ruh[0]) : (uint32_t)(ruh[0] - v0_even);
      uint32_t d1 = (v0_odd > ruh[1])  ? (uint32_t)(v0_odd - ruh[1])  : (uint32_t)(ruh[1] - v0_odd);
      r_.u32[i] = d0 + d1;

      /* v[1]: |odd_h(v0) - even_h(Rt)| + |even_h(v1) - odd_h(Rt)| */
      uint32_t d2 = (v0_odd > ruh[0])  ? (uint32_t)(v0_odd - ruh[0])  : (uint32_t)(ruh[0] - v0_odd);
      uint32_t d3 = (v1_even > ruh[1]) ? (uint32_t)(v1_even - ruh[1]) : (uint32_t)(ruh[1] - v1_even);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] = d2 + d3;
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vdsad_WuhRuh
  #define Q6_Wuw_vdsad_WuhRuh(Vuu, Rt) simde_Q6_Wuw_vdsad_WuhRuh((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vdsadacc_WuwWuhRuh(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuw_vdsadacc_WuwWuhRuh(Vxx, Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    uint16_t ruh[2];
    ruh[0] = HEDLEY_STATIC_CAST(uint16_t, Rt & 0xFFFF);
    ruh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rt >> 16) & 0xFFFF);

    /* Diagonal SAD accumulate: v[0] uses straight pairs, v[1] uses crossed halfwords */
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint16_t v0_even = p_.u16[2 * i];
      uint16_t v0_odd  = p_.u16[2 * i + 1];
      uint16_t v1_even = p_.u16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i];

      uint32_t d0 = (v0_even > ruh[0]) ? (uint32_t)(v0_even - ruh[0]) : (uint32_t)(ruh[0] - v0_even);
      uint32_t d1 = (v0_odd > ruh[1])  ? (uint32_t)(v0_odd - ruh[1])  : (uint32_t)(ruh[1] - v0_odd);
      r_.u32[i] += d0 + d1;

      uint32_t d2 = (v0_odd > ruh[0])  ? (uint32_t)(v0_odd - ruh[0])  : (uint32_t)(ruh[0] - v0_odd);
      uint32_t d3 = (v1_even > ruh[1]) ? (uint32_t)(v1_even - ruh[1]) : (uint32_t)(ruh[1] - v1_even);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] += d2 + d3;
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vdsadacc_WuwWuhRuh
  #define Q6_Wuw_vdsadacc_WuwWuhRuh(Vxx, Vuu, Rt) simde_Q6_Wuw_vdsadacc_WuwWuhRuh((Vxx), (Vuu), (Rt))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VDSAD_H) */
