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

#if !defined(SIMDE_HEXAGON_HVX_STORE_H)
#define SIMDE_HEXAGON_HVX_STORE_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Vector store aligned - basic aligned store to memory */
SIMDE_FUNCTION_ATTRIBUTES
void simde_hvx_store_aligned(void *ptr, simde_hvx_vector_t vec) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* In native mode, use simple pointer assignment for aligned stores */
  *((HVX_Vector *)ptr) = vec;
#else
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec);
  uint8_t *dst = (uint8_t *)ptr;

  /* Copy aligned vector data */
  for (size_t i = 0; i < sizeof(vec_); i++) {
    dst[i] = vec_.u8[i];
  }
#endif
}

/* Vector store unaligned - store to potentially unaligned memory */
SIMDE_FUNCTION_ATTRIBUTES
void simde_hvx_store_unaligned(void *ptr, simde_hvx_vector_t vec) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* In native mode, use simple pointer assignment - HVX handles unaligned */
  *((HVX_Vector *)ptr) = vec;
#else
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec);
  uint8_t *dst = (uint8_t *)ptr;

  /* Copy unaligned vector data */
  for (size_t i = 0; i < sizeof(vec_); i++) {
    dst[i] = vec_.u8[i];
  }
#endif
}

/* Vector store with offset - store to base address + offset */
SIMDE_FUNCTION_ATTRIBUTES
void simde_hvx_store_offset(void *base, ptrdiff_t offset, simde_hvx_vector_t vec) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  uint8_t *ptr = (uint8_t *)base + offset;
  *((HVX_Vector *)ptr) = vec;
#else
  uint8_t *ptr = (uint8_t *)base + offset;
  simde_hvx_store_unaligned(ptr, vec);
#endif
}

/* Vector store non-temporal - store with non-temporal hint */
SIMDE_FUNCTION_ATTRIBUTES
void simde_hvx_store_nt(void *ptr, simde_hvx_vector_t vec) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* Use non-temporal store if available, otherwise fall back to regular store
   */
  /* Note: This would use a specific NT store intrinsic in real HVX */
  *((HVX_Vector *)ptr) = vec;
#else
  /* Non-temporal hint doesn't matter in emulation */
  simde_hvx_store_aligned(ptr, vec);
#endif
}

/* Vector conditional store - store if predicate is true */
SIMDE_FUNCTION_ATTRIBUTES
void simde_hvx_store_conditional(simde_hvx_vector_pred_t pred, void *ptr, simde_hvx_vector_t vec) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* This would use Q6_vmem_QRIV for predicated stores in real HVX */
  /* For now, this is a simplified implementation */
  if (pred.private_.u8[0]) { /* Check first predicate bit */
    *((HVX_Vector *)ptr) = vec;
  }
#else
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec), pred_priv;
  uint8_t *dst = (uint8_t *)ptr;

  /* Copy predicate data */
  simde_memcpy(&pred_priv, &pred, sizeof(pred_priv));

  /* Store conditionally based on predicate bits */
  for (size_t i = 0; i < sizeof(vec_); i++) {
    /* Each byte of predicate controls 8 bytes of vector (128 bytes / 16 pred
     * bytes) */
    size_t pred_idx = i / 8;
    uint8_t pred_bit = (pred_priv.u8[pred_idx] >> (i % 8)) & 1;
    if (pred_bit) {
      dst[i] = vec_.u8[i];
    }
  }
#endif
}

/* Vector store bytes from halfwords - store lower bytes of halfwords */
SIMDE_FUNCTION_ATTRIBUTES
void simde_hvx_store_narrow_h_to_b(void *ptr, simde_hvx_vector_t vec) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  /* This would need a specific HVX intrinsic for narrowing stores */
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec);
  uint8_t *dst = (uint8_t *)ptr;
  for (size_t i = 0; i < 64; i++) { /* 64 halfwords -> 64 bytes */
    dst[i] = (uint8_t)vec_.u16[i];
  }
#else
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec);
  uint8_t *dst = (uint8_t *)ptr;

  /* Store lower bytes of halfwords */
  for (size_t i = 0; i < (sizeof(vec_.u16) / sizeof(vec_.u16[0])); i++) {
    dst[i] = (uint8_t)vec_.u16[i];
  }
#endif
}

/* Vector store halfwords from words - store lower halfwords of words */
SIMDE_FUNCTION_ATTRIBUTES
void simde_hvx_store_narrow_w_to_h(void *ptr, simde_hvx_vector_t vec) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec);
  uint16_t *dst = (uint16_t *)ptr;
  for (size_t i = 0; i < 32; i++) { /* 32 words -> 32 halfwords */
    dst[i] = (uint16_t)vec_.u32[i];
  }
#else
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec);
  uint16_t *dst = (uint16_t *)ptr;

  /* Store lower halfwords of words */
  for (size_t i = 0; i < (sizeof(vec_.u32) / sizeof(vec_.u32[0])); i++) {
    dst[i] = (uint16_t)vec_.u32[i];
  }
#endif
}

/* Vector store with saturation - store bytes with saturation from halfwords */
SIMDE_FUNCTION_ATTRIBUTES
void simde_hvx_store_saturate_h_to_b(void *ptr, simde_hvx_vector_t vec) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec);
  uint8_t *dst = (uint8_t *)ptr;
  for (size_t i = 0; i < 64; i++) { /* 64 halfwords -> 64 bytes */
    int16_t val = vec_.i16[i];
    if (val > UINT8_MAX) {
      dst[i] = UINT8_MAX;
    } else if (val < 0) {
      dst[i] = 0;
    } else {
      dst[i] = (uint8_t)val;
    }
  }
#else
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec);
  uint8_t *dst = (uint8_t *)ptr;

  /* Store bytes with saturation from halfwords */
  for (size_t i = 0; i < (sizeof(vec_.i16) / sizeof(vec_.i16[0])); i++) {
    int16_t val = vec_.i16[i];
    if (val > UINT8_MAX) {
      dst[i] = UINT8_MAX;
    } else if (val < 0) {
      dst[i] = 0;
    } else {
      dst[i] = (uint8_t)val;
    }
  }
#endif
}

/* Vector store with saturation - store halfwords with saturation from words */
SIMDE_FUNCTION_ATTRIBUTES
void simde_hvx_store_saturate_w_to_h(void *ptr, simde_hvx_vector_t vec) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec);
  uint16_t *dst = (uint16_t *)ptr;
  for (size_t i = 0; i < 32; i++) { /* 32 words -> 32 halfwords */
    int32_t val = vec_.i32[i];
    if (val > UINT16_MAX) {
      dst[i] = UINT16_MAX;
    } else if (val < 0) {
      dst[i] = 0;
    } else {
      dst[i] = (uint16_t)val;
    }
  }
#else
  simde_hvx_vector_private vec_ = simde_hvx_vector_to_private(vec);
  uint16_t *dst = (uint16_t *)ptr;

  /* Store halfwords with saturation from words */
  for (size_t i = 0; i < (sizeof(vec_.i32) / sizeof(vec_.i32[0])); i++) {
    int32_t val = vec_.i32[i];
    if (val > UINT16_MAX) {
      dst[i] = UINT16_MAX;
    } else if (val < 0) {
      dst[i] = 0;
    } else {
      dst[i] = (uint16_t)val;
    }
  }
#endif
}

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_STORE_H) */
