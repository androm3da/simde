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
 *   Qualcomm Technologies, Inc. and/or its subsidiaries.
 */

#if !defined(SIMDE_HEXAGON_HVX_VMEM_H)
#define SIMDE_HEXAGON_HVX_VMEM_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vmem_QRIV(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t* Rt, simde_hvx_vector_t Vs) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vmem_QRIV)
    Q6_vmem_QRIV(Qv, (HVX_Vector*)Rt, Vs);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private s_ = simde_hvx_vector_to_private(Vs);
    simde_hvx_vector_private d_ = simde_hvx_vector_to_private(*Rt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      if (q_.u8[i]) d_.u8[i] = s_.u8[i];
    }

    *Rt = simde_hvx_vector_from_private(d_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vmem_QRIV
  #define Q6_vmem_QRIV(Qv, Rt, Vs) simde_Q6_vmem_QRIV((Qv), (Rt), (Vs))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vmem_QnRIV(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t* Rt, simde_hvx_vector_t Vs) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vmem_QnRIV)
    Q6_vmem_QnRIV(Qv, (HVX_Vector*)Rt, Vs);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private s_ = simde_hvx_vector_to_private(Vs);
    simde_hvx_vector_private d_ = simde_hvx_vector_to_private(*Rt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      if (!q_.u8[i]) d_.u8[i] = s_.u8[i];
    }

    *Rt = simde_hvx_vector_from_private(d_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vmem_QnRIV
  #define Q6_vmem_QnRIV(Qv, Rt, Vs) simde_Q6_vmem_QnRIV((Qv), (Rt), (Vs))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vmem_QRIV_nt(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t* Rt, simde_hvx_vector_t Vs) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vmem_QRIV_nt)
    Q6_vmem_QRIV_nt(Qv, (HVX_Vector*)Rt, Vs);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private s_ = simde_hvx_vector_to_private(Vs);
    simde_hvx_vector_private d_ = simde_hvx_vector_to_private(*Rt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      if (q_.u8[i]) d_.u8[i] = s_.u8[i];
    }

    *Rt = simde_hvx_vector_from_private(d_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vmem_QRIV_nt
  #define Q6_vmem_QRIV_nt(Qv, Rt, Vs) simde_Q6_vmem_QRIV_nt((Qv), (Rt), (Vs))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vmem_QnRIV_nt(simde_hvx_vectorpred_t Qv, simde_hvx_vector_t* Rt, simde_hvx_vector_t Vs) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vmem_QnRIV_nt)
    Q6_vmem_QnRIV_nt(Qv, (HVX_Vector*)Rt, Vs);
  #else
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qv);
    simde_hvx_vector_private s_ = simde_hvx_vector_to_private(Vs);
    simde_hvx_vector_private d_ = simde_hvx_vector_to_private(*Rt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      if (!q_.u8[i]) d_.u8[i] = s_.u8[i];
    }

    *Rt = simde_hvx_vector_from_private(d_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vmem_QnRIV_nt
  #define Q6_vmem_QnRIV_nt(Qv, Rt, Vs) simde_Q6_vmem_QnRIV_nt((Qv), (Rt), (Vs))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VMEM_H) */
