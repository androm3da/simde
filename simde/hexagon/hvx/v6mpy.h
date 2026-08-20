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

#if !defined(SIMDE_HEXAGON_HVX_V6MPY_H)
#define SIMDE_HEXAGON_HVX_V6MPY_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
int16_t
simde_v6mpy_coeff_(uint32_t val, int pos) {
  int32_t hi2 = HEDLEY_STATIC_CAST(int32_t, (val >> (24 + 2 * pos)) & 3u);
  uint32_t lo8 = (val >> (pos * 8)) & 0xFFu;
  if (hi2 & 2) hi2 -= 4;
  return HEDLEY_STATIC_CAST(int16_t, (hi2 * 256) + HEDLEY_STATIC_CAST(int32_t, lo8));
}

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_v6mpy_WubWbI_v(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv, int32_t Iu2) SIMDE_REQUIRE_CONSTANT_RANGE(Iu2, 0, 3) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    switch (Iu2 & 3) {
      case 0: return Q6_Ww_v6mpy_WubWbI_v(Vuu, Vvv, 0);
      case 1: return Q6_Ww_v6mpy_WubWbI_v(Vuu, Vvv, 1);
      case 2: return Q6_Ww_v6mpy_WubWbI_v(Vuu, Vvv, 2);
      case 3: return Q6_Ww_v6mpy_WubWbI_v(Vuu, Vvv, 3);
    }
    HEDLEY_UNREACHABLE();
  #else
    simde_hvx_vectorpair_private
      r_,
      pu_ = simde_hvx_vectorpair_to_private(Vuu),
      pv_ = simde_hvx_vectorpair_to_private(Vvv);

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int16_t c00 = simde_v6mpy_coeff_(pv_.u32[i], 0);
      int16_t c01 = simde_v6mpy_coeff_(pv_.u32[i], 1);
      int16_t c02 = simde_v6mpy_coeff_(pv_.u32[i], 2);
      int16_t c10 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 0);
      int16_t c11 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 1);
      int16_t c12 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 2);

      #define UB_V0(n) HEDLEY_STATIC_CAST(int32_t, pu_.u8[4 * i + (n)])
      #define UB_V1(n) HEDLEY_STATIC_CAST(int32_t, pu_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + (n)])

      switch (Iu2 & 3) {
        case 0:
          r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
            UB_V0(3) * c10 + UB_V1(2) * c11 + UB_V1(3) * c12 +
            UB_V0(1) * c00 + UB_V1(0) * c01 + UB_V1(1) * c02;
          r_.i32[i] =
            UB_V0(1) * c10 + UB_V1(0) * c11 + UB_V1(1) * c12;
          break;
        case 1:
          r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
            UB_V0(3) * c00 + UB_V1(2) * c01 + UB_V1(3) * c02;
          r_.i32[i] =
            UB_V0(3) * c10 + UB_V1(2) * c11 + UB_V1(3) * c12 +
            UB_V0(1) * c00 + UB_V1(0) * c01 + UB_V1(1) * c02;
          break;
        case 2:
          r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
            UB_V0(2) * c10 + UB_V0(3) * c11 + UB_V1(2) * c12 +
            UB_V0(0) * c00 + UB_V0(1) * c01 + UB_V1(0) * c02;
          r_.i32[i] =
            UB_V0(0) * c10 + UB_V0(1) * c11 + UB_V1(0) * c12;
          break;
        case 3:
          r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
            UB_V0(2) * c00 + UB_V0(3) * c01 + UB_V1(2) * c02;
          r_.i32[i] =
            UB_V0(2) * c10 + UB_V0(3) * c11 + UB_V1(2) * c12 +
            UB_V0(0) * c00 + UB_V0(1) * c01 + UB_V1(0) * c02;
          break;
      }

      #undef UB_V0
      #undef UB_V1
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_v6mpy_WubWbI_v
  #define Q6_Ww_v6mpy_WubWbI_v(Vuu, Vvv, Iu2) simde_Q6_Ww_v6mpy_WubWbI_v((Vuu), (Vvv), (Iu2))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_v6mpy_WubWbI_h(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv, int32_t Iu2) SIMDE_REQUIRE_CONSTANT_RANGE(Iu2, 0, 3) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    switch (Iu2 & 3) {
      case 0: return Q6_Ww_v6mpy_WubWbI_h(Vuu, Vvv, 0);
      case 1: return Q6_Ww_v6mpy_WubWbI_h(Vuu, Vvv, 1);
      case 2: return Q6_Ww_v6mpy_WubWbI_h(Vuu, Vvv, 2);
      case 3: return Q6_Ww_v6mpy_WubWbI_h(Vuu, Vvv, 3);
    }
    HEDLEY_UNREACHABLE();
  #else
    simde_hvx_vectorpair_private
      r_,
      pu_ = simde_hvx_vectorpair_to_private(Vuu),
      pv_ = simde_hvx_vectorpair_to_private(Vvv);

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int16_t c00 = simde_v6mpy_coeff_(pv_.u32[i], 0);
      int16_t c01 = simde_v6mpy_coeff_(pv_.u32[i], 1);
      int16_t c02 = simde_v6mpy_coeff_(pv_.u32[i], 2);
      int16_t c10 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 0);
      int16_t c11 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 1);
      int16_t c12 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 2);

      #define UB_V0(n) HEDLEY_STATIC_CAST(int32_t, pu_.u8[4 * i + (n)])
      #define UB_V1(n) HEDLEY_STATIC_CAST(int32_t, pu_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + (n)])

      switch (Iu2 & 3) {
        case 0:
          r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
            UB_V1(3) * c10 + UB_V1(1) * c11 + UB_V0(3) * c12 +
            UB_V1(2) * c00 + UB_V1(0) * c01 + UB_V0(2) * c02;
          r_.i32[i] =
            UB_V1(2) * c10 + UB_V1(0) * c11 + UB_V0(2) * c12;
          break;
        case 1:
          r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
            UB_V1(3) * c00 + UB_V1(1) * c01 + UB_V0(3) * c02;
          r_.i32[i] =
            UB_V1(3) * c10 + UB_V1(1) * c11 + UB_V0(3) * c12 +
            UB_V1(2) * c00 + UB_V1(0) * c01 + UB_V0(2) * c02;
          break;
        case 2:
          r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
            UB_V1(1) * c10 + UB_V0(3) * c11 + UB_V0(1) * c12 +
            UB_V1(0) * c00 + UB_V0(2) * c01 + UB_V0(0) * c02;
          r_.i32[i] =
            UB_V1(0) * c10 + UB_V0(2) * c11 + UB_V0(0) * c12;
          break;
        case 3:
          r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] =
            UB_V1(1) * c00 + UB_V0(3) * c01 + UB_V0(1) * c02;
          r_.i32[i] =
            UB_V1(1) * c10 + UB_V0(3) * c11 + UB_V0(1) * c12 +
            UB_V1(0) * c00 + UB_V0(2) * c01 + UB_V0(0) * c02;
          break;
      }

      #undef UB_V0
      #undef UB_V1
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_v6mpy_WubWbI_h
  #define Q6_Ww_v6mpy_WubWbI_h(Vuu, Vvv, Iu2) simde_Q6_Ww_v6mpy_WubWbI_h((Vuu), (Vvv), (Iu2))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_v6mpyacc_WwWubWbI_v(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv, int32_t Iu2) SIMDE_REQUIRE_CONSTANT_RANGE(Iu2, 0, 3) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    switch (Iu2 & 3) {
      case 0: return Q6_Ww_v6mpyacc_WwWubWbI_v(Vxx, Vuu, Vvv, 0);
      case 1: return Q6_Ww_v6mpyacc_WwWubWbI_v(Vxx, Vuu, Vvv, 1);
      case 2: return Q6_Ww_v6mpyacc_WwWubWbI_v(Vxx, Vuu, Vvv, 2);
      case 3: return Q6_Ww_v6mpyacc_WwWubWbI_v(Vxx, Vuu, Vvv, 3);
    }
    HEDLEY_UNREACHABLE();
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      pu_ = simde_hvx_vectorpair_to_private(Vuu),
      pv_ = simde_hvx_vectorpair_to_private(Vvv);

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int16_t c00 = simde_v6mpy_coeff_(pv_.u32[i], 0);
      int16_t c01 = simde_v6mpy_coeff_(pv_.u32[i], 1);
      int16_t c02 = simde_v6mpy_coeff_(pv_.u32[i], 2);
      int16_t c10 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 0);
      int16_t c11 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 1);
      int16_t c12 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 2);

      #define UB_V0(n) HEDLEY_STATIC_CAST(int32_t, pu_.u8[4 * i + (n)])
      #define UB_V1(n) HEDLEY_STATIC_CAST(int32_t, pu_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + (n)])

      switch (Iu2 & 3) {
        case 0:
          r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
            UB_V0(3) * c10 + UB_V1(2) * c11 + UB_V1(3) * c12 +
            UB_V0(1) * c00 + UB_V1(0) * c01 + UB_V1(1) * c02;
          r_.u32[i] +=
            UB_V0(1) * c10 + UB_V1(0) * c11 + UB_V1(1) * c12;
          break;
        case 1:
          r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
            UB_V0(3) * c00 + UB_V1(2) * c01 + UB_V1(3) * c02;
          r_.u32[i] +=
            UB_V0(3) * c10 + UB_V1(2) * c11 + UB_V1(3) * c12 +
            UB_V0(1) * c00 + UB_V1(0) * c01 + UB_V1(1) * c02;
          break;
        case 2:
          r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
            UB_V0(2) * c10 + UB_V0(3) * c11 + UB_V1(2) * c12 +
            UB_V0(0) * c00 + UB_V0(1) * c01 + UB_V1(0) * c02;
          r_.u32[i] +=
            UB_V0(0) * c10 + UB_V0(1) * c11 + UB_V1(0) * c12;
          break;
        case 3:
          r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
            UB_V0(2) * c00 + UB_V0(3) * c01 + UB_V1(2) * c02;
          r_.u32[i] +=
            UB_V0(2) * c10 + UB_V0(3) * c11 + UB_V1(2) * c12 +
            UB_V0(0) * c00 + UB_V0(1) * c01 + UB_V1(0) * c02;
          break;
      }

      #undef UB_V0
      #undef UB_V1
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_v6mpyacc_WwWubWbI_v
  #define Q6_Ww_v6mpyacc_WwWubWbI_v(Vxx, Vuu, Vvv, Iu2) simde_Q6_Ww_v6mpyacc_WwWubWbI_v((Vxx), (Vuu), (Vvv), (Iu2))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_v6mpyacc_WwWubWbI_h(simde_hvx_vectorpair_t Vxx, simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv, int32_t Iu2) SIMDE_REQUIRE_CONSTANT_RANGE(Iu2, 0, 3) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    switch (Iu2 & 3) {
      case 0: return Q6_Ww_v6mpyacc_WwWubWbI_h(Vxx, Vuu, Vvv, 0);
      case 1: return Q6_Ww_v6mpyacc_WwWubWbI_h(Vxx, Vuu, Vvv, 1);
      case 2: return Q6_Ww_v6mpyacc_WwWubWbI_h(Vxx, Vuu, Vvv, 2);
      case 3: return Q6_Ww_v6mpyacc_WwWubWbI_h(Vxx, Vuu, Vvv, 3);
    }
    HEDLEY_UNREACHABLE();
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx),
      pu_ = simde_hvx_vectorpair_to_private(Vuu),
      pv_ = simde_hvx_vectorpair_to_private(Vvv);

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int16_t c00 = simde_v6mpy_coeff_(pv_.u32[i], 0);
      int16_t c01 = simde_v6mpy_coeff_(pv_.u32[i], 1);
      int16_t c02 = simde_v6mpy_coeff_(pv_.u32[i], 2);
      int16_t c10 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 0);
      int16_t c11 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 1);
      int16_t c12 = simde_v6mpy_coeff_(pv_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i], 2);

      #define UB_V0(n) HEDLEY_STATIC_CAST(int32_t, pu_.u8[4 * i + (n)])
      #define UB_V1(n) HEDLEY_STATIC_CAST(int32_t, pu_.u8[SIMDE_HVX_VECTOR_SIZE + 4 * i + (n)])

      switch (Iu2 & 3) {
        case 0:
          r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
            UB_V1(3) * c10 + UB_V1(1) * c11 + UB_V0(3) * c12 +
            UB_V1(2) * c00 + UB_V1(0) * c01 + UB_V0(2) * c02;
          r_.u32[i] +=
            UB_V1(2) * c10 + UB_V1(0) * c11 + UB_V0(2) * c12;
          break;
        case 1:
          r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
            UB_V1(3) * c00 + UB_V1(1) * c01 + UB_V0(3) * c02;
          r_.u32[i] +=
            UB_V1(3) * c10 + UB_V1(1) * c11 + UB_V0(3) * c12 +
            UB_V1(2) * c00 + UB_V1(0) * c01 + UB_V0(2) * c02;
          break;
        case 2:
          r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
            UB_V1(1) * c10 + UB_V0(3) * c11 + UB_V0(1) * c12 +
            UB_V1(0) * c00 + UB_V0(2) * c01 + UB_V0(0) * c02;
          r_.u32[i] +=
            UB_V1(0) * c10 + UB_V0(2) * c11 + UB_V0(0) * c12;
          break;
        case 3:
          r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + i] +=
            UB_V1(1) * c00 + UB_V0(3) * c01 + UB_V0(1) * c02;
          r_.u32[i] +=
            UB_V1(1) * c10 + UB_V0(3) * c11 + UB_V0(1) * c12 +
            UB_V1(0) * c00 + UB_V0(2) * c01 + UB_V0(0) * c02;
          break;
      }

      #undef UB_V0
      #undef UB_V1
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_v6mpyacc_WwWubWbI_h
  #define Q6_Ww_v6mpyacc_WwWubWbI_h(Vxx, Vuu, Vvv, Iu2) simde_Q6_Ww_v6mpyacc_WwWubWbI_h((Vxx), (Vuu), (Vvv), (Iu2))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_V6MPY_H) */
