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

#if !defined(SIMDE_HEXAGON_HVX_VLUT_H)
#define SIMDE_HEXAGON_HVX_VLUT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vlut32_VbVbR(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vlut32_VbVbR(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      idx_ = simde_hvx_vector_to_private(Vu),
      tbl_ = simde_hvx_vector_to_private(Vv);

    uint8_t matchval = HEDLEY_STATIC_CAST(uint8_t, Rt & 0x7);
    uint8_t oddhalf = HEDLEY_STATIC_CAST(uint8_t, (Rt >> (SIMDE_HVX_VECTOR_SIZE >> 7)) & 0x1);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      uint8_t idx = idx_.u8[i];
      size_t hw_idx = idx & (HEDLEY_STATIC_CAST(size_t, SIMDE_HVX_VECTOR_I16_COUNT) - 1);
      if ((idx & 0xE0) == HEDLEY_STATIC_CAST(uint8_t, matchval << 5))
        r_.u8[i] = tbl_.u8[hw_idx * 2 + oddhalf];
      else
        r_.u8[i] = 0;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vlut32_VbVbR
  #define Q6_Vb_vlut32_VbVbR(Vu, Vv, Rt) simde_Q6_Vb_vlut32_VbVbR((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vlut32_VbVbI(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Iu3) SIMDE_REQUIRE_CONSTANT_RANGE(Iu3, 0, 7) {
  return simde_Q6_Vb_vlut32_VbVbR(Vu, Vv, Iu3);
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vlut32_VbVbI
  #define Q6_Vb_vlut32_VbVbI(Vu, Vv, Iu3) simde_Q6_Vb_vlut32_VbVbI((Vu), (Vv), (Iu3))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vlut32_VbVbR_nomatch(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vlut32_VbVbR_nomatch(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      idx_ = simde_hvx_vector_to_private(Vu),
      tbl_ = simde_hvx_vector_to_private(Vv);

    uint8_t matchval = HEDLEY_STATIC_CAST(uint8_t, Rt & 0x7);
    uint8_t oddhalf = HEDLEY_STATIC_CAST(uint8_t, (Rt >> (SIMDE_HVX_VECTOR_SIZE >> 7)) & 0x1);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      uint8_t idx = HEDLEY_STATIC_CAST(uint8_t, (idx_.u8[i] & 0x1F) | HEDLEY_STATIC_CAST(uint8_t, matchval << 5));
      size_t hw_idx = idx & (HEDLEY_STATIC_CAST(size_t, SIMDE_HVX_VECTOR_I16_COUNT) - 1);
      r_.u8[i] = tbl_.u8[hw_idx * 2 + oddhalf];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vlut32_VbVbR_nomatch
  #define Q6_Vb_vlut32_VbVbR_nomatch(Vu, Vv, Rt) simde_Q6_Vb_vlut32_VbVbR_nomatch((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vlut32or_VbVbVbR(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vlut32or_VbVbVbR(Vx, Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_ = simde_hvx_vector_to_private(Vx),
      idx_ = simde_hvx_vector_to_private(Vu),
      tbl_ = simde_hvx_vector_to_private(Vv);

    uint8_t matchval = HEDLEY_STATIC_CAST(uint8_t, Rt & 0x7);
    uint8_t oddhalf = HEDLEY_STATIC_CAST(uint8_t, (Rt >> (SIMDE_HVX_VECTOR_SIZE >> 7)) & 0x1);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      uint8_t idx = idx_.u8[i];
      size_t hw_idx = idx & (HEDLEY_STATIC_CAST(size_t, SIMDE_HVX_VECTOR_I16_COUNT) - 1);
      if ((idx & 0xE0) == HEDLEY_STATIC_CAST(uint8_t, matchval << 5))
        r_.u8[i] |= tbl_.u8[hw_idx * 2 + oddhalf];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vlut32or_VbVbVbR
  #define Q6_Vb_vlut32or_VbVbVbR(Vx, Vu, Vv, Rt) simde_Q6_Vb_vlut32or_VbVbVbR((Vx), (Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vlut32or_VbVbVbI(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Iu3) SIMDE_REQUIRE_CONSTANT_RANGE(Iu3, 0, 7) {
  return simde_Q6_Vb_vlut32or_VbVbVbR(Vx, Vu, Vv, Iu3);
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vlut32or_VbVbVbI
  #define Q6_Vb_vlut32or_VbVbVbI(Vx, Vu, Vv, Iu3) simde_Q6_Vb_vlut32or_VbVbVbI((Vx), (Vu), (Vv), (Iu3))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vlut16_VbVhR(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vlut16_VbVhR(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      idx_ = simde_hvx_vector_to_private(Vu),
      tbl_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    uint8_t matchval = HEDLEY_STATIC_CAST(uint8_t, Rt & 0xF);
    uint8_t oddhalf = HEDLEY_STATIC_CAST(uint8_t, (Rt >> (SIMDE_HVX_VECTOR_SIZE >> 7)) & 0x1);

    /* Computed-index stores directly into r_.i16 (a vector_size member) miscompile
     * at -O2/-O3 with some Hexagon cross-compiler versions; stage through a plain
     * array and copy the result in afterward. */
    int16_t tmp[SIMDE_HVX_PAIR_SIZE / HEDLEY_STATIC_CAST(int, sizeof(int16_t))];

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t idx0 = idx_.u8[2 * i];
      uint8_t idx1 = idx_.u8[2 * i + 1];
      size_t w_idx0 = idx0 & (HEDLEY_STATIC_CAST(size_t, SIMDE_HVX_VECTOR_I32_COUNT) - 1);
      size_t w_idx1 = idx1 & (HEDLEY_STATIC_CAST(size_t, SIMDE_HVX_VECTOR_I32_COUNT) - 1);

      tmp[i] = ((idx0 & 0xF0) == HEDLEY_STATIC_CAST(uint8_t, matchval << 4))
        ? tbl_.i16[w_idx0 * 2 + oddhalf] : 0;
      tmp[SIMDE_HVX_VECTOR_I16_COUNT + i] = ((idx1 & 0xF0) == HEDLEY_STATIC_CAST(uint8_t, matchval << 4))
        ? tbl_.i16[w_idx1 * 2 + oddhalf] : 0;
    }
    simde_memcpy(&r_, tmp, sizeof(tmp));

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vlut16_VbVhR
  #define Q6_Wh_vlut16_VbVhR(Vu, Vv, Rt) simde_Q6_Wh_vlut16_VbVhR((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vlut16_VbVhI(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Iu3) SIMDE_REQUIRE_CONSTANT_RANGE(Iu3, 0, 7) {
  return simde_Q6_Wh_vlut16_VbVhR(Vu, Vv, Iu3);
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vlut16_VbVhI
  #define Q6_Wh_vlut16_VbVhI(Vu, Vv, Iu3) simde_Q6_Wh_vlut16_VbVhI((Vu), (Vv), (Iu3))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vlut16_VbVhR_nomatch(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vlut16_VbVhR_nomatch(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      idx_ = simde_hvx_vector_to_private(Vu),
      tbl_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    uint8_t matchval = HEDLEY_STATIC_CAST(uint8_t, Rt & 0xF);
    uint8_t oddhalf = HEDLEY_STATIC_CAST(uint8_t, (Rt >> (SIMDE_HVX_VECTOR_SIZE >> 7)) & 0x1);

    /* Computed-index stores directly into r_.i16 (a vector_size member) miscompile
     * at -O2/-O3 with some Hexagon cross-compiler versions; stage through a plain
     * array and copy the result in afterward. */
    int16_t tmp[SIMDE_HVX_PAIR_SIZE / HEDLEY_STATIC_CAST(int, sizeof(int16_t))];

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t idx0 = HEDLEY_STATIC_CAST(uint8_t, (idx_.u8[2 * i] & 0x0F) | HEDLEY_STATIC_CAST(uint8_t, matchval << 4));
      uint8_t idx1 = HEDLEY_STATIC_CAST(uint8_t, (idx_.u8[2 * i + 1] & 0x0F) | HEDLEY_STATIC_CAST(uint8_t, matchval << 4));
      size_t w_idx0 = idx0 & (HEDLEY_STATIC_CAST(size_t, SIMDE_HVX_VECTOR_I32_COUNT) - 1);
      size_t w_idx1 = idx1 & (HEDLEY_STATIC_CAST(size_t, SIMDE_HVX_VECTOR_I32_COUNT) - 1);

      tmp[i] = tbl_.i16[w_idx0 * 2 + oddhalf];
      tmp[SIMDE_HVX_VECTOR_I16_COUNT + i] = tbl_.i16[w_idx1 * 2 + oddhalf];
    }
    simde_memcpy(&r_, tmp, sizeof(tmp));

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vlut16_VbVhR_nomatch
  #define Q6_Wh_vlut16_VbVhR_nomatch(Vu, Vv, Rt) simde_Q6_Wh_vlut16_VbVhR_nomatch((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vlut16or_WhVbVhR(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vlut16or_WhVbVhR(Vxx, Vu, Vv, Rt);
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx);
    simde_hvx_vector_private
      idx_ = simde_hvx_vector_to_private(Vu),
      tbl_ = simde_hvx_vector_to_private(Vv);

    uint8_t matchval = HEDLEY_STATIC_CAST(uint8_t, Rt & 0xF);
    uint8_t oddhalf = HEDLEY_STATIC_CAST(uint8_t, (Rt >> (SIMDE_HVX_VECTOR_SIZE >> 7)) & 0x1);

    /* Computed-index stores directly into r_.i16 (a vector_size member) miscompile
     * at -O2/-O3 with some Hexagon cross-compiler versions; stage through a plain
     * array and copy the result in afterward. */
    int16_t tmp[SIMDE_HVX_PAIR_SIZE / HEDLEY_STATIC_CAST(int, sizeof(int16_t))];
    simde_memcpy(tmp, &r_, sizeof(tmp));

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint8_t idx0 = idx_.u8[2 * i];
      uint8_t idx1 = idx_.u8[2 * i + 1];
      size_t w_idx0 = idx0 & (HEDLEY_STATIC_CAST(size_t, SIMDE_HVX_VECTOR_I32_COUNT) - 1);
      size_t w_idx1 = idx1 & (HEDLEY_STATIC_CAST(size_t, SIMDE_HVX_VECTOR_I32_COUNT) - 1);

      if ((idx0 & 0xF0) == HEDLEY_STATIC_CAST(uint8_t, matchval << 4))
        tmp[i] |= tbl_.i16[w_idx0 * 2 + oddhalf];
      if ((idx1 & 0xF0) == HEDLEY_STATIC_CAST(uint8_t, matchval << 4))
        tmp[SIMDE_HVX_VECTOR_I16_COUNT + i] |= tbl_.i16[w_idx1 * 2 + oddhalf];
    }
    simde_memcpy(&r_, tmp, sizeof(tmp));

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vlut16or_WhVbVhR
  #define Q6_Wh_vlut16or_WhVbVhR(Vxx, Vu, Vv, Rt) simde_Q6_Wh_vlut16or_WhVbVhR((Vxx), (Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vlut16or_WhVbVhI(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Iu3) SIMDE_REQUIRE_CONSTANT_RANGE(Iu3, 0, 7) {
  return simde_Q6_Wh_vlut16or_WhVbVhR(Vxx, Vu, Vv, Iu3);
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vlut16or_WhVbVhI
  #define Q6_Wh_vlut16or_WhVbVhI(Vxx, Vu, Vv, Iu3) simde_Q6_Wh_vlut16or_WhVbVhI((Vxx), (Vu), (Vv), (Iu3))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vlut4_VuhPh(simde_hvx_vector_t Vu, int64_t Rtt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vlut4_VuhPh(Vu, Rtt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int16_t tbl[4];
    tbl[0] = HEDLEY_STATIC_CAST(int16_t, Rtt & 0xFFFF);
    tbl[1] = HEDLEY_STATIC_CAST(int16_t, (Rtt >> 16) & 0xFFFF);
    tbl[2] = HEDLEY_STATIC_CAST(int16_t, (Rtt >> 32) & 0xFFFF);
    tbl[3] = HEDLEY_STATIC_CAST(int16_t, (Rtt >> 48) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint16_t idx = (a_.u16[i] >> 14) & 3;
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, tbl[idx]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vlut4_VuhPh
  #define Q6_Vh_vlut4_VuhPh(Vu, Rtt) simde_Q6_Vh_vlut4_VuhPh((Vu), (Rtt))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VLUT_H) */
