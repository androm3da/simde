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

#define SIMDE_TEST_HEXAGON_HVX_INSN vxor

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vxor.h"

static int
test_simde_vxor_VV(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int8_t r[128];
  } test_vec[] = {
    { /* a */ {  INT8_C(  76),  INT8_C( 104), -INT8_C( 121),  INT8_C(  26),  INT8_C(  54),  INT8_C( 109), -INT8_C(   9),  INT8_C(  71),
               -INT8_C(  75),  INT8_C( 101), -INT8_C( 119),  INT8_C(  69),  INT8_C(  20),  INT8_C( 109),  INT8_C(  81),  INT8_C(  76),
                INT8_C(  53),  INT8_C(  28),  INT8_C( 114),  INT8_C(  79),  INT8_C(  22), -INT8_C(  88), -INT8_C( 102),  INT8_C(   9),
                INT8_C(  13), -INT8_C( 121), -INT8_C(  87),  INT8_C(  22),  INT8_C(  56),  INT8_C(  69),  INT8_C(  29),  INT8_C( 115),
               -INT8_C(  80),  INT8_C( 122),  INT8_C(   9),  INT8_C(  33),  INT8_C(  54),  INT8_C(  58),  INT8_C(  66), -INT8_C(  73),
                INT8_C(  50),  INT8_C(  17),  INT8_C(  86),  INT8_C(  42), -INT8_C( 108), -INT8_C(  44),  INT8_C(  55), -INT8_C(  81),
               -INT8_C(  34), -INT8_C(  13), -INT8_C( 113), -INT8_C(  45),  INT8_C(  35), -INT8_C( 125), -INT8_C(  32),  INT8_C(  64),
                INT8_C(  55), -INT8_C(  70), -INT8_C(  97),  INT8_C(  56), -INT8_C(  60), -INT8_C(  35),  INT8_C( 114),  INT8_C( 106),
               -INT8_C(  62), -INT8_C( 120), -INT8_C(  28),  INT8_C(  91), -INT8_C(  40),  INT8_C(  96),  INT8_C(  76), -INT8_C(  58),
               -INT8_C(  55),  INT8_C(  19),  INT8_C(  56), -INT8_C( 104),  INT8_C(  59),  INT8_C( 111), -INT8_C(  16),  INT8_C(  73),
                INT8_C(  47), -INT8_C(  44),  INT8_C(  10),  INT8_C(  37), -INT8_C(  45),  INT8_C(  61), -INT8_C(  73),  INT8_C(  74),
                INT8_C(  75), -INT8_C(  63), -INT8_C(  52),  INT8_C( 126),  INT8_C(  62), -INT8_C(  82),  INT8_C(  12), -INT8_C(  54),
               -INT8_C(  29), -INT8_C( 117), -INT8_C(  84),  INT8_C(  99),  INT8_C(  50), -INT8_C(  65), -INT8_C(   6),  INT8_C(  15),
                INT8_C(  42),  INT8_C(  13),  INT8_C(  20),  INT8_C(  78), -INT8_C(  72), -INT8_C(  59), -INT8_C( 112),  INT8_C(  97),
                INT8_C(  50),  INT8_C( 105), -INT8_C(  22),  INT8_C( 119), -INT8_C(  17), -INT8_C(  96),  INT8_C(  84),  INT8_C(  59),
                INT8_C(  54),  INT8_C( 109),  INT8_C(  83),  INT8_C(  73), -INT8_C( 117),  INT8_C(  10), -INT8_C( 103),  INT8_C(  99) },
      /* b */ { -INT8_C(  96), -INT8_C( 120),  INT8_C(  98), -INT8_C(  45),  INT8_C(   2),  INT8_C(  20),  INT8_C( 115), -INT8_C(   7),
                INT8_C(  61),  INT8_C(  95),  INT8_C(  52), -INT8_C(  19),  INT8_C(   0),  INT8_C(  96),  INT8_C(  90), -INT8_C(  83),
                INT8_C(  63), -INT8_C(  22),  INT8_C(  81),  INT8_C(  35),  INT8_C(  77), -INT8_C( 100),  INT8_C(  55), -INT8_C(  91),
               -INT8_C(  14),  INT8_C(  72),  INT8_C(  33), -INT8_C(  33),  INT8_C(  89),  INT8_C(  55), -INT8_C(  41),  INT8_C(  97),
               -INT8_C(  83),  INT8_C(  32),  INT8_C(  59), -INT8_C(  47),  INT8_C(  98), -INT8_C(  67),  INT8_C(  10), -INT8_C(  95),
                INT8_C(  12),  INT8_C( 110), -INT8_C(  50), -INT8_C(  33),  INT8_C( 108), -INT8_C(  18),  INT8_C(  44),  INT8_C(  92),
                INT8_C(  33), -INT8_C( 101), -INT8_C(   2),  INT8_C(  70), -INT8_C(  73),  INT8_C( 126), -INT8_C(  95), -INT8_C(  35),
               -INT8_C(  12),  INT8_C(  19),  INT8_C( 113),  INT8_C( 113),  INT8_C(  49),  INT8_C(   8), -INT8_C(  86),  INT8_C(  72),
                INT8_C(  16),  INT8_C( 107),  INT8_C(  63),  INT8_C(  29), -INT8_C(  55),  INT8_C(  99),  INT8_C(  22), -INT8_C(  40),
                INT8_C(  58), -INT8_C(  82),  INT8_C(  17), -INT8_C(   4),  INT8_C(  87),  INT8_C(  37), -INT8_C(  76), -INT8_C(  20),
               -INT8_C(  70), -INT8_C(  89),  INT8_C( 101), -INT8_C(  20), -INT8_C(  67), -INT8_C(  59),  INT8_C( 114),  INT8_C(  43),
                INT8_C(  17), -INT8_C(  77),  INT8_C(  35), -INT8_C(  85),  INT8_C( 124), -INT8_C(  91), -INT8_C( 103), -INT8_C( 114),
               -INT8_C(  81),  INT8_C(  35), -INT8_C(  34),  INT8_C(  27), -INT8_C( 115),  INT8_C(  75), -INT8_C(  41), -INT8_C(  49),
                INT8_C(  72), -INT8_C(  31), -INT8_C(  56),  INT8_C( 103),  INT8_C(  66),  INT8_C(  24), -INT8_C(  90),  INT8_C(  16),
               -INT8_C(  45), -INT8_C(  39), -INT8_C( 109), -INT8_C(  77),  INT8_C(  23),  INT8_C(  71), -INT8_C(  53),  INT8_C(  19),
               -INT8_C(  21),  INT8_C( 101), -INT8_C(  93),  INT8_C(  22),  INT8_C(  39),  INT8_C(  47), -INT8_C(  54),  INT8_C(  88) },
      /* r = a ^ b */
              { -INT8_C(  20), -INT8_C(  32), -INT8_C(  27), -INT8_C(  55),  INT8_C(  52),  INT8_C( 121), -INT8_C( 124), -INT8_C(  66),
               -INT8_C( 120),  INT8_C(  58), -INT8_C(  67), -INT8_C(  88),  INT8_C(  20),  INT8_C(  13),  INT8_C(  11), -INT8_C(  31),
                INT8_C(  10), -INT8_C(  10),  INT8_C(  35),  INT8_C( 108),  INT8_C(  91),  INT8_C(  52), -INT8_C(  83), -INT8_C(  84),
               -INT8_C(   1), -INT8_C(  49), -INT8_C( 120), -INT8_C(  55),  INT8_C(  97),  INT8_C( 114), -INT8_C(  54),  INT8_C(  18),
                INT8_C(  29),  INT8_C(  90),  INT8_C(  50), -INT8_C(  16),  INT8_C(  84), -INT8_C( 121),  INT8_C(  72),  INT8_C(  22),
                INT8_C(  62),  INT8_C( 127), -INT8_C( 104), -INT8_C(  11), -INT8_C(   8),  INT8_C(  58),  INT8_C(  27), -INT8_C(  13),
               -INT8_C(   1),  INT8_C( 104),  INT8_C( 113), -INT8_C( 107), -INT8_C( 108), -INT8_C(   3),  INT8_C(  65), -INT8_C(  99),
               -INT8_C(  61), -INT8_C(  87), -INT8_C(  18),  INT8_C(  73), -INT8_C(  11), -INT8_C(  43), -INT8_C(  40),  INT8_C(  34),
               -INT8_C(  46), -INT8_C(  29), -INT8_C(  37),  INT8_C(  70),  INT8_C(  17),  INT8_C(   3),  INT8_C(  90),  INT8_C(  30),
               -INT8_C(  13), -INT8_C(  67),  INT8_C(  41),  INT8_C( 100),  INT8_C( 108),  INT8_C(  74),  INT8_C(  68), -INT8_C(  91),
               -INT8_C( 107),  INT8_C( 115),  INT8_C( 111), -INT8_C(  55),  INT8_C( 110), -INT8_C(   8), -INT8_C(  59),  INT8_C(  97),
                INT8_C(  90),  INT8_C( 114), -INT8_C(  17), -INT8_C(  43),  INT8_C(  66),  INT8_C(  11), -INT8_C( 107),  INT8_C(  68),
                INT8_C(  76), -INT8_C(  88),  INT8_C( 114),  INT8_C( 120), -INT8_C(  65), -INT8_C(  12),  INT8_C(  45), -INT8_C(  64),
                INT8_C(  98), -INT8_C(  20), -INT8_C(  36),  INT8_C(  41), -INT8_C(   6), -INT8_C(  35),  INT8_C(  54),  INT8_C( 113),
               -INT8_C(  31), -INT8_C(  80),  INT8_C( 121), -INT8_C(  60), -INT8_C(   8), -INT8_C(  25), -INT8_C(  97),  INT8_C(  40),
               -INT8_C(  35),  INT8_C(   8), -INT8_C(  16),  INT8_C(  95), -INT8_C(  84),  INT8_C(  37),  INT8_C(  83),  INT8_C(  59) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_V_vxor_VV(a, b);

    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_random();
    simde_hvx_vector_t b = simde_test_hvx_vector_random();
    simde_hvx_vector_t r = simde_Q6_V_vxor_VV(a, b);

    simde_test_hvx_vector_i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vxor_VV)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
