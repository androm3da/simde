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

#if !defined(SIMDE_HEXAGON_HVX_VMPA_H)
#define SIMDE_HEXAGON_HVX_VMPA_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpa_WubRb(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpa_WubRb(Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_,
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, p_.u8[2 * i]) * HEDLEY_STATIC_CAST(int16_t, rb[0]) +
        HEDLEY_STATIC_CAST(int16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i]) * HEDLEY_STATIC_CAST(int16_t, rb[1]));

      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, p_.u8[2 * i + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[2]) +
        HEDLEY_STATIC_CAST(int16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[3]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpa_WubRb
  #define Q6_Wh_vmpa_WubRb(Vuu, Rt) simde_Q6_Wh_vmpa_WubRb((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpa_WhRb(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpa_WhRb(Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_,
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] =
        HEDLEY_STATIC_CAST(int32_t, p_.i16[2 * i]) * HEDLEY_STATIC_CAST(int32_t, rb[0]) +
        HEDLEY_STATIC_CAST(int32_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i]) * HEDLEY_STATIC_CAST(int32_t, rb[1]);

      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
        HEDLEY_STATIC_CAST(int32_t, p_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[2]) +
        HEDLEY_STATIC_CAST(int32_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[3]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpa_WhRb
  #define Q6_Ww_vmpa_WhRb(Vuu, Rt) simde_Q6_Ww_vmpa_WhRb((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpa_WubWb(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpa_WubWb(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      pu_ = simde_hvx_vectorpair_to_private(Vuu),
      pv_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, pu_.u8[2 * i]) *
          HEDLEY_STATIC_CAST(int16_t, pv_.i8[2 * i]) +
        HEDLEY_STATIC_CAST(int16_t, pu_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i]) *
          HEDLEY_STATIC_CAST(int16_t, pv_.i8[SIMDE_HVX_VECTOR_SIZE + 2 * i]));

      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, pu_.u8[2 * i + 1]) *
          HEDLEY_STATIC_CAST(int16_t, pv_.i8[2 * i + 1]) +
        HEDLEY_STATIC_CAST(int16_t, pu_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1]) *
          HEDLEY_STATIC_CAST(int16_t, pv_.i8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpa_WubWb
  #define Q6_Wh_vmpa_WubWb(Vuu, Vvv) simde_Q6_Wh_vmpa_WubWb((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpa_WubWub(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpa_WubWub(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      pu_ = simde_hvx_vectorpair_to_private(Vuu),
      pv_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(uint16_t, pu_.u8[2 * i]) *
          HEDLEY_STATIC_CAST(uint16_t, pv_.u8[2 * i]) +
        HEDLEY_STATIC_CAST(uint16_t, pu_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i]) *
          HEDLEY_STATIC_CAST(uint16_t, pv_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i]));

      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(uint16_t, pu_.u8[2 * i + 1]) *
          HEDLEY_STATIC_CAST(uint16_t, pv_.u8[2 * i + 1]) +
        HEDLEY_STATIC_CAST(uint16_t, pu_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1]) *
          HEDLEY_STATIC_CAST(uint16_t, pv_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpa_WubWub
  #define Q6_Wh_vmpa_WubWub(Vuu, Vvv) simde_Q6_Wh_vmpa_WubWub((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpaacc_WhWubRb(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpaacc_WhWubRb(Vxx, Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(int16_t, p_.u8[2 * i]) * HEDLEY_STATIC_CAST(int16_t, rb[0]) +
        HEDLEY_STATIC_CAST(int16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i]) * HEDLEY_STATIC_CAST(int16_t, rb[1]));

      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(int16_t, p_.u8[2 * i + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[2]) +
        HEDLEY_STATIC_CAST(int16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[3]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpaacc_WhWubRb
  #define Q6_Wh_vmpaacc_WhWubRb(Vxx, Vuu, Rt) simde_Q6_Wh_vmpaacc_WhWubRb((Vxx), (Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpaacc_WwWhRb(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpaacc_WwWhRb(Vxx, Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] += HEDLEY_STATIC_CAST(uint32_t,
        HEDLEY_STATIC_CAST(int32_t, p_.i16[2 * i]) * HEDLEY_STATIC_CAST(int32_t, rb[0]) +
        HEDLEY_STATIC_CAST(int32_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i]) * HEDLEY_STATIC_CAST(int32_t, rb[1]));

      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] += HEDLEY_STATIC_CAST(uint32_t,
        HEDLEY_STATIC_CAST(int32_t, p_.i16[2 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[2]) +
        HEDLEY_STATIC_CAST(int32_t, p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i + 1]) * HEDLEY_STATIC_CAST(int32_t, rb[3]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpaacc_WwWhRb
  #define Q6_Ww_vmpaacc_WwWhRb(Vxx, Vuu, Rt) simde_Q6_Ww_vmpaacc_WwWhRb((Vxx), (Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpa_WubRub(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpa_WubRub(Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_,
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(uint16_t, p_.u8[2 * i]) * HEDLEY_STATIC_CAST(uint16_t, rub[0]) +
        HEDLEY_STATIC_CAST(uint16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i]) * HEDLEY_STATIC_CAST(uint16_t, rub[1]));

      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(uint16_t, p_.u8[2 * i + 1]) * HEDLEY_STATIC_CAST(uint16_t, rub[2]) +
        HEDLEY_STATIC_CAST(uint16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1]) * HEDLEY_STATIC_CAST(uint16_t, rub[3]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpa_WubRub
  #define Q6_Wh_vmpa_WubRub(Vuu, Rt) simde_Q6_Wh_vmpa_WubRub((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpa_WuhRb(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpa_WuhRb(Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_,
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] =
        HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, p_.u16[2 * i])) * HEDLEY_STATIC_CAST(int32_t, rb[0]) +
        HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, p_.u16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i])) * HEDLEY_STATIC_CAST(int32_t, rb[1]);

      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
        HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, p_.u16[2 * i + 1])) * HEDLEY_STATIC_CAST(int32_t, rb[2]) +
        HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, p_.u16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i + 1])) * HEDLEY_STATIC_CAST(int32_t, rb[3]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpa_WuhRb
  #define Q6_Ww_vmpa_WuhRb(Vuu, Rt) simde_Q6_Ww_vmpa_WuhRb((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpaacc_WhWubRub(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpaacc_WhWubRub(Vxx, Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(uint16_t, p_.u8[2 * i]) * HEDLEY_STATIC_CAST(uint16_t, rub[0]) +
        HEDLEY_STATIC_CAST(uint16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i]) * HEDLEY_STATIC_CAST(uint16_t, rub[1]));

      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(uint16_t, p_.u8[2 * i + 1]) * HEDLEY_STATIC_CAST(uint16_t, rub[2]) +
        HEDLEY_STATIC_CAST(uint16_t, p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1]) * HEDLEY_STATIC_CAST(uint16_t, rub[3]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpaacc_WhWubRub
  #define Q6_Wh_vmpaacc_WhWubRub(Vxx, Vuu, Rt) simde_Q6_Wh_vmpaacc_WhWubRub((Vxx), (Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpaacc_WwWuhRb(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpaacc_WwWuhRb(Vxx, Vuu, Rt);
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      p_ = simde_hvx_vectorpair_to_private(Vuu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, HEDLEY_STATIC_CAST(uint32_t, Rt) >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] += HEDLEY_STATIC_CAST(uint32_t,
        HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, p_.u16[2 * i])) * HEDLEY_STATIC_CAST(int32_t, rb[0]) +
        HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, p_.u16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i])) * HEDLEY_STATIC_CAST(int32_t, rb[1]));

      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] += HEDLEY_STATIC_CAST(uint32_t,
        HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, p_.u16[2 * i + 1])) * HEDLEY_STATIC_CAST(int32_t, rb[2]) +
        HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, p_.u16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i + 1])) * HEDLEY_STATIC_CAST(int32_t, rb[3]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpaacc_WwWuhRb
  #define Q6_Ww_vmpaacc_WwWuhRb(Vxx, Vuu, Rt) simde_Q6_Ww_vmpaacc_WwWuhRb((Vxx), (Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vmpa_VhVhVhPh_sat(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int64_t Rtt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vh_vmpa_VhVhVhPh_sat)
    return Q6_Vh_vmpa_VhVhVhPh_sat(Vx, Vu, Rtt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      u_ = simde_hvx_vector_to_private(Vu);

    int16_t rh[4];
    rh[0] = HEDLEY_STATIC_CAST(int16_t, Rtt & 0xFFFF);
    rh[1] = HEDLEY_STATIC_CAST(int16_t, (Rtt >> 16) & 0xFFFF);
    rh[2] = HEDLEY_STATIC_CAST(int16_t, (Rtt >> 32) & 0xFFFF);
    rh[3] = HEDLEY_STATIC_CAST(int16_t, (Rtt >> 48) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      unsigned idx = (HEDLEY_STATIC_CAST(uint16_t, u_.i16[i]) >> 14) & 0x3u;
      int64_t val = (HEDLEY_STATIC_CAST(int64_t, x_.i16[i]) * HEDLEY_STATIC_CAST(int64_t, u_.i16[i]) * 2) +
                    (HEDLEY_STATIC_CAST(int64_t, rh[idx]) * 32768);
      val >>= 16;
      r_.i16[i] = (val > INT16_MAX) ? INT16_MAX : ((val < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, val));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vmpa_VhVhVhPh_sat
  #define Q6_Vh_vmpa_VhVhVhPh_sat(Vx, Vu, Rtt) simde_Q6_Vh_vmpa_VhVhVhPh_sat((Vx), (Vu), (Rtt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vmpa_VhVhVuhPuh_sat(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int64_t Rtt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vh_vmpa_VhVhVuhPuh_sat)
    return Q6_Vh_vmpa_VhVhVuhPuh_sat(Vx, Vu, Rtt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      u_ = simde_hvx_vector_to_private(Vu);

    uint16_t rh[4];
    rh[0] = HEDLEY_STATIC_CAST(uint16_t, Rtt & 0xFFFF);
    rh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rtt >> 16) & 0xFFFF);
    rh[2] = HEDLEY_STATIC_CAST(uint16_t, (Rtt >> 32) & 0xFFFF);
    rh[3] = HEDLEY_STATIC_CAST(uint16_t, (Rtt >> 48) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      unsigned idx = (HEDLEY_STATIC_CAST(unsigned, u_.u16[i]) >> 14) & 0x3u;
      int64_t val = (HEDLEY_STATIC_CAST(int64_t, x_.i16[i]) * HEDLEY_STATIC_CAST(int64_t, u_.u16[i])) +
                    (HEDLEY_STATIC_CAST(int64_t, rh[idx]) * 32768);
      val >>= 16;
      r_.i16[i] = (val > INT16_MAX) ? INT16_MAX : ((val < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, val));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vmpa_VhVhVuhPuh_sat
  #define Q6_Vh_vmpa_VhVhVuhPuh_sat(Vx, Vu, Rtt) simde_Q6_Vh_vmpa_VhVhVuhPuh_sat((Vx), (Vu), (Rtt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vmps_VhVhVuhPuh_sat(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int64_t Rtt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vh_vmps_VhVhVuhPuh_sat)
    return Q6_Vh_vmps_VhVhVuhPuh_sat(Vx, Vu, Rtt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      u_ = simde_hvx_vector_to_private(Vu);

    uint16_t rh[4];
    rh[0] = HEDLEY_STATIC_CAST(uint16_t, Rtt & 0xFFFF);
    rh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rtt >> 16) & 0xFFFF);
    rh[2] = HEDLEY_STATIC_CAST(uint16_t, (Rtt >> 32) & 0xFFFF);
    rh[3] = HEDLEY_STATIC_CAST(uint16_t, (Rtt >> 48) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      unsigned idx = (HEDLEY_STATIC_CAST(unsigned, u_.u16[i]) >> 14) & 0x3u;
      int64_t val = (HEDLEY_STATIC_CAST(int64_t, x_.i16[i]) * HEDLEY_STATIC_CAST(int64_t, u_.u16[i])) -
                    (HEDLEY_STATIC_CAST(int64_t, rh[idx]) * 32768);
      val >>= 16;
      r_.i16[i] = (val > INT16_MAX) ? INT16_MAX : ((val < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, val));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vmps_VhVhVuhPuh_sat
  #define Q6_Vh_vmps_VhVhVuhPuh_sat(Vx, Vu, Rtt) simde_Q6_Vh_vmps_VhVhVuhPuh_sat((Vx), (Vu), (Rtt))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VMPA_H) */
