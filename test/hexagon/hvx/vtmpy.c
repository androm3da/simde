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

#define SIMDE_TEST_HEXAGON_HVX_INSN vtmpy

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vtmpy.h"

static int
test_simde_vtmpy_WbRb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
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
      INT32_C(66912773),
      {
        INT16_C(    46),  INT16_C(    58),  INT16_C(   294),  INT16_C(   110),  INT16_C(   542), -INT16_C(    94),  INT16_C(   534), -INT16_C(    42),
        INT16_C(   782),  INT16_C(    10), -INT16_C(   762),  INT16_C(    62), -INT16_C(   514),  INT16_C(   114), -INT16_C(   266), -INT16_C(    90),
       -INT16_C(   274), -INT16_C(    38), -INT16_C(    26),  INT16_C(    14),  INT16_C(   222),  INT16_C(    66),  INT16_C(   470),  INT16_C(   118),
        INT16_C(   718), -INT16_C(    86),  INT16_C(   710), -INT16_C(   802), -INT16_C(   834),  INT16_C(    18), -INT16_C(   586),  INT16_C(    70),
       -INT16_C(   338),  INT16_C(   122), -INT16_C(    90), -INT16_C(    82), -INT16_C(    98), -INT16_C(    30),  INT16_C(   150),  INT16_C(    22),
        INT16_C(   398),  INT16_C(    74),  INT16_C(   646),  INT16_C(   126),  INT16_C(   638), -INT16_C(   846), -INT16_C(   906), -INT16_C(    26),
       -INT16_C(   658),  INT16_C(    26), -INT16_C(   410),  INT16_C(    78), -INT16_C(   162),  INT16_C(   130), -INT16_C(   170), -INT16_C(    74),
        INT16_C(    78), -INT16_C(    22),  INT16_C(   326),  INT16_C(    30),  INT16_C(   574),  INT16_C(    82),  INT16_C(   822),  INT16_C(   134)
      },
      {
        INT16_C(    96),  INT16_C(    89),  INT16_C(   392),  INT16_C(   213),  INT16_C(   432), -INT16_C(   687),  INT16_C(   216), -INT16_C(   563),
        INT16_C(   512),  INT16_C(   329), -INT16_C(   472),  INT16_C(   453), -INT16_C(   176),  INT16_C(   577), -INT16_C(   136), -INT16_C(   323),
       -INT16_C(   352), -INT16_C(   199), -INT16_C(    56), -INT16_C(    75),  INT16_C(   240),  INT16_C(    49),  INT16_C(   536),  INT16_C(   173),
        INT16_C(   576), -INT16_C(   727),  INT16_C(   360),  INT16_C(   165), -INT16_C(   624),  INT16_C(   289), -INT16_C(   328),  INT16_C(   413),
       -INT16_C(    32),  INT16_C(   537),  INT16_C(     8), -INT16_C(   363), -INT16_C(   208), -INT16_C(   239),  INT16_C(    88), -INT16_C(   115),
        INT16_C(   384),  INT16_C(     9),  INT16_C(   680),  INT16_C(   133),  INT16_C(   208),  INT16_C(     1), -INT16_C(   776),  INT16_C(   125),
       -INT16_C(   480),  INT16_C(   249), -INT16_C(   184),  INT16_C(   373),  INT16_C(   112),  INT16_C(   497), -INT16_C(   360), -INT16_C(   403),
       -INT16_C(    64), -INT16_C(   279),  INT16_C(   232), -INT16_C(   155),  INT16_C(   528), -INT16_C(    31),  INT16_C(   824),  INT16_C(    93)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t vp = simde_Q6_W_vcombine_VV(b, a);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vtmpy_WbRb(vp, test_vec[i].rt);
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
test_simde_vtmpy_WubRb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
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
      INT32_C(66912773),
      {
        INT16_C(    46),  INT16_C(    58),  INT16_C(   294),  INT16_C(   110),  INT16_C(   542),  INT16_C(   162),  INT16_C(   790),  INT16_C(   214),
        INT16_C(  1038),  INT16_C(   266),  INT16_C(  1030),  INT16_C(    62),  INT16_C(  1278),  INT16_C(   114),  INT16_C(  1526),  INT16_C(   166),
        INT16_C(  1774),  INT16_C(   218),  INT16_C(  1510),  INT16_C(   270),  INT16_C(   222),  INT16_C(    66),  INT16_C(   470),  INT16_C(   118),
        INT16_C(   718),  INT16_C(   170),  INT16_C(   966),  INT16_C(   222),  INT16_C(  1214),  INT16_C(   274),  INT16_C(  1206),  INT16_C(    70),
        INT16_C(  1454),  INT16_C(   122),  INT16_C(  1702),  INT16_C(   174),  INT16_C(  1438),  INT16_C(   226),  INT16_C(   406),  INT16_C(    22),
        INT16_C(   398),  INT16_C(    74),  INT16_C(   646),  INT16_C(   126),  INT16_C(   894),  INT16_C(   178),  INT16_C(  1142),  INT16_C(   230),
        INT16_C(  1390),  INT16_C(    26),  INT16_C(  1382),  INT16_C(    78),  INT16_C(  1630),  INT16_C(   130),  INT16_C(  1878),  INT16_C(   182),
        INT16_C(   334),  INT16_C(   234),  INT16_C(   582),  INT16_C(    30),  INT16_C(   574),  INT16_C(    82),  INT16_C(   822),  INT16_C(   134)
      },
      {
        INT16_C(    96),  INT16_C(    89),  INT16_C(   392),  INT16_C(   213),  INT16_C(   688),  INT16_C(   337),  INT16_C(   984),  INT16_C(   461),
        INT16_C(  1280),  INT16_C(   329),  INT16_C(   808), -INT16_C(   315),  INT16_C(  1104), -INT16_C(   191),  INT16_C(  1400), -INT16_C(    67),
        INT16_C(  1696),  INT16_C(    57),  INT16_C(   712),  INT16_C(   693),  INT16_C(   240),  INT16_C(    49),  INT16_C(   536),  INT16_C(   173),
        INT16_C(   832),  INT16_C(   297),  INT16_C(  1128),  INT16_C(   421),  INT16_C(  1424),  INT16_C(   289),  INT16_C(   952), -INT16_C(   355),
        INT16_C(  1248), -INT16_C(   231),  INT16_C(  1544), -INT16_C(   107),  INT16_C(   560),  INT16_C(   785),  INT16_C(   856), -INT16_C(   115),
        INT16_C(   384),  INT16_C(     9),  INT16_C(   680),  INT16_C(   133),  INT16_C(   976),  INT16_C(   257),  INT16_C(  1272),  INT16_C(   381),
        INT16_C(  1568), -INT16_C(   519),  INT16_C(  1096), -INT16_C(   395),  INT16_C(  1392), -INT16_C(   271),  INT16_C(  1688),  INT16_C(   621),
        INT16_C(   704),  INT16_C(   745),  INT16_C(  1000), -INT16_C(   155),  INT16_C(   528), -INT16_C(    31),  INT16_C(   824),  INT16_C(    93)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t vp = simde_Q6_W_vcombine_VV(b, a);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vtmpy_WubRb(vp, test_vec[i].rt);
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
test_simde_vtmpy_WhRb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
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
      INT32_C(66912773),
      {
        INT32_C(  31292),  INT32_C(  30313),  INT32_C(  93228), -INT32_C(   8495),
        INT32_C(  89628),  INT32_C(  17977), -INT32_C( 110836), -INT32_C(  20831),
       -INT32_C(  48900),  INT32_C(   5129),  INT32_C(  76524),  INT32_C(  32369),
        INT32_C( 138460), -INT32_C( 203047), -INT32_C( 192820),  INT32_C(  20033),
       -INT32_C(  65604), -INT32_C(  18775), -INT32_C(   4180),  INT32_C(   7953),
        INT32_C( 121756),  INT32_C(  34425),  INT32_C(  52620), -INT32_C(   4383),
       -INT32_C( 147588),  INT32_C(  22089), -INT32_C(  20372), -INT32_C(  17487),
        INT32_C(  39772),  INT32_C(  10009),  INT32_C( 166988),  INT32_C(  36481)
      },
      {
        INT32_C(  55952),  INT32_C(  44687),  INT32_C(  11488), -INT32_C( 153721),
       -INT32_C( 164048),  INT32_C( 105599), -INT32_C(  12672), -INT32_C(  92809),
       -INT32_C(  57136), -INT32_C(  28305),  INT32_C(  92960),  INT32_C(  34407),
        INT32_C(  48496),  INT32_C(  32607), -INT32_C( 127040),  INT32_C(  95319),
        INT32_C(  24336), -INT32_C( 103089), -INT32_C(  21408), -INT32_C(  38841),
        INT32_C( 129968),  INT32_C(  24127), -INT32_C( 242176),  INT32_C(  22327),
       -INT32_C(  90288),  INT32_C(  85039),  INT32_C(  61344), -INT32_C( 112601),
        INT32_C(  15600), -INT32_C(  49121),  INT32_C( 166976),  INT32_C(  13847)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t vp = simde_Q6_W_vcombine_VV(b, a);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vtmpy_WhRb(vp, test_vec[i].rt);
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

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vtmpy_WbRb)
SIMDE_TEST_FUNC_LIST_ENTRY(vtmpy_WubRb)
SIMDE_TEST_FUNC_LIST_ENTRY(vtmpy_WhRb)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
