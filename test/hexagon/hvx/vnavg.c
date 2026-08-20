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

#define SIMDE_TEST_HEXAGON_HVX_INSN vnavg

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vnavg.h"

static int
test_simde_vnavg_VbVb(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[128]; int8_t b[128]; int8_t r[128];
  } test_vec[] = {
    {      /* a */ {-INT8_C(  88),  INT8_C(  81), -INT8_C(  35), -INT8_C(   8), -INT8_C( 121), -INT8_C( 104), -INT8_C(  20),  INT8_C(  18), -INT8_C(  79), -INT8_C(  33), -INT8_C(  63),  INT8_C(  82),  INT8_C( 109),  INT8_C(  78), -INT8_C(   7),  INT8_C( 104)
                ,  INT8_C( 111),  INT8_C( 120),  INT8_C(  86),  INT8_C(  12),  INT8_C( 116), -INT8_C( 117), -INT8_C(  59), -INT8_C(  96), -INT8_C(  78),  INT8_C(  46),  INT8_C(  55), -INT8_C( 101), -INT8_C(  73),  INT8_C(  96), -INT8_C(  98),  INT8_C(  43)
                , -INT8_C(  41), -INT8_C(  27), -INT8_C(  65),  INT8_C(  76),  INT8_C(  32), -INT8_C( 123), -INT8_C( 122), -INT8_C(   6),  INT8_C(   0),  INT8_C(  22), -INT8_C(  57), -INT8_C(  14), -INT8_C(   5), -INT8_C( 109),  INT8_C(  16),  INT8_C(  78)
                , -INT8_C( 126), -INT8_C(  61), -INT8_C(  40),  INT8_C(  22),  INT8_C(  63),  INT8_C(  79),  INT8_C(  37), -INT8_C(  52), -INT8_C(   2),  INT8_C(  13),  INT8_C( 126),  INT8_C(  59),  INT8_C(  52),  INT8_C( 100), -INT8_C(  19), -INT8_C(  99)
                ,  INT8_C( 100), -INT8_C( 113), -INT8_C( 125), -INT8_C(  35), -INT8_C(  17),  INT8_C(  42),  INT8_C(  57),  INT8_C(   3),  INT8_C(  34),  INT8_C(  74), -INT8_C(  69),  INT8_C(  57), -INT8_C(  42), -INT8_C(  73), -INT8_C( 101),  INT8_C(  44)
                , -INT8_C(  50),  INT8_C(  42), -INT8_C(  44), -INT8_C(   2),  INT8_C(   3),  INT8_C(  66), -INT8_C(  96), -INT8_C(  29),  INT8_C(  15),  INT8_C(  74),  INT8_C(  64), -INT8_C(  78), -INT8_C(   5), -INT8_C(  24), -INT8_C( 126),  INT8_C( 116)
                , -INT8_C(  31),  INT8_C(  30), -INT8_C( 128), -INT8_C(  78), -INT8_C( 115),  INT8_C(  51), -INT8_C(  42), -INT8_C(  44),  INT8_C( 123),  INT8_C(  61), -INT8_C( 103),  INT8_C(  30),  INT8_C(  83),  INT8_C(  41), -INT8_C(  47),  INT8_C(  75)
                ,  INT8_C(  64),  INT8_C(  70), -INT8_C( 104),  INT8_C(  22), -INT8_C(  18), -INT8_C( 112), -INT8_C( 124), -INT8_C(  99),  INT8_C(  81),  INT8_C(  61), -INT8_C(  85),  INT8_C(  37),  INT8_C( 122), -INT8_C(  59),  INT8_C(  98), -INT8_C(  94) },
      /* b */ { INT8_C(  38),  INT8_C(  44), -INT8_C( 110),  INT8_C(  52),  INT8_C(  86), -INT8_C(  38), -INT8_C(  49),  INT8_C(  49), -INT8_C(   7),  INT8_C( 113), -INT8_C(   7),  INT8_C( 121), -INT8_C(  38), -INT8_C(  68),  INT8_C(  19), -INT8_C(  41)
                ,  INT8_C(  63),  INT8_C(  17), -INT8_C(  96),  INT8_C( 100), -INT8_C( 118),  INT8_C(  58), -INT8_C(  23), -INT8_C(  71),  INT8_C( 118),  INT8_C(  48), -INT8_C(  22),  INT8_C(  74), -INT8_C(  28), -INT8_C(  41),  INT8_C(  94),  INT8_C(  78)
                ,  INT8_C(  57), -INT8_C( 111), -INT8_C(  72), -INT8_C(  72), -INT8_C(   5), -INT8_C(  94),  INT8_C(  45),  INT8_C(  99),  INT8_C(   8),  INT8_C(   4), -INT8_C( 115),  INT8_C(  34), -INT8_C( 113), -INT8_C(  97), -INT8_C(  11),  INT8_C(  65)
                ,  INT8_C(  62),  INT8_C(  65), -INT8_C( 101), -INT8_C( 122),  INT8_C(  87), -INT8_C(  94), -INT8_C(  38), -INT8_C(  12),  INT8_C(  76), -INT8_C(  25), -INT8_C(  31),  INT8_C(  51),  INT8_C(   5), -INT8_C(  65), -INT8_C(  11), -INT8_C(  69)
                ,  INT8_C(  13),  INT8_C(  50), -INT8_C(  80),  INT8_C( 126), -INT8_C(  45), -INT8_C(  64), -INT8_C( 101), -INT8_C(  58),  INT8_C(  29), -INT8_C(   5),  INT8_C(  89), -INT8_C(  53), -INT8_C(  86),  INT8_C(  52), -INT8_C(  90), -INT8_C(  57)
                , -INT8_C(  94), -INT8_C(  92), -INT8_C(  21), -INT8_C(  75), -INT8_C(  68),  INT8_C(  43), -INT8_C(  59), -INT8_C(  61),  INT8_C(  33), -INT8_C(  99),  INT8_C(  64),  INT8_C(  45), -INT8_C(  76), -INT8_C(  73), -INT8_C(  31),  INT8_C(  16)
                ,  INT8_C(  97), -INT8_C(  60),  INT8_C(  68), -INT8_C(  48),  INT8_C( 113),  INT8_C(  94),  INT8_C( 115), -INT8_C(  37), -INT8_C(  22), -INT8_C(  70),  INT8_C(  45), -INT8_C(  99), -INT8_C(  28), -INT8_C(  51), -INT8_C(   5), -INT8_C(  37)
                ,  INT8_C( 116), -INT8_C(  98),  INT8_C(  21),  INT8_C( 113),  INT8_C( 121), -INT8_C( 109),  INT8_C( 117),  INT8_C(  60), -INT8_C( 113), -INT8_C( 102),  INT8_C(  53),  INT8_C( 114),  INT8_C(  25), -INT8_C(  78),  INT8_C(  55),  INT8_C( 101) },
      /* r */ {-INT8_C(  63),  INT8_C(  18),  INT8_C(  37), -INT8_C(  30), -INT8_C( 104), -INT8_C(  33),  INT8_C(  14), -INT8_C(  16), -INT8_C(  36), -INT8_C(  73), -INT8_C(  28), -INT8_C(  20),  INT8_C(  73),  INT8_C(  73), -INT8_C(  13),  INT8_C(  72)
                ,  INT8_C(  24),  INT8_C(  51),  INT8_C(  91), -INT8_C(  44),  INT8_C( 117), -INT8_C(  88), -INT8_C(  18), -INT8_C(  13), -INT8_C(  98), -INT8_C(   1),  INT8_C(  38), -INT8_C(  88), -INT8_C(  23),  INT8_C(  68), -INT8_C(  96), -INT8_C(  18)
                , -INT8_C(  49),  INT8_C(  42),  INT8_C(   3),  INT8_C(  74),  INT8_C(  18), -INT8_C(  15), -INT8_C(  84), -INT8_C(  53), -INT8_C(   4),  INT8_C(   9),  INT8_C(  29), -INT8_C(  24),  INT8_C(  54), -INT8_C(   6),  INT8_C(  13),  INT8_C(   6)
                , -INT8_C(  94), -INT8_C(  63),  INT8_C(  30),  INT8_C(  72), -INT8_C(  12),  INT8_C(  86),  INT8_C(  37), -INT8_C(  20), -INT8_C(  39),  INT8_C(  19),  INT8_C(  78),  INT8_C(   4),  INT8_C(  23),  INT8_C(  82), -INT8_C(   4), -INT8_C(  15)
                ,  INT8_C(  43), -INT8_C(  82), -INT8_C(  23), -INT8_C(  81),  INT8_C(  14),  INT8_C(  53),  INT8_C(  79),  INT8_C(  30),  INT8_C(   2),  INT8_C(  39), -INT8_C(  79),  INT8_C(  55),  INT8_C(  22), -INT8_C(  63), -INT8_C(   6),  INT8_C(  50)
                ,  INT8_C(  22),  INT8_C(  67), -INT8_C(  12),  INT8_C(  36),  INT8_C(  35),  INT8_C(  11), -INT8_C(  19),  INT8_C(  16), -INT8_C(   9),  INT8_C(  86),  INT8_C(   0), -INT8_C(  62),  INT8_C(  35),  INT8_C(  24), -INT8_C(  48),  INT8_C(  50)
                , -INT8_C(  64),  INT8_C(  45), -INT8_C(  98), -INT8_C(  15), -INT8_C( 114), -INT8_C(  22), -INT8_C(  79), -INT8_C(   4),  INT8_C(  72),  INT8_C(  65), -INT8_C(  74),  INT8_C(  64),  INT8_C(  55),  INT8_C(  46), -INT8_C(  21),  INT8_C(  56)
                , -INT8_C(  26),  INT8_C(  84), -INT8_C(  63), -INT8_C(  46), -INT8_C(  70), -INT8_C(   2), -INT8_C( 121), -INT8_C(  80),  INT8_C(  97),  INT8_C(  81), -INT8_C(  69), -INT8_C(  39),  INT8_C(  48),  INT8_C(   9),  INT8_C(  21), -INT8_C(  98) } },
    {      /* a */ {-INT8_C( 104),  INT8_C( 102),  INT8_C(  11),  INT8_C(  41),  INT8_C(  58),  INT8_C(  89), -INT8_C(  56), -INT8_C(  49), -INT8_C(  80),  INT8_C(  28), -INT8_C(  74), -INT8_C(  76),  INT8_C(  59),  INT8_C(   5), -INT8_C(  84), -INT8_C(  92)
                , -INT8_C(  18), -INT8_C(  29),  INT8_C(  91),  INT8_C(  75),  INT8_C(  46), -INT8_C(  40),  INT8_C(  11),  INT8_C(  18), -INT8_C(   7),  INT8_C(  27), -INT8_C(  86),  INT8_C(  92),  INT8_C(  73), -INT8_C( 126),  INT8_C(  69),  INT8_C(  22)
                ,  INT8_C(  65), -INT8_C(  72), -INT8_C(  90), -INT8_C(  96), -INT8_C(  70),  INT8_C( 117), -INT8_C(  89), -INT8_C(  86), -INT8_C(  64),  INT8_C( 112),  INT8_C(  53),  INT8_C(  17),  INT8_C( 102),  INT8_C(  92), -INT8_C(  78),  INT8_C(   7)
                , -INT8_C(  36),  INT8_C(  98),  INT8_C( 101),  INT8_C(   5), -INT8_C(  56),  INT8_C(  83), -INT8_C(  91), -INT8_C(  15),  INT8_C( 103),  INT8_C( 109),  INT8_C( 101),  INT8_C(  72), -INT8_C(  23), -INT8_C( 100), -INT8_C(  74),  INT8_C(  91)
                , -INT8_C(  70), -INT8_C(  94),  INT8_C(   3),  INT8_C(  25), -INT8_C(  66),  INT8_C(  32), -INT8_C( 117),  INT8_C(  18),  INT8_C( 113),  INT8_C( 106),  INT8_C(  54), -INT8_C( 111),  INT8_C(  20), -INT8_C(  85), -INT8_C(  89), -INT8_C(  91)
                , -INT8_C(  33),  INT8_C(  24),  INT8_C(  76),  INT8_C(  86), -INT8_C( 119), -INT8_C(  66),  INT8_C(  39), -INT8_C(  44), -INT8_C( 104), -INT8_C(  23), -INT8_C(  15),  INT8_C( 106),  INT8_C(   3),  INT8_C(   2), -INT8_C(  35),  INT8_C(  82)
                ,  INT8_C( 108), -INT8_C(  10), -INT8_C(  74),  INT8_C( 111),  INT8_C(   5), -INT8_C(  70),  INT8_C(  51),  INT8_C(  22),  INT8_C(  78), -INT8_C( 120),  INT8_C(  42), -INT8_C(   6),  INT8_C( 106),  INT8_C(  16), -INT8_C(  22),  INT8_C(  26)
                ,  INT8_C(  14),  INT8_C(  86), -INT8_C(  47),  INT8_C(  40), -INT8_C(   6), -INT8_C(  86), -INT8_C(  55),  INT8_C(  79), -INT8_C(  76),  INT8_C(  21),  INT8_C(  68), -INT8_C(  65),  INT8_C( 103), -INT8_C(  73),  INT8_C(  15),  INT8_C(   7) },
      /* b */ {-INT8_C(  40), -INT8_C(  66), -INT8_C(  92),  INT8_C( 104),  INT8_C(  75),  INT8_C(  27),  INT8_C(   6),  INT8_C(  86),  INT8_C(  74), -INT8_C( 100), -INT8_C(  54),  INT8_C(   7),  INT8_C(  51), -INT8_C(  29),  INT8_C(  34),  INT8_C(  93)
                , -INT8_C(   8),  INT8_C(  24), -INT8_C(  44),  INT8_C(  10),  INT8_C(  88),  INT8_C( 117), -INT8_C(  76),  INT8_C(  21), -INT8_C(  44), -INT8_C( 107), -INT8_C( 118),  INT8_C(  75),  INT8_C( 105), -INT8_C(  90), -INT8_C(  95), -INT8_C(  15)
                , -INT8_C(  42), -INT8_C(  64), -INT8_C( 113),  INT8_C(  83),  INT8_C(  41),  INT8_C(   6), -INT8_C(  48),  INT8_C( 101),  INT8_C(  74),  INT8_C( 123), -INT8_C(  83),  INT8_C(  17), -INT8_C(  77), -INT8_C(  74), -INT8_C( 101),  INT8_C(  24)
                , -INT8_C(  70), -INT8_C( 125), -INT8_C( 108),  INT8_C( 105),  INT8_C(  42), -INT8_C(  52), -INT8_C(  21), -INT8_C( 115), -INT8_C(  62), -INT8_C(  26), -INT8_C(  87),  INT8_C(  72),  INT8_C(  80), -INT8_C(  87),  INT8_C(  52),  INT8_C( 126)
                ,  INT8_C( 102),  INT8_C(  90),  INT8_C(   4), -INT8_C(  50),  INT8_C(  65),  INT8_C(  36), -INT8_C(  43), -INT8_C(  37), -INT8_C(  54), -INT8_C( 108), -INT8_C(  95),  INT8_C(  34), -INT8_C(  43),  INT8_C(  94),  INT8_C(  77),  INT8_C(  60)
                ,  INT8_C(   8), -INT8_C(  59), -INT8_C( 121),  INT8_C(  32), -INT8_C( 108), -INT8_C(  50), -INT8_C(  90), -INT8_C(  69),  INT8_C(  62), -INT8_C(  56), -INT8_C( 121), -INT8_C( 108),  INT8_C(  17),  INT8_C( 126),  INT8_C( 115),  INT8_C( 125)
                ,  INT8_C( 110),  INT8_C(  79),  INT8_C(  70), -INT8_C(  76),  INT8_C(  60), -INT8_C( 109),  INT8_C(  56),  INT8_C(  17), -INT8_C(  21), -INT8_C(  91), -INT8_C( 118),  INT8_C(  51), -INT8_C(  34),  INT8_C(  52), -INT8_C(  93),  INT8_C(  46)
                ,  INT8_C( 122), -INT8_C( 113),  INT8_C(  62), -INT8_C(  99),  INT8_C( 107),  INT8_C(  76), -INT8_C( 125),  INT8_C(  41), -INT8_C(  35), -INT8_C(   7),  INT8_C(  71), -INT8_C(  43),  INT8_C(  49),  INT8_C(  89), -INT8_C(  52), -INT8_C(  81) },
      /* r */ {-INT8_C(  32),  INT8_C(  84),  INT8_C(  51), -INT8_C(  32), -INT8_C(   9),  INT8_C(  31), -INT8_C(  31), -INT8_C(  68), -INT8_C(  77),  INT8_C(  64), -INT8_C(  10), -INT8_C(  42),  INT8_C(   4),  INT8_C(  17), -INT8_C(  59), -INT8_C(  93)
                , -INT8_C(   5), -INT8_C(  27),  INT8_C(  67),  INT8_C(  32), -INT8_C(  21), -INT8_C(  79),  INT8_C(  43), -INT8_C(   2),  INT8_C(  18),  INT8_C(  67),  INT8_C(  16),  INT8_C(   8), -INT8_C(  16), -INT8_C(  18),  INT8_C(  82),  INT8_C(  18)
                ,  INT8_C(  53), -INT8_C(   4),  INT8_C(  11), -INT8_C(  90), -INT8_C(  56),  INT8_C(  55), -INT8_C(  21), -INT8_C(  94), -INT8_C(  69), -INT8_C(   6),  INT8_C(  68),  INT8_C(   0),  INT8_C(  89),  INT8_C(  83),  INT8_C(  11), -INT8_C(   9)
                ,  INT8_C(  17),  INT8_C( 111),  INT8_C( 104), -INT8_C(  50), -INT8_C(  49),  INT8_C(  67), -INT8_C(  35),  INT8_C(  50),  INT8_C(  82),  INT8_C(  67),  INT8_C(  94),  INT8_C(   0), -INT8_C(  52), -INT8_C(   7), -INT8_C(  63), -INT8_C(  18)
                , -INT8_C(  86), -INT8_C(  92), -INT8_C(   1),  INT8_C(  37), -INT8_C(  66), -INT8_C(   2), -INT8_C(  37),  INT8_C(  27),  INT8_C(  83),  INT8_C( 107),  INT8_C(  74), -INT8_C(  73),  INT8_C(  31), -INT8_C(  90), -INT8_C(  83), -INT8_C(  76)
                , -INT8_C(  21),  INT8_C(  41),  INT8_C(  98),  INT8_C(  27), -INT8_C(   6), -INT8_C(   8),  INT8_C(  64),  INT8_C(  12), -INT8_C(  83),  INT8_C(  16),  INT8_C(  53),  INT8_C( 107), -INT8_C(   7), -INT8_C(  62), -INT8_C(  75), -INT8_C(  22)
                , -INT8_C(   1), -INT8_C(  45), -INT8_C(  72),  INT8_C(  93), -INT8_C(  28),  INT8_C(  19), -INT8_C(   3),  INT8_C(   2),  INT8_C(  49), -INT8_C(  15),  INT8_C(  80), -INT8_C(  29),  INT8_C(  70), -INT8_C(  18),  INT8_C(  35), -INT8_C(  10)
                , -INT8_C(  54),  INT8_C(  99), -INT8_C(  55),  INT8_C(  69), -INT8_C(  57), -INT8_C(  81),  INT8_C(  35),  INT8_C(  19), -INT8_C(  21),  INT8_C(  14), -INT8_C(   2), -INT8_C(  11),  INT8_C(  27), -INT8_C(  81),  INT8_C(  33),  INT8_C(  44) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vb_vnavg_VbVb(a, b);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vnavg_VubVub(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a[128]; uint8_t b[128]; int8_t r[128];
  } test_vec[] = {
    {      /* a */ {UINT8_C(117), UINT8_C(135), UINT8_C(123), UINT8_C( 46), UINT8_C(227), UINT8_C( 60), UINT8_C(112), UINT8_C( 23), UINT8_C(110), UINT8_C(119), UINT8_C(151), UINT8_C( 23), UINT8_C(246), UINT8_C( 36), UINT8_C(129), UINT8_C(110)
                , UINT8_C(110), UINT8_C(193), UINT8_C( 82), UINT8_C(127), UINT8_C( 98), UINT8_C(113), UINT8_C( 76), UINT8_C( 38), UINT8_C(212), UINT8_C(135), UINT8_C( 47), UINT8_C(  2), UINT8_C(146), UINT8_C(244), UINT8_C(  6), UINT8_C(184)
                , UINT8_C( 98), UINT8_C(117), UINT8_C(171), UINT8_C(145), UINT8_C( 53), UINT8_C(161), UINT8_C(163), UINT8_C(140), UINT8_C(136), UINT8_C(244), UINT8_C( 15), UINT8_C(166), UINT8_C(165), UINT8_C(133), UINT8_C( 54), UINT8_C( 33)
                , UINT8_C(192), UINT8_C( 31), UINT8_C(185), UINT8_C(135), UINT8_C(113), UINT8_C(141), UINT8_C(171), UINT8_C(194), UINT8_C(245), UINT8_C( 47), UINT8_C( 49), UINT8_C( 78), UINT8_C(124), UINT8_C(180), UINT8_C( 95), UINT8_C(178)
                , UINT8_C(255), UINT8_C(126), UINT8_C( 72), UINT8_C(  6), UINT8_C(191), UINT8_C( 69), UINT8_C(188), UINT8_C( 54), UINT8_C( 80), UINT8_C(179), UINT8_C(249), UINT8_C( 12), UINT8_C( 54), UINT8_C(191), UINT8_C( 48), UINT8_C(194)
                , UINT8_C( 99), UINT8_C(169), UINT8_C(245), UINT8_C(194), UINT8_C(150), UINT8_C(181), UINT8_C(191), UINT8_C( 80), UINT8_C(145), UINT8_C(255), UINT8_C( 92), UINT8_C(221), UINT8_C(  3), UINT8_C(249), UINT8_C( 96), UINT8_C( 67)
                , UINT8_C(191), UINT8_C(187), UINT8_C(208), UINT8_C(130), UINT8_C(250), UINT8_C(240), UINT8_C(212), UINT8_C( 12), UINT8_C(162), UINT8_C( 94), UINT8_C( 50), UINT8_C(246), UINT8_C( 41), UINT8_C(235), UINT8_C( 25), UINT8_C(211)
                , UINT8_C(227), UINT8_C(213), UINT8_C(237), UINT8_C( 37), UINT8_C(181), UINT8_C(102), UINT8_C(193), UINT8_C( 35), UINT8_C(202), UINT8_C(221), UINT8_C( 99), UINT8_C( 27), UINT8_C(240), UINT8_C( 97), UINT8_C(121), UINT8_C(168) },
      /* b */ {UINT8_C( 49), UINT8_C(111), UINT8_C(166), UINT8_C( 54), UINT8_C(120), UINT8_C( 25), UINT8_C(177), UINT8_C( 60), UINT8_C(184), UINT8_C( 25), UINT8_C(184), UINT8_C( 89), UINT8_C( 52), UINT8_C(205), UINT8_C(120), UINT8_C(209)
                , UINT8_C(176), UINT8_C( 76), UINT8_C(184), UINT8_C(149), UINT8_C( 18), UINT8_C(222), UINT8_C(132), UINT8_C(175), UINT8_C( 80), UINT8_C( 55), UINT8_C(204), UINT8_C( 77), UINT8_C( 54), UINT8_C(102), UINT8_C(196), UINT8_C(127)
                , UINT8_C(157), UINT8_C(239), UINT8_C(201), UINT8_C( 88), UINT8_C(178), UINT8_C( 63), UINT8_C(209), UINT8_C(203), UINT8_C( 65), UINT8_C(154), UINT8_C( 92), UINT8_C(138), UINT8_C(124), UINT8_C(167), UINT8_C(  9), UINT8_C(172)
                , UINT8_C( 75), UINT8_C(  0), UINT8_C( 24), UINT8_C(100), UINT8_C(215), UINT8_C( 32), UINT8_C(134), UINT8_C(203), UINT8_C(246), UINT8_C( 15), UINT8_C( 38), UINT8_C(227), UINT8_C( 95), UINT8_C(239), UINT8_C(253), UINT8_C( 79)
                , UINT8_C(248), UINT8_C(146), UINT8_C(151), UINT8_C(234), UINT8_C(161), UINT8_C(157), UINT8_C(  1), UINT8_C(226), UINT8_C(127), UINT8_C(155), UINT8_C(107), UINT8_C(142), UINT8_C(182), UINT8_C(182), UINT8_C(253), UINT8_C(222)
                , UINT8_C(163), UINT8_C( 26), UINT8_C( 82), UINT8_C(145), UINT8_C(249), UINT8_C( 25), UINT8_C( 73), UINT8_C(247), UINT8_C(  4), UINT8_C( 82), UINT8_C(125), UINT8_C(160), UINT8_C(156), UINT8_C(244), UINT8_C( 26), UINT8_C(101)
                , UINT8_C(120), UINT8_C( 12), UINT8_C( 16), UINT8_C(213), UINT8_C( 78), UINT8_C( 19), UINT8_C(245), UINT8_C(176), UINT8_C(193), UINT8_C( 75), UINT8_C(184), UINT8_C( 45), UINT8_C(223), UINT8_C( 73), UINT8_C( 79), UINT8_C(210)
                , UINT8_C( 83), UINT8_C(224), UINT8_C( 79), UINT8_C(154), UINT8_C(105), UINT8_C( 79), UINT8_C( 66), UINT8_C( 93), UINT8_C( 31), UINT8_C( 26), UINT8_C(124), UINT8_C( 73), UINT8_C(109), UINT8_C( 71), UINT8_C(198), UINT8_C(190) },
      /* r */ { INT8_C(  34),  INT8_C(  12), -INT8_C(  22), -INT8_C(   4),  INT8_C(  53),  INT8_C(  17), -INT8_C(  33), -INT8_C(  19), -INT8_C(  37),  INT8_C(  47), -INT8_C(  17), -INT8_C(  33),  INT8_C(  97), -INT8_C(  85),  INT8_C(   4), -INT8_C(  50)
                , -INT8_C(  33),  INT8_C(  58), -INT8_C(  51), -INT8_C(  11),  INT8_C(  40), -INT8_C(  55), -INT8_C(  28), -INT8_C(  69),  INT8_C(  66),  INT8_C(  40), -INT8_C(  79), -INT8_C(  38),  INT8_C(  46),  INT8_C(  71), -INT8_C(  95),  INT8_C(  28)
                , -INT8_C(  30), -INT8_C(  61), -INT8_C(  15),  INT8_C(  28), -INT8_C(  63),  INT8_C(  49), -INT8_C(  23), -INT8_C(  32),  INT8_C(  35),  INT8_C(  45), -INT8_C(  39),  INT8_C(  14),  INT8_C(  20), -INT8_C(  17),  INT8_C(  22), -INT8_C(  70)
                ,  INT8_C(  58),  INT8_C(  15),  INT8_C(  80),  INT8_C(  17), -INT8_C(  51),  INT8_C(  54),  INT8_C(  18), -INT8_C(   5), -INT8_C(   1),  INT8_C(  16),  INT8_C(   5), -INT8_C(  75),  INT8_C(  14), -INT8_C(  30), -INT8_C(  79),  INT8_C(  49)
                ,  INT8_C(   3), -INT8_C(  10), -INT8_C(  40), -INT8_C( 114),  INT8_C(  15), -INT8_C(  44),  INT8_C(  93), -INT8_C(  86), -INT8_C(  24),  INT8_C(  12),  INT8_C(  71), -INT8_C(  65), -INT8_C(  64),  INT8_C(   4), -INT8_C( 103), -INT8_C(  14)
                , -INT8_C(  32),  INT8_C(  71),  INT8_C(  81),  INT8_C(  24), -INT8_C(  50),  INT8_C(  78),  INT8_C(  59), -INT8_C(  84),  INT8_C(  70),  INT8_C(  86), -INT8_C(  17),  INT8_C(  30), -INT8_C(  77),  INT8_C(   2),  INT8_C(  35), -INT8_C(  17)
                ,  INT8_C(  35),  INT8_C(  87),  INT8_C(  96), -INT8_C(  42),  INT8_C(  86),  INT8_C( 110), -INT8_C(  17), -INT8_C(  82), -INT8_C(  16),  INT8_C(   9), -INT8_C(  67),  INT8_C( 100), -INT8_C(  91),  INT8_C(  81), -INT8_C(  27),  INT8_C(   0)
                ,  INT8_C(  72), -INT8_C(   6),  INT8_C(  79), -INT8_C(  59),  INT8_C(  38),  INT8_C(  11),  INT8_C(  63), -INT8_C(  29),  INT8_C(  85),  INT8_C(  97), -INT8_C(  13), -INT8_C(  23),  INT8_C(  65),  INT8_C(  13), -INT8_C(  39), -INT8_C(  11) } },
    {      /* a */ {UINT8_C( 72), UINT8_C( 52), UINT8_C(236), UINT8_C(200), UINT8_C( 63), UINT8_C(228), UINT8_C(179), UINT8_C(250), UINT8_C(116), UINT8_C( 77), UINT8_C(111), UINT8_C(216), UINT8_C(169), UINT8_C( 93), UINT8_C(183), UINT8_C(100)
                , UINT8_C(184), UINT8_C(123), UINT8_C( 63), UINT8_C(211), UINT8_C(226), UINT8_C( 40), UINT8_C( 62), UINT8_C( 34), UINT8_C(170), UINT8_C( 50), UINT8_C( 58), UINT8_C(255), UINT8_C(159), UINT8_C( 98), UINT8_C(188), UINT8_C(  9)
                , UINT8_C( 56), UINT8_C(101), UINT8_C(134), UINT8_C( 20), UINT8_C( 77), UINT8_C(  4), UINT8_C(203), UINT8_C(203), UINT8_C(174), UINT8_C( 26), UINT8_C( 43), UINT8_C( 57), UINT8_C(241), UINT8_C(190), UINT8_C( 76), UINT8_C(186)
                , UINT8_C(191), UINT8_C( 66), UINT8_C(106), UINT8_C(122), UINT8_C(152), UINT8_C(173), UINT8_C(140), UINT8_C(224), UINT8_C( 52), UINT8_C(201), UINT8_C( 34), UINT8_C(224), UINT8_C(186), UINT8_C( 20), UINT8_C( 34), UINT8_C( 36)
                , UINT8_C(120), UINT8_C( 41), UINT8_C(207), UINT8_C(186), UINT8_C(244), UINT8_C( 32), UINT8_C(106), UINT8_C(110), UINT8_C(105), UINT8_C( 80), UINT8_C( 91), UINT8_C(216), UINT8_C(183), UINT8_C(138), UINT8_C(154), UINT8_C(197)
                , UINT8_C(116), UINT8_C( 23), UINT8_C(133), UINT8_C( 86), UINT8_C(198), UINT8_C( 71), UINT8_C( 18), UINT8_C(203), UINT8_C(213), UINT8_C(  1), UINT8_C( 99), UINT8_C( 32), UINT8_C( 96), UINT8_C( 18), UINT8_C(240), UINT8_C( 11)
                , UINT8_C( 88), UINT8_C(237), UINT8_C( 19), UINT8_C( 66), UINT8_C(188), UINT8_C(156), UINT8_C(197), UINT8_C( 50), UINT8_C( 13), UINT8_C(207), UINT8_C(  4), UINT8_C(186), UINT8_C(106), UINT8_C(211), UINT8_C( 10), UINT8_C(237)
                , UINT8_C(  0), UINT8_C( 88), UINT8_C( 80), UINT8_C( 19), UINT8_C( 79), UINT8_C( 88), UINT8_C( 23), UINT8_C(206), UINT8_C(247), UINT8_C( 43), UINT8_C( 95), UINT8_C(228), UINT8_C( 61), UINT8_C(170), UINT8_C( 49), UINT8_C( 23) },
      /* b */ {UINT8_C(185), UINT8_C(117), UINT8_C( 33), UINT8_C(214), UINT8_C(117), UINT8_C( 42), UINT8_C(252), UINT8_C(244), UINT8_C(129), UINT8_C( 86), UINT8_C(158), UINT8_C(209), UINT8_C(153), UINT8_C(197), UINT8_C( 48), UINT8_C(151)
                , UINT8_C(199), UINT8_C( 51), UINT8_C( 14), UINT8_C(135), UINT8_C(184), UINT8_C(111), UINT8_C( 14), UINT8_C( 10), UINT8_C(254), UINT8_C( 75), UINT8_C(205), UINT8_C( 16), UINT8_C(239), UINT8_C(149), UINT8_C(  6), UINT8_C(140)
                , UINT8_C(217), UINT8_C( 31), UINT8_C(209), UINT8_C(  9), UINT8_C(121), UINT8_C(136), UINT8_C( 71), UINT8_C( 16), UINT8_C(106), UINT8_C(154), UINT8_C(139), UINT8_C(245), UINT8_C(252), UINT8_C( 46), UINT8_C(106), UINT8_C(242)
                , UINT8_C( 62), UINT8_C(207), UINT8_C(137), UINT8_C( 33), UINT8_C( 23), UINT8_C( 37), UINT8_C(  2), UINT8_C(251), UINT8_C(134), UINT8_C(170), UINT8_C( 82), UINT8_C( 19), UINT8_C(143), UINT8_C( 50), UINT8_C( 22), UINT8_C(100)
                , UINT8_C(201), UINT8_C(208), UINT8_C( 85), UINT8_C(100), UINT8_C(132), UINT8_C(166), UINT8_C(237), UINT8_C(197), UINT8_C( 96), UINT8_C(118), UINT8_C(100), UINT8_C(211), UINT8_C( 72), UINT8_C(175), UINT8_C(119), UINT8_C(217)
                , UINT8_C( 39), UINT8_C( 53), UINT8_C(107), UINT8_C(235), UINT8_C(222), UINT8_C(154), UINT8_C(175), UINT8_C(162), UINT8_C( 78), UINT8_C( 25), UINT8_C(115), UINT8_C( 59), UINT8_C(216), UINT8_C(247), UINT8_C(251), UINT8_C( 54)
                , UINT8_C( 13), UINT8_C(228), UINT8_C( 86), UINT8_C(  3), UINT8_C( 15), UINT8_C( 30), UINT8_C(133), UINT8_C(191), UINT8_C( 81), UINT8_C(180), UINT8_C( 38), UINT8_C(189), UINT8_C( 34), UINT8_C(122), UINT8_C(174), UINT8_C(178)
                , UINT8_C(252), UINT8_C( 30), UINT8_C(223), UINT8_C(226), UINT8_C(206), UINT8_C(175), UINT8_C(145), UINT8_C(159), UINT8_C( 28), UINT8_C(250), UINT8_C( 97), UINT8_C(250), UINT8_C(143), UINT8_C(207), UINT8_C(126), UINT8_C(188) },
      /* r */ {-INT8_C(  57), -INT8_C(  33),  INT8_C( 101), -INT8_C(   7), -INT8_C(  27),  INT8_C(  93), -INT8_C(  37),  INT8_C(   3), -INT8_C(   7), -INT8_C(   5), -INT8_C(  24),  INT8_C(   3),  INT8_C(   8), -INT8_C(  52),  INT8_C(  67), -INT8_C(  26)
                , -INT8_C(   8),  INT8_C(  36),  INT8_C(  24),  INT8_C(  38),  INT8_C(  21), -INT8_C(  36),  INT8_C(  24),  INT8_C(  12), -INT8_C(  42), -INT8_C(  13), -INT8_C(  74),  INT8_C( 119), -INT8_C(  40), -INT8_C(  26),  INT8_C(  91), -INT8_C(  66)
                , -INT8_C(  81),  INT8_C(  35), -INT8_C(  38),  INT8_C(   5), -INT8_C(  22), -INT8_C(  66),  INT8_C(  66),  INT8_C(  93),  INT8_C(  34), -INT8_C(  64), -INT8_C(  48), -INT8_C(  94), -INT8_C(   6),  INT8_C(  72), -INT8_C(  15), -INT8_C(  28)
                ,  INT8_C(  64), -INT8_C(  71), -INT8_C(  16),  INT8_C(  44),  INT8_C(  64),  INT8_C(  68),  INT8_C(  69), -INT8_C(  14), -INT8_C(  41),  INT8_C(  15), -INT8_C(  24),  INT8_C( 102),  INT8_C(  21), -INT8_C(  15),  INT8_C(   6), -INT8_C(  32)
                , -INT8_C(  41), -INT8_C(  84),  INT8_C(  61),  INT8_C(  43),  INT8_C(  56), -INT8_C(  67), -INT8_C(  66), -INT8_C(  44),  INT8_C(   4), -INT8_C(  19), -INT8_C(   5),  INT8_C(   2),  INT8_C(  55), -INT8_C(  19),  INT8_C(  17), -INT8_C(  10)
                ,  INT8_C(  38), -INT8_C(  15),  INT8_C(  13), -INT8_C(  75), -INT8_C(  12), -INT8_C(  42), -INT8_C(  79),  INT8_C(  20),  INT8_C(  67), -INT8_C(  12), -INT8_C(   8), -INT8_C(  14), -INT8_C(  60), -INT8_C( 115), -INT8_C(   6), -INT8_C(  22)
                ,  INT8_C(  37),  INT8_C(   4), -INT8_C(  34),  INT8_C(  31),  INT8_C(  86),  INT8_C(  63),  INT8_C(  32), -INT8_C(  71), -INT8_C(  34),  INT8_C(  13), -INT8_C(  17), -INT8_C(   2),  INT8_C(  36),  INT8_C(  44), -INT8_C(  82),  INT8_C(  29)
                , -INT8_C( 126),  INT8_C(  29), -INT8_C(  72), -INT8_C( 104), -INT8_C(  64), -INT8_C(  44), -INT8_C(  61),  INT8_C(  23),  INT8_C( 109), -INT8_C( 104), -INT8_C(   1), -INT8_C(  11), -INT8_C(  41), -INT8_C(  19), -INT8_C(  39), -INT8_C(  83) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vb_vnavg_VubVub(a, b);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vnavg_VhVh(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[64]; int16_t b[64]; int16_t r[64];
  } test_vec[] = {
    {      /* a */ {-INT16_C(   414),  INT16_C( 10197), -INT16_C( 22487), -INT16_C(  2666), -INT16_C(    50),  INT16_C(  5798), -INT16_C(  2216), -INT16_C(  2195)
                , -INT16_C(  9256), -INT16_C( 28576), -INT16_C( 11928), -INT16_C( 10921), -INT16_C(  9697), -INT16_C( 26314), -INT16_C( 14036), -INT16_C(  9463)
                , -INT16_C( 25597),  INT16_C(  8101),  INT16_C( 23070),  INT16_C(  6719), -INT16_C(  7830),  INT16_C( 32133),  INT16_C( 28098), -INT16_C( 15669)
                ,  INT16_C(  8677),  INT16_C( 21511),  INT16_C( 27609), -INT16_C( 13427),  INT16_C( 18457),  INT16_C( 15482), -INT16_C( 25461),  INT16_C(  1015)
                ,  INT16_C( 18452), -INT16_C(  2090),  INT16_C(  3289), -INT16_C(  6063),  INT16_C( 20703),  INT16_C( 16570),  INT16_C( 32220),  INT16_C( 32688)
                ,  INT16_C(  8808), -INT16_C( 17691),  INT16_C(   548), -INT16_C( 18611),  INT16_C( 16660),  INT16_C( 16696), -INT16_C( 14765),  INT16_C( 11277)
                ,  INT16_C( 14721),  INT16_C( 29797), -INT16_C(  2580), -INT16_C( 12977), -INT16_C( 30694),  INT16_C(  2760),  INT16_C( 25629), -INT16_C(  6349)
                ,  INT16_C( 18292),  INT16_C( 30183),  INT16_C(  3630),  INT16_C(  1974),  INT16_C( 22417),  INT16_C(  3576), -INT16_C(  5502),  INT16_C(  6931) },
      /* b */ {-INT16_C( 21657),  INT16_C( 16802),  INT16_C(  6315), -INT16_C( 11103), -INT16_C( 28651), -INT16_C( 13470),  INT16_C( 20015),  INT16_C(  1350)
                ,  INT16_C( 13670),  INT16_C( 31280),  INT16_C( 26679),  INT16_C( 12388), -INT16_C( 24316), -INT16_C( 17486), -INT16_C( 12593),  INT16_C( 12305)
                ,  INT16_C(  3893), -INT16_C(  2978), -INT16_C( 25772), -INT16_C( 27832), -INT16_C( 30565), -INT16_C( 12480),  INT16_C( 25003),  INT16_C( 29408)
                , -INT16_C( 24600), -INT16_C( 13739), -INT16_C(  5454),  INT16_C( 12123),  INT16_C( 25100), -INT16_C( 26377), -INT16_C( 23039), -INT16_C(  5242)
                , -INT16_C(  9665),  INT16_C( 15771),  INT16_C(  8474), -INT16_C( 21529), -INT16_C( 15814), -INT16_C( 32162),  INT16_C( 31317), -INT16_C(  4750)
                , -INT16_C(  5637), -INT16_C( 23186),  INT16_C( 14800),  INT16_C(   261),  INT16_C(   557), -INT16_C( 28865),  INT16_C( 18576), -INT16_C(  3796)
                ,  INT16_C(  7758), -INT16_C(  4743), -INT16_C( 20249),  INT16_C(  6440),  INT16_C( 10703), -INT16_C( 12891),  INT16_C( 12663), -INT16_C( 16818)
                , -INT16_C( 31748), -INT16_C(  1769), -INT16_C(  7596),  INT16_C( 26276),  INT16_C( 15401), -INT16_C( 20479), -INT16_C( 20593),  INT16_C( 13499) },
      /* r */ { INT16_C( 10621), -INT16_C(  3303), -INT16_C( 14401),  INT16_C(  4218),  INT16_C( 14300),  INT16_C(  9634), -INT16_C( 11116), -INT16_C(  1773)
                , -INT16_C( 11463), -INT16_C( 29928), -INT16_C( 19304), -INT16_C( 11655),  INT16_C(  7309), -INT16_C(  4414), -INT16_C(   722), -INT16_C( 10884)
                , -INT16_C( 14745),  INT16_C(  5539),  INT16_C( 24421),  INT16_C( 17275),  INT16_C( 11367),  INT16_C( 22306),  INT16_C(  1547), -INT16_C( 22539)
                ,  INT16_C( 16638),  INT16_C( 17625),  INT16_C( 16531), -INT16_C( 12775), -INT16_C(  3322),  INT16_C( 20929), -INT16_C(  1211),  INT16_C(  3128)
                ,  INT16_C( 14058), -INT16_C(  8931), -INT16_C(  2593),  INT16_C(  7733),  INT16_C( 18258),  INT16_C( 24366),  INT16_C(   451),  INT16_C( 18719)
                ,  INT16_C(  7222),  INT16_C(  2747), -INT16_C(  7126), -INT16_C(  9436),  INT16_C(  8051),  INT16_C( 22780), -INT16_C( 16671),  INT16_C(  7536)
                ,  INT16_C(  3481),  INT16_C( 17270),  INT16_C(  8834), -INT16_C(  9709), -INT16_C( 20699),  INT16_C(  7825),  INT16_C(  6483),  INT16_C(  5234)
                ,  INT16_C( 25020),  INT16_C( 15976),  INT16_C(  5613), -INT16_C( 12151),  INT16_C(  3508),  INT16_C( 12027),  INT16_C(  7545), -INT16_C(  3284) } },
    {      /* a */ { INT16_C(  7268),  INT16_C( 31369),  INT16_C( 18600), -INT16_C( 18027), -INT16_C(  6803), -INT16_C(  4950),  INT16_C( 11627),  INT16_C( 17123)
                ,  INT16_C( 13028),  INT16_C( 32320),  INT16_C( 13797), -INT16_C( 10872), -INT16_C( 18873),  INT16_C( 18588), -INT16_C(  4014), -INT16_C( 11706)
                , -INT16_C( 12439),  INT16_C( 19501), -INT16_C(  4984), -INT16_C( 17764),  INT16_C( 17697),  INT16_C( 20159), -INT16_C(  8696), -INT16_C( 13980)
                ,  INT16_C( 22916),  INT16_C(  7143),  INT16_C(   582), -INT16_C( 24253), -INT16_C( 28278),  INT16_C(  2792), -INT16_C(  3636), -INT16_C( 15798)
                ,  INT16_C( 31996), -INT16_C( 27870), -INT16_C( 29970), -INT16_C( 27583), -INT16_C( 10832),  INT16_C( 24964),  INT16_C( 27382),  INT16_C(  9549)
                , -INT16_C( 17801),  INT16_C(  6597),  INT16_C(  3028),  INT16_C(  4413),  INT16_C( 25029),  INT16_C( 19063), -INT16_C( 11186),  INT16_C(  6808)
                ,  INT16_C(   185), -INT16_C(  1580), -INT16_C( 27553),  INT16_C( 26821), -INT16_C(  8531), -INT16_C( 18404), -INT16_C( 23062),  INT16_C( 27804)
                ,  INT16_C( 23631),  INT16_C( 10604), -INT16_C( 17136),  INT16_C(  4125),  INT16_C(  7621),  INT16_C( 10051),  INT16_C( 13804),  INT16_C( 23770) },
      /* b */ {-INT16_C( 23834), -INT16_C( 26533),  INT16_C(  8139),  INT16_C( 29250),  INT16_C( 27840),  INT16_C(  5082), -INT16_C( 15448), -INT16_C( 18530)
                , -INT16_C(  8068),  INT16_C(  1462),  INT16_C( 21798),  INT16_C( 21358), -INT16_C( 27581), -INT16_C( 14656),  INT16_C( 22295), -INT16_C( 10352)
                ,  INT16_C( 28609),  INT16_C(  1887), -INT16_C( 25634),  INT16_C( 12460), -INT16_C( 21679),  INT16_C( 18357), -INT16_C( 12301),  INT16_C( 20106)
                , -INT16_C( 11085),  INT16_C( 15939),  INT16_C(  2324),  INT16_C(  2515),  INT16_C( 14661),  INT16_C(  8771), -INT16_C( 22451),  INT16_C( 22038)
                , -INT16_C( 23370),  INT16_C( 19159), -INT16_C( 26250), -INT16_C( 14824),  INT16_C( 30824), -INT16_C(  4413), -INT16_C( 14302),  INT16_C( 17835)
                ,  INT16_C(  5327),  INT16_C( 24653),  INT16_C(  3125), -INT16_C( 30244),  INT16_C( 31382), -INT16_C( 32699),  INT16_C( 20179),  INT16_C(  2047)
                , -INT16_C(  7368), -INT16_C( 19578),  INT16_C( 30181), -INT16_C(  5146), -INT16_C( 14176), -INT16_C( 21147), -INT16_C( 32053),  INT16_C( 25955)
                , -INT16_C( 23337), -INT16_C( 28242),  INT16_C(  9499),  INT16_C(  2003),  INT16_C( 21198), -INT16_C( 19644), -INT16_C( 23009),  INT16_C( 25745) },
      /* r */ { INT16_C( 15551),  INT16_C( 28951),  INT16_C(  5230), -INT16_C( 23639), -INT16_C( 17322), -INT16_C(  5016),  INT16_C( 13537),  INT16_C( 17826)
                ,  INT16_C( 10548),  INT16_C( 15429), -INT16_C(  4001), -INT16_C( 16115),  INT16_C(  4354),  INT16_C( 16622), -INT16_C( 13155), -INT16_C(   677)
                , -INT16_C( 20524),  INT16_C(  8807),  INT16_C( 10325), -INT16_C( 15112),  INT16_C( 19688),  INT16_C(   901),  INT16_C(  1802), -INT16_C( 17043)
                ,  INT16_C( 17000), -INT16_C(  4398), -INT16_C(   871), -INT16_C( 13384), -INT16_C( 21470), -INT16_C(  2990),  INT16_C(  9407), -INT16_C( 18918)
                ,  INT16_C( 27683), -INT16_C( 23515), -INT16_C(  1860), -INT16_C(  6380), -INT16_C( 20828),  INT16_C( 14688),  INT16_C( 20842), -INT16_C(  4143)
                , -INT16_C( 11564), -INT16_C(  9028), -INT16_C(    49),  INT16_C( 17328), -INT16_C(  3177),  INT16_C( 25881), -INT16_C( 15683),  INT16_C(  2380)
                ,  INT16_C(  3776),  INT16_C(  8999), -INT16_C( 28867),  INT16_C( 15983),  INT16_C(  2822),  INT16_C(  1371),  INT16_C(  4495),  INT16_C(   924)
                ,  INT16_C( 23484),  INT16_C( 19423), -INT16_C( 13318),  INT16_C(  1061), -INT16_C(  6789),  INT16_C( 14847),  INT16_C( 18406), -INT16_C(   988) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vnavg_VhVh(a, b);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vnavg_VwVw(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[32]; int32_t b[32]; int32_t r[32];
  } test_vec[] = {
    {      /* a */ {-INT32_C( 1635578443),  INT32_C( 1008352592), -INT32_C(   46131793),  INT32_C( 1275568732)
                , -INT32_C( 1229038370),  INT32_C( 1761482053), -INT32_C(  794992094), -INT32_C( 1664748425)
                , -INT32_C(  786217483), -INT32_C(  784367751),  INT32_C(  878880462),  INT32_C( 1903658919)
                , -INT32_C(  473625686), -INT32_C( 1325642713), -INT32_C( 1530674276),  INT32_C( 2109467485)
                , -INT32_C( 1514365908),  INT32_C(  688531685),  INT32_C( 1151358188), -INT32_C( 1115509804)
                ,  INT32_C( 1594291995), -INT32_C(  580638555),  INT32_C( 1928781399), -INT32_C( 2147483307)
                , -INT32_C( 1215102098), -INT32_C( 1925262673), -INT32_C( 2067024594),  INT32_C(  627558802)
                , -INT32_C( 1539877509),  INT32_C(  412459404), -INT32_C( 1037492922), -INT32_C(  471742978) },
      /* b */ { INT32_C(  336801868),  INT32_C( 1158473289),  INT32_C(  481609820), -INT32_C(  732911276)
                , -INT32_C(  566399127),  INT32_C(  324974172), -INT32_C(  679415485),  INT32_C(  421603976)
                ,  INT32_C( 1043082090),  INT32_C(    9459710), -INT32_C( 1359174358), -INT32_C( 2013846565)
                , -INT32_C( 1276140434), -INT32_C( 1833213012), -INT32_C( 1115835434), -INT32_C( 1976130504)
                ,  INT32_C(  993465880),  INT32_C(  137633874),  INT32_C( 1356456895), -INT32_C(  253940863)
                , -INT32_C(  385903694),  INT32_C( 1856387129), -INT32_C(  153794806), -INT32_C(  335509119)
                , -INT32_C(  153602713), -INT32_C(  532403190), -INT32_C(  337861803),  INT32_C( 1024619602)
                ,  INT32_C(  338030466),  INT32_C( 2077015093),  INT32_C( 1028703529), -INT32_C( 1699879564) },
      /* r */ {-INT32_C(  986190156), -INT32_C(   75060349), -INT32_C(  263870807),  INT32_C( 1004240004)
                , -INT32_C(  331319622),  INT32_C(  718253940), -INT32_C(   57788305), -INT32_C( 1043176201)
                , -INT32_C(  914649787), -INT32_C(  396913731),  INT32_C( 1119027410),  INT32_C( 1958752742)
                ,  INT32_C(  401257374),  INT32_C(  253785149), -INT32_C(  207419421),  INT32_C( 2042798994)
                , -INT32_C( 1253915894),  INT32_C(  275448905), -INT32_C(  102549354), -INT32_C(  430784471)
                ,  INT32_C(  990097844), -INT32_C( 1218512842),  INT32_C( 1041288102), -INT32_C(  905987094)
                , -INT32_C(  530749693), -INT32_C(  696429742), -INT32_C(  864581396), -INT32_C(  198530400)
                , -INT32_C(  938953988), -INT32_C(  832277845), -INT32_C( 1033098226),  INT32_C(  614068293) } },
    {      /* a */ {-INT32_C(  635321608), -INT32_C( 1822883980), -INT32_C(   96618458),  INT32_C( 1435945294)
                ,  INT32_C(  546409998), -INT32_C(  698094895),  INT32_C( 1146232181), -INT32_C(   56032793)
                , -INT32_C(  925638945),  INT32_C( 1154542854), -INT32_C( 2037610906),  INT32_C( 2123476598)
                , -INT32_C(  837416693), -INT32_C( 1455607552), -INT32_C( 1441508414), -INT32_C( 1835593072)
                ,  INT32_C( 1079687046),  INT32_C( 1383015880), -INT32_C(  906678779), -INT32_C(  352122423)
                ,  INT32_C(  903821344), -INT32_C( 1449695441),  INT32_C(  102249229),  INT32_C( 1708397098)
                ,  INT32_C( 1003351733), -INT32_C( 2121470535), -INT32_C(  917418987),  INT32_C( 1400217751)
                ,  INT32_C( 1139636089),  INT32_C(  969683562),  INT32_C(  605541849), -INT32_C( 2111291878) },
      /* b */ { INT32_C(  250687186), -INT32_C( 2095671763),  INT32_C( 1254960416), -INT32_C( 2138851821)
                ,  INT32_C( 1573673888), -INT32_C(  857323342), -INT32_C( 1054170043), -INT32_C(  641119308)
                ,  INT32_C(  854445530), -INT32_C( 2051452604),  INT32_C(  419378530), -INT32_C( 2095869392)
                ,  INT32_C(  642043381),  INT32_C(  900440630),  INT32_C( 1170153741),  INT32_C(  124978389)
                , -INT32_C( 1182556931), -INT32_C(  394442917),  INT32_C(  635474472),  INT32_C( 1537022269)
                ,  INT32_C( 1818093233), -INT32_C( 1259161121), -INT32_C( 1551492860),  INT32_C( 1440289884)
                , -INT32_C( 1986667675),  INT32_C( 1878102385),  INT32_C(  575115361), -INT32_C(  129376294)
                ,  INT32_C( 2025056753), -INT32_C(  337636433), -INT32_C( 1693581720),  INT32_C( 1340706379) },
      /* r */ {-INT32_C(  443004397),  INT32_C(  136393891), -INT32_C(  675789437),  INT32_C( 1787398557)
                , -INT32_C(  513631945),  INT32_C(   79614223),  INT32_C( 1100201112),  INT32_C(  292543257)
                , -INT32_C(  890042238),  INT32_C( 1602997729), -INT32_C( 1228494718),  INT32_C( 2109672995)
                , -INT32_C(  739730037), -INT32_C( 1178024091), -INT32_C( 1305831078), -INT32_C(  980285731)
                ,  INT32_C( 1131121988),  INT32_C(  888729398), -INT32_C(  771076626), -INT32_C(  944572346)
                , -INT32_C(  457135945), -INT32_C(   95267160),  INT32_C(  826871044),  INT32_C(  134053607)
                ,  INT32_C( 1495009704), -INT32_C( 1999786460), -INT32_C(  746267174),  INT32_C(  764797022)
                , -INT32_C(  442710332),  INT32_C(  653659997),  INT32_C( 1149561784), -INT32_C( 1725999129) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vnavg_VwVw(a, b);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vnavg_VbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vnavg_VubVub)
SIMDE_TEST_FUNC_LIST_ENTRY(vnavg_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vnavg_VwVw)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
