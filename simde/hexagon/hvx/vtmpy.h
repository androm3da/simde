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

#if !defined(SIMDE_HEXAGON_HVX_VTMPY_H)
#define SIMDE_HEXAGON_HVX_VTMPY_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vtmpy_WbRb(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vtmpy_WbRb(Vuu, Rt);
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
      int8_t lo_even = p_.i8[2 * i];
      int8_t lo_odd  = p_.i8[2 * i + 1];
      int8_t hi_even = p_.i8[SIMDE_HVX_VECTOR_SIZE + 2 * i];
      int8_t hi_odd  = p_.i8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1];

      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, lo_even) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, lo_odd)  * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_even));

      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, lo_odd)  * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_even) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_odd));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vtmpy_WbRb
  #define Q6_Wh_vtmpy_WbRb(Vuu, Rt) simde_Q6_Wh_vtmpy_WbRb((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vtmpy_WubRb(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vtmpy_WubRb(Vuu, Rt);
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
      uint8_t lo_even = p_.u8[2 * i];
      uint8_t lo_odd  = p_.u8[2 * i + 1];
      uint8_t hi_even = p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i];
      uint8_t hi_odd  = p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1];

      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, lo_even) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, lo_odd)  * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_even));

      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = HEDLEY_STATIC_CAST(int16_t,
        HEDLEY_STATIC_CAST(int16_t, lo_odd)  * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_even) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_odd));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vtmpy_WubRb
  #define Q6_Wh_vtmpy_WubRb(Vuu, Rt) simde_Q6_Wh_vtmpy_WubRb((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vtmpy_WhRb(simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vtmpy_WhRb(Vuu, Rt);
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
      int16_t lo_even = p_.i16[2 * i];
      int16_t lo_odd  = p_.i16[2 * i + 1];
      int16_t hi_even = p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i];
      int16_t hi_odd  = p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i + 1];

      r_.i32[i] =
        HEDLEY_STATIC_CAST(int32_t, lo_even) * HEDLEY_STATIC_CAST(int32_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int32_t, lo_odd)  * HEDLEY_STATIC_CAST(int32_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int32_t, hi_even);

      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
        HEDLEY_STATIC_CAST(int32_t, lo_odd)  * HEDLEY_STATIC_CAST(int32_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int32_t, hi_even) * HEDLEY_STATIC_CAST(int32_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int32_t, hi_odd);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vtmpy_WhRb
  #define Q6_Ww_vtmpy_WhRb(Vuu, Rt) simde_Q6_Ww_vtmpy_WhRb((Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vtmpyacc_WhWbRb(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vtmpyacc_WhWbRb(Vxx, Vuu, Rt);
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
      int8_t lo_even = p_.i8[2 * i];
      int8_t lo_odd  = p_.i8[2 * i + 1];
      int8_t hi_even = p_.i8[SIMDE_HVX_VECTOR_SIZE + 2 * i];
      int8_t hi_odd  = p_.i8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1];

      r_.u16[i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(int16_t, lo_even) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, lo_odd)  * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_even));

      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(int16_t, lo_odd)  * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_even) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_odd));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vtmpyacc_WhWbRb
  #define Q6_Wh_vtmpyacc_WhWbRb(Vxx, Vuu, Rt) simde_Q6_Wh_vtmpyacc_WhWbRb((Vxx), (Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vtmpyacc_WhWubRb(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vtmpyacc_WhWubRb(Vxx, Vuu, Rt);
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
      uint8_t lo_even = p_.u8[2 * i];
      uint8_t lo_odd  = p_.u8[2 * i + 1];
      uint8_t hi_even = p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i];
      uint8_t hi_odd  = p_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1];

      r_.u16[i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(int16_t, lo_even) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, lo_odd)  * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_even));

      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + i] += HEDLEY_STATIC_CAST(uint16_t,
        HEDLEY_STATIC_CAST(int16_t, lo_odd)  * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_even) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int16_t, hi_odd));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vtmpyacc_WhWubRb
  #define Q6_Wh_vtmpyacc_WhWubRb(Vxx, Vuu, Rt) simde_Q6_Wh_vtmpyacc_WhWubRb((Vxx), (Vuu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vtmpyacc_WwWhRb(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vtmpyacc_WwWhRb(Vxx, Vuu, Rt);
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
      int16_t lo_even = p_.i16[2 * i];
      int16_t lo_odd  = p_.i16[2 * i + 1];
      int16_t hi_even = p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i];
      int16_t hi_odd  = p_.i16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i + 1];

      r_.u32[i] +=
        HEDLEY_STATIC_CAST(int32_t, lo_even) * HEDLEY_STATIC_CAST(int32_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int32_t, lo_odd)  * HEDLEY_STATIC_CAST(int32_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int32_t, hi_even);

      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
        HEDLEY_STATIC_CAST(int32_t, lo_odd)  * HEDLEY_STATIC_CAST(int32_t, rb[(2 * i) % 4]) +
        HEDLEY_STATIC_CAST(int32_t, hi_even) * HEDLEY_STATIC_CAST(int32_t, rb[(2 * i + 1) % 4]) +
        HEDLEY_STATIC_CAST(int32_t, hi_odd);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vtmpyacc_WwWhRb
  #define Q6_Ww_vtmpyacc_WwWhRb(Vxx, Vuu, Rt) simde_Q6_Ww_vtmpyacc_WwWhRb((Vxx), (Vuu), (Rt))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VTMPY_H) */
