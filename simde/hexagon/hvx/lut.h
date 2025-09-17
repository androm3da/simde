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

#if !defined(SIMDE_HEXAGON_HVX_LUT_H)
#define SIMDE_HEXAGON_HVX_LUT_H

#include "../types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

/* 32-entry byte lookup table */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vlut32_bbb(simde_hvx_vector_t indices, simde_hvx_vector_t table, int32_t selector) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vlut32_VbVbR(indices, table, selector);
#else
  simde_hvx_vector_private r_, indices_ = simde_hvx_vector_to_private(indices), table_ = simde_hvx_vector_to_private(table);

  /* HVX vlut32 uses 32 bytes of table data, with 5-bit indices */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u8) / sizeof(r_.u8[0])); i++) {
    uint8_t index = indices_.u8[i] & 0x1F;     /* 5-bit mask for 32 entries */
    size_t table_base = (selector & 0x1) * 32; /* Select which 32-byte segment */
    if (index < 32 && (table_base + index) < sizeof(table_.u8)) {
      r_.u8[i] = table_.u8[table_base + index];
    } else {
      r_.u8[i] = 0; /* Out of range returns 0 */
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vlut32_VbVbR
#define Q6_Vb_vlut32_VbVbR(indices, table, selector) simde_hvx_vlut32_bbb((indices), (table), (selector))
#endif

/* Vector alignment with runtime offset */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_valign_vvr(simde_hvx_vector_t hi, simde_hvx_vector_t lo, int32_t offset) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_valign_VVR(hi, lo, offset);
#else
  simde_hvx_vector_private r_, hi_ = simde_hvx_vector_to_private(hi), lo_ = simde_hvx_vector_to_private(lo);

  /* Offset is in bytes, modulo vector size */
  size_t vector_size = sizeof(r_.u8);
  offset = offset % (int32_t)vector_size;
  if (offset < 0)
    offset += (int32_t)vector_size;

  SIMDE_VECTORIZE
  for (size_t i = 0; i < vector_size; i++) {
    size_t src_idx = (i + (size_t)offset) % vector_size;
    if (src_idx < vector_size / 2) {
      r_.u8[i] = lo_.u8[src_idx + vector_size / 2];
    } else {
      r_.u8[i] = hi_.u8[src_idx - vector_size / 2];
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_valign_VVR
#define Q6_V_valign_VVR(hi, lo, offset) simde_hvx_valign_vvr((hi), (lo), (offset))
#endif

/* Deal bytes (deinterleave within vector) */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vdeal_b(simde_hvx_vector_t v) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vb_vdeal_Vb(v);
#else
  simde_hvx_vector_private r_, v_ = simde_hvx_vector_to_private(v);

  size_t half_size = (sizeof(r_.u8) / sizeof(r_.u8[0])) / 2;

  /* Separate even and odd elements */
  SIMDE_VECTORIZE
  for (size_t i = 0; i < half_size; i++) {
    r_.u8[i] = v_.u8[i * 2];                 /* Even elements in first half */
    r_.u8[i + half_size] = v_.u8[i * 2 + 1]; /* Odd elements in second half */
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vb_vdeal_Vb
#define Q6_Vb_vdeal_Vb(v) simde_hvx_vdeal_b((v))
#endif

/* 4-entry halfword lookup table using pair register */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vlut4_uh_ph(simde_hvx_vector_t indices, simde_hvx_vector_pair_t table_pair) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_Vh_vlut4_VuhPh(indices, table_pair);
#else
  simde_hvx_vector_private r_, indices_ = simde_hvx_vector_to_private(indices);
  simde_hvx_vector_pair_private table_pair_ = simde_hvx_vector_pair_to_private(table_pair);

  /* Extract table data from the vector pair (first 4 halfwords) */
  simde_hvx_vector_private lo_table = simde_hvx_vector_to_private(table_pair_.val[0]);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < (sizeof(r_.u16) / sizeof(r_.u16[0])); i++) {
    uint16_t index = indices_.u16[i] & 0x3; /* 2-bit mask for 4 entries */
    if (index < 4) {
      r_.u16[i] = lo_table.u16[index];
    } else {
      r_.u16[i] = 0;
    }
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_Vh_vlut4_VuhPh
#define Q6_Vh_vlut4_VuhPh(indices, table_pair) simde_hvx_vlut4_uh_ph((indices), (table_pair))
#endif

/* Vector delta permutation */
SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t simde_hvx_vdelta_vv(simde_hvx_vector_t a, simde_hvx_vector_t b) {
#if defined(SIMDE_HEXAGON_HVX_NATIVE)
  return Q6_V_vdelta_VV(a, b);
#else
  simde_hvx_vector_private r_, a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  /* Delta operation: for each byte position i,
     result[i] = a[b[i] & mask] where mask ensures valid index */
  size_t vector_size = sizeof(r_.u8) / sizeof(r_.u8[0]);

  SIMDE_VECTORIZE
  for (size_t i = 0; i < vector_size; i++) {
    uint8_t delta_index = b_.u8[i] & (uint8_t)(vector_size - 1);
    r_.u8[i] = a_.u8[delta_index];
  }

  return simde_hvx_vector_from_private(r_);
#endif
}
#if defined(SIMDE_HEXAGON_ENABLE_NATIVE_ALIASES)
#undef Q6_V_vdelta_VV
#define Q6_V_vdelta_VV(a, b) simde_hvx_vdelta_vv((a), (b))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_LUT_H) */
