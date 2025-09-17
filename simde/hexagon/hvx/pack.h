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

#if !defined(SIMDE_HEXAGON_HVX_PACK_H)
#define SIMDE_HEXAGON_HVX_PACK_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Pack halfwords to bytes with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_pack_vb_vh_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vpack_VhVh_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < 64; i++) {
    int16_t val = a_.i16[i];
    if (val > INT8_MAX) {
      r_.i8[i] = INT8_MAX;
    } else if (val < INT8_MIN) {
      r_.i8[i] = INT8_MIN;
    } else {
      r_.i8[i] = (int8_t)val;
    }
  }

  SIMDE_VECTORIZE
  for (size_t i = 0; i < 64; i++) {
    int16_t val = b_.i16[i];
    if (val > INT8_MAX) {
      r_.i8[i + 64] = INT8_MAX;
    } else if (val < INT8_MIN) {
      r_.i8[i + 64] = INT8_MIN;
    } else {
      r_.i8[i + 64] = (int8_t)val;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vpack_VhVh_sat
#define Q6_Vb_vpack_VhVh_sat(a, b) simde_hvx_pack_vb_vh_sat((a), (b))
#endif

/* Pack words to halfwords with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_pack_vh_vw_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vpack_VwVw_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < 32; i++) {
    int32_t val = a_.i32[i];
    if (val > INT16_MAX) {
      r_.i16[i] = INT16_MAX;
    } else if (val < INT16_MIN) {
      r_.i16[i] = INT16_MIN;
    } else {
      r_.i16[i] = (int16_t)val;
    }
  }

  SIMDE_VECTORIZE
  for (size_t i = 0; i < 32; i++) {
    int32_t val = b_.i32[i];
    if (val > INT16_MAX) {
      r_.i16[i + 32] = INT16_MAX;
    } else if (val < INT16_MIN) {
      r_.i16[i + 32] = INT16_MIN;
    } else {
      r_.i16[i + 32] = (int16_t)val;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vpack_VwVw_sat
#define Q6_Vh_vpack_VwVw_sat(a, b) simde_hvx_pack_vh_vw_sat((a), (b))
#endif

/* Pack unsigned halfwords to unsigned bytes with saturation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_pack_vub_vuh_sat(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vpack_VuhVuh_sat(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < 64; i++) {
    uint16_t val = a_.u16[i];
    if (val > UINT8_MAX) {
      r_.u8[i] = UINT8_MAX;
    } else {
      r_.u8[i] = (uint8_t)val;
    }
  }

  SIMDE_VECTORIZE
  for (size_t i = 0; i < 64; i++) {
    uint16_t val = b_.u16[i];
    if (val > UINT8_MAX) {
      r_.u8[i + 64] = UINT8_MAX;
    } else {
      r_.u8[i + 64] = (uint8_t)val;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vpack_VuhVuh_sat
#define Q6_Vub_vpack_VuhVuh_sat(a, b) simde_hvx_pack_vub_vuh_sat((a), (b))
#endif

/* Unpack low bytes to halfwords (sign extend) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_unpack_vh_vb_lo(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vunpack_Vb(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < 64; i++) {
    r_.i16[i] = (int16_t)a_.i8[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vunpack_Vb
#define Q6_Vh_vunpack_Vb(a) simde_hvx_unpack_vh_vb_lo((a))
#endif

/* Unpack low halfwords to words (sign extend) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_unpack_vw_vh_lo(simde_hvx_vector_t a) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vunpack_Vh(a);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < 32; i++) {
    r_.i32[i] = (int32_t)a_.i16[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vunpack_Vh
#define Q6_Vw_vunpack_Vh(a) simde_hvx_unpack_vw_vh_lo((a))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_PACK_H) */
