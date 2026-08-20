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

#if !defined(SIMDE_HEXAGON_HVX_VDMPY_H)
#define SIMDE_HEXAGON_HVX_VDMPY_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vdmpy_VubRb(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vdmpy_VubRb(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      size_t pair = (i % 2) * 2;
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, a_.u8[2 * i]) * HEDLEY_STATIC_CAST(int16_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int16_t, a_.u8[2 * i + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[pair + 1]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vdmpy_VubRb
  #define Q6_Vh_vdmpy_VubRb(Vu, Rt) simde_Q6_Vh_vdmpy_VubRb((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpy_VhRb(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpy_VhRb(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      size_t pair = (i % 2) * 2;
      r_.i32[i] =
        HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * i]) * HEDLEY_STATIC_CAST(int32_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[pair + 1]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpy_VhRb
  #define Q6_Vw_vdmpy_VhRb(Vu, Rt) simde_Q6_Vw_vdmpy_VhRb((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpy_VhVh_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpy_VhVh_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t sum =
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * i]) +
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * i + 1]);
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpy_VhVh_sat
  #define Q6_Vw_vdmpy_VhVh_sat(Vu, Vv) simde_Q6_Vw_vdmpy_VhVh_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpy_VhRh_sat(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpy_VhRh_sat(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int16_t rh0 = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    int16_t rh1 = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t sum =
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i]) * HEDLEY_STATIC_CAST(int64_t, rh0) +
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int64_t, rh1);
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpy_VhRh_sat
  #define Q6_Vw_vdmpy_VhRh_sat(Vu, Rt) simde_Q6_Vw_vdmpy_VhRh_sat((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vdmpyacc_VhVubRb(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vdmpyacc_VhVubRb(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      size_t pair = (i % 2) * 2;
      r_.u16[i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(int16_t, a_.u8[2 * i]) * HEDLEY_STATIC_CAST(int16_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int16_t, a_.u8[2 * i + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[pair + 1]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vdmpyacc_VhVubRb
  #define Q6_Vh_vdmpyacc_VhVubRb(Vx, Vu, Rt) simde_Q6_Vh_vdmpyacc_VhVubRb((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpyacc_VwVhRb(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpyacc_VwVhRb(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      size_t pair = (i % 2) * 2;
      r_.u32[i] +=
        HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * i]) * HEDLEY_STATIC_CAST(int32_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[pair + 1]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpyacc_VwVhRb
  #define Q6_Vw_vdmpyacc_VwVhRb(Vx, Vu, Rt) simde_Q6_Vw_vdmpyacc_VwVhRb((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpyacc_VwVhVh_sat(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpyacc_VwVhVh_sat(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t dp =
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * i]) +
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * i + 1]);
      int64_t sum = HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) + dp;
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpyacc_VwVhVh_sat
  #define Q6_Vw_vdmpyacc_VwVhVh_sat(Vx, Vu, Vv) simde_Q6_Vw_vdmpyacc_VwVhVh_sat((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpyacc_VwVhRh_sat(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpyacc_VwVhRh_sat(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int16_t rh0 = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    int16_t rh1 = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t dp =
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i]) * HEDLEY_STATIC_CAST(int64_t, rh0) +
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int64_t, rh1);
      int64_t sum = HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) + dp;
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpyacc_VwVhRh_sat
  #define Q6_Vw_vdmpyacc_VwVhRh_sat(Vx, Vu, Rt) simde_Q6_Vw_vdmpyacc_VwVhRh_sat((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vdmpy_WubRb(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vdmpy_WubRb(Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_,
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      size_t pair = (i % 2) * 2;
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, p_.u8[2 * i]) * HEDLEY_STATIC_CAST(int16_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int16_t, p_.u8[2 * i + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[pair + 1]));

      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i]) * HEDLEY_STATIC_CAST(int16_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[pair + 1]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vdmpy_WubRb
  #define Q6_Wh_vdmpy_WubRb(Vuu, Rt) simde_Q6_Wh_vdmpy_WubRb((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vdmpyacc_WhWubRb(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vdmpyacc_WhWubRb(Vxx, Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      size_t pair = (i % 2) * 2;
      r_.u16[i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(int16_t, p_.u8[2 * i]) * HEDLEY_STATIC_CAST(int16_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int16_t, p_.u8[2 * i + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[pair + 1]));

      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(int16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i]) * HEDLEY_STATIC_CAST(int16_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[pair + 1]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vdmpyacc_WhWubRb
  #define Q6_Wh_vdmpyacc_WhWubRb(Vxx, Vuu, Rt) simde_Q6_Wh_vdmpyacc_WhWubRb((Vxx), (Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vdmpy_WhRb(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vdmpy_WhRb(Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_,
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      size_t pair = (i % 2) * 2;
      r_.i32[i] =
        HEDLEY_STATIC_CAST(int32_t, p_.i16[2 * i]) * HEDLEY_STATIC_CAST(int32_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int32_t, p_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[pair + 1]);

      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
        HEDLEY_STATIC_CAST(int32_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i]) * HEDLEY_STATIC_CAST(int32_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int32_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[pair + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vdmpy_WhRb
  #define Q6_Ww_vdmpy_WhRb(Vuu, Rt) simde_Q6_Ww_vdmpy_WhRb((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vdmpyacc_WwWhRb(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vdmpyacc_WwWhRb(Vxx, Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      size_t pair = (i % 2) * 2;
      r_.u32[i] +=
        HEDLEY_STATIC_CAST(int32_t, p_.i16[2 * i]) * HEDLEY_STATIC_CAST(int32_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int32_t, p_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[pair + 1]);

      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
        HEDLEY_STATIC_CAST(int32_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i]) * HEDLEY_STATIC_CAST(int32_t, rb[pair]) +
        HEDLEY_STATIC_CAST(int32_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[pair + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vdmpyacc_WwWhRb
  #define Q6_Ww_vdmpyacc_WwWhRb(Vxx, Vuu, Rt) simde_Q6_Ww_vdmpyacc_WwWhRb((Vxx), (Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpy_VhRuh_sat(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpy_VhRuh_sat(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    uint16_t ruh[2];
    ruh[0] = HEDLEY_STATIC_CAST(uint16_t, Rt & 0xFFFF);
    ruh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t sum =
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint16_t, ruh[0])) +
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint16_t, ruh[1]));
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpy_VhRuh_sat
  #define Q6_Vw_vdmpy_VhRuh_sat(Vu, Rt) simde_Q6_Vw_vdmpy_VhRuh_sat((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpy_WhRh_sat(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpy_WhRh_sat(Vuu, Rt);
  #else
    simde_hvx_vector_private
      r_;
    simde_hvx_vectorpair_private
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int16_t rh0 = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    int16_t rh1 = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t sum =
        HEDLEY_STATIC_CAST(int64_t, p_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int64_t, rh0) +
        HEDLEY_STATIC_CAST(int64_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i]) * HEDLEY_STATIC_CAST(int64_t, rh1);
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpy_WhRh_sat
  #define Q6_Vw_vdmpy_WhRh_sat(Vuu, Rt) simde_Q6_Vw_vdmpy_WhRh_sat((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpy_WhRuh_sat(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpy_WhRuh_sat(Vuu, Rt);
  #else
    simde_hvx_vector_private
      r_;
    simde_hvx_vectorpair_private
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    uint16_t ruh[2];
    ruh[0] = HEDLEY_STATIC_CAST(uint16_t, Rt & 0xFFFF);
    ruh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t sum =
        HEDLEY_STATIC_CAST(int64_t, p_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint16_t, ruh[0])) +
        HEDLEY_STATIC_CAST(int64_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint16_t, ruh[1]));
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpy_WhRuh_sat
  #define Q6_Vw_vdmpy_WhRuh_sat(Vuu, Rt) simde_Q6_Vw_vdmpy_WhRuh_sat((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpyacc_VwVhRuh_sat(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpyacc_VwVhRuh_sat(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    uint16_t ruh[2];
    ruh[0] = HEDLEY_STATIC_CAST(uint16_t, Rt & 0xFFFF);
    ruh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t dp =
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint16_t, ruh[0])) +
        HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint16_t, ruh[1]));
      int64_t sum = HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) + dp;
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpyacc_VwVhRuh_sat
  #define Q6_Vw_vdmpyacc_VwVhRuh_sat(Vx, Vu, Rt) simde_Q6_Vw_vdmpyacc_VwVhRuh_sat((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpyacc_VwWhRh_sat(simde_hvx_vector_t Vx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpyacc_VwWhRh_sat(Vx, Vuu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx);
    simde_hvx_vectorpair_private
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int16_t rh0 = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    int16_t rh1 = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t dp =
        HEDLEY_STATIC_CAST(int64_t, p_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int64_t, rh0) +
        HEDLEY_STATIC_CAST(int64_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i]) * HEDLEY_STATIC_CAST(int64_t, rh1);
      int64_t sum = HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) + dp;
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpyacc_VwWhRh_sat
  #define Q6_Vw_vdmpyacc_VwWhRh_sat(Vx, Vuu, Rt) simde_Q6_Vw_vdmpyacc_VwWhRh_sat((Vx), (Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vdmpyacc_VwWhRuh_sat(simde_hvx_vector_t Vx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vdmpyacc_VwWhRuh_sat(Vx, Vuu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx);
    simde_hvx_vectorpair_private
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    uint16_t ruh[2];
    ruh[0] = HEDLEY_STATIC_CAST(uint16_t, Rt & 0xFFFF);
    ruh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t dp =
        HEDLEY_STATIC_CAST(int64_t, p_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint16_t, ruh[0])) +
        HEDLEY_STATIC_CAST(int64_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint16_t, ruh[1]));
      int64_t sum = HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) + dp;
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vdmpyacc_VwWhRuh_sat
  #define Q6_Vw_vdmpyacc_VwWhRuh_sat(Vx, Vuu, Rt) simde_Q6_Vw_vdmpyacc_VwWhRuh_sat((Vx), (Vuu), (Rt))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VDMPY_H) */
