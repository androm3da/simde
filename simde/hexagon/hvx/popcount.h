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

#if !defined(SIMDE_HEXAGON_HVX_POPCOUNT_H)
#define SIMDE_HEXAGON_HVX_POPCOUNT_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Population count for 16-bit halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vpopcount_h(simde_hvx_vector_t v) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vpopcount_Vh(v);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    uint16_t val = (uint16_t)v_.i16[i];
    uint16_t count = 0;
    while (val) {
      count += val & 1;
      val >>= 1;
    }
    r_.i16[i] = (int16_t)count;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vpopcount_Vh
#define Q6_Vh_vpopcount_Vh(v) simde_hvx_vpopcount_h((v))
#endif

/* Count leading zeros for 16-bit unsigned halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vcl0_uh(simde_hvx_vector_t v) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vcl0_Vuh(v);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    uint16_t val = v_.u16[i];
    uint16_t count = 0;
    if (val == 0) {
      count = 16;
    } else {
      while ((val & 0x8000) == 0) {
        count++;
        val <<= 1;
      }
    }
    r_.u16[i] = count;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vcl0_Vuh
#define Q6_Vuh_vcl0_Vuh(v) simde_hvx_vcl0_uh((v))
#endif

/* Count leading zeros for 32-bit unsigned words */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vcl0_uw(simde_hvx_vector_t v) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuw_vcl0_Vuw(v);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u32) / sizeof(r_.u32[0])); i++) {
    uint32_t val = v_.u32[i];
    uint32_t count = 0;
    if (val == 0) {
      count = 32;
    } else {
      while ((val & 0x80000000U) == 0) {
        count++;
        val <<= 1;
      }
    }
    r_.u32[i] = count;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuw_vcl0_Vuw
#define Q6_Vuw_vcl0_Vuw(v) simde_hvx_vcl0_uw((v))
#endif

/* Normalization amount for 16-bit signed halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vnormamt_h(simde_hvx_vector_t v) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vnormamt_Vh(v);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    int16_t val = v_.i16[i];
    int16_t count = 0;

    if (val == 0 || val == -1) {
      count = 15;
    } else {
      uint16_t uval = (uint16_t)val;
      uint16_t sign_bit = (uval & 0x8000);

      while (count < 15) {
        if (((uval & 0x8000) != 0) != (sign_bit != 0)) {
          break;
        }
        count++;
        uval <<= 1;
      }
      count--;
    }

    r_.i16[i] = count;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vnormamt_Vh
#define Q6_Vh_vnormamt_Vh(v) simde_hvx_vnormamt_h((v))
#endif

/* Normalization amount for 32-bit signed words */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vnormamt_w(simde_hvx_vector_t v) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vw_vnormamt_Vw(v);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    int32_t val = v_.i32[i];
    int32_t count = 0;

    if (val == 0 || val == -1) {
      count = 31;
    } else {
      uint32_t uval = (uint32_t)val;
      uint32_t sign_bit = (uval & 0x80000000U);

      while (count < 31) {
        if (((uval & 0x80000000U) != 0) != (sign_bit != 0)) {
          break;
        }
        count++;
        uval <<= 1;
      }
      count--;
    }

    r_.i32[i] = count;
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vw_vnormamt_Vw
#define Q6_Vw_vnormamt_Vw(v) simde_hvx_vnormamt_w((v))
#endif

/* Vector rotate right */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vror(simde_hvx_vector_t v, int32_t amount) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_vror_VR(v, amount);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  int bits_in_vector = sizeof(v_) * 8;
  amount = amount % bits_in_vector;
  if (amount < 0)
    amount += bits_in_vector;

  if (amount == 0) {
    r_ = v_;
  } else {
    int byte_shift = amount / 8;
    int bit_shift = amount % 8;

    SIMDE_VECTORIZE
    for (size_t i = 0; i < sizeof(r_.u8); i++) {
      size_t src_byte1 = (i + byte_shift) % sizeof(r_.u8);
      size_t src_byte2 = (src_byte1 + 1) % sizeof(r_.u8);

      uint8_t val1 = v_.u8[src_byte1];
      uint8_t val2 = v_.u8[src_byte2];

      r_.u8[i] = (val1 >> bit_shift) | (val2 << (8 - bit_shift));
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_vror_VR
#define Q6_V_vror_VR(v, amount) simde_hvx_vror((v), (amount))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_POPCOUNT_H) */
