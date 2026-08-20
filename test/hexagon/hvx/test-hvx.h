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

#if !defined(SIMDE_TEST_HEXAGON_TEST_HVX_H)
#define SIMDE_TEST_HEXAGON_TEST_HVX_H

#include "../../../simde/hexagon/hvx.h"
#include "../../test.h"

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION

/* Helper: assert two HVX vectors are equal (as int8_t arrays) */
static int
simde_test_hvx_vector_i8_assert_equal_(
    simde_hvx_vector_t a, simde_hvx_vector_t b,
    const char* filename, int line, const char* astr, const char* bstr) {
  int8_t a_[SIMDE_HVX_VECTOR_SIZE];
  int8_t b_[SIMDE_HVX_VECTOR_SIZE];
  simde_memcpy(a_, &a, sizeof(a_));
  simde_memcpy(b_, &b, sizeof(b_));
  return simde_assert_equal_vi8_(SIMDE_HVX_VECTOR_SIZE, a_, b_, filename, line, astr, bstr);
}

static int
simde_test_hvx_vector_i16_assert_equal_(
    simde_hvx_vector_t a, simde_hvx_vector_t b,
    const char* filename, int line, const char* astr, const char* bstr) {
  int16_t a_[SIMDE_HVX_VECTOR_I16_COUNT];
  int16_t b_[SIMDE_HVX_VECTOR_I16_COUNT];
  simde_memcpy(a_, &a, sizeof(a_));
  simde_memcpy(b_, &b, sizeof(b_));
  return simde_assert_equal_vi16_(SIMDE_HVX_VECTOR_I16_COUNT, a_, b_, filename, line, astr, bstr);
}

static int
simde_test_hvx_vector_i32_assert_equal_(
    simde_hvx_vector_t a, simde_hvx_vector_t b,
    const char* filename, int line, const char* astr, const char* bstr) {
  int32_t a_[SIMDE_HVX_VECTOR_I32_COUNT];
  int32_t b_[SIMDE_HVX_VECTOR_I32_COUNT];
  simde_memcpy(a_, &a, sizeof(a_));
  simde_memcpy(b_, &b, sizeof(b_));
  return simde_assert_equal_vi32_(SIMDE_HVX_VECTOR_I32_COUNT, a_, b_, filename, line, astr, bstr);
}

static int
simde_test_hvx_vector_u8_assert_equal_(
    simde_hvx_vector_t a, simde_hvx_vector_t b,
    const char* filename, int line, const char* astr, const char* bstr) {
  uint8_t a_[SIMDE_HVX_VECTOR_SIZE];
  uint8_t b_[SIMDE_HVX_VECTOR_SIZE];
  simde_memcpy(a_, &a, sizeof(a_));
  simde_memcpy(b_, &b, sizeof(b_));
  return simde_assert_equal_vu8_(SIMDE_HVX_VECTOR_SIZE, a_, b_, filename, line, astr, bstr);
}

static int
simde_test_hvx_vector_u16_assert_equal_(
    simde_hvx_vector_t a, simde_hvx_vector_t b,
    const char* filename, int line, const char* astr, const char* bstr) {
  uint16_t a_[SIMDE_HVX_VECTOR_I16_COUNT];
  uint16_t b_[SIMDE_HVX_VECTOR_I16_COUNT];
  simde_memcpy(a_, &a, sizeof(a_));
  simde_memcpy(b_, &b, sizeof(b_));
  return simde_assert_equal_vu16_(SIMDE_HVX_VECTOR_I16_COUNT, a_, b_, filename, line, astr, bstr);
}

static int
simde_test_hvx_vector_u32_assert_equal_(
    simde_hvx_vector_t a, simde_hvx_vector_t b,
    const char* filename, int line, const char* astr, const char* bstr) {
  uint32_t a_[SIMDE_HVX_VECTOR_I32_COUNT];
  uint32_t b_[SIMDE_HVX_VECTOR_I32_COUNT];
  simde_memcpy(a_, &a, sizeof(a_));
  simde_memcpy(b_, &b, sizeof(b_));
  return simde_assert_equal_vu32_(SIMDE_HVX_VECTOR_I32_COUNT, a_, b_, filename, line, astr, bstr);
}

#define simde_test_hvx_vector_i8_assert_equal(a, b)  do { if (simde_test_hvx_vector_i8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vector_i16_assert_equal(a, b) do { if (simde_test_hvx_vector_i16_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vector_i32_assert_equal(a, b) do { if (simde_test_hvx_vector_i32_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vector_u8_assert_equal(a, b)  do { if (simde_test_hvx_vector_u8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vector_u16_assert_equal(a, b) do { if (simde_test_hvx_vector_u16_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_hvx_vector_u32_assert_equal(a, b) do { if (simde_test_hvx_vector_u32_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)

