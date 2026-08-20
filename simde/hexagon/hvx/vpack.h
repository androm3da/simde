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

#if !defined(SIMDE_HEXAGON_HVX_VPACK_H)
#define SIMDE_HEXAGON_HVX_VPACK_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vpacke_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vpacke_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    size_t half = SIMDE_HVX_VECTOR_I16_COUNT;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      r_.u8[i]        = b_.u8[2 * i];
      r_.u8[half + i] = a_.u8[2 * i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vpacke_VhVh
  #define Q6_Vb_vpacke_VhVh(Vu, Vv) simde_Q6_Vb_vpacke_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vpacko_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vpacko_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    size_t half = SIMDE_HVX_VECTOR_I16_COUNT;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      r_.u8[i]        = b_.u8[2 * i + 1];
      r_.u8[half + i] = a_.u8[2 * i + 1];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vpacko_VhVh
  #define Q6_Vb_vpacko_VhVh(Vu, Vv) simde_Q6_Vb_vpacko_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vpacke_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vpacke_VwVw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    size_t half = SIMDE_HVX_VECTOR_I32_COUNT;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      r_.u16[i]        = b_.u16[2 * i];
      r_.u16[half + i] = a_.u16[2 * i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vpacke_VwVw
  #define Q6_Vh_vpacke_VwVw(Vu, Vv) simde_Q6_Vh_vpacke_VwVw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vpacko_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vpacko_VwVw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    size_t half = SIMDE_HVX_VECTOR_I32_COUNT;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      r_.u16[i]        = b_.u16[2 * i + 1];
      r_.u16[half + i] = a_.u16[2 * i + 1];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vpacko_VwVw
  #define Q6_Vh_vpacko_VwVw(Vu, Vv) simde_Q6_Vh_vpacko_VwVw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vpack_VhVh_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vpack_VhVh_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    size_t half = SIMDE_HVX_VECTOR_I16_COUNT;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      int16_t vv = b_.i16[i];
      int16_t vu = a_.i16[i];
      r_.i8[i]        = (vv > INT8_MAX) ? INT8_MAX : ((vv < INT8_MIN) ? INT8_MIN : HEDLEY_STATIC_CAST(int8_t, vv));
      r_.i8[half + i] = (vu > INT8_MAX) ? INT8_MAX : ((vu < INT8_MIN) ? INT8_MIN : HEDLEY_STATIC_CAST(int8_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vpack_VhVh_sat
  #define Q6_Vb_vpack_VhVh_sat(Vu, Vv) simde_Q6_Vb_vpack_VhVh_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vpack_VhVh_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vpack_VhVh_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    size_t half = SIMDE_HVX_VECTOR_I16_COUNT;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      int16_t vv = b_.i16[i];
      int16_t vu = a_.i16[i];
      r_.u8[i]        = (vv > UINT8_MAX) ? UINT8_MAX : ((vv < 0) ? 0 : HEDLEY_STATIC_CAST(uint8_t, vv));
      r_.u8[half + i] = (vu > UINT8_MAX) ? UINT8_MAX : ((vu < 0) ? 0 : HEDLEY_STATIC_CAST(uint8_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vpack_VhVh_sat
  #define Q6_Vub_vpack_VhVh_sat(Vu, Vv) simde_Q6_Vub_vpack_VhVh_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vpack_VwVw_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vpack_VwVw_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    size_t half = SIMDE_HVX_VECTOR_I32_COUNT;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      int32_t vv = b_.i32[i];
      int32_t vu = a_.i32[i];
      r_.i16[i]        = (vv > INT16_MAX) ? INT16_MAX : ((vv < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, vv));
      r_.i16[half + i] = (vu > INT16_MAX) ? INT16_MAX : ((vu < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vpack_VwVw_sat
  #define Q6_Vh_vpack_VwVw_sat(Vu, Vv) simde_Q6_Vh_vpack_VwVw_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vpack_VwVw_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vpack_VwVw_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    size_t half = SIMDE_HVX_VECTOR_I32_COUNT;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      int32_t vv = b_.i32[i];
      int32_t vu = a_.i32[i];
      r_.u16[i]        = (vv > UINT16_MAX) ? UINT16_MAX : ((vv < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, vv));
      r_.u16[half + i] = (vu > UINT16_MAX) ? UINT16_MAX : ((vu < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vpack_VwVw_sat
  #define Q6_Vuh_vpack_VwVw_sat(Vu, Vv) simde_Q6_Vuh_vpack_VwVw_sat((Vu), (Vv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VPACK_H) */
