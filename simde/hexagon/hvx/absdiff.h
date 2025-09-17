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

#if !defined(SIMDE_HEXAGON_HVX_ABSDIFF_H)
#define SIMDE_HEXAGON_HVX_ABSDIFF_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Unsigned byte absolute difference */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vabsdiff_ub(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vabsdiff_VubVub(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    uint8_t val_a = a_.u8[i];
    uint8_t val_b = b_.u8[i];
    r_.u8[i] = (val_a > val_b) ? (val_a - val_b) : (val_b - val_a);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vabsdiff_VubVub
#define Q6_Vub_vabsdiff_VubVub(a, b) simde_hvx_vabsdiff_ub((a), (b))
#endif

/* Signed to unsigned halfword absolute difference */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vabsdiff_h_uh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vabsdiff_VhVh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    int16_t val_a = a_.i16[i];
    int16_t val_b = b_.i16[i];
    int32_t diff = (int32_t)val_a - (int32_t)val_b;
    r_.u16[i] = (uint16_t)((diff < 0) ? -diff : diff);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vabsdiff_VhVh
#define Q6_Vuh_vabsdiff_VhVh(a, b) simde_hvx_vabsdiff_h_uh((a), (b))
#endif

/* Unsigned halfword absolute difference */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vabsdiff_uh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vabsdiff_VuhVuh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    uint16_t val_a = a_.u16[i];
    uint16_t val_b = b_.u16[i];
    r_.u16[i] = (val_a > val_b) ? (val_a - val_b) : (val_b - val_a);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vabsdiff_VuhVuh
#define Q6_Vuh_vabsdiff_VuhVuh(a, b) simde_hvx_vabsdiff_uh((a), (b))
#endif

/* Word absolute difference */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vabsdiff_w_uw(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuw_vabsdiff_VwVw(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u32) / sizeof(r_.u32[0])); i++) {
    int32_t val_a = a_.i32[i];
    int32_t val_b = b_.i32[i];
    int64_t diff = (int64_t)val_a - (int64_t)val_b;
    r_.u32[i] = (uint32_t)((diff < 0) ? -diff : diff);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuw_vabsdiff_VwVw
#define Q6_Vuw_vabsdiff_VwVw(a, b) simde_hvx_vabsdiff_w_uw((a), (b))
#endif

/* Rotating sum of absolute differences on bytes */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_pair_t simde_hvx_vrsad_ub(simde_hvx_vector_pair_t a_pair, int32_t scalar, int32_t rotate) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Wuw_vrsad_WubRubI(a_pair, scalar, rotate);
#else
  simde_hvx_vector_pair_private r_, a_pair_ = simde_hvx_vector_pair_to_private(a_pair);

  /* Extract vectors from pair and create scalar vector */
  simde_hvx_vector_private a_lo = simde_hvx_vector_to_private(a_pair_.val[0]),
                           a_hi = simde_hvx_vector_to_private(a_pair_.val[1]);

  /* Create broadcast scalar vector */
  simde_hvx_vector_private scalar_vec;
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(scalar_vec.u8) / sizeof(scalar_vec.u8[0])); i++) {
    scalar_vec.u8[i] = (uint8_t)(scalar & 0xFF);
  }

  /* Perform SAD with rotation - simplified implementation */
  size_t word_elements = sizeof(r_.u32) / sizeof(r_.u32[0]) / 2; /* Words per vector */

  SIMDE_VECTORIZE
  for (size_t w = 0; w < word_elements; w++) {
    uint32_t sad_sum_lo = 0, sad_sum_hi = 0;

    /* Sum absolute differences for this word position */
    for (size_t b = 0; b < 4; b++) { /* 4 bytes per word */
      size_t idx = w * 4 + b;
      if (idx < sizeof(a_lo.u8) / sizeof(a_lo.u8[0])) {
        /* Rotate index based on rotate parameter */
        size_t rot_idx = (idx + ((rotate & 1) ? 1 : 0)) % (sizeof(a_lo.u8) / sizeof(a_lo.u8[0]));

        uint8_t diff_lo = (a_lo.u8[idx] > scalar_vec.u8[rot_idx]) ? (a_lo.u8[idx] - scalar_vec.u8[rot_idx])
                                                                  : (scalar_vec.u8[rot_idx] - a_lo.u8[idx]);

        uint8_t diff_hi = (a_hi.u8[idx] > scalar_vec.u8[rot_idx]) ? (a_hi.u8[idx] - scalar_vec.u8[rot_idx])
                                                                  : (scalar_vec.u8[rot_idx] - a_hi.u8[idx]);

        sad_sum_lo += diff_lo;
        sad_sum_hi += diff_hi;
      }
    }

    r_.u32[w] = sad_sum_lo;
    r_.u32[w + word_elements] = sad_sum_hi;
  }

  return simde_hvx_vector_pair_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Wuw_vrsad_WubRubI
#define Q6_Wuw_vrsad_WubRubI(a_pair, scalar, rotate) simde_hvx_vrsad_ub((a_pair), (scalar), (rotate))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_ABSDIFF_H) */
