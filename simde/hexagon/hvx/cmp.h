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

#if !defined(SIMDE_HEXAGON_HVX_CMP_H)
#define SIMDE_HEXAGON_HVX_CMP_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector compare equal byte */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pred_t simde_hvx_cmpeq_vb(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Q_vcmp_eq_VbVb(a, b);
#else
  simde_hvx_vector_pred_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    r_.u8[i] = 0;
    for (size_t j = 0; j < 8; j++) {
      size_t elem_idx = i * 8 + j;
      if (elem_idx < 128) {
        if (a_.i8[elem_idx] == b_.i8[elem_idx]) {
          r_.u8[i] |= (1 << j);
        }
      }
    }
  }

  simde_hvx_vector_pred_t result;
  simde_memcpy(&result, &r_, sizeof(result));
  return result;
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Q_vcmp_eq_VbVb
#define Q6_Q_vcmp_eq_VbVb(a, b) simde_hvx_cmpeq_vb((a), (b))
#endif

/* Vector compare greater than byte */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pred_t simde_hvx_cmpgt_vb(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Q_vcmp_gt_VbVb(a, b);
#else
  simde_hvx_vector_pred_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    r_.u8[i] = 0;
    for (size_t j = 0; j < 8; j++) {
      size_t elem_idx = i * 8 + j;
      if (elem_idx < 128) {
        if (a_.i8[elem_idx] > b_.i8[elem_idx]) {
          r_.u8[i] |= (1 << j);
        }
      }
    }
  }

  simde_hvx_vector_pred_t result;
  simde_memcpy(&result, &r_, sizeof(result));
  return result;
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Q_vcmp_gt_VbVb
#define Q6_Q_vcmp_gt_VbVb(a, b) simde_hvx_cmpgt_vb((a), (b))
#endif

/* Vector compare equal halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pred_t simde_hvx_cmpeq_vh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Q_vcmp_eq_VhVh(a, b);
#else
  simde_hvx_vector_pred_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    r_.u16[i] = 0;
    for (size_t j = 0; j < 16; j++) {
      size_t elem_idx = i * 16 + j;
      if (elem_idx < 64) {
        if (a_.i16[elem_idx] == b_.i16[elem_idx]) {
          r_.u16[i] |= (1 << j);
        }
      }
    }
  }

  simde_hvx_vector_pred_t result;
  simde_memcpy(&result, &r_, sizeof(result));
  return result;
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Q_vcmp_eq_VhVh
#define Q6_Q_vcmp_eq_VhVh(a, b) simde_hvx_cmpeq_vh((a), (b))
#endif

/* Vector compare greater than halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pred_t simde_hvx_cmpgt_vh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Q_vcmp_gt_VhVh(a, b);
#else
  simde_hvx_vector_pred_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    r_.u16[i] = 0;
    for (size_t j = 0; j < 16; j++) {
      size_t elem_idx = i * 16 + j;
      if (elem_idx < 64) {
        if (a_.i16[elem_idx] > b_.i16[elem_idx]) {
          r_.u16[i] |= (1 << j);
        }
      }
    }
  }

  simde_hvx_vector_pred_t result;
  simde_memcpy(&result, &r_, sizeof(result));
  return result;
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Q_vcmp_gt_VhVh
#define Q6_Q_vcmp_gt_VhVh(a, b) simde_hvx_cmpgt_vh((a), (b))
#endif

/* Vector compare equal word */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pred_t simde_hvx_cmpeq_vw(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Q_vcmp_eq_VwVw(a, b);
#else
  simde_hvx_vector_pred_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < (sizeof(r_.u32) / sizeof(r_.u32[0])); i++) {
    r_.u32[i] = 0;
    for (size_t j = 0; j < 32; j++) {
      size_t elem_idx = i * 32 + j;
      if (elem_idx < 32) {
        if (a_.i32[elem_idx] == b_.i32[elem_idx]) {
          r_.u32[i] |= (1U << j);
        }
      }
    }
  }

  simde_hvx_vector_pred_t result;
  simde_memcpy(&result, &r_, sizeof(result));
  return result;
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Q_vcmp_eq_VwVw
#define Q6_Q_vcmp_eq_VwVw(a, b) simde_hvx_cmpeq_vw((a), (b))
#endif

/* Vector compare greater than word */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pred_t simde_hvx_cmpgt_vw(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Q_vcmp_gt_VwVw(a, b);
#else
  simde_hvx_vector_pred_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < (sizeof(r_.u32) / sizeof(r_.u32[0])); i++) {
    r_.u32[i] = 0;
    for (size_t j = 0; j < 32; j++) {
      size_t elem_idx = i * 32 + j;
      if (elem_idx < 32) {
        if (a_.i32[elem_idx] > b_.i32[elem_idx]) {
          r_.u32[i] |= (1U << j);
        }
      }
    }
  }

  simde_hvx_vector_pred_t result;
  simde_memcpy(&result, &r_, sizeof(result));
  return result;
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Q_vcmp_gt_VwVw
#define Q6_Q_vcmp_gt_VwVw(a, b) simde_hvx_cmpgt_vw((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_CMP_H) */
