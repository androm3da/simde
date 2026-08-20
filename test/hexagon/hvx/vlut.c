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

#define SIMDE_TEST_HEXAGON_HVX_INSN vlut

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vlut.h"

#if SIMDE_HVX_VECTOR_SIZE == 64
static simde_hvx_vector_t
simde_test_hvx_vlut32_expected(simde_hvx_vector_t vx, simde_hvx_vector_t idx,
                               simde_hvx_vector_t tbl, int32_t rt, int nomatch, int accumulate) {
  simde_hvx_vector_private
    r_ = simde_hvx_vector_to_private(vx),
    idx_ = simde_hvx_vector_to_private(idx),
    tbl_ = simde_hvx_vector_to_private(tbl);
  const uint8_t match = HEDLEY_STATIC_CAST(uint8_t, rt & 7);
  const uint8_t odd = HEDLEY_STATIC_CAST(uint8_t, rt & 1);

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_SIZE ; i++) {
    const uint8_t index = idx_.u8[i];
    const uint8_t value = tbl_.u8[((index & 31) * 2) + odd];
    if (nomatch || ((index & 0xe0) == HEDLEY_STATIC_CAST(uint8_t, match << 5)))
      r_.u8[i] = accumulate ? HEDLEY_STATIC_CAST(uint8_t, r_.u8[i] | value) : value;
    else if (!accumulate)
      r_.u8[i] = 0;
  }
  return simde_hvx_vector_from_private(r_);
}

static simde_hvx_vectorpair_t
simde_test_hvx_vlut16_expected(simde_hvx_vectorpair_t vxx, simde_hvx_vector_t idx,
                               simde_hvx_vector_t tbl, int32_t rt, int nomatch, int accumulate) {
  simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(vxx);
  simde_hvx_vector_private
    idx_ = simde_hvx_vector_to_private(idx),
    tbl_ = simde_hvx_vector_to_private(tbl);
  const uint8_t match = HEDLEY_STATIC_CAST(uint8_t, rt & 15);
  const uint8_t odd = HEDLEY_STATIC_CAST(uint8_t, rt & 1);

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
    const uint8_t index0 = idx_.u8[2 * i];
    const uint8_t index1 = idx_.u8[2 * i + 1];
    const int16_t value0 = tbl_.i16[((index0 & 15) * 2) + odd];
    const int16_t value1 = tbl_.i16[((index1 & 15) * 2) + odd];
    if (nomatch || ((index0 & 0xf0) == HEDLEY_STATIC_CAST(uint8_t, match << 4)))
      r_.i16[i] = accumulate ? HEDLEY_STATIC_CAST(int16_t, r_.i16[i] | value0) : value0;
    else if (!accumulate)
      r_.i16[i] = 0;
    if (nomatch || ((index1 & 0xf0) == HEDLEY_STATIC_CAST(uint8_t, match << 4)))
      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = accumulate
        ? HEDLEY_STATIC_CAST(int16_t, r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] | value1) : value1;
    else if (!accumulate)
      r_.i16[SIMDE_HVX_VECTOR_I16_COUNT + i] = 0;
  }
  return simde_hvx_vectorpair_from_private(r_);
}
#endif

#if SIMDE_HVX_VECTOR_SIZE == 64
  #define SIMDE_TEST_HVX_VLUT32_EXPECTED(static_r, vx, idx, tbl, rt, nomatch, accumulate) \
    simde_test_hvx_vlut32_expected(vx, idx, tbl, rt, nomatch, accumulate)
  #define SIMDE_TEST_HVX_VLUT16_EXPECTED(static_r, vxx, idx, tbl, rt, nomatch, accumulate, part) \
    ((part) ? simde_Q6_V_hi_W : simde_Q6_V_lo_W)(simde_test_hvx_vlut16_expected(vxx, idx, tbl, rt, nomatch, accumulate))
#else
  #define SIMDE_TEST_HVX_VLUT32_EXPECTED(static_r, vx, idx, tbl, rt, nomatch, accumulate) \
    simde_test_hvx_vector_load(static_r)
  #define SIMDE_TEST_HVX_VLUT16_EXPECTED(static_r, vxx, idx, tbl, rt, nomatch, accumulate, part) \
    simde_test_hvx_vector_load(static_r)
#endif

/* Shared input: index vector (128 bytes) */
#define TEST_IDX \
         UINT8_C(3),   UINT8_C(10),   UINT8_C(17),   UINT8_C(24),   UINT8_C(31),   UINT8_C(38),   UINT8_C(45),   UINT8_C(52), \
        UINT8_C(59),   UINT8_C(66),   UINT8_C(73),   UINT8_C(80),   UINT8_C(87),   UINT8_C(94),  UINT8_C(101),  UINT8_C(108), \
       UINT8_C(115),  UINT8_C(122),  UINT8_C(129),  UINT8_C(136),  UINT8_C(143),  UINT8_C(150),  UINT8_C(157),  UINT8_C(164), \
       UINT8_C(171),  UINT8_C(178),  UINT8_C(185),  UINT8_C(192),  UINT8_C(199),  UINT8_C(206),  UINT8_C(213),  UINT8_C(220), \
       UINT8_C(227),  UINT8_C(234),  UINT8_C(241),  UINT8_C(248),  UINT8_C(255),    UINT8_C(6),   UINT8_C(13),   UINT8_C(20), \
        UINT8_C(27),   UINT8_C(34),   UINT8_C(41),   UINT8_C(48),   UINT8_C(55),   UINT8_C(62),   UINT8_C(69),   UINT8_C(76), \
        UINT8_C(83),   UINT8_C(90),   UINT8_C(97),  UINT8_C(104),  UINT8_C(111),  UINT8_C(118),  UINT8_C(125),  UINT8_C(132), \
       UINT8_C(139),  UINT8_C(146),  UINT8_C(153),  UINT8_C(160),  UINT8_C(167),  UINT8_C(174),  UINT8_C(181),  UINT8_C(188), \
       UINT8_C(195),  UINT8_C(202),  UINT8_C(209),  UINT8_C(216),  UINT8_C(223),  UINT8_C(230),  UINT8_C(237),  UINT8_C(244), \
       UINT8_C(251),    UINT8_C(2),    UINT8_C(9),   UINT8_C(16),   UINT8_C(23),   UINT8_C(30),   UINT8_C(37),   UINT8_C(44), \
        UINT8_C(51),   UINT8_C(58),   UINT8_C(65),   UINT8_C(72),   UINT8_C(79),   UINT8_C(86),   UINT8_C(93),  UINT8_C(100), \
       UINT8_C(107),  UINT8_C(114),  UINT8_C(121),  UINT8_C(128),  UINT8_C(135),  UINT8_C(142),  UINT8_C(149),  UINT8_C(156), \
       UINT8_C(163),  UINT8_C(170),  UINT8_C(177),  UINT8_C(184),  UINT8_C(191),  UINT8_C(198),  UINT8_C(205),  UINT8_C(212), \
       UINT8_C(219),  UINT8_C(226),  UINT8_C(233),  UINT8_C(240),  UINT8_C(247),  UINT8_C(254),    UINT8_C(5),   UINT8_C(12), \
        UINT8_C(19),   UINT8_C(26),   UINT8_C(33),   UINT8_C(40),   UINT8_C(47),   UINT8_C(54),   UINT8_C(61),   UINT8_C(68), \
        UINT8_C(75),   UINT8_C(82),   UINT8_C(89),   UINT8_C(96),  UINT8_C(103),  UINT8_C(110),  UINT8_C(117),  UINT8_C(124)

/* Shared input: 32-entry byte table for vlut32 family (128 bytes) */
#define TEST_TBL32 \
        UINT8_C(11),   UINT8_C(24),   UINT8_C(37),   UINT8_C(50),   UINT8_C(63),   UINT8_C(76),   UINT8_C(89),  UINT8_C(102), \
       UINT8_C(115),  UINT8_C(128),  UINT8_C(141),  UINT8_C(154),  UINT8_C(167),  UINT8_C(180),  UINT8_C(193),  UINT8_C(206), \
       UINT8_C(219),  UINT8_C(232),  UINT8_C(245),    UINT8_C(2),   UINT8_C(15),   UINT8_C(28),   UINT8_C(41),   UINT8_C(54), \
        UINT8_C(67),   UINT8_C(80),   UINT8_C(93),  UINT8_C(106),  UINT8_C(119),  UINT8_C(132),  UINT8_C(145),  UINT8_C(158), \
       UINT8_C(171),  UINT8_C(184),  UINT8_C(197),  UINT8_C(210),  UINT8_C(223),  UINT8_C(236),  UINT8_C(249),    UINT8_C(6), \
        UINT8_C(19),   UINT8_C(32),   UINT8_C(45),   UINT8_C(58),   UINT8_C(71),   UINT8_C(84),   UINT8_C(97),  UINT8_C(110), \
       UINT8_C(123),  UINT8_C(136),  UINT8_C(149),  UINT8_C(162),  UINT8_C(175),  UINT8_C(188),  UINT8_C(201),  UINT8_C(214), \
       UINT8_C(227),  UINT8_C(240),  UINT8_C(253),   UINT8_C(10),   UINT8_C(23),   UINT8_C(36),   UINT8_C(49),   UINT8_C(62), \
        UINT8_C(75),   UINT8_C(88),  UINT8_C(101),  UINT8_C(114),  UINT8_C(127),  UINT8_C(140),  UINT8_C(153),  UINT8_C(166), \
       UINT8_C(179),  UINT8_C(192),  UINT8_C(205),  UINT8_C(218),  UINT8_C(231),  UINT8_C(244),    UINT8_C(1),   UINT8_C(14), \
        UINT8_C(27),   UINT8_C(40),   UINT8_C(53),   UINT8_C(66),   UINT8_C(79),   UINT8_C(92),  UINT8_C(105),  UINT8_C(118), \
       UINT8_C(131),  UINT8_C(144),  UINT8_C(157),  UINT8_C(170),  UINT8_C(183),  UINT8_C(196),  UINT8_C(209),  UINT8_C(222), \
       UINT8_C(235),  UINT8_C(248),    UINT8_C(5),   UINT8_C(18),   UINT8_C(31),   UINT8_C(44),   UINT8_C(57),   UINT8_C(70), \
        UINT8_C(83),   UINT8_C(96),  UINT8_C(109),  UINT8_C(122),  UINT8_C(135),  UINT8_C(148),  UINT8_C(161),  UINT8_C(174), \
       UINT8_C(187),  UINT8_C(200),  UINT8_C(213),  UINT8_C(226),  UINT8_C(239),  UINT8_C(252),    UINT8_C(9),   UINT8_C(22), \
        UINT8_C(35),   UINT8_C(48),   UINT8_C(61),   UINT8_C(74),   UINT8_C(87),  UINT8_C(100),  UINT8_C(113),  UINT8_C(126)

