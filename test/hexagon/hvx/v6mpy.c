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

#define SIMDE_TEST_HEXAGON_HVX_INSN v6mpy

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/v6mpy.h"

#define SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE 128
#define SIMDE_TEST_HVX_FIXTURE_PAIR_SIZE (SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE * 2)
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
test_simde_v6mpy_WubWbI_h(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t uu[SIMDE_TEST_HVX_FIXTURE_PAIR_SIZE]; int8_t vv[SIMDE_TEST_HVX_FIXTURE_PAIR_SIZE]; int32_t iu2; int32_t r[SIMDE_TEST_HVX_FIXTURE_PAIR_SIZE / sizeof(int32_t)];
  } test_vec[] = {
    {      /* uu */ {UINT8_C( 58), UINT8_C(104), UINT8_C(117), UINT8_C(190), UINT8_C(247), UINT8_C(183), UINT8_C(183), UINT8_C( 81), UINT8_C(167), UINT8_C(  1), UINT8_C(219), UINT8_C( 39), UINT8_C( 18), UINT8_C(253), UINT8_C(177), UINT8_C(217)
                , UINT8_C(177), UINT8_C( 98), UINT8_C( 45), UINT8_C(145), UINT8_C(156), UINT8_C( 74), UINT8_C(161), UINT8_C(222), UINT8_C(  3), UINT8_C( 55), UINT8_C( 74), UINT8_C(207), UINT8_C( 65), UINT8_C(226), UINT8_C(249), UINT8_C(177)
                , UINT8_C(236), UINT8_C( 65), UINT8_C( 30), UINT8_C( 72), UINT8_C(108), UINT8_C( 45), UINT8_C(197), UINT8_C(  6), UINT8_C( 26), UINT8_C(247), UINT8_C(235), UINT8_C(163), UINT8_C(247), UINT8_C(184), UINT8_C( 26), UINT8_C( 28)
                , UINT8_C( 57), UINT8_C(121), UINT8_C(134), UINT8_C( 32), UINT8_C( 97), UINT8_C(157), UINT8_C(179), UINT8_C(106), UINT8_C(136), UINT8_C(153), UINT8_C(233), UINT8_C(142), UINT8_C(196), UINT8_C(251), UINT8_C( 38), UINT8_C(163)
                , UINT8_C(251), UINT8_C( 96), UINT8_C(226), UINT8_C( 26), UINT8_C(204), UINT8_C(244), UINT8_C(206), UINT8_C( 27), UINT8_C( 97), UINT8_C(241), UINT8_C(215), UINT8_C(138), UINT8_C(110), UINT8_C(157), UINT8_C(238), UINT8_C(123)
                , UINT8_C( 54), UINT8_C(172), UINT8_C(236), UINT8_C(115), UINT8_C( 58), UINT8_C(113), UINT8_C( 58), UINT8_C(243), UINT8_C( 68), UINT8_C(226), UINT8_C(116), UINT8_C( 84), UINT8_C( 29), UINT8_C( 40), UINT8_C(124), UINT8_C(122)
                , UINT8_C( 41), UINT8_C( 15), UINT8_C( 98), UINT8_C(  3), UINT8_C(  7), UINT8_C(194), UINT8_C(229), UINT8_C( 96), UINT8_C( 29), UINT8_C(184), UINT8_C( 83), UINT8_C(144), UINT8_C(219), UINT8_C(223), UINT8_C( 47), UINT8_C( 90)
                , UINT8_C( 67), UINT8_C( 57), UINT8_C(153), UINT8_C(188), UINT8_C(229), UINT8_C( 46), UINT8_C(158), UINT8_C(104), UINT8_C(205), UINT8_C(111), UINT8_C( 26), UINT8_C(133), UINT8_C(174), UINT8_C( 19), UINT8_C( 26), UINT8_C(239)
                , UINT8_C(214), UINT8_C( 85), UINT8_C( 20), UINT8_C( 48), UINT8_C(212), UINT8_C(106), UINT8_C(250), UINT8_C(223), UINT8_C(176), UINT8_C(230), UINT8_C(195), UINT8_C(167), UINT8_C(150), UINT8_C(180), UINT8_C( 87), UINT8_C(195)
                , UINT8_C(136), UINT8_C( 18), UINT8_C(249), UINT8_C( 23), UINT8_C(209), UINT8_C(229), UINT8_C(140), UINT8_C(153), UINT8_C(  7), UINT8_C(234), UINT8_C(187), UINT8_C( 31), UINT8_C( 14), UINT8_C( 31), UINT8_C(132), UINT8_C(115)
                , UINT8_C(150), UINT8_C( 84), UINT8_C(175), UINT8_C(141), UINT8_C( 80), UINT8_C( 31), UINT8_C( 75), UINT8_C(205), UINT8_C(191), UINT8_C(115), UINT8_C( 72), UINT8_C( 69), UINT8_C(  4), UINT8_C(164), UINT8_C(157), UINT8_C( 10)
                , UINT8_C( 32), UINT8_C(243), UINT8_C(103), UINT8_C(126), UINT8_C(  2), UINT8_C(161), UINT8_C(178), UINT8_C(129), UINT8_C(143), UINT8_C(116), UINT8_C( 30), UINT8_C( 55), UINT8_C( 83), UINT8_C(187), UINT8_C(121), UINT8_C( 34)
                , UINT8_C(112), UINT8_C(243), UINT8_C(104), UINT8_C(113), UINT8_C(204), UINT8_C(109), UINT8_C(181), UINT8_C(219), UINT8_C( 87), UINT8_C(168), UINT8_C(105), UINT8_C( 29), UINT8_C(136), UINT8_C(188), UINT8_C( 78), UINT8_C(176)
                , UINT8_C(246), UINT8_C( 51), UINT8_C(226), UINT8_C( 90), UINT8_C( 66), UINT8_C(170), UINT8_C( 50), UINT8_C(145), UINT8_C(131), UINT8_C(188), UINT8_C( 55), UINT8_C(245), UINT8_C(165), UINT8_C( 51), UINT8_C(151), UINT8_C(213)
                , UINT8_C(240), UINT8_C(101), UINT8_C(246), UINT8_C( 72), UINT8_C(151), UINT8_C(141), UINT8_C(  9), UINT8_C( 81), UINT8_C( 97), UINT8_C( 43), UINT8_C(219), UINT8_C(195), UINT8_C(230), UINT8_C(165), UINT8_C(245), UINT8_C(129)
                , UINT8_C(251), UINT8_C( 29), UINT8_C( 11), UINT8_C(243), UINT8_C(103), UINT8_C(222), UINT8_C( 91), UINT8_C( 98), UINT8_C( 89), UINT8_C(  1), UINT8_C( 49), UINT8_C( 59), UINT8_C(241), UINT8_C(206), UINT8_C(141), UINT8_C( 16) },
      /* vv */ {-INT8_C(   6), -INT8_C( 113), -INT8_C(  63),  INT8_C(  74), -INT8_C(  82),  INT8_C( 127), -INT8_C(  25),  INT8_C(  41), -INT8_C( 124),  INT8_C(  34),  INT8_C(  18), -INT8_C(  47),  INT8_C(  31), -INT8_C(  18),  INT8_C(  33),  INT8_C(  21)
                , -INT8_C(  23),  INT8_C(  25),  INT8_C(  73), -INT8_C(  42),  INT8_C(   4), -INT8_C(  10),  INT8_C(  39), -INT8_C(  76), -INT8_C( 123),  INT8_C( 110),  INT8_C(  51),  INT8_C(   6), -INT8_C(  90),  INT8_C(  32), -INT8_C( 127),  INT8_C(  79)
                ,  INT8_C( 127),  INT8_C(   2), -INT8_C(  45), -INT8_C(  61),  INT8_C(  67),  INT8_C(  22),  INT8_C( 117), -INT8_C( 121), -INT8_C(  14),  INT8_C( 125), -INT8_C( 120), -INT8_C(  90),  INT8_C(   6), -INT8_C(  33),  INT8_C(  53), -INT8_C(  23)
                ,  INT8_C(  41), -INT8_C(  98), -INT8_C(  45), -INT8_C( 102),  INT8_C( 108),  INT8_C(   4), -INT8_C(  67),  INT8_C(  47),  INT8_C( 126),  INT8_C(  69), -INT8_C(  93), -INT8_C(  98), -INT8_C(   7), -INT8_C( 114), -INT8_C( 117), -INT8_C(  45)
                ,  INT8_C(  20),  INT8_C(  81),  INT8_C(  80),  INT8_C( 113), -INT8_C(  16),  INT8_C( 121), -INT8_C(  37),  INT8_C(  55), -INT8_C(  60), -INT8_C(  41), -INT8_C(  79), -INT8_C( 119),  INT8_C( 127), -INT8_C(  46), -INT8_C(  74),  INT8_C(   2)
                ,  INT8_C( 112), -INT8_C(  90),  INT8_C(  98), -INT8_C( 122), -INT8_C(  26), -INT8_C(  34),  INT8_C(   2),  INT8_C(  67),  INT8_C(  10),  INT8_C(  22),  INT8_C(  69),  INT8_C(  48),  INT8_C(  88), -INT8_C(  46), -INT8_C(  47), -INT8_C(  34)
                , -INT8_C(  42),  INT8_C( 123),  INT8_C(  52),  INT8_C( 110), -INT8_C(  12),  INT8_C(  62), -INT8_C(  76),  INT8_C( 120),  INT8_C( 124), -INT8_C(  48), -INT8_C(  18), -INT8_C(  55), -INT8_C(  58), -INT8_C(  88), -INT8_C(  80), -INT8_C(  42)
                , -INT8_C( 128), -INT8_C( 116), -INT8_C(  99), -INT8_C(   3),  INT8_C( 117),  INT8_C(  43), -INT8_C(  67), -INT8_C( 128), -INT8_C(  11),  INT8_C(   1), -INT8_C( 112),  INT8_C(   9), -INT8_C(  73), -INT8_C(  16), -INT8_C( 119), -INT8_C(  99)
                ,  INT8_C( 102),  INT8_C(  56),  INT8_C(  19), -INT8_C(   1),  INT8_C(  48), -INT8_C( 106),  INT8_C(  23),  INT8_C(  28), -INT8_C(  94), -INT8_C(  71),  INT8_C(  61), -INT8_C( 108),  INT8_C(  83),  INT8_C(  15),  INT8_C(  45), -INT8_C(  13)
                ,  INT8_C(  90),  INT8_C(  58),  INT8_C( 109),  INT8_C( 111),  INT8_C( 127),  INT8_C(  73), -INT8_C(  97),  INT8_C( 118),  INT8_C(   3), -INT8_C(  23),  INT8_C(   4),  INT8_C(  93),  INT8_C(  42),  INT8_C(  12),  INT8_C( 104), -INT8_C( 106)
                ,  INT8_C(  24),  INT8_C(  27), -INT8_C(  11), -INT8_C(  98),  INT8_C(  74),  INT8_C(  56),  INT8_C(  68),  INT8_C(   6), -INT8_C(  54),  INT8_C(  69),  INT8_C( 103), -INT8_C(   4), -INT8_C(  33), -INT8_C( 128), -INT8_C(   4), -INT8_C(   1)
                , -INT8_C(  48), -INT8_C( 101), -INT8_C(  98), -INT8_C(  72), -INT8_C(  23),  INT8_C(   2),  INT8_C(  67), -INT8_C(  43), -INT8_C(  77),  INT8_C( 126), -INT8_C(  83), -INT8_C(  94), -INT8_C(  76),  INT8_C(  35), -INT8_C(  23), -INT8_C( 100)
                ,  INT8_C(  76), -INT8_C(  37),  INT8_C(  77), -INT8_C(  49), -INT8_C(  46), -INT8_C(  97), -INT8_C( 104),  INT8_C(  97), -INT8_C(  35),  INT8_C(  51), -INT8_C( 126), -INT8_C(  13), -INT8_C( 115), -INT8_C(  62), -INT8_C(  34),  INT8_C(  67)
                , -INT8_C( 116),  INT8_C( 100),  INT8_C(  99), -INT8_C( 115),  INT8_C( 109), -INT8_C(  63), -INT8_C(  40), -INT8_C(  81),  INT8_C( 117), -INT8_C(  13), -INT8_C(  31),  INT8_C(  68), -INT8_C(  96),  INT8_C(  28),  INT8_C(  80), -INT8_C(  87)
                ,  INT8_C(  92),  INT8_C( 109), -INT8_C(  35), -INT8_C(  40),  INT8_C(  76),  INT8_C(  66),  INT8_C( 118), -INT8_C(  75), -INT8_C(   6), -INT8_C( 128),  INT8_C(   4), -INT8_C(  15),  INT8_C(  94),  INT8_C( 102),  INT8_C(  61), -INT8_C(  61)
                ,  INT8_C(  56), -INT8_C(  94),  INT8_C( 118),  INT8_C(  89),  INT8_C( 110), -INT8_C(   4), -INT8_C(  27),  INT8_C(  10), -INT8_C(  58),  INT8_C(  56),  INT8_C(  40),  INT8_C(  31), -INT8_C(  56),  INT8_C(  15), -INT8_C(  25), -INT8_C( 111) },
      /* iu2 */ 0,
      /* r */ {-INT32_C(      73609),  INT32_C(      40585),  INT32_C(     178629), -INT32_C(      50148)
                , -INT32_C(      86397), -INT32_C(        756),  INT32_C(      67512),  INT32_C(      31352)
                , -INT32_C(     104720),  INT32_C(       5506), -INT32_C(      57128), -INT32_C(       5797)
                , -INT32_C(       3132),  INT32_C(     145375), -INT32_C(      70959),  INT32_C(      22019)
                , -INT32_C(       5462),  INT32_C(      42622), -INT32_C(      26328),  INT32_C(      70250)
                ,  INT32_C(      74484), -INT32_C(      28676),  INT32_C(      97904), -INT32_C(      70612)
                , -INT32_C(      27342),  INT32_C(      20008),  INT32_C(     102314), -INT32_C(      13363)
                , -INT32_C(      27196), -INT32_C(      27180), -INT32_C(      12946),  INT32_C(      80573)
                , -INT32_C(     131047), -INT32_C(       3476),  INT32_C(     282497),  INT32_C(      73400)
                , -INT32_C(      82267),  INT32_C(      65443), -INT32_C(       8070),  INT32_C(      35083)
                , -INT32_C(      67917), -INT32_C(      48596), -INT32_C(      67535),  INT32_C(       6610)
                , -INT32_C(      60942),  INT32_C(      54192),  INT32_C(       7469),  INT32_C(      70449)
                , -INT32_C(      29329),  INT32_C(     176055),  INT32_C(      49841),  INT32_C(      85384)
                ,  INT32_C(      75609), -INT32_C(      90485),  INT32_C(     123117), -INT32_C(       2734)
                , -INT32_C(     182956), -INT32_C(      24112),  INT32_C(     141372),  INT32_C(      42316)
                ,  INT32_C(      95939), -INT32_C(      28362),  INT32_C(      18560),  INT32_C(     195040) } },
    {      /* uu */ {UINT8_C( 75), UINT8_C(127), UINT8_C(104), UINT8_C(105), UINT8_C(236), UINT8_C(128), UINT8_C(186), UINT8_C(243), UINT8_C( 66), UINT8_C(238), UINT8_C( 53), UINT8_C(215), UINT8_C(174), UINT8_C( 39), UINT8_C( 58), UINT8_C(200)
                , UINT8_C(129), UINT8_C(141), UINT8_C(215), UINT8_C(217), UINT8_C( 45), UINT8_C( 81), UINT8_C(109), UINT8_C(148), UINT8_C(146), UINT8_C( 33), UINT8_C( 10), UINT8_C(173), UINT8_C( 27), UINT8_C(140), UINT8_C(187), UINT8_C( 97)
                , UINT8_C( 18), UINT8_C(239), UINT8_C(173), UINT8_C(100), UINT8_C(235), UINT8_C(217), UINT8_C( 32), UINT8_C(102), UINT8_C( 29), UINT8_C(124), UINT8_C( 62), UINT8_C(  3), UINT8_C( 36), UINT8_C(175), UINT8_C( 65), UINT8_C(227)
                , UINT8_C(  3), UINT8_C(187), UINT8_C(  5), UINT8_C(200), UINT8_C(156), UINT8_C(209), UINT8_C( 31), UINT8_C(139), UINT8_C( 74), UINT8_C( 97), UINT8_C( 55), UINT8_C(193), UINT8_C(231), UINT8_C(240), UINT8_C( 43), UINT8_C(162)
                , UINT8_C(215), UINT8_C(200), UINT8_C( 26), UINT8_C( 17), UINT8_C(217), UINT8_C( 71), UINT8_C(252), UINT8_C( 62), UINT8_C(243), UINT8_C(145), UINT8_C(129), UINT8_C( 59), UINT8_C( 96), UINT8_C(210), UINT8_C(247), UINT8_C(110)
                , UINT8_C(169), UINT8_C( 27), UINT8_C(220), UINT8_C( 51), UINT8_C(183), UINT8_C(210), UINT8_C( 34), UINT8_C(175), UINT8_C(242), UINT8_C(235), UINT8_C(131), UINT8_C( 66), UINT8_C(249), UINT8_C(177), UINT8_C( 77), UINT8_C(217)
                , UINT8_C(178), UINT8_C( 24), UINT8_C(187), UINT8_C( 61), UINT8_C( 35), UINT8_C( 24), UINT8_C(224), UINT8_C(148), UINT8_C(240), UINT8_C(186), UINT8_C(156), UINT8_C(145), UINT8_C( 32), UINT8_C(253), UINT8_C( 82), UINT8_C(189)
                , UINT8_C( 81), UINT8_C(  1), UINT8_C(180), UINT8_C( 61), UINT8_C( 37), UINT8_C( 97), UINT8_C(234), UINT8_C( 51), UINT8_C(185), UINT8_C(111), UINT8_C(229), UINT8_C( 60), UINT8_C( 21), UINT8_C(214), UINT8_C( 67), UINT8_C( 98)
                , UINT8_C(203), UINT8_C(219), UINT8_C( 42), UINT8_C( 54), UINT8_C(165), UINT8_C( 41), UINT8_C(  5), UINT8_C(169), UINT8_C( 15), UINT8_C( 96), UINT8_C(248), UINT8_C( 22), UINT8_C(203), UINT8_C( 24), UINT8_C(233), UINT8_C( 89)
                , UINT8_C(190), UINT8_C(235), UINT8_C( 55), UINT8_C(153), UINT8_C(224), UINT8_C(182), UINT8_C( 57), UINT8_C( 72), UINT8_C(208), UINT8_C( 85), UINT8_C(  2), UINT8_C(  7), UINT8_C(  5), UINT8_C(234), UINT8_C( 62), UINT8_C(174)
                , UINT8_C( 13), UINT8_C(172), UINT8_C(216), UINT8_C(182), UINT8_C(169), UINT8_C( 89), UINT8_C(  9), UINT8_C(  5), UINT8_C(195), UINT8_C( 66), UINT8_C( 34), UINT8_C( 56), UINT8_C(148), UINT8_C( 83), UINT8_C(207), UINT8_C(141)
                , UINT8_C(112), UINT8_C(149), UINT8_C( 11), UINT8_C(130), UINT8_C(178), UINT8_C( 63), UINT8_C(252), UINT8_C(240), UINT8_C(209), UINT8_C(247), UINT8_C(133), UINT8_C(151), UINT8_C(106), UINT8_C( 85), UINT8_C(180), UINT8_C(118)
                , UINT8_C(149), UINT8_C(142), UINT8_C(197), UINT8_C(174), UINT8_C( 68), UINT8_C( 49), UINT8_C( 89), UINT8_C(187), UINT8_C( 79), UINT8_C(124), UINT8_C(156), UINT8_C(  5), UINT8_C( 62), UINT8_C(204), UINT8_C(180), UINT8_C(182)
                , UINT8_C( 41), UINT8_C( 68), UINT8_C(111), UINT8_C(140), UINT8_C(233), UINT8_C(187), UINT8_C(132), UINT8_C(204), UINT8_C( 30), UINT8_C(111), UINT8_C(120), UINT8_C(100), UINT8_C(164), UINT8_C(153), UINT8_C(129), UINT8_C( 23)
                , UINT8_C( 71), UINT8_C(  3), UINT8_C(116), UINT8_C(195), UINT8_C(117), UINT8_C(164), UINT8_C( 34), UINT8_C(168), UINT8_C(185), UINT8_C(215), UINT8_C(135), UINT8_C( 83), UINT8_C(189), UINT8_C(162), UINT8_C( 72), UINT8_C(141)
                , UINT8_C( 49), UINT8_C(228), UINT8_C(201), UINT8_C(210), UINT8_C(255), UINT8_C(139), UINT8_C(244), UINT8_C(147), UINT8_C( 10), UINT8_C(158), UINT8_C( 27), UINT8_C(169), UINT8_C( 18), UINT8_C( 79), UINT8_C(  0), UINT8_C(209) },
      /* vv */ {-INT8_C(   4),  INT8_C(  11), -INT8_C( 118), -INT8_C(  99),  INT8_C(  51),  INT8_C( 122), -INT8_C(  45),  INT8_C( 112),  INT8_C(   3), -INT8_C(  27), -INT8_C(  43), -INT8_C(  67),  INT8_C(  36), -INT8_C( 109),  INT8_C(  72), -INT8_C( 112)
                , -INT8_C(  33), -INT8_C(  52), -INT8_C(  22),  INT8_C(  54), -INT8_C( 125),  INT8_C(  28), -INT8_C( 128),  INT8_C(  35), -INT8_C( 104),  INT8_C(  33),  INT8_C(  78),  INT8_C(  17), -INT8_C(  46), -INT8_C(  71), -INT8_C(  85),  INT8_C(  63)
                , -INT8_C(  99),  INT8_C(  34),  INT8_C(  45), -INT8_C(  34), -INT8_C(  81),  INT8_C( 110),  INT8_C(  61), -INT8_C( 108),  INT8_C(  49), -INT8_C(  69),  INT8_C( 107), -INT8_C(   1),  INT8_C(  31), -INT8_C(  32), -INT8_C(  16), -INT8_C(  27)
                , -INT8_C(   6),  INT8_C(  12),  INT8_C( 106), -INT8_C( 109), -INT8_C(  54), -INT8_C(  97),  INT8_C(  38),  INT8_C(  85),  INT8_C( 104),  INT8_C(  13), -INT8_C( 110),  INT8_C(  92),  INT8_C(   6),  INT8_C(  51), -INT8_C( 123), -INT8_C(  75)
                , -INT8_C(  82),  INT8_C(  72), -INT8_C(  96),  INT8_C(  82),  INT8_C(  84), -INT8_C(  68),  INT8_C( 108), -INT8_C( 102),  INT8_C(  72),  INT8_C( 119),  INT8_C(  62),  INT8_C(  13), -INT8_C(  63),  INT8_C( 121), -INT8_C(   5), -INT8_C(  28)
                , -INT8_C(  77), -INT8_C(  90), -INT8_C(  12),  INT8_C(  38), -INT8_C(  20), -INT8_C(  73), -INT8_C(  21), -INT8_C(  43), -INT8_C(  81), -INT8_C(  70), -INT8_C(   5),  INT8_C(  29),  INT8_C(  90),  INT8_C(  63), -INT8_C(  48), -INT8_C(  24)
                , -INT8_C( 123), -INT8_C(  39), -INT8_C(  77),  INT8_C( 124),  INT8_C(  93),  INT8_C(  80),  INT8_C(  52), -INT8_C(  91),  INT8_C(  18),  INT8_C(  78), -INT8_C(   2), -INT8_C(  34),  INT8_C(  63),  INT8_C(  36), -INT8_C(  36), -INT8_C(  35)
                , -INT8_C(  63),  INT8_C(  19), -INT8_C(   6),  INT8_C(  34),  INT8_C( 122),  INT8_C( 104), -INT8_C( 115),  INT8_C(  72),  INT8_C(  66), -INT8_C(  79), -INT8_C( 102), -INT8_C(  14),  INT8_C( 110), -INT8_C(  65), -INT8_C(  28),  INT8_C(  34)
                ,  INT8_C(  39), -INT8_C(  39),  INT8_C(  88),  INT8_C( 113),  INT8_C(   1), -INT8_C(  90),  INT8_C(  23),  INT8_C(  80),  INT8_C(  16),  INT8_C(  62),  INT8_C(  11), -INT8_C(  84),  INT8_C(  66),  INT8_C( 119), -INT8_C(  54),  INT8_C( 122)
                ,  INT8_C( 108),  INT8_C(  93),  INT8_C(  37), -INT8_C( 116), -INT8_C(  71),  INT8_C( 108), -INT8_C(  65), -INT8_C(  86), -INT8_C( 108), -INT8_C(  45), -INT8_C(  53), -INT8_C(  10), -INT8_C(  63), -INT8_C( 109),  INT8_C(  98),  INT8_C(   8)
                , -INT8_C(  97),  INT8_C(  87), -INT8_C( 103),  INT8_C(  33), -INT8_C(  22),  INT8_C( 108),  INT8_C(  42),  INT8_C(  35),  INT8_C(  46),  INT8_C(  82),  INT8_C(  98), -INT8_C(   9),  INT8_C(   7),  INT8_C(  72), -INT8_C(  13), -INT8_C(  23)
                ,  INT8_C(   3), -INT8_C(  65),  INT8_C(  33), -INT8_C(  15),  INT8_C(  64),  INT8_C(  36),  INT8_C(  58),  INT8_C(  14),  INT8_C(  32),  INT8_C( 102), -INT8_C(  85),  INT8_C(  45),  INT8_C(  79), -INT8_C(  17),  INT8_C(  97), -INT8_C(  35)
                , -INT8_C(  10),  INT8_C( 114),  INT8_C(  93), -INT8_C( 102),  INT8_C(  70),  INT8_C(   0),  INT8_C( 110), -INT8_C(   7),  INT8_C(  22), -INT8_C(  13), -INT8_C(  25),  INT8_C(  47),  INT8_C(  83), -INT8_C( 124), -INT8_C( 125),  INT8_C( 102)
                ,  INT8_C(  16), -INT8_C(  34), -INT8_C(  29),  INT8_C(  48), -INT8_C(  79),  INT8_C(  33),  INT8_C(  58),  INT8_C(   7),  INT8_C(  72), -INT8_C( 107),  INT8_C(  63),  INT8_C(  47),  INT8_C( 117), -INT8_C(  81),  INT8_C( 114),  INT8_C(  96)
                ,  INT8_C(  19),  INT8_C(  99),  INT8_C(  55), -INT8_C(  30),  INT8_C(  55), -INT8_C(  14),  INT8_C(   1), -INT8_C(  50),  INT8_C(  41), -INT8_C( 127), -INT8_C(   3),  INT8_C(  49),  INT8_C(  76), -INT8_C( 127),  INT8_C(  42),  INT8_C(  64)
                , -INT8_C(  34), -INT8_C( 124),  INT8_C(  28), -INT8_C(  89),  INT8_C(  97),  INT8_C(  51),  INT8_C(  64),  INT8_C(  96),  INT8_C(  22),  INT8_C(  14), -INT8_C(  16),  INT8_C( 126), -INT8_C(  51),  INT8_C(  29), -INT8_C(  25), -INT8_C( 112) },
      /* iu2 */ 1,
      /* r */ { INT32_C(      58390),  INT32_C(      86787), -INT32_C(      64439), -INT32_C(       2673)
                ,  INT32_C(      53023), -INT32_C(     187289),  INT32_C(      38998), -INT32_C(      61424)
                ,  INT32_C(      27101),  INT32_C(      35135), -INT32_C(      19657),  INT32_C(      52269)
                ,  INT32_C(      20617),  INT32_C(      85082), -INT32_C(      75208),  INT32_C(     169684)
                , -INT32_C(     141909),  INT32_C(      58426),  INT32_C(      28982), -INT32_C(      47189)
                , -INT32_C(      62764),  INT32_C(     232002),  INT32_C(      56126), -INT32_C(     142334)
                , -INT32_C(     125455), -INT32_C(     130786),  INT32_C(      31891),  INT32_C(      59972)
                , -INT32_C(      58548), -INT32_C(      42778), -INT32_C(     155636),  INT32_C(      77272)
                ,  INT32_C(      15147),  INT32_C(       2686), -INT32_C(       6139),  INT32_C(      72332)
                ,  INT32_C(      59109), -INT32_C(      60736),  INT32_C(      63443), -INT32_C(      32863)
                , -INT32_C(      72694),  INT32_C(      65783), -INT32_C(      16593),  INT32_C(      18563)
                ,  INT32_C(      73408),  INT32_C(     176931),  INT32_C(      33269),  INT32_C(      37085)
                , -INT32_C(      41516), -INT32_C(      73344), -INT32_C(      11690),  INT32_C(      83324)
                , -INT32_C(      31592),  INT32_C(     268386),  INT32_C(      68792), -INT32_C(     132595)
                ,  INT32_C(      21121),  INT32_C(      45656), -INT32_C(       5322),  INT32_C(      99303)
                , -INT32_C(      78640), -INT32_C(      31587), -INT32_C(      53528), -INT32_C(      96761) } },
    {      /* uu */ {UINT8_C(148), UINT8_C(103), UINT8_C(160), UINT8_C(211), UINT8_C(251), UINT8_C(231), UINT8_C(169), UINT8_C(185), UINT8_C(247), UINT8_C( 18), UINT8_C( 69), UINT8_C( 25), UINT8_C(116), UINT8_C(241), UINT8_C(235), UINT8_C(228)
                , UINT8_C(239), UINT8_C(214), UINT8_C( 88), UINT8_C( 88), UINT8_C(237), UINT8_C( 50), UINT8_C(  1), UINT8_C(106), UINT8_C( 77), UINT8_C( 66), UINT8_C(193), UINT8_C(208), UINT8_C( 17), UINT8_C(100), UINT8_C(253), UINT8_C( 78)
                , UINT8_C( 41), UINT8_C( 78), UINT8_C(155), UINT8_C(194), UINT8_C( 25), UINT8_C(  5), UINT8_C(146), UINT8_C(155), UINT8_C(135), UINT8_C( 16), UINT8_C(235), UINT8_C( 78), UINT8_C(191), UINT8_C( 38), UINT8_C(105), UINT8_C( 37)
                , UINT8_C( 20), UINT8_C(205), UINT8_C(117), UINT8_C( 76), UINT8_C(138), UINT8_C(177), UINT8_C(235), UINT8_C( 61), UINT8_C(219), UINT8_C(222), UINT8_C( 38), UINT8_C(189), UINT8_C(153), UINT8_C( 37), UINT8_C( 35), UINT8_C(233)
                , UINT8_C( 40), UINT8_C(230), UINT8_C( 42), UINT8_C(227), UINT8_C(143), UINT8_C( 17), UINT8_C(144), UINT8_C(244), UINT8_C( 12), UINT8_C(162), UINT8_C(125), UINT8_C(175), UINT8_C(193), UINT8_C(139), UINT8_C(140), UINT8_C(193)
                , UINT8_C( 90), UINT8_C(208), UINT8_C(196), UINT8_C( 49), UINT8_C(155), UINT8_C(244), UINT8_C(141), UINT8_C( 12), UINT8_C( 64), UINT8_C(241), UINT8_C(235), UINT8_C( 86), UINT8_C( 60), UINT8_C( 59), UINT8_C(172), UINT8_C( 23)
                , UINT8_C( 29), UINT8_C(227), UINT8_C(220), UINT8_C( 58), UINT8_C( 72), UINT8_C( 67), UINT8_C(255), UINT8_C(108), UINT8_C(154), UINT8_C(253), UINT8_C( 77), UINT8_C( 95), UINT8_C( 50), UINT8_C(196), UINT8_C( 19), UINT8_C(178)
                , UINT8_C(147), UINT8_C( 47), UINT8_C(142), UINT8_C(193), UINT8_C( 26), UINT8_C(197), UINT8_C(180), UINT8_C(209), UINT8_C(133), UINT8_C( 59), UINT8_C(163), UINT8_C(137), UINT8_C(104), UINT8_C(  0), UINT8_C( 63), UINT8_C(240)
                , UINT8_C(  1), UINT8_C(199), UINT8_C(222), UINT8_C(107), UINT8_C(144), UINT8_C(172), UINT8_C(229), UINT8_C(182), UINT8_C(186), UINT8_C(232), UINT8_C(143), UINT8_C( 84), UINT8_C( 90), UINT8_C(135), UINT8_C( 51), UINT8_C( 46)
                , UINT8_C(157), UINT8_C(192), UINT8_C( 64), UINT8_C( 94), UINT8_C(161), UINT8_C(  6), UINT8_C( 47), UINT8_C( 74), UINT8_C(192), UINT8_C( 44), UINT8_C( 15), UINT8_C(228), UINT8_C(  6), UINT8_C(128), UINT8_C(169), UINT8_C(176)
                , UINT8_C(104), UINT8_C(219), UINT8_C(241), UINT8_C( 91), UINT8_C(  9), UINT8_C(178), UINT8_C(123), UINT8_C(132), UINT8_C(109), UINT8_C(200), UINT8_C(219), UINT8_C(225), UINT8_C(221), UINT8_C( 79), UINT8_C(247), UINT8_C(209)
                , UINT8_C( 77), UINT8_C( 55), UINT8_C(200), UINT8_C(119), UINT8_C(108), UINT8_C(152), UINT8_C( 57), UINT8_C( 41), UINT8_C( 45), UINT8_C(219), UINT8_C(204), UINT8_C(220), UINT8_C(108), UINT8_C(  8), UINT8_C(162), UINT8_C(126)
                , UINT8_C(129), UINT8_C(106), UINT8_C(148), UINT8_C(120), UINT8_C( 92), UINT8_C(149), UINT8_C( 76), UINT8_C(173), UINT8_C( 18), UINT8_C(  3), UINT8_C(115), UINT8_C(148), UINT8_C(162), UINT8_C( 18), UINT8_C(175), UINT8_C(149)
                , UINT8_C( 60), UINT8_C( 68), UINT8_C(130), UINT8_C(  4), UINT8_C( 33), UINT8_C( 65), UINT8_C(185), UINT8_C( 45), UINT8_C( 80), UINT8_C(118), UINT8_C( 58), UINT8_C( 44), UINT8_C(218), UINT8_C(202), UINT8_C(136), UINT8_C(155)
                , UINT8_C( 86), UINT8_C( 66), UINT8_C(154), UINT8_C(187), UINT8_C( 72), UINT8_C(  3), UINT8_C(  6), UINT8_C(145), UINT8_C( 29), UINT8_C(231), UINT8_C( 66), UINT8_C(232), UINT8_C(186), UINT8_C(196), UINT8_C( 29), UINT8_C(187)
                , UINT8_C(200), UINT8_C(242), UINT8_C(141), UINT8_C(177), UINT8_C(158), UINT8_C( 57), UINT8_C(114), UINT8_C( 94), UINT8_C( 62), UINT8_C( 50), UINT8_C( 29), UINT8_C(147), UINT8_C(177), UINT8_C( 52), UINT8_C(146), UINT8_C(196) },
      /* vv */ { INT8_C( 120),  INT8_C(  11),  INT8_C( 111),  INT8_C(  44), -INT8_C(  21), -INT8_C(  28),  INT8_C( 124), -INT8_C(  27), -INT8_C(  25),  INT8_C(  40),  INT8_C( 119),  INT8_C(   0), -INT8_C( 111),  INT8_C( 111), -INT8_C(  84), -INT8_C(  63)
                , -INT8_C( 103),  INT8_C(  61), -INT8_C(  23),  INT8_C(  39),  INT8_C(  70), -INT8_C(  34),  INT8_C(  85), -INT8_C(  93), -INT8_C(  97), -INT8_C(  66),  INT8_C(  21),  INT8_C(  38), -INT8_C(  21), -INT8_C(  43), -INT8_C(  55),  INT8_C(  40)
                ,  INT8_C(  42), -INT8_C(  62),  INT8_C( 101), -INT8_C(  80),  INT8_C(  52), -INT8_C(  21),  INT8_C(   5),  INT8_C(  97),  INT8_C(  51), -INT8_C(   8),  INT8_C(  17),  INT8_C(  37),  INT8_C(  73), -INT8_C(  68),  INT8_C(  98), -INT8_C( 107)
                ,  INT8_C(  91), -INT8_C( 122), -INT8_C(  77),  INT8_C(  93),  INT8_C(  23),  INT8_C(  11), -INT8_C(  41),  INT8_C(   4), -INT8_C(  55),  INT8_C(   2),  INT8_C(  99),  INT8_C(  96), -INT8_C(  57), -INT8_C( 107), -INT8_C(  49),  INT8_C(  10)
                ,  INT8_C(  84),  INT8_C(  89),  INT8_C(  60),  INT8_C(  50),  INT8_C( 100), -INT8_C(  99),  INT8_C(   9),  INT8_C(  85),  INT8_C(  87), -INT8_C( 115),  INT8_C(  43),  INT8_C(  22), -INT8_C(  81),  INT8_C( 101),  INT8_C(  42),  INT8_C( 106)
                , -INT8_C(  27),  INT8_C(  65), -INT8_C( 128),  INT8_C(  15), -INT8_C(  12),  INT8_C(  95),  INT8_C(  81),  INT8_C(  25),  INT8_C( 121), -INT8_C(  21),  INT8_C(  67), -INT8_C( 108), -INT8_C(  38),  INT8_C( 115),  INT8_C( 117),  INT8_C(  80)
                , -INT8_C(  11), -INT8_C(  35),  INT8_C(  53),  INT8_C(  75),  INT8_C(  32), -INT8_C(  61),  INT8_C(  59),  INT8_C(  68), -INT8_C(  31),  INT8_C(  12),  INT8_C(  75),  INT8_C( 114), -INT8_C(  39),  INT8_C(  77),  INT8_C( 104),  INT8_C(  60)
                ,  INT8_C(  58),  INT8_C(  24), -INT8_C( 110), -INT8_C(  85), -INT8_C(  21),  INT8_C(  12), -INT8_C(  88),  INT8_C( 106),  INT8_C(  15), -INT8_C(  18), -INT8_C(  94), -INT8_C(  44),  INT8_C(  46),  INT8_C(  76), -INT8_C(  94), -INT8_C(  89)
                ,  INT8_C(  80), -INT8_C(  94),  INT8_C(  10),  INT8_C(  62),  INT8_C(  48),  INT8_C(  24), -INT8_C(  60),  INT8_C(  46), -INT8_C(  87),  INT8_C( 113), -INT8_C( 120), -INT8_C(   6), -INT8_C( 118),  INT8_C(  73), -INT8_C(  22),  INT8_C(  39)
                , -INT8_C(  57), -INT8_C(   1),  INT8_C(  71), -INT8_C(  88),  INT8_C(  27), -INT8_C(  50), -INT8_C( 115), -INT8_C( 118),  INT8_C(  37), -INT8_C(  97), -INT8_C(  32),  INT8_C( 118), -INT8_C(  14),  INT8_C( 116), -INT8_C( 113),  INT8_C( 121)
                , -INT8_C(  19),  INT8_C(  83),  INT8_C(  27), -INT8_C( 118),  INT8_C( 109), -INT8_C(  26),  INT8_C(  26),  INT8_C(  61),  INT8_C(  52),  INT8_C(  33),  INT8_C(  91), -INT8_C(   4), -INT8_C(  87), -INT8_C(  69), -INT8_C(  85),  INT8_C( 117)
                ,  INT8_C( 106),  INT8_C(   1), -INT8_C( 116),  INT8_C(  21), -INT8_C(  54), -INT8_C(  71),  INT8_C(   2), -INT8_C(  12),  INT8_C(  74), -INT8_C(  22), -INT8_C(  94), -INT8_C( 108), -INT8_C(  90), -INT8_C( 120),  INT8_C(  74), -INT8_C( 125)
                , -INT8_C(  29), -INT8_C(  62),  INT8_C(  40),  INT8_C(  64), -INT8_C(   5), -INT8_C( 102), -INT8_C(  41),  INT8_C( 103), -INT8_C( 102),  INT8_C(  52), -INT8_C(   9),  INT8_C( 123), -INT8_C(  54),  INT8_C(  94),  INT8_C( 113), -INT8_C(  10)
                , -INT8_C( 128), -INT8_C(  23), -INT8_C(  30), -INT8_C(   8),  INT8_C(  12),  INT8_C(  53),  INT8_C(   3),  INT8_C(  58),  INT8_C(  94), -INT8_C(  43), -INT8_C(  57), -INT8_C(   3),  INT8_C(  40), -INT8_C(  94), -INT8_C(  57), -INT8_C(  45)
                ,  INT8_C(  77),  INT8_C(   4),  INT8_C(  88), -INT8_C(  21), -INT8_C(  49),  INT8_C(  17),  INT8_C(  89),  INT8_C(  22),  INT8_C(  94),  INT8_C(  51),  INT8_C( 103),  INT8_C(  95), -INT8_C(  40),  INT8_C( 117), -INT8_C(  28), -INT8_C(  51)
                ,  INT8_C(  43), -INT8_C(  66),  INT8_C( 114), -INT8_C( 106), -INT8_C(  23),  INT8_C( 110),  INT8_C( 101),  INT8_C(  16),  INT8_C( 116),  INT8_C( 103), -INT8_C(  41), -INT8_C(  51), -INT8_C( 112),  INT8_C(  89),  INT8_C(  15), -INT8_C( 107) },
      /* iu2 */ 2,
      /* r */ {-INT32_C(      51880), -INT32_C(     185340), -INT32_C(     120969),  INT32_C(      34447)
                , -INT32_C(      96772), -INT32_C(      44974), -INT32_C(      13569), -INT32_C(      99121)
                , -INT32_C(      93988), -INT32_C(       6261), -INT32_C(      69012),  INT32_C(     124205)
                ,  INT32_C(      65863),  INT32_C(      90399),  INT32_C(     113492),  INT32_C(       6362)
                ,  INT32_C(      39031),  INT32_C(      16109), -INT32_C(      59444), -INT32_C(      28819)
                , -INT32_C(      49704), -INT32_C(     120434),  INT32_C(      14247),  INT32_C(       8076)
                , -INT32_C(     139450),  INT32_C(      72495),  INT32_C(      34803),  INT32_C(      96551)
                ,  INT32_C(      23922),  INT32_C(      65896),  INT32_C(      26720),  INT32_C(     120719)
                , -INT32_C(     229568), -INT32_C(     140612), -INT32_C(      16592),  INT32_C(      74211)
                , -INT32_C(     133738), -INT32_C(     159219),  INT32_C(      43803), -INT32_C(      57968)
                , -INT32_C(     113262),  INT32_C(      84197),  INT32_C(      75444),  INT32_C(     233679)
                ,  INT32_C(     141767),  INT32_C(     107546),  INT32_C(     120286),  INT32_C(      18868)
                ,  INT32_C(      17986),  INT32_C(     224365), -INT32_C(      36701), -INT32_C(     160751)
                , -INT32_C(      38743), -INT32_C(      89802),  INT32_C(     169602),  INT32_C(      76623)
                , -INT32_C(     200955),  INT32_C(     173241), -INT32_C(       1343),  INT32_C(     141819)
                , -INT32_C(     172728), -INT32_C(      36110),  INT32_C(     147370),  INT32_C(      50946) } },
    {      /* uu */ {UINT8_C(211), UINT8_C(149), UINT8_C(168), UINT8_C( 74), UINT8_C( 49), UINT8_C(100), UINT8_C(210), UINT8_C(218), UINT8_C(197), UINT8_C( 52), UINT8_C( 87), UINT8_C( 56), UINT8_C( 91), UINT8_C(175), UINT8_C(229), UINT8_C( 20)
                , UINT8_C(145), UINT8_C( 90), UINT8_C(154), UINT8_C(196), UINT8_C( 24), UINT8_C(121), UINT8_C(113), UINT8_C(233), UINT8_C( 73), UINT8_C( 59), UINT8_C(130), UINT8_C(158), UINT8_C(166), UINT8_C(  2), UINT8_C(145), UINT8_C(243)
                , UINT8_C(161), UINT8_C(211), UINT8_C(163), UINT8_C( 85), UINT8_C(  4), UINT8_C( 13), UINT8_C(123), UINT8_C( 36), UINT8_C( 97), UINT8_C( 51), UINT8_C( 40), UINT8_C(164), UINT8_C(182), UINT8_C(145), UINT8_C(199), UINT8_C( 55)
                , UINT8_C(149), UINT8_C(231), UINT8_C( 60), UINT8_C( 30), UINT8_C(110), UINT8_C(  2), UINT8_C(215), UINT8_C( 84), UINT8_C(204), UINT8_C( 66), UINT8_C( 87), UINT8_C( 16), UINT8_C(151), UINT8_C(128), UINT8_C(241), UINT8_C(247)
                , UINT8_C(176), UINT8_C(228), UINT8_C(229), UINT8_C( 40), UINT8_C(144), UINT8_C( 68), UINT8_C( 11), UINT8_C(171), UINT8_C(208), UINT8_C(  1), UINT8_C( 44), UINT8_C(153), UINT8_C( 29), UINT8_C(104), UINT8_C(132), UINT8_C(129)
                , UINT8_C(251), UINT8_C(177), UINT8_C(232), UINT8_C(110), UINT8_C( 65), UINT8_C(  6), UINT8_C(172), UINT8_C( 82), UINT8_C(184), UINT8_C(111), UINT8_C(247), UINT8_C(194), UINT8_C(164), UINT8_C(128), UINT8_C(242), UINT8_C(  2)
                , UINT8_C(207), UINT8_C(116), UINT8_C( 49), UINT8_C(108), UINT8_C(125), UINT8_C(168), UINT8_C( 96), UINT8_C(212), UINT8_C(101), UINT8_C( 97), UINT8_C(120), UINT8_C(234), UINT8_C( 13), UINT8_C(182), UINT8_C( 87), UINT8_C(214)
                , UINT8_C( 52), UINT8_C( 49), UINT8_C( 36), UINT8_C(228), UINT8_C(115), UINT8_C(239), UINT8_C(157), UINT8_C( 78), UINT8_C(194), UINT8_C(147), UINT8_C(128), UINT8_C(220), UINT8_C(157), UINT8_C(203), UINT8_C(243), UINT8_C(152)
                , UINT8_C( 34), UINT8_C(251), UINT8_C( 16), UINT8_C(152), UINT8_C( 30), UINT8_C(128), UINT8_C(100), UINT8_C(180), UINT8_C( 73), UINT8_C(230), UINT8_C( 24), UINT8_C(164), UINT8_C(227), UINT8_C( 44), UINT8_C(245), UINT8_C(140)
                , UINT8_C(188), UINT8_C( 55), UINT8_C( 53), UINT8_C(  6), UINT8_C( 79), UINT8_C( 33), UINT8_C(161), UINT8_C(179), UINT8_C(143), UINT8_C( 96), UINT8_C(135), UINT8_C(205), UINT8_C(111), UINT8_C(183), UINT8_C(162), UINT8_C(127)
                , UINT8_C(179), UINT8_C(155), UINT8_C( 12), UINT8_C(108), UINT8_C(197), UINT8_C(226), UINT8_C(115), UINT8_C(110), UINT8_C(107), UINT8_C( 83), UINT8_C(133), UINT8_C(141), UINT8_C(255), UINT8_C(208), UINT8_C(230), UINT8_C(186)
                , UINT8_C(124), UINT8_C(251), UINT8_C(  9), UINT8_C(207), UINT8_C(216), UINT8_C( 71), UINT8_C(200), UINT8_C(233), UINT8_C(223), UINT8_C(215), UINT8_C(158), UINT8_C( 74), UINT8_C(130), UINT8_C(  8), UINT8_C(221), UINT8_C( 89)
                , UINT8_C(109), UINT8_C( 39), UINT8_C( 28), UINT8_C( 83), UINT8_C( 56), UINT8_C( 41), UINT8_C(156), UINT8_C( 19), UINT8_C(222), UINT8_C( 85), UINT8_C(122), UINT8_C(132), UINT8_C(163), UINT8_C(205), UINT8_C(  1), UINT8_C(202)
                , UINT8_C(158), UINT8_C(122), UINT8_C( 27), UINT8_C(225), UINT8_C( 44), UINT8_C(197), UINT8_C(100), UINT8_C(239), UINT8_C(111), UINT8_C(206), UINT8_C( 10), UINT8_C( 65), UINT8_C(171), UINT8_C(212), UINT8_C( 76), UINT8_C( 80)
                , UINT8_C(  6), UINT8_C(109), UINT8_C( 33), UINT8_C(201), UINT8_C(154), UINT8_C( 65), UINT8_C( 25), UINT8_C(160), UINT8_C(212), UINT8_C(124), UINT8_C(134), UINT8_C(115), UINT8_C(149), UINT8_C(244), UINT8_C(110), UINT8_C(225)
                , UINT8_C(118), UINT8_C(227), UINT8_C(245), UINT8_C(126), UINT8_C( 74), UINT8_C( 12), UINT8_C(185), UINT8_C(173), UINT8_C( 31), UINT8_C( 49), UINT8_C(240), UINT8_C(212), UINT8_C(208), UINT8_C( 13), UINT8_C(232), UINT8_C( 11) },
      /* vv */ {-INT8_C(  62), -INT8_C(  88),  INT8_C(  63),  INT8_C( 123),  INT8_C(  85), -INT8_C(  94), -INT8_C( 116),  INT8_C(  77), -INT8_C( 123), -INT8_C(  53),  INT8_C(  74), -INT8_C(  25), -INT8_C(  52), -INT8_C( 127),  INT8_C( 113),  INT8_C( 108)
                ,  INT8_C(   6),  INT8_C(  72),  INT8_C(  25), -INT8_C(  69), -INT8_C(  34), -INT8_C(  37),  INT8_C(  59),  INT8_C(  99), -INT8_C(  75),  INT8_C(  92), -INT8_C(  80), -INT8_C(   2),  INT8_C(  50), -INT8_C( 101),  INT8_C(  61), -INT8_C(  18)
                ,  INT8_C( 119),  INT8_C(  89), -INT8_C(  11), -INT8_C(  59),  INT8_C(  86),  INT8_C(  80), -INT8_C(  19), -INT8_C(  65),  INT8_C(  95), -INT8_C(  78), -INT8_C( 102), -INT8_C( 112),  INT8_C(  38), -INT8_C(  59), -INT8_C( 107), -INT8_C(  20)
                , -INT8_C(  35), -INT8_C(  39), -INT8_C(  19),  INT8_C( 114),  INT8_C(  42), -INT8_C(  82), -INT8_C(  71), -INT8_C(  13), -INT8_C(  40), -INT8_C(  37), -INT8_C(  27), -INT8_C(  98),  INT8_C(  37), -INT8_C( 107),  INT8_C(  64),  INT8_C(   0)
                , -INT8_C( 109), -INT8_C(  17), -INT8_C( 126),  INT8_C( 115),  INT8_C( 113), -INT8_C(  95),  INT8_C(  40), -INT8_C(  19),  INT8_C(  73),  INT8_C(  19),  INT8_C(  88),  INT8_C(  62), -INT8_C(  73),  INT8_C(  11),  INT8_C( 113), -INT8_C(  77)
                ,  INT8_C(  49),  INT8_C(  85), -INT8_C(  79), -INT8_C(  67), -INT8_C( 107), -INT8_C(  75), -INT8_C(  99), -INT8_C(   9),  INT8_C( 123),  INT8_C(  86),  INT8_C(  31),  INT8_C(   4), -INT8_C(  51),  INT8_C(  80), -INT8_C(  69),  INT8_C( 111)
                ,  INT8_C(  19),  INT8_C( 105),  INT8_C( 102),  INT8_C(   2), -INT8_C(  36), -INT8_C(  98), -INT8_C(  51),  INT8_C(   4), -INT8_C(  41), -INT8_C(  96), -INT8_C(  76), -INT8_C(  19),  INT8_C(  86),  INT8_C(  42), -INT8_C(   1),  INT8_C(  84)
                ,  INT8_C(  97),  INT8_C(  42),  INT8_C(  61),  INT8_C( 117), -INT8_C(  98), -INT8_C(  34),  INT8_C(  87), -INT8_C(  97), -INT8_C(  27),  INT8_C(  86),  INT8_C(  67),  INT8_C(  19), -INT8_C(  90), -INT8_C(   7),  INT8_C(  72),  INT8_C( 110)
                , -INT8_C(   9), -INT8_C(  77), -INT8_C(  22), -INT8_C( 114), -INT8_C(  81),  INT8_C(  95), -INT8_C(  13), -INT8_C( 125), -INT8_C( 109), -INT8_C(  12),  INT8_C( 121), -INT8_C(  62),  INT8_C( 126),  INT8_C(  53), -INT8_C(  17),  INT8_C(  81)
                ,  INT8_C(  97),  INT8_C(   8), -INT8_C( 127), -INT8_C(  49),  INT8_C(   8), -INT8_C(  54),  INT8_C(  48), -INT8_C(  97),  INT8_C( 106), -INT8_C(  35),  INT8_C( 106),  INT8_C(  22),  INT8_C(  74),  INT8_C( 110),  INT8_C(  89),  INT8_C(  87)
                , -INT8_C(  54), -INT8_C(  59),  INT8_C( 112), -INT8_C( 118),  INT8_C( 127), -INT8_C(  57),  INT8_C(  74), -INT8_C(  84),  INT8_C(  94), -INT8_C(  48),  INT8_C(  92), -INT8_C( 107),  INT8_C(  38), -INT8_C(  25), -INT8_C(   2),  INT8_C(  76)
                ,  INT8_C(   5),  INT8_C( 104),  INT8_C(  38), -INT8_C(  19),  INT8_C(  89),  INT8_C(  68),  INT8_C( 126), -INT8_C(  41), -INT8_C(  56), -INT8_C(   2),  INT8_C(  66),  INT8_C(  86),  INT8_C(  12), -INT8_C(  28), -INT8_C(  95),  INT8_C(  40)
                ,  INT8_C(  92), -INT8_C(  44), -INT8_C( 113),  INT8_C(  78), -INT8_C(  44), -INT8_C(  59), -INT8_C(  56),  INT8_C(  90),  INT8_C(  99), -INT8_C(   8), -INT8_C(  75),  INT8_C(  37), -INT8_C(  75), -INT8_C(  96), -INT8_C(   7),  INT8_C(  24)
                ,  INT8_C(   8), -INT8_C( 111), -INT8_C(   3), -INT8_C(  92), -INT8_C(  14), -INT8_C( 107),  INT8_C(  26), -INT8_C(  36),  INT8_C(  82),  INT8_C(  28),  INT8_C(  26), -INT8_C(  25),  INT8_C(  14),  INT8_C( 119), -INT8_C(  30), -INT8_C(  27)
                ,  INT8_C(  34),  INT8_C(  15),  INT8_C(  85), -INT8_C( 100), -INT8_C( 123), -INT8_C(  35),  INT8_C( 109), -INT8_C(  64),  INT8_C(  85), -INT8_C(  11), -INT8_C(  50),  INT8_C(  28),  INT8_C( 125), -INT8_C( 120), -INT8_C(  81),  INT8_C(  43)
                , -INT8_C( 105),  INT8_C( 108),  INT8_C(  12),  INT8_C(  76), -INT8_C( 122),  INT8_C(  74),  INT8_C(  27),  INT8_C(  54), -INT8_C(  64), -INT8_C(  79),  INT8_C( 105), -INT8_C(  80), -INT8_C(  93), -INT8_C( 108), -INT8_C(  62),  INT8_C( 119) },
      /* iu2 */ 3,
      /* r */ {-INT32_C(     137970),  INT32_C(      31992), -INT32_C(     119326),  INT32_C(      85409)
                , -INT32_C(     193998),  INT32_C(      27207), -INT32_C(      16745), -INT32_C(      84471)
                ,  INT32_C(     111612), -INT32_C(      34258),  INT32_C(     179949), -INT32_C(      24758)
                , -INT32_C(      74438), -INT32_C(        501), -INT32_C(       7955), -INT32_C(      64597)
                ,  INT32_C(      35138), -INT32_C(      83506), -INT32_C(      35874),  INT32_C(      29623)
                , -INT32_C(      12068),  INT32_C(     104613),  INT32_C(      69137), -INT32_C(      83231)
                ,  INT32_C(      40535),  INT32_C(     173058),  INT32_C(     107580), -INT32_C(     128379)
                ,  INT32_C(      43363), -INT32_C(       6672),  INT32_C(      98984), -INT32_C(      95136)
                , -INT32_C(      69775),  INT32_C(      37156), -INT32_C(      25362), -INT32_C(      63389)
                , -INT32_C(     120780), -INT32_C(       4908), -INT32_C(      62408), -INT32_C(     109991)
                ,  INT32_C(     139145), -INT32_C(      45003),  INT32_C(      57987), -INT32_C(      47976)
                , -INT32_C(      70920), -INT32_C(        720), -INT32_C(      32222),  INT32_C(      45291)
                , -INT32_C(      23419), -INT32_C(      33212), -INT32_C(      73744), -INT32_C(      28418)
                ,  INT32_C(       4417),  INT32_C(      14161),  INT32_C(      95127), -INT32_C(      52764)
                , -INT32_C(      30565),  INT32_C(     136508),  INT32_C(       3736),  INT32_C(     177758)
                ,  INT32_C(     138520),  INT32_C(      78149),  INT32_C(      65078), -INT32_C(      94882) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t uu = simde_test_hvx_fixture_pair_load(test_vec[i].uu, chunk);
      simde_hvx_vectorpair_t vv = simde_test_hvx_fixture_pair_load(test_vec[i].vv, chunk);
      simde_hvx_vectorpair_t expected = simde_test_hvx_fixture_pair_load(test_vec[i].r, chunk);
      simde_hvx_vectorpair_t rr;
      int32_t r_arr[SIMDE_HVX_VECTOR_I32_COUNT * 2];
      int32_t expected_arr[SIMDE_HVX_VECTOR_I32_COUNT * 2];
      SIMDE_CONSTIFY_4_(simde_Q6_Ww_v6mpy_WubWbI_h, rr, (HEDLEY_UNREACHABLE(), rr), test_vec[i].iu2, uu, vv);
      simde_memcpy(r_arr, &rr, sizeof(r_arr));
      simde_memcpy(expected_arr, &expected, sizeof(expected_arr));
      for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT * 2 ; j++) {
        simde_assert_equal_i32(r_arr[j], expected_arr[j]);
      }
    }
  }

  return 0;
}

