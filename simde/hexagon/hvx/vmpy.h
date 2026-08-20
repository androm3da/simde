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

#if !defined(SIMDE_HEXAGON_HVX_VMPY_H)
#define SIMDE_HEXAGON_HVX_VMPY_H

#include "types.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpy_VbVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpy_VbVb(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.i16[j] = HEDLEY_STATIC_CAST(int16_t, a_.i8[2 * j]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[2 * j]);
      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + j] = HEDLEY_STATIC_CAST(int16_t, a_.i8[2 * j + 1]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpy_VbVb
  #define Q6_Wh_vmpy_VbVb(Vu, Vv) simde_Q6_Wh_vmpy_VbVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpy_VubVb(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpy_VubVb(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.i16[j] = HEDLEY_STATIC_CAST(int16_t, HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j])) * HEDLEY_STATIC_CAST(int16_t, b_.i8[2 * j]);
      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + j] = HEDLEY_STATIC_CAST(int16_t, HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j + 1])) * HEDLEY_STATIC_CAST(int16_t, b_.i8[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpy_VubVb
  #define Q6_Wh_vmpy_VubVb(Vu, Vv) simde_Q6_Wh_vmpy_VubVb((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuh_vmpy_VubVub(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuh_vmpy_VubVub(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.u16[j] = HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j]) * HEDLEY_STATIC_CAST(uint16_t, b_.u8[2 * j]);
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + j] = HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j + 1]) * HEDLEY_STATIC_CAST(uint16_t, b_.u8[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuh_vmpy_VubVub
  #define Q6_Wuh_vmpy_VubVub(Vu, Vv) simde_Q6_Wuh_vmpy_VubVub((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpy_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpy_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.i32[j] = HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[2 * j]);
      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + j] = HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j + 1]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpy_VhVh
  #define Q6_Ww_vmpy_VhVh(Vu, Vv) simde_Q6_Ww_vmpy_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vmpy_VuhVuh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuw_vmpy_VuhVuh(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.u32[j] = HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * j]) * HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j]);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + j] = HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * j + 1]) * HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vmpy_VuhVuh
  #define Q6_Wuw_vmpy_VuhVuh(Vu, Vv) simde_Q6_Wuw_vmpy_VuhVuh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vmpyi_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vmpyi_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[i]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vmpyi_VhVh
  #define Q6_Vh_vmpyi_VhVh(Vu, Vv) simde_Q6_Vh_vmpyi_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vmpyi_VhRb(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vmpyi_VhRb(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
                    HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) *
                    HEDLEY_STATIC_CAST(int32_t, rb[i % 4]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vmpyi_VhRb
  #define Q6_Vh_vmpyi_VhRb(Vu, Rt) simde_Q6_Vh_vmpyi_VhRb((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyie_VwVuh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyie_VwVuh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * i])));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyie_VwVuh
  #define Q6_Vw_vmpyie_VwVuh(Vu, Vv) simde_Q6_Vw_vmpyie_VwVuh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyieo_VhVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyieo_VhVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t,
        HEDLEY_STATIC_CAST(uint32_t, HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * i]) *
          HEDLEY_STATIC_CAST(int32_t, b_.i16[2 * i + 1])) << 16);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyieo_VhVh
  #define Q6_Vw_vmpyieo_VhVh(Vu, Vv) simde_Q6_Vw_vmpyieo_VhVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyi_VwRb(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyi_VwRb(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t,
                    HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) *
                    HEDLEY_STATIC_CAST(int64_t, rb[i % 4]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyi_VwRb
  #define Q6_Vw_vmpyi_VwRb(Vu, Rt) simde_Q6_Vw_vmpyi_VwRb((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vmpyiacc_VhVhVh(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vmpyiacc_VhVhVh(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
                    x_.i16[i] +
                    HEDLEY_STATIC_CAST(int16_t,
                      HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) *
                      HEDLEY_STATIC_CAST(int32_t, b_.i16[i])));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vmpyiacc_VhVhVh
  #define Q6_Vh_vmpyiacc_VhVhVh(Vx, Vu, Vv) simde_Q6_Vh_vmpyiacc_VhVhVh((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vmpyiacc_VhVhRb(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vmpyiacc_VhVhRb(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t,
                    x_.i16[i] +
                    HEDLEY_STATIC_CAST(int16_t,
                      HEDLEY_STATIC_CAST(int32_t, a_.i16[i]) *
                      HEDLEY_STATIC_CAST(int32_t, rb[i % 4])));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vmpyiacc_VhVhRb
  #define Q6_Vh_vmpyiacc_VhVhRb(Vx, Vu, Rt) simde_Q6_Vh_vmpyiacc_VhVhRb((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyiacc_VwVwRb(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyiacc_VwVwRb(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t,
                    HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) +
                    HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) *
                    HEDLEY_STATIC_CAST(int64_t, rb[i % 4]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyiacc_VwVwRb
  #define Q6_Vw_vmpyiacc_VwVwRb(Vx, Vu, Rt) simde_Q6_Vw_vmpyiacc_VwVwRb((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyiacc_VwVwRh(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyiacc_VwVwRh(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    int16_t rh[2];
    rh[0] = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    rh[1] = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t,
                    HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) +
                    HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) *
                    HEDLEY_STATIC_CAST(int64_t, rh[i % 2]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyiacc_VwVwRh
  #define Q6_Vw_vmpyiacc_VwVwRh(Vx, Vu, Rt) simde_Q6_Vw_vmpyiacc_VwVwRh((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyiacc_VwVwRub(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyiacc_VwVwRub(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t,
                    HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) +
                    HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) *
                    HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint32_t, rub[i % 4])));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyiacc_VwVwRub
  #define Q6_Vw_vmpyiacc_VwVwRub(Vx, Vu, Rt) simde_Q6_Vw_vmpyiacc_VwVwRub((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyieacc_VwVwVh(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyieacc_VwVwVh(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t,
                    HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) +
                    HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) *
                    HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * i]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyieacc_VwVwVh
  #define Q6_Vw_vmpyieacc_VwVwVh(Vx, Vu, Vv) simde_Q6_Vw_vmpyieacc_VwVwVh((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyieacc_VwVwVuh(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyieacc_VwVwVuh(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t,
                    HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) +
                    HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) *
                    HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * i])));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyieacc_VwVwVuh
  #define Q6_Vw_vmpyieacc_VwVwVuh(Vx, Vu, Vv) simde_Q6_Vw_vmpyieacc_VwVwVuh((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyo_VwVh_s1_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyo_VwVh_s1_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t prod = HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * i + 1]);
      int64_t result = (prod * 2) >> 16;
      if (result > INT32_MAX) result = INT32_MAX;
      else if (result < INT32_MIN) result = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, result);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyo_VwVh_s1_sat
  #define Q6_Vw_vmpyo_VwVh_s1_sat(Vu, Vv) simde_Q6_Vw_vmpyo_VwVh_s1_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyo_VwVh_s1_rnd_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyo_VwVh_s1_rnd_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t prod = HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * i + 1]);
      int64_t result = ((prod * 2) + 0x8000) >> 16;
      if (result > INT32_MAX) result = INT32_MAX;
      else if (result < INT32_MIN) result = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, result);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyo_VwVh_s1_rnd_sat
  #define Q6_Vw_vmpyo_VwVh_s1_rnd_sat(Vu, Vv) simde_Q6_Vw_vmpyo_VwVh_s1_rnd_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyoacc_VwVwVh_s1_sat_shift(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyoacc_VwVwVh_s1_sat_shift(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t prod = HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * i + 1]);
      int64_t sum = ((HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) + prod) >> 14) >> 1;
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyoacc_VwVwVh_s1_sat_shift
  #define Q6_Vw_vmpyoacc_VwVwVh_s1_sat_shift(Vx, Vu, Vv) simde_Q6_Vw_vmpyoacc_VwVwVh_s1_sat_shift((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyoacc_VwVwVh_s1_rnd_sat_shift(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyoacc_VwVwVh_s1_rnd_sat_shift(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      int64_t prod = HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * i + 1]);
      int64_t sum = (((HEDLEY_STATIC_CAST(int64_t, x_.i32[i]) + prod) >> 14) + 1) >> 1;
      if (sum > INT32_MAX) sum = INT32_MAX;
      else if (sum < INT32_MIN) sum = INT32_MIN;
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, sum);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyoacc_VwVwVh_s1_rnd_sat_shift
  #define Q6_Vw_vmpyoacc_VwVwVh_s1_rnd_sat_shift(Vx, Vu, Vv) simde_Q6_Vw_vmpyoacc_VwVwVh_s1_rnd_sat_shift((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpy_VubRb(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpy_VubRb(Vu, Rt);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.i16[j] = HEDLEY_STATIC_CAST(int16_t, a_.u8[2 * j]) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * j) % 4]);
      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + j] = HEDLEY_STATIC_CAST(int16_t, a_.u8[2 * j + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * j + 1) % 4]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpy_VubRb
  #define Q6_Wh_vmpy_VubRb(Vu, Rt) simde_Q6_Wh_vmpy_VubRb((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpy_VhRh(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpy_VhRh(Vu, Rt);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    int16_t rh[2];
    rh[0] = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    rh[1] = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.i32[j] = HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j]) * HEDLEY_STATIC_CAST(int32_t, rh[0]);
      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + j] = HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j + 1]) * HEDLEY_STATIC_CAST(int32_t, rh[1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpy_VhRh
  #define Q6_Ww_vmpy_VhRh(Vu, Rt) simde_Q6_Ww_vmpy_VhRh((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuh_vmpy_VubRub(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuh_vmpy_VubRub(Vu, Rt);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.u16[j] = HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j]) * HEDLEY_STATIC_CAST(uint16_t, rub[(2 * j) % 4]);
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + j] = HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j + 1]) * HEDLEY_STATIC_CAST(uint16_t, rub[(2 * j + 1) % 4]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuh_vmpy_VubRub
  #define Q6_Wuh_vmpy_VubRub(Vu, Rt) simde_Q6_Wuh_vmpy_VubRub((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vmpy_VuhRuh(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuw_vmpy_VuhRuh(Vu, Rt);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_;

    uint16_t ruh[2];
    ruh[0] = HEDLEY_STATIC_CAST(uint16_t, Rt & 0xFFFF);
    ruh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.u32[j] = HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * j]) * HEDLEY_STATIC_CAST(uint32_t, ruh[0]);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + j] = HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * j + 1]) * HEDLEY_STATIC_CAST(uint32_t, ruh[1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vmpy_VuhRuh
  #define Q6_Wuw_vmpy_VuhRuh(Vu, Rt) simde_Q6_Wuw_vmpy_VuhRuh((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpyacc_WhVbVb(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpyacc_WhVbVb(Vxx, Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.u16[j] += HEDLEY_STATIC_CAST(int16_t, a_.i8[2 * j]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[2 * j]);
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + j] += HEDLEY_STATIC_CAST(int16_t, a_.i8[2 * j + 1]) * HEDLEY_STATIC_CAST(int16_t, b_.i8[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpyacc_WhVbVb
  #define Q6_Wh_vmpyacc_WhVbVb(Vxx, Vu, Vv) simde_Q6_Wh_vmpyacc_WhVbVb((Vxx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpyacc_WhVubRb(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpyacc_WhVubRb(Vxx, Vu, Rt);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    int8_t rb[4];
    rb[0] = HEDLEY_STATIC_CAST(int8_t, Rt);
    rb[1] = HEDLEY_STATIC_CAST(int8_t, Rt >> 8);
    rb[2] = HEDLEY_STATIC_CAST(int8_t, Rt >> 16);
    rb[3] = HEDLEY_STATIC_CAST(int8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.u16[j] += HEDLEY_STATIC_CAST(int16_t, a_.u8[2 * j]) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * j) % 4]);
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + j] += HEDLEY_STATIC_CAST(int16_t, a_.u8[2 * j + 1]) * HEDLEY_STATIC_CAST(int16_t, rb[(2 * j + 1) % 4]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpyacc_WhVubRb
  #define Q6_Wh_vmpyacc_WhVubRb(Vxx, Vu, Rt) simde_Q6_Wh_vmpyacc_WhVubRb((Vxx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wh_vmpyacc_WhVubVb(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wh_vmpyacc_WhVubVb(Vxx, Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.u16[j] += HEDLEY_STATIC_CAST(int16_t, HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j])) * HEDLEY_STATIC_CAST(int16_t, b_.i8[2 * j]);
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + j] += HEDLEY_STATIC_CAST(int16_t, HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j + 1])) * HEDLEY_STATIC_CAST(int16_t, b_.i8[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wh_vmpyacc_WhVubVb
  #define Q6_Wh_vmpyacc_WhVubVb(Vxx, Vu, Vv) simde_Q6_Wh_vmpyacc_WhVubVb((Vxx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpyacc_WwVhVh(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpyacc_WwVhVh(Vxx, Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.u32[j] += HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[2 * j]);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + j] += HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j + 1]) * HEDLEY_STATIC_CAST(int32_t, b_.i16[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpyacc_WwVhVh
  #define Q6_Ww_vmpyacc_WwVhVh(Vxx, Vu, Vv) simde_Q6_Ww_vmpyacc_WwVhVh((Vxx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpyacc_WwVhRh_sat(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpyacc_WwVhRh_sat(Vxx, Vu, Rt);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    int16_t rh[2];
    rh[0] = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    rh[1] = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      int64_t sum_lo = HEDLEY_STATIC_CAST(int64_t, r_.i32[j]) +
                       HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * j]) * HEDLEY_STATIC_CAST(int64_t, rh[0]);
      if (sum_lo > INT32_MAX) sum_lo = INT32_MAX;
      else if (sum_lo < INT32_MIN) sum_lo = INT32_MIN;
      r_.i32[j] = HEDLEY_STATIC_CAST(int32_t, sum_lo);

      int64_t sum_hi = HEDLEY_STATIC_CAST(int64_t, r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + j]) +
                       HEDLEY_STATIC_CAST(int64_t, a_.i16[2 * j + 1]) * HEDLEY_STATIC_CAST(int64_t, rh[1]);
      if (sum_hi > INT32_MAX) sum_hi = INT32_MAX;
      else if (sum_hi < INT32_MIN) sum_hi = INT32_MIN;
      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + j] = HEDLEY_STATIC_CAST(int32_t, sum_hi);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpyacc_WwVhRh_sat
  #define Q6_Ww_vmpyacc_WwVhRh_sat(Vxx, Vu, Rt) simde_Q6_Ww_vmpyacc_WwVhRh_sat((Vxx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpyacc_WwVhRh(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpyacc_WwVhRh(Vxx, Vu, Rt);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    int16_t rh[2];
    rh[0] = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    rh[1] = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.u32[j] += HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j]) * HEDLEY_STATIC_CAST(int32_t, rh[0]);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + j] += HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j + 1]) * HEDLEY_STATIC_CAST(int32_t, rh[1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpyacc_WwVhRh
  #define Q6_Ww_vmpyacc_WwVhRh(Vxx, Vu, Rt) simde_Q6_Ww_vmpyacc_WwVhRh((Vxx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuh_vmpyacc_WuhVubRub(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuh_vmpyacc_WuhVubRub(Vxx, Vu, Rt);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.u16[j] += HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j]) * HEDLEY_STATIC_CAST(uint16_t, rub[(2 * j) % 4]);
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + j] += HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j + 1]) * HEDLEY_STATIC_CAST(uint16_t, rub[(2 * j + 1) % 4]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuh_vmpyacc_WuhVubRub
  #define Q6_Wuh_vmpyacc_WuhVubRub(Vxx, Vu, Rt) simde_Q6_Wuh_vmpyacc_WuhVubRub((Vxx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuh_vmpyacc_WuhVubVub(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuh_vmpyacc_WuhVubVub(Vxx, Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I16_COUNT ; j++) {
      r_.u16[j] += HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j]) * HEDLEY_STATIC_CAST(uint16_t, b_.u8[2 * j]);
      r_.u16[SIMDE_HVX_VECTOR_I16_COUNT + j] += HEDLEY_STATIC_CAST(uint16_t, a_.u8[2 * j + 1]) * HEDLEY_STATIC_CAST(uint16_t, b_.u8[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuh_vmpyacc_WuhVubVub
  #define Q6_Wuh_vmpyacc_WuhVubVub(Vxx, Vu, Vv) simde_Q6_Wuh_vmpyacc_WuhVubVub((Vxx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vmpyacc_WuwVuhRuh(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuw_vmpyacc_WuwVuhRuh(Vxx, Vu, Rt);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    uint16_t ruh[2];
    ruh[0] = HEDLEY_STATIC_CAST(uint16_t, Rt & 0xFFFF);
    ruh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.u32[j] += HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * j]) * HEDLEY_STATIC_CAST(uint32_t, ruh[0]);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + j] += HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * j + 1]) * HEDLEY_STATIC_CAST(uint32_t, ruh[1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vmpyacc_WuwVuhRuh
  #define Q6_Wuw_vmpyacc_WuwVuhRuh(Vxx, Vu, Rt) simde_Q6_Wuw_vmpyacc_WuwVuhRuh((Vxx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wuw_vmpyacc_WuwVuhVuh(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Wuw_vmpyacc_WuwVuhVuh(Vxx, Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.u32[j] += HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * j]) * HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j]);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + j] += HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * j + 1]) * HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wuw_vmpyacc_WuwVuhVuh
  #define Q6_Wuw_vmpyacc_WuwVuhVuh(Vxx, Vu, Vv) simde_Q6_Wuw_vmpyacc_WuwVuhVuh((Vxx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpy_VhVuh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpy_VhVuh(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.i32[j] = HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j]) * HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j]));
      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + j] = HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j + 1]) * HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j + 1]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpy_VhVuh
  #define Q6_Ww_vmpy_VhVuh(Vu, Vv) simde_Q6_Ww_vmpy_VhVuh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vmpy_VhRh_s1_sat(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vmpy_VhRh_s1_sat(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int16_t rh[2];
    rh[0] = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    rh[1] = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int64_t prod = HEDLEY_STATIC_CAST(int64_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int64_t, rh[i % 2]);
      int32_t result = HEDLEY_STATIC_CAST(int32_t, (prod * 2) >> 16);
      if (result > INT16_MAX) result = INT16_MAX;
      else if (result < INT16_MIN) result = INT16_MIN;
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, result);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vmpy_VhRh_s1_sat
  #define Q6_Vh_vmpy_VhRh_s1_sat(Vu, Rt) simde_Q6_Vh_vmpy_VhRh_s1_sat((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vmpy_VhRh_s1_rnd_sat(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vmpy_VhRh_s1_rnd_sat(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int16_t rh[2];
    rh[0] = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    rh[1] = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int64_t prod = HEDLEY_STATIC_CAST(int64_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int64_t, rh[i % 2]);
      int32_t result = HEDLEY_STATIC_CAST(int32_t, ((prod * 2) + 0x8000) >> 16);
      if (result > INT16_MAX) result = INT16_MAX;
      else if (result < INT16_MIN) result = INT16_MIN;
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, result);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vmpy_VhRh_s1_rnd_sat
  #define Q6_Vh_vmpy_VhRh_s1_rnd_sat(Vu, Rt) simde_Q6_Vh_vmpy_VhRh_s1_rnd_sat((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vh_vmpy_VhVh_s1_rnd_sat(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vh_vmpy_VhVh_s1_rnd_sat(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      int64_t prod = HEDLEY_STATIC_CAST(int64_t, a_.i16[i]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[i]);
      int32_t result = HEDLEY_STATIC_CAST(int32_t, ((prod * 2) + 0x8000) >> 16);
      if (result > INT16_MAX) result = INT16_MAX;
      else if (result < INT16_MIN) result = INT16_MIN;
      r_.i16[i] = HEDLEY_STATIC_CAST(int16_t, result);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vh_vmpy_VhVh_s1_rnd_sat
  #define Q6_Vh_vmpy_VhVh_s1_rnd_sat(Vu, Vv) simde_Q6_Vh_vmpy_VhVh_s1_rnd_sat((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuh_vmpy_VuhVuh_rs16(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vuh_vmpy_VuhVuh_rs16)
    return Q6_Vuh_vmpy_VuhVuh_rs16(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
      uint32_t prod = HEDLEY_STATIC_CAST(uint32_t, a_.u16[i]) * HEDLEY_STATIC_CAST(uint32_t, b_.u16[i]);
      r_.u16[i] = HEDLEY_STATIC_CAST(uint16_t, (prod + 0x8000u) >> 16);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuh_vmpy_VuhVuh_rs16
  #define Q6_Vuh_vmpy_VuhVuh_rs16(Vu, Vv) simde_Q6_Vuh_vmpy_VuhVuh_rs16((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Ww_vmpyacc_WwVhVuh(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Ww_vmpyacc_WwVhVuh(Vxx, Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      r_.u32[j] += HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j]) * HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j]));
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + j] += HEDLEY_STATIC_CAST(int32_t, a_.i16[2 * j + 1]) * HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j + 1]));
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Ww_vmpyacc_WwVhVuh
  #define Q6_Ww_vmpyacc_WwVhVuh(Vxx, Vu, Vv) simde_Q6_Ww_vmpyacc_WwVhVuh((Vxx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuw_vmpye_VuhRuh(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuw_vmpye_VuhRuh(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    uint16_t ruh[2];
    ruh[0] = HEDLEY_STATIC_CAST(uint16_t, Rt & 0xFFFF);
    ruh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * i]) * HEDLEY_STATIC_CAST(uint32_t, ruh[0]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuw_vmpye_VuhRuh
  #define Q6_Vuw_vmpye_VuhRuh(Vu, Rt) simde_Q6_Vuw_vmpye_VuhRuh((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_W_vmpye_VwVuh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_W_vmpye_VwVuh(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      int64_t prod = HEDLEY_STATIC_CAST(int64_t, a_.i32[j]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * j]));
      r_.i32[j] = HEDLEY_STATIC_CAST(int32_t, prod & 0xFFFFFFFF);
      r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + j] = HEDLEY_STATIC_CAST(int32_t, prod >> 32);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_W_vmpye_VwVuh
  #define Q6_W_vmpye_VwVuh(Vu, Vv) simde_Q6_W_vmpye_VwVuh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vuw_vmpyeacc_VuwVuhRuh(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vuw_vmpyeacc_VuwVuhRuh(Vx, Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu);

    uint16_t ruh[2];
    ruh[0] = HEDLEY_STATIC_CAST(uint16_t, Rt & 0xFFFF);
    ruh[1] = HEDLEY_STATIC_CAST(uint16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.u32[i] = x_.u32[i] + HEDLEY_STATIC_CAST(uint32_t, a_.u16[2 * i]) * HEDLEY_STATIC_CAST(uint32_t, ruh[0]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vuw_vmpyeacc_VuwVuhRuh
  #define Q6_Vuw_vmpyeacc_VuwVuhRuh(Vx, Vu, Rt) simde_Q6_Vuw_vmpyeacc_VuwVuhRuh((Vx), (Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyi_VwRh(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyi_VwRh(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    int16_t rh[2];
    rh[0] = HEDLEY_STATIC_CAST(int16_t, Rt & 0xFFFF);
    rh[1] = HEDLEY_STATIC_CAST(int16_t, (Rt >> 16) & 0xFFFF);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) * HEDLEY_STATIC_CAST(int64_t, rh[i % 2]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyi_VwRh
  #define Q6_Vw_vmpyi_VwRh(Vu, Rt) simde_Q6_Vw_vmpyi_VwRh((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyi_VwRub(simde_hvx_vector_t Vu, int32_t Rt) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyi_VwRub(Vu, Rt);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu);

    uint8_t rub[4];
    rub[0] = HEDLEY_STATIC_CAST(uint8_t, Rt);
    rub[1] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 8);
    rub[2] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 16);
    rub[3] = HEDLEY_STATIC_CAST(uint8_t, Rt >> 24);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) * HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint32_t, rub[i % 4])));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyi_VwRub
  #define Q6_Vw_vmpyi_VwRub(Vu, Rt) simde_Q6_Vw_vmpyi_VwRub((Vu), (Rt))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpyio_VwVh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_Vw_vmpyio_VwVh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t, HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * i + 1]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpyio_VwVh
  #define Q6_Vw_vmpyio_VwVh(Vu, Vv) simde_Q6_Vw_vmpyio_VwVh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_W_vmpyoacc_WVwVh(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE)
    return Q6_W_vmpyoacc_WVwVh(Vxx, Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
      uint32_t lo = r_.u32[j];
      int64_t prod = HEDLEY_STATIC_CAST(int64_t, a_.i32[j]) * HEDLEY_STATIC_CAST(int64_t, b_.i16[2 * j + 1]) +
                     HEDLEY_STATIC_CAST(int64_t, r_.i32[SIMDE_HVX_VECTOR_I32_COUNT + j]);
      r_.u32[j] = (HEDLEY_STATIC_CAST(uint32_t, prod) << 16) | (lo >> 16);
      r_.u32[SIMDE_HVX_VECTOR_I32_COUNT + j] = HEDLEY_STATIC_CAST(uint32_t, HEDLEY_STATIC_CAST(uint64_t, prod) >> 16);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_W_vmpyoacc_WVwVh
  #define Q6_W_vmpyoacc_WVwVh(Vxx, Vu, Vv) simde_Q6_W_vmpyoacc_WVwVh((Vxx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vhf_vmpy_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vhf_vmpy_VhfVhf)
    return Q6_Vhf_vmpy_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      r_.f16[i] = simde_float16_from_float32(
        simde_float16_to_float32(a_.f16[i]) *
        simde_float16_to_float32(b_.f16[i]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vhf_vmpy_VhfVhf
  #define Q6_Vhf_vmpy_VhfVhf(Vu, Vv) simde_Q6_Vhf_vmpy_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vhf_vmpyacc_VhfVhfVhf(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vhf_vmpyacc_VhfVhfVhf)
    return Q6_Vhf_vmpyacc_VhfVhfVhf(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      r_.f16[i] = simde_float16_from_float32(
        simde_float16_to_float32(x_.f16[i]) +
        simde_float16_to_float32(a_.f16[i]) *
        simde_float16_to_float32(b_.f16[i]));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vhf_vmpyacc_VhfVhfVhf
  #define Q6_Vhf_vmpyacc_VhfVhfVhf(Vx, Vu, Vv) simde_Q6_Vhf_vmpyacc_VhfVhfVhf((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vsf_vmpy_VsfVsf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vsf_vmpy_VsfVsf)
    return Q6_Vsf_vmpy_VsfVsf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      r_.f32[i] = a_.f32[i] * b_.f32[i];
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vsf_vmpy_VsfVsf
  #define Q6_Vsf_vmpy_VsfVsf(Vu, Vv) simde_Q6_Vsf_vmpy_VsfVsf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wsf_vmpy_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Wsf_vmpy_VhfVhf)
    return Q6_Wsf_vmpy_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      r_.f32[i] = simde_float16_to_float32(a_.f16[i]) *
                  simde_float16_to_float32(b_.f16[i]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wsf_vmpy_VhfVhf
  #define Q6_Wsf_vmpy_VhfVhf(Vu, Vv) simde_Q6_Wsf_vmpy_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wsf_vmpyacc_WsfVhfVhf(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Wsf_vmpyacc_WsfVhfVhf)
    return Q6_Wsf_vmpyacc_WsfVhfVhf(Vxx, Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F16_COUNT ; i++) {
      r_.f32[i] += simde_float16_to_float32(a_.f16[i]) *
                   simde_float16_to_float32(b_.f16[i]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wsf_vmpyacc_WsfVhfVhf
  #define Q6_Wsf_vmpyacc_WsfVhfVhf(Vxx, Vu, Vv) simde_Q6_Wsf_vmpyacc_WsfVhfVhf((Vxx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wsf_vmpy_VbfVbf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Wsf_vmpy_VbfVbf)
    return Q6_Wsf_vmpy_VbfVbf(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      r_.f32[i] = simde_bfloat16_to_float32(a_.bf16[2 * i]) *
                  simde_bfloat16_to_float32(b_.bf16[2 * i]);
      r_.f32[SIMDE_HVX_VECTOR_F32_COUNT + i] = simde_bfloat16_to_float32(a_.bf16[2 * i + 1]) *
                                               simde_bfloat16_to_float32(b_.bf16[2 * i + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wsf_vmpy_VbfVbf
  #define Q6_Wsf_vmpy_VbfVbf(Vu, Vv) simde_Q6_Wsf_vmpy_VbfVbf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Wsf_vmpyacc_WsfVbfVbf(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Wsf_vmpyacc_WsfVbfVbf)
    return Q6_Wsf_vmpyacc_WsfVbfVbf(Vxx, Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(Vxx);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      r_.f32[i] += simde_bfloat16_to_float32(a_.bf16[2 * i]) *
                   simde_bfloat16_to_float32(b_.bf16[2 * i]);
      r_.f32[SIMDE_HVX_VECTOR_F32_COUNT + i] += simde_bfloat16_to_float32(a_.bf16[2 * i + 1]) *
                                                simde_bfloat16_to_float32(b_.bf16[2 * i + 1]);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Wsf_vmpyacc_WsfVbfVbf
  #define Q6_Wsf_vmpyacc_WsfVbfVbf(Vxx, Vu, Vv) simde_Q6_Wsf_vmpyacc_WsfVbfVbf((Vxx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vsf_vdmpy_VhfVhf(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vsf_vdmpy_VhfVhf)
    return Q6_Vsf_vdmpy_VhfVhf(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      r_.f32[i] =
        simde_float16_to_float32(a_.f16[2 * i]) *
        simde_float16_to_float32(b_.f16[2 * i]) +
        simde_float16_to_float32(a_.f16[2 * i + 1]) *
        simde_float16_to_float32(b_.f16[2 * i + 1]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vsf_vdmpy_VhfVhf
  #define Q6_Vsf_vdmpy_VhfVhf(Vu, Vv) simde_Q6_Vsf_vdmpy_VhfVhf((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vsf_vdmpyacc_VsfVhfVhf(simde_hvx_vector_t Vx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vsf_vdmpyacc_VsfVhfVhf)
    return Q6_Vsf_vdmpyacc_VsfVhfVhf(Vx, Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      x_ = simde_hvx_vector_to_private(Vx),
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
      r_.f32[i] = x_.f32[i] +
        simde_float16_to_float32(a_.f16[2 * i]) *
        simde_float16_to_float32(b_.f16[2 * i]) +
        simde_float16_to_float32(a_.f16[2 * i + 1]) *
        simde_float16_to_float32(b_.f16[2 * i + 1]);
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vsf_vdmpyacc_VsfVhfVhf
  #define Q6_Vsf_vdmpyacc_VsfVhfVhf(Vx, Vu, Vv) simde_Q6_Vsf_vdmpyacc_VsfVhfVhf((Vx), (Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vector_t
simde_Q6_Vw_vmpye_VwVuh(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Vw_vmpye_VwVuh)
    return Q6_Vw_vmpye_VwVuh(Vu, Vv);
  #else
    simde_hvx_vector_private
      r_,
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
      r_.i32[i] = HEDLEY_STATIC_CAST(int32_t,
        HEDLEY_STATIC_CAST(int64_t, a_.i32[i]) *
        HEDLEY_STATIC_CAST(int64_t, HEDLEY_STATIC_CAST(uint32_t, b_.u16[2 * i])));
    }

    return simde_hvx_vector_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Vw_vmpye_VwVuh
  #define Q6_Vw_vmpye_VwVuh(Vu, Vv) simde_Q6_Vw_vmpye_VwVuh((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Whf_vmpy_VV(simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Whf_vmpy_VV)
    return Q6_Whf_vmpy_VV(Vu, Vv);
  #else
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);
    simde_hvx_vectorpair_private r_;

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      simde_float32 af = simde_f8e4m3_to_float32(a_.u8[i]);
      simde_float32 bf = simde_f8e4m3_to_float32(b_.u8[i]);
      r_.f16[i] = simde_float16_from_float32(af * bf);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Whf_vmpy_VV
  #define Q6_Whf_vmpy_VV(Vu, Vv) simde_Q6_Whf_vmpy_VV((Vu), (Vv))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_hvx_vectorpair_t
simde_Q6_Whf_vmpyacc_WhfVV(simde_hvx_vectorpair_t Vxx, simde_hvx_vector_t Vu, simde_hvx_vector_t Vv) {
  #if defined(SIMDE_HEXAGON_HVX_NATIVE) && defined(Q6_Whf_vmpyacc_WhfVV)
    return Q6_Whf_vmpyacc_WhfVV(Vxx, Vu, Vv);
  #else
    simde_hvx_vectorpair_private
      r_ = simde_hvx_vectorpair_to_private(Vxx);
    simde_hvx_vector_private
      a_ = simde_hvx_vector_to_private(Vu),
      b_ = simde_hvx_vector_to_private(Vv);

    for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
      simde_float32 af = simde_f8e4m3_to_float32(a_.u8[i]);
      simde_float32 bf = simde_f8e4m3_to_float32(b_.u8[i]);
      simde_float32 existing = simde_float16_to_float32(r_.f16[i]);
      r_.f16[i] = simde_float16_from_float32(existing + af * bf);
    }

    return simde_hvx_vectorpair_from_private(r_);
  #endif
}
#if defined(SIMDE_HEXAGON_HVX_ENABLE_NATIVE_ALIASES)
  #undef Q6_Whf_vmpyacc_WhfVV
  #define Q6_Whf_vmpyacc_WhfVV(Vxx, Vu, Vv) simde_Q6_Whf_vmpyacc_WhfVV((Vxx), (Vu), (Vv))
#endif

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_HEXAGON_HVX_VMPY_H) */
