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

#if !defined(SIMDE_HEXAGON_HVX_SUB_H)
#define SIMDE_HEXAGON_HVX_SUB_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector subtract byte */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_sub_vb(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vsub_VbVb(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])); i++) {
    r_.i8[i] = a_.i8[i] - b_.i8[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vsub_VbVb
#define Q6_Vb_vsub_VbVb(a, b) simde_hvx_sub_vb((a), (b))
#endif

/* Vector subtract byte with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_sub_vb_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vsub_VbVb_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])); i++) {
    int16_t diff = (int16_t)a_.i8[i] - (int16_t)b_.i8[i];
    if (diff > INT8_MAX) {
      r_.i8[i] = INT8_MAX;
    } else if (diff < INT8_MIN) {
      r_.i8[i] = INT8_MIN;
    } else {
      r_.i8[i] = (int8_t)diff;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vsub_VbVb_sat
#define Q6_Vb_vsub_VbVb_sat(a, b) simde_hvx_sub_vb_sat((a), (b))
#endif

/* Vector subtract halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_sub_vh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vsub_VhVh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    r_.i16[i] = a_.i16[i] - b_.i16[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vsub_VhVh
#define Q6_Vh_vsub_VhVh(a, b) simde_hvx_sub_vh((a), (b))
#endif

/* Vector subtract halfword with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_sub_vh_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vsub_VhVh_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    int32_t diff = (int32_t)a_.i16[i] - (int32_t)b_.i16[i];
    if (diff > INT16_MAX) {
      r_.i16[i] = INT16_MAX;
    } else if (diff < INT16_MIN) {
      r_.i16[i] = INT16_MIN;
    } else {
      r_.i16[i] = (int16_t)diff;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vsub_VhVh_sat
#define Q6_Vh_vsub_VhVh_sat(a, b) simde_hvx_sub_vh_sat((a), (b))
#endif

/* Vector subtract word */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_sub_vw(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vsub_VwVw(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    r_.i32[i] = a_.i32[i] - b_.i32[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vsub_VwVw
#define Q6_Vw_vsub_VwVw(a, b) simde_hvx_sub_vw((a), (b))
#endif

/* Vector subtract word with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_sub_vw_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vsub_VwVw_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    int64_t diff = (int64_t)a_.i32[i] - (int64_t)b_.i32[i];
    if (diff > INT32_MAX) {
      r_.i32[i] = INT32_MAX;
    } else if (diff < INT32_MIN) {
      r_.i32[i] = INT32_MIN;
    } else {
      r_.i32[i] = (int32_t)diff;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vsub_VwVw_sat
#define Q6_Vw_vsub_VwVw_sat(a, b) simde_hvx_sub_vw_sat((a), (b))
#endif

/* Vector subtract unsigned byte with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_sub_vub_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vsub_VubVub_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    if (a_.u8[i] < b_.u8[i]) {
      r_.u8[i] = 0;
    } else {
      r_.u8[i] = a_.u8[i] - b_.u8[i];
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vsub_VubVub_sat
#define Q6_Vub_vsub_VubVub_sat(a, b) simde_hvx_sub_vub_sat((a), (b))
#endif

/* Vector subtract unsigned halfword with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_sub_vuh_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vsub_VuhVuh_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    if (a_.u16[i] < b_.u16[i]) {
      r_.u16[i] = 0;
    } else {
      r_.u16[i] = a_.u16[i] - b_.u16[i];
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vsub_VuhVuh_sat
#define Q6_Vuh_vsub_VuhVuh_sat(a, b) simde_hvx_sub_vuh_sat((a), (b))
#endif

/* Vector subtract unsigned byte by signed byte with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_sub_vub_vb_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vsub_VubVb_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    int16_t diff = (int16_t)a_.u8[i] - (int16_t)b_.i8[i];
    if (diff < 0) {
      r_.u8[i] = 0;
    } else if (diff > UINT8_MAX) {
      r_.u8[i] = UINT8_MAX;
    } else {
      r_.u8[i] = (uint8_t)diff;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vsub_VubVb_sat
#define Q6_Vub_vsub_VubVb_sat(a, b) simde_hvx_sub_vub_vb_sat((a), (b))
#endif

/* Vector subtract halfword - produces word results (widening) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_t simde_hvx_sub_vh_to_vw(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Ww_vsub_VhVh(a, b);
#else
  simde_hvx_vector_pair_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Subtract halfwords to produce words (32-bit results) */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.i16) / sizeof(a_.i16[0])); i++) {
    r_.i32[i] = (int32_t)a_.i16[i] - (int32_t)b_.i16[i];
  }

  return r_;
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Ww_vsub_VhVh
#define Q6_Ww_vsub_VhVh(a, b) simde_hvx_sub_vh_to_vw((a), (b))
#endif

/* Vector subtract unsigned byte - produces halfword results (widening) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_t simde_hvx_sub_vub_to_vh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Wh_vsub_VubVub(a, b);
#else
  simde_hvx_vector_pair_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Subtract unsigned bytes to produce halfwords (16-bit results) */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.u8) / sizeof(a_.u8[0])); i++) {
    r_.i16[i] = (int16_t)a_.u8[i] - (int16_t)b_.u8[i];
  }

  return r_;
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Wh_vsub_VubVub
#define Q6_Wh_vsub_VubVub(a, b) simde_hvx_sub_vub_to_vh((a), (b))
#endif

/* Vector subtract unsigned halfword - produces word results (widening) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_t simde_hvx_sub_vuh_to_vw(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Ww_vsub_VuhVuh(a, b);
#else
  simde_hvx_vector_pair_private r_;
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Subtract unsigned halfwords to produce words (32-bit results) */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(a_.u16) / sizeof(a_.u16[0])); i++) {
    r_.i32[i] = (int32_t)a_.u16[i] - (int32_t)b_.u16[i];
  }

  return r_;
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Ww_vsub_VuhVuh
#define Q6_Ww_vsub_VuhVuh(a, b) simde_hvx_sub_vuh_to_vw((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_SUB_H) */
