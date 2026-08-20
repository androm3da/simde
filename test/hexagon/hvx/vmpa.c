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

#define SIMDE_TEST_HEXAGON_HVX_INSN vmpa

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vmpa.h"

static int
test_simde_vmpa_WubRb(SIMDE_MUNIT_TEST_ARGS) {
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
        INT16_C(    37),  INT16_C(   159),  INT16_C(   281),  INT16_C(   403),  INT16_C(   525),  INT16_C(   647),  INT16_C(   769),  INT16_C(   891),
        INT16_C(  1013),  INT16_C(  1135),  INT16_C(   745),  INT16_C(   867),  INT16_C(   989),  INT16_C(  1111),  INT16_C(  1233),  INT16_C(  1355),
        INT16_C(  1477),  INT16_C(  1599),  INT16_C(  1721),  INT16_C(   563),  INT16_C(   173),  INT16_C(   295),  INT16_C(   417),  INT16_C(   539),
        INT16_C(   661),  INT16_C(   783),  INT16_C(   905),  INT16_C(  1027),  INT16_C(  1149),  INT16_C(  1271),  INT16_C(   881),  INT16_C(  1003),
        INT16_C(  1125),  INT16_C(  1247),  INT16_C(  1369),  INT16_C(  1491),  INT16_C(  1613),  INT16_C(   455),  INT16_C(   577),  INT16_C(   187),
        INT16_C(   309),  INT16_C(   431),  INT16_C(   553),  INT16_C(   675),  INT16_C(   797),  INT16_C(   919),  INT16_C(  1041),  INT16_C(  1163),
        INT16_C(  1285),  INT16_C(   895),  INT16_C(  1017),  INT16_C(  1139),  INT16_C(  1261),  INT16_C(  1383),  INT16_C(  1505),  INT16_C(   347),
        INT16_C(   469),  INT16_C(   591),  INT16_C(   713),  INT16_C(   323),  INT16_C(   445),  INT16_C(   567),  INT16_C(   689),  INT16_C(   811)
      },
      {
        INT16_C(    42),  INT16_C(    78),  INT16_C(   114),  INT16_C(   150),  INT16_C(   186),  INT16_C(   222),  INT16_C(   258),  INT16_C(   294),
        INT16_C(   330), -INT16_C(   402), -INT16_C(   366), -INT16_C(   330), -INT16_C(   294), -INT16_C(   258), -INT16_C(   222), -INT16_C(   186),
       -INT16_C(   150), -INT16_C(   114),  INT16_C(   690), -INT16_C(    42), -INT16_C(     6),  INT16_C(    30),  INT16_C(    66),  INT16_C(   102),
        INT16_C(   138),  INT16_C(   174),  INT16_C(   210),  INT16_C(   246),  INT16_C(   282), -INT16_C(   450), -INT16_C(   414), -INT16_C(   378),
       -INT16_C(   342), -INT16_C(   306), -INT16_C(   270), -INT16_C(   234),  INT16_C(   570),  INT16_C(   606),  INT16_C(   642), -INT16_C(    90),
       -INT16_C(    54), -INT16_C(    18),  INT16_C(    18),  INT16_C(    54),  INT16_C(    90),  INT16_C(   126),  INT16_C(   162),  INT16_C(   198),
        INT16_C(   234), -INT16_C(   498), -INT16_C(   462), -INT16_C(   426), -INT16_C(   390), -INT16_C(   354), -INT16_C(   318),  INT16_C(   486),
        INT16_C(   522),  INT16_C(   558),  INT16_C(   594), -INT16_C(   138), -INT16_C(   102), -INT16_C(    66), -INT16_C(    30),  INT16_C(     6)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t vp = simde_Q6_W_vcombine_VV(b, a);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vmpa_WubRb(vp, test_vec[i].rt);
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
test_simde_vmpa_WhRb(SIMDE_MUNIT_TEST_ARGS) {
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
        INT32_C(  25125),  INT32_C(  87833),  INT32_C(  19469),  INT32_C(  82177),
        INT32_C( 144885), -INT32_C( 120599), -INT32_C(  57891), -INT32_C( 126255),
       -INT32_C(  63547), -INT32_C(    839),  INT32_C(  60077),  INT32_C( 122785),
        INT32_C(  54421),  INT32_C( 117129), -INT32_C( 147843), -INT32_C(  85647),
       -INT32_C(  22939), -INT32_C(  91303), -INT32_C(  28595),  INT32_C(  32833),
        INT32_C(  95029),  INT32_C( 157737),  INT32_C(  89373), -INT32_C( 175599),
       -INT32_C( 112891), -INT32_C(  50695),  INT32_C(  12013), -INT32_C(  56351),
        INT32_C(   5077),  INT32_C(  67785),  INT32_C( 129981),  INT32_C( 192689)
      },
      {
        INT32_C(  20028),  INT32_C(  38532), -INT32_C( 139572), -INT32_C( 121068),
        INT32_C(  94044),  INT32_C( 111780),  INT32_C( 130284), -INT32_C(  47820),
       -INT32_C(  29316), -INT32_C(  10044),  INT32_C(   7692),  INT32_C(  26196),
       -INT32_C( 151908),  INT32_C(  63204),  INT32_C(  81708),  INT32_C(  99444),
        INT32_C( 117948), -INT32_C(  60156), -INT32_C(  40884), -INT32_C(  23148),
       -INT32_C(   4644),  INT32_C(  13860),  INT32_C(  32364),  INT32_C(  50868),
        INT32_C(  68604),  INT32_C(  87108),  INT32_C( 105612), -INT32_C(  71724),
       -INT32_C(  53220), -INT32_C(  35484), -INT32_C(  16980),  INT32_C(   1524)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t vp = simde_Q6_W_vcombine_VV(b, a);
    simde_hvx_vectorpair_t r = simde_Q6_Ww_vmpa_WhRb(vp, test_vec[i].rt);
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
test_simde_vmpa_WubWb(SIMDE_MUNIT_TEST_ARGS) {
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
        INT16_C(   130),  INT16_C(  1658),  INT16_C(  4930),  INT16_C(  9946),  INT16_C( 16706), -INT16_C( 10886), -INT16_C(  7294), -INT16_C(  1958),
        INT16_C(  5122), -INT16_C( 19078), -INT16_C( 15934), -INT16_C( 13862), -INT16_C( 10046), -INT16_C(  4486),  INT16_C(  2818), -INT16_C( 25254),
       -INT16_C( 21118), -INT16_C( 15238), -INT16_C(  7614), -INT16_C(  1574),  INT16_C(  1090),  INT16_C(  3706),  INT16_C(  8066),  INT16_C( 14170),
        INT16_C( 22018), -INT16_C(  6534), -INT16_C(  1854),  INT16_C(  4570), -INT16_C( 22846), -INT16_C( 16518), -INT16_C( 14334), -INT16_C( 11174),
       -INT16_C(  6270),  INT16_C(   378),  INT16_C(  8770), -INT16_C( 20262), -INT16_C( 15038), -INT16_C( 10374), -INT16_C(  5246),  INT16_C(  1370),
        INT16_C(  3330),  INT16_C(  7034),  INT16_C( 12482),  INT16_C( 19674), -INT16_C(  4926), -INT16_C(   902), -INT16_C( 29694), -INT16_C( 25766),
       -INT16_C( 20094), -INT16_C( 13958), -INT16_C( 11454), -INT16_C(  7206), -INT16_C(  1214),  INT16_C(  6522), -INT16_C( 18558), -INT16_C( 15270),
       -INT16_C( 12542), -INT16_C(  8070), -INT16_C(  1854),  INT16_C(  3802),  INT16_C(  6850),  INT16_C( 11642),  INT16_C( 18178),  INT16_C( 26458)
      },
      {
        INT16_C(   676),  INT16_C(  3076),  INT16_C(  7220),  INT16_C( 13108), -INT16_C( 12028), -INT16_C(  9308), -INT16_C(  4844),  INT16_C(  1364),
        INT16_C(  9316), -INT16_C( 16316), -INT16_C( 15116), -INT16_C( 12172), -INT16_C(  7484), -INT16_C(  1052), -INT16_C( 26668), -INT16_C( 23404),
       -INT16_C( 18396), -INT16_C( 11644), -INT16_C(  4684),  INT16_C(   436),  INT16_C(  2180),  INT16_C(  5668),  INT16_C( 10900),  INT16_C( 17876),
       -INT16_C(  8220), -INT16_C(  4412),  INT16_C(  1140), -INT16_C( 25356), -INT16_C( 19900), -INT16_C( 15260), -INT16_C( 12972), -INT16_C(  8940),
       -INT16_C(  3164),  INT16_C(  4356), -INT16_C( 22220), -INT16_C( 17868), -INT16_C( 12284), -INT16_C(  8028), -INT16_C(  2028),  INT16_C(  2132),
        INT16_C(  4964),  INT16_C(  9540),  INT16_C( 15860),  INT16_C( 23924), -INT16_C(  3132), -INT16_C( 31004), -INT16_C( 27948), -INT16_C( 23148),
       -INT16_C( 16604), -INT16_C( 12924), -INT16_C(  9548), -INT16_C(  4428),  INT16_C(  2436),  INT16_C( 11044), -INT16_C( 16492), -INT16_C( 14124),
       -INT16_C( 10524), -INT16_C(  5180),  INT16_C(  1908),  INT16_C(  5108),  INT16_C(  9028),  INT16_C( 14692),  INT16_C( 22100),  INT16_C( 31252)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t vp_ab = simde_Q6_W_vcombine_VV(b, a);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vmpa_WubWb(vp_ab, vp_ab);
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
test_simde_vmpa_WubWub(SIMDE_MUNIT_TEST_ARGS) {
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
        INT16_C(   130),  INT16_C(  1658),  INT16_C(  4930),  INT16_C(  9946),  INT16_C( 16706),  INT16_C( 25210), -INT16_C( 30078), -INT16_C( 18086),
       -INT16_C(  4350),  INT16_C( 11130),  INT16_C( 20674),  INT16_C( 26330), -INT16_C( 31806), -INT16_C( 22662), -INT16_C( 11774),  INT16_C(   858),
        INT16_C( 15234),  INT16_C( 31354), -INT16_C( 16318), -INT16_C(  3366),  INT16_C(  1090),  INT16_C(  3706),  INT16_C(  8066),  INT16_C( 14170),
        INT16_C( 22018),  INT16_C( 31610), -INT16_C( 22590), -INT16_C(  9510),  INT16_C(  5314),  INT16_C( 21882),  INT16_C( 28418), -INT16_C( 30374),
       -INT16_C( 21886), -INT16_C( 11654),  INT16_C(   322),  INT16_C( 14042),  INT16_C( 29506), -INT16_C( 23430), -INT16_C( 11646),  INT16_C(  1370),
        INT16_C(  3330),  INT16_C(  7034),  INT16_C( 12482),  INT16_C( 19674),  INT16_C( 28610), -INT16_C( 26246), -INT16_C( 13822),  INT16_C(   346),
        INT16_C( 16258),  INT16_C( 31354), -INT16_C( 28094), -INT16_C( 20262), -INT16_C( 10686),  INT16_C(   634),  INT16_C( 13698),  INT16_C( 25946),
       -INT16_C( 30206), -INT16_C( 19078), -INT16_C(  6206),  INT16_C(  3802),  INT16_C(  6850),  INT16_C( 11642),  INT16_C( 18178),  INT16_C( 26458)
      },
      {
        INT16_C(   676),  INT16_C(  3076),  INT16_C(  7220),  INT16_C( 13108),  INT16_C( 20740),  INT16_C( 30116), -INT16_C( 24300), -INT16_C( 11436),
        INT16_C(  3172),  INT16_C( 18500),  INT16_C( 23284),  INT16_C( 29812), -INT16_C( 27452), -INT16_C( 17436), -INT16_C(  5676),  INT16_C(  7828),
        INT16_C( 23076), -INT16_C( 25468), -INT16_C(  9804),  INT16_C(   436),  INT16_C(  2180),  INT16_C(  5668),  INT16_C( 10900),  INT16_C( 17876),
        INT16_C( 26596), -INT16_C( 28476), -INT16_C( 16268), -INT16_C(  2316),  INT16_C( 13380),  INT16_C( 25700),  INT16_C( 31572), -INT16_C( 26348),
       -INT16_C( 16988), -INT16_C(  5884),  INT16_C(  6964),  INT16_C( 21556), -INT16_C( 28668), -INT16_C( 17756), -INT16_C(  5100),  INT16_C(  2132),
        INT16_C(  4964),  INT16_C(  9540),  INT16_C( 15860),  INT16_C( 23924), -INT16_C( 31804), -INT16_C( 20252), -INT16_C(  6956),  INT16_C(  8084),
        INT16_C( 24868), -INT16_C( 31356), -INT16_C( 24396), -INT16_C( 15692), -INT16_C(  5244),  INT16_C(  6948),  INT16_C( 20884),  INT16_C( 30420),
       -INT16_C( 24860), -INT16_C( 12860),  INT16_C(   884),  INT16_C(  5108),  INT16_C(  9028),  INT16_C( 14692),  INT16_C( 22100),  INT16_C( 31252)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vectorpair_t vp_ab = simde_Q6_W_vcombine_VV(b, a);
    simde_hvx_vectorpair_t r = simde_Q6_Wh_vmpa_WubWub(vp_ab, vp_ab);
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
test_simde_vmpa_extremes(SIMDE_MUNIT_TEST_ARGS) {
  simde_hvx_vector_private x_, u_, expected_;
  simde_hvx_vectorpair_private xx_, p_, expected_pair_;

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
    x_.i16[i] = INT16_MAX;
    u_.i16[i] = INT16_MAX;
    expected_.i16[i] = INT16_MAX;
  }
  simde_hvx_vector_t r = simde_Q6_Vh_vmpa_VhVhVhPh_sat(
    simde_hvx_vector_from_private(x_), simde_hvx_vector_from_private(u_), INT64_C(0x7fff7fff7fff7fff));
  simde_test_hvx_vector_i16_assert_equal(r, simde_hvx_vector_from_private(expected_));

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
    u_.u16[i] = UINT16_MAX;
  }
  r = simde_Q6_Vh_vmpa_VhVhVuhPuh_sat(
    simde_hvx_vector_from_private(x_), simde_hvx_vector_from_private(u_), -INT64_C(1));
  simde_test_hvx_vector_i16_assert_equal(r, simde_hvx_vector_from_private(expected_));

  for (size_t i = 0 ; i < SIMDE_HVX_VECTOR_I16_COUNT ; i++) {
    x_.i16[i] = INT16_MIN;
    expected_.i16[i] = INT16_MIN;
  }
  r = simde_Q6_Vh_vmps_VhVhVuhPuh_sat(
    simde_hvx_vector_from_private(x_), simde_hvx_vector_from_private(u_), -INT64_C(1));
  simde_test_hvx_vector_i16_assert_equal(r, simde_hvx_vector_from_private(expected_));

  for (size_t i = 0 ; i < (2 * SIMDE_HVX_VECTOR_I32_COUNT) ; i++) {
    xx_.u32[i] = UINT32_MAX;
    expected_pair_.u32[i] = UINT32_MAX + (UINT32_C(2) * INT16_MAX * INT8_MAX);
  }
  for (size_t i = 0 ; i < (2 * SIMDE_HVX_VECTOR_I16_COUNT) ; i++) {
    p_.i16[i] = INT16_MAX;
  }
  simde_hvx_vectorpair_t rp = simde_Q6_Ww_vmpaacc_WwWhRb(
    simde_hvx_vectorpair_from_private(xx_), simde_hvx_vectorpair_from_private(p_), INT32_C(0x7f7f7f7f));
  simde_test_hvx_vector_i32_assert_equal(simde_Q6_V_lo_W(rp), simde_Q6_V_lo_W(simde_hvx_vectorpair_from_private(expected_pair_)));
  simde_test_hvx_vector_i32_assert_equal(simde_Q6_V_hi_W(rp), simde_Q6_V_hi_W(simde_hvx_vectorpair_from_private(expected_pair_)));

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmpa_WubRb)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpa_WhRb)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpa_WubWb)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpa_WubWub)
SIMDE_TEST_FUNC_LIST_ENTRY(vmpa_extremes)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
