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

#if !defined(SIMDE_HEXAGON_HVX_BLEND_H)
#define SIMDE_HEXAGON_HVX_BLEND_H

#include "../types.h"
#include <string.h>

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector multiplexer - conditional element selection */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vmux(simde_hvx_vector_pred_t pred, simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_vmux_QVV(pred, a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);
  simde_hvx_vector_pred_private pred_ = simde_hvx_vector_pred_to_private(pred);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    uint8_t mask_bit = (pred_.u8[i / 8] >> (i % 8)) & 1;
    r_.u8[i] = mask_bit ? a_.u8[i] : b_.u8[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_vmux_QVV
#define Q6_V_vmux_QVV(pred, a, b) simde_hvx_vmux((pred), (a), (b))
#endif

/* Vector AND with predicate - mask elements where predicate is true */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vand_pred(simde_hvx_vector_pred_t pred, simde_hvx_vector_t v) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_vand_QV(pred, v);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);
  simde_hvx_vector_pred_private pred_ = simde_hvx_vector_pred_to_private(pred);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    uint8_t mask_bit = (pred_.u8[i / 8] >> (i % 8)) & 1;
    r_.u8[i] = mask_bit ? v_.u8[i] : 0;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_vand_QV
#define Q6_V_vand_QV(pred, v) simde_hvx_vand_pred((pred), (v))
#endif

/* Vector AND with inverted predicate - mask elements where predicate is false
 */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vand_pred_not(simde_hvx_vector_pred_t pred, simde_hvx_vector_t v) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_vand_QnV(pred, v);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);
  simde_hvx_vector_pred_private pred_ = simde_hvx_vector_pred_to_private(pred);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    uint8_t mask_bit = (pred_.u8[i / 8] >> (i % 8)) & 1;
    r_.u8[i] = mask_bit ? 0 : v_.u8[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_vand_QnV
#define Q6_V_vand_QnV(pred, v) simde_hvx_vand_pred_not((pred), (v))
#endif

/* Byte equality comparison to generate predicate */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pred_t simde_hvx_vcmp_eq_b(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Q_vcmp_eq_VbVb(a, b);
#else
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);
  simde_hvx_vector_pred_private r_;

  memset(&r_, 0, sizeof(r_));

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.u8) / sizeof(a_.u8[0])); i++) {
    if (a_.u8[i] == b_.u8[i]) {
      r_.u8[i / 8] |= (1U << (i % 8));
    }
  }

  return simde_hvx_vector_pred_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Q_vcmp_eq_VbVb
#define Q6_Q_vcmp_eq_VbVb(a, b) simde_hvx_vcmp_eq_b((a), (b))
#endif

/* Byte greater-than comparison to generate predicate */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pred_t simde_hvx_vcmp_gt_b(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Q_vcmp_gt_VbVb(a, b);
#else
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);
  simde_hvx_vector_pred_private r_;

  memset(&r_, 0, sizeof(r_));

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.i8) / sizeof(a_.i8[0])); i++) {
    if (a_.i8[i] > b_.i8[i]) {
      r_.u8[i / 8] |= (1U << (i % 8));
    }
  }

  return simde_hvx_vector_pred_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Q_vcmp_gt_VbVb
#define Q6_Q_vcmp_gt_VbVb(a, b) simde_hvx_vcmp_gt_b((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_BLEND_H) */
