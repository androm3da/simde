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
 *   2024      Brian Cain <brian.cain@oss.qualcomm.com> (Qualcomm Technologies,
 *             Inc. and its subsidiaries)
 */

#if !defined(SIMDE_HEXAGON_HVX_MUL_H)
#define SIMDE_HEXAGON_HVX_MUL_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector multiply byte - produces halfword results */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_t simde_hvx_mul_vb(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Wh_vmpy_VbVb(a, b);
#else
  simde_hvx_vector_pair_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Multiply bytes to produce halfwords (16-bit results) */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.i8) / sizeof(a_.i8[0])); i++) {
    r_.i16[i] = (int16_t)a_.i8[i] * (int16_t)b_.i8[i];
  }

  return simde_hvx_vector_pair_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Wh_vmpy_VbVb
#define Q6_Wh_vmpy_VbVb(a, b) simde_hvx_mul_vb((a), (b))
#endif

/* Vector multiply unsigned byte - produces halfword results */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_t simde_hvx_mul_vub_vb(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Wh_vmpy_VubVb(a, b);
#else
  simde_hvx_vector_pair_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Multiply unsigned bytes by signed bytes to produce halfwords */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.u8) / sizeof(a_.u8[0])); i++) {
    r_.i16[i] = (int16_t)a_.u8[i] * (int16_t)b_.i8[i];
  }

  return simde_hvx_vector_pair_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Wh_vmpy_VubVb
#define Q6_Wh_vmpy_VubVb(a, b) simde_hvx_mul_vub_vb((a), (b))
#endif

/* Vector multiply halfword - produces word results */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_t simde_hvx_mul_vh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Ww_vmpy_VhVh(a, b);
#else
  simde_hvx_vector_pair_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Multiply halfwords to produce words (32-bit results) */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.i16) / sizeof(a_.i16[0])); i++) {
    r_.i32[i] = (int32_t)a_.i16[i] * (int32_t)b_.i16[i];
  }

  return simde_hvx_vector_pair_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Ww_vmpy_VhVh
#define Q6_Ww_vmpy_VhVh(a, b) simde_hvx_mul_vh((a), (b))
#endif

/* Vector multiply halfword by unsigned halfword - produces word results */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_t simde_hvx_mul_vh_vuh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Ww_vmpy_VhVuh(a, b);
#else
  simde_hvx_vector_pair_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Multiply signed halfwords by unsigned halfwords to produce words */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.i16) / sizeof(a_.i16[0])); i++) {
    r_.i32[i] = (int32_t)a_.i16[i] * (int32_t)b_.u16[i];
  }

  return simde_hvx_vector_pair_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Ww_vmpy_VhVuh
#define Q6_Ww_vmpy_VhVuh(a, b) simde_hvx_mul_vh_vuh((a), (b))
#endif

/* Vector multiply halfword with saturation and rounding */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_mul_vh_s1_rnd_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vmpy_VhVh_s1_rnd_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Multiply halfwords with saturation and rounding, shift left by 1 */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.i16) / sizeof(a_.i16[0])); i++) {
    int32_t product = (int32_t)a_.i16[i] * (int32_t)b_.i16[i];
    int32_t shifted = product << 1;
    /* Round by adding 0x8000 then right shift by 16 */
    int32_t rounded = (shifted + 0x8000) >> 16;
    /* Saturate to int16 range */
    if (rounded > INT16_MAX) {
      r_.i16[i] = INT16_MAX;
    } else if (rounded < INT16_MIN) {
      r_.i16[i] = INT16_MIN;
    } else {
      r_.i16[i] = (int16_t)rounded;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vmpy_VhVh_s1_rnd_sat
#define Q6_Vh_vmpy_VhVh_s1_rnd_sat(a, b) simde_hvx_mul_vh_s1_rnd_sat((a), (b))
#endif

/* Vector multiply unsigned halfword with right shift 16 */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_mul_vuh_rs16(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vmpy_VuhVuh_rs16(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Multiply unsigned halfwords and right shift by 16 */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.u16) / sizeof(a_.u16[0])); i++) {
    uint32_t product = (uint32_t)a_.u16[i] * (uint32_t)b_.u16[i];
    r_.u16[i] = (uint16_t)(product >> 16);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vmpy_VuhVuh_rs16
#define Q6_Vuh_vmpy_VuhVuh_rs16(a, b) simde_hvx_mul_vuh_rs16((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_MUL_H) */