/* Shared input: accumulator for vlut32or (128 bytes) */
#define TEST_VX \
       UINT8_C(200),    UINT8_C(5),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40), \
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220), \
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6), \
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9), \
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38), \
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210), \
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63), \
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62), \
       UINT8_C(205),    UINT8_C(8),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40), \
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220), \
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6), \
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9), \
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38), \
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210), \
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63), \
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62)

/* Shared input: 16-entry halfword table for vlut16 family, as raw bytes (128 bytes) */
#define TEST_TBL16 \
       UINT8_C(208),  UINT8_C(138),  UINT8_C(136),   UINT8_C(19),   UINT8_C(46),  UINT8_C(251),   UINT8_C(61),   UINT8_C(34), \
       UINT8_C(100),    UINT8_C(0),  UINT8_C(156),  UINT8_C(255),    UINT8_C(0),  UINT8_C(125),    UINT8_C(0),  UINT8_C(131), \
       UINT8_C(225),   UINT8_C(16),  UINT8_C(108),  UINT8_C(217),  UINT8_C(152),   UINT8_C(58),  UINT8_C(104),  UINT8_C(197), \
         UINT8_C(9),    UINT8_C(3),  UINT8_C(247),  UINT8_C(252),  UINT8_C(174),    UINT8_C(8),   UINT8_C(82),  UINT8_C(247), \
        UINT8_C(17),   UINT8_C(39),  UINT8_C(239),  UINT8_C(216),   UINT8_C(32),   UINT8_C(78),  UINT8_C(224),  UINT8_C(177), \
        UINT8_C(43),    UINT8_C(2),  UINT8_C(213),  UINT8_C(253),  UINT8_C(133),   UINT8_C(26),  UINT8_C(123),  UINT8_C(229), \
        UINT8_C(15),   UINT8_C(39),  UINT8_C(241),  UINT8_C(216),   UINT8_C(87),    UINT8_C(4),  UINT8_C(169),  UINT8_C(251), \
       UINT8_C(168),   UINT8_C(97),   UINT8_C(88),  UINT8_C(158),   UINT8_C(69),   UINT8_C(12),  UINT8_C(187),  UINT8_C(243), \
       UINT8_C(208),  UINT8_C(138),  UINT8_C(136),   UINT8_C(19),   UINT8_C(46),  UINT8_C(251),   UINT8_C(61),   UINT8_C(34), \
       UINT8_C(100),    UINT8_C(0),  UINT8_C(156),  UINT8_C(255),    UINT8_C(0),  UINT8_C(125),    UINT8_C(0),  UINT8_C(131), \
       UINT8_C(225),   UINT8_C(16),  UINT8_C(108),  UINT8_C(217),  UINT8_C(152),   UINT8_C(58),  UINT8_C(104),  UINT8_C(197), \
         UINT8_C(9),    UINT8_C(3),  UINT8_C(247),  UINT8_C(252),  UINT8_C(174),    UINT8_C(8),   UINT8_C(82),  UINT8_C(247), \
        UINT8_C(17),   UINT8_C(39),  UINT8_C(239),  UINT8_C(216),   UINT8_C(32),   UINT8_C(78),  UINT8_C(224),  UINT8_C(177), \
        UINT8_C(43),    UINT8_C(2),  UINT8_C(213),  UINT8_C(253),  UINT8_C(133),   UINT8_C(26),  UINT8_C(123),  UINT8_C(229), \
        UINT8_C(15),   UINT8_C(39),  UINT8_C(241),  UINT8_C(216),   UINT8_C(87),    UINT8_C(4),  UINT8_C(169),  UINT8_C(251), \
       UINT8_C(168),   UINT8_C(97),   UINT8_C(88),  UINT8_C(158),   UINT8_C(69),   UINT8_C(12),  UINT8_C(187),  UINT8_C(243)

/* Shared input: accumulator pair (lo half) for vlut16or (128 bytes) */
#define TEST_VXX_LO \
         UINT8_C(1),    UINT8_C(0),    UINT8_C(2),    UINT8_C(0),    UINT8_C(3),    UINT8_C(0),    UINT8_C(4),    UINT8_C(0), \
         UINT8_C(5),    UINT8_C(0),    UINT8_C(6),    UINT8_C(0),    UINT8_C(7),    UINT8_C(0),    UINT8_C(8),    UINT8_C(0), \
         UINT8_C(9),    UINT8_C(0),   UINT8_C(10),    UINT8_C(0),   UINT8_C(11),    UINT8_C(0),   UINT8_C(12),    UINT8_C(0), \
        UINT8_C(13),    UINT8_C(0),   UINT8_C(14),    UINT8_C(0),   UINT8_C(15),    UINT8_C(0),   UINT8_C(16),    UINT8_C(0), \
        UINT8_C(17),    UINT8_C(0),   UINT8_C(18),    UINT8_C(0),   UINT8_C(19),    UINT8_C(0),   UINT8_C(20),    UINT8_C(0), \
        UINT8_C(21),    UINT8_C(0),   UINT8_C(22),    UINT8_C(0),   UINT8_C(23),    UINT8_C(0),   UINT8_C(24),    UINT8_C(0), \
        UINT8_C(25),    UINT8_C(0),   UINT8_C(26),    UINT8_C(0),   UINT8_C(27),    UINT8_C(0),   UINT8_C(28),    UINT8_C(0), \
        UINT8_C(29),    UINT8_C(0),   UINT8_C(30),    UINT8_C(0),   UINT8_C(31),    UINT8_C(0),   UINT8_C(32),    UINT8_C(0), \
       UINT8_C(255),  UINT8_C(255),  UINT8_C(254),  UINT8_C(255),  UINT8_C(253),  UINT8_C(255),  UINT8_C(252),  UINT8_C(255), \
       UINT8_C(251),  UINT8_C(255),  UINT8_C(250),  UINT8_C(255),  UINT8_C(249),  UINT8_C(255),  UINT8_C(248),  UINT8_C(255), \
       UINT8_C(247),  UINT8_C(255),  UINT8_C(246),  UINT8_C(255),  UINT8_C(245),  UINT8_C(255),  UINT8_C(244),  UINT8_C(255), \
       UINT8_C(243),  UINT8_C(255),  UINT8_C(242),  UINT8_C(255),  UINT8_C(241),  UINT8_C(255),  UINT8_C(240),  UINT8_C(255), \
       UINT8_C(239),  UINT8_C(255),  UINT8_C(238),  UINT8_C(255),  UINT8_C(237),  UINT8_C(255),  UINT8_C(236),  UINT8_C(255), \
       UINT8_C(235),  UINT8_C(255),  UINT8_C(234),  UINT8_C(255),  UINT8_C(233),  UINT8_C(255),  UINT8_C(232),  UINT8_C(255), \
       UINT8_C(231),  UINT8_C(255),  UINT8_C(230),  UINT8_C(255),  UINT8_C(229),  UINT8_C(255),  UINT8_C(228),  UINT8_C(255), \
       UINT8_C(227),  UINT8_C(255),  UINT8_C(226),  UINT8_C(255),  UINT8_C(225),  UINT8_C(255),  UINT8_C(224),  UINT8_C(255)

