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

#if !defined(SIMDE_HEXAGON_HVX_VROUND_H)
#define SIMDE_HEXAGON_HVX_VROUND_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vround_VwVw_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vround_VwVw_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t vv = (HEDLEY_STATIC_CAST(int64_t, b_.i32[i]) + 0x8000LL) >> 16;
      int64_t vu = (HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) + 0x8000LL) >> 16;
      r_.i16[2 * i]     = (vv > INT16_MAX) ? INT16_MAX : ((vv < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, vv));
      r_.i16[2 * i + 1] = (vu > INT16_MAX) ? INT16_MAX : ((vu < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vround_VwVw_sat
  #define Q6_Vh_vround_VwVw_sat(Vu, Vv) simde_Q6_Vh_vround_VwVw_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vround_VwVw_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vround_VwVw_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t vv = (HEDLEY_STATIC_CAST(int64_t, b_.i32[i]) + 0x8000LL) >> 16;
      int64_t vu = (HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) + 0x8000LL) >> 16;
      r_.u16[2 * i]     = (vv > UINT16_MAX) ? UINT16_MAX : ((vv < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, vv));
      r_.u16[2 * i + 1] = (vu > UINT16_MAX) ? UINT16_MAX : ((vu < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vround_VwVw_sat
  #define Q6_Vuh_vround_VwVw_sat(Vu, Vv) simde_Q6_Vuh_vround_VwVw_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vround_VhVh_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vround_VhVh_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int32_t vv = (HEDLEY_STATIC_CAST(int32_t, b_.i16[i]) + 0x80) >> 8;
      int32_t vu = (HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) + 0x80) >> 8;
      r_.i8[2 * i]     = (vv > INT8_MAX) ? INT8_MAX : ((vv < INT8_MIN) ? INT8_MIN : HEDLEY_STATIC_CAST(int8_t, vv));
      r_.i8[2 * i + 1] = (vu > INT8_MAX) ? INT8_MAX : ((vu < INT8_MIN) ? INT8_MIN : HEDLEY_STATIC_CAST(int8_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vround_VhVh_sat
  #define Q6_Vb_vround_VhVh_sat(Vu, Vv) simde_Q6_Vb_vround_VhVh_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vround_VhVh_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vround_VhVh_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int32_t vv = (HEDLEY_STATIC_CAST(int32_t, b_.i16[i]) + 0x80) >> 8;
      int32_t vu = (HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) + 0x80) >> 8;
      r_.u8[2 * i]     = (vv > UINT8_MAX) ? UINT8_MAX : ((vv < 0) ? 0 : HEDLEY_STATIC_CAST(uint8_t, vv));
      r_.u8[2 * i + 1] = (vu > UINT8_MAX) ? UINT8_MAX : ((vu < 0) ? 0 : HEDLEY_STATIC_CAST(uint8_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vround_VhVh_sat
  #define Q6_Vub_vround_VhVh_sat(Vu, Vv) simde_Q6_Vub_vround_VhVh_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vround_VuhVuh_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vround_VuhVuh_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint32_t vv = (HEDLEY_STATIC_CAST(uint32_t, b_.u16[i]) + 0x80u) >> 8;
      uint32_t vu = (HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]) + 0x80u) >> 8;
      r_.u8[2 * i]     = (vv > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, vv);
      r_.u8[2 * i + 1] = (vu > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, vu);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vround_VuhVuh_sat
  #define Q6_Vub_vround_VuhVuh_sat(Vu, Vv) simde_Q6_Vub_vround_VuhVuh_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vround_VuwVuw_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vround_VuwVuw_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint64_t vv = (HEDLEY_STATIC_CAST(uint64_t, b_.u32[i]) + 0x8000ULL) >> 16;
      uint64_t vu = (HEDLEY_STATIC_CAST(uint64_t, a_.u32[i]) + 0x8000ULL) >> 16;
      r_.u16[2 * i]     = (vv > UINT16_MAX) ? UINT16_MAX : HEDLEY_STATIC_CAST(uint16_t, vv);
      r_.u16[2 * i + 1] = (vu > UINT16_MAX) ? UINT16_MAX : HEDLEY_STATIC_CAST(uint16_t, vu);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vround_VuwVuw_sat
  #define Q6_Vuh_vround_VuwVuw_sat(Vu, Vv) simde_Q6_Vuh_vround_VuwVuw_sat((Vu), (Vv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VROUND_H) */
