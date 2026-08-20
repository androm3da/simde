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

#define SIMDE_TEST_HEXAGON_HVX_INSN vround

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vround.h"

static int
test_simde_vround_VwVw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
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
       INT16_C( 12837),  INT16_C(  6161),  INT16_C( 26201),  INT16_C( 13357),
      -INT16_C( 25970),  INT16_C( 20553), -INT16_C( 12606),  INT16_C( 27749),
       INT16_C(   758), -INT16_C( 30591),  INT16_C( 13865), -INT16_C( 23394),
       INT16_C( 27229), -INT16_C( 16198), -INT16_C( 24942), -INT16_C(  9002),
      -INT16_C( 11578), -INT16_C(  1806),  INT16_C(  1786),  INT16_C(  5133),
       INT16_C( 14893),  INT16_C( 12329),  INT16_C( 28257),  INT16_C( 19525),
      -INT16_C( 23914),  INT16_C( 26721), -INT16_C( 10550), -INT16_C( 31619),
       INT16_C(  2814), -INT16_C( 24422),  INT16_C( 15921), -INT16_C( 17226),
       INT16_C( 29285), -INT16_C( 10030), -INT16_C( 22886), -INT16_C(  2834),
      -INT16_C(  9522),  INT16_C(  4105),  INT16_C(  3586),  INT16_C( 11301),
       INT16_C( 16949),  INT16_C( 18497),  INT16_C( 30313),  INT16_C( 25693),
      -INT16_C( 21858), -INT16_C( 32647), -INT16_C(  8494), -INT16_C( 25450),
       INT16_C(  4614), -INT16_C( 18254),  INT16_C( 17977), -INT16_C( 11058),
       INT16_C( 31341), -INT16_C(  3862), -INT16_C( 20830),  INT16_C(  3078),
      -INT16_C(  7466),  INT16_C( 10273),  INT16_C(  5642),  INT16_C( 17469),
       INT16_C( 19005),  INT16_C( 24665),  INT16_C( 32369),  INT16_C( 31861)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vround_VwVw_sat(a, b);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vround_VwVw_sat_u(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    uint16_t r[64];
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
      UINT16_C(12837), UINT16_C( 6161), UINT16_C(26201), UINT16_C(13357),
      UINT16_C(    0), UINT16_C(20553), UINT16_C(    0), UINT16_C(27749),
      UINT16_C(  758), UINT16_C(    0), UINT16_C(13865), UINT16_C(    0),
      UINT16_C(27229), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C( 1786), UINT16_C( 5133),
      UINT16_C(14893), UINT16_C(12329), UINT16_C(28257), UINT16_C(19525),
      UINT16_C(    0), UINT16_C(26721), UINT16_C(    0), UINT16_C(    0),
      UINT16_C( 2814), UINT16_C(    0), UINT16_C(15921), UINT16_C(    0),
      UINT16_C(29285), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C( 4105), UINT16_C( 3586), UINT16_C(11301),
      UINT16_C(16949), UINT16_C(18497), UINT16_C(30313), UINT16_C(25693),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C( 4614), UINT16_C(    0), UINT16_C(17977), UINT16_C(    0),
      UINT16_C(31341), UINT16_C(    0), UINT16_C(    0), UINT16_C( 3078),
      UINT16_C(    0), UINT16_C(10273), UINT16_C( 5642), UINT16_C(17469),
      UINT16_C(19005), UINT16_C(24665), UINT16_C(32369), UINT16_C(31861)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuh_vround_VwVw_sat(a, b);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vround_VhVh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int8_t r[128];
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
       INT8_C(  24),  INT8_C(  10),  INT8_C(  50),  INT8_C(  24),  INT8_C(  76),  INT8_C(  38),  INT8_C( 102),  INT8_C(  52),
      -INT8_C( 128),  INT8_C(  66), -INT8_C( 101),  INT8_C(  80), -INT8_C(  75),  INT8_C(  94), -INT8_C(  49),  INT8_C( 108),
      -INT8_C(  23),  INT8_C( 122),  INT8_C(   3), -INT8_C( 119),  INT8_C(  28), -INT8_C( 105),  INT8_C(  54), -INT8_C(  91),
       INT8_C(  80), -INT8_C(  77),  INT8_C( 106), -INT8_C(  63), -INT8_C( 124), -INT8_C(  49), -INT8_C(  97), -INT8_C(  35),
      -INT8_C(  71), -INT8_C(  21), -INT8_C(  45), -INT8_C(   7), -INT8_C(  19),  INT8_C(   7),  INT8_C(   7),  INT8_C(  20),
       INT8_C(  32),  INT8_C(  34),  INT8_C(  58),  INT8_C(  48),  INT8_C(  84),  INT8_C(  62),  INT8_C( 110),  INT8_C(  76),
      -INT8_C( 120),  INT8_C(  90), -INT8_C(  93),  INT8_C( 104), -INT8_C(  67),  INT8_C( 118), -INT8_C(  41), -INT8_C( 124),
      -INT8_C(  15), -INT8_C( 109),  INT8_C(  11), -INT8_C(  95),  INT8_C(  36), -INT8_C(  81),  INT8_C(  62), -INT8_C(  67),
       INT8_C(  88), -INT8_C(  53),  INT8_C( 114), -INT8_C(  39), -INT8_C( 116), -INT8_C(  25), -INT8_C(  89), -INT8_C(  11),
      -INT8_C(  63),  INT8_C(   3), -INT8_C(  37),  INT8_C(  16), -INT8_C(  11),  INT8_C(  30),  INT8_C(  14),  INT8_C(  44),
       INT8_C(  40),  INT8_C(  58),  INT8_C(  66),  INT8_C(  72),  INT8_C(  92),  INT8_C(  86),  INT8_C( 118),  INT8_C( 100),
      -INT8_C( 111),  INT8_C( 114), -INT8_C(  85), -INT8_C( 128), -INT8_C(  59), -INT8_C( 113), -INT8_C(  33), -INT8_C(  99),
      -INT8_C(   7), -INT8_C(  85),  INT8_C(  18), -INT8_C(  71),  INT8_C(  44), -INT8_C(  57),  INT8_C(  70), -INT8_C(  43),
       INT8_C(  96), -INT8_C(  29),  INT8_C( 122), -INT8_C(  15), -INT8_C( 107), -INT8_C(   1), -INT8_C(  81),  INT8_C(  12),
      -INT8_C(  55),  INT8_C(  26), -INT8_C(  29),  INT8_C(  40), -INT8_C(   3),  INT8_C(  54),  INT8_C(  22),  INT8_C(  68),
       INT8_C(  48),  INT8_C(  82),  INT8_C(  74),  INT8_C(  96),  INT8_C( 100),  INT8_C( 110),  INT8_C( 126),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vb_vround_VhVh_sat(a, b);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vround_VhVh_sat_u(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    uint8_t r[128];
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
      UINT8_C( 24), UINT8_C( 10), UINT8_C( 50), UINT8_C( 24), UINT8_C( 76), UINT8_C( 38), UINT8_C(102), UINT8_C( 52),
      UINT8_C(  0), UINT8_C( 66), UINT8_C(  0), UINT8_C( 80), UINT8_C(  0), UINT8_C( 94), UINT8_C(  0), UINT8_C(108),
      UINT8_C(  0), UINT8_C(122), UINT8_C(  3), UINT8_C(  0), UINT8_C( 28), UINT8_C(  0), UINT8_C( 54), UINT8_C(  0),
      UINT8_C( 80), UINT8_C(  0), UINT8_C(106), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  7), UINT8_C(  7), UINT8_C( 20),
      UINT8_C( 32), UINT8_C( 34), UINT8_C( 58), UINT8_C( 48), UINT8_C( 84), UINT8_C( 62), UINT8_C(110), UINT8_C( 76),
      UINT8_C(  0), UINT8_C( 90), UINT8_C(  0), UINT8_C(104), UINT8_C(  0), UINT8_C(118), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 11), UINT8_C(  0), UINT8_C( 36), UINT8_C(  0), UINT8_C( 62), UINT8_C(  0),
      UINT8_C( 88), UINT8_C(  0), UINT8_C(114), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  3), UINT8_C(  0), UINT8_C( 16), UINT8_C(  0), UINT8_C( 30), UINT8_C( 14), UINT8_C( 44),
      UINT8_C( 40), UINT8_C( 58), UINT8_C( 66), UINT8_C( 72), UINT8_C( 92), UINT8_C( 86), UINT8_C(118), UINT8_C(100),
      UINT8_C(  0), UINT8_C(114), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C( 18), UINT8_C(  0), UINT8_C( 44), UINT8_C(  0), UINT8_C( 70), UINT8_C(  0),
      UINT8_C( 96), UINT8_C(  0), UINT8_C(122), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 12),
      UINT8_C(  0), UINT8_C( 26), UINT8_C(  0), UINT8_C( 40), UINT8_C(  0), UINT8_C( 54), UINT8_C( 22), UINT8_C( 68),
      UINT8_C( 48), UINT8_C( 82), UINT8_C( 74), UINT8_C( 96), UINT8_C(100), UINT8_C(110), UINT8_C(126), UINT8_C(124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vround_VhVh_sat(a, b);
    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vround_VuhVuh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    uint8_t r[128];
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
      UINT8_C( 24), UINT8_C( 10), UINT8_C( 50), UINT8_C( 24), UINT8_C( 76), UINT8_C( 38), UINT8_C(102), UINT8_C( 52),
      UINT8_C(128), UINT8_C( 66), UINT8_C(155), UINT8_C( 80), UINT8_C(181), UINT8_C( 94), UINT8_C(207), UINT8_C(108),
      UINT8_C(233), UINT8_C(122), UINT8_C(  3), UINT8_C(137), UINT8_C( 28), UINT8_C(151), UINT8_C( 54), UINT8_C(165),
      UINT8_C( 80), UINT8_C(179), UINT8_C(106), UINT8_C(193), UINT8_C(132), UINT8_C(207), UINT8_C(159), UINT8_C(221),
      UINT8_C(185), UINT8_C(235), UINT8_C(211), UINT8_C(249), UINT8_C(237), UINT8_C(  7), UINT8_C(  7), UINT8_C( 20),
      UINT8_C( 32), UINT8_C( 34), UINT8_C( 58), UINT8_C( 48), UINT8_C( 84), UINT8_C( 62), UINT8_C(110), UINT8_C( 76),
      UINT8_C(136), UINT8_C( 90), UINT8_C(163), UINT8_C(104), UINT8_C(189), UINT8_C(118), UINT8_C(215), UINT8_C(132),
      UINT8_C(241), UINT8_C(147), UINT8_C( 11), UINT8_C(161), UINT8_C( 36), UINT8_C(175), UINT8_C( 62), UINT8_C(189),
      UINT8_C( 88), UINT8_C(203), UINT8_C(114), UINT8_C(217), UINT8_C(140), UINT8_C(231), UINT8_C(167), UINT8_C(245),
      UINT8_C(193), UINT8_C(  3), UINT8_C(219), UINT8_C( 16), UINT8_C(245), UINT8_C( 30), UINT8_C( 14), UINT8_C( 44),
      UINT8_C( 40), UINT8_C( 58), UINT8_C( 66), UINT8_C( 72), UINT8_C( 92), UINT8_C( 86), UINT8_C(118), UINT8_C(100),
      UINT8_C(145), UINT8_C(114), UINT8_C(171), UINT8_C(128), UINT8_C(197), UINT8_C(143), UINT8_C(223), UINT8_C(157),
      UINT8_C(249), UINT8_C(171), UINT8_C( 18), UINT8_C(185), UINT8_C( 44), UINT8_C(199), UINT8_C( 70), UINT8_C(213),
      UINT8_C( 96), UINT8_C(227), UINT8_C(122), UINT8_C(241), UINT8_C(149), UINT8_C(255), UINT8_C(175), UINT8_C( 12),
      UINT8_C(201), UINT8_C( 26), UINT8_C(227), UINT8_C( 40), UINT8_C(253), UINT8_C( 54), UINT8_C( 22), UINT8_C( 68),
      UINT8_C( 48), UINT8_C( 82), UINT8_C( 74), UINT8_C( 96), UINT8_C(100), UINT8_C(110), UINT8_C(126), UINT8_C(124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vround_VuhVuh_sat(a, b);
    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vround_VuwVuw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    uint16_t r[64];
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
      UINT16_C(12837), UINT16_C( 6161), UINT16_C(26201), UINT16_C(13357),
      UINT16_C(39566), UINT16_C(20553), UINT16_C(52930), UINT16_C(27749),
      UINT16_C(  758), UINT16_C(34945), UINT16_C(13865), UINT16_C(42142),
      UINT16_C(27229), UINT16_C(49338), UINT16_C(40594), UINT16_C(56534),
      UINT16_C(53958), UINT16_C(63730), UINT16_C( 1786), UINT16_C( 5133),
      UINT16_C(14893), UINT16_C(12329), UINT16_C(28257), UINT16_C(19525),
      UINT16_C(41622), UINT16_C(26721), UINT16_C(54986), UINT16_C(33917),
      UINT16_C( 2814), UINT16_C(41114), UINT16_C(15921), UINT16_C(48310),
      UINT16_C(29285), UINT16_C(55506), UINT16_C(42650), UINT16_C(62702),
      UINT16_C(56014), UINT16_C( 4105), UINT16_C( 3586), UINT16_C(11301),
      UINT16_C(16949), UINT16_C(18497), UINT16_C(30313), UINT16_C(25693),
      UINT16_C(43678), UINT16_C(32889), UINT16_C(57042), UINT16_C(40086),
      UINT16_C( 4614), UINT16_C(47282), UINT16_C(17977), UINT16_C(54478),
      UINT16_C(31341), UINT16_C(61674), UINT16_C(44706), UINT16_C( 3078),
      UINT16_C(58070), UINT16_C(10273), UINT16_C( 5642), UINT16_C(17469),
      UINT16_C(19005), UINT16_C(24665), UINT16_C(32369), UINT16_C(31861)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuh_vround_VuwVuw_sat(a, b);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vround_VwVw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vround_VwVw_sat_u)
SIMDE_TEST_FUNC_LIST_ENTRY(vround_VhVh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vround_VhVh_sat_u)
SIMDE_TEST_FUNC_LIST_ENTRY(vround_VuhVuh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vround_VuwVuw_sat)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
