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

#if !defined(SIMDE_HEXAGON_HVX_QADD_H)
#define SIMDE_HEXAGON_HVX_QADD_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* Saturated add signed bytes */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_qadd_vb(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vqadd_VbVb(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])); i++) {
    int16_t result = (int16_t)a_.i8[i] + (int16_t)b_.i8[i];
    if (result > INT8_MAX) {
      r_.i8[i] = INT8_MAX;
    } else if (result < INT8_MIN) {
      r_.i8[i] = INT8_MIN;
    } else {
      r_.i8[i] = (int8_t)result;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vqadd_VbVb
#define Q6_Vb_vqadd_VbVb(a, b) simde_hvx_qadd_vb((a), (b))
#endif

/* Saturated add unsigned bytes */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_qadd_vub(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vqadd_VubVub(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    uint16_t result = (uint16_t)a_.u8[i] + (uint16_t)b_.u8[i];
    if (result > UINT8_MAX) {
      r_.u8[i] = UINT8_MAX;
    } else {
      r_.u8[i] = (uint8_t)result;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vqadd_VubVub
#define Q6_Vub_vqadd_VubVub(a, b) simde_hvx_qadd_vub((a), (b))
#endif

/* Saturated add signed halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_qadd_vh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vqadd_VhVh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i16) / sizeof(r_.i16[0])); i++) {
    int32_t result = (int32_t)a_.i16[i] + (int32_t)b_.i16[i];
    if (result > INT16_MAX) {
      r_.i16[i] = INT16_MAX;
    } else if (result < INT16_MIN) {
      r_.i16[i] = INT16_MIN;
    } else {
      r_.i16[i] = (int16_t)result;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vqadd_VhVh
#define Q6_Vh_vqadd_VhVh(a, b) simde_hvx_qadd_vh((a), (b))
#endif

/* Saturated add unsigned halfwords */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_qadd_vuh(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vuh_vqadd_VuhVuh(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    uint32_t result = (uint32_t)a_.u16[i] + (uint32_t)b_.u16[i];
    if (result > UINT16_MAX) {
      r_.u16[i] = UINT16_MAX;
    } else {
      r_.u16[i] = (uint16_t)result;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vuh_vqadd_VuhVuh
#define Q6_Vuh_vqadd_VuhVuh(a, b) simde_hvx_qadd_vuh((a), (b))
#endif

/* Saturated subtract signed bytes */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_qsub_vb(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vqsub_VbVb(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.i8) / sizeof(r_.i8[0])); i++) {
    int16_t result = (int16_t)a_.i8[i] - (int16_t)b_.i8[i];
    if (result > INT8_MAX) {
      r_.i8[i] = INT8_MAX;
    } else if (result < INT8_MIN) {
      r_.i8[i] = INT8_MIN;
    } else {
      r_.i8[i] = (int8_t)result;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vqsub_VbVb
#define Q6_Vb_vqsub_VbVb(a, b) simde_hvx_qsub_vb((a), (b))
#endif

/* Saturated subtract unsigned bytes */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_qsub_vub(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vub_vqsub_VubVub(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    if (a_.u8[i] > b_.u8[i]) {
      r_.u8[i] = a_.u8[i] - b_.u8[i];
    } else {
      r_.u8[i] = 0; /* Saturate to 0 for unsigned */
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vub_vqsub_VubVub
#define Q6_Vub_vqsub_VubVub(a, b) simde_hvx_qsub_vub((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_QADD_H) */
