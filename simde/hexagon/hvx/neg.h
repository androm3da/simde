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

#if !defined(SIMDE_HEXAGON_HVX_NEG_H)
#define SIMDE_HEXAGON_HVX_NEG_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector negate byte */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_neg_vb(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vneg_Vb(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])); i++) {
    r_.i8[i] = -a_.i8[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vneg_Vb
#define Q6_Vb_vneg_Vb(a) simde_hvx_neg_vb((a))
#endif

/* Vector negate halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_neg_vh(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vneg_Vh(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    r_.i16[i] = -a_.i16[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vneg_Vh
#define Q6_Vh_vneg_Vh(a) simde_hvx_neg_vh((a))
#endif

/* Vector negate word */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_neg_vw(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vneg_Vw(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    r_.i32[i] = -a_.i32[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vneg_Vw
#define Q6_Vw_vneg_Vw(a) simde_hvx_neg_vw((a))
#endif

/* Vector negate with saturation byte */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_neg_vb_sat(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vneg_Vb_sat(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])); i++) {
    if (a_.i8[i] == INT8_MIN) {
      r_.i8[i] = INT8_MAX; /* Saturate -128 to 127 */
    } else {
      r_.i8[i] = -a_.i8[i];
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vneg_Vb_sat
#define Q6_Vb_vneg_Vb_sat(a) simde_hvx_neg_vb_sat((a))
#endif

/* Vector negate with saturation halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_neg_vh_sat(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vneg_Vh_sat(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    if (a_.i16[i] == INT16_MIN) {
      r_.i16[i] = INT16_MAX; /* Saturate */
    } else {
      r_.i16[i] = -a_.i16[i];
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vneg_Vh_sat
#define Q6_Vh_vneg_Vh_sat(a) simde_hvx_neg_vh_sat((a))
#endif

/* Vector negate with saturation word */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_neg_vw_sat(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vneg_Vw_sat(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    if (a_.i32[i] == INT32_MIN) {
      r_.i32[i] = INT32_MAX; /* Saturate */
    } else {
      r_.i32[i] = -a_.i32[i];
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vneg_Vw_sat
#define Q6_Vw_vneg_Vw_sat(a) simde_hvx_neg_vw_sat((a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_NEG_H) */
