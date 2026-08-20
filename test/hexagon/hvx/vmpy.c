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

#define SIMDE_TEST_HEXAGON_HVX_INSN vmpy

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vmpy.h"

static int
test_simde_vmpy_VbVb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int16_t r_lo[64];
    int16_t r_hi[64];
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
        INT16_C(    33),  INT16_C(   629),  INT16_C(  1953),  INT16_C(  4005),  INT16_C(  6785), -INT16_C(  8395), -INT16_C(  7743), -INT16_C(  6363),
       -INT16_C(  4255),  INT16_C(  1397), -INT16_C(  1695), -INT16_C(  4059), -INT16_C(  5695), -INT16_C(  6603), -INT16_C(  6783),  INT16_C(  4773),
        INT16_C(  2465),  INT16_C(   885),  INT16_C(    33), -INT16_C(    91),  INT16_C(   513),  INT16_C(  1845),  INT16_C(  3905),  INT16_C(  6693),
        INT16_C( 10209), -INT16_C( 10379), -INT16_C(  8991), -INT16_C(  6875),  INT16_C(  3393),  INT16_C(   309), -INT16_C(  2047), -INT16_C(  3675),
       -INT16_C(  4575), -INT16_C(  4747), -INT16_C(  4191),  INT16_C(  1957),  INT16_C(   385), -INT16_C(   459), -INT16_C(   575),  INT16_C(    37),
        INT16_C(  1377),  INT16_C(  3445),  INT16_C(  6241),  INT16_C(  9765), -INT16_C( 13375), -INT16_C( 11979),  INT16_C(  8833),  INT16_C(  5029),
        INT16_C(  1953), -INT16_C(   395), -INT16_C(  2015), -INT16_C(  2907), -INT16_C(  3071), -INT16_C(  2507),  INT16_C(  1089), -INT16_C(   475),
       -INT16_C(  1311), -INT16_C(  1419), -INT16_C(   799),  INT16_C(   549),  INT16_C(  2625),  INT16_C(  5429),  INT16_C(  8961),  INT16_C( 13221)
      },
      {
        INT16_C(   240),  INT16_C(  1200),  INT16_C(  2888),  INT16_C(  5304), -INT16_C(  8448), -INT16_C(  8160), -INT16_C(  7144), -INT16_C(  5400),
       -INT16_C(  2928), -INT16_C(   240), -INT16_C(  2968), -INT16_C(  4968), -INT16_C(  6240), -INT16_C(  6784),  INT16_C(  6200),  INT16_C(  3528),
        INT16_C(  1584),  INT16_C(   368), -INT16_C(   120),  INT16_C(   120),  INT16_C(  1088),  INT16_C(  2784),  INT16_C(  5208),  INT16_C(  8360),
       -INT16_C( 10800), -INT16_C(  9776), -INT16_C(  8024),  INT16_C(  5208),  INT16_C(  1760), -INT16_C(   960), -INT16_C(  2952), -INT16_C(  4216),
       -INT16_C(  4752), -INT16_C(  4560),  INT16_C(  3016),  INT16_C(  1080), -INT16_C(   128), -INT16_C(   608), -INT16_C(   360),  INT16_C(   616),
        INT16_C(  2320),  INT16_C(  4752),  INT16_C(  7912),  INT16_C( 11800), -INT16_C( 12768),  INT16_C( 11008),  INT16_C(  6840),  INT16_C(  3400),
        INT16_C(   688), -INT16_C(  1296), -INT16_C(  2552), -INT16_C(  3080), -INT16_C(  2880), -INT16_C(  1952),  INT16_C(   216), -INT16_C(   984),
       -INT16_C(  1456), -INT16_C(  1200), -INT16_C(   216),  INT16_C(  1496),  INT16_C(  3936),  INT16_C(  7104),  INT16_C( 11000),  INT16_C( 15624)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vmpy_VbVb(a, b);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(r);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(r);
    simde_test_hvx_vector_i16_assert_equal(r_lo, simde_test_hvx_vector_load(test_vec[i].r_lo));
    simde_test_hvx_vector_i16_assert_equal(r_hi, simde_test_hvx_vector_load(test_vec[i].r_hi));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vmpy_VubVb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int16_t r_lo[64];
    int16_t r_hi[64];
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
        INT16_C(    33),  INT16_C(   629),  INT16_C(  1953),  INT16_C(  4005),  INT16_C(  6785), -INT16_C(  8395), -INT16_C(  7743), -INT16_C(  6363),
       -INT16_C(  4255), -INT16_C(  1419),  INT16_C(  2145),  INT16_C(  6437),  INT16_C( 11457),  INT16_C( 17205),  INT16_C( 23681), -INT16_C( 23643),
       -INT16_C( 19295), -INT16_C( 14219), -INT16_C(  8415), -INT16_C(    91),  INT16_C(   513),  INT16_C(  1845),  INT16_C(  3905),  INT16_C(  6693),
        INT16_C( 10209), -INT16_C( 10379), -INT16_C(  8991), -INT16_C(  6875), -INT16_C(  4031), -INT16_C(   459),  INT16_C(  3841),  INT16_C(  8869),
        INT16_C( 14625),  INT16_C( 21109),  INT16_C( 28321), -INT16_C( 24411), -INT16_C( 19327), -INT16_C(   459), -INT16_C(   575),  INT16_C(    37),
        INT16_C(  1377),  INT16_C(  3445),  INT16_C(  6241),  INT16_C(  9765), -INT16_C( 13375), -INT16_C( 11979), -INT16_C(  9855), -INT16_C(  7003),
       -INT16_C(  3423),  INT16_C(   885),  INT16_C(  5921),  INT16_C( 11685),  INT16_C( 18177),  INT16_C( 25397), -INT16_C( 29887), -INT16_C(   475),
       -INT16_C(  1311), -INT16_C(  1419), -INT16_C(   799),  INT16_C(   549),  INT16_C(  2625),  INT16_C(  5429),  INT16_C(  8961),  INT16_C( 13221)
      },
      {
        INT16_C(   240),  INT16_C(  1200),  INT16_C(  2888),  INT16_C(  5304), -INT16_C(  8448), -INT16_C(  8160), -INT16_C(  7144), -INT16_C(  5400),
       -INT16_C(  2928),  INT16_C(   272),  INT16_C(  4200),  INT16_C(  8856),  INT16_C( 14240),  INT16_C( 20352), -INT16_C( 25544), -INT16_C( 21560),
       -INT16_C( 16848), -INT16_C( 11408), -INT16_C(   120),  INT16_C(   120),  INT16_C(  1088),  INT16_C(  2784),  INT16_C(  5208),  INT16_C(  8360),
       -INT16_C( 10800), -INT16_C(  9776), -INT16_C(  8024), -INT16_C(  5544), -INT16_C(  2336),  INT16_C(  1600),  INT16_C(  6264),  INT16_C( 11656),
        INT16_C( 17776),  INT16_C( 24624), -INT16_C( 26680), -INT16_C( 21960), -INT16_C(   128), -INT16_C(   608), -INT16_C(   360),  INT16_C(   616),
        INT16_C(  2320),  INT16_C(  4752),  INT16_C(  7912),  INT16_C( 11800), -INT16_C( 12768), -INT16_C( 11008), -INT16_C(  8520), -INT16_C(  5304),
       -INT16_C(  1360),  INT16_C(  3312),  INT16_C(  8712),  INT16_C( 14840),  INT16_C( 21696),  INT16_C( 29280), -INT16_C( 27432), -INT16_C(   984),
       -INT16_C(  1456), -INT16_C(  1200), -INT16_C(   216),  INT16_C(  1496),  INT16_C(  3936),  INT16_C(  7104),  INT16_C( 11000),  INT16_C( 15624)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vmpy_VubVb(a, b);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(r);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(r);
    simde_test_hvx_vector_i16_assert_equal(r_lo, simde_test_hvx_vector_load(test_vec[i].r_lo));
    simde_test_hvx_vector_i16_assert_equal(r_hi, simde_test_hvx_vector_load(test_vec[i].r_hi));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vmpy_VubVub(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int16_t r_lo[64];
    int16_t r_hi[64];
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
        INT16_C(    33),  INT16_C(   629),  INT16_C(  1953),  INT16_C(  4005),  INT16_C(  6785),  INT16_C( 10293),  INT16_C( 14529),  INT16_C( 19493),
        INT16_C( 25185),  INT16_C( 31605),  INT16_C(  2145),  INT16_C(  6437),  INT16_C( 11457),  INT16_C( 17205),  INT16_C( 23681),  INT16_C( 30885),
       -INT16_C( 26719), -INT16_C( 18059), -INT16_C(  8671),  INT16_C(  3237),  INT16_C(   513),  INT16_C(  1845),  INT16_C(  3905),  INT16_C(  6693),
        INT16_C( 10209),  INT16_C( 14453),  INT16_C( 19425),  INT16_C( 25125),  INT16_C( 31553), -INT16_C( 26827),  INT16_C(  3841),  INT16_C(  8869),
        INT16_C( 14625),  INT16_C( 21109),  INT16_C( 28321), -INT16_C( 29275), -INT16_C( 20607),  INT16_C(  1845),  INT16_C(  5313),  INT16_C(    37),
        INT16_C(  1377),  INT16_C(  3445),  INT16_C(  6241),  INT16_C(  9765),  INT16_C( 14017),  INT16_C( 18997),  INT16_C( 24705),  INT16_C( 31141),
       -INT16_C( 27231),  INT16_C(   885),  INT16_C(  5921),  INT16_C( 11685),  INT16_C( 18177),  INT16_C( 25397), -INT16_C( 32191),  INT16_C(   805),
        INT16_C(  3553),  INT16_C(  7029),  INT16_C( 11233),  INT16_C(   549),  INT16_C(  2625),  INT16_C(  5429),  INT16_C(  8961),  INT16_C( 13221)
      },
      {
        INT16_C(   240),  INT16_C(  1200),  INT16_C(  2888),  INT16_C(  5304),  INT16_C(  8448),  INT16_C( 12320),  INT16_C( 16920),  INT16_C( 22248),
        INT16_C( 28304),  INT16_C(   272),  INT16_C(  4200),  INT16_C(  8856),  INT16_C( 14240),  INT16_C( 20352),  INT16_C( 27192), -INT16_C( 30776),
       -INT16_C( 22480), -INT16_C( 13456),  INT16_C(  1416),  INT16_C(   120),  INT16_C(  1088),  INT16_C(  2784),  INT16_C(  5208),  INT16_C(  8360),
        INT16_C( 12240),  INT16_C( 16848),  INT16_C( 22184),  INT16_C( 28248), -INT16_C( 30496),  INT16_C(  1600),  INT16_C(  6264),  INT16_C( 11656),
        INT16_C( 17776),  INT16_C( 24624),  INT16_C( 32200), -INT16_C( 25032),  INT16_C(   384),  INT16_C(  3488),  INT16_C(  7320),  INT16_C(   616),
        INT16_C(  2320),  INT16_C(  4752),  INT16_C(  7912),  INT16_C( 11800),  INT16_C( 16416),  INT16_C( 21760),  INT16_C( 27832), -INT16_C( 30904),
       -INT16_C( 23376),  INT16_C(  3312),  INT16_C(  8712),  INT16_C( 14840),  INT16_C( 21696),  INT16_C( 29280), -INT16_C( 27944),  INT16_C(  2088),
        INT16_C(  5200),  INT16_C(  9040),  INT16_C( 13608),  INT16_C(  1496),  INT16_C(  3936),  INT16_C(  7104),  INT16_C( 11000),  INT16_C( 15624)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wuh_vmpy_VubVub(a, b);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(r);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(r);
    simde_test_hvx_vector_i16_assert_equal(r_lo, simde_test_hvx_vector_load(test_vec[i].r_lo));
    simde_test_hvx_vector_i16_assert_equal(r_hi, simde_test_hvx_vector_load(test_vec[i].r_hi));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vmpy_VhVh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t r_lo[32];
    int32_t r_hi[32];
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
        INT32_C(  15775265),  INT32_C( 190485921), -INT32_C( 553631615), -INT32_C( 465848639),
       -INT32_C( 185730975), -INT32_C( 193890719), -INT32_C( 406768959),  INT32_C( 398506625),
        INT32_C(  98700705), -INT32_C(   8770527),  INT32_C(  71690241),  INT32_C( 343625025),
       -INT32_C( 707494431), -INT32_C( 522487327),  INT32_C( 108413249), -INT32_C( 192402175),
       -INT32_C( 308056287),  INT32_C( 190217377), -INT32_C(  12364415), -INT32_C(  21884223),
        INT32_C( 152968033),  INT32_C( 522126945), -INT32_C( 835994431),  INT32_C( 440876673),
        INT32_C(  39619489), -INT32_C( 165550815), -INT32_C( 183980799),  INT32_C(   7290945),
       -INT32_C(  94444575), -INT32_C(  10888735),  INT32_C( 259608641),  INT32_C( 725991681)
      },
      {
        INT32_C(  79088757),  INT32_C( 349966757), -INT32_C( 533781963), -INT32_C( 349831643),
       -INT32_C(  23157387), -INT32_C( 324371675), -INT32_C( 441082571),  INT32_C( 224561829),
        INT32_C(  20923253),  INT32_C(   9162405),  INT32_C( 183615797),  INT32_C( 551717925),
       -INT32_C( 639032715),  INT32_C( 333612069), -INT32_C(  68701899), -INT32_C( 274271067),
       -INT32_C( 293757835),  INT32_C(  64884645), -INT32_C(  39091915),  INT32_C(  40514085),
        INT32_C( 313505653),  INT32_C( 778831909),  INT32_C( 713630773),  INT32_C( 216206245),
       -INT32_C(  84210315), -INT32_C( 198807643), -INT32_C( 121070283), -INT32_C(  64096987),
       -INT32_C(  76708491),  INT32_C(  98542629),  INT32_C( 468758325),  INT32_C(1031308709)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vmpy_VhVh(a, b);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(r);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(r);
    simde_test_hvx_vector_i32_assert_equal(r_lo, simde_test_hvx_vector_load(test_vec[i].r_lo));
    simde_test_hvx_vector_i32_assert_equal(r_hi, simde_test_hvx_vector_load(test_vec[i].r_hi));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vmpy_VuhVuh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    uint32_t r_lo[32];
    uint32_t r_hi[32];
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
       UINT32_C(  15775265), UINT32_C( 190485921), UINT32_C( 557531265), UINT32_C(1116911297),
       UINT32_C(1868626017), UINT32_C( 276854369), UINT32_C( 939799233), UINT32_C(1795078785),
       UINT32_C(2842693025), UINT32_C( 108604449), UINT32_C(  71690241), UINT32_C( 343625025),
       UINT32_C( 807894497), UINT32_C(1464498657), UINT32_C(2313437505), UINT32_C( 413084929),
       UINT32_C(1173253921), UINT32_C(2125757601), UINT32_C(  37639553), UINT32_C( 482939585),
       UINT32_C( 152968033), UINT32_C( 522126945), UINT32_C(1083620545), UINT32_C(1837448833),
       UINT32_C(2783611809), UINT32_C( 574678305), UINT32_C(1432071425), UINT32_C(2481799233),
       UINT32_C( 343008225), UINT32_C( 898161121), UINT32_C( 259608641), UINT32_C( 725991681)
      },
      {
       UINT32_C(  79088757), UINT32_C( 349966757), UINT32_C( 813179445), UINT32_C(1468726821),
       UINT32_C(  26453365), UINT32_C( 584284965), UINT32_C(1343397173), UINT32_C(2294844069),
       UINT32_C(3438625653), UINT32_C(   9162405), UINT32_C( 183615797), UINT32_C( 551717925),
       UINT32_C(1112154741), UINT32_C(1864926245), UINT32_C( 115650869), UINT32_C( 769127589),
       UINT32_C(1625463925), UINT32_C(2674134949), UINT32_C( 229933365), UINT32_C(  40514085),
       UINT32_C( 313505653), UINT32_C( 778831909), UINT32_C(1436492853), UINT32_C(2286488485),
       UINT32_C( 218107253), UINT32_C( 979333029), UINT32_C(1932893493), UINT32_C( 137557285),
       UINT32_C( 596542837), UINT32_C(  98542629), UINT32_C( 468758325), UINT32_C(1031308709)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t r = simde_Q6_Wuw_vmpy_VuhVuh(a, b);
    simde_hvx_vector_t r_lo = simde_Q6_V_lo_W(r);
    simde_hvx_vector_t r_hi = simde_Q6_V_hi_W(r);
    simde_test_hvx_vector_u32_assert_equal(r_lo, simde_test_hvx_vector_load(test_vec[i].r_lo));
    simde_test_hvx_vector_u32_assert_equal(r_hi, simde_test_hvx_vector_load(test_vec[i].r_hi));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vmpyi_VhVh(SIMDE_MUNIT_TEST_ARGS) {
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
       -INT16_C( 18911), -INT16_C( 13195), -INT16_C( 27231),  INT16_C(  4517),  INT16_C( 16513),  INT16_C(  8757), -INT16_C( 18751), -INT16_C(   475),
       -INT16_C(  1951), -INT16_C( 23179),  INT16_C( 30305),  INT16_C( 31525),  INT16_C( 12993), -INT16_C( 25291), -INT16_C( 17791), -INT16_C( 30043),
        INT16_C(  3489),  INT16_C( 17269),  INT16_C( 11297), -INT16_C( 12635), -INT16_C(  6143), -INT16_C( 16075),  INT16_C( 19777), -INT16_C( 29659),
        INT16_C( 32225),  INT16_C(  8821),  INT16_C( 31201), -INT16_C( 31707),  INT16_C( 16705), -INT16_C( 20171),  INT16_C( 11521), -INT16_C(  2907),
        INT16_C( 28449), -INT16_C( 25483),  INT16_C( 31905),  INT16_C(  4005),  INT16_C( 21889), -INT16_C( 32459),  INT16_C(  4801),  INT16_C( 12837),
        INT16_C(  7009), -INT16_C( 18571),  INT16_C(  1633),  INT16_C(  2085), -INT16_C( 17215),  INT16_C(  9269),  INT16_C( 16001),  INT16_C(  2981),
       -INT16_C( 29791),  INT16_C(  3445), -INT16_C(  6879),  INT16_C( 28581), -INT16_C( 21247), -INT16_C( 25291),  INT16_C( 16449), -INT16_C(  2779),
       -INT16_C(  7199), -INT16_C( 31371), -INT16_C(  9759), -INT16_C( 23515),  INT16_C( 20545), -INT16_C( 20683), -INT16_C( 16127), -INT16_C( 31323)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vmpyi_VhVh(a, b);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vmpyi_VhRb(SIMDE_MUNIT_TEST_ARGS) {
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
        INT16_C( 12815),  INT16_C( 12322), -INT16_C( 29277), -INT16_C( 25465),  INT16_C( 19239), -INT16_C( 24430), -INT16_C(  6917),  INT16_C( 17711),
        INT16_C( 25663),  INT16_C(  4354),  INT16_C( 15443), -INT16_C(  4649),  INT16_C( 32087), -INT16_C( 32398), -INT16_C( 27733), -INT16_C( 27009),
       -INT16_C( 27025), -INT16_C(  3614), -INT16_C(  5373),  INT16_C( 15399), -INT16_C( 21881),  INT16_C( 24658),  INT16_C( 17755), -INT16_C(  6961),
       -INT16_C( 15457), -INT16_C( 12094), -INT16_C( 25421), -INT16_C( 29321), -INT16_C(  9033),  INT16_C( 16690), -INT16_C(  3061),  INT16_C( 13855),
       -INT16_C(  2609), -INT16_C( 20062),  INT16_C( 19299), -INT16_C(  8505),  INT16_C(  3815),  INT16_C(  8210), -INT16_C( 23109), -INT16_C( 31633),
        INT16_C(  8959), -INT16_C( 28542), -INT16_C(   749),  INT16_C( 11543),  INT16_C( 15383),  INT16_C(   242),  INT16_C( 21611), -INT16_C( 10817),
        INT16_C( 21807),  INT16_C( 29026), -INT16_C( 21565),  INT16_C( 32359),  INT16_C( 28231), -INT16_C(  7726),  INT16_C(   795),  INT16_C(  9231),
       -INT16_C( 32161),  INT16_C( 20546),  INT16_C( 23923), -INT16_C( 13129), -INT16_C( 25737), -INT16_C( 16206), -INT16_C( 19253),  INT16_C( 30047)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vh_vmpyi_VhRb(a, test_vec[i].rt);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vmpyie_VwVuh(SIMDE_MUNIT_TEST_ARGS) {
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
       -INT32_C(1582582239),  INT32_C(1047369121), -INT32_C(1308213119), -INT32_C(  59394367),
        INT32_C( 498858081), -INT32_C( 508332447),  INT32_C(2020553409), -INT32_C( 436094335),
        INT32_C( 711658913),  INT32_C(2043423777), -INT32_C(1219434495), -INT32_C( 543273663),
       -INT32_C( 557679135), -INT32_C(1262650911),  INT32_C(1636778305), -INT32_C(2132660991),
       -INT32_C(1557565663), -INT32_C(1673036639), -INT32_C( 125217407),  INT32_C( 908858049),
       -INT32_C( 805758111), -INT32_C(2083387807),  INT32_C( 243383489),  INT32_C(1879588481),
       -INT32_C(1469740127),  INT32_C( 588506401), -INT32_C( 790188799), -INT32_C( 829407167),
        INT32_C( 747430881), -INT32_C( 159655455), -INT32_C( 341553087),  INT32_C( 721993985)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vmpyie_VwVuh(a, b);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vmpyieo_VhVh(SIMDE_MUNIT_TEST_ARGS) {
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
        INT32_C( 141492224), -INT32_C(1698234368), -INT32_C( 125894656),  INT32_C( 563544064),
        INT32_C( 370081792),  INT32_C(1189543936), -INT32_C(1239482368), -INT32_C( 256442368),
       -INT32_C( 156303360), -INT32_C( 939065344),  INT32_C( 482279424),  INT32_C( 886505472),
        INT32_C( 407830528), -INT32_C( 953745408),  INT32_C(1096744960), -INT32_C( 537460736),
       -INT32_C( 722534400), -INT32_C(1790509056),  INT32_C( 553582592),  INT32_C(1612120064),
        INT32_C( 848232448), -INT32_C( 798556160),  INT32_C( 966721536),  INT32_C(1849098240),
       -INT32_C( 886112256),  INT32_C(2055667712), -INT32_C( 180420608),  INT32_C( 995557376),
        INT32_C(2010054656), -INT32_C( 240713728),  INT32_C(1239351296),  INT32_C(1836515328)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vmpyieo_VhVh(a, b);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vmpyoacc_VwVwVh_s1_shift_(int round) {
  static const int32_t x_data[] = {
    INT32_C(32768), INT32_C(16384), -INT32_C(16384), INT32_C(0),
    INT32_C(0), INT32_C(0), INT32_MIN, INT32_C(12345)
  };
  static const int32_t u_data[] = {
    INT32_C(0), INT32_C(0), INT32_C(0), INT32_C(65536),
    -INT32_C(65536), INT32_MIN, INT32_MIN, INT32_C(3)
  };
  static const int16_t v_data[] = {
    INT16_C(1), INT16_C(1), INT16_C(1), INT16_C(16384),
    INT16_C(16384), INT16_MIN, INT16_MAX, INT16_C(10923)
  };
  static const int32_t expected[][8] = {
    { INT32_C(1), INT32_C(0), -INT32_C(1), INT32_C(32768),
      -INT32_C(32768), INT32_MAX, INT32_MIN, INT32_C(1) },
    { INT32_C(1), INT32_C(1), INT32_C(0), INT32_C(32768),
      -INT32_C(32768), INT32_MAX, INT32_MIN, INT32_C(1) }
  };
  int32_t x[SIMDE_HVX_VECTOR_I32_COUNT];
  int32_t u[SIMDE_HVX_VECTOR_I32_COUNT];
  int16_t v[SIMDE_HVX_VECTOR_I16_COUNT];
  int32_t e[SIMDE_HVX_VECTOR_I32_COUNT];

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
    const size_t j = i % 8;
    x[i] = x_data[j];
    u[i] = u_data[j];
    v[2 * i] = INT16_C(12345);
    v[2 * i + 1] = v_data[j];
    e[i] = expected[round][j];
  }

  simde_hvx_vector_t x_ = simde_test_hvx_vector_load(x);
  simde_hvx_vector_t u_ = simde_test_hvx_vector_load(u);
  simde_hvx_vector_t v_ = simde_test_hvx_vector_load(v);
  simde_hvx_vector_t r = round
    ? simde_Q6_Vw_vmpyoacc_VwVwVh_s1_rnd_sat_shift(x_, u_, v_)
    : simde_Q6_Vw_vmpyoacc_VwVwVh_s1_sat_shift(x_, u_, v_);
  simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(e));

  return 0;
}

static int
test_simde_vmpyoacc_VwVwVh_s1_sat_shift(SIMDE_MUNIT_TEST_ARGS) {
  return test_simde_vmpyoacc_VwVwVh_s1_shift_(0);
}

static int
test_simde_vmpyoacc_VwVwVh_s1_rnd_sat_shift(SIMDE_MUNIT_TEST_ARGS) {
  return test_simde_vmpyoacc_VwVwVh_s1_shift_(1);
}

static int
test_simde_vmpy_extremes(SIMDE_MUNIT_TEST_ARGS) {
  simde_hvx_vector_private a_, b_, expected_, acc_lo_, acc_hi_, expected_lo_, expected_hi_;

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
    a_.i32[i] = INT32_MAX;
    b_.i16[2 * i] = 0;
    b_.i16[2 * i + 1] = INT16_MIN;
    expected_.i32[i] = -INT32_MAX;
  }
  simde_hvx_vector_t r = simde_Q6_Vw_vmpyo_VwVh_s1_sat(
    simde_hvx_vector_from_private(a_), simde_hvx_vector_from_private(b_));
  simde_test_hvx_vector_i32_assert_equal(r, simde_hvx_vector_from_private(expected_));

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
    a_.i16[i] = INT16_MIN;
    b_.i16[i] = 1;
    expected_.i16[i] = -1;
  }
  r = simde_Q6_Vh_vmpy_VhVh_s1_rnd_sat(
    simde_hvx_vector_from_private(a_), simde_hvx_vector_from_private(b_));
  simde_test_hvx_vector_i16_assert_equal(r, simde_hvx_vector_from_private(expected_));

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I32_COUNT ; i++) {
    int64_t prod = HEDLEY_STATIC_CAST(int64_t, INT32_MAX) * INT16_MAX + INT32_MAX;
    a_.i32[i] = INT32_MAX;
    b_.i16[2 * i] = 0;
    b_.i16[2 * i + 1] = INT16_MAX;
    acc_lo_.u32[i] = UINT32_MAX;
    acc_hi_.u32[i] = INT32_MAX;
    expected_lo_.u32[i] = (HEDLEY_STATIC_CAST(uint32_t, prod) << 16) | UINT16_MAX;
    expected_hi_.u32[i] = HEDLEY_STATIC_CAST(uint32_t, HEDLEY_STATIC_CAST(uint64_t, prod) >> 16);
  }
  simde_hvx_vectorpair_t rp = simde_Q6_W_vmpyoacc_WVwVh(
    simde_Q6_W_vcombine_VV(simde_hvx_vector_from_private(acc_hi_), simde_hvx_vector_from_private(acc_lo_)),
    simde_hvx_vector_from_private(a_), simde_hvx_vector_from_private(b_));
  simde_test_hvx_vector_i32_assert_equal(simde_Q6_V_lo_W(rp), simde_hvx_vector_from_private(expected_lo_));
  simde_test_hvx_vector_i32_assert_equal(simde_Q6_V_hi_W(rp), simde_hvx_vector_from_private(expected_hi_));

  return 0;
}

static int
test_simde_vmpy_VbfVbf(SIMDE_MUNIT_TEST_ARGS) {
  simde_hvx_vector_private a_, b_;
  simde_hvx_vectorpair_private acc_, expected_;

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_BF16_COUNT ; i++) {
    a_.bf16[i] = simde_bfloat16_from_float32(HEDLEY_STATIC_CAST(simde_float32, i + 1));
    b_.bf16[i] = simde_bfloat16_from_float32(HEDLEY_STATIC_CAST(simde_float32, (i % 5) + 1));
  }
  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_F32_COUNT ; i++) {
    expected_.f32[i] = HEDLEY_STATIC_CAST(simde_float32, (2 * i + 1) * ((2 * i) % 5 + 1));
    expected_.f32[SIMDE_HVX_VECTOR_F32_COUNT + i] = HEDLEY_STATIC_CAST(simde_float32, (2 * i + 2) * ((2 * i + 1) % 5 + 1));
  }

  simde_hvx_vectorpair_t r = simde_Q6_Wsf_vmpy_VbfVbf(
    simde_hvx_vector_from_private(a_), simde_hvx_vector_from_private(b_));
  simde_hvx_vectorpair_private r_ = simde_hvx_vectorpair_to_private(r);
  for (size_t i = 0 ; i < (2 * SIMDE_HVX_VECTOR_F32_COUNT) ; i++) {
    simde_assert_equal_f32(r_.f32[i], expected_.f32[i], 0);
    acc_.f32[i] = HEDLEY_STATIC_CAST(simde_float32, 1000 + i);
    expected_.f32[i] += acc_.f32[i];
  }

  r = simde_Q6_Wsf_vmpyacc_WsfVbfVbf(simde_hvx_vectorpair_from_private(acc_),
    simde_hvx_vector_from_private(a_), simde_hvx_vector_from_private(b_));
  r_ = simde_hvx_vectorpair_to_private(r);
  for (size_t i = 0 ; i < (2 * SIMDE_HVX_VECTOR_F32_COUNT) ; i++) {
    simde_assert_equal_f32(r_.f32[i], expected_.f32[i], 0);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmpy_VbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpy_VubVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpy_VubVub)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpy_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpy_VuhVuh)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpyi_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpyi_VhRb)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpyie_VwVuh)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpyieo_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpyoacc_VwVwVh_s1_sat_shift)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpyoacc_VwVwVh_s1_rnd_sat_shift)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpy_extremes)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpy_VbfVbf)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
