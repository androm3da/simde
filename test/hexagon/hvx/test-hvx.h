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
 *   2026      Brian Cain <brian.cain@oss.qualcomm.com> (Copyright owned by Qualcomm Technologies, Inc. and its subsidiaries)
 */

#if !defined(SIMDE_TEST_HEXAGON_TEST_HVX_H)
#define SIMDE_TEST_HEXAGON_TEST_HVX_H

#include "../../../simde/hexagon/hvx.h"
#include "../../test.h"

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION

/* Generate the random / write / assert_equal helpers for one element type.
 *
 * HVX vectors are opaque to the caller, so every helper round-trips through
 * simde_memcpy rather than subscripting: the public type is a native
 * HVX_Vector on Hexagon and a SIMDE_VECTOR() typedef elsewhere.
 *
 * ET               element type, e.g. int16_t
 * symbol_identifier  suffix used by the simde_assert_equal_v*_ and
 *                  simde_test_codegen_write_v* helpers, e.g. i16
 * vector_lanes     elements in one vector
 * pair_lanes       elements in a vector pair */
static simde_hvx_vector_t
simde_test_hvx_vector_load(const void* ptr) {
  simde_hvx_vector_t r;
  simde_memcpy(&r, ptr, sizeof(r));
  return r;
}

static simde_hvx_vectorpair_t
simde_test_hvx_vectorpair_load(const void* ptr) {
  simde_hvx_vectorpair_t r;
  simde_memcpy(&r, ptr, sizeof(r));
  return r;
}

static simde_hvx_vectorpred_t
simde_test_hvx_vectorpred_load(const void* ptr) {
  simde_hvx_vectorpred_t r;
  simde_memcpy(&r, ptr, sizeof(r));
  return r;
}

#define SIMDE_TEST_HVX_GENERATE_TYPE_FUNCS_(ET, symbol_identifier, vector_lanes, pair_lanes, ET_MIN, ET_MAX) \
  static int \
  simde_test_hvx_vector_##symbol_identifier##_assert_equal_( \
      simde_hvx_vector_t a, simde_hvx_vector_t b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    ET a_[vector_lanes], b_[vector_lanes]; \
    simde_memcpy(a_, &a, sizeof(a_)); \
    simde_memcpy(b_, &b, sizeof(b_)); \
    return simde_assert_equal_v##symbol_identifier##_(vector_lanes, a_, b_, filename, line, astr, bstr); \
  } \
 \
  static int \
  simde_test_hvx_vectorpair_##symbol_identifier##_assert_equal_( \
      simde_hvx_vectorpair_t a, simde_hvx_vectorpair_t b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    ET a_[pair_lanes], b_[pair_lanes]; \
    simde_memcpy(a_, &a, sizeof(a_)); \
    simde_memcpy(b_, &b, sizeof(b_)); \
    return simde_assert_equal_v##symbol_identifier##_(pair_lanes, a_, b_, filename, line, astr, bstr); \
  } \
 \
  static void \
  simde_test_hvx_vector_##symbol_identifier##_write(int indent, simde_hvx_vector_t v, SimdeTestVecPos pos) { \
    ET v_[vector_lanes]; \
    simde_memcpy(v_, &v, sizeof(v_)); \
    simde_test_codegen_write_v##symbol_identifier(indent, vector_lanes, v_, pos); \
  } \
 \
  static void \
  simde_test_hvx_vectorpair_##symbol_identifier##_write(int indent, simde_hvx_vectorpair_t v, SimdeTestVecPos pos) { \
    ET v_[pair_lanes]; \
    simde_memcpy(v_, &v, sizeof(v_)); \
    simde_test_codegen_write_v##symbol_identifier(indent, pair_lanes, v_, pos); \
  } \
 \
  /* Seed the leading lanes with the values that saturating and widening \
   * operations are most likely to get wrong, then fill the rest at \
   * random, so a single generated vector covers both. \
   * \
   * `operand` rotates the table so that lane i of operand 0 and lane i \
   * of operand 1 form a different pair each time: without the rotation \
   * both sides would always hold the same edge value and combinations \
   * like MAX + 1 would never be generated. */ \
  static void \
  simde_test_hvx_##symbol_identifier##_fill_(size_t lanes, ET buf[HEDLEY_ARRAY_PARAM(lanes)], int operand) { \
    static const ET edges[] = { \
      ET_MIN, ET_MIN, ET_MAX, ET_MAX, \
      ET_MIN, ET_MAX, HEDLEY_STATIC_CAST(ET, 0), HEDLEY_STATIC_CAST(ET, 1), \
      HEDLEY_STATIC_CAST(ET, -1), HEDLEY_STATIC_CAST(ET, 1), ET_MAX, HEDLEY_STATIC_CAST(ET, 1) \
    }; \
    const size_t n = sizeof(edges) / sizeof(edges[0]); \
    const size_t rot = (HEDLEY_STATIC_CAST(size_t, operand) * 4) % n; \
    simde_test_codegen_random_memory(lanes * sizeof(ET), HEDLEY_REINTERPRET_CAST(uint8_t*, buf)); \
    for (size_t i = 0 ; i < n && i < lanes ; i++) { \
      buf[i] = edges[(i + rot) % n]; \
    } \
  } \
 \
  static simde_hvx_vector_t \
  simde_test_hvx_vector_##symbol_identifier##_random(int operand) { \
    ET buf[vector_lanes]; \
    simde_test_hvx_##symbol_identifier##_fill_(vector_lanes, buf, operand); \
    return simde_test_hvx_vector_load(buf); \
  } \
 \
  static simde_hvx_vectorpair_t \
  simde_test_hvx_vectorpair_##symbol_identifier##_random(int operand) { \
    ET buf[pair_lanes]; \
    simde_test_hvx_##symbol_identifier##_fill_(pair_lanes, buf, operand); \
    return simde_test_hvx_vectorpair_load(buf); \
  }

