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

#if !defined(SIMDE_HEXAGON_HVX_VSAT_H)
#define SIMDE_HEXAGON_HVX_VSAT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vsat_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vsat_VwVw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int32_t vv = b_.i32[i];
      int32_t vu = a_.i32[i];
      r_.i16[2 * i]     = (vv > INT16_MAX) ? INT16_MAX : ((vv < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, vv));
      r_.i16[2 * i + 1] = (vu > INT16_MAX) ? INT16_MAX : ((vu < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vsat_VwVw
  #define Q6_Vh_vsat_VwVw(Vu, Vv) simde_Q6_Vh_vsat_VwVw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vsat_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vsat_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int16_t vv = b_.i16[i];
      int16_t vu = a_.i16[i];
      r_.u8[2 * i]     = (vv > UINT8_MAX) ? UINT8_MAX : ((vv < 0) ? 0 : HEDLEY_STATIC_CAST(uint8_t, vv));
      r_.u8[2 * i + 1] = (vu > UINT8_MAX) ? UINT8_MAX : ((vu < 0) ? 0 : HEDLEY_STATIC_CAST(uint8_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vsat_VhVh
  #define Q6_Vub_vsat_VhVh(Vu, Vv) simde_Q6_Vub_vsat_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vsat_VuwVuw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vsat_VuwVuw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint32_t vv = b_.u32[i];
      uint32_t vu = a_.u32[i];
      r_.u16[2 * i]     = (vv > UINT16_MAX) ? UINT16_MAX : HEDLEY_STATIC_CAST(uint16_t, vv);
      r_.u16[2 * i + 1] = (vu > UINT16_MAX) ? UINT16_MAX : HEDLEY_STATIC_CAST(uint16_t, vu);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vsat_VuwVuw
  #define Q6_Vuh_vsat_VuwVuw(Vu, Vv) simde_Q6_Vuh_vsat_VuwVuw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vsatdw_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vsatdw_VwVw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t dw = HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) * INT64_C(4294967296) + HEDLEY_STATIC_CAST(int64_t, b_.u32[i]);
      if (dw > INT32_MAX) dw = INT32_MAX;
      else if (dw < INT32_MIN) dw = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, dw);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vsatdw_VwVw
  #define Q6_Vw_vsatdw_VwVw(Vu, Vv) simde_Q6_Vw_vsatdw_VwVw((Vu), (Vv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VSAT_H) */
