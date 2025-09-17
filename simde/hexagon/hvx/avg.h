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

#if !defined(SIMDE_HEXAGON_HVX_AVG_H)
#define SIMDE_HEXAGON_HVX_AVG_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector average unsigned byte */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_avg_vub(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vavg_VubVub(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    r_.u8[i] = HEDLEY_STATIC_CAST(uint8_t,
                                  (HEDLEY_STATIC_CAST(uint16_t, a_.u8[i]) + HEDLEY_STATIC_CAST(uint16_t, b_.u8[i]) + 1) / 2);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vavg_VubVub
#define Q6_Vub_vavg_VubVub(a, b) simde_hvx_avg_vub((a), (b))
#endif

/* Vector average unsigned halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_avg_vuh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vavg_VuhVuh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    r_.u16[i] = HEDLEY_STATIC_CAST(
        uint16_t, (HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]) + HEDLEY_STATIC_CAST(uint32_t, b_.u16[i]) + 1) / 2);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vavg_VuhVuh
#define Q6_Vuh_vavg_VuhVuh(a, b) simde_hvx_avg_vuh((a), (b))
#endif

/* Vector average unsigned word */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_avg_vuw(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuw_vavg_VuwVuw(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u32) / sizeof(r_.u32[0])); i++) {
    r_.u32[i] = HEDLEY_STATIC_CAST(
        uint32_t, (HEDLEY_STATIC_CAST(uint64_t, a_.u32[i]) + HEDLEY_STATIC_CAST(uint64_t, b_.u32[i]) + 1) / 2);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuw_vavg_VuwVuw
#define Q6_Vuw_vavg_VuwVuw(a, b) simde_hvx_avg_vuw((a), (b))
#endif

/* Vector rounded average unsigned byte */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_ravg_vub(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vnavg_VubVub(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    r_.u8[i] =
        HEDLEY_STATIC_CAST(uint8_t, (HEDLEY_STATIC_CAST(uint16_t, a_.u8[i]) + HEDLEY_STATIC_CAST(uint16_t, b_.u8[i])) / 2);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vnavg_VubVub
#define Q6_Vub_vnavg_VubVub(a, b) simde_hvx_ravg_vub((a), (b))
#endif

/* Vector rounded average unsigned halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_ravg_vuh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vnavg_VuhVuh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t,
                                   (HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]) + HEDLEY_STATIC_CAST(uint32_t, b_.u16[i])) / 2);
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vnavg_VuhVuh
#define Q6_Vuh_vnavg_VuhVuh(a, b) simde_hvx_ravg_vuh((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_AVG_H) */
