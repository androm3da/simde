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

#if !defined(SIMDE_HEXAGON_HVX_SHUFFLE_H)
#define SIMDE_HEXAGON_HVX_SHUFFLE_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Shuffle even bytes */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_shuffle_vb_even(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vshuffe_VbVb(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Take even indexed elements from a and b */
  for (size_t i = 0; i < 64; i++) {
    r_.i8[i * 2] = a_.i8[i * 2];     /* Even indices from a */
    r_.i8[i * 2 + 1] = b_.i8[i * 2]; /* Even indices from b */
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vshuffe_VbVb
#define Q6_Vb_vshuffe_VbVb(a, b) simde_hvx_shuffle_vb_even((a), (b))
#endif

/* Shuffle odd bytes */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_shuffle_vb_odd(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vshuffo_VbVb(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Take odd indexed elements from a and b */
  for (size_t i = 0; i < 64; i++) {
    r_.i8[i * 2] = a_.i8[i * 2 + 1];     /* Odd indices from a */
    r_.i8[i * 2 + 1] = b_.i8[i * 2 + 1]; /* Odd indices from b */
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vshuffo_VbVb
#define Q6_Vb_vshuffo_VbVb(a, b) simde_hvx_shuffle_vb_odd((a), (b))
#endif

/* Shuffle even halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_shuffle_vh_even(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vshuffe_VhVh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Take even indexed elements from a and b */
  for (size_t i = 0; i < 32; i++) {
    r_.i16[i * 2] = a_.i16[i * 2];     /* Even indices from a */
    r_.i16[i * 2 + 1] = b_.i16[i * 2]; /* Even indices from b */
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vshuffe_VhVh
#define Q6_Vh_vshuffe_VhVh(a, b) simde_hvx_shuffle_vh_even((a), (b))
#endif

/* Shuffle odd halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_shuffle_vh_odd(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vshuffo_VhVh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Take odd indexed elements from a and b */
  for (size_t i = 0; i < 32; i++) {
    r_.i16[i * 2] = a_.i16[i * 2 + 1];     /* Odd indices from a */
    r_.i16[i * 2 + 1] = b_.i16[i * 2 + 1]; /* Odd indices from b */
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vshuffo_VhVh
#define Q6_Vh_vshuffo_VhVh(a, b) simde_hvx_shuffle_vh_odd((a), (b))
#endif

/* Deal bytes (deinterleave) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_deal_vb(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vdeal_Vb(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  /* Rearrange bytes: first 64 bytes are even indices, last 64 are odd indices
   */
  for (size_t i = 0; i < 64; i++) {
    r_.i8[i] = a_.i8[i * 2];          /* Even indices */
    r_.i8[i + 64] = a_.i8[i * 2 + 1]; /* Odd indices */
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vdeal_Vb
#define Q6_Vb_vdeal_Vb(a) simde_hvx_deal_vb((a))
#endif

/* Deal halfwords (deinterleave) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_deal_vh(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vdeal_Vh(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  /* Rearrange halfwords: first 32 are even indices, last 32 are odd indices */
  for (size_t i = 0; i < 32; i++) {
    r_.i16[i] = a_.i16[i * 2];          /* Even indices */
    r_.i16[i + 32] = a_.i16[i * 2 + 1]; /* Odd indices */
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vdeal_Vh
#define Q6_Vh_vdeal_Vh(a) simde_hvx_deal_vh((a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_SHUFFLE_H) */
