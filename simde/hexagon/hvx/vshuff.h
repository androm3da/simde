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

#if !defined(SIMDE_HEXAGON_HVX_VSHUFF_H)
#define SIMDE_HEXAGON_HVX_VSHUFF_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vshuff_Vb(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vshuff_Vb(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    size_t half = SIMDE_HVX_VECTOR_SIZE / 2;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      r_.u8[2 * i]     = a_.u8[i];
      r_.u8[2 * i + 1] = a_.u8[half + i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vshuff_Vb
  #define Q6_Vb_vshuff_Vb(Vu) simde_Q6_Vb_vshuff_Vb((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vshuff_Vh(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vshuff_Vh(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    size_t half = SIMDE_HVX_VECTOR_I16_COUNT / 2;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      r_.u16[2 * i]     = a_.u16[i];
      r_.u16[2 * i + 1] = a_.u16[half + i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vshuff_Vh
  #define Q6_Vh_vshuff_Vh(Vu) simde_Q6_Vh_vshuff_Vh((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vdeal_Vb(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vdeal_Vb(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    size_t half = SIMDE_HVX_VECTOR_SIZE / 2;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      r_.u8[i]        = a_.u8[2 * i];
      r_.u8[half + i] = a_.u8[2 * i + 1];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vdeal_Vb
  #define Q6_Vb_vdeal_Vb(Vu) simde_Q6_Vb_vdeal_Vb((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vdeal_Vh(simde_hvx_vector_t Vu) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vdeal_Vh(Vu);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    size_t half = SIMDE_HVX_VECTOR_I16_COUNT / 2;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < half ; i++) {
      r_.u16[i]        = a_.u16[2 * i];
      r_.u16[half + i] = a_.u16[2 * i + 1];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vdeal_Vh
  #define Q6_Vh_vdeal_Vh(Vu) simde_Q6_Vh_vdeal_Vh((Vu))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vshuffe_VbVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vshuffe_VbVb(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u8[2 * i]     = b_.u8[2 * i];
      r_.u8[2 * i + 1] = a_.u8[2 * i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vshuffe_VbVb
  #define Q6_Vb_vshuffe_VbVb(Vu, Vv) simde_Q6_Vb_vshuffe_VbVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vshuffo_VbVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vshuffo_VbVb(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.u8[2 * i]     = b_.u8[2 * i + 1];
      r_.u8[2 * i + 1] = a_.u8[2 * i + 1];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vshuffo_VbVb
  #define Q6_Vb_vshuffo_VbVb(Vu, Vv) simde_Q6_Vb_vshuffo_VbVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vshuffe_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vshuffe_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u16[2 * i]     = b_.u16[2 * i];
      r_.u16[2 * i + 1] = a_.u16[2 * i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vshuffe_VhVh
  #define Q6_Vh_vshuffe_VhVh(Vu, Vv) simde_Q6_Vh_vshuffe_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vshuffo_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vshuffo_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u16[2 * i]     = b_.u16[2 * i + 1];
      r_.u16[2 * i + 1] = a_.u16[2 * i + 1];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vshuffo_VhVh
  #define Q6_Vh_vshuffo_VhVh(Vu, Vv) simde_Q6_Vh_vshuffo_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wb_vshuffoe_VbVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wb_vshuffoe_VbVb(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      /* lo = vshuffe */
      r_.u8[2 * i]     = b_.u8[2 * i];
      r_.u8[2 * i + 1] = a_.u8[2 * i];
      /* hi = vshuffo */
      r_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i]     = b_.u8[2 * i + 1];
      r_.u8[SIMDE_HVX_VECTOR_SIZE + 2 * i + 1] = a_.u8[2 * i + 1];
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wb_vshuffoe_VbVb
  #define Q6_Wb_vshuffoe_VbVb(Vu, Vv) simde_Q6_Wb_vshuffoe_VbVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vshuffoe_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vshuffoe_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      /* lo = vshuffe */
      r_.u16[2 * i]     = b_.u16[2 * i];
      r_.u16[2 * i + 1] = a_.u16[2 * i];
      /* hi = vshuffo */
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i]     = b_.u16[2 * i + 1];
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i + 1] = a_.u16[2 * i + 1];
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vshuffoe_VhVh
  #define Q6_Wh_vshuffoe_VhVh(Vu, Vv) simde_Q6_Wh_vshuffoe_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vb_vdeale_VbVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vb_vdeale_VbVb(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    size_t quarter = SIMDE_HVX_VECTOR_SIZE / 4;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < quarter ; i++) {
      r_.u8[i]                = b_.u8[4 * i];
      r_.u8[quarter + i]     = b_.u8[4 * i + 2];
      r_.u8[2 * quarter + i] = a_.u8[4 * i];
      r_.u8[3 * quarter + i] = a_.u8[4 * i + 2];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vb_vdeale_VbVb
  #define Q6_Vb_vdeale_VbVb(Vu, Vv) simde_Q6_Vb_vdeale_VbVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_W_vshuff_VVR(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_W_vshuff_VVR(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      lo_ = simde_hvx_vector_to_private(Vv),
      hi_ = simde_hvx_vector_to_private(Vu);

    /* Butterfly stages: for offset = 1, 2, 4, ..., N/2 */
    for (size_t offset = 1 ; offset < SIMDE_HVX_VECTOR_SIZE ; offset <<= 1) {
      if (HEDLEY_STATIC_CAST(uint32_t, Rt) & offset) {
        for (size_t k = 0 ; k < SIMDE_HVX_VECTOR_SIZE ; k++) {
          if (!(k & offset)) {
            uint8_t tmp = hi_.u8[k];
            hi_.u8[k] = lo_.u8[k + offset];
            lo_.u8[k + offset] = tmp;
          }
        }
      }
    }

    simde_hvx_vectorpair_private r_;
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = lo_.u8[i];
      r_.u8[SIMDE_HVX_VECTOR_SIZE + i] = hi_.u8[i];
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_W_vshuff_VVR
  #define Q6_W_vshuff_VVR(Vu, Vv, Rt) simde_Q6_W_vshuff_VVR((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_W_vdeal_VVR(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_W_vdeal_VVR(Vu, Vv, Rt);
  #else
    simde_hvx_vector_private
      lo_ = simde_hvx_vector_to_private(Vv),
      hi_ = simde_hvx_vector_to_private(Vu);

    /* Butterfly stages in REVERSE order: offset = N/2, N/4, ..., 1 */
    for (size_t offset = SIMDE_HVX_VECTOR_SIZE >> 1 ; offset >= 1 ; offset >>= 1) {
      if (HEDLEY_STATIC_CAST(uint32_t, Rt) & offset) {
        for (size_t k = 0 ; k < SIMDE_HVX_VECTOR_SIZE ; k++) {
          if (!(k & offset)) {
            uint8_t tmp = hi_.u8[k];
            hi_.u8[k] = lo_.u8[k + offset];
            lo_.u8[k + offset] = tmp;
          }
        }
      }
    }

    simde_hvx_vectorpair_private r_;
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = lo_.u8[i];
      r_.u8[SIMDE_HVX_VECTOR_SIZE + i] = hi_.u8[i];
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_W_vdeal_VVR
  #define Q6_W_vdeal_VVR(Vu, Vv, Rt) simde_Q6_W_vdeal_VVR((Vu), (Vv), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Qb_vshuffe_QhQh(simde_hvx_vectorpred_t Qs, simde_hvx_vectorpred_t Qt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Qb_vshuffe_QhQh(Qs, Qt);
  #else
    simde_hvx_vectorpred_private
      r_,
      s_ = simde_hvx_vectorpred_to_private(Qs),
      t_ = simde_hvx_vectorpred_to_private(Qt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = (i & 1) ? s_.u8[i - 1] : t_.u8[i];
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Qb_vshuffe_QhQh
  #define Q6_Qb_vshuffe_QhQh(Qs, Qt) simde_Q6_Qb_vshuffe_QhQh((Qs), (Qt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpred_t
simde_Q6_Qh_vshuffe_QwQw(simde_hvx_vectorpred_t Qs, simde_hvx_vectorpred_t Qt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Qh_vshuffe_QwQw(Qs, Qt);
  #else
    simde_hvx_vectorpred_private
      r_,
      s_ = simde_hvx_vectorpred_to_private(Qs),
      t_ = simde_hvx_vectorpred_to_private(Qt);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      r_.u8[i] = (i & 2) ? s_.u8[i - 2] : t_.u8[i];
    }

    return simde_hvx_vectorpred_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Qh_vshuffe_QwQw
  #define Q6_Qh_vshuffe_QwQw(Qs, Qt) simde_Q6_Qh_vshuffe_QwQw((Qs), (Qt))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VSHUFF_H) */
