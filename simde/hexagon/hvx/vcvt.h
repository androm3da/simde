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

#if !defined(SIMDE_HEXAGON_HVX_VCVT_H)
#define SIMDE_HEXAGON_HVX_VCVT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* ---- IEEE float conversions ---- */

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vhf_vcvt_Vh(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vhf_vcvt_Vh)
    return Q6_Vhf_vcvt_Vh(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      r_.f16[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, a_.i16[i]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vhf_vcvt_Vh
  #define Q6_Vhf_vcvt_Vh(Vu) simde_Q6_Vhf_vcvt_Vh((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vhf_vcvt_Vuh(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vhf_vcvt_Vuh)
    return Q6_Vhf_vcvt_Vuh(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      r_.f16[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, a_.u16[i]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vhf_vcvt_Vuh
  #define Q6_Vhf_vcvt_Vuh(Vu) simde_Q6_Vhf_vcvt_Vuh((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vcvt_Vhf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vh_vcvt_Vhf)
    return Q6_Vh_vcvt_Vhf(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(a_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, INT16_MAX)) v = INT16_MAX;
      else if (f < HEDLEY_STATIC_CAST(simde_float32, INT16_MIN)) v = INT16_MIN;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, v);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vcvt_Vhf
  #define Q6_Vh_vcvt_Vhf(Vu) simde_Q6_Vh_vcvt_Vhf((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vcvt_Vhf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vuh_vcvt_Vhf)
    return Q6_Vuh_vcvt_Vhf(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(a_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, UINT16_MAX)) v = UINT16_MAX;
      else if (f < 0.0f) v = 0;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, v);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vcvt_Vhf
  #define Q6_Vuh_vcvt_Vhf(Vu) simde_Q6_Vuh_vcvt_Vhf((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vhf_vcvt_VsfVsf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vhf_vcvt_VsfVsf)
    return Q6_Vhf_vcvt_VsfVsf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      r_.f16[i] = simde_float16_from_float32(b_.f32[i]);
    }
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      r_.f16[SIMDE_HVX_VECTOR_F32_COUNT + i] = simde_float16_from_float32(a_.f32[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vhf_vcvt_VsfVsf
  #define Q6_Vhf_vcvt_VsfVsf(Vu, Vv) simde_Q6_Vhf_vcvt_VsfVsf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wsf_vcvt_Vhf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Wsf_vcvt_Vhf)
    return Q6_Wsf_vcvt_Vhf(Vu);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      r_.f32[i] = simde_float16_to_float32(a_.f16[i]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wsf_vcvt_Vhf
  #define Q6_Wsf_vcvt_Vhf(Vu) simde_Q6_Wsf_vcvt_Vhf((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vcvt_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vb_vcvt_VhfVhf)
    return Q6_Vb_vcvt_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(b_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, INT8_MAX)) v = INT8_MAX;
      else if (f < HEDLEY_STATIC_CAST(simde_float32, INT8_MIN)) v = INT8_MIN;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, v);
    }
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(a_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, INT8_MAX)) v = INT8_MAX;
      else if (f < HEDLEY_STATIC_CAST(simde_float32, INT8_MIN)) v = INT8_MIN;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.i8[SIMDE_HVX_VECTOR_F16_COUNT + i] = HEDLEY_STATIC_CAST(int8_t, v);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vcvt_VhfVhf
  #define Q6_Vb_vcvt_VhfVhf(Vu, Vv) simde_Q6_Vb_vcvt_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vcvt_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vub_vcvt_VhfVhf)
    return Q6_Vub_vcvt_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(b_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, UINT8_MAX)) v = UINT8_MAX;
      else if (f < 0.0f) v = 0;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, v);
    }
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(a_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, UINT8_MAX)) v = UINT8_MAX;
      else if (f < 0.0f) v = 0;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.u8[SIMDE_HVX_VECTOR_F16_COUNT + i] = HEDLEY_STATIC_CAST(uint8_t, v);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vcvt_VhfVhf
  #define Q6_Vub_vcvt_VhfVhf(Vu, Vv) simde_Q6_Vub_vcvt_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Whf_vcvt_Vb(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Whf_vcvt_Vb)
    return Q6_Whf_vcvt_Vb(Vu);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.f16[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, a_.i8[i]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Whf_vcvt_Vb
  #define Q6_Whf_vcvt_Vb(Vu) simde_Q6_Whf_vcvt_Vb((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Whf_vcvt_Vub(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Whf_vcvt_Vub)
    return Q6_Whf_vcvt_Vub(Vu);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.f16[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, a_.u8[i]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Whf_vcvt_Vub
  #define Q6_Whf_vcvt_Vub(Vu) simde_Q6_Whf_vcvt_Vub((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vbf_vcvt_VsfVsf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vbf_vcvt_VsfVsf)
    return Q6_Vbf_vcvt_VsfVsf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      r_.bf16[i] = simde_bfloat16_from_float32(b_.f32[i]);
    }
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      r_.bf16[SIMDE_HVX_VECTOR_F32_COUNT + i] = simde_bfloat16_from_float32(a_.f32[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vbf_vcvt_VsfVsf
  #define Q6_Vbf_vcvt_VsfVsf(Vu, Vv) simde_Q6_Vbf_vcvt_VsfVsf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vcvt2_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vb_vcvt2_VhfVhf)
    return Q6_Vb_vcvt2_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(b_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, INT8_MAX)) v = INT8_MAX;
      else if (f < HEDLEY_STATIC_CAST(simde_float32, INT8_MIN)) v = INT8_MIN;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.i8[i] = HEDLEY_STATIC_CAST(int8_t, v);
    }
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(a_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, INT8_MAX)) v = INT8_MAX;
      else if (f < HEDLEY_STATIC_CAST(simde_float32, INT8_MIN)) v = INT8_MIN;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.i8[SIMDE_HVX_VECTOR_F16_COUNT + i] = HEDLEY_STATIC_CAST(int8_t, v);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vcvt2_VhfVhf
  #define Q6_Vb_vcvt2_VhfVhf(Vu, Vv) simde_Q6_Vb_vcvt2_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vub_vcvt2_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vub_vcvt2_VhfVhf)
    return Q6_Vub_vcvt2_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(b_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, UINT8_MAX)) v = UINT8_MAX;
      else if (f < 0.0f) v = 0;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t, v);
    }
    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(a_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, UINT8_MAX)) v = UINT8_MAX;
      else if (f < 0.0f) v = 0;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.u8[SIMDE_HVX_VECTOR_F16_COUNT + i] = HEDLEY_STATIC_CAST(uint8_t, v);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vub_vcvt2_VhfVhf
  #define Q6_Vub_vcvt2_VhfVhf(Vu, Vv) simde_Q6_Vub_vcvt2_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Whf_vcvt2_Vb(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Whf_vcvt2_Vb)
    return Q6_Whf_vcvt2_Vb(Vu);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.f16[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, a_.i8[i]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Whf_vcvt2_Vb
  #define Q6_Whf_vcvt2_Vb(Vu) simde_Q6_Whf_vcvt2_Vb((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Whf_vcvt2_Vub(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Whf_vcvt2_Vub)
    return Q6_Whf_vcvt2_Vub(Vu);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.f16[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, a_.u8[i]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Whf_vcvt2_Vub
  #define Q6_Whf_vcvt2_Vub(Vu) simde_Q6_Whf_vcvt2_Vub((Vu))
#endif

/* LLVM TableGen confirms the undocumented reverse conversions. */

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vsf_equals_Vw(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vsf_equals_Vw)
    return Q6_Vsf_equals_Vw(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      r_.f32[i] = HEDLEY_STATIC_CAST(simde_float32, a_.i32[i]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vsf_equals_Vw
  #define Q6_Vsf_equals_Vw(Vu) simde_Q6_Vsf_equals_Vw((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_equals_Vsf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vw_equals_Vsf)
    return Q6_Vw_equals_Vsf(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      simde_float32 f = a_.f32[i];
      int64_t v;
      if (f != f) v = 0;
      /* (simde_float32) INT32_MAX rounds up to 2147483648.0f (2^31), which
       * is not > itself, so the comparison must use >= to catch it. */
      else if (f >= HEDLEY_STATIC_CAST(simde_float32, INT32_MAX)) v = INT32_MAX;
      else if (f < HEDLEY_STATIC_CAST(simde_float32, INT32_MIN)) v = INT32_MIN;
      else v = HEDLEY_STATIC_CAST(int64_t, f);
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, v);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_equals_Vsf
  #define Q6_Vw_equals_Vsf(Vu) simde_Q6_Vw_equals_Vsf((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_equals_Vhf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vh_equals_Vhf)
    return Q6_Vh_equals_Vhf(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(a_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else if (f > HEDLEY_STATIC_CAST(simde_float32, INT16_MAX)) v = INT16_MAX;
      else if (f < HEDLEY_STATIC_CAST(simde_float32, INT16_MIN)) v = INT16_MIN;
      else v = HEDLEY_STATIC_CAST(int32_t, f);
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, v);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_equals_Vhf
  #define Q6_Vh_equals_Vhf(Vu) simde_Q6_Vh_equals_Vhf((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_equals_Vhf_rnd(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vh_equals_Vhf_rnd)
    return Q6_Vh_equals_Vhf_rnd(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 f = simde_float16_to_float32(a_.f16[i]);
      int32_t v;
      if (f != f) v = 0;
      else {
        simde_float32 fr = simde_math_nearbyintf(f);
        if (fr > HEDLEY_STATIC_CAST(simde_float32, INT16_MAX)) v = INT16_MAX;
        else if (fr < HEDLEY_STATIC_CAST(simde_float32, INT16_MIN)) v = INT16_MIN;
        else v = HEDLEY_STATIC_CAST(int32_t, fr);
      }
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, v);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_equals_Vhf_rnd
  #define Q6_Vh_equals_Vhf_rnd(Vu) simde_Q6_Vh_equals_Vhf_rnd((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vhf_equals_Vh(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vhf_equals_Vh)
    return Q6_Vhf_equals_Vh(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      r_.f16[i] = simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32, a_.i16[i]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vhf_equals_Vh
  #define Q6_Vhf_equals_Vh(Vu) simde_Q6_Vhf_equals_Vh((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vcvt_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_V_vcvt_VhfVhf)
    return Q6_V_vcvt_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      hi_ = simde_hvx_vector_to_private(Vu),
      lo_ = simde_hvx_vector_to_private(Vv);

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u8[i] = simde_float32_to_f8e4m3(simde_float16_to_float32(lo_.f16[i]));
      r_.u8[SIMDE_HVX_VECTOR_I16_COUNT + i] = simde_float32_to_f8e4m3(simde_float16_to_float32(hi_.f16[i]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vcvt_VhfVhf
  #define Q6_V_vcvt_VhfVhf(Vu, Vv) simde_Q6_V_vcvt_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Whf_vcvt_V(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Whf_vcvt_V)
    return Q6_Whf_vcvt_V(Vu);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.f16[i] = simde_float16_from_float32(simde_f8e4m3_to_float32(a_.u8[i]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Whf_vcvt_V
  #define Q6_Whf_vcvt_V(Vu) simde_Q6_Whf_vcvt_V((Vu))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VCVT_H) */
