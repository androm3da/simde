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

#if !defined(SIMDE_HEXAGON_HVX_EXTRACT_H)
#define SIMDE_HEXAGON_HVX_EXTRACT_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Extract 32-bit word from vector at given position */
SIMDE_FUNCTION_ATTRIBUTES
int32_t simde_hvx_vextract_w(simde_hvx_vector_t v, int32_t position) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_R_vextract_VR(v, position);
#else
  simde_hvx_vector_private v_ = simde_hvx_vector_to_private(v);
  size_t num_elements = sizeof(v_.i32) / sizeof(v_.i32[0]);
  size_t idx = ((uint32_t)position) % num_elements;
  return v_.i32[idx];
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_R_vextract_VR
#define Q6_R_vextract_VR(v, pos) simde_hvx_vextract_w((v), (pos))
#endif

/* Extract 16-bit halfword from vector at given position */
SIMDE_FUNCTION_ATTRIBUTES
int16_t simde_hvx_vextract_h(simde_hvx_vector_t v, int32_t position) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* HVX doesn't have native halfword extract, use word extract + shift */
  int word_pos = position / 2;
  int word_data = Q6_R_vextract_VR(v, word_pos);
  if (position & 1) {
    return (int16_t)(word_data >> 16);
  } else {
    return (int16_t)(word_data & 0xFFFF);
  }
#else
  simde_hvx_vector_private v_ = simde_hvx_vector_to_private(v);
  size_t num_elements = sizeof(v_.i16) / sizeof(v_.i16[0]);
  size_t idx = ((uint32_t)position) % num_elements;
  return v_.i16[idx];
#endif
}

/* Extract 8-bit byte from vector at given position */
SIMDE_FUNCTION_ATTRIBUTES
int8_t simde_hvx_vextract_b(simde_hvx_vector_t v, int32_t position) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* HVX doesn't have native byte extract, use word extract + shift */
  int word_pos = position / 4;
  int word_data = Q6_R_vextract_VR(v, word_pos);
  int byte_offset = position & 3;
  return (int8_t)((word_data >> (byte_offset * 8)) & 0xFF);
#else
  simde_hvx_vector_private v_ = simde_hvx_vector_to_private(v);
  size_t num_elements = sizeof(v_.i8) / sizeof(v_.i8[0]);
  size_t idx = ((uint32_t)position) % num_elements;
  return v_.i8[idx];
#endif
}

/* Extract high vector from vector pair */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_hi_w(simde_hvx_vector_pair_t pair) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_hi_W(pair);
#else
  simde_hvx_vector_pair_private pair_ = simde_hvx_vector_pair_to_private(pair);
  return pair_.val[1];
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_hi_W
#define Q6_V_hi_W(pair) simde_hvx_hi_w((pair))
#endif

/* Extract low vector from vector pair */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_lo_w(simde_hvx_vector_pair_t pair) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_lo_W(pair);
#else
  simde_hvx_vector_pair_private pair_ = simde_hvx_vector_pair_to_private(pair);
  return pair_.val[0];
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_lo_W
#define Q6_V_lo_W(pair) simde_hvx_lo_w((pair))
#endif

/* Insert 32-bit word into vector at position 0 */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vinsert_w(simde_hvx_vector_t v, int32_t scalar) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vinsert_VwR(v, scalar);
#else
  simde_hvx_vector_private v_ = simde_hvx_vector_to_private(v);
  v_.i32[0] = scalar;
  return simde_hvx_vector_from_private(v_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vinsert_VwR
#define Q6_Vw_vinsert_VwR(v, scalar) simde_hvx_vinsert_w((v), (scalar))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_EXTRACT_H) */
