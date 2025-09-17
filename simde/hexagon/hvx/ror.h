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

#if !defined(SIMDE_HEXAGON_HVX_ROR_H)
#define SIMDE_HEXAGON_HVX_ROR_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Rotate right bytes by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vror_b_r(simde_hvx_vector_t v, int32_t rotate_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vror_VbR(v, rotate_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Normalize rotate amount to 0-7 range for 8-bit values */
  rotate_amount = rotate_amount & 0x7;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    uint8_t val = v_.u8[i];
    r_.u8[i] = (val >> rotate_amount) | (val << (8 - rotate_amount));
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vror_VbR
#define Q6_Vb_vror_VbR(v, rotate) simde_hvx_vror_b_r((v), (rotate))
#endif

/* Rotate right halfwords by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vror_h_r(simde_hvx_vector_t v, int32_t rotate_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vror_VhR(v, rotate_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Normalize rotate amount to 0-15 range for 16-bit values */
  rotate_amount = rotate_amount & 0xF;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    uint16_t val = v_.u16[i];
    r_.u16[i] = (val >> rotate_amount) | (val << (16 - rotate_amount));
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vror_VhR
#define Q6_Vh_vror_VhR(v, rotate) simde_hvx_vror_h_r((v), (rotate))
#endif

/* Rotate right words by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vror_w_r(simde_hvx_vector_t v, int32_t rotate_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vror_VwR(v, rotate_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Normalize rotate amount to 0-31 range for 32-bit values */
  rotate_amount = rotate_amount & 0x1F;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u32) / sizeof(r_.u32[0])); i++) {
    uint32_t val = v_.u32[i];
    r_.u32[i] = (val >> rotate_amount) | (val << (32 - rotate_amount));
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vror_VwR
#define Q6_Vw_vror_VwR(v, rotate) simde_hvx_vror_w_r((v), (rotate))
#endif

/* Rotate left bytes by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vrol_b_r(simde_hvx_vector_t v, int32_t rotate_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vrol_VbR(v, rotate_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Normalize rotate amount to 0-7 range for 8-bit values */
  rotate_amount = rotate_amount & 0x7;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    uint8_t val = v_.u8[i];
    r_.u8[i] = (val << rotate_amount) | (val >> (8 - rotate_amount));
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vrol_VbR
#define Q6_Vb_vrol_VbR(v, rotate) simde_hvx_vrol_b_r((v), (rotate))
#endif

/* Rotate left halfwords by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vrol_h_r(simde_hvx_vector_t v, int32_t rotate_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vrol_VhR(v, rotate_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Normalize rotate amount to 0-15 range for 16-bit values */
  rotate_amount = rotate_amount & 0xF;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    uint16_t val = v_.u16[i];
    r_.u16[i] = (val << rotate_amount) | (val >> (16 - rotate_amount));
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vrol_VhR
#define Q6_Vh_vrol_VhR(v, rotate) simde_hvx_vrol_h_r((v), (rotate))
#endif

/* Rotate left words by scalar */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vrol_w_r(simde_hvx_vector_t v, int32_t rotate_amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vrol_VwR(v, rotate_amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  /* Normalize rotate amount to 0-31 range for 32-bit values */
  rotate_amount = rotate_amount & 0x1F;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u32) / sizeof(r_.u32[0])); i++) {
    uint32_t val = v_.u32[i];
    r_.u32[i] = (val << rotate_amount) | (val >> (32 - rotate_amount));
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vrol_VwR
#define Q6_Vw_vrol_VwR(v, rotate) simde_hvx_vrol_w_r((v), (rotate))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_ROR_H) */
