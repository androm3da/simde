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

#define SIMDE_TEST_HEXAGON_HVX_INSN vsub

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vsub.h"

static int
test_simde_vsub_VbVb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[SIMDE_HVX_VECTOR_SIZE];
    int8_t b[SIMDE_HVX_VECTOR_SIZE];
    int8_t r[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),  INT8_C(  48),  INT8_C(  70),  INT8_C( 101), -INT8_C(  78),
         INT8_C(  16), -INT8_C(  99), -INT8_C( 126),  INT8_C( 106),  INT8_C(  20),  INT8_C(   1),  INT8_C(  23),  INT8_C(  96),
        -INT8_C(  49), -INT8_C( 116),  INT8_C(  44), -INT8_C(   1),  INT8_C( 102),  INT8_C(  42),  INT8_C(   3),  INT8_C(   2),
        -INT8_C(  35), -INT8_C(  37), -INT8_C(  31), -INT8_C( 125),  INT8_C(  16), -INT8_C( 117),  INT8_C( 115), -INT8_C(  26),
        -INT8_C(  92), -INT8_C(  56),  INT8_C(   1), -INT8_C(  65), -INT8_C(  67),  INT8_C(  55),  INT8_C( 120), -INT8_C(  89),
        -INT8_C(  36),  INT8_C( 109), -INT8_C(  25), -INT8_C(  14),  INT8_C(  77),  INT8_C(  98), -INT8_C( 110),  INT8_C(  29),
         INT8_C(  40), -INT8_C( 102), -INT8_C(  40),  INT8_C( 111), -INT8_C(  45),  INT8_C(  76), -INT8_C(  32), -INT8_C(  41),
         INT8_C(  30),  INT8_C(  17),  INT8_C(  32),  INT8_C(   7),  INT8_C( 103),  INT8_C(  17),  INT8_C(  75),  INT8_C(  84),
         INT8_C( 108), -INT8_C(  59), -INT8_C(  72), -INT8_C(  92), -INT8_C(  69), -INT8_C( 111),  INT8_C(  23), -INT8_C(  42),
         INT8_C( 105), -INT8_C(  24), -INT8_C(  40),  INT8_C(  21),  INT8_C(  97),  INT8_C(  24),  INT8_C(   8), -INT8_C(  68),
        -INT8_C( 112),  INT8_C(  55), -INT8_C( 111),  INT8_C(  48), -INT8_C( 115), -INT8_C(  70),  INT8_C(  78), -INT8_C(  17),
         INT8_C(   6),  INT8_C(  15), -INT8_C( 108),  INT8_C(  10), -INT8_C(  13), -INT8_C(  67),  INT8_C(  38),  INT8_C(  47),
         INT8_C(  64),  INT8_C( 106), -INT8_C(   2),  INT8_C(  49),  INT8_C(  76), -INT8_C(  47),  INT8_C(  30),  INT8_C( 102),
        -INT8_C(  46),  INT8_C(  38),  INT8_C(   4),  INT8_C(  89), -INT8_C(  19),  INT8_C(  41), -INT8_C(  84), -INT8_C(  81),
         INT8_C(  44),  INT8_C( 105),  INT8_C(  55),  INT8_C(  57), -INT8_C(  85), -INT8_C(   3), -INT8_C(  67), -INT8_C(  29) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  56), -INT8_C(  39), -INT8_C(  85), -INT8_C(  51),
         INT8_C(  59), -INT8_C(  97), -INT8_C(   1),  INT8_C(  81),  INT8_C(  45), -INT8_C(  41), -INT8_C(  93), -INT8_C( 108),
         INT8_C( 124), -INT8_C( 101), -INT8_C(   3),  INT8_C( 116),  INT8_C(  91), -INT8_C(  50),  INT8_C( 126),  INT8_C(  34),
         INT8_C(  61),  INT8_C(  11), -INT8_C(  10), -INT8_C( 127), -INT8_C(  18), -INT8_C( 118), -INT8_C(   7),  INT8_C(  33),
        -INT8_C(  93),  INT8_C(  30),  INT8_C(  29), -INT8_C(  89), -INT8_C(  73), -INT8_C(  20),  INT8_C(  55),  INT8_C(  64),
         INT8_C(   2), -INT8_C(  46),  INT8_C(  78),  INT8_C(  71), -INT8_C(  84),  INT8_C(   0),  INT8_C(   7),  INT8_C(   1),
         INT8_C( 120), -INT8_C(  89),  INT8_C(  87), -INT8_C(  58),  INT8_C( 108), -INT8_C(  44), -INT8_C(  96),  INT8_C(  39),
         INT8_C( 120),  INT8_C(  87),  INT8_C(  80),  INT8_C(  77), -INT8_C(   8), -INT8_C(  37),  INT8_C(  68),  INT8_C(  58),
        -INT8_C(  55),  INT8_C(  69),  INT8_C( 123), -INT8_C(   8), -INT8_C(  79),  INT8_C(  36),  INT8_C(  61), -INT8_C(  83),
         INT8_C( 124),  INT8_C( 118), -INT8_C(  10),  INT8_C(  88),  INT8_C( 100), -INT8_C(   9),  INT8_C( 100), -INT8_C(  39),
         INT8_C(  39),  INT8_C(  99),  INT8_C( 107), -INT8_C( 116),  INT8_C(  82), -INT8_C(  32),  INT8_C(  78),  INT8_C(  44),
        -INT8_C(  96),  INT8_C(  87), -INT8_C(  40), -INT8_C( 112), -INT8_C(  67),  INT8_C( 110),  INT8_C(  51),  INT8_C( 105),
         INT8_C(  84),  INT8_C(  91),  INT8_C(  80), -INT8_C(  60), -INT8_C( 118),  INT8_C( 115),  INT8_C(  84),  INT8_C(  38),
         INT8_C(  37),  INT8_C(  31), -INT8_C( 116),  INT8_C(  27),  INT8_C( 103), -INT8_C(  33), -INT8_C(  77),  INT8_C(  34),
        -INT8_C(  79), -INT8_C(  83), -INT8_C(   3), -INT8_C(  93), -INT8_C(  76), -INT8_C(  93), -INT8_C(  79),  INT8_C(  92) },
      {  INT8_C(   0),  INT8_C(   1),      INT8_MAX,  INT8_C( 126), -INT8_C( 127),  INT8_C( 126), -INT8_C( 127),  INT8_C(   0),
             INT8_MAX, -INT8_C( 127),  INT8_C(   0), -INT8_C( 126), -INT8_C(   8),  INT8_C( 109), -INT8_C(  70), -INT8_C(  27),
        -INT8_C(  43), -INT8_C(   2), -INT8_C( 125),  INT8_C(  25), -INT8_C(  25),  INT8_C(  42),  INT8_C( 116), -INT8_C(  52),
         INT8_C(  83), -INT8_C(  15),  INT8_C(  47), -INT8_C( 117),  INT8_C(  11),  INT8_C(  92), -INT8_C( 123), -INT8_C(  32),
        -INT8_C(  96), -INT8_C(  48), -INT8_C(  21),  INT8_C(   2),  INT8_C(  34),  INT8_C(   1),  INT8_C( 122), -INT8_C(  59),
         INT8_C(   1), -INT8_C(  86), -INT8_C(  28),  INT8_C(  24),  INT8_C(   6),  INT8_C(  75),  INT8_C(  65),  INT8_C( 103),
        -INT8_C(  38), -INT8_C( 101), -INT8_C( 103), -INT8_C(  85), -INT8_C(  95),  INT8_C(  98), -INT8_C( 117),  INT8_C(  28),
        -INT8_C(  80), -INT8_C(  13), -INT8_C( 127), -INT8_C(  87),  INT8_C( 103),  INT8_C( 120),  INT8_C(  64), -INT8_C(  80),
        -INT8_C(  90), -INT8_C(  70), -INT8_C(  48), -INT8_C(  70),  INT8_C( 111),  INT8_C(  54),  INT8_C(   7),  INT8_C(  26),
        -INT8_C(  93),      INT8_MIN,  INT8_C(  61), -INT8_C(  84),  INT8_C(  10),  INT8_C( 109), -INT8_C(  38),  INT8_C(  41),
        -INT8_C(  19),  INT8_C( 114), -INT8_C(  30), -INT8_C(  67), -INT8_C(   3),  INT8_C(  33), -INT8_C(  92), -INT8_C(  29),
         INT8_C( 105), -INT8_C(  44),  INT8_C(  38), -INT8_C(  92),  INT8_C(  59), -INT8_C(  38),  INT8_C(   0), -INT8_C(  61),
         INT8_C( 102), -INT8_C(  72), -INT8_C(  68),  INT8_C( 122),  INT8_C(  54),  INT8_C(  79), -INT8_C(  13), -INT8_C(  58),
        -INT8_C(  20),  INT8_C(  15), -INT8_C(  82),  INT8_C( 109), -INT8_C(  62),  INT8_C(  94), -INT8_C(  54),  INT8_C(  64),
        -INT8_C(  83),  INT8_C(   7),  INT8_C( 120),  INT8_C(  62), -INT8_C( 122),  INT8_C(  74), -INT8_C(   7), -INT8_C( 115),
         INT8_C( 123), -INT8_C(  68),  INT8_C(  58), -INT8_C( 106), -INT8_C(   9),  INT8_C(  90),  INT8_C(  12), -INT8_C( 121) } },
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),  INT8_C( 104),  INT8_C(  27), -INT8_C(  51), -INT8_C(  37),
         INT8_C(  93),  INT8_C( 110), -INT8_C(  60), -INT8_C(  59),  INT8_C(   9), -INT8_C( 122), -INT8_C(  30),  INT8_C(  83),
        -INT8_C(   4), -INT8_C(  13), -INT8_C(  31), -INT8_C(  24),  INT8_C( 105), -INT8_C(  18),  INT8_C(  77), -INT8_C( 123),
         INT8_C(  67),  INT8_C(  30), -INT8_C( 108),  INT8_C(  92),  INT8_C( 110),  INT8_C(  17),  INT8_C(  43),  INT8_C(  38),
         INT8_C( 102), -INT8_C(  85),  INT8_C(   9), -INT8_C(  13), -INT8_C(   6), -INT8_C(  87), -INT8_C(  42), -INT8_C( 121),
        -INT8_C( 101), -INT8_C(  72), -INT8_C( 127), -INT8_C(  56), -INT8_C( 127), -INT8_C(  64), -INT8_C(  56),  INT8_C(  44),
        -INT8_C(  64),  INT8_C(  63), -INT8_C(  26),  INT8_C(  59),  INT8_C(   9),  INT8_C( 104), -INT8_C(  32),  INT8_C(  78),
         INT8_C(  91),  INT8_C(  89),  INT8_C( 110),  INT8_C(  19), -INT8_C(  43), -INT8_C(  64), -INT8_C( 120), -INT8_C( 121),
        -INT8_C( 126), -INT8_C(  35), -INT8_C(  85),  INT8_C(  57), -INT8_C(  66),  INT8_C( 112),  INT8_C(  22),  INT8_C( 104),
         INT8_C(  40),  INT8_C(  52),  INT8_C(  97), -INT8_C(   7),  INT8_C(  23),  INT8_C(  65), -INT8_C(  82),  INT8_C(   5),
         INT8_C(  30), -INT8_C(  60),  INT8_C(  75),  INT8_C(   6), -INT8_C(  22), -INT8_C(  49), -INT8_C(  61), -INT8_C(  24),
         INT8_C(   8), -INT8_C( 115), -INT8_C(  28), -INT8_C(  28),  INT8_C(  59), -INT8_C(  91),  INT8_C(  47),  INT8_C(  72),
         INT8_C(  91),  INT8_C(   5),  INT8_C(  28), -INT8_C(  57), -INT8_C(  54), -INT8_C( 123), -INT8_C(  51), -INT8_C(  80),
         INT8_C(  80), -INT8_C(  92), -INT8_C(  49),  INT8_C(  51), -INT8_C(  59), -INT8_C(   4),  INT8_C(  72), -INT8_C(  93),
        -INT8_C(  74), -INT8_C(  24), -INT8_C(  88),  INT8_C(  57), -INT8_C(  79), -INT8_C(  81), -INT8_C(  60),  INT8_C(  65) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  15),  INT8_C(  58),  INT8_C( 116),  INT8_C( 117),
         INT8_C(  32), -INT8_C( 127), -INT8_C( 113),  INT8_C( 120),  INT8_C(  97), -INT8_C(   6),  INT8_C(  55), -INT8_C( 118),
         INT8_C(  66), -INT8_C(  52),  INT8_C(  97), -INT8_C(  44),  INT8_C(  82), -INT8_C(  99), -INT8_C( 115), -INT8_C(  73),
        -INT8_C( 122),  INT8_C(  57), -INT8_C(  54),  INT8_C( 100),  INT8_C( 114),  INT8_C(  71),  INT8_C(  92), -INT8_C(  16),
         INT8_C(   2),  INT8_C(  49), -INT8_C( 102),  INT8_C(  87),  INT8_C(  39),  INT8_C(  23), -INT8_C(  40),  INT8_C(  42),
        -INT8_C( 104), -INT8_C(  90), -INT8_C(  46), -INT8_C( 107),  INT8_C(  69), -INT8_C(  76),  INT8_C(   3), -INT8_C(  45),
        -INT8_C(  88),  INT8_C(  91), -INT8_C( 110), -INT8_C(  25), -INT8_C( 103), -INT8_C(  13),  INT8_C( 122),  INT8_C(  77),
        -INT8_C( 124), -INT8_C(  78), -INT8_C(   3),  INT8_C( 119),  INT8_C( 126),  INT8_C( 112),  INT8_C(  23), -INT8_C(  39),
         INT8_C(  68),  INT8_C( 111),  INT8_C( 126),  INT8_C(  25), -INT8_C( 109),  INT8_C(  87), -INT8_C(  64), -INT8_C( 114),
         INT8_C( 101),  INT8_C( 122), -INT8_C(  65),  INT8_C(  71),  INT8_C( 115), -INT8_C(  13), -INT8_C(  94),  INT8_C( 120),
        -INT8_C( 107), -INT8_C(  43), -INT8_C( 127),  INT8_C(  18),  INT8_C(  51),  INT8_C(  13),  INT8_C(   0),  INT8_C(  90),
        -INT8_C(  29),  INT8_C( 122),  INT8_C( 110), -INT8_C(  78),  INT8_C(  78),  INT8_C(  93), -INT8_C( 124), -INT8_C(  49),
         INT8_C(  89),  INT8_C(  42), -INT8_C(  70), -INT8_C(  90), -INT8_C( 118), -INT8_C(  30),  INT8_C(   4),  INT8_C(  30),
         INT8_C(  19), -INT8_C(  98), -INT8_C( 123), -INT8_C(  38),  INT8_C(  62),  INT8_C(  39),  INT8_C( 113),  INT8_C(  49),
        -INT8_C( 109), -INT8_C(  42), -INT8_C( 117), -INT8_C( 114),  INT8_C(  49), -INT8_C(   2), -INT8_C( 122), -INT8_C(  65) },
      {  INT8_C(   0),  INT8_C(   1),      INT8_MAX,  INT8_C( 126), -INT8_C( 127),  INT8_C( 126), -INT8_C( 127),  INT8_C(   0),
             INT8_MAX, -INT8_C( 127),  INT8_C(   0), -INT8_C( 126),  INT8_C(  89), -INT8_C(  31),  INT8_C(  89),  INT8_C( 102),
         INT8_C(  61), -INT8_C(  19),  INT8_C(  53),  INT8_C(  77), -INT8_C(  88), -INT8_C( 116), -INT8_C(  85), -INT8_C(  55),
        -INT8_C(  70),  INT8_C(  39),      INT8_MIN,  INT8_C(  20),  INT8_C(  23),  INT8_C(  81), -INT8_C(  64), -INT8_C(  50),
        -INT8_C(  67), -INT8_C(  27), -INT8_C(  54), -INT8_C(   8), -INT8_C(   4), -INT8_C(  54), -INT8_C(  49),  INT8_C(  54),
         INT8_C( 100),  INT8_C( 122),  INT8_C( 111), -INT8_C( 100), -INT8_C(  45), -INT8_C( 110), -INT8_C(   2),  INT8_C(  93),
         INT8_C(   3),  INT8_C(  18), -INT8_C(  81),  INT8_C(  51),  INT8_C(  60),  INT8_C(  12), -INT8_C(  59),  INT8_C(  89),
         INT8_C(  24), -INT8_C(  28),  INT8_C(  84),  INT8_C(  84),  INT8_C( 112),  INT8_C( 117),  INT8_C( 102),  INT8_C(   1),
        -INT8_C(  41), -INT8_C(  89),  INT8_C( 113), -INT8_C( 100),  INT8_C(  87),  INT8_C(  80),  INT8_C( 113), -INT8_C(  82),
         INT8_C(  62),  INT8_C( 110),  INT8_C(  45),  INT8_C(  32),  INT8_C(  43),  INT8_C(  25),  INT8_C(  86), -INT8_C(  38),
        -INT8_C(  61), -INT8_C(  70), -INT8_C(  94), -INT8_C(  78), -INT8_C(  92),  INT8_C(  78),  INT8_C(  12), -INT8_C( 115),
        -INT8_C( 119), -INT8_C(  17), -INT8_C(  54), -INT8_C(  12), -INT8_C(  73), -INT8_C(  62), -INT8_C(  61), -INT8_C( 114),
         INT8_C(  37),  INT8_C(  19),  INT8_C( 118),  INT8_C(  50), -INT8_C(  19),  INT8_C(  72), -INT8_C(  85),  INT8_C( 121),
         INT8_C(   2), -INT8_C(  37),  INT8_C(  98),  INT8_C(  33),  INT8_C(  64), -INT8_C(  93), -INT8_C(  55), -INT8_C( 110),
         INT8_C(  61),  INT8_C(   6),  INT8_C(  74),  INT8_C(  89), -INT8_C( 121), -INT8_C(  43), -INT8_C(  41),  INT8_C( 114),
         INT8_C(  35),  INT8_C(  18),  INT8_C(  29), -INT8_C(  85),      INT8_MIN, -INT8_C(  79),  INT8_C(  62), -INT8_C( 126) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vb_vsub_VbVb(a, b);

    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i8_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i8_random(1);
    simde_hvx_vector_t r = simde_Q6_Vb_vsub_VbVb(a, b);

    simde_test_hvx_vector_i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VhVh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t r[SIMDE_HVX_VECTOR_I16_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C(  6756), -INT16_C( 21356), -INT16_C( 11245), -INT16_C( 25400),
        -INT16_C( 13383), -INT16_C( 24072), -INT16_C(  1574), -INT16_C( 30198),  INT16_C( 31083), -INT16_C(  1103),  INT16_C( 17050), -INT16_C( 20562),
        -INT16_C(  5751),  INT16_C(   608),  INT16_C(  6129), -INT16_C( 17001),  INT16_C( 32055), -INT16_C(  9739),  INT16_C( 18508),  INT16_C( 31923),
         INT16_C( 16335),  INT16_C( 20175),  INT16_C( 17011), -INT16_C(  7397), -INT16_C(  6758), -INT16_C( 17095),  INT16_C(  7836),  INT16_C( 30535),
         INT16_C( 27338), -INT16_C( 15487),  INT16_C( 12528),  INT16_C(   425), -INT16_C( 26355),  INT16_C(  8171),  INT16_C(  1098),  INT16_C(  4039),
         INT16_C( 12019),  INT16_C( 23931),  INT16_C( 14292),  INT16_C(  6087), -INT16_C( 26832),  INT16_C( 17812), -INT16_C( 14072),  INT16_C( 24673),
        -INT16_C( 16179), -INT16_C( 32458),  INT16_C( 10889),  INT16_C( 24546), -INT16_C( 16898),  INT16_C( 11656),  INT16_C( 22272),  INT16_C( 23540) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C( 31303), -INT16_C( 10464),  INT16_C( 28904),  INT16_C( 27896),
        -INT16_C( 30802), -INT16_C( 12343), -INT16_C( 25723),  INT16_C(  7141),  INT16_C( 20337),  INT16_C( 31803), -INT16_C( 24719),  INT16_C( 29111),
        -INT16_C( 26469), -INT16_C( 25319),  INT16_C( 18681),  INT16_C( 18958), -INT16_C( 21548),  INT16_C(  5432),  INT16_C(  8075), -INT16_C( 30143),
         INT16_C( 10037),  INT16_C(  8708),  INT16_C( 12849),  INT16_C( 28910),  INT16_C( 12013), -INT16_C( 16082),  INT16_C( 29701),  INT16_C( 22181),
        -INT16_C(  6260),  INT16_C( 10219),  INT16_C( 16772),  INT16_C(   987), -INT16_C( 27038), -INT16_C( 28939),  INT16_C(  2188), -INT16_C(  4790),
         INT16_C(    24), -INT16_C(  1186),  INT16_C( 30634),  INT16_C( 20160),  INT16_C(  7073), -INT16_C(   738), -INT16_C(  7617),  INT16_C( 15928),
        -INT16_C( 32390), -INT16_C( 12490), -INT16_C(  1061),  INT16_C( 22783),  INT16_C( 25868), -INT16_C( 27121),  INT16_C( 25386), -INT16_C(  4998) },
      {  INT16_C(     0),  INT16_C(     1),        INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C(     0),
               INT16_MAX,       -INT16_MAX,  INT16_C(     0), -INT16_C( 32766),  INT16_C( 24547), -INT16_C( 10892),  INT16_C( 25387),  INT16_C( 12240),
         INT16_C( 17419), -INT16_C( 11729),  INT16_C( 24149),  INT16_C( 28197),  INT16_C( 10746),  INT16_C( 32630), -INT16_C( 23767),  INT16_C( 15863),
         INT16_C( 20718),  INT16_C( 25927), -INT16_C( 12552),  INT16_C( 29577), -INT16_C( 11933), -INT16_C( 15171),  INT16_C( 10433), -INT16_C(  3470),
         INT16_C(  6298),  INT16_C( 11467),  INT16_C(  4162),  INT16_C( 29229), -INT16_C( 18771), -INT16_C(  1013), -INT16_C( 21865),  INT16_C(  8354),
        -INT16_C( 31938), -INT16_C( 25706), -INT16_C(  4244), -INT16_C(   562),  INT16_C(   683), -INT16_C( 28426), -INT16_C(  1090),  INT16_C(  8829),
         INT16_C( 11995),  INT16_C( 25117), -INT16_C( 16342), -INT16_C( 14073),  INT16_C( 31631),  INT16_C( 18550), -INT16_C(  6455),  INT16_C(  8745),
         INT16_C( 16211), -INT16_C( 19968),  INT16_C( 11950),  INT16_C(  1763),  INT16_C( 22770), -INT16_C( 26759), -INT16_C(  3114),  INT16_C( 28538) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C( 29860), -INT16_C( 20169),  INT16_C( 14412), -INT16_C( 19068),
         INT16_C( 26196),  INT16_C( 24887),  INT16_C( 17999), -INT16_C(  9528), -INT16_C( 30780), -INT16_C(  4298),  INT16_C(  1926), -INT16_C( 24258),
        -INT16_C( 30055),  INT16_C(  9657), -INT16_C( 12718),  INT16_C( 28323),  INT16_C( 28992), -INT16_C( 26863),  INT16_C(  5633),  INT16_C( 31557),
        -INT16_C( 11315),  INT16_C( 13064), -INT16_C(  7627),  INT16_C( 23831),  INT16_C( 16260),  INT16_C( 14013),  INT16_C( 27320),  INT16_C( 12995),
        -INT16_C( 24706),  INT16_C( 25098), -INT16_C( 27231),  INT16_C( 31483), -INT16_C(  8754), -INT16_C( 18278),  INT16_C( 20368),  INT16_C( 11044),
        -INT16_C( 29614),  INT16_C( 23481),  INT16_C(  2989), -INT16_C( 17825), -INT16_C( 29109), -INT16_C( 24868),  INT16_C( 14567),  INT16_C( 21455),
         INT16_C(  7604), -INT16_C( 24408), -INT16_C( 19992), -INT16_C(  9513),  INT16_C(  7471),  INT16_C( 15900), -INT16_C( 18953), -INT16_C( 23567) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C(  1735), -INT16_C( 29029), -INT16_C( 10506),  INT16_C( 23872),
        -INT16_C( 22087), -INT16_C( 32630), -INT16_C( 18671),  INT16_C(  6844), -INT16_C(  1037), -INT16_C(  8531), -INT16_C( 18320),  INT16_C( 18561),
         INT16_C( 25069), -INT16_C( 27447),  INT16_C( 21614), -INT16_C( 19394), -INT16_C(  7779),  INT16_C( 20677), -INT16_C( 20074), -INT16_C( 22447),
        -INT16_C(  2868),  INT16_C( 30615), -INT16_C( 25353), -INT16_C( 23989),  INT16_C(  5252), -INT16_C( 23468),  INT16_C( 31579), -INT16_C(  6537),
         INT16_C(   529), -INT16_C( 26179), -INT16_C( 15560), -INT16_C(  2945), -INT16_C(    21), -INT16_C(  5023), -INT16_C(  2257),  INT16_C( 23396),
        -INT16_C( 19011),  INT16_C(   378), -INT16_C( 31564), -INT16_C( 18745), -INT16_C( 13142),  INT16_C( 27746),  INT16_C( 15992),  INT16_C(  4695),
        -INT16_C( 26188),  INT16_C(  1917), -INT16_C( 29729),  INT16_C( 15658), -INT16_C( 17353), -INT16_C( 28356), -INT16_C( 15122),  INT16_C(  1184) },
      {  INT16_C(     0),  INT16_C(     1),        INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C(     0),
               INT16_MAX,       -INT16_MAX,  INT16_C(     0), -INT16_C( 32766),  INT16_C( 28125),  INT16_C(  8860),  INT16_C( 24918),  INT16_C( 22596),
        -INT16_C( 17253), -INT16_C(  8019), -INT16_C( 28866), -INT16_C( 16372), -INT16_C( 29743),  INT16_C(  4233),  INT16_C( 20246),  INT16_C( 22717),
         INT16_C( 10412), -INT16_C( 28432),  INT16_C( 31204), -INT16_C( 17819), -INT16_C( 28765),  INT16_C( 17996),  INT16_C( 25707), -INT16_C( 11532),
        -INT16_C(  8447), -INT16_C( 17551),  INT16_C( 17726), -INT16_C( 17716),  INT16_C( 11008), -INT16_C( 28055), -INT16_C(  4259),  INT16_C( 19532),
        -INT16_C( 25235), -INT16_C( 14259), -INT16_C( 11671), -INT16_C( 31108), -INT16_C(  8733), -INT16_C( 13255),  INT16_C( 22625), -INT16_C( 12352),
        -INT16_C( 10603),  INT16_C( 23103), -INT16_C( 30983),  INT16_C(   920), -INT16_C( 15967),  INT16_C( 12922), -INT16_C(  1425),  INT16_C( 16760),
        -INT16_C( 31744), -INT16_C( 26325),  INT16_C(  9737), -INT16_C( 25171),  INT16_C( 24824), -INT16_C( 21280), -INT16_C(  3831), -INT16_C( 24751) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vsub_VhVh(a, b);

    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i16_random(1);
    simde_hvx_vector_t r = simde_Q6_Vh_vsub_VhVh(a, b);

    simde_test_hvx_vector_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VwVw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t b[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(   362906527),  INT32_C(  1031056445),  INT32_C(   640193899), -INT32_C(  1016964497),
        -INT32_C(  1682210171),  INT32_C(  1248808432),  INT32_C(   158445040),  INT32_C(   663127125),  INT32_C(   682510420), -INT32_C(  1719302726),  INT32_C(  1835079854),  INT32_C(  1635910781),
         INT32_C(   652125076), -INT32_C(  1287251048),  INT32_C(   575518744), -INT32_C(  1007694554),  INT32_C(  1282653264),  INT32_C(  1784934000), -INT32_C(   225927854), -INT32_C(   364974894) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(   241703763), -INT32_C(  1064710868), -INT32_C(   140989561), -INT32_C(   773430543),
         INT32_C(    46905450),  INT32_C(  1972603797), -INT32_C(   660794455),  INT32_C(  2107755465), -INT32_C(  1621659917),  INT32_C(   635419667),  INT32_C(  1983759982),  INT32_C(  2036752333),
        -INT32_C(  1167014609),  INT32_C(   945401132), -INT32_C(   213042226), -INT32_C(  2052709403), -INT32_C(   283699460), -INT32_C(   442538552), -INT32_C(  1196842995), -INT32_C(  2031128151) },
      {  INT32_C(           0),  INT32_C(           1),              INT32_MAX,  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(           0),
                     INT32_MAX, -INT32_C(  2147483647),  INT32_C(           0), -INT32_C(  2147483646),  INT32_C(   121202764),  INT32_C(  2095767313),  INT32_C(   781183460), -INT32_C(   243533954),
        -INT32_C(  1729115621), -INT32_C(   723795365),  INT32_C(   819239495), -INT32_C(  1444628340), -INT32_C(  1990796959),  INT32_C(  1940244903), -INT32_C(   148680128), -INT32_C(   400841552),
         INT32_C(  1819139685),  INT32_C(  2062315116),  INT32_C(   788560970),  INT32_C(  1045014849),  INT32_C(  1566352724), -INT32_C(  2067494744),  INT32_C(   970915141),  INT32_C(  1666153257) } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(   386932045), -INT32_C(  1989224921), -INT32_C(  1778006484),  INT32_C(   783810236),
        -INT32_C(  1016259831),  INT32_C(  1559727961), -INT32_C(    59682449),  INT32_C(  1181416088), -INT32_C(   973194694), -INT32_C(   368480080),  INT32_C(   958935772),  INT32_C(   896063666),
         INT32_C(  1661652486), -INT32_C(   508903867), -INT32_C(  2078522397),  INT32_C(  1282925669), -INT32_C(  1547371060), -INT32_C(   978935407),  INT32_C(   835858258),  INT32_C(  1614970033) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(     6045550),  INT32_C(  2093157016), -INT32_C(   873655308), -INT32_C(  1944237136),
        -INT32_C(  1399557360),  INT32_C(  1275607983), -INT32_C(   745308963), -INT32_C(  1200741278), -INT32_C(  1749405166), -INT32_C(   802238600), -INT32_C(   622721782),  INT32_C(  2085299962),
         INT32_C(  2110962092),  INT32_C(  1662286003), -INT32_C(   192494261), -INT32_C(   498329067),  INT32_C(  1403161199), -INT32_C(  1192396812), -INT32_C(  1563871894),  INT32_C(  1429806185) },
      {  INT32_C(           0),  INT32_C(           1),              INT32_MAX,  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(           0),
                     INT32_MAX, -INT32_C(  2147483647),  INT32_C(           0), -INT32_C(  2147483646),  INT32_C(   380886495),  INT32_C(   212585359), -INT32_C(   904351176), -INT32_C(  1566919924),
         INT32_C(   383297529),  INT32_C(   284119978),  INT32_C(   685626514), -INT32_C(  1912809930),  INT32_C(   776210472),  INT32_C(   433758520),  INT32_C(  1581657554), -INT32_C(  1189236296),
        -INT32_C(   449309606),  INT32_C(  2123777426), -INT32_C(  1886028136),  INT32_C(  1781254736),  INT32_C(  1344435037),  INT32_C(   213461405), -INT32_C(  1895237144),  INT32_C(   185163848) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vsub_VwVw(a, b);

    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i32_random(1);
    simde_hvx_vector_t r = simde_Q6_Vw_vsub_VwVw(a, b);

    simde_test_hvx_vector_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VbVb_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[SIMDE_HVX_VECTOR_SIZE];
    int8_t b[SIMDE_HVX_VECTOR_SIZE];
    int8_t r[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),  INT8_C(  53), -INT8_C(   5), -INT8_C( 119), -INT8_C( 116),
         INT8_C(  82),  INT8_C(  81), -INT8_C(  90), -INT8_C(  21),  INT8_C(  54),  INT8_C(  12),  INT8_C(  42), -INT8_C( 105),
        -INT8_C(  19),  INT8_C(  10),  INT8_C(  72), -INT8_C(  62), -INT8_C( 106), -INT8_C(  90),  INT8_C(   1), -INT8_C(  16),
        -INT8_C(  11), -INT8_C( 120), -INT8_C(  63), -INT8_C(  75), -INT8_C(  80),  INT8_C(  36),      INT8_MIN, -INT8_C(  60),
        -INT8_C(  65),  INT8_C(  48), -INT8_C( 112), -INT8_C(   8),  INT8_C(  58),  INT8_C(  23), -INT8_C(  45), -INT8_C(   9),
         INT8_C(  54),  INT8_C(   0), -INT8_C(  36), -INT8_C(  49),  INT8_C( 103), -INT8_C(  45), -INT8_C(  42),  INT8_C(  16),
        -INT8_C(  43),  INT8_C(  64),  INT8_C(  88),  INT8_C(  85), -INT8_C(  20),  INT8_C(  76), -INT8_C(  49), -INT8_C(  12),
         INT8_C(  74), -INT8_C(  50), -INT8_C( 126),  INT8_C(  67),  INT8_C(   5),  INT8_C(  20),  INT8_C(  98), -INT8_C(  88),
         INT8_C( 112), -INT8_C(  83), -INT8_C(  73),  INT8_C(  52), -INT8_C( 124), -INT8_C(  67),  INT8_C(  41), -INT8_C(  34),
         INT8_C(   1), -INT8_C(  87),  INT8_C( 109),  INT8_C(  73), -INT8_C(  44),  INT8_C(  42),  INT8_C(  40),  INT8_C(  86),
         INT8_C( 101),  INT8_C( 115), -INT8_C(  71),  INT8_C( 119), -INT8_C(  78), -INT8_C(  29),  INT8_C(  64), -INT8_C( 116),
        -INT8_C(  44), -INT8_C(  58),  INT8_C(  62),  INT8_C(  26),  INT8_C(  69), -INT8_C(  83), -INT8_C(  99), -INT8_C( 123),
        -INT8_C(  40), -INT8_C(  68),  INT8_C(  98), -INT8_C(  43),  INT8_C(  35),  INT8_C(  55), -INT8_C(   2), -INT8_C(  24),
         INT8_C(  52), -INT8_C(  96), -INT8_C(  86),  INT8_C(  31), -INT8_C( 103), -INT8_C(  26), -INT8_C( 101),  INT8_C(   1),
        -INT8_C(   6),  INT8_C(  39), -INT8_C(  33),  INT8_C(  67), -INT8_C( 113),  INT8_C(  70),  INT8_C(  64), -INT8_C( 105) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  26),  INT8_C(  65), -INT8_C(  46), -INT8_C( 102),
        -INT8_C(  87), -INT8_C(  86), -INT8_C( 109), -INT8_C(  72), -INT8_C(  62),  INT8_C(  42),  INT8_C( 110),  INT8_C(  99),
        -INT8_C(  97),  INT8_C(  89),  INT8_C(  95),  INT8_C(  92), -INT8_C( 105), -INT8_C( 108),  INT8_C( 109),  INT8_C(  94),
        -INT8_C( 125), -INT8_C(  99),  INT8_C( 107),  INT8_C(  75), -INT8_C(  70),  INT8_C(  63), -INT8_C(  63),  INT8_C(  97),
         INT8_C(  60),  INT8_C(  57), -INT8_C(  31), -INT8_C(  10),  INT8_C(  43),  INT8_C(   9),  INT8_C(  85), -INT8_C(  52),
        -INT8_C(  61), -INT8_C(  91), -INT8_C(  20), -INT8_C(  65), -INT8_C(   6), -INT8_C(  64), -INT8_C(  93),  INT8_C(  85),
         INT8_C(  37), -INT8_C( 123), -INT8_C(  32), -INT8_C(  22), -INT8_C(  53), -INT8_C(  25), -INT8_C(  13), -INT8_C(  61),
        -INT8_C(  96), -INT8_C( 126), -INT8_C(  58), -INT8_C(  62), -INT8_C(  54),  INT8_C(  73), -INT8_C(  49), -INT8_C(  21),
             INT8_MIN,  INT8_C(   2), -INT8_C(  95),  INT8_C( 106),  INT8_C(  26), -INT8_C(  92),  INT8_C(   7), -INT8_C( 104),
         INT8_C(  44), -INT8_C(  77), -INT8_C(  55),  INT8_C(  67), -INT8_C(  87), -INT8_C(   3),  INT8_C( 125), -INT8_C( 113),
        -INT8_C(  68),  INT8_C(  50), -INT8_C( 118),  INT8_C(  34),  INT8_C(  37), -INT8_C( 111), -INT8_C(  24), -INT8_C(   7),
         INT8_C(  80),  INT8_C( 124),  INT8_C(  16),  INT8_C(   1), -INT8_C(  55), -INT8_C(  48),  INT8_C( 121),  INT8_C(  39),
         INT8_C(  60),  INT8_C(  41), -INT8_C( 107),  INT8_C(  49),  INT8_C( 121),  INT8_C(  16),  INT8_C(  81), -INT8_C(  44),
         INT8_C(   7), -INT8_C(  26), -INT8_C(  98),  INT8_C(  95), -INT8_C(  93),  INT8_C(  16), -INT8_C( 127),  INT8_C( 123),
         INT8_C(   7), -INT8_C(   2), -INT8_C(  13),  INT8_C(  70),  INT8_C(  29), -INT8_C(  42),  INT8_C(  52), -INT8_C(  79) },
      {  INT8_C(   0),      INT8_MIN,      INT8_MAX,  INT8_C( 126), -INT8_C( 127),  INT8_C( 126), -INT8_C( 127),  INT8_C(   0),
             INT8_MAX,      INT8_MAX,  INT8_C(   0), -INT8_C( 126),  INT8_C(  27), -INT8_C(  70), -INT8_C(  73), -INT8_C(  14),
             INT8_MAX,      INT8_MAX,  INT8_C(  19),  INT8_C(  51),  INT8_C( 116), -INT8_C(  30), -INT8_C(  68),      INT8_MIN,
         INT8_C(  78), -INT8_C(  79), -INT8_C(  23),      INT8_MIN, -INT8_C(   1),  INT8_C(  18), -INT8_C( 108), -INT8_C( 110),
         INT8_C( 114), -INT8_C(  21),      INT8_MIN,      INT8_MIN, -INT8_C(  10), -INT8_C(  27), -INT8_C(  65),      INT8_MIN,
        -INT8_C( 125), -INT8_C(   9), -INT8_C(  81),  INT8_C(   2),  INT8_C(  15),  INT8_C(  14),      INT8_MIN,  INT8_C(  43),
         INT8_C( 115),  INT8_C(  91), -INT8_C(  16),  INT8_C(  16),  INT8_C( 109),  INT8_C(  19),  INT8_C(  51), -INT8_C(  69),
        -INT8_C(  80),      INT8_MAX,  INT8_C( 120),  INT8_C( 107),  INT8_C(  33),  INT8_C( 101), -INT8_C(  36),  INT8_C(  49),
             INT8_MAX,  INT8_C(  76), -INT8_C(  68),      INT8_MAX,  INT8_C(  59), -INT8_C(  53),      INT8_MAX, -INT8_C(  67),
             INT8_MAX, -INT8_C(  85),  INT8_C(  22), -INT8_C(  54),      INT8_MIN,  INT8_C(  25),  INT8_C(  34),  INT8_C(  70),
        -INT8_C(  43), -INT8_C(  10),      INT8_MAX,  INT8_C(   6),  INT8_C(  43),  INT8_C(  45), -INT8_C(  85),      INT8_MAX,
             INT8_MAX,  INT8_C(  65),  INT8_C(  47),  INT8_C(  85), -INT8_C( 115),  INT8_C(  82),  INT8_C(  88), -INT8_C( 109),
        -INT8_C( 124),      INT8_MIN,  INT8_C(  46),  INT8_C(  25),  INT8_C( 124), -INT8_C(  35),      INT8_MIN,      INT8_MIN,
        -INT8_C( 100), -INT8_C( 109),      INT8_MAX, -INT8_C(  92), -INT8_C(  86),  INT8_C(  39), -INT8_C(  83),  INT8_C(  20),
         INT8_C(  45), -INT8_C(  70),  INT8_C(  12), -INT8_C(  64), -INT8_C(  10), -INT8_C(  42),  INT8_C(  26), -INT8_C( 122),
        -INT8_C(  13),  INT8_C(  41), -INT8_C(  20), -INT8_C(   3),      INT8_MIN,  INT8_C( 112),  INT8_C(  12), -INT8_C(  26) } },
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1), -INT8_C(  25), -INT8_C(  87),  INT8_C(  42), -INT8_C(   2),
        -INT8_C(  87),  INT8_C( 108), -INT8_C(  50),  INT8_C(  88),  INT8_C(  73), -INT8_C(  23), -INT8_C(  14), -INT8_C( 123),
        -INT8_C(  75),  INT8_C(  41), -INT8_C( 109),  INT8_C(  42), -INT8_C(  80),  INT8_C(  43), -INT8_C(  26), -INT8_C(  44),
         INT8_C( 120),  INT8_C( 120),  INT8_C( 121),  INT8_C( 115),  INT8_C( 122), -INT8_C( 126),  INT8_C(  98),  INT8_C(  21),
        -INT8_C(  70),  INT8_C(  27), -INT8_C( 125),  INT8_C(  32), -INT8_C(  32),  INT8_C(  40),  INT8_C(  54), -INT8_C(  78),
        -INT8_C(  49),  INT8_C(  55), -INT8_C(  71),  INT8_C(  66),  INT8_C(  52), -INT8_C( 119), -INT8_C(  45), -INT8_C(  17),
        -INT8_C( 105), -INT8_C(  97), -INT8_C(  85),  INT8_C(  52), -INT8_C(  26), -INT8_C(  20),  INT8_C(  25), -INT8_C(  81),
         INT8_C(  25),  INT8_C(  42),  INT8_C(  62),  INT8_C(  24),  INT8_C( 104), -INT8_C(  86),  INT8_C(  69), -INT8_C(  93),
         INT8_C(  69), -INT8_C(  94),  INT8_C(  31),  INT8_C(  56), -INT8_C(   2),  INT8_C(  27),  INT8_C(  94), -INT8_C(  98),
         INT8_C(  87),  INT8_C(  43),  INT8_C(  76),  INT8_C(  38),  INT8_C(  90), -INT8_C(  27),  INT8_C(  99),  INT8_C(  39),
         INT8_C(  56), -INT8_C( 126), -INT8_C(  67), -INT8_C(  29), -INT8_C(  35), -INT8_C( 105),  INT8_C(  82), -INT8_C(  84),
         INT8_C(  13), -INT8_C(  88),  INT8_C(  88), -INT8_C(  79),  INT8_C(   9),  INT8_C(   0),  INT8_C(  12),  INT8_C(  62),
         INT8_C(   5),  INT8_C(  18),  INT8_C(  19), -INT8_C( 122), -INT8_C(  64), -INT8_C(  30), -INT8_C(   7), -INT8_C(  13),
         INT8_C( 115), -INT8_C(  56),  INT8_C(  18), -INT8_C(  97), -INT8_C(  74),  INT8_C(  62),  INT8_C(  33), -INT8_C( 107),
        -INT8_C(  13),  INT8_C(  58),  INT8_C( 115), -INT8_C(  48),  INT8_C(  76), -INT8_C( 115),  INT8_C(  93), -INT8_C( 127) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(  42),  INT8_C(  42),  INT8_C(  99),  INT8_C(  89),
         INT8_C( 102),  INT8_C(  83), -INT8_C(  67),  INT8_C(   2),  INT8_C( 109), -INT8_C(   4),  INT8_C(  67), -INT8_C(  14),
        -INT8_C( 118), -INT8_C(   6),  INT8_C(  20),  INT8_C(  46), -INT8_C( 119),  INT8_C(  69), -INT8_C(  81), -INT8_C(  28),
        -INT8_C(  47), -INT8_C( 120), -INT8_C(  92),  INT8_C(   7), -INT8_C(  68), -INT8_C(  34), -INT8_C(  37), -INT8_C(  30),
        -INT8_C(  72), -INT8_C(  34), -INT8_C(  17), -INT8_C(  81), -INT8_C(  29), -INT8_C(  26),  INT8_C(  31),  INT8_C(  97),
        -INT8_C(  75), -INT8_C( 122),  INT8_C(  60), -INT8_C(   1),  INT8_C( 120),  INT8_C(   7), -INT8_C(  66),  INT8_C(  25),
         INT8_C(  61), -INT8_C(  50),  INT8_C( 111), -INT8_C(  44),  INT8_C(  22),  INT8_C(  14),  INT8_C(  67), -INT8_C(  64),
        -INT8_C(  37), -INT8_C(  90),  INT8_C(  21), -INT8_C(  20),  INT8_C(  74), -INT8_C(  80), -INT8_C(  22),  INT8_C( 118),
        -INT8_C(  46), -INT8_C(  74),  INT8_C(  18), -INT8_C(  44), -INT8_C(  59), -INT8_C(  52),  INT8_C( 119),  INT8_C( 124),
        -INT8_C(  31), -INT8_C(  76),  INT8_C(  69), -INT8_C(  60), -INT8_C(  55), -INT8_C(  87), -INT8_C(  67),  INT8_C(  92),
         INT8_C(  99),  INT8_C(  38),  INT8_C(  76), -INT8_C(  70), -INT8_C(  94),  INT8_C(  69), -INT8_C(   8), -INT8_C(  27),
         INT8_C(  24),  INT8_C(  90),  INT8_C( 120),  INT8_C(  92), -INT8_C(  50), -INT8_C(   4), -INT8_C(  26), -INT8_C(  43),
        -INT8_C(  98), -INT8_C( 124), -INT8_C(  32), -INT8_C(  53),  INT8_C(  95),  INT8_C(  80), -INT8_C( 103),  INT8_C( 102),
        -INT8_C(  96),  INT8_C( 122),  INT8_C( 103), -INT8_C(  95), -INT8_C(  14), -INT8_C(  34), -INT8_C(  88),  INT8_C(  84),
             INT8_MAX, -INT8_C(  32),  INT8_C(  91), -INT8_C(   4), -INT8_C( 110),  INT8_C(  18),  INT8_C( 116),  INT8_C(  60) },
      {  INT8_C(   0),      INT8_MIN,      INT8_MAX,  INT8_C( 126), -INT8_C( 127),  INT8_C( 126), -INT8_C( 127),  INT8_C(   0),
             INT8_MAX,      INT8_MAX,  INT8_C(   0), -INT8_C( 126),  INT8_C(  17),      INT8_MIN, -INT8_C(  57), -INT8_C(  91),
             INT8_MIN,  INT8_C(  25),  INT8_C(  17),  INT8_C(  86), -INT8_C(  36), -INT8_C(  19), -INT8_C(  81), -INT8_C( 109),
         INT8_C(  43),  INT8_C(  47),      INT8_MIN, -INT8_C(   4),  INT8_C(  39), -INT8_C(  26),  INT8_C(  55), -INT8_C(  16),
             INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C( 108),      INT8_MAX, -INT8_C(  92),      INT8_MAX,  INT8_C(  51),
         INT8_C(   2),  INT8_C(  61), -INT8_C( 108),  INT8_C( 113), -INT8_C(   3),  INT8_C(  66),  INT8_C(  23),      INT8_MIN,
         INT8_C(  26),      INT8_MAX,      INT8_MIN,  INT8_C(  67), -INT8_C(  68), -INT8_C( 126),  INT8_C(  21), -INT8_C(  42),
             INT8_MIN, -INT8_C(  47),      INT8_MIN,  INT8_C(  96), -INT8_C(  48), -INT8_C(  34), -INT8_C(  42), -INT8_C(  17),
         INT8_C(  62),      INT8_MAX,  INT8_C(  41),  INT8_C(  44),  INT8_C(  30), -INT8_C(   6),  INT8_C(  91),      INT8_MIN,
         INT8_C( 115), -INT8_C(  20),  INT8_C(  13),  INT8_C( 100),  INT8_C(  57),  INT8_C(  79), -INT8_C(  25),      INT8_MIN,
         INT8_C( 118),  INT8_C( 119),  INT8_C(   7),  INT8_C(  98),      INT8_MAX,  INT8_C(  60),      INT8_MAX, -INT8_C(  53),
        -INT8_C(  43),      INT8_MIN,      INT8_MIN,  INT8_C(  41),  INT8_C(  59),      INT8_MIN,  INT8_C(  90), -INT8_C(  57),
        -INT8_C(  11),      INT8_MIN, -INT8_C(  32),      INT8_MIN,  INT8_C(  59),  INT8_C(   4),  INT8_C(  38),  INT8_C( 105),
         INT8_C( 103),      INT8_MAX,  INT8_C(  51), -INT8_C(  69),      INT8_MIN, -INT8_C( 110),  INT8_C(  96), -INT8_C( 115),
             INT8_MAX,      INT8_MIN, -INT8_C(  85), -INT8_C(   2), -INT8_C(  60),  INT8_C(  96),  INT8_C( 121),      INT8_MIN,
             INT8_MIN,  INT8_C(  90),  INT8_C(  24), -INT8_C(  44),      INT8_MAX,      INT8_MIN, -INT8_C(  23),      INT8_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vb_vsub_VbVb_sat(a, b);

    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i8_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i8_random(1);
    simde_hvx_vector_t r = simde_Q6_Vb_vsub_VbVb_sat(a, b);

    simde_test_hvx_vector_i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VhVh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t r[SIMDE_HVX_VECTOR_I16_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C( 11051),  INT16_C( 25506), -INT16_C( 23799),  INT16_C( 31613),
        -INT16_C( 31575), -INT16_C( 27149), -INT16_C(  6585), -INT16_C(  9257), -INT16_C( 27504),  INT16_C( 21679),  INT16_C(  5752),  INT16_C( 26537),
         INT16_C( 10346), -INT16_C( 11202),  INT16_C( 16037), -INT16_C( 23191), -INT16_C(  8826),  INT16_C( 25198), -INT16_C(  6032),  INT16_C( 22751),
         INT16_C(  7464), -INT16_C( 25659),  INT16_C( 31704),  INT16_C(  7954),  INT16_C( 29212), -INT16_C(  5020), -INT16_C( 15161), -INT16_C( 27260),
        -INT16_C( 19253),  INT16_C( 11214),  INT16_C( 13141),  INT16_C(  1821),  INT16_C( 26660), -INT16_C( 26179), -INT16_C( 13193),  INT16_C( 15046),
        -INT16_C(  4708), -INT16_C(  4582),  INT16_C( 12257),  INT16_C(  3272), -INT16_C( 28332),  INT16_C( 27145),  INT16_C( 24956),  INT16_C( 10176),
        -INT16_C(  2988),  INT16_C( 24267), -INT16_C( 30985),  INT16_C( 22004),  INT16_C( 31944), -INT16_C(  8652), -INT16_C(  3676),  INT16_C( 28317) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 17324), -INT16_C( 18294), -INT16_C(  5291), -INT16_C(  9871),
         INT16_C( 25916),  INT16_C( 25272), -INT16_C( 10526),  INT16_C( 12073),  INT16_C( 20605),  INT16_C( 13658), -INT16_C(  2907),  INT16_C( 10076),
         INT16_C( 31622), -INT16_C( 10924),  INT16_C( 21785), -INT16_C(  1911),  INT16_C(  6719),  INT16_C( 27255), -INT16_C(  1465),  INT16_C( 11467),
        -INT16_C(   927),  INT16_C( 13844), -INT16_C( 12427),  INT16_C( 28989),  INT16_C(  3059), -INT16_C( 23535),  INT16_C( 31255),  INT16_C(  8872),
         INT16_C( 23472), -INT16_C( 25647), -INT16_C( 27174), -INT16_C( 27968),  INT16_C(  6590),  INT16_C( 27939),  INT16_C( 18593), -INT16_C( 27117),
        -INT16_C(   286),  INT16_C(  1339), -INT16_C( 23291),  INT16_C(  7324),  INT16_C( 21582),  INT16_C( 17582), -INT16_C( 31239),  INT16_C(  1260),
        -INT16_C(  2060),  INT16_C(  1339), -INT16_C(  3870), -INT16_C( 13936),  INT16_C(  7755),  INT16_C( 32022), -INT16_C( 24715), -INT16_C(  2195) },
      {  INT16_C(     0),        INT16_MIN,        INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C(     0),
               INT16_MAX,        INT16_MAX,  INT16_C(     0), -INT16_C( 32766), -INT16_C( 28375),        INT16_MAX, -INT16_C( 18508),        INT16_MAX,
               INT16_MIN,        INT16_MIN,  INT16_C(  3941), -INT16_C( 21330),        INT16_MIN,  INT16_C(  8021),  INT16_C(  8659),  INT16_C( 16461),
        -INT16_C( 21276), -INT16_C(   278), -INT16_C(  5748), -INT16_C( 21280), -INT16_C( 15545), -INT16_C(  2057), -INT16_C(  4567),  INT16_C( 11284),
         INT16_C(  8391),        INT16_MIN,        INT16_MAX, -INT16_C( 21035),  INT16_C( 26153),  INT16_C( 18515),        INT16_MIN,        INT16_MIN,
               INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 29789),  INT16_C( 20070),        INT16_MIN, -INT16_C( 31786),        INT16_MAX,
        -INT16_C(  4422), -INT16_C(  5921),        INT16_MAX, -INT16_C(  4052),        INT16_MIN,  INT16_C(  9563),        INT16_MAX,  INT16_C(  8916),
        -INT16_C(   928),  INT16_C( 22928), -INT16_C( 27115),        INT16_MAX,  INT16_C( 24189),        INT16_MIN,  INT16_C( 21039),  INT16_C( 30512) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C( 23170),  INT16_C(  5031), -INT16_C( 21811), -INT16_C( 27879),
         INT16_C( 28383),  INT16_C( 27030), -INT16_C( 28848),  INT16_C(  7895),  INT16_C( 12438), -INT16_C(  4461),  INT16_C(  8746), -INT16_C(  9556),
        -INT16_C( 24773),  INT16_C( 19425), -INT16_C( 25936),  INT16_C(  3966),  INT16_C( 22675),  INT16_C( 28395), -INT16_C( 21970),  INT16_C( 18512),
        -INT16_C(  2553), -INT16_C( 30950),  INT16_C(  5511),  INT16_C( 21276), -INT16_C( 16633), -INT16_C( 26848), -INT16_C( 14202),  INT16_C( 13044),
        -INT16_C( 25908), -INT16_C( 30203),  INT16_C(  1718),  INT16_C(   150), -INT16_C( 29227),  INT16_C(  5409), -INT16_C( 18784),  INT16_C( 15013),
         INT16_C( 29009), -INT16_C(  2013),  INT16_C(  5118),  INT16_C( 20608), -INT16_C(  5742), -INT16_C( 19975), -INT16_C( 28809), -INT16_C( 24184),
         INT16_C(  1666), -INT16_C(  1406), -INT16_C(   948),  INT16_C( 31155),  INT16_C( 24546), -INT16_C( 10585),  INT16_C( 29750),  INT16_C(  3813) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C( 19926),  INT16_C( 20067),  INT16_C( 21011), -INT16_C( 26510),
         INT16_C(  9737),  INT16_C( 23422), -INT16_C( 26284),  INT16_C(   273),  INT16_C( 21967), -INT16_C( 28145), -INT16_C( 22648), -INT16_C( 28676),
         INT16_C( 31834), -INT16_C( 19176), -INT16_C( 32572),  INT16_C( 32345), -INT16_C(  3316), -INT16_C(  5707),  INT16_C( 17652),  INT16_C(  3622),
         INT16_C(   949),  INT16_C(  2873),  INT16_C( 24431), -INT16_C( 15988), -INT16_C( 11804), -INT16_C( 11607), -INT16_C(  4445), -INT16_C( 21914),
         INT16_C( 11512), -INT16_C( 22802), -INT16_C(  6976), -INT16_C(  5577), -INT16_C( 24214),  INT16_C( 26855), -INT16_C(   460), -INT16_C( 16463),
         INT16_C( 29036), -INT16_C( 11415), -INT16_C( 11379),  INT16_C(  3514),  INT16_C( 30470),  INT16_C( 32294), -INT16_C( 17835),  INT16_C( 30960),
         INT16_C( 28063), -INT16_C( 10439), -INT16_C( 19633), -INT16_C( 16059),  INT16_C( 23750), -INT16_C(  8679), -INT16_C( 20395),  INT16_C( 17012) },
      {  INT16_C(     0),        INT16_MIN,        INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C(     0),
               INT16_MAX,        INT16_MAX,  INT16_C(     0), -INT16_C( 32766),        INT16_MAX, -INT16_C( 15036),        INT16_MIN, -INT16_C(  1369),
         INT16_C( 18646),  INT16_C(  3608), -INT16_C(  2564),  INT16_C(  7622), -INT16_C(  9529),  INT16_C( 23684),  INT16_C( 31394),  INT16_C( 19120),
               INT16_MIN,        INT16_MAX,  INT16_C(  6636), -INT16_C( 28379),  INT16_C( 25991),        INT16_MAX,        INT16_MIN,  INT16_C( 14890),
        -INT16_C(  3502),        INT16_MIN, -INT16_C( 18920),        INT16_MAX, -INT16_C(  4829), -INT16_C( 15241), -INT16_C(  9757),        INT16_MAX,
               INT16_MIN, -INT16_C(  7401),  INT16_C(  8694),  INT16_C(  5727), -INT16_C(  5013), -INT16_C( 21446), -INT16_C( 18324),  INT16_C( 31476),
        -INT16_C(    27),  INT16_C(  9402),  INT16_C( 16497),  INT16_C( 17094),        INT16_MIN,        INT16_MIN, -INT16_C( 10974),        INT16_MIN,
        -INT16_C( 26397),  INT16_C(  9033),  INT16_C( 18685),        INT16_MAX,  INT16_C(   796), -INT16_C(  1906),        INT16_MAX, -INT16_C( 13199) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vsub_VhVh_sat(a, b);

    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i16_random(1);
    simde_hvx_vector_t r = simde_Q6_Vh_vsub_VhVh_sat(a, b);

    simde_test_hvx_vector_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VwVw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t b[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(   889666988),  INT32_C(  1842913837),  INT32_C(  1230031760),  INT32_C(   947321767),
        -INT32_C(   148741080), -INT32_C(   795319155), -INT32_C(   573600778),  INT32_C(  1172935868), -INT32_C(   740192085),  INT32_C(  2112860497),  INT32_C(   825473243),  INT32_C(   332983130),
         INT32_C(  1458794455), -INT32_C(   893131663), -INT32_C(   293918868), -INT32_C(   630610000),  INT32_C(  1858485897), -INT32_C(  1764016254),  INT32_C(  2133899405),  INT32_C(  1962506111) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(  1968169781), -INT32_C(  1687830721), -INT32_C(   205109658), -INT32_C(   757930349),
         INT32_C(   903256888), -INT32_C(  1451589827), -INT32_C(  1278919803), -INT32_C(  1822767139),  INT32_C(   687803897),  INT32_C(  2125731901),  INT32_C(   894548198),  INT32_C(  2016030542),
        -INT32_C(    67952558),  INT32_C(   406842983), -INT32_C(  1169216668), -INT32_C(   315925405), -INT32_C(  1000452324), -INT32_C(  2118650118), -INT32_C(  1741054421), -INT32_C(   541141601) },
      {  INT32_C(           0),              INT32_MIN,              INT32_MAX,  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(           0),
                     INT32_MAX,              INT32_MAX,  INT32_C(           0), -INT32_C(  2147483646),              INT32_MIN,              INT32_MAX,  INT32_C(  1435141418),  INT32_C(  1705252116),
        -INT32_C(  1051997968),  INT32_C(   656270672),  INT32_C(   705319025),              INT32_MAX, -INT32_C(  1427995982), -INT32_C(    12871404), -INT32_C(    69074955), -INT32_C(  1683047412),
         INT32_C(  1526747013), -INT32_C(  1299974646),  INT32_C(   875297800), -INT32_C(   314684595),              INT32_MAX,  INT32_C(   354633864),              INT32_MAX,              INT32_MAX } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(   675734615),  INT32_C(  1545321681),  INT32_C(  1118523696),  INT32_C(  1094648641),
         INT32_C(  1705080284), -INT32_C(  1936083748), -INT32_C(   976537416), -INT32_C(    58721586), -INT32_C(   164123242),  INT32_C(  1194125272),  INT32_C(   706482596), -INT32_C(  2010750840),
        -INT32_C(   269844292), -INT32_C(  1711195350),  INT32_C(   302430573), -INT32_C(  1369881337),  INT32_C(   402931411), -INT32_C(  1547088311),  INT32_C(    18136306),  INT32_C(   293452765) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(  1201695225), -INT32_C(  1681742030), -INT32_C(  2044305424),  INT32_C(  1059797113),
        -INT32_C(   568327638), -INT32_C(   812995644), -INT32_C(    63906923), -INT32_C(  1139866344), -INT32_C(  1052425519), -INT32_C(   911731724), -INT32_C(  1057311345),  INT32_C(   884538815),
         INT32_C(   363320337),  INT32_C(   202030964), -INT32_C(  1710223900), -INT32_C(   284871437), -INT32_C(   628527930), -INT32_C(  1330518143), -INT32_C(  2094315629), -INT32_C(   278986336) },
      {  INT32_C(           0),              INT32_MIN,              INT32_MAX,  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(           0),
                     INT32_MAX,              INT32_MAX,  INT32_C(           0), -INT32_C(  2147483646), -INT32_C(  1877429840),              INT32_MAX,              INT32_MAX,  INT32_C(    34851528),
                     INT32_MAX, -INT32_C(  1123088104), -INT32_C(   912630493),  INT32_C(  1081144758),  INT32_C(   888302277),  INT32_C(  2105856996),  INT32_C(  1763793941),              INT32_MIN,
        -INT32_C(   633164629), -INT32_C(  1913226314),  INT32_C(  2012654473), -INT32_C(  1085009900),  INT32_C(  1031459341), -INT32_C(   216570168),  INT32_C(  2112451935),  INT32_C(   572439101) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vsub_VwVw_sat(a, b);

    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i32_random(1);
    simde_hvx_vector_t r = simde_Q6_Vw_vsub_VwVw_sat(a, b);

    simde_test_hvx_vector_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VubVub_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[SIMDE_HVX_VECTOR_SIZE];
    uint8_t b[SIMDE_HVX_VECTOR_SIZE];
    uint8_t r[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(214), UINT8_C(160), UINT8_C(127), UINT8_C( 26),
        UINT8_C( 26), UINT8_C(  0), UINT8_C( 41), UINT8_C(218), UINT8_C(147), UINT8_C(202), UINT8_C(224), UINT8_C( 41),
        UINT8_C( 27), UINT8_C(207), UINT8_C(129), UINT8_C(229), UINT8_C( 86), UINT8_C(221), UINT8_C( 70), UINT8_C(226),
        UINT8_C( 13), UINT8_C(164), UINT8_C(174), UINT8_C(198), UINT8_C( 42), UINT8_C( 82), UINT8_C(229), UINT8_C(194),
        UINT8_C( 42), UINT8_C( 85), UINT8_C(165), UINT8_C( 68), UINT8_C(135), UINT8_C( 66), UINT8_C( 32), UINT8_C(222),
        UINT8_C( 13), UINT8_C(147), UINT8_C( 58), UINT8_C( 85), UINT8_C( 51), UINT8_C(176), UINT8_C(207), UINT8_C(217),
        UINT8_C(  5), UINT8_C(104), UINT8_C(232), UINT8_C(  8), UINT8_C( 65), UINT8_C( 77), UINT8_C(118), UINT8_C(220),
        UINT8_C( 84), UINT8_C(153), UINT8_C( 59), UINT8_C(172), UINT8_C( 75), UINT8_C(178), UINT8_C( 18), UINT8_C(219),
        UINT8_C(254), UINT8_C(135), UINT8_C( 80), UINT8_C(180), UINT8_C(  0), UINT8_C( 40), UINT8_C(174), UINT8_C(230),
        UINT8_C(156), UINT8_C(100), UINT8_C(182), UINT8_C( 69), UINT8_C(223), UINT8_C(185), UINT8_C( 44), UINT8_C(137),
        UINT8_C(126), UINT8_C( 31), UINT8_C(228), UINT8_C(155), UINT8_C(234), UINT8_C(106), UINT8_C( 57), UINT8_C(192),
        UINT8_C(109), UINT8_C(162), UINT8_C( 71), UINT8_C(  8), UINT8_C(251), UINT8_C( 16), UINT8_C(138), UINT8_C( 64),
        UINT8_C(  3), UINT8_C(108), UINT8_C(240), UINT8_C(110), UINT8_C( 60), UINT8_C( 99), UINT8_C( 46), UINT8_C( 89),
        UINT8_C(172), UINT8_C(  5), UINT8_C(139), UINT8_C(179), UINT8_C( 47), UINT8_C(134), UINT8_C(188), UINT8_C(245),
        UINT8_C( 27), UINT8_C(253), UINT8_C(121), UINT8_C(227), UINT8_C(142), UINT8_C( 99), UINT8_C(247), UINT8_C(181) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(122), UINT8_C(141), UINT8_C(134), UINT8_C(203),
        UINT8_C(206), UINT8_C(135), UINT8_C( 40), UINT8_C(217), UINT8_C(  3), UINT8_C( 25), UINT8_C(214), UINT8_C( 34),
        UINT8_C(114), UINT8_C(140), UINT8_C(160), UINT8_C( 53), UINT8_C( 34), UINT8_C(183), UINT8_C(155), UINT8_C(219),
        UINT8_C(152), UINT8_C(224), UINT8_C(139), UINT8_C(138), UINT8_C( 44), UINT8_C(159), UINT8_C(151), UINT8_C( 99),
        UINT8_C(224), UINT8_C( 43), UINT8_C(107), UINT8_C(181), UINT8_C(  9), UINT8_C(190), UINT8_C(155), UINT8_C(182),
        UINT8_C(106), UINT8_C( 38), UINT8_C(143), UINT8_C(194), UINT8_C( 34), UINT8_C( 47), UINT8_C(101), UINT8_C( 45),
        UINT8_C( 45), UINT8_C(234), UINT8_C( 51), UINT8_C(  3), UINT8_C(220), UINT8_C(244), UINT8_C(109), UINT8_C(127),
        UINT8_C(172), UINT8_C(215), UINT8_C( 42), UINT8_C(145), UINT8_C(199), UINT8_C(190), UINT8_C( 33), UINT8_C( 52),
        UINT8_C(181), UINT8_C(163), UINT8_C(149), UINT8_C(195), UINT8_C(137), UINT8_C(  7), UINT8_C(239), UINT8_C(100),
        UINT8_C(129), UINT8_C(112), UINT8_C(227), UINT8_C(114), UINT8_C(103), UINT8_C( 24), UINT8_C(101), UINT8_C(164),
        UINT8_C(165), UINT8_C( 80), UINT8_C( 92), UINT8_C( 86), UINT8_C( 58), UINT8_C(240), UINT8_C(113), UINT8_C(200),
        UINT8_C(  7), UINT8_C(184), UINT8_C( 54), UINT8_C( 23), UINT8_C(116), UINT8_C(109), UINT8_C(220), UINT8_C( 27),
        UINT8_C(226), UINT8_C( 29), UINT8_C( 49), UINT8_C( 31), UINT8_C(180), UINT8_C(112), UINT8_C(195), UINT8_C(105),
        UINT8_C(217), UINT8_C(246), UINT8_C(119), UINT8_C(131), UINT8_C( 98), UINT8_C( 21), UINT8_C(226), UINT8_C( 84),
        UINT8_C(248), UINT8_C( 29), UINT8_C(132), UINT8_C(215), UINT8_C(135), UINT8_C(132), UINT8_C( 75), UINT8_C(243) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(254), UINT8_C(  0), UINT8_C(254), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C( 92), UINT8_C( 19), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(144), UINT8_C(177), UINT8_C( 10), UINT8_C(  7),
        UINT8_C(  0), UINT8_C( 67), UINT8_C(  0), UINT8_C(176), UINT8_C( 52), UINT8_C( 38), UINT8_C(  0), UINT8_C(  7),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 35), UINT8_C( 60), UINT8_C(  0), UINT8_C(  0), UINT8_C( 78), UINT8_C( 95),
        UINT8_C(  0), UINT8_C( 42), UINT8_C( 58), UINT8_C(  0), UINT8_C(126), UINT8_C(  0), UINT8_C(  0), UINT8_C( 40),
        UINT8_C(  0), UINT8_C(109), UINT8_C(  0), UINT8_C(  0), UINT8_C( 17), UINT8_C(129), UINT8_C(106), UINT8_C(172),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(181), UINT8_C(  5), UINT8_C(  0), UINT8_C(  0), UINT8_C(  9), UINT8_C( 93),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 17), UINT8_C( 27), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(167),
        UINT8_C( 73), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 33), UINT8_C(  0), UINT8_C(130),
        UINT8_C( 27), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(120), UINT8_C(161), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(136), UINT8_C( 69), UINT8_C(176), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(102), UINT8_C(  0), UINT8_C( 17), UINT8_C(  0), UINT8_C(135), UINT8_C(  0), UINT8_C(  0), UINT8_C( 37),
        UINT8_C(  0), UINT8_C( 79), UINT8_C(191), UINT8_C( 79), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 20), UINT8_C( 48), UINT8_C(  0), UINT8_C(113), UINT8_C(  0), UINT8_C(161),
        UINT8_C(  0), UINT8_C(224), UINT8_C(  0), UINT8_C( 12), UINT8_C(  7), UINT8_C(  0), UINT8_C(172), UINT8_C(  0) } },
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(169), UINT8_C(112), UINT8_C(177), UINT8_C(149),
        UINT8_C(191), UINT8_C(114), UINT8_C( 92), UINT8_C( 78), UINT8_C(134), UINT8_C( 51), UINT8_C(122), UINT8_C(156),
        UINT8_C(158), UINT8_C( 97), UINT8_C(197), UINT8_C( 78), UINT8_C(228), UINT8_C(197), UINT8_C(149),    UINT8_MAX,
        UINT8_C( 40), UINT8_C( 39), UINT8_C(138), UINT8_C(246), UINT8_C(218), UINT8_C( 21), UINT8_C( 60), UINT8_C(200),
        UINT8_C(182), UINT8_C(218), UINT8_C(222), UINT8_C(120), UINT8_C(172), UINT8_C(236), UINT8_C(209), UINT8_C(100),
        UINT8_C( 52), UINT8_C(115), UINT8_C(113), UINT8_C(138), UINT8_C(203), UINT8_C(163), UINT8_C( 87), UINT8_C( 68),
        UINT8_C(130), UINT8_C(234), UINT8_C(212), UINT8_C(171), UINT8_C(205), UINT8_C(194), UINT8_C(202), UINT8_C(227),
        UINT8_C(162), UINT8_C(159), UINT8_C(116), UINT8_C(  6), UINT8_C(141), UINT8_C(105), UINT8_C(214), UINT8_C(113),
        UINT8_C( 89), UINT8_C(155), UINT8_C(120), UINT8_C(112), UINT8_C(117), UINT8_C(173), UINT8_C( 82), UINT8_C(243),
        UINT8_C(172), UINT8_C(139), UINT8_C(242), UINT8_C(111), UINT8_C(215), UINT8_C(153), UINT8_C(177), UINT8_C(205),
        UINT8_C(151), UINT8_C(204), UINT8_C(116), UINT8_C(128), UINT8_C( 34), UINT8_C(191), UINT8_C(152), UINT8_C( 63),
        UINT8_C( 55), UINT8_C( 45), UINT8_C( 44), UINT8_C( 73), UINT8_C(147), UINT8_C(187), UINT8_C(140), UINT8_C(156),
        UINT8_C(120), UINT8_C(111), UINT8_C(112), UINT8_C(180), UINT8_C(238), UINT8_C( 94), UINT8_C(159), UINT8_C(116),
        UINT8_C( 64), UINT8_C(245), UINT8_C(136), UINT8_C( 94), UINT8_C(163), UINT8_C(166), UINT8_C(207), UINT8_C( 68),
        UINT8_C(243), UINT8_C(111), UINT8_C( 99), UINT8_C( 13), UINT8_C(175), UINT8_C(238), UINT8_C(202), UINT8_C(145) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(130), UINT8_C(  6), UINT8_C(248), UINT8_C( 32),
        UINT8_C(102), UINT8_C(198), UINT8_C(212), UINT8_C(251), UINT8_C(166), UINT8_C(143), UINT8_C(129), UINT8_C(149),
        UINT8_C( 98), UINT8_C( 23), UINT8_C(201), UINT8_C(188), UINT8_C( 45), UINT8_C(170), UINT8_C(161), UINT8_C(234),
        UINT8_C( 37), UINT8_C( 47), UINT8_C(  9), UINT8_C(108), UINT8_C(230), UINT8_C(108), UINT8_C(118), UINT8_C(249),
        UINT8_C(145), UINT8_C(180), UINT8_C( 36), UINT8_C( 79), UINT8_C(224), UINT8_C(  5), UINT8_C(149), UINT8_C(167),
        UINT8_C( 43), UINT8_C(147), UINT8_C(131), UINT8_C(218), UINT8_C(120), UINT8_C(174), UINT8_C( 36), UINT8_C( 96),
        UINT8_C(125), UINT8_C(242), UINT8_C( 41), UINT8_C( 40), UINT8_C(210), UINT8_C( 52), UINT8_C(181), UINT8_C( 26),
        UINT8_C(193), UINT8_C( 25), UINT8_C(234), UINT8_C( 57), UINT8_C(237), UINT8_C(245), UINT8_C(128), UINT8_C( 63),
        UINT8_C(102), UINT8_C(227), UINT8_C(127), UINT8_C(125), UINT8_C( 67), UINT8_C(140), UINT8_C( 70), UINT8_C( 41),
        UINT8_C(230), UINT8_C(157), UINT8_C(218), UINT8_C(154), UINT8_C(249), UINT8_C(201), UINT8_C( 28), UINT8_C( 75),
        UINT8_C( 69), UINT8_C(160), UINT8_C(206), UINT8_C(161), UINT8_C( 81), UINT8_C(237), UINT8_C( 80), UINT8_C(107),
        UINT8_C(113), UINT8_C( 89), UINT8_C( 48), UINT8_C( 88), UINT8_C(  9), UINT8_C(130), UINT8_C( 84), UINT8_C(212),
        UINT8_C(154), UINT8_C(182), UINT8_C( 87), UINT8_C(171), UINT8_C( 55), UINT8_C(153), UINT8_C(140), UINT8_C(165),
        UINT8_C(112), UINT8_C(126), UINT8_C(198), UINT8_C(142), UINT8_C(253), UINT8_C(110), UINT8_C(216), UINT8_C(210),
        UINT8_C( 53), UINT8_C( 65), UINT8_C(185), UINT8_C( 41), UINT8_C( 98), UINT8_C( 16), UINT8_C( 86), UINT8_C(205) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(254), UINT8_C(  0), UINT8_C(254), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C( 39), UINT8_C(106), UINT8_C(  0), UINT8_C(117),
        UINT8_C( 89), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  7),
        UINT8_C( 60), UINT8_C( 74), UINT8_C(  0), UINT8_C(  0), UINT8_C(183), UINT8_C( 27), UINT8_C(  0), UINT8_C( 21),
        UINT8_C(  3), UINT8_C(  0), UINT8_C(129), UINT8_C(138), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C( 37), UINT8_C( 38), UINT8_C(186), UINT8_C( 41), UINT8_C(  0), UINT8_C(231), UINT8_C( 60), UINT8_C(  0),
        UINT8_C(  9), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 83), UINT8_C(  0), UINT8_C( 51), UINT8_C(  0),
        UINT8_C(  5), UINT8_C(  0), UINT8_C(171), UINT8_C(131), UINT8_C(  0), UINT8_C(142), UINT8_C( 21), UINT8_C(201),
        UINT8_C(  0), UINT8_C(134), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 86), UINT8_C( 50),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 50), UINT8_C( 33), UINT8_C( 12), UINT8_C(202),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 24), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(149), UINT8_C(130),
        UINT8_C( 82), UINT8_C( 44), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 72), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(138), UINT8_C( 57), UINT8_C( 56), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 25), UINT8_C(  9), UINT8_C(183), UINT8_C(  0), UINT8_C( 19), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(119), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 56), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(190), UINT8_C( 46), UINT8_C(  0), UINT8_C(  0), UINT8_C( 77), UINT8_C(222), UINT8_C(116), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vsub_VubVub_sat(a, b);

    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u8_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u8_random(1);
    simde_hvx_vector_t r = simde_Q6_Vub_vsub_VubVub_sat(a, b);

    simde_test_hvx_vector_u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VuhVuh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    uint16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    uint16_t r[SIMDE_HVX_VECTOR_I16_COUNT];
  } test_vec[] = {
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(65245), UINT16_C(65300), UINT16_C(61132), UINT16_C(36507),
        UINT16_C(63249), UINT16_C(  695), UINT16_C(    1), UINT16_C( 4884), UINT16_C( 4150), UINT16_C(29291), UINT16_C(42706), UINT16_C( 5801),
        UINT16_C(25776), UINT16_C( 6708), UINT16_C( 7151), UINT16_C(23289), UINT16_C( 5111), UINT16_C(39709), UINT16_C(44010), UINT16_C(36549),
        UINT16_C(46518), UINT16_C( 3759), UINT16_C(18231), UINT16_C(25242), UINT16_C(62776), UINT16_C( 7743), UINT16_C(31024), UINT16_C(29221),
        UINT16_C(22166), UINT16_C(34397), UINT16_C(23316), UINT16_C(64605), UINT16_C(24318), UINT16_C(13462), UINT16_C(29875), UINT16_C(60077),
        UINT16_C(56648), UINT16_C(47256), UINT16_C(62596), UINT16_C(60696), UINT16_C(20217), UINT16_C(63134), UINT16_C(61597), UINT16_C(64578),
        UINT16_C(53400), UINT16_C(37641), UINT16_C(52468), UINT16_C(41985), UINT16_C(26436), UINT16_C(50872), UINT16_C(16190), UINT16_C(14396) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(59790), UINT16_C(36761), UINT16_C(  460), UINT16_C(13770),
        UINT16_C(49551), UINT16_C(34192), UINT16_C(54745), UINT16_C(19221), UINT16_C(19781), UINT16_C(37107), UINT16_C(53871), UINT16_C( 7098),
        UINT16_C(35264), UINT16_C(58306), UINT16_C(55928), UINT16_C(41395), UINT16_C(58148), UINT16_C( 5671), UINT16_C(28753), UINT16_C(64510),
        UINT16_C(10057), UINT16_C( 8242), UINT16_C(60601), UINT16_C(46029), UINT16_C(20232), UINT16_C(   89), UINT16_C(45881), UINT16_C( 3388),
        UINT16_C(11457), UINT16_C(64524), UINT16_C(10477), UINT16_C(22238), UINT16_C( 7790), UINT16_C(44426), UINT16_C(14452), UINT16_C(45101),
        UINT16_C(40813), UINT16_C(36613), UINT16_C(59059), UINT16_C(10224), UINT16_C(38952), UINT16_C(65291), UINT16_C(39915), UINT16_C(20582),
        UINT16_C(62342), UINT16_C( 9717), UINT16_C(16783), UINT16_C(61950), UINT16_C(14597), UINT16_C(29727), UINT16_C(46621), UINT16_C(48182) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(65534), UINT16_C(    0), UINT16_C(65534), UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX, UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C( 5455), UINT16_C(28539), UINT16_C(60672), UINT16_C(22737),
        UINT16_C(13698), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(34038), UINT16_C(15257), UINT16_C(    0),
        UINT16_C(36461), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(42544), UINT16_C( 7654), UINT16_C(    0), UINT16_C(25833),
        UINT16_C(10709), UINT16_C(    0), UINT16_C(12839), UINT16_C(42367), UINT16_C(16528), UINT16_C(    0), UINT16_C(15423), UINT16_C(14976),
        UINT16_C(15835), UINT16_C(10643), UINT16_C( 3537), UINT16_C(50472), UINT16_C(    0), UINT16_C(    0), UINT16_C(21682), UINT16_C(43996),
        UINT16_C(    0), UINT16_C(27924), UINT16_C(35685), UINT16_C(    0), UINT16_C(11839), UINT16_C(21145), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(13648), UINT16_C(56030), UINT16_C(14201), UINT16_C(32231),
        UINT16_C( 5981), UINT16_C(30687), UINT16_C(37657), UINT16_C(60324), UINT16_C(52542), UINT16_C(52233), UINT16_C(62048), UINT16_C(63335),
        UINT16_C(28149), UINT16_C( 2360), UINT16_C(65494), UINT16_C(15067), UINT16_C(32664), UINT16_C(42830), UINT16_C(45695), UINT16_C(30420),
        UINT16_C(27234), UINT16_C(48944), UINT16_C( 6079), UINT16_C( 8688), UINT16_C(30700), UINT16_C(17534), UINT16_C(56343), UINT16_C( 4546),
        UINT16_C(23049), UINT16_C(64071), UINT16_C(12488), UINT16_C(25266), UINT16_C(32416), UINT16_C(29939), UINT16_C(65533), UINT16_C( 1727),
        UINT16_C(52653), UINT16_C(47978), UINT16_C(54335), UINT16_C(54813), UINT16_C(63891), UINT16_C(42609), UINT16_C(13737), UINT16_C(19597),
        UINT16_C(46242), UINT16_C(12797), UINT16_C(30288), UINT16_C(35631), UINT16_C(38841), UINT16_C(46908), UINT16_C(38425), UINT16_C(39280) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(49757), UINT16_C(17649), UINT16_C(52057), UINT16_C(23061),
        UINT16_C(51291), UINT16_C( 4922), UINT16_C(35435), UINT16_C(21275), UINT16_C(64383), UINT16_C(49671), UINT16_C(55054), UINT16_C(49977),
        UINT16_C(16778), UINT16_C(37489), UINT16_C(51274), UINT16_C(49066), UINT16_C(35396), UINT16_C(19495), UINT16_C(33582), UINT16_C(27175),
        UINT16_C(48902), UINT16_C(61878), UINT16_C(41105), UINT16_C(45834), UINT16_C(63962), UINT16_C(33389), UINT16_C(64833), UINT16_C(27870),
        UINT16_C(58288), UINT16_C(46652), UINT16_C(39014), UINT16_C(49309), UINT16_C(41469), UINT16_C(59049), UINT16_C(30710), UINT16_C(36287),
        UINT16_C(55287), UINT16_C(53509), UINT16_C(57810), UINT16_C(25617), UINT16_C(57480), UINT16_C(16050), UINT16_C(49696), UINT16_C(29497),
        UINT16_C(42997), UINT16_C(55137), UINT16_C(15160), UINT16_C(55204), UINT16_C(59392), UINT16_C( 3562), UINT16_C(59271), UINT16_C(25471) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(65534), UINT16_C(    0), UINT16_C(65534), UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX, UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(38381), UINT16_C(    0), UINT16_C( 9170),
        UINT16_C(    0), UINT16_C(25765), UINT16_C( 2222), UINT16_C(39049), UINT16_C(    0), UINT16_C( 2562), UINT16_C( 6994), UINT16_C(13358),
        UINT16_C(11371), UINT16_C(    0), UINT16_C(14220), UINT16_C(    0), UINT16_C(    0), UINT16_C(23335), UINT16_C(12113), UINT16_C( 3245),
        UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(17419), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(34823), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(29196), UINT16_C( 6411), UINT16_C(26559), UINT16_C(    0), UINT16_C(    0),
        UINT16_C( 3245), UINT16_C(    0), UINT16_C(15128), UINT16_C(    0), UINT16_C(    0), UINT16_C(43346), UINT16_C(    0), UINT16_C(13809) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuh_vsub_VuhVuh_sat(a, b);

    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u16_random(1);
    simde_hvx_vector_t r = simde_Q6_Vuh_vsub_VuhVuh_sat(a, b);

    simde_test_hvx_vector_u16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VuwVuw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[SIMDE_HVX_VECTOR_I32_COUNT];
    uint32_t b[SIMDE_HVX_VECTOR_I32_COUNT];
    uint32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
  } test_vec[] = {
    { { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1), UINT32_C(3172268374), UINT32_C(1627625110), UINT32_C(4275383159), UINT32_C(2504384338),
        UINT32_C(1931324760), UINT32_C(2219640440), UINT32_C(3371328676), UINT32_C(3768812780), UINT32_C(2615446932), UINT32_C(2802887686), UINT32_C(1494430540), UINT32_C( 972567619),
        UINT32_C( 442726227), UINT32_C(1416287252), UINT32_C(2495593778), UINT32_C( 500738386), UINT32_C(1915823399), UINT32_C(3508044998), UINT32_C(3868464602), UINT32_C( 107648765) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),
        UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(4237841358), UINT32_C(3883725302), UINT32_C(2852721119), UINT32_C( 267036191),
        UINT32_C(3070951833), UINT32_C(3306909113), UINT32_C(2582139389), UINT32_C( 118834956), UINT32_C(1259071027), UINT32_C(3811302246), UINT32_C( 388260529), UINT32_C(1470148361),
        UINT32_C(2522917868), UINT32_C(1022761897), UINT32_C(3902016408), UINT32_C(2060040453), UINT32_C(2420657275), UINT32_C( 200699127), UINT32_C(2888864418), UINT32_C(3265623630) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(4294967294), UINT32_C(         0), UINT32_C(4294967294), UINT32_C(         0), UINT32_C(         0),
                  UINT32_MAX, UINT32_C(         1), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1422662040), UINT32_C(2237348147),
        UINT32_C(         0), UINT32_C(         0), UINT32_C( 789189287), UINT32_C(3649977824), UINT32_C(1356375905), UINT32_C(         0), UINT32_C(1106170011), UINT32_C(         0),
        UINT32_C(         0), UINT32_C( 393525355), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(3307345871), UINT32_C( 979600184), UINT32_C(         0) } },
    { { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1), UINT32_C(4181643526), UINT32_C(2924906022), UINT32_C( 822112647), UINT32_C(1145216262),
        UINT32_C(3849833768), UINT32_C(3171131543), UINT32_C(3996540018), UINT32_C(1327726931), UINT32_C(2605007527), UINT32_C(3619340225), UINT32_C(1633674672), UINT32_C(2287946151),
        UINT32_C(4213421831), UINT32_C(3383741236), UINT32_C(4081010849), UINT32_C(2371364536), UINT32_C(4115857875), UINT32_C(2874618693), UINT32_C(3158660115), UINT32_C( 806436745) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),
        UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(2501622191), UINT32_C(2826971488), UINT32_C(1854408407), UINT32_C(4125454777),
        UINT32_C(3701828482), UINT32_C(3435335765), UINT32_C( 970140017), UINT32_C(4239184688), UINT32_C(2583411625), UINT32_C(2050561233), UINT32_C(1825896232), UINT32_C(3276294077),
        UINT32_C(3039110410), UINT32_C(3200228694), UINT32_C(3772381458), UINT32_C( 817859498), UINT32_C(2630480305), UINT32_C(1895973034), UINT32_C(1793514053), UINT32_C(1006473982) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(4294967294), UINT32_C(         0), UINT32_C(4294967294), UINT32_C(         0), UINT32_C(         0),
                  UINT32_MAX, UINT32_C(         1), UINT32_C(         0), UINT32_C(         0), UINT32_C(1680021335), UINT32_C(  97934534), UINT32_C(         0), UINT32_C(         0),
        UINT32_C( 148005286), UINT32_C(         0), UINT32_C(3026400001), UINT32_C(         0), UINT32_C(  21595902), UINT32_C(1568778992), UINT32_C(         0), UINT32_C(         0),
        UINT32_C(1174311421), UINT32_C( 183512542), UINT32_C( 308629391), UINT32_C(1553505038), UINT32_C(1485377570), UINT32_C( 978645659), UINT32_C(1365146062), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuw_vsub_VuwVuw_sat(a, b);

    simde_test_hvx_vector_u32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u32_random(1);
    simde_hvx_vector_t r = simde_Q6_Vuw_vsub_VuwVuw_sat(a, b);

    simde_test_hvx_vector_u32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_WbWb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[SIMDE_HVX_PAIR_SIZE];
    int8_t b[SIMDE_HVX_PAIR_SIZE];
    int8_t r[SIMDE_HVX_PAIR_SIZE];
  } test_vec[] = {
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),  INT8_C( 119),  INT8_C( 102), -INT8_C(  37),  INT8_C(  89),
         INT8_C( 126),      INT8_MIN,  INT8_C( 115),  INT8_C( 121),  INT8_C(  54), -INT8_C(  12), -INT8_C(  74), -INT8_C(  38),
        -INT8_C( 103), -INT8_C(  72), -INT8_C(  88), -INT8_C(  13),  INT8_C(  90),  INT8_C(  17),  INT8_C(  54),  INT8_C( 102),
        -INT8_C( 116),  INT8_C(  20), -INT8_C(  32), -INT8_C( 122), -INT8_C(  40), -INT8_C(  34), -INT8_C(  18),  INT8_C(  52),
         INT8_C( 116),  INT8_C(  38), -INT8_C(  29), -INT8_C(  70), -INT8_C(  89),  INT8_C(  12), -INT8_C( 106),  INT8_C( 121),
         INT8_C(  25),  INT8_C(  28),  INT8_C(  12), -INT8_C(  29),  INT8_C(  93), -INT8_C(  44), -INT8_C( 104),  INT8_C(  94),
        -INT8_C( 104),  INT8_C(  15), -INT8_C(   6),  INT8_C(  48),  INT8_C(  36), -INT8_C(  76), -INT8_C(  38),  INT8_C(  60),
         INT8_C(  67),  INT8_C( 121),  INT8_C(  37),  INT8_C(  47),  INT8_C(  50), -INT8_C(  46),  INT8_C(  70),  INT8_C(  98),
         INT8_C(  69),  INT8_C(  98), -INT8_C(  60),  INT8_C(  94), -INT8_C(  48),  INT8_C(  67),  INT8_C( 123),  INT8_C(  43),
        -INT8_C( 112),  INT8_C(  48),  INT8_C(  93), -INT8_C( 119), -INT8_C(  52), -INT8_C(  67), -INT8_C(  48),  INT8_C(  90),
         INT8_C(  90),  INT8_C(  92),  INT8_C(  33),  INT8_C( 102),  INT8_C(  41), -INT8_C(  44), -INT8_C(  35),  INT8_C(  87),
         INT8_C( 119), -INT8_C(  57),  INT8_C(  42), -INT8_C(  28), -INT8_C(  81), -INT8_C(  14),  INT8_C( 123), -INT8_C(  12),
        -INT8_C( 114), -INT8_C(  88), -INT8_C( 119),  INT8_C(  84), -INT8_C(  39), -INT8_C(  24),  INT8_C(  37),  INT8_C(  21),
         INT8_C(  50), -INT8_C( 117), -INT8_C(  15), -INT8_C(  74), -INT8_C( 100),  INT8_C(  33),  INT8_C( 107), -INT8_C(  80),
        -INT8_C(  82),  INT8_C(  40), -INT8_C(  75),  INT8_C(   0),  INT8_C(  58), -INT8_C(  13),  INT8_C(  39),  INT8_C(  40),
         INT8_C(  67),  INT8_C(  56), -INT8_C( 100),  INT8_C( 116),  INT8_C(  84), -INT8_C(  15), -INT8_C(  29),  INT8_C(  83),
         INT8_C(  89), -INT8_C(  31),  INT8_C(   6), -INT8_C( 112),  INT8_C(  61),  INT8_C( 112), -INT8_C(  35), -INT8_C(  35),
         INT8_C(  66), -INT8_C( 116), -INT8_C(  89),  INT8_C( 115),  INT8_C( 123), -INT8_C(  31), -INT8_C(  40),  INT8_C(  21),
        -INT8_C(  76), -INT8_C( 112),  INT8_C(  17),  INT8_C(  10),  INT8_C(  47), -INT8_C(   9), -INT8_C(  19), -INT8_C(  90),
         INT8_C(  96),  INT8_C(  59),  INT8_C(  17), -INT8_C( 113),  INT8_C(  31), -INT8_C(  12),  INT8_C(  72), -INT8_C(   5),
        -INT8_C(  97),  INT8_C(  98), -INT8_C(  38),  INT8_C( 123), -INT8_C(  42), -INT8_C(  34), -INT8_C(  67), -INT8_C( 101),
         INT8_C(  48), -INT8_C(  52), -INT8_C(  64),  INT8_C(  49),  INT8_C(  81), -INT8_C(  89), -INT8_C(  21), -INT8_C(  17),
        -INT8_C(  18),  INT8_C(  83),  INT8_C(  65),  INT8_C(  58),  INT8_C( 115), -INT8_C(  34), -INT8_C( 108), -INT8_C( 123),
         INT8_C(  36), -INT8_C(  36), -INT8_C(  41),  INT8_C(  42),  INT8_C( 108), -INT8_C(  92), -INT8_C(  90),  INT8_C(  12),
         INT8_C(  23), -INT8_C(  75),  INT8_C(  26), -INT8_C(  72),  INT8_C(  31),  INT8_C(  62),  INT8_C(  77), -INT8_C(  53),
         INT8_C(  81),  INT8_C(  70),  INT8_C( 110), -INT8_C(  29),  INT8_C( 104), -INT8_C(  60),  INT8_C(  88), -INT8_C(  99),
        -INT8_C(  31),  INT8_C(  90),  INT8_C( 114),  INT8_C( 113),  INT8_C(   6),  INT8_C(   2),  INT8_C(  15), -INT8_C(  25),
        -INT8_C(  17), -INT8_C(  78),  INT8_C(  70),  INT8_C(  99), -INT8_C(  37), -INT8_C(  49),  INT8_C( 106),  INT8_C(  90),
        -INT8_C( 108), -INT8_C(  26), -INT8_C( 122),  INT8_C( 103), -INT8_C(   1), -INT8_C(  92), -INT8_C(  96), -INT8_C(  63),
         INT8_C(  18),  INT8_C(   7), -INT8_C(  32), -INT8_C(  88),  INT8_C(  16), -INT8_C( 120), -INT8_C(  75),  INT8_C(  81),
         INT8_C(  35), -INT8_C(  58), -INT8_C(  31), -INT8_C(  67),  INT8_C(   7), -INT8_C(  50), -INT8_C(  70), -INT8_C( 114) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  16), -INT8_C(  94), -INT8_C(   9), -INT8_C( 100),
        -INT8_C(  75),  INT8_C(  87), -INT8_C(  40), -INT8_C(  23), -INT8_C(  53),  INT8_C(  30), -INT8_C(   9),  INT8_C(  94),
        -INT8_C(  10),  INT8_C( 120),  INT8_C(  73), -INT8_C(  33), -INT8_C(  70), -INT8_C(   4), -INT8_C(  63), -INT8_C( 108),
        -INT8_C(  69),  INT8_C(  17), -INT8_C(   1), -INT8_C(  74), -INT8_C(  25), -INT8_C( 108),  INT8_C(   8), -INT8_C( 110),
        -INT8_C(  24), -INT8_C(  41), -INT8_C(  67),  INT8_C(  20),  INT8_C(  98),  INT8_C(  71), -INT8_C(  35), -INT8_C(  72),
        -INT8_C( 127),  INT8_C( 100), -INT8_C(  76), -INT8_C(   1), -INT8_C(  14), -INT8_C(  24),  INT8_C( 113),  INT8_C(  16),
         INT8_C(  94),  INT8_C(  30), -INT8_C(  46),  INT8_C(  72),  INT8_C(  16),  INT8_C(  78), -INT8_C(   8), -INT8_C( 107),
        -INT8_C(   5), -INT8_C(  65), -INT8_C(  23), -INT8_C(  51),  INT8_C(  61), -INT8_C(  24),  INT8_C(  42),  INT8_C( 103),
        -INT8_C(  18), -INT8_C(  41), -INT8_C(  10),  INT8_C(  27), -INT8_C(  58), -INT8_C( 104), -INT8_C(  57), -INT8_C(  92),
             INT8_MAX,  INT8_C( 105), -INT8_C(   4),  INT8_C(  87), -INT8_C(  40),  INT8_C(  88),  INT8_C(  85), -INT8_C(   4),
        -INT8_C(  71), -INT8_C(  64), -INT8_C( 127), -INT8_C(  91), -INT8_C(  84), -INT8_C(  55),  INT8_C(  59),  INT8_C( 108),
         INT8_C(  47),  INT8_C(  66), -INT8_C(  40), -INT8_C(  67),  INT8_C( 118), -INT8_C(  31),  INT8_C(  62), -INT8_C(  10),
        -INT8_C( 124),  INT8_C(  74),  INT8_C(  19), -INT8_C(  88), -INT8_C( 106), -INT8_C( 118),  INT8_C(  52), -INT8_C( 111),
        -INT8_C(  83),  INT8_C(  99),  INT8_C( 122),  INT8_C(  16),  INT8_C( 121),  INT8_C(  77), -INT8_C(  79), -INT8_C(  44),
        -INT8_C(  42), -INT8_C(  60),  INT8_C(  40), -INT8_C(  39),  INT8_C( 109),  INT8_C( 116),  INT8_C(  81),  INT8_C(  95),
             INT8_MAX,  INT8_C(  43),  INT8_C( 111),  INT8_C(  55), -INT8_C( 107), -INT8_C( 117),  INT8_C(  24),  INT8_C(  71),
        -INT8_C( 112), -INT8_C(  91),  INT8_C(  91), -INT8_C(  73), -INT8_C(  10), -INT8_C( 126),  INT8_C(  72),  INT8_C(  71),
        -INT8_C(  70),  INT8_C(  48), -INT8_C(  68),  INT8_C(  36), -INT8_C( 104), -INT8_C(  18), -INT8_C(  18), -INT8_C(  72),
        -INT8_C( 119), -INT8_C( 127), -INT8_C(  47), -INT8_C( 123),  INT8_C( 114), -INT8_C( 116),  INT8_C(  72), -INT8_C(  44),
         INT8_C( 105), -INT8_C( 108), -INT8_C(  79), -INT8_C(  27), -INT8_C(  53),  INT8_C(  60), -INT8_C(   8),  INT8_C(   9),
        -INT8_C(  99),  INT8_C(  33),  INT8_C(  89), -INT8_C(  48), -INT8_C(  95),  INT8_C(  72), -INT8_C(  15), -INT8_C( 104),
         INT8_C(  52),  INT8_C(  67),  INT8_C(  47),  INT8_C(   6),  INT8_C( 111),  INT8_C(   2), -INT8_C(  46),  INT8_C(  12),
        -INT8_C(  57),  INT8_C(  68), -INT8_C(  78),  INT8_C(  12), -INT8_C(  94),  INT8_C(  71),  INT8_C(  84), -INT8_C( 121),
        -INT8_C(  65), -INT8_C( 109), -INT8_C(  43), -INT8_C(  51), -INT8_C(  32), -INT8_C(  89),  INT8_C(  71),  INT8_C(  41),
        -INT8_C(  81), -INT8_C( 123), -INT8_C( 120), -INT8_C(  51),  INT8_C(  46), -INT8_C( 120), -INT8_C( 126),  INT8_C(  83),
         INT8_C(  74), -INT8_C(  52), -INT8_C(  90), -INT8_C(  55), -INT8_C(  50), -INT8_C(  50), -INT8_C(   6), -INT8_C(  56),
         INT8_C(  58), -INT8_C(  31), -INT8_C( 105),  INT8_C(  17), -INT8_C(  76),  INT8_C(   7),  INT8_C(  46),  INT8_C(  54),
         INT8_C(  22),  INT8_C(  27), -INT8_C( 111),  INT8_C(  55),  INT8_C(  25),  INT8_C( 121), -INT8_C(  40), -INT8_C(  30),
        -INT8_C( 103),  INT8_C( 112), -INT8_C( 125),  INT8_C(  30), -INT8_C(  44), -INT8_C(  50), -INT8_C(  46), -INT8_C(  73),
        -INT8_C(   5),  INT8_C(  96),  INT8_C( 109), -INT8_C(  64), -INT8_C(  57),  INT8_C( 113), -INT8_C(  35),  INT8_C(  80),
         INT8_C(  86), -INT8_C(  73), -INT8_C(  42),  INT8_C( 126), -INT8_C(  75),  INT8_C(  27), -INT8_C(  13), -INT8_C(  35) },
      {  INT8_C(   0),  INT8_C(   1),      INT8_MAX,  INT8_C( 126), -INT8_C( 127),  INT8_C( 126), -INT8_C( 127),  INT8_C(   0),
             INT8_MAX, -INT8_C( 127),  INT8_C(   0), -INT8_C( 126),  INT8_C( 103), -INT8_C(  60), -INT8_C(  28), -INT8_C(  67),
        -INT8_C(  55),  INT8_C(  41), -INT8_C( 101), -INT8_C( 112),  INT8_C( 107), -INT8_C(  42), -INT8_C(  65),  INT8_C( 124),
        -INT8_C(  93),  INT8_C(  64),  INT8_C(  95),  INT8_C(  20), -INT8_C(  96),  INT8_C(  21),  INT8_C( 117), -INT8_C(  46),
        -INT8_C(  47),  INT8_C(   3), -INT8_C(  31), -INT8_C(  48), -INT8_C(  15),  INT8_C(  74), -INT8_C(  26), -INT8_C(  94),
        -INT8_C( 116),  INT8_C(  79),  INT8_C(  38), -INT8_C(  90),  INT8_C(  69), -INT8_C(  59), -INT8_C(  71), -INT8_C(  63),
        -INT8_C( 104), -INT8_C(  72),  INT8_C(  88), -INT8_C(  28),  INT8_C( 107), -INT8_C(  20),  INT8_C(  39),  INT8_C(  78),
         INT8_C(  58), -INT8_C(  15),  INT8_C(  40), -INT8_C(  24),  INT8_C(  20),  INT8_C( 102), -INT8_C(  30), -INT8_C(  89),
         INT8_C(  72), -INT8_C(  70),  INT8_C(  60),  INT8_C(  98), -INT8_C(  11), -INT8_C(  22),  INT8_C(  28), -INT8_C(   5),
         INT8_C(  87), -INT8_C( 117), -INT8_C(  50),  INT8_C(  67),  INT8_C(  10), -INT8_C(  85), -INT8_C(  76), -INT8_C( 121),
         INT8_C(  17), -INT8_C(  57),  INT8_C(  97),  INT8_C(  50), -INT8_C(  12),  INT8_C( 101),  INT8_C( 123),  INT8_C(  94),
        -INT8_C(  95), -INT8_C( 100), -INT8_C(  96), -INT8_C(  63),  INT8_C( 125),  INT8_C(  11), -INT8_C(  94), -INT8_C(  21),
         INT8_C(  72), -INT8_C( 123),  INT8_C(  82),  INT8_C(  39),  INT8_C(  57),  INT8_C(  17),  INT8_C(  61), -INT8_C(   2),
         INT8_C(  10),  INT8_C(  94),  INT8_C( 118), -INT8_C(  84),  INT8_C(  67),  INT8_C(  94), -INT8_C(  15), -INT8_C( 124),
        -INT8_C( 123),  INT8_C(  40),  INT8_C( 119), -INT8_C(  90),  INT8_C(  35), -INT8_C(  44), -INT8_C(  70), -INT8_C(  36),
        -INT8_C(  40),  INT8_C( 100), -INT8_C( 115),  INT8_C(  39), -INT8_C(  51),      INT8_MAX, -INT8_C(  42), -INT8_C(  55),
        -INT8_C(  60),  INT8_C(  13),  INT8_C(  45),  INT8_C(  61), -INT8_C(  65),  INT8_C( 102), -INT8_C(  53),  INT8_C(  12),
        -INT8_C(  55),  INT8_C(  60), -INT8_C(  85), -INT8_C(  39),  INT8_C(  71), -INT8_C(  18), -INT8_C( 107), -INT8_C( 106),
        -INT8_C( 120),  INT8_C(  92), -INT8_C(  21),  INT8_C(  79), -INT8_C(  29), -INT8_C(  13), -INT8_C(  22),  INT8_C(  93),
         INT8_C(  43),  INT8_C(  15),  INT8_C(  64), -INT8_C( 123), -INT8_C(  67),  INT8_C( 107), -INT8_C(  91), -INT8_C(  46),
        -INT8_C(   9), -INT8_C(  89),  INT8_C(  96), -INT8_C(  86),  INT8_C(  84), -INT8_C(  72),  INT8_C(  80), -INT8_C(  14),
         INT8_C(   2),  INT8_C(  65), -INT8_C( 127), -INT8_C(  85),  INT8_C(  53), -INT8_C( 106), -INT8_C(  52),  INT8_C(   3),
        -INT8_C(   4), -INT8_C( 119), -INT8_C( 111),  INT8_C(  43), -INT8_C(  30), -INT8_C(  91),  INT8_C(  25), -INT8_C(  29),
         INT8_C(  39),  INT8_C(  15), -INT8_C( 113),  INT8_C(  46), -INT8_C(  47), -INT8_C( 105),  INT8_C(  64), -INT8_C(   2),
         INT8_C( 101),  INT8_C(  73),  INT8_C(   2),  INT8_C(  93), -INT8_C( 116), -INT8_C(   3),  INT8_C(  95), -INT8_C(  29),
         INT8_C( 104),  INT8_C(  48), -INT8_C( 110), -INT8_C(  21), -INT8_C(  15), -INT8_C(  74), -INT8_C(  53),  INT8_C( 120),
         INT8_C(   7),  INT8_C( 122), -INT8_C(  56),  INT8_C(  26), -INT8_C( 102), -INT8_C(  10),  INT8_C(  94), -INT8_C(  43),
        -INT8_C(  89),  INT8_C( 121), -INT8_C(  37),  INT8_C(  96),  INT8_C(  82), -INT8_C(   5), -INT8_C(  31), -INT8_C(  79),
        -INT8_C(  39), -INT8_C( 105), -INT8_C(  75),  INT8_C(  44), -INT8_C(  62),  INT8_C(  86), -INT8_C( 110),  INT8_C( 120),
        -INT8_C(   5),  INT8_C( 118),  INT8_C(   3),  INT8_C(  73),  INT8_C(  43), -INT8_C(  42), -INT8_C(  50),  INT8_C(  10),
         INT8_C(  23), -INT8_C(  89),  INT8_C( 115), -INT8_C(  24),  INT8_C(  73),  INT8_C(  23), -INT8_C(  40),  INT8_C(   1),
        -INT8_C(  51),  INT8_C(  15),  INT8_C(  11),  INT8_C(  63),  INT8_C(  82), -INT8_C(  77), -INT8_C(  57), -INT8_C(  79) } },
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1), -INT8_C(  73), -INT8_C(   5), -INT8_C(  34),  INT8_C( 102),
        -INT8_C(  48),  INT8_C(  42), -INT8_C(  41), -INT8_C(  92), -INT8_C(  45), -INT8_C(  71),  INT8_C(  73), -INT8_C(  65),
        -INT8_C(  11),  INT8_C(  65), -INT8_C(  71),  INT8_C(   7),  INT8_C(  14), -INT8_C(   8), -INT8_C( 123),  INT8_C(  98),
         INT8_C(  87),  INT8_C(  12),      INT8_MAX, -INT8_C(  71),  INT8_C(  99),  INT8_C(  19),  INT8_C(  16), -INT8_C( 122),
        -INT8_C(  22), -INT8_C(  35), -INT8_C( 123),  INT8_C( 110), -INT8_C(  85),  INT8_C(  69), -INT8_C(  30), -INT8_C(  42),
         INT8_C(  18), -INT8_C( 111),  INT8_C(  75),  INT8_C(  50),  INT8_C( 122), -INT8_C( 121),  INT8_C( 101), -INT8_C(  62),
         INT8_C( 106),  INT8_C(  29),  INT8_C( 115),  INT8_C(  43),  INT8_C(  15), -INT8_C(  12),  INT8_C( 104), -INT8_C(  55),
        -INT8_C( 127),  INT8_C(  14),  INT8_C( 103), -INT8_C( 104), -INT8_C( 115), -INT8_C( 113), -INT8_C(  94),  INT8_C(  30),
         INT8_C(  29),  INT8_C( 126),  INT8_C(  10), -INT8_C( 116),  INT8_C( 122), -INT8_C(  80),  INT8_C(   1),  INT8_C(  74),
        -INT8_C( 125),  INT8_C( 101), -INT8_C(  42),  INT8_C(  85),  INT8_C( 122), -INT8_C(  94),  INT8_C(  41), -INT8_C(  25),
         INT8_C(  27), -INT8_C( 104), -INT8_C( 119), -INT8_C(  72), -INT8_C(  14),      INT8_MAX,  INT8_C(  33), -INT8_C(  20),
        -INT8_C(  98),  INT8_C(  35),  INT8_C( 108), -INT8_C(  53),  INT8_C(  91), -INT8_C( 112),  INT8_C(  71),  INT8_C(  79),
        -INT8_C(  17), -INT8_C(   4),  INT8_C(  52),  INT8_C(  66), -INT8_C(  81),  INT8_C(   8),  INT8_C(  92),  INT8_C(  60),
        -INT8_C( 110), -INT8_C( 119),  INT8_C(  58), -INT8_C(  63),  INT8_C( 106),  INT8_C(  22),  INT8_C( 102),  INT8_C( 111),
        -INT8_C( 109), -INT8_C(  68), -INT8_C(  61), -INT8_C(  49),  INT8_C(  97), -INT8_C(  30),  INT8_C(  21), -INT8_C(  90),
        -INT8_C(  96), -INT8_C(  15), -INT8_C(  24), -INT8_C(  92), -INT8_C( 117),  INT8_C(  64),  INT8_C(  17),  INT8_C( 122),
        -INT8_C(  28),  INT8_C(  25), -INT8_C( 126),  INT8_C(  82), -INT8_C(  40),  INT8_C(  97), -INT8_C(  77),  INT8_C(  87),
         INT8_C(  21),  INT8_C(  33),  INT8_C( 122),  INT8_C(  31), -INT8_C(  22),  INT8_C(  14),  INT8_C(  64), -INT8_C(  92),
         INT8_C(  32), -INT8_C(  41), -INT8_C(  98),  INT8_C( 100), -INT8_C( 125),  INT8_C( 118), -INT8_C(  23), -INT8_C( 114),
        -INT8_C( 114),  INT8_C(   2),  INT8_C(  12), -INT8_C( 120),  INT8_C(  68), -INT8_C(  30),  INT8_C( 118),  INT8_C(  69),
        -INT8_C(  41), -INT8_C(  77),  INT8_C(  40),  INT8_C(  37),  INT8_C(  83),  INT8_C(  11), -INT8_C( 121), -INT8_C(  24),
             INT8_MAX,  INT8_C(  57), -INT8_C(  20), -INT8_C(  88),  INT8_C(  65),  INT8_C(  48),  INT8_C(  44), -INT8_C(  85),
        -INT8_C(  28), -INT8_C( 122),  INT8_C(  55),  INT8_C(  68),  INT8_C( 124),  INT8_C( 100),  INT8_C(  97),  INT8_C(  36),
         INT8_C( 116),  INT8_C(  46), -INT8_C(  76),  INT8_C(  79),  INT8_C( 120), -INT8_C(  12),  INT8_C(  10),  INT8_C(  40),
        -INT8_C(  40), -INT8_C( 117), -INT8_C(  57), -INT8_C( 116), -INT8_C( 113),  INT8_C(  18), -INT8_C(  73), -INT8_C(  46),
        -INT8_C( 108), -INT8_C(  14), -INT8_C(  58),  INT8_C(  75), -INT8_C( 121),  INT8_C( 117),  INT8_C( 113), -INT8_C(  44),
         INT8_C( 112),  INT8_C(  69), -INT8_C(  69), -INT8_C( 105),  INT8_C( 121), -INT8_C(  38), -INT8_C(  67), -INT8_C( 120),
        -INT8_C(  34), -INT8_C( 117), -INT8_C(  74),  INT8_C(  40), -INT8_C(  48), -INT8_C(  60), -INT8_C(  56), -INT8_C( 124),
         INT8_C( 126), -INT8_C( 106), -INT8_C( 106),  INT8_C(   7), -INT8_C(  40),  INT8_C(  54), -INT8_C(  99), -INT8_C(   3),
        -INT8_C(  90),  INT8_C(  45),  INT8_C(  45),  INT8_C(  82),  INT8_C(  79), -INT8_C( 119),  INT8_C(  40),  INT8_C( 116),
        -INT8_C(  40),  INT8_C( 116),  INT8_C(  89), -INT8_C(  28),  INT8_C(  54), -INT8_C(  54), -INT8_C( 102), -INT8_C(  87) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C( 102),  INT8_C( 106), -INT8_C(  79),  INT8_C(  78),
         INT8_C(  70), -INT8_C(  75), -INT8_C(  57), -INT8_C( 126), -INT8_C(  55), -INT8_C(  95), -INT8_C(  72),  INT8_C(  47),
         INT8_C(  77), -INT8_C(  28), -INT8_C(  85), -INT8_C( 112),  INT8_C(   1),  INT8_C(  36),  INT8_C(  82), -INT8_C(   2),
         INT8_C(  54),  INT8_C(  72),  INT8_C(  73),  INT8_C(  93),  INT8_C(   2),  INT8_C(  28),  INT8_C( 125), -INT8_C( 105),
         INT8_C(  77),  INT8_C(  77),  INT8_C(  55), -INT8_C(  95),  INT8_C(  43), -INT8_C(  54), -INT8_C(  91),  INT8_C(  23),
             INT8_MAX, -INT8_C(  19), -INT8_C(  57), -INT8_C(  64),  INT8_C( 110), -INT8_C(  39), -INT8_C(  39), -INT8_C(  46),
         INT8_C(  48), -INT8_C(  27), -INT8_C(  84), -INT8_C(  24),  INT8_C(  73), -INT8_C( 113), -INT8_C(  40), -INT8_C(  78),
        -INT8_C(  25),  INT8_C(  54),  INT8_C(  36), -INT8_C(  53), -INT8_C(  43), -INT8_C(  46), -INT8_C( 127),  INT8_C(  62),
         INT8_C(  97),  INT8_C( 120),  INT8_C(  24),  INT8_C( 119),  INT8_C(  15),  INT8_C(  26),  INT8_C(   4),  INT8_C(  11),
        -INT8_C( 117), -INT8_C(  10),  INT8_C( 124),  INT8_C(  51),  INT8_C(  35),  INT8_C(  14),  INT8_C(  14), -INT8_C(  92),
        -INT8_C(  83), -INT8_C(  51),  INT8_C(  33), -INT8_C(  99), -INT8_C( 101), -INT8_C(  86),  INT8_C(  23),  INT8_C(  91),
         INT8_C(  15), -INT8_C(  59),  INT8_C(   7), -INT8_C(  75),  INT8_C(  13),  INT8_C(  89), -INT8_C(  58), -INT8_C(  34),
         INT8_C(  29), -INT8_C(  19),  INT8_C(  36), -INT8_C(  45), -INT8_C(  62), -INT8_C(  67),  INT8_C(  83), -INT8_C(  80),
         INT8_C(  10),  INT8_C(  95),  INT8_C(  97), -INT8_C(  26), -INT8_C(  32),  INT8_C(  57), -INT8_C(  87),  INT8_C(  54),
        -INT8_C(  47),  INT8_C(   5), -INT8_C( 116), -INT8_C(  54),  INT8_C(  51), -INT8_C(  66), -INT8_C(  43),  INT8_C(  47),
         INT8_C(  49),  INT8_C( 114), -INT8_C(  61), -INT8_C(  48), -INT8_C(  29), -INT8_C(  77),  INT8_C(  90), -INT8_C(   8),
         INT8_C(  93),  INT8_C( 121), -INT8_C(  51),  INT8_C(   0), -INT8_C(   1),  INT8_C(  53), -INT8_C(  80),  INT8_C(  85),
        -INT8_C(  68),  INT8_C(  77), -INT8_C(  84), -INT8_C(  18), -INT8_C(  37),  INT8_C(  75),  INT8_C(  70), -INT8_C(  68),
         INT8_C(  30), -INT8_C( 110), -INT8_C( 103),  INT8_C( 120), -INT8_C(   5),  INT8_C(   2),  INT8_C(  15), -INT8_C(  80),
        -INT8_C( 107), -INT8_C(  11),  INT8_C( 120), -INT8_C(   7),  INT8_C(  49), -INT8_C(  42), -INT8_C(  89), -INT8_C(  26),
         INT8_C(  17),  INT8_C(  93), -INT8_C(  74),  INT8_C(   5), -INT8_C( 125),  INT8_C(  27), -INT8_C(  19), -INT8_C( 127),
        -INT8_C(  77),  INT8_C(  37),  INT8_C(  94),  INT8_C(  11),  INT8_C(  45), -INT8_C( 121), -INT8_C(  52), -INT8_C(  37),
        -INT8_C(  89),  INT8_C(  36),  INT8_C(  14), -INT8_C(  95),  INT8_C(  22),  INT8_C(  80), -INT8_C(  41), -INT8_C(  26),
         INT8_C(  70), -INT8_C(  82),  INT8_C( 104), -INT8_C( 102), -INT8_C(  41), -INT8_C(  56),  INT8_C(  51),  INT8_C( 109),
         INT8_C(  20),  INT8_C(  25),  INT8_C(  99),  INT8_C( 108),  INT8_C(  88), -INT8_C( 103),  INT8_C(  54), -INT8_C(  24),
         INT8_C(  14), -INT8_C(  68), -INT8_C(  50), -INT8_C(  55), -INT8_C(  11),  INT8_C(  90), -INT8_C(  19), -INT8_C(   4),
        -INT8_C(  94), -INT8_C(  99),  INT8_C(  57), -INT8_C(  80), -INT8_C(  24),  INT8_C(  98), -INT8_C(  76),  INT8_C(  15),
        -INT8_C( 124), -INT8_C( 115),  INT8_C(  70), -INT8_C( 115), -INT8_C(  95),  INT8_C(  56), -INT8_C(  39), -INT8_C(  48),
             INT8_MAX, -INT8_C(  75),  INT8_C( 104), -INT8_C( 124), -INT8_C( 100),  INT8_C( 103),  INT8_C(  39), -INT8_C(  33),
         INT8_C(  47), -INT8_C(   3), -INT8_C(  66),  INT8_C(  41),  INT8_C(   6), -INT8_C(  65),  INT8_C(  34),  INT8_C(  36),
        -INT8_C( 124),  INT8_C(  30), -INT8_C(  32), -INT8_C( 122), -INT8_C( 104), -INT8_C( 115), -INT8_C( 123), -INT8_C(  45) },
      {  INT8_C(   0),  INT8_C(   1),      INT8_MAX,  INT8_C( 126), -INT8_C( 127),  INT8_C( 126), -INT8_C( 127),  INT8_C(   0),
             INT8_MAX, -INT8_C( 127),  INT8_C(   0), -INT8_C( 126),  INT8_C(  29), -INT8_C( 111),  INT8_C(  45),  INT8_C(  24),
        -INT8_C( 118),  INT8_C( 117),  INT8_C(  16),  INT8_C(  34),  INT8_C(  10),  INT8_C(  24), -INT8_C( 111), -INT8_C( 112),
        -INT8_C(  88),  INT8_C(  93),  INT8_C(  14),  INT8_C( 119),  INT8_C(  13), -INT8_C(  44),  INT8_C(  51),  INT8_C( 100),
         INT8_C(  33), -INT8_C(  60),  INT8_C(  54),  INT8_C(  92),  INT8_C(  97), -INT8_C(   9), -INT8_C( 109), -INT8_C(  17),
        -INT8_C(  99), -INT8_C( 112),  INT8_C(  78), -INT8_C(  51),      INT8_MIN,  INT8_C( 123),  INT8_C(  61), -INT8_C(  65),
        -INT8_C( 109), -INT8_C(  92), -INT8_C( 124),  INT8_C( 114),  INT8_C(  12), -INT8_C(  82), -INT8_C( 116), -INT8_C(  16),
         INT8_C(  58),  INT8_C(  56), -INT8_C(  57),  INT8_C(  67), -INT8_C(  58),  INT8_C( 101), -INT8_C( 112),  INT8_C(  23),
        -INT8_C( 102), -INT8_C(  40),  INT8_C(  67), -INT8_C(  51), -INT8_C(  72), -INT8_C(  67),  INT8_C(  33), -INT8_C(  32),
        -INT8_C(  68),  INT8_C(   6), -INT8_C(  14),  INT8_C(  21),  INT8_C( 107), -INT8_C( 106), -INT8_C(   3),  INT8_C(  63),
        -INT8_C(   8),  INT8_C( 111),  INT8_C(  90),  INT8_C(  34),  INT8_C(  87), -INT8_C( 108),  INT8_C(  27),  INT8_C(  67),
         INT8_C( 110), -INT8_C(  53),  INT8_C( 104),  INT8_C(  27),  INT8_C(  87), -INT8_C(  43),  INT8_C(  10), -INT8_C( 111),
        -INT8_C( 113),  INT8_C(  94),  INT8_C( 101),  INT8_C(  22),  INT8_C(  78),  INT8_C(  55), -INT8_C( 127),  INT8_C( 113),
        -INT8_C(  46),  INT8_C(  15),  INT8_C(  16),  INT8_C( 111), -INT8_C(  19),  INT8_C(  75),  INT8_C(   9), -INT8_C( 116),
        -INT8_C( 120),  INT8_C(  42), -INT8_C(  39), -INT8_C(  37), -INT8_C( 118), -INT8_C(  35), -INT8_C(  67),  INT8_C(  57),
        -INT8_C(  62), -INT8_C(  73),  INT8_C(  55),  INT8_C(   5),  INT8_C(  46),  INT8_C(  36),  INT8_C(  64),  INT8_C( 119),
         INT8_C( 111),      INT8_MAX,  INT8_C(  37), -INT8_C(  44), -INT8_C(  88), -INT8_C( 115), -INT8_C(  73), -INT8_C( 126),
        -INT8_C( 121), -INT8_C(  96), -INT8_C(  75),  INT8_C(  82), -INT8_C(  39),  INT8_C(  44),  INT8_C(   3),  INT8_C(   2),
         INT8_C(  89), -INT8_C(  44), -INT8_C(  50),  INT8_C(  49),  INT8_C(  15), -INT8_C(  61), -INT8_C(   6), -INT8_C(  24),
         INT8_C(   2),  INT8_C(  69),  INT8_C(   5), -INT8_C(  20), -INT8_C( 120),  INT8_C( 116), -INT8_C(  38), -INT8_C(  34),
        -INT8_C(   7),  INT8_C(  13), -INT8_C( 108), -INT8_C( 113),  INT8_C(  19),  INT8_C(  12), -INT8_C(  49),  INT8_C(  95),
        -INT8_C(  58),  INT8_C(  86),  INT8_C( 114),  INT8_C(  32), -INT8_C(  48), -INT8_C(  16), -INT8_C( 102),  INT8_C( 103),
        -INT8_C(  52),  INT8_C(  20), -INT8_C( 114), -INT8_C(  99),  INT8_C(  20), -INT8_C(  87),  INT8_C(  96), -INT8_C(  48),
         INT8_C(  61),  INT8_C(  98),  INT8_C(  41), -INT8_C(  93),  INT8_C( 102),  INT8_C(  20), -INT8_C( 118),  INT8_C(  62),
         INT8_C(  46),      INT8_MIN,  INT8_C(  76), -INT8_C(  75), -INT8_C(  95),  INT8_C(  44), -INT8_C(  41), -INT8_C(  69),
        -INT8_C(  60),  INT8_C( 114),  INT8_C( 100),  INT8_C(  32),  INT8_C(  55),  INT8_C( 121), -INT8_C( 127), -INT8_C(  22),
        -INT8_C( 122),  INT8_C(  54), -INT8_C(   8), -INT8_C( 126), -INT8_C( 110),  INT8_C(  27), -INT8_C( 124), -INT8_C(  40),
        -INT8_C(  50), -INT8_C(  88), -INT8_C( 126), -INT8_C(  25), -INT8_C( 111),  INT8_C( 120),  INT8_C(   9),  INT8_C( 121),
         INT8_C(  90), -INT8_C(   2),  INT8_C( 112), -INT8_C( 101),  INT8_C(  47), -INT8_C( 116), -INT8_C(  17), -INT8_C(  76),
        -INT8_C(   1), -INT8_C(  31),  INT8_C(  46), -INT8_C( 125),  INT8_C(  60), -INT8_C(  49),  INT8_C( 118),  INT8_C(  30),
         INT8_C( 119),  INT8_C(  48),  INT8_C( 111),  INT8_C(  41),  INT8_C(  73), -INT8_C(  54),  INT8_C(   6),  INT8_C(  80),
         INT8_C(  84),  INT8_C(  86),  INT8_C( 121),  INT8_C(  94), -INT8_C(  98),  INT8_C(  61),  INT8_C(  21), -INT8_C(  42) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wb_vsub_WbWb(a, b);

    simde_test_hvx_vectorpair_i8_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i8_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i8_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wb_vsub_WbWb(a, b);

    simde_test_hvx_vectorpair_i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_WhWh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_PAIR_I16_COUNT];
    int16_t b[SIMDE_HVX_PAIR_I16_COUNT];
    int16_t r[SIMDE_HVX_PAIR_I16_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C( 28525), -INT16_C(   593), -INT16_C(   995), -INT16_C(  2599),
         INT16_C( 26637), -INT16_C( 11739), -INT16_C( 12448), -INT16_C( 20571), -INT16_C( 25401), -INT16_C(  6219), -INT16_C(  1431),  INT16_C(  7426),
         INT16_C(  8283),  INT16_C( 20223),  INT16_C( 25380), -INT16_C(   493), -INT16_C( 19456), -INT16_C(  4568),  INT16_C( 27330), -INT16_C( 30509),
         INT16_C( 25628),  INT16_C(   387),  INT16_C(  7596), -INT16_C(  9861),  INT16_C( 18220),  INT16_C(   284), -INT16_C( 14712),  INT16_C( 13961),
         INT16_C( 21350),  INT16_C(   608),  INT16_C( 28198),  INT16_C(  7590), -INT16_C( 22657), -INT16_C( 21230),  INT16_C( 24619), -INT16_C( 24441),
        -INT16_C(  7247), -INT16_C( 32087), -INT16_C(  3299), -INT16_C(  6967), -INT16_C( 22216),  INT16_C( 28153),  INT16_C( 25681), -INT16_C(  5455),
        -INT16_C( 23006), -INT16_C(  1028), -INT16_C( 10712),  INT16_C( 16502), -INT16_C(  3495),  INT16_C(  4454), -INT16_C(  5151), -INT16_C( 29992),
        -INT16_C(  2664),  INT16_C( 11420), -INT16_C(  5847),  INT16_C( 11869),  INT16_C( 24035), -INT16_C( 17295), -INT16_C( 31130), -INT16_C(  5711),
         INT16_C(   245),  INT16_C( 31484),  INT16_C(  4278),  INT16_C( 17242),  INT16_C(  4874), -INT16_C(  2110), -INT16_C(  8619),  INT16_C( 30683),
         INT16_C( 16930),  INT16_C(  5421),  INT16_C( 26652), -INT16_C( 31403), -INT16_C( 14609),  INT16_C( 22610), -INT16_C( 13400), -INT16_C( 19086),
        -INT16_C(  7595), -INT16_C( 31542), -INT16_C( 17030),  INT16_C(  2666), -INT16_C( 29870),  INT16_C( 17491), -INT16_C( 31641), -INT16_C( 19022),
         INT16_C( 28436), -INT16_C(  1596), -INT16_C( 16509), -INT16_C( 17437), -INT16_C(  7742),  INT16_C( 16838),  INT16_C( 15739), -INT16_C( 27352),
        -INT16_C( 28297),  INT16_C(  1442), -INT16_C( 32422), -INT16_C(  9599),  INT16_C( 25295),  INT16_C( 26184), -INT16_C(  7311),  INT16_C( 25326),
         INT16_C(  3365),  INT16_C(  7345), -INT16_C( 16883), -INT16_C( 18293), -INT16_C( 29768),  INT16_C( 22142),  INT16_C( 19598),  INT16_C(  1910),
        -INT16_C( 15728),  INT16_C( 29342),  INT16_C( 24874),  INT16_C(  9529),  INT16_C( 14868),  INT16_C( 23743),  INT16_C( 29897), -INT16_C( 25495) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C( 10690),  INT16_C( 13109),  INT16_C( 24011),  INT16_C( 13483),
         INT16_C( 28274), -INT16_C( 23110), -INT16_C( 21261),  INT16_C(  5314), -INT16_C( 24342), -INT16_C(  9541),  INT16_C( 22732), -INT16_C(  5190),
         INT16_C( 13338), -INT16_C(  8023),  INT16_C(  3026),  INT16_C( 25658),  INT16_C(  9486),  INT16_C(  3445),  INT16_C( 11616), -INT16_C(  7225),
         INT16_C( 10740),  INT16_C( 13512),  INT16_C( 16262),  INT16_C( 25379), -INT16_C( 12851), -INT16_C( 20494),  INT16_C(   970),  INT16_C( 31532),
         INT16_C(  4293),  INT16_C( 13268), -INT16_C(  2890), -INT16_C( 25230), -INT16_C( 13186), -INT16_C( 23547),  INT16_C(  5378), -INT16_C(    73),
        -INT16_C( 26736), -INT16_C( 26319),  INT16_C( 30461),  INT16_C(   322),  INT16_C(  8269), -INT16_C( 32598),  INT16_C(  6586),  INT16_C( 17642),
         INT16_C( 32452), -INT16_C(  8967),  INT16_C( 26993),  INT16_C(   939),  INT16_C( 14039),  INT16_C( 19480), -INT16_C( 21944), -INT16_C( 22463),
         INT16_C(  8481), -INT16_C( 29712),  INT16_C( 18378), -INT16_C(  6042), -INT16_C( 16578), -INT16_C(  6529),  INT16_C( 15338),  INT16_C(  6410),
        -INT16_C(  6168),  INT16_C(  2803),  INT16_C( 10150), -INT16_C(  9803),  INT16_C(  6474),  INT16_C( 29690),  INT16_C(  5609), -INT16_C( 32690),
         INT16_C(  7099),  INT16_C(  6980),  INT16_C( 18797),  INT16_C(  6950), -INT16_C(  3083),  INT16_C( 26923), -INT16_C( 12516),  INT16_C( 13892),
        -INT16_C( 22842), -INT16_C( 14249), -INT16_C(  5554),  INT16_C(  1946), -INT16_C( 31481), -INT16_C( 21757), -INT16_C( 10172), -INT16_C(  9007),
         INT16_C( 12961),  INT16_C(  6012), -INT16_C( 10784),  INT16_C( 14112), -INT16_C(  2782),  INT16_C( 16957),  INT16_C( 32717),  INT16_C( 13978),
         INT16_C( 13167),  INT16_C(  7939),  INT16_C( 19418),  INT16_C( 26397),  INT16_C( 27348),  INT16_C(  9730),  INT16_C(   870),  INT16_C( 30240),
         INT16_C( 21694), -INT16_C(  5049), -INT16_C( 25227), -INT16_C( 29890),  INT16_C( 13605), -INT16_C( 24768),  INT16_C( 12542), -INT16_C( 32400),
        -INT16_C( 12891), -INT16_C( 17877),  INT16_C(  7899), -INT16_C( 24901), -INT16_C( 21470), -INT16_C( 17108), -INT16_C(  3434), -INT16_C( 23080) },
      {  INT16_C(     0),  INT16_C(     1),        INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C(     0),
               INT16_MAX,       -INT16_MAX,  INT16_C(     0), -INT16_C( 32766), -INT16_C( 17835), -INT16_C( 13702), -INT16_C( 25006), -INT16_C( 16082),
        -INT16_C(  1637),  INT16_C( 11371),  INT16_C(  8813), -INT16_C( 25885), -INT16_C(  1059),  INT16_C(  3322), -INT16_C( 24163),  INT16_C( 12616),
        -INT16_C(  5055),  INT16_C( 28246),  INT16_C( 22354), -INT16_C( 26151), -INT16_C( 28942), -INT16_C(  8013),  INT16_C( 15714), -INT16_C( 23284),
         INT16_C( 14888), -INT16_C( 13125), -INT16_C(  8666),  INT16_C( 30296),  INT16_C( 31071),  INT16_C( 20778), -INT16_C( 15682), -INT16_C( 17571),
         INT16_C( 17057), -INT16_C( 12660),  INT16_C( 31088), -INT16_C( 32716), -INT16_C(  9471),  INT16_C(  2317),  INT16_C( 19241), -INT16_C( 24368),
         INT16_C( 19489), -INT16_C(  5768),  INT16_C( 31776), -INT16_C(  7289), -INT16_C( 30485), -INT16_C(  4785),  INT16_C( 19095), -INT16_C( 23097),
         INT16_C( 10078),  INT16_C(  7939),  INT16_C( 27831),  INT16_C( 15563), -INT16_C( 17534), -INT16_C( 15026),  INT16_C( 16793), -INT16_C(  7529),
        -INT16_C( 11145), -INT16_C( 24404), -INT16_C( 24225),  INT16_C( 17911), -INT16_C( 24923), -INT16_C( 10766),  INT16_C( 19068), -INT16_C( 12121),
         INT16_C(  6413),  INT16_C( 28681), -INT16_C(  5872),  INT16_C( 27045), -INT16_C(  1600), -INT16_C( 31800), -INT16_C( 14228), -INT16_C(  2163),
         INT16_C(  9831), -INT16_C(  1559),  INT16_C(  7855),  INT16_C( 27183), -INT16_C( 11526), -INT16_C(  4313), -INT16_C(   884),  INT16_C( 32558),
         INT16_C( 15247), -INT16_C( 17293), -INT16_C( 11476),  INT16_C(   720),  INT16_C(  1611), -INT16_C( 26288), -INT16_C( 21469), -INT16_C( 10015),
         INT16_C( 15475), -INT16_C(  7608), -INT16_C(  5725), -INT16_C( 31549), -INT16_C(  4960), -INT16_C(   119), -INT16_C( 16978),  INT16_C( 24206),
         INT16_C( 24072), -INT16_C(  6497),  INT16_C( 13696),  INT16_C( 29540), -INT16_C(  2053),  INT16_C( 16454), -INT16_C(  8181), -INT16_C(  4914),
        -INT16_C( 18329),  INT16_C( 12394),  INT16_C(  8344),  INT16_C( 11597),  INT16_C( 22163), -INT16_C( 18626),  INT16_C(  7056), -INT16_C( 31226),
        -INT16_C(  2837), -INT16_C( 18317),  INT16_C( 16975), -INT16_C( 31106), -INT16_C( 29198), -INT16_C( 24685), -INT16_C( 32205), -INT16_C(  2415) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C( 23132),  INT16_C( 29584), -INT16_C( 31147),  INT16_C(  1847),
        -INT16_C( 16423), -INT16_C( 14703), -INT16_C( 27372),  INT16_C( 28649), -INT16_C( 28628),  INT16_C( 29931), -INT16_C( 14435), -INT16_C(  7063),
        -INT16_C( 28657), -INT16_C(  9381),  INT16_C(  6543), -INT16_C( 32175),  INT16_C( 13164),  INT16_C( 29952), -INT16_C(  7703), -INT16_C( 16385),
         INT16_C( 29214), -INT16_C( 16616),  INT16_C( 25015), -INT16_C( 19730),  INT16_C( 19573),  INT16_C( 26707), -INT16_C( 32616), -INT16_C(  6042),
         INT16_C(  8757), -INT16_C( 27126),  INT16_C( 13030), -INT16_C( 12589),  INT16_C( 18041), -INT16_C( 24701), -INT16_C( 24221),  INT16_C(  7634),
         INT16_C( 23962), -INT16_C( 16288),  INT16_C( 23804),  INT16_C( 14078), -INT16_C( 25015), -INT16_C(  8433),  INT16_C( 22334),  INT16_C( 31063),
         INT16_C( 26811), -INT16_C( 14810), -INT16_C( 11319),  INT16_C( 21510), -INT16_C(  6189), -INT16_C( 32187), -INT16_C( 25817), -INT16_C(  9196),
        -INT16_C(   780),  INT16_C(  8219), -INT16_C( 28654),  INT16_C( 21153), -INT16_C(  1769),  INT16_C( 15083), -INT16_C( 25786),  INT16_C( 19691),
         INT16_C(  4251),  INT16_C( 18683), -INT16_C( 17739), -INT16_C( 32142), -INT16_C( 15068), -INT16_C(  7933),  INT16_C(  6130), -INT16_C( 14008),
         INT16_C(  5317), -INT16_C( 21835), -INT16_C( 30354), -INT16_C(   350),  INT16_C( 19336), -INT16_C(  7856),  INT16_C( 14868),  INT16_C(  6257),
         INT16_C(  3403), -INT16_C(  5366), -INT16_C( 32078), -INT16_C(   302),  INT16_C( 16074), -INT16_C( 18436), -INT16_C( 30878),  INT16_C(   750),
         INT16_C(  5773), -INT16_C(   220),  INT16_C( 26675),  INT16_C( 26061), -INT16_C( 14507),  INT16_C(  1264),  INT16_C( 15360), -INT16_C( 29836),
        -INT16_C( 13964), -INT16_C( 26478),  INT16_C( 31607), -INT16_C(   364), -INT16_C(  4240), -INT16_C( 17569), -INT16_C( 14086), -INT16_C( 24347),
         INT16_C(  3629),  INT16_C( 29495),  INT16_C( 32537), -INT16_C(  1744),  INT16_C( 13219), -INT16_C(  7692), -INT16_C( 16611), -INT16_C( 18211),
        -INT16_C( 12502), -INT16_C(  4444),  INT16_C(   792),  INT16_C(  5590), -INT16_C( 18392),  INT16_C( 25148), -INT16_C( 10066), -INT16_C(  4279) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 19708),  INT16_C( 25327),  INT16_C(  5092),  INT16_C(  7631),
         INT16_C(  7319), -INT16_C( 31982), -INT16_C( 14082), -INT16_C( 14060),  INT16_C(   481),  INT16_C(  3521), -INT16_C( 30205), -INT16_C( 13168),
        -INT16_C(   403),  INT16_C(   905),  INT16_C( 12882),  INT16_C( 14143),  INT16_C( 15115), -INT16_C( 19434), -INT16_C(  4094),  INT16_C( 29352),
        -INT16_C( 28883),  INT16_C( 23926),  INT16_C(  4725), -INT16_C(  2003),  INT16_C( 25907),  INT16_C( 28892),  INT16_C( 19862), -INT16_C(  4717),
        -INT16_C(  8922),  INT16_C( 23572),  INT16_C(  7337), -INT16_C( 18164),  INT16_C( 31773),  INT16_C(  6646),  INT16_C( 14190),  INT16_C(   223),
         INT16_C(  3740),  INT16_C(  7637),  INT16_C( 31565), -INT16_C(  7762), -INT16_C( 11528), -INT16_C( 17443), -INT16_C(  1284), -INT16_C( 23507),
         INT16_C( 18099),  INT16_C( 22064),  INT16_C( 20513),  INT16_C( 27171),  INT16_C( 30649),  INT16_C(  7284), -INT16_C( 16101), -INT16_C( 10953),
        -INT16_C(  4837),  INT16_C( 32087), -INT16_C(  5585), -INT16_C(  2023), -INT16_C( 14601), -INT16_C( 10360),  INT16_C( 19990),  INT16_C( 18793),
        -INT16_C(  6410),  INT16_C( 15199),  INT16_C( 21455), -INT16_C( 24696), -INT16_C( 27202), -INT16_C( 27779), -INT16_C( 20598), -INT16_C( 20599),
         INT16_C(  7813), -INT16_C( 16041), -INT16_C( 26298), -INT16_C(  6352), -INT16_C( 27669), -INT16_C( 13648),  INT16_C( 32682), -INT16_C( 12312),
         INT16_C(  3334),  INT16_C( 25546),  INT16_C( 23946),  INT16_C( 32615),  INT16_C( 17531), -INT16_C( 22790),  INT16_C( 10584),  INT16_C( 12710),
        -INT16_C( 26534),  INT16_C(  6705),  INT16_C( 12960),  INT16_C( 10413),  INT16_C( 10332),  INT16_C( 31981), -INT16_C( 19286), -INT16_C( 19326),
        -INT16_C( 10267),  INT16_C( 20691),  INT16_C( 13076),  INT16_C( 22934), -INT16_C( 30655),  INT16_C( 20793), -INT16_C( 27330), -INT16_C( 27211),
         INT16_C( 17966), -INT16_C( 30574),  INT16_C( 27417),  INT16_C(  4737),  INT16_C( 24813), -INT16_C(   829),  INT16_C(  1018),  INT16_C( 30562),
        -INT16_C( 10056),  INT16_C( 22821), -INT16_C( 32578),  INT16_C( 28822),  INT16_C(   384),  INT16_C( 25315),  INT16_C( 22173), -INT16_C(  9457) },
      {  INT16_C(     0),  INT16_C(     1),        INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C(     0),
               INT16_MAX,       -INT16_MAX,  INT16_C(     0), -INT16_C( 32766),  INT16_C( 22696),  INT16_C(  4257),  INT16_C( 29297), -INT16_C(  5784),
        -INT16_C( 23742),  INT16_C( 17279), -INT16_C( 13290), -INT16_C( 22827), -INT16_C( 29109),  INT16_C( 26410),  INT16_C( 15770),  INT16_C(  6105),
        -INT16_C( 28254), -INT16_C( 10286), -INT16_C(  6339),  INT16_C( 19218), -INT16_C(  1951), -INT16_C( 16150), -INT16_C(  3609),  INT16_C( 19799),
        -INT16_C(  7439),  INT16_C( 24994),  INT16_C( 20290), -INT16_C( 17727), -INT16_C(  6334), -INT16_C(  2185),  INT16_C( 13058), -INT16_C(  1325),
         INT16_C( 17679),  INT16_C( 14838),  INT16_C(  5693),  INT16_C(  5575), -INT16_C( 13732), -INT16_C( 31347),  INT16_C( 27125),  INT16_C(  7411),
         INT16_C( 20222), -INT16_C( 23925), -INT16_C(  7761),  INT16_C( 21840), -INT16_C( 13487),  INT16_C(  9010),  INT16_C( 23618), -INT16_C( 10966),
         INT16_C(  8712),  INT16_C( 28662), -INT16_C( 31832), -INT16_C(  5661),  INT16_C( 28698),  INT16_C( 26065), -INT16_C(  9716),  INT16_C(  1757),
         INT16_C(  4057), -INT16_C( 23868), -INT16_C( 23069),  INT16_C( 23176),  INT16_C( 12832),  INT16_C( 25443),  INT16_C( 19760),  INT16_C(   898),
         INT16_C( 10661),  INT16_C(  3484),  INT16_C( 26342), -INT16_C(  7446),  INT16_C( 12134),  INT16_C( 19846),  INT16_C( 26728),  INT16_C(  6591),
        -INT16_C(  2496), -INT16_C(  5794), -INT16_C(  4056),  INT16_C(  6002), -INT16_C( 18531),  INT16_C(  5792), -INT16_C( 17814),  INT16_C( 18569),
         INT16_C(    69), -INT16_C( 30912),  INT16_C(  9512),  INT16_C( 32619), -INT16_C(  1457),  INT16_C(  4354),  INT16_C( 24074), -INT16_C( 11960),
         INT16_C( 32307), -INT16_C(  6925),  INT16_C( 13715),  INT16_C( 15648), -INT16_C( 24839), -INT16_C( 30717), -INT16_C( 30890), -INT16_C( 10510),
        -INT16_C(  3697),  INT16_C( 18367),  INT16_C( 18531), -INT16_C( 23298),  INT16_C( 26415),  INT16_C( 27174),  INT16_C( 13244),  INT16_C(  2864),
        -INT16_C( 14337), -INT16_C(  5467),  INT16_C(  5120), -INT16_C(  6481), -INT16_C( 11594), -INT16_C(  6863), -INT16_C( 17629),  INT16_C( 16763),
        -INT16_C(  2446), -INT16_C( 27265), -INT16_C( 32166), -INT16_C( 23232), -INT16_C( 18776), -INT16_C(   167), -INT16_C( 32239),  INT16_C(  5178) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vsub_WhWh(a, b);

    simde_test_hvx_vectorpair_i16_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i16_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i16_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vsub_WhWh(a, b);

    simde_test_hvx_vectorpair_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_WwWw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_PAIR_I32_COUNT];
    int32_t b[SIMDE_HVX_PAIR_I32_COUNT];
    int32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(  2123147079), -INT32_C(  1060610574), -INT32_C(  1125910081), -INT32_C(  1194384334),
         INT32_C(   684142481), -INT32_C(   904512045),  INT32_C(  1845959673),  INT32_C(  1508759880),  INT32_C(   384104424), -INT32_C(   901970991), -INT32_C(   291097094),  INT32_C(   214396455),
         INT32_C(   923920196), -INT32_C(   991883522), -INT32_C(  1481783035),  INT32_C(  1099119860), -INT32_C(  2002299081), -INT32_C(   612270267), -INT32_C(   536233005), -INT32_C(  1536328543),
        -INT32_C(  1799177090), -INT32_C(   977610707),  INT32_C(   956841540),  INT32_C(   963992277),  INT32_C(  1313421249), -INT32_C(   204218691),  INT32_C(  1038772511), -INT32_C(   290321238),
        -INT32_C(  1109160671), -INT32_C(   283555585), -INT32_C(  1944391612),  INT32_C(   762868180),  INT32_C(    39584251),  INT32_C(  2022683295),  INT32_C(   446333405), -INT32_C(   747128677),
         INT32_C(   871798889), -INT32_C(   966569683),  INT32_C(    18631445),  INT32_C(   795772988), -INT32_C(  2010693117), -INT32_C(  1850280588),  INT32_C(  1934175429),  INT32_C(  1776759331),
         INT32_C(  1648846687),  INT32_C(  1177668216),  INT32_C(   867368097), -INT32_C(   377067132), -INT32_C(  1431479603), -INT32_C(   169254259),  INT32_C(   888573029),  INT32_C(   710934482) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX, -INT32_C(   795339632), -INT32_C(  1131151323), -INT32_C(   613054408), -INT32_C(  1486838307),
        -INT32_C(  1681039461),  INT32_C(   482029511),  INT32_C(  1731121046),  INT32_C(  1536029457), -INT32_C(  1270053719), -INT32_C(   915957488),  INT32_C(  1488755324),  INT32_C(   106117741),
        -INT32_C(   160136931), -INT32_C(    33117438), -INT32_C(  1829375490),  INT32_C(   726644997), -INT32_C(  1158136397), -INT32_C(  1635950362), -INT32_C(   162994614), -INT32_C(  1134785000),
        -INT32_C(  1185444121),  INT32_C(   122699769),  INT32_C(  1057021000), -INT32_C(  1579013920),  INT32_C(  1203908769), -INT32_C(  1626692821), -INT32_C(   190151891), -INT32_C(  1538999508),
         INT32_C(  1576014750), -INT32_C(  1920809088), -INT32_C(   214046315),  INT32_C(  1708017003), -INT32_C(     9986034),  INT32_C(   912201110),  INT32_C(   274284946), -INT32_C(  1346662783),
         INT32_C(  1990678011), -INT32_C(   495763011),  INT32_C(  1196081474), -INT32_C(   607996660), -INT32_C(   523284501),  INT32_C(   577020984),  INT32_C(   203895642), -INT32_C(  1816738948),
        -INT32_C(  1759102403),  INT32_C(  1713398804),  INT32_C(   682140985), -INT32_C(  1716470644), -INT32_C(   350608190),  INT32_C(  1251858467), -INT32_C(  1322533647), -INT32_C(    28458086) },
      {  INT32_C(           0),  INT32_C(           1),              INT32_MAX,  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(           0),
                     INT32_MAX, -INT32_C(  2147483647),  INT32_C(           0), -INT32_C(  2147483646), -INT32_C(  1376480585),  INT32_C(    70540749), -INT32_C(   512855673),  INT32_C(   292453973),
        -INT32_C(  1929785354), -INT32_C(  1386541556),  INT32_C(   114838627), -INT32_C(    27269577),  INT32_C(  1654158143),  INT32_C(    13986497), -INT32_C(  1779852418),  INT32_C(   108278714),
         INT32_C(  1084057127), -INT32_C(   958766084),  INT32_C(   347592455),  INT32_C(   372474863), -INT32_C(   844162684),  INT32_C(  1023680095), -INT32_C(   373238391), -INT32_C(   401543543),
        -INT32_C(   613732969), -INT32_C(  1100310476), -INT32_C(   100179460), -INT32_C(  1751961099),  INT32_C(   109512480),  INT32_C(  1422474130),  INT32_C(  1228924402),  INT32_C(  1248678270),
         INT32_C(  1609791875),  INT32_C(  1637253503), -INT32_C(  1730345297), -INT32_C(   945148823),  INT32_C(    49570285),  INT32_C(  1110482185),  INT32_C(   172048459),  INT32_C(   599534106),
        -INT32_C(  1118879122), -INT32_C(   470806672), -INT32_C(  1177450029),  INT32_C(  1403769648), -INT32_C(  1487408616),  INT32_C(  1867665724),  INT32_C(  1730279787), -INT32_C(   701469017),
        -INT32_C(   887018206), -INT32_C(   535730588),  INT32_C(   185227112),  INT32_C(  1339403512), -INT32_C(  1080871413), -INT32_C(  1421112726), -INT32_C(  2083860620),  INT32_C(   739392568) } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(   574411748),  INT32_C(   673636994), -INT32_C(  1061592054), -INT32_C(  1155007157),
        -INT32_C(  1875996547),  INT32_C(  1125094438), -INT32_C(  1064418373), -INT32_C(  2106536908), -INT32_C(  2030175623), -INT32_C(   496110853), -INT32_C(   197053708),  INT32_C(   355135748),
        -INT32_C(  1623402089),  INT32_C(   258821160), -INT32_C(   804578994), -INT32_C(  1670877969), -INT32_C(  1502480271),  INT32_C(   122965906), -INT32_C(   430404567), -INT32_C(   309913155),
        -INT32_C(  1628181249),  INT32_C(  1770283872),  INT32_C(   652311082),  INT32_C(  1751350897),  INT32_C(  1370774816),  INT32_C(   650727075),  INT32_C(   721387694),  INT32_C(  1319086538),
        -INT32_C(  1040726815), -INT32_C(  1703565420),  INT32_C(   665281732),  INT32_C(   175803430), -INT32_C(   311426048),  INT32_C(  1758297847), -INT32_C(   376098786), -INT32_C(   256875713),
         INT32_C(  1817799986), -INT32_C(  2143166953),  INT32_C(  1696758914), -INT32_C(   118907827),  INT32_C(  1508876959), -INT32_C(   437025819),  INT32_C(  1783453247), -INT32_C(   415707654),
         INT32_C(   501279781), -INT32_C(  1593024080), -INT32_C(   613591277),  INT32_C(  1915103169), -INT32_C(  1976931885),  INT32_C(  1969123583),  INT32_C(   253187358), -INT32_C(   657525724) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX, -INT32_C(   368887138),  INT32_C(  1675962496),  INT32_C(  2105305511), -INT32_C(   875489888),
         INT32_C(  1114476360), -INT32_C(   219711068),  INT32_C(  1077975543), -INT32_C(  1116802601),  INT32_C(  1049308231), -INT32_C(  1643086078), -INT32_C(  1122048370), -INT32_C(  1143650163),
        -INT32_C(   661894915), -INT32_C(   666482655),  INT32_C(   287862081),  INT32_C(   797290835),  INT32_C(  1799350940), -INT32_C(   853275466), -INT32_C(  1740856997),  INT32_C(  1733533102),
         INT32_C(  1448131407), -INT32_C(   135993330), -INT32_C(  1946267149), -INT32_C(   678853467), -INT32_C(   202724445),  INT32_C(  1770514832), -INT32_C(  1291296184), -INT32_C(   922541027),
         INT32_C(  1716458158),  INT32_C(  1305991138), -INT32_C(  1278695788),  INT32_C(   283786396), -INT32_C(  1025595786),  INT32_C(   464339751),  INT32_C(  1703566048),  INT32_C(   510874092),
         INT32_C(    16769038),  INT32_C(    84895198), -INT32_C(   802239146),  INT32_C(   623835922),  INT32_C(  1418150395),  INT32_C(   345191388),  INT32_C(   907259026), -INT32_C(  1704511954),
         INT32_C(  1275397717), -INT32_C(  2003481620), -INT32_C(  1347980949), -INT32_C(  1089587789),  INT32_C(  1417328668), -INT32_C(   574875264), -INT32_C(   433226809), -INT32_C(  1732885636) },
      {  INT32_C(           0),  INT32_C(           1),              INT32_MAX,  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(           0),
                     INT32_MAX, -INT32_C(  2147483647),  INT32_C(           0), -INT32_C(  2147483646), -INT32_C(   205524610), -INT32_C(  1002325502),  INT32_C(  1128069731), -INT32_C(   279517269),
         INT32_C(  1304494389),  INT32_C(  1344805506), -INT32_C(  2142393916), -INT32_C(   989734307),  INT32_C(  1215483442),  INT32_C(  1146975225),  INT32_C(   924994662),  INT32_C(  1498785911),
        -INT32_C(   961507174),  INT32_C(   925303815), -INT32_C(  1092441075),  INT32_C(  1826798492),  INT32_C(   993136085),  INT32_C(   976241372),  INT32_C(  1310452430), -INT32_C(  2043446257),
         INT32_C(  1218654640),  INT32_C(  1906277202), -INT32_C(  1696389065), -INT32_C(  1864762932),  INT32_C(  1573499261), -INT32_C(  1119787757),  INT32_C(  2012683878), -INT32_C(  2053339731),
         INT32_C(  1537782323),  INT32_C(  1285410738),  INT32_C(  1943977520), -INT32_C(   107982966),  INT32_C(   714169738),  INT32_C(  1293958096), -INT32_C(  2079664834), -INT32_C(   767749805),
         INT32_C(  1801030948),  INT32_C(  2066905145), -INT32_C(  1795969236), -INT32_C(   742743749),  INT32_C(    90726564), -INT32_C(   782217207),  INT32_C(   876194221),  INT32_C(  1288804300),
        -INT32_C(   774117936),  INT32_C(   410457540),  INT32_C(   734389672), -INT32_C(  1290276338),  INT32_C(   900706743), -INT32_C(  1750968449),  INT32_C(   686414167),  INT32_C(  1075359912) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vsub_WwWw(a, b);

    simde_test_hvx_vectorpair_i32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i32_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i32_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vsub_WwWw(a, b);

    simde_test_hvx_vectorpair_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_WbWb_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[SIMDE_HVX_PAIR_SIZE];
    int8_t b[SIMDE_HVX_PAIR_SIZE];
    int8_t r[SIMDE_HVX_PAIR_SIZE];
  } test_vec[] = {
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),  INT8_C(  68),  INT8_C(  36),  INT8_C(  25), -INT8_C(  37),
         INT8_C( 122),  INT8_C(  75),  INT8_C(   2), -INT8_C(  60),  INT8_C( 123),  INT8_C( 122), -INT8_C(  74), -INT8_C(  87),
         INT8_C( 126),  INT8_C( 115),  INT8_C(   8), -INT8_C(  19), -INT8_C(   6),  INT8_C( 125), -INT8_C(  82),  INT8_C(  83),
         INT8_C(  90), -INT8_C( 118), -INT8_C(   6),  INT8_C(  85),  INT8_C(  60),  INT8_C(  63),  INT8_C(  36), -INT8_C(  57),
        -INT8_C(  30), -INT8_C( 126),  INT8_C(  93), -INT8_C( 120),  INT8_C( 109), -INT8_C(  60), -INT8_C(  49),  INT8_C(  59),
        -INT8_C(  88), -INT8_C(  26),  INT8_C(  47), -INT8_C( 101),  INT8_C( 117),  INT8_C(  90),  INT8_C(  21),  INT8_C(  43),
         INT8_C(  97), -INT8_C(  45),  INT8_C( 106),      INT8_MAX, -INT8_C(  30),  INT8_C(  55), -INT8_C(  21),  INT8_C(  18),
        -INT8_C(  19), -INT8_C( 115), -INT8_C(  18),  INT8_C(  76), -INT8_C(  43),  INT8_C(  73), -INT8_C(  11),  INT8_C(  61),
        -INT8_C(  69),  INT8_C(  83),  INT8_C(  64),  INT8_C(  11), -INT8_C(   4),  INT8_C(  82),  INT8_C(  68),  INT8_C(  91),
        -INT8_C(  30),  INT8_C(  81),  INT8_C( 102), -INT8_C(  20),  INT8_C( 122),  INT8_C(  18), -INT8_C(  14), -INT8_C(  25),
         INT8_C(  89), -INT8_C(   4),  INT8_C(  27),  INT8_C(  15), -INT8_C( 118),  INT8_C(  84), -INT8_C(  67), -INT8_C(  32),
         INT8_C( 126), -INT8_C( 119),  INT8_C(  97), -INT8_C(  86),      INT8_MAX,  INT8_C(  89), -INT8_C(  97), -INT8_C( 103),
         INT8_C(   4),  INT8_C( 125),  INT8_C(  98),  INT8_C( 104), -INT8_C(  81),  INT8_C(  68),  INT8_C(  58), -INT8_C(  31),
         INT8_C(  64), -INT8_C(  44),  INT8_C( 114), -INT8_C( 123), -INT8_C(  93), -INT8_C(  76), -INT8_C(  22),  INT8_C(   7),
        -INT8_C(  87),  INT8_C( 121), -INT8_C(  37),  INT8_C(  83), -INT8_C(  23), -INT8_C(   4),  INT8_C(   5), -INT8_C(  67),
         INT8_C(  65),  INT8_C(  66),  INT8_C(  12),  INT8_C(  83), -INT8_C( 112), -INT8_C(  45), -INT8_C(  38),  INT8_C(  30),
        -INT8_C( 117), -INT8_C(   5), -INT8_C( 117),  INT8_C( 108),  INT8_C( 120), -INT8_C(  62), -INT8_C(  57), -INT8_C( 109),
         INT8_C( 114),  INT8_C( 103),  INT8_C(  13),  INT8_C(  22),  INT8_C(  61), -INT8_C(  33), -INT8_C(  96), -INT8_C(  85),
        -INT8_C( 126), -INT8_C( 120), -INT8_C(  56), -INT8_C(  61), -INT8_C(  97), -INT8_C(  39), -INT8_C( 111),  INT8_C(  83),
        -INT8_C(  83), -INT8_C(  48),  INT8_C(  49),  INT8_C(  44), -INT8_C(  12), -INT8_C(  88),  INT8_C( 114),  INT8_C(  63),
        -INT8_C(  85),  INT8_C(  85), -INT8_C(  17),      INT8_MAX,  INT8_C(  71), -INT8_C(  90),  INT8_C( 108), -INT8_C(  55),
        -INT8_C(  14),  INT8_C(  95), -INT8_C(  11), -INT8_C(  46),  INT8_C( 111),  INT8_C(  27), -INT8_C(  73), -INT8_C(  65),
         INT8_C(  29),  INT8_C(  43),  INT8_C(  85), -INT8_C(  94),  INT8_C( 125), -INT8_C(  47), -INT8_C(   1),  INT8_C(  35),
         INT8_C( 112),  INT8_C(  12),  INT8_C( 108),  INT8_C( 126), -INT8_C( 105),  INT8_C( 113),  INT8_C(   2),  INT8_C(  52),
         INT8_C(  31),  INT8_C( 104), -INT8_C(  39),  INT8_C(  94),  INT8_C(  80), -INT8_C(  13), -INT8_C(  70),  INT8_C(  96),
        -INT8_C(  63), -INT8_C( 112),  INT8_C( 122), -INT8_C( 112),  INT8_C(  97), -INT8_C(  73),  INT8_C(  86),  INT8_C(  74),
         INT8_C(  80), -INT8_C(  82), -INT8_C(  77),  INT8_C( 125), -INT8_C( 117),  INT8_C(  68),  INT8_C(  26),  INT8_C(  65),
        -INT8_C(  23),  INT8_C( 117),  INT8_C(   4), -INT8_C(  38),  INT8_C(  72),  INT8_C(   8),  INT8_C(  58),  INT8_C(  11),
         INT8_C(  93), -INT8_C(  79), -INT8_C(  34),  INT8_C( 101), -INT8_C(  47), -INT8_C(  46),  INT8_C( 111),  INT8_C(  43),
        -INT8_C( 105),  INT8_C(   3), -INT8_C( 118),  INT8_C( 117), -INT8_C(  27),  INT8_C(  33),  INT8_C(  34),  INT8_C(  71),
        -INT8_C(  91), -INT8_C(  78), -INT8_C(  59),  INT8_C(  46), -INT8_C( 112), -INT8_C(  61), -INT8_C(  69),      INT8_MIN },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  90),  INT8_C(  14),  INT8_C(  20), -INT8_C(  21),
        -INT8_C(  96),  INT8_C(  25),  INT8_C(  65),  INT8_C(  13), -INT8_C( 102), -INT8_C(  61), -INT8_C(  61), -INT8_C(  15),
        -INT8_C(  16), -INT8_C(  67), -INT8_C( 118),  INT8_C(  98),  INT8_C(  23),  INT8_C(  77),  INT8_C(  35),  INT8_C(  40),
         INT8_C(  37),  INT8_C(  46), -INT8_C(   4),  INT8_C(  45),  INT8_C( 120),  INT8_C( 125), -INT8_C(  85), -INT8_C(  65),
         INT8_C(  46),  INT8_C(  68), -INT8_C( 117),  INT8_C( 122), -INT8_C( 108),  INT8_C(   9),  INT8_C(  30), -INT8_C(  68),
        -INT8_C(  81),  INT8_C(  57), -INT8_C(   4), -INT8_C(  10), -INT8_C( 103),  INT8_C(  92), -INT8_C(  35), -INT8_C(  99),
         INT8_C( 105),  INT8_C(  62),  INT8_C(  17), -INT8_C( 105), -INT8_C(   9),  INT8_C(  12), -INT8_C(  31),  INT8_C(  39),
         INT8_C(  62),  INT8_C(  23), -INT8_C(  10), -INT8_C(  89),  INT8_C(  47), -INT8_C(  47), -INT8_C(  50), -INT8_C( 104),
         INT8_C(  88),  INT8_C(  82),  INT8_C( 106), -INT8_C(  88), -INT8_C( 121),  INT8_C(  64), -INT8_C( 118),  INT8_C(  11),
        -INT8_C(   6), -INT8_C(   4), -INT8_C(  30),  INT8_C(   0), -INT8_C( 107), -INT8_C(  33), -INT8_C( 109),  INT8_C(   8),
         INT8_C(  67),  INT8_C(  30), -INT8_C(  29), -INT8_C(  90),  INT8_C(  92), -INT8_C( 116),  INT8_C(  43), -INT8_C(  57),
         INT8_C(  37), -INT8_C(  73), -INT8_C(  99),  INT8_C( 121), -INT8_C(  78), -INT8_C( 107),  INT8_C( 105), -INT8_C(  15),
        -INT8_C(  93),  INT8_C(  52), -INT8_C(  80),  INT8_C(  69),  INT8_C(  99),  INT8_C(  62),  INT8_C(   1),  INT8_C(  11),
         INT8_C(  73), -INT8_C(  43), -INT8_C(  10), -INT8_C(  48), -INT8_C( 121), -INT8_C(  57), -INT8_C( 124),  INT8_C(  42),
        -INT8_C(  67), -INT8_C(  57), -INT8_C(   8), -INT8_C(  66),  INT8_C(  75),  INT8_C( 120), -INT8_C(  63), -INT8_C(  32),
         INT8_C(  29),  INT8_C(  41), -INT8_C(  95),  INT8_C( 104),  INT8_C(  83), -INT8_C( 120), -INT8_C(  77), -INT8_C(  87),
        -INT8_C(  70),  INT8_C( 115), -INT8_C( 101),  INT8_C(  40), -INT8_C(  60),  INT8_C(  30),  INT8_C( 112), -INT8_C(  91),
        -INT8_C(  76),  INT8_C(  63), -INT8_C(  89),  INT8_C(   3), -INT8_C(  43), -INT8_C(   7),  INT8_C(  75), -INT8_C( 113),
        -INT8_C(  63), -INT8_C(  78),  INT8_C(  31), -INT8_C(  19), -INT8_C(  86), -INT8_C(  43),  INT8_C(  73), -INT8_C( 121),
         INT8_C(  97),  INT8_C(  50), -INT8_C(  77),  INT8_C(  80),  INT8_C(  50), -INT8_C(  53), -INT8_C(  21),  INT8_C( 104),
        -INT8_C( 117),  INT8_C( 120),  INT8_C(  75), -INT8_C(  43),  INT8_C( 125),  INT8_C( 126),  INT8_C(  47), -INT8_C(  23),
        -INT8_C(  39),  INT8_C( 102), -INT8_C(  35), -INT8_C(  48), -INT8_C(  12),  INT8_C(  27),      INT8_MAX,  INT8_C(  32),
        -INT8_C(  10),  INT8_C( 111), -INT8_C(  13),  INT8_C(  33), -INT8_C(  56), -INT8_C(  67),  INT8_C(  49),  INT8_C(  71),
         INT8_C(  27), -INT8_C(  80),  INT8_C(  86), -INT8_C( 114), -INT8_C(  89),  INT8_C(   0),  INT8_C(  29),  INT8_C(  49),
         INT8_C(  28),  INT8_C(  93),  INT8_C( 111),  INT8_C(  67), -INT8_C(  38),  INT8_C(   2), -INT8_C( 103),  INT8_C(   9),
        -INT8_C( 114),  INT8_C(  85), -INT8_C( 118),  INT8_C(  48), -INT8_C( 106),  INT8_C( 113),  INT8_C(  45),      INT8_MIN,
         INT8_C(  89),  INT8_C(  50),  INT8_C(  69), -INT8_C(  86),  INT8_C(  99), -INT8_C( 101),  INT8_C(  11), -INT8_C(  46),
        -INT8_C(  33), -INT8_C( 126),  INT8_C(  45), -INT8_C(  35),  INT8_C(  38), -INT8_C(  30),  INT8_C(  92),  INT8_C( 121),
        -INT8_C(  28),  INT8_C(  52),  INT8_C( 121),  INT8_C(  30),  INT8_C( 108),  INT8_C(  74),  INT8_C(  48), -INT8_C(  61),
         INT8_C(  31), -INT8_C( 101), -INT8_C(  74),  INT8_C( 121),  INT8_C(  76),  INT8_C(  54), -INT8_C(  33), -INT8_C(  39),
         INT8_C(  82), -INT8_C(  35),  INT8_C(  17),  INT8_C(  62),  INT8_C(  47), -INT8_C(  29),  INT8_C( 111),  INT8_C(  49) },
      {  INT8_C(   0),      INT8_MIN,      INT8_MAX,  INT8_C( 126), -INT8_C( 127),  INT8_C( 126), -INT8_C( 127),  INT8_C(   0),
             INT8_MAX,      INT8_MAX,  INT8_C(   0), -INT8_C( 126), -INT8_C(  22),  INT8_C(  22),  INT8_C(   5), -INT8_C(  16),
             INT8_MAX,  INT8_C(  50), -INT8_C(  63), -INT8_C(  73),      INT8_MAX,      INT8_MAX, -INT8_C(  13), -INT8_C(  72),
             INT8_MAX,      INT8_MAX,  INT8_C( 126), -INT8_C( 117), -INT8_C(  29),  INT8_C(  48), -INT8_C( 117),  INT8_C(  43),
         INT8_C(  53),      INT8_MIN, -INT8_C(   2),  INT8_C(  40), -INT8_C(  60), -INT8_C(  62),  INT8_C( 121),  INT8_C(   8),
        -INT8_C(  76),      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX, -INT8_C(  69), -INT8_C(  79),      INT8_MAX,
        -INT8_C(   7), -INT8_C(  83),  INT8_C(  51), -INT8_C(  91),      INT8_MAX, -INT8_C(   2),  INT8_C(  56),      INT8_MAX,
        -INT8_C(   8), -INT8_C( 107),  INT8_C(  89),      INT8_MAX, -INT8_C(  21),  INT8_C(  43),  INT8_C(  10), -INT8_C(  21),
        -INT8_C(  81),      INT8_MIN, -INT8_C(   8),      INT8_MAX, -INT8_C(  90),  INT8_C( 120),  INT8_C(  39),      INT8_MAX,
             INT8_MIN,  INT8_C(   1), -INT8_C(  42),  INT8_C(  99),  INT8_C( 117),  INT8_C(  18),      INT8_MAX,  INT8_C(  80),
        -INT8_C(  24),  INT8_C(  85),      INT8_MAX, -INT8_C(  20),      INT8_MAX,  INT8_C(  51),  INT8_C(  95), -INT8_C(  33),
         INT8_C(  22), -INT8_C(  34),  INT8_C(  56),  INT8_C( 105),      INT8_MIN,      INT8_MAX, -INT8_C( 110),  INT8_C(  25),
         INT8_C(  89), -INT8_C(  46),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN, -INT8_C(  88),
         INT8_C(  97),  INT8_C(  73),      INT8_MAX,  INT8_C(  35),      INT8_MIN,  INT8_C(   6),  INT8_C(  57), -INT8_C(  42),
        -INT8_C(   9), -INT8_C(   1),  INT8_C( 124), -INT8_C(  75),  INT8_C(  28), -INT8_C(  19),  INT8_C( 102), -INT8_C(  35),
        -INT8_C(  20),      INT8_MAX, -INT8_C(  29),      INT8_MAX, -INT8_C(  98), -INT8_C( 124),  INT8_C(  68), -INT8_C(  35),
         INT8_C(  36),  INT8_C(  25),  INT8_C( 107), -INT8_C(  21),      INT8_MIN,  INT8_C(  75),  INT8_C(  39),  INT8_C( 117),
        -INT8_C(  47), -INT8_C( 120), -INT8_C(  16),  INT8_C(  68),      INT8_MAX, -INT8_C(  92),      INT8_MIN, -INT8_C(  18),
             INT8_MAX,  INT8_C(  40),  INT8_C( 102),  INT8_C(  19),  INT8_C( 104), -INT8_C(  26),      INT8_MIN,  INT8_C(  28),
        -INT8_C(  63), -INT8_C(  42), -INT8_C(  87), -INT8_C(  42), -INT8_C(  11),  INT8_C(   4),      INT8_MIN,      INT8_MAX,
             INT8_MIN, -INT8_C(  98),  INT8_C( 126), -INT8_C(  36), -INT8_C(  62), -INT8_C(  35),      INT8_MAX, -INT8_C(  41),
         INT8_C(  32), -INT8_C(  35), -INT8_C(  92),      INT8_MAX, -INT8_C(  54),      INT8_MIN,  INT8_C(  61), -INT8_C(  32),
         INT8_C(  25), -INT8_C(   7),  INT8_C(  24),  INT8_C(   2),  INT8_C( 123),  INT8_C(   0),      INT8_MIN, -INT8_C(  97),
         INT8_C(  39), -INT8_C(  68),  INT8_C(  98), -INT8_C( 127),      INT8_MAX,  INT8_C(  20), -INT8_C(  50), -INT8_C(  36),
         INT8_C(  85),  INT8_C(  92),  INT8_C(  22),      INT8_MAX, -INT8_C(  16),  INT8_C( 113), -INT8_C(  27),  INT8_C(   3),
         INT8_C(   3),  INT8_C(  11),      INT8_MIN,  INT8_C(  27),  INT8_C( 118), -INT8_C(  15),  INT8_C(  33),  INT8_C(  87),
         INT8_C(  51),      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(  41),      INT8_MAX,
        -INT8_C(   9),      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(  15),  INT8_C( 111),
         INT8_C(  10),      INT8_MAX, -INT8_C(  41), -INT8_C(   3),  INT8_C(  34),  INT8_C(  38), -INT8_C(  34), -INT8_C( 110),
         INT8_C( 121),      INT8_MIN,      INT8_MIN,  INT8_C(  71),      INT8_MIN, -INT8_C( 120),  INT8_C(  63),  INT8_C( 104),
             INT8_MIN,  INT8_C( 104), -INT8_C(  44), -INT8_C(   4), -INT8_C( 103), -INT8_C(  21),  INT8_C(  67),  INT8_C( 110),
             INT8_MIN, -INT8_C(  43), -INT8_C(  76), -INT8_C(  16),      INT8_MIN, -INT8_C(  32),      INT8_MIN,      INT8_MIN } },
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),  INT8_C(  76),  INT8_C( 110),  INT8_C(  56),  INT8_C(  88),
         INT8_C(   0),  INT8_C( 125),  INT8_C(  17), -INT8_C( 121), -INT8_C(  83),  INT8_C( 121),  INT8_C(  20),  INT8_C(  48),
         INT8_C(  78), -INT8_C( 114), -INT8_C(  25),  INT8_C( 126), -INT8_C(  34),  INT8_C(  80),  INT8_C(  86),  INT8_C( 122),
         INT8_C(  28), -INT8_C(  78), -INT8_C(   2),  INT8_C(  70), -INT8_C( 119),  INT8_C(  73),  INT8_C( 121),  INT8_C( 110),
        -INT8_C(  69),  INT8_C(  32),  INT8_C(  88),  INT8_C(  95), -INT8_C(  26), -INT8_C(   6), -INT8_C(  39),  INT8_C(   0),
         INT8_C(   6), -INT8_C( 100),  INT8_C(   1),  INT8_C(  94),  INT8_C(   1),  INT8_C( 119),  INT8_C(  66),  INT8_C(  57),
        -INT8_C(  44), -INT8_C(  91), -INT8_C(  35), -INT8_C(  11), -INT8_C(  91), -INT8_C(  99), -INT8_C(   1),  INT8_C(   4),
        -INT8_C(  21),  INT8_C(  28), -INT8_C(  89), -INT8_C(  80),  INT8_C(   6),  INT8_C(  61), -INT8_C(  28), -INT8_C(  39),
        -INT8_C(   3), -INT8_C(  39),  INT8_C( 119), -INT8_C(   4),  INT8_C(  61),  INT8_C( 104), -INT8_C(  68), -INT8_C(  35),
         INT8_C(  29),  INT8_C(  35),  INT8_C(  47),  INT8_C(  75),  INT8_C( 101),  INT8_C( 119),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  26),  INT8_C(  82), -INT8_C(   2), -INT8_C( 100),  INT8_C(  69), -INT8_C(  60),  INT8_C(  70),  INT8_C(  23),
        -INT8_C(  30),  INT8_C(  78),  INT8_C(   0),  INT8_C(  14),  INT8_C(  10),  INT8_C( 119),  INT8_C( 115), -INT8_C(  30),
         INT8_C(  10), -INT8_C(  29), -INT8_C(  23),  INT8_C( 123), -INT8_C(  80),  INT8_C(  29),  INT8_C(  45),  INT8_C( 106),
             INT8_MIN,  INT8_C( 111), -INT8_C( 102), -INT8_C( 119),  INT8_C( 113),  INT8_C(  34), -INT8_C(  81),  INT8_C(  13),
         INT8_C(  35), -INT8_C(  96),  INT8_C(  57), -INT8_C(  31), -INT8_C( 111), -INT8_C(  79), -INT8_C( 117),  INT8_C(  31),
         INT8_C(  13),  INT8_C( 118),  INT8_C( 109), -INT8_C(  57), -INT8_C(  93), -INT8_C(  52), -INT8_C( 104), -INT8_C(  59),
         INT8_C(  41),  INT8_C(  17),  INT8_C(  33),  INT8_C( 122),  INT8_C(  71), -INT8_C(  32), -INT8_C(  74),  INT8_C( 114),
         INT8_C( 113),  INT8_C(  62),  INT8_C(  34),  INT8_C(  97),  INT8_C(  97),  INT8_C(  98), -INT8_C(  92),  INT8_C(  21),
         INT8_C(  77), -INT8_C(   1), -INT8_C(  50),  INT8_C(  37),  INT8_C( 119), -INT8_C( 123),  INT8_C(  12),  INT8_C(  99),
         INT8_C(  47), -INT8_C(  55), -INT8_C(  48),  INT8_C( 114), -INT8_C(  27),  INT8_C(  80), -INT8_C(  53),  INT8_C(  31),
        -INT8_C( 103),  INT8_C( 115), -INT8_C(  22),  INT8_C(  95),  INT8_C( 117), -INT8_C(  40),  INT8_C(  65), -INT8_C( 125),
         INT8_C( 108),  INT8_C(  86), -INT8_C( 100), -INT8_C(  45), -INT8_C(  66), -INT8_C(  70),  INT8_C( 122),  INT8_C( 109),
         INT8_C( 110),  INT8_C(  81),  INT8_C(  65), -INT8_C(  63), -INT8_C( 126),  INT8_C(  78), -INT8_C(  58),  INT8_C(  52),
        -INT8_C(  81), -INT8_C(  22),  INT8_C(  80),  INT8_C(  61),  INT8_C(  83),  INT8_C( 109),  INT8_C(  67), -INT8_C( 127),
         INT8_C( 109),  INT8_C(  30),  INT8_C(  26),  INT8_C(  23),  INT8_C(  99),  INT8_C(   8), -INT8_C(  75), -INT8_C(  33),
        -INT8_C(  29), -INT8_C(  77),  INT8_C(  89), -INT8_C(  77),  INT8_C( 126),  INT8_C(  35), -INT8_C(  21),  INT8_C(  17),
         INT8_C( 107),  INT8_C( 112), -INT8_C(  61), -INT8_C( 120), -INT8_C(  26),  INT8_C(  65), -INT8_C(  46), -INT8_C(  95),
         INT8_C(  21), -INT8_C(  39), -INT8_C(  80), -INT8_C(  52), -INT8_C(  59), -INT8_C( 127),  INT8_C(  57), -INT8_C( 125),
        -INT8_C(  34),  INT8_C( 121), -INT8_C(  66),  INT8_C(  93), -INT8_C(  78),  INT8_C(  70),  INT8_C(  22), -INT8_C(  17),
         INT8_C( 113),  INT8_C(  48),  INT8_C(  61),  INT8_C(  78), -INT8_C(  77),  INT8_C( 102),  INT8_C(  32),  INT8_C(  26),
         INT8_C(  74),  INT8_C(  65),  INT8_C(  40), -INT8_C(  49),  INT8_C(   5),  INT8_C( 117),  INT8_C(  72), -INT8_C(  84) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(  58), -INT8_C(  69),  INT8_C(  38),  INT8_C(  56),
        -INT8_C( 109), -INT8_C(  77),  INT8_C(  75), -INT8_C( 115), -INT8_C(  82), -INT8_C(   9),  INT8_C(  50),  INT8_C(  22),
        -INT8_C(  48),  INT8_C(  56),  INT8_C(  81), -INT8_C(  25),  INT8_C( 120),  INT8_C(  33), -INT8_C( 103), -INT8_C(   8),
        -INT8_C( 108), -INT8_C(  39),  INT8_C( 106), -INT8_C(  16), -INT8_C(  88), -INT8_C(  30), -INT8_C( 123), -INT8_C(  36),
        -INT8_C(  36), -INT8_C(  84),  INT8_C(  69), -INT8_C( 112), -INT8_C( 116), -INT8_C(  38),  INT8_C( 126), -INT8_C(  52),
        -INT8_C(  33), -INT8_C(  41), -INT8_C(  78), -INT8_C( 103), -INT8_C(  91),  INT8_C(  80),  INT8_C(  41), -INT8_C(  37),
        -INT8_C( 111),  INT8_C( 101),  INT8_C(  28),  INT8_C(  39), -INT8_C( 111),  INT8_C(  84),  INT8_C( 113),  INT8_C(   3),
        -INT8_C( 122), -INT8_C(  20),  INT8_C(   7),  INT8_C(  31), -INT8_C( 112),  INT8_C(  27), -INT8_C( 117),  INT8_C(  49),
        -INT8_C(  70), -INT8_C( 118),  INT8_C(   2),  INT8_C(  76), -INT8_C(  65), -INT8_C(  37),  INT8_C(  52),  INT8_C(  63),
        -INT8_C(  69),  INT8_C(  26),  INT8_C(  95), -INT8_C(   2), -INT8_C(  35), -INT8_C(  52),  INT8_C( 123), -INT8_C(  41),
        -INT8_C( 115),  INT8_C(   1), -INT8_C(  43),  INT8_C( 110),  INT8_C( 103),  INT8_C(  49),  INT8_C(  23), -INT8_C(  45),
             INT8_MIN,  INT8_C(  39),  INT8_C(  40), -INT8_C( 115), -INT8_C(  71), -INT8_C(  43),  INT8_C( 107), -INT8_C(  54),
         INT8_C(   6),  INT8_C(  53), -INT8_C(  61),  INT8_C(  59), -INT8_C(  76), -INT8_C(  70), -INT8_C(   9),  INT8_C(  23),
        -INT8_C( 109), -INT8_C( 125),  INT8_C(  11),  INT8_C(  76),  INT8_C(  78),  INT8_C(   4),  INT8_C(   9), -INT8_C(  26),
         INT8_C(  67),  INT8_C( 120),  INT8_C(  35),  INT8_C(  37),  INT8_C(  91), -INT8_C(  87),  INT8_C(  72),  INT8_C(  45),
         INT8_C(  27), -INT8_C( 112), -INT8_C(  85),  INT8_C(   2), -INT8_C(  83), -INT8_C(  61), -INT8_C( 105), -INT8_C(   3),
         INT8_C(  96), -INT8_C( 112), -INT8_C(  17), -INT8_C( 126), -INT8_C( 101), -INT8_C(  81), -INT8_C(  84), -INT8_C(  61),
        -INT8_C( 112), -INT8_C(  46), -INT8_C(  55),  INT8_C(  59), -INT8_C(  50), -INT8_C(  92), -INT8_C(  94), -INT8_C(  96),
         INT8_C(  74), -INT8_C(  15),  INT8_C( 119), -INT8_C(  65),  INT8_C(  32), -INT8_C(  73), -INT8_C( 102),  INT8_C(  69),
         INT8_C(  94), -INT8_C( 120),  INT8_C(  93), -INT8_C( 112),  INT8_C(  53), -INT8_C(  89),  INT8_C( 122),  INT8_C(  29),
         INT8_C(  26),  INT8_C(  13), -INT8_C(  68),  INT8_C(  38),  INT8_C(  73),  INT8_C(  39), -INT8_C( 111),  INT8_C(  10),
        -INT8_C(  48),  INT8_C(  39),  INT8_C(  22),  INT8_C(  79), -INT8_C(  78), -INT8_C(  50), -INT8_C(   2),  INT8_C(  53),
         INT8_C( 102),  INT8_C(  93), -INT8_C(   4), -INT8_C(  63),  INT8_C(  65),  INT8_C(  29),  INT8_C(  90), -INT8_C(  13),
        -INT8_C(  82),  INT8_C(  59), -INT8_C(  50), -INT8_C(  12), -INT8_C(  65),  INT8_C( 118),  INT8_C(  56),  INT8_C(   8),
         INT8_C(  19),  INT8_C( 126), -INT8_C(  26), -INT8_C(  51),      INT8_MIN,  INT8_C(  68), -INT8_C(  40),  INT8_C(   1),
         INT8_C(  30),  INT8_C(  49),  INT8_C( 104), -INT8_C(   6), -INT8_C(   5), -INT8_C(  16),  INT8_C(  64), -INT8_C(  74),
         INT8_C(  35),  INT8_C(   2),  INT8_C(   5),  INT8_C(  69),  INT8_C(  39), -INT8_C( 101), -INT8_C(  24),  INT8_C( 100),
         INT8_C(  71), -INT8_C( 124), -INT8_C(  98),  INT8_C( 126),  INT8_C(  71), -INT8_C(  19), -INT8_C(  14),  INT8_C(  57),
         INT8_C(   7),  INT8_C(  93), -INT8_C(  44),  INT8_C(   2), -INT8_C(  76), -INT8_C(  44), -INT8_C(  55),  INT8_C( 124),
         INT8_C(  38), -INT8_C(  45),  INT8_C(  61),  INT8_C(  63), -INT8_C(   5),  INT8_C(  33), -INT8_C(  14), -INT8_C(  17),
        -INT8_C(  26), -INT8_C( 127), -INT8_C(   2), -INT8_C(   9), -INT8_C(  94), -INT8_C(  85), -INT8_C( 101),  INT8_C(  81) },
      {  INT8_C(   0),      INT8_MIN,      INT8_MAX,  INT8_C( 126), -INT8_C( 127),  INT8_C( 126), -INT8_C( 127),  INT8_C(   0),
             INT8_MAX,      INT8_MAX,  INT8_C(   0), -INT8_C( 126),      INT8_MAX,      INT8_MAX,  INT8_C(  18),  INT8_C(  32),
         INT8_C( 109),      INT8_MAX, -INT8_C(  58), -INT8_C(   6), -INT8_C(   1),      INT8_MAX, -INT8_C(  30),  INT8_C(  26),
         INT8_C( 126),      INT8_MIN, -INT8_C( 106),      INT8_MAX,      INT8_MIN,  INT8_C(  47),      INT8_MAX,      INT8_MAX,
             INT8_MAX, -INT8_C(  39), -INT8_C( 108),  INT8_C(  86), -INT8_C(  31),  INT8_C( 103),      INT8_MAX,      INT8_MAX,
        -INT8_C(  33),  INT8_C( 116),  INT8_C(  19),      INT8_MAX,  INT8_C(  90),  INT8_C(  32),      INT8_MIN,  INT8_C(  52),
         INT8_C(  39), -INT8_C(  59),  INT8_C(  79),      INT8_MAX,  INT8_C(  92),  INT8_C(  39),  INT8_C(  25),  INT8_C(  94),
         INT8_C(  67),      INT8_MIN, -INT8_C(  63), -INT8_C(  50),  INT8_C(  20),      INT8_MIN, -INT8_C( 114),  INT8_C(   1),
         INT8_C( 101),  INT8_C(  48), -INT8_C(  96), -INT8_C( 111),  INT8_C( 118),  INT8_C(  34),  INT8_C(  89), -INT8_C(  88),
         INT8_C(  67),  INT8_C(  79),  INT8_C( 117), -INT8_C(  80),  INT8_C( 126),      INT8_MAX, -INT8_C( 120), -INT8_C(  98),
         INT8_C(  98),  INT8_C(   9), -INT8_C(  48),  INT8_C(  77),      INT8_MAX,      INT8_MAX, -INT8_C(  38), -INT8_C(  45),
             INT8_MAX,  INT8_C(  81),  INT8_C(  41),      INT8_MIN, -INT8_C(  34), -INT8_C( 109),  INT8_C(  47),  INT8_C(  68),
         INT8_C(  98),  INT8_C(  39), -INT8_C(  40),      INT8_MAX,  INT8_C(  81),      INT8_MAX,  INT8_C(   8),  INT8_C(  24),
         INT8_C(   4), -INT8_C(  82),  INT8_C(  38),  INT8_C(  64), -INT8_C(   4),  INT8_C(  99),  INT8_C(  54),  INT8_C(  83),
        -INT8_C(  19),      INT8_MAX, -INT8_C( 113),      INT8_MIN,  INT8_C(  35),  INT8_C(  30), -INT8_C(  90),  INT8_C(  39),
        -INT8_C(  32),      INT8_MIN,  INT8_C(  22), -INT8_C(  68),      INT8_MIN,  INT8_C(   8),      INT8_MIN, -INT8_C(  14),
        -INT8_C(  14),      INT8_MAX,      INT8_MAX, -INT8_C(  59), -INT8_C(  10),  INT8_C(   9),  INT8_C(   1), -INT8_C(  56),
        -INT8_C(  55),      INT8_MAX,  INT8_C(  50),      INT8_MAX,      INT8_MAX,  INT8_C(  49),  INT8_C(  10),      INT8_MAX,
             INT8_MAX,  INT8_C( 108),  INT8_C(  89),  INT8_C(  38),      INT8_MAX,      INT8_MAX,  INT8_C(   2),  INT8_C( 117),
         INT8_C(   3),  INT8_C(  14),      INT8_MIN,  INT8_C( 102),  INT8_C(  87), -INT8_C(  50),  INT8_C( 114),  INT8_C(  30),
        -INT8_C(  47),  INT8_C(  65),      INT8_MIN,      INT8_MAX, -INT8_C(  80),      INT8_MAX,      INT8_MIN,  INT8_C(   2),
             INT8_MIN,  INT8_C( 102),  INT8_C(  46),  INT8_C(  57),  INT8_C(  44), -INT8_C(  79),      INT8_MAX,      INT8_MIN,
             INT8_MAX,  INT8_C(  47), -INT8_C( 122), -INT8_C( 124),  INT8_C(  12), -INT8_C(  20),  INT8_C( 124),  INT8_C(  56),
         INT8_C(   8), -INT8_C(  12),  INT8_C(  69),  INT8_C(   0),      INT8_MIN,  INT8_C(  49),      INT8_MIN,  INT8_C(  65),
         INT8_C(   1), -INT8_C(  81),      INT8_MAX,  INT8_C(  73),      INT8_MAX, -INT8_C(   9),  INT8_C(  11),      INT8_MIN,
         INT8_C(  90), -INT8_C(  96),  INT8_C(  52),  INT8_C(  74),      INT8_MAX, -INT8_C(  60), -INT8_C(  35), -INT8_C(  34),
        -INT8_C(  59), -INT8_C( 126), -INT8_C(  15), -INT8_C(  71),      INT8_MAX,  INT8_C(  51), -INT8_C(  85),  INT8_C(  91),
         INT8_C(  72),  INT8_C( 110), -INT8_C(  66),      INT8_MIN, -INT8_C(  65),      INT8_MAX, -INT8_C(  22),      INT8_MIN,
        -INT8_C(  50),  INT8_C(  85),  INT8_C(  18),      INT8_MIN,      INT8_MIN, -INT8_C( 108),  INT8_C(  71),      INT8_MIN,
        -INT8_C(  41),  INT8_C(  28), -INT8_C(  22),  INT8_C(  91), -INT8_C(   2),  INT8_C( 114),  INT8_C(  77),      INT8_MIN,
         INT8_C(  75),  INT8_C(  93),  INT8_C(   0),  INT8_C(  15), -INT8_C(  72),  INT8_C(  69),  INT8_C(  46),  INT8_C(  43),
         INT8_C( 100),      INT8_MAX,  INT8_C(  42), -INT8_C(  40),  INT8_C(  99),      INT8_MAX,      INT8_MAX,      INT8_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wb_vsub_WbWb_sat(a, b);

    simde_test_hvx_vectorpair_i8_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i8_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i8_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wb_vsub_WbWb_sat(a, b);

    simde_test_hvx_vectorpair_i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_WhWh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_PAIR_I16_COUNT];
    int16_t b[SIMDE_HVX_PAIR_I16_COUNT];
    int16_t r[SIMDE_HVX_PAIR_I16_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C( 27019), -INT16_C( 24872), -INT16_C( 16145), -INT16_C( 21221),
        -INT16_C( 14654), -INT16_C(  9849), -INT16_C(  5396),  INT16_C( 29096), -INT16_C(  8506), -INT16_C( 14160),  INT16_C( 19596),  INT16_C( 17004),
         INT16_C(  5198), -INT16_C( 13465), -INT16_C(  4516), -INT16_C( 15528),  INT16_C( 14709),  INT16_C(  7930), -INT16_C(  1471), -INT16_C(  9146),
         INT16_C( 13697),  INT16_C(  4600),  INT16_C( 21984),  INT16_C( 14327),  INT16_C( 25985),  INT16_C( 16264),  INT16_C(  2195),  INT16_C(    45),
        -INT16_C( 26845), -INT16_C( 22170),  INT16_C( 13008), -INT16_C(  1244), -INT16_C(  3286), -INT16_C(  1871),  INT16_C( 27075),  INT16_C( 25223),
         INT16_C( 32684),  INT16_C( 32663), -INT16_C(  5681),  INT16_C( 27363),  INT16_C( 14914),  INT16_C(  5847),  INT16_C( 21104), -INT16_C( 28811),
         INT16_C( 21003),  INT16_C(  5849),  INT16_C(  2799),  INT16_C( 18959),  INT16_C(  8553),  INT16_C( 20250), -INT16_C( 16091),  INT16_C(  7101),
         INT16_C( 15919),  INT16_C(  3703), -INT16_C(  3714),  INT16_C( 16026),  INT16_C(  2758), -INT16_C( 17224), -INT16_C( 28100), -INT16_C( 16827),
        -INT16_C( 14377), -INT16_C(  1851), -INT16_C( 21787), -INT16_C(  3296),  INT16_C( 26048),  INT16_C( 28057), -INT16_C( 26208), -INT16_C(  5740),
        -INT16_C( 15342),  INT16_C(  2324), -INT16_C( 24533),  INT16_C( 31550),  INT16_C( 27698), -INT16_C( 27504),  INT16_C( 16111),  INT16_C( 20973),
         INT16_C( 12807),  INT16_C(  6163), -INT16_C( 29032),  INT16_C( 25921), -INT16_C( 32607), -INT16_C( 15679),  INT16_C(  9339), -INT16_C(  5015),
        -INT16_C( 32648),  INT16_C( 32548),  INT16_C( 13808),  INT16_C(  2464), -INT16_C( 20755), -INT16_C( 16964),  INT16_C( 21924), -INT16_C(  4435),
        -INT16_C( 19841),  INT16_C( 17690),  INT16_C( 23505), -INT16_C( 30018), -INT16_C(  8960),  INT16_C( 27332),  INT16_C( 28439),  INT16_C( 12452),
        -INT16_C(  4590),  INT16_C( 10726), -INT16_C( 28755),  INT16_C(  2948),  INT16_C(  7930),  INT16_C( 20675),  INT16_C( 23906), -INT16_C( 27185),
        -INT16_C(  2373), -INT16_C(  1613),  INT16_C( 13281), -INT16_C( 24765), -INT16_C( 23967),  INT16_C( 11880),  INT16_C(  5745), -INT16_C(  7269) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 12661),  INT16_C(  2414), -INT16_C( 30675),  INT16_C(  2285),
        -INT16_C(   835),  INT16_C(  4477),  INT16_C( 24911), -INT16_C(  2665),  INT16_C(  2957),  INT16_C(  8152),  INT16_C( 21966), -INT16_C(  6430),
        -INT16_C(  9401),  INT16_C( 30805), -INT16_C( 18725), -INT16_C( 29068),  INT16_C( 15664),  INT16_C( 10629), -INT16_C( 18150), -INT16_C( 22425),
         INT16_C(  1579), -INT16_C(   192),  INT16_C( 14827), -INT16_C(  8902), -INT16_C( 12768), -INT16_C(  9886), -INT16_C( 16867),  INT16_C( 20928),
        -INT16_C( 21115),  INT16_C( 15636),  INT16_C( 23281), -INT16_C(  8621),  INT16_C( 20319),  INT16_C( 29882),  INT16_C( 25147), -INT16_C( 30626),
        -INT16_C(  4362), -INT16_C( 13652),  INT16_C( 19260), -INT16_C(  7607),  INT16_C( 24395), -INT16_C(   102), -INT16_C( 32573), -INT16_C( 21348),
         INT16_C( 31827),  INT16_C( 17520),  INT16_C( 13570),  INT16_C( 12318), -INT16_C( 11841), -INT16_C( 30363), -INT16_C( 17586),  INT16_C( 22925),
        -INT16_C( 23022),  INT16_C( 15565),  INT16_C( 14851), -INT16_C( 11155), -INT16_C(  1884),  INT16_C(  1552), -INT16_C(  3450), -INT16_C(  5295),
         INT16_C( 19438),  INT16_C( 24864), -INT16_C( 16815),  INT16_C( 12247), -INT16_C( 25196),  INT16_C( 17815), -INT16_C( 18481),  INT16_C( 28027),
         INT16_C( 11601), -INT16_C( 25972),  INT16_C( 27824), -INT16_C( 20673),  INT16_C(  5604),  INT16_C( 29460),  INT16_C( 20799), -INT16_C( 30204),
         INT16_C( 12278),  INT16_C( 25400), -INT16_C( 28649),  INT16_C( 19288),  INT16_C(  1218), -INT16_C( 15603), -INT16_C( 17274), -INT16_C(  5807),
        -INT16_C(  1713),  INT16_C(  1926),  INT16_C( 10443),  INT16_C( 10749),  INT16_C( 16574), -INT16_C( 25751),  INT16_C( 15140), -INT16_C( 31298),
         INT16_C( 31525),  INT16_C( 14001),  INT16_C( 17826),  INT16_C(  2006),  INT16_C( 23392), -INT16_C(  7014), -INT16_C(  7800),  INT16_C( 31040),
        -INT16_C(  7436),  INT16_C( 25689),  INT16_C( 12246), -INT16_C( 13871),  INT16_C( 23092), -INT16_C(  6031), -INT16_C( 20853), -INT16_C( 14962),
         INT16_C( 26763), -INT16_C( 30081), -INT16_C( 13053), -INT16_C( 12064),  INT16_C(  1748),  INT16_C( 19484), -INT16_C( 22334), -INT16_C( 32163) },
      {  INT16_C(     0),        INT16_MIN,        INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C(     0),
               INT16_MAX,        INT16_MAX,  INT16_C(     0), -INT16_C( 32766),  INT16_C( 14358), -INT16_C( 27286),  INT16_C( 14530), -INT16_C( 23506),
        -INT16_C( 13819), -INT16_C( 14326), -INT16_C( 30307),  INT16_C( 31761), -INT16_C( 11463), -INT16_C( 22312), -INT16_C(  2370),  INT16_C( 23434),
         INT16_C( 14599),        INT16_MIN,  INT16_C( 14209),  INT16_C( 13540), -INT16_C(   955), -INT16_C(  2699),  INT16_C( 16679),  INT16_C( 13279),
         INT16_C( 12118),  INT16_C(  4792),  INT16_C(  7157),  INT16_C( 23229),        INT16_MAX,  INT16_C( 26150),  INT16_C( 19062), -INT16_C( 20883),
        -INT16_C(  5730),        INT16_MIN, -INT16_C( 10273),  INT16_C(  7377), -INT16_C( 23605), -INT16_C( 31753),  INT16_C(  1928),        INT16_MAX,
               INT16_MAX,        INT16_MAX, -INT16_C( 24941),        INT16_MAX, -INT16_C(  9481),  INT16_C(  5949),        INT16_MAX, -INT16_C(  7463),
        -INT16_C( 10824), -INT16_C( 11671), -INT16_C( 10771),  INT16_C(  6641),  INT16_C( 20394),        INT16_MAX,  INT16_C(  1495), -INT16_C( 15824),
               INT16_MAX, -INT16_C( 11862), -INT16_C( 18565),  INT16_C( 27181),  INT16_C(  4642), -INT16_C( 18776), -INT16_C( 24650), -INT16_C( 11532),
               INT16_MIN, -INT16_C( 26715), -INT16_C(  4972), -INT16_C( 15543),        INT16_MAX,  INT16_C( 10242), -INT16_C(  7727),        INT16_MIN,
        -INT16_C( 26943),  INT16_C( 28296),        INT16_MIN,        INT16_MAX,  INT16_C( 22094),        INT16_MIN, -INT16_C(  4688),        INT16_MAX,
         INT16_C(   529), -INT16_C( 19237), -INT16_C(   383),  INT16_C(  6633),        INT16_MIN, -INT16_C(    76),  INT16_C( 26613),  INT16_C(   792),
        -INT16_C( 30935),  INT16_C( 30622),  INT16_C(  3365), -INT16_C(  8285),        INT16_MIN,  INT16_C(  8787),  INT16_C(  6784),  INT16_C( 26863),
               INT16_MIN,  INT16_C(  3689),  INT16_C(  5679), -INT16_C( 32024), -INT16_C( 32352),        INT16_MAX,        INT16_MAX, -INT16_C( 18588),
         INT16_C(  2846), -INT16_C( 14963),        INT16_MIN,  INT16_C( 16819), -INT16_C( 15162),  INT16_C( 26706),        INT16_MAX, -INT16_C( 12223),
        -INT16_C( 29136),  INT16_C( 28468),  INT16_C( 26334), -INT16_C( 12701), -INT16_C( 25715), -INT16_C(  7604),  INT16_C( 28079),  INT16_C( 24894) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C(   357), -INT16_C(  5405),  INT16_C( 14588), -INT16_C( 11264),
         INT16_C( 23929),  INT16_C(  1109), -INT16_C( 22615), -INT16_C( 28436), -INT16_C(  5596),  INT16_C(  4316),  INT16_C( 22298), -INT16_C( 25603),
         INT16_C(  5531), -INT16_C( 31342),  INT16_C( 28602),  INT16_C( 15107), -INT16_C(  4778), -INT16_C(  1878),  INT16_C(  6500), -INT16_C(  7772),
        -INT16_C( 12617), -INT16_C( 15231),  INT16_C( 29319),  INT16_C( 31050), -INT16_C( 31415), -INT16_C( 32308),  INT16_C( 11423), -INT16_C( 16407),
        -INT16_C( 11281),  INT16_C(  2844),  INT16_C( 22482), -INT16_C( 21527), -INT16_C( 25222),  INT16_C( 32507),  INT16_C( 28818),  INT16_C( 27204),
         INT16_C( 29384), -INT16_C( 19544), -INT16_C(  3118), -INT16_C( 19732),  INT16_C( 29326),  INT16_C( 18021),  INT16_C( 16238), -INT16_C( 22204),
         INT16_C(   953), -INT16_C( 27874), -INT16_C(  7915), -INT16_C(  4747),  INT16_C(  6990),  INT16_C( 22823), -INT16_C( 18158), -INT16_C( 18114),
         INT16_C( 20847),  INT16_C( 16009), -INT16_C(  7416),  INT16_C( 27580),  INT16_C( 13603), -INT16_C( 24983), -INT16_C( 27211),  INT16_C( 12421),
        -INT16_C(  5539), -INT16_C( 24635), -INT16_C( 30050), -INT16_C( 10656),  INT16_C( 14477), -INT16_C( 18255), -INT16_C(   153),  INT16_C( 20142),
        -INT16_C(  9985),  INT16_C( 25661), -INT16_C( 25459), -INT16_C( 27772), -INT16_C(  4330), -INT16_C(  4904), -INT16_C(  3342),  INT16_C( 19044),
         INT16_C( 14430), -INT16_C( 15349), -INT16_C( 13388), -INT16_C( 27336), -INT16_C( 26807),  INT16_C(  9021), -INT16_C( 24681),  INT16_C(  5197),
         INT16_C( 17492),  INT16_C(  6152),  INT16_C( 11028),  INT16_C( 28083),  INT16_C(  9507),  INT16_C( 32151),  INT16_C( 21809),  INT16_C(  1654),
         INT16_C( 12815), -INT16_C( 13234), -INT16_C(  3600),  INT16_C(  2011),  INT16_C( 13185), -INT16_C(   257),  INT16_C( 30764),  INT16_C(  5843),
        -INT16_C( 29878),  INT16_C(  9893), -INT16_C(  2683), -INT16_C( 23401),  INT16_C(  3857), -INT16_C( 13403), -INT16_C(  3362), -INT16_C(  2228),
         INT16_C( 23504),  INT16_C( 23900),  INT16_C( 31714), -INT16_C( 30601),  INT16_C( 29242), -INT16_C( 30547), -INT16_C( 20031), -INT16_C( 20523) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C( 22768),  INT16_C( 26090), -INT16_C(  5116),  INT16_C( 16419),
         INT16_C( 11979), -INT16_C( 31754),  INT16_C( 31923), -INT16_C( 13796), -INT16_C( 28575),  INT16_C( 29883),  INT16_C(  5400), -INT16_C( 23619),
         INT16_C(  2816),  INT16_C( 14101),  INT16_C( 16752),  INT16_C( 10090),  INT16_C(  9560), -INT16_C( 26316),  INT16_C(  1090),  INT16_C( 24486),
         INT16_C( 23606), -INT16_C( 25792),  INT16_C(  3687), -INT16_C( 16904), -INT16_C( 21109), -INT16_C(  1055), -INT16_C(  7619),  INT16_C( 14978),
        -INT16_C(  9135), -INT16_C( 15857), -INT16_C( 25625), -INT16_C(  4952), -INT16_C( 14935),  INT16_C(  4955),  INT16_C( 18792), -INT16_C( 28989),
         INT16_C( 25457), -INT16_C(  7511),  INT16_C( 14657), -INT16_C( 17411), -INT16_C( 24491), -INT16_C( 24979), -INT16_C(  5362),  INT16_C(  8739),
         INT16_C( 18021),  INT16_C(  7699), -INT16_C( 12905),  INT16_C( 14640), -INT16_C(  3583), -INT16_C( 22427),  INT16_C( 14992),  INT16_C( 27700),
         INT16_C(  9165),  INT16_C( 10342), -INT16_C( 28358),  INT16_C(  3857), -INT16_C(  1461),  INT16_C(  8727), -INT16_C( 23579), -INT16_C( 11150),
        -INT16_C( 28278),  INT16_C( 14972),  INT16_C(  6453), -INT16_C( 13514),  INT16_C( 13905), -INT16_C( 25593), -INT16_C( 16637),  INT16_C( 26734),
         INT16_C( 14050), -INT16_C(  7041),  INT16_C(  8043),  INT16_C( 24310),  INT16_C( 16267), -INT16_C( 30390),  INT16_C(  5789), -INT16_C( 31877),
        -INT16_C( 14621),  INT16_C( 12530), -INT16_C( 27432),  INT16_C( 21175),  INT16_C( 17306), -INT16_C( 23667), -INT16_C(  6716), -INT16_C(  2951),
         INT16_C( 24713), -INT16_C( 25442),  INT16_C( 31601),  INT16_C( 14086), -INT16_C( 20322), -INT16_C(  9519),  INT16_C( 25569),  INT16_C(  3870),
        -INT16_C(  9444),  INT16_C( 27124),  INT16_C(   543), -INT16_C( 15364),  INT16_C( 32130),  INT16_C( 25677),  INT16_C(  6549),  INT16_C( 14935),
         INT16_C( 29778), -INT16_C( 15268),  INT16_C( 26969),  INT16_C( 11126), -INT16_C( 25906),  INT16_C( 23558), -INT16_C( 19219),  INT16_C( 30001),
         INT16_C( 24743),  INT16_C( 16619),  INT16_C( 11740),  INT16_C( 11670),  INT16_C(  2669),  INT16_C( 31634), -INT16_C(  7299),  INT16_C( 19673) },
      {  INT16_C(     0),        INT16_MIN,        INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C( 32766),       -INT16_MAX,  INT16_C(     0),
               INT16_MAX,        INT16_MAX,  INT16_C(     0), -INT16_C( 32766),  INT16_C( 23125), -INT16_C( 31495),  INT16_C( 19704), -INT16_C( 27683),
         INT16_C( 11950),        INT16_MAX,        INT16_MIN, -INT16_C( 14640),  INT16_C( 22979), -INT16_C( 25567),  INT16_C( 16898), -INT16_C(  1984),
         INT16_C(  2715),        INT16_MIN,  INT16_C( 11850),  INT16_C(  5017), -INT16_C( 14338),  INT16_C( 24438),  INT16_C(  5410), -INT16_C( 32258),
               INT16_MIN,  INT16_C( 10561),  INT16_C( 25632),        INT16_MAX, -INT16_C( 10306), -INT16_C( 31253),  INT16_C( 19042), -INT16_C( 31385),
        -INT16_C(  2146),  INT16_C( 18701),        INT16_MAX, -INT16_C( 16575), -INT16_C( 10287),  INT16_C( 27552),  INT16_C( 10026),        INT16_MAX,
         INT16_C(  3927), -INT16_C( 12033), -INT16_C( 17775), -INT16_C(  2321),        INT16_MAX,        INT16_MAX,  INT16_C( 21600), -INT16_C( 30943),
        -INT16_C( 17068),        INT16_MIN,  INT16_C(  4990), -INT16_C( 19387),  INT16_C( 10573),        INT16_MAX,        INT16_MIN,        INT16_MIN,
         INT16_C( 11682),  INT16_C(  5667),  INT16_C( 20942),  INT16_C( 23723),  INT16_C( 15064),        INT16_MIN, -INT16_C(  3632),  INT16_C( 23571),
         INT16_C( 22739),        INT16_MIN,        INT16_MIN,  INT16_C(  2858),  INT16_C(   572),  INT16_C(  7338),  INT16_C( 16484), -INT16_C(  6592),
        -INT16_C( 24035),  INT16_C( 32702),        INT16_MIN,        INT16_MIN, -INT16_C( 20597),  INT16_C( 25486), -INT16_C(  9131),        INT16_MAX,
         INT16_C( 29051), -INT16_C( 27879),  INT16_C( 14044),        INT16_MIN,        INT16_MIN,  INT16_C( 32688), -INT16_C( 17965),  INT16_C(  8148),
        -INT16_C(  7221),  INT16_C( 31594), -INT16_C( 20573),  INT16_C( 13997),  INT16_C( 29829),        INT16_MAX, -INT16_C(  3760), -INT16_C(  2216),
         INT16_C( 22259),        INT16_MIN, -INT16_C(  4143),  INT16_C( 17375), -INT16_C( 18945), -INT16_C( 25934),  INT16_C( 24215), -INT16_C(  9092),
               INT16_MIN,  INT16_C( 25161), -INT16_C( 29652),        INT16_MIN,  INT16_C( 29763),        INT16_MIN,  INT16_C( 15857), -INT16_C( 32229),
        -INT16_C(  1239),  INT16_C(  7281),  INT16_C( 19974),        INT16_MIN,  INT16_C( 26573),        INT16_MIN, -INT16_C( 12732),        INT16_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vsub_WhWh_sat(a, b);

    simde_test_hvx_vectorpair_i16_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i16_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i16_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vsub_WhWh_sat(a, b);

    simde_test_hvx_vectorpair_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_WwWw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_PAIR_I32_COUNT];
    int32_t b[SIMDE_HVX_PAIR_I32_COUNT];
    int32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(   867329543),  INT32_C(   284077907),  INT32_C(  2127700360),  INT32_C(  1560069051),
         INT32_C(   518184601), -INT32_C(  1074235359),  INT32_C(  1855703127),  INT32_C(   273076220),  INT32_C(  1952513913), -INT32_C(  1959659135), -INT32_C(  1918627845), -INT32_C(   666762432),
         INT32_C(  1588690462),  INT32_C(  1015731738),  INT32_C(   415856846),  INT32_C(   298794534),  INT32_C(  1666910308),  INT32_C(   692918487), -INT32_C(  1140413534),  INT32_C(    62071237),
         INT32_C(  1795319191),  INT32_C(   752437030), -INT32_C(  1907564285), -INT32_C(  2138266864),  INT32_C(   451972542),  INT32_C(  1336989026),  INT32_C(   597489510), -INT32_C(   103046373),
        -INT32_C(   108323681), -INT32_C(  1470413359),  INT32_C(   884648679), -INT32_C(  1986457413), -INT32_C(    63721463), -INT32_C(   259284280),  INT32_C(  1629255159),  INT32_C(  1960052739),
        -INT32_C(   585323314),  INT32_C(  1293529958), -INT32_C(  2055040113), -INT32_C(  1612479448), -INT32_C(   846865396), -INT32_C(   682788495),  INT32_C(   565948769),  INT32_C(  2091059252),
        -INT32_C(   135493592),  INT32_C(  1324185043),  INT32_C(  1528609414), -INT32_C(   331096283),  INT32_C(  1588094729), -INT32_C(  2052509650),  INT32_C(   455037223), -INT32_C(  1726197533) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(  2082549540),  INT32_C(   364290970),  INT32_C(  1964080154),  INT32_C(  1897005493),
         INT32_C(  1219093680), -INT32_C(   237011670),  INT32_C(  1624684541), -INT32_C(   221363266), -INT32_C(  1839084008), -INT32_C(   771382573), -INT32_C(  1468128673), -INT32_C(  1912008070),
        -INT32_C(  1935680035), -INT32_C(   695999794),  INT32_C(   628287237), -INT32_C(   759147501),  INT32_C(  1038379425),  INT32_C(   866795268),  INT32_C(  1036843740),  INT32_C(  1860219023),
        -INT32_C(   589841131), -INT32_C(  1889637831),  INT32_C(  1092412436),  INT32_C(   958626836), -INT32_C(  1985181154),  INT32_C(    84576335), -INT32_C(   514835661), -INT32_C(  1627932406),
        -INT32_C(   512246852),  INT32_C(  1784397865),  INT32_C(   894843056),  INT32_C(   250319777), -INT32_C(   587976398),  INT32_C(  1011354795), -INT32_C(   572065662), -INT32_C(   600251862),
        -INT32_C(  2043287579), -INT32_C(   755969961), -INT32_C(  1242177738),  INT32_C(   382547672),  INT32_C(   415430782),  INT32_C(  1019066633), -INT32_C(  1587238916), -INT32_C(   814617509),
        -INT32_C(   744025655),  INT32_C(  1583177812), -INT32_C(   347239370),  INT32_C(  1718140888),  INT32_C(  1156694483), -INT32_C(  1208077319), -INT32_C(  1064752381),  INT32_C(   942958785) },
      {  INT32_C(           0),              INT32_MIN,              INT32_MAX,  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(           0),
                     INT32_MAX,              INT32_MAX,  INT32_C(           0), -INT32_C(  2147483646), -INT32_C(  1215219997), -INT32_C(    80213063),  INT32_C(   163620206), -INT32_C(   336936442),
        -INT32_C(   700909079), -INT32_C(   837223689),  INT32_C(   231018586),  INT32_C(   494439486),              INT32_MAX, -INT32_C(  1188276562), -INT32_C(   450499172),  INT32_C(  1245245638),
                     INT32_MAX,  INT32_C(  1711731532), -INT32_C(   212430391),  INT32_C(  1057942035),  INT32_C(   628530883), -INT32_C(   173876781),              INT32_MIN, -INT32_C(  1798147786),
                     INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MIN,              INT32_MAX,  INT32_C(  1252412691),  INT32_C(  1112325171),  INT32_C(  1524886033),
         INT32_C(   403923171),              INT32_MIN, -INT32_C(    10194377),              INT32_MIN,  INT32_C(   524254935), -INT32_C(  1270639075),              INT32_MAX,              INT32_MAX,
         INT32_C(  1457964265),  INT32_C(  2049499919), -INT32_C(   812862375), -INT32_C(  1995027120), -INT32_C(  1262296178), -INT32_C(  1701855128),              INT32_MAX,              INT32_MAX,
         INT32_C(   608532063), -INT32_C(   258992769),  INT32_C(  1875848784), -INT32_C(  2049237171),  INT32_C(   431400246), -INT32_C(   844432331),  INT32_C(  1519789604),              INT32_MIN } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(  2029440682), -INT32_C(  1262067620), -INT32_C(  1352846818), -INT32_C(  1774926346),
         INT32_C(  1958370095),  INT32_C(   689916629), -INT32_C(  1270039379), -INT32_C(   292164279), -INT32_C(   347914052),  INT32_C(  1820797425), -INT32_C(  2139944799),  INT32_C(  1430473818),
         INT32_C(   892599193), -INT32_C(  2001152595), -INT32_C(  1740817179),  INT32_C(   541763863), -INT32_C(   344069657),  INT32_C(   755180076),  INT32_C(   878702905),  INT32_C(    12552108),
        -INT32_C(  1421659535),  INT32_C(  1657585342), -INT32_C(   126264282),  INT32_C(  1735161259),  INT32_C(   790140594), -INT32_C(   279159545), -INT32_C(   907861507),  INT32_C(  1419865866),
         INT32_C(  1010673565), -INT32_C(    58875716),  INT32_C(   925781320),  INT32_C(   629191304), -INT32_C(   465772126),  INT32_C(  1701070985), -INT32_C(   137889731), -INT32_C(   714953747),
        -INT32_C(  1552011409),  INT32_C(  1248735114),  INT32_C(     5637811),  INT32_C(   852056997), -INT32_C(   884058639),  INT32_C(  1293976810), -INT32_C(  1354722031), -INT32_C(  1973892549),
        -INT32_C(   776160748),  INT32_C(   168022558), -INT32_C(  1914662982),  INT32_C(  1315307572), -INT32_C(   553312320),  INT32_C(  1203979578),  INT32_C(   585489786),  INT32_C(   697630405) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX, -INT32_C(   341242675), -INT32_C(   888828017), -INT32_C(  1174167672),  INT32_C(   646871586),
         INT32_C(  1528403108), -INT32_C(  1693685416), -INT32_C(  1281787273),  INT32_C(  1945623358), -INT32_C(  1340495403),  INT32_C(  1643545037), -INT32_C(  1863571856),  INT32_C(   838264320),
         INT32_C(  2098049569), -INT32_C(  1294431768), -INT32_C(  1579015108),  INT32_C(   363206736),  INT32_C(   131295969),  INT32_C(  1324875326),  INT32_C(   121767458),  INT32_C(  1781835706),
         INT32_C(  1820339123),  INT32_C(   858810596), -INT32_C(   784988990), -INT32_C(   780650639),  INT32_C(   360717922),  INT32_C(  1872813684),  INT32_C(   821570028),  INT32_C(  2023395635),
         INT32_C(   146068104),  INT32_C(   355030194),  INT32_C(  1127264500),  INT32_C(  1111941512), -INT32_C(  1964001155), -INT32_C(   113890489), -INT32_C(   277020150),  INT32_C(  1777401316),
        -INT32_C(  1670642451), -INT32_C(  1722381534),  INT32_C(  1538185735),  INT32_C(   345976868), -INT32_C(   945129532), -INT32_C(  1037632010),  INT32_C(  2015893055),  INT32_C(  1657866215),
        -INT32_C(   985952571),  INT32_C(  1660998735),  INT32_C(   586981327),  INT32_C(  1894034506),  INT32_C(  2080478059),  INT32_C(   486986705),  INT32_C(  1479019240), -INT32_C(   829406596) },
      {  INT32_C(           0),              INT32_MIN,              INT32_MAX,  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(  2147483646), -INT32_C(  2147483647),  INT32_C(           0),
                     INT32_MAX,              INT32_MAX,  INT32_C(           0), -INT32_C(  2147483646),              INT32_MAX, -INT32_C(   373239603), -INT32_C(   178679146),              INT32_MIN,
         INT32_C(   429966987),              INT32_MAX,  INT32_C(    11747894),              INT32_MIN,  INT32_C(   992581351),  INT32_C(   177252388), -INT32_C(   276372943),  INT32_C(   592209498),
        -INT32_C(  1205450376), -INT32_C(   706720827), -INT32_C(   161802071),  INT32_C(   178557127), -INT32_C(   475365626), -INT32_C(   569695250),  INT32_C(   756935447), -INT32_C(  1769283598),
                     INT32_MIN,  INT32_C(   798774746),  INT32_C(   658724708),              INT32_MAX,  INT32_C(   429422672),              INT32_MIN, -INT32_C(  1729431535), -INT32_C(   603529769),
         INT32_C(   864605461), -INT32_C(   413905910), -INT32_C(   201483180), -INT32_C(   482750208),  INT32_C(  1498229029),  INT32_C(  1814961474),  INT32_C(   139130419),              INT32_MIN,
         INT32_C(   118631042),              INT32_MAX, -INT32_C(  1532547924),  INT32_C(   506080129),  INT32_C(    61070893),              INT32_MAX,              INT32_MIN,              INT32_MIN,
         INT32_C(   209791823), -INT32_C(  1492976177),              INT32_MIN, -INT32_C(   578726934),              INT32_MIN,  INT32_C(   716992873), -INT32_C(   893529454),  INT32_C(  1527037001) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vsub_WwWw_sat(a, b);

    simde_test_hvx_vectorpair_i32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i32_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i32_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vsub_WwWw_sat(a, b);

    simde_test_hvx_vectorpair_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_WubWub_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[SIMDE_HVX_PAIR_SIZE];
    uint8_t b[SIMDE_HVX_PAIR_SIZE];
    uint8_t r[SIMDE_HVX_PAIR_SIZE];
  } test_vec[] = {
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(182), UINT8_C(197), UINT8_C(239), UINT8_C(242),
           UINT8_MAX, UINT8_C(100), UINT8_C(158), UINT8_C(206), UINT8_C( 96), UINT8_C(112), UINT8_C( 20), UINT8_C( 38),
        UINT8_C(152), UINT8_C( 44), UINT8_C(242), UINT8_C(241), UINT8_C( 14), UINT8_C(249), UINT8_C(146), UINT8_C( 24),
        UINT8_C(155), UINT8_C( 30), UINT8_C(218), UINT8_C(164), UINT8_C(183), UINT8_C(151), UINT8_C(141), UINT8_C( 30),
        UINT8_C(131), UINT8_C(183), UINT8_C(  9), UINT8_C( 36), UINT8_C(167), UINT8_C(208), UINT8_C( 40), UINT8_C( 31),
        UINT8_C(160), UINT8_C( 19), UINT8_C(142), UINT8_C(249), UINT8_C( 10), UINT8_C( 53), UINT8_C( 54), UINT8_C(151),
        UINT8_C( 41), UINT8_C(128), UINT8_C( 48), UINT8_C(134), UINT8_C(192), UINT8_C(232), UINT8_C( 45), UINT8_C(216),
        UINT8_C(131), UINT8_C( 61), UINT8_C(169), UINT8_C( 26), UINT8_C(200), UINT8_C(201), UINT8_C(217), UINT8_C(217),
        UINT8_C( 76), UINT8_C(241), UINT8_C( 56), UINT8_C(  0), UINT8_C( 35), UINT8_C(127), UINT8_C( 44), UINT8_C( 80),
        UINT8_C(178), UINT8_C(191), UINT8_C(212), UINT8_C(115), UINT8_C( 58), UINT8_C(252), UINT8_C(118), UINT8_C( 30),
        UINT8_C( 91), UINT8_C( 70), UINT8_C( 50), UINT8_C(180), UINT8_C(110), UINT8_C(119), UINT8_C( 11), UINT8_C(137),
        UINT8_C( 34), UINT8_C( 62), UINT8_C(173), UINT8_C(236), UINT8_C(144), UINT8_C( 52), UINT8_C(114), UINT8_C( 22),
        UINT8_C(181), UINT8_C(172), UINT8_C(247), UINT8_C(211), UINT8_C(190), UINT8_C(220), UINT8_C(233), UINT8_C( 46),
        UINT8_C( 27), UINT8_C( 44), UINT8_C(117), UINT8_C(144), UINT8_C(  9), UINT8_C(114), UINT8_C(  3), UINT8_C( 43),
        UINT8_C(226), UINT8_C( 12), UINT8_C(218), UINT8_C(126), UINT8_C( 54), UINT8_C(115), UINT8_C(  5), UINT8_C(187),
        UINT8_C(198), UINT8_C(110), UINT8_C(171), UINT8_C( 17), UINT8_C(182), UINT8_C(235), UINT8_C(115), UINT8_C(238),
        UINT8_C( 79), UINT8_C(245), UINT8_C(  6), UINT8_C( 73), UINT8_C(227), UINT8_C(200), UINT8_C( 58), UINT8_C(158),
        UINT8_C(244), UINT8_C(238), UINT8_C( 12), UINT8_C(162), UINT8_C( 98), UINT8_C(245), UINT8_C(176), UINT8_C( 71),
        UINT8_C(  4), UINT8_C( 52), UINT8_C( 14), UINT8_C(201), UINT8_C(128), UINT8_C( 77), UINT8_C(131), UINT8_C(199),
        UINT8_C(163), UINT8_C(144), UINT8_C(147), UINT8_C(163), UINT8_C( 20), UINT8_C(173), UINT8_C(167), UINT8_C(206),
        UINT8_C(217), UINT8_C(134), UINT8_C( 43), UINT8_C(195), UINT8_C(151), UINT8_C(243), UINT8_C( 13), UINT8_C( 56),
        UINT8_C(196), UINT8_C( 16), UINT8_C(212), UINT8_C(162), UINT8_C(173), UINT8_C(237), UINT8_C(242), UINT8_C(229),
        UINT8_C(172), UINT8_C(  0), UINT8_C(165), UINT8_C(100), UINT8_C(131), UINT8_C(210), UINT8_C( 92), UINT8_C(  1),
        UINT8_C(192), UINT8_C( 68), UINT8_C( 81), UINT8_C( 62), UINT8_C( 38), UINT8_C(  1), UINT8_C( 77), UINT8_C(  4),
        UINT8_C( 17), UINT8_C(141), UINT8_C(233), UINT8_C( 28), UINT8_C(200), UINT8_C( 85), UINT8_C(250), UINT8_C( 57),
        UINT8_C( 54), UINT8_C( 68), UINT8_C( 56), UINT8_C( 77), UINT8_C(240), UINT8_C(166), UINT8_C( 96), UINT8_C(184),
        UINT8_C(  3), UINT8_C( 31), UINT8_C(214), UINT8_C(135), UINT8_C( 80), UINT8_C(104), UINT8_C( 53), UINT8_C(107),
        UINT8_C(121), UINT8_C(248), UINT8_C( 20), UINT8_C(232), UINT8_C(234), UINT8_C(207), UINT8_C( 84), UINT8_C(217),
        UINT8_C( 16), UINT8_C(251), UINT8_C(169), UINT8_C(237), UINT8_C(  8), UINT8_C( 47), UINT8_C(105), UINT8_C(246),
        UINT8_C( 78), UINT8_C(140), UINT8_C(228), UINT8_C(199), UINT8_C(124), UINT8_C(173), UINT8_C(179), UINT8_C(127),
        UINT8_C(134), UINT8_C(182), UINT8_C( 39), UINT8_C(218), UINT8_C( 84), UINT8_C(197), UINT8_C( 94), UINT8_C(232) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(225), UINT8_C(127), UINT8_C( 45), UINT8_C(206),
        UINT8_C( 36), UINT8_C( 99), UINT8_C( 83), UINT8_C(197), UINT8_C( 16), UINT8_C(169), UINT8_C( 65), UINT8_C( 96),
        UINT8_C(157), UINT8_C(234), UINT8_C(224), UINT8_C(245), UINT8_C( 97), UINT8_C( 49), UINT8_C( 53), UINT8_C(242),
        UINT8_C(240), UINT8_C(  1), UINT8_C( 57), UINT8_C( 88), UINT8_C(  8), UINT8_C(143), UINT8_C(180), UINT8_C( 62),
        UINT8_C(  7), UINT8_C(211), UINT8_C(245), UINT8_C( 19), UINT8_C(146), UINT8_C(  1), UINT8_C(162), UINT8_C(158),
        UINT8_C( 21), UINT8_C(106), UINT8_C(221), UINT8_C( 40), UINT8_C(132), UINT8_C(185), UINT8_C(  1), UINT8_C(184),
        UINT8_C(181), UINT8_C(239), UINT8_C(242), UINT8_C( 99), UINT8_C( 54), UINT8_C( 58), UINT8_C(254), UINT8_C(199),
        UINT8_C( 28), UINT8_C(101), UINT8_C( 47), UINT8_C( 41), UINT8_C( 24), UINT8_C(181), UINT8_C(153), UINT8_C(218),
        UINT8_C(252), UINT8_C(132), UINT8_C(131), UINT8_C(161), UINT8_C( 91), UINT8_C(166), UINT8_C( 81), UINT8_C(181),
        UINT8_C(130), UINT8_C(149), UINT8_C( 70), UINT8_C( 35), UINT8_C(234), UINT8_C( 75), UINT8_C(  8), UINT8_C(106),
        UINT8_C(208), UINT8_C(143), UINT8_C(109), UINT8_C( 40), UINT8_C(134), UINT8_C(242), UINT8_C( 76), UINT8_C( 32),
        UINT8_C( 40), UINT8_C( 57), UINT8_C(115), UINT8_C(104), UINT8_C(150), UINT8_C(112), UINT8_C(247), UINT8_C(210),
        UINT8_C(221), UINT8_C( 67), UINT8_C(245), UINT8_C( 31), UINT8_C( 65), UINT8_C(145), UINT8_C( 10), UINT8_C( 68),
           UINT8_MAX, UINT8_C(208), UINT8_C(209), UINT8_C(224), UINT8_C( 59), UINT8_C(124), UINT8_C(132), UINT8_C(186),
        UINT8_C(164), UINT8_C( 54), UINT8_C(109), UINT8_C(193), UINT8_C(126), UINT8_C(171), UINT8_C(214), UINT8_C(102),
        UINT8_C(114), UINT8_C( 35), UINT8_C(191), UINT8_C(237), UINT8_C( 33), UINT8_C( 45), UINT8_C( 98), UINT8_C(222),
        UINT8_C( 23), UINT8_C(170), UINT8_C(124), UINT8_C( 61), UINT8_C( 91), UINT8_C(144), UINT8_C(133), UINT8_C( 85),
        UINT8_C( 16), UINT8_C( 50), UINT8_C(200), UINT8_C(161), UINT8_C(123), UINT8_C(237), UINT8_C( 68), UINT8_C(152),
        UINT8_C( 45), UINT8_C(128), UINT8_C(135), UINT8_C(167), UINT8_C(202), UINT8_C( 48), UINT8_C(220), UINT8_C( 94),
        UINT8_C(241), UINT8_C(146), UINT8_C(116), UINT8_C(204), UINT8_C(203), UINT8_C(220), UINT8_C( 29), UINT8_C(158),
        UINT8_C(251), UINT8_C( 85), UINT8_C(207), UINT8_C(128), UINT8_C(143), UINT8_C( 27), UINT8_C(130), UINT8_C( 57),
        UINT8_C( 92), UINT8_C(161), UINT8_C(145), UINT8_C( 97), UINT8_C( 97), UINT8_C( 36), UINT8_C(173), UINT8_C(121),
        UINT8_C(197), UINT8_C( 63), UINT8_C(187), UINT8_C( 85), UINT8_C( 33), UINT8_C(131), UINT8_C(  4), UINT8_C(101),
        UINT8_C( 43), UINT8_C( 47), UINT8_C( 97), UINT8_C(178), UINT8_C(121), UINT8_C( 13), UINT8_C(213), UINT8_C( 47),
        UINT8_C(146), UINT8_C(177), UINT8_C(211), UINT8_C(248), UINT8_C(228), UINT8_C(202), UINT8_C(102), UINT8_C(129),
        UINT8_C(103), UINT8_C(  1), UINT8_C( 59), UINT8_C(252), UINT8_C(122), UINT8_C( 97), UINT8_C( 64), UINT8_C(166),
        UINT8_C(188), UINT8_C(  9), UINT8_C(225), UINT8_C(199), UINT8_C( 72), UINT8_C( 18), UINT8_C(188), UINT8_C( 26),
        UINT8_C(173), UINT8_C(195), UINT8_C( 23), UINT8_C(208), UINT8_C(206), UINT8_C(138), UINT8_C(221), UINT8_C( 60),
        UINT8_C(249), UINT8_C( 65), UINT8_C(204), UINT8_C(142), UINT8_C( 64), UINT8_C( 84), UINT8_C( 91), UINT8_C(107),
        UINT8_C(198), UINT8_C(220), UINT8_C(139), UINT8_C(205), UINT8_C(217),    UINT8_MAX, UINT8_C(151), UINT8_C( 18),
        UINT8_C(110), UINT8_C( 68), UINT8_C(151), UINT8_C(127), UINT8_C(154), UINT8_C(122), UINT8_C( 18), UINT8_C(152) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(254), UINT8_C(  0), UINT8_C(254), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 70), UINT8_C(194), UINT8_C( 36),
        UINT8_C(219), UINT8_C(  1), UINT8_C( 75), UINT8_C(  9), UINT8_C( 80), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 18), UINT8_C(  0), UINT8_C(  0), UINT8_C(200), UINT8_C( 93), UINT8_C(  0),
        UINT8_C(  0), UINT8_C( 29), UINT8_C(161), UINT8_C( 76), UINT8_C(175), UINT8_C(  8), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(124), UINT8_C(  0), UINT8_C(  0), UINT8_C( 17), UINT8_C( 21), UINT8_C(207), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(139), UINT8_C(  0), UINT8_C(  0), UINT8_C(209), UINT8_C(  0), UINT8_C(  0), UINT8_C( 53), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 35), UINT8_C(138), UINT8_C(174), UINT8_C(  0), UINT8_C( 17),
        UINT8_C(103), UINT8_C(  0), UINT8_C(122), UINT8_C(  0), UINT8_C(176), UINT8_C( 20), UINT8_C( 64), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(109), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C( 48), UINT8_C( 42), UINT8_C(142), UINT8_C( 80), UINT8_C(  0), UINT8_C(177), UINT8_C(110), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(140), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(105),
        UINT8_C(  0), UINT8_C(  5), UINT8_C( 58), UINT8_C(132), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(105), UINT8_C(  2), UINT8_C(180), UINT8_C(125), UINT8_C( 75), UINT8_C(223), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C( 62), UINT8_C(  0), UINT8_C(109), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 85),
        UINT8_C( 84), UINT8_C( 75), UINT8_C(  0), UINT8_C(  0), UINT8_C(149), UINT8_C(190), UINT8_C( 17), UINT8_C( 16),
        UINT8_C( 56), UINT8_C( 75), UINT8_C(  0), UINT8_C( 12), UINT8_C(136), UINT8_C( 56), UINT8_C(  0), UINT8_C( 73),
        UINT8_C(228), UINT8_C(188), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  8), UINT8_C(108), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 34), UINT8_C(  0), UINT8_C( 29), UINT8_C(  0), UINT8_C(105),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 31), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(138), UINT8_C( 48),
        UINT8_C(  0), UINT8_C( 49), UINT8_C(  0), UINT8_C( 67), UINT8_C(  8), UINT8_C(216), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(104), UINT8_C(  0), UINT8_C( 67), UINT8_C( 65), UINT8_C( 76), UINT8_C(201), UINT8_C( 69), UINT8_C(108),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 15), UINT8_C( 98), UINT8_C( 79), UINT8_C( 88), UINT8_C(  0),
        UINT8_C(149), UINT8_C( 21), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 22), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(148), UINT8_C(  0),
        UINT8_C(  0), UINT8_C( 67), UINT8_C(  0), UINT8_C(  0), UINT8_C(118), UINT8_C( 69), UINT8_C( 32), UINT8_C( 18),
        UINT8_C(  0), UINT8_C( 22), UINT8_C(  0), UINT8_C(  0), UINT8_C(  8), UINT8_C( 86), UINT8_C(  0), UINT8_C( 81),
        UINT8_C(  0), UINT8_C( 53), UINT8_C(  0), UINT8_C( 24), UINT8_C( 28), UINT8_C( 69), UINT8_C(  0), UINT8_C(157),
        UINT8_C(  0), UINT8_C(186), UINT8_C(  0), UINT8_C( 95), UINT8_C(  0), UINT8_C(  0), UINT8_C( 14), UINT8_C(139),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 89), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 28), UINT8_C(109),
        UINT8_C( 24), UINT8_C(114), UINT8_C(  0), UINT8_C( 91), UINT8_C(  0), UINT8_C( 75), UINT8_C( 76), UINT8_C( 80) } },
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(181), UINT8_C(  7), UINT8_C(240), UINT8_C(219),
        UINT8_C(217), UINT8_C(145), UINT8_C(143), UINT8_C(213), UINT8_C( 53), UINT8_C( 75), UINT8_C(227), UINT8_C(170),
        UINT8_C(218), UINT8_C(174), UINT8_C(181), UINT8_C( 11), UINT8_C( 17), UINT8_C(187), UINT8_C( 27), UINT8_C( 39),
        UINT8_C( 49), UINT8_C(167), UINT8_C( 58), UINT8_C(189), UINT8_C(150), UINT8_C(217), UINT8_C(124), UINT8_C( 54),
        UINT8_C(127), UINT8_C(207), UINT8_C( 52), UINT8_C(232), UINT8_C( 69), UINT8_C(198), UINT8_C( 53), UINT8_C(198),
        UINT8_C(  1), UINT8_C(252), UINT8_C(170), UINT8_C( 91), UINT8_C(147), UINT8_C(224), UINT8_C(235), UINT8_C( 42),
        UINT8_C(188), UINT8_C(105), UINT8_C( 53), UINT8_C(  0), UINT8_C(201), UINT8_C(248), UINT8_C(205), UINT8_C(107),
        UINT8_C(160), UINT8_C(122), UINT8_C( 79), UINT8_C(100), UINT8_C( 31), UINT8_C(217), UINT8_C( 65), UINT8_C(240),
        UINT8_C( 55), UINT8_C(245), UINT8_C(181), UINT8_C(253), UINT8_C( 41), UINT8_C(128), UINT8_C( 94), UINT8_C( 48),
        UINT8_C( 84), UINT8_C(160), UINT8_C( 34), UINT8_C( 18), UINT8_C(112), UINT8_C(131), UINT8_C(140), UINT8_C(114),
        UINT8_C( 29), UINT8_C(137), UINT8_C(167), UINT8_C(135), UINT8_C( 10), UINT8_C(173), UINT8_C( 95), UINT8_C( 29),
        UINT8_C(162), UINT8_C(159), UINT8_C(159), UINT8_C( 56), UINT8_C(202), UINT8_C( 53), UINT8_C(180), UINT8_C(103),
        UINT8_C( 31), UINT8_C(183), UINT8_C( 48), UINT8_C(214), UINT8_C(153), UINT8_C( 49), UINT8_C(223), UINT8_C(148),
        UINT8_C(218), UINT8_C( 88), UINT8_C( 51), UINT8_C(182), UINT8_C(100), UINT8_C(123), UINT8_C(184), UINT8_C( 82),
        UINT8_C(113), UINT8_C( 26), UINT8_C( 32), UINT8_C( 87), UINT8_C(207), UINT8_C(113), UINT8_C( 42), UINT8_C( 59),
        UINT8_C( 97), UINT8_C(208), UINT8_C(154), UINT8_C(179), UINT8_C(243), UINT8_C(114), UINT8_C(168), UINT8_C(176),
        UINT8_C( 64), UINT8_C(252), UINT8_C( 12), UINT8_C(237), UINT8_C( 21), UINT8_C( 86), UINT8_C( 10), UINT8_C(221),
        UINT8_C( 61), UINT8_C(121), UINT8_C(156), UINT8_C( 57), UINT8_C( 74), UINT8_C(113), UINT8_C(246), UINT8_C(230),
        UINT8_C( 44), UINT8_C(175), UINT8_C(165), UINT8_C( 63), UINT8_C(203), UINT8_C( 41), UINT8_C(  5), UINT8_C(187),
        UINT8_C( 89), UINT8_C(237), UINT8_C(206), UINT8_C(161), UINT8_C(159), UINT8_C(114), UINT8_C(148), UINT8_C( 95),
        UINT8_C( 61), UINT8_C(  4), UINT8_C(170), UINT8_C(164), UINT8_C( 39), UINT8_C(237), UINT8_C( 52), UINT8_C(217),
        UINT8_C(  8), UINT8_C(133), UINT8_C(172), UINT8_C( 91), UINT8_C(233), UINT8_C(198), UINT8_C( 94), UINT8_C( 98),
        UINT8_C(215), UINT8_C(107), UINT8_C( 30), UINT8_C( 35), UINT8_C(243), UINT8_C(200), UINT8_C( 37), UINT8_C(191),
        UINT8_C( 77), UINT8_C( 98), UINT8_C(178), UINT8_C(131), UINT8_C(224), UINT8_C(140), UINT8_C( 82), UINT8_C( 30),
        UINT8_C( 43), UINT8_C( 55), UINT8_C( 21), UINT8_C(  5), UINT8_C(173), UINT8_C(238), UINT8_C( 76), UINT8_C( 43),
        UINT8_C( 86), UINT8_C( 81), UINT8_C(212), UINT8_C(213), UINT8_C( 25), UINT8_C(113), UINT8_C( 25), UINT8_C(105),
        UINT8_C(168), UINT8_C(141), UINT8_C(195), UINT8_C(132), UINT8_C(128), UINT8_C(140), UINT8_C(126), UINT8_C( 69),
        UINT8_C(191), UINT8_C( 26), UINT8_C(244), UINT8_C(114), UINT8_C(189), UINT8_C( 47), UINT8_C( 91), UINT8_C(188),
        UINT8_C(232), UINT8_C(110), UINT8_C( 46), UINT8_C(  7), UINT8_C(160), UINT8_C( 70), UINT8_C(  1), UINT8_C(188),
        UINT8_C( 14), UINT8_C(179), UINT8_C(181), UINT8_C(250), UINT8_C(105), UINT8_C( 90), UINT8_C( 98), UINT8_C(221),
        UINT8_C(155), UINT8_C(121), UINT8_C( 13), UINT8_C(128), UINT8_C(126), UINT8_C(177), UINT8_C(161), UINT8_C( 95) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C( 93), UINT8_C( 85), UINT8_C( 92), UINT8_C(176),
        UINT8_C(152), UINT8_C(172), UINT8_C(174), UINT8_C(215), UINT8_C( 73), UINT8_C( 50), UINT8_C(  4), UINT8_C( 53),
        UINT8_C(  5), UINT8_C( 71), UINT8_C( 34), UINT8_C( 88), UINT8_C(202), UINT8_C(181), UINT8_C( 23), UINT8_C(227),
        UINT8_C( 49), UINT8_C( 83), UINT8_C(195), UINT8_C(162), UINT8_C( 26), UINT8_C( 54), UINT8_C( 91), UINT8_C(141),
        UINT8_C(189), UINT8_C(193), UINT8_C(199), UINT8_C(126), UINT8_C(103), UINT8_C(226), UINT8_C(225), UINT8_C(219),
        UINT8_C( 22), UINT8_C( 16), UINT8_C(236), UINT8_C(217), UINT8_C(175), UINT8_C(210), UINT8_C( 88), UINT8_C( 77),
        UINT8_C(177), UINT8_C(201), UINT8_C(198), UINT8_C(110), UINT8_C(159), UINT8_C( 11), UINT8_C( 71), UINT8_C(157),
        UINT8_C( 32), UINT8_C( 75), UINT8_C(141), UINT8_C(  6), UINT8_C(144), UINT8_C( 66), UINT8_C(164), UINT8_C(208),
        UINT8_C(141), UINT8_C(101), UINT8_C(234), UINT8_C(217), UINT8_C(177), UINT8_C(157), UINT8_C( 48), UINT8_C(177),
        UINT8_C( 24), UINT8_C(183), UINT8_C(249), UINT8_C(239), UINT8_C( 63), UINT8_C( 20), UINT8_C(196), UINT8_C(190),
        UINT8_C(112), UINT8_C( 27), UINT8_C(200), UINT8_C(205), UINT8_C(156), UINT8_C( 94), UINT8_C(207), UINT8_C(  4),
        UINT8_C(220), UINT8_C(201), UINT8_C( 80), UINT8_C(  3), UINT8_C(220), UINT8_C(219), UINT8_C(219), UINT8_C(182),
        UINT8_C(201), UINT8_C( 54), UINT8_C(225), UINT8_C(170), UINT8_C(102), UINT8_C( 25), UINT8_C( 30), UINT8_C(184),
        UINT8_C(213), UINT8_C( 35), UINT8_C(203), UINT8_C( 46), UINT8_C(242), UINT8_C( 45), UINT8_C(189), UINT8_C(169),
        UINT8_C( 52), UINT8_C(169), UINT8_C(246), UINT8_C( 40), UINT8_C( 72), UINT8_C( 70), UINT8_C(103), UINT8_C(108),
        UINT8_C( 28), UINT8_C( 92), UINT8_C(246), UINT8_C(117), UINT8_C(215), UINT8_C( 94), UINT8_C(209), UINT8_C(112),
        UINT8_C(212), UINT8_C( 36), UINT8_C(  8), UINT8_C(244), UINT8_C( 46), UINT8_C( 65), UINT8_C( 93), UINT8_C(126),
        UINT8_C(227), UINT8_C(175), UINT8_C( 83), UINT8_C(242), UINT8_C( 58), UINT8_C(137), UINT8_C( 64), UINT8_C( 18),
        UINT8_C(168), UINT8_C(191), UINT8_C(134), UINT8_C( 98), UINT8_C( 29), UINT8_C(131), UINT8_C( 63), UINT8_C(187),
        UINT8_C(159), UINT8_C( 18), UINT8_C(248), UINT8_C(162), UINT8_C( 58), UINT8_C( 93), UINT8_C(243), UINT8_C( 72),
        UINT8_C(100), UINT8_C(215), UINT8_C( 44), UINT8_C(184), UINT8_C(246), UINT8_C( 92), UINT8_C(145), UINT8_C( 12),
        UINT8_C(107), UINT8_C( 52), UINT8_C(139), UINT8_C(132), UINT8_C(174), UINT8_C( 41), UINT8_C(217), UINT8_C(175),
        UINT8_C( 68), UINT8_C(143), UINT8_C(  9), UINT8_C(140), UINT8_C( 14), UINT8_C(189), UINT8_C(218), UINT8_C(151),
        UINT8_C( 40), UINT8_C(222), UINT8_C( 54), UINT8_C(156), UINT8_C(  1), UINT8_C(187), UINT8_C(  7), UINT8_C( 52),
        UINT8_C( 91), UINT8_C(114), UINT8_C( 59), UINT8_C(184), UINT8_C( 53), UINT8_C(128), UINT8_C(247), UINT8_C(214),
        UINT8_C(226), UINT8_C( 59), UINT8_C(  6), UINT8_C( 58), UINT8_C( 45), UINT8_C(120), UINT8_C( 26), UINT8_C( 57),
        UINT8_C(229), UINT8_C(192), UINT8_C(214), UINT8_C(105), UINT8_C(139), UINT8_C(186), UINT8_C(117), UINT8_C( 33),
        UINT8_C(237), UINT8_C(135), UINT8_C( 59), UINT8_C( 39), UINT8_C( 88), UINT8_C( 68), UINT8_C(110), UINT8_C(233),
        UINT8_C( 23), UINT8_C(225), UINT8_C(116), UINT8_C(187), UINT8_C(185), UINT8_C(146), UINT8_C(128), UINT8_C( 50),
        UINT8_C( 64), UINT8_C(163),    UINT8_MAX, UINT8_C( 27), UINT8_C(136), UINT8_C(170), UINT8_C(160), UINT8_C( 69),
        UINT8_C(230), UINT8_C(120), UINT8_C(254), UINT8_C(116), UINT8_C( 12), UINT8_C( 28), UINT8_C(222), UINT8_C( 30) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(254), UINT8_C(  0), UINT8_C(254), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C( 88), UINT8_C(  0), UINT8_C(148), UINT8_C( 43),
        UINT8_C( 65), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 25), UINT8_C(223), UINT8_C(117),
        UINT8_C(213), UINT8_C(103), UINT8_C(147), UINT8_C(  0), UINT8_C(  0), UINT8_C(  6), UINT8_C(  4), UINT8_C(  0),
        UINT8_C(  0), UINT8_C( 84), UINT8_C(  0), UINT8_C( 27), UINT8_C(124), UINT8_C(163), UINT8_C( 33), UINT8_C(  0),
        UINT8_C(  0), UINT8_C( 14), UINT8_C(  0), UINT8_C(106), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(236), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 14), UINT8_C(147), UINT8_C(  0),
        UINT8_C( 11), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 42), UINT8_C(237), UINT8_C(134), UINT8_C(  0),
        UINT8_C(128), UINT8_C( 47), UINT8_C(  0), UINT8_C( 94), UINT8_C(  0), UINT8_C(151), UINT8_C(  0), UINT8_C( 32),
        UINT8_C(  0), UINT8_C(144), UINT8_C(  0), UINT8_C( 36), UINT8_C(  0), UINT8_C(  0), UINT8_C( 46), UINT8_C(  0),
        UINT8_C( 60), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 49), UINT8_C(111), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(110), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 79), UINT8_C(  0), UINT8_C( 25),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 79), UINT8_C( 53), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(129), UINT8_C(  0), UINT8_C( 44), UINT8_C( 51), UINT8_C( 24), UINT8_C(193), UINT8_C(  0),
        UINT8_C(  5), UINT8_C( 53), UINT8_C(  0), UINT8_C(136), UINT8_C(  0), UINT8_C( 78), UINT8_C(  0), UINT8_C(  0),
        UINT8_C( 61), UINT8_C(  0), UINT8_C(  0), UINT8_C( 47), UINT8_C(135), UINT8_C( 43), UINT8_C(  0), UINT8_C(  0),
        UINT8_C( 69), UINT8_C(116), UINT8_C(  0), UINT8_C( 62), UINT8_C( 28), UINT8_C( 20), UINT8_C(  0), UINT8_C( 64),
        UINT8_C(  0), UINT8_C(216), UINT8_C(  4), UINT8_C(  0), UINT8_C(  0), UINT8_C( 21), UINT8_C(  0), UINT8_C( 95),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 73), UINT8_C(  0), UINT8_C( 16), UINT8_C(  0), UINT8_C(182), UINT8_C(212),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 31), UINT8_C(  0), UINT8_C(174), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(219), UINT8_C(  0), UINT8_C(  0), UINT8_C(101), UINT8_C( 21), UINT8_C(  0), UINT8_C( 23),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(126), UINT8_C(  0), UINT8_C(  0), UINT8_C(145), UINT8_C(  0), UINT8_C(205),
        UINT8_C(  0), UINT8_C( 81), UINT8_C( 33), UINT8_C(  0), UINT8_C( 59), UINT8_C(157), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(147), UINT8_C(  0), UINT8_C( 21), UINT8_C(  0), UINT8_C(229), UINT8_C( 11), UINT8_C(  0), UINT8_C( 40),
        UINT8_C( 37), UINT8_C(  0), UINT8_C(124), UINT8_C(  0), UINT8_C(223), UINT8_C(  0), UINT8_C( 75), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(120), UINT8_C(110), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C( 22), UINT8_C(206), UINT8_C(155), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 48),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 27), UINT8_C(  0), UINT8_C(  0), UINT8_C(  9), UINT8_C( 36),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(185), UINT8_C( 75), UINT8_C(101), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(209), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(138),
        UINT8_C(  0), UINT8_C( 16), UINT8_C(  0), UINT8_C(223), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(152),
        UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C( 12), UINT8_C(114), UINT8_C(149), UINT8_C(  0), UINT8_C( 65) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wub_vsub_WubWub_sat(a, b);

    simde_test_hvx_vectorpair_u8_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_u8_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_u8_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wub_vsub_WubWub_sat(a, b);

    simde_test_hvx_vectorpair_u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_u8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_u8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_WuhWuh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[SIMDE_HVX_PAIR_I16_COUNT];
    uint16_t b[SIMDE_HVX_PAIR_I16_COUNT];
    uint16_t r[SIMDE_HVX_PAIR_I16_COUNT];
  } test_vec[] = {
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(59060), UINT16_C(24505), UINT16_C(39700), UINT16_C(46551),
        UINT16_C(42663), UINT16_C(13981), UINT16_C(50221), UINT16_C(11690), UINT16_C( 8055), UINT16_C( 3211), UINT16_C(30848), UINT16_C(32899),
        UINT16_C(20455), UINT16_C(17529), UINT16_C( 5422), UINT16_C(57231), UINT16_C(19687), UINT16_C( 6994), UINT16_C(48830), UINT16_C(38647),
        UINT16_C( 2190), UINT16_C(43340), UINT16_C(23809), UINT16_C(36469), UINT16_C(22382), UINT16_C(22812), UINT16_C(60663), UINT16_C(34431),
        UINT16_C( 3484), UINT16_C(52030), UINT16_C(53674), UINT16_C(14675), UINT16_C(36567), UINT16_C(21914), UINT16_C( 7100), UINT16_C(47619),
        UINT16_C(29444), UINT16_C(53128), UINT16_C( 6751), UINT16_C(64890), UINT16_C(19462), UINT16_C(44319), UINT16_C(  807), UINT16_C(43871),
        UINT16_C(62717), UINT16_C(50087), UINT16_C(44851), UINT16_C(54671), UINT16_C(15031), UINT16_C(31958), UINT16_C( 3046), UINT16_C(35538),
        UINT16_C( 3595), UINT16_C(42351), UINT16_C(62811), UINT16_C(35400), UINT16_C(48826), UINT16_C(21155), UINT16_C(55713), UINT16_C(57071),
        UINT16_C( 8264), UINT16_C(46743), UINT16_C(41620), UINT16_C(24444), UINT16_C( 4391), UINT16_C(18222), UINT16_C(60474), UINT16_C(39594),
        UINT16_C(54634), UINT16_C(44076), UINT16_C(61219), UINT16_C(61696), UINT16_C(29973), UINT16_C(42914), UINT16_C(47987), UINT16_C( 9192),
        UINT16_C(34568), UINT16_C(12916), UINT16_C( 1268), UINT16_C(52436), UINT16_C( 6223), UINT16_C(45465), UINT16_C(55657), UINT16_C(55329),
        UINT16_C(  157), UINT16_C(18369), UINT16_C(13407), UINT16_C(13848), UINT16_C( 4994), UINT16_C(59568), UINT16_C(40818), UINT16_C(33425),
        UINT16_C( 8906), UINT16_C(60338), UINT16_C(30971), UINT16_C(45398), UINT16_C( 7538), UINT16_C(33361), UINT16_C(58074), UINT16_C(17016),
        UINT16_C(62802), UINT16_C(41819), UINT16_C(46110), UINT16_C(45973), UINT16_C(22436), UINT16_C(27175), UINT16_C( 8954), UINT16_C(31200),
        UINT16_C(40024), UINT16_C(24039), UINT16_C(16247), UINT16_C( 4798), UINT16_C(50699), UINT16_C(21183), UINT16_C(52529), UINT16_C( 6014) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C( 6749), UINT16_C( 1513), UINT16_C(19290), UINT16_C(35054),
        UINT16_C(42279), UINT16_C( 1904), UINT16_C( 1607), UINT16_C(23969), UINT16_C(48704), UINT16_C(11584), UINT16_C( 3577), UINT16_C(47067),
        UINT16_C(50408), UINT16_C(41479), UINT16_C(36422), UINT16_C(64692), UINT16_C(36239), UINT16_C(55142), UINT16_C(47627), UINT16_C(61515),
        UINT16_C(16315), UINT16_C(18385), UINT16_C(62950), UINT16_C(40264), UINT16_C(43820), UINT16_C( 1319), UINT16_C(48351), UINT16_C(24551),
        UINT16_C(14224), UINT16_C( 6210), UINT16_C(60899), UINT16_C(11448), UINT16_C(35393), UINT16_C(56261), UINT16_C(22477), UINT16_C(33859),
        UINT16_C(47398), UINT16_C(  550), UINT16_C( 3266), UINT16_C(56961), UINT16_C(59874), UINT16_C(20960), UINT16_C( 2875), UINT16_C(51224),
        UINT16_C(59708), UINT16_C(21684), UINT16_C(33366), UINT16_C(19468), UINT16_C(32420), UINT16_C(64133), UINT16_C(  647), UINT16_C(34189),
        UINT16_C(36473), UINT16_C( 6018), UINT16_C(39916), UINT16_C(51544), UINT16_C(49851), UINT16_C(25328), UINT16_C( 1353), UINT16_C( 1299),
        UINT16_C(31124), UINT16_C(52978), UINT16_C(33925), UINT16_C(28386), UINT16_C(25615), UINT16_C(32380), UINT16_C(29563), UINT16_C(62791),
        UINT16_C(26685), UINT16_C(65408), UINT16_C(55491), UINT16_C(21093), UINT16_C(58579), UINT16_C(47677), UINT16_C(48888), UINT16_C(54119),
        UINT16_C(46658), UINT16_C( 6540), UINT16_C(28388), UINT16_C(35301), UINT16_C(53273), UINT16_C( 4300), UINT16_C(63194), UINT16_C(51925),
        UINT16_C(34926), UINT16_C(12297), UINT16_C(63071), UINT16_C(18569), UINT16_C(11489), UINT16_C(51647), UINT16_C(52278), UINT16_C(35878),
        UINT16_C(52398), UINT16_C( 1946), UINT16_C(54436), UINT16_C(52158), UINT16_C(31277), UINT16_C(15439), UINT16_C(43454), UINT16_C(40768),
        UINT16_C(45293), UINT16_C(65446), UINT16_C(50546), UINT16_C(27183), UINT16_C(61067), UINT16_C(13996), UINT16_C(16818), UINT16_C(39687),
        UINT16_C(61234), UINT16_C(19404), UINT16_C(51027), UINT16_C(26634), UINT16_C(18083), UINT16_C(29060), UINT16_C(13244), UINT16_C(59670) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(65534), UINT16_C(    0), UINT16_C(65534), UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX, UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(52311), UINT16_C(22992), UINT16_C(20410), UINT16_C(11497),
        UINT16_C(  384), UINT16_C(12077), UINT16_C(48614), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(27271), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 1203), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(24955), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(21493), UINT16_C(12312), UINT16_C( 9880),
        UINT16_C(    0), UINT16_C(45820), UINT16_C(    0), UINT16_C( 3227), UINT16_C( 1174), UINT16_C(    0), UINT16_C(    0), UINT16_C(13760),
        UINT16_C(    0), UINT16_C(52578), UINT16_C( 3485), UINT16_C( 7929), UINT16_C(    0), UINT16_C(23359), UINT16_C(    0), UINT16_C(    0),
        UINT16_C( 3009), UINT16_C(28403), UINT16_C(11485), UINT16_C(35203), UINT16_C(    0), UINT16_C(    0), UINT16_C( 2399), UINT16_C( 1349),
        UINT16_C(    0), UINT16_C(36333), UINT16_C(22895), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(54360), UINT16_C(55772),
        UINT16_C(    0), UINT16_C(    0), UINT16_C( 7695), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(30911), UINT16_C(    0),
        UINT16_C(27949), UINT16_C(    0), UINT16_C( 5728), UINT16_C(40603), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0), UINT16_C( 6376), UINT16_C(    0), UINT16_C(17135), UINT16_C(    0), UINT16_C(41165), UINT16_C(    0), UINT16_C( 3404),
        UINT16_C(    0), UINT16_C( 6072), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 7921), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(58392), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(17922), UINT16_C(14620), UINT16_C(    0),
        UINT16_C(17509), UINT16_C(    0), UINT16_C(    0), UINT16_C(18790), UINT16_C(    0), UINT16_C(13179), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0), UINT16_C( 4635), UINT16_C(    0), UINT16_C(    0), UINT16_C(32616), UINT16_C(    0), UINT16_C(39285), UINT16_C(    0) } },
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(54358), UINT16_C(35845), UINT16_C(  997), UINT16_C(43978),
        UINT16_C(45607), UINT16_C(  963), UINT16_C(56001), UINT16_C(50773), UINT16_C(54924), UINT16_C(56196), UINT16_C(33816), UINT16_C(58502),
        UINT16_C(54636), UINT16_C(22315), UINT16_C(34063), UINT16_C( 9422), UINT16_C(35260), UINT16_C(54127), UINT16_C( 1868), UINT16_C(42126),
        UINT16_C(57177), UINT16_C(15424), UINT16_C(14227), UINT16_C(54159), UINT16_C(42485), UINT16_C(49605), UINT16_C(48429), UINT16_C(19426),
        UINT16_C(10883), UINT16_C(42295), UINT16_C(63997), UINT16_C(17239), UINT16_C( 5756), UINT16_C(31443), UINT16_C(59921), UINT16_C( 2233),
        UINT16_C( 4913), UINT16_C(25833), UINT16_C(10069), UINT16_C(22719), UINT16_C(23114), UINT16_C(26364), UINT16_C(44260), UINT16_C(52126),
        UINT16_C(34398), UINT16_C( 7359), UINT16_C(33387), UINT16_C(58354), UINT16_C(35461), UINT16_C(43687), UINT16_C(52712), UINT16_C(44959),
        UINT16_C(57486), UINT16_C(64907), UINT16_C( 5845), UINT16_C(23341), UINT16_C(35455), UINT16_C(58338), UINT16_C( 3554), UINT16_C(23037),
        UINT16_C(51406), UINT16_C(57805), UINT16_C(23318), UINT16_C(16780), UINT16_C(55463), UINT16_C(65074), UINT16_C(33562), UINT16_C(51959),
        UINT16_C(24191), UINT16_C(14573), UINT16_C(10340), UINT16_C(50343), UINT16_C(35075), UINT16_C(39179), UINT16_C(31164), UINT16_C(11805),
        UINT16_C(23645), UINT16_C(20186), UINT16_C(56196), UINT16_C( 5249), UINT16_C(58789), UINT16_C(35711), UINT16_C(19989), UINT16_C( 5811),
        UINT16_C(37948), UINT16_C(24479), UINT16_C(23367), UINT16_C(61244), UINT16_C(12184), UINT16_C(61843), UINT16_C(58678), UINT16_C(46494),
        UINT16_C(24077), UINT16_C( 4449), UINT16_C(20011), UINT16_C(57635), UINT16_C( 4051), UINT16_C(24775), UINT16_C( 5226), UINT16_C(35685),
        UINT16_C(24986), UINT16_C(45386), UINT16_C( 8594), UINT16_C(49021), UINT16_C( 9383), UINT16_C(41292), UINT16_C(39698), UINT16_C( 1467),
        UINT16_C(19847), UINT16_C(54507), UINT16_C(20252), UINT16_C(53169), UINT16_C(15400), UINT16_C(35684), UINT16_C( 8795), UINT16_C(38939) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(25557), UINT16_C(39230), UINT16_C(24799), UINT16_C(51901),
        UINT16_C(36860), UINT16_C(31232), UINT16_C(33491), UINT16_C(28352), UINT16_C(64177), UINT16_C(28631), UINT16_C( 7941), UINT16_C(51458),
        UINT16_C(19623), UINT16_C(10333), UINT16_C(40831), UINT16_C(13762), UINT16_C(39520), UINT16_C(40122), UINT16_C( 4135), UINT16_C( 3054),
        UINT16_C(14327), UINT16_C(17052), UINT16_C(44862), UINT16_C(25504), UINT16_C(59098), UINT16_C(54161), UINT16_C(65155), UINT16_C(47563),
        UINT16_C(15333), UINT16_C(41775), UINT16_C(59882), UINT16_C(34672), UINT16_C(39478), UINT16_C(44588), UINT16_C( 1962), UINT16_C(19308),
        UINT16_C(24305), UINT16_C( 7026), UINT16_C(17739), UINT16_C(52196), UINT16_C(19465), UINT16_C( 7977), UINT16_C(49983), UINT16_C(53034),
        UINT16_C(43279), UINT16_C(46969), UINT16_C(61280), UINT16_C(53983), UINT16_C(53957), UINT16_C(62145), UINT16_C(27815), UINT16_C(47851),
        UINT16_C(28244), UINT16_C(59846), UINT16_C(35139), UINT16_C(52179), UINT16_C(53646), UINT16_C(62285), UINT16_C(38665), UINT16_C(41661),
        UINT16_C(31196), UINT16_C(63604), UINT16_C(45363), UINT16_C(15220), UINT16_C(60948), UINT16_C( 6385), UINT16_C(60209), UINT16_C(30585),
        UINT16_C(43893), UINT16_C(22603), UINT16_C(20527), UINT16_C(65072), UINT16_C(10985), UINT16_C(20732), UINT16_C(24021), UINT16_C(43000),
        UINT16_C(28540), UINT16_C(17476), UINT16_C( 9402), UINT16_C(64254), UINT16_C(57814), UINT16_C(24430), UINT16_C(31153), UINT16_C(50520),
        UINT16_C(41864), UINT16_C(16890), UINT16_C( 8506), UINT16_C( 3574), UINT16_C(60840), UINT16_C(22326), UINT16_C(10500), UINT16_C( 7365),
        UINT16_C(23365), UINT16_C(59527), UINT16_C( 2419), UINT16_C(44343), UINT16_C(29700), UINT16_C( 7059), UINT16_C(35311), UINT16_C(48480),
        UINT16_C( 5400), UINT16_C(36440), UINT16_C(53153), UINT16_C(49565), UINT16_C(55221), UINT16_C(35884), UINT16_C(15401), UINT16_C(33187),
        UINT16_C(50933), UINT16_C(16994), UINT16_C(18352), UINT16_C(11201), UINT16_C(19445), UINT16_C(46418), UINT16_C(51611), UINT16_C(33504) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(65534), UINT16_C(    0), UINT16_C(65534), UINT16_C(    0), UINT16_C(    0),
             UINT16_MAX, UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(28801), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
        UINT16_C( 8747), UINT16_C(    0), UINT16_C(22510), UINT16_C(22421), UINT16_C(    0), UINT16_C(27565), UINT16_C(25875), UINT16_C( 7044),
        UINT16_C(35013), UINT16_C(11982), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(14005), UINT16_C(    0), UINT16_C(39072),
        UINT16_C(42850), UINT16_C(    0), UINT16_C(    0), UINT16_C(28655), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(  520), UINT16_C( 4115), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(57959), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(18807), UINT16_C(    0), UINT16_C(    0), UINT16_C( 3649), UINT16_C(18387), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 4371), UINT16_C(    0), UINT16_C(    0), UINT16_C(24897), UINT16_C(    0),
        UINT16_C(29242), UINT16_C( 5061), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(20210), UINT16_C(    0), UINT16_C(    0), UINT16_C( 1560), UINT16_C(    0), UINT16_C(58689), UINT16_C(    0), UINT16_C(21374),
        UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(24090), UINT16_C(18447), UINT16_C( 7143), UINT16_C(    0),
        UINT16_C(    0), UINT16_C( 2710), UINT16_C(46794), UINT16_C(    0), UINT16_C(  975), UINT16_C(11281), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(    0), UINT16_C( 7589), UINT16_C(14861), UINT16_C(57670), UINT16_C(    0), UINT16_C(39517), UINT16_C(48178), UINT16_C(39129),
        UINT16_C(  712), UINT16_C(    0), UINT16_C(17592), UINT16_C(13292), UINT16_C(    0), UINT16_C(17716), UINT16_C(    0), UINT16_C(    0),
        UINT16_C(19586), UINT16_C( 8946), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 5408), UINT16_C(24297), UINT16_C(    0),
        UINT16_C(    0), UINT16_C(37513), UINT16_C( 1900), UINT16_C(41968), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 5435) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wuh_vsub_WuhWuh_sat(a, b);

    simde_test_hvx_vectorpair_u16_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_u16_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_u16_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wuh_vsub_WuhWuh_sat(a, b);

    simde_test_hvx_vectorpair_u16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_u16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_u16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_WuwWuw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[SIMDE_HVX_PAIR_I32_COUNT];
    uint32_t b[SIMDE_HVX_PAIR_I32_COUNT];
    uint32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1), UINT32_C( 972116907), UINT32_C(1817568365), UINT32_C( 611679309), UINT32_C(3715603489),
        UINT32_C(1925903880), UINT32_C(3786164731), UINT32_C(3775295436), UINT32_C(2027679335), UINT32_C(2736594692), UINT32_C(1646530430), UINT32_C(1411047165), UINT32_C(2974107032),
        UINT32_C(2906772755), UINT32_C(4169113267), UINT32_C( 234802893), UINT32_C(1322289486), UINT32_C( 611161560), UINT32_C(2924373507), UINT32_C(2620926638), UINT32_C(3040231491),
        UINT32_C(3461217715), UINT32_C(  87390277), UINT32_C( 266514512), UINT32_C( 122137656), UINT32_C(2098158216), UINT32_C( 510816422), UINT32_C(2168030557), UINT32_C(3077494970),
        UINT32_C(3142754627), UINT32_C( 407183146), UINT32_C(1205726889), UINT32_C( 298270781), UINT32_C(3515894433), UINT32_C( 714178125), UINT32_C( 775401837), UINT32_C(1077899811),
        UINT32_C(2691470514), UINT32_C(3898238014), UINT32_C(1318361583), UINT32_C(1061566742), UINT32_C(3446713239), UINT32_C(1250723392), UINT32_C(4184645949), UINT32_C(1233833279),
        UINT32_C(3485480194), UINT32_C(3767482783), UINT32_C( 961823826), UINT32_C( 994479847), UINT32_C(1127206133), UINT32_C(3290987982), UINT32_C(1747220548), UINT32_C(1788525802) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),
        UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C( 253653355), UINT32_C(1747761551), UINT32_C(3115011382), UINT32_C( 873846689),
        UINT32_C(1233988317), UINT32_C(1120424895), UINT32_C(4034962074), UINT32_C(3090046011), UINT32_C(2513627664), UINT32_C(2675252331), UINT32_C(2781153856), UINT32_C(    891326),
        UINT32_C(  28709157), UINT32_C(4278242175), UINT32_C( 569593378), UINT32_C( 612932335), UINT32_C(3171674662), UINT32_C(1839195651), UINT32_C(3461531242), UINT32_C( 304417816),
        UINT32_C(4280267894), UINT32_C(1428081093), UINT32_C( 339058958), UINT32_C( 258847436), UINT32_C( 917017975), UINT32_C( 188932889), UINT32_C(1282202728), UINT32_C(2824328845),
        UINT32_C( 563737327), UINT32_C(2333067073), UINT32_C(1230920008), UINT32_C(2704823498), UINT32_C( 711173809), UINT32_C(4065296356), UINT32_C(4132872460), UINT32_C(1372033474),
        UINT32_C(2787747838), UINT32_C( 602644536), UINT32_C(2390279472), UINT32_C(4272558781), UINT32_C(1633521697), UINT32_C( 831760434), UINT32_C(3857444317), UINT32_C(2753168940),
        UINT32_C( 156405207), UINT32_C(3996264044), UINT32_C(1252723193), UINT32_C(3154730524), UINT32_C(3828429027), UINT32_C(1068703508), UINT32_C(2072913711), UINT32_C(1902045845) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(4294967294), UINT32_C(         0), UINT32_C(4294967294), UINT32_C(         0), UINT32_C(         0),
                  UINT32_MAX, UINT32_C(         1), UINT32_C(         0), UINT32_C(         0), UINT32_C( 718463552), UINT32_C(  69806814), UINT32_C(         0), UINT32_C(2841756800),
        UINT32_C( 691915563), UINT32_C(2665739836), UINT32_C(         0), UINT32_C(         0), UINT32_C( 222967028), UINT32_C(         0), UINT32_C(         0), UINT32_C(2973215706),
        UINT32_C(2878063598), UINT32_C(         0), UINT32_C(         0), UINT32_C( 709357151), UINT32_C(         0), UINT32_C(1085177856), UINT32_C(         0), UINT32_C(2735813675),
        UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(1181140241), UINT32_C( 321883533), UINT32_C( 885827829), UINT32_C( 253166125),
        UINT32_C(2579017300), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2804720624), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
        UINT32_C(         0), UINT32_C(3295593478), UINT32_C(         0), UINT32_C(         0), UINT32_C(1813191542), UINT32_C( 418962958), UINT32_C( 327201632), UINT32_C(         0),
        UINT32_C(3329074987), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2222284474), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1), UINT32_C(2415497404), UINT32_C( 667870333), UINT32_C( 189433773), UINT32_C(2308196844),
        UINT32_C(2710127271), UINT32_C(3655825503), UINT32_C(1715028981), UINT32_C( 113146179), UINT32_C(3422491161), UINT32_C(1715872836), UINT32_C(1043768652), UINT32_C(1567381725),
        UINT32_C(1578176404), UINT32_C(1605812862), UINT32_C(2925435251), UINT32_C(2351493859), UINT32_C(1100982340), UINT32_C(1712312047), UINT32_C( 288503811), UINT32_C(2738614629),
        UINT32_C( 773200453), UINT32_C(1748615057), UINT32_C(1102675440), UINT32_C(2715971584), UINT32_C(1311488560), UINT32_C(2239476505), UINT32_C(3989476603), UINT32_C(3348485477),
        UINT32_C(2828644958), UINT32_C( 798349370), UINT32_C(2114933673), UINT32_C(3889835061), UINT32_C(3812924015), UINT32_C(4281212678), UINT32_C( 371743798), UINT32_C( 556437698),
        UINT32_C(3712383370), UINT32_C(3272389099), UINT32_C( 730685961), UINT32_C(2556237359), UINT32_C(2758914275), UINT32_C(1016967631), UINT32_C( 730403362), UINT32_C(2754263142),
        UINT32_C( 851265523), UINT32_C( 424132298), UINT32_C(3220710663), UINT32_C(4046706039), UINT32_C(2435064571), UINT32_C(2735717378), UINT32_C( 656808881), UINT32_C( 404792778) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),
        UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(4252629071), UINT32_C( 127962540), UINT32_C( 706676259), UINT32_C(3047349287),
        UINT32_C(3007516279), UINT32_C(1524417935), UINT32_C( 139227501), UINT32_C(1399247779), UINT32_C(4097338380), UINT32_C(1129748604), UINT32_C( 458659921), UINT32_C(1290418072),
        UINT32_C(1785800877), UINT32_C(4191215203), UINT32_C(1702288652), UINT32_C( 560393417), UINT32_C(3411620188), UINT32_C(1320868662), UINT32_C(1272936036), UINT32_C(2564714310),
        UINT32_C(1844319914), UINT32_C(1242889814), UINT32_C( 868319486), UINT32_C(  70782960), UINT32_C(1298117660), UINT32_C(1872292622), UINT32_C( 930458813), UINT32_C(4066779356),
        UINT32_C(3500823638), UINT32_C(1019101887), UINT32_C(1885151377), UINT32_C(3642473493), UINT32_C(4036599933), UINT32_C(1627632153), UINT32_C(1357639246), UINT32_C( 948340794),
        UINT32_C( 834013786), UINT32_C( 721605885), UINT32_C(2623390460), UINT32_C(2879914622), UINT32_C(4155248572), UINT32_C(2782676343), UINT32_C(1990075690), UINT32_C(2108803713),
        UINT32_C(2744315540), UINT32_C(4067134297), UINT32_C(4242732471), UINT32_C( 636190856), UINT32_C( 396899159), UINT32_C(1439252982), UINT32_C(  23165091), UINT32_C(1085579160) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(4294967294), UINT32_C(         0), UINT32_C(4294967294), UINT32_C(         0), UINT32_C(         0),
                  UINT32_MAX, UINT32_C(         1), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 539907793), UINT32_C(         0), UINT32_C(         0),
        UINT32_C(         0), UINT32_C(2131407568), UINT32_C(1575801480), UINT32_C(         0), UINT32_C(         0), UINT32_C( 586124232), UINT32_C( 585108731), UINT32_C( 276963653),
        UINT32_C(         0), UINT32_C(         0), UINT32_C(1223146599), UINT32_C(1791100442), UINT32_C(         0), UINT32_C( 391443385), UINT32_C(         0), UINT32_C( 173900319),
        UINT32_C(         0), UINT32_C( 505725243), UINT32_C( 234355954), UINT32_C(2645188624), UINT32_C(  13370900), UINT32_C( 367183883), UINT32_C(3059017790), UINT32_C(         0),
        UINT32_C(         0), UINT32_C(         0), UINT32_C( 229782296), UINT32_C( 247361568), UINT32_C(         0), UINT32_C(2653580525), UINT32_C(         0), UINT32_C(         0),
        UINT32_C(2878369584), UINT32_C(2550783214), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 645459429),
        UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(3410515183), UINT32_C(2038165412), UINT32_C(1296464396), UINT32_C( 633643790), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wuw_vsub_WuwWuw_sat(a, b);

    simde_test_hvx_vectorpair_u32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_u32_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_u32_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wuw_vsub_WuwWuw_sat(a, b);

    simde_test_hvx_vectorpair_u32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_u32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_u32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VubVub(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[SIMDE_HVX_VECTOR_SIZE];
    uint8_t b[SIMDE_HVX_VECTOR_SIZE];
    int16_t r[SIMDE_HVX_PAIR_I16_COUNT];
  } test_vec[] = {
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(231), UINT8_C(221), UINT8_C(  6), UINT8_C(130),
        UINT8_C(200), UINT8_C(126), UINT8_C(145), UINT8_C(153), UINT8_C( 62), UINT8_C(168), UINT8_C(187), UINT8_C(116),
        UINT8_C(223), UINT8_C(215), UINT8_C(239), UINT8_C( 66), UINT8_C( 50), UINT8_C(152), UINT8_C( 13), UINT8_C( 25),
        UINT8_C(134), UINT8_C(  0), UINT8_C( 74), UINT8_C(243), UINT8_C( 34), UINT8_C( 57), UINT8_C(146), UINT8_C(219),
        UINT8_C(208), UINT8_C( 54), UINT8_C(240), UINT8_C( 79), UINT8_C(111), UINT8_C(195), UINT8_C( 75), UINT8_C(  6),
        UINT8_C(185), UINT8_C( 82), UINT8_C(115), UINT8_C(254), UINT8_C(117), UINT8_C( 57), UINT8_C(230), UINT8_C(198),
        UINT8_C(236), UINT8_C(  6), UINT8_C(215), UINT8_C(134), UINT8_C( 89), UINT8_C(216), UINT8_C(203), UINT8_C(241),
        UINT8_C( 63), UINT8_C(187), UINT8_C( 31), UINT8_C( 28), UINT8_C(228), UINT8_C(165), UINT8_C( 91), UINT8_C(218),
        UINT8_C(114), UINT8_C(175), UINT8_C(180), UINT8_C(253), UINT8_C( 95), UINT8_C( 89), UINT8_C(223), UINT8_C(237),
        UINT8_C(186), UINT8_C( 43), UINT8_C(239), UINT8_C( 32), UINT8_C(101), UINT8_C( 75), UINT8_C( 72), UINT8_C( 32),
        UINT8_C( 91), UINT8_C( 43), UINT8_C(239), UINT8_C(151), UINT8_C(111), UINT8_C( 76), UINT8_C(241), UINT8_C(180),
        UINT8_C(157), UINT8_C( 24), UINT8_C(214), UINT8_C( 45), UINT8_C(188), UINT8_C(214), UINT8_C( 95), UINT8_C( 12),
        UINT8_C( 27), UINT8_C(168), UINT8_C( 83), UINT8_C( 87), UINT8_C( 33), UINT8_C( 67), UINT8_C(218), UINT8_C(221),
        UINT8_C(123), UINT8_C( 70), UINT8_C( 70), UINT8_C(215), UINT8_C( 39), UINT8_C( 44), UINT8_C(160), UINT8_C( 59),
        UINT8_C( 86), UINT8_C(212), UINT8_C( 61), UINT8_C(196), UINT8_C(187), UINT8_C(105), UINT8_C( 81), UINT8_C(130) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(152), UINT8_C( 21), UINT8_C(225), UINT8_C(223),
        UINT8_C(129), UINT8_C(209), UINT8_C(241), UINT8_C( 27), UINT8_C( 69), UINT8_C(246), UINT8_C(242), UINT8_C(  9),
        UINT8_C( 52), UINT8_C(133), UINT8_C(110), UINT8_C( 95), UINT8_C(107), UINT8_C(101), UINT8_C(237), UINT8_C(101),
        UINT8_C(124), UINT8_C(170), UINT8_C(  4), UINT8_C(118), UINT8_C( 89), UINT8_C( 85), UINT8_C( 83), UINT8_C( 73),
        UINT8_C(164), UINT8_C(102), UINT8_C(153), UINT8_C(  9), UINT8_C(226), UINT8_C( 87), UINT8_C( 73), UINT8_C(200),
        UINT8_C( 95), UINT8_C(145), UINT8_C(167), UINT8_C(166), UINT8_C(101), UINT8_C(240), UINT8_C(133), UINT8_C(133),
        UINT8_C(148), UINT8_C(196), UINT8_C(188), UINT8_C(193), UINT8_C( 31), UINT8_C(243), UINT8_C(214), UINT8_C(127),
        UINT8_C( 78), UINT8_C(184), UINT8_C( 78), UINT8_C(237), UINT8_C(242), UINT8_C(165), UINT8_C(240), UINT8_C( 32),
        UINT8_C(104), UINT8_C(151), UINT8_C( 84), UINT8_C(182), UINT8_C(160), UINT8_C(246), UINT8_C(182), UINT8_C( 56),
        UINT8_C(107), UINT8_C( 20), UINT8_C(241), UINT8_C( 26), UINT8_C(109), UINT8_C(100), UINT8_C( 97), UINT8_C(  8),
        UINT8_C(243), UINT8_C(160), UINT8_C(100), UINT8_C(210), UINT8_C(238), UINT8_C(128), UINT8_C(137), UINT8_C(197),
        UINT8_C(215), UINT8_C(109), UINT8_C( 65), UINT8_C( 16), UINT8_C(154), UINT8_C(117), UINT8_C( 32), UINT8_C(104),
        UINT8_C( 39), UINT8_C( 55), UINT8_C(239), UINT8_C(192), UINT8_C(191), UINT8_C( 74), UINT8_C( 56), UINT8_C(  2),
        UINT8_C(243), UINT8_C( 83), UINT8_C( 57), UINT8_C(162), UINT8_C( 46), UINT8_C(254), UINT8_C( 80), UINT8_C( 28),
        UINT8_C(192), UINT8_C(194), UINT8_C(148), UINT8_C(  3), UINT8_C(235), UINT8_C(233), UINT8_C(208), UINT8_C( 41) },
      {  INT16_C(     0),  INT16_C(   255), -INT16_C(   255), -INT16_C(   255),  INT16_C(   255),  INT16_C(     0),  INT16_C(    79), -INT16_C(   219),
         INT16_C(    71), -INT16_C(    96), -INT16_C(     7), -INT16_C(    55),  INT16_C(   171),  INT16_C(   129), -INT16_C(    57), -INT16_C(   224),
         INT16_C(    10),  INT16_C(    70), -INT16_C(    55),  INT16_C(    63),  INT16_C(    44),  INT16_C(    87), -INT16_C(   115),  INT16_C(     2),
         INT16_C(    90), -INT16_C(    52),  INT16_C(    16),  INT16_C(    97),  INT16_C(    88),  INT16_C(    27),  INT16_C(    58), -INT16_C(    11),
        -INT16_C(    15), -INT16_C(    47), -INT16_C(    14), -INT16_C(   149),  INT16_C(    10),  INT16_C(    96), -INT16_C(    65),  INT16_C(    41),
         INT16_C(    79), -INT16_C(     2), -INT16_C(     8), -INT16_C(    25), -INT16_C(   152),  INT16_C(   139), -INT16_C(   127),  INT16_C(   104),
        -INT16_C(    58),  INT16_C(   149),  INT16_C(    34),  INT16_C(    63), -INT16_C(    12), -INT16_C(   156), -INT16_C(   158),  INT16_C(   162),
        -INT16_C(   120),  INT16_C(    13), -INT16_C(     7),  INT16_C(    80), -INT16_C(   106), -INT16_C(    87), -INT16_C(    48), -INT16_C(   127),
        -INT16_C(   255),  INT16_C(   254),  INT16_C(   254),  INT16_C(     0),  INT16_C(     1), -INT16_C(   254),  INT16_C(   200), -INT16_C(    93),
        -INT16_C(    83),  INT16_C(   126), -INT16_C(    78),  INT16_C(   107),  INT16_C(    82), -INT16_C(    29),  INT16_C(    51), -INT16_C(    76),
        -INT16_C(   170),  INT16_C(   125), -INT16_C(    28),  INT16_C(   146), -INT16_C(    48),  INT16_C(    70),  INT16_C(   108), -INT16_C(   194),
        -INT16_C(    63),  INT16_C(    88), -INT16_C(   183),  INT16_C(    65), -INT16_C(   190), -INT16_C(    59), -INT16_C(    27),  INT16_C(   114),
         INT16_C(     3), -INT16_C(   209),  INT16_C(     0),  INT16_C(   186),  INT16_C(    24),  INT16_C(    71), -INT16_C(   157),  INT16_C(   181),
         INT16_C(    23),  INT16_C(     6), -INT16_C(    25),  INT16_C(    24), -INT16_C(   117), -INT16_C(    59), -INT16_C(    52), -INT16_C(    17),
        -INT16_C(    85),  INT16_C(    29),  INT16_C(    97), -INT16_C(    92),  INT16_C(   113), -INT16_C(   105), -INT16_C(     7),  INT16_C(   219),
        -INT16_C(    13),  INT16_C(    53), -INT16_C(   210),  INT16_C(    31),  INT16_C(    18),  INT16_C(   193), -INT16_C(   128),  INT16_C(    89) } },
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(191), UINT8_C(136), UINT8_C(234), UINT8_C( 38),
        UINT8_C(251), UINT8_C(230), UINT8_C( 87), UINT8_C( 20), UINT8_C(135), UINT8_C(162), UINT8_C( 91), UINT8_C(206),
        UINT8_C(248), UINT8_C(242), UINT8_C(213), UINT8_C(217), UINT8_C( 49), UINT8_C(186), UINT8_C( 32), UINT8_C( 85),
        UINT8_C( 87), UINT8_C(189), UINT8_C(130), UINT8_C(186), UINT8_C(112), UINT8_C( 29), UINT8_C(141), UINT8_C(176),
        UINT8_C(236), UINT8_C(245), UINT8_C(  5), UINT8_C(161), UINT8_C(117), UINT8_C(193), UINT8_C( 19), UINT8_C( 65),
        UINT8_C(108), UINT8_C(168), UINT8_C(159), UINT8_C(151), UINT8_C( 13), UINT8_C(206), UINT8_C(200), UINT8_C(130),
        UINT8_C( 57), UINT8_C( 35),    UINT8_MAX, UINT8_C(237), UINT8_C(103), UINT8_C(232), UINT8_C(122), UINT8_C(215),
        UINT8_C(207), UINT8_C(218), UINT8_C( 96), UINT8_C(213), UINT8_C(211), UINT8_C(230), UINT8_C(248), UINT8_C(205),
        UINT8_C( 85), UINT8_C(223), UINT8_C( 76), UINT8_C(201), UINT8_C( 90), UINT8_C( 92), UINT8_C(197), UINT8_C(131),
        UINT8_C(209), UINT8_C(229), UINT8_C(116), UINT8_C(194), UINT8_C( 50), UINT8_C(112), UINT8_C(157), UINT8_C( 70),
        UINT8_C( 90), UINT8_C(  4), UINT8_C(169), UINT8_C(110), UINT8_C(197), UINT8_C( 12), UINT8_C(200), UINT8_C(217),
        UINT8_C(114), UINT8_C(250), UINT8_C( 34), UINT8_C( 11), UINT8_C(252), UINT8_C(195), UINT8_C( 81), UINT8_C( 58),
        UINT8_C(171), UINT8_C(233), UINT8_C(235), UINT8_C(247), UINT8_C( 75), UINT8_C( 19), UINT8_C(249), UINT8_C( 29),
        UINT8_C(139), UINT8_C(  7), UINT8_C( 84), UINT8_C( 67), UINT8_C(239), UINT8_C( 63), UINT8_C(156), UINT8_C(165),
        UINT8_C(132), UINT8_C(  4), UINT8_C( 18), UINT8_C( 36), UINT8_C(160), UINT8_C( 31), UINT8_C(186), UINT8_C( 83) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(211), UINT8_C(107), UINT8_C( 48), UINT8_C( 57),
        UINT8_C(135), UINT8_C(188), UINT8_C(105), UINT8_C(  0), UINT8_C(231), UINT8_C(158), UINT8_C(194), UINT8_C(247),
        UINT8_C(198), UINT8_C(222), UINT8_C(149), UINT8_C(246), UINT8_C(109), UINT8_C(177), UINT8_C( 42), UINT8_C(189),
        UINT8_C( 84), UINT8_C(232), UINT8_C(190), UINT8_C(216), UINT8_C(112), UINT8_C(194), UINT8_C(249), UINT8_C( 80),
        UINT8_C(102), UINT8_C( 44), UINT8_C(240), UINT8_C(147), UINT8_C(243), UINT8_C(176), UINT8_C(148), UINT8_C(105),
        UINT8_C(121), UINT8_C(166), UINT8_C(149), UINT8_C(186), UINT8_C( 15), UINT8_C(239), UINT8_C( 71), UINT8_C( 57),
        UINT8_C( 44), UINT8_C(168), UINT8_C(150), UINT8_C(235), UINT8_C( 72), UINT8_C(170), UINT8_C(248), UINT8_C( 65),
        UINT8_C( 39), UINT8_C( 66), UINT8_C(193), UINT8_C(186), UINT8_C( 48), UINT8_C( 33), UINT8_C(216), UINT8_C(198),
        UINT8_C(141), UINT8_C(243), UINT8_C(188), UINT8_C(174), UINT8_C(102), UINT8_C(115), UINT8_C(146), UINT8_C(156),
        UINT8_C(143), UINT8_C(130), UINT8_C(  3), UINT8_C( 46), UINT8_C(213), UINT8_C(114), UINT8_C( 30), UINT8_C( 93),
        UINT8_C( 91), UINT8_C( 91), UINT8_C(244), UINT8_C(170), UINT8_C(254), UINT8_C(128), UINT8_C(105), UINT8_C(112),
        UINT8_C(186), UINT8_C( 16), UINT8_C( 25), UINT8_C(145), UINT8_C(237), UINT8_C(195), UINT8_C(196), UINT8_C(205),
        UINT8_C( 82), UINT8_C(  9), UINT8_C(135), UINT8_C( 47), UINT8_C(108), UINT8_C(127),    UINT8_MAX, UINT8_C(147),
        UINT8_C(170), UINT8_C(213), UINT8_C( 55), UINT8_C(191), UINT8_C(202), UINT8_C(160), UINT8_C(241), UINT8_C( 29),
        UINT8_C(162), UINT8_C(221), UINT8_C(243), UINT8_C(131), UINT8_C(146), UINT8_C(244), UINT8_C(  7), UINT8_C(118) },
      {  INT16_C(     0),  INT16_C(   255), -INT16_C(   255), -INT16_C(   255),  INT16_C(   255),  INT16_C(     0), -INT16_C(    20),  INT16_C(   186),
         INT16_C(   116), -INT16_C(    18), -INT16_C(    96), -INT16_C(   103),  INT16_C(    50),  INT16_C(    64), -INT16_C(    60), -INT16_C(    10),
         INT16_C(     3), -INT16_C(    60),  INT16_C(     0), -INT16_C(   108),  INT16_C(   134), -INT16_C(   235), -INT16_C(   126), -INT16_C(   129),
        -INT16_C(    13),  INT16_C(    10), -INT16_C(     2),  INT16_C(   129),  INT16_C(    13),  INT16_C(   105),  INT16_C(    31), -INT16_C(   126),
         INT16_C(   168), -INT16_C(    97),  INT16_C(   163),  INT16_C(    32), -INT16_C(    56), -INT16_C(   112), -INT16_C(    12),  INT16_C(    51),
         INT16_C(    66),  INT16_C(   113), -INT16_C(   163),  INT16_C(   127), -INT16_C(     1), -INT16_C(    75), -INT16_C(    57),  INT16_C(    95),
        -INT16_C(    72),  INT16_C(     9),  INT16_C(    15), -INT16_C(   115),  INT16_C(    89),  INT16_C(   100), -INT16_C(    33), -INT16_C(     6),
        -INT16_C(    31),  INT16_C(    29),  INT16_C(    37), -INT16_C(    85), -INT16_C(    30), -INT16_C(   225),  INT16_C(    14),  INT16_C(   179),
        -INT16_C(   255),  INT16_C(   254),  INT16_C(   254),  INT16_C(     0),  INT16_C(     1), -INT16_C(   254),  INT16_C(    29), -INT16_C(    19),
         INT16_C(    42),  INT16_C(    20),  INT16_C(     4), -INT16_C(    41),  INT16_C(    20), -INT16_C(    29),  INT16_C(     9), -INT16_C(   104),
        -INT16_C(    43), -INT16_C(    30), -INT16_C(   165),  INT16_C(    96),  INT16_C(   201),  INT16_C(    14),  INT16_C(    17), -INT16_C(    40),
         INT16_C(     2), -INT16_C(    35), -INT16_C(    33),  INT16_C(    73), -INT16_C(   133),  INT16_C(     2),  INT16_C(    62),  INT16_C(   150),
         INT16_C(   152),  INT16_C(    27),  INT16_C(   197),  INT16_C(     7), -INT16_C(    20),  INT16_C(    27), -INT16_C(    23), -INT16_C(    25),
         INT16_C(    99),  INT16_C(   148), -INT16_C(     2), -INT16_C(    23), -INT16_C(    87), -INT16_C(    60), -INT16_C(   116),  INT16_C(   105),
         INT16_C(   234), -INT16_C(   134),  INT16_C(     0), -INT16_C(   147),  INT16_C(   224),  INT16_C(   200), -INT16_C(   108), -INT16_C(   118),
        -INT16_C(   206), -INT16_C(   124), -INT16_C(    97),  INT16_C(   136), -INT16_C(   217), -INT16_C(    95), -INT16_C(   213), -INT16_C(    35) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vsub_VubVub(a, b);

    simde_test_hvx_vectorpair_i16_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u8_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u8_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vsub_VubVub(a, b);

    simde_test_hvx_vector_u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VhVh_widen(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    int32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C( 28524), -INT16_C(  4179),  INT16_C( 19779), -INT16_C( 14082),
         INT16_C(  8144), -INT16_C( 24068),  INT16_C(  5987),  INT16_C( 32385),  INT16_C( 23470), -INT16_C( 13022),  INT16_C( 15328),  INT16_C(  2979),
         INT16_C( 25276),  INT16_C( 11152), -INT16_C( 27509), -INT16_C( 17847),  INT16_C( 22813), -INT16_C( 28668),  INT16_C(  5143),  INT16_C( 24318),
         INT16_C( 22745),  INT16_C( 14378), -INT16_C( 19279),  INT16_C(  1573),  INT16_C( 17221),  INT16_C( 21199), -INT16_C( 30119),  INT16_C(  9874),
        -INT16_C( 28446), -INT16_C( 22022), -INT16_C( 26378),  INT16_C( 25014),  INT16_C( 11548), -INT16_C( 17651),  INT16_C( 19932),  INT16_C( 24727),
         INT16_C( 18201), -INT16_C( 13037),  INT16_C(  7283), -INT16_C( 32137), -INT16_C(  5208),  INT16_C(  5397), -INT16_C( 10362), -INT16_C( 25575),
        -INT16_C(  2473),  INT16_C( 19537), -INT16_C(  3169),  INT16_C( 24684),  INT16_C(  7032),  INT16_C( 29441),  INT16_C( 13236),  INT16_C( 23580) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C( 10312), -INT16_C(  3413),  INT16_C( 29466), -INT16_C(  1795),
        -INT16_C( 24763), -INT16_C( 26672), -INT16_C( 26291), -INT16_C( 22470), -INT16_C( 10436), -INT16_C( 18830), -INT16_C(  9088), -INT16_C( 13047),
         INT16_C( 30476),  INT16_C( 16488),  INT16_C(  9502), -INT16_C( 21567), -INT16_C( 14568), -INT16_C( 21672), -INT16_C(  6551),  INT16_C(  9640),
        -INT16_C( 14202), -INT16_C( 23645), -INT16_C( 23302), -INT16_C( 24416),  INT16_C( 18572),  INT16_C(  6593),  INT16_C( 22150), -INT16_C( 26586),
         INT16_C( 32423), -INT16_C( 19326),  INT16_C( 12721), -INT16_C(   284), -INT16_C( 29662), -INT16_C( 13753), -INT16_C( 12317), -INT16_C( 11029),
        -INT16_C( 32744), -INT16_C( 25269),  INT16_C(  7827), -INT16_C( 12138), -INT16_C(  6123), -INT16_C( 13839), -INT16_C( 13891),  INT16_C( 17671),
         INT16_C( 26679),  INT16_C( 23263),  INT16_C( 13769), -INT16_C(  8231),  INT16_C(  3523),  INT16_C( 14995), -INT16_C( 28359),  INT16_C( 10190) },
      {  INT32_C(           0),  INT32_C(       32767), -INT32_C(       32767), -INT32_C(       32767),  INT32_C(       32767),  INT32_C(           0), -INT32_C(       18212), -INT32_C(        9687),
         INT32_C(       32907),  INT32_C(       32278),  INT32_C(       33906),  INT32_C(       24416), -INT32_C(        5200), -INT32_C(       37011),  INT32_C(       37381),  INT32_C(       11694),
         INT32_C(       36947),  INT32_C(        4023), -INT32_C(        1351), -INT32_C(       52269), -INT32_C(       60869), -INT32_C(       39099),  INT32_C(       41210),  INT32_C(       32249),
         INT32_C(       50945), -INT32_C(         544),  INT32_C(         915),  INT32_C(        3529), -INT32_C(       29152), -INT32_C(       16938),  INT32_C(        3509),  INT32_C(       41595),
        -INT32_C(       65535),  INT32_C(       32766),  INT32_C(       32766),  INT32_C(           0),  INT32_C(       32769), -INT32_C(       32766), -INT32_C(         766), -INT32_C(       12287),
         INT32_C(        2604),  INT32_C(       54855),  INT32_C(        5808),  INT32_C(       16026), -INT32_C(        5336),  INT32_C(        3720), -INT32_C(        6996),  INT32_C(       14678),
         INT32_C(       38023),  INT32_C(       25989),  INT32_C(       14606),  INT32_C(       36460), -INT32_C(        2696),  INT32_C(       25298), -INT32_C(        3898),  INT32_C(       35756),
         INT32_C(       12232), -INT32_C(       19999),  INT32_C(       19236), -INT32_C(       43246), -INT32_C(        3726),  INT32_C(       32915),  INT32_C(       14446),  INT32_C(       13390) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C(   999),  INT16_C(  9897), -INT16_C(  3950),  INT16_C(  8694),
        -INT16_C(  6071), -INT16_C(  2531),  INT16_C( 26420),  INT16_C( 20072), -INT16_C(   919),  INT16_C( 11206),  INT16_C( 29911),  INT16_C( 10105),
         INT16_C( 18652), -INT16_C( 32578),  INT16_C( 12517),  INT16_C( 19024),  INT16_C(  1161), -INT16_C(   462), -INT16_C( 14834), -INT16_C(  7551),
        -INT16_C( 31250),  INT16_C(   641), -INT16_C( 25935), -INT16_C( 17609),  INT16_C( 32083), -INT16_C(  8487), -INT16_C(  3330),  INT16_C( 17055),
         INT16_C( 32602),  INT16_C(  1683), -INT16_C( 18781),  INT16_C( 31190),  INT16_C(  3406), -INT16_C(  1660),  INT16_C( 17620),  INT16_C( 20329),
        -INT16_C(  9122), -INT16_C( 26551), -INT16_C( 17583),  INT16_C( 17534),  INT16_C( 24543), -INT16_C(  7288),  INT16_C( 27378),  INT16_C( 29554),
        -INT16_C(  3445), -INT16_C( 29205), -INT16_C( 31196), -INT16_C( 23633), -INT16_C( 29539),  INT16_C(  6032), -INT16_C( 22637),  INT16_C( 19805) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C(  4302), -INT16_C( 22958),  INT16_C( 30604),  INT16_C( 29222),
        -INT16_C( 15469), -INT16_C( 20461),  INT16_C( 18970),  INT16_C(  2172),  INT16_C( 11626),  INT16_C( 32271),  INT16_C( 19618),  INT16_C( 26774),
        -INT16_C(   707), -INT16_C( 21242),  INT16_C( 27002),  INT16_C( 27207), -INT16_C( 21446),  INT16_C( 17343),  INT16_C( 16664),  INT16_C( 13954),
        -INT16_C( 14098),  INT16_C(  4968), -INT16_C(  5769), -INT16_C( 27639),  INT16_C( 26469), -INT16_C(  4243), -INT16_C(  8046),  INT16_C( 19004),
        -INT16_C( 29421), -INT16_C( 29454), -INT16_C( 15388), -INT16_C( 22683), -INT16_C( 13084),  INT16_C( 24117), -INT16_C( 11601), -INT16_C( 22650),
        -INT16_C( 14160),  INT16_C(  2534), -INT16_C( 29010), -INT16_C( 32329), -INT16_C( 19669),  INT16_C( 28755),  INT16_C( 13508), -INT16_C(  7690),
         INT16_C(  7733), -INT16_C( 16305),  INT16_C( 11528),  INT16_C( 18453), -INT16_C(  2690),  INT16_C( 16234), -INT16_C(  3216), -INT16_C( 25223) },
      {  INT32_C(           0),  INT32_C(       32767), -INT32_C(       32767), -INT32_C(       32767),  INT32_C(       32767),  INT32_C(           0),  INT32_C(        5301), -INT32_C(       34554),
         INT32_C(        9398),  INT32_C(        7450), -INT32_C(       12545),  INT32_C(       10293),  INT32_C(       19359), -INT32_C(       14485),  INT32_C(       22607), -INT32_C(       31498),
        -INT32_C(       17152), -INT32_C(       20166),  INT32_C(        5614),  INT32_C(        4716),  INT32_C(       62023), -INT32_C(        3393),  INT32_C(       16490),  INT32_C(       29221),
         INT32_C(        5038),  INT32_C(       11427),  INT32_C(       44212),  INT32_C(       13870), -INT32_C(       11178), -INT32_C(       42724), -INT32_C(       26849), -INT32_C(       19421),
        -INT32_C(       65535),  INT32_C(       32766),  INT32_C(       32766),  INT32_C(           0),  INT32_C(       32769), -INT32_C(       32766),  INT32_C(       32855), -INT32_C(       20528),
         INT32_C(       17930),  INT32_C(       17900), -INT32_C(       21065), -INT32_C(       16669), -INT32_C(       11336), -INT32_C(        8183), -INT32_C(       17805), -INT32_C(       21505),
        -INT32_C(        4327),  INT32_C(       10030), -INT32_C(        4244), -INT32_C(        1949),  INT32_C(       31137),  INT32_C(       53873), -INT32_C(       25777),  INT32_C(       42979),
        -INT32_C(       29085),  INT32_C(       49863), -INT32_C(       36043),  INT32_C(       37244), -INT32_C(       12900), -INT32_C(       42086), -INT32_C(       10202),  INT32_C(       45028) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vsub_VhVh(a, b);

    simde_test_hvx_vectorpair_i32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i16_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vsub_VhVh(a, b);

    simde_test_hvx_vector_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VuhVuh_widen(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    uint16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    int32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(64009), UINT16_C(33755), UINT16_C(40999), UINT16_C(27704),
        UINT16_C(15605), UINT16_C(27184), UINT16_C(44797), UINT16_C(34328), UINT16_C(53330), UINT16_C(30287), UINT16_C( 4449), UINT16_C(47091),
        UINT16_C(34015), UINT16_C(47743), UINT16_C(43508), UINT16_C(29346), UINT16_C(57169), UINT16_C(10168), UINT16_C(51411), UINT16_C( 6417),
        UINT16_C( 3968), UINT16_C(19274), UINT16_C(34538), UINT16_C(32353), UINT16_C(36463), UINT16_C( 4835), UINT16_C( 1486), UINT16_C(43305),
        UINT16_C(26506), UINT16_C(26929), UINT16_C( 7181), UINT16_C(63517), UINT16_C(27520), UINT16_C( 1368), UINT16_C(34481), UINT16_C( 2596),
        UINT16_C(62448), UINT16_C(62277), UINT16_C(55464), UINT16_C(16632), UINT16_C(20988), UINT16_C(62427), UINT16_C( 2191), UINT16_C( 7962),
        UINT16_C(15795), UINT16_C(  944), UINT16_C(38733), UINT16_C( 1249), UINT16_C(11324), UINT16_C(55844), UINT16_C(55996), UINT16_C(14400) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C( 2106), UINT16_C(50442), UINT16_C(60094), UINT16_C(59718),
        UINT16_C(42851), UINT16_C(33343), UINT16_C(42717), UINT16_C(35591), UINT16_C(21523), UINT16_C(21140), UINT16_C(54863), UINT16_C( 3596),
        UINT16_C(37135), UINT16_C(54582), UINT16_C(61929), UINT16_C(25358), UINT16_C(17491), UINT16_C(20838), UINT16_C(46027), UINT16_C(56067),
        UINT16_C( 8382), UINT16_C(54629), UINT16_C( 4009), UINT16_C(58552), UINT16_C(33529), UINT16_C(33964), UINT16_C(45054), UINT16_C(12672),
        UINT16_C(37907), UINT16_C(63411), UINT16_C(43569), UINT16_C(28979), UINT16_C( 4640), UINT16_C(61816), UINT16_C(20564), UINT16_C(64659),
        UINT16_C(21535), UINT16_C( 3547), UINT16_C(32061), UINT16_C(20774), UINT16_C(43057), UINT16_C(26293), UINT16_C(11375), UINT16_C(37972),
        UINT16_C(26400), UINT16_C(40580), UINT16_C(22087), UINT16_C(40852), UINT16_C(39436), UINT16_C( 2125), UINT16_C(43427), UINT16_C(39229) },
      {  INT32_C(           0),  INT32_C(       65535), -INT32_C(       65535), -INT32_C(       65535),  INT32_C(       65535),  INT32_C(           0),  INT32_C(       61903), -INT32_C(       19095),
        -INT32_C(       27246),  INT32_C(        2080),  INT32_C(       31807), -INT32_C(       50414), -INT32_C(        3120), -INT32_C(       18421),  INT32_C(       39678),  INT32_C(        5384),
        -INT32_C(        4414),  INT32_C(       30529),  INT32_C(        2934), -INT32_C(       43568), -INT32_C(       11401), -INT32_C(       36388),  INT32_C(       22880),  INT32_C(       13917),
         INT32_C(       40913),  INT32_C(       23403), -INT32_C(       22069), -INT32_C(        9184), -INT32_C(       10605),  INT32_C(       16646), -INT32_C(       28112),  INT32_C(       12569),
        -INT32_C(       65535),  INT32_C(       65534),  INT32_C(       65534),  INT32_C(           0),  INT32_C(           1), -INT32_C(       65534), -INT32_C(       16687), -INT32_C(       32014),
        -INT32_C(        6159), -INT32_C(        1263),  INT32_C(        9147),  INT32_C(       43495), -INT32_C(        6839),  INT32_C(        3988), -INT32_C(       10670), -INT32_C(       49650),
        -INT32_C(       35355), -INT32_C(       26199), -INT32_C(       29129),  INT32_C(       30633), -INT32_C(       36482),  INT32_C(       34538), -INT32_C(       60448), -INT32_C(       62063),
         INT32_C(       58730), -INT32_C(        4142),  INT32_C(       36134), -INT32_C(       30010), -INT32_C(       39636), -INT32_C(       39603),  INT32_C(       53719), -INT32_C(       24829) } },
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(34032), UINT16_C(26930), UINT16_C(47596), UINT16_C( 6102),
        UINT16_C(40427), UINT16_C( 2651), UINT16_C(60342), UINT16_C(61512), UINT16_C(11133), UINT16_C(51196), UINT16_C( 5223), UINT16_C(16207),
        UINT16_C(40889), UINT16_C(24072), UINT16_C(26221), UINT16_C(53477), UINT16_C( 1829), UINT16_C(23457), UINT16_C(17099), UINT16_C( 8090),
        UINT16_C( 1759), UINT16_C(36680), UINT16_C(50255), UINT16_C(17845), UINT16_C(55402), UINT16_C(62793), UINT16_C(37164), UINT16_C(35145),
        UINT16_C(24224), UINT16_C(50342), UINT16_C(32229), UINT16_C(43660), UINT16_C(28703), UINT16_C( 7088), UINT16_C( 2130), UINT16_C(22161),
        UINT16_C(10076), UINT16_C(50535), UINT16_C( 2663), UINT16_C(38740), UINT16_C(12170), UINT16_C(14213), UINT16_C(19517), UINT16_C(31496),
        UINT16_C(30776), UINT16_C( 3086), UINT16_C( 9161), UINT16_C(31071), UINT16_C(11904), UINT16_C(57602), UINT16_C(37005), UINT16_C(36459) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(24758), UINT16_C(25396), UINT16_C(23176), UINT16_C(31453),
        UINT16_C(65211), UINT16_C(52203), UINT16_C(56705), UINT16_C(42499), UINT16_C(53565), UINT16_C(65201), UINT16_C(43872), UINT16_C(61719),
        UINT16_C(60773), UINT16_C(61086), UINT16_C(21265), UINT16_C(58413), UINT16_C(55815), UINT16_C(54732), UINT16_C(38873), UINT16_C(57223),
        UINT16_C( 4408), UINT16_C( 4813), UINT16_C(36982), UINT16_C(13871), UINT16_C(11271), UINT16_C(36169), UINT16_C(50207), UINT16_C(11643),
        UINT16_C(55492), UINT16_C(38152), UINT16_C(51514), UINT16_C(54973), UINT16_C(46901), UINT16_C(28584), UINT16_C(27811), UINT16_C(18763),
        UINT16_C(61410), UINT16_C(16377), UINT16_C(45601), UINT16_C( 3778), UINT16_C(25508), UINT16_C(19710), UINT16_C(31631), UINT16_C(59270),
        UINT16_C( 5203), UINT16_C(   94), UINT16_C(56612), UINT16_C(34850), UINT16_C(24457), UINT16_C(28656), UINT16_C(42785), UINT16_C(15663) },
      {  INT32_C(           0),  INT32_C(       65535), -INT32_C(       65535), -INT32_C(       65535),  INT32_C(       65535),  INT32_C(           0),  INT32_C(        9274),  INT32_C(       24420),
        -INT32_C(       24784),  INT32_C(        3637), -INT32_C(       42432), -INT32_C(       38649), -INT32_C(       19884),  INT32_C(        4956), -INT32_C(       53986), -INT32_C(       21774),
        -INT32_C(        2649),  INT32_C(       13273),  INT32_C(       44131), -INT32_C(       13043), -INT32_C(       31268), -INT32_C(       19285), -INT32_C(       18198), -INT32_C(       25681),
        -INT32_C(       51334), -INT32_C(       42938), -INT32_C(       13338), -INT32_C(       12114),  INT32_C(       25573), -INT32_C(       47451), -INT32_C(       12553), -INT32_C(        5780),
        -INT32_C(       65535),  INT32_C(       65534),  INT32_C(       65534),  INT32_C(           0),  INT32_C(           1), -INT32_C(       65534),  INT32_C(        1534), -INT32_C(       25351),
        -INT32_C(       49552),  INT32_C(       19013), -INT32_C(       14005), -INT32_C(       45512), -INT32_C(       37014), -INT32_C(        4936), -INT32_C(       31275), -INT32_C(       49133),
         INT32_C(       31867),  INT32_C(        3974),  INT32_C(       26624),  INT32_C(       23502),  INT32_C(       12190), -INT32_C(       11313), -INT32_C(       21496),  INT32_C(        3398),
         INT32_C(       34158),  INT32_C(       34962), -INT32_C(        5497), -INT32_C(       27774),  INT32_C(        2992), -INT32_C(        3779),  INT32_C(       28946),  INT32_C(       20796) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vsub_VuhVuh(a, b);

    simde_test_hvx_vectorpair_i32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u16_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vsub_VuhVuh(a, b);

    simde_test_hvx_vector_u16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VubVb_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[SIMDE_HVX_VECTOR_SIZE];
    int8_t b[SIMDE_HVX_VECTOR_SIZE];
    uint8_t r[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C( 95), UINT8_C( 19), UINT8_C(127), UINT8_C( 45),
        UINT8_C(  0), UINT8_C( 34), UINT8_C(210), UINT8_C(  8), UINT8_C(  7), UINT8_C( 46), UINT8_C( 34), UINT8_C(116),
        UINT8_C(114), UINT8_C( 18), UINT8_C(128), UINT8_C(156), UINT8_C(170), UINT8_C(251), UINT8_C(191), UINT8_C(237),
        UINT8_C( 31), UINT8_C(238), UINT8_C(166), UINT8_C( 68), UINT8_C( 55), UINT8_C(128), UINT8_C(144), UINT8_C(179),
        UINT8_C(222), UINT8_C(197), UINT8_C(236), UINT8_C(151), UINT8_C(177), UINT8_C(224), UINT8_C(173), UINT8_C(162),
        UINT8_C( 60), UINT8_C(129), UINT8_C(112), UINT8_C( 81), UINT8_C(231), UINT8_C( 43), UINT8_C(157), UINT8_C( 97),
        UINT8_C(153), UINT8_C(247), UINT8_C(218), UINT8_C( 72), UINT8_C( 59), UINT8_C(190), UINT8_C(233), UINT8_C(107),
        UINT8_C( 61), UINT8_C(216), UINT8_C( 31), UINT8_C(169), UINT8_C(182), UINT8_C(  0), UINT8_C( 41), UINT8_C( 98),
        UINT8_C(243), UINT8_C( 30), UINT8_C( 71), UINT8_C(235), UINT8_C( 93), UINT8_C(198), UINT8_C(250), UINT8_C(112),
        UINT8_C(172), UINT8_C(216), UINT8_C(164), UINT8_C(102), UINT8_C(191), UINT8_C(235), UINT8_C(  7), UINT8_C(184),
        UINT8_C(121), UINT8_C(163), UINT8_C(151), UINT8_C(212), UINT8_C(123), UINT8_C( 32), UINT8_C( 89), UINT8_C( 89),
        UINT8_C( 14), UINT8_C(115), UINT8_C(238), UINT8_C( 85), UINT8_C( 97), UINT8_C( 75), UINT8_C(224), UINT8_C(200),
        UINT8_C(248), UINT8_C(199), UINT8_C(222), UINT8_C(  0), UINT8_C(186), UINT8_C( 49), UINT8_C( 16), UINT8_C(193),
        UINT8_C(103), UINT8_C(164), UINT8_C( 83), UINT8_C( 99), UINT8_C( 39), UINT8_C(137), UINT8_C(104), UINT8_C( 88),
        UINT8_C(116), UINT8_C( 39), UINT8_C( 80), UINT8_C(181), UINT8_C( 67), UINT8_C(234), UINT8_C( 97), UINT8_C( 32) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(  25), -INT8_C( 108), -INT8_C(   4), -INT8_C(  86),
        -INT8_C(  90),  INT8_C(  93),  INT8_C(  96),  INT8_C(  16),  INT8_C( 121),  INT8_C(   1), -INT8_C(  34), -INT8_C(  28),
         INT8_C( 107), -INT8_C( 105),  INT8_C(  18), -INT8_C(  12), -INT8_C(  90), -INT8_C(  76),  INT8_C(  77), -INT8_C(  94),
             INT8_MIN, -INT8_C(  38), -INT8_C( 112), -INT8_C(  86), -INT8_C(  51),      INT8_MAX,  INT8_C( 118),  INT8_C(  51),
        -INT8_C(  53), -INT8_C( 117), -INT8_C(  11), -INT8_C(  86), -INT8_C( 116),  INT8_C(  95),  INT8_C(  71), -INT8_C(  92),
         INT8_C(   3),  INT8_C(  40), -INT8_C(  61), -INT8_C( 117),  INT8_C( 122), -INT8_C( 122), -INT8_C( 104), -INT8_C(  99),
        -INT8_C(  40),  INT8_C(  27),  INT8_C(  77),  INT8_C(  47),  INT8_C( 118), -INT8_C(  90),  INT8_C(  75),  INT8_C( 106),
         INT8_C( 126),  INT8_C(  55), -INT8_C(  76),  INT8_C(  86), -INT8_C(  92),  INT8_C(  73), -INT8_C(  44), -INT8_C( 115),
         INT8_C(  47),  INT8_C(  85), -INT8_C(  18),  INT8_C(  33),  INT8_C(  40),  INT8_C( 124), -INT8_C( 104),  INT8_C( 124),
         INT8_C(  39), -INT8_C(   3),  INT8_C(  19),  INT8_C( 104), -INT8_C( 126),  INT8_C(  99),  INT8_C(  87), -INT8_C(  81),
         INT8_C(  96),  INT8_C( 115),  INT8_C(  63),  INT8_C(  36),  INT8_C(  78), -INT8_C(  83), -INT8_C(  59),  INT8_C(  99),
         INT8_C(  87), -INT8_C(  62), -INT8_C(  15), -INT8_C( 106),  INT8_C(  27),  INT8_C(  85),  INT8_C(  74), -INT8_C(  21),
        -INT8_C(  33), -INT8_C(  29), -INT8_C(  12),  INT8_C(  35), -INT8_C(  45),  INT8_C(  78), -INT8_C(  44), -INT8_C(  57),
         INT8_C(   9),  INT8_C(  86), -INT8_C( 103),  INT8_C(  83),  INT8_C(  30),  INT8_C(  82),  INT8_C( 109),  INT8_C(  10),
        -INT8_C(  19),  INT8_C(   8), -INT8_C(  23), -INT8_C(  85),  INT8_C(  22),  INT8_C(  60),  INT8_C(  67),  INT8_C(   9) },
      { UINT8_C(128), UINT8_C(  0),    UINT8_MAX, UINT8_C(254), UINT8_C(  1), UINT8_C(254), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(129), UINT8_C(128), UINT8_C(  0), UINT8_C(120), UINT8_C(127), UINT8_C(131), UINT8_C(131),
        UINT8_C( 90), UINT8_C(  0), UINT8_C(114), UINT8_C(  0), UINT8_C(  0), UINT8_C( 45), UINT8_C( 68), UINT8_C(144),
        UINT8_C(  7), UINT8_C(123), UINT8_C(110), UINT8_C(168),    UINT8_MAX,    UINT8_MAX, UINT8_C(114),    UINT8_MAX,
        UINT8_C(159),    UINT8_MAX,    UINT8_MAX, UINT8_C(154), UINT8_C(106), UINT8_C(  1), UINT8_C( 26), UINT8_C(128),
           UINT8_MAX,    UINT8_MAX, UINT8_C(247), UINT8_C(237),    UINT8_MAX, UINT8_C(129), UINT8_C(102), UINT8_C(254),
        UINT8_C( 57), UINT8_C( 89), UINT8_C(173), UINT8_C(198), UINT8_C(109), UINT8_C(165),    UINT8_MAX, UINT8_C(196),
        UINT8_C(193), UINT8_C(220), UINT8_C(141), UINT8_C( 25), UINT8_C(  0),    UINT8_MAX, UINT8_C(158), UINT8_C(  1),
        UINT8_C(  0), UINT8_C(161), UINT8_C(107), UINT8_C( 83),    UINT8_MAX, UINT8_C(  0), UINT8_C( 85), UINT8_C(213),
        UINT8_C(196), UINT8_C(  0), UINT8_C( 89), UINT8_C(202), UINT8_C( 53), UINT8_C( 74),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(133), UINT8_C(219), UINT8_C(145), UINT8_C(  0),    UINT8_MAX, UINT8_C(136), UINT8_C(  0),    UINT8_MAX,
        UINT8_C( 25), UINT8_C( 48), UINT8_C( 88), UINT8_C(176), UINT8_C( 45), UINT8_C(115), UINT8_C(148), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(177), UINT8_C(253), UINT8_C(191), UINT8_C( 70), UINT8_C(  0), UINT8_C(150), UINT8_C(221),
           UINT8_MAX, UINT8_C(228), UINT8_C(234), UINT8_C(  0), UINT8_C(231), UINT8_C(  0), UINT8_C( 60), UINT8_C(250),
        UINT8_C( 94), UINT8_C( 78), UINT8_C(186), UINT8_C( 16), UINT8_C(  9), UINT8_C( 55), UINT8_C(  0), UINT8_C( 78),
        UINT8_C(135), UINT8_C( 31), UINT8_C(103),    UINT8_MAX, UINT8_C( 45), UINT8_C(174), UINT8_C( 30), UINT8_C( 23) } },
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(134), UINT8_C( 35), UINT8_C(187), UINT8_C(212),
        UINT8_C(160), UINT8_C( 85), UINT8_C(219), UINT8_C( 53), UINT8_C( 63), UINT8_C( 88), UINT8_C( 59), UINT8_C(174),
        UINT8_C( 69), UINT8_C(115), UINT8_C(118), UINT8_C( 63), UINT8_C( 12), UINT8_C(129), UINT8_C(197), UINT8_C( 30),
        UINT8_C(102), UINT8_C(114), UINT8_C(250), UINT8_C(232), UINT8_C( 57), UINT8_C( 44), UINT8_C(104), UINT8_C( 88),
        UINT8_C( 74), UINT8_C(177), UINT8_C( 31), UINT8_C(193), UINT8_C(229), UINT8_C( 57), UINT8_C( 10), UINT8_C( 34),
        UINT8_C( 28), UINT8_C(115), UINT8_C(171), UINT8_C(214), UINT8_C(216), UINT8_C( 33), UINT8_C( 49), UINT8_C(132),
        UINT8_C( 31), UINT8_C(139), UINT8_C( 50),    UINT8_MAX, UINT8_C( 74), UINT8_C( 37), UINT8_C(169), UINT8_C(215),
        UINT8_C(171), UINT8_C( 83), UINT8_C( 83), UINT8_C(211), UINT8_C(211), UINT8_C( 70), UINT8_C(143), UINT8_C(139),
        UINT8_C(155), UINT8_C(128), UINT8_C(246), UINT8_C(186), UINT8_C(131), UINT8_C( 51), UINT8_C( 21), UINT8_C( 79),
        UINT8_C(158), UINT8_C(171), UINT8_C(189), UINT8_C(  1), UINT8_C( 13), UINT8_C(216), UINT8_C( 77), UINT8_C(173),
        UINT8_C(189), UINT8_C(237), UINT8_C(244), UINT8_C( 46), UINT8_C(205), UINT8_C(131), UINT8_C(  5), UINT8_C(152),
        UINT8_C( 84), UINT8_C( 49), UINT8_C(250), UINT8_C( 73), UINT8_C( 68), UINT8_C(243), UINT8_C(204), UINT8_C(180),
        UINT8_C(143), UINT8_C( 71), UINT8_C( 27),    UINT8_MAX, UINT8_C(168), UINT8_C( 20), UINT8_C(236), UINT8_C(141),
        UINT8_C(106), UINT8_C( 33), UINT8_C(172), UINT8_C( 37), UINT8_C(213), UINT8_C(136), UINT8_C( 25), UINT8_C( 87),
        UINT8_C(  0), UINT8_C(  9), UINT8_C( 17), UINT8_C( 62), UINT8_C(252), UINT8_C(103), UINT8_C(135), UINT8_C( 31) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C( 100), -INT8_C(  67), -INT8_C(  13), -INT8_C( 107),
        -INT8_C(  90),  INT8_C(  81), -INT8_C( 112),  INT8_C( 121),  INT8_C(  35), -INT8_C(  17),  INT8_C(  44),  INT8_C(  16),
         INT8_C(   1), -INT8_C(  82), -INT8_C(  60),  INT8_C(  74), -INT8_C(  81),  INT8_C(  70), -INT8_C(  43),  INT8_C(  61),
         INT8_C( 119), -INT8_C(  82), -INT8_C( 123), -INT8_C(  98),  INT8_C( 108),  INT8_C( 126),  INT8_C(  72),  INT8_C( 105),
        -INT8_C( 127), -INT8_C(  56), -INT8_C(  50), -INT8_C(  32),  INT8_C( 107), -INT8_C(  26),  INT8_C(   9),  INT8_C(  27),
        -INT8_C( 118), -INT8_C(  68),  INT8_C(  11), -INT8_C(  95), -INT8_C( 118), -INT8_C(  33),  INT8_C(  38), -INT8_C( 102),
         INT8_C(  39),  INT8_C(  17),  INT8_C(  38),  INT8_C(  31), -INT8_C(  72), -INT8_C(   8),  INT8_C( 107),  INT8_C(   5),
        -INT8_C( 112), -INT8_C( 108),  INT8_C(  15), -INT8_C( 116), -INT8_C(  43),  INT8_C( 119), -INT8_C(  24),  INT8_C(  77),
        -INT8_C(  14),  INT8_C(  81),  INT8_C(  38), -INT8_C(  75),  INT8_C(  44), -INT8_C( 103),  INT8_C(  33), -INT8_C(  66),
         INT8_C(  26),  INT8_C(   9), -INT8_C(  42), -INT8_C(  49),  INT8_C( 107),  INT8_C(  25),  INT8_C(  50),  INT8_C(  57),
        -INT8_C(  64),  INT8_C(  92), -INT8_C( 106), -INT8_C(  70), -INT8_C(  25), -INT8_C(   8), -INT8_C(   4),      INT8_MAX,
        -INT8_C(  70),  INT8_C(  90),  INT8_C(  82),  INT8_C( 104), -INT8_C(  51), -INT8_C(  17),  INT8_C(  95),  INT8_C( 118),
         INT8_C(  30), -INT8_C( 121),  INT8_C(  62),  INT8_C(  79), -INT8_C(  54),  INT8_C(  46),  INT8_C(  98),  INT8_C( 126),
         INT8_C(  93), -INT8_C(  66), -INT8_C(  43),  INT8_C(  99), -INT8_C( 108), -INT8_C(  94),  INT8_C(   3), -INT8_C( 116),
         INT8_C(  20), -INT8_C(  72), -INT8_C(  85),  INT8_C(  83), -INT8_C( 110),  INT8_C(  27),  INT8_C(  76), -INT8_C(  33) },
      { UINT8_C(128), UINT8_C(  0),    UINT8_MAX, UINT8_C(254), UINT8_C(  1), UINT8_C(254), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(129), UINT8_C(128), UINT8_C(  0), UINT8_C(234), UINT8_C(102), UINT8_C(200),    UINT8_MAX,
        UINT8_C(250), UINT8_C(  4),    UINT8_MAX, UINT8_C(  0), UINT8_C( 28), UINT8_C(105), UINT8_C( 15), UINT8_C(158),
        UINT8_C( 68), UINT8_C(197), UINT8_C(178), UINT8_C(  0), UINT8_C( 93), UINT8_C( 59), UINT8_C(240), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(196),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C( 32), UINT8_C(  0),
        UINT8_C(201), UINT8_C(233), UINT8_C( 81), UINT8_C(225), UINT8_C(122), UINT8_C( 83), UINT8_C(  1), UINT8_C(  7),
        UINT8_C(146), UINT8_C(183), UINT8_C(160),    UINT8_MAX,    UINT8_MAX, UINT8_C( 66), UINT8_C( 11), UINT8_C(234),
        UINT8_C(  0), UINT8_C(122), UINT8_C( 12), UINT8_C(224), UINT8_C(146), UINT8_C( 45), UINT8_C( 62), UINT8_C(210),
           UINT8_MAX, UINT8_C(191), UINT8_C( 68),    UINT8_MAX, UINT8_C(254), UINT8_C(  0), UINT8_C(167), UINT8_C( 62),
        UINT8_C(169), UINT8_C( 47), UINT8_C(208),    UINT8_MAX, UINT8_C( 87), UINT8_C(154), UINT8_C(  0), UINT8_C(145),
        UINT8_C(132), UINT8_C(162), UINT8_C(231), UINT8_C( 50), UINT8_C(  0), UINT8_C(191), UINT8_C( 27), UINT8_C(116),
        UINT8_C(253), UINT8_C(145),    UINT8_MAX, UINT8_C(116), UINT8_C(230), UINT8_C(139), UINT8_C(  9), UINT8_C( 25),
        UINT8_C(154), UINT8_C(  0), UINT8_C(168), UINT8_C(  0), UINT8_C(119),    UINT8_MAX, UINT8_C(109), UINT8_C( 62),
        UINT8_C(113), UINT8_C(192), UINT8_C(  0), UINT8_C(176), UINT8_C(222), UINT8_C(  0), UINT8_C(138), UINT8_C( 15),
        UINT8_C( 13), UINT8_C( 99), UINT8_C(215), UINT8_C(  0),    UINT8_MAX, UINT8_C(230), UINT8_C( 22), UINT8_C(203),
        UINT8_C(  0), UINT8_C( 81), UINT8_C(102), UINT8_C(  0),    UINT8_MAX, UINT8_C( 76), UINT8_C( 59), UINT8_C( 64) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vsub_VubVb_sat(a, b);

    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u8_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i8_random(1);
    simde_hvx_vector_t r = simde_Q6_Vub_vsub_VubVb_sat(a, b);

    simde_test_hvx_vector_u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsub_VwVwQ_carry(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t b[SIMDE_HVX_VECTOR_I32_COUNT];
    uint8_t c[SIMDE_HVX_VECTOR_SIZE];
    int32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
    uint8_t qo[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(  1819140116), -INT32_C(   135869288), -INT32_C(   296419831), -INT32_C(  1670856195),
        -INT32_C(  1488345318), -INT32_C(   728104133), -INT32_C(  2007858735),  INT32_C(  1951909794), -INT32_C(  1537013181),  INT32_C(  1895831331), -INT32_C(  2070768391), -INT32_C(   134461495),
        -INT32_C(  1483989669), -INT32_C(  1708541533),  INT32_C(  1179991422), -INT32_C(   634343803), -INT32_C(   836128690), -INT32_C(  1922089693), -INT32_C(  1020581392),  INT32_C(   488762293) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX, -INT32_C(  2034400896),  INT32_C(  1250629256), -INT32_C(  1015797448), -INT32_C(  1696331626),
        -INT32_C(    38763440),  INT32_C(   982562448),  INT32_C(   526241969), -INT32_C(   247383776), -INT32_C(  1959567011),  INT32_C(   190836025),  INT32_C(  1072032851),  INT32_C(   868651743),
         INT32_C(  1821155368), -INT32_C(  1619040075), -INT32_C(  1889203329), -INT32_C(  1220998683),  INT32_C(  1569602890), -INT32_C(   749658939),  INT32_C(  1603204535),  INT32_C(       87168) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX },
      {  INT32_C(           0),  INT32_C(           1),              INT32_MAX,  INT32_C(  2147483645),              INT32_MIN,  INT32_C(  2147483645), -INT32_C(  2147483647), -INT32_C(           1),
                     INT32_MAX,              INT32_MIN,  INT32_C(           0), -INT32_C(  2147483647),  INT32_C(   215260779), -INT32_C(  1386498545),  INT32_C(   719377616),  INT32_C(    25475430),
        -INT32_C(  1449581878), -INT32_C(  1710666582),  INT32_C(  1760866592), -INT32_C(  2095673726),  INT32_C(   422553829),  INT32_C(  1704995305),  INT32_C(  1152166054), -INT32_C(  1003113239),
         INT32_C(   989822258), -INT32_C(    89501459), -INT32_C(  1225772545),  INT32_C(   586654879),  INT32_C(  1889235715), -INT32_C(  1172430755),  INT32_C(  1671181369),  INT32_C(   488675125) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(   318853050),  INT32_C(  2052997531), -INT32_C(  1674301652),  INT32_C(  1905438436),
         INT32_C(  1431160703),  INT32_C(  2043544121), -INT32_C(  1814239830),  INT32_C(  1979964375), -INT32_C(  1125332849),  INT32_C(   567231246),  INT32_C(   474348280),  INT32_C(  1960649097),
        -INT32_C(  1175396192), -INT32_C(  1207301834),  INT32_C(   114134524),  INT32_C(  2118002804), -INT32_C(   836623444),  INT32_C(    94662351),  INT32_C(   650420593),  INT32_C(   234183088) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(   622142473), -INT32_C(  1540866241),  INT32_C(   403461553), -INT32_C(   176972601),
        -INT32_C(  1721272800), -INT32_C(   204442978), -INT32_C(  1755494643), -INT32_C(  1399585987),  INT32_C(   679289415), -INT32_C(   191515570),  INT32_C(  1913781745), -INT32_C(  1915804119),
        -INT32_C(  1633663039),  INT32_C(   919561589), -INT32_C(   713514384), -INT32_C(  1028925330), -INT32_C(  1423775679), -INT32_C(   748608202), -INT32_C(  1084402814),  INT32_C(   908487296) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      { -INT32_C(           1),  INT32_C(           0),  INT32_C(  2147483646),  INT32_C(  2147483645), -INT32_C(  2147483647),  INT32_C(  2147483646),              INT32_MIN,  INT32_C(           0),
         INT32_C(  2147483646), -INT32_C(  2147483647), -INT32_C(           1), -INT32_C(  2147483647), -INT32_C(   940995524), -INT32_C(   701103525), -INT32_C(  2077763205),  INT32_C(  2082411036),
        -INT32_C(  1142533793), -INT32_C(  2046980197), -INT32_C(    58745187), -INT32_C(   915416935), -INT32_C(  1804622265),  INT32_C(   758746816), -INT32_C(  1439433465), -INT32_C(   418514081),
         INT32_C(   458266847), -INT32_C(  2126863424),  INT32_C(   827648908), -INT32_C(  1148039162),  INT32_C(   587152234),  INT32_C(   843270553),  INT32_C(  1734823406), -INT32_C(   674304208) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpred_t c = simde_test_hvx_vectorpred_load(test_vec[i].c);
    simde_hvx_vector_t r = simde_Q6_Vw_vsub_VwVwQ_carry(a, b, &c);

    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
    simde_test_hvx_vectorpred_assert_equal(c, simde_test_hvx_vectorpred_load(test_vec[i].qo));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i32_random(1);
    simde_hvx_vectorpred_t c = simde_test_hvx_vectorpred_random();
    simde_hvx_vectorpred_t c_in = c;
    simde_hvx_vector_t r = simde_Q6_Vw_vsub_VwVwQ_carry(a, b, &c);

    simde_test_hvx_vector_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpred_write(2, c_in, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i32_write(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpred_write(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VwVw)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VbVb_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VhVh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VwVw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VubVub_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VuhVuh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VuwVuw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_WbWb)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_WhWh)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_WwWw)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_WbWb_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_WhWh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_WwWw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_WubWub_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_WuhWuh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_WuwWuw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VubVub)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VhVh_widen)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VuhVuh_widen)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VubVb_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_VwVwQ_carry)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
