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

#if !defined(SIMDE_HEXAGON_HVX_LOAD_H)
#define SIMDE_HEXAGON_HVX_LOAD_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector load aligned - basic aligned load from memory */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_load_aligned(const void *ptr) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* In native mode, use simple pointer dereference for aligned loads */
  return *((const HVX_Vector *)ptr);
#else
  simde_hvx_vector_private r_;
  const uint8_t *src = (const uint8_t *)ptr;

  /* Copy aligned vector data */
  for (size_t i = 0; i < sizeof(r_); i++) {
    r_.u8[i] = src[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

/* Vector load unaligned - load from potentially unaligned memory */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_load_unaligned(const void *ptr) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* In native mode, use simple pointer dereference - HVX handles unaligned */
  return *((const HVX_Vector *)ptr);
#else
  simde_hvx_vector_private r_;
  const uint8_t *src = (const uint8_t *)ptr;

  /* Copy unaligned vector data */
  for (size_t i = 0; i < sizeof(r_); i++) {
    r_.u8[i] = src[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

/* Vector load with offset - load from base address + offset */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_load_offset(const void *base, ptrdiff_t offset) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  const uint8_t *ptr = (const uint8_t *)base + offset;
  return *((const HVX_Vector *)ptr);
#else
  const uint8_t *ptr = (const uint8_t *)base + offset;
  return simde_hvx_load_unaligned(ptr);
#endif
}

/* Vector conditional load - load if predicate is true */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_load_conditional(simde_hvx_vector_pred_t pred, const void *ptr,
                                              simde_hvx_vector_t default_val) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* Note: This is a simplified implementation */
  /* Real HVX would use predicated load operations, but those are complex to
   * emulate */
  HVX_Vector loaded = *((const HVX_Vector *)ptr);
  /* For now, return either loaded or default based on first predicate bit */
  /* A proper implementation would need bitwise predicate handling */
  return pred.private_.u8[0] ? loaded : default_val;
#else
  simde_hvx_vector_private r_, default_ = simde_hvx_vector_to_private(default_val), pred_priv;
  const uint8_t *src = (const uint8_t *)ptr;

  /* Copy predicate data */
  simde_memcpy(&pred_priv, &pred, sizeof(pred_priv));

  /* Load conditionally based on predicate bits */
  for (size_t i = 0; i < sizeof(r_); i++) {
    /* Each byte of predicate controls 8 bytes of vector (128 bytes / 16 pred
     * bytes) */
    size_t pred_idx = i / 8;
    uint8_t pred_bit = (pred_priv.u8[pred_idx] >> (i % 8)) & 1;
    r_.u8[i] = pred_bit ? src[i] : default_.u8[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

/* Vector load zero-extended byte - load bytes and zero-extend to halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_load_zero_extend_b_to_h(const void *ptr) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* This would need a specific HVX intrinsic for zero-extension loads */
  /* For now, do a regular load and zero-extend manually */
  const uint8_t *src = (const uint8_t *)ptr;
  HVX_Vector result;
  uint16_t *dst = (uint16_t *)&result;
  for (size_t i = 0; i < 64; i++) { /* 64 halfwords in 128-byte vector */
    dst[i] = (uint16_t)src[i];
  }
  return result;
#else
  simde_hvx_vector_private r_;
  const uint8_t *src = (const uint8_t *)ptr;

  /* Load bytes and zero-extend to halfwords */
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    r_.u16[i] = (uint16_t)src[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

/* Vector load sign-extended byte - load bytes and sign-extend to halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_load_sign_extend_b_to_h(const void *ptr) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* This would need a specific HVX intrinsic for sign-extension loads */
  const int8_t *src = (const int8_t *)ptr;
  HVX_Vector result;
  int16_t *dst = (int16_t *)&result;
  for (size_t i = 0; i < 64; i++) { /* 64 halfwords in 128-byte vector */
    dst[i] = (int16_t)src[i];
  }
  return result;
#else
  simde_hvx_vector_private r_;
  const int8_t *src = (const int8_t *)ptr;

  /* Load bytes and sign-extend to halfwords */
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    r_.i16[i] = (int16_t)src[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

/* Vector load zero-extended halfword - load halfwords and zero-extend to words
 */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_load_zero_extend_h_to_w(const void *ptr) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  const uint16_t *src = (const uint16_t *)ptr;
  HVX_Vector result;
  uint32_t *dst = (uint32_t *)&result;
  for (size_t i = 0; i < 32; i++) { /* 32 words in 128-byte vector */
    dst[i] = (uint32_t)src[i];
  }
  return result;
#else
  simde_hvx_vector_private r_;
  const uint16_t *src = (const uint16_t *)ptr;

  /* Load halfwords and zero-extend to words */
  for (size_t i = 0; i < (sizeof(r_.u32) / sizeof(r_.u32[0])); i++) {
    r_.u32[i] = (uint32_t)src[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

/* Vector load sign-extended halfword - load halfwords and sign-extend to words
 */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_load_sign_extend_h_to_w(const void *ptr) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  const int16_t *src = (const int16_t *)ptr;
  HVX_Vector result;
  int32_t *dst = (int32_t *)&result;
  for (size_t i = 0; i < 32; i++) { /* 32 words in 128-byte vector */
    dst[i] = (int32_t)src[i];
  }
  return result;
#else
  simde_hvx_vector_private r_;
  const int16_t *src = (const int16_t *)ptr;

  /* Load halfwords and sign-extend to words */
  for (size_t i = 0; i < (sizeof(r_.i32) / sizeof(r_.i32[0])); i++) {
    r_.i32[i] = (int32_t)src[i];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_LOAD_H) */
