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

#define SIMDE_TEST_HEXAGON_HVX_INSN vcondnac

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vcondnac.h"

static int
test_simde_condnac_QVbVb(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int8_t x[128]; int8_t u[128]; int8_t r[128];
  } test_vec[] = {
    {      /* q */ {UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0) },
      /* x */ {-INT8_C(  56), -INT8_C(  42), -INT8_C(  97), -INT8_C(  83),  INT8_C( 103), -INT8_C(  85), -INT8_C(  99), -INT8_C( 126),  INT8_C(  87),  INT8_C(  53),  INT8_C(  11),  INT8_C(  12), -INT8_C( 118), -INT8_C(   4),  INT8_C(  39), -INT8_C(  24)
                , -INT8_C(  79),  INT8_C(  44), -INT8_C( 122), -INT8_C(  51), -INT8_C(  57),  INT8_C(  19),  INT8_C(  53), -INT8_C(   4), -INT8_C(  52),  INT8_C(  28), -INT8_C(  12),  INT8_C(  71),  INT8_C(  55),  INT8_C(  51),  INT8_C(   4),  INT8_C(  56)
                ,  INT8_C(  28), -INT8_C(  84), -INT8_C( 119),  INT8_C( 105), -INT8_C(  47),  INT8_C( 103), -INT8_C(  76), -INT8_C(  67),  INT8_C(  62), -INT8_C(  40), -INT8_C(  40),  INT8_C(  43),  INT8_C(  19),  INT8_C( 113),  INT8_C( 112), -INT8_C( 127)
                ,  INT8_C(  94), -INT8_C(  30),  INT8_C( 107),  INT8_C(  66),  INT8_C( 104), -INT8_C(  33),  INT8_C(  36),  INT8_C(   6),  INT8_C(  36), -INT8_C(  49), -INT8_C(  33), -INT8_C(   9),  INT8_C(  22), -INT8_C(  16),  INT8_C(  30), -INT8_C(  99)
                , -INT8_C(   3), -INT8_C(  84), -INT8_C(   9), -INT8_C( 102),  INT8_C(  71),  INT8_C(   0),  INT8_C(  84), -INT8_C(  68), -INT8_C( 113), -INT8_C(  64), -INT8_C(  67),  INT8_C(  41), -INT8_C(  83), -INT8_C(  45),  INT8_C(  89), -INT8_C(  17)
                , -INT8_C(  80),  INT8_C(  37), -INT8_C(  36), -INT8_C(  32), -INT8_C( 115), -INT8_C(  15), -INT8_C( 113),  INT8_C(  41),  INT8_C(  84),  INT8_C(  37),  INT8_C(  22),  INT8_C(  25), -INT8_C( 123),  INT8_C(  69), -INT8_C(  35), -INT8_C(  68)
                , -INT8_C(  70),  INT8_C(  61), -INT8_C(   2), -INT8_C( 128),  INT8_C(  51), -INT8_C(  36),  INT8_C(  61),  INT8_C(  90), -INT8_C(  65), -INT8_C( 100),  INT8_C(  36), -INT8_C(  87),  INT8_C(  44),  INT8_C(  56),  INT8_C( 120),  INT8_C(  24)
                , -INT8_C(  41), -INT8_C(  80),  INT8_C(  30), -INT8_C(  76),  INT8_C(  56), -INT8_C(  26), -INT8_C(  83), -INT8_C(  75), -INT8_C(  42),  INT8_C(  99), -INT8_C(  46),  INT8_C(  12),  INT8_C(  21),  INT8_C( 100),  INT8_C( 117),  INT8_C( 106) },
      /* u */ {-INT8_C(  65),  INT8_C(  85), -INT8_C(   3), -INT8_C( 114), -INT8_C(  50), -INT8_C(   2),  INT8_C(   9), -INT8_C( 128), -INT8_C(  93),  INT8_C(  35), -INT8_C( 112),  INT8_C(  65), -INT8_C( 101),  INT8_C(  48),  INT8_C( 119),  INT8_C( 110)
                ,  INT8_C(  16),  INT8_C(  72),  INT8_C(  25),  INT8_C( 112),  INT8_C(  10),  INT8_C(  70),  INT8_C(  51),  INT8_C(  83),  INT8_C(  38), -INT8_C(  38), -INT8_C( 112), -INT8_C( 122), -INT8_C(  74),  INT8_C(  97), -INT8_C(  49),  INT8_C(  75)
                , -INT8_C(  31),  INT8_C(  45),  INT8_C(  27),  INT8_C( 109), -INT8_C(  35), -INT8_C(  66),  INT8_C(   9), -INT8_C( 119), -INT8_C(  25),  INT8_C(  47), -INT8_C(  39), -INT8_C(   5), -INT8_C(   5),  INT8_C(  16),  INT8_C(   8), -INT8_C(  57)
                ,  INT8_C(  69),  INT8_C(  61), -INT8_C(   5),  INT8_C(  46),  INT8_C( 123),  INT8_C(  46), -INT8_C(  50),  INT8_C( 117), -INT8_C(  94),  INT8_C(  37),  INT8_C(  11), -INT8_C(  31), -INT8_C( 106),  INT8_C(  73),  INT8_C(  26), -INT8_C(  36)
                , -INT8_C(  75), -INT8_C(  79), -INT8_C(  65),  INT8_C(  51), -INT8_C(  45),  INT8_C(  47),  INT8_C( 120), -INT8_C(  57),  INT8_C( 121), -INT8_C(  21), -INT8_C(  51),  INT8_C(  63),  INT8_C(  79), -INT8_C(   6), -INT8_C( 115),  INT8_C(  67)
                , -INT8_C(  87),  INT8_C(  34), -INT8_C(  52), -INT8_C(  87), -INT8_C(  73), -INT8_C(  43), -INT8_C(  33), -INT8_C(  15),  INT8_C(  26),  INT8_C(  50),  INT8_C(  91),  INT8_C( 119),  INT8_C(  75), -INT8_C(   5),  INT8_C(  22), -INT8_C(  92)
                , -INT8_C(  51), -INT8_C( 119), -INT8_C( 105),  INT8_C(  47),  INT8_C(  82), -INT8_C(  34), -INT8_C(  29), -INT8_C(  47),  INT8_C(  86),  INT8_C(   5), -INT8_C( 112),  INT8_C(  12),  INT8_C( 119), -INT8_C(  47),  INT8_C(  35), -INT8_C(  49)
                ,  INT8_C(  75),  INT8_C(  54),  INT8_C( 116),  INT8_C(  38),  INT8_C(  16),  INT8_C(  56), -INT8_C(  94),  INT8_C(  66), -INT8_C( 120), -INT8_C(  97), -INT8_C(  84),  INT8_C(  56), -INT8_C(  34), -INT8_C(  87), -INT8_C(  45), -INT8_C(  31) },
      /* r */ {-INT8_C(  56), -INT8_C(  42), -INT8_C(  97),  INT8_C(  31), -INT8_C( 103), -INT8_C(  83), -INT8_C( 108),  INT8_C(   2),  INT8_C(  87),  INT8_C(  53),  INT8_C( 123), -INT8_C(  53), -INT8_C( 118), -INT8_C(  52),  INT8_C(  39), -INT8_C(  24)
                , -INT8_C(  95),  INT8_C(  44),  INT8_C( 109), -INT8_C(  51), -INT8_C(  57),  INT8_C(  19),  INT8_C(  53), -INT8_C(  87), -INT8_C(  90),  INT8_C(  66),  INT8_C( 100), -INT8_C(  63), -INT8_C( 127),  INT8_C(  51),  INT8_C(  53), -INT8_C(  19)
                ,  INT8_C(  28), -INT8_C(  84),  INT8_C( 110),  INT8_C( 105), -INT8_C(  12),  INT8_C( 103), -INT8_C(  76), -INT8_C(  67),  INT8_C(  87), -INT8_C(  87), -INT8_C(  40),  INT8_C(  43),  INT8_C(  24),  INT8_C( 113),  INT8_C( 112), -INT8_C( 127)
                ,  INT8_C(  94), -INT8_C(  91),  INT8_C( 107),  INT8_C(  20),  INT8_C( 104), -INT8_C(  79),  INT8_C(  86),  INT8_C(   6),  INT8_C(  36), -INT8_C(  86), -INT8_C(  33), -INT8_C(   9), -INT8_C( 128), -INT8_C(  16),  INT8_C(   4), -INT8_C(  99)
                , -INT8_C(   3), -INT8_C(   5), -INT8_C(   9),  INT8_C( 103),  INT8_C( 116), -INT8_C(  47), -INT8_C(  36), -INT8_C(  68),  INT8_C(  22), -INT8_C(  43), -INT8_C(  67),  INT8_C(  41), -INT8_C(  83), -INT8_C(  39), -INT8_C(  52), -INT8_C(  84)
                ,  INT8_C(   7),  INT8_C(   3),  INT8_C(  16), -INT8_C(  32), -INT8_C(  42),  INT8_C(  28), -INT8_C( 113),  INT8_C(  41),  INT8_C(  58),  INT8_C(  37),  INT8_C(  22), -INT8_C(  94),  INT8_C(  58),  INT8_C(  74), -INT8_C(  57), -INT8_C(  68)
                , -INT8_C(  70),  INT8_C(  61),  INT8_C( 103),  INT8_C(  81), -INT8_C(  31), -INT8_C(  36),  INT8_C(  61),  INT8_C(  90), -INT8_C(  65), -INT8_C( 100),  INT8_C(  36), -INT8_C(  99), -INT8_C(  75),  INT8_C( 103),  INT8_C( 120),  INT8_C(  24)
                , -INT8_C( 116), -INT8_C(  80), -INT8_C(  86), -INT8_C( 114),  INT8_C(  56), -INT8_C(  82),  INT8_C(  11),  INT8_C( 115),  INT8_C(  78),  INT8_C(  99), -INT8_C(  46), -INT8_C(  44),  INT8_C(  55),  INT8_C( 100), -INT8_C(  94),  INT8_C( 106) } },
    {      /* q */ {UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255) },
      /* x */ { INT8_C(  83),  INT8_C( 108),  INT8_C(  41),  INT8_C(  84),  INT8_C(  87), -INT8_C(  90),  INT8_C(  61),  INT8_C(  70), -INT8_C( 114), -INT8_C(   4),  INT8_C(  99),  INT8_C(   7),  INT8_C(  60),  INT8_C(  63),  INT8_C( 103), -INT8_C(  99)
                ,  INT8_C(  57),  INT8_C(  12),  INT8_C(  12),  INT8_C( 115), -INT8_C( 118),  INT8_C( 117),  INT8_C(  12), -INT8_C( 109),  INT8_C( 125), -INT8_C( 119), -INT8_C(  86),  INT8_C(   7), -INT8_C(  81), -INT8_C(  56), -INT8_C(  51),  INT8_C(  30)
                , -INT8_C(  28),  INT8_C(  97), -INT8_C( 122), -INT8_C( 119),  INT8_C( 106), -INT8_C(   2), -INT8_C(  87), -INT8_C(  49),  INT8_C(  57), -INT8_C( 124),  INT8_C( 110), -INT8_C(  14),  INT8_C( 118),  INT8_C(  56), -INT8_C( 115),  INT8_C( 112)
                , -INT8_C( 107), -INT8_C(   3), -INT8_C( 120),  INT8_C( 121), -INT8_C(  62), -INT8_C(  23), -INT8_C(  57), -INT8_C(  65), -INT8_C(  31), -INT8_C(  72),  INT8_C(  59), -INT8_C(  64), -INT8_C(  26),  INT8_C( 113), -INT8_C(  49),  INT8_C(  55)
                ,  INT8_C(  19),  INT8_C(  56),  INT8_C(  15), -INT8_C(  68),  INT8_C(   5),  INT8_C(  32), -INT8_C( 103),  INT8_C(   8), -INT8_C(  27), -INT8_C( 127),  INT8_C( 116),  INT8_C(  50),  INT8_C(  78),  INT8_C( 124), -INT8_C(  56),  INT8_C(  91)
                , -INT8_C(  68),  INT8_C(  82), -INT8_C( 118),  INT8_C(  65), -INT8_C(  18), -INT8_C(  34),  INT8_C(  25),  INT8_C(   8),  INT8_C( 114), -INT8_C(  47),  INT8_C(  99),  INT8_C(  21), -INT8_C( 114), -INT8_C(  33), -INT8_C( 114), -INT8_C( 115)
                ,  INT8_C(  49),  INT8_C(  65),  INT8_C(  86), -INT8_C(   8), -INT8_C(  86), -INT8_C(  92),  INT8_C(  97),  INT8_C(  84), -INT8_C( 104), -INT8_C( 125),  INT8_C( 109),  INT8_C(  95), -INT8_C(  64), -INT8_C( 102),  INT8_C(  44), -INT8_C(  46)
                , -INT8_C( 106),  INT8_C(  68),  INT8_C(  94), -INT8_C(  86),  INT8_C( 118),  INT8_C(  84),  INT8_C( 105), -INT8_C(  54),  INT8_C(  99), -INT8_C( 126),  INT8_C(  74),  INT8_C(  34), -INT8_C(   8), -INT8_C(  85), -INT8_C(  34),  INT8_C(  87) },
      /* u */ {-INT8_C(  65), -INT8_C( 125),  INT8_C( 104),  INT8_C(  67), -INT8_C(  65),  INT8_C(   3),  INT8_C(  18),  INT8_C(  20), -INT8_C(  22),  INT8_C(  67),  INT8_C(  72), -INT8_C(  64), -INT8_C(  68),  INT8_C(  94), -INT8_C( 125),  INT8_C(  56)
                , -INT8_C(  32), -INT8_C(  87), -INT8_C(  38),  INT8_C( 107),  INT8_C(  16), -INT8_C(  77),  INT8_C(  79),  INT8_C(  82),  INT8_C(  17), -INT8_C(  86), -INT8_C( 122), -INT8_C(  84), -INT8_C(  73), -INT8_C(  82),  INT8_C(  87), -INT8_C( 117)
                , -INT8_C(  18),  INT8_C(  90), -INT8_C(  34),  INT8_C(  96),  INT8_C(  13),  INT8_C(  27), -INT8_C(  10),  INT8_C( 112),  INT8_C(  68), -INT8_C( 122),  INT8_C(  17),  INT8_C( 126),  INT8_C(  57), -INT8_C(  41),  INT8_C(  89),  INT8_C( 100)
                ,  INT8_C(  43),  INT8_C(  70),  INT8_C(  35),  INT8_C(  38), -INT8_C(  39),  INT8_C( 112), -INT8_C(  72),  INT8_C( 107), -INT8_C(  99),  INT8_C(  19),  INT8_C( 103), -INT8_C( 108), -INT8_C( 102),  INT8_C(  12), -INT8_C(  56), -INT8_C(  21)
                ,  INT8_C(  73),  INT8_C(  96), -INT8_C(  43),  INT8_C(  93), -INT8_C(  29), -INT8_C(   7),  INT8_C(  20), -INT8_C(  93), -INT8_C(   2), -INT8_C( 102), -INT8_C(  77),  INT8_C( 105), -INT8_C(  97), -INT8_C( 104),  INT8_C(  55),  INT8_C(  15)
                ,  INT8_C(  81),  INT8_C( 110), -INT8_C(  13),  INT8_C(  73),  INT8_C(  16), -INT8_C(  14), -INT8_C(  50), -INT8_C(  30), -INT8_C(  59), -INT8_C( 102),  INT8_C(  65),  INT8_C(  80), -INT8_C(  13),  INT8_C(  71),  INT8_C(   5), -INT8_C(  42)
                , -INT8_C(  55), -INT8_C(  72), -INT8_C(   6), -INT8_C(  50), -INT8_C(  13), -INT8_C(  52), -INT8_C(  54), -INT8_C(  21), -INT8_C(  76), -INT8_C(  31), -INT8_C(  61),  INT8_C(  98),  INT8_C( 106), -INT8_C(  28), -INT8_C(  30), -INT8_C(  52)
                ,  INT8_C( 101),  INT8_C(  19), -INT8_C(  57), -INT8_C(  56), -INT8_C( 102),  INT8_C(  45), -INT8_C(  53), -INT8_C(  12), -INT8_C( 105),  INT8_C(  36), -INT8_C(  47), -INT8_C(   4), -INT8_C(  40), -INT8_C(  44),  INT8_C(  38),  INT8_C(  75) },
      /* r */ {-INT8_C( 108), -INT8_C(  23),  INT8_C(  41),  INT8_C(  84), -INT8_C( 104), -INT8_C(  93),  INT8_C(  43),  INT8_C(  50), -INT8_C(  92), -INT8_C(   4),  INT8_C(  27),  INT8_C(  71),  INT8_C(  60), -INT8_C(  31), -INT8_C(  28),  INT8_C( 101)
                ,  INT8_C(  89),  INT8_C(  12),  INT8_C(  50),  INT8_C( 115), -INT8_C( 118),  INT8_C( 117), -INT8_C(  67),  INT8_C(  65),  INT8_C( 125), -INT8_C( 119),  INT8_C(  36),  INT8_C(  91), -INT8_C(  81),  INT8_C(  26),  INT8_C( 118), -INT8_C( 109)
                , -INT8_C(  10),  INT8_C(   7), -INT8_C(  88),  INT8_C(  41),  INT8_C( 106), -INT8_C(   2), -INT8_C(  77), -INT8_C(  49), -INT8_C(  11), -INT8_C(   2),  INT8_C( 110), -INT8_C(  14),  INT8_C( 118),  INT8_C(  56), -INT8_C( 115),  INT8_C(  12)
                ,  INT8_C( 106), -INT8_C(  73), -INT8_C( 120),  INT8_C( 121), -INT8_C(  23), -INT8_C(  23), -INT8_C(  57), -INT8_C(  65), -INT8_C(  31), -INT8_C(  91),  INT8_C(  59),  INT8_C(  44), -INT8_C(  26),  INT8_C( 113), -INT8_C(  49),  INT8_C(  76)
                ,  INT8_C(  19),  INT8_C(  56),  INT8_C(  58), -INT8_C(  68),  INT8_C(  34),  INT8_C(  32), -INT8_C( 123),  INT8_C( 101), -INT8_C(  27), -INT8_C(  25),  INT8_C( 116),  INT8_C(  50),  INT8_C(  78), -INT8_C(  28), -INT8_C( 111),  INT8_C(  76)
                ,  INT8_C( 107), -INT8_C(  28), -INT8_C( 118), -INT8_C(   8), -INT8_C(  34), -INT8_C(  20),  INT8_C(  25),  INT8_C(   8),  INT8_C( 114), -INT8_C(  47),  INT8_C(  99), -INT8_C(  59), -INT8_C( 114), -INT8_C( 104), -INT8_C( 119), -INT8_C(  73)
                ,  INT8_C(  49),  INT8_C(  65),  INT8_C(  86), -INT8_C(   8), -INT8_C(  86), -INT8_C(  40), -INT8_C( 105),  INT8_C( 105), -INT8_C( 104), -INT8_C(  94),  INT8_C( 109), -INT8_C(   3),  INT8_C(  86), -INT8_C(  74),  INT8_C(  44), -INT8_C(  46)
                , -INT8_C( 106),  INT8_C(  68),  INT8_C(  94), -INT8_C(  86),  INT8_C( 118),  INT8_C(  84), -INT8_C(  98), -INT8_C(  54), -INT8_C(  52),  INT8_C(  94),  INT8_C(  74),  INT8_C(  34),  INT8_C(  32), -INT8_C(  85), -INT8_C(  34),  INT8_C(  12) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vb_condnac_QVbVb(q, x, u);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_condnac_QnVbVb(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int8_t x[128]; int8_t u[128]; int8_t r[128];
  } test_vec[] = {
    {      /* q */ {UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255) },
      /* x */ { INT8_C(  23),  INT8_C(  16),  INT8_C( 115),  INT8_C(   8), -INT8_C(  51),  INT8_C( 114), -INT8_C(  69),  INT8_C( 103), -INT8_C(  11),  INT8_C(  89),  INT8_C(  34),  INT8_C(  67),  INT8_C( 122),  INT8_C(  60),  INT8_C(  92), -INT8_C( 124)
                ,  INT8_C(  20),  INT8_C(  86),  INT8_C(  78), -INT8_C(  30),  INT8_C( 122),  INT8_C(  66), -INT8_C(  29),  INT8_C(  54),  INT8_C(   1), -INT8_C(  42), -INT8_C(  71),  INT8_C( 119),  INT8_C(   3), -INT8_C(  40),  INT8_C(  16), -INT8_C(  69)
                , -INT8_C(  17), -INT8_C(  78), -INT8_C( 120), -INT8_C(  33),  INT8_C(  63),  INT8_C(  78),  INT8_C(  82), -INT8_C(  12), -INT8_C(  23), -INT8_C(  95),  INT8_C(   4), -INT8_C(  97), -INT8_C( 106),  INT8_C(  55),  INT8_C( 122),  INT8_C(  58)
                ,  INT8_C(  30), -INT8_C(   7),  INT8_C( 109),  INT8_C(  51), -INT8_C(  20),  INT8_C(  47),  INT8_C(  13),  INT8_C(  88), -INT8_C(  98), -INT8_C(  72), -INT8_C(  65), -INT8_C(  96), -INT8_C(  50), -INT8_C( 106), -INT8_C(   7),  INT8_C(   4)
                ,  INT8_C(  56), -INT8_C(  10), -INT8_C(  68),  INT8_C( 116),  INT8_C(  14), -INT8_C(  72),  INT8_C(  92),  INT8_C(   8), -INT8_C(  64), -INT8_C( 114),  INT8_C(  10),  INT8_C(  16),  INT8_C( 110), -INT8_C(  24), -INT8_C( 108), -INT8_C(  20)
                , -INT8_C(  34),  INT8_C(   0),  INT8_C(  11),  INT8_C(  45), -INT8_C(  81),  INT8_C(  28),  INT8_C(  45),  INT8_C(  40), -INT8_C(  41), -INT8_C(  64),  INT8_C(  83), -INT8_C(   4), -INT8_C(  98),  INT8_C( 109),  INT8_C( 109),  INT8_C(  87)
                ,  INT8_C(   7),  INT8_C( 126),  INT8_C(  41), -INT8_C(   2), -INT8_C(  60), -INT8_C(   1), -INT8_C(   3),  INT8_C(  41), -INT8_C(  51), -INT8_C(  89), -INT8_C(  37), -INT8_C(  30), -INT8_C(   8), -INT8_C(  32),  INT8_C(  25),  INT8_C(  77)
                , -INT8_C( 101),  INT8_C(  58),  INT8_C(  72),  INT8_C(   6),  INT8_C(   7), -INT8_C(  46), -INT8_C(  91), -INT8_C(  21), -INT8_C( 106),  INT8_C(  98),  INT8_C( 110), -INT8_C(  19),  INT8_C( 100), -INT8_C(  55),  INT8_C(  58),  INT8_C( 116) },
      /* u */ {-INT8_C(  88),  INT8_C( 100),  INT8_C(  58), -INT8_C(  34), -INT8_C(  39), -INT8_C(  47),  INT8_C(   1),  INT8_C(  54), -INT8_C(  20), -INT8_C(  53), -INT8_C(  68), -INT8_C( 104), -INT8_C(  86),  INT8_C( 114),  INT8_C(   4),  INT8_C(  11)
                , -INT8_C( 102), -INT8_C( 114),  INT8_C(  30), -INT8_C( 115), -INT8_C( 123), -INT8_C(  82), -INT8_C( 120), -INT8_C(  13), -INT8_C(  56),  INT8_C(  14),  INT8_C( 112),  INT8_C( 106), -INT8_C(  62),  INT8_C(  33), -INT8_C( 127),  INT8_C(  61)
                ,  INT8_C(  91),  INT8_C(  79), -INT8_C( 121), -INT8_C(  73), -INT8_C( 105), -INT8_C( 120), -INT8_C(  92), -INT8_C(  26), -INT8_C(  22), -INT8_C(  99),  INT8_C(  88), -INT8_C(  23), -INT8_C( 119), -INT8_C(  16), -INT8_C( 120),  INT8_C( 126)
                , -INT8_C(  64), -INT8_C(  32),  INT8_C(  66),  INT8_C(  62),  INT8_C(  89),  INT8_C(   8),  INT8_C(  72), -INT8_C(  22),  INT8_C(  17), -INT8_C(   8), -INT8_C( 115),  INT8_C(  56),  INT8_C(  90), -INT8_C(  58), -INT8_C(  85),  INT8_C(  34)
                ,  INT8_C(  89),  INT8_C(  42),  INT8_C( 105), -INT8_C(  29),  INT8_C(   0),  INT8_C(  72), -INT8_C(  76), -INT8_C( 112), -INT8_C(  15), -INT8_C(  40),  INT8_C(  98),  INT8_C( 105),  INT8_C(  74),  INT8_C( 119),  INT8_C( 124), -INT8_C(  13)
                ,  INT8_C(  17), -INT8_C( 118), -INT8_C( 105),  INT8_C(  66), -INT8_C(  35),  INT8_C(  23), -INT8_C(  54), -INT8_C(  31),  INT8_C(  90), -INT8_C( 104), -INT8_C(  59),  INT8_C(  11),  INT8_C(  19),  INT8_C(  49), -INT8_C(  69),  INT8_C(   3)
                ,  INT8_C(  47), -INT8_C(  17), -INT8_C(  55), -INT8_C(  41),  INT8_C(  62), -INT8_C(  18),  INT8_C(  42),  INT8_C(  52),  INT8_C(  88),  INT8_C(  80),  INT8_C(  98), -INT8_C(  42),  INT8_C(  77),  INT8_C(  86), -INT8_C(  65), -INT8_C(  44)
                , -INT8_C(  38),  INT8_C( 102),  INT8_C(  31),  INT8_C( 121), -INT8_C(  49),  INT8_C(  58), -INT8_C( 126), -INT8_C(  54), -INT8_C(  17),  INT8_C(  46), -INT8_C( 109),  INT8_C(  66),  INT8_C(   1), -INT8_C(  97), -INT8_C(  92),  INT8_C(  73) },
      /* r */ { INT8_C( 111), -INT8_C(  84),  INT8_C(  57),  INT8_C(   8), -INT8_C(  12), -INT8_C(  95), -INT8_C(  69),  INT8_C( 103),  INT8_C(   9),  INT8_C(  89),  INT8_C( 102), -INT8_C(  85), -INT8_C(  48),  INT8_C(  60),  INT8_C(  88),  INT8_C( 121)
                ,  INT8_C( 122), -INT8_C(  56),  INT8_C(  48),  INT8_C(  85),  INT8_C( 122),  INT8_C(  66),  INT8_C(  91),  INT8_C(  67),  INT8_C(   1), -INT8_C(  56),  INT8_C(  73),  INT8_C( 119),  INT8_C(  65), -INT8_C(  40), -INT8_C( 113),  INT8_C( 126)
                , -INT8_C( 108), -INT8_C(  78),  INT8_C(   1), -INT8_C(  33),  INT8_C(  63), -INT8_C(  58),  INT8_C(  82), -INT8_C(  12), -INT8_C(   1),  INT8_C(   4),  INT8_C(   4), -INT8_C(  74),  INT8_C(  13),  INT8_C(  55), -INT8_C(  14), -INT8_C(  68)
                ,  INT8_C(  30), -INT8_C(   7),  INT8_C( 109), -INT8_C(  11), -INT8_C(  20),  INT8_C(  47),  INT8_C(  13),  INT8_C(  88), -INT8_C( 115), -INT8_C(  72),  INT8_C(  50),  INT8_C( 104),  INT8_C( 116), -INT8_C(  48),  INT8_C(  78),  INT8_C(   4)
                ,  INT8_C(  56), -INT8_C(  52),  INT8_C(  83),  INT8_C( 116),  INT8_C(  14),  INT8_C( 112),  INT8_C(  92),  INT8_C( 120), -INT8_C(  49), -INT8_C(  74), -INT8_C(  88),  INT8_C(  16),  INT8_C(  36),  INT8_C( 113), -INT8_C( 108), -INT8_C(  20)
                , -INT8_C(  34),  INT8_C( 118),  INT8_C( 116), -INT8_C(  21), -INT8_C(  81),  INT8_C(  28),  INT8_C(  45),  INT8_C(  71),  INT8_C( 125),  INT8_C(  40),  INT8_C(  83), -INT8_C(   4), -INT8_C( 117),  INT8_C(  60), -INT8_C(  78),  INT8_C(  84)
                , -INT8_C(  40),  INT8_C( 126),  INT8_C(  41),  INT8_C(  39), -INT8_C( 122), -INT8_C(   1), -INT8_C(  45),  INT8_C(  41),  INT8_C( 117), -INT8_C(  89),  INT8_C( 121), -INT8_C(  30), -INT8_C(  85), -INT8_C( 118),  INT8_C(  90),  INT8_C( 121)
                , -INT8_C( 101),  INT8_C(  58),  INT8_C(  41), -INT8_C( 115),  INT8_C(  56), -INT8_C( 104), -INT8_C(  91), -INT8_C(  21), -INT8_C(  89),  INT8_C(  98),  INT8_C( 110), -INT8_C(  85),  INT8_C( 100), -INT8_C(  55),  INT8_C(  58),  INT8_C( 116) } },
    {      /* q */ {UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0) },
      /* x */ {-INT8_C(   7),  INT8_C(  81), -INT8_C(  80),  INT8_C(   5),  INT8_C(  94), -INT8_C(  17),  INT8_C(  96),  INT8_C(  24), -INT8_C(   7),  INT8_C(  14),  INT8_C(  60),  INT8_C(   9), -INT8_C( 125),  INT8_C(  28),  INT8_C(   4),  INT8_C(  76)
                , -INT8_C(  63), -INT8_C(  14),  INT8_C(  25), -INT8_C(   9),  INT8_C(  92), -INT8_C(  83), -INT8_C(  73), -INT8_C( 100),  INT8_C(  72), -INT8_C(  77),  INT8_C(  85),  INT8_C(  67),  INT8_C(  41), -INT8_C( 104), -INT8_C(  22), -INT8_C(  71)
                ,  INT8_C(  50),  INT8_C(  80),  INT8_C(  94), -INT8_C(  15), -INT8_C(  19), -INT8_C(  52),  INT8_C(  47),  INT8_C(  27),  INT8_C(  48), -INT8_C(  62),  INT8_C(  80), -INT8_C( 111), -INT8_C( 120),  INT8_C(  89),  INT8_C(   1), -INT8_C(   5)
                ,  INT8_C(  72),  INT8_C(  17), -INT8_C( 108),  INT8_C(  70),  INT8_C(  52), -INT8_C( 114),  INT8_C(  46),  INT8_C( 110),  INT8_C(  20),  INT8_C( 110), -INT8_C(  34),  INT8_C(  15), -INT8_C( 128),  INT8_C( 104), -INT8_C(  67), -INT8_C(  94)
                ,  INT8_C(  92), -INT8_C(  18),  INT8_C(  26), -INT8_C(  48), -INT8_C( 126), -INT8_C(  54),  INT8_C(  35), -INT8_C( 127),  INT8_C(  55),  INT8_C(  83), -INT8_C(  36), -INT8_C(  81), -INT8_C( 122),  INT8_C(   9),  INT8_C( 105),  INT8_C(  78)
                ,  INT8_C( 123), -INT8_C(   2),  INT8_C(   7), -INT8_C( 127),  INT8_C(  68),  INT8_C( 116), -INT8_C(  46),  INT8_C(  34),  INT8_C(  74), -INT8_C(  11),  INT8_C(  49),  INT8_C(  63), -INT8_C( 120),  INT8_C(  23),  INT8_C( 124),  INT8_C( 120)
                ,  INT8_C(  67), -INT8_C(  30),  INT8_C(  70),  INT8_C( 118), -INT8_C(  22), -INT8_C(  73),  INT8_C(  72),  INT8_C( 108),  INT8_C(  52), -INT8_C(  97),  INT8_C(  61),  INT8_C(   9),  INT8_C(  73),  INT8_C(  14),  INT8_C( 121),  INT8_C(  96)
                , -INT8_C(  41), -INT8_C(  13), -INT8_C(  36),  INT8_C(  21),  INT8_C( 106),  INT8_C(  25), -INT8_C( 116),  INT8_C(  95),  INT8_C(  28), -INT8_C( 103), -INT8_C(   8),  INT8_C(  28),  INT8_C( 126), -INT8_C( 120),  INT8_C(  48),  INT8_C(  11) },
      /* u */ {-INT8_C(  60),  INT8_C(  50), -INT8_C(  22),  INT8_C(  51),  INT8_C(  95),  INT8_C(  22),  INT8_C(  44),  INT8_C(  63), -INT8_C(  26),  INT8_C(  66), -INT8_C(  85), -INT8_C(   8),  INT8_C(  45), -INT8_C(  46), -INT8_C(  98), -INT8_C(  83)
                ,  INT8_C(  91),  INT8_C(  39),  INT8_C(  67), -INT8_C( 106),  INT8_C(  98),  INT8_C(  69),  INT8_C( 120), -INT8_C(  13), -INT8_C(  29), -INT8_C( 109), -INT8_C(  97),  INT8_C(  15),  INT8_C(  76),  INT8_C(  78), -INT8_C(  85),  INT8_C( 124)
                ,  INT8_C(  76), -INT8_C(  38), -INT8_C(  78),  INT8_C( 119),  INT8_C(  77), -INT8_C(  32), -INT8_C( 104),  INT8_C(  39), -INT8_C(  43), -INT8_C( 123), -INT8_C(  52),  INT8_C(  40), -INT8_C(  76), -INT8_C( 116),  INT8_C(  34), -INT8_C(  16)
                , -INT8_C(  43), -INT8_C( 117),  INT8_C(  92), -INT8_C(  26),  INT8_C( 121), -INT8_C(   8),  INT8_C( 118), -INT8_C( 119),  INT8_C( 116),  INT8_C(  81),  INT8_C(  54), -INT8_C(  18), -INT8_C(   6), -INT8_C(  19), -INT8_C(  19),  INT8_C( 122)
                ,  INT8_C(  51),  INT8_C(  89), -INT8_C( 119), -INT8_C( 101), -INT8_C( 107), -INT8_C( 103),  INT8_C(  41), -INT8_C(   9),  INT8_C(  29), -INT8_C(  10), -INT8_C(  76),  INT8_C(  14), -INT8_C(  40),  INT8_C( 124), -INT8_C(  57), -INT8_C( 111)
                ,  INT8_C(  34),  INT8_C(  74), -INT8_C(  27),  INT8_C(  82),  INT8_C(  28),  INT8_C( 116),  INT8_C(  92),  INT8_C( 110), -INT8_C(  10), -INT8_C( 111), -INT8_C( 119), -INT8_C(  80),  INT8_C(  18),  INT8_C(  82),  INT8_C( 101), -INT8_C( 122)
                ,  INT8_C(  47),  INT8_C(  42), -INT8_C(   6), -INT8_C(  74), -INT8_C(  53), -INT8_C(  62),  INT8_C(  56), -INT8_C(  51),  INT8_C(  74),  INT8_C(   6), -INT8_C(  80), -INT8_C(  52), -INT8_C(  60), -INT8_C(  52),  INT8_C(  58), -INT8_C(  90)
                ,  INT8_C(  99),  INT8_C( 121), -INT8_C(  20), -INT8_C(  73), -INT8_C(  16), -INT8_C(  43),  INT8_C(  60),  INT8_C(  29),  INT8_C(  62),  INT8_C(  36),  INT8_C(   4),  INT8_C(  16),  INT8_C(  28), -INT8_C(  66), -INT8_C( 116),  INT8_C(  73) },
      /* r */ {-INT8_C(   7),  INT8_C(  81), -INT8_C(  58),  INT8_C(   5),  INT8_C(  94), -INT8_C(  39),  INT8_C(  96), -INT8_C(  39), -INT8_C(   7), -INT8_C(  52), -INT8_C( 111),  INT8_C(  17), -INT8_C( 125),  INT8_C(  74),  INT8_C(   4), -INT8_C(  97)
                ,  INT8_C( 102), -INT8_C(  53), -INT8_C(  42),  INT8_C(  97), -INT8_C(   6), -INT8_C(  83), -INT8_C(  73), -INT8_C(  87),  INT8_C(  72), -INT8_C(  77), -INT8_C(  74),  INT8_C(  52),  INT8_C(  41), -INT8_C( 104), -INT8_C(  22),  INT8_C(  61)
                , -INT8_C(  26),  INT8_C(  80),  INT8_C(  94), -INT8_C(  15), -INT8_C(  19), -INT8_C(  20),  INT8_C(  47),  INT8_C(  27),  INT8_C(  91),  INT8_C(  61),  INT8_C(  80),  INT8_C( 105), -INT8_C( 120),  INT8_C(  89), -INT8_C(  33),  INT8_C(  11)
                ,  INT8_C(  72), -INT8_C( 122),  INT8_C(  56),  INT8_C(  70),  INT8_C(  52), -INT8_C( 114),  INT8_C(  46), -INT8_C(  27), -INT8_C(  96),  INT8_C(  29), -INT8_C(  34),  INT8_C(  33), -INT8_C( 128),  INT8_C( 104), -INT8_C(  67),  INT8_C(  40)
                ,  INT8_C(  41), -INT8_C( 107), -INT8_C( 111), -INT8_C(  48), -INT8_C(  19),  INT8_C(  49),  INT8_C(  35), -INT8_C( 127),  INT8_C(  26),  INT8_C(  93),  INT8_C(  40), -INT8_C(  81), -INT8_C( 122),  INT8_C(   9), -INT8_C(  94), -INT8_C(  67)
                ,  INT8_C(  89), -INT8_C(   2),  INT8_C(   7),  INT8_C(  47),  INT8_C(  40),  INT8_C( 116),  INT8_C( 118), -INT8_C(  76),  INT8_C(  84),  INT8_C( 100),  INT8_C(  49), -INT8_C( 113),  INT8_C( 118),  INT8_C(  23),  INT8_C(  23),  INT8_C( 120)
                ,  INT8_C(  20), -INT8_C(  30),  INT8_C(  70),  INT8_C( 118), -INT8_C(  22), -INT8_C(  11),  INT8_C(  16), -INT8_C(  97),  INT8_C(  52), -INT8_C(  97), -INT8_C( 115),  INT8_C(   9),  INT8_C(  73),  INT8_C(  66),  INT8_C( 121), -INT8_C(  70)
                , -INT8_C(  41),  INT8_C( 122), -INT8_C(  16),  INT8_C(  94),  INT8_C( 122),  INT8_C(  25), -INT8_C( 116),  INT8_C(  95), -INT8_C(  34),  INT8_C( 117), -INT8_C(   8),  INT8_C(  12),  INT8_C(  98), -INT8_C(  54),  INT8_C(  48), -INT8_C(  62) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vb_condnac_QnVbVb(q, x, u);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_condnac_QVhVh(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int16_t x[64]; int16_t u[64]; int16_t r[64];
  } test_vec[] = {
    {      /* q */ {UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0) },
      /* x */ {-INT16_C( 19329),  INT16_C(  7840), -INT16_C( 27104),  INT16_C( 11355),  INT16_C( 20112), -INT16_C( 28711),  INT16_C(  9423),  INT16_C( 13575)
                , -INT16_C( 27355),  INT16_C( 24357), -INT16_C(  9996),  INT16_C(  1659),  INT16_C( 21796), -INT16_C( 24907),  INT16_C( 30756),  INT16_C(  5844)
                ,  INT16_C( 31899),  INT16_C( 23041),  INT16_C(  3187), -INT16_C(  3887), -INT16_C(  8355),  INT16_C(  3026), -INT16_C( 25020), -INT16_C( 22013)
                ,  INT16_C( 24209),  INT16_C( 20604), -INT16_C( 13619),  INT16_C( 10141), -INT16_C(  4239),  INT16_C( 32398), -INT16_C( 23032), -INT16_C(  2876)
                , -INT16_C( 11447),  INT16_C( 12149),  INT16_C( 13309), -INT16_C( 12687), -INT16_C( 15093),  INT16_C( 11885), -INT16_C(  1522),  INT16_C( 20083)
                , -INT16_C( 20588),  INT16_C( 27575), -INT16_C( 16643),  INT16_C(  2540),  INT16_C( 28587), -INT16_C( 23103),  INT16_C( 27121),  INT16_C( 24490)
                , -INT16_C(  9744), -INT16_C(  3674),  INT16_C(  6185), -INT16_C( 23589), -INT16_C( 14175),  INT16_C( 20382),  INT16_C( 21462), -INT16_C( 12482)
                ,  INT16_C( 30045),  INT16_C( 25128), -INT16_C(  6645),  INT16_C( 15720), -INT16_C(   452),  INT16_C( 10898),  INT16_C( 11028), -INT16_C(  7672) },
      /* u */ {-INT16_C( 17984),  INT16_C( 14010),  INT16_C(  1503),  INT16_C( 19816), -INT16_C( 24122),  INT16_C( 18588),  INT16_C( 19992),  INT16_C(  7200)
                , -INT16_C( 14642), -INT16_C( 19826), -INT16_C(  3207),  INT16_C(  4282), -INT16_C( 28789), -INT16_C( 10975), -INT16_C( 24827),  INT16_C(   740)
                , -INT16_C( 18875),  INT16_C( 27822),  INT16_C( 10604),  INT16_C( 28934),  INT16_C(  8811),  INT16_C( 24653),  INT16_C( 11547),  INT16_C( 17120)
                ,  INT16_C( 12588),  INT16_C( 31101), -INT16_C( 20206), -INT16_C( 25875), -INT16_C( 15721), -INT16_C( 10059),  INT16_C( 19517), -INT16_C( 31084)
                , -INT16_C( 20907),  INT16_C( 23061),  INT16_C( 21915),  INT16_C( 10590), -INT16_C( 26605),  INT16_C(   758), -INT16_C( 24545), -INT16_C( 27861)
                ,  INT16_C(  4670), -INT16_C( 26838),  INT16_C( 13837), -INT16_C(  5938),  INT16_C(  2825), -INT16_C( 17868), -INT16_C(  5187), -INT16_C( 10341)
                , -INT16_C( 27457), -INT16_C(  3678), -INT16_C(  2462),  INT16_C( 32397), -INT16_C( 31777), -INT16_C( 30723),  INT16_C( 15105), -INT16_C( 14793)
                , -INT16_C(  4892), -INT16_C( 20700), -INT16_C( 10536), -INT16_C(  8088), -INT16_C( 22474),  INT16_C(  7530), -INT16_C( 13231), -INT16_C( 22024) },
      /* r */ {-INT16_C(  1345), -INT16_C(  6170), -INT16_C( 27104), -INT16_C(  8613),  INT16_C( 20170),  INT16_C( 18393),  INT16_C(  9399),  INT16_C( 13575)
                , -INT16_C( 12763), -INT16_C( 21353), -INT16_C(  6668), -INT16_C(  2623), -INT16_C( 14951), -INT16_C( 24940),  INT16_C( 30751),  INT16_C(  5844)
                ,  INT16_C( 31830),  INT16_C( 23041), -INT16_C(  7417),  INT16_C( 32721), -INT16_C( 17166),  INT16_C(  3026), -INT16_C( 25047), -INT16_C( 21981)
                ,  INT16_C( 24209), -INT16_C( 10628),  INT16_C(  6587),  INT16_C( 10160),  INT16_C( 11377),  INT16_C( 32398), -INT16_C( 22837),  INT16_C( 28356)
                ,  INT16_C(  9289), -INT16_C( 10912),  INT16_C( 13154), -INT16_C( 23183), -INT16_C( 14856),  INT16_C( 11885), -INT16_C(  1522), -INT16_C( 17592)
                , -INT16_C( 20650),  INT16_C( 27575), -INT16_C( 30480),  INT16_C(  8684),  INT16_C( 28587), -INT16_C(  5183),  INT16_C( 26932), -INT16_C( 30550)
                , -INT16_C(  9744), -INT16_C(  3674),  INT16_C(  8647),  INT16_C(  9550), -INT16_C( 14142), -INT16_C( 14434),  INT16_C(  6357),  INT16_C(  2311)
                , -INT16_C( 30627),  INT16_C( 25092), -INT16_C(  6605),  INT16_C( 15616),  INT16_C( 22022),  INT16_C( 10898),  INT16_C( 24259), -INT16_C(  7664) } },
    {      /* q */ {UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0) },
      /* x */ { INT16_C( 20976),  INT16_C( 28477), -INT16_C( 12139), -INT16_C(   320), -INT16_C( 24074),  INT16_C( 16362),  INT16_C( 14654),  INT16_C(  1335)
                ,  INT16_C( 20917), -INT16_C( 21843),  INT16_C( 23244),  INT16_C( 21105),  INT16_C( 13772), -INT16_C( 18435),  INT16_C( 25034),  INT16_C(  2353)
                ,  INT16_C(  5475),  INT16_C( 29967), -INT16_C( 26175),  INT16_C(  8332),  INT16_C( 18279), -INT16_C( 26072), -INT16_C(  8532),  INT16_C(  3591)
                ,  INT16_C( 15102), -INT16_C(  9183), -INT16_C( 13249),  INT16_C( 31576), -INT16_C( 19517), -INT16_C( 30422),  INT16_C( 17149),  INT16_C( 10389)
                , -INT16_C( 17515), -INT16_C( 27078), -INT16_C( 25003), -INT16_C( 17803),  INT16_C( 22998), -INT16_C( 28175), -INT16_C( 30925),  INT16_C(   342)
                , -INT16_C( 15244), -INT16_C( 15913), -INT16_C( 24027), -INT16_C( 25837),  INT16_C( 20399),  INT16_C( 22740),  INT16_C( 13145),  INT16_C( 12905)
                ,  INT16_C(  1979),  INT16_C( 20227),  INT16_C(   511), -INT16_C( 13001),  INT16_C( 13413),  INT16_C( 25037), -INT16_C( 20450),  INT16_C( 22848)
                , -INT16_C( 30778), -INT16_C( 19753),  INT16_C( 17700), -INT16_C( 14666), -INT16_C( 27635),  INT16_C( 10407), -INT16_C( 17633), -INT16_C( 22904) },
      /* u */ { INT16_C( 10786),  INT16_C( 10725), -INT16_C(  1973),  INT16_C( 16833), -INT16_C( 11667),  INT16_C( 22914),  INT16_C( 16542), -INT16_C( 21148)
                , -INT16_C(  9057), -INT16_C( 22304),  INT16_C( 14899), -INT16_C( 25447), -INT16_C( 25864), -INT16_C( 28323), -INT16_C(   493),  INT16_C( 12282)
                ,  INT16_C(   869), -INT16_C( 21194),  INT16_C( 25756), -INT16_C( 32567),  INT16_C(  8299),  INT16_C( 11390),  INT16_C( 30405),  INT16_C(  2804)
                , -INT16_C(   727), -INT16_C( 12557),  INT16_C(  7277),  INT16_C( 30404),  INT16_C( 32137),  INT16_C( 13503), -INT16_C( 21937),  INT16_C(  9910)
                ,  INT16_C( 22211),  INT16_C(  3240), -INT16_C(  6413),  INT16_C( 14206), -INT16_C(   317), -INT16_C( 14292), -INT16_C( 22002),  INT16_C( 16669)
                ,  INT16_C(  7911), -INT16_C( 25205),  INT16_C( 14670),  INT16_C( 20566),  INT16_C( 23198),  INT16_C( 23677),  INT16_C( 12522),  INT16_C(  5496)
                , -INT16_C(  9120), -INT16_C( 31050),  INT16_C( 24472),  INT16_C(  6899),  INT16_C( 31079),  INT16_C( 26745), -INT16_C( 20356), -INT16_C( 17856)
                ,  INT16_C( 17069),  INT16_C(  3677), -INT16_C( 29285), -INT16_C(  8325),  INT16_C(  6519), -INT16_C( 31781),  INT16_C(  6583), -INT16_C(  1488) },
      /* r */ { INT16_C( 10224),  INT16_C( 28504), -INT16_C( 12214), -INT16_C( 17216), -INT16_C( 12407), -INT16_C(  6552), -INT16_C(  1888),  INT16_C( 22327)
                ,  INT16_C( 29974),  INT16_C(   461),  INT16_C(  8396), -INT16_C( 18984), -INT16_C( 25908), -INT16_C( 18435),  INT16_C( 25527), -INT16_C(  9935)
                ,  INT16_C(  4451), -INT16_C( 14375),  INT16_C( 13605), -INT16_C( 24637),  INT16_C( 18428), -INT16_C( 25942),  INT16_C( 26540),  INT16_C(   787)
                ,  INT16_C( 15061), -INT16_C(  9170), -INT16_C( 20526),  INT16_C( 31576), -INT16_C( 19654),  INT16_C( 21611), -INT16_C( 26371),  INT16_C( 10389)
                , -INT16_C( 17515), -INT16_C( 30318), -INT16_C( 18603), -INT16_C( 32009),  INT16_C( 22803), -INT16_C( 13883), -INT16_C(  8923),  INT16_C(   313)
                , -INT16_C( 23180),  INT16_C(  9292),  INT16_C( 26839),  INT16_C( 19133),  INT16_C( 20241), -INT16_C(   937),  INT16_C( 13167),  INT16_C( 12905)
                ,  INT16_C( 11099), -INT16_C( 14259), -INT16_C( 23809), -INT16_C( 13001),  INT16_C( 13413),  INT16_C( 24916), -INT16_C( 20318),  INT16_C( 22848)
                ,  INT16_C( 17689), -INT16_C( 23430),  INT16_C( 17801), -INT16_C(  6218),  INT16_C( 31245), -INT16_C( 23385), -INT16_C( 24289), -INT16_C( 22952) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vh_condnac_QVhVh(q, x, u);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_condnac_QnVhVh(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int16_t x[64]; int16_t u[64]; int16_t r[64];
  } test_vec[] = {
    {      /* q */ {UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0) },
      /* x */ {-INT16_C(   610), -INT16_C( 23986),  INT16_C( 29427), -INT16_C( 14043),  INT16_C( 23159),  INT16_C(  8486),  INT16_C( 19116),  INT16_C( 23115)
                , -INT16_C(  2394), -INT16_C(  3045),  INT16_C( 21428),  INT16_C( 32229), -INT16_C( 29277), -INT16_C(  1143), -INT16_C(  4989),  INT16_C( 14352)
                ,  INT16_C(   782),  INT16_C( 26051),  INT16_C( 26517),  INT16_C( 19477), -INT16_C( 14142),  INT16_C( 12006), -INT16_C( 15009),  INT16_C( 26750)
                ,  INT16_C( 30129),  INT16_C( 21376), -INT16_C(   701),  INT16_C( 28706), -INT16_C( 11149),  INT16_C( 32330), -INT16_C( 16392),  INT16_C( 29228)
                ,  INT16_C( 16349), -INT16_C( 26540), -INT16_C( 26515), -INT16_C( 29569),  INT16_C( 31804),  INT16_C( 17092), -INT16_C(  9707),  INT16_C( 13910)
                , -INT16_C( 23009),  INT16_C( 12017),  INT16_C( 11601),  INT16_C(  9751),  INT16_C( 23974),  INT16_C(  9378),  INT16_C( 10161),  INT16_C( 27986)
                , -INT16_C(  5445),  INT16_C( 19952), -INT16_C( 25781), -INT16_C( 16517),  INT16_C( 31152),  INT16_C( 22659), -INT16_C(  6138),  INT16_C( 28470)
                , -INT16_C(  7443),  INT16_C( 31867), -INT16_C( 11265),  INT16_C( 20150), -INT16_C( 13162),  INT16_C(  9586),  INT16_C( 25279),  INT16_C( 28463) },
      /* u */ {-INT16_C( 14039), -INT16_C(  5697), -INT16_C( 22954),  INT16_C( 28029),  INT16_C(  4314),  INT16_C( 20464), -INT16_C( 22725), -INT16_C( 30845)
                ,  INT16_C( 17336),  INT16_C( 17185),  INT16_C( 19653), -INT16_C( 28530),  INT16_C(  2899),  INT16_C( 31407),  INT16_C( 23617),  INT16_C( 27542)
                ,  INT16_C(  3816),  INT16_C( 25605),  INT16_C(  1385),  INT16_C( 31829),  INT16_C( 11207),  INT16_C( 26057),  INT16_C( 20420), -INT16_C( 17369)
                , -INT16_C( 22589), -INT16_C( 32561), -INT16_C( 24169), -INT16_C(  3852), -INT16_C(  8466),  INT16_C( 11450), -INT16_C(   931),  INT16_C( 32159)
                ,  INT16_C( 18899),  INT16_C( 16241), -INT16_C(  8651),  INT16_C( 24141), -INT16_C(  4438), -INT16_C( 24107),  INT16_C( 17336),  INT16_C( 29000)
                , -INT16_C( 21529),  INT16_C( 26960), -INT16_C( 26090), -INT16_C( 15279), -INT16_C(  7862),  INT16_C( 20081), -INT16_C( 19792),  INT16_C( 24843)
                , -INT16_C( 20393), -INT16_C( 16058),  INT16_C(  1854),  INT16_C(  5464),  INT16_C( 30464), -INT16_C( 19498),  INT16_C( 20082),  INT16_C( 18073)
                , -INT16_C( 12749), -INT16_C( 17914), -INT16_C( 13201),  INT16_C(  7870),  INT16_C(  5010), -INT16_C( 20032), -INT16_C( 12552), -INT16_C( 24805) },
      /* r */ {-INT16_C(   651), -INT16_C( 18354),  INT16_C( 29341),  INT16_C( 23333),  INT16_C( 23197), -INT16_C( 11978), -INT16_C( 23636), -INT16_C( 11576)
                , -INT16_C( 19802), -INT16_C(  2822),  INT16_C(  1775),  INT16_C( 32087), -INT16_C( 29360), -INT16_C(  1143), -INT16_C(  5054), -INT16_C( 13296)
                ,  INT16_C(   782),  INT16_C( 26046),  INT16_C( 26517), -INT16_C( 12352), -INT16_C( 25406),  INT16_C( 11805), -INT16_C( 15009), -INT16_C( 21378)
                , -INT16_C( 12879), -INT16_C( 11599), -INT16_C(   701),  INT16_C( 28718), -INT16_C(  2701),  INT16_C( 32400), -INT16_C( 15368), -INT16_C(  3028)
                , -INT16_C(  2550),  INT16_C( 22755), -INT16_C( 17811),  INT16_C( 11826),  INT16_C( 31804), -INT16_C( 24380), -INT16_C( 27043), -INT16_C( 15090)
                , -INT16_C(  1505),  INT16_C( 12017),  INT16_C( 11601),  INT16_C( 24855),  INT16_C( 31836),  INT16_C(  9265),  INT16_C( 30129),  INT16_C( 27986)
                , -INT16_C(  5445),  INT16_C( 19882), -INT16_C( 25843), -INT16_C( 16517),  INT16_C( 31152),  INT16_C( 22659), -INT16_C( 26362),  INT16_C( 28573)
                , -INT16_C(  7443), -INT16_C( 15755),  INT16_C(  1936),  INT16_C( 20216), -INT16_C( 13308),  INT16_C(  9650),  INT16_C( 25279), -INT16_C( 12268) } },
    {      /* q */ {UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0) },
      /* x */ {-INT16_C( 25614), -INT16_C(  9315), -INT16_C( 30909), -INT16_C( 27386), -INT16_C( 19186), -INT16_C( 27463),  INT16_C( 14316),  INT16_C(  7021)
                ,  INT16_C( 24799),  INT16_C( 29592), -INT16_C(  2885),  INT16_C(  8517), -INT16_C(  5799),  INT16_C( 26346),  INT16_C( 28584),  INT16_C( 14597)
                , -INT16_C( 27917),  INT16_C(  2272), -INT16_C( 30714),  INT16_C( 22691),  INT16_C(   197),  INT16_C( 17464),  INT16_C( 29246),  INT16_C( 21376)
                , -INT16_C( 23365), -INT16_C(  3909), -INT16_C( 24736),  INT16_C(  4539),  INT16_C(  7429), -INT16_C(  4593), -INT16_C( 14078), -INT16_C( 19952)
                ,  INT16_C(  5523),  INT16_C( 31195),  INT16_C( 24874),  INT16_C( 20185), -INT16_C( 14724),  INT16_C( 26860),  INT16_C( 10774),  INT16_C(  7852)
                , -INT16_C( 21693), -INT16_C( 32397), -INT16_C(  3256), -INT16_C(  9424),  INT16_C( 21225),  INT16_C( 14009),  INT16_C( 15948),  INT16_C( 31564)
                , -INT16_C( 27684), -INT16_C( 14090), -INT16_C( 31299), -INT16_C( 25467),  INT16_C( 10303), -INT16_C(  1562),  INT16_C( 28511), -INT16_C( 17849)
                , -INT16_C(  4733), -INT16_C(  7158),  INT16_C(  5242),  INT16_C( 28331),  INT16_C(  5160), -INT16_C( 26482),  INT16_C( 19676),  INT16_C(  4967) },
      /* u */ {-INT16_C(  1055), -INT16_C(  9455), -INT16_C( 11721),  INT16_C( 14666),  INT16_C( 16322), -INT16_C(  3647),  INT16_C(  7029),  INT16_C( 18944)
                , -INT16_C( 25956), -INT16_C( 27923),  INT16_C( 18478), -INT16_C(  7307), -INT16_C( 19546),  INT16_C(  4764), -INT16_C(  1928),  INT16_C( 20276)
                , -INT16_C( 18083), -INT16_C( 20410), -INT16_C( 32679),  INT16_C( 24683), -INT16_C(  6285), -INT16_C( 13261),  INT16_C( 20281),  INT16_C(  8976)
                , -INT16_C( 19529),  INT16_C(  2015),  INT16_C( 11171), -INT16_C(   112),  INT16_C( 12366), -INT16_C( 11156),  INT16_C( 15929), -INT16_C( 25468)
                , -INT16_C( 16895), -INT16_C( 21731), -INT16_C( 31289), -INT16_C(  9024), -INT16_C( 28368), -INT16_C( 25034), -INT16_C( 28692),  INT16_C( 13022)
                , -INT16_C( 30395), -INT16_C( 15601), -INT16_C( 25473),  INT16_C( 24738),  INT16_C( 18482), -INT16_C( 16266),  INT16_C(  2214),  INT16_C(  1998)
                , -INT16_C( 20966),  INT16_C( 17309), -INT16_C( 18538),  INT16_C( 16977),  INT16_C( 10485),  INT16_C( 11117),  INT16_C( 26812), -INT16_C( 23038)
                ,  INT16_C( 11319), -INT16_C(  9928), -INT16_C(  7002), -INT16_C( 19461), -INT16_C(  2565), -INT16_C(  1367),  INT16_C(  2589),  INT16_C( 29586) },
      /* r */ {-INT16_C( 25839), -INT16_C(  9315), -INT16_C( 19133),  INT16_C( 23484), -INT16_C( 19186), -INT16_C( 23879),  INT16_C( 14199),  INT16_C(  7021)
                , -INT16_C( 14781), -INT16_C(  8040), -INT16_C(  2931),  INT16_C( 15685),  INT16_C( 13657),  INT16_C( 21738),  INT16_C( 28464),  INT16_C( 14801)
                , -INT16_C(  9741),  INT16_C( 22682),  INT16_C(  1798),  INT16_C( 22584),  INT16_C(  6597),  INT16_C( 30725),  INT16_C(  8965),  INT16_C( 12400)
                , -INT16_C(  3653), -INT16_C(  3909),  INT16_C( 29629),  INT16_C(  4539),  INT16_C(  7607),  INT16_C(  6415), -INT16_C( 14078), -INT16_C( 19952)
                ,  INT16_C(  5523),  INT16_C( 31195),  INT16_C( 24931),  INT16_C( 29401),  INT16_C( 13692),  INT16_C( 26860), -INT16_C( 26090), -INT16_C(  5170)
                ,  INT16_C(  8515), -INT16_C( 16796), -INT16_C(  3256), -INT16_C(  9424),  INT16_C( 21175),  INT16_C( 30275),  INT16_C( 13734),  INT16_C( 31564)
                , -INT16_C(  6718), -INT16_C( 31399), -INT16_C( 12611),  INT16_C( 23092), -INT16_C(   182), -INT16_C(  1562),  INT16_C( 28579), -INT16_C( 17849)
                , -INT16_C(  4788),  INT16_C(  2570),  INT16_C( 12154),  INT16_C( 28331),  INT16_C(  7725), -INT16_C( 26395),  INT16_C( 19647), -INT16_C( 24619) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vh_condnac_QnVhVh(q, x, u);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_condnac_QVwVw(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int32_t x[32]; int32_t u[32]; int32_t r[32];
  } test_vec[] = {
    {      /* q */ {UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0) },
      /* x */ {-INT32_C(  470401831),  INT32_C(  630162507), -INT32_C(  787051454),  INT32_C(  380591876)
                , -INT32_C( 1364071351), -INT32_C( 1915381964), -INT32_C(  354410201), -INT32_C( 1774014607)
                , -INT32_C(  359319245),  INT32_C(  213901012), -INT32_C(  250144852), -INT32_C(  366218151)
                ,  INT32_C( 1193668133),  INT32_C( 1953046226),  INT32_C( 1310712499),  INT32_C( 1081376034)
                ,  INT32_C(  227879450), -INT32_C( 2001419769),  INT32_C( 1090610584), -INT32_C(  516282550)
                ,  INT32_C( 1495021293), -INT32_C( 1828983253),  INT32_C( 1543647385), -INT32_C( 1293298926)
                ,  INT32_C( 1029887142), -INT32_C( 1296103094),  INT32_C( 1390077266), -INT32_C(  874676196)
                , -INT32_C(  774368843),  INT32_C( 1922386966), -INT32_C( 1024013992),  INT32_C(  267089347) },
      /* u */ {-INT32_C(  391510872),  INT32_C(  954581283), -INT32_C( 1866484430), -INT32_C( 1930549375)
                ,  INT32_C( 2017032105), -INT32_C( 1574220980), -INT32_C( 2107309738), -INT32_C(  431625188)
                ,  INT32_C( 1243663275),  INT32_C( 2063413359),  INT32_C(  937993780),  INT32_C( 1562118459)
                ,  INT32_C( 1646212574),  INT32_C( 1589204106), -INT32_C(  984451052), -INT32_C(  341187984)
                , -INT32_C(  795623385), -INT32_C(  874501588),  INT32_C( 1429013127), -INT32_C(  569028192)
                , -INT32_C( 1814802216),  INT32_C(  202524669), -INT32_C(  464531235),  INT32_C(  816754851)
                , -INT32_C( 1879126109),  INT32_C(  311318595),  INT32_C( 1224921012),  INT32_C(   81435610)
                , -INT32_C(  494312415),  INT32_C(  599270604),  INT32_C(  466512101),  INT32_C( 2140418126) },
      /* r */ {-INT32_C(  481542951),  INT32_C(  631866408), -INT32_C(  782857150),  INT32_C(  381761411)
                ,  INT32_C(  917599392), -INT32_C( 1918200012),  INT32_C( 1759519015), -INT32_C( 1342389391)
                , -INT32_C( 1602995917),  INT32_C(  214085221), -INT32_C(  248614536), -INT32_C( 1928336610)
                ,  INT32_C( 1191622693),  INT32_C(  363798088),  INT32_C( 1322085043),  INT32_C( 1087012274)
                ,  INT32_C(  227895795), -INT32_C( 1126918181), -INT32_C(  352230504),  INT32_C(   54142794)
                , -INT32_C(  985143571), -INT32_C( 1830181333),  INT32_C( 1555193753), -INT32_C( 1304747409)
                , -INT32_C( 1385953882), -INT32_C( 1305474742),  INT32_C(  165156178), -INT32_C(  956137444)
                , -INT32_C(  774328907),  INT32_C( 1323125782), -INT32_C( 1477025704),  INT32_C(  257377653) } },
    {      /* q */ {UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0) },
      /* x */ {-INT32_C( 1889090010),  INT32_C(  424658876),  INT32_C( 1851118196),  INT32_C(  688660280)
                , -INT32_C(  183140200),  INT32_C( 1453947094), -INT32_C( 1532723453), -INT32_C(  170442645)
                , -INT32_C( 1564418992),  INT32_C( 1490723309), -INT32_C( 1159116973), -INT32_C(  960699717)
                ,  INT32_C( 1615995806), -INT32_C( 1050395801), -INT32_C( 2032404537), -INT32_C( 1317884804)
                ,  INT32_C(  286081018),  INT32_C( 1784147578),  INT32_C( 1001531923),  INT32_C( 1201805093)
                ,  INT32_C( 1668197753), -INT32_C( 1142484250), -INT32_C(  169530586), -INT32_C(  959534288)
                ,  INT32_C( 1396361014), -INT32_C(  597211503),  INT32_C(  465820640),  INT32_C(  523932955)
                ,  INT32_C(  158587588), -INT32_C(     415737), -INT32_C(  737442023), -INT32_C( 1401497798) },
      /* u */ {-INT32_C( 1971376224), -INT32_C( 1485636979), -INT32_C(  579660365), -INT32_C(  117857891)
                , -INT32_C(  182857011), -INT32_C( 1783165529), -INT32_C(  530109678), -INT32_C(  378836818)
                ,  INT32_C( 1400061778),  INT32_C( 1637281957), -INT32_C(  220833328),  INT32_C(  212414857)
                ,  INT32_C( 1316452505), -INT32_C(  311830522),  INT32_C( 1895839092), -INT32_C( 1882987140)
                , -INT32_C( 1566272601),  INT32_C(  873473638), -INT32_C(  874213288), -INT32_C(  765016118)
                ,  INT32_C(  209775452), -INT32_C( 1274436049),  INT32_C(  364852914),  INT32_C( 1148572949)
                ,  INT32_C(  364429693),  INT32_C(  991637078),  INT32_C(  181721908),  INT32_C(  560527134)
                ,  INT32_C(  987109190),  INT32_C(  103456265),  INT32_C( 1804769994),  INT32_C( 1970078130) },
      /* r */ { INT32_C(   82286214),  INT32_C(  433899311),  INT32_C( 1860353140),  INT32_C(  806124856)
                , -INT32_C(     294760),  INT32_C( 1453947094), -INT32_C( 1532734479),  INT32_C(  215433323)
                , -INT32_C( 1564435376), -INT32_C(  136662712), -INT32_C( 1173207165), -INT32_C(  960699854)
                ,  INT32_C(  290630405), -INT32_C( 1050395807),  INT32_C(  366737235),  INT32_C(  561170300)
                ,  INT32_C(  292044627),  INT32_C( 1784147578),  INT32_C( 1875745043),  INT32_C( 1195069275)
                ,  INT32_C( 1676520733), -INT32_C( 1142461210), -INT32_C(  521800666), -INT32_C( 2100384976)
                ,  INT32_C( 1396361145), -INT32_C( 1587079109),  INT32_C(  468648108), -INT32_C(   36596453)
                , -INT32_C(  831268226), -INT32_C(  103872249),  INT32_C( 1752729423), -INT32_C( 1408641656) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vw_condnac_QVwVw(q, x, u);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_condnac_QnVwVw(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int32_t x[32]; int32_t u[32]; int32_t r[32];
  } test_vec[] = {
    {      /* q */ {UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0) },
      /* x */ { INT32_C( 1439337867),  INT32_C(  196915797), -INT32_C(  925587634), -INT32_C(  498051436)
                , -INT32_C( 1731537416), -INT32_C(  479862821),  INT32_C( 1394370986),  INT32_C( 1874138053)
                ,  INT32_C( 1367047073),  INT32_C( 1453404191),  INT32_C(  505998013), -INT32_C(  568244515)
                ,  INT32_C( 1365262416),  INT32_C( 2094530414), -INT32_C( 1044309292), -INT32_C(  895963375)
                , -INT32_C( 1465647883), -INT32_C( 1216244518), -INT32_C(  221586733),  INT32_C(  440789174)
                , -INT32_C( 1364457866), -INT32_C( 1262214752), -INT32_C( 2140785606), -INT32_C(  222084647)
                , -INT32_C( 1515345292), -INT32_C(   34589275), -INT32_C(  617259094), -INT32_C(  252864141)
                ,  INT32_C( 1945123461),  INT32_C(  748269378), -INT32_C( 1754344187),  INT32_C( 1740500628) },
      /* u */ { INT32_C(  508092562),  INT32_C( 1788557632),  INT32_C(  707020958),  INT32_C( 1840943251)
                , -INT32_C( 1937360420), -INT32_C( 1180575606),  INT32_C( 1405794796), -INT32_C( 1894357431)
                , -INT32_C(  589306121), -INT32_C(  633198485), -INT32_C( 1413196278),  INT32_C( 1346105530)
                , -INT32_C( 1808846597), -INT32_C(  875746615), -INT32_C( 1774770185), -INT32_C(  540187007)
                ,  INT32_C( 1036306144), -INT32_C(  957283304),  INT32_C( 1461231206), -INT32_C(  505524660)
                ,  INT32_C( 2105468704),  INT32_C( 1140753322), -INT32_C(  747106536),  INT32_C( 1127495608)
                , -INT32_C(   86307459), -INT32_C(  779450268), -INT32_C(  394704183),  INT32_C( 1286240810)
                ,  INT32_C( 1653122406),  INT32_C(  858413972),  INT32_C( 1495459057),  INT32_C( 1874077733) },
      /* r */ { INT32_C(  931245195), -INT32_C( 1591627243), -INT32_C( 1632590002), -INT32_C(  493529599)
                ,  INT32_C(  205837596),  INT32_C(  700768081),  INT32_C( 1397844394), -INT32_C(  524964411)
                ,  INT32_C( 1954256033),  INT32_C( 2090938548),  INT32_C(  505975997), -INT32_C( 1927195101)
                , -INT32_C( 1117765547), -INT32_C( 1311255387), -INT32_C( 1047924012), -INT32_C(  895963375)
                ,  INT32_C( 1789132021), -INT32_C(  259943230), -INT32_C(  221627181),  INT32_C(  944085686)
                ,  INT32_C(  833363798),  INT32_C( 1891901856), -INT32_C( 2140785606), -INT32_C( 1346172383)
                , -INT32_C( 1429037833),  INT32_C(  744860993), -INT32_C(  617259039), -INT32_C(  264005303)
                ,  INT32_C( 1945123461),  INT32_C(  745516866),  INT32_C( 1047457812), -INT32_C(  121770385) } },
    {      /* q */ {UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0) },
      /* x */ {-INT32_C(  214332461),  INT32_C(  739281328),  INT32_C( 1235025648),  INT32_C(  732418016)
                ,  INT32_C(  116537817), -INT32_C(  490092331),  INT32_C( 1512794529), -INT32_C( 1124255358)
                , -INT32_C( 1320097439),  INT32_C(   10320956),  INT32_C( 2083214310), -INT32_C(  738311845)
                ,  INT32_C( 1877807472), -INT32_C(  497688206), -INT32_C( 1341796298),  INT32_C(  149656564)
                ,  INT32_C( 1474307458),  INT32_C(  574076772), -INT32_C(  857308996),  INT32_C(  135371573)
                , -INT32_C(  195219625),  INT32_C( 1347307213),  INT32_C( 2006397929), -INT32_C( 1780861325)
                , -INT32_C(  326512095), -INT32_C( 1343553486), -INT32_C( 1579019510), -INT32_C(  271970236)
                , -INT32_C( 1817517856), -INT32_C( 1301312940), -INT32_C(  141338719),  INT32_C(  684022668) },
      /* u */ { INT32_C( 1404180731), -INT32_C( 1531046824),  INT32_C(  279589657),  INT32_C(   13708117)
                , -INT32_C( 1390804608),  INT32_C( 2108893529),  INT32_C(   28206481), -INT32_C( 1334724117)
                ,  INT32_C(   19522145),  INT32_C(  633189757),  INT32_C( 1910589855), -INT32_C( 1497582542)
                ,  INT32_C(  660102805), -INT32_C(  649885027),  INT32_C( 1073081541), -INT32_C( 1145188478)
                ,  INT32_C(  883310265), -INT32_C( 1408990098),  INT32_C( 1494126988), -INT32_C(  535082396)
                ,  INT32_C(  525536378),  INT32_C(   24570116),  INT32_C( 1609151238), -INT32_C(  594863056)
                ,  INT32_C(   41996666),  INT32_C(  812643917),  INT32_C(  184169669), -INT32_C(   54054776)
                , -INT32_C(  330886144),  INT32_C( 1997547051), -INT32_C( 1897294465), -INT32_C( 1945265239) },
      /* r */ {-INT32_C(  214332461),  INT32_C(  743601584),  INT32_C(  949812951),  INT32_C(  735487115)
                ,  INT32_C(  116537689), -INT32_C(  501833771),  INT32_C( 1518142480),  INT32_C(  217939863)
                , -INT32_C( 1336874655), -INT32_C(  622887876),  INT32_C(  172624614),  INT32_C(  771657051)
                ,  INT32_C( 1217704560), -INT32_C(  497723691),  INT32_C( 1880089398),  INT32_C( 1294832498)
                ,  INT32_C(  601892297),  INT32_C(  574076918), -INT32_C(  857308996),  INT32_C(  655465269)
                , -INT32_C(  715316649),  INT32_C( 1347307213),  INT32_C( 2007859433), -INT32_C( 1780861325)
                , -INT32_C(  368508761),  INT32_C( 2146107442), -INT32_C( 1763189238), -INT32_C(  285024444)
                , -INT32_C( 1822170912),  INT32_C(  996107348),  INT32_C( 1754486562), -INT32_C( 1665704989) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vw_condnac_QnVwVw(q, x, u);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(condnac_QVbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(condnac_QnVbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(condnac_QVhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(condnac_QnVhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(condnac_QVwVw)
SIMDE_TEST_FUNC_LIST_ENTRY(condnac_QnVwVw)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
