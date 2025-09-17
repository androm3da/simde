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

#if !defined(SIMDE_HEXAGON_HVX_NORM_H)
#define SIMDE_HEXAGON_HVX_NORM_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Arithmetic shift left halfwords by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vasl_h_r(simde_hvx_vector_t v, int32_t shift_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vasl_VhR(v, shift_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Clamp shift amount to valid range */
  shift_amount = shift_amount & 0x1F; /* 5-bit mask for 32-bit range */
  if (shift_amount >= 16)
    shift_amount = 15; /* Clamp to halfword bit width */

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    if (shift_amount == 0) {
      r_.i16[i] = v_.i16[i];
    } else {
      /* Arithmetic left shift */
      r_.i16[i] = (int16_t)((int32_t)v_.i16[i] << shift_amount);
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vasl_VhR
#define Q6_Vh_vasl_VhR(v, shift) simde_hvx_vasl_h_r((v), (shift))
#endif

/* Arithmetic shift right halfwords by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vasr_h_r(simde_hvx_vector_t v, int32_t shift_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vasr_VhR(v, shift_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Clamp shift amount to valid range */
  shift_amount = shift_amount & 0x1F; /* 5-bit mask */
  if (shift_amount >= 16)
    shift_amount = 15; /* Clamp to halfword bit width */

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    if (shift_amount == 0) {
      r_.i16[i] = v_.i16[i];
    } else {
      /* Arithmetic right shift preserves sign */
      r_.i16[i] = (int16_t)(v_.i16[i] >> shift_amount);
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vasr_VhR
#define Q6_Vh_vasr_VhR(v, shift) simde_hvx_vasr_h_r((v), (shift))
#endif

/* Arithmetic shift left words by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vasl_w_r(simde_hvx_vector_t v, int32_t shift_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vasl_VwR(v, shift_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Clamp shift amount to valid range */
  shift_amount = shift_amount & 0x1F; /* 5-bit mask for word shifts */

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    if (shift_amount == 0) {
      r_.i32[i] = v_.i32[i];
    } else if (shift_amount >= 32) {
      r_.i32[i] = 0; /* Shifted out of range */
    } else {
      /* Arithmetic left shift */
      r_.i32[i] = v_.i32[i] << shift_amount;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vasl_VwR
#define Q6_Vw_vasl_VwR(v, shift) simde_hvx_vasl_w_r((v), (shift))
#endif

/* Arithmetic shift right words by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vasr_w_r(simde_hvx_vector_t v, int32_t shift_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vasr_VwR(v, shift_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Clamp shift amount to valid range */
  shift_amount = shift_amount & 0x1F; /* 5-bit mask */

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    if (shift_amount == 0) {
      r_.i32[i] = v_.i32[i];
    } else if (shift_amount >= 32) {
      /* Sign extend for arithmetic shift */
      r_.i32[i] = (v_.i32[i] < 0) ? -1 : 0;
    } else {
      /* Arithmetic right shift preserves sign */
      r_.i32[i] = v_.i32[i] >> shift_amount;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vasr_VwR
#define Q6_Vw_vasr_VwR(v, shift) simde_hvx_vasr_w_r((v), (shift))
#endif

/* Logical shift right unsigned halfwords by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vlsr_uh_r(simde_hvx_vector_t v, int32_t shift_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vlsr_VuhR(v, shift_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Clamp shift amount to valid range */
  shift_amount = shift_amount & 0x1F; /* 5-bit mask */
  if (shift_amount >= 16)
    shift_amount = 16; /* Allow full clear */

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    if (shift_amount == 0) {
      r_.u16[i] = v_.u16[i];
    } else if (shift_amount >= 16) {
      r_.u16[i] = 0; /* Shifted out completely */
    } else {
      /* Logical right shift - no sign extension */
      r_.u16[i] = v_.u16[i] >> shift_amount;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vlsr_VuhR
#define Q6_Vuh_vlsr_VuhR(v, shift) simde_hvx_vlsr_uh_r((v), (shift))
#endif

/* Logical shift right unsigned words by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vlsr_uw_r(simde_hvx_vector_t v, int32_t shift_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuw_vlsr_VuwR(v, shift_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Clamp shift amount to valid range */
  shift_amount = shift_amount & 0x1F; /* 5-bit mask */

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u32) / sizeof(r_.u32[0])); i++) {
    if (shift_amount == 0) {
      r_.u32[i] = v_.u32[i];
    } else if (shift_amount >= 32) {
      r_.u32[i] = 0; /* Shifted out completely */
    } else {
      /* Logical right shift - no sign extension */
      r_.u32[i] = v_.u32[i] >> shift_amount;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuw_vlsr_VuwR
#define Q6_Vuw_vlsr_VuwR(v, shift) simde_hvx_vlsr_uw_r((v), (shift))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_NORM_H) */