static int
test_simde_v6mpy_WubWbI_v(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t uu[SIMDE_TEST_HVX_FIXTURE_PAIR_SIZE]; int8_t vv[SIMDE_TEST_HVX_FIXTURE_PAIR_SIZE]; int32_t iu2; int32_t r[SIMDE_TEST_HVX_FIXTURE_PAIR_SIZE / sizeof(int32_t)];
  } test_vec[] = {
    {      /* uu */ {UINT8_C( 98), UINT8_C( 21), UINT8_C(184), UINT8_C( 54), UINT8_C(180), UINT8_C( 53), UINT8_C(213), UINT8_C(169), UINT8_C(203), UINT8_C(169), UINT8_C(182), UINT8_C(107), UINT8_C( 95), UINT8_C(109), UINT8_C( 19), UINT8_C(212)
                , UINT8_C( 94), UINT8_C(244), UINT8_C(143), UINT8_C(170), UINT8_C( 18), UINT8_C( 80), UINT8_C(141), UINT8_C(203), UINT8_C(200), UINT8_C(188), UINT8_C(190), UINT8_C( 44), UINT8_C(129), UINT8_C(179), UINT8_C(202), UINT8_C(153)
                , UINT8_C( 74), UINT8_C(106), UINT8_C( 28), UINT8_C(119), UINT8_C( 40), UINT8_C(121), UINT8_C( 49), UINT8_C( 32), UINT8_C(118), UINT8_C(155), UINT8_C(123), UINT8_C(164), UINT8_C(210), UINT8_C(136), UINT8_C( 42), UINT8_C( 86)
                , UINT8_C(108), UINT8_C( 89), UINT8_C(124), UINT8_C(215), UINT8_C(241), UINT8_C(110), UINT8_C(214), UINT8_C(154), UINT8_C(103), UINT8_C(192), UINT8_C(236), UINT8_C(196), UINT8_C(250), UINT8_C(182), UINT8_C( 80), UINT8_C( 91)
                , UINT8_C(241), UINT8_C(233), UINT8_C(255), UINT8_C(175), UINT8_C(245), UINT8_C(214), UINT8_C( 63), UINT8_C(  9), UINT8_C(237), UINT8_C(120), UINT8_C(228), UINT8_C(150), UINT8_C( 77), UINT8_C( 91), UINT8_C( 30), UINT8_C(  4)
                , UINT8_C(235), UINT8_C(201), UINT8_C(125), UINT8_C(  3), UINT8_C(142), UINT8_C(231), UINT8_C(186), UINT8_C(158), UINT8_C(244), UINT8_C(250), UINT8_C(189), UINT8_C(163), UINT8_C(194), UINT8_C(184), UINT8_C(226), UINT8_C(247)
                , UINT8_C(114), UINT8_C( 70), UINT8_C(232), UINT8_C(151), UINT8_C(249), UINT8_C( 68), UINT8_C(145), UINT8_C( 54), UINT8_C(128), UINT8_C(237), UINT8_C(206), UINT8_C(139), UINT8_C( 80), UINT8_C( 74), UINT8_C(200), UINT8_C(255)
                , UINT8_C( 58), UINT8_C( 60), UINT8_C(147), UINT8_C( 15), UINT8_C(122), UINT8_C(204), UINT8_C( 44), UINT8_C(249), UINT8_C( 69), UINT8_C(196), UINT8_C(147), UINT8_C( 40), UINT8_C( 80), UINT8_C(199), UINT8_C( 82), UINT8_C( 81)
                , UINT8_C( 47), UINT8_C(125), UINT8_C(137), UINT8_C(163), UINT8_C(121), UINT8_C(181), UINT8_C( 75), UINT8_C(204), UINT8_C( 73), UINT8_C( 67), UINT8_C(198), UINT8_C( 33), UINT8_C( 34), UINT8_C(201), UINT8_C(245), UINT8_C(226)
                , UINT8_C( 74), UINT8_C(133), UINT8_C( 68), UINT8_C(109), UINT8_C( 60), UINT8_C( 39), UINT8_C(192), UINT8_C( 32), UINT8_C(162), UINT8_C( 96), UINT8_C(200), UINT8_C( 31), UINT8_C(154), UINT8_C(176), UINT8_C(  8), UINT8_C( 75)
                , UINT8_C(135), UINT8_C( 45), UINT8_C(184), UINT8_C( 90), UINT8_C( 90), UINT8_C(218), UINT8_C(165), UINT8_C( 39), UINT8_C( 68), UINT8_C(146), UINT8_C( 85), UINT8_C(222), UINT8_C(207), UINT8_C(176), UINT8_C(192), UINT8_C(205)
                , UINT8_C(230), UINT8_C(102), UINT8_C( 11), UINT8_C( 68), UINT8_C( 40), UINT8_C( 49), UINT8_C(235), UINT8_C(250), UINT8_C( 99), UINT8_C(196), UINT8_C(111), UINT8_C( 59), UINT8_C( 78), UINT8_C(216), UINT8_C(  8), UINT8_C( 66)
                , UINT8_C(141), UINT8_C(201), UINT8_C(238), UINT8_C(  1), UINT8_C(119), UINT8_C(113), UINT8_C(183), UINT8_C( 22), UINT8_C(245), UINT8_C(  7), UINT8_C(183), UINT8_C(106), UINT8_C(119), UINT8_C(138), UINT8_C(109), UINT8_C(147)
                , UINT8_C(163), UINT8_C( 98), UINT8_C(177), UINT8_C(187), UINT8_C( 82), UINT8_C(144), UINT8_C(216), UINT8_C( 49), UINT8_C( 36), UINT8_C(198), UINT8_C(120), UINT8_C(149), UINT8_C(185), UINT8_C(253), UINT8_C(204), UINT8_C(184)
                , UINT8_C(105), UINT8_C( 72), UINT8_C( 32), UINT8_C(173), UINT8_C(219), UINT8_C(236), UINT8_C(175), UINT8_C(193), UINT8_C(124), UINT8_C( 85), UINT8_C(232), UINT8_C(189), UINT8_C( 19), UINT8_C(176), UINT8_C( 94), UINT8_C( 97)
                , UINT8_C( 59), UINT8_C(239), UINT8_C(213), UINT8_C(137), UINT8_C(241), UINT8_C( 16), UINT8_C( 83), UINT8_C(137), UINT8_C(109), UINT8_C( 75), UINT8_C(180), UINT8_C( 28), UINT8_C(123), UINT8_C(111), UINT8_C(156), UINT8_C(191) },
      /* vv */ {-INT8_C(   2), -INT8_C(  43), -INT8_C( 121), -INT8_C( 121),  INT8_C(  51),  INT8_C(  63),  INT8_C(  59), -INT8_C(   4), -INT8_C(  32),  INT8_C(  37),  INT8_C(  87), -INT8_C( 107),  INT8_C(  25), -INT8_C( 126), -INT8_C(  90), -INT8_C(   9)
                , -INT8_C(  39), -INT8_C(  92), -INT8_C(  61), -INT8_C(  64),  INT8_C(  23),  INT8_C( 113),  INT8_C(  96),  INT8_C(   2), -INT8_C(  97), -INT8_C( 112),  INT8_C(  87), -INT8_C( 101), -INT8_C(  81), -INT8_C(  80),  INT8_C(  65),  INT8_C(  45)
                ,  INT8_C( 112),  INT8_C(  85),  INT8_C(  75),  INT8_C(  71), -INT8_C(   7), -INT8_C(  31),  INT8_C( 114), -INT8_C(  38), -INT8_C(  61),  INT8_C(  30), -INT8_C(  87), -INT8_C(  30), -INT8_C(  98),  INT8_C(  20), -INT8_C(  88),  INT8_C(  56)
                ,  INT8_C(   4), -INT8_C(  54),  INT8_C(  21), -INT8_C( 110),  INT8_C( 104), -INT8_C(  55), -INT8_C(  74),  INT8_C(  89), -INT8_C(   4), -INT8_C( 122),  INT8_C(  69), -INT8_C(  98),  INT8_C(   4), -INT8_C(  78), -INT8_C( 103), -INT8_C( 110)
                ,  INT8_C(  96), -INT8_C( 118),  INT8_C( 120), -INT8_C(  86), -INT8_C(  97), -INT8_C( 127), -INT8_C( 115),  INT8_C(  16), -INT8_C(  91),  INT8_C(  98),  INT8_C( 102),  INT8_C(  94), -INT8_C(  54),  INT8_C(  51), -INT8_C( 123), -INT8_C( 127)
                ,  INT8_C( 121),  INT8_C( 101), -INT8_C(  76), -INT8_C(  60), -INT8_C( 106), -INT8_C(  57), -INT8_C(  47), -INT8_C(  78), -INT8_C(  47), -INT8_C(  99), -INT8_C(  21),  INT8_C(  11), -INT8_C(  18), -INT8_C(  83),  INT8_C(   2), -INT8_C(   6)
                , -INT8_C(  49), -INT8_C(  12),  INT8_C( 105),  INT8_C(  48),  INT8_C(  82), -INT8_C(  52), -INT8_C( 119),  INT8_C(  14),  INT8_C(  24), -INT8_C( 107),  INT8_C(  39), -INT8_C(  81),  INT8_C(  55),  INT8_C( 105),  INT8_C( 122),  INT8_C(   8)
                , -INT8_C(   2),  INT8_C(  71),  INT8_C( 124),  INT8_C(  43),  INT8_C(  79), -INT8_C( 127),  INT8_C(  80), -INT8_C(  89), -INT8_C(  29), -INT8_C(  76),  INT8_C(  26), -INT8_C(  51),  INT8_C(  97),  INT8_C(  59), -INT8_C(  26), -INT8_C( 100)
                ,  INT8_C( 127), -INT8_C(  30),  INT8_C( 117),  INT8_C( 115),  INT8_C( 106), -INT8_C(  57),  INT8_C(  95), -INT8_C(  87), -INT8_C(  21), -INT8_C(  50),  INT8_C(  72),  INT8_C(  86), -INT8_C(  63),  INT8_C(  44), -INT8_C(  49),  INT8_C(  70)
                ,  INT8_C(  41), -INT8_C(  19), -INT8_C(  25), -INT8_C(  39),  INT8_C( 124),  INT8_C(  40), -INT8_C( 110), -INT8_C( 127),  INT8_C(  44),  INT8_C(  35),  INT8_C(   1), -INT8_C( 114), -INT8_C(  84),  INT8_C(  42),  INT8_C( 116), -INT8_C(  43)
                , -INT8_C(  32), -INT8_C( 108), -INT8_C( 110),  INT8_C(  29),  INT8_C(   4), -INT8_C(  26), -INT8_C( 115),  INT8_C(  58), -INT8_C(  16), -INT8_C(  65),  INT8_C(  30),  INT8_C(  34),  INT8_C( 126),  INT8_C(   2), -INT8_C( 102), -INT8_C(  29)
                , -INT8_C(  64), -INT8_C(  72),  INT8_C( 121), -INT8_C(  11), -INT8_C(  58),  INT8_C(  45),  INT8_C(  64),  INT8_C(  45), -INT8_C( 124),  INT8_C( 116), -INT8_C( 108),  INT8_C( 122), -INT8_C(  25), -INT8_C(  98),  INT8_C(  33),  INT8_C( 105)
                ,  INT8_C( 116), -INT8_C(  76),  INT8_C(  75),  INT8_C(  31),  INT8_C(  36),  INT8_C( 100), -INT8_C(  56),  INT8_C( 108),  INT8_C(  92),  INT8_C(  58), -INT8_C( 112), -INT8_C(   7), -INT8_C(  46), -INT8_C(  23), -INT8_C(  11),  INT8_C(  69)
                ,  INT8_C(  28), -INT8_C(  64), -INT8_C(  68),  INT8_C(  33),  INT8_C(  62),  INT8_C(  31), -INT8_C(  19), -INT8_C(  74), -INT8_C(  35), -INT8_C(  63), -INT8_C(  21), -INT8_C(  41),  INT8_C(  36), -INT8_C(  78),  INT8_C(  86),  INT8_C(  50)
                ,  INT8_C(  74),  INT8_C(  64),  INT8_C( 105),  INT8_C(  44), -INT8_C( 104), -INT8_C(  37), -INT8_C(  24),  INT8_C( 111),  INT8_C(  89),  INT8_C(  84), -INT8_C( 108), -INT8_C( 107), -INT8_C( 111), -INT8_C(  47), -INT8_C( 106), -INT8_C(  76)
                ,  INT8_C(  18),  INT8_C(  11),  INT8_C(  84),  INT8_C( 112),  INT8_C( 115),  INT8_C(  52), -INT8_C(  37), -INT8_C(  32),  INT8_C(  89),  INT8_C( 123),  INT8_C( 119), -INT8_C(  65),  INT8_C( 125),  INT8_C(  29),  INT8_C( 104), -INT8_C(  71) },
      /* iu2 */ 0,
      /* r */ {-INT32_C(       9462), -INT32_C(      94164),  INT32_C(       8889),  INT32_C(      17036)
                ,  INT32_C(     116889),  INT32_C(      38494), -INT32_C(     123690),  INT32_C(     187976)
                ,  INT32_C(      54390), -INT32_C(     111918), -INT32_C(      99544), -INT32_C(      80274)
                ,  INT32_C(     127302),  INT32_C(      19548), -INT32_C(     133332), -INT32_C(      42442)
                ,  INT32_C(      23195), -INT32_C(      46116), -INT32_C(      70254),  INT32_C(     134407)
                ,  INT32_C(      56628), -INT32_C(      83152),  INT32_C(     104632), -INT32_C(      97664)
                , -INT32_C(      44284), -INT32_C(      81255),  INT32_C(     158265),  INT32_C(        909)
                , -INT32_C(      39379),  INT32_C(      31304), -INT32_C(      57504), -INT32_C(        462)
                ,  INT32_C(      40215), -INT32_C(     103672),  INT32_C(     198151),  INT32_C(      22509)
                ,  INT32_C(     175892),  INT32_C(      60896), -INT32_C(     109685),  INT32_C(      81925)
                ,  INT32_C(     107574), -INT32_C(      44264), -INT32_C(     232550), -INT32_C(     180030)
                ,  INT32_C(     121482), -INT32_C(      43047), -INT32_C(     123106),  INT32_C(      19643)
                , -INT32_C(     270711),  INT32_C(      59150), -INT32_C(     120598),  INT32_C(     157281)
                ,  INT32_C(      74400), -INT32_C(      84111),  INT32_C(     143334), -INT32_C(     289933)
                , -INT32_C(      36143), -INT32_C(      74427),  INT32_C(      94734),  INT32_C(      88212)
                , -INT32_C(     139822),  INT32_C(      42575),  INT32_C(      53878), -INT32_C(      24501) } },
    {      /* uu */ {UINT8_C(188), UINT8_C(165), UINT8_C(176), UINT8_C(147), UINT8_C(212), UINT8_C(181), UINT8_C(128), UINT8_C(212), UINT8_C( 44), UINT8_C(205), UINT8_C(218), UINT8_C(236), UINT8_C(236), UINT8_C(192), UINT8_C(230), UINT8_C( 66)
                , UINT8_C(132), UINT8_C( 91), UINT8_C( 13), UINT8_C(122), UINT8_C( 58), UINT8_C(203), UINT8_C(125), UINT8_C( 79), UINT8_C( 23), UINT8_C(118), UINT8_C(221), UINT8_C(213), UINT8_C(245), UINT8_C(120), UINT8_C(174), UINT8_C(148)
                , UINT8_C(136), UINT8_C(150), UINT8_C( 22), UINT8_C( 48), UINT8_C( 33), UINT8_C(113), UINT8_C(249), UINT8_C(186), UINT8_C( 80), UINT8_C(241), UINT8_C( 39), UINT8_C( 25), UINT8_C(126), UINT8_C(213), UINT8_C(178), UINT8_C( 81)
                , UINT8_C( 85), UINT8_C( 90), UINT8_C(242), UINT8_C( 58), UINT8_C( 42), UINT8_C(100), UINT8_C(105), UINT8_C(214), UINT8_C(  8), UINT8_C( 57), UINT8_C(149), UINT8_C(169), UINT8_C(149), UINT8_C(200), UINT8_C(  8), UINT8_C( 63)
                , UINT8_C(191), UINT8_C(224), UINT8_C(155), UINT8_C(238), UINT8_C(241), UINT8_C(209), UINT8_C( 67), UINT8_C(175), UINT8_C( 95), UINT8_C(229), UINT8_C(186), UINT8_C( 16), UINT8_C(116), UINT8_C( 73), UINT8_C(  6), UINT8_C( 38)
                , UINT8_C(135), UINT8_C(143), UINT8_C( 46), UINT8_C(126), UINT8_C(133), UINT8_C( 54), UINT8_C( 92), UINT8_C( 87), UINT8_C(126), UINT8_C(252), UINT8_C(115), UINT8_C(125), UINT8_C( 20), UINT8_C(  7), UINT8_C( 21), UINT8_C( 35)
                , UINT8_C( 85), UINT8_C(235), UINT8_C( 26), UINT8_C( 24), UINT8_C(237), UINT8_C(198), UINT8_C(121), UINT8_C(147), UINT8_C( 60), UINT8_C(204), UINT8_C(153), UINT8_C(229), UINT8_C(237), UINT8_C(144), UINT8_C( 88), UINT8_C( 45)
                , UINT8_C(211), UINT8_C(141), UINT8_C( 74), UINT8_C(154), UINT8_C( 47), UINT8_C( 40), UINT8_C( 95), UINT8_C(219), UINT8_C(167), UINT8_C( 51), UINT8_C( 35), UINT8_C(245), UINT8_C( 15), UINT8_C( 15), UINT8_C(181), UINT8_C(176)
                , UINT8_C(207), UINT8_C(151), UINT8_C(132), UINT8_C(218), UINT8_C( 12), UINT8_C(253), UINT8_C( 39), UINT8_C(234), UINT8_C(136), UINT8_C(180), UINT8_C(180), UINT8_C(157), UINT8_C( 11), UINT8_C(118), UINT8_C( 26), UINT8_C( 18)
                , UINT8_C(130), UINT8_C(130), UINT8_C(166), UINT8_C(  1), UINT8_C( 81), UINT8_C(251), UINT8_C(238), UINT8_C(223), UINT8_C(168), UINT8_C( 43), UINT8_C(226), UINT8_C(153), UINT8_C( 33), UINT8_C(202), UINT8_C(155), UINT8_C( 95)
                , UINT8_C(219), UINT8_C(186), UINT8_C( 11), UINT8_C(114), UINT8_C( 32), UINT8_C(122), UINT8_C(179), UINT8_C(210), UINT8_C(154), UINT8_C(124), UINT8_C(  2), UINT8_C(115), UINT8_C( 66), UINT8_C(143), UINT8_C( 56), UINT8_C( 40)
                , UINT8_C( 26), UINT8_C(171), UINT8_C(191), UINT8_C( 27), UINT8_C(253), UINT8_C( 46), UINT8_C(143), UINT8_C(210), UINT8_C( 40), UINT8_C(179), UINT8_C(  3), UINT8_C(186), UINT8_C( 15), UINT8_C( 36), UINT8_C(153), UINT8_C(224)
                , UINT8_C(216), UINT8_C(160), UINT8_C(198), UINT8_C(254), UINT8_C(225), UINT8_C( 18), UINT8_C(250), UINT8_C(203), UINT8_C(117), UINT8_C( 26), UINT8_C(112), UINT8_C( 31), UINT8_C( 79), UINT8_C(105), UINT8_C(156), UINT8_C( 50)
                , UINT8_C( 52), UINT8_C(115), UINT8_C(105), UINT8_C(118), UINT8_C(174), UINT8_C( 60), UINT8_C( 88), UINT8_C(137), UINT8_C(115), UINT8_C(254), UINT8_C(221), UINT8_C( 45), UINT8_C( 52), UINT8_C(240), UINT8_C(255), UINT8_C(132)
                , UINT8_C(104), UINT8_C(200), UINT8_C(222), UINT8_C(129), UINT8_C(135), UINT8_C(200), UINT8_C(225), UINT8_C(187), UINT8_C(129), UINT8_C(112), UINT8_C( 45), UINT8_C( 54), UINT8_C(193), UINT8_C( 91), UINT8_C(  4), UINT8_C( 10)
                , UINT8_C( 49), UINT8_C( 58), UINT8_C(  3), UINT8_C( 62), UINT8_C(191), UINT8_C(110), UINT8_C(246), UINT8_C( 19), UINT8_C(239), UINT8_C( 27), UINT8_C(103), UINT8_C(154), UINT8_C(103), UINT8_C( 97), UINT8_C(101), UINT8_C( 27) },
      /* vv */ { INT8_C(  33),  INT8_C( 127),  INT8_C( 104), -INT8_C(  46), -INT8_C(  77),  INT8_C(  13), -INT8_C(  31),  INT8_C(  39), -INT8_C(  70),  INT8_C(  27),  INT8_C(  52), -INT8_C( 106),  INT8_C(  16),  INT8_C(  38),  INT8_C(  81), -INT8_C(  40)
                , -INT8_C(  39), -INT8_C( 111), -INT8_C( 126), -INT8_C( 105),  INT8_C( 105), -INT8_C(  93),  INT8_C(  16), -INT8_C(  84), -INT8_C(  68),  INT8_C(  48),  INT8_C(  28),  INT8_C(  31),  INT8_C(  71), -INT8_C( 105),  INT8_C(  66), -INT8_C(  17)
                ,  INT8_C(  28), -INT8_C(  94), -INT8_C(  19),  INT8_C(   0),  INT8_C(  39),  INT8_C(  24), -INT8_C(  64), -INT8_C(  93),  INT8_C(  37), -INT8_C(  64), -INT8_C( 108),  INT8_C(  35), -INT8_C(  74),  INT8_C(   7), -INT8_C(   8),  INT8_C( 102)
                ,  INT8_C(  36), -INT8_C(  64), -INT8_C(  61), -INT8_C(  42), -INT8_C( 111), -INT8_C(  53),  INT8_C( 118),  INT8_C(  27), -INT8_C(   7),  INT8_C(  74), -INT8_C(  23), -INT8_C(  59),  INT8_C( 120),  INT8_C( 123), -INT8_C(  32),  INT8_C(  77)
                ,  INT8_C(  13), -INT8_C(  18), -INT8_C(  18), -INT8_C(  69), -INT8_C(  76), -INT8_C(  77), -INT8_C(  50), -INT8_C(  38),  INT8_C(  21),  INT8_C(  72), -INT8_C(  66),  INT8_C( 114), -INT8_C(  89), -INT8_C(  70), -INT8_C( 118), -INT8_C(  51)
                ,  INT8_C(   9), -INT8_C(  18), -INT8_C(  76), -INT8_C(  30), -INT8_C(  84),  INT8_C(  22),  INT8_C(  15),  INT8_C(  38),  INT8_C( 122),  INT8_C( 125),  INT8_C(  42),  INT8_C(  58), -INT8_C(  13), -INT8_C(  49), -INT8_C(  17), -INT8_C(  58)
                , -INT8_C(  50), -INT8_C(  83),  INT8_C(  31), -INT8_C(  25), -INT8_C(  34),  INT8_C(   1),  INT8_C(  47), -INT8_C( 108),  INT8_C(   9), -INT8_C(  82),  INT8_C( 125), -INT8_C(  68), -INT8_C( 112), -INT8_C(  53),  INT8_C(  97), -INT8_C(  60)
                , -INT8_C(  40), -INT8_C(  30),  INT8_C(  20), -INT8_C(  77), -INT8_C(  84), -INT8_C( 101),  INT8_C(  23), -INT8_C(   1), -INT8_C(  73), -INT8_C(  62), -INT8_C(  26), -INT8_C(  68),  INT8_C( 120), -INT8_C(  96), -INT8_C(  89),  INT8_C(  85)
                , -INT8_C( 104), -INT8_C(  33), -INT8_C(   4),  INT8_C(  71), -INT8_C(  55), -INT8_C(  72), -INT8_C( 100),  INT8_C(  92),  INT8_C(  34),  INT8_C(  19), -INT8_C(  11),  INT8_C( 100),  INT8_C(  80), -INT8_C(  30),  INT8_C(  67), -INT8_C(  38)
                , -INT8_C(  22),  INT8_C(  96), -INT8_C(  82), -INT8_C(  71),  INT8_C(  24),  INT8_C(  10), -INT8_C(  73),  INT8_C(  19),  INT8_C(  63),  INT8_C( 117),  INT8_C(  71), -INT8_C( 115),  INT8_C(  92), -INT8_C(  14), -INT8_C(  57), -INT8_C(  21)
                , -INT8_C(  21), -INT8_C(  12),  INT8_C(  63),  INT8_C(  67),  INT8_C(  45), -INT8_C( 105), -INT8_C( 105),  INT8_C(  53), -INT8_C(  76), -INT8_C(  24), -INT8_C(  29),  INT8_C(  71), -INT8_C(   1),  INT8_C(  49),  INT8_C( 110), -INT8_C( 108)
                ,  INT8_C(  54),  INT8_C( 101),  INT8_C(  88), -INT8_C(   9), -INT8_C(  72),  INT8_C(  51),  INT8_C( 119),  INT8_C(  13),  INT8_C(  44),  INT8_C(  36), -INT8_C(  64),  INT8_C(  93), -INT8_C(  56),  INT8_C( 111),  INT8_C( 121), -INT8_C(  45)
                ,  INT8_C(  47), -INT8_C(  45), -INT8_C( 103), -INT8_C(  76),  INT8_C(  17),  INT8_C(  67), -INT8_C(  17),  INT8_C(  43), -INT8_C(  37),  INT8_C(  70),  INT8_C( 122),  INT8_C(  92),  INT8_C(  48), -INT8_C(  21),  INT8_C( 126),  INT8_C(  93)
                ,  INT8_C(  99), -INT8_C(  60), -INT8_C(   9),  INT8_C(  28),  INT8_C(  32), -INT8_C( 111), -INT8_C(  82),  INT8_C( 106), -INT8_C(   7),  INT8_C(  29),  INT8_C(  98),  INT8_C(  56),  INT8_C(  91),  INT8_C(  43), -INT8_C( 119), -INT8_C(  78)
                ,  INT8_C(  59),  INT8_C(  72), -INT8_C(  48),  INT8_C( 125), -INT8_C(  38),  INT8_C(  31), -INT8_C(  25),  INT8_C( 121), -INT8_C( 110), -INT8_C(  36), -INT8_C( 110), -INT8_C(  73),  INT8_C( 111), -INT8_C(  94),  INT8_C(  40), -INT8_C( 109)
                , -INT8_C(  53), -INT8_C(  54),  INT8_C(  99),  INT8_C(  11),  INT8_C(  11), -INT8_C(  59), -INT8_C( 112), -INT8_C( 122), -INT8_C( 110),  INT8_C(  84), -INT8_C(  85),  INT8_C(  89), -INT8_C(  87), -INT8_C(  80),  INT8_C(  29), -INT8_C(  41) },
      /* iu2 */ 1,
      /* r */ { INT32_C(     104490),  INT32_C(      52892),  INT32_C(      42703),  INT32_C(       7490)
                ,  INT32_C(      89403), -INT32_C(      28765),  INT32_C(      16640), -INT32_C(     211614)
                ,  INT32_C(      92618),  INT32_C(      43996), -INT32_C(      43166), -INT32_C(      38309)
                ,  INT32_C(      97864),  INT32_C(      17762),  INT32_C(     217060),  INT32_C(     179172)
                , -INT32_C(      39006), -INT32_C(     344491), -INT32_C(     111341),  INT32_C(      67215)
                , -INT32_C(      32205), -INT32_C(     120170), -INT32_C(     279869),  INT32_C(      60075)
                , -INT32_C(     102814),  INT32_C(      96029), -INT32_C(      33124),  INT32_C(     115233)
                , -INT32_C(      11208), -INT32_C(      43826),  INT32_C(     113977),  INT32_C(     125534)
                ,  INT32_C(      24831), -INT32_C(      72991),  INT32_C(      22360), -INT32_C(       5202)
                ,  INT32_C(      62194), -INT32_C(     124447), -INT32_C(      18040), -INT32_C(      86025)
                ,  INT32_C(      30144), -INT32_C(     103266), -INT32_C(      46951), -INT32_C(      22562)
                ,  INT32_C(      70137),  INT32_C(      10599),  INT32_C(     129673),  INT32_C(      53515)
                , -INT32_C(     116658), -INT32_C(      47564), -INT32_C(       1838),  INT32_C(      12054)
                , -INT32_C(      77564), -INT32_C(      73205), -INT32_C(     143907),  INT32_C(     140198)
                ,  INT32_C(      31989),  INT32_C(     147120), -INT32_C(       8703),  INT32_C(       9286)
                , -INT32_C(      20114), -INT32_C(      47669),  INT32_C(      34445),  INT32_C(     119613) } },
    {      /* uu */ {UINT8_C(215), UINT8_C(205), UINT8_C( 39), UINT8_C( 45), UINT8_C(151), UINT8_C(251), UINT8_C(103), UINT8_C(216), UINT8_C(217), UINT8_C(206), UINT8_C( 30), UINT8_C(141), UINT8_C( 91), UINT8_C( 62), UINT8_C(123), UINT8_C(238)
                , UINT8_C(110), UINT8_C(230), UINT8_C( 76), UINT8_C( 22), UINT8_C( 73), UINT8_C(141), UINT8_C(222), UINT8_C(162), UINT8_C(197), UINT8_C( 40), UINT8_C( 59), UINT8_C( 77), UINT8_C(197), UINT8_C(125), UINT8_C( 11), UINT8_C( 43)
                , UINT8_C(147), UINT8_C(203), UINT8_C( 85), UINT8_C(111), UINT8_C(241), UINT8_C(248), UINT8_C( 47), UINT8_C(133), UINT8_C(222), UINT8_C(206), UINT8_C( 94), UINT8_C( 58), UINT8_C(233), UINT8_C( 83), UINT8_C( 97), UINT8_C( 67)
                , UINT8_C( 64), UINT8_C(219), UINT8_C( 80), UINT8_C( 24), UINT8_C(119), UINT8_C(177), UINT8_C(200), UINT8_C(  6), UINT8_C(191), UINT8_C(178), UINT8_C(117), UINT8_C( 63), UINT8_C(230), UINT8_C(  7), UINT8_C( 85), UINT8_C(155)
                , UINT8_C(  5), UINT8_C( 85), UINT8_C( 58), UINT8_C(116), UINT8_C(198), UINT8_C(122), UINT8_C(  2), UINT8_C( 78), UINT8_C(179), UINT8_C(154), UINT8_C( 27), UINT8_C(123), UINT8_C(219), UINT8_C(254), UINT8_C(116), UINT8_C(199)
                , UINT8_C( 83), UINT8_C(198), UINT8_C(  4), UINT8_C( 96), UINT8_C( 84), UINT8_C( 23), UINT8_C( 14), UINT8_C(238), UINT8_C( 44), UINT8_C(223), UINT8_C(192), UINT8_C(232), UINT8_C( 30), UINT8_C(243), UINT8_C(206), UINT8_C(125)
                , UINT8_C(207), UINT8_C(189), UINT8_C(164), UINT8_C(120), UINT8_C( 67), UINT8_C(146), UINT8_C(104), UINT8_C( 63), UINT8_C(251), UINT8_C(144), UINT8_C(109), UINT8_C(103), UINT8_C(210), UINT8_C(  3), UINT8_C(240), UINT8_C( 44)
                , UINT8_C(129), UINT8_C( 63), UINT8_C( 76), UINT8_C(197), UINT8_C( 21), UINT8_C( 91), UINT8_C(226), UINT8_C(155), UINT8_C( 67), UINT8_C(233), UINT8_C(118), UINT8_C(103), UINT8_C( 67), UINT8_C(120), UINT8_C(120), UINT8_C(197)
                , UINT8_C( 19), UINT8_C(103), UINT8_C(116), UINT8_C( 61), UINT8_C( 44), UINT8_C(112), UINT8_C(248), UINT8_C(252), UINT8_C(142), UINT8_C(122), UINT8_C( 98), UINT8_C( 71), UINT8_C(101), UINT8_C(189), UINT8_C(189), UINT8_C( 37)
                , UINT8_C( 69), UINT8_C(233), UINT8_C(121), UINT8_C(170), UINT8_C(210), UINT8_C(199), UINT8_C( 21), UINT8_C(204), UINT8_C(223), UINT8_C(106), UINT8_C(171), UINT8_C( 49), UINT8_C(235), UINT8_C(210), UINT8_C( 42), UINT8_C(150)
                , UINT8_C( 38), UINT8_C( 74), UINT8_C(119), UINT8_C(161), UINT8_C(139), UINT8_C( 53), UINT8_C( 78), UINT8_C( 18), UINT8_C(202), UINT8_C(188), UINT8_C(140), UINT8_C( 30), UINT8_C( 67), UINT8_C(127), UINT8_C(182), UINT8_C(244)
                , UINT8_C(164), UINT8_C( 24), UINT8_C(184), UINT8_C( 62), UINT8_C( 98), UINT8_C( 80), UINT8_C( 32), UINT8_C(228), UINT8_C(241), UINT8_C( 75), UINT8_C( 58), UINT8_C( 26), UINT8_C(186), UINT8_C( 38), UINT8_C( 65), UINT8_C(248)
                , UINT8_C( 58), UINT8_C( 16), UINT8_C(215), UINT8_C(249), UINT8_C(208), UINT8_C(133), UINT8_C(181), UINT8_C(153), UINT8_C( 87), UINT8_C( 24), UINT8_C(147), UINT8_C( 10), UINT8_C( 62), UINT8_C(133), UINT8_C( 80), UINT8_C(230)
                , UINT8_C( 29), UINT8_C(202), UINT8_C(249), UINT8_C( 38), UINT8_C(182), UINT8_C(210), UINT8_C(120), UINT8_C( 32), UINT8_C(182), UINT8_C(216), UINT8_C(177), UINT8_C( 65), UINT8_C(149), UINT8_C(198), UINT8_C( 93), UINT8_C( 65)
                , UINT8_C( 80), UINT8_C( 34), UINT8_C( 71), UINT8_C(102), UINT8_C(253), UINT8_C(200), UINT8_C(183), UINT8_C(160), UINT8_C(238), UINT8_C(111), UINT8_C(200), UINT8_C(  0), UINT8_C( 77), UINT8_C( 38), UINT8_C(135), UINT8_C(183)
                , UINT8_C(151), UINT8_C(233), UINT8_C( 56), UINT8_C(194), UINT8_C(190), UINT8_C( 11), UINT8_C(112), UINT8_C(205), UINT8_C( 18), UINT8_C(180), UINT8_C( 93), UINT8_C(245), UINT8_C(186), UINT8_C( 44), UINT8_C( 88), UINT8_C(252) },
      /* vv */ { INT8_C(  30),  INT8_C(  85),  INT8_C(  29), -INT8_C( 113), -INT8_C(   7),  INT8_C( 117),  INT8_C(  59), -INT8_C(  34), -INT8_C(  73),  INT8_C(  89), -INT8_C(   4), -INT8_C( 110),  INT8_C(  21),  INT8_C(  41),  INT8_C(  71), -INT8_C(   6)
                , -INT8_C(  68), -INT8_C(  66),  INT8_C( 114),  INT8_C(  90),  INT8_C(  35),  INT8_C(  39), -INT8_C(  28),  INT8_C(  36), -INT8_C(  15),  INT8_C(  41),  INT8_C(  49), -INT8_C(  63),  INT8_C(  42), -INT8_C(  46), -INT8_C( 109),  INT8_C(  89)
                ,  INT8_C(  83), -INT8_C(   7), -INT8_C(  92),  INT8_C(  58),  INT8_C(  59), -INT8_C(  16), -INT8_C(  36), -INT8_C( 118), -INT8_C(  81), -INT8_C(  97),  INT8_C(  49),  INT8_C( 118),  INT8_C(   2), -INT8_C(  72), -INT8_C(  43),  INT8_C(  98)
                ,  INT8_C(  23),  INT8_C(  40),  INT8_C(  79),  INT8_C(  54), -INT8_C(  56),  INT8_C(  35), -INT8_C(  95), -INT8_C(   4), -INT8_C(  81), -INT8_C(  39),  INT8_C(  19), -INT8_C(  73),  INT8_C(   9), -INT8_C( 121), -INT8_C(  68), -INT8_C(  27)
                ,  INT8_C(  29),  INT8_C(   4), -INT8_C(  62), -INT8_C(  39), -INT8_C(  61), -INT8_C( 107),  INT8_C( 121),  INT8_C( 124), -INT8_C(   4),  INT8_C( 119),  INT8_C(   6), -INT8_C( 106),  INT8_C(  13),  INT8_C(  19), -INT8_C( 120),  INT8_C(  20)
                ,  INT8_C( 127),  INT8_C(  11), -INT8_C(  60), -INT8_C( 113),  INT8_C(  92), -INT8_C(  70),  INT8_C( 124), -INT8_C( 100), -INT8_C(  21),  INT8_C( 120),  INT8_C(  72), -INT8_C(   4),  INT8_C(  53), -INT8_C( 112),  INT8_C(  54),  INT8_C( 116)
                ,  INT8_C(  41), -INT8_C(  60),  INT8_C(  85), -INT8_C( 127),  INT8_C(  84),  INT8_C(  99),  INT8_C(  61), -INT8_C(  60), -INT8_C(  10), -INT8_C(   9),  INT8_C( 126),  INT8_C(  63), -INT8_C(   8), -INT8_C(  45), -INT8_C(  96), -INT8_C( 114)
                ,  INT8_C(  30),  INT8_C(  92),  INT8_C( 113),  INT8_C( 107), -INT8_C(  53),  INT8_C(  35), -INT8_C( 114), -INT8_C(  61),  INT8_C( 125), -INT8_C(  95), -INT8_C(  37), -INT8_C(   2), -INT8_C(   3), -INT8_C(  10),  INT8_C(  91),  INT8_C(   1)
                ,  INT8_C(  99), -INT8_C( 110),  INT8_C(  16),  INT8_C( 123),  INT8_C(  81),  INT8_C(  22), -INT8_C( 103), -INT8_C(  96), -INT8_C(  56), -INT8_C(  61),  INT8_C( 120), -INT8_C(  32), -INT8_C(  46), -INT8_C( 114),  INT8_C(  56), -INT8_C(  74)
                , -INT8_C(  43), -INT8_C( 109),  INT8_C(   6),  INT8_C(   3), -INT8_C(  87), -INT8_C(  26),  INT8_C(   6), -INT8_C( 104), -INT8_C( 118),  INT8_C(  36), -INT8_C(   6), -INT8_C( 127),  INT8_C(  37), -INT8_C(  24),  INT8_C(   3), -INT8_C( 125)
                ,  INT8_C( 110),  INT8_C( 101), -INT8_C(  84), -INT8_C(  92),  INT8_C( 116), -INT8_C(  82), -INT8_C(   1), -INT8_C(  21),  INT8_C( 111), -INT8_C(  44), -INT8_C(  52),  INT8_C(  39),  INT8_C(  42),  INT8_C(   8),  INT8_C(  68),  INT8_C(  70)
                , -INT8_C(  64),  INT8_C(  49),  INT8_C( 108),  INT8_C( 106), -INT8_C(  78), -INT8_C(  41), -INT8_C(  63),  INT8_C(  53), -INT8_C(  27),  INT8_C(   2), -INT8_C( 116),  INT8_C( 104),  INT8_C(  55),  INT8_C(  33),  INT8_C(  15),  INT8_C(  75)
                ,  INT8_C(  21),  INT8_C( 102), -INT8_C(  18),  INT8_C( 115),  INT8_C( 114), -INT8_C( 118), -INT8_C(  64),  INT8_C(   1),  INT8_C(  30), -INT8_C(  45), -INT8_C(  69),  INT8_C( 109),  INT8_C(  99),  INT8_C(  37),  INT8_C( 112), -INT8_C(  58)
                ,  INT8_C(  68),  INT8_C( 115), -INT8_C(  40), -INT8_C(  16),  INT8_C(   4),  INT8_C(   6),  INT8_C(  95),  INT8_C(  51),  INT8_C(  14),  INT8_C(  88), -INT8_C(  70), -INT8_C(  96),  INT8_C(  33), -INT8_C(  59), -INT8_C(  29), -INT8_C( 111)
                , -INT8_C(  23),  INT8_C(  43),  INT8_C(  52),  INT8_C(   8), -INT8_C(   8), -INT8_C(  29),  INT8_C(  24),  INT8_C(  84), -INT8_C(  41), -INT8_C(  19),  INT8_C( 111), -INT8_C( 121), -INT8_C(  46), -INT8_C( 113), -INT8_C(  52), -INT8_C(  18)
                ,  INT8_C(  61), -INT8_C(  67), -INT8_C(  21),  INT8_C(  22), -INT8_C(  46), -INT8_C(  84),  INT8_C( 114), -INT8_C(  28), -INT8_C(  46),  INT8_C(   7), -INT8_C( 103), -INT8_C(  77),  INT8_C(  51), -INT8_C(  55), -INT8_C( 127),  INT8_C(  73) },
      /* iu2 */ 2,
      /* r */ {-INT32_C(     113345),  INT32_C(       1957),  INT32_C(      27906), -INT32_C(      23006)
                ,  INT32_C(      29494),  INT32_C(      27595),  INT32_C(     134808), -INT32_C(      13438)
                ,  INT32_C(      75721), -INT32_C(     153287),  INT32_C(       2002), -INT32_C(      83042)
                , -INT32_C(     188133),  INT32_C(     128839), -INT32_C(     136693), -INT32_C(      46793)
                ,  INT32_C(       6451),  INT32_C(     130032),  INT32_C(      15989), -INT32_C(       9081)
                ,  INT32_C(      27254), -INT32_C(      50332), -INT32_C(      39092),  INT32_C(     128508)
                , -INT32_C(      36250),  INT32_C(     157974),  INT32_C(      87119), -INT32_C(      87475)
                ,  INT32_C(      43997), -INT32_C(      32262), -INT32_C(       3305),  INT32_C(       7243)
                , -INT32_C(     133527), -INT32_C(     136679),  INT32_C(      14156), -INT32_C(      72790)
                , -INT32_C(      83478), -INT32_C(      18154),  INT32_C(     179244),  INT32_C(     123354)
                , -INT32_C(     111431), -INT32_C(     217629), -INT32_C(      60744), -INT32_C(     139117)
                , -INT32_C(     106548),  INT32_C(      62983), -INT32_C(      15307), -INT32_C(      86932)
                , -INT32_C(      21323),  INT32_C(      43732), -INT32_C(      11584),  INT32_C(     116360)
                , -INT32_C(      52181),  INT32_C(      53858), -INT32_C(      88074),  INT32_C(     197770)
                ,  INT32_C(      90947),  INT32_C(     180352),  INT32_C(      33764), -INT32_C(     162287)
                , -INT32_C(      34978),  INT32_C(      98276), -INT32_C(      63016),  INT32_C(      67474) } },
    {      /* uu */ {UINT8_C(  0), UINT8_C( 50), UINT8_C( 26), UINT8_C( 91), UINT8_C( 10), UINT8_C(182), UINT8_C( 65), UINT8_C(244), UINT8_C(231), UINT8_C(143), UINT8_C( 16), UINT8_C( 68), UINT8_C(140), UINT8_C(139), UINT8_C( 58), UINT8_C(161)
                , UINT8_C( 79), UINT8_C( 53), UINT8_C(234), UINT8_C(228), UINT8_C(168), UINT8_C(  2), UINT8_C(124), UINT8_C(106), UINT8_C(  8), UINT8_C( 46), UINT8_C(114), UINT8_C(199), UINT8_C(161), UINT8_C( 16), UINT8_C(173), UINT8_C(117)
                , UINT8_C(196), UINT8_C(224), UINT8_C(155), UINT8_C( 51), UINT8_C(173), UINT8_C(198), UINT8_C( 63), UINT8_C(124), UINT8_C(212), UINT8_C( 15), UINT8_C( 51), UINT8_C( 40), UINT8_C( 61), UINT8_C( 18), UINT8_C(176), UINT8_C( 55)
                , UINT8_C(230), UINT8_C( 96), UINT8_C( 26), UINT8_C(236), UINT8_C( 60), UINT8_C( 93), UINT8_C(127), UINT8_C(186), UINT8_C( 61), UINT8_C(236), UINT8_C(222), UINT8_C(248), UINT8_C(244), UINT8_C( 18), UINT8_C( 20), UINT8_C(137)
                , UINT8_C(132), UINT8_C(150), UINT8_C(169), UINT8_C(226), UINT8_C( 51), UINT8_C( 68), UINT8_C( 25), UINT8_C(169), UINT8_C(237), UINT8_C(113), UINT8_C(107), UINT8_C(185), UINT8_C(193), UINT8_C(171), UINT8_C(  0), UINT8_C( 59)
                , UINT8_C( 66), UINT8_C( 44), UINT8_C(232), UINT8_C(225), UINT8_C(211), UINT8_C( 39), UINT8_C(146), UINT8_C(254), UINT8_C(198), UINT8_C( 48), UINT8_C(204), UINT8_C( 84), UINT8_C( 53), UINT8_C( 44), UINT8_C(184), UINT8_C( 63)
                , UINT8_C(  6), UINT8_C( 66), UINT8_C(234), UINT8_C(200), UINT8_C( 71), UINT8_C(153), UINT8_C(135), UINT8_C(174), UINT8_C( 28), UINT8_C(163), UINT8_C(244), UINT8_C( 34), UINT8_C(121), UINT8_C(144), UINT8_C(109), UINT8_C(111)
                , UINT8_C(217), UINT8_C( 92), UINT8_C(  1), UINT8_C(167), UINT8_C( 30), UINT8_C( 38), UINT8_C(129), UINT8_C(218), UINT8_C(137), UINT8_C(  5), UINT8_C(116), UINT8_C( 52), UINT8_C(135), UINT8_C(190), UINT8_C(244), UINT8_C(122)
                , UINT8_C(226), UINT8_C(177), UINT8_C(149), UINT8_C(165), UINT8_C(116), UINT8_C(204), UINT8_C(191), UINT8_C( 11), UINT8_C( 10), UINT8_C( 19), UINT8_C(133), UINT8_C( 68), UINT8_C(125), UINT8_C( 77), UINT8_C(137), UINT8_C(157)
                , UINT8_C(234), UINT8_C( 93), UINT8_C( 70), UINT8_C(  7), UINT8_C(133), UINT8_C( 31), UINT8_C( 23), UINT8_C( 80), UINT8_C(154), UINT8_C(147), UINT8_C( 74), UINT8_C(169), UINT8_C(241), UINT8_C(120), UINT8_C(208), UINT8_C( 11)
                , UINT8_C(220), UINT8_C(132), UINT8_C(182), UINT8_C(151), UINT8_C(172), UINT8_C(135), UINT8_C(127), UINT8_C(191), UINT8_C( 96), UINT8_C(184), UINT8_C(154), UINT8_C(203), UINT8_C( 60), UINT8_C( 48), UINT8_C(167), UINT8_C(101)
                , UINT8_C( 59), UINT8_C(229), UINT8_C( 81), UINT8_C(220), UINT8_C(  9), UINT8_C(223), UINT8_C(240), UINT8_C(185), UINT8_C(235), UINT8_C( 11), UINT8_C(220), UINT8_C( 86), UINT8_C(189), UINT8_C( 42), UINT8_C(249), UINT8_C( 33)
                , UINT8_C(103), UINT8_C( 84), UINT8_C(128), UINT8_C(211), UINT8_C(253), UINT8_C( 75), UINT8_C( 35), UINT8_C( 76), UINT8_C(125), UINT8_C( 58), UINT8_C(132), UINT8_C(216), UINT8_C(249), UINT8_C(156), UINT8_C(193), UINT8_C( 31)
                , UINT8_C(169), UINT8_C(  0), UINT8_C(213), UINT8_C( 26), UINT8_C(207), UINT8_C(242), UINT8_C(141), UINT8_C(126), UINT8_C( 42), UINT8_C( 99), UINT8_C( 76), UINT8_C( 83), UINT8_C(193), UINT8_C( 89), UINT8_C( 84), UINT8_C(227)
                , UINT8_C( 82), UINT8_C( 85), UINT8_C( 88), UINT8_C( 33), UINT8_C( 98), UINT8_C(113), UINT8_C(208), UINT8_C(145), UINT8_C(171), UINT8_C(119), UINT8_C(  2), UINT8_C( 69), UINT8_C( 40), UINT8_C(113), UINT8_C(117), UINT8_C(214)
                , UINT8_C(207), UINT8_C( 57), UINT8_C(216), UINT8_C( 76), UINT8_C( 79), UINT8_C( 41), UINT8_C(182), UINT8_C(103), UINT8_C(  3), UINT8_C(137), UINT8_C( 92), UINT8_C( 36), UINT8_C(139), UINT8_C( 72), UINT8_C( 74), UINT8_C( 16) },
      /* vv */ {-INT8_C(  99), -INT8_C( 101), -INT8_C(  69),  INT8_C(  43), -INT8_C(   9),  INT8_C(  69), -INT8_C(  35), -INT8_C(  55),  INT8_C(   4), -INT8_C(  20), -INT8_C(  74), -INT8_C(  30), -INT8_C(  75), -INT8_C(  61),  INT8_C(  24), -INT8_C(  97)
                ,  INT8_C(  19),  INT8_C( 112),  INT8_C( 116), -INT8_C(  52),  INT8_C( 114), -INT8_C(  47), -INT8_C(  22),  INT8_C(  35),  INT8_C(   8), -INT8_C(  43),  INT8_C(  17), -INT8_C(  16),  INT8_C(   6),  INT8_C( 121),  INT8_C(  70),  INT8_C(  35)
                ,  INT8_C(  64), -INT8_C( 103), -INT8_C( 104),  INT8_C(  20), -INT8_C(   1),  INT8_C(   4),  INT8_C(  75),  INT8_C(  24), -INT8_C(  18), -INT8_C(  12),  INT8_C(  94),  INT8_C( 126),  INT8_C(  52),  INT8_C(  55),  INT8_C(  64), -INT8_C(  45)
                , -INT8_C(  89),  INT8_C(  29), -INT8_C(  23),  INT8_C(  88), -INT8_C(  37), -INT8_C( 101),  INT8_C(  22),  INT8_C(  91),  INT8_C(  83), -INT8_C(   5), -INT8_C(  79),  INT8_C(  11), -INT8_C(  92), -INT8_C(  84),  INT8_C( 122),  INT8_C( 110)
                , -INT8_C( 128),  INT8_C(  76), -INT8_C(  25),  INT8_C( 126),  INT8_C(  89), -INT8_C(  19), -INT8_C(  91), -INT8_C(  77), -INT8_C(  73),  INT8_C(  14),  INT8_C(  30),  INT8_C( 110), -INT8_C( 120), -INT8_C(  23), -INT8_C(  13), -INT8_C(  63)
                ,  INT8_C(  63), -INT8_C( 111), -INT8_C(  95), -INT8_C(  71),  INT8_C(  29),  INT8_C( 124),  INT8_C(  18),  INT8_C( 126),  INT8_C( 108), -INT8_C( 108), -INT8_C(  53),  INT8_C(  98), -INT8_C(  85), -INT8_C(  84), -INT8_C( 122), -INT8_C( 123)
                , -INT8_C(  15),  INT8_C( 116),  INT8_C(  36), -INT8_C(  87),  INT8_C(  94), -INT8_C( 117), -INT8_C(  94), -INT8_C(  15), -INT8_C( 125),  INT8_C(  84),  INT8_C(   6),  INT8_C(  72), -INT8_C(  42),  INT8_C(  41),  INT8_C(  26), -INT8_C(  83)
                , -INT8_C( 106), -INT8_C(  86),  INT8_C(   5), -INT8_C(  45), -INT8_C(   8), -INT8_C(  19), -INT8_C( 127),  INT8_C(  69),  INT8_C(  40), -INT8_C(  20),  INT8_C(  68), -INT8_C(  60), -INT8_C(  24), -INT8_C(  73), -INT8_C( 111), -INT8_C(  84)
                , -INT8_C(  39), -INT8_C(   6), -INT8_C(  47),  INT8_C( 125),  INT8_C(  74), -INT8_C(  74), -INT8_C(  51), -INT8_C( 114), -INT8_C(  60), -INT8_C(  33),  INT8_C(  33),  INT8_C(   9),  INT8_C(  23), -INT8_C( 104), -INT8_C(  37), -INT8_C( 117)
                ,  INT8_C( 108),  INT8_C(  67),  INT8_C(   8), -INT8_C( 121),  INT8_C(  73), -INT8_C(  10), -INT8_C( 124),  INT8_C( 116),  INT8_C( 120), -INT8_C(  89),  INT8_C(  45),  INT8_C(  57),  INT8_C(  64),  INT8_C( 110), -INT8_C(  15),  INT8_C( 116)
                , -INT8_C(  24),  INT8_C(   6), -INT8_C(   5), -INT8_C(  55), -INT8_C(  91), -INT8_C(  88),  INT8_C(  81), -INT8_C( 125),  INT8_C(  49), -INT8_C( 101), -INT8_C( 121), -INT8_C(  54), -INT8_C(   8),  INT8_C( 114),  INT8_C(  96), -INT8_C(  29)
                , -INT8_C(  13), -INT8_C(  24), -INT8_C(  79),  INT8_C( 115), -INT8_C(  24), -INT8_C(  83), -INT8_C(  39),  INT8_C(  20),  INT8_C(   1),  INT8_C(  61),  INT8_C( 101),  INT8_C( 124), -INT8_C(  76), -INT8_C(  19),  INT8_C( 103), -INT8_C(  50)
                , -INT8_C(  50),  INT8_C(  76), -INT8_C(  32),  INT8_C( 122), -INT8_C(  50),  INT8_C(  13),  INT8_C(  62), -INT8_C(  25),  INT8_C(   9), -INT8_C(   5), -INT8_C(  73), -INT8_C(  84),  INT8_C(  59), -INT8_C(  37),  INT8_C(  19),  INT8_C(  19)
                , -INT8_C(  85), -INT8_C(   2),  INT8_C(  46),  INT8_C(  69), -INT8_C(  36), -INT8_C(  98),  INT8_C( 110), -INT8_C(  42), -INT8_C(  13),  INT8_C(  21),  INT8_C( 111), -INT8_C(   7), -INT8_C(  52),  INT8_C(  69), -INT8_C( 125), -INT8_C(  32)
                , -INT8_C(  36), -INT8_C(  29), -INT8_C(  81),  INT8_C(  99),  INT8_C(   9),  INT8_C(  26), -INT8_C(  14), -INT8_C(  37),  INT8_C(  86),  INT8_C( 127), -INT8_C(  84), -INT8_C(  62),  INT8_C(   4),  INT8_C(  54), -INT8_C( 125),  INT8_C(  66)
                , -INT8_C( 113),  INT8_C(  86),  INT8_C(  66), -INT8_C(  68),  INT8_C(  32),  INT8_C(  34), -INT8_C(  51), -INT8_C(  28), -INT8_C( 103),  INT8_C(   8), -INT8_C(  56), -INT8_C(  68),  INT8_C(  57),  INT8_C(  72),  INT8_C(   6),  INT8_C(  30) },
      /* iu2 */ 3,
      /* r */ {-INT32_C(      86551), -INT32_C(      57331), -INT32_C(      94931), -INT32_C(      25450)
                ,  INT32_C(      60585), -INT32_C(       1000), -INT32_C(      68349), -INT32_C(      94062)
                ,  INT32_C(     289436),  INT32_C(      25849), -INT32_C(      90923), -INT32_C(      56864)
                ,  INT32_C(      68908),  INT32_C(     189859), -INT32_C(     112792), -INT32_C(     143730)
                , -INT32_C(     234609),  INT32_C(      13037), -INT32_C(     208959),  INT32_C(     242002)
                ,  INT32_C(     212463), -INT32_C(      42197), -INT32_C(      36334),  INT32_C(      77204)
                , -INT32_C(      54866),  INT32_C(      22580), -INT32_C(     164352), -INT32_C(      27581)
                , -INT32_C(      22622),  INT32_C(      55519),  INT32_C(       7844), -INT32_C(     147643)
                , -INT32_C(      83486), -INT32_C(      33186), -INT32_C(      35970),  INT32_C(      24189)
                , -INT32_C(      20266), -INT32_C(       1848),  INT32_C(      25613), -INT32_C(     121029)
                ,  INT32_C(     105035), -INT32_C(       4890), -INT32_C(      39402),  INT32_C(      20561)
                , -INT32_C(      70037), -INT32_C(       4381), -INT32_C(      64194), -INT32_C(     115578)
                , -INT32_C(     108776),  INT32_C(      32693), -INT32_C(     143597),  INT32_C(      60646)
                , -INT32_C(      28802), -INT32_C(     137604), -INT32_C(      93468),  INT32_C(     116788)
                , -INT32_C(       4790),  INT32_C(      51884),  INT32_C(      17424), -INT32_C(      29497)
                ,  INT32_C(      84660),  INT32_C(     195968),  INT32_C(      36480),  INT32_C(      20544) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t uu = simde_test_hvx_fixture_pair_load(test_vec[i].uu, chunk);
      simde_hvx_vectorpair_t vv = simde_test_hvx_fixture_pair_load(test_vec[i].vv, chunk);
      simde_hvx_vectorpair_t expected = simde_test_hvx_fixture_pair_load(test_vec[i].r, chunk);
      simde_hvx_vectorpair_t rr;
      int32_t r_arr[SIMDE_HVX_VECTOR_I32_COUNT * 2];
      int32_t expected_arr[SIMDE_HVX_VECTOR_I32_COUNT * 2];
      SIMDE_CONSTIFY_4_(simde_Q6_Ww_v6mpy_WubWbI_v, rr, (HEDLEY_UNREACHABLE(), rr), test_vec[i].iu2, uu, vv);
      simde_memcpy(r_arr, &rr, sizeof(r_arr));
      simde_memcpy(expected_arr, &expected, sizeof(expected_arr));
      for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT * 2 ; j++) {
        simde_assert_equal_i32(r_arr[j], expected_arr[j]);
      }
    }
  }

  return 0;
}

