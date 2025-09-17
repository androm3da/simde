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

#if !defined(SIMDE_HEXAGON_HVX_ABS_H)
#define SIMDE_HEXAGON_HVX_ABS_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector absolute value byte */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_abs_vb(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vabs_Vb(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])); i++) {
    r_.i8[i] = (a_.i8[i] < 0) ? -a_.i8[i] : a_.i8[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vabs_Vb
#define Q6_Vb_vabs_Vb(a) simde_hvx_abs_vb((a))
#endif

/* Vector absolute value byte with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_abs_vb_sat(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vabs_Vb_sat(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])); i++) {
    if (a_.i8[i] == INT8_MIN) {
      r_.i8[i] = INT8_MAX; /* Saturate -128 to 127 */
    } else {
      r_.i8[i] = (a_.i8[i] < 0) ? -a_.i8[i] : a_.i8[i];
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vabs_Vb_sat
#define Q6_Vb_vabs_Vb_sat(a) simde_hvx_abs_vb_sat((a))
#endif

/* Vector absolute value halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_abs_vh(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vabs_Vh(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    r_.i16[i] = (a_.i16[i] < 0) ? -a_.i16[i] : a_.i16[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vabs_Vh
#define Q6_Vh_vabs_Vh(a) simde_hvx_abs_vh((a))
#endif

/* Vector absolute value halfword with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_abs_vh_sat(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vabs_Vh_sat(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    if (a_.i16[i] == INT16_MIN) {
      r_.i16[i] = INT16_MAX; /* Saturate */
    } else {
      r_.i16[i] = (a_.i16[i] < 0) ? -a_.i16[i] : a_.i16[i];
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vabs_Vh_sat
#define Q6_Vh_vabs_Vh_sat(a) simde_hvx_abs_vh_sat((a))
#endif

/* Vector absolute value word */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_abs_vw(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vabs_Vw(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    r_.i32[i] = (a_.i32[i] < 0) ? -a_.i32[i] : a_.i32[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vabs_Vw
#define Q6_Vw_vabs_Vw(a) simde_hvx_abs_vw((a))
#endif

/* Vector absolute value word with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_abs_vw_sat(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vabs_Vw_sat(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    if (a_.i32[i] == INT32_MIN) {
      r_.i32[i] = INT32_MAX; /* Saturate */
    } else {
      r_.i32[i] = (a_.i32[i] < 0) ? -a_.i32[i] : a_.i32[i];
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vabs_Vw_sat
#define Q6_Vw_vabs_Vw_sat(a) simde_hvx_abs_vw_sat((a))
#endif

/* Vector absolute difference unsigned byte */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_absdiff_vub(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vabsdiff_VubVub(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    r_.u8[i] = (a_.u8[i] > b_.u8[i]) ? (a_.u8[i] - b_.u8[i]) : (b_.u8[i] - a_.u8[i]);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vabsdiff_VubVub
#define Q6_Vub_vabsdiff_VubVub(a, b) simde_hvx_absdiff_vub((a), (b))
#endif

/* Vector absolute difference unsigned halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_absdiff_vuh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vabsdiff_VuhVuh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    r_.u16[i] = (a_.u16[i] > b_.u16[i]) ? (a_.u16[i] - b_.u16[i]) : (b_.u16[i] - a_.u16[i]);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vabsdiff_VuhVuh
#define Q6_Vuh_vabsdiff_VuhVuh(a, b) simde_hvx_absdiff_vuh((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_ABS_H) */
