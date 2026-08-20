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

#if !defined(SIMDE_HEXAGON_HVX_VABS_H)
#define SIMDE_HEXAGON_HVX_VABS_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vabs_Vb(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vabs_Vb(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.i8[i] = (a_.i8[i] < 0) ? HEDLEY_STATIC_CAST(int8_t, -a_.i8[i]) : a_.i8[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vabs_Vb
  #define Q6_Vb_vabs_Vb(Vu) simde_Q6_Vb_vabs_Vb((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vabs_Vb_sat(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vabs_Vb_sat(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.i8[i] = (a_.i8[i] == INT8_MIN) ? INT8_MAX : ((a_.i8[i] < 0) ? HEDLEY_STATIC_CAST(int8_t, -a_.i8[i]) : a_.i8[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vabs_Vb_sat
  #define Q6_Vb_vabs_Vb_sat(Vu) simde_Q6_Vb_vabs_Vb_sat((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vabs_Vh(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vabs_Vh(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = (a_.i16[i] < 0) ? HEDLEY_STATIC_CAST(int16_t, -a_.i16[i]) : a_.i16[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vabs_Vh
  #define Q6_Vh_vabs_Vh(Vu) simde_Q6_Vh_vabs_Vh((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vabs_Vh_sat(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vabs_Vh_sat(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = (a_.i16[i] == INT16_MIN) ? INT16_MAX : ((a_.i16[i] < 0) ? HEDLEY_STATIC_CAST(int16_t, -a_.i16[i]) : a_.i16[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vabs_Vh_sat
  #define Q6_Vh_vabs_Vh_sat(Vu) simde_Q6_Vh_vabs_Vh_sat((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vabs_Vw(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vabs_Vw(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = (a_.i32[i] < 0) ? HEDLEY_STATIC_CAST(int32_t, 0u - HEDLEY_STATIC_CAST(uint32_t, a_.i32[i])) : a_.i32[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vabs_Vw
  #define Q6_Vw_vabs_Vw(Vu) simde_Q6_Vw_vabs_Vw((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vabs_Vw_sat(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vabs_Vw_sat(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = (a_.i32[i] == INT32_MIN) ? INT32_MAX : ((a_.i32[i] < 0) ? -a_.i32[i] : a_.i32[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vabs_Vw_sat
  #define Q6_Vw_vabs_Vw_sat(Vu) simde_Q6_Vw_vabs_Vw_sat((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vabsdiff_VubVub(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vub_vabsdiff_VubVub(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? HEDLEY_STATIC_CAST(uint8_t, a_.u8[i] - b_.u8[i]) : HEDLEY_STATIC_CAST(uint8_t, b_.u8[i] - a_.u8[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vabsdiff_VubVub
  #define Q6_Vub_vabsdiff_VubVub(Vu, Vv) simde_Q6_Vub_vabsdiff_VubVub((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vabsdiff_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vabsdiff_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, (a_.i16[i] > b_.i16[i]) ? (a_.i16[i] - b_.i16[i]) : (b_.i16[i] - a_.i16[i]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vabsdiff_VhVh
  #define Q6_Vuh_vabsdiff_VhVh(Vu, Vv) simde_Q6_Vuh_vabsdiff_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vabsdiff_VuhVuh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuh_vabsdiff_VuhVuh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] = (a_.u16[i] > b_.u16[i]) ? HEDLEY_STATIC_CAST(uint16_t, a_.u16[i] - b_.u16[i]) : HEDLEY_STATIC_CAST(uint16_t, b_.u16[i] - a_.u16[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vabsdiff_VuhVuh
  #define Q6_Vuh_vabsdiff_VuhVuh(Vu, Vv) simde_Q6_Vuh_vabsdiff_VuhVuh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuw_vabsdiff_VwVw(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuw_vabsdiff_VwVw(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t diff = HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) - HEDLEY_STATIC_CAST(int64_t, b_.i32[i]);
      r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, (diff < 0) ? -diff : diff);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuw_vabsdiff_VwVw
  #define Q6_Vuw_vabsdiff_VwVw(Vu, Vv) simde_Q6_Vuw_vabsdiff_VwVw((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vhf_vabs_Vhf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vhf_vabs_Vhf)
    return Q6_Vhf_vabs_Vhf(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] = a_.u16[i] & UINT16_C(0x7FFF);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vhf_vabs_Vhf
  #define Q6_Vhf_vabs_Vhf(Vu) simde_Q6_Vhf_vabs_Vhf((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vsf_vabs_Vsf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vsf_vabs_Vsf)
    return Q6_Vsf_vabs_Vsf(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = a_.u32[i] & UINT32_C(0x7FFFFFFF);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vsf_vabs_Vsf
  #define Q6_Vsf_vabs_Vsf(Vu) simde_Q6_Vsf_vabs_Vsf((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vabs_V(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_V_vabs_V)
    return Q6_V_vabs_V(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = a_.u8[i] & 0x7Fu;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vabs_V
  #define Q6_V_vabs_V(Vu) simde_Q6_V_vabs_V((Vu))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VABS_H) */