static int
test_simde_v6mpyacc_lane_selection(SIMDE_MUNIT_TEST_ARGS) {
  uint8_t u[SIMDE_HVX_PAIR_SIZE] = { 0 };
  uint32_t v[SIMDE_HVX_VECTOR_I32_COUNT * 2] = { 0 };
  int32_t x[SIMDE_HVX_VECTOR_I32_COUNT * 2];
  simde_hvx_vectorpair_t uu, vv, xx, r;

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
    u[4 * i + 0] = 1;
    u[4 * i + 1] = 2;
    u[4 * i + 2] = 3;
    u[4 * i + 3] = 4;
    u[SIMDE_HVX_VECTOR_SIZE + 4 * i + 0] = 5;
    u[SIMDE_HVX_VECTOR_SIZE + 4 * i + 1] = 6;
    u[SIMDE_HVX_VECTOR_SIZE + 4 * i + 2] = 7;
    u[SIMDE_HVX_VECTOR_SIZE + 4 * i + 3] = 8;
    v[i] = UINT32_C(0x00030201);
    v[SIMDE_HVX_VECTOR_I32_COUNT + i] = UINT32_C(0x3ffdfeff);
  }
  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT * 2 ; i++) x[i] = 1000;
  simde_memcpy(&uu, u, sizeof(uu));
  simde_memcpy(&vv, v, sizeof(vv));
  simde_memcpy(&xx, x, sizeof(xx));

  r = simde_Q6_Ww_v6mpyacc_WwWubWbI_v(xx, uu, vv, 2);
  simde_memcpy(x, &r, sizeof(x));
  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
    simde_assert_equal_i32(x[i], 980);
    simde_assert_equal_i32(x[SIMDE_HVX_VECTOR_I32_COUNT + i], 988);
  }

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT * 2 ; i++) x[i] = 1000;
  simde_memcpy(&xx, x, sizeof(xx));
  r = simde_Q6_Ww_v6mpyacc_WwWubWbI_h(xx, uu, vv, 3);
  simde_memcpy(x, &r, sizeof(x));
  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
    simde_assert_equal_i32(x[i], 994);
    simde_assert_equal_i32(x[SIMDE_HVX_VECTOR_I32_COUNT + i], 1020);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(v6mpy_WubWbI_h)
SIMDE_TEST_FUNC_LIST_ENTRY(v6mpy_WubWbI_v)
SIMDE_TEST_FUNC_LIST_ENTRY(v6mpyacc_lane_selection)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
