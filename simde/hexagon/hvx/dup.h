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

#if !defined(SIMDE_HEXAGON_HVX_DUP_H)
#define SIMDE_HEXAGON_HVX_DUP_H

#include "../types.h"
#include <string.h>

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Broadcast 32-bit scalar to all vector elements */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vsplat_w(int32_t scalar) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_vsplat_R(scalar);
#else
  simde_hvx_vector_private r_;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    r_.i32[i] = scalar;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_vsplat_R
#define Q6_V_vsplat_R(scalar) simde_hvx_vsplat_w((scalar))
#endif

/* Broadcast 16-bit scalar to all halfword elements */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vsplat_h(int16_t scalar) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vsplat_R((int32_t)scalar);
#else
  simde_hvx_vector_private r_;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    r_.i16[i] = scalar;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vsplat_R
#define Q6_Vh_vsplat_R(scalar) simde_hvx_vsplat_h((int16_t)(scalar))
#endif

/* Broadcast 8-bit scalar to all byte elements */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vsplat_b(int8_t scalar) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vsplat_R((int32_t)scalar);
#else
  simde_hvx_vector_private r_;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])); i++) {
    r_.i8[i] = scalar;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vsplat_R
#define Q6_Vb_vsplat_R(scalar) simde_hvx_vsplat_b((int8_t)(scalar))
#endif

/* Create vector of all zeros */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vzero(void) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_vzero();
#else
  simde_hvx_vector_private r_;
  memset(&r_, 0, sizeof(r_));
  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_vzero
#define Q6_V_vzero() simde_hvx_vzero()
#endif

/* Combine two vectors into vector pair (first function for pair support) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_t simde_hvx_vcombine(simde_hvx_vector_t hi, simde_hvx_vector_t lo) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_W_vcombine_VV(hi, lo);
#else
  simde_hvx_vector_pair_private r_;
  r_.val[0] = lo;
  r_.val[1] = hi;
  return simde_hvx_vector_pair_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_W_vcombine_VV
#define Q6_W_vcombine_VV(hi, lo) simde_hvx_vcombine((hi), (lo))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_DUP_H) */
