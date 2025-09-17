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

#if !defined(SIMDE_HEXAGON_HVX_CVT_H)
#define SIMDE_HEXAGON_HVX_CVT_H

#include "../types.h"
#include <string.h>

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Convert byte to halfword (8-bit to 16-bit) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_cvt_vh_vb(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vsxt_Vb(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  memset(&r_, 0, sizeof(r_));

  size_t max_elements = (sizeof(a_.i8) / sizeof(a_.i8[0]));
  if (max_elements > 64)
    max_elements = 64;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < max_elements; i++) {
    r_.i16[i] = (int16_t)a_.i8[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vsxt_Vb
#define Q6_Vh_vsxt_Vb(a) simde_hvx_cvt_vh_vb((a))
#endif

/* Convert unsigned byte to halfword (8-bit to 16-bit) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_cvt_vuh_vub(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vzxt_Vub(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  memset(&r_, 0, sizeof(r_));

  size_t max_elements_u8 = (sizeof(a_.u8) / sizeof(a_.u8[0]));
  if (max_elements_u8 > 64)
    max_elements_u8 = 64;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < max_elements_u8; i++) {
    r_.u16[i] = (uint16_t)a_.u8[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vzxt_Vub
#define Q6_Vuh_vzxt_Vub(a) simde_hvx_cvt_vuh_vub((a))
#endif

/* Convert halfword to word (16-bit to 32-bit) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_cvt_vw_vh(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vsxt_Vh(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  memset(&r_, 0, sizeof(r_));

  size_t max_elements_i16 = (sizeof(a_.i16) / sizeof(a_.i16[0]));
  if (max_elements_i16 > 32)
    max_elements_i16 = 32;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < max_elements_i16; i++) {
    r_.i32[i] = (int32_t)a_.i16[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vsxt_Vh
#define Q6_Vw_vsxt_Vh(a) simde_hvx_cvt_vw_vh((a))
#endif

/* Convert unsigned halfword to word (16-bit to 32-bit) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_cvt_vuw_vuh(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuw_vzxt_Vuh(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  memset(&r_, 0, sizeof(r_));

  size_t max_elements_u16 = (sizeof(a_.u16) / sizeof(a_.u16[0]));
  if (max_elements_u16 > 32)
    max_elements_u16 = 32;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < max_elements_u16; i++) {
    r_.u32[i] = (uint32_t)a_.u16[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuw_vzxt_Vuh
#define Q6_Vuw_vzxt_Vuh(a) simde_hvx_cvt_vuw_vuh((a))
#endif

/* Convert word to byte with saturation (32-bit to 8-bit) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_cvt_vb_vw_sat(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vsat_VwVw(a, a); /* Using same vector twice for conversion */
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  memset(&r_, 0, sizeof(r_));

  size_t max_elements_i32 = (sizeof(a_.i32) / sizeof(a_.i32[0]));
  if (max_elements_i32 > 32)
    max_elements_i32 = 32;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < max_elements_i32; i++) {
    int32_t val = a_.i32[i];
    if (val > INT8_MAX) {
      r_.i8[i] = INT8_MAX;
    } else if (val < INT8_MIN) {
      r_.i8[i] = INT8_MIN;
    } else {
      r_.i8[i] = (int8_t)val;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

/* Convert halfword to byte with saturation (16-bit to 8-bit) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_cvt_vb_vh_sat(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vsat_VhVh(a, a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  memset(&r_, 0, sizeof(r_));

  size_t max_elements_i16_sat = (sizeof(a_.i16) / sizeof(a_.i16[0]));
  if (max_elements_i16_sat > 64)
    max_elements_i16_sat = 64;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < max_elements_i16_sat; i++) {
    int16_t val = a_.i16[i];
    if (val > INT8_MAX) {
      r_.i8[i] = INT8_MAX;
    } else if (val < INT8_MIN) {
      r_.i8[i] = INT8_MIN;
    } else {
      r_.i8[i] = (int8_t)val;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_CVT_H) */
