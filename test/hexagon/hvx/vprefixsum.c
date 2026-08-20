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

#define SIMDE_TEST_HEXAGON_HVX_INSN vprefixsum

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vprefixsum.h"

static int
test_simde_prefixsum_Q_Vb(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int8_t r[128];
  } test_vec[] = {
    {      /* q */ {UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0) },
      /* r */ { INT8_C(   1),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   3),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   6),  INT8_C(   6),  INT8_C(   6),  INT8_C(   6),  INT8_C(   6),  INT8_C(   7)
                ,  INT8_C(   7),  INT8_C(   8),  INT8_C(   9),  INT8_C(   9),  INT8_C(   9),  INT8_C(  10),  INT8_C(  11),  INT8_C(  11),  INT8_C(  11),  INT8_C(  11),  INT8_C(  11),  INT8_C(  11),  INT8_C(  12),  INT8_C(  13),  INT8_C(  14),  INT8_C(  15)
                ,  INT8_C(  16),  INT8_C(  17),  INT8_C(  17),  INT8_C(  18),  INT8_C(  18),  INT8_C(  19),  INT8_C(  20),  INT8_C(  21),  INT8_C(  22),  INT8_C(  22),  INT8_C(  22),  INT8_C(  22),  INT8_C(  23),  INT8_C(  23),  INT8_C(  23),  INT8_C(  24)
                ,  INT8_C(  24),  INT8_C(  24),  INT8_C(  25),  INT8_C(  25),  INT8_C(  25),  INT8_C(  25),  INT8_C(  25),  INT8_C(  25),  INT8_C(  26),  INT8_C(  26),  INT8_C(  27),  INT8_C(  28),  INT8_C(  29),  INT8_C(  29),  INT8_C(  30),  INT8_C(  30)
                ,  INT8_C(  30),  INT8_C(  30),  INT8_C(  31),  INT8_C(  31),  INT8_C(  31),  INT8_C(  32),  INT8_C(  32),  INT8_C(  33),  INT8_C(  33),  INT8_C(  34),  INT8_C(  34),  INT8_C(  35),  INT8_C(  36),  INT8_C(  36),  INT8_C(  36),  INT8_C(  36)
                ,  INT8_C(  37),  INT8_C(  38),  INT8_C(  39),  INT8_C(  39),  INT8_C(  40),  INT8_C(  40),  INT8_C(  41),  INT8_C(  41),  INT8_C(  41),  INT8_C(  41),  INT8_C(  41),  INT8_C(  41),  INT8_C(  41),  INT8_C(  42),  INT8_C(  42),  INT8_C(  43)
                ,  INT8_C(  43),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  44),  INT8_C(  45),  INT8_C(  46),  INT8_C(  47),  INT8_C(  48),  INT8_C(  49),  INT8_C(  50),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51)
                ,  INT8_C(  51),  INT8_C(  51),  INT8_C(  52),  INT8_C(  53),  INT8_C(  54),  INT8_C(  54),  INT8_C(  55),  INT8_C(  55),  INT8_C(  56),  INT8_C(  57),  INT8_C(  58),  INT8_C(  59),  INT8_C(  60),  INT8_C(  60),  INT8_C(  61),  INT8_C(  61) } },
    {      /* q */ {UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0) },
      /* r */ { INT8_C(   0),  INT8_C(   1),  INT8_C(   2),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   6),  INT8_C(   6),  INT8_C(   6),  INT8_C(   6),  INT8_C(   7)
                ,  INT8_C(   8),  INT8_C(   8),  INT8_C(   8),  INT8_C(   9),  INT8_C(  10),  INT8_C(  11),  INT8_C(  11),  INT8_C(  12),  INT8_C(  13),  INT8_C(  14),  INT8_C(  15),  INT8_C(  16),  INT8_C(  16),  INT8_C(  16),  INT8_C(  17),  INT8_C(  17)
                ,  INT8_C(  18),  INT8_C(  19),  INT8_C(  19),  INT8_C(  20),  INT8_C(  21),  INT8_C(  22),  INT8_C(  22),  INT8_C(  22),  INT8_C(  22),  INT8_C(  23),  INT8_C(  24),  INT8_C(  25),  INT8_C(  25),  INT8_C(  26),  INT8_C(  27),  INT8_C(  27)
                ,  INT8_C(  28),  INT8_C(  28),  INT8_C(  29),  INT8_C(  30),  INT8_C(  31),  INT8_C(  32),  INT8_C(  33),  INT8_C(  33),  INT8_C(  34),  INT8_C(  35),  INT8_C(  36),  INT8_C(  36),  INT8_C(  36),  INT8_C(  37),  INT8_C(  37),  INT8_C(  38)
                ,  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  40),  INT8_C(  41),  INT8_C(  42),  INT8_C(  43),  INT8_C(  44),  INT8_C(  45),  INT8_C(  46),  INT8_C(  47),  INT8_C(  48),  INT8_C(  48),  INT8_C(  49),  INT8_C(  49),  INT8_C(  49)
                ,  INT8_C(  50),  INT8_C(  51),  INT8_C(  51),  INT8_C(  52),  INT8_C(  53),  INT8_C(  53),  INT8_C(  54),  INT8_C(  54),  INT8_C(  55),  INT8_C(  56),  INT8_C(  57),  INT8_C(  58),  INT8_C(  58),  INT8_C(  58),  INT8_C(  58),  INT8_C(  58)
                ,  INT8_C(  58),  INT8_C(  58),  INT8_C(  59),  INT8_C(  59),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  60),  INT8_C(  61),  INT8_C(  61),  INT8_C(  62),  INT8_C(  62),  INT8_C(  63)
                ,  INT8_C(  64),  INT8_C(  64),  INT8_C(  65),  INT8_C(  65),  INT8_C(  66),  INT8_C(  66),  INT8_C(  67),  INT8_C(  68),  INT8_C(  69),  INT8_C(  69),  INT8_C(  69),  INT8_C(  70),  INT8_C(  71),  INT8_C(  71),  INT8_C(  72),  INT8_C(  72) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t r = simde_Q6_Vb_prefixsum_Q(q);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_prefixsum_Q_Vh(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int16_t r[64];
  } test_vec[] = {
    {      /* q */ {UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255) },
      /* r */ { INT16_C(     2),  INT16_C(     3),  INT16_C(     4),  INT16_C(     5),  INT16_C(     6),  INT16_C(     8),  INT16_C(    10),  INT16_C(    10)
                ,  INT16_C(    11),  INT16_C(    11),  INT16_C(    12),  INT16_C(    12),  INT16_C(    13),  INT16_C(    13),  INT16_C(    14),  INT16_C(    14)
                ,  INT16_C(    16),  INT16_C(    17),  INT16_C(    18),  INT16_C(    18),  INT16_C(    19),  INT16_C(    21),  INT16_C(    21),  INT16_C(    22)
                ,  INT16_C(    23),  INT16_C(    24),  INT16_C(    25),  INT16_C(    26),  INT16_C(    27),  INT16_C(    27),  INT16_C(    28),  INT16_C(    30)
                ,  INT16_C(    32),  INT16_C(    32),  INT16_C(    33),  INT16_C(    34),  INT16_C(    36),  INT16_C(    38),  INT16_C(    39),  INT16_C(    40)
                ,  INT16_C(    42),  INT16_C(    43),  INT16_C(    43),  INT16_C(    45),  INT16_C(    46),  INT16_C(    46),  INT16_C(    48),  INT16_C(    48)
                ,  INT16_C(    48),  INT16_C(    48),  INT16_C(    50),  INT16_C(    51),  INT16_C(    52),  INT16_C(    54),  INT16_C(    55),  INT16_C(    57)
                ,  INT16_C(    59),  INT16_C(    59),  INT16_C(    59),  INT16_C(    60),  INT16_C(    60),  INT16_C(    61),  INT16_C(    61),  INT16_C(    63) } },
    {      /* q */ {UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255) },
      /* r */ { INT16_C(     0),  INT16_C(     2),  INT16_C(     4),  INT16_C(     5),  INT16_C(     7),  INT16_C(     8),  INT16_C(     8),  INT16_C(     9)
                ,  INT16_C(    10),  INT16_C(    11),  INT16_C(    12),  INT16_C(    12),  INT16_C(    13),  INT16_C(    14),  INT16_C(    15),  INT16_C(    15)
                ,  INT16_C(    16),  INT16_C(    16),  INT16_C(    18),  INT16_C(    18),  INT16_C(    19),  INT16_C(    19),  INT16_C(    19),  INT16_C(    21)
                ,  INT16_C(    22),  INT16_C(    22),  INT16_C(    24),  INT16_C(    25),  INT16_C(    26),  INT16_C(    27),  INT16_C(    29),  INT16_C(    31)
                ,  INT16_C(    32),  INT16_C(    34),  INT16_C(    35),  INT16_C(    36),  INT16_C(    37),  INT16_C(    39),  INT16_C(    39),  INT16_C(    41)
                ,  INT16_C(    42),  INT16_C(    43),  INT16_C(    45),  INT16_C(    47),  INT16_C(    47),  INT16_C(    48),  INT16_C(    49),  INT16_C(    51)
                ,  INT16_C(    51),  INT16_C(    51),  INT16_C(    52),  INT16_C(    54),  INT16_C(    54),  INT16_C(    55),  INT16_C(    55),  INT16_C(    57)
                ,  INT16_C(    58),  INT16_C(    60),  INT16_C(    60),  INT16_C(    61),  INT16_C(    61),  INT16_C(    63),  INT16_C(    64),  INT16_C(    66) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t r = simde_Q6_Vh_prefixsum_Q(q);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_prefixsum_Q_Vw(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t q[128]; int32_t r[32];
  } test_vec[] = {
    {      /* q */ {UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255) },
      /* r */ { INT32_C(          1),  INT32_C(          3),  INT32_C(          4),  INT32_C(          5)
                ,  INT32_C(          7),  INT32_C(         10),  INT32_C(         12),  INT32_C(         13)
                ,  INT32_C(         16),  INT32_C(         19),  INT32_C(         21),  INT32_C(         23)
                ,  INT32_C(         25),  INT32_C(         27),  INT32_C(         30),  INT32_C(         32)
                ,  INT32_C(         33),  INT32_C(         34),  INT32_C(         37),  INT32_C(         39)
                ,  INT32_C(         39),  INT32_C(         41),  INT32_C(         42),  INT32_C(         44)
                ,  INT32_C(         48),  INT32_C(         50),  INT32_C(         52),  INT32_C(         53)
                ,  INT32_C(         53),  INT32_C(         55),  INT32_C(         57),  INT32_C(         60) } },
    {      /* q */ {UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255)
                , UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(  0) },
      /* r */ { INT32_C(          1),  INT32_C(          3),  INT32_C(          4),  INT32_C(          5)
                ,  INT32_C(          7),  INT32_C(          8),  INT32_C(          9),  INT32_C(         11)
                ,  INT32_C(         14),  INT32_C(         15),  INT32_C(         18),  INT32_C(         21)
                ,  INT32_C(         23),  INT32_C(         24),  INT32_C(         25),  INT32_C(         28)
                ,  INT32_C(         30),  INT32_C(         33),  INT32_C(         35),  INT32_C(         39)
                ,  INT32_C(         39),  INT32_C(         41),  INT32_C(         42),  INT32_C(         43)
                ,  INT32_C(         44),  INT32_C(         47),  INT32_C(         49),  INT32_C(         51)
                ,  INT32_C(         53),  INT32_C(         55),  INT32_C(         56),  INT32_C(         58) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(test_vec[i].q);
    simde_hvx_vector_t r = simde_Q6_Vw_prefixsum_Q(q);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(prefixsum_Q_Vb)
SIMDE_TEST_FUNC_LIST_ENTRY(prefixsum_Q_Vh)
SIMDE_TEST_FUNC_LIST_ENTRY(prefixsum_Q_Vw)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
