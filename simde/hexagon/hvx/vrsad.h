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

#if !defined(SIMDE_HEXAGON_HVX_VRSAD_H)
#define SIMDE_HEXAGON_HVX_VRSAD_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vrsad_WubRubI(simde_hvx_vectorpair_t Vuu, int32_t Rt, int32_t Iu2) SIMDE_REQUIRE_CONSTANT_RANGE(Iu2, 0, 1) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    switch (Iu2 & 1) {
      case 0: return Q6_Wuw_vrsad_WubRubI(Vuu, Rt, 0);
      case 1: return Q6_Wuw_vrsad_WubRubI(Vuu, Rt, 1);
    }
    HEDLEY_UNREACHABLE();
  #else
    simde_hvx_vectorpair_private
      r_,
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    int ui = Iu2 & 1;
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      size_t v0_off = 0;
      size_t v1_off = SIMDE_HVX_VECTOR_SIZE;
      size_t vsel = ui ? v1_off : v0_off;

      uint32_t sum_lo = 0;
      uint8_t vb, sb;
      vb = p_.u8[vsel + 4 * i + 0]; sb = rub[(0 - ui) & 3];
      sum_lo += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[v0_off + 4 * i + 1]; sb = rub[(1 - ui) & 3];
      sum_lo += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[v0_off + 4 * i + 2]; sb = rub[(2 - ui) & 3];
      sum_lo += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[v0_off + 4 * i + 3]; sb = rub[(3 - ui) & 3];
      sum_lo += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      r_.u32[i] = sum_lo;

      uint32_t sum_hi = 0;
      vb = p_.u8[v1_off + 4 * i + 0]; sb = rub[(2 - ui) & 3];
      sum_hi += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[v1_off + 4 * i + 1]; sb = rub[(3 - ui) & 3];
      sum_hi += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[vsel + 4 * i + 2]; sb = rub[(0 - ui) & 3];
      sum_hi += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[v0_off + 4 * i + 3]; sb = rub[(1 - ui) & 3];
      sum_hi += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] = sum_hi;
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vrsad_WubRubI
  #define Q6_Wuw_vrsad_WubRubI(Vuu, Rt, Iu2) simde_Q6_Wuw_vrsad_WubRubI((Vuu), (Rt), (Iu2))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vrsadacc_WuwWubRubI(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt, int32_t Iu2) SIMDE_REQUIRE_CONSTANT_RANGE(Iu2, 0, 1) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    switch (Iu2 & 1) {
      case 0: return Q6_Wuw_vrsadacc_WuwWubRubI(Vxx, Vuu, Rt, 0);
      case 1: return Q6_Wuw_vrsadacc_WuwWubRubI(Vxx, Vuu, Rt, 1);
    }
    HEDLEY_UNREACHABLE();
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    int ui = Iu2 & 1;
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      size_t v0_off = 0;
      size_t v1_off = SIMDE_HVX_VECTOR_SIZE;
      size_t vsel = ui ? v1_off : v0_off;

      uint32_t sum_lo = 0;
      uint8_t vb, sb;
      vb = p_.u8[vsel + 4 * i + 0]; sb = rub[(0 - ui) & 3];
      sum_lo += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[v0_off + 4 * i + 1]; sb = rub[(1 - ui) & 3];
      sum_lo += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[v0_off + 4 * i + 2]; sb = rub[(2 - ui) & 3];
      sum_lo += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[v0_off + 4 * i + 3]; sb = rub[(3 - ui) & 3];
      sum_lo += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      r_.u32[i] += sum_lo;

      uint32_t sum_hi = 0;
      vb = p_.u8[v1_off + 4 * i + 0]; sb = rub[(2 - ui) & 3];
      sum_hi += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[v1_off + 4 * i + 1]; sb = rub[(3 - ui) & 3];
      sum_hi += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[vsel + 4 * i + 2]; sb = rub[(0 - ui) & 3];
      sum_hi += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      vb = p_.u8[v0_off + 4 * i + 3]; sb = rub[(1 - ui) & 3];
      sum_hi += (vb > sb) ? (uint32_t)(vb - sb) : (uint32_t)(sb - vb);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] += sum_hi;
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vrsadacc_WuwWubRubI
  #define Q6_Wuw_vrsadacc_WuwWubRubI(Vxx, Vuu, Rt, Iu2) simde_Q6_Wuw_vrsadacc_WuwWubRubI((Vxx), (Vuu), (Rt), (Iu2))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VRSAD_H) */
