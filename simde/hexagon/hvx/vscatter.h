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

#if !defined(SIMDE_HEXAGON_HVX_VSCATTER_H)
#define SIMDE_HEXAGON_HVX_VSCATTER_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vscatter_RMVhV(intptr_t Rt, int32_t Mu, simde_hvx_vector_t Vv, simde_hvx_vector_t Vw) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vscatter_RMVhV)
    Q6_vscatter_RMVhV(Rt, Mu, Vv, Vw);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 1));
    simde_hvx_vector_private v_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vector_private w_ = simde_hvx_vector_to_private(Vw);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 1u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint32_t offset = HEDLEY_STATIC_CAST(uint32_t, v_.u16[i]);
      if (offset <= region) {
        uint16_t tmp = w_.u16[i];
        simde_memcpy(base + offset, &tmp, 2);
      }
    }
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vscatter_RMVhV
  #define Q6_vscatter_RMVhV(Rt, Mu, Vv, Vw) simde_Q6_vscatter_RMVhV((Rt), (Mu), (Vv), (Vw))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vscatter_RMVwV(intptr_t Rt, int32_t Mu, simde_hvx_vector_t Vv, simde_hvx_vector_t Vw) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vscatter_RMVwV)
    Q6_vscatter_RMVwV(Rt, Mu, Vv, Vw);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 3));
    simde_hvx_vector_private v_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vector_private w_ = simde_hvx_vector_to_private(Vw);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 3u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint32_t offset = v_.u32[i];
      if (offset <= region) {
        uint32_t tmp = w_.u32[i];
        simde_memcpy(base + offset, &tmp, 4);
      }
    }
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vscatter_RMVwV
  #define Q6_vscatter_RMVwV(Rt, Mu, Vv, Vw) simde_Q6_vscatter_RMVwV((Rt), (Mu), (Vv), (Vw))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vscatter_RMWwV(intptr_t Rt, int32_t Mu, simde_hvx_vectorpair_t Vvv, simde_hvx_vector_t Vw) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vscatter_RMWwV)
    Q6_vscatter_RMWwV(Rt, Mu, Vvv, Vw);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 1));
    simde_hvx_vectorpair_private vv_ = simde_hvx_vectorpair_to_private(Vvv);
    simde_hvx_vector_private w_ = simde_hvx_vector_to_private(Vw);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 1u;

    for (size_t i = 0 ; i < (2 * SIMDE_HVX_VECTOR_I32_COUNT) ; i++) {
      uint32_t offset = vv_.u32[i];
      if (offset <= region) {
        uint16_t tmp = w_.u16[i];
        simde_memcpy(base + offset, &tmp, 2);
      }
    }
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vscatter_RMWwV
  #define Q6_vscatter_RMWwV(Rt, Mu, Vvv, Vw) simde_Q6_vscatter_RMWwV((Rt), (Mu), (Vvv), (Vw))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vscatteracc_RMVhV(intptr_t Rt, int32_t Mu, simde_hvx_vector_t Vv, simde_hvx_vector_t Vw) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vscatteracc_RMVhV)
    Q6_vscatteracc_RMVhV(Rt, Mu, Vv, Vw);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 1));
    simde_hvx_vector_private v_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vector_private w_ = simde_hvx_vector_to_private(Vw);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 1u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint32_t offset = HEDLEY_STATIC_CAST(uint32_t, v_.u16[i]) & 0xFFFEu;
      if (offset <= region) {
        uint16_t existing;
        simde_memcpy(&existing, base + offset, 2);
        uint16_t result = HEDLEY_STATIC_CAST(uint16_t, existing + w_.u16[i]);
        simde_memcpy(base + offset, &result, 2);
      }
    }
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vscatteracc_RMVhV
  #define Q6_vscatteracc_RMVhV(Rt, Mu, Vv, Vw) simde_Q6_vscatteracc_RMVhV((Rt), (Mu), (Vv), (Vw))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vscatteracc_RMVwV(intptr_t Rt, int32_t Mu, simde_hvx_vector_t Vv, simde_hvx_vector_t Vw) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vscatteracc_RMVwV)
    Q6_vscatteracc_RMVwV(Rt, Mu, Vv, Vw);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 3));
    simde_hvx_vector_private v_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vector_private w_ = simde_hvx_vector_to_private(Vw);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 3u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint32_t offset = v_.u32[i] & 0xFFFFFFFCu;
      if (offset <= region) {
        uint32_t existing;
        simde_memcpy(&existing, base + offset, 4);
        uint32_t result = existing + w_.u32[i];
        simde_memcpy(base + offset, &result, 4);
      }
    }
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vscatteracc_RMVwV
  #define Q6_vscatteracc_RMVwV(Rt, Mu, Vv, Vw) simde_Q6_vscatteracc_RMVwV((Rt), (Mu), (Vv), (Vw))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vscatteracc_RMWwV(intptr_t Rt, int32_t Mu, simde_hvx_vectorpair_t Vvv, simde_hvx_vector_t Vw) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vscatteracc_RMWwV)
    Q6_vscatteracc_RMWwV(Rt, Mu, Vvv, Vw);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 1));
    simde_hvx_vectorpair_private vv_ = simde_hvx_vectorpair_to_private(Vvv);
    simde_hvx_vector_private w_ = simde_hvx_vector_to_private(Vw);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 1u;

    for (size_t i = 0 ; i < (2 * SIMDE_HVX_VECTOR_I32_COUNT) ; i++) {
      uint32_t offset = vv_.u32[i] & 0xFFFFFFFEu;
      if (offset <= region) {
        uint16_t existing;
        simde_memcpy(&existing, base + offset, 2);
        uint16_t result = HEDLEY_STATIC_CAST(uint16_t, existing + w_.u16[i]);
        simde_memcpy(base + offset, &result, 2);
      }
    }
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vscatteracc_RMWwV
  #define Q6_vscatteracc_RMWwV(Rt, Mu, Vvv, Vw) simde_Q6_vscatteracc_RMWwV((Rt), (Mu), (Vvv), (Vw))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vscatter_QRMVhV(simde_hvx_vectorpred_t Qs, intptr_t Rt, int32_t Mu, simde_hvx_vector_t Vv, simde_hvx_vector_t Vw) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vscatter_QRMVhV)
    Q6_vscatter_QRMVhV(Qs, Rt, Mu, Vv, Vw);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 1));
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qs);
    simde_hvx_vector_private v_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vector_private w_ = simde_hvx_vector_to_private(Vw);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 1u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      if (q_.u8[i * 2]) {
        uint32_t offset = HEDLEY_STATIC_CAST(uint32_t, v_.u16[i]);
        if (offset <= region) {
          uint16_t tmp = w_.u16[i];
          simde_memcpy(base + offset, &tmp, 2);
        }
      }
    }
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vscatter_QRMVhV
  #define Q6_vscatter_QRMVhV(Qs, Rt, Mu, Vv, Vw) simde_Q6_vscatter_QRMVhV((Qs), (Rt), (Mu), (Vv), (Vw))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vscatter_QRMVwV(simde_hvx_vectorpred_t Qs, intptr_t Rt, int32_t Mu, simde_hvx_vector_t Vv, simde_hvx_vector_t Vw) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vscatter_QRMVwV)
    Q6_vscatter_QRMVwV(Qs, Rt, Mu, Vv, Vw);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 3));
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qs);
    simde_hvx_vector_private v_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vector_private w_ = simde_hvx_vector_to_private(Vw);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 3u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      if (q_.u8[i * 4]) {
        uint32_t offset = v_.u32[i];
        if (offset <= region) {
          uint32_t tmp = w_.u32[i];
          simde_memcpy(base + offset, &tmp, 4);
        }
      }
    }
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vscatter_QRMVwV
  #define Q6_vscatter_QRMVwV(Qs, Rt, Mu, Vv, Vw) simde_Q6_vscatter_QRMVwV((Qs), (Rt), (Mu), (Vv), (Vw))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vscatter_QRMWwV(simde_hvx_vectorpred_t Qs, intptr_t Rt, int32_t Mu, simde_hvx_vectorpair_t Vvv, simde_hvx_vector_t Vw) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vscatter_QRMWwV)
    Q6_vscatter_QRMWwV(Qs, Rt, Mu, Vvv, Vw);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 1));
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qs);
    simde_hvx_vectorpair_private vv_ = simde_hvx_vectorpair_to_private(Vvv);
    simde_hvx_vector_private w_ = simde_hvx_vector_to_private(Vw);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 1u;

    for (size_t i = 0 ; i < (2 * SIMDE_HVX_VECTOR_I32_COUNT) ; i++) {
      if (q_.u8[i * 2]) {
        uint32_t offset = vv_.u32[i];
        if (offset <= region) {
          uint16_t tmp = w_.u16[i];
          simde_memcpy(base + offset, &tmp, 2);
        }
      }
    }
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vscatter_QRMWwV
  #define Q6_vscatter_QRMWwV(Qs, Rt, Mu, Vvv, Vw) simde_Q6_vscatter_QRMWwV((Qs), (Rt), (Mu), (Vvv), (Vw))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VSCATTER_H) */
