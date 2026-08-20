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

#define SIMDE_TEST_HEXAGON_HVX_INSN vunpack

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vunpack.h"

#define SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE 128
#define SIMDE_TEST_HVX_FIXTURE_CHUNKS (SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE / SIMDE_HVX_VECTOR_SIZE)

static simde_hvx_vector_t
simde_test_hvx_fixture_vector_load(const void* ptr, size_t chunk) {
  return simde_test_hvx_vector_load(
    HEDLEY_REINTERPRET_CAST(const uint8_t*, ptr) + (chunk * SIMDE_HVX_VECTOR_SIZE));
}

static simde_hvx_vector_t
simde_test_hvx_fixture_pair_vector_load(const void* lo, const void* hi, size_t chunk, size_t part) {
  const size_t offset = (chunk * SIMDE_HVX_PAIR_SIZE) + (part * SIMDE_HVX_VECTOR_SIZE);
  const uint8_t* ptr = offset < SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE
    ? HEDLEY_REINTERPRET_CAST(const uint8_t*, lo) + offset
    : HEDLEY_REINTERPRET_CAST(const uint8_t*, hi) + offset - SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE;
  return simde_test_hvx_vector_load(ptr);
}

static int
test_simde_vsxt_Vb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { /* a */ { INT8_C(3), INT8_C(10), INT8_C(17), INT8_C(24), INT8_C(31), INT8_C(38), INT8_C(45), INT8_C(52),
                INT8_C(59), INT8_C(66), INT8_C(73), INT8_C(80), INT8_C(87), INT8_C(94), INT8_C(101), INT8_C(108),
                INT8_C(115), INT8_C(122), -INT8_C(127), -INT8_C(120), -INT8_C(113), -INT8_C(106), -INT8_C(99), -INT8_C(92),
                -INT8_C(85), -INT8_C(78), -INT8_C(71), -INT8_C(64), -INT8_C(57), -INT8_C(50), -INT8_C(43), -INT8_C(36),
                -INT8_C(29), -INT8_C(22), -INT8_C(15), -INT8_C(8), -INT8_C(1), INT8_C(6), INT8_C(13), INT8_C(20),
                INT8_C(27), INT8_C(34), INT8_C(41), INT8_C(48), INT8_C(55), INT8_C(62), INT8_C(69), INT8_C(76),
                INT8_C(83), INT8_C(90), INT8_C(97), INT8_C(104), INT8_C(111), INT8_C(118), INT8_C(125), -INT8_C(124),
                -INT8_C(117), -INT8_C(110), -INT8_C(103), -INT8_C(96), -INT8_C(89), -INT8_C(82), -INT8_C(75), -INT8_C(68),
                -INT8_C(61), -INT8_C(54), -INT8_C(47), -INT8_C(40), -INT8_C(33), -INT8_C(26), -INT8_C(19), -INT8_C(12),
                -INT8_C(5), INT8_C(2), INT8_C(9), INT8_C(16), INT8_C(23), INT8_C(30), INT8_C(37), INT8_C(44),
                INT8_C(51), INT8_C(58), INT8_C(65), INT8_C(72), INT8_C(79), INT8_C(86), INT8_C(93), INT8_C(100),
                INT8_C(107), INT8_C(114), INT8_C(121), -INT8_C(128), -INT8_C(121), -INT8_C(114), -INT8_C(107), -INT8_C(100),
                -INT8_C(93), -INT8_C(86), -INT8_C(79), -INT8_C(72), -INT8_C(65), -INT8_C(58), -INT8_C(51), -INT8_C(44),
                -INT8_C(37), -INT8_C(30), -INT8_C(23), -INT8_C(16), -INT8_C(9), -INT8_C(2), INT8_C(5), INT8_C(12),
                INT8_C(19), INT8_C(26), INT8_C(33), INT8_C(40), INT8_C(47), INT8_C(54), INT8_C(61), INT8_C(68),
                INT8_C(75), INT8_C(82), INT8_C(89), INT8_C(96), INT8_C(103), INT8_C(110), INT8_C(117), INT8_C(124) },
      /* r_lo */ { INT16_C(3), INT16_C(17), INT16_C(31), INT16_C(45), INT16_C(59), INT16_C(73), INT16_C(87), INT16_C(101),
                   INT16_C(115), -INT16_C(127), -INT16_C(113), -INT16_C(99), -INT16_C(85), -INT16_C(71), -INT16_C(57), -INT16_C(43),
                   -INT16_C(29), -INT16_C(15), -INT16_C(1), INT16_C(13), INT16_C(27), INT16_C(41), INT16_C(55), INT16_C(69),
                   INT16_C(83), INT16_C(97), INT16_C(111), INT16_C(125), -INT16_C(117), -INT16_C(103), -INT16_C(89), -INT16_C(75),
                   -INT16_C(61), -INT16_C(47), -INT16_C(33), -INT16_C(19), -INT16_C(5), INT16_C(9), INT16_C(23), INT16_C(37),
                   INT16_C(51), INT16_C(65), INT16_C(79), INT16_C(93), INT16_C(107), INT16_C(121), -INT16_C(121), -INT16_C(107),
                   -INT16_C(93), -INT16_C(79), -INT16_C(65), -INT16_C(51), -INT16_C(37), -INT16_C(23), -INT16_C(9), INT16_C(5),
                   INT16_C(19), INT16_C(33), INT16_C(47), INT16_C(61), INT16_C(75), INT16_C(89), INT16_C(103), INT16_C(117) },
      /* r_hi */ { INT16_C(10), INT16_C(24), INT16_C(38), INT16_C(52), INT16_C(66), INT16_C(80), INT16_C(94), INT16_C(108),
                   INT16_C(122), -INT16_C(120), -INT16_C(106), -INT16_C(92), -INT16_C(78), -INT16_C(64), -INT16_C(50), -INT16_C(36),
                   -INT16_C(22), -INT16_C(8), INT16_C(6), INT16_C(20), INT16_C(34), INT16_C(48), INT16_C(62), INT16_C(76),
                   INT16_C(90), INT16_C(104), INT16_C(118), -INT16_C(124), -INT16_C(110), -INT16_C(96), -INT16_C(82), -INT16_C(68),
                   -INT16_C(54), -INT16_C(40), -INT16_C(26), -INT16_C(12), INT16_C(2), INT16_C(16), INT16_C(30), INT16_C(44),
                   INT16_C(58), INT16_C(72), INT16_C(86), INT16_C(100), INT16_C(114), -INT16_C(128), -INT16_C(114), -INT16_C(100),
                   -INT16_C(86), -INT16_C(72), -INT16_C(58), -INT16_C(44), -INT16_C(30), -INT16_C(16), -INT16_C(2), INT16_C(12),
                   INT16_C(26), INT16_C(40), INT16_C(54), INT16_C(68), INT16_C(82), INT16_C(96), INT16_C(110), INT16_C(124) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t pair = simde_Q6_Wh_vsxt_Vb(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk));
      simde_test_hvx_vector_i16_assert_equal(simde_Q6_V_lo_W(pair), simde_test_hvx_fixture_vector_load(test_vec[i].r_lo, chunk));
      simde_test_hvx_vector_i16_assert_equal(simde_Q6_V_hi_W(pair), simde_test_hvx_fixture_vector_load(test_vec[i].r_hi, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vsxt_Vh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t r_lo[32];
    int32_t r_hi[32];
  } test_vec[] = {
    { /* a */ { INT8_C(3), INT8_C(10), INT8_C(17), INT8_C(24), INT8_C(31), INT8_C(38), INT8_C(45), INT8_C(52),
                INT8_C(59), INT8_C(66), INT8_C(73), INT8_C(80), INT8_C(87), INT8_C(94), INT8_C(101), INT8_C(108),
                INT8_C(115), INT8_C(122), -INT8_C(127), -INT8_C(120), -INT8_C(113), -INT8_C(106), -INT8_C(99), -INT8_C(92),
                -INT8_C(85), -INT8_C(78), -INT8_C(71), -INT8_C(64), -INT8_C(57), -INT8_C(50), -INT8_C(43), -INT8_C(36),
                -INT8_C(29), -INT8_C(22), -INT8_C(15), -INT8_C(8), -INT8_C(1), INT8_C(6), INT8_C(13), INT8_C(20),
                INT8_C(27), INT8_C(34), INT8_C(41), INT8_C(48), INT8_C(55), INT8_C(62), INT8_C(69), INT8_C(76),
                INT8_C(83), INT8_C(90), INT8_C(97), INT8_C(104), INT8_C(111), INT8_C(118), INT8_C(125), -INT8_C(124),
                -INT8_C(117), -INT8_C(110), -INT8_C(103), -INT8_C(96), -INT8_C(89), -INT8_C(82), -INT8_C(75), -INT8_C(68),
                -INT8_C(61), -INT8_C(54), -INT8_C(47), -INT8_C(40), -INT8_C(33), -INT8_C(26), -INT8_C(19), -INT8_C(12),
                -INT8_C(5), INT8_C(2), INT8_C(9), INT8_C(16), INT8_C(23), INT8_C(30), INT8_C(37), INT8_C(44),
                INT8_C(51), INT8_C(58), INT8_C(65), INT8_C(72), INT8_C(79), INT8_C(86), INT8_C(93), INT8_C(100),
                INT8_C(107), INT8_C(114), INT8_C(121), -INT8_C(128), -INT8_C(121), -INT8_C(114), -INT8_C(107), -INT8_C(100),
                -INT8_C(93), -INT8_C(86), -INT8_C(79), -INT8_C(72), -INT8_C(65), -INT8_C(58), -INT8_C(51), -INT8_C(44),
                -INT8_C(37), -INT8_C(30), -INT8_C(23), -INT8_C(16), -INT8_C(9), -INT8_C(2), INT8_C(5), INT8_C(12),
                INT8_C(19), INT8_C(26), INT8_C(33), INT8_C(40), INT8_C(47), INT8_C(54), INT8_C(61), INT8_C(68),
                INT8_C(75), INT8_C(82), INT8_C(89), INT8_C(96), INT8_C(103), INT8_C(110), INT8_C(117), INT8_C(124) },
      /* r_lo */ { INT32_C(2563), INT32_C(9759), INT32_C(16955), INT32_C(24151), INT32_C(31347), -INT32_C(26993), -INT32_C(19797), -INT32_C(12601),
                   -INT32_C(5405), INT32_C(1791), INT32_C(8731), INT32_C(15927), INT32_C(23123), INT32_C(30319), -INT32_C(28021), -INT32_C(20825),
                   -INT32_C(13629), -INT32_C(6433), INT32_C(763), INT32_C(7703), INT32_C(14899), INT32_C(22095), INT32_C(29291), -INT32_C(29049),
                   -INT32_C(21853), -INT32_C(14657), -INT32_C(7461), -INT32_C(265), INT32_C(6675), INT32_C(13871), INT32_C(21067), INT32_C(28263) },
      /* r_hi */ { INT32_C(6161), INT32_C(13357), INT32_C(20553), INT32_C(27749), -INT32_C(30591), -INT32_C(23395), -INT32_C(16199), -INT32_C(9003),
                   -INT32_C(1807), INT32_C(5133), INT32_C(12329), INT32_C(19525), INT32_C(26721), -INT32_C(31619), -INT32_C(24423), -INT32_C(17227),
                   -INT32_C(10031), -INT32_C(2835), INT32_C(4105), INT32_C(11301), INT32_C(18497), INT32_C(25693), -INT32_C(32647), -INT32_C(25451),
                   -INT32_C(18255), -INT32_C(11059), -INT32_C(3863), INT32_C(3077), INT32_C(10273), INT32_C(17469), INT32_C(24665), INT32_C(31861) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t pair = simde_Q6_Ww_vsxt_Vh(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk));
      simde_test_hvx_vector_i32_assert_equal(simde_Q6_V_lo_W(pair), simde_test_hvx_fixture_vector_load(test_vec[i].r_lo, chunk));
      simde_test_hvx_vector_i32_assert_equal(simde_Q6_V_hi_W(pair), simde_test_hvx_fixture_vector_load(test_vec[i].r_hi, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vzxt_Vub(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    uint16_t r_lo[64];
    uint16_t r_hi[64];
  } test_vec[] = {
    { /* a */ { INT8_C(3), INT8_C(10), INT8_C(17), INT8_C(24), INT8_C(31), INT8_C(38), INT8_C(45), INT8_C(52),
                INT8_C(59), INT8_C(66), INT8_C(73), INT8_C(80), INT8_C(87), INT8_C(94), INT8_C(101), INT8_C(108),
                INT8_C(115), INT8_C(122), -INT8_C(127), -INT8_C(120), -INT8_C(113), -INT8_C(106), -INT8_C(99), -INT8_C(92),
                -INT8_C(85), -INT8_C(78), -INT8_C(71), -INT8_C(64), -INT8_C(57), -INT8_C(50), -INT8_C(43), -INT8_C(36),
                -INT8_C(29), -INT8_C(22), -INT8_C(15), -INT8_C(8), -INT8_C(1), INT8_C(6), INT8_C(13), INT8_C(20),
                INT8_C(27), INT8_C(34), INT8_C(41), INT8_C(48), INT8_C(55), INT8_C(62), INT8_C(69), INT8_C(76),
                INT8_C(83), INT8_C(90), INT8_C(97), INT8_C(104), INT8_C(111), INT8_C(118), INT8_C(125), -INT8_C(124),
                -INT8_C(117), -INT8_C(110), -INT8_C(103), -INT8_C(96), -INT8_C(89), -INT8_C(82), -INT8_C(75), -INT8_C(68),
                -INT8_C(61), -INT8_C(54), -INT8_C(47), -INT8_C(40), -INT8_C(33), -INT8_C(26), -INT8_C(19), -INT8_C(12),
                -INT8_C(5), INT8_C(2), INT8_C(9), INT8_C(16), INT8_C(23), INT8_C(30), INT8_C(37), INT8_C(44),
                INT8_C(51), INT8_C(58), INT8_C(65), INT8_C(72), INT8_C(79), INT8_C(86), INT8_C(93), INT8_C(100),
                INT8_C(107), INT8_C(114), INT8_C(121), -INT8_C(128), -INT8_C(121), -INT8_C(114), -INT8_C(107), -INT8_C(100),
                -INT8_C(93), -INT8_C(86), -INT8_C(79), -INT8_C(72), -INT8_C(65), -INT8_C(58), -INT8_C(51), -INT8_C(44),
                -INT8_C(37), -INT8_C(30), -INT8_C(23), -INT8_C(16), -INT8_C(9), -INT8_C(2), INT8_C(5), INT8_C(12),
                INT8_C(19), INT8_C(26), INT8_C(33), INT8_C(40), INT8_C(47), INT8_C(54), INT8_C(61), INT8_C(68),
                INT8_C(75), INT8_C(82), INT8_C(89), INT8_C(96), INT8_C(103), INT8_C(110), INT8_C(117), INT8_C(124) },
      /* r_lo */ { UINT16_C(3), UINT16_C(17), UINT16_C(31), UINT16_C(45), UINT16_C(59), UINT16_C(73), UINT16_C(87), UINT16_C(101),
                   UINT16_C(115), UINT16_C(129), UINT16_C(143), UINT16_C(157), UINT16_C(171), UINT16_C(185), UINT16_C(199), UINT16_C(213),
                   UINT16_C(227), UINT16_C(241), UINT16_C(255), UINT16_C(13), UINT16_C(27), UINT16_C(41), UINT16_C(55), UINT16_C(69),
                   UINT16_C(83), UINT16_C(97), UINT16_C(111), UINT16_C(125), UINT16_C(139), UINT16_C(153), UINT16_C(167), UINT16_C(181),
                   UINT16_C(195), UINT16_C(209), UINT16_C(223), UINT16_C(237), UINT16_C(251), UINT16_C(9), UINT16_C(23), UINT16_C(37),
                   UINT16_C(51), UINT16_C(65), UINT16_C(79), UINT16_C(93), UINT16_C(107), UINT16_C(121), UINT16_C(135), UINT16_C(149),
                   UINT16_C(163), UINT16_C(177), UINT16_C(191), UINT16_C(205), UINT16_C(219), UINT16_C(233), UINT16_C(247), UINT16_C(5),
                   UINT16_C(19), UINT16_C(33), UINT16_C(47), UINT16_C(61), UINT16_C(75), UINT16_C(89), UINT16_C(103), UINT16_C(117) },
      /* r_hi */ { UINT16_C(10), UINT16_C(24), UINT16_C(38), UINT16_C(52), UINT16_C(66), UINT16_C(80), UINT16_C(94), UINT16_C(108),
                   UINT16_C(122), UINT16_C(136), UINT16_C(150), UINT16_C(164), UINT16_C(178), UINT16_C(192), UINT16_C(206), UINT16_C(220),
                   UINT16_C(234), UINT16_C(248), UINT16_C(6), UINT16_C(20), UINT16_C(34), UINT16_C(48), UINT16_C(62), UINT16_C(76),
                   UINT16_C(90), UINT16_C(104), UINT16_C(118), UINT16_C(132), UINT16_C(146), UINT16_C(160), UINT16_C(174), UINT16_C(188),
                   UINT16_C(202), UINT16_C(216), UINT16_C(230), UINT16_C(244), UINT16_C(2), UINT16_C(16), UINT16_C(30), UINT16_C(44),
                   UINT16_C(58), UINT16_C(72), UINT16_C(86), UINT16_C(100), UINT16_C(114), UINT16_C(128), UINT16_C(142), UINT16_C(156),
                   UINT16_C(170), UINT16_C(184), UINT16_C(198), UINT16_C(212), UINT16_C(226), UINT16_C(240), UINT16_C(254), UINT16_C(12),
                   UINT16_C(26), UINT16_C(40), UINT16_C(54), UINT16_C(68), UINT16_C(82), UINT16_C(96), UINT16_C(110), UINT16_C(124) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t pair = simde_Q6_Wuh_vzxt_Vub(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk));
      simde_test_hvx_vector_u16_assert_equal(simde_Q6_V_lo_W(pair), simde_test_hvx_fixture_vector_load(test_vec[i].r_lo, chunk));
      simde_test_hvx_vector_u16_assert_equal(simde_Q6_V_hi_W(pair), simde_test_hvx_fixture_vector_load(test_vec[i].r_hi, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vzxt_Vuh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    uint32_t r_lo[32];
    uint32_t r_hi[32];
  } test_vec[] = {
    { /* a */ { INT8_C(3), INT8_C(10), INT8_C(17), INT8_C(24), INT8_C(31), INT8_C(38), INT8_C(45), INT8_C(52),
                INT8_C(59), INT8_C(66), INT8_C(73), INT8_C(80), INT8_C(87), INT8_C(94), INT8_C(101), INT8_C(108),
                INT8_C(115), INT8_C(122), -INT8_C(127), -INT8_C(120), -INT8_C(113), -INT8_C(106), -INT8_C(99), -INT8_C(92),
                -INT8_C(85), -INT8_C(78), -INT8_C(71), -INT8_C(64), -INT8_C(57), -INT8_C(50), -INT8_C(43), -INT8_C(36),
                -INT8_C(29), -INT8_C(22), -INT8_C(15), -INT8_C(8), -INT8_C(1), INT8_C(6), INT8_C(13), INT8_C(20),
                INT8_C(27), INT8_C(34), INT8_C(41), INT8_C(48), INT8_C(55), INT8_C(62), INT8_C(69), INT8_C(76),
                INT8_C(83), INT8_C(90), INT8_C(97), INT8_C(104), INT8_C(111), INT8_C(118), INT8_C(125), -INT8_C(124),
                -INT8_C(117), -INT8_C(110), -INT8_C(103), -INT8_C(96), -INT8_C(89), -INT8_C(82), -INT8_C(75), -INT8_C(68),
                -INT8_C(61), -INT8_C(54), -INT8_C(47), -INT8_C(40), -INT8_C(33), -INT8_C(26), -INT8_C(19), -INT8_C(12),
                -INT8_C(5), INT8_C(2), INT8_C(9), INT8_C(16), INT8_C(23), INT8_C(30), INT8_C(37), INT8_C(44),
                INT8_C(51), INT8_C(58), INT8_C(65), INT8_C(72), INT8_C(79), INT8_C(86), INT8_C(93), INT8_C(100),
                INT8_C(107), INT8_C(114), INT8_C(121), -INT8_C(128), -INT8_C(121), -INT8_C(114), -INT8_C(107), -INT8_C(100),
                -INT8_C(93), -INT8_C(86), -INT8_C(79), -INT8_C(72), -INT8_C(65), -INT8_C(58), -INT8_C(51), -INT8_C(44),
                -INT8_C(37), -INT8_C(30), -INT8_C(23), -INT8_C(16), -INT8_C(9), -INT8_C(2), INT8_C(5), INT8_C(12),
                INT8_C(19), INT8_C(26), INT8_C(33), INT8_C(40), INT8_C(47), INT8_C(54), INT8_C(61), INT8_C(68),
                INT8_C(75), INT8_C(82), INT8_C(89), INT8_C(96), INT8_C(103), INT8_C(110), INT8_C(117), INT8_C(124) },
      /* r_lo */ { UINT32_C(2563), UINT32_C(9759), UINT32_C(16955), UINT32_C(24151), UINT32_C(31347), UINT32_C(38543), UINT32_C(45739), UINT32_C(52935),
                   UINT32_C(60131), UINT32_C(1791), UINT32_C(8731), UINT32_C(15927), UINT32_C(23123), UINT32_C(30319), UINT32_C(37515), UINT32_C(44711),
                   UINT32_C(51907), UINT32_C(59103), UINT32_C(763), UINT32_C(7703), UINT32_C(14899), UINT32_C(22095), UINT32_C(29291), UINT32_C(36487),
                   UINT32_C(43683), UINT32_C(50879), UINT32_C(58075), UINT32_C(65271), UINT32_C(6675), UINT32_C(13871), UINT32_C(21067), UINT32_C(28263) },
      /* r_hi */ { UINT32_C(6161), UINT32_C(13357), UINT32_C(20553), UINT32_C(27749), UINT32_C(34945), UINT32_C(42141), UINT32_C(49337), UINT32_C(56533),
                   UINT32_C(63729), UINT32_C(5133), UINT32_C(12329), UINT32_C(19525), UINT32_C(26721), UINT32_C(33917), UINT32_C(41113), UINT32_C(48309),
                   UINT32_C(55505), UINT32_C(62701), UINT32_C(4105), UINT32_C(11301), UINT32_C(18497), UINT32_C(25693), UINT32_C(32889), UINT32_C(40085),
                   UINT32_C(47281), UINT32_C(54477), UINT32_C(61673), UINT32_C(3077), UINT32_C(10273), UINT32_C(17469), UINT32_C(24665), UINT32_C(31861) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t pair = simde_Q6_Wuw_vzxt_Vuh(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk));
      simde_test_hvx_vector_u32_assert_equal(simde_Q6_V_lo_W(pair), simde_test_hvx_fixture_vector_load(test_vec[i].r_lo, chunk));
      simde_test_hvx_vector_u32_assert_equal(simde_Q6_V_hi_W(pair), simde_test_hvx_fixture_vector_load(test_vec[i].r_hi, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vunpack_Vb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { /* a */ { INT8_C(3), INT8_C(10), INT8_C(17), INT8_C(24), INT8_C(31), INT8_C(38), INT8_C(45), INT8_C(52),
                INT8_C(59), INT8_C(66), INT8_C(73), INT8_C(80), INT8_C(87), INT8_C(94), INT8_C(101), INT8_C(108),
                INT8_C(115), INT8_C(122), -INT8_C(127), -INT8_C(120), -INT8_C(113), -INT8_C(106), -INT8_C(99), -INT8_C(92),
                -INT8_C(85), -INT8_C(78), -INT8_C(71), -INT8_C(64), -INT8_C(57), -INT8_C(50), -INT8_C(43), -INT8_C(36),
                -INT8_C(29), -INT8_C(22), -INT8_C(15), -INT8_C(8), -INT8_C(1), INT8_C(6), INT8_C(13), INT8_C(20),
                INT8_C(27), INT8_C(34), INT8_C(41), INT8_C(48), INT8_C(55), INT8_C(62), INT8_C(69), INT8_C(76),
                INT8_C(83), INT8_C(90), INT8_C(97), INT8_C(104), INT8_C(111), INT8_C(118), INT8_C(125), -INT8_C(124),
                -INT8_C(117), -INT8_C(110), -INT8_C(103), -INT8_C(96), -INT8_C(89), -INT8_C(82), -INT8_C(75), -INT8_C(68),
                -INT8_C(61), -INT8_C(54), -INT8_C(47), -INT8_C(40), -INT8_C(33), -INT8_C(26), -INT8_C(19), -INT8_C(12),
                -INT8_C(5), INT8_C(2), INT8_C(9), INT8_C(16), INT8_C(23), INT8_C(30), INT8_C(37), INT8_C(44),
                INT8_C(51), INT8_C(58), INT8_C(65), INT8_C(72), INT8_C(79), INT8_C(86), INT8_C(93), INT8_C(100),
                INT8_C(107), INT8_C(114), INT8_C(121), -INT8_C(128), -INT8_C(121), -INT8_C(114), -INT8_C(107), -INT8_C(100),
                -INT8_C(93), -INT8_C(86), -INT8_C(79), -INT8_C(72), -INT8_C(65), -INT8_C(58), -INT8_C(51), -INT8_C(44),
                -INT8_C(37), -INT8_C(30), -INT8_C(23), -INT8_C(16), -INT8_C(9), -INT8_C(2), INT8_C(5), INT8_C(12),
                INT8_C(19), INT8_C(26), INT8_C(33), INT8_C(40), INT8_C(47), INT8_C(54), INT8_C(61), INT8_C(68),
                INT8_C(75), INT8_C(82), INT8_C(89), INT8_C(96), INT8_C(103), INT8_C(110), INT8_C(117), INT8_C(124) },
      /* r_lo */ { INT16_C(3), INT16_C(10), INT16_C(17), INT16_C(24), INT16_C(31), INT16_C(38), INT16_C(45), INT16_C(52),
                   INT16_C(59), INT16_C(66), INT16_C(73), INT16_C(80), INT16_C(87), INT16_C(94), INT16_C(101), INT16_C(108),
                   INT16_C(115), INT16_C(122), -INT16_C(127), -INT16_C(120), -INT16_C(113), -INT16_C(106), -INT16_C(99), -INT16_C(92),
                   -INT16_C(85), -INT16_C(78), -INT16_C(71), -INT16_C(64), -INT16_C(57), -INT16_C(50), -INT16_C(43), -INT16_C(36),
                   -INT16_C(29), -INT16_C(22), -INT16_C(15), -INT16_C(8), -INT16_C(1), INT16_C(6), INT16_C(13), INT16_C(20),
                   INT16_C(27), INT16_C(34), INT16_C(41), INT16_C(48), INT16_C(55), INT16_C(62), INT16_C(69), INT16_C(76),
                   INT16_C(83), INT16_C(90), INT16_C(97), INT16_C(104), INT16_C(111), INT16_C(118), INT16_C(125), -INT16_C(124),
                   -INT16_C(117), -INT16_C(110), -INT16_C(103), -INT16_C(96), -INT16_C(89), -INT16_C(82), -INT16_C(75), -INT16_C(68) },
      /* r_hi */ { -INT16_C(61), -INT16_C(54), -INT16_C(47), -INT16_C(40), -INT16_C(33), -INT16_C(26), -INT16_C(19), -INT16_C(12),
                   -INT16_C(5), INT16_C(2), INT16_C(9), INT16_C(16), INT16_C(23), INT16_C(30), INT16_C(37), INT16_C(44),
                   INT16_C(51), INT16_C(58), INT16_C(65), INT16_C(72), INT16_C(79), INT16_C(86), INT16_C(93), INT16_C(100),
                   INT16_C(107), INT16_C(114), INT16_C(121), -INT16_C(128), -INT16_C(121), -INT16_C(114), -INT16_C(107), -INT16_C(100),
                   -INT16_C(93), -INT16_C(86), -INT16_C(79), -INT16_C(72), -INT16_C(65), -INT16_C(58), -INT16_C(51), -INT16_C(44),
                   -INT16_C(37), -INT16_C(30), -INT16_C(23), -INT16_C(16), -INT16_C(9), -INT16_C(2), INT16_C(5), INT16_C(12),
                   INT16_C(19), INT16_C(26), INT16_C(33), INT16_C(40), INT16_C(47), INT16_C(54), INT16_C(61), INT16_C(68),
                   INT16_C(75), INT16_C(82), INT16_C(89), INT16_C(96), INT16_C(103), INT16_C(110), INT16_C(117), INT16_C(124) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t pair = simde_Q6_Wh_vunpack_Vb(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk));
      simde_test_hvx_vector_i16_assert_equal(simde_Q6_V_lo_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 0));
      simde_test_hvx_vector_i16_assert_equal(simde_Q6_V_hi_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 1));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vunpack_Vub(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    uint16_t r_lo[64];
    uint16_t r_hi[64];
  } test_vec[] = {
    { /* a */ { INT8_C(3), INT8_C(10), INT8_C(17), INT8_C(24), INT8_C(31), INT8_C(38), INT8_C(45), INT8_C(52),
                INT8_C(59), INT8_C(66), INT8_C(73), INT8_C(80), INT8_C(87), INT8_C(94), INT8_C(101), INT8_C(108),
                INT8_C(115), INT8_C(122), -INT8_C(127), -INT8_C(120), -INT8_C(113), -INT8_C(106), -INT8_C(99), -INT8_C(92),
                -INT8_C(85), -INT8_C(78), -INT8_C(71), -INT8_C(64), -INT8_C(57), -INT8_C(50), -INT8_C(43), -INT8_C(36),
                -INT8_C(29), -INT8_C(22), -INT8_C(15), -INT8_C(8), -INT8_C(1), INT8_C(6), INT8_C(13), INT8_C(20),
                INT8_C(27), INT8_C(34), INT8_C(41), INT8_C(48), INT8_C(55), INT8_C(62), INT8_C(69), INT8_C(76),
                INT8_C(83), INT8_C(90), INT8_C(97), INT8_C(104), INT8_C(111), INT8_C(118), INT8_C(125), -INT8_C(124),
                -INT8_C(117), -INT8_C(110), -INT8_C(103), -INT8_C(96), -INT8_C(89), -INT8_C(82), -INT8_C(75), -INT8_C(68),
                -INT8_C(61), -INT8_C(54), -INT8_C(47), -INT8_C(40), -INT8_C(33), -INT8_C(26), -INT8_C(19), -INT8_C(12),
                -INT8_C(5), INT8_C(2), INT8_C(9), INT8_C(16), INT8_C(23), INT8_C(30), INT8_C(37), INT8_C(44),
                INT8_C(51), INT8_C(58), INT8_C(65), INT8_C(72), INT8_C(79), INT8_C(86), INT8_C(93), INT8_C(100),
                INT8_C(107), INT8_C(114), INT8_C(121), -INT8_C(128), -INT8_C(121), -INT8_C(114), -INT8_C(107), -INT8_C(100),
                -INT8_C(93), -INT8_C(86), -INT8_C(79), -INT8_C(72), -INT8_C(65), -INT8_C(58), -INT8_C(51), -INT8_C(44),
                -INT8_C(37), -INT8_C(30), -INT8_C(23), -INT8_C(16), -INT8_C(9), -INT8_C(2), INT8_C(5), INT8_C(12),
                INT8_C(19), INT8_C(26), INT8_C(33), INT8_C(40), INT8_C(47), INT8_C(54), INT8_C(61), INT8_C(68),
                INT8_C(75), INT8_C(82), INT8_C(89), INT8_C(96), INT8_C(103), INT8_C(110), INT8_C(117), INT8_C(124) },
      /* r_lo */ { UINT16_C(3), UINT16_C(10), UINT16_C(17), UINT16_C(24), UINT16_C(31), UINT16_C(38), UINT16_C(45), UINT16_C(52),
                   UINT16_C(59), UINT16_C(66), UINT16_C(73), UINT16_C(80), UINT16_C(87), UINT16_C(94), UINT16_C(101), UINT16_C(108),
                   UINT16_C(115), UINT16_C(122), UINT16_C(129), UINT16_C(136), UINT16_C(143), UINT16_C(150), UINT16_C(157), UINT16_C(164),
                   UINT16_C(171), UINT16_C(178), UINT16_C(185), UINT16_C(192), UINT16_C(199), UINT16_C(206), UINT16_C(213), UINT16_C(220),
                   UINT16_C(227), UINT16_C(234), UINT16_C(241), UINT16_C(248), UINT16_C(255), UINT16_C(6), UINT16_C(13), UINT16_C(20),
                   UINT16_C(27), UINT16_C(34), UINT16_C(41), UINT16_C(48), UINT16_C(55), UINT16_C(62), UINT16_C(69), UINT16_C(76),
                   UINT16_C(83), UINT16_C(90), UINT16_C(97), UINT16_C(104), UINT16_C(111), UINT16_C(118), UINT16_C(125), UINT16_C(132),
                   UINT16_C(139), UINT16_C(146), UINT16_C(153), UINT16_C(160), UINT16_C(167), UINT16_C(174), UINT16_C(181), UINT16_C(188) },
      /* r_hi */ { UINT16_C(195), UINT16_C(202), UINT16_C(209), UINT16_C(216), UINT16_C(223), UINT16_C(230), UINT16_C(237), UINT16_C(244),
                   UINT16_C(251), UINT16_C(2), UINT16_C(9), UINT16_C(16), UINT16_C(23), UINT16_C(30), UINT16_C(37), UINT16_C(44),
                   UINT16_C(51), UINT16_C(58), UINT16_C(65), UINT16_C(72), UINT16_C(79), UINT16_C(86), UINT16_C(93), UINT16_C(100),
                   UINT16_C(107), UINT16_C(114), UINT16_C(121), UINT16_C(128), UINT16_C(135), UINT16_C(142), UINT16_C(149), UINT16_C(156),
                   UINT16_C(163), UINT16_C(170), UINT16_C(177), UINT16_C(184), UINT16_C(191), UINT16_C(198), UINT16_C(205), UINT16_C(212),
                   UINT16_C(219), UINT16_C(226), UINT16_C(233), UINT16_C(240), UINT16_C(247), UINT16_C(254), UINT16_C(5), UINT16_C(12),
                   UINT16_C(19), UINT16_C(26), UINT16_C(33), UINT16_C(40), UINT16_C(47), UINT16_C(54), UINT16_C(61), UINT16_C(68),
                   UINT16_C(75), UINT16_C(82), UINT16_C(89), UINT16_C(96), UINT16_C(103), UINT16_C(110), UINT16_C(117), UINT16_C(124) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t pair = simde_Q6_Wuh_vunpack_Vub(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk));
      simde_test_hvx_vector_u16_assert_equal(simde_Q6_V_lo_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 0));
      simde_test_hvx_vector_u16_assert_equal(simde_Q6_V_hi_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 1));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vunpack_Vh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t r_lo[32];
    int32_t r_hi[32];
  } test_vec[] = {
    { /* a */ { INT8_C(3), INT8_C(10), INT8_C(17), INT8_C(24), INT8_C(31), INT8_C(38), INT8_C(45), INT8_C(52),
                INT8_C(59), INT8_C(66), INT8_C(73), INT8_C(80), INT8_C(87), INT8_C(94), INT8_C(101), INT8_C(108),
                INT8_C(115), INT8_C(122), -INT8_C(127), -INT8_C(120), -INT8_C(113), -INT8_C(106), -INT8_C(99), -INT8_C(92),
                -INT8_C(85), -INT8_C(78), -INT8_C(71), -INT8_C(64), -INT8_C(57), -INT8_C(50), -INT8_C(43), -INT8_C(36),
                -INT8_C(29), -INT8_C(22), -INT8_C(15), -INT8_C(8), -INT8_C(1), INT8_C(6), INT8_C(13), INT8_C(20),
                INT8_C(27), INT8_C(34), INT8_C(41), INT8_C(48), INT8_C(55), INT8_C(62), INT8_C(69), INT8_C(76),
                INT8_C(83), INT8_C(90), INT8_C(97), INT8_C(104), INT8_C(111), INT8_C(118), INT8_C(125), -INT8_C(124),
                -INT8_C(117), -INT8_C(110), -INT8_C(103), -INT8_C(96), -INT8_C(89), -INT8_C(82), -INT8_C(75), -INT8_C(68),
                -INT8_C(61), -INT8_C(54), -INT8_C(47), -INT8_C(40), -INT8_C(33), -INT8_C(26), -INT8_C(19), -INT8_C(12),
                -INT8_C(5), INT8_C(2), INT8_C(9), INT8_C(16), INT8_C(23), INT8_C(30), INT8_C(37), INT8_C(44),
                INT8_C(51), INT8_C(58), INT8_C(65), INT8_C(72), INT8_C(79), INT8_C(86), INT8_C(93), INT8_C(100),
                INT8_C(107), INT8_C(114), INT8_C(121), -INT8_C(128), -INT8_C(121), -INT8_C(114), -INT8_C(107), -INT8_C(100),
                -INT8_C(93), -INT8_C(86), -INT8_C(79), -INT8_C(72), -INT8_C(65), -INT8_C(58), -INT8_C(51), -INT8_C(44),
                -INT8_C(37), -INT8_C(30), -INT8_C(23), -INT8_C(16), -INT8_C(9), -INT8_C(2), INT8_C(5), INT8_C(12),
                INT8_C(19), INT8_C(26), INT8_C(33), INT8_C(40), INT8_C(47), INT8_C(54), INT8_C(61), INT8_C(68),
                INT8_C(75), INT8_C(82), INT8_C(89), INT8_C(96), INT8_C(103), INT8_C(110), INT8_C(117), INT8_C(124) },
      /* r_lo */ { INT32_C(2563), INT32_C(6161), INT32_C(9759), INT32_C(13357), INT32_C(16955), INT32_C(20553), INT32_C(24151), INT32_C(27749),
                   INT32_C(31347), -INT32_C(30591), -INT32_C(26993), -INT32_C(23395), -INT32_C(19797), -INT32_C(16199), -INT32_C(12601), -INT32_C(9003),
                   -INT32_C(5405), -INT32_C(1807), INT32_C(1791), INT32_C(5133), INT32_C(8731), INT32_C(12329), INT32_C(15927), INT32_C(19525),
                   INT32_C(23123), INT32_C(26721), INT32_C(30319), -INT32_C(31619), -INT32_C(28021), -INT32_C(24423), -INT32_C(20825), -INT32_C(17227) },
      /* r_hi */ { -INT32_C(13629), -INT32_C(10031), -INT32_C(6433), -INT32_C(2835), INT32_C(763), INT32_C(4105), INT32_C(7703), INT32_C(11301),
                   INT32_C(14899), INT32_C(18497), INT32_C(22095), INT32_C(25693), INT32_C(29291), -INT32_C(32647), -INT32_C(29049), -INT32_C(25451),
                   -INT32_C(21853), -INT32_C(18255), -INT32_C(14657), -INT32_C(11059), -INT32_C(7461), -INT32_C(3863), -INT32_C(265), INT32_C(3077),
                   INT32_C(6675), INT32_C(10273), INT32_C(13871), INT32_C(17469), INT32_C(21067), INT32_C(24665), INT32_C(28263), INT32_C(31861) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t pair = simde_Q6_Ww_vunpack_Vh(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk));
      simde_test_hvx_vector_i32_assert_equal(simde_Q6_V_lo_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 0));
      simde_test_hvx_vector_i32_assert_equal(simde_Q6_V_hi_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 1));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vunpack_Vuh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    uint32_t r_lo[32];
    uint32_t r_hi[32];
  } test_vec[] = {
    { /* a */ { INT8_C(3), INT8_C(10), INT8_C(17), INT8_C(24), INT8_C(31), INT8_C(38), INT8_C(45), INT8_C(52),
                INT8_C(59), INT8_C(66), INT8_C(73), INT8_C(80), INT8_C(87), INT8_C(94), INT8_C(101), INT8_C(108),
                INT8_C(115), INT8_C(122), -INT8_C(127), -INT8_C(120), -INT8_C(113), -INT8_C(106), -INT8_C(99), -INT8_C(92),
                -INT8_C(85), -INT8_C(78), -INT8_C(71), -INT8_C(64), -INT8_C(57), -INT8_C(50), -INT8_C(43), -INT8_C(36),
                -INT8_C(29), -INT8_C(22), -INT8_C(15), -INT8_C(8), -INT8_C(1), INT8_C(6), INT8_C(13), INT8_C(20),
                INT8_C(27), INT8_C(34), INT8_C(41), INT8_C(48), INT8_C(55), INT8_C(62), INT8_C(69), INT8_C(76),
                INT8_C(83), INT8_C(90), INT8_C(97), INT8_C(104), INT8_C(111), INT8_C(118), INT8_C(125), -INT8_C(124),
                -INT8_C(117), -INT8_C(110), -INT8_C(103), -INT8_C(96), -INT8_C(89), -INT8_C(82), -INT8_C(75), -INT8_C(68),
                -INT8_C(61), -INT8_C(54), -INT8_C(47), -INT8_C(40), -INT8_C(33), -INT8_C(26), -INT8_C(19), -INT8_C(12),
                -INT8_C(5), INT8_C(2), INT8_C(9), INT8_C(16), INT8_C(23), INT8_C(30), INT8_C(37), INT8_C(44),
                INT8_C(51), INT8_C(58), INT8_C(65), INT8_C(72), INT8_C(79), INT8_C(86), INT8_C(93), INT8_C(100),
                INT8_C(107), INT8_C(114), INT8_C(121), -INT8_C(128), -INT8_C(121), -INT8_C(114), -INT8_C(107), -INT8_C(100),
                -INT8_C(93), -INT8_C(86), -INT8_C(79), -INT8_C(72), -INT8_C(65), -INT8_C(58), -INT8_C(51), -INT8_C(44),
                -INT8_C(37), -INT8_C(30), -INT8_C(23), -INT8_C(16), -INT8_C(9), -INT8_C(2), INT8_C(5), INT8_C(12),
                INT8_C(19), INT8_C(26), INT8_C(33), INT8_C(40), INT8_C(47), INT8_C(54), INT8_C(61), INT8_C(68),
                INT8_C(75), INT8_C(82), INT8_C(89), INT8_C(96), INT8_C(103), INT8_C(110), INT8_C(117), INT8_C(124) },
      /* r_lo */ { UINT32_C(2563), UINT32_C(6161), UINT32_C(9759), UINT32_C(13357), UINT32_C(16955), UINT32_C(20553), UINT32_C(24151), UINT32_C(27749),
                   UINT32_C(31347), UINT32_C(34945), UINT32_C(38543), UINT32_C(42141), UINT32_C(45739), UINT32_C(49337), UINT32_C(52935), UINT32_C(56533),
                   UINT32_C(60131), UINT32_C(63729), UINT32_C(1791), UINT32_C(5133), UINT32_C(8731), UINT32_C(12329), UINT32_C(15927), UINT32_C(19525),
                   UINT32_C(23123), UINT32_C(26721), UINT32_C(30319), UINT32_C(33917), UINT32_C(37515), UINT32_C(41113), UINT32_C(44711), UINT32_C(48309) },
      /* r_hi */ { UINT32_C(51907), UINT32_C(55505), UINT32_C(59103), UINT32_C(62701), UINT32_C(763), UINT32_C(4105), UINT32_C(7703), UINT32_C(11301),
                   UINT32_C(14899), UINT32_C(18497), UINT32_C(22095), UINT32_C(25693), UINT32_C(29291), UINT32_C(32889), UINT32_C(36487), UINT32_C(40085),
                   UINT32_C(43683), UINT32_C(47281), UINT32_C(50879), UINT32_C(54477), UINT32_C(58075), UINT32_C(61673), UINT32_C(65271), UINT32_C(3077),
                   UINT32_C(6675), UINT32_C(10273), UINT32_C(13871), UINT32_C(17469), UINT32_C(21067), UINT32_C(24665), UINT32_C(28263), UINT32_C(31861) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t pair = simde_Q6_Wuw_vunpack_Vuh(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk));
      simde_test_hvx_vector_u32_assert_equal(simde_Q6_V_lo_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 0));
      simde_test_hvx_vector_u32_assert_equal(simde_Q6_V_hi_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 1));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vunpackoor_WhVb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { /* a */ { INT8_C(3), INT8_C(10), INT8_C(17), INT8_C(24), INT8_C(31), INT8_C(38), INT8_C(45), INT8_C(52),
                INT8_C(59), INT8_C(66), INT8_C(73), INT8_C(80), INT8_C(87), INT8_C(94), INT8_C(101), INT8_C(108),
                INT8_C(115), INT8_C(122), -INT8_C(127), -INT8_C(120), -INT8_C(113), -INT8_C(106), -INT8_C(99), -INT8_C(92),
                -INT8_C(85), -INT8_C(78), -INT8_C(71), -INT8_C(64), -INT8_C(57), -INT8_C(50), -INT8_C(43), -INT8_C(36),
                -INT8_C(29), -INT8_C(22), -INT8_C(15), -INT8_C(8), -INT8_C(1), INT8_C(6), INT8_C(13), INT8_C(20),
                INT8_C(27), INT8_C(34), INT8_C(41), INT8_C(48), INT8_C(55), INT8_C(62), INT8_C(69), INT8_C(76),
                INT8_C(83), INT8_C(90), INT8_C(97), INT8_C(104), INT8_C(111), INT8_C(118), INT8_C(125), -INT8_C(124),
                -INT8_C(117), -INT8_C(110), -INT8_C(103), -INT8_C(96), -INT8_C(89), -INT8_C(82), -INT8_C(75), -INT8_C(68),
                -INT8_C(61), -INT8_C(54), -INT8_C(47), -INT8_C(40), -INT8_C(33), -INT8_C(26), -INT8_C(19), -INT8_C(12),
                -INT8_C(5), INT8_C(2), INT8_C(9), INT8_C(16), INT8_C(23), INT8_C(30), INT8_C(37), INT8_C(44),
                INT8_C(51), INT8_C(58), INT8_C(65), INT8_C(72), INT8_C(79), INT8_C(86), INT8_C(93), INT8_C(100),
                INT8_C(107), INT8_C(114), INT8_C(121), -INT8_C(128), -INT8_C(121), -INT8_C(114), -INT8_C(107), -INT8_C(100),
                -INT8_C(93), -INT8_C(86), -INT8_C(79), -INT8_C(72), -INT8_C(65), -INT8_C(58), -INT8_C(51), -INT8_C(44),
                -INT8_C(37), -INT8_C(30), -INT8_C(23), -INT8_C(16), -INT8_C(9), -INT8_C(2), INT8_C(5), INT8_C(12),
                INT8_C(19), INT8_C(26), INT8_C(33), INT8_C(40), INT8_C(47), INT8_C(54), INT8_C(61), INT8_C(68),
                INT8_C(75), INT8_C(82), INT8_C(89), INT8_C(96), INT8_C(103), INT8_C(110), INT8_C(117), INT8_C(124) },
      /* r_lo */ { INT16_C(768), INT16_C(2560), INT16_C(4352), INT16_C(6144), INT16_C(7936), INT16_C(9728), INT16_C(11520), INT16_C(13312),
                   INT16_C(15104), INT16_C(16896), INT16_C(18688), INT16_C(20480), INT16_C(22272), INT16_C(24064), INT16_C(25856), INT16_C(27648),
                   INT16_C(29440), INT16_C(31232), -INT16_C(32512), -INT16_C(30720), -INT16_C(28928), -INT16_C(27136), -INT16_C(25344), -INT16_C(23552),
                   -INT16_C(21760), -INT16_C(19968), -INT16_C(18176), -INT16_C(16384), -INT16_C(14592), -INT16_C(12800), -INT16_C(11008), -INT16_C(9216),
                   -INT16_C(7424), -INT16_C(5632), -INT16_C(3840), -INT16_C(2048), -INT16_C(256), INT16_C(1536), INT16_C(3328), INT16_C(5120),
                   INT16_C(6912), INT16_C(8704), INT16_C(10496), INT16_C(12288), INT16_C(14080), INT16_C(15872), INT16_C(17664), INT16_C(19456),
                   INT16_C(21248), INT16_C(23040), INT16_C(24832), INT16_C(26624), INT16_C(28416), INT16_C(30208), INT16_C(32000), -INT16_C(31744),
                   -INT16_C(29952), -INT16_C(28160), -INT16_C(26368), -INT16_C(24576), -INT16_C(22784), -INT16_C(20992), -INT16_C(19200), -INT16_C(17408) },
      /* r_hi */ { -INT16_C(15616), -INT16_C(13824), -INT16_C(12032), -INT16_C(10240), -INT16_C(8448), -INT16_C(6656), -INT16_C(4864), -INT16_C(3072),
                   -INT16_C(1280), INT16_C(512), INT16_C(2304), INT16_C(4096), INT16_C(5888), INT16_C(7680), INT16_C(9472), INT16_C(11264),
                   INT16_C(13056), INT16_C(14848), INT16_C(16640), INT16_C(18432), INT16_C(20224), INT16_C(22016), INT16_C(23808), INT16_C(25600),
                   INT16_C(27392), INT16_C(29184), INT16_C(30976), -INT16_C(32768), -INT16_C(30976), -INT16_C(29184), -INT16_C(27392), -INT16_C(25600),
                   -INT16_C(23808), -INT16_C(22016), -INT16_C(20224), -INT16_C(18432), -INT16_C(16640), -INT16_C(14848), -INT16_C(13056), -INT16_C(11264),
                   -INT16_C(9472), -INT16_C(7680), -INT16_C(5888), -INT16_C(4096), -INT16_C(2304), -INT16_C(512), INT16_C(1280), INT16_C(3072),
                   INT16_C(4864), INT16_C(6656), INT16_C(8448), INT16_C(10240), INT16_C(12032), INT16_C(13824), INT16_C(15616), INT16_C(17408),
                   INT16_C(19200), INT16_C(20992), INT16_C(22784), INT16_C(24576), INT16_C(26368), INT16_C(28160), INT16_C(29952), INT16_C(31744) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vector_t zero = simde_Q6_V_vzero();
      simde_hvx_vectorpair_t pair = simde_Q6_Wh_vunpackoor_WhVb(
        simde_Q6_W_vcombine_VV(zero, zero), simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk));
      simde_test_hvx_vector_i16_assert_equal(simde_Q6_V_lo_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 0));
      simde_test_hvx_vector_i16_assert_equal(simde_Q6_V_hi_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 1));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vunpackoor_WwVh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t r_lo[32];
    int32_t r_hi[32];
  } test_vec[] = {
    { /* a */ { INT8_C(3), INT8_C(10), INT8_C(17), INT8_C(24), INT8_C(31), INT8_C(38), INT8_C(45), INT8_C(52),
                INT8_C(59), INT8_C(66), INT8_C(73), INT8_C(80), INT8_C(87), INT8_C(94), INT8_C(101), INT8_C(108),
                INT8_C(115), INT8_C(122), -INT8_C(127), -INT8_C(120), -INT8_C(113), -INT8_C(106), -INT8_C(99), -INT8_C(92),
                -INT8_C(85), -INT8_C(78), -INT8_C(71), -INT8_C(64), -INT8_C(57), -INT8_C(50), -INT8_C(43), -INT8_C(36),
                -INT8_C(29), -INT8_C(22), -INT8_C(15), -INT8_C(8), -INT8_C(1), INT8_C(6), INT8_C(13), INT8_C(20),
                INT8_C(27), INT8_C(34), INT8_C(41), INT8_C(48), INT8_C(55), INT8_C(62), INT8_C(69), INT8_C(76),
                INT8_C(83), INT8_C(90), INT8_C(97), INT8_C(104), INT8_C(111), INT8_C(118), INT8_C(125), -INT8_C(124),
                -INT8_C(117), -INT8_C(110), -INT8_C(103), -INT8_C(96), -INT8_C(89), -INT8_C(82), -INT8_C(75), -INT8_C(68),
                -INT8_C(61), -INT8_C(54), -INT8_C(47), -INT8_C(40), -INT8_C(33), -INT8_C(26), -INT8_C(19), -INT8_C(12),
                -INT8_C(5), INT8_C(2), INT8_C(9), INT8_C(16), INT8_C(23), INT8_C(30), INT8_C(37), INT8_C(44),
                INT8_C(51), INT8_C(58), INT8_C(65), INT8_C(72), INT8_C(79), INT8_C(86), INT8_C(93), INT8_C(100),
                INT8_C(107), INT8_C(114), INT8_C(121), -INT8_C(128), -INT8_C(121), -INT8_C(114), -INT8_C(107), -INT8_C(100),
                -INT8_C(93), -INT8_C(86), -INT8_C(79), -INT8_C(72), -INT8_C(65), -INT8_C(58), -INT8_C(51), -INT8_C(44),
                -INT8_C(37), -INT8_C(30), -INT8_C(23), -INT8_C(16), -INT8_C(9), -INT8_C(2), INT8_C(5), INT8_C(12),
                INT8_C(19), INT8_C(26), INT8_C(33), INT8_C(40), INT8_C(47), INT8_C(54), INT8_C(61), INT8_C(68),
                INT8_C(75), INT8_C(82), INT8_C(89), INT8_C(96), INT8_C(103), INT8_C(110), INT8_C(117), INT8_C(124) },
      /* r_lo */ { INT32_C(167968768), INT32_C(403767296), INT32_C(639565824), INT32_C(875364352), INT32_C(1111162880), INT32_C(1346961408), INT32_C(1582759936), INT32_C(1818558464),
                   INT32_C(2054356992), -INT32_C(2004811776), -INT32_C(1769013248), -INT32_C(1533214720), -INT32_C(1297416192), -INT32_C(1061617664), -INT32_C(825819136), -INT32_C(590020608),
                   -INT32_C(354222080), -INT32_C(118423552), INT32_C(117374976), INT32_C(336396288), INT32_C(572194816), INT32_C(807993344), INT32_C(1043791872), INT32_C(1279590400),
                   INT32_C(1515388928), INT32_C(1751187456), INT32_C(1986985984), -INT32_C(2072182784), -INT32_C(1836384256), -INT32_C(1600585728), -INT32_C(1364787200), -INT32_C(1128988672) },
      /* r_hi */ { -INT32_C(893190144), -INT32_C(657391616), -INT32_C(421593088), -INT32_C(185794560), INT32_C(50003968), INT32_C(269025280), INT32_C(504823808), INT32_C(740622336),
                   INT32_C(976420864), INT32_C(1212219392), INT32_C(1448017920), INT32_C(1683816448), INT32_C(1919614976), -INT32_C(2139553792), -INT32_C(1903755264), -INT32_C(1667956736),
                   -INT32_C(1432158208), -INT32_C(1196359680), -INT32_C(960561152), -INT32_C(724762624), -INT32_C(488964096), -INT32_C(253165568), -INT32_C(17367040), INT32_C(201654272),
                   INT32_C(437452800), INT32_C(673251328), INT32_C(909049856), INT32_C(1144848384), INT32_C(1380646912), INT32_C(1616445440), INT32_C(1852243968), INT32_C(2088042496) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vector_t zero = simde_Q6_V_vzero();
      simde_hvx_vectorpair_t pair = simde_Q6_Ww_vunpackoor_WwVh(
        simde_Q6_W_vcombine_VV(zero, zero), simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk));
      simde_test_hvx_vector_i32_assert_equal(simde_Q6_V_lo_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 0));
      simde_test_hvx_vector_i32_assert_equal(simde_Q6_V_hi_W(pair), simde_test_hvx_fixture_pair_vector_load(test_vec[i].r_lo, test_vec[i].r_hi, chunk, 1));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsxt_Vb)
SIMDE_TEST_FUNC_LIST_ENTRY(vsxt_Vh)
SIMDE_TEST_FUNC_LIST_ENTRY(vzxt_Vub)
SIMDE_TEST_FUNC_LIST_ENTRY(vzxt_Vuh)
SIMDE_TEST_FUNC_LIST_ENTRY(vunpack_Vb)
SIMDE_TEST_FUNC_LIST_ENTRY(vunpack_Vub)
SIMDE_TEST_FUNC_LIST_ENTRY(vunpack_Vh)
SIMDE_TEST_FUNC_LIST_ENTRY(vunpack_Vuh)
SIMDE_TEST_FUNC_LIST_ENTRY(vunpackoor_WhVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vunpackoor_WwVh)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
