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

#define SIMDE_TEST_HEXAGON_HVX_INSN vrsad

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vrsad.h"

#define SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE 128
#define SIMDE_TEST_HVX_FIXTURE_CHUNKS (SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE / SIMDE_HVX_VECTOR_SIZE)

static simde_hvx_vectorpair_t
simde_test_hvx_fixture_pair_load(const void* ptr, size_t chunk) {
  simde_hvx_vectorpair_t r;
  uint8_t* r_ = HEDLEY_REINTERPRET_CAST(uint8_t*, &r);
  const uint8_t* ptr_ = HEDLEY_REINTERPRET_CAST(const uint8_t*, ptr);

  simde_memcpy(r_, ptr_ + (chunk * SIMDE_HVX_VECTOR_SIZE), SIMDE_HVX_VECTOR_SIZE);
  simde_memcpy(r_ + SIMDE_HVX_VECTOR_SIZE,
               ptr_ + SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE + (chunk * SIMDE_HVX_VECTOR_SIZE),
               SIMDE_HVX_VECTOR_SIZE);
  return r;
}

static int
test_simde_vrsad_WubRubI(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a[256]; uint32_t rt; int32_t iu1; uint32_t r[64];
  } test_vec[] = {
    {      /* a */ {UINT8_C( 22), UINT8_C( 80), UINT8_C(213), UINT8_C(253), UINT8_C( 56), UINT8_C(158), UINT8_C( 76), UINT8_C( 39), UINT8_C(142), UINT8_C(112), UINT8_C( 15), UINT8_C(248), UINT8_C( 58), UINT8_C(109), UINT8_C(213), UINT8_C(163)
                , UINT8_C(138), UINT8_C( 46), UINT8_C( 15), UINT8_C( 79), UINT8_C(101), UINT8_C(150), UINT8_C( 39), UINT8_C(165), UINT8_C( 73), UINT8_C(200), UINT8_C(235), UINT8_C(177), UINT8_C(123), UINT8_C(108), UINT8_C(223), UINT8_C(208)
                , UINT8_C(193), UINT8_C(197), UINT8_C( 57), UINT8_C(174), UINT8_C(143), UINT8_C(113), UINT8_C( 88), UINT8_C(209), UINT8_C(114), UINT8_C(162), UINT8_C(226), UINT8_C( 73), UINT8_C(158), UINT8_C(253), UINT8_C( 65), UINT8_C(211)
                , UINT8_C(198), UINT8_C( 64), UINT8_C( 42), UINT8_C(  5), UINT8_C( 93), UINT8_C( 98), UINT8_C(216), UINT8_C(196), UINT8_C(176), UINT8_C( 11), UINT8_C(236), UINT8_C(140), UINT8_C(113), UINT8_C(115), UINT8_C(152), UINT8_C(155)
                , UINT8_C(249), UINT8_C( 43), UINT8_C(162), UINT8_C(107), UINT8_C(122), UINT8_C(106), UINT8_C( 53), UINT8_C(250), UINT8_C(  6), UINT8_C(213), UINT8_C( 23), UINT8_C( 75), UINT8_C( 20), UINT8_C(174), UINT8_C( 90), UINT8_C(139)
                , UINT8_C(228), UINT8_C(230), UINT8_C(112), UINT8_C( 47), UINT8_C(125), UINT8_C(108), UINT8_C( 87), UINT8_C(138), UINT8_C(255), UINT8_C(114), UINT8_C(141), UINT8_C(144), UINT8_C(152), UINT8_C(209), UINT8_C(116), UINT8_C( 35)
                , UINT8_C( 96), UINT8_C(176), UINT8_C( 14), UINT8_C( 15), UINT8_C(160), UINT8_C(244), UINT8_C(161), UINT8_C(131), UINT8_C( 65), UINT8_C(123), UINT8_C(223), UINT8_C( 81), UINT8_C( 67), UINT8_C( 87), UINT8_C( 22), UINT8_C(204)
                , UINT8_C(115), UINT8_C( 86), UINT8_C(182), UINT8_C( 76), UINT8_C(204), UINT8_C(224), UINT8_C(143), UINT8_C(153), UINT8_C(248), UINT8_C( 17), UINT8_C( 71), UINT8_C(153), UINT8_C( 68), UINT8_C( 36), UINT8_C( 80), UINT8_C(196)
                , UINT8_C(224), UINT8_C( 10), UINT8_C( 77), UINT8_C( 21), UINT8_C(205), UINT8_C(139), UINT8_C(172), UINT8_C(187), UINT8_C(184), UINT8_C(142), UINT8_C(100), UINT8_C(137), UINT8_C(145), UINT8_C(122), UINT8_C( 85), UINT8_C(223)
                , UINT8_C(109), UINT8_C( 30), UINT8_C(121), UINT8_C(183), UINT8_C( 93), UINT8_C(180), UINT8_C( 41), UINT8_C( 48), UINT8_C( 61), UINT8_C(200), UINT8_C(108), UINT8_C(184), UINT8_C(236), UINT8_C(  5), UINT8_C(175), UINT8_C( 56)
                , UINT8_C(113), UINT8_C(105), UINT8_C( 72), UINT8_C(160), UINT8_C( 69), UINT8_C( 61), UINT8_C( 26), UINT8_C(252), UINT8_C( 31), UINT8_C(183), UINT8_C(141), UINT8_C( 97), UINT8_C(  2), UINT8_C(119), UINT8_C( 25), UINT8_C( 73)
                , UINT8_C(226), UINT8_C(129), UINT8_C(218), UINT8_C( 51), UINT8_C(175), UINT8_C(133), UINT8_C( 61), UINT8_C( 37), UINT8_C( 51), UINT8_C(219), UINT8_C( 81), UINT8_C(105), UINT8_C( 49), UINT8_C( 53), UINT8_C(160), UINT8_C( 81)
                , UINT8_C(206), UINT8_C( 77), UINT8_C( 84), UINT8_C( 79), UINT8_C( 35), UINT8_C(120), UINT8_C(142), UINT8_C( 48), UINT8_C(120), UINT8_C(174), UINT8_C( 40), UINT8_C(254), UINT8_C( 34), UINT8_C(  7), UINT8_C( 94), UINT8_C(209)
                , UINT8_C(248), UINT8_C(164), UINT8_C(169), UINT8_C( 93), UINT8_C(192), UINT8_C( 96), UINT8_C( 54), UINT8_C( 10), UINT8_C( 61), UINT8_C( 59), UINT8_C( 82), UINT8_C(211), UINT8_C( 31), UINT8_C( 82), UINT8_C(239), UINT8_C( 96)
                , UINT8_C(145), UINT8_C( 30), UINT8_C( 79), UINT8_C(111), UINT8_C(162), UINT8_C( 45), UINT8_C( 80), UINT8_C(  1), UINT8_C( 73), UINT8_C(194), UINT8_C(154), UINT8_C(160), UINT8_C( 56), UINT8_C(239), UINT8_C( 22), UINT8_C( 60)
                , UINT8_C(203), UINT8_C(242), UINT8_C(121), UINT8_C(191), UINT8_C( 23), UINT8_C(209), UINT8_C(118), UINT8_C( 61), UINT8_C(178), UINT8_C(167), UINT8_C(122), UINT8_C(  1), UINT8_C(187), UINT8_C(159), UINT8_C( 88), UINT8_C( 21) },
      /* rt */ UINT32_C(1558541019),
      /* iu1 */ 0,
      /* r */ {UINT32_C(       408), UINT32_C(       413), UINT32_C(       449), UINT32_C(       253)
                , UINT32_C(       376), UINT32_C(       417), UINT32_C(       323), UINT32_C(       224)
                , UINT32_C(       363), UINT32_C(       335), UINT32_C(       175), UINT32_C(       483)
                , UINT32_C(       345), UINT32_C(       259), UINT32_C(       201), UINT32_C(       247)
                , UINT32_C(       183), UINT32_C(       439), UINT32_C(       535), UINT32_C(       445)
                , UINT32_C(       287), UINT32_C(       288), UINT32_C(       176), UINT32_C(       332)
                , UINT32_C(       477), UINT32_C(       296), UINT32_C(       180), UINT32_C(       498)
                , UINT32_C(       195), UINT32_C(       272), UINT32_C(       345), UINT32_C(       482)
                , UINT32_C(       232), UINT32_C(       289), UINT32_C(       433), UINT32_C(       169)
                , UINT32_C(       421), UINT32_C(       455), UINT32_C(       355), UINT32_C(       192)
                , UINT32_C(       351), UINT32_C(       417), UINT32_C(       337), UINT32_C(       505)
                , UINT32_C(       326), UINT32_C(       180), UINT32_C(       348), UINT32_C(       327)
                , UINT32_C(       102), UINT32_C(       524), UINT32_C(       426), UINT32_C(       434)
                , UINT32_C(       265), UINT32_C(       197), UINT32_C(       309), UINT32_C(       390)
                , UINT32_C(       450), UINT32_C(       189), UINT32_C(       295), UINT32_C(       607)
                , UINT32_C(       251), UINT32_C(       438), UINT32_C(       313), UINT32_C(       330) } },
    {      /* a */ {UINT8_C(  4), UINT8_C(173), UINT8_C( 33), UINT8_C(158), UINT8_C( 23), UINT8_C(193), UINT8_C( 87), UINT8_C( 30), UINT8_C( 15), UINT8_C(147), UINT8_C( 42), UINT8_C(230), UINT8_C(163), UINT8_C( 94), UINT8_C( 85), UINT8_C( 86)
                , UINT8_C(191), UINT8_C( 43), UINT8_C( 11), UINT8_C(238), UINT8_C( 35), UINT8_C(174), UINT8_C(225), UINT8_C(139), UINT8_C(244), UINT8_C(245), UINT8_C( 31), UINT8_C(249), UINT8_C(122), UINT8_C( 72), UINT8_C(198), UINT8_C( 76)
                , UINT8_C(128), UINT8_C(249), UINT8_C( 85), UINT8_C(157), UINT8_C( 67), UINT8_C(203), UINT8_C( 67), UINT8_C( 45), UINT8_C( 58), UINT8_C(163), UINT8_C( 59), UINT8_C( 60), UINT8_C( 91), UINT8_C(116), UINT8_C( 50), UINT8_C(112)
                , UINT8_C(152), UINT8_C(112), UINT8_C(  4), UINT8_C( 17), UINT8_C(128), UINT8_C(131), UINT8_C(236), UINT8_C( 14), UINT8_C( 46), UINT8_C(225), UINT8_C(202), UINT8_C( 46), UINT8_C( 61), UINT8_C( 95), UINT8_C( 10), UINT8_C(134)
                , UINT8_C( 68), UINT8_C(253), UINT8_C( 75), UINT8_C(222), UINT8_C(183), UINT8_C(179), UINT8_C( 78), UINT8_C(184), UINT8_C(253), UINT8_C(123), UINT8_C(189), UINT8_C( 77), UINT8_C( 82), UINT8_C(228), UINT8_C(116), UINT8_C( 19)
                , UINT8_C(117), UINT8_C(169), UINT8_C(145), UINT8_C(116), UINT8_C( 67), UINT8_C(  3), UINT8_C(157), UINT8_C(204), UINT8_C( 18), UINT8_C( 91), UINT8_C( 74), UINT8_C(  6), UINT8_C(106), UINT8_C(250), UINT8_C(153), UINT8_C( 34)
                , UINT8_C( 26), UINT8_C(166), UINT8_C( 66), UINT8_C(204), UINT8_C( 16), UINT8_C(239), UINT8_C(134), UINT8_C(216), UINT8_C(246), UINT8_C( 98), UINT8_C(216), UINT8_C(135), UINT8_C(113), UINT8_C( 36), UINT8_C(123), UINT8_C( 67)
                , UINT8_C(223), UINT8_C(224), UINT8_C( 84), UINT8_C(246), UINT8_C( 88), UINT8_C( 82), UINT8_C( 57), UINT8_C(255), UINT8_C( 27), UINT8_C(100), UINT8_C(226), UINT8_C(184), UINT8_C(187), UINT8_C( 21), UINT8_C(218), UINT8_C(161)
                , UINT8_C(142), UINT8_C(171), UINT8_C( 54), UINT8_C(188), UINT8_C(165), UINT8_C(230), UINT8_C(100), UINT8_C(214), UINT8_C( 59), UINT8_C(191), UINT8_C(227), UINT8_C(226), UINT8_C(102), UINT8_C(128), UINT8_C(124), UINT8_C(207)
                , UINT8_C(155), UINT8_C(127), UINT8_C(159), UINT8_C(126), UINT8_C(245), UINT8_C(252), UINT8_C( 51), UINT8_C(  5), UINT8_C(128), UINT8_C(133), UINT8_C(227), UINT8_C( 36), UINT8_C(189), UINT8_C(129), UINT8_C(133), UINT8_C(112)
                , UINT8_C(113), UINT8_C( 17), UINT8_C( 74), UINT8_C( 58), UINT8_C(232), UINT8_C( 35), UINT8_C(  3), UINT8_C(125), UINT8_C(112), UINT8_C( 20), UINT8_C(238), UINT8_C(182), UINT8_C(214), UINT8_C(139), UINT8_C(208), UINT8_C( 79)
                , UINT8_C(114), UINT8_C( 32), UINT8_C(212), UINT8_C(216), UINT8_C(222), UINT8_C(123), UINT8_C(116), UINT8_C( 63), UINT8_C(123), UINT8_C(103), UINT8_C(184), UINT8_C(151), UINT8_C(202), UINT8_C(193), UINT8_C( 92), UINT8_C(248)
                , UINT8_C(112), UINT8_C( 98), UINT8_C(232), UINT8_C(153), UINT8_C(173), UINT8_C(172), UINT8_C( 51), UINT8_C(114), UINT8_C(136), UINT8_C(179), UINT8_C( 96), UINT8_C( 72), UINT8_C( 33), UINT8_C( 36), UINT8_C(161), UINT8_C( 28)
                , UINT8_C(215), UINT8_C(108), UINT8_C(243), UINT8_C( 55), UINT8_C(  0), UINT8_C(158), UINT8_C( 38), UINT8_C( 35), UINT8_C(154), UINT8_C(  1), UINT8_C(154), UINT8_C(228), UINT8_C(132), UINT8_C(247), UINT8_C(229), UINT8_C( 38)
                , UINT8_C(123), UINT8_C(199), UINT8_C( 63), UINT8_C(149), UINT8_C( 45), UINT8_C(118), UINT8_C( 86), UINT8_C( 88), UINT8_C( 76), UINT8_C( 13), UINT8_C( 79), UINT8_C(116), UINT8_C(186), UINT8_C( 21), UINT8_C(193), UINT8_C( 49)
                , UINT8_C(  5), UINT8_C( 47), UINT8_C(241), UINT8_C( 83), UINT8_C(254), UINT8_C( 39), UINT8_C(253), UINT8_C( 79), UINT8_C( 47), UINT8_C( 89), UINT8_C( 30), UINT8_C( 22), UINT8_C( 57), UINT8_C(209), UINT8_C(134), UINT8_C(190) },
      /* rt */ UINT32_C(3453863044),
      /* iu1 */ 0,
      /* r */ {UINT32_C(       386), UINT32_C(       421), UINT32_C(       370), UINT32_C(       388)
                , UINT32_C(       455), UINT32_C(       189), UINT32_C(       395), UINT32_C(       286)
                , UINT32_C(       241), UINT32_C(       386), UINT32_C(       414), UINT32_C(       385)
                , UINT32_C(       509), UINT32_C(       275), UINT32_C(       293), UINT32_C(       454)
                , UINT32_C(       284), UINT32_C(       232), UINT32_C(       354), UINT32_C(       373)
                , UINT32_C(       207), UINT32_C(       323), UINT32_C(       565), UINT32_C(       319)
                , UINT32_C(       292), UINT32_C(       257), UINT32_C(       287), UINT32_C(       415)
                , UINT32_C(       297), UINT32_C(       372), UINT32_C(       227), UINT32_C(       277)
                , UINT32_C(       250), UINT32_C(       292), UINT32_C(       300), UINT32_C(       353)
                , UINT32_C(       307), UINT32_C(       221), UINT32_C(       319), UINT32_C(       294)
                , UINT32_C(       382), UINT32_C(       397), UINT32_C(       503), UINT32_C(       239)
                , UINT32_C(       587), UINT32_C(       369), UINT32_C(       420), UINT32_C(       215)
                , UINT32_C(       299), UINT32_C(       147), UINT32_C(       287), UINT32_C(       550)
                , UINT32_C(       196), UINT32_C(       301), UINT32_C(       519), UINT32_C(       314)
                , UINT32_C(       178), UINT32_C(       285), UINT32_C(       482), UINT32_C(       357)
                , UINT32_C(       472), UINT32_C(       333), UINT32_C(       396), UINT32_C(       289) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t rr;
      SIMDE_CONSTIFY_2_(simde_Q6_Wuw_vrsad_WubRubI, rr, (HEDLEY_UNREACHABLE(), rr), test_vec[i].iu1,
                       simde_test_hvx_fixture_pair_load(test_vec[i].a, chunk), (int32_t)test_vec[i].rt);
      simde_test_hvx_vector_u32_assert_equal(
        simde_Q6_V_lo_W(rr),
        simde_test_hvx_vector_load(test_vec[i].r + (chunk * SIMDE_HVX_VECTOR_I32_COUNT)));
      simde_test_hvx_vector_u32_assert_equal(
        simde_Q6_V_hi_W(rr),
        simde_test_hvx_vector_load(test_vec[i].r + (SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE / sizeof(uint32_t)) +
                                  (chunk * SIMDE_HVX_VECTOR_I32_COUNT)));
    }
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrsad_WubRubI)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
