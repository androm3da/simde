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

#if !defined(SIMDE_HEXAGON_HVX_VGATHER_H)
#define SIMDE_HEXAGON_HVX_VGATHER_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vgather_ARMVh(simde_hvx_vector_t* Rs, intptr_t Rt, int32_t Mu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vgather_ARMVh)
    Q6_vgather_ARMVh((HVX_Vector*)Rs, Rt, Mu, Vv);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 1));
    simde_hvx_vector_private v_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vector_private r_ = simde_hvx_vector_to_private(*Rs);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 1u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint32_t offset = HEDLEY_STATIC_CAST(uint32_t, v_.u16[i]);
      if (offset <= region) {
        uint16_t tmp;
        simde_memcpy(&tmp, base + offset, 2);
        r_.u16[i] = tmp;
      }
    }

    *Rs = simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vgather_ARMVh
  #define Q6_vgather_ARMVh(Rs, Rt, Mu, Vv) simde_Q6_vgather_ARMVh((Rs), (Rt), (Mu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vgather_ARMVw(simde_hvx_vector_t* Rs, intptr_t Rt, int32_t Mu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vgather_ARMVw)
    Q6_vgather_ARMVw((HVX_Vector*)Rs, Rt, Mu, Vv);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 3));
    simde_hvx_vector_private v_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vector_private r_ = simde_hvx_vector_to_private(*Rs);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 3u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      uint32_t offset = v_.u32[i];
      if (offset <= region) {
        uint32_t tmp;
        simde_memcpy(&tmp, base + offset, 4);
        r_.u32[i] = tmp;
      }
    }

    *Rs = simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vgather_ARMVw
  #define Q6_vgather_ARMVw(Rs, Rt, Mu, Vv) simde_Q6_vgather_ARMVw((Rs), (Rt), (Mu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vgather_ARMWw(simde_hvx_vector_t* Rs, intptr_t Rt, int32_t Mu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vgather_ARMWw)
    Q6_vgather_ARMWw((HVX_Vector*)Rs, Rt, Mu, Vvv);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 1));
    simde_hvx_vectorpair_private vv_ = simde_hvx_vectorpair_to_private(Vvv);
    simde_hvx_vector_private r_ = simde_hvx_vector_to_private(*Rs);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 1u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      for (size_t j = 0 ; j < 2 ; j++) {
        uint32_t offset = vv_.u32[(j * SIMDE_HVX_VECTOR_I32_COUNT) + i];
        if (offset <= region) {
          uint16_t tmp;
          simde_memcpy(&tmp, base + offset, 2);
          r_.u16[(2 * i) + j] = tmp;
        }
      }
    }

    *Rs = simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vgather_ARMWw
  #define Q6_vgather_ARMWw(Rs, Rt, Mu, Vvv) simde_Q6_vgather_ARMWw((Rs), (Rt), (Mu), (Vvv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vgather_AQRMVh(simde_hvx_vector_t* Rs, simde_hvx_vectorpred_t Qs, intptr_t Rt, int32_t Mu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vgather_AQRMVh)
    Q6_vgather_AQRMVh((HVX_Vector*)Rs, Qs, Rt, Mu, Vv);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 1));
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qs);
    simde_hvx_vector_private v_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vector_private r_ = simde_hvx_vector_to_private(*Rs);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 1u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      if (q_.u8[i * 2]) {
        uint32_t offset = HEDLEY_STATIC_CAST(uint32_t, v_.u16[i]);
        if (offset <= region) {
          uint16_t tmp;
          simde_memcpy(&tmp, base + offset, 2);
          r_.u16[i] = tmp;
        }
      }
    }

    *Rs = simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vgather_AQRMVh
  #define Q6_vgather_AQRMVh(Rs, Qs, Rt, Mu, Vv) simde_Q6_vgather_AQRMVh((Rs), (Qs), (Rt), (Mu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vgather_AQRMVw(simde_hvx_vector_t* Rs, simde_hvx_vectorpred_t Qs, intptr_t Rt, int32_t Mu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vgather_AQRMVw)
    Q6_vgather_AQRMVw((HVX_Vector*)Rs, Qs, Rt, Mu, Vv);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 3));
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qs);
    simde_hvx_vector_private v_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vector_private r_ = simde_hvx_vector_to_private(*Rs);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 3u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      if (q_.u8[i * 4]) {
        uint32_t offset = v_.u32[i];
        if (offset <= region) {
          uint32_t tmp;
          simde_memcpy(&tmp, base + offset, 4);
          r_.u32[i] = tmp;
        }
      }
    }

    *Rs = simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vgather_AQRMVw
  #define Q6_vgather_AQRMVw(Rs, Qs, Rt, Mu, Vv) simde_Q6_vgather_AQRMVw((Rs), (Qs), (Rt), (Mu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
void
simde_Q6_vgather_AQRMWw(simde_hvx_vector_t* Rs, simde_hvx_vectorpred_t Qs, intptr_t Rt, int32_t Mu, simde_hvx_vectorpair_t Vvv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_vgather_AQRMWw)
    Q6_vgather_AQRMWw((HVX_Vector*)Rs, Qs, Rt, Mu, Vvv);
  #else
    uint8_t* base = HEDLEY_REINTERPRET_CAST(uint8_t*, HEDLEY_STATIC_CAST(uintptr_t, Rt) & ~HEDLEY_STATIC_CAST(uintptr_t, 1));
    simde_hvx_vectorpred_private q_ = simde_hvx_vectorpred_to_private(Qs);
    simde_hvx_vectorpair_private vv_ = simde_hvx_vectorpair_to_private(Vvv);
    simde_hvx_vector_private r_ = simde_hvx_vector_to_private(*Rs);
    uint32_t region = (HEDLEY_STATIC_CAST(uint32_t, Mu) & 0x1FFFFu) | 1u;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      for (size_t j = 0 ; j < 2 ; j++) {
        size_t lane = (2 * i) + j;
        if (q_.u8[lane * 2]) {
          uint32_t offset = vv_.u32[(j * SIMDE_HVX_VECTOR_I32_COUNT) + i];
          if (offset <= region) {
            uint16_t tmp;
            simde_memcpy(&tmp, base + offset, 2);
            r_.u16[lane] = tmp;
          }
        }
      }
    }

    *Rs = simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_vgather_AQRMWw
  #define Q6_vgather_AQRMWw(Rs, Qs, Rt, Mu, Vvv) simde_Q6_vgather_AQRMWw((Rs), (Qs), (Rt), (Mu), (Vvv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VGATHER_H) */