SIMDE_TEST_HVX_GENERATE_TYPE_FUNCS_(  int8_t,  i8, SIMDE_HVX_VECTOR_SIZE,      SIMDE_HVX_PAIR_SIZE,      INT8_MIN,  INT8_MAX)
SIMDE_TEST_HVX_GENERATE_TYPE_FUNCS_( int16_t, i16, SIMDE_HVX_VECTOR_I16_COUNT, SIMDE_HVX_PAIR_I16_COUNT, INT16_MIN, INT16_MAX)
SIMDE_TEST_HVX_GENERATE_TYPE_FUNCS_( int32_t, i32, SIMDE_HVX_VECTOR_I32_COUNT, SIMDE_HVX_PAIR_I32_COUNT, INT32_MIN, INT32_MAX)
SIMDE_TEST_HVX_GENERATE_TYPE_FUNCS_( uint8_t,  u8, SIMDE_HVX_VECTOR_SIZE,      SIMDE_HVX_PAIR_SIZE,      UINT8_C(0),  UINT8_MAX)
SIMDE_TEST_HVX_GENERATE_TYPE_FUNCS_(uint16_t, u16, SIMDE_HVX_VECTOR_I16_COUNT, SIMDE_HVX_PAIR_I16_COUNT, UINT16_C(0), UINT16_MAX)
SIMDE_TEST_HVX_GENERATE_TYPE_FUNCS_(uint32_t, u32, SIMDE_HVX_VECTOR_I32_COUNT, SIMDE_HVX_PAIR_I32_COUNT, UINT32_C(0), UINT32_MAX)

#define simde_test_hvx_vector_i8_assert_equal(a, b)  do { if (simde_test_hvx_vector_i8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vector_i16_assert_equal(a, b) do { if (simde_test_hvx_vector_i16_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vector_i32_assert_equal(a, b) do { if (simde_test_hvx_vector_i32_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vector_u8_assert_equal(a, b)  do { if (simde_test_hvx_vector_u8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vector_u16_assert_equal(a, b) do { if (simde_test_hvx_vector_u16_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vector_u32_assert_equal(a, b) do { if (simde_test_hvx_vector_u32_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)

#define simde_test_hvx_vectorpair_i8_assert_equal(a, b)  do { if (simde_test_hvx_vectorpair_i8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vectorpair_i16_assert_equal(a, b) do { if (simde_test_hvx_vectorpair_i16_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vectorpair_i32_assert_equal(a, b) do { if (simde_test_hvx_vectorpair_i32_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vectorpair_u8_assert_equal(a, b)  do { if (simde_test_hvx_vectorpair_u8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vectorpair_u16_assert_equal(a, b) do { if (simde_test_hvx_vectorpair_u16_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vectorpair_u32_assert_equal(a, b) do { if (simde_test_hvx_vectorpair_u32_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)

/* A predicate is one bit per byte lane on hardware; the portable
 * representation is a 0x00/0xFF byte mask, so compare it as bytes. */
static int
simde_test_hvx_vectorpred_assert_equal_(
    simde_hvx_vectorpred_t a, simde_hvx_vectorpred_t b,
    const char* filename, int line, const char* astr, const char* bstr) {
  uint8_t a_[SIMDE_HVX_VECTOR_SIZE], b_[SIMDE_HVX_VECTOR_SIZE];
  simde_memcpy(a_, &a, sizeof(a_));
  simde_memcpy(b_, &b, sizeof(b_));
  return simde_assert_equal_vu8_(SIMDE_HVX_VECTOR_SIZE, a_, b_, filename, line, astr, bstr);
}

#define simde_test_hvx_vectorpred_assert_equal(a, b) do { if (simde_test_hvx_vectorpred_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)

static void
simde_test_hvx_vectorpred_write(int indent, simde_hvx_vectorpred_t v, SimdeTestVecPos pos) {
  uint8_t v_[SIMDE_HVX_VECTOR_SIZE];
  simde_memcpy(v_, &v, sizeof(v_));
  simde_test_codegen_write_vu8(indent, SIMDE_HVX_VECTOR_SIZE, v_, pos);
}

/* Build a predicate from random bytes.  A predicate lane is all-set or
 * all-clear, so reduce each random byte to 0x00 or 0xFF first. */
static simde_hvx_vectorpred_t
simde_test_hvx_vectorpred_random(void) {
  uint8_t bytes[SIMDE_HVX_VECTOR_SIZE];
  simde_test_codegen_random_memory(sizeof(bytes), bytes);
  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
    bytes[i] = (bytes[i] & 1) ? UINT8_C(0xff) : UINT8_C(0x00);
  }
  return simde_test_hvx_vectorpred_load(bytes);
}

/* HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION */
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_TEST_HEXAGON_TEST_HVX_H) */
