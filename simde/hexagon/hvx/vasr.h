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

#if !defined(SIMDE_HEXAGON_HVX_VASR_H)
#define SIMDE_HEXAGON_HVX_VASR_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vasr_VhR(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vasr_VhR(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int shift = Rt & 15;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = a_.i16[i] >> shift;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vasr_VhR
  #define Q6_Vh_vasr_VhR(Vu, Rt) simde_Q6_Vh_vasr_VhR((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vasr_VwR(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vasr_VwR(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int shift = Rt & 31;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = a_.i32[i] >> shift;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vasr_VwR
  #define Q6_Vw_vasr_VwR(Vu, Rt) simde_Q6_Vw_vasr_VwR((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vasr_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vasr_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int shift = ((HEDLEY_STATIC_CAST(int, b_.i16[i]) & 0x1F) ^ 0x10) - 0x10;
      if (shift >= 0) {
        r_.i16[i] = (shift >= 16) ? (a_.i16[i] >> 15) : (a_.i16[i] >> shift);
      } else {
        int lshift = -shift;
        r_.i16[i] = (lshift >= 16) ? 0 : HEDLEY_STATIC_CAST(int16_t, a_.u16[i] << lshift);
      }
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vasr_VhVh
  #define Q6_Vh_vasr_VhVh(Vu, Vv) simde_Q6_Vh_vasr_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vasr_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vasr_VwVw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int shift = ((HEDLEY_STATIC_CAST(int, b_.i32[i]) & 0x3F) ^ 0x20) - 0x20;
      if (shift >= 0) {
        r_.i32[i] = (shift >= 32) ? (a_.i32[i] >> 31) : (a_.i32[i] >> shift);
      } else {
        int lshift = -shift;
        r_.i32[i] = (lshift >= 32) ? 0 : HEDLEY_STATIC_CAST(int32_t, a_.u32[i] << lshift);
      }
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vasr_VwVw
  #define Q6_Vw_vasr_VwVw(Vu, Vv) simde_Q6_Vw_vasr_VwVw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vasr_VwVwR(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vasr_VwVwR(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0xF;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i16[2 * i]     = HEDLEY_STATIC_CAST(int16_t, b_.i32[i] >> shift);
      r_.i16[2 * i + 1] = HEDLEY_STATIC_CAST(int16_t, a_.i32[i] >> shift);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vasr_VwVwR
  #define Q6_Vh_vasr_VwVwR(Vu, Vv, Rt) simde_Q6_Vh_vasr_VwVwR((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vasr_VwVwR_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vasr_VwVwR_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0xF;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int32_t vv = b_.i32[i] >> shift;
      int32_t vu = a_.i32[i] >> shift;
      r_.i16[2 * i]     = (vv > INT16_MAX) ? INT16_MAX : ((vv < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, vv));
      r_.i16[2 * i + 1] = (vu > INT16_MAX) ? INT16_MAX : ((vu < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vasr_VwVwR_sat
  #define Q6_Vh_vasr_VwVwR_sat(Vu, Vv, Rt) simde_Q6_Vh_vasr_VwVwR_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vasr_VwVwR_rnd_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vasr_VwVwR_rnd_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0xF;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t vvr = HEDLEY_STATIC_CAST(int64_t, b_.i32[i]);
      int64_t vur = HEDLEY_STATIC_CAST(int64_t, a_.i32[i]);
      if (shift > 0) {
        vvr = (vvr + (1LL << (shift - 1))) >> shift;
        vur = (vur + (1LL << (shift - 1))) >> shift;
      }
      r_.i16[2 * i]     = (vvr > INT16_MAX) ? INT16_MAX : ((vvr < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, vvr));
      r_.i16[2 * i + 1] = (vur > INT16_MAX) ? INT16_MAX : ((vur < INT16_MIN) ? INT16_MIN : HEDLEY_STATIC_CAST(int16_t, vur));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vasr_VwVwR_rnd_sat
  #define Q6_Vh_vasr_VwVwR_rnd_sat(Vu, Vv, Rt) simde_Q6_Vh_vasr_VwVwR_rnd_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vasr_VwVwR_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vasr_VwVwR_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0xF;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int32_t vv = b_.i32[i] >> shift;
      int32_t vu = a_.i32[i] >> shift;
      r_.u16[2 * i]     = (vv > HEDLEY_STATIC_CAST(int32_t, UINT16_MAX)) ? UINT16_MAX : ((vv < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, vv));
      r_.u16[2 * i + 1] = (vu > HEDLEY_STATIC_CAST(int32_t, UINT16_MAX)) ? UINT16_MAX : ((vu < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vasr_VwVwR_sat
  #define Q6_Vuh_vasr_VwVwR_sat(Vu, Vv, Rt) simde_Q6_Vuh_vasr_VwVwR_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vasr_VwVwR_rnd_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vasr_VwVwR_rnd_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0xF;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t vvr = HEDLEY_STATIC_CAST(int64_t, b_.i32[i]);
      int64_t vur = HEDLEY_STATIC_CAST(int64_t, a_.i32[i]);
      if (shift > 0) {
        vvr = (vvr + (1LL << (shift - 1))) >> shift;
        vur = (vur + (1LL << (shift - 1))) >> shift;
      }
      r_.u16[2 * i]     = (vvr > UINT16_MAX) ? UINT16_MAX : ((vvr < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, vvr));
      r_.u16[2 * i + 1] = (vur > UINT16_MAX) ? UINT16_MAX : ((vur < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, vur));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vasr_VwVwR_rnd_sat
  #define Q6_Vuh_vasr_VwVwR_rnd_sat(Vu, Vv, Rt) simde_Q6_Vuh_vasr_VwVwR_rnd_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vasr_VhVhR_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vasr_VhVhR_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0x7;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int16_t vv = b_.i16[i] >> shift;
      int16_t vu = a_.i16[i] >> shift;
      r_.i8[2 * i]     = (vv > INT8_MAX) ? INT8_MAX : ((vv < INT8_MIN) ? INT8_MIN : HEDLEY_STATIC_CAST(int8_t, vv));
      r_.i8[2 * i + 1] = (vu > INT8_MAX) ? INT8_MAX : ((vu < INT8_MIN) ? INT8_MIN : HEDLEY_STATIC_CAST(int8_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vasr_VhVhR_sat
  #define Q6_Vb_vasr_VhVhR_sat(Vu, Vv, Rt) simde_Q6_Vb_vasr_VhVhR_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vasr_VhVhR_rnd_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vasr_VhVhR_rnd_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0x7;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int32_t vvr = HEDLEY_STATIC_CAST(int32_t, b_.i16[i]);
      int32_t vur = HEDLEY_STATIC_CAST(int32_t, a_.i16[i]);
      if (shift > 0) {
        vvr = (vvr + (1 << (shift - 1))) >> shift;
        vur = (vur + (1 << (shift - 1))) >> shift;
      }
      r_.i8[2 * i]     = (vvr > INT8_MAX) ? INT8_MAX : ((vvr < INT8_MIN) ? INT8_MIN : HEDLEY_STATIC_CAST(int8_t, vvr));
      r_.i8[2 * i + 1] = (vur > INT8_MAX) ? INT8_MAX : ((vur < INT8_MIN) ? INT8_MIN : HEDLEY_STATIC_CAST(int8_t, vur));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vasr_VhVhR_rnd_sat
  #define Q6_Vb_vasr_VhVhR_rnd_sat(Vu, Vv, Rt) simde_Q6_Vb_vasr_VhVhR_rnd_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vasr_VhVhR_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vasr_VhVhR_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0x7;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int16_t vv = b_.i16[i] >> shift;
      int16_t vu = a_.i16[i] >> shift;
      r_.u8[2 * i]     = (vv > UINT8_MAX) ? UINT8_MAX : ((vv < 0) ? 0 : HEDLEY_STATIC_CAST(uint8_t, vv));
      r_.u8[2 * i + 1] = (vu > UINT8_MAX) ? UINT8_MAX : ((vu < 0) ? 0 : HEDLEY_STATIC_CAST(uint8_t, vu));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vasr_VhVhR_sat
  #define Q6_Vub_vasr_VhVhR_sat(Vu, Vv, Rt) simde_Q6_Vub_vasr_VhVhR_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vasr_VhVhR_rnd_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vasr_VhVhR_rnd_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0x7;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int32_t vvr = HEDLEY_STATIC_CAST(int32_t, b_.i16[i]);
      int32_t vur = HEDLEY_STATIC_CAST(int32_t, a_.i16[i]);
      if (shift > 0) {
        vvr = (vvr + (1 << (shift - 1))) >> shift;
        vur = (vur + (1 << (shift - 1))) >> shift;
      }
      r_.u8[2 * i]     = (vvr > UINT8_MAX) ? UINT8_MAX : ((vvr < 0) ? 0 : HEDLEY_STATIC_CAST(uint8_t, vvr));
      r_.u8[2 * i + 1] = (vur > UINT8_MAX) ? UINT8_MAX : ((vur < 0) ? 0 : HEDLEY_STATIC_CAST(uint8_t, vur));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vasr_VhVhR_rnd_sat
  #define Q6_Vub_vasr_VhVhR_rnd_sat(Vu, Vv, Rt) simde_Q6_Vub_vasr_VhVhR_rnd_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vasr_VuwVuwR_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vasr_VuwVuwR_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0xF;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint32_t vv = b_.u32[i] >> shift;
      uint32_t vu = a_.u32[i] >> shift;
      r_.u16[2 * i]     = (vv > UINT16_MAX) ? UINT16_MAX : HEDLEY_STATIC_CAST(uint16_t, vv);
      r_.u16[2 * i + 1] = (vu > UINT16_MAX) ? UINT16_MAX : HEDLEY_STATIC_CAST(uint16_t, vu);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vasr_VuwVuwR_sat
  #define Q6_Vuh_vasr_VuwVuwR_sat(Vu, Vv, Rt) simde_Q6_Vuh_vasr_VuwVuwR_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vasr_VuwVuwR_rnd_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vasr_VuwVuwR_rnd_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0xF;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint64_t vvr = HEDLEY_STATIC_CAST(uint64_t, b_.u32[i]);
      uint64_t vur = HEDLEY_STATIC_CAST(uint64_t, a_.u32[i]);
      if (shift > 0) {
        vvr = (vvr + (1ULL << (shift - 1))) >> shift;
        vur = (vur + (1ULL << (shift - 1))) >> shift;
      }
      r_.u16[2 * i]     = (vvr > UINT16_MAX) ? UINT16_MAX : HEDLEY_STATIC_CAST(uint16_t, vvr);
      r_.u16[2 * i + 1] = (vur > UINT16_MAX) ? UINT16_MAX : HEDLEY_STATIC_CAST(uint16_t, vur);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vasr_VuwVuwR_rnd_sat
  #define Q6_Vuh_vasr_VuwVuwR_rnd_sat(Vu, Vv, Rt) simde_Q6_Vuh_vasr_VuwVuwR_rnd_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vasr_VuhVuhR_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vasr_VuhVuhR_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0x7;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint16_t vv = b_.u16[i] >> shift;
      uint16_t vu = a_.u16[i] >> shift;
      r_.u8[2 * i]     = (vv > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, vv);
      r_.u8[2 * i + 1] = (vu > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, vu);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vasr_VuhVuhR_sat
  #define Q6_Vub_vasr_VuhVuhR_sat(Vu, Vv, Rt) simde_Q6_Vub_vasr_VuhVuhR_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vasr_VuhVuhR_rnd_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vasr_VuhVuhR_rnd_sat(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    int shift = Rt & 0x7;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint32_t vvr = HEDLEY_STATIC_CAST(uint32_t, b_.u16[i]);
      uint32_t vur = HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]);
      if (shift > 0) {
        vvr = (vvr + (1u << (shift - 1))) >> shift;
        vur = (vur + (1u << (shift - 1))) >> shift;
      }
      r_.u8[2 * i]     = (vvr > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, vvr);
      r_.u8[2 * i + 1] = (vur > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, vur);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vasr_VuhVuhR_rnd_sat
  #define Q6_Vub_vasr_VuhVuhR_rnd_sat(Vu, Vv, Rt) simde_Q6_Vub_vasr_VuhVuhR_rnd_sat((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vasr_WuhVub_sat(simde_hvx_vectorpair_t Vuu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vub_vasr_WuhVub_sat)
    return Q6_Vub_vasr_WuhVub_sat(Vuu, Vv);
  #else
    simde_hvx_vectorpair_private p_ = simde_hvx_vectorpair_to_private(Vuu);
    simde_hvx_vector_private
      r_,
      v_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      unsigned shift_lo = v_.u8[2 * i] & 0x7;
      unsigned shift_hi = v_.u8[2 * i + 1] & 0x7;
      uint16_t lo_val = p_.u16[i] >> shift_lo;
      uint16_t hi_val = p_.u16[SIMDE_HVX_VECTOR_I16_COUNT + i] >> shift_hi;
      r_.u8[2 * i]     = (lo_val > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, lo_val);
      r_.u8[2 * i + 1] = (hi_val > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, hi_val);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vasr_WuhVub_sat
  #define Q6_Vub_vasr_WuhVub_sat(Vuu, Vv) simde_Q6_Vub_vasr_WuhVub_sat((Vuu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vasr_WuhVub_rnd_sat(simde_hvx_vectorpair_t Vuu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vub_vasr_WuhVub_rnd_sat)
    return Q6_Vub_vasr_WuhVub_rnd_sat(Vuu, Vv);
  #else
    simde_hvx_vectorpair_private p_ = simde_hvx_vectorpair_to_private(Vuu);
    simde_hvx_vector_private
      r_,
      v_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      unsigned shift_lo = v_.u8[2 * i] & 0x7;
      unsigned shift_hi = v_.u8[2 * i + 1] & 0x7;
      uint32_t lo_val = HEDLEY_STATIC_CAST(uint32_t, p_.u16[i]);
      uint32_t hi_val = HEDLEY_STATIC_CAST(uint32_t, p_.u16[SIMDE_HVX_VECTOR_I16_COUNT + i]);
      if (shift_lo > 0) lo_val = (lo_val + (1u << (shift_lo - 1))) >> shift_lo;
      if (shift_hi > 0) hi_val = (hi_val + (1u << (shift_hi - 1))) >> shift_hi;
      r_.u8[2 * i]     = (lo_val > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, lo_val);
      r_.u8[2 * i + 1] = (hi_val > UINT8_MAX) ? UINT8_MAX : HEDLEY_STATIC_CAST(uint8_t, hi_val);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vasr_WuhVub_rnd_sat
  #define Q6_Vub_vasr_WuhVub_rnd_sat(Vuu, Vv) simde_Q6_Vub_vasr_WuhVub_rnd_sat((Vuu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vasr_WwVuh_sat(simde_hvx_vectorpair_t Vuu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vuh_vasr_WwVuh_sat)
    return Q6_Vuh_vasr_WwVuh_sat(Vuu, Vv);
  #else
    simde_hvx_vectorpair_private p_ = simde_hvx_vectorpair_to_private(Vuu);
    simde_hvx_vector_private
      r_,
      v_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint16_t shift_lo = v_.u16[2 * i];
      uint16_t shift_hi = v_.u16[2 * i + 1];
      int32_t lo_val = p_.i32[i] >> (shift_lo & 15);
      int32_t hi_val = p_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] >> (shift_hi & 15);
      r_.u16[2 * i]     = (lo_val > HEDLEY_STATIC_CAST(int32_t, UINT16_MAX)) ? UINT16_MAX : ((lo_val < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, lo_val));
      r_.u16[2 * i + 1] = (hi_val > HEDLEY_STATIC_CAST(int32_t, UINT16_MAX)) ? UINT16_MAX : ((hi_val < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, hi_val));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vasr_WwVuh_sat
  #define Q6_Vuh_vasr_WwVuh_sat(Vuu, Vv) simde_Q6_Vuh_vasr_WwVuh_sat((Vuu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vasr_WwVuh_rnd_sat(simde_hvx_vectorpair_t Vuu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vuh_vasr_WwVuh_rnd_sat)
    return Q6_Vuh_vasr_WwVuh_rnd_sat(Vuu, Vv);
  #else
    simde_hvx_vectorpair_private p_ = simde_hvx_vectorpair_to_private(Vuu);
    simde_hvx_vector_private
      r_,
      v_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint16_t shift_lo = v_.u16[2 * i] & 15;
      uint16_t shift_hi = v_.u16[2 * i + 1] & 15;
      int64_t lo_val = HEDLEY_STATIC_CAST(int64_t, p_.i32[i]);
      int64_t hi_val = HEDLEY_STATIC_CAST(int64_t, p_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i]);
      if (shift_lo > 0) lo_val = (lo_val + (1LL << (shift_lo - 1))) >> shift_lo;
      if (shift_hi > 0) hi_val = (hi_val + (1LL << (shift_hi - 1))) >> shift_hi;
      r_.u16[2 * i]     = (lo_val > UINT16_MAX) ? UINT16_MAX : ((lo_val < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, lo_val));
      r_.u16[2 * i + 1] = (hi_val > UINT16_MAX) ? UINT16_MAX : ((hi_val < 0) ? 0 : HEDLEY_STATIC_CAST(uint16_t, hi_val));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vasr_WwVuh_rnd_sat
  #define Q6_Vuh_vasr_WwVuh_rnd_sat(Vuu, Vv) simde_Q6_Vuh_vasr_WwVuh_rnd_sat((Vuu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vasracc_VwVwR(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vasracc_VwVwR(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int shift = Rt & 31;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = x_.u32[i] + HEDLEY_STATIC_CAST(uint32_t, a_.i32[i] >> shift);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vasracc_VwVwR
  #define Q6_Vw_vasracc_VwVwR(Vx, Vu, Rt) simde_Q6_Vw_vasracc_VwVwR((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vasracc_VhVhR(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vasracc_VhVhR(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int shift = Rt & 15;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, x_.u16[i] + HEDLEY_STATIC_CAST(uint16_t, a_.i16[i] >> shift));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vasracc_VhVhR
  #define Q6_Vh_vasracc_VhVhR(Vx, Vu, Rt) simde_Q6_Vh_vasracc_VhVhR((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vasrinto_WwVwVw(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vasrinto_WwVwVw(Vxx, Vu, Vv);
  #else
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      /* ISA: shift = Vu.w[i] << 32 (sign-extended to 64 bits, placed in upper half) */
      uint64_t shift = HEDLEY_STATIC_CAST(uint64_t, HEDLEY_STATIC_CAST(int64_t, a_.i32[i])) << 32;
      /* ISA: mask = Vxx as 64-bit value (hi:lo) */
      uint64_t mask = (HEDLEY_STATIC_CAST(uint64_t, HEDLEY_STATIC_CAST(uint32_t, r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i])) << 32) |
                      HEDLEY_STATIC_CAST(uint64_t, HEDLEY_STATIC_CAST(uint32_t, r_.i32[i]));
      uint64_t lomask = UINT64_C(0xFFFFFFFF);
      int32_t raw_shift = b_.i32[i];
      int count = HEDLEY_STATIC_CAST(int, -(raw_shift & 0x40) + (raw_shift & 0x3f));
      uint64_t result;
      if (count == -64) {
        result = 0;
      } else if (count < 0) {
        int lcount = -count;
        result = (shift << lcount) | (mask & (lomask << lcount));
      } else {
        /* arithmetic right shift of signed shift value */
        int64_t sshift = HEDLEY_STATIC_CAST(int64_t, shift);
        result = HEDLEY_STATIC_CAST(uint64_t, sshift >> count) | (mask & (lomask >> count));
      }
      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + i] = HEDLEY_STATIC_CAST(int32_t, (result >> 32) & UINT64_C(0xFFFFFFFF));
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, result & UINT64_C(0xFFFFFFFF));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vasrinto_WwVwVw
  #define Q6_Ww_vasrinto_WwVwVw(Vxx, Vu, Vv) simde_Q6_Ww_vasrinto_WwVwVw((Vxx), (Vu), (Vv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VASR_H) */