/* Shared input: accumulator pair (hi half) for vlut16or (128 bytes) */
#define TEST_VXX_HI \
       UINT8_C(100),    UINT8_C(0),  UINT8_C(101),    UINT8_C(0),  UINT8_C(102),    UINT8_C(0),  UINT8_C(103),    UINT8_C(0), \
       UINT8_C(104),    UINT8_C(0),  UINT8_C(105),    UINT8_C(0),  UINT8_C(106),    UINT8_C(0),  UINT8_C(107),    UINT8_C(0), \
       UINT8_C(108),    UINT8_C(0),  UINT8_C(109),    UINT8_C(0),  UINT8_C(110),    UINT8_C(0),  UINT8_C(111),    UINT8_C(0), \
       UINT8_C(112),    UINT8_C(0),  UINT8_C(113),    UINT8_C(0),  UINT8_C(114),    UINT8_C(0),  UINT8_C(115),    UINT8_C(0), \
       UINT8_C(116),    UINT8_C(0),  UINT8_C(117),    UINT8_C(0),  UINT8_C(118),    UINT8_C(0),  UINT8_C(119),    UINT8_C(0), \
       UINT8_C(120),    UINT8_C(0),  UINT8_C(121),    UINT8_C(0),  UINT8_C(122),    UINT8_C(0),  UINT8_C(123),    UINT8_C(0), \
       UINT8_C(124),    UINT8_C(0),  UINT8_C(125),    UINT8_C(0),  UINT8_C(126),    UINT8_C(0),  UINT8_C(127),    UINT8_C(0), \
       UINT8_C(128),    UINT8_C(0),  UINT8_C(129),    UINT8_C(0),  UINT8_C(130),    UINT8_C(0),  UINT8_C(131),    UINT8_C(0), \
       UINT8_C(156),  UINT8_C(255),  UINT8_C(155),  UINT8_C(255),  UINT8_C(154),  UINT8_C(255),  UINT8_C(153),  UINT8_C(255), \
       UINT8_C(152),  UINT8_C(255),  UINT8_C(151),  UINT8_C(255),  UINT8_C(150),  UINT8_C(255),  UINT8_C(149),  UINT8_C(255), \
       UINT8_C(148),  UINT8_C(255),  UINT8_C(147),  UINT8_C(255),  UINT8_C(146),  UINT8_C(255),  UINT8_C(145),  UINT8_C(255), \
       UINT8_C(144),  UINT8_C(255),  UINT8_C(143),  UINT8_C(255),  UINT8_C(142),  UINT8_C(255),  UINT8_C(141),  UINT8_C(255), \
       UINT8_C(140),  UINT8_C(255),  UINT8_C(139),  UINT8_C(255),  UINT8_C(138),  UINT8_C(255),  UINT8_C(137),  UINT8_C(255), \
       UINT8_C(136),  UINT8_C(255),  UINT8_C(135),  UINT8_C(255),  UINT8_C(134),  UINT8_C(255),  UINT8_C(133),  UINT8_C(255), \
       UINT8_C(132),  UINT8_C(255),  UINT8_C(131),  UINT8_C(255),  UINT8_C(130),  UINT8_C(255),  UINT8_C(129),  UINT8_C(255), \
       UINT8_C(128),  UINT8_C(255),  UINT8_C(127),  UINT8_C(255),  UINT8_C(126),  UINT8_C(255),  UINT8_C(125),  UINT8_C(255)

