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

#define SIMDE_TEST_HEXAGON_HVX_INSN vcondacc

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vcondacc.h"

static int
test_simde_condacc_QVbVb(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int8_t x[128]; int8_t u[128]; int8_t r[128];
  } test_vec[] = {
    {      /* q */ {UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0) },
      /* x */ { INT8_C(  85),  INT8_C(  51),  INT8_C(  66), -INT8_C(  50),  INT8_C(  60), -INT8_C(  31), -INT8_C(  30), -INT8_C(  67), -INT8_C(  35),  INT8_C(   3),  INT8_C(   1), -INT8_C(  34), -INT8_C(  93),  INT8_C( 127),  INT8_C(  75), -INT8_C(  90)
                ,  INT8_C(  43), -INT8_C(  89),  INT8_C(   5),  INT8_C(  54),  INT8_C(  16), -INT8_C(  62), -INT8_C( 108),  INT8_C(  35), -INT8_C(  82), -INT8_C(  67), -INT8_C(  67),  INT8_C(  24),  INT8_C(  79),  INT8_C(  91), -INT8_C(  24), -INT8_C(  75)
                ,  INT8_C(  31),  INT8_C( 119), -INT8_C(  98),  INT8_C(   7),  INT8_C(  23),  INT8_C(  75), -INT8_C(  96),  INT8_C(  70), -INT8_C( 118),  INT8_C( 116),  INT8_C(  94),  INT8_C(  63), -INT8_C(  81),  INT8_C(  33),  INT8_C(  40), -INT8_C(  97)
                , -INT8_C(  19), -INT8_C(  10),  INT8_C( 102),  INT8_C(  29),  INT8_C(  60),  INT8_C( 100), -INT8_C(  21), -INT8_C(  68),  INT8_C(  76), -INT8_C(  99),  INT8_C(  93), -INT8_C( 122),  INT8_C( 118), -INT8_C(  90), -INT8_C(  56),  INT8_C(  33)
                , -INT8_C(  87), -INT8_C(  43),  INT8_C(  34),  INT8_C(  15), -INT8_C(  15), -INT8_C(  90),  INT8_C( 126),  INT8_C( 121), -INT8_C( 107), -INT8_C(  66), -INT8_C(  64), -INT8_C(  91),  INT8_C(  69), -INT8_C( 112),  INT8_C(   8),  INT8_C( 121)
                , -INT8_C(  35), -INT8_C( 101), -INT8_C( 113), -INT8_C(  60),  INT8_C(  96),  INT8_C(  56), -INT8_C(  36),  INT8_C(  96),  INT8_C(  88), -INT8_C(  54), -INT8_C(  47), -INT8_C(  91),  INT8_C(  48), -INT8_C( 113), -INT8_C(  31), -INT8_C(  25)
                , -INT8_C( 112),  INT8_C(   7),  INT8_C( 116),  INT8_C(  92), -INT8_C(   4),  INT8_C(  80), -INT8_C( 100),  INT8_C(   6), -INT8_C(  69),  INT8_C(  90),  INT8_C(  87),  INT8_C( 108), -INT8_C( 104), -INT8_C(   8), -INT8_C(  17),  INT8_C(  52)
                ,  INT8_C(  78),  INT8_C(  69), -INT8_C( 113), -INT8_C(  64),  INT8_C(  61), -INT8_C(  16),  INT8_C( 123), -INT8_C(  15),  INT8_C(  37),  INT8_C(  80),  INT8_C(  43), -INT8_C(  90),  INT8_C(   7), -INT8_C(  28),  INT8_C(  11),  INT8_C(  98) },
      /* u */ { INT8_C(  74), -INT8_C(  43),  INT8_C(  47),  INT8_C(  54),  INT8_C(  19), -INT8_C(   6), -INT8_C(  12), -INT8_C(  60), -INT8_C(  91),  INT8_C(  80), -INT8_C( 128), -INT8_C(  81),  INT8_C( 120),  INT8_C(  59),  INT8_C(  36), -INT8_C( 101)
                ,  INT8_C(  41), -INT8_C(  77),  INT8_C( 124),  INT8_C(  17), -INT8_C(  44),  INT8_C(  61), -INT8_C(  23), -INT8_C(  13), -INT8_C(   9),  INT8_C(  52), -INT8_C(  15),  INT8_C( 101), -INT8_C(  29), -INT8_C(  88), -INT8_C(  13),  INT8_C(   1)
                ,  INT8_C( 102),  INT8_C(  78),  INT8_C(  93), -INT8_C(  43),  INT8_C(  33), -INT8_C( 100),  INT8_C(  90), -INT8_C(  74), -INT8_C(  61), -INT8_C(  97), -INT8_C(  89), -INT8_C(  46), -INT8_C(  33), -INT8_C(  62), -INT8_C(  23), -INT8_C( 117)
                ,  INT8_C( 125), -INT8_C(  71),  INT8_C(  66),  INT8_C(  71),  INT8_C(  41),  INT8_C(  72),  INT8_C(  41),  INT8_C(  13),  INT8_C(  81), -INT8_C( 100), -INT8_C(  77),  INT8_C(  48),  INT8_C(  51), -INT8_C(  50),  INT8_C(  51), -INT8_C(  99)
                ,  INT8_C(  28), -INT8_C(  28), -INT8_C( 118),  INT8_C( 122), -INT8_C(  32), -INT8_C( 109),  INT8_C(  44),  INT8_C(  21),  INT8_C(  85),  INT8_C(  71),  INT8_C(  51),  INT8_C(  34), -INT8_C(  50),  INT8_C( 115), -INT8_C(  91), -INT8_C( 121)
                ,  INT8_C(   1),  INT8_C(  41), -INT8_C(  21), -INT8_C( 103),  INT8_C(  28), -INT8_C(  55), -INT8_C(  30), -INT8_C(  83),  INT8_C(  84), -INT8_C(  62),  INT8_C( 122), -INT8_C(  34),  INT8_C(  66), -INT8_C( 107), -INT8_C(  90), -INT8_C(  53)
                , -INT8_C(  37),  INT8_C(   1), -INT8_C(  42), -INT8_C(   1), -INT8_C(  62),  INT8_C(  50),  INT8_C(  47),  INT8_C(  60),  INT8_C(  39),  INT8_C(   7),  INT8_C(  89), -INT8_C(  50),  INT8_C( 106), -INT8_C(  11), -INT8_C(   5),  INT8_C(  24)
                , -INT8_C( 108),  INT8_C(  24), -INT8_C(  89),  INT8_C(  10), -INT8_C(  37), -INT8_C(  26),  INT8_C(  16),  INT8_C(  35), -INT8_C(  17),  INT8_C(  55), -INT8_C(  52), -INT8_C(  85), -INT8_C(  85),  INT8_C(  41), -INT8_C(   2),  INT8_C(  42) },
      /* r */ {-INT8_C(  97),  INT8_C(  51),  INT8_C(  66), -INT8_C(  50),  INT8_C(  60), -INT8_C(  31), -INT8_C(  30), -INT8_C( 127), -INT8_C( 126),  INT8_C(  83),  INT8_C(   1), -INT8_C( 115),  INT8_C(  27),  INT8_C( 127),  INT8_C(  75), -INT8_C(  90)
                ,  INT8_C(  43),  INT8_C(  90),  INT8_C(   5),  INT8_C(  71), -INT8_C(  28), -INT8_C(   1),  INT8_C( 125),  INT8_C(  35), -INT8_C(  82), -INT8_C(  67), -INT8_C(  67),  INT8_C(  24),  INT8_C(  50),  INT8_C(  91), -INT8_C(  24), -INT8_C(  74)
                ,  INT8_C(  31), -INT8_C(  59), -INT8_C(   5),  INT8_C(   7),  INT8_C(  56),  INT8_C(  75), -INT8_C(   6),  INT8_C(  70), -INT8_C( 118),  INT8_C( 116),  INT8_C(   5),  INT8_C(  17), -INT8_C(  81),  INT8_C(  33),  INT8_C(  17), -INT8_C(  97)
                ,  INT8_C( 106), -INT8_C(  81), -INT8_C(  88),  INT8_C(  29),  INT8_C( 101),  INT8_C( 100), -INT8_C(  21), -INT8_C(  55),  INT8_C(  76),  INT8_C(  57),  INT8_C(  93), -INT8_C(  74), -INT8_C(  87), -INT8_C(  90), -INT8_C(  56),  INT8_C(  33)
                , -INT8_C(  59), -INT8_C(  71),  INT8_C(  34),  INT8_C(  15), -INT8_C(  47),  INT8_C(  57), -INT8_C(  86),  INT8_C( 121), -INT8_C( 107), -INT8_C(  66), -INT8_C(  13), -INT8_C(  91),  INT8_C(  69), -INT8_C( 112),  INT8_C(   8),  INT8_C(   0)
                , -INT8_C(  34), -INT8_C( 101),  INT8_C( 122), -INT8_C(  60),  INT8_C( 124),  INT8_C(  56), -INT8_C(  36),  INT8_C(  13), -INT8_C(  84), -INT8_C(  54), -INT8_C(  47), -INT8_C(  91),  INT8_C( 114), -INT8_C( 113), -INT8_C(  31), -INT8_C(  25)
                ,  INT8_C( 107),  INT8_C(   7),  INT8_C(  74),  INT8_C(  92), -INT8_C(  66),  INT8_C(  80), -INT8_C(  53),  INT8_C(  66), -INT8_C(  69),  INT8_C(  97),  INT8_C(  87),  INT8_C(  58), -INT8_C( 104), -INT8_C(  19), -INT8_C(  22),  INT8_C(  76)
                , -INT8_C(  30),  INT8_C(  93), -INT8_C( 113), -INT8_C(  54),  INT8_C(  24), -INT8_C(  16), -INT8_C( 117),  INT8_C(  20),  INT8_C(  37), -INT8_C( 121),  INT8_C(  43), -INT8_C(  90),  INT8_C(   7), -INT8_C(  28),  INT8_C(   9),  INT8_C(  98) } },
    {      /* q */ {UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255) },
      /* x */ {-INT8_C(  83),  INT8_C( 103),  INT8_C(  43), -INT8_C(  11),  INT8_C(  93), -INT8_C( 127), -INT8_C( 102),  INT8_C( 104), -INT8_C(  93),  INT8_C(  18),  INT8_C(   7), -INT8_C( 111), -INT8_C(  48), -INT8_C(  21), -INT8_C(  22),  INT8_C(  30)
                ,  INT8_C( 114), -INT8_C(  70), -INT8_C(  32),  INT8_C(   8),  INT8_C(  31),  INT8_C(  67), -INT8_C(  46), -INT8_C(  32), -INT8_C( 103),  INT8_C( 112), -INT8_C(  23), -INT8_C(  49),  INT8_C(  61), -INT8_C(  17), -INT8_C( 113), -INT8_C(  38)
                , -INT8_C(  33),  INT8_C(   2), -INT8_C(  73), -INT8_C( 102), -INT8_C(  63), -INT8_C(  33),  INT8_C(  39), -INT8_C( 110),  INT8_C(  69), -INT8_C(  18), -INT8_C(  36), -INT8_C(  11),  INT8_C(  50), -INT8_C(   4), -INT8_C(  19), -INT8_C( 107)
                , -INT8_C(  76), -INT8_C(  94),  INT8_C(  90),  INT8_C(  30), -INT8_C(  11), -INT8_C( 102),  INT8_C(  59), -INT8_C( 104), -INT8_C(  88), -INT8_C(  64),  INT8_C(  68),  INT8_C(  60), -INT8_C(  18), -INT8_C(  95), -INT8_C(  43), -INT8_C(  10)
                , -INT8_C(  25),  INT8_C( 125), -INT8_C(  61), -INT8_C(  38), -INT8_C(  12), -INT8_C(  93),  INT8_C( 103), -INT8_C( 123),  INT8_C(  94), -INT8_C(  13),  INT8_C(  78), -INT8_C(  83), -INT8_C( 110),  INT8_C( 113), -INT8_C(  70), -INT8_C(  92)
                ,  INT8_C(  95),  INT8_C(  70),  INT8_C(  59),  INT8_C( 101), -INT8_C(  27),  INT8_C(  92), -INT8_C(  65), -INT8_C(  58),  INT8_C(  17), -INT8_C( 108), -INT8_C( 124), -INT8_C(  86),  INT8_C(  27),  INT8_C(  31), -INT8_C(  92),  INT8_C(  98)
                , -INT8_C(  52),  INT8_C(  21), -INT8_C( 116),  INT8_C(  23),  INT8_C(  53),  INT8_C(  76), -INT8_C( 123), -INT8_C(   8),  INT8_C( 101),  INT8_C(  53), -INT8_C( 103),  INT8_C(  16), -INT8_C(  37), -INT8_C( 119), -INT8_C(  67),  INT8_C(  37)
                ,  INT8_C(  69), -INT8_C(  51),  INT8_C(  74),  INT8_C(  18), -INT8_C( 124), -INT8_C(  60), -INT8_C(  98), -INT8_C(  34),  INT8_C(  51), -INT8_C( 127), -INT8_C(  43), -INT8_C(  87), -INT8_C(  53),  INT8_C(  28), -INT8_C(  50),  INT8_C(  43) },
      /* u */ { INT8_C(  49), -INT8_C( 110),  INT8_C(  99),  INT8_C(  77),  INT8_C(  75),  INT8_C(  80),  INT8_C(  43),  INT8_C( 107),  INT8_C( 127), -INT8_C(  46), -INT8_C(  25),  INT8_C(  14),  INT8_C( 115),  INT8_C(  66), -INT8_C( 106), -INT8_C(  58)
                ,  INT8_C(  24), -INT8_C(  62),  INT8_C( 101), -INT8_C( 115), -INT8_C(  34), -INT8_C(  81),  INT8_C(  74), -INT8_C(  65),  INT8_C(  37), -INT8_C( 109),  INT8_C( 107),  INT8_C(  60), -INT8_C(  39), -INT8_C(  24),  INT8_C(  43),  INT8_C(  60)
                , -INT8_C(  61),  INT8_C(  19), -INT8_C(  63), -INT8_C(  22), -INT8_C(  22), -INT8_C(  77), -INT8_C(  79), -INT8_C(  20),  INT8_C(  43), -INT8_C(  90), -INT8_C(  34),  INT8_C(  15), -INT8_C(  63),  INT8_C( 102),  INT8_C(   1), -INT8_C(  98)
                , -INT8_C(  73),  INT8_C(  42),  INT8_C(  66),  INT8_C(  58),  INT8_C(  21), -INT8_C(  74),  INT8_C(  70),  INT8_C(  11), -INT8_C( 112), -INT8_C(  34), -INT8_C(   8),  INT8_C(  50),  INT8_C(  30),  INT8_C(  61), -INT8_C(  15),  INT8_C(  51)
                , -INT8_C(  70), -INT8_C( 107), -INT8_C(  84), -INT8_C( 101), -INT8_C(  97),  INT8_C( 105), -INT8_C(  62),  INT8_C(  87),  INT8_C( 122), -INT8_C(   7), -INT8_C(  50),  INT8_C(  77),  INT8_C(  47),  INT8_C( 119),  INT8_C(  23), -INT8_C(  13)
                , -INT8_C(  71),  INT8_C(  83),  INT8_C(  55), -INT8_C(  38), -INT8_C( 104), -INT8_C(  87), -INT8_C(  54),  INT8_C(   8),  INT8_C(  67), -INT8_C(  96), -INT8_C(  85),  INT8_C(  10),  INT8_C(  33),  INT8_C(  63), -INT8_C( 107), -INT8_C(  33)
                , -INT8_C(  22),  INT8_C(  80),  INT8_C(  88), -INT8_C( 103),  INT8_C(  67), -INT8_C(   5),  INT8_C( 101), -INT8_C( 103), -INT8_C(  29),  INT8_C(  92),  INT8_C(  16),  INT8_C(  51), -INT8_C(  33), -INT8_C(  28),  INT8_C(  61), -INT8_C( 117)
                , -INT8_C(  80), -INT8_C(  39),  INT8_C(  25), -INT8_C(  12),  INT8_C( 117), -INT8_C(  65), -INT8_C( 119),  INT8_C(   0),  INT8_C(  62),  INT8_C( 120), -INT8_C(  39),  INT8_C( 104), -INT8_C( 102), -INT8_C(  23),  INT8_C( 123), -INT8_C(  17) },
      /* r */ {-INT8_C(  34),  INT8_C( 103), -INT8_C( 114),  INT8_C(  66), -INT8_C(  88), -INT8_C(  47), -INT8_C(  59), -INT8_C(  45), -INT8_C(  93),  INT8_C(  18), -INT8_C(  18), -INT8_C( 111), -INT8_C(  48), -INT8_C(  21), -INT8_C(  22), -INT8_C(  28)
                ,  INT8_C( 114),  INT8_C( 124),  INT8_C(  69),  INT8_C(   8), -INT8_C(   3),  INT8_C(  67),  INT8_C(  28), -INT8_C(  32), -INT8_C(  66),  INT8_C(   3), -INT8_C(  23), -INT8_C(  49),  INT8_C(  61), -INT8_C(  41), -INT8_C( 113), -INT8_C(  38)
                , -INT8_C(  33),  INT8_C(   2), -INT8_C(  73), -INT8_C( 102), -INT8_C(  63), -INT8_C( 110), -INT8_C(  40), -INT8_C( 110),  INT8_C(  69), -INT8_C(  18), -INT8_C(  36), -INT8_C(  11),  INT8_C(  50),  INT8_C(  98), -INT8_C(  19),  INT8_C(  51)
                ,  INT8_C( 107), -INT8_C(  52),  INT8_C(  90),  INT8_C(  88), -INT8_C(  11),  INT8_C(  80),  INT8_C(  59), -INT8_C(  93),  INT8_C(  56), -INT8_C(  64),  INT8_C(  68),  INT8_C( 110),  INT8_C(  12), -INT8_C(  34), -INT8_C(  58),  INT8_C(  41)
                , -INT8_C(  95),  INT8_C( 125),  INT8_C( 111), -INT8_C(  38), -INT8_C( 109), -INT8_C(  93),  INT8_C( 103), -INT8_C( 123), -INT8_C(  40), -INT8_C(  20),  INT8_C(  78), -INT8_C(  83), -INT8_C( 110),  INT8_C( 113), -INT8_C(  70), -INT8_C(  92)
                ,  INT8_C(  24),  INT8_C(  70),  INT8_C(  59),  INT8_C(  63), -INT8_C(  27),  INT8_C(  92), -INT8_C( 119), -INT8_C(  50),  INT8_C(  84),  INT8_C(  52),  INT8_C(  47), -INT8_C(  86),  INT8_C(  60),  INT8_C(  31), -INT8_C(  92),  INT8_C(  98)
                , -INT8_C(  74),  INT8_C( 101), -INT8_C( 116),  INT8_C(  23),  INT8_C(  53),  INT8_C(  76), -INT8_C( 123), -INT8_C(   8),  INT8_C( 101), -INT8_C( 111), -INT8_C(  87),  INT8_C(  16), -INT8_C(  70),  INT8_C( 109), -INT8_C(  67), -INT8_C(  80)
                ,  INT8_C(  69), -INT8_C(  90),  INT8_C(  99),  INT8_C(  18), -INT8_C( 124), -INT8_C(  60), -INT8_C(  98), -INT8_C(  34),  INT8_C(  51), -INT8_C( 127), -INT8_C(  43), -INT8_C(  87),  INT8_C( 101),  INT8_C(  28),  INT8_C(  73),  INT8_C(  26) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vb_condacc_QVbVb(q, x, u);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_condacc_QnVbVb(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int8_t x[128]; int8_t u[128]; int8_t r[128];
  } test_vec[] = {
    {      /* q */ {UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255) },
      /* x */ {-INT8_C(  62), -INT8_C(  40), -INT8_C(  75), -INT8_C(  98),  INT8_C( 122),  INT8_C(  20), -INT8_C( 111),  INT8_C(  75),  INT8_C( 126), -INT8_C(  40), -INT8_C(  70),  INT8_C(  34), -INT8_C(  12),  INT8_C(  90), -INT8_C( 118),  INT8_C(  94)
                ,  INT8_C(  83), -INT8_C(  92), -INT8_C(  35), -INT8_C(  45),  INT8_C(  72),  INT8_C(  98), -INT8_C(  40), -INT8_C(  12), -INT8_C(  42),  INT8_C(  38), -INT8_C( 105),  INT8_C(  19),  INT8_C(  12), -INT8_C(  98),  INT8_C( 113), -INT8_C(  82)
                , -INT8_C(  33), -INT8_C(  40), -INT8_C(  53),  INT8_C(  27),  INT8_C(  42),  INT8_C( 108), -INT8_C( 111), -INT8_C( 128),  INT8_C(  76),  INT8_C(  30), -INT8_C( 108), -INT8_C(  19), -INT8_C( 119),  INT8_C(  93), -INT8_C(  35), -INT8_C(   8)
                ,  INT8_C(  60), -INT8_C(  79),  INT8_C(  83), -INT8_C(  15), -INT8_C(  66), -INT8_C(  26), -INT8_C( 105), -INT8_C(  22), -INT8_C(  35), -INT8_C(   1),  INT8_C(  29), -INT8_C(  90),  INT8_C(  39), -INT8_C( 117), -INT8_C(  40), -INT8_C(  97)
                ,  INT8_C(  62),  INT8_C( 101),  INT8_C(  51), -INT8_C( 106), -INT8_C(   8),  INT8_C(  81), -INT8_C(  53),  INT8_C(  46), -INT8_C(  75),  INT8_C(  77),  INT8_C(  54), -INT8_C(  43),  INT8_C(  16), -INT8_C( 107),  INT8_C(  68), -INT8_C( 106)
                ,  INT8_C( 122),  INT8_C(  32), -INT8_C(  87), -INT8_C( 122), -INT8_C(  63), -INT8_C(  35), -INT8_C(  77), -INT8_C(  50), -INT8_C(  82), -INT8_C(  22), -INT8_C(  49),  INT8_C( 109), -INT8_C(  69),  INT8_C(  50),  INT8_C( 104),  INT8_C(  30)
                ,  INT8_C( 121),  INT8_C(  17), -INT8_C(  18), -INT8_C( 115), -INT8_C( 112),  INT8_C( 113),  INT8_C( 121), -INT8_C(  14),  INT8_C( 109),  INT8_C(  81),  INT8_C(  28), -INT8_C( 105), -INT8_C(  22), -INT8_C( 122), -INT8_C(  41),  INT8_C(  36)
                , -INT8_C(  58), -INT8_C(  67), -INT8_C(  27),  INT8_C(  47), -INT8_C( 103),  INT8_C( 110), -INT8_C(  78), -INT8_C(  48), -INT8_C(  22), -INT8_C(  75),  INT8_C(  15), -INT8_C(   8), -INT8_C(  95), -INT8_C(  42), -INT8_C(  13),  INT8_C( 123) },
      /* u */ { INT8_C(  34), -INT8_C( 110), -INT8_C(  43),  INT8_C(  17), -INT8_C( 109), -INT8_C(  75),  INT8_C(  56),  INT8_C( 103),  INT8_C(  80), -INT8_C(  39), -INT8_C(  83), -INT8_C(  44),  INT8_C( 120), -INT8_C(  81), -INT8_C(  26),  INT8_C(  98)
                ,  INT8_C(  57), -INT8_C(  31),  INT8_C(  47),  INT8_C(  85), -INT8_C(  25), -INT8_C( 100), -INT8_C(  39),  INT8_C(  33), -INT8_C(  93),  INT8_C( 100),  INT8_C(  50), -INT8_C(  25),  INT8_C(  75),  INT8_C(  32),  INT8_C(  16), -INT8_C( 110)
                , -INT8_C(  89), -INT8_C(  37),  INT8_C(  95),  INT8_C(  94),  INT8_C(  72),  INT8_C(  56),  INT8_C( 106), -INT8_C(  19),  INT8_C( 117), -INT8_C(  72),  INT8_C(   8), -INT8_C(  54), -INT8_C(  64),  INT8_C(  46), -INT8_C(  92),  INT8_C(  88)
                , -INT8_C(  84), -INT8_C(  36), -INT8_C(  66),  INT8_C( 124), -INT8_C( 122),  INT8_C(  63), -INT8_C( 110),  INT8_C(  59),  INT8_C( 123), -INT8_C(  71), -INT8_C(  34),  INT8_C( 122),  INT8_C(  76),  INT8_C(  44), -INT8_C(  79),  INT8_C(  97)
                ,  INT8_C(  46),  INT8_C(  35), -INT8_C(   4),  INT8_C(  47), -INT8_C(   8),  INT8_C(  25),  INT8_C(  22), -INT8_C(  24), -INT8_C(  39),  INT8_C( 107), -INT8_C(  48),  INT8_C( 105),  INT8_C(  20), -INT8_C(  41), -INT8_C(  58), -INT8_C(  89)
                ,  INT8_C(  70),  INT8_C(  82), -INT8_C( 126), -INT8_C( 112), -INT8_C(  14), -INT8_C(  65), -INT8_C(  67),  INT8_C(  41),  INT8_C(   6), -INT8_C(  87), -INT8_C(  90), -INT8_C(   2), -INT8_C(  78), -INT8_C(  97), -INT8_C(  61),  INT8_C(  68)
                ,  INT8_C(  63),  INT8_C(  24),  INT8_C(  17),  INT8_C(  95),  INT8_C( 105),  INT8_C(  73),  INT8_C(  54),  INT8_C(  62),  INT8_C(   5), -INT8_C(  41), -INT8_C(   3),  INT8_C(  83),  INT8_C(  78),  INT8_C(   7),  INT8_C(  29),  INT8_C(  66)
                , -INT8_C(  93), -INT8_C(   2),  INT8_C(  42), -INT8_C(  81),  INT8_C(  22), -INT8_C( 109),  INT8_C(  41), -INT8_C(  60), -INT8_C(  27),  INT8_C(  61),  INT8_C(  81),  INT8_C(  16),  INT8_C(  65), -INT8_C(  61),  INT8_C(  71), -INT8_C(  36) },
      /* r */ {-INT8_C(  62),  INT8_C( 106), -INT8_C( 118), -INT8_C(  98),  INT8_C(  13), -INT8_C(  55), -INT8_C(  55),  INT8_C(  75), -INT8_C(  50), -INT8_C(  79), -INT8_C(  70), -INT8_C(  10),  INT8_C( 108),  INT8_C(   9), -INT8_C( 118),  INT8_C(  94)
                , -INT8_C( 116), -INT8_C(  92), -INT8_C(  35), -INT8_C(  45),  INT8_C(  47), -INT8_C(   2), -INT8_C(  40), -INT8_C(  12),  INT8_C( 121), -INT8_C( 118), -INT8_C( 105),  INT8_C(  19),  INT8_C(  12), -INT8_C(  66),  INT8_C( 113), -INT8_C(  82)
                , -INT8_C( 122), -INT8_C(  77),  INT8_C(  42),  INT8_C(  27),  INT8_C(  42),  INT8_C( 108), -INT8_C(   5), -INT8_C( 128),  INT8_C(  76),  INT8_C(  30), -INT8_C( 100), -INT8_C(  19), -INT8_C( 119), -INT8_C( 117), -INT8_C(  35),  INT8_C(  80)
                , -INT8_C(  24), -INT8_C(  79),  INT8_C(  17),  INT8_C( 109),  INT8_C(  68), -INT8_C(  26), -INT8_C( 105),  INT8_C(  37), -INT8_C(  35), -INT8_C(  72),  INT8_C(  29), -INT8_C(  90),  INT8_C(  39), -INT8_C( 117), -INT8_C(  40), -INT8_C(  97)
                ,  INT8_C( 108),  INT8_C( 101),  INT8_C(  51), -INT8_C( 106), -INT8_C(  16),  INT8_C( 106), -INT8_C(  53),  INT8_C(  46), -INT8_C( 114),  INT8_C(  77),  INT8_C(   6), -INT8_C(  43),  INT8_C(  36), -INT8_C( 107),  INT8_C(  68), -INT8_C( 106)
                , -INT8_C(  64),  INT8_C( 114),  INT8_C(  43), -INT8_C( 122), -INT8_C(  63), -INT8_C(  35),  INT8_C( 112), -INT8_C(   9), -INT8_C(  76), -INT8_C( 109), -INT8_C(  49),  INT8_C( 107),  INT8_C( 109), -INT8_C(  47),  INT8_C( 104),  INT8_C(  30)
                ,  INT8_C( 121),  INT8_C(  41), -INT8_C(  18), -INT8_C(  20), -INT8_C( 112),  INT8_C( 113),  INT8_C( 121),  INT8_C(  48),  INT8_C( 114),  INT8_C(  40),  INT8_C(  28), -INT8_C(  22), -INT8_C(  22), -INT8_C( 115), -INT8_C(  41),  INT8_C( 102)
                , -INT8_C(  58), -INT8_C(  67),  INT8_C(  15),  INT8_C(  47), -INT8_C( 103),  INT8_C( 110), -INT8_C(  37), -INT8_C(  48), -INT8_C(  49), -INT8_C(  75),  INT8_C(  96), -INT8_C(   8), -INT8_C(  30), -INT8_C(  42),  INT8_C(  58),  INT8_C( 123) } },
    {      /* q */ {UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0) },
      /* x */ {-INT8_C(  22), -INT8_C(  87), -INT8_C( 128),  INT8_C(  17), -INT8_C(  93), -INT8_C(  97),  INT8_C(  53),  INT8_C(  30),  INT8_C(  72),  INT8_C(  53),  INT8_C(  46), -INT8_C(  24), -INT8_C(  89), -INT8_C(  40),  INT8_C(  11),  INT8_C(  72)
                , -INT8_C(  16), -INT8_C(  70), -INT8_C(   4), -INT8_C( 118),  INT8_C(  59), -INT8_C(   9), -INT8_C(  44),  INT8_C(   2),  INT8_C(  72), -INT8_C( 117), -INT8_C(   2), -INT8_C(  49), -INT8_C(  16), -INT8_C(  40),  INT8_C(  37),  INT8_C(  62)
                , -INT8_C(  87),  INT8_C(  79), -INT8_C(   6), -INT8_C( 105), -INT8_C(  63),  INT8_C(  38), -INT8_C(  26),  INT8_C(  23), -INT8_C(  67), -INT8_C(   9),  INT8_C( 107), -INT8_C( 122), -INT8_C(  72), -INT8_C(  66), -INT8_C(  81),  INT8_C(  64)
                ,  INT8_C( 113), -INT8_C(  67),  INT8_C(  28), -INT8_C(  17), -INT8_C(  19), -INT8_C( 101),  INT8_C(  77), -INT8_C(  84), -INT8_C(  49), -INT8_C(  95), -INT8_C(  27),  INT8_C(  69),  INT8_C(  92), -INT8_C(  88), -INT8_C( 118),  INT8_C( 102)
                ,  INT8_C( 111), -INT8_C(  54),  INT8_C( 117),  INT8_C(  33), -INT8_C(  13),  INT8_C( 103),  INT8_C(  10), -INT8_C( 100), -INT8_C(  69),  INT8_C(  22), -INT8_C(  58), -INT8_C(  27),  INT8_C( 126),  INT8_C(  57), -INT8_C( 115),  INT8_C(  52)
                ,  INT8_C( 123),  INT8_C(  55),  INT8_C(  16),  INT8_C(  20), -INT8_C(  88),  INT8_C( 123), -INT8_C(  15), -INT8_C(  10),  INT8_C( 107),  INT8_C( 124),  INT8_C(  29),  INT8_C(  41), -INT8_C(  95), -INT8_C(   3), -INT8_C(  34), -INT8_C(  18)
                ,  INT8_C(  42), -INT8_C(   7), -INT8_C(  89), -INT8_C(  47),  INT8_C(  99), -INT8_C(  66),  INT8_C(  70), -INT8_C(  42),  INT8_C(  18),  INT8_C(  25), -INT8_C(   5),  INT8_C(  93),  INT8_C(  63),  INT8_C(  16), -INT8_C(  60), -INT8_C(  63)
                , -INT8_C( 108), -INT8_C(  11),  INT8_C(  29), -INT8_C(  56),  INT8_C(  27),  INT8_C(  94),  INT8_C(  24),  INT8_C(  75),  INT8_C(  76), -INT8_C(  68), -INT8_C( 102), -INT8_C(  17),  INT8_C( 106),  INT8_C( 113),  INT8_C(  49),  INT8_C(  57) },
      /* u */ { INT8_C(  21),  INT8_C(   9),  INT8_C(  87),  INT8_C(  69), -INT8_C(  96), -INT8_C(  51),  INT8_C(  51), -INT8_C(   5), -INT8_C(  94), -INT8_C(  99), -INT8_C(  85), -INT8_C( 109),  INT8_C( 108),  INT8_C(   6), -INT8_C(  72),  INT8_C(  61)
                ,  INT8_C(  78),  INT8_C(  68),  INT8_C(  66),  INT8_C(  71), -INT8_C(  40),  INT8_C(  57), -INT8_C(  38), -INT8_C(  70),  INT8_C( 115),  INT8_C(  97), -INT8_C( 119), -INT8_C(  47),  INT8_C(  65),  INT8_C(  53),  INT8_C(  50),  INT8_C(  63)
                , -INT8_C(  98),  INT8_C(  20), -INT8_C(  86),  INT8_C(  64),  INT8_C(  67), -INT8_C( 126),  INT8_C( 115),  INT8_C(  91),  INT8_C( 115),  INT8_C(  53),  INT8_C(  24),  INT8_C(   0), -INT8_C(   3),  INT8_C(  38), -INT8_C(  15),  INT8_C(  83)
                , -INT8_C(  57), -INT8_C( 114), -INT8_C(  61),  INT8_C(  67),  INT8_C(  98), -INT8_C(  81),  INT8_C(  96),  INT8_C(  67), -INT8_C( 117), -INT8_C(  18),  INT8_C( 104),  INT8_C(  21), -INT8_C(  68), -INT8_C(  45),  INT8_C( 107), -INT8_C(  78)
                , -INT8_C(  71), -INT8_C(  18),  INT8_C(  61), -INT8_C(  96),  INT8_C(  20),  INT8_C( 124),  INT8_C(  75), -INT8_C(  47), -INT8_C(  45),  INT8_C(  20),  INT8_C(  90),  INT8_C( 101), -INT8_C(  79),  INT8_C(  31), -INT8_C(  57),  INT8_C(  17)
                , -INT8_C( 117),  INT8_C(  16),  INT8_C(  88), -INT8_C(  29),  INT8_C( 101),  INT8_C(  98),  INT8_C(  47),  INT8_C(  87),  INT8_C(  17),  INT8_C(  53), -INT8_C(  85),  INT8_C(  82), -INT8_C( 112), -INT8_C(   7),  INT8_C(  49), -INT8_C( 128)
                , -INT8_C( 100),  INT8_C( 108), -INT8_C( 116),  INT8_C(  35), -INT8_C(  44), -INT8_C(  81),  INT8_C( 102),  INT8_C(  69), -INT8_C(  39), -INT8_C(  70), -INT8_C( 100), -INT8_C(  54), -INT8_C(  54), -INT8_C(  36),  INT8_C(  67),  INT8_C(  33)
                , -INT8_C( 104),  INT8_C(  66), -INT8_C( 112),  INT8_C(  39),  INT8_C( 119),  INT8_C(  42),  INT8_C(  52),  INT8_C(   4), -INT8_C( 107), -INT8_C(  90), -INT8_C(  55),  INT8_C(  32), -INT8_C( 127), -INT8_C( 108), -INT8_C(   6),  INT8_C( 115) },
      /* r */ {-INT8_C(   1), -INT8_C(  78), -INT8_C( 128),  INT8_C(  17), -INT8_C(  93), -INT8_C(  97),  INT8_C(  53),  INT8_C(  30),  INT8_C(  72), -INT8_C(  46), -INT8_C(  39), -INT8_C(  24), -INT8_C(  89), -INT8_C(  40),  INT8_C(  11), -INT8_C( 123)
                ,  INT8_C(  62), -INT8_C(   2),  INT8_C(  62), -INT8_C( 118),  INT8_C(  59),  INT8_C(  48), -INT8_C(  82),  INT8_C(   2), -INT8_C(  69), -INT8_C(  20), -INT8_C( 121), -INT8_C(  96), -INT8_C(  16),  INT8_C(  13),  INT8_C(  37),  INT8_C(  62)
                ,  INT8_C(  71),  INT8_C(  79), -INT8_C(  92), -INT8_C(  41),  INT8_C(   4), -INT8_C(  88),  INT8_C(  89),  INT8_C(  23),  INT8_C(  48), -INT8_C(   9), -INT8_C( 125), -INT8_C( 122), -INT8_C(  75), -INT8_C(  28), -INT8_C(  96), -INT8_C( 109)
                ,  INT8_C( 113),  INT8_C(  75), -INT8_C(  33),  INT8_C(  50), -INT8_C(  19), -INT8_C( 101),  INT8_C(  77), -INT8_C(  84), -INT8_C(  49), -INT8_C(  95),  INT8_C(  77),  INT8_C(  69),  INT8_C(  92),  INT8_C( 123), -INT8_C( 118),  INT8_C( 102)
                ,  INT8_C( 111), -INT8_C(  72), -INT8_C(  78), -INT8_C(  63), -INT8_C(  13), -INT8_C(  29),  INT8_C(  85),  INT8_C( 109), -INT8_C(  69),  INT8_C(  42), -INT8_C(  58), -INT8_C(  27),  INT8_C( 126),  INT8_C(  88), -INT8_C( 115),  INT8_C(  52)
                ,  INT8_C(   6),  INT8_C(  71),  INT8_C( 104), -INT8_C(   9),  INT8_C(  13), -INT8_C(  35), -INT8_C(  15),  INT8_C(  77),  INT8_C( 107),  INT8_C( 124), -INT8_C(  56),  INT8_C( 123), -INT8_C(  95), -INT8_C(  10),  INT8_C(  15), -INT8_C(  18)
                ,  INT8_C(  42), -INT8_C(   7), -INT8_C(  89), -INT8_C(  47),  INT8_C(  99), -INT8_C(  66), -INT8_C(  84),  INT8_C(  27),  INT8_C(  18),  INT8_C(  25), -INT8_C(   5),  INT8_C(  93),  INT8_C(   9), -INT8_C(  20), -INT8_C(  60), -INT8_C(  63)
                ,  INT8_C(  44),  INT8_C(  55), -INT8_C(  83), -INT8_C(  56),  INT8_C(  27),  INT8_C(  94),  INT8_C(  24),  INT8_C(  79),  INT8_C(  76), -INT8_C(  68), -INT8_C( 102),  INT8_C(  15),  INT8_C( 106),  INT8_C(   5),  INT8_C(  49), -INT8_C(  84) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vb_condacc_QnVbVb(q, x, u);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_condacc_QVhVh(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int16_t x[64]; int16_t u[64]; int16_t r[64];
  } test_vec[] = {
    {      /* q */ {UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255) },
      /* x */ { INT16_C( 11176), -INT16_C( 19133),  INT16_C( 21415),  INT16_C( 10641),  INT16_C( 16170), -INT16_C( 25782),  INT16_C( 25718),  INT16_C(  8954)
                , -INT16_C(  1848),  INT16_C( 14098), -INT16_C( 21602), -INT16_C( 10228),  INT16_C(  9021),  INT16_C( 30701),  INT16_C(  5445), -INT16_C( 23022)
                , -INT16_C( 16842), -INT16_C( 13804), -INT16_C( 17203), -INT16_C(  7252),  INT16_C( 12821), -INT16_C(  7880),  INT16_C( 17788),  INT16_C( 10268)
                ,  INT16_C( 24130), -INT16_C( 12252), -INT16_C( 26260),  INT16_C( 27011), -INT16_C( 25844),  INT16_C( 16858), -INT16_C(  7591), -INT16_C( 11579)
                , -INT16_C( 29245), -INT16_C(  4813),  INT16_C( 23200), -INT16_C( 21656), -INT16_C( 16890), -INT16_C(   560),  INT16_C( 25825), -INT16_C( 21792)
                , -INT16_C( 20252), -INT16_C( 27661), -INT16_C(  1109),  INT16_C(  3788), -INT16_C( 24687),  INT16_C( 10622), -INT16_C( 27033), -INT16_C( 27179)
                ,  INT16_C( 17631), -INT16_C(  3427), -INT16_C( 12989),  INT16_C(  8740),  INT16_C(  2989),  INT16_C( 26929),  INT16_C( 13299),  INT16_C( 13525)
                ,  INT16_C( 20306), -INT16_C( 26710),  INT16_C( 10049), -INT16_C( 23700),  INT16_C( 21909),  INT16_C( 26557), -INT16_C( 29536),  INT16_C( 29280) },
      /* u */ { INT16_C(  1541), -INT16_C( 11398),  INT16_C(  5460), -INT16_C( 19908),  INT16_C( 13659), -INT16_C( 19347),  INT16_C( 25657), -INT16_C( 27453)
                , -INT16_C(  3433), -INT16_C( 30137),  INT16_C( 10796), -INT16_C( 29190), -INT16_C(  3124), -INT16_C(  3909), -INT16_C( 25792),  INT16_C(  8167)
                , -INT16_C(  5278), -INT16_C( 10485),  INT16_C( 14322), -INT16_C( 23186), -INT16_C( 12162),  INT16_C( 25500), -INT16_C(  8459), -INT16_C( 22029)
                , -INT16_C( 12652), -INT16_C( 22229), -INT16_C(  7806), -INT16_C( 30316),  INT16_C(  6927),  INT16_C( 16562), -INT16_C( 24739),  INT16_C(  8682)
                , -INT16_C( 25943),  INT16_C( 26267),  INT16_C( 14298),  INT16_C(  8510),  INT16_C(  3701),  INT16_C(  9980), -INT16_C( 25174),  INT16_C(  9941)
                ,  INT16_C( 21338),  INT16_C( 27075),  INT16_C( 28417), -INT16_C( 17019), -INT16_C( 12925),  INT16_C( 27876),  INT16_C( 29260), -INT16_C( 30301)
                ,  INT16_C( 31485), -INT16_C( 30722),  INT16_C( 15880), -INT16_C( 31065), -INT16_C( 16208), -INT16_C( 19207),  INT16_C(   593), -INT16_C(  4832)
                , -INT16_C( 27123), -INT16_C( 13509), -INT16_C( 30847), -INT16_C( 14387), -INT16_C( 19803), -INT16_C( 19260), -INT16_C(  9579), -INT16_C( 12296) },
      /* r */ { INT16_C( 12717), -INT16_C( 19133),  INT16_C( 26791),  INT16_C( 10641),  INT16_C( 29829),  INT16_C( 20407), -INT16_C( 14161), -INT16_C( 18438)
                , -INT16_C(  5281), -INT16_C( 16039), -INT16_C( 21558), -INT16_C( 10228),  INT16_C(  9021),  INT16_C( 26861), -INT16_C( 20411), -INT16_C( 23022)
                , -INT16_C( 22120), -INT16_C( 24300), -INT16_C( 17203), -INT16_C( 30292),  INT16_C(   533),  INT16_C( 17620),  INT16_C(  9340), -INT16_C( 11761)
                ,  INT16_C( 11478),  INT16_C( 31012),  INT16_C( 31470), -INT16_C(  3197), -INT16_C( 18932),  INT16_C( 16780), -INT16_C( 32330), -INT16_C( 11579)
                , -INT16_C( 29245), -INT16_C(  4658), -INT16_C( 28000), -INT16_C( 13208), -INT16_C( 16773),  INT16_C(  9424),  INT16_C( 25739), -INT16_C( 21792)
                ,  INT16_C(  1252), -INT16_C(   525),  INT16_C( 27308),  INT16_C(  3665), -INT16_C( 24812), -INT16_C( 27010), -INT16_C( 26957),  INT16_C(  8149)
                , -INT16_C( 16417), -INT16_C(  3427), -INT16_C( 12989),  INT16_C(  8907), -INT16_C( 13219),  INT16_C(  7722),  INT16_C( 13124),  INT16_C(  8661)
                , -INT16_C(  6817),  INT16_C( 25258),  INT16_C( 10049), -INT16_C( 23751),  INT16_C(  2106),  INT16_C(  7297), -INT16_C( 29536),  INT16_C( 16984) } },
    {      /* q */ {UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0) },
      /* x */ {-INT16_C( 32196), -INT16_C( 14979),  INT16_C(  3400),  INT16_C(  3705), -INT16_C( 22669), -INT16_C( 19500),  INT16_C(  2616), -INT16_C(  7394)
                ,  INT16_C( 17117),  INT16_C( 19125),  INT16_C(  7931), -INT16_C( 27907),  INT16_C(  6186), -INT16_C(  1343), -INT16_C(  7201), -INT16_C( 17145)
                , -INT16_C( 32441),  INT16_C(  3554), -INT16_C( 29398), -INT16_C(  4900),  INT16_C( 18783),  INT16_C(  4621),  INT16_C(  1591),  INT16_C( 12511)
                ,  INT16_C( 32587),  INT16_C(  9785), -INT16_C(  4195),  INT16_C( 23005),  INT16_C(  1531), -INT16_C( 32687), -INT16_C(  2702),  INT16_C(   235)
                , -INT16_C( 21713),  INT16_C( 14411), -INT16_C( 12117), -INT16_C( 12577),  INT16_C( 24360), -INT16_C(  6286),  INT16_C( 11178),  INT16_C( 26219)
                , -INT16_C( 28709), -INT16_C(  3180),  INT16_C(  1020), -INT16_C( 15112), -INT16_C( 10271), -INT16_C(  1446), -INT16_C( 28146),  INT16_C( 30554)
                , -INT16_C( 13643), -INT16_C(  2848),  INT16_C(   924),  INT16_C( 23998), -INT16_C(  4581),  INT16_C(  7463),  INT16_C( 26205), -INT16_C( 17453)
                , -INT16_C(  6504),  INT16_C( 26488), -INT16_C(  1483), -INT16_C( 13172), -INT16_C( 11139), -INT16_C( 20832), -INT16_C(  2393), -INT16_C( 29062) },
      /* u */ {-INT16_C( 12357),  INT16_C( 11120), -INT16_C( 10543), -INT16_C( 10756), -INT16_C( 17947), -INT16_C( 23430),  INT16_C( 29863),  INT16_C( 20186)
                ,  INT16_C(  8103),  INT16_C( 24794), -INT16_C(  9317), -INT16_C( 28939), -INT16_C( 12971), -INT16_C( 27761), -INT16_C( 11129), -INT16_C( 29983)
                , -INT16_C( 31089), -INT16_C( 24878),  INT16_C( 16221),  INT16_C( 11103),  INT16_C( 22745), -INT16_C( 10866),  INT16_C( 17676), -INT16_C(  4781)
                ,  INT16_C( 27228), -INT16_C( 20067),  INT16_C(  4422),  INT16_C( 25451),  INT16_C(  9740),  INT16_C( 13629), -INT16_C(  9732),  INT16_C(  9769)
                , -INT16_C( 32217),  INT16_C( 28166),  INT16_C( 20873), -INT16_C( 26968),  INT16_C( 17379), -INT16_C(  4266), -INT16_C(  1285),  INT16_C( 17592)
                ,  INT16_C( 11564), -INT16_C(  5495),  INT16_C(  8709), -INT16_C( 31002),  INT16_C( 29538), -INT16_C(  1338),  INT16_C( 32533), -INT16_C( 20207)
                , -INT16_C( 30631),  INT16_C( 22438),  INT16_C( 24085), -INT16_C( 17253),  INT16_C( 11571), -INT16_C(  7759), -INT16_C( 12702),  INT16_C( 24512)
                , -INT16_C( 23509), -INT16_C(   517),  INT16_C(   810),  INT16_C( 18939), -INT16_C( 10483), -INT16_C(  7420), -INT16_C(  9373),  INT16_C( 29122) },
      /* r */ { INT16_C( 20796), -INT16_C( 14867),  INT16_C(  3353),  INT16_C(  3701),  INT16_C( 24920),  INT16_C( 22606),  INT16_C(  2783), -INT16_C(  7176)
                ,  INT16_C( 25220),  INT16_C( 19087),  INT16_C(  7830), -INT16_C( 27907),  INT16_C(  6186), -INT16_C(  1343), -INT16_C(  7322),  INT16_C( 18183)
                ,  INT16_C(  1863), -INT16_C( 21278), -INT16_C( 13177), -INT16_C(  5061), -INT16_C( 23969), -INT16_C(  6387),  INT16_C( 19255),  INT16_C(  7903)
                ,  INT16_C( 32587), -INT16_C( 10439), -INT16_C(  4125),  INT16_C( 23005),  INT16_C( 11271), -INT16_C( 19058), -INT16_C(  2706),  INT16_C( 10219)
                , -INT16_C( 21674),  INT16_C( 14417),  INT16_C(  8756), -INT16_C( 12665),  INT16_C( 24360), -INT16_C( 10638),  INT16_C(  9898), -INT16_C( 21725)
                , -INT16_C( 17145), -INT16_C(  8556),  INT16_C(  9729), -INT16_C( 15138), -INT16_C( 10271), -INT16_C(  1446), -INT16_C( 28125),  INT16_C( 30554)
                , -INT16_C( 13643), -INT16_C(  2848),  INT16_C(   945),  INT16_C(  6846), -INT16_C(  4581),  INT16_C(  7640),  INT16_C( 26303),  INT16_C(  7059)
                , -INT16_C(  6461),  INT16_C( 26488), -INT16_C(  1483), -INT16_C( 13177), -INT16_C( 11126), -INT16_C( 20828), -INT16_C(  2550), -INT16_C( 29124) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vh_condacc_QVhVh(q, x, u);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_condacc_QnVhVh(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int16_t x[64]; int16_t u[64]; int16_t r[64];
  } test_vec[] = {
    {      /* q */ {UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255) },
      /* x */ {-INT16_C( 25095),  INT16_C( 23988),  INT16_C( 18261),  INT16_C( 11237),  INT16_C(  7894), -INT16_C( 24331), -INT16_C( 14872), -INT16_C( 11268)
                , -INT16_C( 11390), -INT16_C( 12543), -INT16_C(   610),  INT16_C( 14574),  INT16_C( 12923),  INT16_C(  8394),  INT16_C(   539),  INT16_C( 28590)
                ,  INT16_C( 20819), -INT16_C( 18455),  INT16_C(  8137), -INT16_C( 14554), -INT16_C( 11538), -INT16_C( 25079), -INT16_C(  2753),  INT16_C( 27760)
                , -INT16_C( 19642), -INT16_C( 30760), -INT16_C(  9782), -INT16_C( 15328), -INT16_C( 20246), -INT16_C(  3238),  INT16_C(   870),  INT16_C( 31660)
                , -INT16_C(  9916),  INT16_C( 11292),  INT16_C( 22541),  INT16_C(  6225),  INT16_C( 10421), -INT16_C(  1069), -INT16_C( 28194),  INT16_C( 20685)
                ,  INT16_C(  9917),  INT16_C( 15724), -INT16_C( 24529), -INT16_C(  7739), -INT16_C( 12135), -INT16_C( 19578),  INT16_C( 12701),  INT16_C( 12140)
                , -INT16_C(  7080), -INT16_C( 23969), -INT16_C( 26669), -INT16_C( 20275), -INT16_C( 26317),  INT16_C(  4934), -INT16_C(  6167), -INT16_C( 22847)
                ,  INT16_C( 17078), -INT16_C( 16031), -INT16_C( 24795), -INT16_C( 15236), -INT16_C( 18002), -INT16_C( 31572),  INT16_C( 22132), -INT16_C(  8973) },
      /* u */ { INT16_C( 25651),  INT16_C( 23880), -INT16_C( 23838),  INT16_C( 18883), -INT16_C( 12869),  INT16_C( 24495), -INT16_C( 26095), -INT16_C( 28004)
                ,  INT16_C( 21357),  INT16_C( 20875),  INT16_C(  1172),  INT16_C( 22363),  INT16_C( 14341), -INT16_C( 30610),  INT16_C( 15812), -INT16_C( 19547)
                ,  INT16_C( 27690), -INT16_C( 16289), -INT16_C(  1224), -INT16_C(   420),  INT16_C( 15455),  INT16_C(  3017), -INT16_C( 11499), -INT16_C(  5428)
                , -INT16_C(  3288), -INT16_C( 24351), -INT16_C(  9886),  INT16_C( 21424), -INT16_C( 17066), -INT16_C(  7924), -INT16_C( 23668), -INT16_C(  3883)
                , -INT16_C( 11419), -INT16_C(  2776), -INT16_C(  1358), -INT16_C(  6579),  INT16_C(  9724),  INT16_C( 17473),  INT16_C(  5616), -INT16_C( 13751)
                , -INT16_C(  7866),  INT16_C( 30198), -INT16_C( 26216),  INT16_C(  3774), -INT16_C( 10690), -INT16_C( 15257),  INT16_C( 32106),  INT16_C(  5770)
                , -INT16_C( 15123), -INT16_C( 18189),  INT16_C(  9636), -INT16_C( 19661),  INT16_C(  6022), -INT16_C(  5419),  INT16_C( 14068),  INT16_C( 23740)
                , -INT16_C( 30020),  INT16_C( 31132),  INT16_C(  4093), -INT16_C( 11682),  INT16_C( 18202), -INT16_C(  1941), -INT16_C( 23965),  INT16_C(  4560) },
      /* r */ { INT16_C(   761),  INT16_C( 23988),  INT16_C( 18231),  INT16_C( 11237), -INT16_C(  4975),  INT16_C(   164), -INT16_C( 14872), -INT16_C( 11268)
                ,  INT16_C(  9967),  INT16_C(  8193), -INT16_C(   718),  INT16_C( 14574),  INT16_C( 27259),  INT16_C(  8248),  INT16_C(   539),  INT16_C(  9043)
                ,  INT16_C( 20861), -INT16_C( 18616),  INT16_C(  7937), -INT16_C( 14554), -INT16_C( 11699), -INT16_C( 22062), -INT16_C(  2732),  INT16_C( 22332)
                , -INT16_C( 22930), -INT16_C( 30791), -INT16_C( 19668), -INT16_C( 15328),  INT16_C( 28224), -INT16_C( 11174),  INT16_C(   870),  INT16_C( 31660)
                , -INT16_C( 21436),  INT16_C(  8476),  INT16_C( 22719),  INT16_C(  6225),  INT16_C( 20149),  INT16_C( 16595), -INT16_C( 22562),  INT16_C(  6934)
                ,  INT16_C(  9917),  INT16_C( 15714), -INT16_C( 24529), -INT16_C(  3899), -INT16_C( 22887), -INT16_C( 19475),  INT16_C( 12551),  INT16_C( 12278)
                , -INT16_C(  7099),  INT16_C( 23378), -INT16_C( 26669),  INT16_C( 25600), -INT16_C( 26317), -INT16_C(   442), -INT16_C(  6179), -INT16_C( 22915)
                , -INT16_C( 12942), -INT16_C( 16031), -INT16_C( 20699), -INT16_C( 15236),  INT16_C(   174), -INT16_C( 31721),  INT16_C( 22231), -INT16_C(  8973) } },
    {      /* q */ {UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0) },
      /* x */ { INT16_C( 22237), -INT16_C(   204), -INT16_C(  8585), -INT16_C(  4619), -INT16_C( 21566),  INT16_C( 21319), -INT16_C( 28457),  INT16_C( 16643)
                ,  INT16_C( 25636), -INT16_C(  1258), -INT16_C(  5599), -INT16_C( 24882), -INT16_C( 15971), -INT16_C( 13775),  INT16_C(  7452),  INT16_C( 11731)
                ,  INT16_C( 29059), -INT16_C(  2171),  INT16_C( 27051), -INT16_C( 14703), -INT16_C( 10546), -INT16_C( 25871), -INT16_C(  1343), -INT16_C( 11504)
                ,  INT16_C( 17428), -INT16_C( 30255),  INT16_C(  4441),  INT16_C( 19080),  INT16_C(  8686), -INT16_C(  9409),  INT16_C( 25330),  INT16_C( 12638)
                ,  INT16_C(  6483),  INT16_C(  4482),  INT16_C(   484),  INT16_C( 26794),  INT16_C( 23053),  INT16_C( 13703),  INT16_C( 30114),  INT16_C( 11643)
                , -INT16_C( 28739), -INT16_C(  5224),  INT16_C( 29443), -INT16_C( 26845), -INT16_C(  5804), -INT16_C( 14434), -INT16_C( 19758),  INT16_C( 29033)
                ,  INT16_C( 18041),  INT16_C( 28327),  INT16_C( 12319), -INT16_C( 14810),  INT16_C( 31901), -INT16_C( 12333),  INT16_C( 10373),  INT16_C( 14344)
                ,  INT16_C( 20175),  INT16_C( 25493),  INT16_C( 32471),  INT16_C( 12948), -INT16_C(  8874),  INT16_C( 25402), -INT16_C( 27456),  INT16_C( 23634) },
      /* u */ { INT16_C( 28418),  INT16_C(  5400),  INT16_C( 21569), -INT16_C(  9774), -INT16_C(  5459), -INT16_C(  5683),  INT16_C(  1984), -INT16_C(  2171)
                , -INT16_C( 11521), -INT16_C( 17722), -INT16_C( 26004), -INT16_C( 32345), -INT16_C( 29847),  INT16_C(  8246), -INT16_C(  7184),  INT16_C(  6827)
                ,  INT16_C( 24080), -INT16_C( 28133),  INT16_C(  7337),  INT16_C(  6246), -INT16_C( 25262),  INT16_C( 22760),  INT16_C( 11926),  INT16_C(  8870)
                ,  INT16_C( 13568),  INT16_C(  7576),  INT16_C( 29597), -INT16_C(  7777),  INT16_C( 28279), -INT16_C( 25057), -INT16_C(  3880), -INT16_C(  3792)
                ,  INT16_C( 30769), -INT16_C( 11351),  INT16_C(  6910), -INT16_C( 26043),  INT16_C( 10360),  INT16_C( 22939), -INT16_C( 13436),  INT16_C( 11056)
                , -INT16_C( 12074),  INT16_C( 14800), -INT16_C(  7011),  INT16_C( 26970),  INT16_C( 26949),  INT16_C( 10656),  INT16_C( 30335),  INT16_C(  6879)
                ,  INT16_C( 19975),  INT16_C( 28925),  INT16_C( 26812), -INT16_C(  7329), -INT16_C( 24510),  INT16_C(  5821), -INT16_C( 28733),  INT16_C( 23315)
                ,  INT16_C(   567), -INT16_C( 18707),  INT16_C( 15856), -INT16_C( 23231), -INT16_C(  9425), -INT16_C(  2777),  INT16_C(  7347),  INT16_C( 13049) },
      /* r */ {-INT16_C( 14883),  INT16_C(  5172),  INT16_C( 12984), -INT16_C(  4665), -INT16_C( 21649),  INT16_C( 15687), -INT16_C( 26473),  INT16_C( 14472)
                ,  INT16_C( 14116), -INT16_C( 18980), -INT16_C(  5599), -INT16_C( 24882), -INT16_C( 16122), -INT16_C(  5529),  INT16_C(   284),  INT16_C( 18643)
                , -INT16_C( 12397), -INT16_C(  2144), -INT16_C( 31061), -INT16_C(  8457),  INT16_C( 29728), -INT16_C(  3087), -INT16_C(  1449), -INT16_C(  2634)
                ,  INT16_C( 17428), -INT16_C( 30359),  INT16_C(  4598),  INT16_C( 11303),  INT16_C(  8686), -INT16_C(  9378),  INT16_C( 21450),  INT16_C( 12638)
                ,  INT16_C(  6483), -INT16_C(  6782),  INT16_C(   484),  INT16_C( 26863),  INT16_C( 23053),  INT16_C( 13703),  INT16_C( 16678),  INT16_C( 11691)
                ,  INT16_C( 24765),  INT16_C(  9624),  INT16_C( 22275),  INT16_C(   125), -INT16_C(  5804), -INT16_C( 14434),  INT16_C( 10577), -INT16_C( 29624)
                ,  INT16_C( 18041), -INT16_C(  8281), -INT16_C( 26593), -INT16_C( 22139),  INT16_C(  7391), -INT16_C( 12333), -INT16_C( 18299), -INT16_C( 27877)
                ,  INT16_C( 20943),  INT16_C(  6786),  INT16_C( 32471), -INT16_C( 10348), -INT16_C(  8874),  INT16_C( 22625), -INT16_C( 27533), -INT16_C( 28846) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vh_condacc_QnVhVh(q, x, u);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_condacc_QVwVw(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int32_t x[32]; int32_t u[32]; int32_t r[32];
  } test_vec[] = {
    {      /* q */ {UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      /* x */ { INT32_C(  235112065),  INT32_C(  337300016),  INT32_C( 1330612769), -INT32_C( 2079237755)
                , -INT32_C(   94707274),  INT32_C( 1360783810), -INT32_C( 1637156216), -INT32_C(  190959579)
                ,  INT32_C( 1403092974), -INT32_C( 1427636649),  INT32_C( 1838215808),  INT32_C( 2130729225)
                , -INT32_C( 1620411367),  INT32_C(  273040043), -INT32_C(  488167301), -INT32_C(  388198204)
                ,  INT32_C( 2047441380),  INT32_C( 2084455724), -INT32_C(  238616109), -INT32_C(  924252643)
                , -INT32_C(   79715552), -INT32_C(  426017414),  INT32_C( 1801495216), -INT32_C( 1407671014)
                ,  INT32_C(  808022682), -INT32_C( 1089219781),  INT32_C( 2070809842),  INT32_C( 1922523821)
                , -INT32_C( 1367805650),  INT32_C( 1603352871),  INT32_C( 1147479968),  INT32_C( 1445466797) },
      /* u */ { INT32_C( 1744938585),  INT32_C( 1345034897),  INT32_C( 2011975651), -INT32_C(  695192482)
                ,  INT32_C(  276532514), -INT32_C(  871983244), -INT32_C(  559701269),  INT32_C(  999418480)
                ,  INT32_C( 1292066942), -INT32_C( 1816643274), -INT32_C( 1048988815), -INT32_C( 1210500207)
                , -INT32_C(  197566963),  INT32_C(  850080675), -INT32_C( 1957186672), -INT32_C( 1397273612)
                , -INT32_C( 1860319720),  INT32_C(  918788912),  INT32_C( 1686916031), -INT32_C( 1979071543)
                , -INT32_C( 1993118737), -INT32_C(  328064087), -INT32_C(  590913347), -INT32_C(  720404386)
                , -INT32_C(  488678584), -INT32_C(  752856411),  INT32_C( 1307535846),  INT32_C(  275360907)
                , -INT32_C(  777570378), -INT32_C(  252697347),  INT32_C( 1290908662), -INT32_C( 1363551451) },
      /* r */ { INT32_C( 1979919489),  INT32_C( 1682361025),  INT32_C( 1330612769), -INT32_C( 2069800477)
                ,  INT32_C(  181854680),  INT32_C(  488827330), -INT32_C( 1643185549), -INT32_C(  198168427)
                ,  INT32_C( 1403092974), -INT32_C( 1432289705),  INT32_C(  789246705),  INT32_C( 2144950537)
                , -INT32_C( 1616651738),  INT32_C( 1123107406),  INT32_C( 1860642827), -INT32_C(  388198204)
                ,  INT32_C( 2049392636),  INT32_C( 2080458076), -INT32_C(  238616109),  INT32_C( 1391053085)
                , -INT32_C(   76307697), -INT32_C(  744775389),  INT32_C( 1797825200), -INT32_C( 1406622438)
                ,  INT32_C(  805859994), -INT32_C( 1089264160), -INT32_C(  915507470), -INT32_C( 2097082451)
                , -INT32_C( 2145376028),  INT32_C( 1603352868),  INT32_C( 1147479968),  INT32_C( 1445466797) } },
    {      /* q */ {UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0) },
      /* x */ { INT32_C( 1152626088), -INT32_C(   23468104),  INT32_C(  668192136),  INT32_C(  701192747)
                , -INT32_C(  797434595), -INT32_C(  871702582), -INT32_C( 1424179654), -INT32_C(  919930755)
                ,  INT32_C(  773784510),  INT32_C(  577851140), -INT32_C( 1973980652), -INT32_C( 1777526883)
                ,  INT32_C(   56799539), -INT32_C( 1838410139), -INT32_C( 1418656667),  INT32_C(  250858494)
                , -INT32_C(   91378299),  INT32_C(  958415020),  INT32_C( 1717923261),  INT32_C(  782136621)
                , -INT32_C( 1853136240),  INT32_C( 1117434913), -INT32_C(  632240620), -INT32_C(  772238585)
                ,  INT32_C(  175659669), -INT32_C( 1381215720), -INT32_C( 1680771007),  INT32_C( 1074085357)
                ,  INT32_C( 2026610823),  INT32_C(  618163706),  INT32_C(  603462741), -INT32_C( 1807095240) },
      /* u */ {-INT32_C(  896131712),  INT32_C(  136315807), -INT32_C( 1437875699), -INT32_C( 2057547718)
                ,  INT32_C( 1851689027),  INT32_C( 2043608656), -INT32_C(  664482720),  INT32_C( 1036704782)
                , -INT32_C( 1651652435),  INT32_C(  895005777),  INT32_C( 1379378380),  INT32_C(  703543656)
                , -INT32_C( 1382635381), -INT32_C( 2128604599), -INT32_C(  822518113), -INT32_C( 1026666354)
                ,  INT32_C(  174532703), -INT32_C(  852134890), -INT32_C( 1714675043),  INT32_C(  908191984)
                ,  INT32_C(  891320286), -INT32_C(  718699074), -INT32_C(  813316114), -INT32_C(  527984482)
                , -INT32_C( 1506228730), -INT32_C( 1434577033),  INT32_C( 1973470396),  INT32_C( 1811036704)
                , -INT32_C( 1697431185), -INT32_C( 1355804538), -INT32_C(  156552080),  INT32_C( 1649177065) },
      /* r */ { INT32_C(  256494376),  INT32_C(  110750551), -INT32_C(  757871224),  INT32_C(  701192747)
                ,  INT32_C( 1048059165),  INT32_C( 1158340378), -INT32_C( 1424192870), -INT32_C(  919939957)
                ,  INT32_C(  783025003),  INT32_C(  577831765), -INT32_C( 1970310636), -INT32_C( 1089661027)
                ,  INT32_C(   56777011),  INT32_C(  325850725),  INT32_C( 2054251365),  INT32_C(  247602430)
                , -INT32_C(   84627996),  INT32_C(  958444716),  INT32_C(    3248218),  INT32_C( 1688106285)
                , -INT32_C( 1851008368),  INT32_C( 1120156127), -INT32_C(  623473132), -INT32_C( 1292358905)
                ,  INT32_C(  179395227), -INT32_C( 1389735281), -INT32_C( 1680786367),  INT32_C( 1089945069)
                ,  INT32_C( 2026627574),  INT32_C(  618163706),  INT32_C(  603462741), -INT32_C( 1802085320) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vw_condacc_QVwVw(q, x, u);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_condacc_QnVwVw(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int32_t x[32]; int32_t u[32]; int32_t r[32];
  } test_vec[] = {
    {      /* q */ {UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255) },
      /* x */ { INT32_C( 1808259230),  INT32_C( 1313715893), -INT32_C( 1778870514),  INT32_C( 2027988281)
                , -INT32_C( 1757090910), -INT32_C( 1110231465), -INT32_C(  925326210), -INT32_C( 1849845061)
                ,  INT32_C(  462280069), -INT32_C(  585470023), -INT32_C(  573381378),  INT32_C( 1752982461)
                ,  INT32_C( 1068023916),  INT32_C( 2145906225),  INT32_C(  877344484),  INT32_C(  357886861)
                , -INT32_C( 1988464153), -INT32_C(   71122629), -INT32_C( 1858014475), -INT32_C( 2094747720)
                , -INT32_C( 1180381820),  INT32_C(  514343581), -INT32_C(  133974580),  INT32_C( 1666499494)
                ,  INT32_C(  260548479),  INT32_C(  515546180),  INT32_C( 1521405313), -INT32_C( 1896773495)
                ,  INT32_C( 2000365145), -INT32_C( 1256987743),  INT32_C( 1595656867), -INT32_C( 1783456063) },
      /* u */ { INT32_C(  296803679), -INT32_C(  748210942),  INT32_C(  734971681), -INT32_C( 1022597330)
                , -INT32_C( 1277709332),  INT32_C(  195068386), -INT32_C(  484524781),  INT32_C(  869444182)
                ,  INT32_C( 1201555588),  INT32_C( 2091997259),  INT32_C( 1086396553),  INT32_C( 2000646658)
                , -INT32_C(  646813038), -INT32_C(  558227061), -INT32_C( 1825297491),  INT32_C( 2008145107)
                ,  INT32_C(  649636622), -INT32_C(  175004784),  INT32_C( 2035709755),  INT32_C( 1026132553)
                ,  INT32_C( 1587070403),  INT32_C(  347851638), -INT32_C( 1644236984), -INT32_C(   85274241)
                ,  INT32_C(  531641922),  INT32_C( 2005413193),  INT32_C(  659532122),  INT32_C(  398744012)
                , -INT32_C( 1984048006),  INT32_C( 1974905303),  INT32_C(  942780735),  INT32_C( 1573678510) },
      /* r */ { INT32_C( 1803072926),  INT32_C(  565491383), -INT32_C( 1043898833),  INT32_C( 1005390951)
                , -INT32_C( 1757090930), -INT32_C( 1116489671), -INT32_C(  925343343), -INT32_C(  977429829)
                ,  INT32_C( 1670192649), -INT32_C(  585447239), -INT32_C(  573381497), -INT32_C(  541367363)
                ,  INT32_C(  430451308),  INT32_C( 2141384380),  INT32_C(  877355665),  INT32_C(  357877856)
                , -INT32_C( 1988464139), -INT32_C(  246103605),  INT32_C(  171993845), -INT32_C( 2094777855)
                ,  INT32_C(  413438852),  INT32_C(  862195357), -INT32_C( 1778141748),  INT32_C( 1665123109)
                ,  INT32_C(  792190401), -INT32_C( 1766143603),  INT32_C( 1526648193), -INT32_C( 1900705707)
                ,  INT32_C( 2000365145), -INT32_C( 1244994696), -INT32_C( 1756509533), -INT32_C( 1786798399) } },
    {      /* q */ {UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255) },
      /* x */ { INT32_C( 1340000347),  INT32_C(  269384516), -INT32_C( 1085471254), -INT32_C(  517767627)
                , -INT32_C( 1504892727), -INT32_C(  723380426),  INT32_C( 1888881148),  INT32_C( 1804958048)
                , -INT32_C(  237267600),  INT32_C(  557589064), -INT32_C( 1455363295),  INT32_C( 1635576555)
                , -INT32_C(  677245687),  INT32_C(  193059846),  INT32_C(  325594594), -INT32_C( 1980936829)
                , -INT32_C(  321867240), -INT32_C( 1462564082),  INT32_C( 1441306946),  INT32_C( 1738551917)
                ,  INT32_C(  661329226), -INT32_C( 1925150540),  INT32_C(  210427069), -INT32_C(  178210481)
                ,  INT32_C(  709816304), -INT32_C( 1332786244),  INT32_C(  831239574),  INT32_C( 1289867835)
                ,  INT32_C( 1260849983), -INT32_C( 1574640204),  INT32_C(  436663275), -INT32_C(  141449029) },
      /* u */ {-INT32_C( 1270759855),  INT32_C(  588250354),  INT32_C( 1602750726), -INT32_C( 1828072252)
                , -INT32_C(  659554869), -INT32_C( 1264745680), -INT32_C( 1774604762), -INT32_C( 1585280087)
                , -INT32_C( 1754524428), -INT32_C( 1401365765), -INT32_C(  259741448), -INT32_C(  552271601)
                , -INT32_C( 1432516843),  INT32_C( 1111292711), -INT32_C( 2076288842),  INT32_C(  362896946)
                ,  INT32_C( 1056842114),  INT32_C(  425860130),  INT32_C( 1820944794),  INT32_C(  745195674)
                , -INT32_C( 1065881574),  INT32_C( 1814741779),  INT32_C( 1762258323),  INT32_C( 2142842705)
                ,  INT32_C( 1337248344),  INT32_C( 1836513327), -INT32_C( 1946391883), -INT32_C( 1401030091)
                ,  INT32_C( 2073880829),  INT32_C(  135678962), -INT32_C(  111920343), -INT32_C( 1251282860) },
      /* r */ { INT32_C( 1327548588),  INT32_C(  856587076), -INT32_C( 1076556054), -INT32_C(  517767627)
                ,  INT32_C( 2130520265), -INT32_C(  729834954),  INT32_C( 1888925730),  INT32_C( 1804928265)
                , -INT32_C(  246961552), -INT32_C(  851641016), -INT32_C( 1446647015),  INT32_C( 1636952826)
                , -INT32_C( 2103274487),  INT32_C(  197056262), -INT32_C( 1754780190), -INT32_C( 1987138635)
                ,  INT32_C(  734974874), -INT32_C( 1462556880),  INT32_C( 1433535042), -INT32_C( 1801389203)
                , -INT32_C(  404552374), -INT32_C( 1922332492),  INT32_C(  210427069), -INT32_C(  178210481)
                ,  INT32_C(  704887368),  INT32_C(  512707563), -INT32_C( 1115114165),  INT32_C( 1289866299)
                , -INT32_C(  970460100), -INT32_C( 1438961228),  INT32_C(  442183659), -INT32_C(  134436849) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t u = simde_test_hvx_vector_load(test_vec[i].u);
    simde_hvx_vector_t r = simde_Q6_Vw_condacc_QnVwVw(q, x, u);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(condacc_QVbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(condacc_QnVbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(condacc_QVhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(condacc_QnVhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(condacc_QVwVw)
SIMDE_TEST_FUNC_LIST_ENTRY(condacc_QnVwVw)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