/* Vectorpred assert equal */
static int
simde_test_hvx_vectorpred_u8_assert_equal_(
    simde_hvx_vectorpred_t a, simde_hvx_vectorpred_t b,
    const char* filename, int line, const char* astr, const char* bstr) {
  uint8_t a_[SIMDE_HVX_VECTOR_SIZE];
  uint8_t b_[SIMDE_HVX_VECTOR_SIZE];
  simde_memcpy(a_, &a, sizeof(a_));
  simde_memcpy(b_, &b, sizeof(b_));
  return simde_assert_equal_vu8_(SIMDE_HVX_VECTOR_SIZE, a_, b_, filename, line, astr, bstr);
}

#define simde_test_hvx_vectorpred_u8_assert_equal(a, b) do { if (simde_test_hvx_vectorpred_u8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)

/* Helper: load an HVX vector from a byte array */
static simde_hvx_vector_t
simde_test_hvx_vector_load(const void* ptr) {
  simde_hvx_vector_t r;
  simde_memcpy(&r, ptr, SIMDE_HVX_VECTOR_SIZE);
  return r;
}

/* Helper: load an HVX vector predicate from a byte array */
static simde_hvx_vectorpred_t
simde_test_hvx_vectorpred_load(const void* ptr) {
  simde_hvx_vectorpred_t r;
  simde_memcpy(&r, ptr, SIMDE_HVX_VECTOR_SIZE);
  return r;
}

/* Helper: generate random HVX vector */
static simde_hvx_vector_t
simde_test_hvx_vector_random(void) {
  simde_hvx_vector_t r;
  simde_test_codegen_random_memory(sizeof(r), HEDLEY_REINTERPRET_CAST(uint8_t*, &r));
  return r;
}

/* Helper: write HVX vector as int8_t array */
static void
simde_test_hvx_vector_i8_write(int indent, simde_hvx_vector_t v, SimdeTestVecPos pos) {
  int8_t v_[SIMDE_HVX_VECTOR_SIZE];
  simde_memcpy(v_, &v, sizeof(v_));
  simde_test_codegen_write_vi8(indent, SIMDE_HVX_VECTOR_SIZE, v_, pos);
}

static void
simde_test_hvx_vector_i16_write(int indent, simde_hvx_vector_t v, SimdeTestVecPos pos) {
  int16_t v_[SIMDE_HVX_VECTOR_I16_COUNT];
  simde_memcpy(v_, &v, sizeof(v_));
  simde_test_codegen_write_vi16(indent, SIMDE_HVX_VECTOR_I16_COUNT, v_, pos);
}

static void
simde_test_hvx_vector_i32_write(int indent, simde_hvx_vector_t v, SimdeTestVecPos pos) {
  int32_t v_[SIMDE_HVX_VECTOR_I32_COUNT];
  simde_memcpy(v_, &v, sizeof(v_));
  simde_test_codegen_write_vi32(indent, SIMDE_HVX_VECTOR_I32_COUNT, v_, pos);
}

static void
simde_test_hvx_vector_u8_write(int indent, simde_hvx_vector_t v, SimdeTestVecPos pos) {
  uint8_t v_[SIMDE_HVX_VECTOR_SIZE];
  simde_memcpy(v_, &v, sizeof(v_));
  simde_test_codegen_write_vu8(indent, SIMDE_HVX_VECTOR_SIZE, v_, pos);
}

static void
simde_test_hvx_vector_u16_write(int indent, simde_hvx_vector_t v, SimdeTestVecPos pos) {
  uint16_t v_[SIMDE_HVX_VECTOR_I16_COUNT];
  simde_memcpy(v_, &v, sizeof(v_));
  simde_test_codegen_write_vu16(indent, SIMDE_HVX_VECTOR_I16_COUNT, v_, pos);
}

static void
simde_test_hvx_vector_u32_write(int indent, simde_hvx_vector_t v, SimdeTestVecPos pos) {
  uint32_t v_[SIMDE_HVX_VECTOR_I32_COUNT];
  simde_memcpy(v_, &v, sizeof(v_));
  simde_test_codegen_write_vu32(indent, SIMDE_HVX_VECTOR_I32_COUNT, v_, pos);
}

/* HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION */
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_TEST_HEXAGON_TEST_HVX_H) */
