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

#if !defined(SIMDE_HEXAGON_HVX_SHIFT_H)
#define SIMDE_HEXAGON_HVX_SHIFT_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector shift left halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_shl_vh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vshl_VhVh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    int shift = b_.i16[i] & 0x1F; /* Limit shift to 0-31 */
    if (shift >= 16) {
      r_.i16[i] = 0;
    } else {
      r_.i16[i] = a_.i16[i] << shift;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vshl_VhVh
#define Q6_Vh_vshl_VhVh(a, b) simde_hvx_shl_vh((a), (b))
#endif

/* Vector shift left word */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_shl_vw(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vshl_VwVw(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    int shift = b_.i32[i] & 0x1F; /* Limit shift to 0-31 */
    r_.i32[i] = a_.i32[i] << shift;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vshl_VwVw
#define Q6_Vw_vshl_VwVw(a, b) simde_hvx_shl_vw((a), (b))
#endif

/* Vector arithmetic shift right halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_asr_vh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vasr_VhVh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    int shift = b_.i16[i] & 0x1F; /* Limit shift to 0-31 */
    if (shift >= 16) {
      r_.i16[i] = (a_.i16[i] < 0) ? -1 : 0; /* Sign extend */
    } else {
      r_.i16[i] = a_.i16[i] >> shift;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vasr_VhVh
#define Q6_Vh_vasr_VhVh(a, b) simde_hvx_asr_vh((a), (b))
#endif

/* Vector arithmetic shift right word */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_asr_vw(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vasr_VwVw(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    int shift = b_.i32[i] & 0x1F; /* Limit shift to 0-31 */
    r_.i32[i] = a_.i32[i] >> shift;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vasr_VwVw
#define Q6_Vw_vasr_VwVw(a, b) simde_hvx_asr_vw((a), (b))
#endif

/* Vector logical shift right halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_lsr_vuh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vlsr_VuhVuh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    int shift = b_.u16[i] & 0x1F; /* Limit shift to 0-31 */
    if (shift >= 16) {
      r_.u16[i] = 0;
    } else {
      r_.u16[i] = a_.u16[i] >> shift;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vlsr_VuhVuh
#define Q6_Vuh_vlsr_VuhVuh(a, b) simde_hvx_lsr_vuh((a), (b))
#endif

/* Vector logical shift right word */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_lsr_vuw(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuw_vlsr_VuwVuw(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u32) / sizeof(r_.u32[0])); i++) {
    int shift = b_.u32[i] & 0x1F; /* Limit shift to 0-31 */
    r_.u32[i] = a_.u32[i] >> shift;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuw_vlsr_VuwVuw
#define Q6_Vuw_vlsr_VuwVuw(a, b) simde_hvx_lsr_vuw((a), (b))
#endif

/* Vector shift left by immediate - halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_shl_vh_imm(simde_hvx_vector_t a, const int imm) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* This would use a specific immediate shift intrinsic */
  /* For now, convert to vector shift */
  simde_hvx_vector_t shift_vec;
  simde_hvx_vector_private shift_ = *SIMDE_HEXAGON_HVX_TO_PRIVATE(&shift_vec);
  for (size_t i = 0; i < sizeof(shift_.i16) / sizeof(shift_.i16[0]); i++) {
    shift_.i16[i] = imm;
  }
  shift_vec = *SIMDE_HEXAGON_HVX_FROM_PRIVATE(&shift_);
  return simde_hvx_shl_vh(a, shift_vec);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  int shift = imm & 0x1F; /* Limit shift to 0-31 */

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    if (shift >= 16) {
      r_.i16[i] = 0;
    } else {
      r_.i16[i] = a_.i16[i] << shift;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

/* Vector shift right by immediate - halfword */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_asr_vh_imm(simde_hvx_vector_t a, const int imm) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* This would use a specific immediate shift intrinsic */
  simde_hvx_vector_t shift_vec;
  simde_hvx_vector_private shift_ = *SIMDE_HEXAGON_HVX_TO_PRIVATE(&shift_vec);
  for (size_t i = 0; i < sizeof(shift_.i16) / sizeof(shift_.i16[0]); i++) {
    shift_.i16[i] = imm;
  }
  shift_vec = *SIMDE_HEXAGON_HVX_FROM_PRIVATE(&shift_);
  return simde_hvx_asr_vh(a, shift_vec);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  int shift = imm & 0x1F; /* Limit shift to 0-31 */

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    if (shift >= 16) {
      r_.i16[i] = (a_.i16[i] < 0) ? -1 : 0; /* Sign extend */
    } else {
      r_.i16[i] = a_.i16[i] >> shift;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_SHIFT_H) */
