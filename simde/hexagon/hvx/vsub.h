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
 *   2026      Brian Cain <brian.cain@oss.qualcomm.com> (Copyright owned by Qualcomm Technologies, Inc. and its subsidiaries)
 */

#if !defined(SIMDE_HEXAGON_HVX_VSUB_H)
#define SIMDE_HEXAGON_HVX_VSUB_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vsub_VbVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vsub_VbVb(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u8 = a_.u8 - b_.u8;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
        r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, a_.u8[i] - b_.u8[i]);
      }
    #endif

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vsub_VbVb
  #define Q6_Vb_vsub_VbVb(Vu, Vv) simde_Q6_Vb_vsub_VbVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vsub_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vsub_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u16 = a_.u16 - b_.u16;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
        r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, a_.u16[i] - b_.u16[i]);
      }
    #endif

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vsub_VhVh
  #define Q6_Vh_vsub_VhVh(Vu, Vv) simde_Q6_Vh_vsub_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vsub_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vsub_VwVw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    #if defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.u32 = a_.u32 - b_.u32;
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
        r_.u32[i] = a_.u32[i] - b_.u32[i];
      }
    #endif

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vsub_VwVw
  #define Q6_Vw_vsub_VwVw(Vu, Vv) simde_Q6_Vw_vsub_VwVw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vsub_VbVb_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vsub_VbVb_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      int16_t diff = HEDLEY_STATIC_CAST(int16_t, a_.i8[i]) - HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
      if (diff > INT8_MAX) diff = INT8_MAX;
      else if (diff < INT8_MIN) diff = INT8_MIN;
      r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, diff);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vsub_VbVb_sat
  #define Q6_Vb_vsub_VbVb_sat(Vu, Vv) simde_Q6_Vb_vsub_VbVb_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vsub_VhVh_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vsub_VhVh_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int32_t diff = HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) - HEDLEY_STATIC_CAST(int32_t, b_.i16[i]);
      if (diff > INT16_MAX) diff = INT16_MAX;
      else if (diff < INT16_MIN) diff = INT16_MIN;
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, diff);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vsub_VhVh_sat
  #define Q6_Vh_vsub_VhVh_sat(Vu, Vv) simde_Q6_Vh_vsub_VhVh_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vsub_VwVw_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vsub_VwVw_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t diff = HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) - HEDLEY_STATIC_CAST(int64_t, b_.i32[i]);
      if (diff > INT32_MAX) diff = INT32_MAX;
      else if (diff < INT32_MIN) diff = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, diff);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vsub_VwVw_sat
  #define Q6_Vw_vsub_VwVw_sat(Vu, Vv) simde_Q6_Vw_vsub_VwVw_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vsub_VubVub_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vsub_VubVub_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? (a_.u8[i] - b_.u8[i]) : 0;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vsub_VubVub_sat
  #define Q6_Vub_vsub_VubVub_sat(Vu, Vv) simde_Q6_Vub_vsub_VubVub_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vsub_VuhVuh_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vsub_VuhVuh_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] = (a_.u16[i] > b_.u16[i]) ? (a_.u16[i] - b_.u16[i]) : 0;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vsub_VuhVuh_sat
  #define Q6_Vuh_vsub_VuhVuh_sat(Vu, Vv) simde_Q6_Vuh_vsub_VuhVuh_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuw_vsub_VuwVuw_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuw_vsub_VuwVuw_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = (a_.u32[i] > b_.u32[i]) ? (a_.u32[i] - b_.u32[i]) : 0;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuw_vsub_VuwVuw_sat
  #define Q6_Vuw_vsub_VuwVuw_sat(Vu, Vv) simde_Q6_Vuw_vsub_VuwVuw_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wb_vsub_WbWb(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wb_vsub_WbWb(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      a_ = simde_hvx_vectorpair_to_private(Vuu),
      b_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_PAIR_SIZE ; i++) {
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, a_.u8[i] - b_.u8[i]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wb_vsub_WbWb
  #define Q6_Wb_vsub_WbWb(Vuu, Vvv) simde_Q6_Wb_vsub_WbWb((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vsub_WhWh(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vsub_WhWh(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      a_ = simde_hvx_vectorpair_to_private(Vuu),
      b_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_PAIR_I16_COUNT ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, a_.u16[i] - b_.u16[i]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vsub_WhWh
  #define Q6_Wh_vsub_WhWh(Vuu, Vvv) simde_Q6_Wh_vsub_WhWh((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vsub_WwWw(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vsub_WwWw(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      a_ = simde_hvx_vectorpair_to_private(Vuu),
      b_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_PAIR_I32_COUNT ; i++) {
      r_.u32[i] = a_.u32[i] - b_.u32[i];
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vsub_WwWw
  #define Q6_Ww_vsub_WwWw(Vuu, Vvv) simde_Q6_Ww_vsub_WwWw((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wb_vsub_WbWb_sat(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wb_vsub_WbWb_sat(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      a_ = simde_hvx_vectorpair_to_private(Vuu),
      b_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_PAIR_SIZE ; i++) {
      int16_t diff = HEDLEY_STATIC_CAST(int16_t, a_.i8[i]) - HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
      if (diff > INT8_MAX) diff = INT8_MAX;
      else if (diff < INT8_MIN) diff = INT8_MIN;
      r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, diff);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wb_vsub_WbWb_sat
  #define Q6_Wb_vsub_WbWb_sat(Vuu, Vvv) simde_Q6_Wb_vsub_WbWb_sat((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vsub_WhWh_sat(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vsub_WhWh_sat(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      a_ = simde_hvx_vectorpair_to_private(Vuu),
      b_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_PAIR_I16_COUNT ; i++) {
      int32_t diff = HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) - HEDLEY_STATIC_CAST(int32_t, b_.i16[i]);
      if (diff > INT16_MAX) diff = INT16_MAX;
      else if (diff < INT16_MIN) diff = INT16_MIN;
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, diff);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vsub_WhWh_sat
  #define Q6_Wh_vsub_WhWh_sat(Vuu, Vvv) simde_Q6_Wh_vsub_WhWh_sat((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vsub_WwWw_sat(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vsub_WwWw_sat(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      a_ = simde_hvx_vectorpair_to_private(Vuu),
      b_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_PAIR_I32_COUNT ; i++) {
      int64_t diff = HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) - HEDLEY_STATIC_CAST(int64_t, b_.i32[i]);
      if (diff > INT32_MAX) diff = INT32_MAX;
      else if (diff < INT32_MIN) diff = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, diff);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vsub_WwWw_sat
  #define Q6_Ww_vsub_WwWw_sat(Vuu, Vvv) simde_Q6_Ww_vsub_WwWw_sat((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wub_vsub_WubWub_sat(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wub_vsub_WubWub_sat(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      a_ = simde_hvx_vectorpair_to_private(Vuu),
      b_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_PAIR_SIZE ; i++) {
      r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? HEDLEY_STATIC_CAST(uint8_t, a_.u8[i] - b_.u8[i]) : 0;
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wub_vsub_WubWub_sat
  #define Q6_Wub_vsub_WubWub_sat(Vuu, Vvv) simde_Q6_Wub_vsub_WubWub_sat((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuh_vsub_WuhWuh_sat(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuh_vsub_WuhWuh_sat(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      a_ = simde_hvx_vectorpair_to_private(Vuu),
      b_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_PAIR_I16_COUNT ; i++) {
      r_.u16[i] = (a_.u16[i] > b_.u16[i]) ? HEDLEY_STATIC_CAST(uint16_t, a_.u16[i] - b_.u16[i]) : 0;
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuh_vsub_WuhWuh_sat
  #define Q6_Wuh_vsub_WuhWuh_sat(Vuu, Vvv) simde_Q6_Wuh_vsub_WuhWuh_sat((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vsub_WuwWuw_sat(simde_hvx_vectorpair_t Vuu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuw_vsub_WuwWuw_sat(Vuu, Vvv);
  #else
    simde_hvx_vectorpair_private
      r_,
      a_ = simde_hvx_vectorpair_to_private(Vuu),
      b_ = simde_hvx_vectorpair_to_private(Vvv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_PAIR_I32_COUNT ; i++) {
      r_.u32[i] = (a_.u32[i] > b_.u32[i]) ? HEDLEY_STATIC_CAST(uint32_t, a_.u32[i] - b_.u32[i]) : 0;
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vsub_WuwWuw_sat
  #define Q6_Wuw_vsub_WuwWuw_sat(Vuu, Vvv) simde_Q6_Wuw_vsub_WuwWuw_sat((Vuu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vsub_VubVub(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vsub_VubVub(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.i16[j] = HEDLEY_STATIC_CAST(int16_t, HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j]) - HEDLEY_STATIC_CAST(uint16_t, b_.u8[2 * j]));
      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + j] = HEDLEY_STATIC_CAST(int16_t, HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j + 1]) - HEDLEY_STATIC_CAST(uint16_t, b_.u8[2 * j + 1]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vsub_VubVub
  #define Q6_Wh_vsub_VubVub(Vu, Vv) simde_Q6_Wh_vsub_VubVub((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vsub_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vsub_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.i32[j] = HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j]) - HEDLEY_STATIC_CAST(int32_t, b_.i16[2 * j]);
      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + j] = HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j + 1]) - HEDLEY_STATIC_CAST(int32_t, b_.i16[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vsub_VhVh
  #define Q6_Ww_vsub_VhVh(Vu, Vv) simde_Q6_Ww_vsub_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vsub_VuhVuh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vsub_VuhVuh(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.i32[j] = HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * j]) - HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j]));
      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + j] = HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * j + 1]) - HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j + 1]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vsub_VuhVuh
  #define Q6_Ww_vsub_VuhVuh(Vu, Vv) simde_Q6_Ww_vsub_VuhVuh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vsub_VubVb_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vsub_VubVb_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      int16_t diff = HEDLEY_STATIC_CAST(int16_t, a_.u8[i]) - HEDLEY_STATIC_CAST(int16_t, b_.i8[i]);
      if (diff > UINT8_MAX) diff = UINT8_MAX;
      else if (diff < 0) diff = 0;
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, diff);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vsub_VubVb_sat
  #define Q6_Vub_vsub_VubVb_sat(Vu, Vv) simde_Q6_Vub_vsub_VubVb_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vsub_VwVwQ_carry(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, simde_hvx_vectorpred_t* Qx) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vsub_VwVwQ_carry(Vu, Vv, Qx);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(*Qx);
    simde_hvx_vectorpred_private qo_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint32_t carry_in = (q_.u8[i * 4] & 1u);
      uint64_t sum = HEDLEY_STATIC_CAST(uint64_t, a_.u32[i]) + HEDLEY_STATIC_CAST(uint64_t, HEDLEY_STATIC_CAST(uint32_t, ~b_.u32[i])) + carry_in;
      r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, sum);
      uint8_t carry_out = (sum > UINT32_MAX) ? 0xFF : 0x00;
      qo_.u8[i * 4]     = carry_out;
      qo_.u8[i * 4 + 1] = carry_out;
      qo_.u8[i * 4 + 2] = carry_out;
      qo_.u8[i * 4 + 3] = carry_out;
    }

    *Qx = simde_hvx_vectorpred_from_private(qo_);
    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vsub_VwVwQ_carry
  #define Q6_Vw_vsub_VwVwQ_carry(Vu, Vv, Qx) simde_Q6_Vw_vsub_VwVwQ_carry((Vu), (Vv), (Qx))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VSUB_H) */
