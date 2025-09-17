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

#if !defined(SIMDE_HEXAGON_HVX_AND_H)
#define SIMDE_HEXAGON_HVX_AND_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector bitwise AND */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_and(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* Note: Hexagon uses Q6_V_vand_VV for bitwise AND */
  /* The exact intrinsic name may vary - this is a placeholder */
  return a & b; /* Assuming vector bitwise operations are supported */
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u64) / sizeof(r_.u64[0])); i++) {
    r_.u64[i] = a_.u64[i] & b_.u64[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

/* Vector bitwise NOT */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_not(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_vnot_V(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u64) / sizeof(r_.u64[0])); i++) {
    r_.u64[i] = ~a_.u64[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_vnot_V
#define Q6_V_vnot_V(a) simde_hvx_not((a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_AND_H) */
