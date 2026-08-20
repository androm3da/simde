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

#define SIMDE_TEST_HEXAGON_HVX_INSN vilog2

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vilog2.h"

static int
test_simde_vilog2_Vsf(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[128];
    int32_t r[32];
  } test_vec[] = {
    { {
      UINT8_C(0), UINT8_C(0), UINT8_C(128), UINT8_C(63), UINT8_C(0), UINT8_C(0), UINT8_C(128), UINT8_C(191),
      UINT8_C(219), UINT8_C(15), UINT8_C(73), UINT8_C(64), UINT8_C(219), UINT8_C(15), UINT8_C(73), UINT8_C(192),
      UINT8_C(0), UINT8_C(0), UINT8_C(200), UINT8_C(66), UINT8_C(0), UINT8_C(0), UINT8_C(200), UINT8_C(194),
      UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(63), UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(191),
      UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(64), UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(192),
      UINT8_C(0), UINT8_C(80), UINT8_C(154), UINT8_C(68), UINT8_C(0), UINT8_C(80), UINT8_C(154), UINT8_C(196),
      UINT8_C(0), UINT8_C(0), UINT8_C(128), UINT8_C(62), UINT8_C(0), UINT8_C(0), UINT8_C(128), UINT8_C(190),
      UINT8_C(249), UINT8_C(2), UINT8_C(21), UINT8_C(80), UINT8_C(249), UINT8_C(2), UINT8_C(21), UINT8_C(208),
      UINT8_C(255), UINT8_C(230), UINT8_C(219), UINT8_C(46), UINT8_C(255), UINT8_C(230), UINT8_C(219), UINT8_C(174),
      UINT8_C(0), UINT8_C(0), UINT8_C(128), UINT8_C(71), UINT8_C(0), UINT8_C(0), UINT8_C(128), UINT8_C(199),
      UINT8_C(23), UINT8_C(183), UINT8_C(209), UINT8_C(56), UINT8_C(23), UINT8_C(183), UINT8_C(209), UINT8_C(184),
      UINT8_C(0), UINT8_C(0), UINT8_C(224), UINT8_C(64), UINT8_C(0), UINT8_C(0), UINT8_C(224), UINT8_C(192),
      UINT8_C(0), UINT8_C(0), UINT8_C(192), UINT8_C(63), UINT8_C(0), UINT8_C(0), UINT8_C(192), UINT8_C(191),
      UINT8_C(0), UINT8_C(0), UINT8_C(64), UINT8_C(64), UINT8_C(0), UINT8_C(0), UINT8_C(64), UINT8_C(192),
      UINT8_C(240), UINT8_C(35), UINT8_C(116), UINT8_C(73), UINT8_C(240), UINT8_C(35), UINT8_C(116), UINT8_C(201),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(63), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(191)
      },
      {
      INT32_C(0), INT32_C(0), INT32_C(1), INT32_C(1), INT32_C(6), INT32_C(6), -INT32_C(1), -INT32_C(1),
      INT32_C(1), INT32_C(1), INT32_C(10), INT32_C(10), -INT32_C(2), -INT32_C(2), INT32_C(33), INT32_C(33),
      -INT32_C(34), -INT32_C(34), INT32_C(16), INT32_C(16), -INT32_C(14), -INT32_C(14), INT32_C(2), INT32_C(2),
      INT32_C(0), INT32_C(0), INT32_C(1), INT32_C(1), INT32_C(19), INT32_C(19), INT32_C(0), INT32_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vw_vilog2_Vsf(a);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vilog2_Vhf(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[128];
    int32_t r[32];
  } test_vec[] = {
    { {
      UINT8_C(0), UINT8_C(4), UINT8_C(37), UINT8_C(132), UINT8_C(74), UINT8_C(8), UINT8_C(111), UINT8_C(140),
      UINT8_C(148), UINT8_C(16), UINT8_C(185), UINT8_C(148), UINT8_C(222), UINT8_C(24), UINT8_C(3), UINT8_C(157),
      UINT8_C(40), UINT8_C(33), UINT8_C(77), UINT8_C(165), UINT8_C(114), UINT8_C(41), UINT8_C(151), UINT8_C(173),
      UINT8_C(188), UINT8_C(49), UINT8_C(225), UINT8_C(181), UINT8_C(6), UINT8_C(58), UINT8_C(43), UINT8_C(190),
      UINT8_C(80), UINT8_C(62), UINT8_C(117), UINT8_C(194), UINT8_C(154), UINT8_C(70), UINT8_C(191), UINT8_C(202),
      UINT8_C(228), UINT8_C(78), UINT8_C(9), UINT8_C(211), UINT8_C(46), UINT8_C(87), UINT8_C(83), UINT8_C(219),
      UINT8_C(120), UINT8_C(95), UINT8_C(157), UINT8_C(227), UINT8_C(194), UINT8_C(103), UINT8_C(231), UINT8_C(235),
      UINT8_C(12), UINT8_C(108), UINT8_C(49), UINT8_C(240), UINT8_C(86), UINT8_C(116), UINT8_C(123), UINT8_C(248),
      UINT8_C(0), UINT8_C(4), UINT8_C(37), UINT8_C(132), UINT8_C(74), UINT8_C(8), UINT8_C(111), UINT8_C(140),
      UINT8_C(148), UINT8_C(16), UINT8_C(185), UINT8_C(148), UINT8_C(222), UINT8_C(24), UINT8_C(3), UINT8_C(157),
      UINT8_C(40), UINT8_C(33), UINT8_C(77), UINT8_C(165), UINT8_C(114), UINT8_C(41), UINT8_C(151), UINT8_C(173),
      UINT8_C(188), UINT8_C(49), UINT8_C(225), UINT8_C(181), UINT8_C(6), UINT8_C(58), UINT8_C(43), UINT8_C(190),
      UINT8_C(80), UINT8_C(62), UINT8_C(117), UINT8_C(194), UINT8_C(154), UINT8_C(70), UINT8_C(191), UINT8_C(202),
      UINT8_C(228), UINT8_C(78), UINT8_C(9), UINT8_C(211), UINT8_C(46), UINT8_C(87), UINT8_C(83), UINT8_C(219),
      UINT8_C(120), UINT8_C(95), UINT8_C(157), UINT8_C(227), UINT8_C(194), UINT8_C(103), UINT8_C(231), UINT8_C(235),
      UINT8_C(12), UINT8_C(108), UINT8_C(49), UINT8_C(240), UINT8_C(86), UINT8_C(116), UINT8_C(123), UINT8_C(248)
      },
      {
      -INT32_C(14), -INT32_C(14), -INT32_C(13), -INT32_C(12), -INT32_C(11), -INT32_C(10), -INT32_C(9), -INT32_C(8),
      -INT32_C(7), -INT32_C(6), -INT32_C(5), -INT32_C(4), -INT32_C(3), -INT32_C(2), -INT32_C(1), INT32_C(0),
      INT32_C(0), INT32_C(1), INT32_C(2), INT32_C(3), INT32_C(4), INT32_C(5), INT32_C(6), INT32_C(7),
      INT32_C(8), INT32_C(9), INT32_C(10), INT32_C(11), INT32_C(12), INT32_C(13), INT32_C(14), INT32_C(15)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vw_vilog2_Vhf(a);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vilog2_subnormal(SIMDE_MUNIT_TEST_ARGS) {
  simde_hvx_vector_private a_, expected_;

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
    a_.u32[i] = UINT32_C(0);
    expected_.i32[i] = -INT32_C(127);
  }
  a_.u32[0] = UINT32_C(0x00000001);
  a_.u32[1] = UINT32_C(0x00000002);
  a_.u32[2] = UINT32_C(0x00400000);
  a_.u32[3] = UINT32_C(0x80400000);
  expected_.i32[0] = -INT32_C(149);
  expected_.i32[1] = -INT32_C(148);
  expected_.i32[2] = -INT32_C(127);
  expected_.i32[3] = -INT32_C(127);
  simde_test_hvx_vector_i32_assert_equal(
    simde_Q6_Vw_vilog2_Vsf(simde_hvx_vector_from_private(a_)),
    simde_hvx_vector_from_private(expected_));

  simde_memset(&a_, 0, sizeof(a_));
  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) expected_.i32[i] = -INT32_C(15);
  a_.u16[0] = UINT16_C(0x0001);
  a_.u16[1] = UINT16_C(0x0002);
  a_.u16[2] = UINT16_C(0x0200);
  a_.u16[3] = UINT16_C(0x8200);
  expected_.i32[0] = -INT32_C(24);
  expected_.i32[1] = -INT32_C(23);
  expected_.i32[2] = -INT32_C(15);
  expected_.i32[3] = -INT32_C(15);
  simde_test_hvx_vector_i32_assert_equal(
    simde_Q6_Vw_vilog2_Vhf(simde_hvx_vector_from_private(a_)),
    simde_hvx_vector_from_private(expected_));

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vilog2_Vsf)
SIMDE_TEST_FUNC_LIST_ENTRY(vilog2_Vhf)
SIMDE_TEST_FUNC_LIST_ENTRY(vilog2_subnormal)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
