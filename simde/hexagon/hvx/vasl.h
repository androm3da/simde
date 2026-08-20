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

#if !defined(SIMDE_HEXAGON_HVX_VASL_H)
#define SIMDE_HEXAGON_HVX_VASL_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vasl_VhR(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vasl_VhR(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int shift = Rt & 15;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, HEDLEY_STATIC_CAST(unsigned int, a_.u16[i]) << shift);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vasl_VhR
  #define Q6_Vh_vasl_VhR(Vu, Rt) simde_Q6_Vh_vasl_VhR((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vasl_VwR(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vasl_VwR(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int shift = Rt & 31;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = a_.u32[i] << shift;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vasl_VwR
  #define Q6_Vw_vasl_VwR(Vu, Rt) simde_Q6_Vw_vasl_VwR((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vasl_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vasl_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int shift = ((HEDLEY_STATIC_CAST(int, b_.i16[i]) & 0x1F) ^ 0x10) - 0x10;
      if (shift >= 0) {
        r_.i16[i] = (shift >= 16) ? 0 : HEDLEY_STATIC_CAST(int16_t, HEDLEY_STATIC_CAST(unsigned int, a_.u16[i]) << shift);
      } else {
        int rshift = -shift;
        r_.i16[i] = (rshift >= 16) ? (a_.i16[i] >> 15) : (a_.i16[i] >> rshift);
      }
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vasl_VhVh
  #define Q6_Vh_vasl_VhVh(Vu, Vv) simde_Q6_Vh_vasl_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vasl_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vasl_VwVw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int shift = ((HEDLEY_STATIC_CAST(int, b_.i32[i]) & 0x3F) ^ 0x20) - 0x20;
      if (shift >= 0) {
        r_.i32[i] = (shift >= 32) ? 0 : HEDLEY_STATIC_CAST(int32_t, a_.u32[i] << shift);
      } else {
        int rshift = -shift;
        r_.i32[i] = (rshift >= 32) ? (a_.i32[i] >> 31) : (a_.i32[i] >> rshift);
      }
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vasl_VwVw
  #define Q6_Vw_vasl_VwVw(Vu, Vv) simde_Q6_Vw_vasl_VwVw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vaslacc_VwVwR(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vaslacc_VwVwR(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int shift = Rt & 31;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = x_.u32[i] + (a_.u32[i] << shift);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vaslacc_VwVwR
  #define Q6_Vw_vaslacc_VwVwR(Vx, Vu, Rt) simde_Q6_Vw_vaslacc_VwVwR((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vaslacc_VhVhR(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vaslacc_VhVhR(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int shift = Rt & 15;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, x_.u16[i] + HEDLEY_STATIC_CAST(uint16_t, HEDLEY_STATIC_CAST(unsigned int, a_.u16[i]) << shift));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vaslacc_VhVhR
  #define Q6_Vh_vaslacc_VhVhR(Vx, Vu, Rt) simde_Q6_Vh_vaslacc_VhVhR((Vx), (Vu), (Rt))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VASL_H) */
