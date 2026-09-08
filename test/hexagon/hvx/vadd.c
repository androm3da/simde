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

#define SIMDE_TEST_HEXAGON_HVX_INSN vadd

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vadd.h"

static int
test_simde_vadd_VbVb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[SIMDE_HVX_VECTOR_SIZE];
    int8_t b[SIMDE_HVX_VECTOR_SIZE];
    int8_t r[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1), -INT8_C(  48), -INT8_C(  54), -INT8_C(  50), -INT8_C( 114),
         INT8_C(  17), -INT8_C(  63),  INT8_C(  79), -INT8_C(  56), -INT8_C(  34), -INT8_C( 100),  INT8_C(  64),  INT8_C(  32),
         INT8_C(  80),  INT8_C(  76), -INT8_C(  66), -INT8_C(  75), -INT8_C(  68), -INT8_C(  10), -INT8_C(  66),  INT8_C(  45),
        -INT8_C(  21),  INT8_C( 103),  INT8_C(  68),  INT8_C(  52),  INT8_C( 105), -INT8_C(  25),  INT8_C( 108),  INT8_C(  35),
        -INT8_C(  10),  INT8_C(  22),  INT8_C(  56),  INT8_C(  15),  INT8_C(  65),  INT8_C(  44), -INT8_C(  31),  INT8_C( 102),
        -INT8_C( 104),  INT8_C(  80),  INT8_C(   0),  INT8_C( 102), -INT8_C(  76),  INT8_C( 110),  INT8_C(  96), -INT8_C( 111),
         INT8_C(  90),  INT8_C(  93),  INT8_C(  76),  INT8_C(  52), -INT8_C(  26), -INT8_C( 127), -INT8_C(   2), -INT8_C( 114),
         INT8_C(  23), -INT8_C(  35), -INT8_C(  62),  INT8_C(  75),  INT8_C(  10),  INT8_C(  31), -INT8_C(  14), -INT8_C( 105),
        -INT8_C(  55), -INT8_C(  47),  INT8_C(  83),  INT8_C(   4),  INT8_C(  68),  INT8_C(  49),  INT8_C(  57), -INT8_C( 115),
         INT8_C( 126),  INT8_C(  65),  INT8_C(  52),  INT8_C(  72), -INT8_C(  63), -INT8_C(  12),      INT8_MIN, -INT8_C( 126),
         INT8_C( 125), -INT8_C(  94), -INT8_C( 122), -INT8_C(  11),  INT8_C( 126), -INT8_C(  71),  INT8_C(  62), -INT8_C(  95),
        -INT8_C( 101),  INT8_C(  77),  INT8_C(  98), -INT8_C(   4),  INT8_C(  51),  INT8_C(  91), -INT8_C(  77),  INT8_C(  11),
        -INT8_C(  98), -INT8_C(  33),  INT8_C(   5),  INT8_C(  10), -INT8_C(  99), -INT8_C(  20),  INT8_C( 120), -INT8_C( 102),
         INT8_C(  74), -INT8_C(  79), -INT8_C(  86), -INT8_C(  51),  INT8_C(  85),  INT8_C( 101),  INT8_C(  15), -INT8_C(  36),
        -INT8_C(  43), -INT8_C(  22), -INT8_C( 126),  INT8_C(  99),  INT8_C(  63), -INT8_C(  95), -INT8_C(  35),  INT8_C(   4) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  46),  INT8_C(  82), -INT8_C(  62), -INT8_C(  48),
         INT8_C( 118), -INT8_C(  76), -INT8_C( 126), -INT8_C( 103),  INT8_C(  76),  INT8_C( 101), -INT8_C(  96),  INT8_C(  65),
         INT8_C(  60), -INT8_C(  80),  INT8_C(  20),  INT8_C(  69),  INT8_C(  81),  INT8_C(  80),  INT8_C(  62), -INT8_C(  20),
        -INT8_C( 110), -INT8_C(  94), -INT8_C( 112),  INT8_C(  40), -INT8_C(  12),  INT8_C(  53), -INT8_C( 124),  INT8_C( 110),
        -INT8_C(  24),  INT8_C( 103),  INT8_C(  48), -INT8_C(  70),  INT8_C( 124), -INT8_C(   7), -INT8_C(  98),  INT8_C(  84),
         INT8_C( 103), -INT8_C(  61),  INT8_C(   9), -INT8_C(   7),  INT8_C( 114),  INT8_C(  38), -INT8_C(  80), -INT8_C( 105),
         INT8_C(  37), -INT8_C(  21),  INT8_C( 125),  INT8_C( 126), -INT8_C( 102),  INT8_C( 109),  INT8_C( 100),  INT8_C(  24),
         INT8_C( 109),  INT8_C( 114),  INT8_C(  12),  INT8_C(  53),  INT8_C(  32),  INT8_C(  93), -INT8_C( 102),  INT8_C(  49),
         INT8_C(  85), -INT8_C(  31), -INT8_C(  73), -INT8_C(   5), -INT8_C(  70),  INT8_C(  85),  INT8_C(  85), -INT8_C(  38),
        -INT8_C(  26), -INT8_C(  93),  INT8_C(   6), -INT8_C(  58),  INT8_C( 110),  INT8_C(   0), -INT8_C(  32),  INT8_C(  34),
        -INT8_C(  21),  INT8_C(  86), -INT8_C( 103),  INT8_C(  83),  INT8_C( 121),  INT8_C(  37),  INT8_C(  21),  INT8_C(  64),
         INT8_C(  99), -INT8_C(  26),  INT8_C(  30), -INT8_C(  56), -INT8_C(  54), -INT8_C(  46),  INT8_C( 120), -INT8_C(  61),
         INT8_C(  96),  INT8_C(  67),  INT8_C(  79),  INT8_C(   5),  INT8_C(  74),  INT8_C( 111), -INT8_C(  48), -INT8_C(  35),
         INT8_C(  23), -INT8_C(  44), -INT8_C( 114), -INT8_C(  56),  INT8_C(  37), -INT8_C( 114), -INT8_C(  75),  INT8_C(  18),
        -INT8_C(  79),  INT8_C(  60), -INT8_C( 110),  INT8_C(  44),  INT8_C(  23), -INT8_C(  83),  INT8_C( 117),  INT8_C(  13) },
      {  INT8_C(   0), -INT8_C(   1),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   2),
             INT8_MAX, -INT8_C( 127), -INT8_C(   2),      INT8_MIN, -INT8_C(   2),  INT8_C(  28), -INT8_C( 112),  INT8_C(  94),
        -INT8_C( 121),  INT8_C( 117), -INT8_C(  47),  INT8_C(  97),  INT8_C(  42),  INT8_C(   1), -INT8_C(  32),  INT8_C(  97),
        -INT8_C( 116), -INT8_C(   4), -INT8_C(  46), -INT8_C(   6),  INT8_C(  13),  INT8_C(  70), -INT8_C(   4),  INT8_C(  25),
         INT8_C( 125),  INT8_C(   9), -INT8_C(  44),  INT8_C(  92),  INT8_C(  93),  INT8_C(  28), -INT8_C(  16), -INT8_C( 111),
        -INT8_C(  34),  INT8_C( 125),  INT8_C( 104), -INT8_C(  55), -INT8_C(  67),  INT8_C(  37),      INT8_MAX, -INT8_C(  70),
        -INT8_C(   1),  INT8_C(  19),  INT8_C(   9),  INT8_C(  95),  INT8_C(  38), -INT8_C( 108),  INT8_C(  16),  INT8_C(  40),
             INT8_MAX,  INT8_C(  72), -INT8_C(  55), -INT8_C(  78),      INT8_MIN, -INT8_C(  18),  INT8_C(  98), -INT8_C(  90),
        -INT8_C( 124),  INT8_C(  79), -INT8_C(  50),      INT8_MIN,  INT8_C(  42),  INT8_C( 124), -INT8_C( 116), -INT8_C(  56),
         INT8_C(  30), -INT8_C(  78),  INT8_C(  10), -INT8_C(   1), -INT8_C(   2), -INT8_C( 122), -INT8_C( 114),  INT8_C( 103),
         INT8_C( 100), -INT8_C(  28),  INT8_C(  58),  INT8_C(  14),  INT8_C(  47), -INT8_C(  12),  INT8_C(  96), -INT8_C(  92),
         INT8_C( 104), -INT8_C(   8),  INT8_C(  31),  INT8_C(  72), -INT8_C(   9), -INT8_C(  34),  INT8_C(  83), -INT8_C(  31),
        -INT8_C(   2),  INT8_C(  51),      INT8_MIN, -INT8_C(  60), -INT8_C(   3),  INT8_C(  45),  INT8_C(  43), -INT8_C(  50),
        -INT8_C(   2),  INT8_C(  34),  INT8_C(  84),  INT8_C(  15), -INT8_C(  25),  INT8_C(  91),  INT8_C(  72),  INT8_C( 119),
         INT8_C(  97), -INT8_C( 123),  INT8_C(  56), -INT8_C( 107),  INT8_C( 122), -INT8_C(  13), -INT8_C(  60), -INT8_C(  18),
        -INT8_C( 122),  INT8_C(  38),  INT8_C(  20), -INT8_C( 113),  INT8_C(  86),  INT8_C(  78),  INT8_C(  82),  INT8_C(  17) } },
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1), -INT8_C(  56),  INT8_C(  35), -INT8_C(   9),  INT8_C(  79),
        -INT8_C(  17),  INT8_C( 121),  INT8_C(  78), -INT8_C( 105), -INT8_C(  91),  INT8_C(  68), -INT8_C(  42), -INT8_C( 102),
        -INT8_C(  77), -INT8_C(  59),  INT8_C(   8), -INT8_C(  42),  INT8_C(  38),  INT8_C(  55),  INT8_C(  39), -INT8_C( 118),
        -INT8_C( 112), -INT8_C(  42), -INT8_C( 104), -INT8_C(  61), -INT8_C( 103), -INT8_C(  48),  INT8_C( 116), -INT8_C(  52),
         INT8_C(  23), -INT8_C(  82),  INT8_C(  46), -INT8_C(  14), -INT8_C( 109), -INT8_C(  38), -INT8_C( 111), -INT8_C(  48),
         INT8_C(  41), -INT8_C(  59),  INT8_C(  95),  INT8_C(   3), -INT8_C( 119), -INT8_C( 111), -INT8_C(  50),      INT8_MAX,
         INT8_C(  31), -INT8_C(  67), -INT8_C(  56),  INT8_C(  73),  INT8_C(  47),  INT8_C( 112), -INT8_C(  17),  INT8_C(  22),
         INT8_C(  93),  INT8_C(  49),  INT8_C(   1),  INT8_C(  64),  INT8_C( 110), -INT8_C(  37),  INT8_C(  55),  INT8_C(  83),
        -INT8_C(  76), -INT8_C(  28),  INT8_C(  23),  INT8_C(  21), -INT8_C(  50), -INT8_C(  61), -INT8_C(  93),  INT8_C(  92),
        -INT8_C(  62), -INT8_C(  26), -INT8_C( 112), -INT8_C(  16), -INT8_C(  31),  INT8_C( 119),  INT8_C(  73),  INT8_C(  47),
         INT8_C( 108), -INT8_C(  32), -INT8_C(  12), -INT8_C(  22),  INT8_C(  84),  INT8_C( 122), -INT8_C(  54), -INT8_C(  41),
         INT8_C(  96), -INT8_C(  56), -INT8_C(  90),  INT8_C(  49), -INT8_C(  16),  INT8_C( 111), -INT8_C( 120), -INT8_C(  14),
        -INT8_C( 127), -INT8_C(  18), -INT8_C(  77),  INT8_C(   7), -INT8_C(  21), -INT8_C( 109),  INT8_C(  78), -INT8_C( 126),
        -INT8_C(  20),  INT8_C( 110),  INT8_C(  55), -INT8_C(  65), -INT8_C( 103), -INT8_C(  94), -INT8_C(  45),  INT8_C(  82),
         INT8_C(  49), -INT8_C(  87), -INT8_C(  74),  INT8_C(  75), -INT8_C( 103),  INT8_C( 105), -INT8_C( 109), -INT8_C(  80) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(  78), -INT8_C(  69),  INT8_C(  44),  INT8_C(  18),
        -INT8_C( 124),  INT8_C(  64), -INT8_C( 124),  INT8_C(  46),  INT8_C(  95),  INT8_C(  11),  INT8_C(  21), -INT8_C(  36),
         INT8_C( 124), -INT8_C( 104),  INT8_C( 112),  INT8_C( 116), -INT8_C(  85),  INT8_C(  59),  INT8_C(  31), -INT8_C(  80),
        -INT8_C(  56),  INT8_C(  20), -INT8_C(  18), -INT8_C(  64), -INT8_C(  28), -INT8_C(  11), -INT8_C(  49), -INT8_C(  87),
         INT8_C(  92), -INT8_C(  80), -INT8_C(  65), -INT8_C(  86), -INT8_C(  57),  INT8_C(  36),  INT8_C(  54),  INT8_C(  88),
         INT8_C(  15), -INT8_C(   6),  INT8_C(  71), -INT8_C(  69),  INT8_C(  13),  INT8_C(  11), -INT8_C( 102), -INT8_C(  96),
        -INT8_C(  88),  INT8_C(   0),  INT8_C( 102), -INT8_C(  97),  INT8_C(  38),  INT8_C(  84), -INT8_C(  34),  INT8_C(   7),
        -INT8_C(  47), -INT8_C(   1), -INT8_C( 117),  INT8_C(  82),  INT8_C(   1), -INT8_C(  62), -INT8_C(  26),  INT8_C( 112),
         INT8_C(  55),  INT8_C(  31),  INT8_C(  69), -INT8_C(  93), -INT8_C(  79),  INT8_C( 109),  INT8_C(  26), -INT8_C(  58),
         INT8_C(  42), -INT8_C(  33),  INT8_C(  73), -INT8_C( 117), -INT8_C( 114), -INT8_C(   4),  INT8_C(   7),  INT8_C( 103),
        -INT8_C(  74),  INT8_C(  80), -INT8_C(  15),      INT8_MIN,  INT8_C(  95),  INT8_C( 123), -INT8_C(   7),  INT8_C( 123),
         INT8_C(  69),  INT8_C( 105), -INT8_C(  13),  INT8_C(  13), -INT8_C(  15),  INT8_C(   5),  INT8_C(  77), -INT8_C(  49),
        -INT8_C( 118),  INT8_C( 105),  INT8_C(   8),      INT8_MAX,  INT8_C(  97), -INT8_C(  93),  INT8_C(  34),  INT8_C(  48),
        -INT8_C( 122),  INT8_C(  71),  INT8_C(  20), -INT8_C(  59),  INT8_C(  66),  INT8_C(  80), -INT8_C(  32),      INT8_MAX,
         INT8_C(  35), -INT8_C(  33),  INT8_C(  47),  INT8_C(   7), -INT8_C(  90),  INT8_C(  82), -INT8_C(  17),  INT8_C(  85) },
      {  INT8_C(   0), -INT8_C(   1),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   2),
             INT8_MAX, -INT8_C( 127), -INT8_C(   2),      INT8_MIN,  INT8_C( 122), -INT8_C(  34),  INT8_C(  35),  INT8_C(  97),
         INT8_C( 115), -INT8_C(  71), -INT8_C(  46), -INT8_C(  59),  INT8_C(   4),  INT8_C(  79), -INT8_C(  21),  INT8_C( 118),
         INT8_C(  47),  INT8_C(  93),  INT8_C( 120),  INT8_C(  74), -INT8_C(  47),  INT8_C( 114),  INT8_C(  70),  INT8_C(  58),
         INT8_C(  88), -INT8_C(  22), -INT8_C( 122), -INT8_C( 125),  INT8_C( 125), -INT8_C(  59),  INT8_C(  67),  INT8_C( 117),
         INT8_C( 115),  INT8_C(  94), -INT8_C(  19), -INT8_C( 100),  INT8_C(  90), -INT8_C(   2), -INT8_C(  57),  INT8_C(  40),
         INT8_C(  56), -INT8_C(  65), -INT8_C(  90), -INT8_C(  66), -INT8_C( 106), -INT8_C( 100),  INT8_C( 104),  INT8_C(  31),
        -INT8_C(  57), -INT8_C(  67),  INT8_C(  46), -INT8_C(  24),  INT8_C(  85), -INT8_C(  60), -INT8_C(  51),  INT8_C(  29),
         INT8_C(  46),  INT8_C(  48), -INT8_C( 116), -INT8_C( 110),  INT8_C( 111), -INT8_C(  99),  INT8_C(  29), -INT8_C(  61),
        -INT8_C(  21),  INT8_C(   3),  INT8_C(  92), -INT8_C(  72),      INT8_MAX,  INT8_C(  48), -INT8_C(  67),  INT8_C(  34),
        -INT8_C(  20), -INT8_C(  59), -INT8_C(  39),  INT8_C( 123),  INT8_C( 111),  INT8_C( 115),  INT8_C(  80), -INT8_C( 106),
         INT8_C(  34),  INT8_C(  48), -INT8_C(  27),  INT8_C( 106), -INT8_C(  77), -INT8_C(  11), -INT8_C(  61),  INT8_C(  82),
        -INT8_C(  91),  INT8_C(  49), -INT8_C( 103),  INT8_C(  62), -INT8_C(  31),  INT8_C( 116), -INT8_C(  43), -INT8_C(  63),
         INT8_C(  11),  INT8_C(  87), -INT8_C(  69), -INT8_C( 122),  INT8_C(  76),  INT8_C(  54),  INT8_C( 112), -INT8_C(  78),
         INT8_C( 114), -INT8_C(  75),  INT8_C(  75), -INT8_C( 124), -INT8_C(  37), -INT8_C(  14), -INT8_C(  77), -INT8_C(  47),
         INT8_C(  84), -INT8_C( 120), -INT8_C(  27),  INT8_C(  82),  INT8_C(  63), -INT8_C(  69), -INT8_C( 126),  INT8_C(   5) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vb_vadd_VbVb(a, b);

    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i8_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i8_random(1);
    simde_hvx_vector_t r = simde_Q6_Vb_vadd_VbVb(a, b);

    simde_test_hvx_vector_i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VhVh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t r[SIMDE_HVX_VECTOR_I16_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C( 14909), -INT16_C( 24274),  INT16_C( 21520), -INT16_C(  9032),
         INT16_C( 13757),  INT16_C(  3572),  INT16_C(  2270),  INT16_C(  2771), -INT16_C( 18702), -INT16_C( 13567),  INT16_C(  5271), -INT16_C( 17293),
         INT16_C( 18788),  INT16_C(  4438), -INT16_C( 27888),  INT16_C( 26657), -INT16_C(  6147), -INT16_C(   100),  INT16_C( 19392),  INT16_C( 16737),
        -INT16_C( 31407), -INT16_C( 30115),  INT16_C( 23906), -INT16_C( 28558),  INT16_C( 24208), -INT16_C(  5472),  INT16_C( 10450),  INT16_C(  7966),
        -INT16_C( 22190),  INT16_C(  5114), -INT16_C(  9755), -INT16_C( 25197), -INT16_C( 18082),  INT16_C( 21499),  INT16_C( 21418),  INT16_C(  5420),
         INT16_C(   865),  INT16_C( 26063), -INT16_C( 30314),  INT16_C( 10717), -INT16_C( 16541), -INT16_C( 11855), -INT16_C( 12853), -INT16_C(  6930),
         INT16_C( 27074), -INT16_C( 23331), -INT16_C(  5198), -INT16_C( 28032), -INT16_C( 27087),  INT16_C(  6473),  INT16_C( 19931),  INT16_C( 15919) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C( 15752),  INT16_C( 22066), -INT16_C(  8380),  INT16_C( 25971),
        -INT16_C( 10100), -INT16_C( 12069), -INT16_C( 27889), -INT16_C( 31121), -INT16_C( 28047),  INT16_C( 13469), -INT16_C( 12861),  INT16_C(  9633),
        -INT16_C(  7531), -INT16_C( 22164), -INT16_C( 12383),  INT16_C( 22943), -INT16_C( 21448),  INT16_C( 24512), -INT16_C(  4871), -INT16_C(  4461),
         INT16_C( 12805),  INT16_C( 14844),  INT16_C(  8599),  INT16_C( 20820), -INT16_C(  3123),  INT16_C( 10007), -INT16_C( 20513), -INT16_C( 14976),
        -INT16_C( 23924), -INT16_C( 17481), -INT16_C(   170), -INT16_C( 18028),  INT16_C( 14549),  INT16_C(  5770), -INT16_C( 28159),  INT16_C( 26587),
        -INT16_C( 26717),  INT16_C( 31695),  INT16_C(  6181),  INT16_C( 25596), -INT16_C( 31404),  INT16_C( 22176),  INT16_C(  9862), -INT16_C(  3394),
         INT16_C(  9881), -INT16_C(  9317),  INT16_C( 28022), -INT16_C( 26235), -INT16_C( 29977), -INT16_C( 19872), -INT16_C( 23657), -INT16_C( 32538) },
      {  INT16_C(     0), -INT16_C(     1),        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     2),
               INT16_MAX,       -INT16_MAX, -INT16_C(     2),        INT16_MIN, -INT16_C(   843), -INT16_C(  2208),  INT16_C( 13140),  INT16_C( 16939),
         INT16_C(  3657), -INT16_C(  8497), -INT16_C( 25619), -INT16_C( 28350),  INT16_C( 18787), -INT16_C(    98), -INT16_C(  7590), -INT16_C(  7660),
         INT16_C( 11257), -INT16_C( 17726),  INT16_C( 25265), -INT16_C( 15936), -INT16_C( 27595),  INT16_C( 24412),  INT16_C( 14521),  INT16_C( 12276),
        -INT16_C( 18602), -INT16_C( 15271),  INT16_C( 32505), -INT16_C(  7738),  INT16_C( 21085),  INT16_C(  4535), -INT16_C( 10063), -INT16_C(  7010),
         INT16_C( 19422), -INT16_C( 12367), -INT16_C(  9925),  INT16_C( 22311), -INT16_C(  3533),  INT16_C( 27269), -INT16_C(  6741),  INT16_C( 32007),
        -INT16_C( 25852), -INT16_C(  7778), -INT16_C( 24133), -INT16_C( 29223),  INT16_C( 17591),  INT16_C( 10321), -INT16_C(  2991), -INT16_C( 10324),
        -INT16_C( 28581), -INT16_C( 32648),  INT16_C( 22824),  INT16_C( 11269),  INT16_C(  8472), -INT16_C( 13399), -INT16_C(  3726), -INT16_C( 16619) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C( 20368),  INT16_C(   380), -INT16_C( 24590),  INT16_C( 30399),
         INT16_C( 24820),  INT16_C( 26015),  INT16_C( 18301),  INT16_C( 19519), -INT16_C( 26164), -INT16_C( 17714),  INT16_C( 22084),  INT16_C(  4739),
         INT16_C( 14890), -INT16_C(  8775),  INT16_C(  3789),  INT16_C(  3965), -INT16_C( 29101),  INT16_C( 11060),  INT16_C( 13198),  INT16_C(  3967),
         INT16_C( 15538), -INT16_C(  5448), -INT16_C( 22746), -INT16_C(  6220), -INT16_C( 18596), -INT16_C( 29401), -INT16_C( 23101),  INT16_C( 27521),
         INT16_C( 29514),  INT16_C( 27362),  INT16_C(  1101), -INT16_C( 17698), -INT16_C(  4755), -INT16_C(  3549),  INT16_C( 12272),  INT16_C(  1899),
        -INT16_C(  4712), -INT16_C( 15270), -INT16_C(  2717),  INT16_C( 30494), -INT16_C( 11264),  INT16_C( 24404), -INT16_C( 21971),  INT16_C(   783),
         INT16_C(  5926), -INT16_C( 24666),  INT16_C( 29981), -INT16_C( 17935),  INT16_C( 31916),  INT16_C( 31197),  INT16_C(  1266),  INT16_C(  1685) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C(  1475), -INT16_C( 30951), -INT16_C( 16508),  INT16_C(  4345),
        -INT16_C(  2224),  INT16_C( 24077), -INT16_C(  1876),  INT16_C(  8587), -INT16_C( 22439),  INT16_C( 10328), -INT16_C( 25259),  INT16_C( 22091),
         INT16_C(  3275), -INT16_C( 16966),  INT16_C( 16544),  INT16_C( 14162), -INT16_C( 11484),  INT16_C( 17512), -INT16_C( 31754),  INT16_C( 31517),
        -INT16_C( 24390),  INT16_C( 23473), -INT16_C( 21229),  INT16_C(  7270),  INT16_C(  1799),  INT16_C( 17368), -INT16_C( 28504),  INT16_C(  6863),
         INT16_C(  1817), -INT16_C( 17106),  INT16_C(  9015), -INT16_C( 18828), -INT16_C(   684), -INT16_C( 31141), -INT16_C( 31296),  INT16_C( 24881),
        -INT16_C( 28311), -INT16_C(  4702), -INT16_C( 30573), -INT16_C(  2973),  INT16_C( 19561),  INT16_C( 13018),  INT16_C( 14743),  INT16_C(  5576),
         INT16_C(  6556), -INT16_C(  8799),  INT16_C( 18480),  INT16_C( 11249),  INT16_C( 13767), -INT16_C( 29897), -INT16_C( 31034), -INT16_C( 27732) },
      {  INT16_C(     0), -INT16_C(     1),        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     2),
               INT16_MAX,       -INT16_MAX, -INT16_C(     2),        INT16_MIN,  INT16_C( 21843), -INT16_C( 30571),  INT16_C( 24438), -INT16_C( 30792),
         INT16_C( 22596), -INT16_C( 15444),  INT16_C( 16425),  INT16_C( 28106),  INT16_C( 16933), -INT16_C(  7386), -INT16_C(  3175),  INT16_C( 26830),
         INT16_C( 18165), -INT16_C( 25741),  INT16_C( 20333),  INT16_C( 18127),  INT16_C( 24951),  INT16_C( 28572), -INT16_C( 18556), -INT16_C( 30052),
        -INT16_C(  8852),  INT16_C( 18025),  INT16_C( 21561),  INT16_C(  1050), -INT16_C( 16797), -INT16_C( 12033),  INT16_C( 13931), -INT16_C( 31152),
         INT16_C( 31331),  INT16_C( 10256),  INT16_C( 10116),  INT16_C( 29010), -INT16_C(  5439),  INT16_C( 30846), -INT16_C( 19024),  INT16_C( 26780),
         INT16_C( 32513), -INT16_C( 19972),  INT16_C( 32246),  INT16_C( 27521),  INT16_C(  8297), -INT16_C( 28114), -INT16_C(  7228),  INT16_C(  6359),
         INT16_C( 12482),  INT16_C( 32071), -INT16_C( 17075), -INT16_C(  6686), -INT16_C( 19853),  INT16_C(  1300), -INT16_C( 29768), -INT16_C( 26047) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vadd_VhVh(a, b);

    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i16_random(1);
    simde_hvx_vector_t r = simde_Q6_Vh_vadd_VhVh(a, b);

    simde_test_hvx_vector_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VwVw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t b[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(   272389948), -INT32_C(  1729822939),  INT32_C(    64668769), -INT32_C(   548100501),
        -INT32_C(  2116870881),  INT32_C(  1391336159),  INT32_C(  1791281143),  INT32_C(   864477171),  INT32_C(   161058984), -INT32_C(   678871173), -INT32_C(   372009065), -INT32_C(  1217504905),
        -INT32_C(   626599712),  INT32_C(    26894966),  INT32_C(   181342959),  INT32_C(  2118360284),  INT32_C(   880824657),  INT32_C(  1105383992),  INT32_C(  2062844763), -INT32_C(  1098406487) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(  1381459041),  INT32_C(   220629345),  INT32_C(   890811804), -INT32_C(  1107834143),
        -INT32_C(  1998897793),  INT32_C(  2122185097),  INT32_C(   336617906),  INT32_C(  1815143755),  INT32_C(  1483835327),  INT32_C(  1585045377), -INT32_C(  1539576545),  INT32_C(   592629979),
        -INT32_C(  1573332637),  INT32_C(  1497314891),  INT32_C(   442290770), -INT32_C(   381321648), -INT32_C(    41801801),  INT32_C(  1649321403),  INT32_C(  1353202538), -INT32_C(   160283664) },
      {  INT32_C(           0), -INT32_C(           1),              INT32_MAX,              INT32_MIN,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           2),
                     INT32_MAX, -INT32_C(  2147483647), -INT32_C(           2),              INT32_MIN,  INT32_C(  1653848989), -INT32_C(  1509193594),  INT32_C(   955480573), -INT32_C(  1655934644),
         INT32_C(   179198622), -INT32_C(   781446040),  INT32_C(  2127899049), -INT32_C(  1615346370),  INT32_C(  1644894311),  INT32_C(   906174204), -INT32_C(  1911585610), -INT32_C(   624874926),
         INT32_C(  2095034947),  INT32_C(  1524209857),  INT32_C(   623633729),  INT32_C(  1737038636),  INT32_C(   839022856), -INT32_C(  1540261901), -INT32_C(   878919995), -INT32_C(  1258690151) } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(  1250705604), -INT32_C(  2009414820),  INT32_C(   515570503),  INT32_C(  1875477517),
        -INT32_C(   799912937),  INT32_C(   754088847),  INT32_C(  1299236382), -INT32_C(   809116526),  INT32_C(  1766828617), -INT32_C(  1546439761), -INT32_C(  1185925194), -INT32_C(  1845855122),
        -INT32_C(  1779272458),  INT32_C(  1300160462), -INT32_C(  1992704595),  INT32_C(  1459713159),  INT32_C(  1144343389),  INT32_C(   166656062), -INT32_C(  1963771948),  INT32_C(  2124916908) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(   575028202),  INT32_C(   275789592),  INT32_C(  1986720945),  INT32_C(   612028254),
        -INT32_C(   259104830),  INT32_C(  2145122028),  INT32_C(   338127741), -INT32_C(  1096030998), -INT32_C(  1289879989),  INT32_C(   324078950), -INT32_C(  1612663549), -INT32_C(   948678798),
         INT32_C(   910118459), -INT32_C(   953262533),  INT32_C(  1990953595),  INT32_C(   521729617), -INT32_C(   830949902), -INT32_C(   911693500),  INT32_C(   495277657),  INT32_C(  1884127663) },
      {  INT32_C(           0), -INT32_C(           1),              INT32_MAX,              INT32_MIN,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           2),
                     INT32_MAX, -INT32_C(  2147483647), -INT32_C(           2),              INT32_MIN, -INT32_C(   675677402), -INT32_C(  1733625228), -INT32_C(  1792675848), -INT32_C(  1807461525),
        -INT32_C(  1059017767), -INT32_C(  1395756421),  INT32_C(  1637364123), -INT32_C(  1905147524),  INT32_C(   476948628), -INT32_C(  1222360811),  INT32_C(  1496378553),  INT32_C(  1500433376),
        -INT32_C(   869153999),  INT32_C(   346897929), -INT32_C(     1751000),  INT32_C(  1981442776),  INT32_C(   313393487), -INT32_C(   745037438), -INT32_C(  1468494291), -INT32_C(   285922725) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_VwVw(a, b);

    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i32_random(1);
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_VwVw(a, b);

    simde_test_hvx_vector_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VbVb_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[SIMDE_HVX_VECTOR_SIZE];
    int8_t b[SIMDE_HVX_VECTOR_SIZE];
    int8_t r[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),  INT8_C(  98),  INT8_C(  17), -INT8_C(  40),  INT8_C( 101),
        -INT8_C(  83), -INT8_C(  21),  INT8_C(  44), -INT8_C(  19), -INT8_C(  62),  INT8_C( 120),  INT8_C( 106),  INT8_C( 109),
        -INT8_C(  51),  INT8_C( 114), -INT8_C( 103),  INT8_C(  94),  INT8_C(  50),  INT8_C( 125), -INT8_C(  53), -INT8_C(  49),
         INT8_C(  27), -INT8_C(  74),  INT8_C(  81), -INT8_C(  74),  INT8_C(  94), -INT8_C(  24),  INT8_C(   4),  INT8_C(  23),
         INT8_C(   4),  INT8_C(  55),  INT8_C(  83), -INT8_C(  26), -INT8_C(  13), -INT8_C(  99), -INT8_C(  65),  INT8_C(  78),
        -INT8_C(  87), -INT8_C(  15), -INT8_C(  45),  INT8_C(  54), -INT8_C( 104),  INT8_C(  22),  INT8_C(  68), -INT8_C(  61),
         INT8_C(   6),  INT8_C(   3), -INT8_C(  34),  INT8_C( 111),  INT8_C(   5),  INT8_C(  12), -INT8_C(  87), -INT8_C(  32),
        -INT8_C(   6),  INT8_C(  78), -INT8_C(  75), -INT8_C(  74),  INT8_C(  25), -INT8_C(  22),  INT8_C( 114),  INT8_C(  47),
         INT8_C( 111),  INT8_C(  75),  INT8_C(   5),  INT8_C(  97), -INT8_C(  77),  INT8_C(   2), -INT8_C(  74), -INT8_C(  14),
        -INT8_C(  22), -INT8_C(  51),  INT8_C(  18),  INT8_C(  96),  INT8_C(   9), -INT8_C(  24), -INT8_C(  36),  INT8_C(  48),
        -INT8_C( 119), -INT8_C(  85), -INT8_C(  60),  INT8_C(  67), -INT8_C(  27), -INT8_C(  92), -INT8_C(  73),  INT8_C(  95),
         INT8_C( 115), -INT8_C(  46),  INT8_C(  89),  INT8_C(  64),  INT8_C(  74), -INT8_C(  39), -INT8_C(  41),  INT8_C(  67),
        -INT8_C( 109),  INT8_C( 119), -INT8_C( 121), -INT8_C(  12), -INT8_C(  68),  INT8_C( 100), -INT8_C( 101), -INT8_C(  17),
         INT8_C(  67), -INT8_C(  97),  INT8_C( 115),  INT8_C(  19),  INT8_C(  77),  INT8_C(  60), -INT8_C( 111),  INT8_C(  75),
        -INT8_C( 110),      INT8_MIN,  INT8_C(  28),  INT8_C( 117), -INT8_C( 122), -INT8_C(  29),  INT8_C( 120), -INT8_C(  67) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C( 110), -INT8_C(  36), -INT8_C(  96),  INT8_C(  34),
        -INT8_C(  53), -INT8_C( 111), -INT8_C(  86), -INT8_C(  50),  INT8_C( 118), -INT8_C(  35), -INT8_C(  70), -INT8_C(  15),
         INT8_C( 111),  INT8_C(  88),  INT8_C(  69), -INT8_C( 120),  INT8_C(  96), -INT8_C( 115),  INT8_C(  68), -INT8_C( 115),
         INT8_C(  62),  INT8_C( 109),      INT8_MAX, -INT8_C(  61),  INT8_C( 115),  INT8_C( 101),  INT8_C(  90),  INT8_C(  58),
         INT8_C(  25), -INT8_C(  34),  INT8_C(  86),  INT8_C(  57), -INT8_C(  81),  INT8_C(  52),  INT8_C(  40), -INT8_C(  43),
        -INT8_C(  43),  INT8_C(  64),  INT8_C( 107),  INT8_C(  71), -INT8_C(  38),  INT8_C(  54),  INT8_C(  98), -INT8_C(  44),
         INT8_C(  82), -INT8_C( 110), -INT8_C(  38), -INT8_C(  82), -INT8_C(  16),  INT8_C(   2), -INT8_C(  30),  INT8_C( 126),
        -INT8_C(  44), -INT8_C(  70), -INT8_C(  70),  INT8_C(  37),  INT8_C(  13), -INT8_C(   8), -INT8_C(  95), -INT8_C( 118),
        -INT8_C(  11), -INT8_C(  22),  INT8_C( 103),  INT8_C(  32), -INT8_C( 119),  INT8_C(  34),  INT8_C(  41),  INT8_C( 119),
         INT8_C( 106), -INT8_C(  89), -INT8_C(  76),  INT8_C(  83), -INT8_C(  10), -INT8_C(  28), -INT8_C( 117), -INT8_C( 108),
        -INT8_C(  85),  INT8_C(  99), -INT8_C(  29),  INT8_C(  10), -INT8_C( 124),  INT8_C(  59), -INT8_C(  83), -INT8_C(  54),
         INT8_C( 125),  INT8_C(  49),  INT8_C(  71), -INT8_C(  92),  INT8_C(  50), -INT8_C(  97), -INT8_C(  83), -INT8_C(  43),
         INT8_C(  45),  INT8_C(  72),  INT8_C(  44),  INT8_C(  13),  INT8_C(  21),  INT8_C(   2),  INT8_C(   7), -INT8_C(  55),
         INT8_C(  56), -INT8_C( 117), -INT8_C(  96),  INT8_C(  67), -INT8_C(  40), -INT8_C(  39), -INT8_C(  21),  INT8_C(  78),
        -INT8_C(   5), -INT8_C(  96), -INT8_C( 126),  INT8_C( 113),      INT8_MAX,  INT8_C(  72),  INT8_C(  45),  INT8_C(  41) },
      {      INT8_MIN, -INT8_C(   1),      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(   2),
             INT8_MIN, -INT8_C( 127),      INT8_MAX,      INT8_MAX, -INT8_C(  12), -INT8_C(  19),      INT8_MIN,      INT8_MAX,
             INT8_MIN,      INT8_MIN, -INT8_C(  42), -INT8_C(  69),  INT8_C(  56),  INT8_C(  85),  INT8_C(  36),  INT8_C(  94),
         INT8_C(  60),      INT8_MAX, -INT8_C(  34), -INT8_C(  26),      INT8_MAX,  INT8_C(  10),  INT8_C(  15),      INT8_MIN,
         INT8_C(  89),  INT8_C(  35),      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(  77),  INT8_C(  94),  INT8_C(  81),
         INT8_C(  29),  INT8_C(  21),      INT8_MAX,  INT8_C(  31), -INT8_C(  94), -INT8_C(  47), -INT8_C(  25),  INT8_C(  35),
             INT8_MIN,  INT8_C(  49),  INT8_C(  62),  INT8_C( 125),      INT8_MIN,  INT8_C(  76),      INT8_MAX, -INT8_C( 105),
         INT8_C(  88), -INT8_C( 107), -INT8_C(  72),  INT8_C(  29), -INT8_C(  11),  INT8_C(  14), -INT8_C( 117),  INT8_C(  94),
        -INT8_C(  50),  INT8_C(   8),      INT8_MIN, -INT8_C(  37),  INT8_C(  38), -INT8_C(  30),  INT8_C(  19), -INT8_C(  71),
         INT8_C( 100),  INT8_C(  53),  INT8_C( 108),      INT8_MAX,      INT8_MIN,  INT8_C(  36), -INT8_C(  33),  INT8_C( 105),
         INT8_C(  84),      INT8_MIN, -INT8_C(  58),      INT8_MAX, -INT8_C(   1), -INT8_C(  52),      INT8_MIN, -INT8_C(  60),
             INT8_MIN,  INT8_C(  14), -INT8_C(  89),  INT8_C(  77),      INT8_MIN, -INT8_C(  33),      INT8_MIN,  INT8_C(  41),
             INT8_MAX,  INT8_C(   3),      INT8_MAX, -INT8_C(  28),  INT8_C( 124),      INT8_MIN, -INT8_C( 124),  INT8_C(  24),
        -INT8_C(  64),      INT8_MAX, -INT8_C(  77),  INT8_C(   1), -INT8_C(  47),  INT8_C( 102), -INT8_C(  94), -INT8_C(  72),
         INT8_C( 123),      INT8_MIN,  INT8_C(  19),  INT8_C(  86),  INT8_C(  37),  INT8_C(  21),      INT8_MIN,      INT8_MAX,
        -INT8_C( 115),      INT8_MIN, -INT8_C(  98),      INT8_MAX,  INT8_C(   5),  INT8_C(  43),      INT8_MAX, -INT8_C(  26) } },
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1), -INT8_C(  43),  INT8_C(  21), -INT8_C(   7), -INT8_C( 104),
         INT8_C(  20),  INT8_C( 101), -INT8_C(  76), -INT8_C(  55),  INT8_C(   4), -INT8_C(  14),  INT8_C(  42), -INT8_C(  80),
         INT8_C(  50),  INT8_C(   8),  INT8_C(  37), -INT8_C(  79),  INT8_C(  31),  INT8_C(  70),  INT8_C(  60),  INT8_C(  70),
         INT8_C(  29),  INT8_C(   3),  INT8_C( 113),  INT8_C(  24), -INT8_C(  85), -INT8_C(  33),  INT8_C(  57),  INT8_C(  53),
        -INT8_C(  19),  INT8_C(  60), -INT8_C(  86), -INT8_C(  23),  INT8_C(  88),  INT8_C(  52), -INT8_C(  30), -INT8_C(  23),
        -INT8_C(  25), -INT8_C(  52), -INT8_C(  82),  INT8_C(  95), -INT8_C(  35),  INT8_C(  20), -INT8_C(  92), -INT8_C( 116),
         INT8_C( 126),  INT8_C(  16),  INT8_C(  49),  INT8_C(  78), -INT8_C(  55), -INT8_C(  35), -INT8_C(  96), -INT8_C(  80),
         INT8_C(   6),  INT8_C(   7),  INT8_C(  94),  INT8_C( 117),  INT8_C(  62), -INT8_C(  22), -INT8_C(   2),  INT8_C( 116),
         INT8_C( 106),  INT8_C(  79),  INT8_C(  59),  INT8_C(  50),  INT8_C(  71),  INT8_C(  21), -INT8_C(  78), -INT8_C(  79),
         INT8_C(  41),  INT8_C(  99), -INT8_C(  44),  INT8_C(  36), -INT8_C( 117), -INT8_C(  57), -INT8_C(  92), -INT8_C(  19),
        -INT8_C(  86),  INT8_C(  47),  INT8_C(  51), -INT8_C(  53), -INT8_C(  53),  INT8_C(  60),  INT8_C(  43),  INT8_C(  78),
        -INT8_C(  44),  INT8_C(  99), -INT8_C(  36), -INT8_C( 120), -INT8_C(  87),  INT8_C(  32), -INT8_C( 109),  INT8_C(  39),
        -INT8_C(  36),  INT8_C(  70), -INT8_C( 116), -INT8_C(  62), -INT8_C(  24), -INT8_C(   3),  INT8_C(  72),  INT8_C(   7),
        -INT8_C(  36),  INT8_C(  65), -INT8_C(  59),  INT8_C(  67),  INT8_C(  97),  INT8_C(  80),  INT8_C(  38), -INT8_C(  92),
        -INT8_C(  20), -INT8_C(  87), -INT8_C( 110),  INT8_C( 105), -INT8_C(  93), -INT8_C( 113),  INT8_C(  93),  INT8_C(  81) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  37),  INT8_C(   0), -INT8_C(  53), -INT8_C(  43),
        -INT8_C(   6), -INT8_C(  33), -INT8_C(  61), -INT8_C(  45), -INT8_C(  58),  INT8_C(  78),  INT8_C(  23),  INT8_C( 100),
         INT8_C(  69), -INT8_C(  43), -INT8_C(  73),  INT8_C( 109), -INT8_C(  53),  INT8_C(   1), -INT8_C( 127), -INT8_C(  85),
         INT8_C(   3), -INT8_C(  48),  INT8_C(  98), -INT8_C(  12),  INT8_C( 124),  INT8_C(  94),  INT8_C(  91),  INT8_C( 126),
        -INT8_C(  61),  INT8_C(  94), -INT8_C( 122),  INT8_C( 112),  INT8_C(  23), -INT8_C(  67), -INT8_C( 113),  INT8_C(  13),
         INT8_C( 117),      INT8_MIN, -INT8_C( 118),  INT8_C(  62), -INT8_C( 101), -INT8_C(  46),  INT8_C(  16),  INT8_C(  76),
         INT8_C(  81), -INT8_C(  15), -INT8_C(  62), -INT8_C(  31), -INT8_C(   5),  INT8_C(  50),  INT8_C(  73), -INT8_C(   5),
        -INT8_C(  29),  INT8_C(  99),  INT8_C(  49),  INT8_C(  22), -INT8_C(  96), -INT8_C(  80), -INT8_C(  48),  INT8_C( 104),
        -INT8_C( 119),  INT8_C(   8), -INT8_C(   6),  INT8_C( 114),  INT8_C(   8), -INT8_C( 108),  INT8_C( 113),  INT8_C(  91),
        -INT8_C(  88),  INT8_C(  29), -INT8_C( 107),  INT8_C(  32),  INT8_C(  34), -INT8_C(   3), -INT8_C( 104),  INT8_C(   0),
        -INT8_C(  92),  INT8_C( 101), -INT8_C(  71), -INT8_C(  42), -INT8_C(  14),  INT8_C(  50), -INT8_C(  12),  INT8_C(   6),
        -INT8_C( 108),  INT8_C(  37), -INT8_C(  68),  INT8_C(  74), -INT8_C(  33), -INT8_C(   9),  INT8_C(  26),  INT8_C( 120),
        -INT8_C( 110),  INT8_C(  64),  INT8_C(  36),  INT8_C(   8), -INT8_C(   4),  INT8_C( 100), -INT8_C(  74),  INT8_C(  88),
         INT8_C(  82), -INT8_C(  48), -INT8_C(  10), -INT8_C(  82),  INT8_C(  99),  INT8_C(  24), -INT8_C(  31),  INT8_C(  59),
        -INT8_C( 102), -INT8_C( 110),  INT8_C(  50),  INT8_C(  41), -INT8_C(  68), -INT8_C(   1), -INT8_C(  25), -INT8_C(  89) },
      {      INT8_MIN, -INT8_C(   1),      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(   2),
             INT8_MIN, -INT8_C( 127),      INT8_MAX,      INT8_MAX, -INT8_C(   6),  INT8_C(  21), -INT8_C(  60),      INT8_MIN,
         INT8_C(  14),  INT8_C(  68),      INT8_MIN, -INT8_C( 100), -INT8_C(  54),  INT8_C(  64),  INT8_C(  65),  INT8_C(  20),
         INT8_C( 119), -INT8_C(  35), -INT8_C(  36),  INT8_C(  30), -INT8_C(  22),  INT8_C(  71), -INT8_C(  67), -INT8_C(  15),
         INT8_C(  32), -INT8_C(  45),      INT8_MAX,  INT8_C(  12),  INT8_C(  39),  INT8_C(  61),      INT8_MAX,      INT8_MAX,
        -INT8_C(  80),      INT8_MAX,      INT8_MIN,  INT8_C(  89),  INT8_C( 111), -INT8_C(  15),      INT8_MIN, -INT8_C(  10),
         INT8_C(  92),      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN, -INT8_C(  26), -INT8_C(  76), -INT8_C(  40),
             INT8_MAX,  INT8_C(   1), -INT8_C(  13),  INT8_C(  47), -INT8_C(  60),  INT8_C(  15), -INT8_C(  23), -INT8_C(  85),
        -INT8_C(  23),  INT8_C( 106),      INT8_MAX,      INT8_MAX, -INT8_C(  34), -INT8_C( 102), -INT8_C(  50),      INT8_MAX,
        -INT8_C(  13),  INT8_C(  87),  INT8_C(  53),      INT8_MAX,  INT8_C(  79), -INT8_C(  87),  INT8_C(  35),  INT8_C(  12),
        -INT8_C(  47),      INT8_MAX,      INT8_MIN,  INT8_C(  68), -INT8_C(  83), -INT8_C(  60),      INT8_MIN, -INT8_C(  19),
             INT8_MIN,      INT8_MAX, -INT8_C(  20), -INT8_C(  95), -INT8_C(  67),  INT8_C( 110),  INT8_C(  31),  INT8_C(  84),
             INT8_MIN,      INT8_MAX, -INT8_C( 104), -INT8_C(  46), -INT8_C( 120),  INT8_C(  23), -INT8_C(  83),      INT8_MAX,
             INT8_MIN,      INT8_MAX, -INT8_C(  80), -INT8_C(  54), -INT8_C(  28),  INT8_C(  97), -INT8_C(   2),  INT8_C(  95),
         INT8_C(  46),  INT8_C(  17), -INT8_C(  69), -INT8_C(  15),      INT8_MAX,  INT8_C( 104),  INT8_C(   7), -INT8_C(  33),
        -INT8_C( 122),      INT8_MIN, -INT8_C(  60),      INT8_MAX,      INT8_MIN, -INT8_C( 114),  INT8_C(  68), -INT8_C(   8) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vb_vadd_VbVb_sat(a, b);

    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i8_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i8_random(1);
    simde_hvx_vector_t r = simde_Q6_Vb_vadd_VbVb_sat(a, b);

    simde_test_hvx_vector_i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VhVh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t r[SIMDE_HVX_VECTOR_I16_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C(  7093), -INT16_C( 14203),  INT16_C( 32635),  INT16_C( 17612),
        -INT16_C(  2342), -INT16_C( 12451),  INT16_C(  3542),  INT16_C(  7718), -INT16_C( 10690),  INT16_C( 16301), -INT16_C( 11949),  INT16_C(  7233),
        -INT16_C( 29387),  INT16_C( 23097),  INT16_C( 14607), -INT16_C( 30243), -INT16_C( 19856),  INT16_C( 28542), -INT16_C(  1876), -INT16_C( 16842),
        -INT16_C( 17061), -INT16_C( 21103),  INT16_C( 24227),  INT16_C( 30217),  INT16_C( 10604), -INT16_C( 21333),  INT16_C( 15137), -INT16_C( 31758),
         INT16_C( 14211),  INT16_C( 19556), -INT16_C( 26860), -INT16_C( 22007),  INT16_C( 25493), -INT16_C(  3962),  INT16_C(  4080), -INT16_C(  6468),
        -INT16_C(  1932),  INT16_C( 31575), -INT16_C(  7544), -INT16_C( 24448), -INT16_C( 29279), -INT16_C( 13569),  INT16_C( 12377), -INT16_C( 16102),
        -INT16_C( 29984), -INT16_C( 10858),  INT16_C( 19287),  INT16_C(  4329),  INT16_C( 23322), -INT16_C(  2985),  INT16_C( 17231),  INT16_C( 29591) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 14447),  INT16_C( 16681), -INT16_C(  7419),  INT16_C( 28359),
         INT16_C( 23081),  INT16_C( 22585),  INT16_C( 15657), -INT16_C( 18510), -INT16_C( 17060), -INT16_C( 16782),  INT16_C( 23730),  INT16_C( 17781),
         INT16_C( 27642), -INT16_C(  8378), -INT16_C( 18383), -INT16_C( 12946), -INT16_C( 11171),  INT16_C( 30047), -INT16_C( 28989),  INT16_C( 10922),
        -INT16_C( 12290),  INT16_C(  5543),  INT16_C( 12599),  INT16_C( 17483),  INT16_C( 19592), -INT16_C( 22809), -INT16_C( 28888), -INT16_C( 28883),
         INT16_C( 23157),  INT16_C( 24832),  INT16_C( 20410), -INT16_C(  9786), -INT16_C( 30374),  INT16_C( 21690),  INT16_C( 11642), -INT16_C( 18656),
         INT16_C( 10443), -INT16_C(  6931), -INT16_C( 14639),  INT16_C(  2226),  INT16_C(  1973), -INT16_C(  4937),  INT16_C( 15939), -INT16_C( 25431),
         INT16_C(  2793), -INT16_C( 16042), -INT16_C( 21837),  INT16_C( 15671),  INT16_C(  1885), -INT16_C( 31994),  INT16_C( 28066), -INT16_C( 11733) },
      {        INT16_MIN, -INT16_C(     1),        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C(     2),
               INT16_MIN,       -INT16_MAX,        INT16_MAX,        INT16_MAX,  INT16_C( 21540),  INT16_C(  2478),  INT16_C( 25216),        INT16_MAX,
         INT16_C( 20739),  INT16_C( 10134),  INT16_C( 19199), -INT16_C( 10792), -INT16_C( 27750), -INT16_C(   481),  INT16_C( 11781),  INT16_C( 25014),
        -INT16_C(  1745),  INT16_C( 14719), -INT16_C(  3776),        INT16_MIN, -INT16_C( 31027),        INT16_MAX, -INT16_C( 30865), -INT16_C(  5920),
        -INT16_C( 29351), -INT16_C( 15560),        INT16_MAX,        INT16_MAX,  INT16_C( 30196),        INT16_MIN, -INT16_C( 13751),        INT16_MIN,
               INT16_MAX,        INT16_MAX, -INT16_C(  6450), -INT16_C( 31793), -INT16_C(  4881),  INT16_C( 17728),  INT16_C( 15722), -INT16_C( 25124),
         INT16_C(  8511),  INT16_C( 24644), -INT16_C( 22183), -INT16_C( 22222), -INT16_C( 27306), -INT16_C( 18506),  INT16_C( 28316),        INT16_MIN,
        -INT16_C( 27191), -INT16_C( 26900), -INT16_C(  2550),  INT16_C( 20000),  INT16_C( 25207),        INT16_MIN,        INT16_MAX,  INT16_C( 17858) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C( 27845), -INT16_C( 12983), -INT16_C( 17667),  INT16_C( 23561),
        -INT16_C( 22251),  INT16_C( 29083),  INT16_C( 26211),  INT16_C( 32705), -INT16_C( 19846),  INT16_C( 18871),  INT16_C( 11543),  INT16_C(  3864),
        -INT16_C( 10571), -INT16_C( 20088),  INT16_C( 25589), -INT16_C( 17324), -INT16_C(  8838), -INT16_C(  6032), -INT16_C( 17694),  INT16_C( 18903),
         INT16_C(  5625),  INT16_C( 24430), -INT16_C( 30519),  INT16_C(  4068), -INT16_C( 28237),  INT16_C(  7119), -INT16_C(  1295),  INT16_C( 15245),
         INT16_C( 29781), -INT16_C( 12685), -INT16_C( 32153), -INT16_C( 26676),  INT16_C( 17321), -INT16_C( 19069),  INT16_C( 18948),  INT16_C(  5552),
        -INT16_C( 15731), -INT16_C( 31607), -INT16_C( 21145), -INT16_C( 19638),  INT16_C(  4061),  INT16_C( 17780),  INT16_C( 20285), -INT16_C( 25593),
         INT16_C( 12523),  INT16_C( 11828), -INT16_C( 24596), -INT16_C(  5131), -INT16_C( 24524),  INT16_C(  1104), -INT16_C(  2378), -INT16_C( 18102) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C( 26686), -INT16_C(  9318), -INT16_C(  2636),  INT16_C(  6166),
         INT16_C( 21858),  INT16_C( 13816),  INT16_C( 10224),  INT16_C( 17605), -INT16_C(  9899),  INT16_C( 13289), -INT16_C(  1370),  INT16_C( 22405),
        -INT16_C( 12170),  INT16_C( 26149), -INT16_C(  2737),  INT16_C(  3150),  INT16_C( 23303),  INT16_C( 12746), -INT16_C( 22933), -INT16_C(  1570),
        -INT16_C( 11498), -INT16_C( 11604), -INT16_C(  5051), -INT16_C( 22061), -INT16_C( 25057), -INT16_C( 18153), -INT16_C( 13684), -INT16_C( 26138),
        -INT16_C( 18149), -INT16_C( 17643),  INT16_C( 13679), -INT16_C(   442), -INT16_C(   743),  INT16_C( 14365), -INT16_C( 30274),  INT16_C( 30695),
        -INT16_C( 25267), -INT16_C( 28921), -INT16_C( 14218),  INT16_C( 14738), -INT16_C( 28799), -INT16_C( 23573),  INT16_C(  3848), -INT16_C( 14267),
         INT16_C(  8581), -INT16_C( 28548),  INT16_C( 13684),  INT16_C( 24696),  INT16_C( 14157),  INT16_C(  7508), -INT16_C( 17844), -INT16_C(  3955) },
      {        INT16_MIN, -INT16_C(     1),        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C(     2),
               INT16_MIN,       -INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MIN, -INT16_C( 22301), -INT16_C( 20303),  INT16_C( 29727),
        -INT16_C(   393),        INT16_MAX,        INT16_MAX,        INT16_MAX, -INT16_C( 29745),  INT16_C( 32160),  INT16_C( 10173),  INT16_C( 26269),
        -INT16_C( 22741),  INT16_C(  6061),  INT16_C( 22852), -INT16_C( 14174),  INT16_C( 14465),  INT16_C(  6714),        INT16_MIN,  INT16_C( 17333),
        -INT16_C(  5873),  INT16_C( 12826),        INT16_MIN, -INT16_C( 17993),        INT16_MIN, -INT16_C( 11034), -INT16_C( 14979), -INT16_C( 10893),
         INT16_C( 11632), -INT16_C( 30328), -INT16_C( 18474), -INT16_C( 27118),  INT16_C( 16578), -INT16_C(  4704), -INT16_C( 11326),        INT16_MAX,
               INT16_MIN,        INT16_MIN,        INT16_MIN, -INT16_C(  4900), -INT16_C( 24738), -INT16_C(  5793),  INT16_C( 24133),        INT16_MIN,
         INT16_C( 21104), -INT16_C( 16720), -INT16_C( 10912),  INT16_C( 19565), -INT16_C( 10367),  INT16_C(  8612), -INT16_C( 20222), -INT16_C( 22057) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vadd_VhVh_sat(a, b);

    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i16_random(1);
    simde_hvx_vector_t r = simde_Q6_Vh_vadd_VhVh_sat(a, b);

    simde_test_hvx_vector_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VwVw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t b[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(  1334879081), -INT32_C(  1974743759),  INT32_C(   798220575), -INT32_C(   254876546),
        -INT32_C(   336129346),  INT32_C(  2042694164),  INT32_C(   687841117),  INT32_C(   259798602),  INT32_C(    42968284),  INT32_C(  1150029859),  INT32_C(  2077371679),  INT32_C(   623867542),
         INT32_C(  1896829499), -INT32_C(   931107163), -INT32_C(   899616150),  INT32_C(  2078477473),  INT32_C(   281692532), -INT32_C(   230350148), -INT32_C(   432086477),  INT32_C(   427360227) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(  1854594522),  INT32_C(   459666315),  INT32_C(   973015230), -INT32_C(  1180603656),
         INT32_C(  1588765688),  INT32_C(  2131277085),  INT32_C(    89474652),  INT32_C(  1560435126),  INT32_C(   903214538), -INT32_C(  1339660845), -INT32_C(  1845932530),  INT32_C(  1105199419),
        -INT32_C(   937868506),  INT32_C(   599268636),  INT32_C(  1956916414),  INT32_C(  1808710215), -INT32_C(  1929094255),  INT32_C(   269466930), -INT32_C(   213074351), -INT32_C(  1451266634) },
      {              INT32_MIN, -INT32_C(           1),              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(           2),
                     INT32_MIN, -INT32_C(  2147483647),              INT32_MAX,              INT32_MAX,              INT32_MAX, -INT32_C(  1515077444),  INT32_C(  1771235805), -INT32_C(  1435480202),
         INT32_C(  1252636342),              INT32_MAX,  INT32_C(   777315769),  INT32_C(  1820233728),  INT32_C(   946182822), -INT32_C(   189630986),  INT32_C(   231439149),  INT32_C(  1729066961),
         INT32_C(   958960993), -INT32_C(   331838527),  INT32_C(  1057300264),              INT32_MAX, -INT32_C(  1647401723),  INT32_C(    39116782), -INT32_C(   645160828), -INT32_C(  1023906407) } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(  2116244529), -INT32_C(  1192815543),  INT32_C(   424702141), -INT32_C(  1287350924),
         INT32_C(   302979945),  INT32_C(  1320216518), -INT32_C(   495596694), -INT32_C(  1785186915), -INT32_C(  1658145994), -INT32_C(  1563940662),  INT32_C(    66642197), -INT32_C(  1052802793),
         INT32_C(  1835571322), -INT32_C(  1534167424),  INT32_C(  1360574466), -INT32_C(  1620871564), -INT32_C(  1654436139),  INT32_C(  1068828484),  INT32_C(  1220996335), -INT32_C(   335407678) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX, -INT32_C(   256367881),  INT32_C(  1883668825),  INT32_C(   332971731),  INT32_C(   395126860),
         INT32_C(   688772436),  INT32_C(   292404978),  INT32_C(  1179184175),  INT32_C(   567062791),  INT32_C(   908012174), -INT32_C(  1906902955), -INT32_C(   767268028),  INT32_C(  1904259155),
         INT32_C(  1796226369),  INT32_C(   990004211),  INT32_C(   111711000),  INT32_C(  2003402976), -INT32_C(  1955963051),  INT32_C(   424125788),  INT32_C(  1661179187),  INT32_C(    72576445) },
      {              INT32_MIN, -INT32_C(           1),              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(           2),
                     INT32_MIN, -INT32_C(  2147483647),              INT32_MAX,              INT32_MAX,  INT32_C(  1859876648),  INT32_C(   690853282),  INT32_C(   757673872), -INT32_C(   892224064),
         INT32_C(   991752381),  INT32_C(  1612621496),  INT32_C(   683587481), -INT32_C(  1218124124), -INT32_C(   750133820),              INT32_MIN, -INT32_C(   700625831),  INT32_C(   851456362),
                     INT32_MAX, -INT32_C(   544163213),  INT32_C(  1472285466),  INT32_C(   382531412),              INT32_MIN,  INT32_C(  1492954272),              INT32_MAX, -INT32_C(   262831233) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_VwVw_sat(a, b);

    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i32_random(1);
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_VwVw_sat(a, b);

    simde_test_hvx_vector_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VubVub_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[SIMDE_HVX_VECTOR_SIZE];
    uint8_t b[SIMDE_HVX_VECTOR_SIZE];
    uint8_t r[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(123), UINT8_C(173), UINT8_C(249), UINT8_C(195),
        UINT8_C(119), UINT8_C( 34), UINT8_C(200), UINT8_C(  1), UINT8_C(118), UINT8_C(222), UINT8_C(143), UINT8_C( 71),
        UINT8_C(235), UINT8_C(239), UINT8_C(159), UINT8_C(179), UINT8_C(178), UINT8_C(223), UINT8_C(127), UINT8_C(160),
        UINT8_C(122), UINT8_C(216), UINT8_C(158), UINT8_C( 68), UINT8_C(192), UINT8_C(189), UINT8_C( 87), UINT8_C(226),
        UINT8_C(234), UINT8_C( 40), UINT8_C(198), UINT8_C(248), UINT8_C( 93), UINT8_C(146), UINT8_C(237), UINT8_C(172),
        UINT8_C(207), UINT8_C(168), UINT8_C(245), UINT8_C(234), UINT8_C(162), UINT8_C( 51), UINT8_C( 42), UINT8_C(105),
        UINT8_C(149), UINT8_C(157), UINT8_C(244), UINT8_C(220), UINT8_C(152), UINT8_C( 76), UINT8_C( 68), UINT8_C(241),
        UINT8_C(154), UINT8_C(244), UINT8_C(120), UINT8_C(245), UINT8_C(  2), UINT8_C(129), UINT8_C(163), UINT8_C(137),
        UINT8_C(182), UINT8_C(237), UINT8_C( 72), UINT8_C(178), UINT8_C( 60), UINT8_C(156), UINT8_C(153), UINT8_C(192),
        UINT8_C( 95), UINT8_C(236), UINT8_C(146), UINT8_C(182), UINT8_C(188), UINT8_C( 20), UINT8_C(224), UINT8_C(  0),
        UINT8_C(135), UINT8_C(122), UINT8_C( 94), UINT8_C(113), UINT8_C(214), UINT8_C(179), UINT8_C(197), UINT8_C(244),
        UINT8_C( 36), UINT8_C(229), UINT8_C(242), UINT8_C(  5), UINT8_C( 23), UINT8_C(114), UINT8_C(194), UINT8_C(109),
        UINT8_C( 64), UINT8_C( 69), UINT8_C(209), UINT8_C( 49), UINT8_C(131), UINT8_C(  0), UINT8_C( 26), UINT8_C(168),
        UINT8_C( 71), UINT8_C( 20), UINT8_C(236), UINT8_C( 87), UINT8_C(225), UINT8_C(228), UINT8_C(  1), UINT8_C( 79),
        UINT8_C( 32), UINT8_C(230), UINT8_C(105), UINT8_C( 55), UINT8_C( 30), UINT8_C( 81), UINT8_C(173), UINT8_C(233) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C( 91), UINT8_C(252), UINT8_C(173), UINT8_C(215),
        UINT8_C( 59), UINT8_C( 94), UINT8_C( 79), UINT8_C( 40), UINT8_C( 94), UINT8_C(149), UINT8_C(164), UINT8_C(111),
        UINT8_C( 30), UINT8_C( 15), UINT8_C(253), UINT8_C(115), UINT8_C( 50), UINT8_C(145), UINT8_C( 69), UINT8_C(196),
        UINT8_C(163), UINT8_C( 91), UINT8_C(105), UINT8_C(238), UINT8_C(168), UINT8_C( 75), UINT8_C(126), UINT8_C( 43),
        UINT8_C( 25), UINT8_C(200), UINT8_C(174), UINT8_C(188), UINT8_C( 50), UINT8_C(140), UINT8_C(146), UINT8_C(192),
        UINT8_C(126), UINT8_C(141), UINT8_C(212), UINT8_C( 72), UINT8_C( 14), UINT8_C(202), UINT8_C(101), UINT8_C(222),
        UINT8_C(118), UINT8_C(190), UINT8_C( 17), UINT8_C(164), UINT8_C( 44), UINT8_C(144), UINT8_C( 28), UINT8_C( 36),
        UINT8_C(186), UINT8_C( 94), UINT8_C(236), UINT8_C(  3), UINT8_C(214), UINT8_C(154), UINT8_C( 99), UINT8_C( 10),
        UINT8_C(101), UINT8_C(151), UINT8_C(122), UINT8_C(152), UINT8_C(192), UINT8_C(169), UINT8_C(107), UINT8_C(137),
        UINT8_C( 84), UINT8_C(209), UINT8_C(178), UINT8_C(133), UINT8_C( 70), UINT8_C(102), UINT8_C(166), UINT8_C(153),
        UINT8_C(168), UINT8_C(161), UINT8_C(214), UINT8_C(203), UINT8_C( 69), UINT8_C( 18), UINT8_C( 31), UINT8_C(194),
        UINT8_C(105), UINT8_C( 10), UINT8_C(187), UINT8_C(180), UINT8_C( 10), UINT8_C( 24), UINT8_C( 45), UINT8_C( 87),
        UINT8_C( 24), UINT8_C(216), UINT8_C(156), UINT8_C( 98), UINT8_C(144), UINT8_C(  3), UINT8_C( 27), UINT8_C( 61),
        UINT8_C(251), UINT8_C( 52), UINT8_C( 10), UINT8_C(187), UINT8_C( 60), UINT8_C(179), UINT8_C( 77), UINT8_C(168),
        UINT8_C(153), UINT8_C( 21), UINT8_C(107), UINT8_C( 44), UINT8_C( 27), UINT8_C(  2), UINT8_C( 60), UINT8_C(104) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  2),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX,    UINT8_MAX, UINT8_C(214),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(178), UINT8_C(128),    UINT8_MAX, UINT8_C( 41), UINT8_C(212),    UINT8_MAX,    UINT8_MAX, UINT8_C(182),
           UINT8_MAX, UINT8_C(254),    UINT8_MAX,    UINT8_MAX, UINT8_C(228),    UINT8_MAX, UINT8_C(196),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(213),    UINT8_MAX,
           UINT8_MAX, UINT8_C(240),    UINT8_MAX,    UINT8_MAX, UINT8_C(143),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(176), UINT8_C(253), UINT8_C(143),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(196), UINT8_C(220), UINT8_C( 96),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(248), UINT8_C(216),    UINT8_MAX,    UINT8_MAX, UINT8_C(147),
           UINT8_MAX,    UINT8_MAX, UINT8_C(194),    UINT8_MAX, UINT8_C(252),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(179),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(122),    UINT8_MAX, UINT8_C(153),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(197), UINT8_C(228),    UINT8_MAX,
        UINT8_C(141), UINT8_C(239),    UINT8_MAX, UINT8_C(185), UINT8_C( 33), UINT8_C(138), UINT8_C(239), UINT8_C(196),
        UINT8_C( 88),    UINT8_MAX,    UINT8_MAX, UINT8_C(147),    UINT8_MAX, UINT8_C(  3), UINT8_C( 53), UINT8_C(229),
           UINT8_MAX, UINT8_C( 72), UINT8_C(246),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 78), UINT8_C(247),
        UINT8_C(185), UINT8_C(251), UINT8_C(212), UINT8_C( 99), UINT8_C( 57), UINT8_C( 83), UINT8_C(233),    UINT8_MAX } },
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(  5), UINT8_C( 61), UINT8_C( 34), UINT8_C(128),
        UINT8_C( 35), UINT8_C(132), UINT8_C( 54), UINT8_C(183), UINT8_C(236), UINT8_C(245), UINT8_C(  5), UINT8_C( 54),
        UINT8_C(232), UINT8_C(115), UINT8_C(  7), UINT8_C(145), UINT8_C(120), UINT8_C(104), UINT8_C(129), UINT8_C( 95),
        UINT8_C(205), UINT8_C(  1), UINT8_C(224), UINT8_C(222), UINT8_C(157), UINT8_C(232), UINT8_C(190), UINT8_C(114),
        UINT8_C(106), UINT8_C( 66), UINT8_C( 18), UINT8_C( 11), UINT8_C(228), UINT8_C(164), UINT8_C(130), UINT8_C(191),
        UINT8_C(228), UINT8_C(190), UINT8_C(156), UINT8_C(156), UINT8_C(129), UINT8_C(136), UINT8_C(248), UINT8_C( 33),
        UINT8_C(200), UINT8_C(217), UINT8_C(169), UINT8_C( 14), UINT8_C(157), UINT8_C(232), UINT8_C(184), UINT8_C(104),
        UINT8_C(208), UINT8_C(193), UINT8_C(211), UINT8_C( 20), UINT8_C(203), UINT8_C(154), UINT8_C(108), UINT8_C(130),
        UINT8_C(  0), UINT8_C( 60), UINT8_C(115), UINT8_C(101), UINT8_C( 88), UINT8_C(113), UINT8_C( 24), UINT8_C(231),
        UINT8_C( 53), UINT8_C(249), UINT8_C(249), UINT8_C(196), UINT8_C( 57), UINT8_C(124), UINT8_C( 19), UINT8_C( 15),
        UINT8_C( 81), UINT8_C(120), UINT8_C( 74), UINT8_C( 68), UINT8_C(  3), UINT8_C(187), UINT8_C(138), UINT8_C( 41),
        UINT8_C(244), UINT8_C(235), UINT8_C(234), UINT8_C( 38), UINT8_C(105), UINT8_C(112), UINT8_C( 75), UINT8_C(170),
        UINT8_C(158), UINT8_C(221), UINT8_C(160), UINT8_C( 33), UINT8_C(123), UINT8_C(124), UINT8_C(126), UINT8_C(152),
        UINT8_C(227), UINT8_C(210), UINT8_C( 49), UINT8_C( 35), UINT8_C(208), UINT8_C(172), UINT8_C(196),    UINT8_MAX,
        UINT8_C( 94), UINT8_C( 91), UINT8_C(139), UINT8_C( 33), UINT8_C(164), UINT8_C( 41), UINT8_C( 26), UINT8_C( 37) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C( 91), UINT8_C(124), UINT8_C(105), UINT8_C(211),
        UINT8_C(  7), UINT8_C( 86), UINT8_C(159), UINT8_C( 43), UINT8_C(101), UINT8_C( 93), UINT8_C( 54), UINT8_C( 95),
        UINT8_C(225), UINT8_C(181), UINT8_C(224), UINT8_C( 41), UINT8_C(198), UINT8_C(135), UINT8_C( 38), UINT8_C( 44),
        UINT8_C(171), UINT8_C(109), UINT8_C(232), UINT8_C(220), UINT8_C(252), UINT8_C( 99), UINT8_C(248), UINT8_C( 51),
        UINT8_C(138), UINT8_C(233), UINT8_C(208), UINT8_C(234), UINT8_C(132), UINT8_C(195), UINT8_C(137), UINT8_C( 51),
        UINT8_C(  1), UINT8_C(109), UINT8_C(226), UINT8_C( 48), UINT8_C(223), UINT8_C( 90), UINT8_C( 20), UINT8_C(154),
        UINT8_C(184), UINT8_C(171), UINT8_C( 68), UINT8_C( 52), UINT8_C( 60), UINT8_C(176), UINT8_C(169), UINT8_C( 77),
        UINT8_C(152), UINT8_C(146), UINT8_C( 99), UINT8_C( 30), UINT8_C(188), UINT8_C( 57), UINT8_C( 44), UINT8_C(115),
        UINT8_C(172), UINT8_C(176), UINT8_C( 84), UINT8_C(119), UINT8_C(  4), UINT8_C(116), UINT8_C(232), UINT8_C(156),
        UINT8_C(234), UINT8_C(198), UINT8_C( 48), UINT8_C( 72), UINT8_C(215), UINT8_C(136), UINT8_C(196), UINT8_C( 48),
        UINT8_C(  7), UINT8_C(158), UINT8_C(102), UINT8_C(176), UINT8_C( 48), UINT8_C(  1), UINT8_C(242), UINT8_C( 79),
        UINT8_C( 73), UINT8_C(140), UINT8_C(200), UINT8_C( 65), UINT8_C( 79), UINT8_C(218), UINT8_C(214), UINT8_C(173),
        UINT8_C( 42), UINT8_C(109), UINT8_C(  4), UINT8_C(237), UINT8_C(244), UINT8_C( 67), UINT8_C(198), UINT8_C(111),
        UINT8_C(140), UINT8_C( 65), UINT8_C( 31), UINT8_C(177), UINT8_C(  0), UINT8_C( 10), UINT8_C( 44), UINT8_C( 72),
        UINT8_C( 13), UINT8_C(249), UINT8_C( 88), UINT8_C(107), UINT8_C(108), UINT8_C(211), UINT8_C( 77), UINT8_C(155) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  2),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX,    UINT8_MAX, UINT8_C( 96), UINT8_C(185), UINT8_C(139),    UINT8_MAX,
        UINT8_C( 42), UINT8_C(218), UINT8_C(213), UINT8_C(226),    UINT8_MAX,    UINT8_MAX, UINT8_C( 59), UINT8_C(149),
           UINT8_MAX,    UINT8_MAX, UINT8_C(231), UINT8_C(186),    UINT8_MAX, UINT8_C(239), UINT8_C(167), UINT8_C(139),
           UINT8_MAX, UINT8_C(110),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(165),
        UINT8_C(244),    UINT8_MAX, UINT8_C(226), UINT8_C(245),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(242),
        UINT8_C(229),    UINT8_MAX,    UINT8_MAX, UINT8_C(204),    UINT8_MAX, UINT8_C(226),    UINT8_MAX, UINT8_C(187),
           UINT8_MAX,    UINT8_MAX, UINT8_C(237), UINT8_C( 66), UINT8_C(217),    UINT8_MAX,    UINT8_MAX, UINT8_C(181),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 50),    UINT8_MAX, UINT8_C(211), UINT8_C(152), UINT8_C(245),
        UINT8_C(172), UINT8_C(236), UINT8_C(199), UINT8_C(220), UINT8_C( 92), UINT8_C(229),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(215), UINT8_C( 63),
        UINT8_C( 88),    UINT8_MAX, UINT8_C(176), UINT8_C(244), UINT8_C( 51), UINT8_C(188),    UINT8_MAX, UINT8_C(120),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(103), UINT8_C(184),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(200),    UINT8_MAX, UINT8_C(164),    UINT8_MAX,    UINT8_MAX, UINT8_C(191),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C( 80), UINT8_C(212), UINT8_C(208), UINT8_C(182), UINT8_C(240),    UINT8_MAX,
        UINT8_C(107),    UINT8_MAX, UINT8_C(227), UINT8_C(140),    UINT8_MAX, UINT8_C(252), UINT8_C(103), UINT8_C(192) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vadd_VubVub_sat(a, b);

    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u8_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u8_random(1);
    simde_hvx_vector_t r = simde_Q6_Vub_vadd_VubVub_sat(a, b);

    simde_test_hvx_vector_u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VuhVuh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    uint16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    uint16_t r[SIMDE_HVX_VECTOR_I16_COUNT];
  } test_vec[] = {
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(30846), UINT16_C(52925), UINT16_C(29979), UINT16_C(47128),
        UINT16_C( 1934), UINT16_C(59699), UINT16_C(44959), UINT16_C(33213), UINT16_C(39296), UINT16_C(20822), UINT16_C(46178), UINT16_C(  223),
        UINT16_C( 5362), UINT16_C(  139), UINT16_C(53001), UINT16_C(50453), UINT16_C(63061), UINT16_C(42106), UINT16_C(43288), UINT16_C(14444),
        UINT16_C( 2154), UINT16_C(20387), UINT16_C(21763), UINT16_C(62909), UINT16_C(20711), UINT16_C( 9934), UINT16_C( 6404), UINT16_C(49037),
        UINT16_C(58742), UINT16_C(40302), UINT16_C(26467), UINT16_C(57217), UINT16_C(47151), UINT16_C(24292), UINT16_C(41389), UINT16_C(11314),
        UINT16_C(47495), UINT16_C( 7534), UINT16_C(56916), UINT16_C(16180), UINT16_C( 9333), UINT16_C(14971), UINT16_C( 6634), UINT16_C(53219),
        UINT16_C( 8099), UINT16_C(16862), UINT16_C(45869), UINT16_C(35705), UINT16_C(13346), UINT16_C(54383), UINT16_C(29919), UINT16_C( 6859) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(25362), UINT16_C(34525), UINT16_C( 7734), UINT16_C(27432),
        UINT16_C(64614), UINT16_C(14911), UINT16_C(59101), UINT16_C( 1098), UINT16_C(45494), UINT16_C(11934), UINT16_C(10252), UINT16_C(23850),
        UINT16_C(29169), UINT16_C(49862), UINT16_C( 7904), UINT16_C(13959), UINT16_C(34184), UINT16_C(26349), UINT16_C(64254), UINT16_C(25454),
        UINT16_C( 9534), UINT16_C( 2660), UINT16_C(61302), UINT16_C(47080), UINT16_C(65170), UINT16_C(48414), UINT16_C(43733), UINT16_C(48427),
        UINT16_C(17660), UINT16_C( 1560), UINT16_C(38682), UINT16_C( 5186), UINT16_C(28684), UINT16_C( 4491), UINT16_C(47637), UINT16_C(37393),
        UINT16_C(  876), UINT16_C( 3524), UINT16_C(10384), UINT16_C(54395), UINT16_C(10134), UINT16_C(28998), UINT16_C(41867), UINT16_C( 7474),
        UINT16_C(19953), UINT16_C(24774), UINT16_C(12469), UINT16_C(59087), UINT16_C(23287), UINT16_C(40316), UINT16_C(59180), UINT16_C(50807) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    2),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX,      UINT16_MAX, UINT16_C(56208),      UINT16_MAX, UINT16_C(37713),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(34311),      UINT16_MAX, UINT16_C(32756), UINT16_C(56430), UINT16_C(24073),
        UINT16_C(34531), UINT16_C(50001), UINT16_C(60905), UINT16_C(64412),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(39898),
        UINT16_C(11688), UINT16_C(23047),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(58348), UINT16_C(50137),      UINT16_MAX,
             UINT16_MAX, UINT16_C(41862), UINT16_C(65149), UINT16_C(62403),      UINT16_MAX, UINT16_C(28783),      UINT16_MAX, UINT16_C(48707),
        UINT16_C(48371), UINT16_C(11058),      UINT16_MAX,      UINT16_MAX, UINT16_C(19467), UINT16_C(43969), UINT16_C(48501), UINT16_C(60693),
        UINT16_C(28052), UINT16_C(41636), UINT16_C(58338),      UINT16_MAX, UINT16_C(36633),      UINT16_MAX,      UINT16_MAX, UINT16_C(57666) } },
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C( 9423), UINT16_C(53904), UINT16_C(55442), UINT16_C(32276),
        UINT16_C(16577), UINT16_C(14939), UINT16_C(18572), UINT16_C(64651), UINT16_C( 6639), UINT16_C(26416), UINT16_C(47693), UINT16_C(55679),
        UINT16_C(35160), UINT16_C(57365), UINT16_C( 9024), UINT16_C(38948), UINT16_C( 9756), UINT16_C(62545), UINT16_C(12155), UINT16_C(57353),
        UINT16_C(44712), UINT16_C(59465), UINT16_C(13165), UINT16_C(64550), UINT16_C( 8937), UINT16_C(32786), UINT16_C(22833), UINT16_C(23377),
        UINT16_C( 7101), UINT16_C(31201), UINT16_C(16185), UINT16_C(57130), UINT16_C(30654), UINT16_C(  561), UINT16_C(54212), UINT16_C(10309),
        UINT16_C(49494), UINT16_C(38525), UINT16_C(35991), UINT16_C(30060), UINT16_C( 7937), UINT16_C(62261), UINT16_C(27455), UINT16_C( 4221),
        UINT16_C(62047), UINT16_C(21630), UINT16_C(45045), UINT16_C(36476), UINT16_C(48324), UINT16_C(31799), UINT16_C(27452), UINT16_C(40227) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(28613), UINT16_C(42035), UINT16_C(23402), UINT16_C( 1161),
        UINT16_C(36809), UINT16_C(35746), UINT16_C(15104), UINT16_C(15897), UINT16_C(15440), UINT16_C(55076), UINT16_C(58671), UINT16_C(22368),
        UINT16_C(43167), UINT16_C(31300), UINT16_C(25094), UINT16_C(43474), UINT16_C(44983), UINT16_C(16487), UINT16_C(15320), UINT16_C(38278),
        UINT16_C(11995), UINT16_C(47296), UINT16_C(28600), UINT16_C(40858), UINT16_C(43399), UINT16_C(42754), UINT16_C(16147), UINT16_C(45821),
        UINT16_C(58648), UINT16_C(42442), UINT16_C(11005), UINT16_C(25997), UINT16_C(33859), UINT16_C(57531), UINT16_C(55251), UINT16_C(26738),
        UINT16_C( 4159), UINT16_C(30237), UINT16_C(  381), UINT16_C(49529), UINT16_C(14984), UINT16_C( 5542), UINT16_C(58289), UINT16_C(47104),
        UINT16_C(32499), UINT16_C( 6651), UINT16_C( 1863), UINT16_C(52481), UINT16_C(45727), UINT16_C(40810), UINT16_C(42679), UINT16_C(28558) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    2),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX,      UINT16_MAX, UINT16_C(38036),      UINT16_MAX,      UINT16_MAX, UINT16_C(33437),
        UINT16_C(53386), UINT16_C(50685), UINT16_C(33676),      UINT16_MAX, UINT16_C(22079),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX, UINT16_C(34118),      UINT16_MAX, UINT16_C(54739),      UINT16_MAX, UINT16_C(27475),      UINT16_MAX,
        UINT16_C(56707),      UINT16_MAX, UINT16_C(41765),      UINT16_MAX, UINT16_C(52336),      UINT16_MAX, UINT16_C(38980),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX, UINT16_C(27190),      UINT16_MAX, UINT16_C(64513), UINT16_C(58092),      UINT16_MAX, UINT16_C(37047),
        UINT16_C(53653),      UINT16_MAX, UINT16_C(36372),      UINT16_MAX, UINT16_C(22921),      UINT16_MAX,      UINT16_MAX, UINT16_C(51325),
             UINT16_MAX, UINT16_C(28281), UINT16_C(46908),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuh_vadd_VuhVuh_sat(a, b);

    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u16_random(1);
    simde_hvx_vector_t r = simde_Q6_Vuh_vadd_VuhVuh_sat(a, b);

    simde_test_hvx_vector_u16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VuwVuw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[SIMDE_HVX_VECTOR_I32_COUNT];
    uint32_t b[SIMDE_HVX_VECTOR_I32_COUNT];
    uint32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
  } test_vec[] = {
    { { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1), UINT32_C(1718574426), UINT32_C(1067975435), UINT32_C(3019635423), UINT32_C(1058699292),
        UINT32_C(2131228585), UINT32_C( 270080171), UINT32_C(1624770660), UINT32_C( 865884081), UINT32_C(3978388873), UINT32_C(3790392222), UINT32_C(3508098169), UINT32_C(2787711512),
        UINT32_C(2666910910), UINT32_C(4039157713), UINT32_C( 595865691), UINT32_C(2053268167), UINT32_C(1618977746), UINT32_C(  67744517), UINT32_C(2850593659), UINT32_C(3848643588) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),
        UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C( 838828092), UINT32_C(1172951847), UINT32_C( 703326965), UINT32_C(1911268364),
        UINT32_C(2015961215), UINT32_C(1428408853), UINT32_C(3490265559), UINT32_C(2701625217), UINT32_C(1820697771), UINT32_C(2750757459), UINT32_C(1867360538), UINT32_C( 199971881),
        UINT32_C( 941798667), UINT32_C(3406742180), UINT32_C(1598634505), UINT32_C( 313992613), UINT32_C(2426035004), UINT32_C(2859455876), UINT32_C(2979388460), UINT32_C(2101663560) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         2),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX,           UINT32_MAX, UINT32_C(2557402518), UINT32_C(2240927282), UINT32_C(3722962388), UINT32_C(2969967656),
        UINT32_C(4147189800), UINT32_C(1698489024),           UINT32_MAX, UINT32_C(3567509298),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(2987683393),
        UINT32_C(3608709577),           UINT32_MAX, UINT32_C(2194500196), UINT32_C(2367260780), UINT32_C(4045012750), UINT32_C(2927200393),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1), UINT32_C( 514666007), UINT32_C(3171239982), UINT32_C(4129449276), UINT32_C(2466964524),
        UINT32_C( 335579243), UINT32_C( 216548930), UINT32_C( 295287701), UINT32_C( 428251190), UINT32_C(4041273399), UINT32_C( 327627858), UINT32_C(3429125565), UINT32_C(2485494873),
        UINT32_C(2710708985), UINT32_C(3068050817), UINT32_C(  50142078), UINT32_C(2424590255), UINT32_C(3341543315), UINT32_C(1262105625), UINT32_C(1180884321), UINT32_C(2326992741) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),
        UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C( 595380698), UINT32_C(3214835190), UINT32_C(3851901395), UINT32_C(3866608574),
        UINT32_C(4197634328), UINT32_C(1698984958), UINT32_C( 874223025), UINT32_C( 248527553), UINT32_C(  23845891), UINT32_C(2930450380), UINT32_C(1853427163), UINT32_C( 372477368),
        UINT32_C(1862291964), UINT32_C(2824350324), UINT32_C( 959781636), UINT32_C(1539041924), UINT32_C(3613314133), UINT32_C(2309176855), UINT32_C(1850740904), UINT32_C( 925606396) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         2),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX,           UINT32_MAX, UINT32_C(1110046705),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                  UINT32_MAX, UINT32_C(1915533888), UINT32_C(1169510726), UINT32_C( 676778743), UINT32_C(4065119290), UINT32_C(3258078238),           UINT32_MAX, UINT32_C(2857972241),
                  UINT32_MAX,           UINT32_MAX, UINT32_C(1009923714), UINT32_C(3963632179),           UINT32_MAX, UINT32_C(3571282480), UINT32_C(3031625225), UINT32_C(3252599137) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuw_vadd_VuwVuw_sat(a, b);

    simde_test_hvx_vector_u32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u32_random(1);
    simde_hvx_vector_t r = simde_Q6_Vuw_vadd_VuwVuw_sat(a, b);

    simde_test_hvx_vector_u32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_WbWb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[SIMDE_HVX_PAIR_SIZE];
    int8_t b[SIMDE_HVX_PAIR_SIZE];
    int8_t r[SIMDE_HVX_PAIR_SIZE];
  } test_vec[] = {
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),  INT8_C(  77),  INT8_C(  97),  INT8_C(  22), -INT8_C(  75),
         INT8_C(  87), -INT8_C(  52), -INT8_C(  39),  INT8_C(  84), -INT8_C(  42),  INT8_C(  22),  INT8_C( 122), -INT8_C( 126),
        -INT8_C(  71),  INT8_C(  48), -INT8_C(  16),  INT8_C(  77), -INT8_C(  65), -INT8_C(  18), -INT8_C( 113),  INT8_C(  59),
         INT8_C(  64),  INT8_C(  66), -INT8_C(  77), -INT8_C(  65), -INT8_C(  69), -INT8_C(  62),  INT8_C(   1), -INT8_C(  22),
         INT8_C(   6),  INT8_C( 100), -INT8_C( 126),  INT8_C( 108),  INT8_C(  83), -INT8_C(  17), -INT8_C(  17), -INT8_C(  84),
        -INT8_C( 111), -INT8_C(   5), -INT8_C(  62), -INT8_C(  15),  INT8_C(  78),  INT8_C(  49),      INT8_MAX,  INT8_C( 120),
        -INT8_C(  74), -INT8_C(  71),  INT8_C(  80),  INT8_C(  53), -INT8_C(  63),  INT8_C(  50),  INT8_C(  34),  INT8_C( 125),
        -INT8_C(  50),  INT8_C( 102),  INT8_C(  53),  INT8_C(   8), -INT8_C( 110),  INT8_C(  94), -INT8_C(  60),  INT8_C(  41),
        -INT8_C( 100),  INT8_C(  83), -INT8_C(  82),  INT8_C(  63),  INT8_C(  81),  INT8_C(   2),  INT8_C(   8),  INT8_C(  69),
         INT8_C(   4),  INT8_C(  68), -INT8_C(  83), -INT8_C(  38), -INT8_C(  12),  INT8_C(   3), -INT8_C( 101),  INT8_C(   6),
        -INT8_C(  57), -INT8_C(  65), -INT8_C(  73),  INT8_C(  84),  INT8_C(  22), -INT8_C(   6),  INT8_C(  94),  INT8_C(  59),
         INT8_C(  36),  INT8_C(  61), -INT8_C(  12),  INT8_C( 108),  INT8_C(   5), -INT8_C(  66),  INT8_C(  82),  INT8_C(  46),
         INT8_C(  68),  INT8_C(   5),  INT8_C(  21),  INT8_C(  40),  INT8_C(   5), -INT8_C(  28), -INT8_C(  70),  INT8_C(  49),
         INT8_C(  29), -INT8_C(  42), -INT8_C(  82),  INT8_C(  75), -INT8_C(  50),  INT8_C(   7),  INT8_C(  12),  INT8_C(  29),
         INT8_C( 109), -INT8_C(  21),  INT8_C( 107), -INT8_C(  93),  INT8_C( 106),  INT8_C(  27),  INT8_C(  16), -INT8_C( 124),
         INT8_C(  57),  INT8_C(  83),  INT8_C( 106),  INT8_C(  46),  INT8_C(  69),  INT8_C(  96),  INT8_C(  89), -INT8_C(  95),
         INT8_C(  50), -INT8_C(  46), -INT8_C(   9),  INT8_C(  68),  INT8_C(  60), -INT8_C(  12),  INT8_C(  77),  INT8_C( 124),
         INT8_C(  47),  INT8_C(   2), -INT8_C(  86),  INT8_C( 119),  INT8_C(  94),  INT8_C(  87), -INT8_C(  85),  INT8_C(  16),
        -INT8_C(  39), -INT8_C(  59), -INT8_C(  33),  INT8_C(  32), -INT8_C(  51), -INT8_C(  83),  INT8_C( 119), -INT8_C(  83),
         INT8_C( 121),  INT8_C(  96),  INT8_C(  86),  INT8_C(   8),  INT8_C(  63), -INT8_C(  61),  INT8_C(  11),  INT8_C(  39),
        -INT8_C(  57),  INT8_C(  36), -INT8_C(  88), -INT8_C(  22),  INT8_C(  88),  INT8_C(  98), -INT8_C(  32), -INT8_C(  63),
         INT8_C( 105), -INT8_C(  79),  INT8_C(  31), -INT8_C(  22),  INT8_C(   8), -INT8_C(  52), -INT8_C(  91),  INT8_C(  43),
        -INT8_C(  64),  INT8_C( 126),  INT8_C(  99), -INT8_C( 101), -INT8_C(  14), -INT8_C( 120), -INT8_C(  26),  INT8_C(  68),
         INT8_C( 118),  INT8_C( 117),  INT8_C(  76),  INT8_C(  80), -INT8_C(  58),  INT8_C(  60), -INT8_C(  97), -INT8_C(  73),
         INT8_C(  36),  INT8_C(   7),  INT8_C(   1),  INT8_C(  46),  INT8_C(  83),  INT8_C( 108), -INT8_C(  63), -INT8_C(  34),
         INT8_C(  77),  INT8_C(  72),  INT8_C( 122),  INT8_C( 108), -INT8_C(   7), -INT8_C( 111), -INT8_C(  67), -INT8_C(  58),
        -INT8_C(  77),  INT8_C(  61),  INT8_C(  86), -INT8_C(  15), -INT8_C(   1),  INT8_C(  60), -INT8_C(  32), -INT8_C( 124),
         INT8_C(  30), -INT8_C(  89), -INT8_C(  58), -INT8_C( 103),  INT8_C(  60),  INT8_C(  87),  INT8_C(  83),  INT8_C( 109),
         INT8_C(  67),  INT8_C(  47),  INT8_C(  79), -INT8_C(  22),  INT8_C(  77),  INT8_C(  19),  INT8_C(  79),  INT8_C(  37),
        -INT8_C(  90),  INT8_C(  22), -INT8_C(  28),  INT8_C(  97), -INT8_C( 115),  INT8_C(  71),  INT8_C(   9), -INT8_C(  43),
        -INT8_C(   5), -INT8_C(  23), -INT8_C(  50), -INT8_C(  43), -INT8_C(  51), -INT8_C( 115), -INT8_C(  74),  INT8_C(  69) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C( 115),  INT8_C(  93),  INT8_C(  88),  INT8_C(  19),
         INT8_C(   4),  INT8_C(  62), -INT8_C( 114), -INT8_C(  78),  INT8_C(  58), -INT8_C( 104),  INT8_C(  51),  INT8_C(   1),
        -INT8_C(  25),  INT8_C( 117), -INT8_C(  49),  INT8_C(  16), -INT8_C(  76),  INT8_C( 111), -INT8_C(  85),  INT8_C( 115),
        -INT8_C(  40),  INT8_C(  71),  INT8_C( 111), -INT8_C(  10), -INT8_C( 102),  INT8_C(  68), -INT8_C(  98), -INT8_C(  26),
        -INT8_C(  18),  INT8_C(  63),  INT8_C(  85), -INT8_C( 126),  INT8_C(  10),  INT8_C(  12), -INT8_C(   8),  INT8_C( 126),
        -INT8_C(  86),  INT8_C(  34), -INT8_C( 125),  INT8_C(  42), -INT8_C(  16),  INT8_C(  89),  INT8_C(  57),  INT8_C(  50),
        -INT8_C(  86), -INT8_C(  89), -INT8_C(  14),  INT8_C(  67), -INT8_C(  51), -INT8_C( 126), -INT8_C( 114), -INT8_C(   5),
        -INT8_C( 110), -INT8_C(  11), -INT8_C( 119),  INT8_C(  28), -INT8_C(  33),  INT8_C( 100), -INT8_C(  66),  INT8_C(   3),
         INT8_C( 119),  INT8_C(  72),  INT8_C(  80), -INT8_C(  12),  INT8_C( 115), -INT8_C(  39), -INT8_C(   5),  INT8_C(  75),
         INT8_C(  13),  INT8_C(  78), -INT8_C(   9),  INT8_C(  95),  INT8_C(   7),  INT8_C(  31), -INT8_C(  90), -INT8_C(  85),
        -INT8_C(  79),  INT8_C( 104), -INT8_C( 101),  INT8_C(  45), -INT8_C(  65),  INT8_C(   8), -INT8_C(  36),  INT8_C(  71),
         INT8_C(  56),  INT8_C(  21), -INT8_C( 103),  INT8_C(  44), -INT8_C( 100), -INT8_C(   9), -INT8_C( 116),  INT8_C(  31),
         INT8_C( 102),  INT8_C( 114),  INT8_C(  33), -INT8_C( 115), -INT8_C(  73),  INT8_C(  50), -INT8_C(  74), -INT8_C(  96),
        -INT8_C(  55), -INT8_C(  26),  INT8_C(  22),  INT8_C(  15), -INT8_C(  95),  INT8_C(  94),  INT8_C(  90), -INT8_C( 105),
         INT8_C( 120), -INT8_C( 114), -INT8_C(  92),  INT8_C( 108), -INT8_C(   1),  INT8_C( 103),  INT8_C(  94),  INT8_C(  40),
         INT8_C(  75),  INT8_C(  82), -INT8_C(  21), -INT8_C(  11),  INT8_C(  56),  INT8_C(  97), -INT8_C(  52), -INT8_C(  21),
        -INT8_C(  55), -INT8_C(  21), -INT8_C(  40), -INT8_C( 101),  INT8_C(   7),  INT8_C( 113),  INT8_C( 108), -INT8_C( 103),
         INT8_C(  20), -INT8_C( 119),  INT8_C(  79),  INT8_C(   6), -INT8_C( 107),  INT8_C(   3), -INT8_C(  65),  INT8_C(  31),
        -INT8_C(  31),  INT8_C(  36), -INT8_C( 115), -INT8_C(  64), -INT8_C(  98),  INT8_C(  30),  INT8_C(  70),  INT8_C(  78),
         INT8_C( 119), -INT8_C(  32), -INT8_C( 119), -INT8_C(  39),  INT8_C(  16), -INT8_C(  35), -INT8_C(  59), -INT8_C(  83),
        -INT8_C( 114),  INT8_C(  81),  INT8_C(  16), -INT8_C(  62),  INT8_C(  98), -INT8_C( 103),  INT8_C(  41),  INT8_C( 118),
        -INT8_C(  69), -INT8_C(  57),  INT8_C(  43), -INT8_C( 127), -INT8_C(  46), -INT8_C( 116), -INT8_C( 110), -INT8_C(   3),
         INT8_C(  12),  INT8_C(  57),  INT8_C(  44), -INT8_C(  49), -INT8_C( 116),  INT8_C(  66), -INT8_C(  46),  INT8_C(  58),
         INT8_C(  71), -INT8_C(  94), -INT8_C(  54), -INT8_C(  22), -INT8_C(  95),  INT8_C(  88), -INT8_C(  75), -INT8_C( 106),
         INT8_C(  30),  INT8_C(  52),  INT8_C( 101),  INT8_C( 122), -INT8_C( 101), -INT8_C( 110),  INT8_C(  35),  INT8_C(  86),
        -INT8_C( 107),  INT8_C(   3), -INT8_C( 108),  INT8_C(  18),  INT8_C(  74), -INT8_C(  87),  INT8_C(  26), -INT8_C( 117),
        -INT8_C(  81),  INT8_C(  39), -INT8_C(  38),  INT8_C( 104),  INT8_C(  94),  INT8_C( 124),  INT8_C( 104), -INT8_C(  79),
         INT8_C(  91), -INT8_C(  43),  INT8_C(  96), -INT8_C( 111),  INT8_C(  42), -INT8_C(  56), -INT8_C(  35), -INT8_C( 110),
         INT8_C( 112),  INT8_C(  44),  INT8_C(  90),  INT8_C(  24), -INT8_C(  36), -INT8_C(  30), -INT8_C( 103),  INT8_C(  97),
         INT8_C( 122), -INT8_C(  30), -INT8_C(  88),  INT8_C(   0),  INT8_C(  84),  INT8_C(  83), -INT8_C(  20),  INT8_C(  92),
        -INT8_C(  20),  INT8_C(  97),  INT8_C(  35),  INT8_C(  67), -INT8_C( 104),      INT8_MIN,  INT8_C(  55), -INT8_C(  82) },
      {  INT8_C(   0), -INT8_C(   1),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   2),
             INT8_MAX, -INT8_C( 127), -INT8_C(   2),      INT8_MIN, -INT8_C(  38), -INT8_C(  66),  INT8_C( 110), -INT8_C(  56),
         INT8_C(  91),  INT8_C(  10),  INT8_C( 103),  INT8_C(   6),  INT8_C(  16), -INT8_C(  82), -INT8_C(  83), -INT8_C( 125),
        -INT8_C(  96), -INT8_C(  91), -INT8_C(  65),  INT8_C(  93),  INT8_C( 115),  INT8_C(  93),  INT8_C(  58), -INT8_C(  82),
         INT8_C(  24), -INT8_C( 119),  INT8_C(  34), -INT8_C(  75),  INT8_C(  85),  INT8_C(   6), -INT8_C(  97), -INT8_C(  48),
        -INT8_C(  12), -INT8_C(  93), -INT8_C(  41), -INT8_C(  18),  INT8_C(  93), -INT8_C(   5), -INT8_C(  25),  INT8_C(  42),
         INT8_C(  59),  INT8_C(  29),  INT8_C(  69),  INT8_C(  27),  INT8_C(  62), -INT8_C( 118), -INT8_C(  72), -INT8_C(  86),
         INT8_C(  96),  INT8_C(  96),  INT8_C(  66),  INT8_C( 120), -INT8_C( 114), -INT8_C(  76), -INT8_C(  80),  INT8_C( 120),
         INT8_C(  96),  INT8_C(  91), -INT8_C(  66),  INT8_C(  36),  INT8_C( 113), -INT8_C(  62), -INT8_C( 126),  INT8_C(  44),
         INT8_C(  19), -INT8_C( 101), -INT8_C(   2),  INT8_C(  51), -INT8_C(  60), -INT8_C(  37),  INT8_C(   3), -INT8_C( 112),
         INT8_C(  17), -INT8_C( 110), -INT8_C(  92),  INT8_C(  57), -INT8_C(   5),  INT8_C(  34),  INT8_C(  65), -INT8_C(  79),
         INT8_C( 120),  INT8_C(  39),  INT8_C(  82), -INT8_C( 127), -INT8_C(  43),  INT8_C(   2),  INT8_C(  58), -INT8_C( 126),
         INT8_C(  92),  INT8_C(  82), -INT8_C( 115), -INT8_C( 104), -INT8_C(  95), -INT8_C(  75), -INT8_C(  34),  INT8_C(  77),
        -INT8_C(  86),  INT8_C( 119),  INT8_C(  54), -INT8_C(  75), -INT8_C(  68),  INT8_C(  22),  INT8_C( 112), -INT8_C(  47),
        -INT8_C(  26), -INT8_C(  68), -INT8_C(  60),  INT8_C(  90),  INT8_C( 111),  INT8_C( 101),  INT8_C( 102), -INT8_C(  76),
        -INT8_C(  27),  INT8_C( 121),  INT8_C(  15),  INT8_C(  15),  INT8_C( 105), -INT8_C( 126),  INT8_C( 110), -INT8_C(  84),
        -INT8_C( 124), -INT8_C(  91),  INT8_C(  85),  INT8_C(  35),  INT8_C( 125), -INT8_C(  63),  INT8_C(  37), -INT8_C( 116),
        -INT8_C(   5), -INT8_C(  67), -INT8_C(  49), -INT8_C(  33),  INT8_C(  67),  INT8_C( 101), -INT8_C(  71),  INT8_C(  21),
         INT8_C(  67), -INT8_C( 117), -INT8_C(   7),  INT8_C( 125), -INT8_C(  13),  INT8_C(  90),  INT8_C( 106),  INT8_C(  47),
        -INT8_C(  70), -INT8_C(  23),  INT8_C( 108), -INT8_C(  32),  INT8_C( 107), -INT8_C(  53), -INT8_C(  67), -INT8_C(   5),
        -INT8_C(  16),  INT8_C(  64), -INT8_C(  33), -INT8_C(  31),  INT8_C(  79), -INT8_C(  96), -INT8_C(  48), -INT8_C(  44),
         INT8_C(  85),  INT8_C( 117), -INT8_C(  72), -INT8_C(  84), -INT8_C(  70), -INT8_C(   5),  INT8_C(   9),  INT8_C(  55),
         INT8_C(  36),  INT8_C( 120),  INT8_C(  74),  INT8_C( 107), -INT8_C(  38),  INT8_C(  88),  INT8_C(  55),  INT8_C(  40),
        -INT8_C(  52), -INT8_C(  73), -INT8_C( 113),  INT8_C( 106),  INT8_C( 126), -INT8_C(  54), -INT8_C(  72),  INT8_C( 126),
        -INT8_C(  67),  INT8_C(  23),  INT8_C(  22),  INT8_C(  58),  INT8_C( 103), -INT8_C( 108),  INT8_C(  84),  INT8_C(  77),
         INT8_C(  66),  INT8_C(  59),  INT8_C( 102), -INT8_C(  88), -INT8_C(  18), -INT8_C(   2), -INT8_C(  28),  INT8_C(  52),
        -INT8_C(  30),  INT8_C(  75),  INT8_C(  14),  INT8_C( 126),  INT8_C(  67),  INT8_C(  58), -INT8_C(  41),  INT8_C(  81),
         INT8_C(  98),  INT8_C( 100),  INT8_C(  48),  INT8_C(  89),  INT8_C(  93), -INT8_C(  72),  INT8_C(  72),  INT8_C(  53),
         INT8_C( 121),  INT8_C( 124),  INT8_C(  38),  INT8_C(  42),  INT8_C( 102),  INT8_C(  31),  INT8_C(  48), -INT8_C(   1),
        -INT8_C(  77),  INT8_C(  91), -INT8_C(  87),  INT8_C(   2),  INT8_C(  41), -INT8_C(  11), -INT8_C(  24), -INT8_C( 122),
         INT8_C(  32), -INT8_C(   8), -INT8_C( 116),  INT8_C(  97), -INT8_C(  31), -INT8_C( 102), -INT8_C(  11),  INT8_C(  49),
        -INT8_C(  25),  INT8_C(  74), -INT8_C(  15),  INT8_C(  24),  INT8_C( 101),  INT8_C(  13), -INT8_C(  19), -INT8_C(  13) } },
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1), -INT8_C(  75), -INT8_C(  22),  INT8_C(  48), -INT8_C( 126),
        -INT8_C(  66),  INT8_C(  52),  INT8_C(   7),  INT8_C(  44), -INT8_C( 102),  INT8_C( 101),  INT8_C(  40),  INT8_C(  75),
        -INT8_C(  90), -INT8_C(  66), -INT8_C(  10),  INT8_C(  75),  INT8_C( 116),  INT8_C(   8),  INT8_C(  83), -INT8_C(  42),
         INT8_C(  17), -INT8_C(  35), -INT8_C(   2),  INT8_C(  58),  INT8_C( 101),  INT8_C(  73),  INT8_C(  53), -INT8_C( 106),
         INT8_C(  26),  INT8_C( 125), -INT8_C(  18),  INT8_C(  40), -INT8_C( 102), -INT8_C(  98), -INT8_C(  44), -INT8_C( 107),
         INT8_C(  34),  INT8_C(  99), -INT8_C(  93),  INT8_C( 117),  INT8_C( 120), -INT8_C(  67),  INT8_C(  54),  INT8_C(  16),
         INT8_C(  91),  INT8_C(  64),  INT8_C(  81),  INT8_C(  87),  INT8_C(  37),  INT8_C(  82),  INT8_C(  88),  INT8_C( 109),
         INT8_C(  85), -INT8_C(   4), -INT8_C(  67),  INT8_C( 112),  INT8_C(  76), -INT8_C(  70), -INT8_C(  56), -INT8_C( 110),
         INT8_C(   3),  INT8_C( 113), -INT8_C( 104), -INT8_C(  98), -INT8_C(  16), -INT8_C(  61),  INT8_C(  23),  INT8_C(  31),
         INT8_C(  80),  INT8_C(  89),  INT8_C(  16), -INT8_C( 104), -INT8_C(  22), -INT8_C(  46),  INT8_C(  10),  INT8_C(  81),
         INT8_C( 122),  INT8_C( 102),  INT8_C( 117),  INT8_C( 118), -INT8_C(  92),  INT8_C(  26), -INT8_C( 123), -INT8_C(  61),
         INT8_C(  17), -INT8_C(   5), -INT8_C(  35),  INT8_C( 108),  INT8_C( 101),  INT8_C(  23), -INT8_C(  41), -INT8_C(  83),
             INT8_MIN,  INT8_C(  68),  INT8_C(  86), -INT8_C( 121), -INT8_C( 109), -INT8_C(  86),  INT8_C(  15),  INT8_C( 125),
        -INT8_C(  49), -INT8_C(  18),  INT8_C(  76), -INT8_C( 107), -INT8_C(  17), -INT8_C(  48), -INT8_C(  34),  INT8_C(  53),
         INT8_C(  58), -INT8_C(  15), -INT8_C( 111), -INT8_C(  81), -INT8_C(  17),  INT8_C(  19),  INT8_C(  95),  INT8_C(  46),
         INT8_C(  16),  INT8_C( 105),  INT8_C(  63),  INT8_C(  76),  INT8_C(  15),  INT8_C( 106), -INT8_C(   1),  INT8_C(  96),
         INT8_C(  53), -INT8_C(  66), -INT8_C(  57),  INT8_C(  39), -INT8_C(  37),  INT8_C( 105), -INT8_C(  75), -INT8_C( 104),
         INT8_C( 125), -INT8_C(  45),  INT8_C(  26), -INT8_C( 108),  INT8_C( 112),  INT8_C(  53),  INT8_C( 118),  INT8_C( 123),
        -INT8_C(  16),  INT8_C(  48), -INT8_C(  16),  INT8_C(  64), -INT8_C(  37), -INT8_C(  28), -INT8_C(  52),  INT8_C( 121),
        -INT8_C(   3), -INT8_C(  78), -INT8_C(  10), -INT8_C(  43), -INT8_C(  41),  INT8_C( 105),  INT8_C(  87),  INT8_C(  82),
         INT8_C(  95),  INT8_C( 107), -INT8_C( 110),  INT8_C(  44),  INT8_C(  37), -INT8_C( 107), -INT8_C(  58),  INT8_C(  26),
        -INT8_C( 127), -INT8_C(   5), -INT8_C(  59),  INT8_C(  66), -INT8_C(  86), -INT8_C(  21), -INT8_C(  40),  INT8_C(   8),
        -INT8_C(  23), -INT8_C(  50), -INT8_C(  83),  INT8_C( 104),  INT8_C(  79), -INT8_C(  95), -INT8_C(  76), -INT8_C(  41),
         INT8_C(  28),  INT8_C(  75), -INT8_C(  36), -INT8_C( 103), -INT8_C(  95),  INT8_C(  88), -INT8_C(  24), -INT8_C(  84),
         INT8_C( 108),  INT8_C(  38), -INT8_C(  49),  INT8_C(  51), -INT8_C(  39), -INT8_C( 126),  INT8_C(  31),  INT8_C(  28),
        -INT8_C(  55), -INT8_C( 120),  INT8_C( 119), -INT8_C(  69),  INT8_C(  16), -INT8_C(  32), -INT8_C( 109), -INT8_C(   3),
        -INT8_C(  69),  INT8_C(  25), -INT8_C(  35), -INT8_C(  92),  INT8_C(  21), -INT8_C(  53),  INT8_C(  35),  INT8_C(  87),
             INT8_MAX,  INT8_C(  95), -INT8_C(  98), -INT8_C( 107),  INT8_C(  77),  INT8_C(  90), -INT8_C(  75), -INT8_C(  21),
         INT8_C(  21),  INT8_C(  37), -INT8_C(   3), -INT8_C(  52), -INT8_C(  16), -INT8_C(   8), -INT8_C(  99),  INT8_C(  96),
        -INT8_C(   6),  INT8_C(  53),  INT8_C(   5), -INT8_C(  25), -INT8_C(  72),  INT8_C(  39),  INT8_C( 121),  INT8_C(  73),
         INT8_C(  36), -INT8_C(  46),  INT8_C(  65),  INT8_C( 119),  INT8_C(  25), -INT8_C(  61), -INT8_C(  31), -INT8_C(  40) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(   1),  INT8_C( 116),  INT8_C( 126), -INT8_C(   2),
        -INT8_C(  22),  INT8_C(  65),  INT8_C(  61),  INT8_C(  98),  INT8_C(  62), -INT8_C( 115), -INT8_C(  34), -INT8_C(  69),
         INT8_C(  90),  INT8_C( 113),  INT8_C( 116), -INT8_C(  89),  INT8_C(  55), -INT8_C(  52), -INT8_C( 106),  INT8_C( 121),
         INT8_C(  47), -INT8_C( 100),  INT8_C( 103), -INT8_C(  97),  INT8_C(  36),  INT8_C(  70),  INT8_C(  60),  INT8_C(  40),
        -INT8_C( 117),  INT8_C(  75),  INT8_C(  43),  INT8_C(  60), -INT8_C(  71), -INT8_C(  34),  INT8_C(  61), -INT8_C( 102),
        -INT8_C( 101), -INT8_C(  36), -INT8_C(  72), -INT8_C(  37),  INT8_C(  44), -INT8_C(  71),  INT8_C(  90), -INT8_C( 105),
        -INT8_C(  25), -INT8_C(   8), -INT8_C( 103),  INT8_C(   6),  INT8_C( 125), -INT8_C( 125),  INT8_C( 106), -INT8_C( 111),
        -INT8_C( 105), -INT8_C(  98),  INT8_C( 115), -INT8_C( 123), -INT8_C(  36),  INT8_C(  34), -INT8_C(  76),  INT8_C(  49),
        -INT8_C(   1),  INT8_C(   6),      INT8_MAX,  INT8_C(   6), -INT8_C(   8), -INT8_C(  58), -INT8_C(  12),  INT8_C(  24),
        -INT8_C(  87),  INT8_C(  14),  INT8_C(  38), -INT8_C(   6), -INT8_C(  33), -INT8_C(  61),  INT8_C(   4), -INT8_C(  88),
        -INT8_C(   4),  INT8_C(  56), -INT8_C( 114), -INT8_C(  77), -INT8_C(  12), -INT8_C(  37),  INT8_C(  31),  INT8_C(  26),
         INT8_C( 107), -INT8_C(  96),  INT8_C(   0),  INT8_C(  26),  INT8_C(  94),  INT8_C(  44),  INT8_C(  97),  INT8_C(  95),
         INT8_C(  12), -INT8_C(  64), -INT8_C(  56), -INT8_C(  49),  INT8_C(  70),  INT8_C(  31),  INT8_C(  55), -INT8_C(  54),
         INT8_C(  74),  INT8_C(  37),  INT8_C(  31), -INT8_C(  63), -INT8_C(  12),  INT8_C(  80),  INT8_C(  54), -INT8_C(  45),
         INT8_C(  75), -INT8_C(  99), -INT8_C( 108), -INT8_C(  39), -INT8_C(  25), -INT8_C( 106), -INT8_C(  74), -INT8_C(  82),
         INT8_C( 125), -INT8_C(  46),  INT8_C(  65), -INT8_C( 118), -INT8_C(  61), -INT8_C(  45),  INT8_C( 122), -INT8_C(  77),
        -INT8_C(  85), -INT8_C( 102), -INT8_C(   9), -INT8_C( 115), -INT8_C(  30),  INT8_C( 122),  INT8_C( 121),  INT8_C(  40),
        -INT8_C(  66), -INT8_C(  95),  INT8_C( 113),  INT8_C( 112),  INT8_C(  40),  INT8_C(  47), -INT8_C(  58),  INT8_C(  44),
         INT8_C(  91),  INT8_C( 125), -INT8_C( 123), -INT8_C(   5), -INT8_C(  86),  INT8_C(  66), -INT8_C( 121), -INT8_C(  15),
         INT8_C(  60), -INT8_C(  99),  INT8_C(  21), -INT8_C(  63), -INT8_C( 120),  INT8_C(  13), -INT8_C(  90), -INT8_C(  12),
         INT8_C(  42), -INT8_C(  48),  INT8_C( 121), -INT8_C(  71),  INT8_C(  70), -INT8_C(  64), -INT8_C(  29),  INT8_C(   3),
         INT8_C(  77), -INT8_C( 102), -INT8_C(  16), -INT8_C(  24), -INT8_C(  62),  INT8_C( 115), -INT8_C(  53), -INT8_C( 126),
         INT8_C( 101), -INT8_C(  35),      INT8_MAX, -INT8_C(  85), -INT8_C(  32), -INT8_C(  76), -INT8_C(  23), -INT8_C( 119),
         INT8_C(  99), -INT8_C(  57), -INT8_C( 106), -INT8_C( 115), -INT8_C(  72),  INT8_C(  48),  INT8_C( 122),  INT8_C(   3),
        -INT8_C(  66),  INT8_C(  68), -INT8_C(  87), -INT8_C(  42),  INT8_C(  47),  INT8_C( 113), -INT8_C(  68),  INT8_C(  52),
        -INT8_C(  74), -INT8_C(  80), -INT8_C(  60), -INT8_C( 116),  INT8_C( 124),  INT8_C(  13), -INT8_C(  41),  INT8_C( 125),
        -INT8_C(  93), -INT8_C(  63),  INT8_C(  21), -INT8_C(  40),  INT8_C(  66),  INT8_C(   1),  INT8_C(  70), -INT8_C( 110),
         INT8_C(  54),  INT8_C(  35),  INT8_C(  46),  INT8_C(  65), -INT8_C( 108),  INT8_C(  77),  INT8_C( 118), -INT8_C(  80),
        -INT8_C(  99), -INT8_C( 114), -INT8_C(  68),  INT8_C( 110),  INT8_C(  38),  INT8_C(  87),  INT8_C(  63), -INT8_C(  46),
         INT8_C(  46),  INT8_C( 118),  INT8_C(  55), -INT8_C(  88), -INT8_C(  26), -INT8_C(  25), -INT8_C(  70),  INT8_C(  40),
         INT8_C(  43), -INT8_C(  12), -INT8_C(   6), -INT8_C( 116), -INT8_C(  22), -INT8_C(   4), -INT8_C(  59), -INT8_C( 118) },
      {  INT8_C(   0), -INT8_C(   1),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   2),
             INT8_MAX, -INT8_C( 127), -INT8_C(   2),      INT8_MIN, -INT8_C(  76),  INT8_C(  94), -INT8_C(  82),      INT8_MIN,
        -INT8_C(  88),  INT8_C( 117),  INT8_C(  68), -INT8_C( 114), -INT8_C(  40), -INT8_C(  14),  INT8_C(   6),  INT8_C(   6),
         INT8_C(   0),  INT8_C(  47),  INT8_C( 106), -INT8_C(  14), -INT8_C(  85), -INT8_C(  44), -INT8_C(  23),  INT8_C(  79),
         INT8_C(  64),  INT8_C( 121),  INT8_C( 101), -INT8_C(  39), -INT8_C( 119), -INT8_C( 113),  INT8_C( 113), -INT8_C(  66),
        -INT8_C(  91), -INT8_C(  56),  INT8_C(  25),  INT8_C( 100),  INT8_C(  83),  INT8_C( 124),  INT8_C(  17),  INT8_C(  47),
        -INT8_C(  67),  INT8_C(  63),  INT8_C(  91),  INT8_C(  80), -INT8_C(  92),  INT8_C( 118), -INT8_C( 112), -INT8_C(  89),
         INT8_C(  66),  INT8_C(  56), -INT8_C(  22),  INT8_C(  93), -INT8_C(  94), -INT8_C(  43), -INT8_C(  62), -INT8_C(   2),
        -INT8_C(  20), -INT8_C( 102),  INT8_C(  48), -INT8_C(  11),  INT8_C(  40), -INT8_C(  36),  INT8_C( 124), -INT8_C(  61),
         INT8_C(   2),  INT8_C( 119),  INT8_C(  23), -INT8_C(  92), -INT8_C(  24), -INT8_C( 119),  INT8_C(  11),  INT8_C(  55),
        -INT8_C(   7),  INT8_C( 103),  INT8_C(  54), -INT8_C( 110), -INT8_C(  55), -INT8_C( 107),  INT8_C(  14), -INT8_C(   7),
         INT8_C( 118), -INT8_C(  98),  INT8_C(   3),  INT8_C(  41), -INT8_C( 104), -INT8_C(  11), -INT8_C(  92), -INT8_C(  35),
         INT8_C( 124), -INT8_C( 101), -INT8_C(  35), -INT8_C( 122), -INT8_C(  61),  INT8_C(  67),  INT8_C(  56),  INT8_C(  12),
        -INT8_C( 116),  INT8_C(   4),  INT8_C(  30),  INT8_C(  86), -INT8_C(  39), -INT8_C(  55),  INT8_C(  70),  INT8_C(  71),
         INT8_C(  25),  INT8_C(  19),  INT8_C( 107),  INT8_C(  86), -INT8_C(  29),  INT8_C(  32),  INT8_C(  20),  INT8_C(   8),
        -INT8_C( 123), -INT8_C( 114),  INT8_C(  37), -INT8_C( 120), -INT8_C(  42), -INT8_C(  87),  INT8_C(  21), -INT8_C(  36),
        -INT8_C( 115),  INT8_C(  59),      INT8_MIN, -INT8_C(  42), -INT8_C(  46),  INT8_C(  61),  INT8_C( 121),  INT8_C(  19),
        -INT8_C(  32),  INT8_C(  88), -INT8_C(  66), -INT8_C(  76), -INT8_C(  67), -INT8_C(  29),  INT8_C(  46), -INT8_C(  64),
         INT8_C(  59),  INT8_C( 116), -INT8_C( 117),  INT8_C(   4), -INT8_C( 104),  INT8_C( 100),  INT8_C(  60), -INT8_C(  89),
         INT8_C(  75), -INT8_C(  83),  INT8_C( 117),  INT8_C(  59), -INT8_C( 123),  INT8_C(  38),  INT8_C(  83),  INT8_C( 106),
         INT8_C(  57),  INT8_C(  79),  INT8_C(  11), -INT8_C( 106),  INT8_C(  95),  INT8_C( 118), -INT8_C(   3),  INT8_C(  70),
        -INT8_C( 119),  INT8_C(  59),  INT8_C(  11), -INT8_C(  27),  INT8_C( 107),  INT8_C(  85), -INT8_C(  87),  INT8_C(  29),
        -INT8_C(  50), -INT8_C( 107), -INT8_C(  75),  INT8_C(  42),  INT8_C( 108),  INT8_C(  94), -INT8_C(  93), -INT8_C( 118),
         INT8_C(  78), -INT8_C(  85),  INT8_C(  44),  INT8_C(  19),  INT8_C(  47),  INT8_C(  85), -INT8_C(  99),  INT8_C(  96),
             INT8_MAX,  INT8_C(  18),  INT8_C( 114),  INT8_C(  38),  INT8_C(  89), -INT8_C( 120),  INT8_C(  98), -INT8_C(  81),
         INT8_C(  42),  INT8_C( 106),  INT8_C( 120),  INT8_C(   9),  INT8_C(   8), -INT8_C(  13), -INT8_C(  37),  INT8_C(  80),
             INT8_MAX,  INT8_C(  56),  INT8_C(  59),  INT8_C(  71), -INT8_C( 116), -INT8_C(  19),  INT8_C( 106),  INT8_C( 122),
         INT8_C(  94), -INT8_C(  38), -INT8_C(  14),  INT8_C( 124),  INT8_C(  87), -INT8_C(  52),  INT8_C( 105), -INT8_C(  23),
        -INT8_C(  75), -INT8_C( 126), -INT8_C(  52), -INT8_C(  42), -INT8_C(  31), -INT8_C(  89),  INT8_C(  43), -INT8_C( 101),
        -INT8_C(  78), -INT8_C(  77), -INT8_C(  71),  INT8_C(  58),  INT8_C(  22),  INT8_C(  79), -INT8_C(  36),  INT8_C(  50),
         INT8_C(  40), -INT8_C(  85),  INT8_C(  60), -INT8_C( 113), -INT8_C(  98),  INT8_C(  14),  INT8_C(  51),  INT8_C( 113),
         INT8_C(  79), -INT8_C(  58),  INT8_C(  59),  INT8_C(   3),  INT8_C(   3), -INT8_C(  65), -INT8_C(  90),  INT8_C(  98) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wb_vadd_WbWb(a, b);

    simde_test_hvx_vectorpair_i8_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i8_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i8_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wb_vadd_WbWb(a, b);

    simde_test_hvx_vectorpair_i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_WhWh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_PAIR_I16_COUNT];
    int16_t b[SIMDE_HVX_PAIR_I16_COUNT];
    int16_t r[SIMDE_HVX_PAIR_I16_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C( 21833),  INT16_C( 11832),  INT16_C( 11796), -INT16_C( 12446),
         INT16_C( 32341), -INT16_C( 25712),  INT16_C(  4797),  INT16_C( 10502),  INT16_C( 13604), -INT16_C(   311),  INT16_C( 26620), -INT16_C( 26671),
         INT16_C(  3478), -INT16_C( 14541),  INT16_C(  2607), -INT16_C( 22168), -INT16_C( 24496),  INT16_C( 18133),  INT16_C( 21607), -INT16_C( 31089),
         INT16_C( 24759),  INT16_C( 15405), -INT16_C( 16784), -INT16_C( 25805), -INT16_C( 24823),  INT16_C( 23262),  INT16_C( 18333), -INT16_C(  5877),
         INT16_C( 31190),  INT16_C( 23626), -INT16_C(  1530), -INT16_C( 15947), -INT16_C( 17676), -INT16_C( 15605),  INT16_C( 22463),  INT16_C(  5969),
         INT16_C(  5344), -INT16_C( 31969), -INT16_C( 23449),  INT16_C(  7225), -INT16_C( 30109),  INT16_C( 31854), -INT16_C( 16289), -INT16_C(  6267),
         INT16_C(  9009), -INT16_C( 10951),  INT16_C( 13005), -INT16_C( 20773),  INT16_C( 32035), -INT16_C( 17935), -INT16_C( 14223),  INT16_C(  7909),
         INT16_C( 11628),  INT16_C( 27051),  INT16_C( 22833), -INT16_C(  2648),  INT16_C( 12354), -INT16_C( 12424), -INT16_C( 24283),  INT16_C( 22247),
         INT16_C(  5646),  INT16_C( 18845), -INT16_C( 28203), -INT16_C( 26488),  INT16_C(   343), -INT16_C( 22100), -INT16_C(  8941), -INT16_C( 10024),
        -INT16_C( 13495), -INT16_C( 16070), -INT16_C( 12293), -INT16_C( 12167),  INT16_C( 15042),  INT16_C( 23028), -INT16_C(  7094), -INT16_C(  4723),
         INT16_C( 21391), -INT16_C( 29295),  INT16_C(  4913), -INT16_C(    99),  INT16_C( 26994),  INT16_C( 15903), -INT16_C(  5439),  INT16_C(  8617),
        -INT16_C( 13972),  INT16_C( 22250),  INT16_C( 12730),  INT16_C(  1675),  INT16_C( 22433),  INT16_C( 15675), -INT16_C(  2913),  INT16_C(  1251),
        -INT16_C( 18166),  INT16_C(  3579),  INT16_C( 27038), -INT16_C( 13451),  INT16_C( 11282), -INT16_C( 27111),  INT16_C( 23783), -INT16_C(  8983),
         INT16_C( 25609), -INT16_C( 28260),  INT16_C( 16334),  INT16_C( 30367),  INT16_C( 14930), -INT16_C( 15107),  INT16_C( 24828), -INT16_C( 13755),
         INT16_C( 28159),  INT16_C( 13916),  INT16_C(  6378), -INT16_C(  6757), -INT16_C(  7318),  INT16_C(   515),  INT16_C( 13449), -INT16_C(  4648) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C( 28778),  INT16_C( 18705),  INT16_C(   515), -INT16_C( 22138),
        -INT16_C(  9339),  INT16_C(   319), -INT16_C(  7176), -INT16_C( 30773),  INT16_C( 10152),  INT16_C(  3684),  INT16_C( 12506), -INT16_C(  3060),
        -INT16_C( 11404),  INT16_C(  1130), -INT16_C( 13434), -INT16_C( 29692),  INT16_C( 26997),  INT16_C( 28144),  INT16_C( 25688), -INT16_C( 13199),
         INT16_C( 10485), -INT16_C( 10931),  INT16_C(  4556), -INT16_C(  5929),  INT16_C( 13472),  INT16_C(  9326),  INT16_C(  2769), -INT16_C( 22092),
         INT16_C(  1396), -INT16_C(  2453), -INT16_C(  7839),  INT16_C(  2844),  INT16_C( 11006), -INT16_C(  5388), -INT16_C(  2058), -INT16_C(  6494),
        -INT16_C( 13844),  INT16_C( 21049),  INT16_C( 20285),  INT16_C( 10315), -INT16_C( 22848),  INT16_C(  1563),  INT16_C(  8522), -INT16_C( 27349),
        -INT16_C(  8864),  INT16_C( 29478),  INT16_C( 11127),  INT16_C( 24874), -INT16_C(  9958),  INT16_C( 31946), -INT16_C(  8198),  INT16_C( 21839),
         INT16_C( 30099),  INT16_C(   535),  INT16_C(  5394), -INT16_C( 26158), -INT16_C( 28944),  INT16_C( 21051),  INT16_C( 15247), -INT16_C( 29167),
        -INT16_C( 18814),  INT16_C( 11974),  INT16_C( 23408), -INT16_C( 30094),  INT16_C(  4854),  INT16_C( 25763), -INT16_C( 18178), -INT16_C( 19461),
        -INT16_C( 15082),  INT16_C( 23452),  INT16_C(  5607), -INT16_C( 31371), -INT16_C( 14630),  INT16_C( 22798),  INT16_C( 10903), -INT16_C(  4176),
         INT16_C( 14233), -INT16_C( 21396),  INT16_C(  5611),  INT16_C( 29028), -INT16_C( 11041),  INT16_C(  9959),  INT16_C(  4951), -INT16_C( 13041),
         INT16_C( 26469), -INT16_C(  6488),  INT16_C(  3674),  INT16_C( 32029), -INT16_C( 31357), -INT16_C( 23121),  INT16_C(   267),  INT16_C( 20828),
         INT16_C( 15186),  INT16_C(  9340), -INT16_C( 29592),  INT16_C(  1757), -INT16_C( 13929), -INT16_C( 12703),  INT16_C( 30435),  INT16_C(  4353),
        -INT16_C( 16027), -INT16_C(  7336),  INT16_C( 11688),  INT16_C( 13197),  INT16_C( 24158), -INT16_C(  2300), -INT16_C( 11056), -INT16_C( 18351),
         INT16_C( 16440), -INT16_C(  7059), -INT16_C( 24655), -INT16_C( 13080),  INT16_C(  6185), -INT16_C( 18963), -INT16_C( 11953), -INT16_C( 30997) },
      {  INT16_C(     0), -INT16_C(     1),        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     2),
               INT16_MAX,       -INT16_MAX, -INT16_C(     2),        INT16_MIN, -INT16_C(  6945),  INT16_C( 30537),  INT16_C( 12311),  INT16_C( 30952),
         INT16_C( 23002), -INT16_C( 25393), -INT16_C(  2379), -INT16_C( 20271),  INT16_C( 23756),  INT16_C(  3373), -INT16_C( 26410), -INT16_C( 29731),
        -INT16_C(  7926), -INT16_C( 13411), -INT16_C( 10827),  INT16_C( 13676),  INT16_C(  2501), -INT16_C( 19259), -INT16_C( 18241),  INT16_C( 21248),
        -INT16_C( 30292),  INT16_C(  4474), -INT16_C( 12228), -INT16_C( 31734), -INT16_C( 11351),  INT16_C( 32588),  INT16_C( 21102), -INT16_C( 27969),
         INT16_C( 32586),  INT16_C( 21173), -INT16_C(  9369), -INT16_C( 13103), -INT16_C(  6670), -INT16_C( 20993),  INT16_C( 20405), -INT16_C(   525),
        -INT16_C(  8500), -INT16_C( 10920), -INT16_C(  3164),  INT16_C( 17540),  INT16_C( 12579), -INT16_C( 32119), -INT16_C(  7767),  INT16_C( 31920),
         INT16_C(   145),  INT16_C( 18527),  INT16_C( 24132),  INT16_C(  4101),  INT16_C( 22077),  INT16_C( 14011), -INT16_C( 22421),  INT16_C( 29748),
        -INT16_C( 23809),  INT16_C( 27586),  INT16_C( 28227), -INT16_C( 28806), -INT16_C( 16590),  INT16_C(  8627), -INT16_C(  9036), -INT16_C(  6920),
        -INT16_C( 13168),  INT16_C( 30819), -INT16_C(  4795),  INT16_C(  8954),  INT16_C(  5197),  INT16_C(  3663), -INT16_C( 27119), -INT16_C( 29485),
        -INT16_C( 28577),  INT16_C(  7382), -INT16_C(  6686),  INT16_C( 21998),  INT16_C(   412), -INT16_C( 19710),  INT16_C(  3809), -INT16_C(  8899),
        -INT16_C( 29912),  INT16_C( 14845),  INT16_C( 10524),  INT16_C( 28929),  INT16_C( 15953),  INT16_C( 25862), -INT16_C(   488), -INT16_C(  4424),
         INT16_C( 12497),  INT16_C( 15762),  INT16_C( 16404), -INT16_C( 31832), -INT16_C(  8924), -INT16_C(  7446), -INT16_C(  2646),  INT16_C( 22079),
        -INT16_C(  2980),  INT16_C( 12919), -INT16_C(  2554), -INT16_C( 11694), -INT16_C(  2647),  INT16_C( 25722), -INT16_C( 11318), -INT16_C(  4630),
         INT16_C(  9582),  INT16_C( 29940),  INT16_C( 28022), -INT16_C( 21972), -INT16_C( 26448), -INT16_C( 17407),  INT16_C( 13772), -INT16_C( 32106),
        -INT16_C( 20937),  INT16_C(  6857), -INT16_C( 18277), -INT16_C( 19837), -INT16_C(  1133), -INT16_C( 18448),  INT16_C(  1496),  INT16_C( 29891) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C( 23483), -INT16_C( 15442),  INT16_C( 31963),  INT16_C( 15792),
         INT16_C( 27812),  INT16_C(  1562),  INT16_C( 20603), -INT16_C( 28001),  INT16_C( 27833),  INT16_C( 27513), -INT16_C( 27480),  INT16_C( 31307),
         INT16_C( 28534), -INT16_C( 17263),  INT16_C( 31000), -INT16_C(  7247), -INT16_C(  6889),  INT16_C( 12212), -INT16_C( 20060),  INT16_C( 16795),
         INT16_C( 14702), -INT16_C(  4074), -INT16_C(   621), -INT16_C( 27376),  INT16_C(  7458),  INT16_C( 20679),  INT16_C( 13926), -INT16_C( 13272),
         INT16_C( 31745),  INT16_C( 23643),  INT16_C( 16334),  INT16_C( 22296),  INT16_C( 10135), -INT16_C( 14288), -INT16_C( 30361),  INT16_C(  4215),
        -INT16_C( 28437), -INT16_C( 27350),  INT16_C( 22912),  INT16_C( 11108),  INT16_C( 30525),  INT16_C( 17540),  INT16_C( 12630), -INT16_C(  2241),
        -INT16_C( 21618), -INT16_C( 25261),  INT16_C( 20430), -INT16_C(  6049),  INT16_C( 23657), -INT16_C( 20445),  INT16_C( 29902), -INT16_C( 30153),
         INT16_C(  1928), -INT16_C( 13058), -INT16_C( 32255),  INT16_C( 28960),  INT16_C(  9355), -INT16_C( 10223),  INT16_C(  1769), -INT16_C( 25113),
         INT16_C( 25357), -INT16_C( 29196), -INT16_C(  4654),  INT16_C( 10269),  INT16_C( 26158), -INT16_C( 22902),  INT16_C( 13618),  INT16_C( 25615),
         INT16_C( 29815),  INT16_C( 29264), -INT16_C( 22814),  INT16_C(  4127), -INT16_C(  4092),  INT16_C( 27574),  INT16_C(  7027), -INT16_C( 31719),
        -INT16_C( 19812),  INT16_C(  8228),  INT16_C(  9924),  INT16_C( 11793), -INT16_C(  8610), -INT16_C( 14318),  INT16_C( 24293),  INT16_C(  7191),
         INT16_C(  5727), -INT16_C( 29309), -INT16_C(  9943), -INT16_C( 27630),  INT16_C( 22195), -INT16_C( 22515), -INT16_C(  4811),  INT16_C( 16593),
         INT16_C( 13051),  INT16_C(  6278),  INT16_C( 28586), -INT16_C( 20898),  INT16_C( 26267), -INT16_C( 11709),  INT16_C( 19189),  INT16_C( 27748),
         INT16_C( 15764), -INT16_C(  3409),  INT16_C( 30643),  INT16_C( 15742), -INT16_C( 28981), -INT16_C( 28938), -INT16_C( 11041),  INT16_C( 28138),
         INT16_C( 30594),  INT16_C( 25928), -INT16_C( 16889), -INT16_C( 30133),  INT16_C( 27791), -INT16_C(  7123), -INT16_C( 25734),  INT16_C( 16048) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 31803), -INT16_C( 15201),  INT16_C( 11861),  INT16_C(  7279),
         INT16_C( 19061),  INT16_C( 16550),  INT16_C( 20428), -INT16_C(  2439), -INT16_C( 20008),  INT16_C( 30310),  INT16_C( 19612),  INT16_C( 21449),
         INT16_C( 32446),  INT16_C( 31419), -INT16_C(  3673), -INT16_C( 19501),  INT16_C(  2005), -INT16_C( 23347), -INT16_C( 25219),  INT16_C(  9847),
         INT16_C( 14883), -INT16_C( 29015), -INT16_C( 15289),  INT16_C( 31025),  INT16_C(  4556),  INT16_C( 10596),  INT16_C( 20493),  INT16_C( 10368),
         INT16_C(  2777), -INT16_C( 30776),  INT16_C( 15376), -INT16_C( 11158), -INT16_C( 20965),  INT16_C( 24454),  INT16_C( 14274), -INT16_C( 31977),
        -INT16_C( 26602), -INT16_C( 18254),  INT16_C( 21166),  INT16_C( 11059), -INT16_C( 15659),  INT16_C( 27968),  INT16_C( 17072), -INT16_C( 29515),
         INT16_C( 17237), -INT16_C( 18421),  INT16_C(  5008), -INT16_C( 24428),  INT16_C(  4393),  INT16_C( 16862),  INT16_C( 32023),  INT16_C( 21950),
        -INT16_C( 24379), -INT16_C( 24133),  INT16_C( 31353), -INT16_C( 20578), -INT16_C( 15159), -INT16_C( 30804),  INT16_C(  8412), -INT16_C( 19911),
         INT16_C( 24967),  INT16_C( 13326),  INT16_C(  2227), -INT16_C(  1536),  INT16_C(  5075),  INT16_C( 18784),  INT16_C(  6232),  INT16_C( 11796),
         INT16_C(  8224),  INT16_C( 19277), -INT16_C( 22428), -INT16_C( 11811), -INT16_C( 27727), -INT16_C( 24905), -INT16_C( 24572), -INT16_C( 31884),
        -INT16_C( 27222),  INT16_C(  9021),  INT16_C( 21362), -INT16_C(  5512), -INT16_C( 21379), -INT16_C(  4932),  INT16_C( 23183), -INT16_C(   614),
        -INT16_C( 22201), -INT16_C(  1266),  INT16_C(  1434), -INT16_C( 10965), -INT16_C( 19617),  INT16_C( 17214),  INT16_C( 28350),  INT16_C( 22217),
        -INT16_C(  1711), -INT16_C( 28870),  INT16_C( 27156), -INT16_C( 23257),  INT16_C( 12141),  INT16_C( 21750),  INT16_C( 13758), -INT16_C( 30517),
         INT16_C( 14275), -INT16_C(  9009), -INT16_C(  9635),  INT16_C( 19342), -INT16_C( 17276),  INT16_C( 28888), -INT16_C(  7608),  INT16_C(  6771),
        -INT16_C(  2204), -INT16_C( 13655),  INT16_C(  7067),  INT16_C( 11088),  INT16_C(  6821),  INT16_C( 11028), -INT16_C( 18139),  INT16_C( 23226) },
      {  INT16_C(     0), -INT16_C(     1),        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     2),
               INT16_MAX,       -INT16_MAX, -INT16_C(     2),        INT16_MIN,  INT16_C(  8320), -INT16_C( 30643), -INT16_C( 21712),  INT16_C( 23071),
        -INT16_C( 18663),  INT16_C( 18112), -INT16_C( 24505), -INT16_C( 30440),  INT16_C(  7825), -INT16_C(  7713), -INT16_C(  7868), -INT16_C( 12780),
        -INT16_C(  4556),  INT16_C( 14156),  INT16_C( 27327), -INT16_C( 26748), -INT16_C(  4884), -INT16_C( 11135),  INT16_C( 20257),  INT16_C( 26642),
         INT16_C( 29585),  INT16_C( 32447), -INT16_C( 15910),  INT16_C(  3649),  INT16_C( 12014),  INT16_C( 31275), -INT16_C( 31117), -INT16_C(  2904),
        -INT16_C( 31014), -INT16_C(  7133),  INT16_C( 31710),  INT16_C( 11138), -INT16_C( 10830),  INT16_C( 10166), -INT16_C( 16087), -INT16_C( 27762),
         INT16_C( 10497),  INT16_C( 19932), -INT16_C( 21458),  INT16_C( 22167),  INT16_C( 14866), -INT16_C( 20028),  INT16_C( 29702), -INT16_C( 31756),
        -INT16_C(  4381),  INT16_C( 21854),  INT16_C( 25438), -INT16_C( 30477),  INT16_C( 28050), -INT16_C(  3583), -INT16_C(  3611), -INT16_C(  8203),
        -INT16_C( 22451),  INT16_C( 28345), -INT16_C(   902),  INT16_C(  8382), -INT16_C(  5804),  INT16_C( 24509),  INT16_C( 10181),  INT16_C( 20512),
        -INT16_C( 15212), -INT16_C( 15870), -INT16_C(  2427),  INT16_C(  8733),  INT16_C( 31233), -INT16_C(  4118),  INT16_C( 19850), -INT16_C( 28125),
        -INT16_C( 27497), -INT16_C( 16995),  INT16_C( 20294), -INT16_C(  7684), -INT16_C( 31819),  INT16_C(  2669), -INT16_C( 17545),  INT16_C(  1933),
         INT16_C( 18502),  INT16_C( 17249),  INT16_C( 31286),  INT16_C(  6281), -INT16_C( 29989), -INT16_C( 19250), -INT16_C( 18060),  INT16_C(  6577),
        -INT16_C( 16474), -INT16_C( 30575), -INT16_C(  8509),  INT16_C( 26941),  INT16_C(  2578), -INT16_C(  5301),  INT16_C( 23539), -INT16_C( 26726),
         INT16_C( 11340), -INT16_C( 22592), -INT16_C(  9794),  INT16_C( 21381), -INT16_C( 27128),  INT16_C( 10041), -INT16_C( 32589), -INT16_C(  2769),
         INT16_C( 30039), -INT16_C( 12418),  INT16_C( 21008), -INT16_C( 30452),  INT16_C( 19279), -INT16_C(    50), -INT16_C( 18649), -INT16_C( 30627),
         INT16_C( 28390),  INT16_C( 12273), -INT16_C(  9822), -INT16_C( 19045), -INT16_C( 30924),  INT16_C(  3905),  INT16_C( 21663), -INT16_C( 26262) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vadd_WhWh(a, b);

    simde_test_hvx_vectorpair_i16_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i16_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i16_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vadd_WhWh(a, b);

    simde_test_hvx_vectorpair_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_WwWw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_PAIR_I32_COUNT];
    int32_t b[SIMDE_HVX_PAIR_I32_COUNT];
    int32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(   685572173),  INT32_C(  1605267160),  INT32_C(  1069948977),  INT32_C(   407889401),
         INT32_C(   285748980), -INT32_C(   798356917),  INT32_C(  1570515389), -INT32_C(   239911593), -INT32_C(   868009671),  INT32_C(   347038407),  INT32_C(   278666949), -INT32_C(  2018931304),
        -INT32_C(  2006027126), -INT32_C(  1941625049),  INT32_C(   465742433),  INT32_C(   912393574), -INT32_C(  2072265426),  INT32_C(  1153780568),  INT32_C(  2126405456), -INT32_C(  1377283358),
        -INT32_C(  1199022689), -INT32_C(   449562668), -INT32_C(   526673087),  INT32_C(  1488454899),  INT32_C(  1390236068), -INT32_C(   361640531), -INT32_C(  2046587239), -INT32_C(  1259895306),
        -INT32_C(  1956023390), -INT32_C(  2047565375),  INT32_C(  1639967541),  INT32_C(   659424080),  INT32_C(  1327238834), -INT32_C(  1202845303), -INT32_C(  1243628115), -INT32_C(  1068239272),
         INT32_C(  1119508463),  INT32_C(   688481281), -INT32_C(   787749739),  INT32_C(  2007930919), -INT32_C(  1885910141),  INT32_C(   692663608),  INT32_C(  1720824887),  INT32_C(  1623912892),
         INT32_C(   482767355),  INT32_C(  1925019379), -INT32_C(   426820014),  INT32_C(  1362223111), -INT32_C(  2044000182),  INT32_C(   442809335), -INT32_C(  1982350252), -INT32_C(  2088979892) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(   315249668), -INT32_C(  1402761679), -INT32_C(   670440822),  INT32_C(   391096842),
         INT32_C(   924154782),  INT32_C(   885968866), -INT32_C(   190194444), -INT32_C(  1113963848), -INT32_C(   499387328),  INT32_C(    90806388), -INT32_C(  1627704397), -INT32_C(   902531497),
         INT32_C(   836441154),  INT32_C(   386345000),  INT32_C(  1130345116),  INT32_C(   922389862),  INT32_C(   632196978), -INT32_C(   238212188),  INT32_C(   342299320), -INT32_C(   375936485),
        -INT32_C(  1400980659),  INT32_C(    95114318), -INT32_C(   934266007),  INT32_C(  2096468631),  INT32_C(  1997092857),  INT32_C(  1068153656), -INT32_C(   147608044), -INT32_C(    96010634),
         INT32_C(   911832179),  INT32_C(  1250523187), -INT32_C(  2074373183),  INT32_C(   135523900), -INT32_C(  1610306424),  INT32_C(   203756158), -INT32_C(  1437207489),  INT32_C(   333218598),
        -INT32_C(   774327292), -INT32_C(   634443632),  INT32_C(   236883780), -INT32_C(   356064557), -INT32_C(  2122366306), -INT32_C(   592254586),  INT32_C(  2030887175),  INT32_C(  1339660624),
        -INT32_C(  1853748439),  INT32_C(   719767462), -INT32_C(  1746876448),  INT32_C(    55054075),  INT32_C(  1833586811),  INT32_C(   617611402),  INT32_C(  1535593315), -INT32_C(  1085772086) },
      {  INT32_C(           0), -INT32_C(           1),              INT32_MAX,              INT32_MIN,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           2),
                     INT32_MAX, -INT32_C(  2147483647), -INT32_C(           2),              INT32_MIN,  INT32_C(  1000821841),  INT32_C(   202505481),  INT32_C(   399508155),  INT32_C(   798986243),
         INT32_C(  1209903762),  INT32_C(    87611949),  INT32_C(  1380320945), -INT32_C(  1353875441), -INT32_C(  1367396999),  INT32_C(   437844795), -INT32_C(  1349037448),  INT32_C(  1373504495),
        -INT32_C(  1169585972), -INT32_C(  1555280049),  INT32_C(  1596087549),  INT32_C(  1834783436), -INT32_C(  1440068448),  INT32_C(   915568380), -INT32_C(  1826262520), -INT32_C(  1753219843),
         INT32_C(  1694963948), -INT32_C(   354448350), -INT32_C(  1460939094), -INT32_C(   710043766), -INT32_C(   907638371),  INT32_C(   706513125),  INT32_C(  2100772013), -INT32_C(  1355905940),
        -INT32_C(  1044191211), -INT32_C(   797042188), -INT32_C(   434405642),  INT32_C(   794947980), -INT32_C(   283067590), -INT32_C(   999089145),  INT32_C(  1614131692), -INT32_C(   735020674),
         INT32_C(   345181171),  INT32_C(    54037649), -INT32_C(   550865959),  INT32_C(  1651866362),  INT32_C(   286690849),  INT32_C(   100409022), -INT32_C(   543255234), -INT32_C(  1331393780),
        -INT32_C(  1370981084), -INT32_C(  1650180455),  INT32_C(  2121270834),  INT32_C(  1417277186), -INT32_C(   210413371),  INT32_C(  1060420737), -INT32_C(   446756937),  INT32_C(  1120215318) } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(   516540508), -INT32_C(  1091023849), -INT32_C(  1562223071), -INT32_C(  2105513340),
         INT32_C(   596829633), -INT32_C(  1639024850),  INT32_C(  1570964046), -INT32_C(  2131884672), -INT32_C(   536770838), -INT32_C(   118151049),  INT32_C(   705170655),  INT32_C(  1419590992),
         INT32_C(  1062848537), -INT32_C(   255393072),  INT32_C(  1045348384),  INT32_C(   756107901),  INT32_C(   512856155),  INT32_C(   594102225),  INT32_C(   291197976), -INT32_C(  1081303923),
         INT32_C(  1939314664),  INT32_C(  1638845185), -INT32_C(  2095279209),  INT32_C(  1834944018), -INT32_C(  1894156549), -INT32_C(  1597918292), -INT32_C(  1785878344),  INT32_C(  1657890846),
        -INT32_C(  1296789788), -INT32_C(  1633455154),  INT32_C(   939034984),  INT32_C(   521169293),  INT32_C(  1880710619), -INT32_C(  1133405019), -INT32_C(  1327787165),  INT32_C(   112242618),
         INT32_C(  2040313109), -INT32_C(  1795300262),  INT32_C(   369081913),  INT32_C(  1396449284),  INT32_C(   699357582), -INT32_C(  1137509041),  INT32_C(  1581057736),  INT32_C(   290368186),
         INT32_C(  1976665623),  INT32_C(  1187491460), -INT32_C(  1972278599), -INT32_C(  2135159071), -INT32_C(  1335634142),  INT32_C(  1975693727),  INT32_C(  1595416954),  INT32_C(  1984968027) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX, -INT32_C(  1598633265),  INT32_C(   407897805),  INT32_C(   897255446),  INT32_C(   416155163),
         INT32_C(  1411486173),  INT32_C(  1773912882),  INT32_C(  1636160393), -INT32_C(  1874359070),  INT32_C(  1019582996), -INT32_C(  1634355182),  INT32_C(   906635048), -INT32_C(  1817473358),
        -INT32_C(  1608170550), -INT32_C(  1632451553), -INT32_C(  1012853145),  INT32_C(   471600473),  INT32_C(  1357903618), -INT32_C(  1254910694), -INT32_C(   486625783),  INT32_C(  1198301668),
         INT32_C(  1739468135), -INT32_C(  1396312088), -INT32_C(  1288637695), -INT32_C(   683082354), -INT32_C(   344600576),  INT32_C(   397276483), -INT32_C(  1181543718), -INT32_C(  1341782762),
        -INT32_C(  1024489432),  INT32_C(  1596340619),  INT32_C(   165881627), -INT32_C(   965615894),  INT32_C(  2053140798), -INT32_C(    75156685),  INT32_C(   218839848),  INT32_C(   136940217),
         INT32_C(  1813491347),  INT32_C(  1605732945),  INT32_C(  1645729827), -INT32_C(  1206417190), -INT32_C(  1345688542),  INT32_C(   729369540),  INT32_C(  1222364742), -INT32_C(  1067450856),
         INT32_C(  1717683058), -INT32_C(       39044),  INT32_C(   684039238),  INT32_C(  2037637463), -INT32_C(   491715769), -INT32_C(  1740378012), -INT32_C(  1319241437),  INT32_C(  1856482714) },
      {  INT32_C(           0), -INT32_C(           1),              INT32_MAX,              INT32_MIN,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           2),
                     INT32_MAX, -INT32_C(  2147483647), -INT32_C(           2),              INT32_MIN, -INT32_C(  2115173773), -INT32_C(   683126044), -INT32_C(   664967625), -INT32_C(  1689358177),
         INT32_C(  2008315806),  INT32_C(   134888032), -INT32_C(  1087842857),  INT32_C(   288723554),  INT32_C(   482812158), -INT32_C(  1752506231),  INT32_C(  1611805703), -INT32_C(   397882366),
        -INT32_C(   545322013), -INT32_C(  1887844625),  INT32_C(    32495239),  INT32_C(  1227708374),  INT32_C(  1870759773), -INT32_C(   660808469), -INT32_C(   195427807),  INT32_C(   116997745),
        -INT32_C(   616184497),  INT32_C(   242533097),  INT32_C(   911050392),  INT32_C(  1151861664),  INT32_C(  2056210171), -INT32_C(  1200641809),  INT32_C(  1327545234),  INT32_C(   316108084),
         INT32_C(  1973688076), -INT32_C(    37114535),  INT32_C(  1104916611), -INT32_C(   444446601), -INT32_C(   361115879), -INT32_C(  1208561704), -INT32_C(  1108947317),  INT32_C(   249182835),
        -INT32_C(   441162840), -INT32_C(   189567317),  INT32_C(  2014811740),  INT32_C(   190032094), -INT32_C(   646330960), -INT32_C(   408139501), -INT32_C(  1491544818), -INT32_C(   777082670),
        -INT32_C(   600618615),  INT32_C(  1187452416), -INT32_C(  1288239361), -INT32_C(    97521608), -INT32_C(  1827349911),  INT32_C(   235315715),  INT32_C(   276175517), -INT32_C(   453516555) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vadd_WwWw(a, b);

    simde_test_hvx_vectorpair_i32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i32_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i32_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vadd_WwWw(a, b);

    simde_test_hvx_vectorpair_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_WbWb_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[SIMDE_HVX_PAIR_SIZE];
    int8_t b[SIMDE_HVX_PAIR_SIZE];
    int8_t r[SIMDE_HVX_PAIR_SIZE];
  } test_vec[] = {
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1), -INT8_C(  24),  INT8_C(  25), -INT8_C(  42), -INT8_C( 120),
        -INT8_C(  14),  INT8_C(  22),  INT8_C(  70), -INT8_C(   9),  INT8_C(   4),  INT8_C(  44), -INT8_C(  38),  INT8_C( 109),
        -INT8_C(  96), -INT8_C(  70), -INT8_C(   6), -INT8_C(  82), -INT8_C( 117),  INT8_C(  90), -INT8_C( 103),  INT8_C(  66),
        -INT8_C(  34), -INT8_C(  53),  INT8_C(  91), -INT8_C(   5),  INT8_C(  41), -INT8_C(  63), -INT8_C(  48),  INT8_C(  63),
         INT8_C(  97), -INT8_C(  67), -INT8_C( 101),  INT8_C(  30),  INT8_C(  48),  INT8_C( 102), -INT8_C( 122),  INT8_C(  67),
         INT8_C(   5), -INT8_C( 117), -INT8_C(  68), -INT8_C(  69),  INT8_C( 121),  INT8_C( 118),  INT8_C(  46), -INT8_C(  96),
         INT8_C( 104), -INT8_C(  80), -INT8_C(  32), -INT8_C( 122),  INT8_C(  99), -INT8_C(  68),  INT8_C(   2), -INT8_C(   7),
         INT8_C(  81),  INT8_C(   5),  INT8_C(  68), -INT8_C(  84), -INT8_C(  47), -INT8_C(  41), -INT8_C(  57),  INT8_C(  79),
         INT8_C(  69), -INT8_C(  25),  INT8_C(  38),  INT8_C(  45), -INT8_C(  18),  INT8_C(  59),  INT8_C(  30), -INT8_C(  94),
         INT8_C( 124),  INT8_C(  58), -INT8_C( 106), -INT8_C(  51),  INT8_C( 101),  INT8_C(  81),  INT8_C( 103),  INT8_C(   5),
         INT8_C(  72),  INT8_C(  97),  INT8_C(  41), -INT8_C(  94), -INT8_C( 115),  INT8_C( 116),  INT8_C(   4),  INT8_C(  81),
        -INT8_C(  16), -INT8_C( 109),  INT8_C(  93), -INT8_C(  95), -INT8_C(  13), -INT8_C(  36), -INT8_C(  42),  INT8_C(   7),
        -INT8_C(  52),  INT8_C(  89),  INT8_C(  80), -INT8_C(  21), -INT8_C( 119),  INT8_C(   9),  INT8_C( 112),  INT8_C( 101),
         INT8_C(  95),  INT8_C(  90),  INT8_C( 116), -INT8_C(   1), -INT8_C(  98),  INT8_C( 103), -INT8_C(  89), -INT8_C(  27),
         INT8_C(   3),  INT8_C(   9), -INT8_C( 110),  INT8_C(  86), -INT8_C(  84), -INT8_C( 114), -INT8_C(  73), -INT8_C(   8),
        -INT8_C(  97),  INT8_C(  26),  INT8_C( 125),  INT8_C(  65), -INT8_C(  34), -INT8_C( 111),  INT8_C(  90), -INT8_C(   9),
        -INT8_C(  66),  INT8_C(  11), -INT8_C(  99),  INT8_C(  93),  INT8_C(  20),  INT8_C( 117), -INT8_C(  33), -INT8_C(  57),
         INT8_C(  61),  INT8_C( 104),  INT8_C( 103),  INT8_C(  56),  INT8_C(  21),  INT8_C(  33),  INT8_C(  71),  INT8_C(  11),
        -INT8_C(  82), -INT8_C(  30), -INT8_C(  94),  INT8_C(  30),  INT8_C( 102),  INT8_C( 121),  INT8_C(  67),  INT8_C(   6),
         INT8_C(  85), -INT8_C( 115),  INT8_C(  97), -INT8_C( 117),  INT8_C(  63), -INT8_C(  49), -INT8_C(  40), -INT8_C(  52),
        -INT8_C(  82),  INT8_C(  42),  INT8_C(  72), -INT8_C(  23), -INT8_C(  40),  INT8_C(  22),  INT8_C(  66), -INT8_C(  75),
         INT8_C(  32), -INT8_C( 105), -INT8_C(  68), -INT8_C(  40),  INT8_C(  62), -INT8_C(  60), -INT8_C( 107),  INT8_C(  92),
             INT8_MIN, -INT8_C(  17),  INT8_C(  96),  INT8_C( 102), -INT8_C(  89), -INT8_C( 125), -INT8_C( 125), -INT8_C(  25),
        -INT8_C(  51),  INT8_C(  85),  INT8_C(  59),  INT8_C(  57),  INT8_C(  73),  INT8_C( 108),  INT8_C( 121), -INT8_C(  90),
        -INT8_C( 112), -INT8_C(  92), -INT8_C(  81), -INT8_C(  48),  INT8_C(  89), -INT8_C(  81),  INT8_C(  64),  INT8_C( 125),
         INT8_C(   5), -INT8_C(  75),  INT8_C(  77), -INT8_C( 103), -INT8_C(  12),  INT8_C(  11),  INT8_C(  22), -INT8_C(  25),
         INT8_C(  47),  INT8_C(  74),  INT8_C( 125), -INT8_C(  57),  INT8_C( 108), -INT8_C(  48),  INT8_C(  35), -INT8_C(  41),
        -INT8_C(  61),  INT8_C(   4), -INT8_C(  64),  INT8_C(  97),  INT8_C(  91), -INT8_C( 110),  INT8_C(  10), -INT8_C(  22),
        -INT8_C(  47),  INT8_C(  49),  INT8_C(  67),  INT8_C(  54), -INT8_C(  37), -INT8_C(  23),  INT8_C(  49),  INT8_C(   1),
        -INT8_C(  44), -INT8_C( 100),  INT8_C(  80), -INT8_C(   9), -INT8_C(  27),  INT8_C(  67),  INT8_C(  64),  INT8_C( 123),
        -INT8_C(  59), -INT8_C(  21),  INT8_C(   8), -INT8_C(  47),  INT8_C(   5), -INT8_C(  34),  INT8_C(  63), -INT8_C(  50) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C( 109), -INT8_C( 113),  INT8_C( 125),  INT8_C( 110),
        -INT8_C(  43),  INT8_C(  25), -INT8_C(  93),  INT8_C(  12),  INT8_C( 115), -INT8_C(  24), -INT8_C(  63), -INT8_C(  75),
        -INT8_C(  10), -INT8_C(   9), -INT8_C( 104),  INT8_C(  71), -INT8_C(  32),  INT8_C( 117), -INT8_C( 125), -INT8_C(   9),
        -INT8_C(  37), -INT8_C( 127),  INT8_C(  14), -INT8_C( 100),  INT8_C(  96),  INT8_C(  96), -INT8_C(  22),  INT8_C(   6),
        -INT8_C( 121),  INT8_C(  22),  INT8_C(  53),  INT8_C(  14),  INT8_C( 111),  INT8_C(  73),  INT8_C( 122),  INT8_C( 106),
        -INT8_C(  88),  INT8_C(  89), -INT8_C(  97), -INT8_C(   5),  INT8_C(  31), -INT8_C(  70),  INT8_C(  53), -INT8_C( 104),
        -INT8_C(   7), -INT8_C( 120), -INT8_C(   5), -INT8_C(  23), -INT8_C(  48),  INT8_C(  43), -INT8_C(  57), -INT8_C(  93),
         INT8_C(  91),  INT8_C(  37),  INT8_C(  93),  INT8_C( 106), -INT8_C(  50),  INT8_C(  52),  INT8_C(   2),  INT8_C( 106),
        -INT8_C(   1),  INT8_C(  54),  INT8_C(  63),  INT8_C(  77), -INT8_C( 105), -INT8_C(  40), -INT8_C(  53), -INT8_C(  53),
        -INT8_C(  65), -INT8_C(  46),  INT8_C( 100), -INT8_C(  54),  INT8_C( 112),  INT8_C(  93),  INT8_C( 106), -INT8_C(  97),
        -INT8_C(  36), -INT8_C(   7),  INT8_C( 108), -INT8_C(  79), -INT8_C(  48),  INT8_C(  90),  INT8_C(  48), -INT8_C(  72),
         INT8_C(   7),  INT8_C(  43), -INT8_C(   2), -INT8_C(  20),  INT8_C(  10),  INT8_C(  25),  INT8_C(  31),  INT8_C( 113),
        -INT8_C( 120), -INT8_C( 116),  INT8_C(  45),  INT8_C(  43),  INT8_C( 120), -INT8_C(  51),  INT8_C(  65), -INT8_C(  57),
         INT8_C(  77), -INT8_C(  79), -INT8_C(  84), -INT8_C(  51),  INT8_C(  87),  INT8_C( 116),  INT8_C(  32),  INT8_C(  78),
         INT8_C(  95), -INT8_C(  80),  INT8_C(  58), -INT8_C( 103),  INT8_C(  80), -INT8_C( 100), -INT8_C(  47), -INT8_C(  86),
         INT8_C(  74),  INT8_C(  92), -INT8_C(  99),  INT8_C(  24), -INT8_C( 100), -INT8_C(  76), -INT8_C(  73), -INT8_C(  76),
        -INT8_C(  61), -INT8_C(  22),  INT8_C(  84), -INT8_C(  27), -INT8_C( 114), -INT8_C(  53),  INT8_C(  54), -INT8_C(  86),
        -INT8_C(  56), -INT8_C(  62),  INT8_C(  20), -INT8_C( 122),  INT8_C(  26),  INT8_C(  57),  INT8_C(  69),  INT8_C(  68),
         INT8_C(  72),  INT8_C( 109), -INT8_C(   7), -INT8_C(  34), -INT8_C(  11), -INT8_C(  56), -INT8_C(  58), -INT8_C(  24),
         INT8_C(  91),  INT8_C(  35),  INT8_C(  63), -INT8_C( 110), -INT8_C(  95), -INT8_C( 100),  INT8_C(  95), -INT8_C( 126),
        -INT8_C(  47), -INT8_C(  83),  INT8_C(  54),  INT8_C(  40), -INT8_C(  66),  INT8_C(  59),  INT8_C( 112),  INT8_C(   6),
        -INT8_C(  44), -INT8_C(  36), -INT8_C(  15),  INT8_C(   4), -INT8_C(  71), -INT8_C( 102), -INT8_C(  76), -INT8_C(  43),
         INT8_C(  58),  INT8_C(  16),  INT8_C(  52), -INT8_C(  63), -INT8_C(  25),  INT8_C( 105), -INT8_C(  42), -INT8_C(  45),
        -INT8_C(  16), -INT8_C(  65), -INT8_C(  39), -INT8_C(  47), -INT8_C(  13),  INT8_C(  61),  INT8_C(  73),  INT8_C(  52),
        -INT8_C(  18),  INT8_C(  75), -INT8_C(  16), -INT8_C( 101),  INT8_C(  97), -INT8_C( 117),      INT8_MAX,  INT8_C( 103),
        -INT8_C(  58), -INT8_C(  50), -INT8_C( 101), -INT8_C(  50), -INT8_C(  46), -INT8_C(  44),  INT8_C( 120),  INT8_C(  19),
         INT8_C(  14), -INT8_C(  27), -INT8_C( 101), -INT8_C(  50), -INT8_C( 109), -INT8_C(  67), -INT8_C( 112),  INT8_C(  50),
         INT8_C( 118), -INT8_C(  25),  INT8_C(  92), -INT8_C(  63), -INT8_C(  46),  INT8_C(  44),  INT8_C(  70), -INT8_C(   3),
        -INT8_C( 123),  INT8_C(  92),  INT8_C(  46), -INT8_C(  33), -INT8_C(  54), -INT8_C(  25), -INT8_C( 103), -INT8_C( 121),
        -INT8_C( 111), -INT8_C(  57),  INT8_C(  60),  INT8_C(  63),  INT8_C(  15), -INT8_C( 114), -INT8_C( 123),  INT8_C( 104),
        -INT8_C(  88),  INT8_C( 114), -INT8_C(  83), -INT8_C( 101), -INT8_C(  11),  INT8_C(  47), -INT8_C(  20),  INT8_C(  30) },
      {      INT8_MIN, -INT8_C(   1),      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(   2),
             INT8_MIN, -INT8_C( 127),      INT8_MAX,      INT8_MAX,  INT8_C(  85), -INT8_C(  88),  INT8_C(  83), -INT8_C(  10),
        -INT8_C(  57),  INT8_C(  47), -INT8_C(  23),  INT8_C(   3),  INT8_C( 119),  INT8_C(  20), -INT8_C( 101),  INT8_C(  34),
        -INT8_C( 106), -INT8_C(  79), -INT8_C( 110), -INT8_C(  11),      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(  57),
        -INT8_C(  71),      INT8_MIN,  INT8_C( 105), -INT8_C( 105),      INT8_MAX,  INT8_C(  33), -INT8_C(  70),  INT8_C(  69),
        -INT8_C(  24), -INT8_C(  45), -INT8_C(  48),  INT8_C(  44),      INT8_MAX,      INT8_MAX,  INT8_C(   0),      INT8_MAX,
        -INT8_C(  83), -INT8_C(  28),      INT8_MIN, -INT8_C(  74),      INT8_MAX,  INT8_C(  48),  INT8_C(  99),      INT8_MIN,
         INT8_C(  97),      INT8_MIN, -INT8_C(  37),      INT8_MIN,  INT8_C(  51), -INT8_C(  25), -INT8_C(  55), -INT8_C( 100),
             INT8_MAX,  INT8_C(  42),      INT8_MAX,  INT8_C(  22), -INT8_C(  97),  INT8_C(  11), -INT8_C(  55),      INT8_MAX,
         INT8_C(  68),  INT8_C(  29),  INT8_C( 101),  INT8_C( 122), -INT8_C( 123),  INT8_C(  19), -INT8_C(  23),      INT8_MIN,
         INT8_C(  59),  INT8_C(  12), -INT8_C(   6), -INT8_C( 105),      INT8_MAX,      INT8_MAX,      INT8_MAX, -INT8_C(  92),
         INT8_C(  36),  INT8_C(  90),      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,  INT8_C(  52),  INT8_C(   9),
        -INT8_C(   9), -INT8_C(  66),  INT8_C(  91), -INT8_C( 115), -INT8_C(   3), -INT8_C(  11), -INT8_C(  11),  INT8_C( 120),
             INT8_MIN, -INT8_C(  27),  INT8_C( 125),  INT8_C(  22),  INT8_C(   1), -INT8_C(  42),      INT8_MAX,  INT8_C(  44),
             INT8_MAX,  INT8_C(  11),  INT8_C(  32), -INT8_C(  52), -INT8_C(  11),      INT8_MAX, -INT8_C(  57),  INT8_C(  51),
         INT8_C(  98), -INT8_C(  71), -INT8_C(  52), -INT8_C(  17), -INT8_C(   4),      INT8_MIN, -INT8_C( 120), -INT8_C(  94),
        -INT8_C(  23),  INT8_C( 118),  INT8_C(  26),  INT8_C(  89),      INT8_MIN,      INT8_MIN,  INT8_C(  17), -INT8_C(  85),
        -INT8_C( 127), -INT8_C(  11), -INT8_C(  15),  INT8_C(  66), -INT8_C(  94),  INT8_C(  64),  INT8_C(  21),      INT8_MIN,
         INT8_C(   5),  INT8_C(  42),  INT8_C( 123), -INT8_C(  66),  INT8_C(  47),  INT8_C(  90),      INT8_MAX,  INT8_C(  79),
        -INT8_C(  10),  INT8_C(  79), -INT8_C( 101), -INT8_C(   4),  INT8_C(  91),  INT8_C(  65),  INT8_C(   9), -INT8_C(  18),
             INT8_MAX, -INT8_C(  80),      INT8_MAX,      INT8_MIN, -INT8_C(  32),      INT8_MIN,  INT8_C(  55),      INT8_MIN,
             INT8_MIN, -INT8_C(  41),  INT8_C( 126),  INT8_C(  17), -INT8_C( 106),  INT8_C(  81),      INT8_MAX, -INT8_C(  69),
        -INT8_C(  12),      INT8_MIN, -INT8_C(  83), -INT8_C(  36), -INT8_C(   9),      INT8_MIN,      INT8_MIN,  INT8_C(  49),
        -INT8_C(  70), -INT8_C(   1),      INT8_MAX,  INT8_C(  39), -INT8_C( 114), -INT8_C(  20),      INT8_MIN, -INT8_C(  70),
        -INT8_C(  67),  INT8_C(  20),  INT8_C(  20),  INT8_C(  10),  INT8_C(  60),      INT8_MAX,      INT8_MAX, -INT8_C(  38),
             INT8_MIN, -INT8_C(  17), -INT8_C(  97),      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,
        -INT8_C(  53), -INT8_C( 125), -INT8_C(  24),      INT8_MIN, -INT8_C(  58), -INT8_C(  33),      INT8_MAX, -INT8_C(   6),
         INT8_C(  61),  INT8_C(  47),  INT8_C(  24), -INT8_C( 107), -INT8_C(   1), -INT8_C( 115), -INT8_C(  77),  INT8_C(   9),
         INT8_C(  57), -INT8_C(  21),  INT8_C(  28),  INT8_C(  34),  INT8_C(  45), -INT8_C(  66),  INT8_C(  80), -INT8_C(  25),
             INT8_MIN,      INT8_MAX,  INT8_C( 113),  INT8_C(  21), -INT8_C(  91), -INT8_C(  48), -INT8_C(  54), -INT8_C( 120),
             INT8_MIN,      INT8_MIN,      INT8_MAX,  INT8_C(  54), -INT8_C(  12), -INT8_C(  47), -INT8_C(  59),      INT8_MAX,
             INT8_MIN,  INT8_C(  93), -INT8_C(  75),      INT8_MIN, -INT8_C(   6),  INT8_C(  13),  INT8_C(  43), -INT8_C(  20) } },
    { {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),  INT8_C(  79),  INT8_C( 117), -INT8_C(   1),  INT8_C(   2),
         INT8_C(  67),  INT8_C(  66),  INT8_C(  36),  INT8_C( 109),  INT8_C(   6),  INT8_C( 115), -INT8_C(   4), -INT8_C(  86),
         INT8_C(  80), -INT8_C(  65), -INT8_C(  16),  INT8_C(  11),  INT8_C(  92),  INT8_C(  80),  INT8_C( 103),  INT8_C( 126),
         INT8_C(  95), -INT8_C(  77), -INT8_C(  99),  INT8_C(   2), -INT8_C( 108), -INT8_C(  50),  INT8_C(  62),  INT8_C( 107),
        -INT8_C(  52), -INT8_C(  94), -INT8_C(  80), -INT8_C(  56), -INT8_C(  52),  INT8_C(  18), -INT8_C(  43), -INT8_C( 125),
        -INT8_C(   6),  INT8_C( 114), -INT8_C( 112), -INT8_C( 118), -INT8_C(  92),  INT8_C(  77), -INT8_C(  23), -INT8_C(  90),
        -INT8_C( 120),  INT8_C(  34), -INT8_C( 104),  INT8_C(  22), -INT8_C(  76),  INT8_C(  84), -INT8_C(  89), -INT8_C(  11),
         INT8_C(  28),  INT8_C(  53), -INT8_C(  82),  INT8_C(  48), -INT8_C(  54), -INT8_C(  67), -INT8_C(  32),  INT8_C(  52),
         INT8_C(  21),  INT8_C(  23),  INT8_C( 106), -INT8_C(  85), -INT8_C(  82), -INT8_C( 121), -INT8_C( 121),      INT8_MIN,
         INT8_C(  89),  INT8_C(  44),  INT8_C(   0), -INT8_C(  55),  INT8_C(  20), -INT8_C(  93),      INT8_MAX,  INT8_C(  60),
         INT8_C(  96), -INT8_C( 117), -INT8_C(  70),  INT8_C(   4),  INT8_C(  76),  INT8_C(  12), -INT8_C( 108),  INT8_C(  85),
         INT8_C( 105), -INT8_C(  37), -INT8_C(  24), -INT8_C( 112),  INT8_C(   4), -INT8_C(  87),  INT8_C(  93), -INT8_C( 126),
        -INT8_C(  73),  INT8_C(  20), -INT8_C(  16),  INT8_C(  93),  INT8_C( 119),  INT8_C(  77), -INT8_C(  93),  INT8_C( 102),
        -INT8_C( 123),  INT8_C(  82),  INT8_C(   4), -INT8_C(  67),  INT8_C(  36), -INT8_C(  50), -INT8_C(  38), -INT8_C(  20),
         INT8_C(  84),  INT8_C(  77), -INT8_C(   7),  INT8_C(  57),  INT8_C(  28),  INT8_C(  98), -INT8_C(   4), -INT8_C( 110),
        -INT8_C(   3),  INT8_C(  78), -INT8_C( 120),  INT8_C( 102), -INT8_C(  65), -INT8_C(  38),  INT8_C(   5), -INT8_C(  73),
        -INT8_C(  25),  INT8_C(   1),  INT8_C(  38),  INT8_C(  13), -INT8_C(  58), -INT8_C(  67),  INT8_C(  60),  INT8_C(  78),
        -INT8_C( 108), -INT8_C(  64), -INT8_C( 121),  INT8_C(  66),  INT8_C(  45), -INT8_C( 101),  INT8_C(  63), -INT8_C(  21),
        -INT8_C( 100),  INT8_C( 107), -INT8_C(  73),  INT8_C( 113), -INT8_C( 116),  INT8_C(  84), -INT8_C(  81),  INT8_C(  57),
         INT8_C(  15),  INT8_C(  53), -INT8_C(  97), -INT8_C(  69),  INT8_C(  72),  INT8_C( 103),  INT8_C(  63),      INT8_MIN,
         INT8_C(  24),  INT8_C(  45), -INT8_C( 104),  INT8_C( 117), -INT8_C(  32), -INT8_C(  42), -INT8_C(  56),  INT8_C(  50),
        -INT8_C( 117), -INT8_C(  79), -INT8_C(  92), -INT8_C(  38),  INT8_C( 121),  INT8_C(  98), -INT8_C(  42), -INT8_C(  72),
         INT8_C(   6),  INT8_C(  96), -INT8_C(  60), -INT8_C( 124), -INT8_C(  67),  INT8_C( 108),  INT8_C(  30),  INT8_C(  92),
         INT8_C(  14),  INT8_C(  95), -INT8_C(  91), -INT8_C( 124), -INT8_C(  29),  INT8_C(  15),  INT8_C(   8),  INT8_C(  49),
        -INT8_C( 116),  INT8_C(  84), -INT8_C(  29),  INT8_C(  95), -INT8_C(  76),  INT8_C( 113),  INT8_C( 125), -INT8_C( 100),
        -INT8_C(  46), -INT8_C(  76), -INT8_C(  14), -INT8_C( 108),  INT8_C(  46), -INT8_C(  96), -INT8_C(  17),  INT8_C(  44),
         INT8_C(  78),  INT8_C( 111), -INT8_C( 118), -INT8_C(  82),  INT8_C(  80), -INT8_C(  65),  INT8_C( 125),  INT8_C(  11),
        -INT8_C(  41),  INT8_C( 112), -INT8_C( 126),  INT8_C(  68),  INT8_C( 110), -INT8_C( 107), -INT8_C(  16), -INT8_C( 115),
         INT8_C( 108), -INT8_C(  79), -INT8_C(  84), -INT8_C(  88),  INT8_C(  98), -INT8_C(   4),  INT8_C(  50), -INT8_C(  34),
         INT8_C(  41),  INT8_C(  12),  INT8_C(  82),  INT8_C( 111), -INT8_C(  82),  INT8_C(  21), -INT8_C(  68),  INT8_C(  13),
        -INT8_C(  11),  INT8_C( 103), -INT8_C(  65),  INT8_C(  77), -INT8_C(  88),  INT8_C( 104),  INT8_C(  94),  INT8_C(  69) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  71), -INT8_C(  70), -INT8_C(  67), -INT8_C(  64),
         INT8_C(  35), -INT8_C(  91),  INT8_C(  65),  INT8_C(  56), -INT8_C( 122),  INT8_C(  93), -INT8_C( 109),  INT8_C(  36),
        -INT8_C( 109), -INT8_C(   9), -INT8_C( 108),  INT8_C(  36), -INT8_C(  72),  INT8_C( 126), -INT8_C(  44),  INT8_C( 106),
         INT8_C(  48),  INT8_C( 120), -INT8_C( 115), -INT8_C(  64),  INT8_C(  76),  INT8_C(   0), -INT8_C(  60),  INT8_C(  26),
        -INT8_C(  78),  INT8_C(  12),  INT8_C( 108), -INT8_C(  84),  INT8_C( 125),  INT8_C( 121), -INT8_C(  44), -INT8_C(  73),
         INT8_C(  27),  INT8_C( 118), -INT8_C(  92), -INT8_C(  11), -INT8_C(  51),  INT8_C(  13), -INT8_C(  82), -INT8_C(  51),
        -INT8_C(  75),  INT8_C( 113),  INT8_C(  98),  INT8_C(  32),  INT8_C(  69), -INT8_C( 107),  INT8_C(  13),  INT8_C(  47),
        -INT8_C( 110), -INT8_C(  37),  INT8_C(  88), -INT8_C(   2),  INT8_C(  74), -INT8_C(  76), -INT8_C(  80), -INT8_C( 121),
        -INT8_C(  58),  INT8_C(  67),  INT8_C(  32), -INT8_C( 109), -INT8_C(  27), -INT8_C(  48),  INT8_C( 105), -INT8_C( 106),
        -INT8_C(  87),  INT8_C( 115),  INT8_C(  26), -INT8_C(  64),  INT8_C(  19),  INT8_C(  75),  INT8_C( 100),  INT8_C(  11),
         INT8_C(  49),  INT8_C(  23), -INT8_C(  39), -INT8_C(  99), -INT8_C(  80), -INT8_C(  75),  INT8_C( 120),  INT8_C(  18),
         INT8_C(  83), -INT8_C(  44), -INT8_C(  40), -INT8_C(   7),  INT8_C(  95),  INT8_C(  26),  INT8_C(  59),  INT8_C(  64),
         INT8_C(  81), -INT8_C(  77),  INT8_C(  43), -INT8_C(  73), -INT8_C(  79), -INT8_C(  40), -INT8_C( 118), -INT8_C(  63),
        -INT8_C(  97), -INT8_C(  11), -INT8_C(  58),  INT8_C(  49), -INT8_C(  63), -INT8_C(  21), -INT8_C(  15),  INT8_C(  27),
        -INT8_C(   5), -INT8_C(  22), -INT8_C(  78),  INT8_C(  36),  INT8_C(  60), -INT8_C(  40),  INT8_C(  91),  INT8_C(  73),
         INT8_C(  49), -INT8_C(  81), -INT8_C( 103),  INT8_C(   3), -INT8_C(  64), -INT8_C(  33),  INT8_C(  77),  INT8_C(  47),
        -INT8_C(  31),  INT8_C(  31), -INT8_C(  61), -INT8_C(   7),  INT8_C( 101),  INT8_C( 104), -INT8_C(  62), -INT8_C(  33),
         INT8_C( 120), -INT8_C(  92), -INT8_C(  91),  INT8_C(  59),  INT8_C(   4),  INT8_C(  10), -INT8_C(  83), -INT8_C( 121),
         INT8_C( 126), -INT8_C(  16), -INT8_C(  36), -INT8_C(  79), -INT8_C(  46), -INT8_C(  32), -INT8_C(   5),  INT8_C(  60),
         INT8_C(  36),  INT8_C(  11),  INT8_C( 120),  INT8_C(  75), -INT8_C(  85),  INT8_C(  86), -INT8_C(  33),  INT8_C(  36),
        -INT8_C(  11), -INT8_C( 124),  INT8_C(  59), -INT8_C(  33),  INT8_C( 100), -INT8_C(  48), -INT8_C(  11),  INT8_C(  17),
         INT8_C(  86), -INT8_C(  28),  INT8_C(  87), -INT8_C( 108),  INT8_C(  52),  INT8_C(  41), -INT8_C(  50), -INT8_C(  69),
         INT8_C( 117),  INT8_C(   1),  INT8_C(  42),  INT8_C( 116),  INT8_C(  77),  INT8_C(  27),  INT8_C(  53),  INT8_C( 111),
         INT8_C(  20),  INT8_C(  12),  INT8_C(  47),  INT8_C(   4), -INT8_C( 117),  INT8_C(  84),  INT8_C( 119),  INT8_C(  40),
        -INT8_C( 105), -INT8_C(  88),  INT8_C( 114),  INT8_C(  23), -INT8_C(  13),  INT8_C(  21), -INT8_C(  62), -INT8_C(  95),
         INT8_C( 118), -INT8_C(  64),  INT8_C( 114), -INT8_C( 109), -INT8_C(  72), -INT8_C(  57), -INT8_C(  86),  INT8_C(  20),
         INT8_C(  62),  INT8_C(  20), -INT8_C( 126),  INT8_C(  25),  INT8_C(  64),  INT8_C(  50), -INT8_C(  96), -INT8_C(   2),
         INT8_C(  16), -INT8_C(   2),  INT8_C(  98),  INT8_C(   6), -INT8_C(  97), -INT8_C( 119),  INT8_C(  38),  INT8_C(  83),
         INT8_C( 112),  INT8_C(  36), -INT8_C(  61),  INT8_C( 121), -INT8_C(  62), -INT8_C(  86),  INT8_C(  94),  INT8_C(  53),
         INT8_C(  36),  INT8_C(  82),  INT8_C(  77), -INT8_C( 104),  INT8_C( 112),  INT8_C( 124),  INT8_C( 113),  INT8_C( 118),
        -INT8_C(  77),  INT8_C(   5), -INT8_C( 111), -INT8_C( 124),  INT8_C(  56), -INT8_C(  81),  INT8_C(  42), -INT8_C( 118) },
      {      INT8_MIN, -INT8_C(   1),      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(   2),
             INT8_MIN, -INT8_C( 127),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  47), -INT8_C(  68), -INT8_C(  62),
         INT8_C( 102), -INT8_C(  25),  INT8_C( 101),      INT8_MAX, -INT8_C( 116),      INT8_MAX, -INT8_C( 113), -INT8_C(  50),
        -INT8_C(  29), -INT8_C(  74), -INT8_C( 124),  INT8_C(  47),  INT8_C(  20),      INT8_MAX,  INT8_C(  59),      INT8_MAX,
             INT8_MAX,  INT8_C(  43),      INT8_MIN, -INT8_C(  62), -INT8_C(  32), -INT8_C(  50),  INT8_C(   2),      INT8_MAX,
             INT8_MIN, -INT8_C(  82),  INT8_C(  28),      INT8_MIN,  INT8_C(  73),      INT8_MAX, -INT8_C(  87),      INT8_MIN,
         INT8_C(  21),      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(  90), -INT8_C( 105),      INT8_MIN,
             INT8_MIN,      INT8_MAX, -INT8_C(   6),  INT8_C(  54), -INT8_C(   7), -INT8_C(  23), -INT8_C(  76),  INT8_C(  36),
        -INT8_C(  82),  INT8_C(  16),  INT8_C(   6),  INT8_C(  46),  INT8_C(  20),      INT8_MIN, -INT8_C( 112), -INT8_C(  69),
        -INT8_C(  37),  INT8_C(  90),      INT8_MAX,      INT8_MIN, -INT8_C( 109),      INT8_MIN, -INT8_C(  16),      INT8_MIN,
         INT8_C(   2),      INT8_MAX,  INT8_C(  26), -INT8_C( 119),  INT8_C(  39), -INT8_C(  18),      INT8_MAX,  INT8_C(  71),
             INT8_MAX, -INT8_C(  94), -INT8_C( 109), -INT8_C(  95), -INT8_C(   4), -INT8_C(  63),  INT8_C(  12),  INT8_C( 103),
             INT8_MAX, -INT8_C(  81), -INT8_C(  64), -INT8_C( 119),  INT8_C(  99), -INT8_C(  61),      INT8_MAX, -INT8_C(  62),
         INT8_C(   8), -INT8_C(  57),  INT8_C(  27),  INT8_C(  20),  INT8_C(  40),  INT8_C(  37),      INT8_MIN,  INT8_C(  39),
             INT8_MIN,  INT8_C(  71), -INT8_C(  54), -INT8_C(  18), -INT8_C(  27), -INT8_C(  71), -INT8_C(  53),  INT8_C(   7),
         INT8_C(  79),  INT8_C(  55), -INT8_C(  85),  INT8_C(  93),  INT8_C(  88),  INT8_C(  58),  INT8_C(  87), -INT8_C(  37),
         INT8_C(  46), -INT8_C(   3),      INT8_MIN,  INT8_C( 105),      INT8_MIN, -INT8_C(  71),  INT8_C(  82), -INT8_C(  26),
        -INT8_C(  56),  INT8_C(  32), -INT8_C(  23),  INT8_C(   6),  INT8_C(  43),  INT8_C(  37), -INT8_C(   2),  INT8_C(  45),
         INT8_C(  12),      INT8_MIN,      INT8_MIN,  INT8_C( 125),  INT8_C(  49), -INT8_C(  91), -INT8_C(  20),      INT8_MIN,
         INT8_C(  26),  INT8_C(  91), -INT8_C( 109),  INT8_C(  34),      INT8_MIN,  INT8_C(  52), -INT8_C(  86),  INT8_C( 117),
         INT8_C(  51),  INT8_C(  64),  INT8_C(  23),  INT8_C(   6), -INT8_C(  13),      INT8_MAX,  INT8_C(  30), -INT8_C(  92),
         INT8_C(  13), -INT8_C(  79), -INT8_C(  45),  INT8_C(  84),  INT8_C(  68), -INT8_C(  90), -INT8_C(  67),  INT8_C(  67),
        -INT8_C(  31), -INT8_C( 107), -INT8_C(   5),      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(  92),      INT8_MIN,
         INT8_C( 123),  INT8_C(  97), -INT8_C(  18), -INT8_C(   8),  INT8_C(  10),      INT8_MAX,  INT8_C(  83),      INT8_MAX,
         INT8_C(  34),  INT8_C( 107), -INT8_C(  44), -INT8_C( 120),      INT8_MIN,  INT8_C(  99),      INT8_MAX,  INT8_C(  89),
             INT8_MIN, -INT8_C(   4),  INT8_C(  85),  INT8_C( 118), -INT8_C(  89),      INT8_MAX,  INT8_C(  63),      INT8_MIN,
         INT8_C(  72),      INT8_MIN,  INT8_C( 100),      INT8_MIN, -INT8_C(  26),      INT8_MIN, -INT8_C( 103),  INT8_C(  64),
             INT8_MAX,      INT8_MAX,      INT8_MIN, -INT8_C(  57),      INT8_MAX, -INT8_C(  15),  INT8_C(  29),  INT8_C(   9),
        -INT8_C(  25),  INT8_C( 110), -INT8_C(  28),  INT8_C(  74),  INT8_C(  13),      INT8_MIN,  INT8_C(  22), -INT8_C(  32),
             INT8_MAX, -INT8_C(  43),      INT8_MIN,  INT8_C(  33),  INT8_C(  36), -INT8_C(  90),      INT8_MAX,  INT8_C(  19),
         INT8_C(  77),  INT8_C(  94),      INT8_MAX,  INT8_C(   7),  INT8_C(  30),      INT8_MAX,  INT8_C(  45),      INT8_MAX,
        -INT8_C(  88),  INT8_C( 108),      INT8_MIN, -INT8_C(  47), -INT8_C(  32),  INT8_C(  23),      INT8_MAX, -INT8_C(  49) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wb_vadd_WbWb_sat(a, b);

    simde_test_hvx_vectorpair_i8_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i8_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i8_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wb_vadd_WbWb_sat(a, b);

    simde_test_hvx_vectorpair_i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_WhWh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_PAIR_I16_COUNT];
    int16_t b[SIMDE_HVX_PAIR_I16_COUNT];
    int16_t r[SIMDE_HVX_PAIR_I16_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C(  6526),  INT16_C(  6898), -INT16_C(  3446), -INT16_C( 21193),
         INT16_C( 18926), -INT16_C( 13244),  INT16_C( 19952),  INT16_C(  8784),  INT16_C( 24731),  INT16_C( 31139), -INT16_C( 26473), -INT16_C( 28524),
         INT16_C( 25612),  INT16_C(  9680),  INT16_C( 13631),  INT16_C( 29126), -INT16_C( 15102),  INT16_C( 32738), -INT16_C( 20843), -INT16_C(  4028),
         INT16_C(  7325),  INT16_C( 13407), -INT16_C( 17232), -INT16_C( 24922), -INT16_C( 12240), -INT16_C( 19783), -INT16_C( 26930),  INT16_C( 17259),
         INT16_C( 13292),  INT16_C(  1857), -INT16_C(  8691), -INT16_C( 25414), -INT16_C(  1398), -INT16_C(  8592), -INT16_C(  7796),  INT16_C( 14848),
        -INT16_C( 22561), -INT16_C(  2965),  INT16_C( 23161),  INT16_C(  4680), -INT16_C( 28878), -INT16_C( 11947),  INT16_C(  8245), -INT16_C( 17972),
        -INT16_C( 20459), -INT16_C(  5088), -INT16_C( 24885), -INT16_C( 26785), -INT16_C(  4021), -INT16_C( 22487),  INT16_C( 21435), -INT16_C( 14608),
        -INT16_C( 26052),  INT16_C( 10249), -INT16_C(  1029), -INT16_C( 20103),  INT16_C( 29766),  INT16_C( 11710),  INT16_C( 18934), -INT16_C(  5511),
         INT16_C(  4649), -INT16_C( 24264), -INT16_C( 23494),  INT16_C(   485),  INT16_C( 29347), -INT16_C( 10170), -INT16_C( 28338), -INT16_C( 27767),
         INT16_C( 20269), -INT16_C(  6240), -INT16_C(  4575),  INT16_C( 11396), -INT16_C(  4166), -INT16_C( 10291),  INT16_C( 29521), -INT16_C(  8826),
        -INT16_C( 23513), -INT16_C( 13200),  INT16_C( 23165), -INT16_C(  3504),  INT16_C( 30199), -INT16_C( 18592),  INT16_C( 26011),  INT16_C( 23766),
        -INT16_C(  1325),  INT16_C( 25066), -INT16_C(  8385),  INT16_C(  1079), -INT16_C( 29154),  INT16_C(  8036), -INT16_C( 28766),  INT16_C( 23223),
        -INT16_C( 21026), -INT16_C( 12261),  INT16_C(     1),  INT16_C(  3002),  INT16_C( 25352),  INT16_C(  8347), -INT16_C( 11805),  INT16_C(  1680),
         INT16_C( 21037), -INT16_C( 31991),  INT16_C( 10675),  INT16_C( 25317),  INT16_C(  2140), -INT16_C( 26026), -INT16_C( 11802),  INT16_C(  8035),
        -INT16_C(  7957),  INT16_C( 11721), -INT16_C( 13856),  INT16_C(  3343), -INT16_C(  6452),  INT16_C( 16213), -INT16_C( 29279), -INT16_C( 27712) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 12738), -INT16_C( 10152),  INT16_C(   331), -INT16_C( 25888),
         INT16_C(    30),  INT16_C( 30985),  INT16_C( 27589), -INT16_C(  3689),  INT16_C(  2504),  INT16_C( 20083), -INT16_C(  5872), -INT16_C(  2544),
        -INT16_C( 26193),  INT16_C( 25831),  INT16_C( 25469),  INT16_C( 22358), -INT16_C( 11826),  INT16_C(  2181), -INT16_C( 16999),  INT16_C( 13942),
         INT16_C( 23548), -INT16_C( 27485), -INT16_C( 10690),  INT16_C(  4561),  INT16_C( 14416),  INT16_C(  4719),  INT16_C(  8411),  INT16_C(  6757),
         INT16_C( 21822),  INT16_C( 21733),  INT16_C( 17538), -INT16_C(  7937), -INT16_C(  3704), -INT16_C( 30712),  INT16_C( 31312),  INT16_C( 30773),
         INT16_C( 17672), -INT16_C( 21472), -INT16_C( 18286), -INT16_C( 16911),  INT16_C( 10771), -INT16_C( 23357),  INT16_C( 14576), -INT16_C( 28643),
        -INT16_C(  1472),  INT16_C(  4125),  INT16_C(  7358),  INT16_C( 32001),  INT16_C( 10526),  INT16_C( 29183), -INT16_C( 29306),  INT16_C( 24221),
        -INT16_C( 29354),  INT16_C( 28146), -INT16_C( 13655),  INT16_C( 11603), -INT16_C( 28532), -INT16_C( 29306),  INT16_C( 15841),  INT16_C( 24305),
         INT16_C(  3388),  INT16_C(   488), -INT16_C(  5306), -INT16_C( 24287), -INT16_C( 14177),  INT16_C( 32692), -INT16_C(  5527),  INT16_C( 17176),
         INT16_C(  2205), -INT16_C( 27701),  INT16_C(  6368), -INT16_C( 19117),  INT16_C(  2713),  INT16_C( 11227),  INT16_C( 26764),  INT16_C( 12517),
         INT16_C( 32717),  INT16_C( 32050), -INT16_C( 15670), -INT16_C( 12049), -INT16_C( 24868), -INT16_C( 11709), -INT16_C( 25975), -INT16_C( 11365),
        -INT16_C( 16903),  INT16_C(  3112), -INT16_C(  7888),  INT16_C(  4041), -INT16_C( 20976),  INT16_C( 13155),  INT16_C( 21025),  INT16_C(  3492),
        -INT16_C( 27111), -INT16_C( 19762),  INT16_C( 25978), -INT16_C( 20212),  INT16_C( 19129),  INT16_C( 13770), -INT16_C( 18534),  INT16_C( 32451),
        -INT16_C( 29414), -INT16_C( 26268), -INT16_C(  3367),  INT16_C( 12811),  INT16_C(  5082), -INT16_C( 19669), -INT16_C( 19284), -INT16_C( 29595),
         INT16_C( 23497),  INT16_C(   322),  INT16_C( 24173), -INT16_C( 24349),  INT16_C(   519), -INT16_C(  9697), -INT16_C(  5696),  INT16_C( 26997) },
      {        INT16_MIN, -INT16_C(     1),        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C(     2),
               INT16_MIN,       -INT16_MAX,        INT16_MAX,        INT16_MAX,  INT16_C(  6212), -INT16_C(  3254), -INT16_C(  3115),        INT16_MIN,
         INT16_C( 18956),  INT16_C( 17741),        INT16_MAX,  INT16_C(  5095),  INT16_C( 27235),        INT16_MAX, -INT16_C( 32345), -INT16_C( 31068),
        -INT16_C(   581),        INT16_MAX,        INT16_MAX,        INT16_MAX, -INT16_C( 26928),        INT16_MAX,        INT16_MIN,  INT16_C(  9914),
         INT16_C( 30873), -INT16_C( 14078), -INT16_C( 27922), -INT16_C( 20361),  INT16_C(  2176), -INT16_C( 15064), -INT16_C( 18519),  INT16_C( 24016),
               INT16_MAX,  INT16_C( 23590),  INT16_C(  8847),        INT16_MIN, -INT16_C(  5102),        INT16_MIN,  INT16_C( 23516),        INT16_MAX,
        -INT16_C(  4889), -INT16_C( 24437),  INT16_C(  4875), -INT16_C( 12231), -INT16_C( 18107),        INT16_MIN,  INT16_C( 22821),        INT16_MIN,
        -INT16_C( 21931), -INT16_C(   963), -INT16_C( 17527),  INT16_C(  5216),  INT16_C(  6505),  INT16_C(  6696), -INT16_C(  7871),  INT16_C(  9613),
               INT16_MIN,        INT16_MAX, -INT16_C( 14684), -INT16_C(  8500),  INT16_C(  1234), -INT16_C( 17596),        INT16_MAX,  INT16_C( 18794),
         INT16_C(  8037), -INT16_C( 23776), -INT16_C( 28800), -INT16_C( 23802),  INT16_C( 15170),  INT16_C( 22522),        INT16_MIN, -INT16_C( 10591),
         INT16_C( 22474),        INT16_MIN,  INT16_C(  1793), -INT16_C(  7721), -INT16_C(  1453),  INT16_C(   936),        INT16_MAX,  INT16_C(  3691),
         INT16_C(  9204),  INT16_C( 18850),  INT16_C(  7495), -INT16_C( 15553),  INT16_C(  5331), -INT16_C( 30301),  INT16_C(    36),  INT16_C( 12401),
        -INT16_C( 18228),  INT16_C( 28178), -INT16_C( 16273),  INT16_C(  5120),        INT16_MIN,  INT16_C( 21191), -INT16_C(  7741),  INT16_C( 26715),
               INT16_MIN, -INT16_C( 32023),  INT16_C( 25979), -INT16_C( 17210),        INT16_MAX,  INT16_C( 22117), -INT16_C( 30339),        INT16_MAX,
        -INT16_C(  8377),        INT16_MIN,  INT16_C(  7308),        INT16_MAX,  INT16_C(  7222),        INT16_MIN, -INT16_C( 31086), -INT16_C( 21560),
         INT16_C( 15540),  INT16_C( 12043),  INT16_C( 10317), -INT16_C( 21006), -INT16_C(  5933),  INT16_C(  6516),        INT16_MIN, -INT16_C(   715) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C(  8233), -INT16_C( 22538),  INT16_C( 23890), -INT16_C(  6403),
        -INT16_C( 10716),  INT16_C( 32001),  INT16_C( 29171),  INT16_C( 21552), -INT16_C( 10915), -INT16_C( 21030),  INT16_C( 17597),  INT16_C( 13093),
        -INT16_C( 10554),  INT16_C( 24221), -INT16_C( 28178), -INT16_C( 23967), -INT16_C( 22696), -INT16_C(  4202),  INT16_C( 17443),  INT16_C( 25005),
         INT16_C( 24397),  INT16_C( 15847),  INT16_C( 26135), -INT16_C(  8924),  INT16_C( 20998),  INT16_C(  8282),  INT16_C(  4700),  INT16_C(  4880),
         INT16_C(  9373), -INT16_C( 17065), -INT16_C( 14637),  INT16_C( 10131),  INT16_C(  6952), -INT16_C( 17403), -INT16_C( 13238), -INT16_C(  9988),
        -INT16_C(   342), -INT16_C( 20651), -INT16_C(  7223),  INT16_C( 26499),  INT16_C( 27023), -INT16_C( 31319), -INT16_C( 28752), -INT16_C(  6383),
        -INT16_C( 22183),  INT16_C(  8617), -INT16_C(  1289),  INT16_C( 18577), -INT16_C( 16597), -INT16_C( 28999), -INT16_C( 25497), -INT16_C( 13531),
         INT16_C( 25749), -INT16_C( 13489),  INT16_C( 17895), -INT16_C(  2172),  INT16_C( 25354),  INT16_C( 23404), -INT16_C( 31887), -INT16_C( 31333),
        -INT16_C(  2266),  INT16_C( 19003), -INT16_C( 16766),  INT16_C(  3702),  INT16_C(  9958), -INT16_C( 24378), -INT16_C( 12693), -INT16_C( 20666),
        -INT16_C( 24376), -INT16_C( 19311),  INT16_C(  6398),  INT16_C( 15954), -INT16_C( 11868),  INT16_C(  3025), -INT16_C( 18214),  INT16_C(   351),
         INT16_C( 26107),  INT16_C(   705), -INT16_C( 29072),  INT16_C( 10527), -INT16_C( 17067), -INT16_C( 21364),  INT16_C( 27101), -INT16_C(  7425),
         INT16_C( 19222), -INT16_C( 11237), -INT16_C(  4494), -INT16_C(  3695),  INT16_C(  3898),  INT16_C( 28153),  INT16_C( 13490),  INT16_C( 24754),
        -INT16_C(  2284),  INT16_C(    75),  INT16_C( 28276),  INT16_C(  1394),  INT16_C(  5950),  INT16_C( 10728),  INT16_C( 24741),  INT16_C(  8336),
         INT16_C( 12704), -INT16_C( 31678), -INT16_C( 15840), -INT16_C( 26539),  INT16_C( 22387), -INT16_C( 13082), -INT16_C(  2862), -INT16_C( 12952),
        -INT16_C( 13083),  INT16_C( 18196),  INT16_C(   354),  INT16_C( 23319), -INT16_C( 19444),  INT16_C(  5345),  INT16_C(  2384),  INT16_C( 29306) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 21542),  INT16_C( 12763),  INT16_C(  6615), -INT16_C( 23908),
         INT16_C( 25153), -INT16_C(  5070), -INT16_C( 10880),  INT16_C( 31631), -INT16_C(  4773),  INT16_C( 29619), -INT16_C(  7083), -INT16_C(  4208),
         INT16_C( 14576),  INT16_C(  7558),  INT16_C(  7637), -INT16_C( 10294), -INT16_C( 18237), -INT16_C( 13505),  INT16_C(  8425),  INT16_C( 12500),
         INT16_C( 19473), -INT16_C( 20019),  INT16_C( 11582),  INT16_C( 22895),  INT16_C( 21776), -INT16_C( 22925),  INT16_C( 29317), -INT16_C( 32765),
         INT16_C( 19942), -INT16_C( 17722),  INT16_C(  2881),  INT16_C(  8630), -INT16_C(  2748), -INT16_C(   848), -INT16_C( 31828), -INT16_C( 15332),
        -INT16_C( 31616), -INT16_C(  5816), -INT16_C(  6117), -INT16_C( 26836), -INT16_C( 28896),  INT16_C( 11804), -INT16_C(  2268), -INT16_C( 16611),
        -INT16_C(  2694),  INT16_C(   144),  INT16_C( 11186), -INT16_C( 10836),  INT16_C( 15370),  INT16_C( 27833), -INT16_C(  2036),  INT16_C(  8747),
         INT16_C( 23794), -INT16_C( 25607), -INT16_C( 14162), -INT16_C( 16491),  INT16_C( 15862),  INT16_C( 15779), -INT16_C( 18736),  INT16_C(  4039),
        -INT16_C( 27843), -INT16_C( 13413),  INT16_C( 24102),  INT16_C( 20956),  INT16_C(  9165), -INT16_C( 27143), -INT16_C( 32646), -INT16_C( 26478),
        -INT16_C(  8223),  INT16_C(  3687), -INT16_C( 27276), -INT16_C( 22937), -INT16_C( 24627),  INT16_C(  2301), -INT16_C( 12831), -INT16_C( 21727),
        -INT16_C( 23486),  INT16_C(  5665),  INT16_C( 19106),  INT16_C( 12851),  INT16_C( 30065), -INT16_C( 30505), -INT16_C(  7623), -INT16_C(  1700),
        -INT16_C(  1895), -INT16_C(  5163), -INT16_C(  1802), -INT16_C( 18483),  INT16_C(  6730),  INT16_C( 19085),  INT16_C( 27511),  INT16_C( 22249),
        -INT16_C( 21861), -INT16_C(  8144), -INT16_C(  3553),  INT16_C( 26778),  INT16_C( 30306),  INT16_C( 11946), -INT16_C( 22750),  INT16_C(  2349),
         INT16_C(  7533), -INT16_C(  7855), -INT16_C( 10379), -INT16_C( 13471),  INT16_C( 18578),  INT16_C( 19214), -INT16_C( 27914), -INT16_C( 27566),
        -INT16_C( 26295), -INT16_C( 28549), -INT16_C( 10772), -INT16_C( 13897), -INT16_C( 18844),  INT16_C(  2671), -INT16_C( 26900),  INT16_C( 30177) },
      {        INT16_MIN, -INT16_C(     1),        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C(     2),
               INT16_MIN,       -INT16_MAX,        INT16_MAX,        INT16_MAX,  INT16_C( 13309), -INT16_C(  9775),  INT16_C( 30505), -INT16_C( 30311),
         INT16_C( 14437),  INT16_C( 26931),  INT16_C( 18291),        INT16_MAX, -INT16_C( 15688),  INT16_C(  8589),  INT16_C( 10514),  INT16_C(  8885),
         INT16_C(  4022),  INT16_C( 31779), -INT16_C( 20541),        INT16_MIN,        INT16_MIN, -INT16_C( 17707),  INT16_C( 25868),        INT16_MAX,
               INT16_MAX, -INT16_C(  4172),        INT16_MAX,  INT16_C( 13971),        INT16_MAX, -INT16_C( 14643),        INT16_MAX, -INT16_C( 27885),
         INT16_C( 29315),        INT16_MIN, -INT16_C( 11756),  INT16_C( 18761),  INT16_C(  4204), -INT16_C( 18251),        INT16_MIN, -INT16_C( 25320),
        -INT16_C( 31958), -INT16_C( 26467), -INT16_C( 13340), -INT16_C(   337), -INT16_C(  1873), -INT16_C( 19515), -INT16_C( 31020), -INT16_C( 22994),
        -INT16_C( 24877),  INT16_C(  8761),  INT16_C(  9897),  INT16_C(  7741), -INT16_C(  1227), -INT16_C(  1166), -INT16_C( 27533), -INT16_C(  4784),
               INT16_MAX,        INT16_MIN,  INT16_C(  3733), -INT16_C( 18663),        INT16_MAX,        INT16_MAX,        INT16_MIN, -INT16_C( 27294),
        -INT16_C( 30109),  INT16_C(  5590),  INT16_C(  7336),  INT16_C( 24658),  INT16_C( 19123),        INT16_MIN,        INT16_MIN,        INT16_MIN,
        -INT16_C( 32599), -INT16_C( 15624), -INT16_C( 20878), -INT16_C(  6983),        INT16_MIN,  INT16_C(  5326), -INT16_C( 31045), -INT16_C( 21376),
         INT16_C(  2621),  INT16_C(  6370), -INT16_C(  9966),  INT16_C( 23378),  INT16_C( 12998),        INT16_MIN,  INT16_C( 19478), -INT16_C(  9125),
         INT16_C( 17327), -INT16_C( 16400), -INT16_C(  6296), -INT16_C( 22178),  INT16_C( 10628),        INT16_MAX,        INT16_MAX,        INT16_MAX,
        -INT16_C( 24145), -INT16_C(  8069),  INT16_C( 24723),  INT16_C( 28172),        INT16_MAX,  INT16_C( 22674),  INT16_C(  1991),  INT16_C( 10685),
         INT16_C( 20237),        INT16_MIN, -INT16_C( 26219),        INT16_MIN,        INT16_MAX,  INT16_C(  6132), -INT16_C( 30776),        INT16_MIN,
               INT16_MIN, -INT16_C( 10353), -INT16_C( 10418),  INT16_C(  9422),        INT16_MIN,  INT16_C(  8016), -INT16_C( 24516),        INT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vadd_WhWh_sat(a, b);

    simde_test_hvx_vectorpair_i16_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i16_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i16_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vadd_WhWh_sat(a, b);

    simde_test_hvx_vectorpair_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_WwWw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_PAIR_I32_COUNT];
    int32_t b[SIMDE_HVX_PAIR_I32_COUNT];
    int32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(   202784944), -INT32_C(   648690600), -INT32_C(  1836329459), -INT32_C(  1028288132),
        -INT32_C(   807950425),  INT32_C(  1114001045), -INT32_C(   778774005),  INT32_C(   431531622),  INT32_C(   541251799), -INT32_C(   578413075),  INT32_C(   724524698),  INT32_C(   138127749),
        -INT32_C(  1491671514),  INT32_C(   855258728), -INT32_C(  1257160415),  INT32_C(  2039849688), -INT32_C(   260082276),  INT32_C(  1623983118), -INT32_C(   649950667), -INT32_C(   634292226),
        -INT32_C(  1800793534), -INT32_C(  1712321319),  INT32_C(   893046119),  INT32_C(   145085958),  INT32_C(   844104885), -INT32_C(   752129206),  INT32_C(   414102919),  INT32_C(   593077150),
        -INT32_C(   962334726),  INT32_C(   710317590),  INT32_C(   277623016), -INT32_C(   449286104), -INT32_C(   768152812),  INT32_C(  2136924534),  INT32_C(   245286433), -INT32_C(   420711647),
        -INT32_C(   515409199), -INT32_C(   912174703), -INT32_C(  1519806512),  INT32_C(  1446087793), -INT32_C(   620762788), -INT32_C(  1710019700), -INT32_C(   693602351), -INT32_C(  1280260079),
        -INT32_C(  1424059894),  INT32_C(  1638715817), -INT32_C(   133776510), -INT32_C(   219811946), -INT32_C(   795637282), -INT32_C(   659660777),  INT32_C(   964436599), -INT32_C(  1717725680) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX, -INT32_C(   190723481), -INT32_C(   307847046), -INT32_C(  1721420777), -INT32_C(  1761921454),
        -INT32_C(   630827699), -INT32_C(  1332196384),  INT32_C(   729208950), -INT32_C(   242846990),  INT32_C(   649802252), -INT32_C(   855350313), -INT32_C(  2004184378), -INT32_C(   807359549),
        -INT32_C(  1782671595), -INT32_C(  2133157010), -INT32_C(  1822588470), -INT32_C(   693231046), -INT32_C(  1795154280), -INT32_C(  2058470907),  INT32_C(    41349634), -INT32_C(   862367061),
        -INT32_C(   771980225), -INT32_C(   153211868), -INT32_C(  1507711918), -INT32_C(   599376130), -INT32_C(  1904161116),  INT32_C(  1511778025),  INT32_C(  1092825641), -INT32_C(   757384255),
         INT32_C(  1618761992),  INT32_C(  1740997021),  INT32_C(  1921687717), -INT32_C(   879769069), -INT32_C(  1295758912),  INT32_C(    78946784),  INT32_C(  1128141878), -INT32_C(   641012230),
        -INT32_C(  1471879699), -INT32_C(   233919243), -INT32_C(  1162433224),  INT32_C(   609521026), -INT32_C(   753446683), -INT32_C(  1135693397),  INT32_C(   307857176), -INT32_C(   116367789),
         INT32_C(  1075393250),  INT32_C(  1335144042), -INT32_C(    65739924),  INT32_C(  1472777230),  INT32_C(  1499054959), -INT32_C(   758544686), -INT32_C(  2137427571),  INT32_C(  1719759128) },
      {              INT32_MIN, -INT32_C(           1),              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(           2),
                     INT32_MIN, -INT32_C(  2147483647),              INT32_MAX,              INT32_MAX,  INT32_C(    12061463), -INT32_C(   956537646),              INT32_MIN,              INT32_MIN,
        -INT32_C(  1438778124), -INT32_C(   218195339), -INT32_C(    49565055),  INT32_C(   188684632),  INT32_C(  1191054051), -INT32_C(  1433763388), -INT32_C(  1279659680), -INT32_C(   669231800),
                     INT32_MIN, -INT32_C(  1277898282),              INT32_MIN,  INT32_C(  1346618642), -INT32_C(  2055236556), -INT32_C(   434487789), -INT32_C(   608601033), -INT32_C(  1496659287),
                     INT32_MIN, -INT32_C(  1865533187), -INT32_C(   614665799), -INT32_C(   454290172), -INT32_C(  1060056231),  INT32_C(   759648819),  INT32_C(  1506928560), -INT32_C(   164307105),
         INT32_C(   656427266),              INT32_MAX,              INT32_MAX, -INT32_C(  1329055173), -INT32_C(  2063911724),              INT32_MAX,  INT32_C(  1373428311), -INT32_C(  1061723877),
        -INT32_C(  1987288898), -INT32_C(  1146093946),              INT32_MIN,  INT32_C(  2055608819), -INT32_C(  1374209471),              INT32_MIN, -INT32_C(   385745175), -INT32_C(  1396627868),
        -INT32_C(   348666644),              INT32_MAX, -INT32_C(   199516434),  INT32_C(  1252965284),  INT32_C(   703417677), -INT32_C(  1418205463), -INT32_C(  1172990972),  INT32_C(     2033448) } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(    39524437), -INT32_C(  1220595934), -INT32_C(  1785175391), -INT32_C(  1959784258),
         INT32_C(  1891473955),  INT32_C(   511117249), -INT32_C(  1582258001),  INT32_C(  2124938234),  INT32_C(  1661084931), -INT32_C(  1072650271), -INT32_C(  1213779644), -INT32_C(  1536011464),
        -INT32_C(  1071749206),  INT32_C(   630802125), -INT32_C(  1632193224), -INT32_C(   126064999), -INT32_C(   276805337),  INT32_C(  1064099958),  INT32_C(  1968840619),  INT32_C(   782573406),
        -INT32_C(   915796610), -INT32_C(  1467374808),  INT32_C(  1445835149),  INT32_C(  1520086146),  INT32_C(  1312150016),  INT32_C(   256061401), -INT32_C(  1971892313), -INT32_C(  1992905560),
        -INT32_C(  1039792931),  INT32_C(  1580866463), -INT32_C(   521900904), -INT32_C(   739023383), -INT32_C(  1871762055),  INT32_C(   338245302), -INT32_C(  1930420130),  INT32_C(  1626439174),
        -INT32_C(  1904300548),  INT32_C(  1542789812),  INT32_C(   628942033), -INT32_C(   436616595),  INT32_C(   314169762),  INT32_C(  1285127247),  INT32_C(   873755811),  INT32_C(   388260775),
         INT32_C(  1569586754), -INT32_C(   329921722), -INT32_C(   581086373), -INT32_C(  1803662178), -INT32_C(   559428189),  INT32_C(  1672579816),  INT32_C(   456949454), -INT32_C(  1035931840) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX, -INT32_C(  1084701027),  INT32_C(   998526226), -INT32_C(  1664068788), -INT32_C(   507544332),
        -INT32_C(  1812063192),  INT32_C(  1716962491),  INT32_C(  2143093236), -INT32_C(  1791768273), -INT32_C(   825828583), -INT32_C(   429453366), -INT32_C(  1202899088),  INT32_C(  1899416979),
        -INT32_C(  1779202272),  INT32_C(   686081282),  INT32_C(   263233379),  INT32_C(  1593032993),  INT32_C(  1665903842), -INT32_C(   347968740),  INT32_C(   550509127), -INT32_C(  1770399934),
         INT32_C(  1414359671), -INT32_C(   486913696),  INT32_C(  1712080080), -INT32_C(  1368179141),  INT32_C(  1079399324),  INT32_C(  2065237973), -INT32_C(   827776299), -INT32_C(  1956071172),
         INT32_C(   792279596),  INT32_C(  1780190610),  INT32_C(  1751674418), -INT32_C(   653120817), -INT32_C(  1480890800),  INT32_C(  1703980203), -INT32_C(  1345320149),  INT32_C(  1799009898),
         INT32_C(  1183230447), -INT32_C(  1877471679), -INT32_C(   525982518),  INT32_C(   514449618),  INT32_C(  1040441568),  INT32_C(   740680742), -INT32_C(   317756481), -INT32_C(  1482541907),
         INT32_C(   497768021), -INT32_C(   284235860), -INT32_C(  2082143943), -INT32_C(   596840606),  INT32_C(  1899662852), -INT32_C(  1712058106), -INT32_C(  1447722429), -INT32_C(   177588572) },
      {              INT32_MIN, -INT32_C(           1),              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(           2),
                     INT32_MIN, -INT32_C(  2147483647),              INT32_MAX,              INT32_MAX, -INT32_C(  1045176590), -INT32_C(   222069708),              INT32_MIN,              INT32_MIN,
         INT32_C(    79410763),              INT32_MAX,  INT32_C(   560835235),  INT32_C(   333169961),  INT32_C(   835256348), -INT32_C(  1502103637),              INT32_MIN,  INT32_C(   363405515),
                     INT32_MIN,  INT32_C(  1316883407), -INT32_C(  1368959845),  INT32_C(  1466967994),  INT32_C(  1389098505),  INT32_C(   716131218),              INT32_MAX, -INT32_C(   987826528),
         INT32_C(   498563061), -INT32_C(  1954288504),              INT32_MAX,  INT32_C(   151907005),              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MIN,
        -INT32_C(   247513335),              INT32_MAX,  INT32_C(  1229773514), -INT32_C(  1392144200),              INT32_MIN,  INT32_C(  2042225505),              INT32_MIN,              INT32_MAX,
        -INT32_C(   721070101), -INT32_C(   334681867),  INT32_C(   102959515),  INT32_C(    77833023),  INT32_C(  1354611330),  INT32_C(  2025807989),  INT32_C(   555999330), -INT32_C(  1094281132),
         INT32_C(  2067354775), -INT32_C(   614157582),              INT32_MIN,              INT32_MIN,  INT32_C(  1340234663), -INT32_C(    39478290), -INT32_C(   990772975), -INT32_C(  1213520412) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vadd_WwWw_sat(a, b);

    simde_test_hvx_vectorpair_i32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i32_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_i32_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vadd_WwWw_sat(a, b);

    simde_test_hvx_vectorpair_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_WubWub_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[SIMDE_HVX_PAIR_SIZE];
    uint8_t b[SIMDE_HVX_PAIR_SIZE];
    uint8_t r[SIMDE_HVX_PAIR_SIZE];
  } test_vec[] = {
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(208), UINT8_C( 76), UINT8_C( 67), UINT8_C( 62),
        UINT8_C(185), UINT8_C(250), UINT8_C( 61), UINT8_C( 88), UINT8_C( 40), UINT8_C( 10), UINT8_C(245), UINT8_C(208),
        UINT8_C(252), UINT8_C(129), UINT8_C(194), UINT8_C( 69), UINT8_C(178), UINT8_C( 84), UINT8_C(146), UINT8_C(197),
        UINT8_C(173), UINT8_C(  2), UINT8_C(148), UINT8_C(108), UINT8_C(  2), UINT8_C(184), UINT8_C( 92), UINT8_C( 55),
        UINT8_C( 13), UINT8_C( 50), UINT8_C( 38), UINT8_C( 63), UINT8_C( 35), UINT8_C( 19), UINT8_C(174), UINT8_C(118),
        UINT8_C( 63), UINT8_C(213), UINT8_C(140), UINT8_C( 22), UINT8_C(242), UINT8_C( 54), UINT8_C(185), UINT8_C(221),
        UINT8_C(151), UINT8_C( 89), UINT8_C(151), UINT8_C( 36), UINT8_C(  7), UINT8_C( 59), UINT8_C(242), UINT8_C( 53),
        UINT8_C( 59), UINT8_C(223), UINT8_C( 42), UINT8_C(163), UINT8_C( 48), UINT8_C( 36), UINT8_C(101), UINT8_C(194),
        UINT8_C(100), UINT8_C(250), UINT8_C(246), UINT8_C(111), UINT8_C( 36), UINT8_C(190), UINT8_C( 34), UINT8_C(106),
        UINT8_C(139), UINT8_C(225), UINT8_C(151), UINT8_C(189), UINT8_C( 52), UINT8_C( 37), UINT8_C(170), UINT8_C(208),
        UINT8_C(134), UINT8_C(  3), UINT8_C( 36), UINT8_C(238), UINT8_C( 99), UINT8_C(164), UINT8_C( 83), UINT8_C(131),
        UINT8_C(146), UINT8_C(135), UINT8_C(220), UINT8_C(224), UINT8_C(109), UINT8_C(  7), UINT8_C( 74), UINT8_C(239),
        UINT8_C( 38), UINT8_C(100), UINT8_C(192), UINT8_C(124), UINT8_C(225), UINT8_C(229), UINT8_C(233), UINT8_C(235),
        UINT8_C( 67), UINT8_C( 94), UINT8_C(141), UINT8_C(178), UINT8_C(149), UINT8_C(176), UINT8_C(204), UINT8_C( 70),
        UINT8_C(207), UINT8_C( 77), UINT8_C(154), UINT8_C( 80), UINT8_C(100), UINT8_C(208), UINT8_C( 23), UINT8_C(253),
        UINT8_C(129), UINT8_C(186), UINT8_C(222), UINT8_C(172), UINT8_C( 40), UINT8_C( 91), UINT8_C( 27), UINT8_C( 53),
        UINT8_C(176), UINT8_C( 13), UINT8_C( 79), UINT8_C( 91), UINT8_C(179), UINT8_C(113), UINT8_C(128), UINT8_C(101),
        UINT8_C( 47), UINT8_C(245), UINT8_C(171), UINT8_C(146), UINT8_C(116), UINT8_C(141), UINT8_C(247), UINT8_C(133),
        UINT8_C(103), UINT8_C( 33), UINT8_C(152), UINT8_C( 69), UINT8_C( 68), UINT8_C(132), UINT8_C( 80), UINT8_C(122),
        UINT8_C(137), UINT8_C(164), UINT8_C(234), UINT8_C( 77), UINT8_C(205), UINT8_C( 91), UINT8_C(172), UINT8_C( 76),
        UINT8_C(198), UINT8_C(226), UINT8_C(194), UINT8_C(122), UINT8_C(203), UINT8_C( 98), UINT8_C(118), UINT8_C( 20),
        UINT8_C( 53), UINT8_C( 34), UINT8_C( 12), UINT8_C(145), UINT8_C( 85), UINT8_C(112), UINT8_C(156), UINT8_C(  9),
        UINT8_C( 13), UINT8_C( 88), UINT8_C(216), UINT8_C(210), UINT8_C( 41), UINT8_C(132), UINT8_C( 97), UINT8_C( 73),
        UINT8_C(147), UINT8_C( 12), UINT8_C(207), UINT8_C(223), UINT8_C(239), UINT8_C( 91), UINT8_C( 23), UINT8_C(122),
        UINT8_C( 49), UINT8_C(181), UINT8_C(251), UINT8_C( 72), UINT8_C( 52), UINT8_C(254), UINT8_C(205), UINT8_C(182),
        UINT8_C(206), UINT8_C( 31), UINT8_C(247), UINT8_C( 93), UINT8_C(195), UINT8_C(163), UINT8_C(  0), UINT8_C(155),
        UINT8_C(151), UINT8_C(251), UINT8_C( 99), UINT8_C( 79), UINT8_C(228), UINT8_C(140), UINT8_C( 33), UINT8_C(165),
        UINT8_C( 37), UINT8_C(250), UINT8_C(127), UINT8_C(253), UINT8_C(235), UINT8_C( 33), UINT8_C(189), UINT8_C(108),
        UINT8_C(209), UINT8_C( 63), UINT8_C(146), UINT8_C( 54), UINT8_C( 89), UINT8_C(151), UINT8_C(214), UINT8_C(190),
        UINT8_C(251), UINT8_C( 78), UINT8_C(174), UINT8_C(134), UINT8_C(184), UINT8_C( 32), UINT8_C(252), UINT8_C(224),
        UINT8_C(212), UINT8_C( 22), UINT8_C( 57), UINT8_C( 38), UINT8_C( 63), UINT8_C(206), UINT8_C(116), UINT8_C(165) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C( 17), UINT8_C(189), UINT8_C(146), UINT8_C( 10),
        UINT8_C(193), UINT8_C( 40), UINT8_C(189), UINT8_C( 91), UINT8_C(136), UINT8_C( 50), UINT8_C( 61), UINT8_C(110),
        UINT8_C(218), UINT8_C(  0), UINT8_C(137), UINT8_C( 26), UINT8_C(190), UINT8_C(234), UINT8_C(111), UINT8_C(183),
        UINT8_C(223), UINT8_C(100), UINT8_C(154), UINT8_C( 14), UINT8_C( 88), UINT8_C(  5), UINT8_C(  5), UINT8_C(184),
        UINT8_C(178), UINT8_C(181), UINT8_C(211), UINT8_C(206), UINT8_C( 35), UINT8_C(254), UINT8_C(144), UINT8_C( 15),
        UINT8_C( 28), UINT8_C(163), UINT8_C(203), UINT8_C( 81), UINT8_C( 68), UINT8_C(135), UINT8_C(  1), UINT8_C( 98),
        UINT8_C(228), UINT8_C( 37), UINT8_C( 87), UINT8_C(  3), UINT8_C(235), UINT8_C(108), UINT8_C(243), UINT8_C(137),
        UINT8_C( 28), UINT8_C( 71), UINT8_C( 36), UINT8_C( 98), UINT8_C( 99), UINT8_C( 42), UINT8_C(181), UINT8_C(204),
        UINT8_C(253), UINT8_C( 12), UINT8_C(146), UINT8_C(126), UINT8_C( 75), UINT8_C( 34), UINT8_C( 76), UINT8_C(148),
        UINT8_C(119), UINT8_C( 32), UINT8_C(229), UINT8_C(230), UINT8_C(159), UINT8_C(210), UINT8_C( 89), UINT8_C(109),
        UINT8_C(163), UINT8_C( 83), UINT8_C(178), UINT8_C( 25), UINT8_C( 25), UINT8_C(195), UINT8_C(208), UINT8_C(131),
        UINT8_C(251), UINT8_C( 88), UINT8_C( 87), UINT8_C(205), UINT8_C( 76), UINT8_C( 88), UINT8_C( 56), UINT8_C( 64),
        UINT8_C( 60), UINT8_C(136), UINT8_C( 59), UINT8_C(223), UINT8_C(198), UINT8_C(225), UINT8_C( 17), UINT8_C(223),
        UINT8_C(163), UINT8_C(214), UINT8_C( 82), UINT8_C(  0), UINT8_C( 93), UINT8_C(226), UINT8_C(228), UINT8_C(107),
        UINT8_C( 26), UINT8_C(130), UINT8_C( 93), UINT8_C(179), UINT8_C(174), UINT8_C(193), UINT8_C( 97), UINT8_C(185),
        UINT8_C(212), UINT8_C(119), UINT8_C( 57), UINT8_C(105), UINT8_C(185), UINT8_C(114), UINT8_C(181), UINT8_C(148),
        UINT8_C(162), UINT8_C(155), UINT8_C(104), UINT8_C( 24), UINT8_C( 84), UINT8_C( 35), UINT8_C( 81), UINT8_C(108),
        UINT8_C( 78), UINT8_C(187), UINT8_C(220), UINT8_C(212), UINT8_C( 48), UINT8_C( 66), UINT8_C( 19), UINT8_C(117),
        UINT8_C(243), UINT8_C( 34), UINT8_C(  3), UINT8_C(137), UINT8_C(233), UINT8_C(145), UINT8_C(172), UINT8_C( 91),
        UINT8_C(104), UINT8_C( 75), UINT8_C(207), UINT8_C( 31), UINT8_C(135), UINT8_C(109), UINT8_C( 19), UINT8_C( 31),
        UINT8_C(133), UINT8_C(101), UINT8_C(127), UINT8_C(229), UINT8_C(195), UINT8_C(183), UINT8_C(141), UINT8_C( 29),
        UINT8_C(251), UINT8_C(241), UINT8_C(166), UINT8_C( 72), UINT8_C( 40), UINT8_C( 77), UINT8_C(225), UINT8_C(118),
        UINT8_C( 83), UINT8_C(232), UINT8_C(228), UINT8_C(121), UINT8_C( 39), UINT8_C( 55), UINT8_C(  0), UINT8_C(170),
        UINT8_C(153), UINT8_C(108), UINT8_C(170), UINT8_C(203), UINT8_C(240), UINT8_C( 50), UINT8_C(117), UINT8_C( 99),
        UINT8_C(243), UINT8_C( 63), UINT8_C( 37), UINT8_C( 24), UINT8_C(243), UINT8_C(145), UINT8_C(173), UINT8_C(240),
        UINT8_C(119), UINT8_C(177), UINT8_C(116), UINT8_C(214), UINT8_C(149), UINT8_C(207), UINT8_C( 26), UINT8_C( 58),
        UINT8_C( 56), UINT8_C( 17), UINT8_C(  5), UINT8_C(204), UINT8_C(172), UINT8_C(134), UINT8_C( 22), UINT8_C(107),
        UINT8_C(158), UINT8_C( 13), UINT8_C(247), UINT8_C(219), UINT8_C( 50), UINT8_C(246), UINT8_C( 61), UINT8_C(218),
        UINT8_C(203), UINT8_C(193), UINT8_C( 41), UINT8_C(157), UINT8_C( 96), UINT8_C(133), UINT8_C(225), UINT8_C( 45),
        UINT8_C(210), UINT8_C(179), UINT8_C(127), UINT8_C(237), UINT8_C(108), UINT8_C( 27), UINT8_C( 20), UINT8_C(  2),
        UINT8_C( 72), UINT8_C( 54), UINT8_C(219), UINT8_C(242), UINT8_C(236), UINT8_C(159), UINT8_C(175), UINT8_C(219) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  2),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX,    UINT8_MAX, UINT8_C(225),    UINT8_MAX, UINT8_C(213), UINT8_C( 72),
           UINT8_MAX,    UINT8_MAX, UINT8_C(250), UINT8_C(179), UINT8_C(176), UINT8_C( 60),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(129),    UINT8_MAX, UINT8_C( 95),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(102),    UINT8_MAX, UINT8_C(122), UINT8_C( 90), UINT8_C(189), UINT8_C( 97), UINT8_C(239),
        UINT8_C(191), UINT8_C(231), UINT8_C(249),    UINT8_MAX, UINT8_C( 70),    UINT8_MAX,    UINT8_MAX, UINT8_C(133),
        UINT8_C( 91),    UINT8_MAX,    UINT8_MAX, UINT8_C(103),    UINT8_MAX, UINT8_C(189), UINT8_C(186),    UINT8_MAX,
           UINT8_MAX, UINT8_C(126), UINT8_C(238), UINT8_C( 39), UINT8_C(242), UINT8_C(167),    UINT8_MAX, UINT8_C(190),
        UINT8_C( 87),    UINT8_MAX, UINT8_C( 78),    UINT8_MAX, UINT8_C(147), UINT8_C( 78),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(237), UINT8_C(111), UINT8_C(224), UINT8_C(110), UINT8_C(254),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(211), UINT8_C(247),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C( 86), UINT8_C(214),    UINT8_MAX, UINT8_C(124),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(223),    UINT8_MAX,    UINT8_MAX, UINT8_C(185), UINT8_C( 95), UINT8_C(130),    UINT8_MAX,
        UINT8_C( 98), UINT8_C(236), UINT8_C(251),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(250),    UINT8_MAX,
        UINT8_C(230),    UINT8_MAX, UINT8_C(223), UINT8_C(178), UINT8_C(242),    UINT8_MAX,    UINT8_MAX, UINT8_C(177),
        UINT8_C(233), UINT8_C(207), UINT8_C(247),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(120),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(225), UINT8_C(205), UINT8_C(208), UINT8_C(201),
           UINT8_MAX, UINT8_C(168), UINT8_C(183), UINT8_C(115),    UINT8_MAX, UINT8_C(148), UINT8_C(209), UINT8_C(209),
        UINT8_C(125),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(164), UINT8_C(207),    UINT8_MAX, UINT8_C(250),
           UINT8_MAX, UINT8_C( 67), UINT8_C(155), UINT8_C(206),    UINT8_MAX,    UINT8_MAX, UINT8_C(252), UINT8_C(213),
        UINT8_C(241), UINT8_C(239),    UINT8_MAX, UINT8_C(108),    UINT8_MAX, UINT8_C(200), UINT8_C(191), UINT8_C(107),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 49),
           UINT8_MAX,    UINT8_MAX, UINT8_C(178), UINT8_C(217), UINT8_C(125), UINT8_C(189),    UINT8_MAX, UINT8_C(127),
        UINT8_C( 96),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 80), UINT8_C(187), UINT8_C( 97), UINT8_C(243),
           UINT8_MAX, UINT8_C(120),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(141), UINT8_C(140), UINT8_C(221),
           UINT8_MAX, UINT8_C(244),    UINT8_MAX, UINT8_C( 96),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(208),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 26), UINT8_C(213),
        UINT8_C(207),    UINT8_MAX, UINT8_C(104),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 55),    UINT8_MAX,
        UINT8_C(195),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(250),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(187), UINT8_C(211), UINT8_C(185),    UINT8_MAX,    UINT8_MAX, UINT8_C(235),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 59),    UINT8_MAX, UINT8_C(226),
           UINT8_MAX, UINT8_C( 76),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C( 36), UINT8_C(126), UINT8_C(  2), UINT8_C( 32),
        UINT8_C(212), UINT8_C( 30), UINT8_C(193), UINT8_C(216), UINT8_C( 54), UINT8_C(173), UINT8_C(242), UINT8_C(155),
        UINT8_C( 47), UINT8_C(145), UINT8_C(128), UINT8_C(204), UINT8_C( 78), UINT8_C(232), UINT8_C(178), UINT8_C( 31),
        UINT8_C(127), UINT8_C( 42), UINT8_C(131), UINT8_C( 42), UINT8_C(188), UINT8_C(109), UINT8_C( 43), UINT8_C(190),
        UINT8_C( 81), UINT8_C( 55), UINT8_C(125), UINT8_C( 97), UINT8_C(132), UINT8_C( 63), UINT8_C(111), UINT8_C( 72),
        UINT8_C(247), UINT8_C(238), UINT8_C(201), UINT8_C( 28), UINT8_C(109), UINT8_C( 60), UINT8_C( 96), UINT8_C(236),
        UINT8_C(113), UINT8_C(202), UINT8_C( 93), UINT8_C(109), UINT8_C(116), UINT8_C(142), UINT8_C(206), UINT8_C( 57),
        UINT8_C(106), UINT8_C( 27), UINT8_C(173), UINT8_C(239), UINT8_C(119), UINT8_C( 56), UINT8_C( 57), UINT8_C(126),
        UINT8_C(157), UINT8_C( 15), UINT8_C(172), UINT8_C( 22), UINT8_C(244), UINT8_C(153), UINT8_C(107), UINT8_C(  7),
        UINT8_C(218), UINT8_C(227), UINT8_C(  1), UINT8_C( 97), UINT8_C(108), UINT8_C( 92), UINT8_C(211), UINT8_C( 13),
        UINT8_C(195), UINT8_C( 67), UINT8_C( 94), UINT8_C( 92), UINT8_C(  4), UINT8_C(119), UINT8_C(148), UINT8_C(126),
        UINT8_C( 54), UINT8_C( 76), UINT8_C(193), UINT8_C(234), UINT8_C(190), UINT8_C(105), UINT8_C(251), UINT8_C( 65),
        UINT8_C( 62), UINT8_C(238), UINT8_C( 87), UINT8_C(141), UINT8_C(157), UINT8_C( 41),    UINT8_MAX, UINT8_C(220),
        UINT8_C( 59), UINT8_C(234), UINT8_C(134), UINT8_C(206), UINT8_C(208), UINT8_C(151), UINT8_C( 72), UINT8_C(214),
        UINT8_C(226), UINT8_C(226), UINT8_C(154), UINT8_C( 86), UINT8_C(238), UINT8_C(195), UINT8_C( 26), UINT8_C(129),
        UINT8_C(134), UINT8_C(128), UINT8_C( 87), UINT8_C(132), UINT8_C( 47), UINT8_C(136), UINT8_C(114), UINT8_C( 81),
           UINT8_MAX, UINT8_C(223), UINT8_C(167), UINT8_C(225), UINT8_C(103), UINT8_C(144), UINT8_C( 88), UINT8_C( 17),
        UINT8_C(110), UINT8_C(  6), UINT8_C(114), UINT8_C(244), UINT8_C( 97), UINT8_C(  7), UINT8_C(132), UINT8_C(244),
        UINT8_C(235), UINT8_C( 91), UINT8_C(137), UINT8_C(148), UINT8_C( 50), UINT8_C(197), UINT8_C( 27), UINT8_C(143),
        UINT8_C( 26), UINT8_C(151), UINT8_C(126), UINT8_C( 12), UINT8_C(215), UINT8_C(  8), UINT8_C( 85), UINT8_C(100),
        UINT8_C(131), UINT8_C(243), UINT8_C( 13), UINT8_C(217), UINT8_C(124), UINT8_C( 50), UINT8_C(163), UINT8_C(239),
        UINT8_C( 82), UINT8_C(193), UINT8_C(172), UINT8_C( 41), UINT8_C(122), UINT8_C(113), UINT8_C(210), UINT8_C(127),
        UINT8_C( 47), UINT8_C(253), UINT8_C(175), UINT8_C(140), UINT8_C( 39), UINT8_C(127), UINT8_C(145), UINT8_C(155),
        UINT8_C(143), UINT8_C(189), UINT8_C( 74), UINT8_C(217), UINT8_C( 87), UINT8_C( 39), UINT8_C(147), UINT8_C(245),
        UINT8_C(224), UINT8_C(201), UINT8_C(173), UINT8_C(108), UINT8_C( 83), UINT8_C(110), UINT8_C(113), UINT8_C(113),
        UINT8_C(202), UINT8_C( 16), UINT8_C( 58), UINT8_C(112), UINT8_C(237), UINT8_C(225), UINT8_C( 67), UINT8_C(  8),
        UINT8_C(142), UINT8_C(252), UINT8_C(204), UINT8_C( 52), UINT8_C( 69), UINT8_C(158), UINT8_C(217), UINT8_C(181),
        UINT8_C(139), UINT8_C( 14), UINT8_C(227), UINT8_C(243), UINT8_C(143), UINT8_C( 70), UINT8_C( 78), UINT8_C( 16),
        UINT8_C(179), UINT8_C(156), UINT8_C( 78), UINT8_C(192), UINT8_C( 52), UINT8_C( 90), UINT8_C(145), UINT8_C(121),
        UINT8_C(177), UINT8_C(196), UINT8_C(  8), UINT8_C(219), UINT8_C(111), UINT8_C(199), UINT8_C(105), UINT8_C( 45),
        UINT8_C( 73), UINT8_C( 58), UINT8_C(141), UINT8_C(200), UINT8_C(104), UINT8_C(239), UINT8_C( 78), UINT8_C(252) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C( 66), UINT8_C(254), UINT8_C(116), UINT8_C(127),
        UINT8_C( 86), UINT8_C(111), UINT8_C( 66), UINT8_C(110), UINT8_C(121), UINT8_C(139), UINT8_C(157), UINT8_C(174),
        UINT8_C( 95), UINT8_C(152), UINT8_C(181), UINT8_C(  6), UINT8_C(153), UINT8_C( 98), UINT8_C(108), UINT8_C( 16),
        UINT8_C(209), UINT8_C(239), UINT8_C( 85), UINT8_C(215), UINT8_C( 53), UINT8_C(101), UINT8_C( 68), UINT8_C(120),
        UINT8_C(234), UINT8_C(230), UINT8_C(  1), UINT8_C(218), UINT8_C(254), UINT8_C( 15), UINT8_C(  7), UINT8_C(201),
        UINT8_C(111), UINT8_C(214), UINT8_C( 25), UINT8_C(129), UINT8_C(179), UINT8_C(177), UINT8_C(185), UINT8_C(  1),
        UINT8_C( 95), UINT8_C(185), UINT8_C(211), UINT8_C(249), UINT8_C( 85), UINT8_C(129), UINT8_C(108), UINT8_C(  7),
        UINT8_C(164), UINT8_C(127), UINT8_C(104), UINT8_C(203), UINT8_C(111), UINT8_C( 16), UINT8_C(194), UINT8_C( 51),
        UINT8_C(  2), UINT8_C( 59), UINT8_C( 60), UINT8_C(  4), UINT8_C( 82), UINT8_C( 41), UINT8_C( 23), UINT8_C( 25),
        UINT8_C(144), UINT8_C(214), UINT8_C( 25), UINT8_C(163), UINT8_C(220), UINT8_C(109), UINT8_C( 86), UINT8_C( 97),
        UINT8_C(193), UINT8_C( 83), UINT8_C(111), UINT8_C( 55), UINT8_C( 83), UINT8_C(105), UINT8_C( 99), UINT8_C(222),
           UINT8_MAX, UINT8_C( 19), UINT8_C( 89), UINT8_C( 35), UINT8_C(194), UINT8_C( 72), UINT8_C(193), UINT8_C(121),
        UINT8_C(167), UINT8_C(218), UINT8_C( 39), UINT8_C( 63), UINT8_C( 22), UINT8_C(140), UINT8_C( 42), UINT8_C(227),
        UINT8_C( 36), UINT8_C(209), UINT8_C(244), UINT8_C(  0), UINT8_C( 44), UINT8_C(194), UINT8_C(145), UINT8_C( 99),
        UINT8_C(190), UINT8_C(249), UINT8_C(181), UINT8_C(166), UINT8_C(206), UINT8_C( 75), UINT8_C(228), UINT8_C(109),
        UINT8_C(143), UINT8_C( 16), UINT8_C( 18), UINT8_C( 85), UINT8_C(132), UINT8_C(248), UINT8_C(219), UINT8_C( 29),
        UINT8_C(251), UINT8_C( 41), UINT8_C( 62), UINT8_C( 90), UINT8_C( 22), UINT8_C( 86), UINT8_C(229), UINT8_C(  1),
        UINT8_C(228), UINT8_C(155), UINT8_C(211), UINT8_C( 64), UINT8_C( 64), UINT8_C( 27), UINT8_C( 66), UINT8_C( 10),
        UINT8_C(164), UINT8_C( 98), UINT8_C(169), UINT8_C(191), UINT8_C( 70), UINT8_C( 97), UINT8_C( 27), UINT8_C(218),
        UINT8_C(212), UINT8_C( 82), UINT8_C(109), UINT8_C(214), UINT8_C(179), UINT8_C(211), UINT8_C( 89), UINT8_C(248),
        UINT8_C(177), UINT8_C(230), UINT8_C(184), UINT8_C(230), UINT8_C(156), UINT8_C( 60), UINT8_C(229), UINT8_C(225),
        UINT8_C(204), UINT8_C(225), UINT8_C( 36), UINT8_C(236), UINT8_C(126), UINT8_C(103), UINT8_C(195), UINT8_C( 89),
        UINT8_C(176), UINT8_C( 58), UINT8_C(211), UINT8_C( 78), UINT8_C(206), UINT8_C(108), UINT8_C(111), UINT8_C(140),
        UINT8_C(228), UINT8_C( 84), UINT8_C(192), UINT8_C( 59), UINT8_C( 24), UINT8_C( 43), UINT8_C(179), UINT8_C( 58),
        UINT8_C(165), UINT8_C(187), UINT8_C(251), UINT8_C(191), UINT8_C(116), UINT8_C(202), UINT8_C( 34), UINT8_C( 63),
        UINT8_C(147), UINT8_C( 25), UINT8_C(232), UINT8_C( 81), UINT8_C(253), UINT8_C(179), UINT8_C( 41), UINT8_C(102),
        UINT8_C(100), UINT8_C(104), UINT8_C(113), UINT8_C(187), UINT8_C(207), UINT8_C(174), UINT8_C(159), UINT8_C(158),
        UINT8_C(151), UINT8_C(223), UINT8_C(238), UINT8_C(224), UINT8_C(241), UINT8_C( 78), UINT8_C(140), UINT8_C( 67),
        UINT8_C(244), UINT8_C( 66), UINT8_C(135), UINT8_C(  7), UINT8_C(116), UINT8_C( 24), UINT8_C(203), UINT8_C( 83),
        UINT8_C(162), UINT8_C(231), UINT8_C(135), UINT8_C(225), UINT8_C(236), UINT8_C( 70), UINT8_C(  6), UINT8_C(236),
        UINT8_C( 94), UINT8_C(221), UINT8_C( 34), UINT8_C(199), UINT8_C( 78), UINT8_C(102), UINT8_C(100), UINT8_C(208) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  2),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX,    UINT8_MAX, UINT8_C(102),    UINT8_MAX, UINT8_C(118), UINT8_C(159),
           UINT8_MAX, UINT8_C(141),    UINT8_MAX,    UINT8_MAX, UINT8_C(175),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(142),    UINT8_MAX,    UINT8_MAX, UINT8_C(210), UINT8_C(231),    UINT8_MAX,    UINT8_MAX, UINT8_C( 47),
           UINT8_MAX,    UINT8_MAX, UINT8_C(216),    UINT8_MAX, UINT8_C(241), UINT8_C(210), UINT8_C(111),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(126),    UINT8_MAX,    UINT8_MAX, UINT8_C( 78), UINT8_C(118),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(226), UINT8_C(157),    UINT8_MAX, UINT8_C(237),    UINT8_MAX, UINT8_C(237),
        UINT8_C(208),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(201),    UINT8_MAX,    UINT8_MAX, UINT8_C( 64),
           UINT8_MAX, UINT8_C(154),    UINT8_MAX,    UINT8_MAX, UINT8_C(230), UINT8_C( 72), UINT8_C(251), UINT8_C(177),
        UINT8_C(159), UINT8_C( 74), UINT8_C(232), UINT8_C( 26),    UINT8_MAX, UINT8_C(194), UINT8_C(130), UINT8_C( 32),
           UINT8_MAX,    UINT8_MAX, UINT8_C( 26),    UINT8_MAX,    UINT8_MAX, UINT8_C(201),    UINT8_MAX, UINT8_C(110),
           UINT8_MAX, UINT8_C(150), UINT8_C(205), UINT8_C(147), UINT8_C( 87), UINT8_C(224), UINT8_C(247),    UINT8_MAX,
           UINT8_MAX, UINT8_C( 95),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(177),    UINT8_MAX, UINT8_C(186),
        UINT8_C(229),    UINT8_MAX, UINT8_C(126), UINT8_C(204), UINT8_C(179), UINT8_C(181),    UINT8_MAX,    UINT8_MAX,
        UINT8_C( 95),    UINT8_MAX,    UINT8_MAX, UINT8_C(206), UINT8_C(252),    UINT8_MAX, UINT8_C(217),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(252),    UINT8_MAX,    UINT8_MAX, UINT8_C(254), UINT8_C(238),
           UINT8_MAX, UINT8_C(144), UINT8_C(105), UINT8_C(217), UINT8_C(179),    UINT8_MAX,    UINT8_MAX, UINT8_C(110),
           UINT8_MAX,    UINT8_MAX, UINT8_C(229),    UINT8_MAX, UINT8_C(125), UINT8_C(230),    UINT8_MAX, UINT8_C( 18),
           UINT8_MAX, UINT8_C(161),    UINT8_MAX,    UINT8_MAX, UINT8_C(161), UINT8_C( 34), UINT8_C(198), UINT8_C(254),
           UINT8_MAX, UINT8_C(189),    UINT8_MAX,    UINT8_MAX, UINT8_C(120),    UINT8_MAX, UINT8_C( 54),    UINT8_MAX,
        UINT8_C(238), UINT8_C(233), UINT8_C(235), UINT8_C(226),    UINT8_MAX, UINT8_C(219), UINT8_C(174),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(197),    UINT8_MAX,    UINT8_MAX, UINT8_C(110),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(208),    UINT8_MAX, UINT8_C(248), UINT8_C(216),    UINT8_MAX, UINT8_C(216),
        UINT8_C(223),    UINT8_MAX,    UINT8_MAX, UINT8_C(218), UINT8_C(245), UINT8_C(235),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(111), UINT8_C( 82),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(199),    UINT8_MAX, UINT8_C(147), UINT8_C(176),
           UINT8_MAX, UINT8_C( 41),    UINT8_MAX, UINT8_C(193),    UINT8_MAX,    UINT8_MAX, UINT8_C(108), UINT8_C(110),
        UINT8_C(242),    UINT8_MAX,    UINT8_MAX, UINT8_C(239),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(237),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(148), UINT8_C(218), UINT8_C( 83),
           UINT8_MAX, UINT8_C(222), UINT8_C(213), UINT8_C(199), UINT8_C(168), UINT8_C(114),    UINT8_MAX, UINT8_C(204),
           UINT8_MAX,    UINT8_MAX, UINT8_C(143),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(111),    UINT8_MAX,
        UINT8_C(167),    UINT8_MAX, UINT8_C(175),    UINT8_MAX, UINT8_C(182),    UINT8_MAX, UINT8_C(178),    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wub_vadd_WubWub_sat(a, b);

    simde_test_hvx_vectorpair_u8_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_u8_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_u8_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wub_vadd_WubWub_sat(a, b);

    simde_test_hvx_vectorpair_u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_u8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_u8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_WuhWuh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[SIMDE_HVX_PAIR_I16_COUNT];
    uint16_t b[SIMDE_HVX_PAIR_I16_COUNT];
    uint16_t r[SIMDE_HVX_PAIR_I16_COUNT];
  } test_vec[] = {
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(56238), UINT16_C(53527), UINT16_C(51896), UINT16_C(65163),
        UINT16_C(43768), UINT16_C(35062), UINT16_C(50346), UINT16_C(29860), UINT16_C(20065), UINT16_C(30494), UINT16_C( 1830), UINT16_C(39925),
        UINT16_C(55814), UINT16_C(59696), UINT16_C(41787), UINT16_C(34255), UINT16_C(50351), UINT16_C(40132), UINT16_C(33570), UINT16_C( 4248),
        UINT16_C(63273), UINT16_C(54999), UINT16_C(54317), UINT16_C(41729), UINT16_C(10186), UINT16_C(29467), UINT16_C(14199), UINT16_C(32199),
        UINT16_C(  855), UINT16_C(33855), UINT16_C( 3344), UINT16_C(30980), UINT16_C(24667), UINT16_C(36108), UINT16_C(42519), UINT16_C(28390),
        UINT16_C(48881), UINT16_C(50492), UINT16_C(24886), UINT16_C(52631), UINT16_C(61905), UINT16_C( 3489), UINT16_C(15805), UINT16_C(21732),
        UINT16_C( 9048), UINT16_C(55370), UINT16_C(47246), UINT16_C(20284), UINT16_C(44583), UINT16_C(29681), UINT16_C(13273), UINT16_C(62530),
        UINT16_C(50630), UINT16_C(38179), UINT16_C(31892), UINT16_C( 2905), UINT16_C(10413), UINT16_C(34109), UINT16_C(29291), UINT16_C(18472),
        UINT16_C(39910), UINT16_C(26441), UINT16_C( 8166), UINT16_C( 7974), UINT16_C(11346), UINT16_C(50369), UINT16_C( 2606), UINT16_C(24587),
        UINT16_C(42153), UINT16_C(41714), UINT16_C(54515), UINT16_C( 6371), UINT16_C(64737), UINT16_C(64685), UINT16_C(41129), UINT16_C(44639),
        UINT16_C(  217), UINT16_C(44528), UINT16_C( 7241), UINT16_C(38888), UINT16_C(40903), UINT16_C(26572), UINT16_C(27807), UINT16_C(19924),
        UINT16_C(59368), UINT16_C(33023), UINT16_C(36868), UINT16_C(40437), UINT16_C(57040), UINT16_C(60761), UINT16_C(15192), UINT16_C(49320),
        UINT16_C( 1152), UINT16_C(65280), UINT16_C(31700), UINT16_C( 4957), UINT16_C(25961), UINT16_C(61833), UINT16_C(62281), UINT16_C(41344),
        UINT16_C(49230), UINT16_C(41384), UINT16_C(44327), UINT16_C( 2677), UINT16_C(35286), UINT16_C(14648), UINT16_C( 8349), UINT16_C(52307),
        UINT16_C(58767), UINT16_C(62230), UINT16_C( 8177), UINT16_C(11221), UINT16_C(14576), UINT16_C(27725), UINT16_C( 3099), UINT16_C(32482) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(33089), UINT16_C(38774), UINT16_C(62626), UINT16_C(48348),
        UINT16_C(46327), UINT16_C( 4652), UINT16_C(49634), UINT16_C(41346), UINT16_C(22903), UINT16_C(55663), UINT16_C( 8305), UINT16_C(10422),
        UINT16_C(55326), UINT16_C( 8546), UINT16_C(11784), UINT16_C(47687), UINT16_C( 7233), UINT16_C(44059), UINT16_C(13392), UINT16_C(54525),
        UINT16_C(26936), UINT16_C(21082), UINT16_C( 2164), UINT16_C(60296), UINT16_C(52084), UINT16_C(61186), UINT16_C(34899), UINT16_C(19413),
        UINT16_C(54477), UINT16_C(14945), UINT16_C(41991), UINT16_C(50395), UINT16_C(43053), UINT16_C(41021), UINT16_C(39231), UINT16_C(23203),
        UINT16_C(48520), UINT16_C(31592), UINT16_C(34265), UINT16_C(33898), UINT16_C(13814), UINT16_C(28059), UINT16_C(52480), UINT16_C(62051),
        UINT16_C(54703), UINT16_C(63506), UINT16_C(11505), UINT16_C(13731), UINT16_C(20084), UINT16_C(59504), UINT16_C(45181), UINT16_C(60310),
        UINT16_C(40162), UINT16_C(23846), UINT16_C(12056), UINT16_C(36407), UINT16_C(60428), UINT16_C(51093), UINT16_C(16976), UINT16_C(21553),
        UINT16_C(35464), UINT16_C(30970), UINT16_C( 5195), UINT16_C(64229), UINT16_C( 3850), UINT16_C(48402), UINT16_C(49872), UINT16_C(41769),
        UINT16_C( 5516), UINT16_C(63298), UINT16_C(29260), UINT16_C(25497), UINT16_C(20679), UINT16_C(27130), UINT16_C(34056), UINT16_C(28413),
        UINT16_C(11724), UINT16_C(59093), UINT16_C(56529), UINT16_C(11859), UINT16_C(36931), UINT16_C(56308), UINT16_C(20478), UINT16_C( 3291),
        UINT16_C(35275), UINT16_C(39896), UINT16_C( 2767), UINT16_C(59228), UINT16_C(22992), UINT16_C(13040), UINT16_C(46817), UINT16_C(47052),
        UINT16_C(28446), UINT16_C(25313), UINT16_C(54372), UINT16_C(12623), UINT16_C(24359), UINT16_C(51340), UINT16_C( 1939), UINT16_C(39026),
        UINT16_C(21274), UINT16_C(37247), UINT16_C(25312), UINT16_C(23142), UINT16_C(42116), UINT16_C(32423), UINT16_C(13325), UINT16_C(21966),
        UINT16_C(57920), UINT16_C(25522), UINT16_C(13674), UINT16_C(14244), UINT16_C(50759), UINT16_C(38305), UINT16_C(18217), UINT16_C(36252) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    2),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX, UINT16_C(39714),      UINT16_MAX,      UINT16_MAX, UINT16_C(42968),      UINT16_MAX, UINT16_C(10135), UINT16_C(50347),
             UINT16_MAX,      UINT16_MAX, UINT16_C(53571),      UINT16_MAX, UINT16_C(57584),      UINT16_MAX, UINT16_C(46962), UINT16_C(58773),
             UINT16_MAX,      UINT16_MAX, UINT16_C(56481),      UINT16_MAX, UINT16_C(62270),      UINT16_MAX, UINT16_C(49098), UINT16_C(51612),
        UINT16_C(55332), UINT16_C(48800), UINT16_C(45335),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(51593),
             UINT16_MAX,      UINT16_MAX, UINT16_C(59151),      UINT16_MAX,      UINT16_MAX, UINT16_C(31548),      UINT16_MAX,      UINT16_MAX,
        UINT16_C(63751),      UINT16_MAX, UINT16_C(58751), UINT16_C(34015), UINT16_C(64667),      UINT16_MAX, UINT16_C(58454),      UINT16_MAX,
             UINT16_MAX, UINT16_C(62025), UINT16_C(43948), UINT16_C(39312),      UINT16_MAX,      UINT16_MAX, UINT16_C(46267), UINT16_C(40025),
             UINT16_MAX, UINT16_C(57411), UINT16_C(13361),      UINT16_MAX, UINT16_C(15196),      UINT16_MAX, UINT16_C(52478),      UINT16_MAX,
        UINT16_C(47669),      UINT16_MAX,      UINT16_MAX, UINT16_C(31868),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
        UINT16_C(11941),      UINT16_MAX, UINT16_C(63770), UINT16_C(50747),      UINT16_MAX,      UINT16_MAX, UINT16_C(48285), UINT16_C(23215),
             UINT16_MAX,      UINT16_MAX, UINT16_C(39635),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(62009),      UINT16_MAX,
        UINT16_C(29598),      UINT16_MAX,      UINT16_MAX, UINT16_C(17580), UINT16_C(50320),      UINT16_MAX, UINT16_C(64220),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(25819),      UINT16_MAX, UINT16_C(47071), UINT16_C(21674),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX, UINT16_C(21851), UINT16_C(25465), UINT16_C(65335),      UINT16_MAX, UINT16_C(21316),      UINT16_MAX } },
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C( 3868), UINT16_C( 8576), UINT16_C( 5168), UINT16_C(31758),
        UINT16_C(51122), UINT16_C(43421), UINT16_C(62082), UINT16_C(19442), UINT16_C(21456), UINT16_C(64882), UINT16_C(46134), UINT16_C(14757),
        UINT16_C( 4088), UINT16_C(21475), UINT16_C(52991), UINT16_C(18339), UINT16_C(21972), UINT16_C(56995), UINT16_C(38193), UINT16_C(12837),
        UINT16_C( 6641), UINT16_C(57142), UINT16_C(36327), UINT16_C(33735), UINT16_C(32350), UINT16_C(25738), UINT16_C(17081), UINT16_C(62842),
        UINT16_C( 5742), UINT16_C(23632), UINT16_C(64419), UINT16_C( 5306), UINT16_C(51378), UINT16_C( 4327), UINT16_C( 3739), UINT16_C(11775),
        UINT16_C(58141), UINT16_C(21436), UINT16_C(57931), UINT16_C(17161), UINT16_C( 2864), UINT16_C(14536), UINT16_C(11565), UINT16_C(56507),
        UINT16_C(16612), UINT16_C(25785), UINT16_C(13620), UINT16_C( 4611), UINT16_C(32990), UINT16_C(37942), UINT16_C(23301), UINT16_C(35874),
        UINT16_C(62074), UINT16_C( 9364), UINT16_C(35755), UINT16_C(30365), UINT16_C(58605), UINT16_C(58392), UINT16_C(33678), UINT16_C(61938),
        UINT16_C(19136), UINT16_C(58095), UINT16_C(22856), UINT16_C(50200), UINT16_C(49856), UINT16_C( 9145), UINT16_C(61174), UINT16_C(34452),
        UINT16_C(36944), UINT16_C(46965), UINT16_C(29526), UINT16_C(55297), UINT16_C(24051), UINT16_C(56715), UINT16_C(30208), UINT16_C(39308),
        UINT16_C(54997), UINT16_C(29302), UINT16_C(21482), UINT16_C(29177), UINT16_C(52438), UINT16_C( 4230), UINT16_C(17454), UINT16_C(22910),
        UINT16_C(45210), UINT16_C(56062), UINT16_C(43787), UINT16_C(17353), UINT16_C(46324), UINT16_C(10696), UINT16_C(37073), UINT16_C(19255),
        UINT16_C(21210), UINT16_C(49355), UINT16_C(45949), UINT16_C(15948), UINT16_C( 9482), UINT16_C(37584), UINT16_C(58989), UINT16_C(49227),
        UINT16_C(38727), UINT16_C(27839), UINT16_C(51881), UINT16_C(35485), UINT16_C( 9737), UINT16_C(24056), UINT16_C(29698), UINT16_C(49600),
        UINT16_C(26462), UINT16_C(58166), UINT16_C(52516), UINT16_C(48156), UINT16_C(24715), UINT16_C(32914), UINT16_C(57269), UINT16_C(58691) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(27682), UINT16_C(39365), UINT16_C(48151), UINT16_C(54193),
        UINT16_C(64747), UINT16_C(58319), UINT16_C(19731), UINT16_C( 8682), UINT16_C(60140), UINT16_C(17796), UINT16_C(31914), UINT16_C(62976),
        UINT16_C( 7860), UINT16_C( 2247), UINT16_C(24806), UINT16_C(11847), UINT16_C(24074), UINT16_C(18183), UINT16_C( 1018), UINT16_C(27002),
        UINT16_C(44115), UINT16_C(32394), UINT16_C(42248), UINT16_C(17682), UINT16_C(64198), UINT16_C( 7212), UINT16_C(59995), UINT16_C(21452),
        UINT16_C(62104), UINT16_C(57277), UINT16_C(15013), UINT16_C(38754), UINT16_C(48967), UINT16_C(57299), UINT16_C(11995), UINT16_C(53570),
        UINT16_C(24557), UINT16_C(47861), UINT16_C( 1288), UINT16_C( 4384), UINT16_C(13947), UINT16_C(42430), UINT16_C(44657), UINT16_C(38112),
        UINT16_C( 6542), UINT16_C(32394), UINT16_C(17681), UINT16_C(17015), UINT16_C(20350), UINT16_C(25894), UINT16_C(11163), UINT16_C(27657),
        UINT16_C(33543), UINT16_C(50374), UINT16_C(27337), UINT16_C(63381), UINT16_C(57862), UINT16_C(65142), UINT16_C(21454), UINT16_C(20027),
        UINT16_C( 8035), UINT16_C(29201), UINT16_C(45205), UINT16_C( 1334), UINT16_C(22856), UINT16_C(53431), UINT16_C(20550), UINT16_C(19530),
        UINT16_C(23720), UINT16_C(10112), UINT16_C(64903), UINT16_C(54144), UINT16_C(65496), UINT16_C(26925), UINT16_C(23733), UINT16_C( 3001),
        UINT16_C(51973), UINT16_C(35929), UINT16_C(36680), UINT16_C( 5548), UINT16_C(30735), UINT16_C(52382), UINT16_C(56148), UINT16_C( 8856),
        UINT16_C(12359), UINT16_C(61442), UINT16_C(58410), UINT16_C(15358), UINT16_C(55144), UINT16_C(52682), UINT16_C(32713), UINT16_C(65392),
        UINT16_C( 2561), UINT16_C(49118), UINT16_C(29904), UINT16_C( 7046), UINT16_C(58464), UINT16_C(65420), UINT16_C(60278), UINT16_C(46017),
        UINT16_C(61185), UINT16_C(20889), UINT16_C(41971), UINT16_C(20280), UINT16_C(  847), UINT16_C(48688), UINT16_C(25497), UINT16_C(16013),
        UINT16_C(23411), UINT16_C(34400), UINT16_C(35532), UINT16_C(50890), UINT16_C(16324), UINT16_C(51570), UINT16_C(64729), UINT16_C(52331) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    2),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX,      UINT16_MAX, UINT16_C(31550), UINT16_C(47941), UINT16_C(53319),      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(28124),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
        UINT16_C(11948), UINT16_C(23722),      UINT16_MAX, UINT16_C(30186), UINT16_C(46046),      UINT16_MAX, UINT16_C(39211), UINT16_C(39839),
        UINT16_C(50756),      UINT16_MAX,      UINT16_MAX, UINT16_C(51417),      UINT16_MAX, UINT16_C(32950),      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(44060),      UINT16_MAX, UINT16_C(61626), UINT16_C(15734), UINT16_C(65345),
             UINT16_MAX,      UINT16_MAX, UINT16_C(59219), UINT16_C(21545), UINT16_C(16811), UINT16_C(56966), UINT16_C(56222),      UINT16_MAX,
        UINT16_C(23154), UINT16_C(58179), UINT16_C(31301), UINT16_C(21626), UINT16_C(53340), UINT16_C(63836), UINT16_C(34464), UINT16_C(63531),
             UINT16_MAX, UINT16_C(59738), UINT16_C(63092),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(55132),      UINT16_MAX,
        UINT16_C(27171),      UINT16_MAX,      UINT16_MAX, UINT16_C(51534),      UINT16_MAX, UINT16_C(62576),      UINT16_MAX, UINT16_C(53982),
        UINT16_C(60664), UINT16_C(57077),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(53941), UINT16_C(42309),
             UINT16_MAX, UINT16_C(65231), UINT16_C(58162), UINT16_C(34725),      UINT16_MAX, UINT16_C(56612),      UINT16_MAX, UINT16_C(31766),
        UINT16_C(57569),      UINT16_MAX,      UINT16_MAX, UINT16_C(32711),      UINT16_MAX, UINT16_C(63378),      UINT16_MAX,      UINT16_MAX,
        UINT16_C(23771),      UINT16_MAX,      UINT16_MAX, UINT16_C(22994),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,
             UINT16_MAX, UINT16_C(48728),      UINT16_MAX, UINT16_C(55765), UINT16_C(10584),      UINT16_MAX, UINT16_C(55195),      UINT16_MAX,
        UINT16_C(49873),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(41039),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wuh_vadd_WuhWuh_sat(a, b);

    simde_test_hvx_vectorpair_u16_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_u16_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_u16_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wuh_vadd_WuhWuh_sat(a, b);

    simde_test_hvx_vectorpair_u16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_u16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_u16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_WuwWuw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[SIMDE_HVX_PAIR_I32_COUNT];
    uint32_t b[SIMDE_HVX_PAIR_I32_COUNT];
    uint32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1), UINT32_C( 738264149), UINT32_C(3564511329), UINT32_C(1607634018), UINT32_C( 407322301),
        UINT32_C(2388272957), UINT32_C(1838740539), UINT32_C(3292681930), UINT32_C(2563139019), UINT32_C( 473363592), UINT32_C(3732007598), UINT32_C(1873209896), UINT32_C(2459076493),
        UINT32_C(2092089875), UINT32_C(1396563313), UINT32_C(1290984366), UINT32_C(4238803674), UINT32_C( 129136680), UINT32_C(2180657447), UINT32_C(2802001227), UINT32_C(2219734861),
        UINT32_C(1995926750), UINT32_C(2718435276), UINT32_C(2587890927), UINT32_C(4156239516), UINT32_C(1462151974), UINT32_C(2778085581), UINT32_C(4259859286), UINT32_C(2569604168),
        UINT32_C(3963101991), UINT32_C( 341546806), UINT32_C(2072867785), UINT32_C(4195385135), UINT32_C(3454024270), UINT32_C( 773978752), UINT32_C( 892801886), UINT32_C(3085108083),
        UINT32_C(3948298142), UINT32_C(3113978241), UINT32_C(2076248380), UINT32_C(3135346764), UINT32_C(1729777857), UINT32_C( 151768302), UINT32_C( 601434964), UINT32_C(1835848238),
        UINT32_C(3138918993), UINT32_C(3224571147), UINT32_C(3895824416), UINT32_C(1618665937), UINT32_C(3217687528), UINT32_C(3239670511), UINT32_C(1886715611), UINT32_C(3917882771) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),
        UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C( 174399675), UINT32_C(4250249972), UINT32_C(4184837693), UINT32_C(1068983920),
        UINT32_C(3515346799), UINT32_C(2473360321), UINT32_C(1711475049), UINT32_C(1514142073), UINT32_C(3358328412), UINT32_C(3664245309), UINT32_C(2196310130), UINT32_C( 469107491),
        UINT32_C(3312516489), UINT32_C(3519920325), UINT32_C( 616136070), UINT32_C(1405368919), UINT32_C( 608031499), UINT32_C(3932696306), UINT32_C( 158321693), UINT32_C( 701756934),
        UINT32_C(3510774327), UINT32_C(1774255342), UINT32_C(2615610140), UINT32_C(3624268384), UINT32_C( 567800223), UINT32_C(3983569254), UINT32_C(1141796478), UINT32_C(1894884453),
        UINT32_C( 206892610), UINT32_C(3115853721), UINT32_C(3812120055), UINT32_C(  33393489), UINT32_C( 844083841), UINT32_C( 820667144), UINT32_C(3475734804), UINT32_C(3355052654),
        UINT32_C(1045262673), UINT32_C( 102943552), UINT32_C(3998479197), UINT32_C(3251720378), UINT32_C( 492716071), UINT32_C(2815088199), UINT32_C(1839982578), UINT32_C(1220720374),
        UINT32_C(2251045157), UINT32_C(1416398369), UINT32_C(2227929381), UINT32_C( 380383366), UINT32_C(1643120391), UINT32_C(2018830841), UINT32_C(3500906391), UINT32_C(1155940541) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         2),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX,           UINT32_MAX, UINT32_C( 912663824),           UINT32_MAX,           UINT32_MAX, UINT32_C(1476306221),
                  UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(4077281092), UINT32_C(3831692004),           UINT32_MAX, UINT32_C(4069520026), UINT32_C(2928183984),
                  UINT32_MAX,           UINT32_MAX, UINT32_C(1907120436),           UINT32_MAX, UINT32_C( 737168179),           UINT32_MAX, UINT32_C(2960322920), UINT32_C(2921491795),
                  UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(2029952197),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
        UINT32_C(4169994601), UINT32_C(3457400527),           UINT32_MAX, UINT32_C(4228778624),           UINT32_MAX, UINT32_C(1594645896),           UINT32_MAX,           UINT32_MAX,
                  UINT32_MAX, UINT32_C(3216921793),           UINT32_MAX,           UINT32_MAX, UINT32_C(2222493928), UINT32_C(2966856501), UINT32_C(2441417542), UINT32_C(3056568612),
                  UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(1999049303),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1), UINT32_C(1269379239), UINT32_C(3454401541), UINT32_C(1277720794), UINT32_C(1020525285),
        UINT32_C(1758775431), UINT32_C(2994707903), UINT32_C(1888086913), UINT32_C(2398178232), UINT32_C(4209996559), UINT32_C(3668220852), UINT32_C( 956445984), UINT32_C(1985211884),
        UINT32_C( 579691052), UINT32_C(2938062112), UINT32_C(2236088477), UINT32_C(1019988148), UINT32_C(1444282992), UINT32_C(4219260878), UINT32_C(2565697197), UINT32_C( 324780177),
        UINT32_C(3466566186), UINT32_C(2674344778), UINT32_C(1153283813), UINT32_C(1082645860), UINT32_C(3182187587), UINT32_C(2212249018), UINT32_C(2663905333), UINT32_C( 859831779),
        UINT32_C(3916047434), UINT32_C(1067250632), UINT32_C(3533414261), UINT32_C( 432900067), UINT32_C( 332079695), UINT32_C(4017878067), UINT32_C(2150957921), UINT32_C(1616290314),
        UINT32_C(3088628718), UINT32_C(3472178556), UINT32_C(1091280027), UINT32_C(3077143894), UINT32_C(2825671968), UINT32_C(4120119340), UINT32_C(2984011047), UINT32_C(4279833099),
        UINT32_C(4037201734), UINT32_C(3751996226), UINT32_C(2560157931), UINT32_C(2988962166), UINT32_C(2637131512), UINT32_C( 430486327), UINT32_C(2836030370), UINT32_C(1153275412) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),           UINT32_MAX, UINT32_C(         1),
        UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(4217328827), UINT32_C(3356258520), UINT32_C(3995777626), UINT32_C(3464944080),
        UINT32_C(3538081796), UINT32_C( 614669109), UINT32_C(2899129807), UINT32_C(2305974713), UINT32_C( 682616449), UINT32_C(2389151060), UINT32_C( 372764687), UINT32_C( 275902999),
        UINT32_C(2152243383), UINT32_C(1952420740), UINT32_C( 649308523), UINT32_C(3090316704), UINT32_C(2164931183), UINT32_C(2412907256), UINT32_C(3269628820), UINT32_C(1518816410),
        UINT32_C(3353934253), UINT32_C(4119213788), UINT32_C( 972187263), UINT32_C(3700657362), UINT32_C(2064488038), UINT32_C(1926290434), UINT32_C(1720810959), UINT32_C(2811386602),
        UINT32_C(1240502388), UINT32_C(2230166202), UINT32_C(3573853749), UINT32_C(2595020169), UINT32_C( 744020298), UINT32_C(2670213687), UINT32_C(2414885717), UINT32_C(4082424041),
        UINT32_C(2345235428), UINT32_C( 425120038), UINT32_C(4048710818), UINT32_C(2763150657), UINT32_C( 820144505), UINT32_C(1394097614), UINT32_C( 522212799), UINT32_C(2930229904),
        UINT32_C(2502539872), UINT32_C(2557508703), UINT32_C(2367699673), UINT32_C(3855557952), UINT32_C( 113483460), UINT32_C( 790623189), UINT32_C( 392437122), UINT32_C(2938097203) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         2),
                  UINT32_MAX, UINT32_C(         1),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                  UINT32_MAX, UINT32_C(3609377012),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(1329210671), UINT32_C(2261114883),
        UINT32_C(2731934435),           UINT32_MAX, UINT32_C(2885397000), UINT32_C(4110304852), UINT32_C(3609214175),           UINT32_MAX,           UINT32_MAX, UINT32_C(1843596587),
                  UINT32_MAX,           UINT32_MAX, UINT32_C(2125471076),           UINT32_MAX,           UINT32_MAX, UINT32_C(4138539452),           UINT32_MAX, UINT32_C(3671218381),
                  UINT32_MAX, UINT32_C(3297416834),           UINT32_MAX, UINT32_C(3027920236), UINT32_C(1076099993),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,
                  UINT32_MAX, UINT32_C(3897298594),           UINT32_MAX,           UINT32_MAX, UINT32_C(3645816473),           UINT32_MAX, UINT32_C(3506223846),           UINT32_MAX,
                  UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(2750614972), UINT32_C(1221109516), UINT32_C(3228467492), UINT32_C(4091372615) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wuw_vadd_WuwWuw_sat(a, b);

    simde_test_hvx_vectorpair_u32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_u32_random(0);
    simde_hvx_vectorpair_t b = simde_test_hvx_vectorpair_u32_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wuw_vadd_WuwWuw_sat(a, b);

    simde_test_hvx_vectorpair_u32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vectorpair_u32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_u32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VubVub(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[SIMDE_HVX_VECTOR_SIZE];
    uint8_t b[SIMDE_HVX_VECTOR_SIZE];
    int16_t r[SIMDE_HVX_PAIR_I16_COUNT];
  } test_vec[] = {
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(157), UINT8_C( 12), UINT8_C(135), UINT8_C( 59),
        UINT8_C(230), UINT8_C(171), UINT8_C(135), UINT8_C(251), UINT8_C( 27), UINT8_C(  4), UINT8_C( 53), UINT8_C( 76),
        UINT8_C( 71), UINT8_C(248), UINT8_C( 81), UINT8_C(211), UINT8_C( 77), UINT8_C(110), UINT8_C( 38), UINT8_C(167),
        UINT8_C(104), UINT8_C(155), UINT8_C(167), UINT8_C( 20), UINT8_C(159), UINT8_C(120), UINT8_C(143), UINT8_C(244),
        UINT8_C(  5), UINT8_C(183), UINT8_C(175), UINT8_C( 16), UINT8_C(200), UINT8_C(  9), UINT8_C(145), UINT8_C(167),
        UINT8_C(120), UINT8_C( 10), UINT8_C(251), UINT8_C(132), UINT8_C(146), UINT8_C(195), UINT8_C(140), UINT8_C(210),
        UINT8_C(190), UINT8_C( 40), UINT8_C(126), UINT8_C(211), UINT8_C(197), UINT8_C( 66), UINT8_C(156), UINT8_C( 20),
        UINT8_C( 71), UINT8_C(164), UINT8_C( 51), UINT8_C(241), UINT8_C(  8), UINT8_C( 26), UINT8_C(136), UINT8_C(164),
        UINT8_C(243), UINT8_C(125), UINT8_C(168), UINT8_C( 70), UINT8_C(143), UINT8_C(159), UINT8_C( 61), UINT8_C(  0),
        UINT8_C(109), UINT8_C(106), UINT8_C(123), UINT8_C( 42), UINT8_C( 60), UINT8_C(209), UINT8_C(208), UINT8_C(  7),
        UINT8_C(251), UINT8_C( 24), UINT8_C(176), UINT8_C(250), UINT8_C(180), UINT8_C( 27), UINT8_C(245), UINT8_C(179),
        UINT8_C(195), UINT8_C(201), UINT8_C(189), UINT8_C( 43), UINT8_C(205), UINT8_C( 14), UINT8_C(155), UINT8_C(  7),
        UINT8_C( 77), UINT8_C( 25), UINT8_C(241), UINT8_C( 32), UINT8_C(167), UINT8_C(137), UINT8_C( 77), UINT8_C( 38),
        UINT8_C(  3), UINT8_C( 20), UINT8_C(197), UINT8_C(230), UINT8_C(142), UINT8_C( 50), UINT8_C(229), UINT8_C(226),
        UINT8_C( 73), UINT8_C( 39), UINT8_C(142), UINT8_C( 83), UINT8_C(173), UINT8_C(113), UINT8_C(219), UINT8_C(116) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(180), UINT8_C(251), UINT8_C( 88), UINT8_C(183),
        UINT8_C( 63), UINT8_C(219), UINT8_C( 65), UINT8_C(  8), UINT8_C( 87), UINT8_C(237), UINT8_C( 37), UINT8_C( 31),
        UINT8_C(128), UINT8_C(245), UINT8_C(203), UINT8_C( 84), UINT8_C(131), UINT8_C( 94), UINT8_C( 72), UINT8_C(237),
        UINT8_C(210), UINT8_C( 90), UINT8_C( 59), UINT8_C( 81), UINT8_C( 68), UINT8_C( 57), UINT8_C(112), UINT8_C(199),
        UINT8_C( 10), UINT8_C( 62), UINT8_C(158), UINT8_C(222), UINT8_C(203), UINT8_C( 87), UINT8_C(167), UINT8_C( 63),
        UINT8_C(226), UINT8_C(134), UINT8_C(217), UINT8_C(152), UINT8_C( 40), UINT8_C( 34), UINT8_C( 35), UINT8_C(213),
        UINT8_C(224), UINT8_C( 42), UINT8_C(216), UINT8_C(160), UINT8_C(145), UINT8_C( 29), UINT8_C( 44), UINT8_C( 77),
        UINT8_C(131), UINT8_C( 76), UINT8_C( 82), UINT8_C( 70), UINT8_C( 18), UINT8_C(217), UINT8_C(101), UINT8_C( 83),
        UINT8_C(  2), UINT8_C( 43), UINT8_C(112), UINT8_C(216), UINT8_C(126), UINT8_C(107), UINT8_C(148), UINT8_C(235),
        UINT8_C(223), UINT8_C(184), UINT8_C( 65), UINT8_C( 58), UINT8_C( 62), UINT8_C(171), UINT8_C(229), UINT8_C(130),
        UINT8_C(102), UINT8_C(195), UINT8_C( 16), UINT8_C( 74), UINT8_C(130), UINT8_C(  0), UINT8_C(131), UINT8_C(207),
           UINT8_MAX, UINT8_C( 61), UINT8_C( 77), UINT8_C(113), UINT8_C( 69), UINT8_C(214), UINT8_C( 85), UINT8_C( 22),
        UINT8_C( 60), UINT8_C( 75), UINT8_C(200), UINT8_C( 42), UINT8_C( 97), UINT8_C( 47), UINT8_C(106), UINT8_C(192),
        UINT8_C( 85), UINT8_C( 95), UINT8_C(199), UINT8_C(144), UINT8_C(225), UINT8_C( 48), UINT8_C(165), UINT8_C(166),
        UINT8_C(161), UINT8_C(222), UINT8_C(108), UINT8_C(152), UINT8_C(149), UINT8_C(239), UINT8_C(253), UINT8_C(173) },
      {  INT16_C(     0),  INT16_C(   255),  INT16_C(   255),  INT16_C(   255),  INT16_C(   255),  INT16_C(   510),  INT16_C(   337),  INT16_C(   223),
         INT16_C(   293),  INT16_C(   200),  INT16_C(   114),  INT16_C(    90),  INT16_C(   199),  INT16_C(   284),  INT16_C(   208),  INT16_C(   110),
         INT16_C(   314),  INT16_C(   226),  INT16_C(   227),  INT16_C(   255),  INT16_C(    15),  INT16_C(   333),  INT16_C(   403),  INT16_C(   312),
         INT16_C(   346),  INT16_C(   468),  INT16_C(   186),  INT16_C(   175),  INT16_C(   414),  INT16_C(   342),  INT16_C(   342),  INT16_C(   200),
         INT16_C(   202),  INT16_C(   133),  INT16_C(    26),  INT16_C(   237),  INT16_C(   245),  INT16_C(   280),  INT16_C(   269),  INT16_C(   209),
         INT16_C(   332),  INT16_C(   188),  INT16_C(   122),  INT16_C(   437),  INT16_C(   353),  INT16_C(   192),  INT16_C(   310),  INT16_C(   376),
         INT16_C(   450),  INT16_C(   266),  INT16_C(   274),  INT16_C(   240),  INT16_C(   137),  INT16_C(   441),  INT16_C(   264),  INT16_C(   183),
         INT16_C(    88),  INT16_C(   396),  INT16_C(   367),  INT16_C(   394),  INT16_C(   234),  INT16_C(   250),  INT16_C(   322),  INT16_C(   472),
         INT16_C(   255),  INT16_C(   256),  INT16_C(   256),  INT16_C(     2),  INT16_C(     1),  INT16_C(   256),  INT16_C(   263),  INT16_C(   242),
         INT16_C(   390),  INT16_C(   259),  INT16_C(   241),  INT16_C(   107),  INT16_C(   493),  INT16_C(   295),  INT16_C(   204),  INT16_C(   404),
         INT16_C(   245),  INT16_C(   101),  INT16_C(   177),  INT16_C(   443),  INT16_C(   245),  INT16_C(   238),  INT16_C(    96),  INT16_C(   230),
         INT16_C(   144),  INT16_C(   284),  INT16_C(   229),  INT16_C(   423),  INT16_C(    82),  INT16_C(   371),  INT16_C(    95),  INT16_C(    97),
         INT16_C(   240),  INT16_C(   311),  INT16_C(   243),  INT16_C(   247),  INT16_C(   168),  INT16_C(   286),  INT16_C(   266),  INT16_C(   235),
         INT16_C(   290),  INT16_C(   100),  INT16_C(   380),  INT16_C(   137),  INT16_C(   219),  INT16_C(   324),  INT16_C(    27),  INT16_C(   386),
         INT16_C(   262),  INT16_C(   156),  INT16_C(   228),  INT16_C(    29),  INT16_C(   100),  INT16_C(    74),  INT16_C(   184),  INT16_C(   230),
         INT16_C(   115),  INT16_C(   374),  INT16_C(    98),  INT16_C(   392),  INT16_C(   261),  INT16_C(   235),  INT16_C(   352),  INT16_C(   289) } },
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C( 18), UINT8_C(249), UINT8_C(193), UINT8_C( 74),
        UINT8_C(  3), UINT8_C(156), UINT8_C(167), UINT8_C( 31), UINT8_C( 85), UINT8_C(201), UINT8_C( 17), UINT8_C(207),
        UINT8_C( 13), UINT8_C(  3), UINT8_C(174), UINT8_C( 72), UINT8_C(103), UINT8_C( 96), UINT8_C( 24), UINT8_C(146),
        UINT8_C(158), UINT8_C(161), UINT8_C( 91), UINT8_C( 75), UINT8_C(220), UINT8_C(  5), UINT8_C(219), UINT8_C( 28),
        UINT8_C(105), UINT8_C( 12), UINT8_C(185), UINT8_C(  3), UINT8_C(190), UINT8_C( 62), UINT8_C(101), UINT8_C(208),
        UINT8_C( 64), UINT8_C( 49), UINT8_C(210), UINT8_C(177), UINT8_C( 56), UINT8_C( 19), UINT8_C(  8), UINT8_C( 48),
        UINT8_C(229), UINT8_C(241), UINT8_C( 16), UINT8_C( 82), UINT8_C( 56), UINT8_C(214), UINT8_C(190), UINT8_C(142),
        UINT8_C(142), UINT8_C( 16), UINT8_C( 41), UINT8_C(  4), UINT8_C(249), UINT8_C( 25), UINT8_C(193), UINT8_C( 74),
        UINT8_C(106), UINT8_C(189), UINT8_C(211), UINT8_C(201), UINT8_C( 42), UINT8_C(203), UINT8_C(169), UINT8_C(  8),
        UINT8_C(113), UINT8_C(105), UINT8_C( 69), UINT8_C( 54), UINT8_C(111), UINT8_C(207), UINT8_C(221), UINT8_C(180),
        UINT8_C(128), UINT8_C(232), UINT8_C(117), UINT8_C( 39), UINT8_C(180), UINT8_C(214), UINT8_C(103), UINT8_C(138),
        UINT8_C(206), UINT8_C( 78), UINT8_C(236), UINT8_C(208), UINT8_C(188), UINT8_C(135), UINT8_C(192), UINT8_C(173),
        UINT8_C(123), UINT8_C( 87), UINT8_C(213), UINT8_C(233), UINT8_C( 57), UINT8_C(128), UINT8_C( 80), UINT8_C( 74),
        UINT8_C(  4), UINT8_C(133), UINT8_C(210), UINT8_C( 41), UINT8_C(139), UINT8_C(252), UINT8_C( 16), UINT8_C(144),
        UINT8_C( 36), UINT8_C(115), UINT8_C( 23), UINT8_C(123), UINT8_C( 54), UINT8_C(103), UINT8_C(184), UINT8_C( 56) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(243), UINT8_C(137), UINT8_C(233), UINT8_C( 64),
        UINT8_C(226), UINT8_C(166), UINT8_C(114), UINT8_C(116), UINT8_C(176), UINT8_C(113), UINT8_C(146), UINT8_C( 84),
        UINT8_C( 92), UINT8_C(181), UINT8_C(182), UINT8_C(131), UINT8_C(148), UINT8_C( 13), UINT8_C(161), UINT8_C(137),
        UINT8_C( 88), UINT8_C( 10), UINT8_C(131), UINT8_C(133), UINT8_C( 29), UINT8_C( 33), UINT8_C(203), UINT8_C(166),
        UINT8_C(165), UINT8_C(107), UINT8_C(119), UINT8_C( 59), UINT8_C( 12), UINT8_C( 29), UINT8_C(171), UINT8_C( 31),
        UINT8_C(105), UINT8_C( 55), UINT8_C( 19), UINT8_C(208), UINT8_C(251), UINT8_C(248), UINT8_C(130), UINT8_C(131),
        UINT8_C(211), UINT8_C( 51), UINT8_C( 70), UINT8_C(186), UINT8_C(100), UINT8_C( 63), UINT8_C(250), UINT8_C(159),
        UINT8_C(250), UINT8_C( 91), UINT8_C(134), UINT8_C(219), UINT8_C(241), UINT8_C(  9), UINT8_C( 36), UINT8_C( 69),
        UINT8_C( 40), UINT8_C(  1), UINT8_C(142), UINT8_C( 50), UINT8_C(237), UINT8_C(183), UINT8_C(216), UINT8_C( 82),
        UINT8_C(225), UINT8_C(219), UINT8_C(232), UINT8_C(172), UINT8_C(108), UINT8_C(235), UINT8_C(107), UINT8_C(162),
        UINT8_C(169), UINT8_C( 30), UINT8_C( 34), UINT8_C( 34), UINT8_C(194), UINT8_C(105), UINT8_C(164), UINT8_C( 63),
        UINT8_C(141), UINT8_C(248), UINT8_C(126), UINT8_C(226), UINT8_C(163), UINT8_C(249), UINT8_C(174), UINT8_C( 77),
        UINT8_C( 61), UINT8_C( 78), UINT8_C(213), UINT8_C(150), UINT8_C( 55), UINT8_C(206), UINT8_C(154), UINT8_C(180),
        UINT8_C(117), UINT8_C(214), UINT8_C( 56), UINT8_C(140), UINT8_C( 71), UINT8_C( 77), UINT8_C(  5), UINT8_C(202),
        UINT8_C( 71), UINT8_C( 32), UINT8_C(181), UINT8_C( 10), UINT8_C(151), UINT8_C( 96), UINT8_C( 43), UINT8_C(197) },
      {  INT16_C(     0),  INT16_C(   255),  INT16_C(   255),  INT16_C(   255),  INT16_C(   255),  INT16_C(   510),  INT16_C(   261),  INT16_C(   426),
         INT16_C(   229),  INT16_C(   281),  INT16_C(   261),  INT16_C(   163),  INT16_C(   105),  INT16_C(   356),  INT16_C(   251),  INT16_C(   185),
         INT16_C(   246),  INT16_C(   222),  INT16_C(   249),  INT16_C(   422),  INT16_C(   270),  INT16_C(   304),  INT16_C(   202),  INT16_C(   272),
         INT16_C(   169),  INT16_C(   229),  INT16_C(   307),  INT16_C(   138),  INT16_C(   440),  INT16_C(    86),  INT16_C(   156),  INT16_C(   440),
         INT16_C(   392),  INT16_C(   175),  INT16_C(   490),  INT16_C(   229),  INT16_C(   146),  INT16_C(   353),  INT16_C(   279),  INT16_C(   385),
         INT16_C(   338),  INT16_C(   301),  INT16_C(   219),  INT16_C(   328),  INT16_C(   297),  INT16_C(   151),  INT16_C(   374),  INT16_C(   267),
         INT16_C(   347),  INT16_C(   362),  INT16_C(   351),  INT16_C(   366),  INT16_C(   184),  INT16_C(   426),  INT16_C(   112),  INT16_C(   234),
         INT16_C(   121),  INT16_C(   266),  INT16_C(   210),  INT16_C(    21),  INT16_C(   107),  INT16_C(   204),  INT16_C(   205),  INT16_C(   227),
         INT16_C(   255),  INT16_C(   256),  INT16_C(   256),  INT16_C(     2),  INT16_C(     1),  INT16_C(   256),  INT16_C(   386),  INT16_C(   138),
         INT16_C(   322),  INT16_C(   147),  INT16_C(   314),  INT16_C(   291),  INT16_C(   184),  INT16_C(   203),  INT16_C(   109),  INT16_C(   283),
         INT16_C(   171),  INT16_C(   208),  INT16_C(    38),  INT16_C(   194),  INT16_C(   119),  INT16_C(    62),  INT16_C(    91),  INT16_C(   239),
         INT16_C(   104),  INT16_C(   385),  INT16_C(   267),  INT16_C(   179),  INT16_C(   292),  INT16_C(   268),  INT16_C(   277),  INT16_C(   301),
         INT16_C(   107),  INT16_C(   223),  INT16_C(    34),  INT16_C(   143),  INT16_C(   190),  INT16_C(   251),  INT16_C(   386),  INT16_C(    90),
         INT16_C(   324),  INT16_C(   226),  INT16_C(   442),  INT16_C(   342),  INT16_C(   262),  INT16_C(    73),  INT16_C(   319),  INT16_C(   201),
         INT16_C(   326),  INT16_C(   434),  INT16_C(   384),  INT16_C(   250),  INT16_C(   165),  INT16_C(   383),  INT16_C(   334),  INT16_C(   254),
         INT16_C(   347),  INT16_C(   181),  INT16_C(   329),  INT16_C(   346),  INT16_C(   147),  INT16_C(   133),  INT16_C(   199),  INT16_C(   253) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vadd_VubVub(a, b);

    simde_test_hvx_vectorpair_i16_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u8_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u8_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vadd_VubVub(a, b);

    simde_test_hvx_vector_u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VhVh_widen(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    int32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C( 23108),  INT16_C( 20398),  INT16_C( 25442), -INT16_C( 26401),
        -INT16_C(  2519), -INT16_C( 18949), -INT16_C(  1992), -INT16_C( 19738),  INT16_C( 12192),  INT16_C( 14045),  INT16_C( 14428),  INT16_C( 17867),
         INT16_C(  2130), -INT16_C( 21480), -INT16_C(  9299), -INT16_C( 31483), -INT16_C( 21872),  INT16_C(  8106), -INT16_C( 27779),  INT16_C(  7030),
         INT16_C( 24824), -INT16_C( 20986), -INT16_C(   596), -INT16_C( 27969),  INT16_C( 19347),  INT16_C(  8679),  INT16_C(  2909),  INT16_C(  6126),
        -INT16_C( 20469), -INT16_C(  7461),  INT16_C( 20684),  INT16_C( 26223),  INT16_C(    27),  INT16_C( 15979), -INT16_C(  4892),  INT16_C(  8237),
        -INT16_C(   206),  INT16_C( 31666),  INT16_C( 10990),  INT16_C(  3228), -INT16_C( 15087),  INT16_C( 23061),  INT16_C( 20898),  INT16_C( 17232),
        -INT16_C(  6868),  INT16_C( 19357),  INT16_C( 32205), -INT16_C( 27248),  INT16_C(  8542), -INT16_C( 14723), -INT16_C( 14720), -INT16_C(  8862) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 29528),  INT16_C( 27758), -INT16_C( 13850),  INT16_C( 24250),
        -INT16_C( 29992), -INT16_C( 13861),  INT16_C(  7645),  INT16_C(  8067), -INT16_C( 20328), -INT16_C( 25476), -INT16_C( 17773), -INT16_C( 19325),
         INT16_C( 23567), -INT16_C( 20055),  INT16_C( 26757),  INT16_C(    54),  INT16_C(  6110),  INT16_C( 16759),  INT16_C( 28583),  INT16_C( 30391),
         INT16_C(  5720), -INT16_C( 26346),  INT16_C( 29272),  INT16_C(  6517),  INT16_C( 30051), -INT16_C( 25675), -INT16_C( 29616), -INT16_C(   730),
        -INT16_C( 12310), -INT16_C( 12519), -INT16_C(  2520),  INT16_C( 13049),  INT16_C( 13299), -INT16_C(  1618), -INT16_C(  2032),  INT16_C( 14304),
        -INT16_C(  5291), -INT16_C( 23543),  INT16_C( 16649), -INT16_C( 27208), -INT16_C( 10010),  INT16_C( 22893),  INT16_C(  9727), -INT16_C( 27930),
        -INT16_C( 29492), -INT16_C( 20751), -INT16_C( 28972),  INT16_C( 18667), -INT16_C( 17253), -INT16_C( 21838), -INT16_C(  5516), -INT16_C(  8614) },
      { -INT32_C(       65536),  INT32_C(       32767), -INT32_C(       32769),  INT32_C(       32767), -INT32_C(       32769),  INT32_C(       65534),  INT32_C(        6420),  INT32_C(       11592),
        -INT32_C(       32511),  INT32_C(        5653), -INT32_C(        8136), -INT32_C(        3345),  INT32_C(       25697),  INT32_C(       17458), -INT32_C(       15762),  INT32_C(         804),
         INT32_C(       30544),  INT32_C(       28676),  INT32_C(       49398), -INT32_C(       26707), -INT32_C(       32779),  INT32_C(       18164),  INT32_C(       13326), -INT32_C(        6924),
        -INT32_C(        5497),  INT32_C(       27639), -INT32_C(       25097),  INT32_C(       30625), -INT32_C(       36360),  INT32_C(        3233), -INT32_C(        8711), -INT32_C(       20236),
        -INT32_C(           1),  INT32_C(       32768),  INT32_C(       32768),  INT32_C(           2), -INT32_C(       32767),  INT32_C(       32768),  INT32_C(       48156), -INT32_C(        2151),
        -INT32_C(       32810), -INT32_C(       11671), -INT32_C(       11431), -INT32_C(        1458), -INT32_C(       41535), -INT32_C(       31429),  INT32_C(       24865),  INT32_C(       37421),
        -INT32_C(       47332), -INT32_C(       21452), -INT32_C(       16996),  INT32_C(        5396), -INT32_C(       19980),  INT32_C(       39272),  INT32_C(       14361),  INT32_C(       22541),
         INT32_C(        8123), -INT32_C(       23980),  INT32_C(       45954), -INT32_C(       10698), -INT32_C(        1394), -INT32_C(        8581), -INT32_C(       36561), -INT32_C(       17476) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C( 15303),  INT16_C(  4319),  INT16_C(  2805),  INT16_C( 19721),
        -INT16_C( 19508), -INT16_C(  6901),  INT16_C( 18490),  INT16_C( 26021), -INT16_C( 13011),  INT16_C(  2679), -INT16_C( 19754),  INT16_C( 12288),
         INT16_C( 11985),  INT16_C(   223), -INT16_C(  2120), -INT16_C( 10778),  INT16_C( 16991),  INT16_C( 21240), -INT16_C( 10042), -INT16_C(  1488),
         INT16_C( 15237), -INT16_C(  4627),  INT16_C(  2211),  INT16_C( 22228), -INT16_C(  8020), -INT16_C( 26019), -INT16_C(  6951),  INT16_C(   294),
         INT16_C( 26519),  INT16_C(  9454),  INT16_C( 31509),  INT16_C( 19781),  INT16_C( 24103),  INT16_C( 16986), -INT16_C( 29961),  INT16_C( 24973),
         INT16_C(  3370), -INT16_C( 25906), -INT16_C( 30494),  INT16_C( 11229),  INT16_C( 10248), -INT16_C( 22203),  INT16_C( 19984), -INT16_C( 27840),
        -INT16_C(  5356), -INT16_C( 20109),  INT16_C( 10000),  INT16_C( 20351),  INT16_C( 15119),  INT16_C(  8869), -INT16_C( 31561), -INT16_C(   773) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 17735), -INT16_C(  5899),  INT16_C( 22304), -INT16_C( 20591),
         INT16_C(  8711),  INT16_C( 25148),  INT16_C( 22266), -INT16_C( 28418), -INT16_C(  5801),  INT16_C(  4475),  INT16_C(  5766), -INT16_C( 10276),
        -INT16_C( 15641),  INT16_C( 29472),  INT16_C( 32634), -INT16_C(   748), -INT16_C(  1903), -INT16_C(   890),  INT16_C( 14972), -INT16_C( 15297),
         INT16_C( 21132),  INT16_C( 12947), -INT16_C( 31047),  INT16_C( 23065),  INT16_C( 29153),  INT16_C(  4047), -INT16_C( 24246),  INT16_C( 29446),
        -INT16_C(  4792),  INT16_C( 18674),  INT16_C(  9253),  INT16_C(  5054),  INT16_C( 12432), -INT16_C( 32278),  INT16_C(  1802),  INT16_C( 21486),
         INT16_C( 30852), -INT16_C( 11748),  INT16_C( 28388), -INT16_C( 23406), -INT16_C(  9183),  INT16_C( 23187), -INT16_C( 18985), -INT16_C( 29520),
         INT16_C( 26595),  INT16_C(  1967), -INT16_C( 26828),  INT16_C( 11491), -INT16_C(  4697),  INT16_C(  5558), -INT16_C( 19896),  INT16_C( 16157) },
      { -INT32_C(       65536),  INT32_C(       32767), -INT32_C(       32769),  INT32_C(       32767), -INT32_C(       32769),  INT32_C(       65534),  INT32_C(        2432),  INT32_C(       25109),
        -INT32_C(       10797),  INT32_C(       40756), -INT32_C(       18812), -INT32_C(       13988), -INT32_C(        3656),  INT32_C(       30514),  INT32_C(       15088),  INT32_C(        4930),
         INT32_C(       36369), -INT32_C(       28836),  INT32_C(       21133), -INT32_C(       31197),  INT32_C(       21727),  INT32_C(       40762),  INT32_C(       36535), -INT32_C(       28159),
         INT32_C(       34222), -INT32_C(        2106),  INT32_C(        1065),  INT32_C(         999),  INT32_C(       21239), -INT32_C(       16828),  INT32_C(       10422), -INT32_C(       51457),
        -INT32_C(           1),  INT32_C(       32768),  INT32_C(       32768),  INT32_C(           2), -INT32_C(       32767),  INT32_C(       32768), -INT32_C(        1580), -INT32_C(         870),
         INT32_C(       18247), -INT32_C(        2397),  INT32_C(        7154),  INT32_C(        2012),  INT32_C(       29695), -INT32_C(       11526),  INT32_C(       20350), -INT32_C(       16785),
         INT32_C(        8320),  INT32_C(       45293), -INT32_C(       21972),  INT32_C(       29740),  INT32_C(       28128),  INT32_C(       24835), -INT32_C(       15292),  INT32_C(       46459),
        -INT32_C(       37654), -INT32_C(       12177),  INT32_C(         984), -INT32_C(       57360), -INT32_C(       18142),  INT32_C(       31842),  INT32_C(       14427),  INT32_C(       15384) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vadd_VhVh(a, b);

    simde_test_hvx_vectorpair_i32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i16_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vadd_VhVh(a, b);

    simde_test_hvx_vector_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VuhVuh_widen(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    uint16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    int32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(42568), UINT16_C( 5554), UINT16_C(18360), UINT16_C(41990),
        UINT16_C(20779), UINT16_C(53745), UINT16_C(19528), UINT16_C(17389), UINT16_C(61809), UINT16_C(15812), UINT16_C(50243), UINT16_C( 6688),
        UINT16_C(41407), UINT16_C(38942), UINT16_C(41981), UINT16_C(34286), UINT16_C( 3537), UINT16_C(24197), UINT16_C(26153), UINT16_C(51509),
        UINT16_C(42004), UINT16_C( 9438), UINT16_C(56129), UINT16_C(53040), UINT16_C(37842), UINT16_C(57485), UINT16_C(14897), UINT16_C(64329),
        UINT16_C( 6994), UINT16_C(21773), UINT16_C(56042), UINT16_C(63742), UINT16_C(24290), UINT16_C(37864), UINT16_C(14970), UINT16_C(38829),
        UINT16_C( 2514), UINT16_C(63708), UINT16_C(36087), UINT16_C(28431), UINT16_C(41530), UINT16_C(28635), UINT16_C(10641), UINT16_C( 7158),
        UINT16_C(44341), UINT16_C( 7039), UINT16_C(53745), UINT16_C(30682), UINT16_C(10799), UINT16_C(56658), UINT16_C(63719), UINT16_C(35205) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(41183), UINT16_C(12584), UINT16_C(55755), UINT16_C( 8198),
        UINT16_C(31863), UINT16_C(63098), UINT16_C(21195), UINT16_C(46721), UINT16_C(21299), UINT16_C( 2591), UINT16_C(31979), UINT16_C(49475),
        UINT16_C(39650), UINT16_C(45787), UINT16_C(43375), UINT16_C(37327), UINT16_C(22876), UINT16_C( 4204), UINT16_C(37609), UINT16_C(54604),
        UINT16_C(16997), UINT16_C(46705), UINT16_C( 6245), UINT16_C(61873), UINT16_C(15024), UINT16_C(59812), UINT16_C( 2907), UINT16_C(39137),
        UINT16_C(61737), UINT16_C( 7540), UINT16_C(11762), UINT16_C(34251), UINT16_C(41902), UINT16_C(52461), UINT16_C(21298), UINT16_C(36451),
        UINT16_C(24611), UINT16_C(60357), UINT16_C(40835), UINT16_C(36664), UINT16_C(44729), UINT16_C(57902), UINT16_C(24509), UINT16_C(12863),
        UINT16_C(44580), UINT16_C( 2829), UINT16_C(28405), UINT16_C(57687), UINT16_C(19794), UINT16_C(19444), UINT16_C(16655), UINT16_C(37095) },
      {  INT32_C(           0),  INT32_C(       65535),  INT32_C(       65535),  INT32_C(       65535),  INT32_C(       65535),  INT32_C(      131070),  INT32_C(       83751),  INT32_C(       74115),
         INT32_C(       52642),  INT32_C(       40723),  INT32_C(       83108),  INT32_C(       82222),  INT32_C(       81057),  INT32_C(       85356),  INT32_C(       26413),  INT32_C(       63762),
         INT32_C(       59001),  INT32_C(       62374),  INT32_C(       52866),  INT32_C(       17804),  INT32_C(       68731),  INT32_C(       67804),  INT32_C(       66192),  INT32_C(       36268),
         INT32_C(       27125),  INT32_C(       76922),  INT32_C(       86259),  INT32_C(       35150),  INT32_C(       88921),  INT32_C(       82150),  INT32_C(       30593),  INT32_C(       80374),
         INT32_C(       65535),  INT32_C(       65536),  INT32_C(       65536),  INT32_C(           2),  INT32_C(           1),  INT32_C(       65536),  INT32_C(       18138),  INT32_C(       50188),
         INT32_C(      116843),  INT32_C(       64110),  INT32_C(       18403),  INT32_C(       56163),  INT32_C(       84729),  INT32_C(       71613),  INT32_C(       28401),  INT32_C(      106113),
         INT32_C(       56143),  INT32_C(      114913),  INT32_C(      117297),  INT32_C(      103466),  INT32_C(       29313),  INT32_C(       97993),  INT32_C(       90325),  INT32_C(       75280),
         INT32_C(      124065),  INT32_C(       65095),  INT32_C(       86537),  INT32_C(       20021),  INT32_C(        9868),  INT32_C(       88369),  INT32_C(       76102),  INT32_C(       72300) } },
    { { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),
             UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(61581), UINT16_C(18805), UINT16_C(28452), UINT16_C(61219),
        UINT16_C(43209), UINT16_C(52724), UINT16_C(47273), UINT16_C(47733), UINT16_C( 1969), UINT16_C(61410), UINT16_C(59289), UINT16_C(60201),
        UINT16_C(49659), UINT16_C(48550), UINT16_C(32000), UINT16_C(22848), UINT16_C(48201), UINT16_C( 7100), UINT16_C(23448), UINT16_C(35248),
        UINT16_C(  356), UINT16_C( 4797), UINT16_C(31177), UINT16_C(38885), UINT16_C(56581), UINT16_C(64945), UINT16_C(21717), UINT16_C(39727),
        UINT16_C(46683), UINT16_C(10665), UINT16_C(21707), UINT16_C(22810), UINT16_C(49254), UINT16_C(62622), UINT16_C(59614), UINT16_C(28309),
        UINT16_C(58404), UINT16_C(49755), UINT16_C(34668), UINT16_C(40865), UINT16_C(47458), UINT16_C(41772), UINT16_C(62228), UINT16_C( 7206),
        UINT16_C(41704), UINT16_C(44494), UINT16_C(44781), UINT16_C(11387), UINT16_C(47510), UINT16_C(42022), UINT16_C(56315), UINT16_C(57059) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(23474), UINT16_C(57798), UINT16_C(54093), UINT16_C(46039),
        UINT16_C(41115), UINT16_C(34635), UINT16_C(63110), UINT16_C(45362), UINT16_C(34910), UINT16_C(22006), UINT16_C(37798), UINT16_C( 2852),
        UINT16_C(29392), UINT16_C(26910), UINT16_C(45785), UINT16_C(11770), UINT16_C( 6799), UINT16_C(  517), UINT16_C(50383), UINT16_C(23161),
        UINT16_C(32147), UINT16_C(38401), UINT16_C(23441), UINT16_C(10944), UINT16_C(31422), UINT16_C(58590), UINT16_C(16358), UINT16_C(45056),
        UINT16_C(63129), UINT16_C(46974), UINT16_C(10752), UINT16_C(10254), UINT16_C(31320), UINT16_C(19118), UINT16_C(63463), UINT16_C(17591),
        UINT16_C(49951), UINT16_C(51954), UINT16_C(20502), UINT16_C(52616), UINT16_C(  600), UINT16_C(38914), UINT16_C(25998), UINT16_C(30390),
        UINT16_C( 2008), UINT16_C(35975), UINT16_C(30339), UINT16_C(13203), UINT16_C(54628), UINT16_C(42879), UINT16_C(32164), UINT16_C(54793) },
      {  INT32_C(           0),  INT32_C(       65535),  INT32_C(       65535),  INT32_C(       65535),  INT32_C(       65535),  INT32_C(      131070),  INT32_C(       85055),  INT32_C(       82545),
         INT32_C(       84324),  INT32_C(      110383),  INT32_C(       36879),  INT32_C(       97087),  INT32_C(       79051),  INT32_C(       77785),  INT32_C(       55000),  INT32_C(       73831),
         INT32_C(       32503),  INT32_C(       54618),  INT32_C(       88003),  INT32_C(       38075),  INT32_C(      109812),  INT32_C(       32459),  INT32_C(       80574),  INT32_C(      123077),
         INT32_C(      108355),  INT32_C(       55170),  INT32_C(       48058),  INT32_C(       88226),  INT32_C(       43712),  INT32_C(       75120),  INT32_C(      102138),  INT32_C(       88479),
         INT32_C(       65535),  INT32_C(       65536),  INT32_C(       65536),  INT32_C(           2),  INT32_C(           1),  INT32_C(       65536),  INT32_C(       76603),  INT32_C(      107258),
         INT32_C(       87359),  INT32_C(       93095),  INT32_C(       83416),  INT32_C(       63053),  INT32_C(       75460),  INT32_C(       34618),  INT32_C(        7617),  INT32_C(       58409),
         INT32_C(       43198),  INT32_C(       49829),  INT32_C(      123535),  INT32_C(       84783),  INT32_C(       57639),  INT32_C(       33064),  INT32_C(       81740),  INT32_C(       45900),
         INT32_C(      101709),  INT32_C(       93481),  INT32_C(       80686),  INT32_C(       37596),  INT32_C(       80469),  INT32_C(       24590),  INT32_C(       84901),  INT32_C(      111852) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vadd_VuhVuh(a, b);

    simde_test_hvx_vectorpair_i32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u16_random(1);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vadd_VuhVuh(a, b);

    simde_test_hvx_vector_u16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddacc_WhVubVub(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_PAIR_I16_COUNT];
    uint8_t b[SIMDE_HVX_VECTOR_SIZE];
    uint8_t c[SIMDE_HVX_VECTOR_SIZE];
    int16_t r[SIMDE_HVX_PAIR_I16_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C( 22132), -INT16_C(  3241),  INT16_C( 13454), -INT16_C(  7281),
        -INT16_C(  3319), -INT16_C( 29382), -INT16_C( 23164), -INT16_C( 26416), -INT16_C(  9460), -INT16_C( 24627), -INT16_C(  2644), -INT16_C(  4618),
         INT16_C( 19783),  INT16_C(  6957), -INT16_C( 32474),  INT16_C( 29921),  INT16_C( 24580), -INT16_C( 16921),  INT16_C( 14055), -INT16_C( 26708),
         INT16_C(  5908), -INT16_C( 10165),  INT16_C( 17757), -INT16_C( 22043), -INT16_C( 27357),  INT16_C( 24290), -INT16_C( 10473), -INT16_C( 10608),
        -INT16_C( 31826), -INT16_C( 18158),  INT16_C( 12570), -INT16_C( 16648), -INT16_C( 24399), -INT16_C( 31263), -INT16_C(  8077), -INT16_C(  3798),
        -INT16_C(  4100), -INT16_C( 31062),  INT16_C( 10080), -INT16_C(  7969),  INT16_C( 20251), -INT16_C( 25236),  INT16_C(  7524),  INT16_C( 14181),
        -INT16_C( 24217), -INT16_C(  5813),  INT16_C( 21343), -INT16_C(  6114),  INT16_C(  4606), -INT16_C( 31324),  INT16_C( 17600), -INT16_C( 20265),
         INT16_C( 25586), -INT16_C(  9962),  INT16_C(  9896),  INT16_C(  4436), -INT16_C( 26324), -INT16_C( 19299),  INT16_C(  6873),  INT16_C( 17175),
        -INT16_C( 28908), -INT16_C( 10534),  INT16_C(  4861), -INT16_C(  5267), -INT16_C( 21706), -INT16_C(  3729),  INT16_C( 10478), -INT16_C( 13150),
        -INT16_C(  2104),  INT16_C( 31814), -INT16_C( 30398), -INT16_C(   491), -INT16_C( 30997),  INT16_C(  9068),  INT16_C( 26239), -INT16_C( 20532),
         INT16_C( 14435), -INT16_C(  3826), -INT16_C( 14579), -INT16_C( 22519),  INT16_C( 32347), -INT16_C( 18163), -INT16_C( 32268),  INT16_C( 25151),
        -INT16_C(  2395), -INT16_C( 23947), -INT16_C(  8114), -INT16_C( 21338),  INT16_C( 14298),  INT16_C(  7428),  INT16_C(  4653),  INT16_C( 25482),
         INT16_C( 30342), -INT16_C(  9519), -INT16_C( 27744), -INT16_C(   937),  INT16_C(   890), -INT16_C( 12539),  INT16_C( 28007),  INT16_C( 11839),
         INT16_C(  8770), -INT16_C( 21135),  INT16_C( 25002),  INT16_C( 13376), -INT16_C(  4984), -INT16_C( 31564),  INT16_C( 26633), -INT16_C( 22502),
         INT16_C( 31272), -INT16_C( 17286),  INT16_C( 29738),  INT16_C( 20676), -INT16_C(  8058), -INT16_C(  6071), -INT16_C( 20541),  INT16_C( 31415) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(150), UINT8_C( 33), UINT8_C( 96), UINT8_C(229),
        UINT8_C(230), UINT8_C(188), UINT8_C( 24), UINT8_C( 55), UINT8_C( 99), UINT8_C(235), UINT8_C(253), UINT8_C(176),
        UINT8_C(170), UINT8_C( 54), UINT8_C(102), UINT8_C(191), UINT8_C( 48), UINT8_C(170), UINT8_C( 89), UINT8_C(145),
        UINT8_C( 46), UINT8_C(200), UINT8_C(200), UINT8_C( 39), UINT8_C(223), UINT8_C(136), UINT8_C(117), UINT8_C( 11),
        UINT8_C(134), UINT8_C(152), UINT8_C( 99), UINT8_C( 47), UINT8_C( 51), UINT8_C( 39), UINT8_C( 68), UINT8_C(201),
        UINT8_C( 69), UINT8_C( 98), UINT8_C( 71), UINT8_C(189), UINT8_C(180), UINT8_C( 10), UINT8_C(179), UINT8_C( 91),
        UINT8_C( 37), UINT8_C(108), UINT8_C( 50), UINT8_C(218), UINT8_C(202), UINT8_C(216), UINT8_C( 19), UINT8_C(180),
        UINT8_C(164), UINT8_C(  9), UINT8_C( 42), UINT8_C(246), UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C( 95),
        UINT8_C(233), UINT8_C(242), UINT8_C( 24), UINT8_C(205), UINT8_C( 42), UINT8_C(201), UINT8_C(  6), UINT8_C(  1),
        UINT8_C( 41), UINT8_C( 44), UINT8_C(119), UINT8_C(121), UINT8_C( 23), UINT8_C( 27), UINT8_C(216), UINT8_C(217),
        UINT8_C(158), UINT8_C(125), UINT8_C(248), UINT8_C(201), UINT8_C(103), UINT8_C(204), UINT8_C( 52), UINT8_C(138),
        UINT8_C( 22), UINT8_C(219), UINT8_C(  5), UINT8_C( 46), UINT8_C(209), UINT8_C(121), UINT8_C(247), UINT8_C(186),
        UINT8_C(221), UINT8_C(169), UINT8_C(177), UINT8_C( 20), UINT8_C( 49), UINT8_C(120), UINT8_C( 39), UINT8_C(109),
        UINT8_C(203), UINT8_C(225), UINT8_C(194), UINT8_C(178), UINT8_C(134), UINT8_C(179), UINT8_C( 94), UINT8_C(136),
        UINT8_C(252), UINT8_C(188), UINT8_C( 48), UINT8_C(237), UINT8_C(225), UINT8_C(169), UINT8_C(  4), UINT8_C( 23) },
      {    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1), UINT8_C(115), UINT8_C(  7), UINT8_C(192), UINT8_C(208),
        UINT8_C( 51), UINT8_C( 54), UINT8_C( 56), UINT8_C(170), UINT8_C(220), UINT8_C( 80), UINT8_C(118), UINT8_C(184),
        UINT8_C(190), UINT8_C( 38), UINT8_C(161), UINT8_C(187), UINT8_C(215), UINT8_C( 27), UINT8_C(230), UINT8_C( 45),
        UINT8_C( 47), UINT8_C( 73), UINT8_C(225), UINT8_C(152), UINT8_C(246), UINT8_C(177), UINT8_C( 18), UINT8_C(124),
        UINT8_C(203), UINT8_C(167), UINT8_C(208), UINT8_C(  4), UINT8_C( 26), UINT8_C( 94), UINT8_C(103), UINT8_C(  6),
        UINT8_C( 44), UINT8_C( 60), UINT8_C(174), UINT8_C(  6), UINT8_C( 62), UINT8_C(116), UINT8_C( 79), UINT8_C( 53),
        UINT8_C(208), UINT8_C( 39), UINT8_C( 29), UINT8_C(121), UINT8_C(251), UINT8_C(215), UINT8_C(249), UINT8_C( 91),
        UINT8_C( 10), UINT8_C(  3), UINT8_C(223), UINT8_C( 11), UINT8_C(144), UINT8_C(155), UINT8_C(165), UINT8_C(132),
        UINT8_C(178), UINT8_C(219), UINT8_C(129), UINT8_C( 15), UINT8_C( 80), UINT8_C(186), UINT8_C(137), UINT8_C(179),
        UINT8_C(189), UINT8_C( 76), UINT8_C( 12), UINT8_C(174), UINT8_C(  3), UINT8_C( 64), UINT8_C( 86), UINT8_C( 97),
        UINT8_C(225), UINT8_C(236), UINT8_C(168), UINT8_C(138), UINT8_C(212), UINT8_C(146), UINT8_C( 51), UINT8_C(105),
        UINT8_C( 57), UINT8_C( 95), UINT8_C(240), UINT8_C( 47), UINT8_C( 47), UINT8_C( 16), UINT8_C(253), UINT8_C(249),
        UINT8_C(180), UINT8_C(223), UINT8_C(201), UINT8_C( 12), UINT8_C(203), UINT8_C(105), UINT8_C( 78), UINT8_C(123),
        UINT8_C( 30), UINT8_C(109), UINT8_C( 33), UINT8_C( 47), UINT8_C( 24), UINT8_C(140), UINT8_C(243), UINT8_C(195),
        UINT8_C( 64), UINT8_C( 38), UINT8_C( 38), UINT8_C( 43), UINT8_C(  8), UINT8_C(126), UINT8_C(  3), UINT8_C( 66) },
      { -INT16_C( 32513), -INT16_C( 32513), -INT16_C( 32514), -INT16_C( 32259),        INT16_MIN, -INT16_C( 32514),  INT16_C(   265),  INT16_C(   289),
         INT16_C(   280),  INT16_C(    81), -INT16_C( 32450),  INT16_C(   372), -INT16_C( 21772), -INT16_C(  2978),  INT16_C( 13717), -INT16_C(  6962),
        -INT16_C(  3226), -INT16_C( 28957), -INT16_C( 22695), -INT16_C( 26281), -INT16_C(  9123), -INT16_C( 24320), -INT16_C(  2567), -INT16_C(  4447),
         INT16_C( 19896),  INT16_C(  7202), -INT16_C( 32232),  INT16_C( 30179),  INT16_C( 24825), -INT16_C( 16842),  INT16_C( 14508), -INT16_C( 26440),
         INT16_C(  6082), -INT16_C(  9900),  INT16_C( 17902), -INT16_C( 21876), -INT16_C( 26946),  INT16_C( 24443), -INT16_C( 10351), -INT16_C( 10465),
        -INT16_C( 31596), -INT16_C( 18027),  INT16_C( 12596), -INT16_C( 16346), -INT16_C( 24016), -INT16_C( 30847), -INT16_C(  7762), -INT16_C(  3695),
        -INT16_C(  4021), -INT16_C( 30817),  INT16_C( 10336), -INT16_C(  7469),  INT16_C( 20652), -INT16_C( 24858),  INT16_C(  7776),  INT16_C( 14298),
        -INT16_C( 23984), -INT16_C(  5586),  INT16_C( 21501), -INT16_C(  5777),  INT16_C(  4922), -INT16_C( 31238),  INT16_C( 17833), -INT16_C( 20258),
         INT16_C( 25842), -INT16_C(  9960),  INT16_C(  9897),  INT16_C(  4692), -INT16_C( 26069), -INT16_C( 19043),  INT16_C(  6913),  INT16_C( 17612),
        -INT16_C( 28666), -INT16_C( 10309),  INT16_C(  5176), -INT16_C(  4907), -INT16_C( 21614), -INT16_C(  3351),  INT16_C( 10675), -INT16_C( 12960),
        -INT16_C(  1831),  INT16_C( 32005), -INT16_C( 30085), -INT16_C(   356), -INT16_C( 30678),  INT16_C(  9119),  INT16_C( 26372), -INT16_C( 20325),
         INT16_C( 14593), -INT16_C(  3631), -INT16_C( 14453), -INT16_C( 22375),  INT16_C( 32494), -INT16_C( 17824), -INT16_C( 31837),  INT16_C( 25422),
        -INT16_C(  2383), -INT16_C( 23690), -INT16_C(  7959), -INT16_C( 21111),  INT16_C( 14759),  INT16_C(  7648),  INT16_C(  5040),  INT16_C( 25662),
         INT16_C( 30462), -INT16_C(  9224), -INT16_C( 27653), -INT16_C(   623),  INT16_C(  1251), -INT16_C( 12200),  INT16_C( 28357),  INT16_C( 12082),
         INT16_C(  9084), -INT16_C( 21042),  INT16_C( 25139),  INT16_C( 13811), -INT16_C(  4592), -INT16_C( 31532),  INT16_C( 26858), -INT16_C( 22270),
         INT16_C( 31606), -INT16_C( 17061),  INT16_C( 30057),  INT16_C( 21007), -INT16_C(  7832), -INT16_C(  5791), -INT16_C( 20246),  INT16_C( 31504) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C( 23594), -INT16_C( 18797),  INT16_C( 17441),  INT16_C( 28270),
         INT16_C(  8796),  INT16_C(  3972),  INT16_C( 14498), -INT16_C( 23878), -INT16_C( 13566), -INT16_C(  9120),  INT16_C(  6084), -INT16_C( 30545),
        -INT16_C( 32650),  INT16_C(  3174), -INT16_C( 10546), -INT16_C(  3206), -INT16_C( 19798),  INT16_C( 26535),  INT16_C( 32725), -INT16_C(   336),
         INT16_C( 24178),  INT16_C( 20187), -INT16_C( 12650),  INT16_C( 29676), -INT16_C( 28938),  INT16_C( 30765), -INT16_C( 29410), -INT16_C( 12280),
        -INT16_C( 16760),  INT16_C( 17129),  INT16_C(  6883), -INT16_C( 18215),  INT16_C( 13546), -INT16_C( 24308), -INT16_C( 17972),  INT16_C(  1368),
        -INT16_C( 18420),  INT16_C(  2443), -INT16_C(  4706),  INT16_C(  4599),  INT16_C( 27396),  INT16_C(  8431),  INT16_C( 14087),  INT16_C(  8128),
        -INT16_C(  1779),  INT16_C( 19424),  INT16_C(  9342),  INT16_C( 18615), -INT16_C( 23541), -INT16_C( 21749), -INT16_C(  7447), -INT16_C( 29716),
         INT16_C(  7211),  INT16_C( 24250), -INT16_C(  1531),  INT16_C(  8551),  INT16_C( 25298),  INT16_C( 20791),  INT16_C(  8271), -INT16_C( 31193),
         INT16_C( 30257),  INT16_C( 17450), -INT16_C( 31730),  INT16_C(  1051), -INT16_C( 16000), -INT16_C(  1860),  INT16_C( 20494), -INT16_C(  1791),
        -INT16_C( 15900),  INT16_C(   369),  INT16_C( 30329),  INT16_C( 26860), -INT16_C( 22575), -INT16_C(  6579),  INT16_C( 17661), -INT16_C( 14591),
         INT16_C( 11677), -INT16_C( 15390), -INT16_C( 23165),  INT16_C( 26624),  INT16_C(  5854), -INT16_C(  5710),  INT16_C( 13927),  INT16_C(  5603),
         INT16_C( 22802),  INT16_C( 25137), -INT16_C(  9175),  INT16_C(  7135),  INT16_C( 11476), -INT16_C( 27235), -INT16_C( 12974),  INT16_C(  2021),
        -INT16_C( 19477), -INT16_C( 18000),  INT16_C( 26936),  INT16_C(  6042),  INT16_C( 16953),  INT16_C(  3885), -INT16_C( 24275),  INT16_C( 28585),
        -INT16_C( 18035),  INT16_C( 19965), -INT16_C(   909), -INT16_C( 19396), -INT16_C( 20443), -INT16_C(  1626), -INT16_C( 13998), -INT16_C(   743),
        -INT16_C( 22622), -INT16_C( 10600),  INT16_C( 17240),  INT16_C( 30477), -INT16_C( 15622), -INT16_C(  4407), -INT16_C(  3857),  INT16_C( 22240) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(200), UINT8_C(106), UINT8_C(242), UINT8_C(173),
        UINT8_C(167), UINT8_C(157), UINT8_C( 70), UINT8_C(109), UINT8_C(196), UINT8_C(211), UINT8_C(180), UINT8_C(188),
        UINT8_C( 49), UINT8_C( 67), UINT8_C(171), UINT8_C( 64), UINT8_C( 89), UINT8_C(213), UINT8_C(158), UINT8_C( 75),
        UINT8_C(150), UINT8_C( 89), UINT8_C( 53), UINT8_C( 25), UINT8_C(146), UINT8_C(235), UINT8_C(211), UINT8_C( 75),
        UINT8_C( 64), UINT8_C( 96), UINT8_C( 97), UINT8_C( 70), UINT8_C(211), UINT8_C(190), UINT8_C(179), UINT8_C(147),
        UINT8_C( 58), UINT8_C(134), UINT8_C(224), UINT8_C(212), UINT8_C(122), UINT8_C(  0), UINT8_C(218), UINT8_C(126),
        UINT8_C(117), UINT8_C( 99), UINT8_C( 49), UINT8_C(187), UINT8_C(124), UINT8_C(202), UINT8_C( 44), UINT8_C(244),
        UINT8_C(190), UINT8_C(250), UINT8_C(194), UINT8_C( 32), UINT8_C(224), UINT8_C( 48), UINT8_C( 53),    UINT8_MAX,
        UINT8_C(200), UINT8_C( 95), UINT8_C(218), UINT8_C(232), UINT8_C(231), UINT8_C(235), UINT8_C(240), UINT8_C( 90),
        UINT8_C(104), UINT8_C(161), UINT8_C( 87), UINT8_C( 73), UINT8_C(127), UINT8_C(149), UINT8_C(251), UINT8_C(205),
        UINT8_C( 49), UINT8_C(  4), UINT8_C( 34), UINT8_C( 78), UINT8_C(145), UINT8_C( 16), UINT8_C( 29), UINT8_C(142),
        UINT8_C( 89), UINT8_C(248), UINT8_C( 59), UINT8_C(194), UINT8_C(133), UINT8_C( 80), UINT8_C(204), UINT8_C( 44),
        UINT8_C(202), UINT8_C(152), UINT8_C(252), UINT8_C( 56), UINT8_C( 85), UINT8_C(234), UINT8_C(101), UINT8_C( 15),
        UINT8_C(  6), UINT8_C(223), UINT8_C( 48), UINT8_C( 86), UINT8_C( 67), UINT8_C( 89), UINT8_C(133), UINT8_C(196),
        UINT8_C(131), UINT8_C( 19), UINT8_C( 90), UINT8_C(235), UINT8_C( 69), UINT8_C( 39), UINT8_C(241), UINT8_C(225) },
      {    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1), UINT8_C( 87), UINT8_C(194), UINT8_C( 92), UINT8_C(211),
        UINT8_C( 35), UINT8_C(210), UINT8_C(215), UINT8_C(176), UINT8_C(138), UINT8_C(174), UINT8_C( 19), UINT8_C(154),
        UINT8_C(142), UINT8_C(212), UINT8_C(254), UINT8_C(194), UINT8_C(124), UINT8_C(203), UINT8_C( 50), UINT8_C(181),
        UINT8_C(219), UINT8_C(230), UINT8_C( 44), UINT8_C( 58), UINT8_C(129), UINT8_C( 60), UINT8_C( 74), UINT8_C( 96),
        UINT8_C(176), UINT8_C(163), UINT8_C(241), UINT8_C( 25), UINT8_C(143), UINT8_C( 66), UINT8_C(136), UINT8_C( 14),
        UINT8_C(  6), UINT8_C( 24), UINT8_C(111), UINT8_C(161), UINT8_C(207), UINT8_C(167), UINT8_C( 47), UINT8_C( 52),
        UINT8_C( 85), UINT8_C(174), UINT8_C( 37), UINT8_C( 14), UINT8_C(157), UINT8_C(110), UINT8_C( 21), UINT8_C(191),
        UINT8_C(235), UINT8_C( 12), UINT8_C( 61), UINT8_C(151), UINT8_C(204), UINT8_C( 87), UINT8_C( 85), UINT8_C( 58),
        UINT8_C(174), UINT8_C( 83), UINT8_C(128), UINT8_C(235), UINT8_C( 21), UINT8_C( 63), UINT8_C(102), UINT8_C( 35),
        UINT8_C(158), UINT8_C( 70), UINT8_C( 29), UINT8_C(225), UINT8_C( 50), UINT8_C(168), UINT8_C(146), UINT8_C( 63),
        UINT8_C( 14), UINT8_C(115), UINT8_C( 13), UINT8_C( 78), UINT8_C( 81), UINT8_C( 52), UINT8_C(152), UINT8_C( 28),
        UINT8_C(170), UINT8_C(210), UINT8_C(  6), UINT8_C(101), UINT8_C( 37), UINT8_C( 34), UINT8_C( 90), UINT8_C( 89),
        UINT8_C(  6), UINT8_C(146), UINT8_C(144), UINT8_C(115), UINT8_C(251), UINT8_C( 74), UINT8_C( 29), UINT8_C(162),
        UINT8_C(126), UINT8_C( 79), UINT8_C(219), UINT8_C(  5), UINT8_C(217), UINT8_C(124), UINT8_C(221), UINT8_C(186),
        UINT8_C(252), UINT8_C( 46), UINT8_C(197), UINT8_C( 14), UINT8_C(211), UINT8_C(110), UINT8_C( 31), UINT8_C( 61) },
      { -INT16_C( 32513), -INT16_C( 32513), -INT16_C( 32514), -INT16_C( 32259),        INT16_MIN, -INT16_C( 32514),  INT16_C(   287),  INT16_C(   335),
         INT16_C(   201),  INT16_C(   286), -INT16_C( 32435),  INT16_C(   200),  INT16_C( 23785), -INT16_C( 18372),  INT16_C( 17654),  INT16_C( 28478),
         INT16_C(  9165),  INT16_C(  4069),  INT16_C( 14773), -INT16_C( 23593), -INT16_C( 13326), -INT16_C(  8782),  INT16_C(  6438), -INT16_C( 30230),
        -INT16_C( 32586),  INT16_C(  3509), -INT16_C( 10217), -INT16_C(  2941), -INT16_C( 19596),  INT16_C( 26621), -INT16_C( 32530), -INT16_C(   271),
         INT16_C( 24603),  INT16_C( 20442), -INT16_C( 12222),  INT16_C( 29814), -INT16_C( 28564),  INT16_C( 31111), -INT16_C( 29158), -INT16_C( 11938),
        -INT16_C( 16498),  INT16_C( 17245),  INT16_C(  7060), -INT16_C( 17818),  INT16_C( 13609), -INT16_C( 24261), -INT16_C( 17746),  INT16_C(  1549),
        -INT16_C( 18161),  INT16_C(  2508), -INT16_C(  4536),  INT16_C(  4893),  INT16_C( 27604),  INT16_C(  8827),  INT16_C( 14423),  INT16_C(  8258),
        -INT16_C(  1647),  INT16_C( 19691),  INT16_C(  9626),  INT16_C( 18969), -INT16_C( 23158), -INT16_C( 21462), -INT16_C(  7167), -INT16_C( 29444),
         INT16_C(  7467),  INT16_C( 24252), -INT16_C(  1530),  INT16_C(  8807),  INT16_C( 25553),  INT16_C( 21047),  INT16_C(  8571), -INT16_C( 30809),
         INT16_C( 30624),  INT16_C( 17735), -INT16_C( 31345),  INT16_C(  1393), -INT16_C( 15721), -INT16_C(  1602),  INT16_C( 20910), -INT16_C(  1535),
        -INT16_C( 15581),  INT16_C(   452),  INT16_C( 30624),  INT16_C( 27031), -INT16_C( 22316), -INT16_C(  6484),  INT16_C( 17917), -INT16_C( 14430),
         INT16_C( 11835), -INT16_C( 15017), -INT16_C( 22998),  INT16_C( 26802),  INT16_C(  6127), -INT16_C(  5509),  INT16_C( 14239),  INT16_C(  6038),
         INT16_C( 23064),  INT16_C( 25320), -INT16_C(  9040),  INT16_C(  7448),  INT16_C( 11654), -INT16_C( 26768), -INT16_C( 12676),  INT16_C(  2146),
        -INT16_C( 19246), -INT16_C( 17702),  INT16_C( 27253),  INT16_C(  6310),  INT16_C( 17072),  INT16_C(  4041), -INT16_C( 24207),  INT16_C( 28755),
        -INT16_C( 17577),  INT16_C( 20260), -INT16_C(   795), -INT16_C( 19263), -INT16_C( 20145), -INT16_C(  1455), -INT16_C( 13690), -INT16_C(   566),
        -INT16_C( 22320), -INT16_C( 10509),  INT16_C( 17453),  INT16_C( 30859), -INT16_C( 15557), -INT16_C(  4158), -INT16_C(  3708),  INT16_C( 22526) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t c = simde_test_hvx_vector_load(test_vec[i].c);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vaddacc_WhVubVub(a, b, c);

    simde_test_hvx_vectorpair_i16_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u8_random(1);
    simde_hvx_vector_t c = simde_test_hvx_vector_u8_random(2);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vaddacc_WhVubVub(a, b, c);

    simde_test_hvx_vectorpair_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u8_write(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddacc_WwVhVh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_PAIR_I32_COUNT];
    int16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t c[SIMDE_HVX_VECTOR_I16_COUNT];
    int32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(  1072214996), -INT32_C(  1588197988), -INT32_C(  1969483451),  INT32_C(  1964227089),
         INT32_C(   203366824),  INT32_C(  2102331777),  INT32_C(   196656830),  INT32_C(   318048084),  INT32_C(   630366792), -INT32_C(   400665141),  INT32_C(  1931578095), -INT32_C(  1360355452),
         INT32_C(  1743874649), -INT32_C(  1320890074),  INT32_C(   881628233),  INT32_C(  1563066985), -INT32_C(   719393937), -INT32_C(   133994317),  INT32_C(   991933338),  INT32_C(  1381437247),
        -INT32_C(  2038435417),  INT32_C(  1731428035), -INT32_C(  1873439081), -INT32_C(  2108708270),  INT32_C(  1598500350), -INT32_C(  1611256279), -INT32_C(  1803152162),  INT32_C(  1117253353),
         INT32_C(   690594279),  INT32_C(  1672596389),  INT32_C(  1302927097),  INT32_C(  1388830996),  INT32_C(  2079813272), -INT32_C(   271505672),  INT32_C(  1320398822), -INT32_C(   376721697),
        -INT32_C(    88763996),  INT32_C(   233250572), -INT32_C(  1388980081),  INT32_C(   766862938),  INT32_C(  1871904578),  INT32_C(  1485763777), -INT32_C(  1717678643), -INT32_C(  1412151296),
         INT32_C(   844737244),  INT32_C(  1083630036),  INT32_C(    11278945),  INT32_C(   987827716),  INT32_C(  1858595931),  INT32_C(   923762022), -INT32_C(   913488785), -INT32_C(   579617041) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C( 14394), -INT16_C( 26308),  INT16_C(  3292),  INT16_C( 14312),
        -INT16_C( 23911), -INT16_C( 14100),  INT16_C(  4728),  INT16_C( 26810),  INT16_C( 15727), -INT16_C( 19645), -INT16_C(  2393),  INT16_C(  4572),
        -INT16_C( 22940), -INT16_C( 10349), -INT16_C( 15879),  INT16_C( 24913), -INT16_C( 20550), -INT16_C(  5229), -INT16_C( 21046), -INT16_C( 15665),
         INT16_C( 31022),  INT16_C(  4886), -INT16_C( 25604), -INT16_C( 14452),  INT16_C( 25109),  INT16_C( 11070),  INT16_C( 26137), -INT16_C( 12496),
        -INT16_C(  5244), -INT16_C( 12983), -INT16_C( 31863),  INT16_C( 14591), -INT16_C( 15232),  INT16_C(  4562), -INT16_C( 28841),  INT16_C( 20741),
         INT16_C( 16711),  INT16_C( 25452), -INT16_C(   258), -INT16_C( 22772),  INT16_C(  9338),  INT16_C( 19509),  INT16_C( 21103), -INT16_C( 29948),
        -INT16_C( 11294),  INT16_C( 11510), -INT16_C( 15479),  INT16_C( 16716), -INT16_C( 29333), -INT16_C( 30402), -INT16_C( 28411),  INT16_C( 29759) },
      { -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,
               INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C( 27325),  INT16_C( 17748),  INT16_C( 32251), -INT16_C(  7122),
         INT16_C( 15546),  INT16_C(  4446),  INT16_C( 18780), -INT16_C( 12410), -INT16_C(  9185), -INT16_C( 28095),  INT16_C(  2738),  INT16_C( 28010),
        -INT16_C(   666), -INT16_C( 29696),  INT16_C( 12210),  INT16_C( 19895),  INT16_C( 15649),  INT16_C( 28021), -INT16_C( 31661), -INT16_C( 32736),
        -INT16_C( 16850),  INT16_C( 15658), -INT16_C( 23461),  INT16_C(  7513), -INT16_C( 24156), -INT16_C( 10588), -INT16_C(  2109), -INT16_C( 21925),
         INT16_C( 14885),  INT16_C(  1839), -INT16_C( 22891),  INT16_C( 17341), -INT16_C(   320), -INT16_C( 24041),  INT16_C( 14555), -INT16_C( 18921),
        -INT16_C( 23730), -INT16_C( 11996), -INT16_C(  1809),  INT16_C(  7693),  INT16_C( 14880), -INT16_C( 30465), -INT16_C( 26997), -INT16_C(  2361),
         INT16_C( 25794),  INT16_C(  8983), -INT16_C(  5971), -INT16_C(  1490),  INT16_C( 15707), -INT16_C( 17037),  INT16_C(  2145),  INT16_C( 32624) },
      {  INT32_C(  2147450879), -INT32_C(  2147450881),  INT32_C(  2147450878), -INT32_C(  2147418115),  INT32_C(  2147418112), -INT32_C(  2147450882), -INT32_C(       41719),  INT32_C(       35544),
        -INT32_C(        8366),  INT32_C(       23509), -INT32_C(  2147477107),  INT32_C(         346),  INT32_C(  1072191390), -INT32_C(  1588201657), -INT32_C(  1969488352),  INT32_C(  1964174382),
         INT32_C(   203380996),  INT32_C(  2102282712),  INT32_C(   196657783),  INT32_C(   318072112),  INT32_C(   630376433), -INT32_C(   400719895),  INT32_C(  1931562543), -INT32_C(  1360369738),
         INT32_C(  1743867630), -INT32_C(  1320892141),  INT32_C(   881652451),  INT32_C(  1563061091), -INT32_C(   719379437), -INT32_C(   134015767),  INT32_C(   991919712),  INT32_C(  1381410981),
        -INT32_C(  2038402649),  INT32_C(  1731428037), -INT32_C(  1873471848), -INT32_C(  2108675502),  INT32_C(  1598500349), -INT32_C(  1611223511), -INT32_C(  1803160722),  INT32_C(  1117260543),
         INT32_C(   690584625),  INT32_C(  1672610789),  INT32_C(  1302879357),  INT32_C(  1388863578),  INT32_C(  2079773227), -INT32_C(   271460864),  INT32_C(  1320421614), -INT32_C(   376770098),
        -INT32_C(    88743452),  INT32_C(   233243633), -INT32_C(  1388979599),  INT32_C(   766828517),  INT32_C(  1871893434),  INT32_C(  1485795709), -INT32_C(  1717698122), -INT32_C(  1412149476),
         INT32_C(   844750700),  INT32_C(  1083614957),  INT32_C(    11267989),  INT32_C(   987795407),  INT32_C(  1858616424),  INT32_C(   923777248), -INT32_C(   913536224), -INT32_C(   579554658) } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(  1999413780),  INT32_C(   554659893),  INT32_C(  1403030870),  INT32_C(  2007720889),
        -INT32_C(  1784215761),  INT32_C(   387680435), -INT32_C(   188193812), -INT32_C(   979702074), -INT32_C(  1744042150),  INT32_C(  1296082520), -INT32_C(  1982263263), -INT32_C(  1013682791),
        -INT32_C(  2075521985),  INT32_C(  1924253294),  INT32_C(   392915513),  INT32_C(  2043152758),  INT32_C(   501525976),  INT32_C(  1515929699),  INT32_C(   578292716),  INT32_C(  1051461025),
        -INT32_C(  1749661280), -INT32_C(   209386184),  INT32_C(   201143213),  INT32_C(   546579632),  INT32_C(   468929702),  INT32_C(  2084344726),  INT32_C(   273076337),  INT32_C(  1071094587),
        -INT32_C(  1734385944),  INT32_C(  1628388605),  INT32_C(  1466380660), -INT32_C(  1744828560),  INT32_C(  1877865312),  INT32_C(  1620454801), -INT32_C(  1821845387), -INT32_C(   728899078),
         INT32_C(  1863370327),  INT32_C(  1414248972), -INT32_C(  1047070467),  INT32_C(  2126448593), -INT32_C(  1309298059),  INT32_C(  1060140351),  INT32_C(  2039419926),  INT32_C(   972341088),
        -INT32_C(  1082819318),  INT32_C(   163349699),  INT32_C(  1416447757),  INT32_C(  1729479310), -INT32_C(  1738014947),  INT32_C(  1873200186), -INT32_C(   408243288), -INT32_C(   930688222) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C( 28936), -INT16_C( 27121),  INT16_C( 27382),  INT16_C( 27688),
        -INT16_C(  5677),  INT16_C( 22429),  INT16_C( 12615),  INT16_C( 21846),  INT16_C(  3749), -INT16_C(  3982),  INT16_C(  6876),  INT16_C(  3362),
         INT16_C( 14156), -INT16_C( 25474), -INT16_C( 20267), -INT16_C( 23116),  INT16_C( 24183), -INT16_C( 26578), -INT16_C(  1070), -INT16_C( 26928),
         INT16_C( 12139),  INT16_C( 21685), -INT16_C( 11030),  INT16_C(  2064),  INT16_C( 14657),  INT16_C( 29069), -INT16_C(  6962), -INT16_C( 30454),
        -INT16_C(  7706),  INT16_C( 15180), -INT16_C( 22343),  INT16_C(  6240),  INT16_C( 11247), -INT16_C( 25153),  INT16_C(  9401), -INT16_C( 20834),
        -INT16_C( 16837), -INT16_C(  2551),  INT16_C( 30387), -INT16_C(  9566), -INT16_C(  5312), -INT16_C( 29308), -INT16_C( 17556),  INT16_C( 26921),
        -INT16_C(  3414), -INT16_C( 13579),  INT16_C(  5309),  INT16_C( 24333), -INT16_C(  1802), -INT16_C( 19342),  INT16_C(  8703),  INT16_C(  2176) },
      { -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,
               INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C( 26370), -INT16_C( 28901), -INT16_C( 13295),  INT16_C( 21583),
         INT16_C(  4837), -INT16_C( 15452), -INT16_C( 30019),  INT16_C( 14705), -INT16_C( 20438),  INT16_C( 27560), -INT16_C( 32717),  INT16_C( 27891),
        -INT16_C(  7849),  INT16_C(  7683), -INT16_C(  4852), -INT16_C( 25087),  INT16_C( 25396),  INT16_C( 17509),  INT16_C(  5306), -INT16_C( 27539),
         INT16_C( 16335),  INT16_C(   695), -INT16_C( 27822), -INT16_C(   705), -INT16_C( 31610),  INT16_C( 11188),  INT16_C(  3559), -INT16_C(  4310),
        -INT16_C( 32451), -INT16_C( 11325),  INT16_C( 31537), -INT16_C(  4652),  INT16_C( 32218), -INT16_C( 27907), -INT16_C(  1809), -INT16_C( 28699),
         INT16_C( 23292), -INT16_C( 10183),  INT16_C(  1409),  INT16_C( 30593), -INT16_C(  2605),  INT16_C(  2749), -INT16_C( 10774),  INT16_C( 32495),
         INT16_C( 25781), -INT16_C( 25037),  INT16_C( 29817),  INT16_C( 25537), -INT16_C( 24290), -INT16_C( 23225),  INT16_C(  1552), -INT16_C( 16374) },
      {  INT32_C(  2147450879), -INT32_C(  2147450881),  INT32_C(  2147450878), -INT32_C(  2147418115),  INT32_C(  2147418112), -INT32_C(  2147450882),  INT32_C(        2566),  INT32_C(       14088),
        -INT32_C(         841), -INT32_C(       17403),  INT32_C(  2147466958), -INT32_C(       25840), -INT32_C(  1999407473),  INT32_C(   554634774),  INT32_C(  1403080449),  INT32_C(  2007725125),
        -INT32_C(  1784187287),  INT32_C(   387641583), -INT32_C(   188210765), -INT32_C(   979705477), -INT32_C(  1744082307),  INT32_C(  1296091714), -INT32_C(  1982219798), -INT32_C(  1013675199),
        -INT32_C(  2075515530),  INT32_C(  1924285090),  INT32_C(   392907596),  INT32_C(  2043124428),  INT32_C(   501548343),  INT32_C(  1515964825),  INT32_C(   578266624),  INT32_C(  1051471280),
        -INT32_C(  1749628512), -INT32_C(   209386182),  INT32_C(   201110446),  INT32_C(   546612400),  INT32_C(   468929701),  INT32_C(  2084377494),  INT32_C(   273020315),  INT32_C(  1071143858),
        -INT32_C(  1734378967),  INT32_C(  1628425156),  INT32_C(  1466404238), -INT32_C(  1744797307),  INT32_C(  1877847521),  INT32_C(  1620406598), -INT32_C(  1821854456), -INT32_C(   728953545),
         INT32_C(  1863392707),  INT32_C(  1414250331), -INT32_C(  1047030210),  INT32_C(  2126413829), -INT32_C(  1309294204),  INT32_C(  1060141939),  INT32_C(  2039366866),  INT32_C(   972291555),
        -INT32_C(  1082832052),  INT32_C(   163370726),  INT32_C(  1416421198),  INT32_C(  1729538726), -INT32_C(  1738053563),  INT32_C(  1873250056), -INT32_C(   408285855), -INT32_C(   930702420) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t c = simde_test_hvx_vector_load(test_vec[i].c);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vaddacc_WwVhVh(a, b, c);

    simde_test_hvx_vectorpair_i32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i16_random(1);
    simde_hvx_vector_t c = simde_test_hvx_vector_i16_random(2);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vaddacc_WwVhVh(a, b, c);

    simde_test_hvx_vectorpair_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i16_write(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddacc_WwVuhVuh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_PAIR_I32_COUNT];
    uint16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    uint16_t c[SIMDE_HVX_VECTOR_I16_COUNT];
    int32_t r[SIMDE_HVX_PAIR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(  1136135353),  INT32_C(   306347071), -INT32_C(   292998305),  INT32_C(  2085287146),
         INT32_C(  1862448770), -INT32_C(  1822629948),  INT32_C(   262585587),  INT32_C(   289074818), -INT32_C(   849755098), -INT32_C(   373370610),  INT32_C(  1877685476),  INT32_C(   504036872),
         INT32_C(  1174840599),  INT32_C(    86687469),  INT32_C(   112495400), -INT32_C(    54667490), -INT32_C(  1240237934), -INT32_C(   853683723),  INT32_C(  1303280706), -INT32_C(  2004877588),
        -INT32_C(   709981105), -INT32_C(   668343623),  INT32_C(  1631139653),  INT32_C(  1241118772),  INT32_C(  1844210002),  INT32_C(  1529361562), -INT32_C(  1166924707), -INT32_C(  2009730108),
        -INT32_C(   184369405), -INT32_C(   743212363), -INT32_C(     9415085), -INT32_C(   493846336), -INT32_C(   194726915), -INT32_C(   613639307),  INT32_C(  1697128333), -INT32_C(   801387434),
        -INT32_C(   967697116), -INT32_C(  1047084481),  INT32_C(   814173199), -INT32_C(  1547313850),  INT32_C(   878322284),  INT32_C(  1299919033), -INT32_C(  1120368905),  INT32_C(  1933402057),
         INT32_C(  1497348592),  INT32_C(  1058625590), -INT32_C(  1299031811), -INT32_C(  1923518627),  INT32_C(  1775737011),  INT32_C(    44874936), -INT32_C(  1271242907), -INT32_C(   835917082) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(61339), UINT16_C(  798), UINT16_C( 2278), UINT16_C( 1108),
        UINT16_C(30428), UINT16_C(60663), UINT16_C(31667), UINT16_C(  466), UINT16_C(45428), UINT16_C(31830), UINT16_C(29856), UINT16_C(20712),
        UINT16_C(45180), UINT16_C(62913), UINT16_C(12469), UINT16_C(60318), UINT16_C(32558), UINT16_C(60891), UINT16_C(11955), UINT16_C(59650),
        UINT16_C(49649), UINT16_C(26672), UINT16_C(27970), UINT16_C( 5071), UINT16_C( 9407), UINT16_C(38925), UINT16_C( 4372), UINT16_C(45506),
        UINT16_C(23288), UINT16_C(50785), UINT16_C(51351), UINT16_C(28825), UINT16_C(43485), UINT16_C(32931), UINT16_C(43445), UINT16_C(32157),
        UINT16_C(29837), UINT16_C(24448), UINT16_C(44057), UINT16_C(30841), UINT16_C(36205), UINT16_C(14352), UINT16_C(12345), UINT16_C(13303),
        UINT16_C(30120), UINT16_C(50188), UINT16_C(27974), UINT16_C(32550), UINT16_C( 9063), UINT16_C(23182), UINT16_C( 4882), UINT16_C(54858) },
      {      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
        UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1), UINT16_C( 3042), UINT16_C(60875), UINT16_C(21371), UINT16_C(39944),
        UINT16_C(12150), UINT16_C(62256), UINT16_C(45786), UINT16_C( 3768), UINT16_C(32738), UINT16_C(41484), UINT16_C(28862), UINT16_C(21253),
        UINT16_C(47843), UINT16_C(43797), UINT16_C(50435), UINT16_C(18986), UINT16_C(44945), UINT16_C(15947), UINT16_C( 6258), UINT16_C(63312),
        UINT16_C(46789), UINT16_C(60659), UINT16_C(14535), UINT16_C(43922), UINT16_C(47429), UINT16_C(18808), UINT16_C(44047), UINT16_C(40344),
        UINT16_C(28879), UINT16_C(64088), UINT16_C(27658), UINT16_C(49107), UINT16_C(56635), UINT16_C(11511), UINT16_C(53004), UINT16_C(   53),
        UINT16_C(31888), UINT16_C(56885), UINT16_C(48081), UINT16_C(38690), UINT16_C(58099), UINT16_C(46450), UINT16_C(37508), UINT16_C(17464),
        UINT16_C( 1055), UINT16_C(35727), UINT16_C(49699), UINT16_C(55154), UINT16_C(43014), UINT16_C(12889), UINT16_C( 9535), UINT16_C(47616) },
      { -INT32_C(  2147418113), -INT32_C(  2147418113), -INT32_C(  2147418114), -INT32_C(  2147352579),              INT32_MIN, -INT32_C(  2147418114),  INT32_C(       64381),  INT32_C(       23650),
         INT32_C(       42577),  INT32_C(       77454), -INT32_C(  2147405483),  INT32_C(       58719), -INT32_C(  1136042330),  INT32_C(   306409975), -INT32_C(   292920802),  INT32_C(  2085305359),
         INT32_C(  1862545208), -INT32_C(  1822587443),  INT32_C(   262642423),  INT32_C(   289123237), -INT32_C(   849702931), -INT32_C(   373291601),  INT32_C(  1877785596),  INT32_C(   504133321),
         INT32_C(  1174902324),  INT32_C(    86779607),  INT32_C(   112589704), -INT32_C(    54617637), -INT32_C(  1240206759), -INT32_C(   853606050),  INT32_C(  1303332783), -INT32_C(  2004863171),
        -INT32_C(   709915569), -INT32_C(   668343621),  INT32_C(  1631139654),  INT32_C(  1241184308),  INT32_C(  1844275537),  INT32_C(  1529427098), -INT32_C(  1166863034), -INT32_C(  2009689056),
        -INT32_C(   184246486), -INT32_C(   743208129), -INT32_C(     9341771), -INT32_C(   493804371), -INT32_C(   194620205), -INT32_C(   613560003),  INT32_C(  1697205171), -INT32_C(   801264472),
        -INT32_C(   967609785), -INT32_C(  1047035488),  INT32_C(   814230932), -INT32_C(  1547228000),  INT32_C(   878437157),  INT32_C(  1299996965), -INT32_C(  1120324463),  INT32_C(  1933434267),
         INT32_C(  1497429925),  INT32_C(  1058695121), -INT32_C(  1298971009), -INT32_C(  1923487860),  INT32_C(  1775822926),  INT32_C(    44962640), -INT32_C(  1271206836), -INT32_C(   835814608) } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(  1318917009),  INT32_C(   361466207), -INT32_C(  1993403421), -INT32_C(    37426750),
         INT32_C(   532731161),  INT32_C(  1092395079),  INT32_C(   966395971),  INT32_C(   521843350), -INT32_C(    59331048), -INT32_C(  1122920843), -INT32_C(  1324390505), -INT32_C(  1761661233),
        -INT32_C(  1869267910),  INT32_C(   446410007),  INT32_C(  1015911783),  INT32_C(  1848440397),  INT32_C(   915112421), -INT32_C(  1281081906), -INT32_C(  1453861410),  INT32_C(  1768175357),
        -INT32_C(  2051596306),  INT32_C(   619407261),  INT32_C(   755999633), -INT32_C(   444362322),  INT32_C(  1274157868), -INT32_C(    17459846), -INT32_C(   545046078), -INT32_C(  1238986688),
        -INT32_C(   494761392),  INT32_C(   692599043),  INT32_C(  1135339176),  INT32_C(  2019301809),  INT32_C(  1576707450), -INT32_C(  2140252727),  INT32_C(  1917522991), -INT32_C(   689346415),
         INT32_C(    76267267),  INT32_C(   609503675),  INT32_C(  1422955447),  INT32_C(  1149964358), -INT32_C(  1405115117),  INT32_C(    57370421),  INT32_C(  1909559378), -INT32_C(  1310554951),
         INT32_C(  1688855656),  INT32_C(   337235489), -INT32_C(   658347776), -INT32_C(  1252941601), -INT32_C(   159944988), -INT32_C(   805435193), -INT32_C(  1655335319), -INT32_C(  1434927208) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1),
        UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(61471), UINT16_C(44895), UINT16_C(  744), UINT16_C( 5983),
        UINT16_C(36686), UINT16_C(44202), UINT16_C( 8820), UINT16_C(24154), UINT16_C( 1389), UINT16_C(53846), UINT16_C(20512), UINT16_C(41363),
        UINT16_C(34942), UINT16_C(47741), UINT16_C(42047), UINT16_C(54444), UINT16_C( 8543), UINT16_C( 6001), UINT16_C(49802), UINT16_C(13625),
        UINT16_C(55097), UINT16_C(54549), UINT16_C(64407), UINT16_C(14548), UINT16_C(25086), UINT16_C(32006), UINT16_C(38905), UINT16_C(28571),
        UINT16_C(11299), UINT16_C(42119), UINT16_C(42152), UINT16_C(16422), UINT16_C(43950), UINT16_C(17716), UINT16_C(63814), UINT16_C(38581),
        UINT16_C(27800), UINT16_C(33603), UINT16_C(37285), UINT16_C(12414), UINT16_C(43090), UINT16_C(35073), UINT16_C(48069), UINT16_C(28817),
        UINT16_C(37412), UINT16_C(44828), UINT16_C(62345), UINT16_C(  754), UINT16_C(56576), UINT16_C(26411), UINT16_C(40986), UINT16_C( 6191) },
      {      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    1), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,
        UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    1), UINT16_C( 7184), UINT16_C(43995), UINT16_C(44280), UINT16_C(22477),
        UINT16_C(22918), UINT16_C(18224), UINT16_C(30184), UINT16_C(49414), UINT16_C(42841), UINT16_C(13143), UINT16_C(41985), UINT16_C(27524),
        UINT16_C(33043), UINT16_C(34776), UINT16_C(39357), UINT16_C(29004), UINT16_C(45113), UINT16_C( 2433), UINT16_C(35607), UINT16_C(40734),
        UINT16_C(19213), UINT16_C(65517), UINT16_C(42703), UINT16_C(63454), UINT16_C(  467), UINT16_C(36023), UINT16_C(65482), UINT16_C(23400),
        UINT16_C(24261), UINT16_C(12655), UINT16_C(47657), UINT16_C(14516), UINT16_C( 3784), UINT16_C(32061), UINT16_C( 6319), UINT16_C(24892),
        UINT16_C(37347), UINT16_C(18696), UINT16_C(36566), UINT16_C(44636), UINT16_C( 8271), UINT16_C(17863), UINT16_C(22985), UINT16_C(20552),
        UINT16_C(64715), UINT16_C(64908), UINT16_C(29840), UINT16_C(13852), UINT16_C(41687), UINT16_C(53953), UINT16_C( 7755), UINT16_C( 9575) },
      { -INT32_C(  2147418113), -INT32_C(  2147418113), -INT32_C(  2147418114), -INT32_C(  2147352579),              INT32_MIN, -INT32_C(  2147418114),  INT32_C(       68655),  INT32_C(       45025),
         INT32_C(       59603),  INT32_C(       39005), -INT32_C(  2147439419),  INT32_C(       62498), -INT32_C(  1318849024),  INT32_C(   361547611), -INT32_C(  1993349765), -INT32_C(    37341341),
         INT32_C(   532805471),  INT32_C(  1092502189),  INT32_C(   966421524),  INT32_C(   521947737), -INT32_C(    59295488), -INT32_C(  1122831034), -INT32_C(  1324342771), -INT32_C(  1761591100),
        -INT32_C(  1869202763),  INT32_C(   446483858),  INT32_C(  1015963144),  INT32_C(  1848511451),  INT32_C(   915214548), -INT32_C(  1280989721), -INT32_C(  1453763147),  INT32_C(  1768224098),
        -INT32_C(  2051530770),  INT32_C(   619407263),  INT32_C(   755999634), -INT32_C(   444296786),  INT32_C(  1274223403), -INT32_C(    17394310), -INT32_C(   544957188), -INT32_C(  1238958228),
        -INT32_C(   494698966),  INT32_C(   692672611),  INT32_C(  1135406165),  INT32_C(  2019370696),  INT32_C(  1576789967), -INT32_C(  2140169279),  INT32_C(  1917531425), -INT32_C(   689292056),
         INT32_C(    76387333),  INT32_C(   609581677),  INT32_C(  1423023476),  INT32_C(  1150016329), -INT32_C(  1405060343),  INT32_C(    57401359),  INT32_C(  1909609155), -INT32_C(  1310491478),
         INT32_C(  1688907955),  INT32_C(   337292539), -INT32_C(   658294840), -INT32_C(  1252892232), -INT32_C(   159835252), -INT32_C(   805420587), -INT32_C(  1655254955), -INT32_C(  1434911442) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t c = simde_test_hvx_vector_load(test_vec[i].c);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vaddacc_WwVuhVuh(a, b, c);

    simde_test_hvx_vectorpair_i32_assert_equal(r, simde_test_hvx_vectorpair_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vectorpair_t a = simde_test_hvx_vectorpair_i32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_u16_random(1);
    simde_hvx_vector_t c = simde_test_hvx_vector_u16_random(2);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vaddacc_WwVuhVuh(a, b, c);

    simde_test_hvx_vectorpair_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u16_write(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpair_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VubVb_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[SIMDE_HVX_VECTOR_SIZE];
    int8_t b[SIMDE_HVX_VECTOR_SIZE];
    uint8_t r[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C( 64), UINT8_C( 25), UINT8_C( 11), UINT8_C( 47),
        UINT8_C(247), UINT8_C( 15), UINT8_C(190), UINT8_C(  4), UINT8_C(168), UINT8_C( 33), UINT8_C(  1), UINT8_C(121),
        UINT8_C(163), UINT8_C( 29), UINT8_C(132), UINT8_C(223), UINT8_C(136), UINT8_C( 78), UINT8_C( 40), UINT8_C(251),
        UINT8_C(227), UINT8_C( 10), UINT8_C( 31), UINT8_C( 43), UINT8_C( 81), UINT8_C( 93), UINT8_C(180), UINT8_C( 93),
        UINT8_C( 11), UINT8_C( 92), UINT8_C(116), UINT8_C(213), UINT8_C(186), UINT8_C( 25), UINT8_C( 65), UINT8_C(178),
        UINT8_C(237), UINT8_C(192), UINT8_C( 70), UINT8_C( 58), UINT8_C( 59), UINT8_C(252), UINT8_C(133), UINT8_C(204),
        UINT8_C( 98), UINT8_C( 60), UINT8_C(106), UINT8_C( 79), UINT8_C( 95), UINT8_C(187), UINT8_C(237), UINT8_C(113),
        UINT8_C(112), UINT8_C( 12), UINT8_C(113), UINT8_C( 41), UINT8_C(212), UINT8_C( 95), UINT8_C(104), UINT8_C(114),
        UINT8_C( 79), UINT8_C(134), UINT8_C(235), UINT8_C( 80), UINT8_C( 15), UINT8_C(229), UINT8_C(126), UINT8_C( 24),
        UINT8_C(151), UINT8_C(157), UINT8_C(101), UINT8_C( 87), UINT8_C( 17), UINT8_C(186), UINT8_C(182), UINT8_C(200),
        UINT8_C(157), UINT8_C( 21), UINT8_C(251), UINT8_C(222), UINT8_C(235), UINT8_C(213), UINT8_C( 39), UINT8_C(  6),
        UINT8_C(  2), UINT8_C(214), UINT8_C(104), UINT8_C( 71), UINT8_C( 99), UINT8_C(133), UINT8_C(240), UINT8_C( 98),
        UINT8_C( 72), UINT8_C( 40), UINT8_C( 31), UINT8_C(247), UINT8_C(241), UINT8_C(113), UINT8_C( 59), UINT8_C( 89),
        UINT8_C( 29),    UINT8_MAX, UINT8_C( 42), UINT8_C( 50), UINT8_C( 84), UINT8_C(165), UINT8_C( 75), UINT8_C(107),
        UINT8_C(  3), UINT8_C(228), UINT8_C( 13), UINT8_C( 34), UINT8_C(179), UINT8_C(231), UINT8_C(238), UINT8_C( 25) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(  20),  INT8_C(  89),  INT8_C(  52), -INT8_C(  36),
         INT8_C(  93), -INT8_C(   8), -INT8_C(  59), -INT8_C(  88),  INT8_C( 125),  INT8_C(  57), -INT8_C(  32),  INT8_C(  38),
        -INT8_C(  62),  INT8_C(  83), -INT8_C(  15), -INT8_C(  53),  INT8_C( 109),  INT8_C(  12),  INT8_C(  28),  INT8_C(  98),
        -INT8_C(  22), -INT8_C( 122),  INT8_C(  79),  INT8_C(   6),  INT8_C(  30),  INT8_C(  44),  INT8_C( 121), -INT8_C(  44),
        -INT8_C( 123),  INT8_C(  62), -INT8_C(   1),  INT8_C(  32), -INT8_C(  15), -INT8_C( 101),  INT8_C(  72), -INT8_C(  91),
        -INT8_C(  32), -INT8_C(  66),  INT8_C(  81),  INT8_C(   1), -INT8_C(  78),  INT8_C(  61), -INT8_C(  72),  INT8_C( 113),
         INT8_C(  94),  INT8_C(  69),  INT8_C(  41),  INT8_C( 102),  INT8_C(  71), -INT8_C(  79), -INT8_C(  21), -INT8_C(  33),
        -INT8_C(  15), -INT8_C(  48), -INT8_C(  53),  INT8_C(  45), -INT8_C( 106),  INT8_C(  97),  INT8_C(  17),  INT8_C(  78),
        -INT8_C(  24), -INT8_C( 117),  INT8_C(  56), -INT8_C( 116),  INT8_C(  94), -INT8_C(  51), -INT8_C(  42),  INT8_C(  10),
         INT8_C(  83), -INT8_C( 109),  INT8_C(  38), -INT8_C(  49), -INT8_C(  73),  INT8_C(  93), -INT8_C(   4), -INT8_C(  31),
         INT8_C(   8),  INT8_C(  35), -INT8_C( 111), -INT8_C(  94), -INT8_C(  81), -INT8_C( 120),  INT8_C(  24),  INT8_C(  76),
         INT8_C(  76), -INT8_C( 123), -INT8_C(  95),  INT8_C(  71),  INT8_C( 124),  INT8_C(  90),  INT8_C(  39), -INT8_C(  71),
        -INT8_C(  22), -INT8_C( 101), -INT8_C(  91), -INT8_C( 126), -INT8_C( 127), -INT8_C(  32), -INT8_C(  96), -INT8_C(  25),
         INT8_C( 125),  INT8_C(  54), -INT8_C(  88),  INT8_C(  83),  INT8_C(  76),  INT8_C(  74),  INT8_C( 120), -INT8_C(  72),
         INT8_C( 118), -INT8_C(  89),  INT8_C(  17),  INT8_C(  15), -INT8_C( 106),  INT8_C(  11),      INT8_MAX,  INT8_C(  19) },
      { UINT8_C(  0), UINT8_C(127),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(127), UINT8_C(  2),
        UINT8_C(127), UINT8_C(  0),    UINT8_MAX, UINT8_C(128), UINT8_C( 44), UINT8_C(114), UINT8_C( 63), UINT8_C( 11),
           UINT8_MAX, UINT8_C(  7), UINT8_C(131), UINT8_C(  0),    UINT8_MAX, UINT8_C( 90), UINT8_C(  0), UINT8_C(159),
        UINT8_C(101), UINT8_C(112), UINT8_C(117), UINT8_C(170), UINT8_C(245), UINT8_C( 90), UINT8_C( 68),    UINT8_MAX,
        UINT8_C(205), UINT8_C(  0), UINT8_C(110), UINT8_C( 49), UINT8_C(111), UINT8_C(137),    UINT8_MAX, UINT8_C( 49),
        UINT8_C(  0), UINT8_C(154), UINT8_C(115), UINT8_C(245), UINT8_C(171), UINT8_C(  0), UINT8_C(137), UINT8_C( 87),
        UINT8_C(205), UINT8_C(126), UINT8_C(151), UINT8_C( 59), UINT8_C(  0),    UINT8_MAX, UINT8_C( 61),    UINT8_MAX,
        UINT8_C(192), UINT8_C(129), UINT8_C(147), UINT8_C(181), UINT8_C(166), UINT8_C(108), UINT8_C(216), UINT8_C( 80),
        UINT8_C( 97), UINT8_C(  0), UINT8_C( 60), UINT8_C( 86), UINT8_C(106), UINT8_C(192), UINT8_C(121), UINT8_C(192),
        UINT8_C( 55), UINT8_C( 17),    UINT8_MAX, UINT8_C(  0), UINT8_C(109), UINT8_C(178), UINT8_C( 84), UINT8_C( 34),
        UINT8_C(234), UINT8_C( 48), UINT8_C(139), UINT8_C( 38), UINT8_C(  0),    UINT8_MAX, UINT8_C(178), UINT8_C(169),
        UINT8_C(165), UINT8_C( 56), UINT8_C(140), UINT8_C(128), UINT8_C(154), UINT8_C( 93), UINT8_C( 63), UINT8_C( 82),
        UINT8_C( 78), UINT8_C( 91), UINT8_C(  9), UINT8_C(142), UINT8_C(223), UINT8_C(223),    UINT8_MAX, UINT8_C( 27),
        UINT8_C( 50), UINT8_C(  0), UINT8_C(  0), UINT8_C(121), UINT8_C(114), UINT8_C( 81), UINT8_C(  0), UINT8_C( 64),
        UINT8_C(154),    UINT8_MAX, UINT8_C(  0), UINT8_C(133), UINT8_C(160), UINT8_C(239), UINT8_C(195), UINT8_C( 35),
        UINT8_C(121), UINT8_C(139), UINT8_C( 30), UINT8_C( 49), UINT8_C( 73), UINT8_C(242),    UINT8_MAX, UINT8_C( 44) } },
    { { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),
           UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  1), UINT8_C(163), UINT8_C( 84), UINT8_C( 38), UINT8_C( 82),
        UINT8_C(181), UINT8_C(198), UINT8_C(148), UINT8_C( 96), UINT8_C( 26), UINT8_C( 78), UINT8_C(220), UINT8_C(251),
        UINT8_C( 55), UINT8_C( 36), UINT8_C(202), UINT8_C(100), UINT8_C( 60), UINT8_C(115), UINT8_C( 61), UINT8_C(191),
        UINT8_C(195), UINT8_C(122), UINT8_C(101), UINT8_C(187), UINT8_C( 62), UINT8_C( 90), UINT8_C( 26), UINT8_C( 92),
        UINT8_C( 35), UINT8_C(234), UINT8_C(217), UINT8_C(113), UINT8_C(139), UINT8_C(248), UINT8_C(133), UINT8_C(202),
        UINT8_C(220), UINT8_C( 53), UINT8_C(209), UINT8_C(189), UINT8_C( 24), UINT8_C(110), UINT8_C(121), UINT8_C(  1),
        UINT8_C(141), UINT8_C( 84), UINT8_C(199), UINT8_C( 68), UINT8_C(116), UINT8_C( 49), UINT8_C( 73), UINT8_C(241),
        UINT8_C(188), UINT8_C( 23), UINT8_C(245), UINT8_C( 29), UINT8_C(129), UINT8_C( 14), UINT8_C( 42), UINT8_C(201),
        UINT8_C(115), UINT8_C( 47), UINT8_C(193), UINT8_C(252), UINT8_C(138), UINT8_C( 33), UINT8_C(218), UINT8_C(237),
        UINT8_C(209), UINT8_C( 46), UINT8_C(190), UINT8_C( 10), UINT8_C(113), UINT8_C(  0), UINT8_C(130), UINT8_C(136),
        UINT8_C(194), UINT8_C(162), UINT8_C( 43), UINT8_C(123), UINT8_C(109), UINT8_C(239), UINT8_C(155), UINT8_C(210),
        UINT8_C(181), UINT8_C(171), UINT8_C(192), UINT8_C( 71), UINT8_C(206), UINT8_C( 24), UINT8_C(157), UINT8_C(180),
        UINT8_C( 66), UINT8_C(219), UINT8_C(126), UINT8_C(189), UINT8_C(253), UINT8_C(104), UINT8_C( 28), UINT8_C(171),
        UINT8_C(105), UINT8_C(127), UINT8_C(  3), UINT8_C( 32), UINT8_C(236), UINT8_C(200), UINT8_C(204), UINT8_C( 73),
        UINT8_C(  1), UINT8_C(245), UINT8_C(223), UINT8_C(199), UINT8_C(245), UINT8_C(  3), UINT8_C(196), UINT8_C(  5) },
      {      INT8_MIN,      INT8_MAX,  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),      INT8_MAX,  INT8_C(   1),
             INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  88), -INT8_C(  27),      INT8_MIN, -INT8_C(   9),
        -INT8_C(  25),  INT8_C(  10), -INT8_C(  36), -INT8_C(   9), -INT8_C(  43), -INT8_C( 111),  INT8_C(   7),  INT8_C(  11),
        -INT8_C(  86), -INT8_C(   5), -INT8_C(  60),  INT8_C(  24),  INT8_C(  70),  INT8_C( 115),  INT8_C(  17),  INT8_C(  27),
         INT8_C(  48),  INT8_C(  88), -INT8_C(  43),  INT8_C( 100),  INT8_C(  29), -INT8_C( 124),  INT8_C(   7), -INT8_C(  63),
        -INT8_C(  96), -INT8_C( 122),  INT8_C( 112),  INT8_C(  26), -INT8_C(  87), -INT8_C(  26),  INT8_C(  84), -INT8_C(   3),
        -INT8_C(  15),  INT8_C(  42), -INT8_C(  22),  INT8_C(   7),  INT8_C(  95),  INT8_C(  76), -INT8_C( 123),  INT8_C(  51),
         INT8_C(  46), -INT8_C(  11),  INT8_C(  93),  INT8_C(  81),  INT8_C(  71),  INT8_C( 104),  INT8_C(  41), -INT8_C( 122),
        -INT8_C(  98),  INT8_C(  36), -INT8_C(  73),  INT8_C(  64), -INT8_C( 126), -INT8_C(  18), -INT8_C(  81), -INT8_C(  77),
         INT8_C(  35),  INT8_C(  25),  INT8_C(  58),  INT8_C(  81), -INT8_C(  92),  INT8_C(  48),  INT8_C(  95), -INT8_C(  45),
         INT8_C(   9), -INT8_C(  95), -INT8_C( 122),  INT8_C(  45), -INT8_C( 111), -INT8_C(  88),  INT8_C( 116), -INT8_C(  37),
         INT8_C(  96), -INT8_C(   2),  INT8_C(   5), -INT8_C( 111),  INT8_C(  87),  INT8_C(  46),  INT8_C(  45),  INT8_C(  12),
        -INT8_C(  49),  INT8_C(  31), -INT8_C(  95),  INT8_C( 124), -INT8_C( 124), -INT8_C(  16), -INT8_C( 103), -INT8_C(  20),
        -INT8_C(  69), -INT8_C(  50),  INT8_C(  98),  INT8_C( 119),  INT8_C(  37), -INT8_C(  76), -INT8_C(  64), -INT8_C(  85),
        -INT8_C( 126),  INT8_C(   2), -INT8_C( 120),  INT8_C(  11), -INT8_C(  89),  INT8_C(  46), -INT8_C( 100),  INT8_C(  97),
         INT8_C(  80), -INT8_C(  34), -INT8_C( 105), -INT8_C(  15), -INT8_C( 110), -INT8_C(  83),  INT8_C(  83), -INT8_C(  70) },
      { UINT8_C(  0), UINT8_C(127),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(127), UINT8_C(  2),
        UINT8_C(127), UINT8_C(  0),    UINT8_MAX, UINT8_C(128), UINT8_C(251), UINT8_C( 57), UINT8_C(  0), UINT8_C( 73),
        UINT8_C(156), UINT8_C(208), UINT8_C(112), UINT8_C( 87), UINT8_C(  0), UINT8_C(  0), UINT8_C(227),    UINT8_MAX,
        UINT8_C(  0), UINT8_C( 31), UINT8_C(142), UINT8_C(124), UINT8_C(130), UINT8_C(230), UINT8_C( 78), UINT8_C(218),
        UINT8_C(243), UINT8_C(210), UINT8_C( 58),    UINT8_MAX, UINT8_C( 91), UINT8_C(  0), UINT8_C( 33), UINT8_C( 29),
        UINT8_C(  0), UINT8_C(112),    UINT8_MAX, UINT8_C(139), UINT8_C( 52), UINT8_C(222), UINT8_C(217), UINT8_C(199),
        UINT8_C(205), UINT8_C( 95), UINT8_C(187), UINT8_C(196), UINT8_C(119), UINT8_C(186), UINT8_C(  0), UINT8_C( 52),
        UINT8_C(187), UINT8_C( 73),    UINT8_MAX, UINT8_C(149), UINT8_C(187), UINT8_C(153), UINT8_C(114), UINT8_C(119),
        UINT8_C( 90), UINT8_C( 59), UINT8_C(172), UINT8_C( 93), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0), UINT8_C(124),
        UINT8_C(150), UINT8_C( 72), UINT8_C(251),    UINT8_MAX, UINT8_C( 46), UINT8_C( 81),    UINT8_MAX, UINT8_C(192),
        UINT8_C(218), UINT8_C(  0), UINT8_C( 68), UINT8_C( 55), UINT8_C(  2), UINT8_C(  0), UINT8_C(246), UINT8_C( 99),
           UINT8_MAX, UINT8_C(160), UINT8_C( 48), UINT8_C( 12), UINT8_C(196),    UINT8_MAX, UINT8_C(200), UINT8_C(222),
        UINT8_C(132), UINT8_C(202), UINT8_C( 97), UINT8_C(195), UINT8_C( 82), UINT8_C(  8), UINT8_C( 54), UINT8_C(160),
        UINT8_C(  0), UINT8_C(169), UINT8_C(224),    UINT8_MAX,    UINT8_MAX, UINT8_C( 28), UINT8_C(  0), UINT8_C( 86),
        UINT8_C(  0), UINT8_C(129), UINT8_C(  0), UINT8_C( 43), UINT8_C(147), UINT8_C(246), UINT8_C(104), UINT8_C(170),
        UINT8_C( 81), UINT8_C(211), UINT8_C(118), UINT8_C(184), UINT8_C(135), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vadd_VubVb_sat(a, b);

    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_u8_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i8_random(1);
    simde_hvx_vector_t r = simde_Q6_Vub_vadd_VubVb_sat(a, b);

    simde_test_hvx_vector_u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VwVwQ_carry(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t b[SIMDE_HVX_VECTOR_I32_COUNT];
    uint8_t c[SIMDE_HVX_VECTOR_SIZE];
    int32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
    uint8_t qo[SIMDE_HVX_VECTOR_SIZE];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),  INT32_C(   756147788), -INT32_C(   691325062),  INT32_C(  1829944159),  INT32_C(  1402594782),
         INT32_C(   312803326),  INT32_C(  1984670976),  INT32_C(   803370120),  INT32_C(   615002364),  INT32_C(   337930255),  INT32_C(   220856168), -INT32_C(  2140491944),  INT32_C(  1161285723),
         INT32_C(  1374452938), -INT32_C(  1928119994),  INT32_C(  1955848988),  INT32_C(  1158370296),  INT32_C(  1037117826),  INT32_C(  1483681517), -INT32_C(  1520011023), -INT32_C(   760066837) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(   872937017), -INT32_C(   848939689), -INT32_C(   300269286), -INT32_C(   476798696),
         INT32_C(  1193441765),  INT32_C(   274210533),  INT32_C(   881324946), -INT32_C(  1654047458),  INT32_C(  1368277525),  INT32_C(  1747604806),  INT32_C(  1555049980), -INT32_C(  1659779545),
         INT32_C(  1696014966),  INT32_C(  1571843900),  INT32_C(  1826753676),  INT32_C(   770423219), -INT32_C(  1765234875), -INT32_C(  1644878803),  INT32_C(  1988616525), -INT32_C(  1034646979) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX },
      {  INT32_C(           1), -INT32_C(           1),              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           2),
                     INT32_MIN, -INT32_C(  2147483647), -INT32_C(           1), -INT32_C(  2147483647),  INT32_C(  1629084806), -INT32_C(  1540264750),  INT32_C(  1529674874),  INT32_C(   925796086),
         INT32_C(  1506245092), -INT32_C(  2036085786),  INT32_C(  1684695067), -INT32_C(  1039045094),  INT32_C(  1706207780),  INT32_C(  1968460974), -INT32_C(   585441964), -INT32_C(   498493822),
        -INT32_C(  1224499392), -INT32_C(   356276093), -INT32_C(   512364631),  INT32_C(  1928793515), -INT32_C(   728117048), -INT32_C(   161197286),  INT32_C(   468605502), -INT32_C(  1794713816) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(  2115195257), -INT32_C(  1292844528), -INT32_C(  1019737230), -INT32_C(  1513706849),
        -INT32_C(  1285658765), -INT32_C(  1349507853), -INT32_C(   204947164), -INT32_C(  1388352724), -INT32_C(  1575054716),  INT32_C(   655260232),  INT32_C(  1971953127),  INT32_C(  1497066368),
        -INT32_C(   554586579), -INT32_C(  2109254446),  INT32_C(   166464007),  INT32_C(  1581657607), -INT32_C(   924529394),  INT32_C(   952996429), -INT32_C(    67983051),  INT32_C(   852921202) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(  1608831766), -INT32_C(   704996160),  INT32_C(   301900123),  INT32_C(   463201118),
         INT32_C(  1609193280), -INT32_C(  1613619871), -INT32_C(  1262153120),  INT32_C(  1843282025),  INT32_C(  1756685800), -INT32_C(  1931139071),  INT32_C(   638689833),  INT32_C(   769784092),
        -INT32_C(  1835846677),  INT32_C(  1307753270), -INT32_C(   284269771), -INT32_C(  1128094127), -INT32_C(   295684513), -INT32_C(   630523137),  INT32_C(   536502507), -INT32_C(   884760700) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {  INT32_C(           1),  INT32_C(           0),              INT32_MIN, -INT32_C(  2147483647),              INT32_MIN,              INT32_MIN,              INT32_MAX,  INT32_C(           3),
                     INT32_MAX, -INT32_C(  2147483647), -INT32_C(           2),              INT32_MIN, -INT32_C(   506363491), -INT32_C(  1997840687), -INT32_C(   717837106), -INT32_C(  1050505731),
         INT32_C(   323534516),  INT32_C(  1331839572), -INT32_C(  1467100284),  INT32_C(   454929301),  INT32_C(   181631085), -INT32_C(  1275878839), -INT32_C(  1684324336), -INT32_C(  2028116836),
         INT32_C(  1904534041), -INT32_C(   801501175), -INT32_C(   117805763),  INT32_C(   453563481), -INT32_C(  1220213906),  INT32_C(   322473293),  INT32_C(   468519456), -INT32_C(    31839498) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpred_t c = simde_test_hvx_vectorpred_load(test_vec[i].c);
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_VwVwQ_carry(a, b, &c);

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
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_VwVwQ_carry(a, b, &c);

    simde_test_hvx_vector_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpred_write(2, c_in, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i32_write(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpred_write(2, c, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VwVwQ_carry_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t b[SIMDE_HVX_VECTOR_I32_COUNT];
    uint8_t c[SIMDE_HVX_VECTOR_SIZE];
    int32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(   708842031), -INT32_C(  1480682930),  INT32_C(  1461101286), -INT32_C(  1622962949),
         INT32_C(  1491382621),  INT32_C(  1878660200),  INT32_C(  1033534144), -INT32_C(   912856343),  INT32_C(  1063132766), -INT32_C(  2053487805),  INT32_C(  1780950077),  INT32_C(   396113774),
         INT32_C(  1118444685), -INT32_C(   522855732), -INT32_C(  1027669110),  INT32_C(   965956137), -INT32_C(   422008971), -INT32_C(  1524963160),  INT32_C(   938375237), -INT32_C(   968214115) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(  1232995294),  INT32_C(   245882101),  INT32_C(   225084167), -INT32_C(   196588609),
         INT32_C(  1593064582), -INT32_C(  1123263942), -INT32_C(   785860661), -INT32_C(  1832003089),  INT32_C(  1186366752), -INT32_C(  1652657835),  INT32_C(   905959485), -INT32_C(  1566889304),
        -INT32_C(   756562985), -INT32_C(  1580126795), -INT32_C(  1240730874),  INT32_C(  1904038620),  INT32_C(  1258230841), -INT32_C(  1651752089),  INT32_C(  1592480583),  INT32_C(  1158050888) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      {              INT32_MIN, -INT32_C(           1),              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(           3),
                     INT32_MIN, -INT32_C(  2147483646),              INT32_MAX,              INT32_MAX,  INT32_C(   524153264), -INT32_C(  1234800829),  INT32_C(  1686185454), -INT32_C(  1819551558),
                     INT32_MAX,  INT32_C(   755396258),  INT32_C(   247673483),              INT32_MIN,              INT32_MAX,              INT32_MIN,              INT32_MAX, -INT32_C(  1170775530),
         INT32_C(   361881700), -INT32_C(  2102982526),              INT32_MIN,              INT32_MAX,  INT32_C(   836221871),              INT32_MIN,              INT32_MAX,  INT32_C(   189836773) } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(  1743610390),  INT32_C(  1314775402),  INT32_C(  1821561925), -INT32_C(  1070702210),
         INT32_C(  1565600969), -INT32_C(  1615474888),  INT32_C(  1207569947), -INT32_C(   780671544),  INT32_C(  1172193480),  INT32_C(  1951028386), -INT32_C(  1595187167), -INT32_C(  1004643689),
        -INT32_C(   415273471),  INT32_C(  1759444416), -INT32_C(   150198722),  INT32_C(   369255288),  INT32_C(   525755277), -INT32_C(   546820196), -INT32_C(   687994527), -INT32_C(   675804416) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX, -INT32_C(  1818630788),  INT32_C(  1668198646), -INT32_C(  1749165036), -INT32_C(  2100007469),
         INT32_C(  1393776750),  INT32_C(   646720401), -INT32_C(  1203211396),  INT32_C(  2040234193),  INT32_C(  2009512209),  INT32_C(   994881112),  INT32_C(  1033670247), -INT32_C(   769638587),
         INT32_C(  1123441403), -INT32_C(   356058739),  INT32_C(   231880324), -INT32_C(  1631148807),  INT32_C(  1703300816),  INT32_C(  2068216525),  INT32_C(   544768267),  INT32_C(   191070501) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {              INT32_MIN, -INT32_C(           1),              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(           3),
                     INT32_MIN, -INT32_C(  2147483646),              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(    72396890),              INT32_MIN,
                     INT32_MAX, -INT32_C(   968754486),  INT32_C(     4358552),  INT32_C(  1259562649),              INT32_MAX,              INT32_MAX, -INT32_C(   561516919), -INT32_C(  1774282276),
         INT32_C(   708167933),  INT32_C(  1403385677),  INT32_C(    81681603), -INT32_C(  1261893519),              INT32_MAX,  INT32_C(  1521396329), -INT32_C(   143226259), -INT32_C(   484733915) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpred_t c = simde_test_hvx_vectorpred_load(test_vec[i].c);
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_VwVwQ_carry_sat(a, b, c);

    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i32_random(1);
    simde_hvx_vectorpred_t c = simde_test_hvx_vectorpred_random();
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_VwVwQ_carry_sat(a, b, c);

    simde_test_hvx_vector_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vectorpred_write(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_vclb_VhVh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t b[SIMDE_HVX_VECTOR_I16_COUNT];
    int16_t r[SIMDE_HVX_VECTOR_I16_COUNT];
  } test_vec[] = {
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),  INT16_C( 24265), -INT16_C( 24052),  INT16_C( 18780), -INT16_C( 24190),
         INT16_C( 20485), -INT16_C(  2105),  INT16_C(  7315),  INT16_C(   622),  INT16_C(  3463), -INT16_C( 25982), -INT16_C( 10542),  INT16_C( 29297),
        -INT16_C(  8434), -INT16_C( 12512),  INT16_C( 29179),  INT16_C( 13698), -INT16_C( 10151), -INT16_C( 25597),  INT16_C( 17621),  INT16_C( 16371),
        -INT16_C( 12352),  INT16_C( 14059), -INT16_C( 20456), -INT16_C( 23816),  INT16_C( 21941),  INT16_C(  8306),  INT16_C( 22270),  INT16_C( 22393),
         INT16_C( 20839), -INT16_C( 22972),  INT16_C( 12300),  INT16_C( 14377),  INT16_C( 20886), -INT16_C( 20759),  INT16_C( 16521),  INT16_C( 22740),
        -INT16_C(  3426),  INT16_C( 19206), -INT16_C(  2283),  INT16_C( 20111),  INT16_C( 12671), -INT16_C( 11586), -INT16_C( 12885),  INT16_C( 26737),
        -INT16_C( 11354), -INT16_C( 28493), -INT16_C(  6622),  INT16_C(  7769),  INT16_C( 26120), -INT16_C( 21451), -INT16_C(   436),  INT16_C( 25626) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX, -INT16_C(  7820),  INT16_C( 17054), -INT16_C( 11036), -INT16_C(  4552),
        -INT16_C(  6060), -INT16_C( 28356), -INT16_C(  3913), -INT16_C( 23858), -INT16_C( 10068),  INT16_C( 17521), -INT16_C( 26724), -INT16_C(  9226),
        -INT16_C(  1450),  INT16_C( 29862),  INT16_C( 23332), -INT16_C( 19491), -INT16_C( 30538), -INT16_C( 17207),  INT16_C( 10320), -INT16_C( 30011),
        -INT16_C( 31572),  INT16_C( 25417), -INT16_C(  5530),  INT16_C(  3554),  INT16_C( 16349),  INT16_C( 27565),  INT16_C( 29390), -INT16_C( 15496),
         INT16_C( 15244),  INT16_C(  8646), -INT16_C(  7814), -INT16_C(  1229),  INT16_C( 26134),  INT16_C( 17526),  INT16_C( 26251),  INT16_C( 19354),
         INT16_C( 10773),  INT16_C(  5328),  INT16_C( 23664),  INT16_C( 12379),  INT16_C(  3570),  INT16_C(  4168),  INT16_C( 18920), -INT16_C( 13803),
         INT16_C(  6816), -INT16_C( 28796), -INT16_C( 23308), -INT16_C(  1003), -INT16_C( 27359), -INT16_C( 21969), -INT16_C( 31785), -INT16_C( 20882) },
      {       -INT16_MAX,        INT16_MIN,  INT16_C(     1),  INT16_C(     2),  INT16_C(     0),  INT16_C(     2), -INT16_C( 32753),  INT16_C(    16),
        -INT16_C( 32752), -INT16_C( 32753),        INT16_MIN, -INT16_C( 32754), -INT16_C(  7819),  INT16_C( 17055), -INT16_C( 11035), -INT16_C(  4551),
        -INT16_C(  6059), -INT16_C( 28352), -INT16_C(  3910), -INT16_C( 23852), -INT16_C( 10064),  INT16_C( 17522), -INT16_C( 26722), -INT16_C(  9225),
        -INT16_C(  1448),  INT16_C( 29864),  INT16_C( 23333), -INT16_C( 19489), -INT16_C( 30536), -INT16_C( 17206),  INT16_C( 10321), -INT16_C( 30009),
        -INT16_C( 31570),  INT16_C( 25419), -INT16_C(  5529),  INT16_C(  3555),  INT16_C( 16350),  INT16_C( 27567),  INT16_C( 29391), -INT16_C( 15495),
         INT16_C( 15245),  INT16_C(  8647), -INT16_C(  7812), -INT16_C(  1227),  INT16_C( 26135),  INT16_C( 17527),  INT16_C( 26252),  INT16_C( 19355),
         INT16_C( 10777),  INT16_C(  5329),  INT16_C( 23668),  INT16_C( 12380),  INT16_C(  3572),  INT16_C(  4170),  INT16_C( 18922), -INT16_C( 13802),
         INT16_C(  6818), -INT16_C( 28795), -INT16_C( 23305), -INT16_C(  1000), -INT16_C( 27358), -INT16_C( 21968), -INT16_C( 31778), -INT16_C( 20881) } },
    { {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1),
        -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1), -INT16_C( 29954), -INT16_C( 23942), -INT16_C(  4475),  INT16_C(  5880),
        -INT16_C(  5190), -INT16_C(  4252), -INT16_C( 12036),  INT16_C( 28596), -INT16_C( 31303),  INT16_C( 29481),  INT16_C( 26612), -INT16_C( 30230),
        -INT16_C( 29270), -INT16_C(  7287), -INT16_C( 20347), -INT16_C(  6836), -INT16_C(  7866), -INT16_C( 29563),  INT16_C(  5430), -INT16_C( 18291),
        -INT16_C( 15199),  INT16_C( 15739),  INT16_C(  5028), -INT16_C( 29794), -INT16_C(  1740),  INT16_C( 16598), -INT16_C( 15203), -INT16_C( 29932),
        -INT16_C(  8211),  INT16_C(  2878), -INT16_C( 23491),  INT16_C( 28093), -INT16_C( 22948), -INT16_C( 19883),  INT16_C( 22695),  INT16_C(  4927),
        -INT16_C(  1054),  INT16_C( 30139), -INT16_C( 31039), -INT16_C( 31872), -INT16_C(   816),  INT16_C( 11537),  INT16_C( 16939),  INT16_C(  9336),
        -INT16_C( 24038), -INT16_C( 17014), -INT16_C(  6743), -INT16_C( 26641),  INT16_C(  9025),  INT16_C(  3961), -INT16_C( 29960), -INT16_C(  8325) },
      {        INT16_MIN,        INT16_MAX,  INT16_C(     0),  INT16_C(     1), -INT16_C(     1),  INT16_C(     1),        INT16_MAX,  INT16_C(     1),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C(  9710), -INT16_C( 28620), -INT16_C(  6031), -INT16_C( 31959),
         INT16_C( 10714), -INT16_C( 30062), -INT16_C( 18004), -INT16_C( 27023), -INT16_C( 26293), -INT16_C(  9480),  INT16_C( 23772), -INT16_C( 18295),
        -INT16_C(  1031),  INT16_C(  5582), -INT16_C( 30222), -INT16_C(  7825), -INT16_C( 12246), -INT16_C( 10450), -INT16_C( 26935),  INT16_C(  1868),
         INT16_C( 13387),  INT16_C( 27432),  INT16_C(  5021),  INT16_C( 19721), -INT16_C( 30516), -INT16_C( 20352), -INT16_C(   673),  INT16_C(  8194),
        -INT16_C( 11677), -INT16_C(  5402), -INT16_C(  8825),  INT16_C(  3025), -INT16_C(  7712), -INT16_C( 32605), -INT16_C( 26130), -INT16_C( 31200),
        -INT16_C( 25481),  INT16_C(  1412),  INT16_C(  1811),  INT16_C( 15910),  INT16_C( 18531),  INT16_C( 22701), -INT16_C( 16105), -INT16_C(  9076),
        -INT16_C(  3950), -INT16_C(  4366),  INT16_C(  6034), -INT16_C( 28387),  INT16_C( 32759), -INT16_C(  8173),  INT16_C( 21069),  INT16_C(  8631) },
      {       -INT16_MAX,        INT16_MIN,  INT16_C(     1),  INT16_C(     2),  INT16_C(     0),  INT16_C(     2), -INT16_C( 32753),  INT16_C(    16),
        -INT16_C( 32752), -INT16_C( 32753),        INT16_MIN, -INT16_C( 32754),  INT16_C(  9711), -INT16_C( 28619), -INT16_C(  6028), -INT16_C( 31956),
         INT16_C( 10717), -INT16_C( 30059), -INT16_C( 18002), -INT16_C( 27022), -INT16_C( 26292), -INT16_C(  9479),  INT16_C( 23773), -INT16_C( 18294),
        -INT16_C(  1030),  INT16_C(  5585), -INT16_C( 30221), -INT16_C(  7822), -INT16_C( 12243), -INT16_C( 10449), -INT16_C( 26932),  INT16_C(  1869),
         INT16_C( 13389),  INT16_C( 27434),  INT16_C(  5024),  INT16_C( 19722), -INT16_C( 30511), -INT16_C( 20351), -INT16_C(   671),  INT16_C(  8195),
        -INT16_C( 11675), -INT16_C(  5398), -INT16_C(  8824),  INT16_C(  3026), -INT16_C(  7711), -INT16_C( 32604), -INT16_C( 26129), -INT16_C( 31197),
        -INT16_C( 25476),  INT16_C(  1413),  INT16_C(  1812),  INT16_C( 15911),  INT16_C( 18537),  INT16_C( 22703), -INT16_C( 16104), -INT16_C(  9074),
        -INT16_C(  3949), -INT16_C(  4365),  INT16_C(  6037), -INT16_C( 28386),  INT16_C( 32761), -INT16_C(  8169),  INT16_C( 21070),  INT16_C(  8633) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vadd_vclb_VhVh(a, b);

    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i16_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i16_random(1);
    simde_hvx_vector_t r = simde_Q6_Vh_vadd_vclb_VhVh(a, b);

    simde_test_hvx_vector_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_vclb_VwVw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t b[SIMDE_HVX_VECTOR_I32_COUNT];
    int32_t r[SIMDE_HVX_VECTOR_I32_COUNT];
  } test_vec[] = {
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(  1194791600), -INT32_C(   703486149), -INT32_C(   590591907), -INT32_C(  1913676536),
        -INT32_C(   892977678),  INT32_C(   481294489), -INT32_C(  1026852842),  INT32_C(  1231401281), -INT32_C(    96145696),  INT32_C(  1755878539), -INT32_C(  1433801739),  INT32_C(  1317344048),
        -INT32_C(  1900935196), -INT32_C(   265972241), -INT32_C(  1270760366), -INT32_C(  1313753464), -INT32_C(  1405627996), -INT32_C(  1576776449), -INT32_C(  1760943697),  INT32_C(  1971879478) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(   823742940),  INT32_C(   137392432),  INT32_C(  1383220156),  INT32_C(   861110450),
         INT32_C(  1838616189),  INT32_C(  1456075617),  INT32_C(  1919343584),  INT32_C(   651255217),  INT32_C(   774787961),  INT32_C(   782859126), -INT32_C(  1539334449), -INT32_C(   358082312),
         INT32_C(   262077911), -INT32_C(  1157558692),  INT32_C(  1568583077), -INT32_C(  1246497635),  INT32_C(   908088842), -INT32_C(  1707786688),  INT32_C(   645498290), -INT32_C(  1371465521) },
      { -INT32_C(  2147483647),              INT32_MIN,  INT32_C(           1),  INT32_C(           2),  INT32_C(           0),  INT32_C(           2), -INT32_C(  2147483617),  INT32_C(          32),
        -INT32_C(  2147483616), -INT32_C(  2147483617),              INT32_MIN, -INT32_C(  2147483618),  INT32_C(   823742941),  INT32_C(   137392434),  INT32_C(  1383220158),  INT32_C(   861110451),
         INT32_C(  1838616191),  INT32_C(  1456075620),  INT32_C(  1919343586),  INT32_C(   651255218),  INT32_C(   774787966),  INT32_C(   782859127), -INT32_C(  1539334448), -INT32_C(   358082311),
         INT32_C(   262077912), -INT32_C(  1157558688),  INT32_C(  1568583078), -INT32_C(  1246497634),  INT32_C(   908088843), -INT32_C(  1707786687),  INT32_C(   645498291), -INT32_C(  1371465520) } },
    { {              INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1),
        -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1), -INT32_C(  1716429340), -INT32_C(   822807392),  INT32_C(  1665449982), -INT32_C(  1153237695),
        -INT32_C(  1666343567), -INT32_C(   281190343), -INT32_C(  1299429031),  INT32_C(   675635803),  INT32_C(   767977310),  INT32_C(   459925623),  INT32_C(  1460395134), -INT32_C(  1280418670),
        -INT32_C(  1066793315),  INT32_C(  1525511134),  INT32_C(  1621357760),  INT32_C(  1372469423), -INT32_C(  2100963427),  INT32_C(  1534217633), -INT32_C(   225891287),  INT32_C(  2065993971) },
      {              INT32_MIN,              INT32_MAX,  INT32_C(           0),  INT32_C(           1), -INT32_C(           1),  INT32_C(           1),              INT32_MAX,  INT32_C(           1),
                     INT32_MIN,              INT32_MIN,              INT32_MAX,              INT32_MAX, -INT32_C(  1026782257), -INT32_C(  1699356331), -INT32_C(  1301167173), -INT32_C(  1133168914),
        -INT32_C(   655907343),  INT32_C(  1923202277),  INT32_C(  1795678474),  INT32_C(   439289894),  INT32_C(  1417533661),  INT32_C(    78304951),  INT32_C(   591432944), -INT32_C(   743703032),
         INT32_C(   235564576),  INT32_C(   499838585), -INT32_C(   981536412),  INT32_C(  1168909144),  INT32_C(   982184787), -INT32_C(   492208275), -INT32_C(   646799590),  INT32_C(  1549843513) },
      { -INT32_C(  2147483647),              INT32_MIN,  INT32_C(           1),  INT32_C(           2),  INT32_C(           0),  INT32_C(           2), -INT32_C(  2147483617),  INT32_C(          32),
        -INT32_C(  2147483616), -INT32_C(  2147483617),              INT32_MIN, -INT32_C(  2147483618), -INT32_C(  1026782256), -INT32_C(  1699356329), -INT32_C(  1301167172), -INT32_C(  1133168913),
        -INT32_C(   655907342),  INT32_C(  1923202280),  INT32_C(  1795678475),  INT32_C(   439289896),  INT32_C(  1417533663),  INT32_C(    78304954),  INT32_C(   591432945), -INT32_C(   743703031),
         INT32_C(   235564578),  INT32_C(   499838586), -INT32_C(   981536411),  INT32_C(  1168909145),  INT32_C(   982184788), -INT32_C(   492208274), -INT32_C(   646799586),  INT32_C(  1549843514) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_vclb_VwVw(a, b);

    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', SIMDE_CODEGEN_FP);
  for (int i = 0 ; i < 2 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_i32_random(0);
    simde_hvx_vector_t b = simde_test_hvx_vector_i32_random(1);
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_vclb_VwVw(a, b);

    simde_test_hvx_vector_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VwVw)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VbVb_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VhVh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VwVw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VubVub_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VuhVuh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VuwVuw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_WbWb)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_WhWh)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_WwWw)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_WbWb_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_WhWh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_WwWw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_WubWub_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_WuhWuh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_WuwWuw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VubVub)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VhVh_widen)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VuhVuh_widen)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddacc_WhVubVub)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddacc_WwVhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddacc_WwVuhVuh)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VubVb_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VwVwQ_carry)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VwVwQ_carry_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_vclb_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_vclb_VwVw)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