static int
test_simde_vlut32_VbVbR_Rt0(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(0),
      {
        UINT8_C(89),   UINT8_C(15),  UINT8_C(197),  UINT8_C(123),   UINT8_C(49),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(167),   UINT8_C(93),   UINT8_C(19),
       UINT8_C(201),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),   UINT8_C(63),  UINT8_C(245),  UINT8_C(171),   UINT8_C(97),   UINT8_C(23),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(141),   UINT8_C(67),
       UINT8_C(249),  UINT8_C(175),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 0, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_Rt1(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(1),
      {
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(231),  UINT8_C(157),   UINT8_C(83),
         UINT8_C(9),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),  UINT8_C(127),   UINT8_C(53),  UINT8_C(235),  UINT8_C(161),   UINT8_C(87),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(205),  UINT8_C(131),
        UINT8_C(57),  UINT8_C(239),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),  UINT8_C(101),   UINT8_C(27),  UINT8_C(209),  UINT8_C(135),   UINT8_C(61),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 0, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_Rt2(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(2),
      {
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),   UINT8_C(76),    UINT8_C(2),  UINT8_C(184),  UINT8_C(110),   UINT8_C(36),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(154),   UINT8_C(80),
         UINT8_C(6),  UINT8_C(188),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),   UINT8_C(50),  UINT8_C(232),  UINT8_C(158),   UINT8_C(84),   UINT8_C(10),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(128),
        UINT8_C(54),  UINT8_C(236),  UINT8_C(162),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 0, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_Rt3(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(3),
      {
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(218),  UINT8_C(144),
        UINT8_C(70),  UINT8_C(252),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),  UINT8_C(114),   UINT8_C(40),  UINT8_C(222),  UINT8_C(148),   UINT8_C(74),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(192),
       UINT8_C(118),   UINT8_C(44),  UINT8_C(226),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),   UINT8_C(88),   UINT8_C(14),  UINT8_C(196),  UINT8_C(122),   UINT8_C(48)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 0, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_Rt4(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(4),
      {
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),   UINT8_C(37),  UINT8_C(219),  UINT8_C(145),   UINT8_C(71),  UINT8_C(253),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(115),
        UINT8_C(41),  UINT8_C(223),  UINT8_C(149),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),   UINT8_C(11),  UINT8_C(193),  UINT8_C(119),   UINT8_C(45),  UINT8_C(227),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 0, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_Rt5(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(5),
      {
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(179),
       UINT8_C(105),   UINT8_C(31),  UINT8_C(213),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),   UINT8_C(75),    UINT8_C(1),  UINT8_C(183),  UINT8_C(109),   UINT8_C(35),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
       UINT8_C(153),   UINT8_C(79),    UINT8_C(5),  UINT8_C(187),  UINT8_C(113),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 0, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_Rt6(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(6),
      {
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),   UINT8_C(24),  UINT8_C(206),  UINT8_C(132),   UINT8_C(58),  UINT8_C(240),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
       UINT8_C(102),   UINT8_C(28),  UINT8_C(210),  UINT8_C(136),   UINT8_C(62),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(180),  UINT8_C(106),   UINT8_C(32),
       UINT8_C(214),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 0, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_Rt7(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(7),
      {
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
       UINT8_C(166),   UINT8_C(92),   UINT8_C(18),  UINT8_C(200),  UINT8_C(126),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),  UINT8_C(244),  UINT8_C(170),   UINT8_C(96),
        UINT8_C(22),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),  UINT8_C(140),   UINT8_C(66),  UINT8_C(248),  UINT8_C(174),  UINT8_C(100),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),
         UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0),    UINT8_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 0, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbI(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde_hvx_vector_t idx = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_IDX });
  simde_hvx_vector_t tbl = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_TBL32 });
  simde_hvx_vector_t r_imm = simde_Q6_Vb_vlut32_VbVbI(idx, tbl, 5);
  simde_hvx_vector_t r_reg = simde_Q6_Vb_vlut32_VbVbR(idx, tbl, 5);

  simde_test_hvx_vector_u8_assert_equal(r_imm, r_reg);

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_nomatch_Rt0(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(0),
      {
        UINT8_C(89),   UINT8_C(15),  UINT8_C(197),  UINT8_C(123),   UINT8_C(49),  UINT8_C(167),   UINT8_C(93),   UINT8_C(19),
       UINT8_C(201),   UINT8_C(63),  UINT8_C(245),  UINT8_C(171),   UINT8_C(97),   UINT8_C(23),  UINT8_C(141),   UINT8_C(67),
       UINT8_C(249),  UINT8_C(175),   UINT8_C(37),  UINT8_C(219),  UINT8_C(145),   UINT8_C(71),  UINT8_C(253),  UINT8_C(115),
        UINT8_C(41),  UINT8_C(223),  UINT8_C(149),   UINT8_C(11),  UINT8_C(193),  UINT8_C(119),   UINT8_C(45),  UINT8_C(227),
        UINT8_C(89),   UINT8_C(15),  UINT8_C(197),  UINT8_C(123),   UINT8_C(49),  UINT8_C(167),   UINT8_C(93),   UINT8_C(19),
       UINT8_C(201),   UINT8_C(63),  UINT8_C(245),  UINT8_C(171),   UINT8_C(97),   UINT8_C(23),  UINT8_C(141),   UINT8_C(67),
       UINT8_C(249),  UINT8_C(175),   UINT8_C(37),  UINT8_C(219),  UINT8_C(145),   UINT8_C(71),  UINT8_C(253),  UINT8_C(115),
        UINT8_C(41),  UINT8_C(223),  UINT8_C(149),   UINT8_C(11),  UINT8_C(193),  UINT8_C(119),   UINT8_C(45),  UINT8_C(227),
        UINT8_C(89),   UINT8_C(15),  UINT8_C(197),  UINT8_C(123),   UINT8_C(49),  UINT8_C(167),   UINT8_C(93),   UINT8_C(19),
       UINT8_C(201),   UINT8_C(63),  UINT8_C(245),  UINT8_C(171),   UINT8_C(97),   UINT8_C(23),  UINT8_C(141),   UINT8_C(67),
       UINT8_C(249),  UINT8_C(175),   UINT8_C(37),  UINT8_C(219),  UINT8_C(145),   UINT8_C(71),  UINT8_C(253),  UINT8_C(115),
        UINT8_C(41),  UINT8_C(223),  UINT8_C(149),   UINT8_C(11),  UINT8_C(193),  UINT8_C(119),   UINT8_C(45),  UINT8_C(227),
        UINT8_C(89),   UINT8_C(15),  UINT8_C(197),  UINT8_C(123),   UINT8_C(49),  UINT8_C(167),   UINT8_C(93),   UINT8_C(19),
       UINT8_C(201),   UINT8_C(63),  UINT8_C(245),  UINT8_C(171),   UINT8_C(97),   UINT8_C(23),  UINT8_C(141),   UINT8_C(67),
       UINT8_C(249),  UINT8_C(175),   UINT8_C(37),  UINT8_C(219),  UINT8_C(145),   UINT8_C(71),  UINT8_C(253),  UINT8_C(115),
        UINT8_C(41),  UINT8_C(223),  UINT8_C(149),   UINT8_C(11),  UINT8_C(193),  UINT8_C(119),   UINT8_C(45),  UINT8_C(227)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR_nomatch(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 1, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_nomatch_Rt1(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(1),
      {
       UINT8_C(153),   UINT8_C(79),    UINT8_C(5),  UINT8_C(187),  UINT8_C(113),  UINT8_C(231),  UINT8_C(157),   UINT8_C(83),
         UINT8_C(9),  UINT8_C(127),   UINT8_C(53),  UINT8_C(235),  UINT8_C(161),   UINT8_C(87),  UINT8_C(205),  UINT8_C(131),
        UINT8_C(57),  UINT8_C(239),  UINT8_C(101),   UINT8_C(27),  UINT8_C(209),  UINT8_C(135),   UINT8_C(61),  UINT8_C(179),
       UINT8_C(105),   UINT8_C(31),  UINT8_C(213),   UINT8_C(75),    UINT8_C(1),  UINT8_C(183),  UINT8_C(109),   UINT8_C(35),
       UINT8_C(153),   UINT8_C(79),    UINT8_C(5),  UINT8_C(187),  UINT8_C(113),  UINT8_C(231),  UINT8_C(157),   UINT8_C(83),
         UINT8_C(9),  UINT8_C(127),   UINT8_C(53),  UINT8_C(235),  UINT8_C(161),   UINT8_C(87),  UINT8_C(205),  UINT8_C(131),
        UINT8_C(57),  UINT8_C(239),  UINT8_C(101),   UINT8_C(27),  UINT8_C(209),  UINT8_C(135),   UINT8_C(61),  UINT8_C(179),
       UINT8_C(105),   UINT8_C(31),  UINT8_C(213),   UINT8_C(75),    UINT8_C(1),  UINT8_C(183),  UINT8_C(109),   UINT8_C(35),
       UINT8_C(153),   UINT8_C(79),    UINT8_C(5),  UINT8_C(187),  UINT8_C(113),  UINT8_C(231),  UINT8_C(157),   UINT8_C(83),
         UINT8_C(9),  UINT8_C(127),   UINT8_C(53),  UINT8_C(235),  UINT8_C(161),   UINT8_C(87),  UINT8_C(205),  UINT8_C(131),
        UINT8_C(57),  UINT8_C(239),  UINT8_C(101),   UINT8_C(27),  UINT8_C(209),  UINT8_C(135),   UINT8_C(61),  UINT8_C(179),
       UINT8_C(105),   UINT8_C(31),  UINT8_C(213),   UINT8_C(75),    UINT8_C(1),  UINT8_C(183),  UINT8_C(109),   UINT8_C(35),
       UINT8_C(153),   UINT8_C(79),    UINT8_C(5),  UINT8_C(187),  UINT8_C(113),  UINT8_C(231),  UINT8_C(157),   UINT8_C(83),
         UINT8_C(9),  UINT8_C(127),   UINT8_C(53),  UINT8_C(235),  UINT8_C(161),   UINT8_C(87),  UINT8_C(205),  UINT8_C(131),
        UINT8_C(57),  UINT8_C(239),  UINT8_C(101),   UINT8_C(27),  UINT8_C(209),  UINT8_C(135),   UINT8_C(61),  UINT8_C(179),
       UINT8_C(105),   UINT8_C(31),  UINT8_C(213),   UINT8_C(75),    UINT8_C(1),  UINT8_C(183),  UINT8_C(109),   UINT8_C(35)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR_nomatch(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 1, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_nomatch_Rt2(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(2),
      {
       UINT8_C(102),   UINT8_C(28),  UINT8_C(210),  UINT8_C(136),   UINT8_C(62),  UINT8_C(180),  UINT8_C(106),   UINT8_C(32),
       UINT8_C(214),   UINT8_C(76),    UINT8_C(2),  UINT8_C(184),  UINT8_C(110),   UINT8_C(36),  UINT8_C(154),   UINT8_C(80),
         UINT8_C(6),  UINT8_C(188),   UINT8_C(50),  UINT8_C(232),  UINT8_C(158),   UINT8_C(84),   UINT8_C(10),  UINT8_C(128),
        UINT8_C(54),  UINT8_C(236),  UINT8_C(162),   UINT8_C(24),  UINT8_C(206),  UINT8_C(132),   UINT8_C(58),  UINT8_C(240),
       UINT8_C(102),   UINT8_C(28),  UINT8_C(210),  UINT8_C(136),   UINT8_C(62),  UINT8_C(180),  UINT8_C(106),   UINT8_C(32),
       UINT8_C(214),   UINT8_C(76),    UINT8_C(2),  UINT8_C(184),  UINT8_C(110),   UINT8_C(36),  UINT8_C(154),   UINT8_C(80),
         UINT8_C(6),  UINT8_C(188),   UINT8_C(50),  UINT8_C(232),  UINT8_C(158),   UINT8_C(84),   UINT8_C(10),  UINT8_C(128),
        UINT8_C(54),  UINT8_C(236),  UINT8_C(162),   UINT8_C(24),  UINT8_C(206),  UINT8_C(132),   UINT8_C(58),  UINT8_C(240),
       UINT8_C(102),   UINT8_C(28),  UINT8_C(210),  UINT8_C(136),   UINT8_C(62),  UINT8_C(180),  UINT8_C(106),   UINT8_C(32),
       UINT8_C(214),   UINT8_C(76),    UINT8_C(2),  UINT8_C(184),  UINT8_C(110),   UINT8_C(36),  UINT8_C(154),   UINT8_C(80),
         UINT8_C(6),  UINT8_C(188),   UINT8_C(50),  UINT8_C(232),  UINT8_C(158),   UINT8_C(84),   UINT8_C(10),  UINT8_C(128),
        UINT8_C(54),  UINT8_C(236),  UINT8_C(162),   UINT8_C(24),  UINT8_C(206),  UINT8_C(132),   UINT8_C(58),  UINT8_C(240),
       UINT8_C(102),   UINT8_C(28),  UINT8_C(210),  UINT8_C(136),   UINT8_C(62),  UINT8_C(180),  UINT8_C(106),   UINT8_C(32),
       UINT8_C(214),   UINT8_C(76),    UINT8_C(2),  UINT8_C(184),  UINT8_C(110),   UINT8_C(36),  UINT8_C(154),   UINT8_C(80),
         UINT8_C(6),  UINT8_C(188),   UINT8_C(50),  UINT8_C(232),  UINT8_C(158),   UINT8_C(84),   UINT8_C(10),  UINT8_C(128),
        UINT8_C(54),  UINT8_C(236),  UINT8_C(162),   UINT8_C(24),  UINT8_C(206),  UINT8_C(132),   UINT8_C(58),  UINT8_C(240)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR_nomatch(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 1, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_nomatch_Rt3(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(3),
      {
       UINT8_C(166),   UINT8_C(92),   UINT8_C(18),  UINT8_C(200),  UINT8_C(126),  UINT8_C(244),  UINT8_C(170),   UINT8_C(96),
        UINT8_C(22),  UINT8_C(140),   UINT8_C(66),  UINT8_C(248),  UINT8_C(174),  UINT8_C(100),  UINT8_C(218),  UINT8_C(144),
        UINT8_C(70),  UINT8_C(252),  UINT8_C(114),   UINT8_C(40),  UINT8_C(222),  UINT8_C(148),   UINT8_C(74),  UINT8_C(192),
       UINT8_C(118),   UINT8_C(44),  UINT8_C(226),   UINT8_C(88),   UINT8_C(14),  UINT8_C(196),  UINT8_C(122),   UINT8_C(48),
       UINT8_C(166),   UINT8_C(92),   UINT8_C(18),  UINT8_C(200),  UINT8_C(126),  UINT8_C(244),  UINT8_C(170),   UINT8_C(96),
        UINT8_C(22),  UINT8_C(140),   UINT8_C(66),  UINT8_C(248),  UINT8_C(174),  UINT8_C(100),  UINT8_C(218),  UINT8_C(144),
        UINT8_C(70),  UINT8_C(252),  UINT8_C(114),   UINT8_C(40),  UINT8_C(222),  UINT8_C(148),   UINT8_C(74),  UINT8_C(192),
       UINT8_C(118),   UINT8_C(44),  UINT8_C(226),   UINT8_C(88),   UINT8_C(14),  UINT8_C(196),  UINT8_C(122),   UINT8_C(48),
       UINT8_C(166),   UINT8_C(92),   UINT8_C(18),  UINT8_C(200),  UINT8_C(126),  UINT8_C(244),  UINT8_C(170),   UINT8_C(96),
        UINT8_C(22),  UINT8_C(140),   UINT8_C(66),  UINT8_C(248),  UINT8_C(174),  UINT8_C(100),  UINT8_C(218),  UINT8_C(144),
        UINT8_C(70),  UINT8_C(252),  UINT8_C(114),   UINT8_C(40),  UINT8_C(222),  UINT8_C(148),   UINT8_C(74),  UINT8_C(192),
       UINT8_C(118),   UINT8_C(44),  UINT8_C(226),   UINT8_C(88),   UINT8_C(14),  UINT8_C(196),  UINT8_C(122),   UINT8_C(48),
       UINT8_C(166),   UINT8_C(92),   UINT8_C(18),  UINT8_C(200),  UINT8_C(126),  UINT8_C(244),  UINT8_C(170),   UINT8_C(96),
        UINT8_C(22),  UINT8_C(140),   UINT8_C(66),  UINT8_C(248),  UINT8_C(174),  UINT8_C(100),  UINT8_C(218),  UINT8_C(144),
        UINT8_C(70),  UINT8_C(252),  UINT8_C(114),   UINT8_C(40),  UINT8_C(222),  UINT8_C(148),   UINT8_C(74),  UINT8_C(192),
       UINT8_C(118),   UINT8_C(44),  UINT8_C(226),   UINT8_C(88),   UINT8_C(14),  UINT8_C(196),  UINT8_C(122),   UINT8_C(48)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR_nomatch(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 1, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_nomatch_Rt4(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(4),
      {
        UINT8_C(89),   UINT8_C(15),  UINT8_C(197),  UINT8_C(123),   UINT8_C(49),  UINT8_C(167),   UINT8_C(93),   UINT8_C(19),
       UINT8_C(201),   UINT8_C(63),  UINT8_C(245),  UINT8_C(171),   UINT8_C(97),   UINT8_C(23),  UINT8_C(141),   UINT8_C(67),
       UINT8_C(249),  UINT8_C(175),   UINT8_C(37),  UINT8_C(219),  UINT8_C(145),   UINT8_C(71),  UINT8_C(253),  UINT8_C(115),
        UINT8_C(41),  UINT8_C(223),  UINT8_C(149),   UINT8_C(11),  UINT8_C(193),  UINT8_C(119),   UINT8_C(45),  UINT8_C(227),
        UINT8_C(89),   UINT8_C(15),  UINT8_C(197),  UINT8_C(123),   UINT8_C(49),  UINT8_C(167),   UINT8_C(93),   UINT8_C(19),
       UINT8_C(201),   UINT8_C(63),  UINT8_C(245),  UINT8_C(171),   UINT8_C(97),   UINT8_C(23),  UINT8_C(141),   UINT8_C(67),
       UINT8_C(249),  UINT8_C(175),   UINT8_C(37),  UINT8_C(219),  UINT8_C(145),   UINT8_C(71),  UINT8_C(253),  UINT8_C(115),
        UINT8_C(41),  UINT8_C(223),  UINT8_C(149),   UINT8_C(11),  UINT8_C(193),  UINT8_C(119),   UINT8_C(45),  UINT8_C(227),
        UINT8_C(89),   UINT8_C(15),  UINT8_C(197),  UINT8_C(123),   UINT8_C(49),  UINT8_C(167),   UINT8_C(93),   UINT8_C(19),
       UINT8_C(201),   UINT8_C(63),  UINT8_C(245),  UINT8_C(171),   UINT8_C(97),   UINT8_C(23),  UINT8_C(141),   UINT8_C(67),
       UINT8_C(249),  UINT8_C(175),   UINT8_C(37),  UINT8_C(219),  UINT8_C(145),   UINT8_C(71),  UINT8_C(253),  UINT8_C(115),
        UINT8_C(41),  UINT8_C(223),  UINT8_C(149),   UINT8_C(11),  UINT8_C(193),  UINT8_C(119),   UINT8_C(45),  UINT8_C(227),
        UINT8_C(89),   UINT8_C(15),  UINT8_C(197),  UINT8_C(123),   UINT8_C(49),  UINT8_C(167),   UINT8_C(93),   UINT8_C(19),
       UINT8_C(201),   UINT8_C(63),  UINT8_C(245),  UINT8_C(171),   UINT8_C(97),   UINT8_C(23),  UINT8_C(141),   UINT8_C(67),
       UINT8_C(249),  UINT8_C(175),   UINT8_C(37),  UINT8_C(219),  UINT8_C(145),   UINT8_C(71),  UINT8_C(253),  UINT8_C(115),
        UINT8_C(41),  UINT8_C(223),  UINT8_C(149),   UINT8_C(11),  UINT8_C(193),  UINT8_C(119),   UINT8_C(45),  UINT8_C(227)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR_nomatch(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 1, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_nomatch_Rt5(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(5),
      {
       UINT8_C(153),   UINT8_C(79),    UINT8_C(5),  UINT8_C(187),  UINT8_C(113),  UINT8_C(231),  UINT8_C(157),   UINT8_C(83),
         UINT8_C(9),  UINT8_C(127),   UINT8_C(53),  UINT8_C(235),  UINT8_C(161),   UINT8_C(87),  UINT8_C(205),  UINT8_C(131),
        UINT8_C(57),  UINT8_C(239),  UINT8_C(101),   UINT8_C(27),  UINT8_C(209),  UINT8_C(135),   UINT8_C(61),  UINT8_C(179),
       UINT8_C(105),   UINT8_C(31),  UINT8_C(213),   UINT8_C(75),    UINT8_C(1),  UINT8_C(183),  UINT8_C(109),   UINT8_C(35),
       UINT8_C(153),   UINT8_C(79),    UINT8_C(5),  UINT8_C(187),  UINT8_C(113),  UINT8_C(231),  UINT8_C(157),   UINT8_C(83),
         UINT8_C(9),  UINT8_C(127),   UINT8_C(53),  UINT8_C(235),  UINT8_C(161),   UINT8_C(87),  UINT8_C(205),  UINT8_C(131),
        UINT8_C(57),  UINT8_C(239),  UINT8_C(101),   UINT8_C(27),  UINT8_C(209),  UINT8_C(135),   UINT8_C(61),  UINT8_C(179),
       UINT8_C(105),   UINT8_C(31),  UINT8_C(213),   UINT8_C(75),    UINT8_C(1),  UINT8_C(183),  UINT8_C(109),   UINT8_C(35),
       UINT8_C(153),   UINT8_C(79),    UINT8_C(5),  UINT8_C(187),  UINT8_C(113),  UINT8_C(231),  UINT8_C(157),   UINT8_C(83),
         UINT8_C(9),  UINT8_C(127),   UINT8_C(53),  UINT8_C(235),  UINT8_C(161),   UINT8_C(87),  UINT8_C(205),  UINT8_C(131),
        UINT8_C(57),  UINT8_C(239),  UINT8_C(101),   UINT8_C(27),  UINT8_C(209),  UINT8_C(135),   UINT8_C(61),  UINT8_C(179),
       UINT8_C(105),   UINT8_C(31),  UINT8_C(213),   UINT8_C(75),    UINT8_C(1),  UINT8_C(183),  UINT8_C(109),   UINT8_C(35),
       UINT8_C(153),   UINT8_C(79),    UINT8_C(5),  UINT8_C(187),  UINT8_C(113),  UINT8_C(231),  UINT8_C(157),   UINT8_C(83),
         UINT8_C(9),  UINT8_C(127),   UINT8_C(53),  UINT8_C(235),  UINT8_C(161),   UINT8_C(87),  UINT8_C(205),  UINT8_C(131),
        UINT8_C(57),  UINT8_C(239),  UINT8_C(101),   UINT8_C(27),  UINT8_C(209),  UINT8_C(135),   UINT8_C(61),  UINT8_C(179),
       UINT8_C(105),   UINT8_C(31),  UINT8_C(213),   UINT8_C(75),    UINT8_C(1),  UINT8_C(183),  UINT8_C(109),   UINT8_C(35)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR_nomatch(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 1, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_nomatch_Rt6(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(6),
      {
       UINT8_C(102),   UINT8_C(28),  UINT8_C(210),  UINT8_C(136),   UINT8_C(62),  UINT8_C(180),  UINT8_C(106),   UINT8_C(32),
       UINT8_C(214),   UINT8_C(76),    UINT8_C(2),  UINT8_C(184),  UINT8_C(110),   UINT8_C(36),  UINT8_C(154),   UINT8_C(80),
         UINT8_C(6),  UINT8_C(188),   UINT8_C(50),  UINT8_C(232),  UINT8_C(158),   UINT8_C(84),   UINT8_C(10),  UINT8_C(128),
        UINT8_C(54),  UINT8_C(236),  UINT8_C(162),   UINT8_C(24),  UINT8_C(206),  UINT8_C(132),   UINT8_C(58),  UINT8_C(240),
       UINT8_C(102),   UINT8_C(28),  UINT8_C(210),  UINT8_C(136),   UINT8_C(62),  UINT8_C(180),  UINT8_C(106),   UINT8_C(32),
       UINT8_C(214),   UINT8_C(76),    UINT8_C(2),  UINT8_C(184),  UINT8_C(110),   UINT8_C(36),  UINT8_C(154),   UINT8_C(80),
         UINT8_C(6),  UINT8_C(188),   UINT8_C(50),  UINT8_C(232),  UINT8_C(158),   UINT8_C(84),   UINT8_C(10),  UINT8_C(128),
        UINT8_C(54),  UINT8_C(236),  UINT8_C(162),   UINT8_C(24),  UINT8_C(206),  UINT8_C(132),   UINT8_C(58),  UINT8_C(240),
       UINT8_C(102),   UINT8_C(28),  UINT8_C(210),  UINT8_C(136),   UINT8_C(62),  UINT8_C(180),  UINT8_C(106),   UINT8_C(32),
       UINT8_C(214),   UINT8_C(76),    UINT8_C(2),  UINT8_C(184),  UINT8_C(110),   UINT8_C(36),  UINT8_C(154),   UINT8_C(80),
         UINT8_C(6),  UINT8_C(188),   UINT8_C(50),  UINT8_C(232),  UINT8_C(158),   UINT8_C(84),   UINT8_C(10),  UINT8_C(128),
        UINT8_C(54),  UINT8_C(236),  UINT8_C(162),   UINT8_C(24),  UINT8_C(206),  UINT8_C(132),   UINT8_C(58),  UINT8_C(240),
       UINT8_C(102),   UINT8_C(28),  UINT8_C(210),  UINT8_C(136),   UINT8_C(62),  UINT8_C(180),  UINT8_C(106),   UINT8_C(32),
       UINT8_C(214),   UINT8_C(76),    UINT8_C(2),  UINT8_C(184),  UINT8_C(110),   UINT8_C(36),  UINT8_C(154),   UINT8_C(80),
         UINT8_C(6),  UINT8_C(188),   UINT8_C(50),  UINT8_C(232),  UINT8_C(158),   UINT8_C(84),   UINT8_C(10),  UINT8_C(128),
        UINT8_C(54),  UINT8_C(236),  UINT8_C(162),   UINT8_C(24),  UINT8_C(206),  UINT8_C(132),   UINT8_C(58),  UINT8_C(240)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR_nomatch(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 1, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32_VbVbR_nomatch_Rt7(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(7),
      {
       UINT8_C(166),   UINT8_C(92),   UINT8_C(18),  UINT8_C(200),  UINT8_C(126),  UINT8_C(244),  UINT8_C(170),   UINT8_C(96),
        UINT8_C(22),  UINT8_C(140),   UINT8_C(66),  UINT8_C(248),  UINT8_C(174),  UINT8_C(100),  UINT8_C(218),  UINT8_C(144),
        UINT8_C(70),  UINT8_C(252),  UINT8_C(114),   UINT8_C(40),  UINT8_C(222),  UINT8_C(148),   UINT8_C(74),  UINT8_C(192),
       UINT8_C(118),   UINT8_C(44),  UINT8_C(226),   UINT8_C(88),   UINT8_C(14),  UINT8_C(196),  UINT8_C(122),   UINT8_C(48),
       UINT8_C(166),   UINT8_C(92),   UINT8_C(18),  UINT8_C(200),  UINT8_C(126),  UINT8_C(244),  UINT8_C(170),   UINT8_C(96),
        UINT8_C(22),  UINT8_C(140),   UINT8_C(66),  UINT8_C(248),  UINT8_C(174),  UINT8_C(100),  UINT8_C(218),  UINT8_C(144),
        UINT8_C(70),  UINT8_C(252),  UINT8_C(114),   UINT8_C(40),  UINT8_C(222),  UINT8_C(148),   UINT8_C(74),  UINT8_C(192),
       UINT8_C(118),   UINT8_C(44),  UINT8_C(226),   UINT8_C(88),   UINT8_C(14),  UINT8_C(196),  UINT8_C(122),   UINT8_C(48),
       UINT8_C(166),   UINT8_C(92),   UINT8_C(18),  UINT8_C(200),  UINT8_C(126),  UINT8_C(244),  UINT8_C(170),   UINT8_C(96),
        UINT8_C(22),  UINT8_C(140),   UINT8_C(66),  UINT8_C(248),  UINT8_C(174),  UINT8_C(100),  UINT8_C(218),  UINT8_C(144),
        UINT8_C(70),  UINT8_C(252),  UINT8_C(114),   UINT8_C(40),  UINT8_C(222),  UINT8_C(148),   UINT8_C(74),  UINT8_C(192),
       UINT8_C(118),   UINT8_C(44),  UINT8_C(226),   UINT8_C(88),   UINT8_C(14),  UINT8_C(196),  UINT8_C(122),   UINT8_C(48),
       UINT8_C(166),   UINT8_C(92),   UINT8_C(18),  UINT8_C(200),  UINT8_C(126),  UINT8_C(244),  UINT8_C(170),   UINT8_C(96),
        UINT8_C(22),  UINT8_C(140),   UINT8_C(66),  UINT8_C(248),  UINT8_C(174),  UINT8_C(100),  UINT8_C(218),  UINT8_C(144),
        UINT8_C(70),  UINT8_C(252),  UINT8_C(114),   UINT8_C(40),  UINT8_C(222),  UINT8_C(148),   UINT8_C(74),  UINT8_C(192),
       UINT8_C(118),   UINT8_C(44),  UINT8_C(226),   UINT8_C(88),   UINT8_C(14),  UINT8_C(196),  UINT8_C(122),   UINT8_C(48)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32_VbVbR_nomatch(idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, r, idx, tbl, test_vec[i].rt, 1, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32or_VbVbVbR_Rt0(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vx[128];
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VX },
      { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(0),
      {
       UINT8_C(217),   UINT8_C(15),  UINT8_C(199),  UINT8_C(127),   UINT8_C(51),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(239),   UINT8_C(95),   UINT8_C(55),
       UINT8_C(251),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62),
       UINT8_C(205),    UINT8_C(8),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(255),  UINT8_C(253),  UINT8_C(239),  UINT8_C(105),  UINT8_C(191),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),  UINT8_C(175),  UINT8_C(211),
       UINT8_C(255),  UINT8_C(175),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vx = simde_test_hvx_vector_load(test_vec[i].vx);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32or_VbVbVbR(vx, idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, vx, idx, tbl, test_vec[i].rt, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32or_VbVbVbR_Rt1(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vx[128];
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VX },
      { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(1),
      {
       UINT8_C(200),    UINT8_C(5),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(255),  UINT8_C(223),  UINT8_C(123),
        UINT8_C(25),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),  UINT8_C(127),  UINT8_C(183),  UINT8_C(255),  UINT8_C(179),   UINT8_C(95),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62),
       UINT8_C(205),    UINT8_C(8),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),  UINT8_C(237),  UINT8_C(223),
       UINT8_C(121),  UINT8_C(239),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(237),   UINT8_C(63),  UINT8_C(253),  UINT8_C(151),  UINT8_C(189),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vx = simde_test_hvx_vector_load(test_vec[i].vx);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32or_VbVbVbR(vx, idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, vx, idx, tbl, test_vec[i].rt, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32or_VbVbVbR_Rt2(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vx[128];
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VX },
      { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(2),
      {
       UINT8_C(200),    UINT8_C(5),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(222),   UINT8_C(62),  UINT8_C(252),  UINT8_C(110),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),  UINT8_C(191),  UINT8_C(210),
       UINT8_C(110),  UINT8_C(190),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62),
       UINT8_C(205),    UINT8_C(8),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),  UINT8_C(248),  UINT8_C(254),   UINT8_C(94),  UINT8_C(158),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),  UINT8_C(191),
        UINT8_C(62),  UINT8_C(253),  UINT8_C(227),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vx = simde_test_hvx_vector_load(test_vec[i].vx);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32or_VbVbVbR(vx, idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, vx, idx, tbl, test_vec[i].rt, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32or_VbVbVbR_Rt3(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vx[128];
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VX },
      { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(3),
      {
       UINT8_C(200),    UINT8_C(5),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),  UINT8_C(251),  UINT8_C(220),
        UINT8_C(70),  UINT8_C(252),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(251),   UINT8_C(63),  UINT8_C(255),  UINT8_C(149),  UINT8_C(218),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62),
       UINT8_C(205),    UINT8_C(8),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),  UINT8_C(198),
       UINT8_C(127),   UINT8_C(44),  UINT8_C(231),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),  UINT8_C(120),  UINT8_C(175),  UINT8_C(205),  UINT8_C(250),   UINT8_C(62)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vx = simde_test_hvx_vector_load(test_vec[i].vx);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32or_VbVbVbR(vx, idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, vx, idx, tbl, test_vec[i].rt, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32or_VbVbVbR_Rt4(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vx[128];
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VX },
      { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(4),
      {
       UINT8_C(200),    UINT8_C(5),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(191),  UINT8_C(219),  UINT8_C(241),   UINT8_C(95),  UINT8_C(255),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),  UINT8_C(127),
        UINT8_C(41),  UINT8_C(223),  UINT8_C(247),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62),
       UINT8_C(205),    UINT8_C(8),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(79),  UINT8_C(215),  UINT8_C(255),   UINT8_C(63),  UINT8_C(235),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vx = simde_test_hvx_vector_load(test_vec[i].vx);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32or_VbVbVbR(vx, idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, vx, idx, tbl, test_vec[i].rt, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32or_VbVbVbR_Rt5(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vx[128];
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VX },
      { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(5),
      {
       UINT8_C(200),    UINT8_C(5),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),  UINT8_C(183),
       UINT8_C(111),   UINT8_C(63),  UINT8_C(215),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),  UINT8_C(107),  UINT8_C(175),  UINT8_C(191),  UINT8_C(255),   UINT8_C(63),
       UINT8_C(205),    UINT8_C(8),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(189),   UINT8_C(95),  UINT8_C(141),  UINT8_C(251),  UINT8_C(127),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vx = simde_test_hvx_vector_load(test_vec[i].vx);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32or_VbVbVbR(vx, idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, vx, idx, tbl, test_vec[i].rt, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32or_VbVbVbR_Rt6(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vx[128];
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VX },
      { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(6),
      {
       UINT8_C(200),    UINT8_C(5),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(93),  UINT8_C(222),  UINT8_C(237),   UINT8_C(63),  UINT8_C(249),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62),
       UINT8_C(239),   UINT8_C(28),  UINT8_C(210),  UINT8_C(207),   UINT8_C(63),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(254),  UINT8_C(123),   UINT8_C(38),
       UINT8_C(254),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vx = simde_test_hvx_vector_load(test_vec[i].vx);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32or_VbVbVbR(vx, idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, vx, idx, tbl, test_vec[i].rt, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32or_VbVbVbR_Rt7(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vx[128];
    uint8_t idx[128];
    uint8_t tbl[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VX },
      { TEST_IDX },
      { TEST_TBL32 },
      INT32_C(7),
      {
       UINT8_C(200),    UINT8_C(5),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(250),   UINT8_C(90),   UINT8_C(40),
        UINT8_C(17),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(182),   UINT8_C(95),  UINT8_C(159),  UINT8_C(201),  UINT8_C(127),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),    UINT8_C(4),  UINT8_C(166),  UINT8_C(253),   UINT8_C(19),   UINT8_C(88),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62),
       UINT8_C(205),    UINT8_C(8),  UINT8_C(130),   UINT8_C(71),    UINT8_C(3),  UINT8_C(254),  UINT8_C(250),  UINT8_C(104),
        UINT8_C(23),  UINT8_C(210),   UINT8_C(60),  UINT8_C(100),    UINT8_C(8),  UINT8_C(175),   UINT8_C(33),  UINT8_C(220),
        UINT8_C(64),   UINT8_C(12),  UINT8_C(190),   UINT8_C(88),  UINT8_C(240),   UINT8_C(30),  UINT8_C(150),    UINT8_C(6),
       UINT8_C(111),   UINT8_C(44),  UINT8_C(199),   UINT8_C(77),   UINT8_C(22),  UINT8_C(233),   UINT8_C(55),    UINT8_C(9),
       UINT8_C(180),   UINT8_C(27),  UINT8_C(141),   UINT8_C(65),   UINT8_C(15),  UINT8_C(202),   UINT8_C(91),   UINT8_C(38),
       UINT8_C(122),  UINT8_C(140),  UINT8_C(230),  UINT8_C(253),  UINT8_C(191),  UINT8_C(124),   UINT8_C(47),  UINT8_C(210),
       UINT8_C(110),    UINT8_C(6),  UINT8_C(233),   UINT8_C(55),  UINT8_C(189),   UINT8_C(21),  UINT8_C(144),   UINT8_C(63),
         UINT8_C(8),  UINT8_C(217),   UINT8_C(99),   UINT8_C(40),  UINT8_C(175),   UINT8_C(13),  UINT8_C(250),   UINT8_C(62)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vx = simde_test_hvx_vector_load(test_vec[i].vx);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl = simde_test_hvx_vector_load(test_vec[i].tbl);
    simde_hvx_vector_t r = simde_Q6_Vb_vlut32or_VbVbVbR(vx, idx, tbl, test_vec[i].rt);

    simde_test_hvx_vector_u8_assert_equal(r, SIMDE_TEST_HVX_VLUT32_EXPECTED(test_vec[i].r, vx, idx, tbl, test_vec[i].rt, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut32or_VbVbVbI(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde_hvx_vector_t vx = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_VX });
  simde_hvx_vector_t idx = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_IDX });
  simde_hvx_vector_t tbl = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_TBL32 });
  simde_hvx_vector_t r_imm = simde_Q6_Vb_vlut32or_VbVbVbI(vx, idx, tbl, 5);
  simde_hvx_vector_t r_reg = simde_Q6_Vb_vlut32or_VbVbVbR(vx, idx, tbl, 5);

  simde_test_hvx_vector_u8_assert_equal(r_imm, r_reg);

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt0(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(0),
      {
      INT16_C(32000),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(1111),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(20000),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(15000),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
       INT16_C(555),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),  INT16_C(777),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),  INT16_C(100),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(9999),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt1(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(1),
      {
         INT16_C(0), -INT16_C(1234), INT16_C(3141),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(6789),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(2222),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      INT16_C(32000),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0), INT16_C(10001),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(4321),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(30000), INT16_C(25000),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
       INT16_C(555),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt2(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(2),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(1111),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(20000),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(15000),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), INT16_C(8765), -INT16_C(3141),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0), -INT16_C(777),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(100),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(9999),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), -INT16_C(10001),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt3(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(3),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(6789),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(2222),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      -INT16_C(32000),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(1111),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(9876),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(5000), -INT16_C(25000),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      -INT16_C(555),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0), -INT16_C(777),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt4(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(4),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(20000),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(15000),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), -INT16_C(1234), INT16_C(3141),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(6789),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),  INT16_C(100),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(9999),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), INT16_C(10001),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(4321),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt5(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(5),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(2222),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      INT16_C(32000),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(1111),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(20000),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(30000), INT16_C(25000),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
       INT16_C(555),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),  INT16_C(777),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),  INT16_C(100),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt6(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(6),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(15000),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), INT16_C(8765), -INT16_C(3141),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(6789),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(2222),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(9999),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), -INT16_C(10001),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(9876),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(5000), -INT16_C(25000),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt7(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(7),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      -INT16_C(32000),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(1111),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(20000),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(15000)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      -INT16_C(555),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0), -INT16_C(777),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(100),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt8(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(8),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), -INT16_C(1234), INT16_C(3141),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(6789),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(2222),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), INT16_C(10001),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(4321),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(30000), INT16_C(25000),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt9(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(9),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(1111),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(20000),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(15000),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),  INT16_C(777),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),  INT16_C(100),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(9999),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt10(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(10),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(6789),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(2222),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      -INT16_C(32000),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(9876),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(5000), -INT16_C(25000),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      -INT16_C(555),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt11(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(11),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(20000),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(15000),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), INT16_C(8765), -INT16_C(3141),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(100),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(9999),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), -INT16_C(10001),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt12(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(12),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(2222),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      INT16_C(32000),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(1111),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(30000), INT16_C(25000),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
       INT16_C(555),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),  INT16_C(777),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt13(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(13),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(15000),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), -INT16_C(1234), INT16_C(3141),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(6789),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(9999),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), INT16_C(10001),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(4321),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt14(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(14),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      -INT16_C(32000),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(1111),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(20000),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
      -INT16_C(555),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0), -INT16_C(777),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(100),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_Rt15(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(15),
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), INT16_C(8765), -INT16_C(3141),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(6789),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(2222),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      },
      {
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0), -INT16_C(10001),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0), -INT16_C(9876),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0), INT16_C(5000), -INT16_C(25000),    INT16_C(0),
         INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0),    INT16_C(0)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 0, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 0, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhI(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde_hvx_vector_t idx = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_IDX });
  simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_TBL16 });
  simde_hvx_vectorpair_t pair_imm = simde_Q6_Wh_vlut16_VbVhI(idx, tbl16, 5);
  simde_hvx_vectorpair_t pair_reg = simde_Q6_Wh_vlut16_VbVhR(idx, tbl16, 5);

  simde_test_hvx_vector_i16_assert_equal(simde_Q6_V_lo_W(pair_imm), simde_Q6_V_lo_W(pair_reg));
  simde_test_hvx_vector_i16_assert_equal(simde_Q6_V_hi_W(pair_imm), simde_Q6_V_hi_W(pair_reg));

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt0(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(0),
      {
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000)
      },
      {
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt1(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(1),
      {
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000)
      },
      {
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt2(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(2),
      {
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000)
      },
      {
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt3(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(3),
      {
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000)
      },
      {
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt4(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(4),
      {
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000)
      },
      {
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt5(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(5),
      {
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000)
      },
      {
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt6(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(6),
      {
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000)
      },
      {
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt7(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(7),
      {
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000)
      },
      {
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt8(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(8),
      {
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000)
      },
      {
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt9(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(9),
      {
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000)
      },
      {
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt10(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(10),
      {
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000)
      },
      {
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt11(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(11),
      {
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000)
      },
      {
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt12(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(12),
      {
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000)
      },
      {
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt13(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(13),
      {
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000),
      INT16_C(32000), -INT16_C(1234), INT16_C(3141), INT16_C(1111), INT16_C(6789), INT16_C(20000), INT16_C(2222), INT16_C(15000)
      },
      {
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999),
       INT16_C(555), INT16_C(10001),  INT16_C(777), INT16_C(4321),  INT16_C(100), -INT16_C(30000), INT16_C(25000), INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt14(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(14),
      {
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000)
      },
      {
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16_VbVhR_nomatch_Rt15(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(15),
      {
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000),
      -INT16_C(32000), INT16_C(8765), -INT16_C(3141), -INT16_C(1111), -INT16_C(6789), -INT16_C(20000), -INT16_C(2222), -INT16_C(15000)
      },
      {
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999),
      -INT16_C(555), -INT16_C(10001), -INT16_C(777), -INT16_C(9876), -INT16_C(100), INT16_C(5000), -INT16_C(25000), -INT16_C(9999)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16_VbVhR_nomatch(idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, pair, idx, tbl16, test_vec[i].rt, 1, 0, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, pair, idx, tbl16, test_vec[i].rt, 1, 0, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt0(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(0),
      {
      INT16_C(32001),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19), INT16_C(1111),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),   -INT16_C(8),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(623),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(895),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103),   -INT16_C(4), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(113),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt1(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(1),
      {
         INT16_C(1), -INT16_C(1234), INT16_C(3143),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20), INT16_C(6805),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(1),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100), INT16_C(10101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118), INT16_C(4343),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104),  -INT16_C(41),  -INT16_C(66), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
       -INT16_C(81), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt2(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(2),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3), -INT16_C(1107),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21), -INT16_C(19978),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),   -INT16_C(1),   -INT16_C(1),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101), -INT16_C(777),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),   -INT16_C(4),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106),  -INT16_C(11),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124),  -INT16_C(17), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt3(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(3),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4), -INT16_C(6785),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22), -INT16_C(2217),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(19),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102), -INT16_C(9873),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120), INT16_C(5113), -INT16_C(24966),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
       -INT16_C(43), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125),   -INT16_C(9), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt4(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(4),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5), INT16_C(20006),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23), INT16_C(15000),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),   -INT16_C(2),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(25),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(108),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122), INT16_C(10111),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126),  -INT16_C(31), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt5(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(5),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6), INT16_C(2223),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
      INT16_C(32025),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),   -INT16_C(9),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104), -INT16_C(29959), INT16_C(25066),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(639),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(101), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127),  -INT16_C(28), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt6(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(6),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7), -INT16_C(15000),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25), INT16_C(8767), -INT16_C(3141),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),   -INT16_C(5),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(13),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106), -INT16_C(9989),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124), -INT16_C(9985),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110),   -INT16_C(3), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128),   -INT16_C(1), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt7(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(7),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
      -INT16_C(31991),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27), -INT16_C(1091),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(24)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
      -INT16_C(515),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125), -INT16_C(769),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(100), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130),   -INT16_C(3)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt8(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(8),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9), -INT16_C(1234), INT16_C(3151),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28), INT16_C(6813),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),   -INT16_C(1),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108), INT16_C(10109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126), INT16_C(4351),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112),  -INT16_C(33),  -INT16_C(82), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt9(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(9),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11), INT16_C(1119),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29), INT16_C(20030),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),   -INT16_C(8),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(879),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(228),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(113),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt10(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(10),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12), -INT16_C(6785),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30), -INT16_C(2209),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110), -INT16_C(9873),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128), INT16_C(5001), -INT16_C(24870),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
       -INT16_C(35), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt11(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(11),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13), -INT16_C(19986),   INT16_C(15),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31), -INT16_C(15000),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),   -INT16_C(1),   -INT16_C(1),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),   -INT16_C(4),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130), -INT16_C(9997),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116),  -INT16_C(17), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt12(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(12),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14), INT16_C(2223),   INT16_C(16),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),   -INT16_C(1),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112), -INT16_C(29967), INT16_C(25082),  INT16_C(115),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
       -INT16_C(65), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(117), -INT16_C(119), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt13(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(13),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15), INT16_C(15000),
        INT16_C(17),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(17),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114), INT16_C(10111),
       INT16_C(116),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118),  -INT16_C(23), -INT16_C(120), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt14(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(14),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
      -INT16_C(31983),   INT16_C(18),   INT16_C(19),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(3),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),  -INT16_C(23),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
      -INT16_C(523),  INT16_C(117),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101),   -INT16_C(1), -INT16_C(103), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(100), -INT16_C(121), -INT16_C(122), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhR_Rt15(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t vxx_lo[128];
    uint8_t vxx_hi[128];
    uint8_t idx[128];
    uint8_t tbl16[128];
    int32_t rt;
    int16_t r_lo[64];
    int16_t r_hi[64];
  } test_vec[] = {
    { { TEST_VXX_LO },
      { TEST_VXX_HI },
      { TEST_IDX },
      { TEST_TBL16 },
      INT32_C(15),
      {
         INT16_C(1),    INT16_C(2),    INT16_C(3),    INT16_C(4),    INT16_C(5),    INT16_C(6),    INT16_C(7),    INT16_C(8),
         INT16_C(9),   INT16_C(10),   INT16_C(11),   INT16_C(12),   INT16_C(13),   INT16_C(14),   INT16_C(15),   INT16_C(16),
        INT16_C(17), INT16_C(8767), -INT16_C(3141),   INT16_C(20),   INT16_C(21),   INT16_C(22),   INT16_C(23),   INT16_C(24),
        INT16_C(25),   INT16_C(26),   INT16_C(27),   INT16_C(28),   INT16_C(29),   INT16_C(30),   INT16_C(31),   INT16_C(32),
        -INT16_C(1),   -INT16_C(2),   -INT16_C(3),   -INT16_C(4),   -INT16_C(5),   -INT16_C(6),   -INT16_C(7),   -INT16_C(8),
        -INT16_C(9),  -INT16_C(10),  -INT16_C(11),  -INT16_C(12),  -INT16_C(13),  -INT16_C(14),  -INT16_C(15),  -INT16_C(16),
       -INT16_C(17),  -INT16_C(18),  -INT16_C(19),  -INT16_C(20),  -INT16_C(21),  -INT16_C(22),   -INT16_C(5),  -INT16_C(24),
       -INT16_C(25),  -INT16_C(26),  -INT16_C(27),  -INT16_C(28),  -INT16_C(29),  -INT16_C(30),  -INT16_C(31),  -INT16_C(32)
      },
      {
       INT16_C(100),  INT16_C(101),  INT16_C(102),  INT16_C(103),  INT16_C(104),  INT16_C(105),  INT16_C(106),  INT16_C(107),
       INT16_C(108),  INT16_C(109),  INT16_C(110),  INT16_C(111),  INT16_C(112),  INT16_C(113),  INT16_C(114),  INT16_C(115),
       INT16_C(116), -INT16_C(9985),  INT16_C(118),  INT16_C(119),  INT16_C(120),  INT16_C(121),  INT16_C(122),  INT16_C(123),
       INT16_C(124),  INT16_C(125),  INT16_C(126),  INT16_C(127),  INT16_C(128),  INT16_C(129),  INT16_C(130),  INT16_C(131),
      -INT16_C(100), -INT16_C(101), -INT16_C(102),   -INT16_C(3), -INT16_C(104), -INT16_C(105), -INT16_C(106), -INT16_C(107),
      -INT16_C(108), -INT16_C(109), -INT16_C(110), -INT16_C(111), -INT16_C(112), -INT16_C(113), -INT16_C(114), -INT16_C(115),
      -INT16_C(116), -INT16_C(117), -INT16_C(118), -INT16_C(119), -INT16_C(120), -INT16_C(113),  -INT16_C(34), -INT16_C(123),
      -INT16_C(124), -INT16_C(125), -INT16_C(126), -INT16_C(127), -INT16_C(128), -INT16_C(129), -INT16_C(130), -INT16_C(131)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load(test_vec[i].vxx_lo);
    simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load(test_vec[i].vxx_hi);
    simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load(test_vec[i].tbl16);
    simde_hvx_vectorpair_t pair = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, test_vec[i].rt);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(pair);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(pair);

    simde_test_hvx_vector_i16_assert_equal(r_lo, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_lo, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 0));
    simde_test_hvx_vector_i16_assert_equal(r_hi, SIMDE_TEST_HVX_VLUT16_EXPECTED(test_vec[i].r_hi, vxx, idx, tbl16, test_vec[i].rt, 0, 1, 1));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut16or_WhVbVhI(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde_hvx_vector_t vxx_lo = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_VXX_LO });
  simde_hvx_vector_t vxx_hi = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_VXX_HI });
  simde_hvx_vectorpair_t vxx = simde_Q6_W_vcombine_VV(vxx_hi, vxx_lo);
  simde_hvx_vector_t idx = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_IDX });
  simde_hvx_vector_t tbl16 = simde_test_hvx_vector_load((const uint8_t[128]) { TEST_TBL16 });
  simde_hvx_vectorpair_t pair_imm = simde_Q6_Wh_vlut16or_WhVbVhI(vxx, idx, tbl16, 5);
  simde_hvx_vectorpair_t pair_reg = simde_Q6_Wh_vlut16or_WhVbVhR(vxx, idx, tbl16, 5);

  simde_test_hvx_vector_i16_assert_equal(simde_Q6_V_lo_W(pair_imm), simde_Q6_V_lo_W(pair_reg));
  simde_test_hvx_vector_i16_assert_equal(simde_Q6_V_hi_W(pair_imm), simde_Q6_V_hi_W(pair_reg));

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlut4_VuhPh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t idx[64];
    int64_t rtt;
    int16_t r[64];
  } test_vec[] = {
    { {
      UINT16_C(0x0000), UINT16_C(0x4000), UINT16_C(0x8000), UINT16_C(0xC000), UINT16_C(0x1234), UINT16_C(0x5678), UINT16_C(0x9ABC), UINT16_C(0xDEF0),
      UINT16_C(0x3FFF), UINT16_C(0x7FFF), UINT16_C(0xBFFF), UINT16_C(0xFFFF), UINT16_C(0x0001), UINT16_C(0x4001), UINT16_C(0x8001), UINT16_C(0xC001),
      UINT16_C(0x2AAA), UINT16_C(0x6AAA), UINT16_C(0xAAAA), UINT16_C(0xEAAA), UINT16_C(0x1555), UINT16_C(0x5555), UINT16_C(0x9555), UINT16_C(0xD555),
      UINT16_C(0x0F0F), UINT16_C(0x4F0F), UINT16_C(0x8F0F), UINT16_C(0xCF0F), UINT16_C(0x3210), UINT16_C(0x7654), UINT16_C(0xBA98), UINT16_C(0xFEDC),
      UINT16_C(0x0000), UINT16_C(0x4000), UINT16_C(0x8000), UINT16_C(0xC000), UINT16_C(0x1234), UINT16_C(0x5678), UINT16_C(0x9ABC), UINT16_C(0xDEF0),
      UINT16_C(0x3FFF), UINT16_C(0x7FFF), UINT16_C(0xBFFF), UINT16_C(0xFFFF), UINT16_C(0x0001), UINT16_C(0x4001), UINT16_C(0x8001), UINT16_C(0xC001),
      UINT16_C(0x2AAA), UINT16_C(0x6AAA), UINT16_C(0xAAAA), UINT16_C(0xEAAA), UINT16_C(0x1555), UINT16_C(0x5555), UINT16_C(0x9555), UINT16_C(0xD555),
      UINT16_C(0x0F0F), UINT16_C(0x4F0F), UINT16_C(0x8F0F), UINT16_C(0xCF0F), UINT16_C(0x3210), UINT16_C(0x7654), UINT16_C(0xBA98), UINT16_C(0xFEDC)
      },
      INT64_C(0x1234ABCD5678EF90),
      {
      -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660), -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660),
      -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660), -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660),
      -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660), -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660),
      -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660), -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660),
      -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660), -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660),
      -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660), -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660),
      -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660), -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660),
      -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660), -INT16_C(4208), INT16_C(22136), -INT16_C(21555), INT16_C(4660)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t idx = simde_test_hvx_vector_load(test_vec[i].idx);
    simde_hvx_vector_t r = simde_Q6_Vh_vlut4_VuhPh(idx, test_vec[i].rtt);

    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_Rt0)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_Rt1)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_Rt2)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_Rt3)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_Rt4)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_Rt5)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_Rt6)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_Rt7)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbI)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_nomatch_Rt0)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_nomatch_Rt1)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_nomatch_Rt2)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_nomatch_Rt3)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_nomatch_Rt4)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_nomatch_Rt5)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_nomatch_Rt6)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32_VbVbR_nomatch_Rt7)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32or_VbVbVbR_Rt0)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32or_VbVbVbR_Rt1)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32or_VbVbVbR_Rt2)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32or_VbVbVbR_Rt3)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32or_VbVbVbR_Rt4)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32or_VbVbVbR_Rt5)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32or_VbVbVbR_Rt6)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32or_VbVbVbR_Rt7)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut32or_VbVbVbI)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt0)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt1)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt2)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt3)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt4)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt5)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt6)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt7)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt8)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt9)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt10)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt11)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt12)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt13)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt14)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_Rt15)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhI)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt0)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt1)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt2)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt3)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt4)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt5)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt6)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt7)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt8)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt9)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt10)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt11)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt12)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt13)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt14)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16_VbVhR_nomatch_Rt15)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt0)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt1)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt2)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt3)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt4)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt5)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt6)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt7)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt8)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt9)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt10)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt11)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt12)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt13)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt14)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhR_Rt15)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut16or_WhVbVhI)
SIMDE_TEST_FUNC_LIST_ENTRY(vlut4_VuhPh)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
