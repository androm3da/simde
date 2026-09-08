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

#define SIMDE_TEST_HEXAGON_HVX_INSN vsplat

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vsplat.h"

static int
test_simde_vsplat_R(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
  } test_vec[] = {
    {  INT32_C(   875615495),
      {  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),
         INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),
         INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),
         INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495),  INT32_C(   875615495) } },
    { -INT32_C(   821412706),
      { -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706),
        -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706),
        -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706),
        -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706), -INT32_C(   821412706) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t r = simde_Q6_V_vsplat_R(test_vec[i].a);

    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_hvx_vector_t r = simde_Q6_V_vsplat_R(a);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsplat_Rb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int8_t r[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    {  INT32_C(  1435150463),
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX } },
    { -INT32_C(  1816882551),
      { -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119),
        -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119), -INT8_C( 119) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t r = simde_Q6_Vb_vsplat_R(test_vec[i].a);

    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_hvx_vector_t r = simde_Q6_Vb_vsplat_R(a);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsplat_Rh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int16_t r[SIMDE_HVX_VECTOR_I16_COUNT];
  } test_vec[] = {
    {  INT32_C(  1833989748),
      {  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),
         INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),
         INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),
         INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),
         INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),
         INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),
         INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),
         INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324),  INT16_C( 30324) } },
    { -INT32_C(  1641224817),
      { -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769),
        -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769),
        -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769),
        -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769),
        -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769),
        -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769),
        -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769),
        -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769), -INT16_C(  6769) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t r = simde_Q6_Vh_vsplat_R(test_vec[i].a);

    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_hvx_vector_t r = simde_Q6_Vh_vsplat_R(a);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsplat_R)
SIMDE_TEST_FUNC_LIST_ENTRY(vsplat_Rb)
SIMDE_TEST_FUNC_LIST_ENTRY(vsplat_Rh)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
