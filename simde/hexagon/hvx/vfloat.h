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

#if !defined(SIMDE_HEXAGON_HVX_VFLOAT_H)
#define SIMDE_HEXAGON_HVX_VFLOAT_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vhf_vfmax_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vhf_vfmax_VhfVhf)
    return Q6_Vhf_vfmax_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 af = simde_float16_to_float32(a_.f16[i]);
      simde_float32 bf = simde_float16_to_float32(b_.f16[i]);
      simde_float32 rf;
      if ((af != af) || (bf != bf)) rf = SIMDE_MATH_NANF;
      else if ((af == 0.0f) && (bf == 0.0f)) {
        r_.u16[i] = (a_.u16[i] & b_.u16[i]) & UINT16_C(0x8000);
        continue;
      }
      else rf = (af > bf) ? af : bf;
      r_.f16[i] = simde_float16_from_float32(rf);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vhf_vfmax_VhfVhf
  #define Q6_Vhf_vfmax_VhfVhf(Vu, Vv) simde_Q6_Vhf_vfmax_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vsf_vfmax_VsfVsf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vsf_vfmax_VsfVsf)
    return Q6_Vsf_vfmax_VsfVsf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      simde_float32 af = a_.f32[i], bf = b_.f32[i];
      if ((af != af) || (bf != bf)) r_.f32[i] = SIMDE_MATH_NANF;
      else if ((af == 0.0f) && (bf == 0.0f)) r_.u32[i] = (a_.u32[i] & b_.u32[i]) & UINT32_C(0x80000000);
      else r_.f32[i] = (af > bf) ? af : bf;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vsf_vfmax_VsfVsf
  #define Q6_Vsf_vfmax_VsfVsf(Vu, Vv) simde_Q6_Vsf_vfmax_VsfVsf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vhf_vfmin_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vhf_vfmin_VhfVhf)
    return Q6_Vhf_vfmin_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      simde_float32 af = simde_float16_to_float32(a_.f16[i]);
      simde_float32 bf = simde_float16_to_float32(b_.f16[i]);
      simde_float32 rf;
      if ((af != af) || (bf != bf)) rf = SIMDE_MATH_NANF;
      else if ((af == 0.0f) && (bf == 0.0f)) {
        r_.u16[i] = (a_.u16[i] | b_.u16[i]) & UINT16_C(0x8000);
        continue;
      }
      else rf = (af < bf) ? af : bf;
      r_.f16[i] = simde_float16_from_float32(rf);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vhf_vfmin_VhfVhf
  #define Q6_Vhf_vfmin_VhfVhf(Vu, Vv) simde_Q6_Vhf_vfmin_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vsf_vfmin_VsfVsf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vsf_vfmin_VsfVsf)
    return Q6_Vsf_vfmin_VsfVsf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      simde_float32 af = a_.f32[i], bf = b_.f32[i];
      if ((af != af) || (bf != bf)) r_.f32[i] = SIMDE_MATH_NANF;
      else if ((af == 0.0f) && (bf == 0.0f)) r_.u32[i] = (a_.u32[i] | b_.u32[i]) & UINT32_C(0x80000000);
      else r_.f32[i] = (af < bf) ? af : bf;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vsf_vfmin_VsfVsf
  #define Q6_Vsf_vfmin_VsfVsf(Vu, Vv) simde_Q6_Vsf_vfmin_VsfVsf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vhf_vfneg_Vhf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vhf_vfneg_Vhf)
    return Q6_Vhf_vfneg_Vhf(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u16[i] = a_.u16[i] ^ UINT16_C(0x8000);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vhf_vfneg_Vhf
  #define Q6_Vhf_vfneg_Vhf(Vu) simde_Q6_Vhf_vfneg_Vhf((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vsf_vfneg_Vsf(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vsf_vfneg_Vsf)
    return Q6_Vsf_vfneg_Vsf(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = a_.u32[i] ^ UINT32_C(0x80000000);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vsf_vfneg_Vsf
  #define Q6_Vsf_vfneg_Vsf(Vu) simde_Q6_Vsf_vfneg_Vsf((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vfneg_V(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_V_vfneg_V)
    return Q6_V_vfneg_V(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = a_.u8[i] ^ 0x80u;
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vfneg_V
  #define Q6_V_vfneg_V(Vu) simde_Q6_V_vfneg_V((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vfmax_VV(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_V_vfmax_VV)
    return Q6_V_vfmax_VV(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      simde_float32 af = simde_f8e4m3_to_float32(a_.u8[i]);
      simde_float32 bf = simde_f8e4m3_to_float32(b_.u8[i]);
      if ((af != af) || (bf != bf)) r_.u8[i] = UINT8_C(0x7F);
      else if ((af == 0.0f) && (bf == 0.0f)) r_.u8[i] = (a_.u8[i] & b_.u8[i]) & UINT8_C(0x80);
      else r_.u8[i] = (af >= bf) ? a_.u8[i] : b_.u8[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vfmax_VV
  #define Q6_V_vfmax_VV(Vu, Vv) simde_Q6_V_vfmax_VV((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_V_vfmin_VV(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_V_vfmin_VV)
    return Q6_V_vfmin_VV(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      simde_float32 af = simde_f8e4m3_to_float32(a_.u8[i]);
      simde_float32 bf = simde_f8e4m3_to_float32(b_.u8[i]);
      if ((af != af) || (bf != bf)) r_.u8[i] = UINT8_C(0x7F);
      else if ((af == 0.0f) && (bf == 0.0f)) r_.u8[i] = (a_.u8[i] | b_.u8[i]) & UINT8_C(0x80);
      else r_.u8[i] = (af <= bf) ? a_.u8[i] : b_.u8[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_V_vfmin_VV
  #define Q6_V_vfmin_VV(Vu, Vv) simde_Q6_V_vfmin_VV((Vu), (Vv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VFLOAT_H) */
