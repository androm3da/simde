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

#if !defined(SIMDE_HEXAGON_HVX_DMPY_H)
#define SIMDE_HEXAGON_HVX_DMPY_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Double multiply high halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vdmpy_h_h(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vdmpy_VhVh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    /* Double multiply: multiply by 2 and take high bits */
    int32_t result = ((int32_t)a_.i16[i] * (int32_t)b_.i16[i]) << 1;
    r_.i32[i] = result;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vdmpy_VhVh
#define Q6_Vw_vdmpy_VhVh(a, b) simde_hvx_vdmpy_h_h((a), (b))
#endif

/* Double multiply and accumulate high halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vdmpy_h_h_acc(simde_hvx_vector_t acc, simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vdmpy_VwVhVh(acc, a, b);
#else
  simde_hvx_vector_private r_, acc_ = simde_hvx_vector_to_private(acc), a_ = simde_hvx_vector_to_private(a),
                               b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    /* Double multiply and accumulate */
    int32_t dmpy_result = ((int32_t)a_.i16[i] * (int32_t)b_.i16[i]) << 1;
    r_.i32[i] = acc_.i32[i] + dmpy_result;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vdmpy_VwVhVh
#define Q6_Vw_vdmpy_VwVhVh(acc, a, b) simde_hvx_vdmpy_h_h_acc((acc), (a), (b))
#endif

/* Double multiply saturated halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vdmpy_h_h_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vdmpy_VhVh_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    /* Double multiply with saturation */
    int32_t result = ((int32_t)a_.i16[i] * (int32_t)b_.i16[i]) << 1;

    /* Saturate to 16-bit range */
    if (result > INT16_MAX) {
      r_.i16[i] = INT16_MAX;
    } else if (result < INT16_MIN) {
      r_.i16[i] = INT16_MIN;
    } else {
      r_.i16[i] = (int16_t)result;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vdmpy_VhVh_sat
#define Q6_Vh_vdmpy_VhVh_sat(a, b) simde_hvx_vdmpy_h_h_sat((a), (b))
#endif

/* Complex multiply halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vcmpy_h_h(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vcmpy_VhVh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Complex multiply: (a.re + j*a.im) * (b.re + j*b.im) =
     (a.re*b.re - a.im*b.im) + j*(a.re*b.im + a.im*b.re) */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) / 2; i++) {
    size_t real_idx = i * 2;
    size_t imag_idx = i * 2 + 1;

    int32_t a_real = a_.i16[real_idx];
    int32_t a_imag = a_.i16[imag_idx];
    int32_t b_real = b_.i16[real_idx];
    int32_t b_imag = b_.i16[imag_idx];

    /* Real part: a.re*b.re - a.im*b.im */
    r_.i32[real_idx] = (a_real * b_real) - (a_imag * b_imag);
    /* Imaginary part: a.re*b.im + a.im*b.re */
    r_.i32[imag_idx] = (a_real * b_imag) + (a_imag * b_real);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vcmpy_VhVh
#define Q6_Vw_vcmpy_VhVh(a, b) simde_hvx_vcmpy_h_h((a), (b))
#endif

/* Complex multiply and accumulate halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vcmpy_h_h_acc(simde_hvx_vector_t acc, simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vcmpy_VwVhVh(acc, a, b);
#else
  simde_hvx_vector_private r_, acc_ = simde_hvx_vector_to_private(acc), a_ = simde_hvx_vector_to_private(a),
                               b_ = simde_hvx_vector_to_private(b);

  /* Complex multiply and accumulate */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])) / 2; i++) {
    size_t real_idx = i * 2;
    size_t imag_idx = i * 2 + 1;

    int32_t a_real = a_.i16[real_idx];
    int32_t a_imag = a_.i16[imag_idx];
    int32_t b_real = b_.i16[real_idx];
    int32_t b_imag = b_.i16[imag_idx];

    /* Accumulate complex multiply result */
    r_.i32[real_idx] = acc_.i32[real_idx] + ((a_real * b_real) - (a_imag * b_imag));
    r_.i32[imag_idx] = acc_.i32[imag_idx] + ((a_real * b_imag) + (a_imag * b_real));
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vcmpy_VwVhVh
#define Q6_Vw_vcmpy_VwVhVh(acc, a, b) simde_hvx_vcmpy_h_h_acc((acc), (a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_DMPY_H) */
