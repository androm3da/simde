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

#if !defined(SIMDE_HEXAGON_HVX_ROUND_H)
#define SIMDE_HEXAGON_HVX_ROUND_H

#include "../types.h"
#include <limits.h>

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Pack halfwords to signed bytes with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vpack_hh_sat_b(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vpack_VhVh_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  size_t half_elements = (sizeof(r_.i8) / sizeof(r_.i8[0])) / 2;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < half_elements; i++) {
    int16_t val_a = a_.i16[i];
    int16_t val_b = b_.i16[i];

    if (val_a > INT8_MAX) {
      r_.i8[i] = INT8_MAX;
    } else if (val_a < INT8_MIN) {
      r_.i8[i] = INT8_MIN;
    } else {
      r_.i8[i] = (int8_t)val_a;
    }

    if (val_b > INT8_MAX) {
      r_.i8[i + half_elements] = INT8_MAX;
    } else if (val_b < INT8_MIN) {
      r_.i8[i + half_elements] = INT8_MIN;
    } else {
      r_.i8[i + half_elements] = (int8_t)val_b;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vpack_VhVh_sat
#define Q6_Vb_vpack_VhVh_sat(a, b) simde_hvx_vpack_hh_sat_b((a), (b))
#endif

/* Pack halfwords to unsigned bytes with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vpack_hh_sat_ub(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vpack_VhVh_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  size_t half_elements = (sizeof(r_.u8) / sizeof(r_.u8[0])) / 2;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < half_elements; i++) {
    int16_t val_a = a_.i16[i];
    int16_t val_b = b_.i16[i];

    if (val_a > UINT8_MAX) {
      r_.u8[i] = UINT8_MAX;
    } else if (val_a < 0) {
      r_.u8[i] = 0;
    } else {
      r_.u8[i] = (uint8_t)val_a;
    }

    if (val_b > UINT8_MAX) {
      r_.u8[i + half_elements] = UINT8_MAX;
    } else if (val_b < 0) {
      r_.u8[i + half_elements] = 0;
    } else {
      r_.u8[i + half_elements] = (uint8_t)val_b;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vpack_VhVh_sat
#define Q6_Vub_vpack_VhVh_sat(a, b) simde_hvx_vpack_hh_sat_ub((a), (b))
#endif

/* Pack words to halfwords with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vpack_ww_sat_h(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vpack_VwVw_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  size_t half_elements = (sizeof(r_.i16) / sizeof(r_.i16[0])) / 2;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < half_elements; i++) {
    int32_t val_a = a_.i32[i];
    int32_t val_b = b_.i32[i];

    if (val_a > INT16_MAX) {
      r_.i16[i] = INT16_MAX;
    } else if (val_a < INT16_MIN) {
      r_.i16[i] = INT16_MIN;
    } else {
      r_.i16[i] = (int16_t)val_a;
    }

    if (val_b > INT16_MAX) {
      r_.i16[i + half_elements] = INT16_MAX;
    } else if (val_b < INT16_MIN) {
      r_.i16[i + half_elements] = INT16_MIN;
    } else {
      r_.i16[i + half_elements] = (int16_t)val_b;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vpack_VwVw_sat
#define Q6_Vh_vpack_VwVw_sat(a, b) simde_hvx_vpack_ww_sat_h((a), (b))
#endif

/* Round halfwords to unsigned bytes with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vround_hh_sat_ub(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vround_VhVh_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  size_t half_elements = (sizeof(r_.u8) / sizeof(r_.u8[0])) / 2;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < half_elements; i++) {
    int16_t val_a = a_.i16[i];
    int16_t val_b = b_.i16[i];

    int16_t rounded_a = (val_a >= 0) ? (val_a + 128) >> 8 : (val_a + 127) >> 8;
    int16_t rounded_b = (val_b >= 0) ? (val_b + 128) >> 8 : (val_b + 127) >> 8;

    if (rounded_a > UINT8_MAX) {
      r_.u8[i] = UINT8_MAX;
    } else if (rounded_a < 0) {
      r_.u8[i] = 0;
    } else {
      r_.u8[i] = (uint8_t)rounded_a;
    }

    if (rounded_b > UINT8_MAX) {
      r_.u8[i + half_elements] = UINT8_MAX;
    } else if (rounded_b < 0) {
      r_.u8[i + half_elements] = 0;
    } else {
      r_.u8[i + half_elements] = (uint8_t)rounded_b;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vround_VhVh_sat
#define Q6_Vub_vround_VhVh_sat(a, b) simde_hvx_vround_hh_sat_ub((a), (b))
#endif

/* Add halfwords with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vadd_h_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vadd_VhVh_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    int32_t sum = (int32_t)a_.i16[i] + (int32_t)b_.i16[i];

    if (sum > INT16_MAX) {
      r_.i16[i] = INT16_MAX;
    } else if (sum < INT16_MIN) {
      r_.i16[i] = INT16_MIN;
    } else {
      r_.i16[i] = (int16_t)sum;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vadd_VhVh_sat
#define Q6_Vh_vadd_VhVh_sat(a, b) simde_hvx_vadd_h_sat((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_ROUND_H) */
