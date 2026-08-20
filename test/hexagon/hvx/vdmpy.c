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

#define SIMDE_TEST_HEXAGON_HVX_INSN vdmpy

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vdmpy.h"

static int
test_simde_vdmpy_VubRb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t rt;
    int16_t r[64];
  } test_vec[] = {
    { {
        INT8_C(   3),  INT8_C(  10),  INT8_C(  17),  INT8_C(  24),  INT8_C(  31),  INT8_C(  38),  INT8_C(  45),  INT8_C(  52),
        INT8_C(  59),  INT8_C(  66),  INT8_C(  73),  INT8_C(  80),  INT8_C(  87),  INT8_C(  94),  INT8_C( 101),  INT8_C( 108),
        INT8_C( 115),  INT8_C( 122), -INT8_C( 127), -INT8_C( 120), -INT8_C( 113), -INT8_C( 106), -INT8_C(  99), -INT8_C(  92),
       -INT8_C(  85), -INT8_C(  78), -INT8_C(  71), -INT8_C(  64), -INT8_C(  57), -INT8_C(  50), -INT8_C(  43), -INT8_C(  36),
       -INT8_C(  29), -INT8_C(  22), -INT8_C(  15), -INT8_C(   8), -INT8_C(   1),  INT8_C(   6),  INT8_C(  13),  INT8_C(  20),
        INT8_C(  27),  INT8_C(  34),  INT8_C(  41),  INT8_C(  48),  INT8_C(  55),  INT8_C(  62),  INT8_C(  69),  INT8_C(  76),
        INT8_C(  83),  INT8_C(  90),  INT8_C(  97),  INT8_C( 104),  INT8_C( 111),  INT8_C( 118),  INT8_C( 125), -INT8_C( 124),
       -INT8_C( 117), -INT8_C( 110), -INT8_C( 103), -INT8_C(  96), -INT8_C(  89), -INT8_C(  82), -INT8_C(  75), -INT8_C(  68),
       -INT8_C(  61), -INT8_C(  54), -INT8_C(  47), -INT8_C(  40), -INT8_C(  33), -INT8_C(  26), -INT8_C(  19), -INT8_C(  12),
       -INT8_C(   5),  INT8_C(   2),  INT8_C(   9),  INT8_C(  16),  INT8_C(  23),  INT8_C(  30),  INT8_C(  37),  INT8_C(  44),
        INT8_C(  51),  INT8_C(  58),  INT8_C(  65),  INT8_C(  72),  INT8_C(  79),  INT8_C(  86),  INT8_C(  93),  INT8_C( 100),
        INT8_C( 107),  INT8_C( 114),  INT8_C( 121), -INT8_C( 128), -INT8_C( 121), -INT8_C( 114), -INT8_C( 107), -INT8_C( 100),
       -INT8_C(  93), -INT8_C(  86), -INT8_C(  79), -INT8_C(  72), -INT8_C(  65), -INT8_C(  58), -INT8_C(  51), -INT8_C(  44),
       -INT8_C(  37), -INT8_C(  30), -INT8_C(  23), -INT8_C(  16), -INT8_C(   9), -INT8_C(   2),  INT8_C(   5),  INT8_C(  12),
        INT8_C(  19),  INT8_C(  26),  INT8_C(  33),  INT8_C(  40),  INT8_C(  47),  INT8_C(  54),  INT8_C(  61),  INT8_C(  68),
        INT8_C(  75),  INT8_C(  82),  INT8_C(  89),  INT8_C(  96),  INT8_C( 103),  INT8_C( 110),  INT8_C( 117),  INT8_C( 124)
      },
      INT32_C(66912773),
      {
        INT16_C(    35),  INT16_C(    21),  INT16_C(   231),  INT16_C(    21),  INT16_C(   427),  INT16_C(    21),  INT16_C(   623),  INT16_C(    21),
        INT16_C(   819),  INT16_C(    21),  INT16_C(  1015),  INT16_C(    21),  INT16_C(  1211),  INT16_C(    21),  INT16_C(  1407),  INT16_C(    21),
        INT16_C(  1603),  INT16_C(    21),  INT16_C(  1287),  INT16_C(    21),  INT16_C(   203),  INT16_C(    21),  INT16_C(   399),  INT16_C(    21),
        INT16_C(   595),  INT16_C(    21),  INT16_C(   791),  INT16_C(    21),  INT16_C(   987),  INT16_C(    21),  INT16_C(  1183),  INT16_C(    21),
        INT16_C(  1379),  INT16_C(    21),  INT16_C(  1575),  INT16_C(    21),  INT16_C(  1259),  INT16_C(    21),  INT16_C(   175),  INT16_C(    21),
        INT16_C(   371),  INT16_C(    21),  INT16_C(   567),  INT16_C(    21),  INT16_C(   763),  INT16_C(    21),  INT16_C(   959),  INT16_C(    21),
        INT16_C(  1155),  INT16_C(    21),  INT16_C(  1351),  INT16_C(    21),  INT16_C(  1547),  INT16_C(    21),  INT16_C(  1743),  INT16_C(    21),
        INT16_C(   147),  INT16_C(    21),  INT16_C(   343),  INT16_C(    21),  INT16_C(   539),  INT16_C(    21),  INT16_C(   735),  INT16_C(    21)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vh_vdmpy_VubRb(a, test_vec[i].rt);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vdmpy_VhRb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t rt;
    int32_t r[32];
  } test_vec[] = {
    { {
        INT8_C(   3),  INT8_C(  10),  INT8_C(  17),  INT8_C(  24),  INT8_C(  31),  INT8_C(  38),  INT8_C(  45),  INT8_C(  52),
        INT8_C(  59),  INT8_C(  66),  INT8_C(  73),  INT8_C(  80),  INT8_C(  87),  INT8_C(  94),  INT8_C( 101),  INT8_C( 108),
        INT8_C( 115),  INT8_C( 122), -INT8_C( 127), -INT8_C( 120), -INT8_C( 113), -INT8_C( 106), -INT8_C(  99), -INT8_C(  92),
       -INT8_C(  85), -INT8_C(  78), -INT8_C(  71), -INT8_C(  64), -INT8_C(  57), -INT8_C(  50), -INT8_C(  43), -INT8_C(  36),
       -INT8_C(  29), -INT8_C(  22), -INT8_C(  15), -INT8_C(   8), -INT8_C(   1),  INT8_C(   6),  INT8_C(  13),  INT8_C(  20),
        INT8_C(  27),  INT8_C(  34),  INT8_C(  41),  INT8_C(  48),  INT8_C(  55),  INT8_C(  62),  INT8_C(  69),  INT8_C(  76),
        INT8_C(  83),  INT8_C(  90),  INT8_C(  97),  INT8_C( 104),  INT8_C( 111),  INT8_C( 118),  INT8_C( 125), -INT8_C( 124),
       -INT8_C( 117), -INT8_C( 110), -INT8_C( 103), -INT8_C(  96), -INT8_C(  89), -INT8_C(  82), -INT8_C(  75), -INT8_C(  68),
       -INT8_C(  61), -INT8_C(  54), -INT8_C(  47), -INT8_C(  40), -INT8_C(  33), -INT8_C(  26), -INT8_C(  19), -INT8_C(  12),
       -INT8_C(   5),  INT8_C(   2),  INT8_C(   9),  INT8_C(  16),  INT8_C(  23),  INT8_C(  30),  INT8_C(  37),  INT8_C(  44),
        INT8_C(  51),  INT8_C(  58),  INT8_C(  65),  INT8_C(  72),  INT8_C(  79),  INT8_C(  86),  INT8_C(  93),  INT8_C( 100),
        INT8_C( 107),  INT8_C( 114),  INT8_C( 121), -INT8_C( 128), -INT8_C( 121), -INT8_C( 114), -INT8_C( 107), -INT8_C( 100),
       -INT8_C(  93), -INT8_C(  86), -INT8_C(  79), -INT8_C(  72), -INT8_C(  65), -INT8_C(  58), -INT8_C(  51), -INT8_C(  44),
       -INT8_C(  37), -INT8_C(  30), -INT8_C(  23), -INT8_C(  16), -INT8_C(   9), -INT8_C(   2),  INT8_C(   5),  INT8_C(  12),
        INT8_C(  19),  INT8_C(  26),  INT8_C(  33),  INT8_C(  40),  INT8_C(  47),  INT8_C(  54),  INT8_C(  61),  INT8_C(  68),
        INT8_C(  75),  INT8_C(  82),  INT8_C(  89),  INT8_C(  96),  INT8_C( 103),  INT8_C( 110),  INT8_C( 117),  INT8_C( 124)
      },
      INT32_C(66912773),
      {
        INT32_C(  25137),  INT32_C(  10794),  INT32_C( 125881),  INT32_C(  10794),
        INT32_C(  95553),  INT32_C(  10794), -INT32_C( 131383),  INT32_C(  10794),
       -INT32_C(  30639),  INT32_C(  10026),  INT32_C(  68313),  INT32_C(  10794),
        INT32_C( 169057), -INT32_C( 185814), -INT32_C( 188951),  INT32_C(  10794),
       -INT32_C(  88207),  INT32_C(  10794),  INT32_C(  12025),  INT32_C(  10794),
        INT32_C( 111489),  INT32_C(  10794),  INT32_C(  81161),  INT32_C(  10794),
       -INT32_C( 145775),  INT32_C(  10794), -INT32_C(  45031),  INT32_C(  10026),
        INT32_C(  53921),  INT32_C(  10794),  INT32_C( 154665),  INT32_C(  10794)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vw_vdmpy_VhRb(a, test_vec[i].rt);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vdmpy_VhVh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t r[32];
  } test_vec[] = {
    { {
        INT8_C(   3),  INT8_C(  10),  INT8_C(  17),  INT8_C(  24),  INT8_C(  31),  INT8_C(  38),  INT8_C(  45),  INT8_C(  52),
        INT8_C(  59),  INT8_C(  66),  INT8_C(  73),  INT8_C(  80),  INT8_C(  87),  INT8_C(  94),  INT8_C( 101),  INT8_C( 108),
        INT8_C( 115),  INT8_C( 122), -INT8_C( 127), -INT8_C( 120), -INT8_C( 113), -INT8_C( 106), -INT8_C(  99), -INT8_C(  92),
       -INT8_C(  85), -INT8_C(  78), -INT8_C(  71), -INT8_C(  64), -INT8_C(  57), -INT8_C(  50), -INT8_C(  43), -INT8_C(  36),
       -INT8_C(  29), -INT8_C(  22), -INT8_C(  15), -INT8_C(   8), -INT8_C(   1),  INT8_C(   6),  INT8_C(  13),  INT8_C(  20),
        INT8_C(  27),  INT8_C(  34),  INT8_C(  41),  INT8_C(  48),  INT8_C(  55),  INT8_C(  62),  INT8_C(  69),  INT8_C(  76),
        INT8_C(  83),  INT8_C(  90),  INT8_C(  97),  INT8_C( 104),  INT8_C( 111),  INT8_C( 118),  INT8_C( 125), -INT8_C( 124),
       -INT8_C( 117), -INT8_C( 110), -INT8_C( 103), -INT8_C(  96), -INT8_C(  89), -INT8_C(  82), -INT8_C(  75), -INT8_C(  68),
       -INT8_C(  61), -INT8_C(  54), -INT8_C(  47), -INT8_C(  40), -INT8_C(  33), -INT8_C(  26), -INT8_C(  19), -INT8_C(  12),
       -INT8_C(   5),  INT8_C(   2),  INT8_C(   9),  INT8_C(  16),  INT8_C(  23),  INT8_C(  30),  INT8_C(  37),  INT8_C(  44),
        INT8_C(  51),  INT8_C(  58),  INT8_C(  65),  INT8_C(  72),  INT8_C(  79),  INT8_C(  86),  INT8_C(  93),  INT8_C( 100),
        INT8_C( 107),  INT8_C( 114),  INT8_C( 121), -INT8_C( 128), -INT8_C( 121), -INT8_C( 114), -INT8_C( 107), -INT8_C( 100),
       -INT8_C(  93), -INT8_C(  86), -INT8_C(  79), -INT8_C(  72), -INT8_C(  65), -INT8_C(  58), -INT8_C(  51), -INT8_C(  44),
       -INT8_C(  37), -INT8_C(  30), -INT8_C(  23), -INT8_C(  16), -INT8_C(   9), -INT8_C(   2),  INT8_C(   5),  INT8_C(  12),
        INT8_C(  19),  INT8_C(  26),  INT8_C(  33),  INT8_C(  40),  INT8_C(  47),  INT8_C(  54),  INT8_C(  61),  INT8_C(  68),
        INT8_C(  75),  INT8_C(  82),  INT8_C(  89),  INT8_C(  96),  INT8_C( 103),  INT8_C( 110),  INT8_C( 117),  INT8_C( 124)
      },
      {
        INT8_C(  11),  INT8_C(  24),  INT8_C(  37),  INT8_C(  50),  INT8_C(  63),  INT8_C(  76),  INT8_C(  89),  INT8_C( 102),
        INT8_C( 115), -INT8_C( 128), -INT8_C( 115), -INT8_C( 102), -INT8_C(  89), -INT8_C(  76), -INT8_C(  63), -INT8_C(  50),
       -INT8_C(  37), -INT8_C(  24), -INT8_C(  11),  INT8_C(   2),  INT8_C(  15),  INT8_C(  28),  INT8_C(  41),  INT8_C(  54),
        INT8_C(  67),  INT8_C(  80),  INT8_C(  93),  INT8_C( 106),  INT8_C( 119), -INT8_C( 124), -INT8_C( 111), -INT8_C(  98),
       -INT8_C(  85), -INT8_C(  72), -INT8_C(  59), -INT8_C(  46), -INT8_C(  33), -INT8_C(  20), -INT8_C(   7),  INT8_C(   6),
        INT8_C(  19),  INT8_C(  32),  INT8_C(  45),  INT8_C(  58),  INT8_C(  71),  INT8_C(  84),  INT8_C(  97),  INT8_C( 110),
        INT8_C( 123), -INT8_C( 120), -INT8_C( 107), -INT8_C(  94), -INT8_C(  81), -INT8_C(  68), -INT8_C(  55), -INT8_C(  42),
       -INT8_C(  29), -INT8_C(  16), -INT8_C(   3),  INT8_C(  10),  INT8_C(  23),  INT8_C(  36),  INT8_C(  49),  INT8_C(  62),
        INT8_C(  75),  INT8_C(  88),  INT8_C( 101),  INT8_C( 114),  INT8_C( 127), -INT8_C( 116), -INT8_C( 103), -INT8_C(  90),
       -INT8_C(  77), -INT8_C(  64), -INT8_C(  51), -INT8_C(  38), -INT8_C(  25), -INT8_C(  12),  INT8_C(   1),  INT8_C(  14),
        INT8_C(  27),  INT8_C(  40),  INT8_C(  53),  INT8_C(  66),  INT8_C(  79),  INT8_C(  92),  INT8_C( 105),  INT8_C( 118),
       -INT8_C( 125), -INT8_C( 112), -INT8_C(  99), -INT8_C(  86), -INT8_C(  73), -INT8_C(  60), -INT8_C(  47), -INT8_C(  34),
       -INT8_C(  21), -INT8_C(   8),  INT8_C(   5),  INT8_C(  18),  INT8_C(  31),  INT8_C(  44),  INT8_C(  57),  INT8_C(  70),
        INT8_C(  83),  INT8_C(  96),  INT8_C( 109),  INT8_C( 122), -INT8_C( 121), -INT8_C( 108), -INT8_C(  95), -INT8_C(  82),
       -INT8_C(  69), -INT8_C(  56), -INT8_C(  43), -INT8_C(  30), -INT8_C(  17), -INT8_C(   4),  INT8_C(   9),  INT8_C(  22),
        INT8_C(  35),  INT8_C(  48),  INT8_C(  61),  INT8_C(  74),  INT8_C(  87),  INT8_C( 100),  INT8_C( 113),  INT8_C( 126)
      },
      {
        INT32_C(  94864022),  INT32_C( 540452678), -INT32_C(1087413578), -INT32_C( 815680282),
       -INT32_C( 208888362), -INT32_C( 518262394), -INT32_C( 847851530),  INT32_C( 623068454),
        INT32_C( 119623958),  INT32_C(    391878),  INT32_C( 255306038),  INT32_C( 895342950),
       -INT32_C(1346527146), -INT32_C( 188875258),  INT32_C(  39711350), -INT32_C( 466673242),
       -INT32_C( 601814122),  INT32_C( 255102022), -INT32_C(  51456330),  INT32_C(  18629862),
        INT32_C( 466473686),  INT32_C(1300958854), -INT32_C( 122363658),  INT32_C( 657082918),
       -INT32_C(  44590826), -INT32_C( 364358458), -INT32_C( 305051082), -INT32_C(  56806042),
       -INT32_C( 171153066),  INT32_C(  87653894),  INT32_C( 728366966),  INT32_C(1757300390)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vdmpy_VhVh_sat(a, b);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vdmpy_VhRh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t rt;
    int32_t r[32];
  } test_vec[] = {
    { {
        INT8_C(   3),  INT8_C(  10),  INT8_C(  17),  INT8_C(  24),  INT8_C(  31),  INT8_C(  38),  INT8_C(  45),  INT8_C(  52),
        INT8_C(  59),  INT8_C(  66),  INT8_C(  73),  INT8_C(  80),  INT8_C(  87),  INT8_C(  94),  INT8_C( 101),  INT8_C( 108),
        INT8_C( 115),  INT8_C( 122), -INT8_C( 127), -INT8_C( 120), -INT8_C( 113), -INT8_C( 106), -INT8_C(  99), -INT8_C(  92),
       -INT8_C(  85), -INT8_C(  78), -INT8_C(  71), -INT8_C(  64), -INT8_C(  57), -INT8_C(  50), -INT8_C(  43), -INT8_C(  36),
       -INT8_C(  29), -INT8_C(  22), -INT8_C(  15), -INT8_C(   8), -INT8_C(   1),  INT8_C(   6),  INT8_C(  13),  INT8_C(  20),
        INT8_C(  27),  INT8_C(  34),  INT8_C(  41),  INT8_C(  48),  INT8_C(  55),  INT8_C(  62),  INT8_C(  69),  INT8_C(  76),
        INT8_C(  83),  INT8_C(  90),  INT8_C(  97),  INT8_C( 104),  INT8_C( 111),  INT8_C( 118),  INT8_C( 125), -INT8_C( 124),
       -INT8_C( 117), -INT8_C( 110), -INT8_C( 103), -INT8_C(  96), -INT8_C(  89), -INT8_C(  82), -INT8_C(  75), -INT8_C(  68),
       -INT8_C(  61), -INT8_C(  54), -INT8_C(  47), -INT8_C(  40), -INT8_C(  33), -INT8_C(  26), -INT8_C(  19), -INT8_C(  12),
       -INT8_C(   5),  INT8_C(   2),  INT8_C(   9),  INT8_C(  16),  INT8_C(  23),  INT8_C(  30),  INT8_C(  37),  INT8_C(  44),
        INT8_C(  51),  INT8_C(  58),  INT8_C(  65),  INT8_C(  72),  INT8_C(  79),  INT8_C(  86),  INT8_C(  93),  INT8_C( 100),
        INT8_C( 107),  INT8_C( 114),  INT8_C( 121), -INT8_C( 128), -INT8_C( 121), -INT8_C( 114), -INT8_C( 107), -INT8_C( 100),
       -INT8_C(  93), -INT8_C(  86), -INT8_C(  79), -INT8_C(  72), -INT8_C(  65), -INT8_C(  58), -INT8_C(  51), -INT8_C(  44),
       -INT8_C(  37), -INT8_C(  30), -INT8_C(  23), -INT8_C(  16), -INT8_C(   9), -INT8_C(   2),  INT8_C(   5),  INT8_C(  12),
        INT8_C(  19),  INT8_C(  26),  INT8_C(  33),  INT8_C(  40),  INT8_C(  47),  INT8_C(  54),  INT8_C(  61),  INT8_C(  68),
        INT8_C(  75),  INT8_C(  82),  INT8_C(  89),  INT8_C(  96),  INT8_C( 103),  INT8_C( 110),  INT8_C( 117),  INT8_C( 124)
      },
      INT32_C(327683),
      {
        INT32_C(  38494),  INT32_C(  96062),  INT32_C( 153630),  INT32_C( 211198),
       -INT32_C(  58914), -INT32_C( 197954), -INT32_C( 140386), -INT32_C(  82818),
       -INT32_C(  25250),  INT32_C(  31038),  INT32_C(  87838),  INT32_C( 145406),
        INT32_C( 202974), -INT32_C(  67138), -INT32_C( 206178), -INT32_C( 148610),
       -INT32_C(  91042), -INT32_C(  33474),  INT32_C(  22814),  INT32_C(  79614),
        INT32_C( 137182),  INT32_C( 194750), -INT32_C(  75362), -INT32_C( 214402),
       -INT32_C( 156834), -INT32_C(  99266), -INT32_C(  41698),  INT32_C(  14590),
        INT32_C(  71390),  INT32_C( 128958),  INT32_C( 186526),  INT32_C( 244094)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vw_vdmpy_VhRh_sat(a, test_vec[i].rt);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vdmpyacc_focused(SIMDE_MUNIT_TEST_ARGS) {
  uint8_t ub[SIMDE_HVX_VECTOR_SIZE];
  int16_t h[SIMDE_HVX_VECTOR_I16_COUNT], ah[SIMDE_HVX_VECTOR_I16_COUNT], bh[SIMDE_HVX_VECTOR_I16_COUNT], eh[SIMDE_HVX_VECTOR_I16_COUNT];
  int32_t w[SIMDE_HVX_VECTOR_I32_COUNT], ew[SIMDE_HVX_VECTOR_I32_COUNT];
  int16_t pair_h[SIMDE_HVX_VECTOR_I16_COUNT * 2] = { 0 };
  simde_hvx_vector_t vu, vv, vx, r;
  simde_hvx_vectorpair_t wu;

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
    ub[2 * i] = 10;
    ub[2 * i + 1] = 20;
    h[i] = 100;
    eh[i] = (i & 1) ? 10 : 60;
  }
  vu = simde_test_hvx_vector_load(ub);
  vx = simde_test_hvx_vector_load(h);
  r = simde_Q6_Vh_vdmpyacc_VhVubRb(vx, vu, INT32_C(0xf905fd02));
  simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(eh));

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
    w[i] = (i & 1) ? (INT32_MIN + 10) : (INT32_MAX - 10);
    ah[2 * i] = 100;
    ah[2 * i + 1] = 200;
    bh[2 * i] = (i & 1) ? -3 : 3;
    bh[2 * i + 1] = (i & 1) ? -4 : 4;
    ew[i] = (i & 1) ? INT32_MIN : INT32_MAX;
  }
  vx = simde_test_hvx_vector_load(w);
  vu = simde_test_hvx_vector_load(ah);
  vv = simde_test_hvx_vector_load(bh);
  r = simde_Q6_Vw_vdmpyacc_VwVhVh_sat(vx, vu, vv);
  simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(ew));

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
    w[i] = 0;
    pair_h[2 * i + 1] = (i & 1) ? INT16_MIN : INT16_MAX;
    pair_h[SIMDE_HVX_VECTOR_I16_COUNT + 2 * i] = (i & 1) ? INT16_MIN : INT16_MAX;
    ew[i] = (i & 1) ? INT32_MIN : INT32_MAX;
  }
  simde_memcpy(&wu, pair_h, sizeof(wu));
  vx = simde_test_hvx_vector_load(w);
  r = simde_Q6_Vw_vdmpyacc_VwWhRuh_sat(vx, wu, INT32_C(0xfffeffff));
  simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(ew));

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vdmpy_VubRb)
SIMDE_TEST_FUNC_LIST_ENTRY(vdmpy_VhRb)
SIMDE_TEST_FUNC_LIST_ENTRY(vdmpy_VhVh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vdmpy_VhRh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vdmpyacc_focused)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
