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

#define SIMDE_TEST_HEXAGON_HVX_INSN vabs

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vabs.h"

static int
test_simde_vabs_Vb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t r[128];
  } test_vec[] = {
    { {
       INT8_C(  57),  INT8_C(  12), -INT8_C( 116),  INT8_C( 125),  INT8_C( 114),  INT8_C(  71),  INT8_C(  52),  INT8_C(  44),
      -INT8_C(  40),  INT8_C(  16),  INT8_C(  15),  INT8_C(  47),  INT8_C( 111),  INT8_C( 119),  INT8_C(  13),  INT8_C( 101),
      -INT8_C(  42),  INT8_C( 112), -INT8_C(  27), -INT8_C( 114),  INT8_C(   3),  INT8_C(  81), -INT8_C(  40), -INT8_C(  82),
      -INT8_C( 114),  INT8_C(  79),  INT8_C( 110), -INT8_C(  84),  INT8_C(  52),  INT8_C(  47), -INT8_C(  62),  INT8_C(  49),
      -INT8_C(  73), -INT8_C(  80), -INT8_C( 121),  INT8_C(  22), -INT8_C(  21),  INT8_C(  63), -INT8_C(  63),  INT8_C(  40),
      -INT8_C( 106), -INT8_C(  71),  INT8_C(  98),  INT8_C(  35),  INT8_C(  23),  INT8_C( 116), -INT8_C( 108),  INT8_C(  40),
       INT8_C( 119),  INT8_C(  51), -INT8_C(  62), -INT8_C( 114), -INT8_C(  24), -INT8_C(  70),  INT8_C(  83), -INT8_C(  67),
      -INT8_C(  75),  INT8_C( 107), -INT8_C( 120),  INT8_C(  36),  INT8_C(  87),  INT8_C( 125),  INT8_C(  83), -INT8_C(  20),
      -INT8_C(  62), -INT8_C( 118),  INT8_C( 112), -INT8_C(  90),  INT8_C(  28),  INT8_C( 117),  INT8_C(  16), -INT8_C(  95),
      -INT8_C(  51), -INT8_C( 119),  INT8_C(  33),  INT8_C( 108), -INT8_C(  95),  INT8_C( 108), -INT8_C(   1), -INT8_C(  54),
      -INT8_C(  22),  INT8_C(  73), -INT8_C( 121),  INT8_C(  71),  INT8_C( 126), -INT8_C( 122), -INT8_C(  37), -INT8_C(  52),
      -INT8_C(  71),  INT8_C( 112),  INT8_C(  70), -INT8_C(   4),  INT8_C(  46),  INT8_C(  24),  INT8_C(  56),  INT8_C(  78),
       INT8_C(  81), -INT8_C(  40),  INT8_C(  32), -INT8_C(  59), -INT8_C(  61), -INT8_C(  17), -INT8_C( 128),  INT8_C(   5),
       INT8_C(  58), -INT8_C( 120), -INT8_C(  82),  INT8_C(  57), -INT8_C( 106), -INT8_C(  34),  INT8_C(  80), -INT8_C(  24),
       INT8_C(   1), -INT8_C( 122),  INT8_C(  91),  INT8_C(  54), -INT8_C( 104),  INT8_C( 101),  INT8_C(  78), -INT8_C(  65),
       INT8_C(  82),  INT8_C(   0), -INT8_C(  91), -INT8_C(   6),  INT8_C(   9),  INT8_C(  57), -INT8_C(  71), -INT8_C(  99)
      },
      {
       INT8_C(  57),  INT8_C(  12),  INT8_C( 116),  INT8_C( 125),  INT8_C( 114),  INT8_C(  71),  INT8_C(  52),  INT8_C(  44),
       INT8_C(  40),  INT8_C(  16),  INT8_C(  15),  INT8_C(  47),  INT8_C( 111),  INT8_C( 119),  INT8_C(  13),  INT8_C( 101),
       INT8_C(  42),  INT8_C( 112),  INT8_C(  27),  INT8_C( 114),  INT8_C(   3),  INT8_C(  81),  INT8_C(  40),  INT8_C(  82),
       INT8_C( 114),  INT8_C(  79),  INT8_C( 110),  INT8_C(  84),  INT8_C(  52),  INT8_C(  47),  INT8_C(  62),  INT8_C(  49),
       INT8_C(  73),  INT8_C(  80),  INT8_C( 121),  INT8_C(  22),  INT8_C(  21),  INT8_C(  63),  INT8_C(  63),  INT8_C(  40),
       INT8_C( 106),  INT8_C(  71),  INT8_C(  98),  INT8_C(  35),  INT8_C(  23),  INT8_C( 116),  INT8_C( 108),  INT8_C(  40),
       INT8_C( 119),  INT8_C(  51),  INT8_C(  62),  INT8_C( 114),  INT8_C(  24),  INT8_C(  70),  INT8_C(  83),  INT8_C(  67),
       INT8_C(  75),  INT8_C( 107),  INT8_C( 120),  INT8_C(  36),  INT8_C(  87),  INT8_C( 125),  INT8_C(  83),  INT8_C(  20),
       INT8_C(  62),  INT8_C( 118),  INT8_C( 112),  INT8_C(  90),  INT8_C(  28),  INT8_C( 117),  INT8_C(  16),  INT8_C(  95),
       INT8_C(  51),  INT8_C( 119),  INT8_C(  33),  INT8_C( 108),  INT8_C(  95),  INT8_C( 108),  INT8_C(   1),  INT8_C(  54),
       INT8_C(  22),  INT8_C(  73),  INT8_C( 121),  INT8_C(  71),  INT8_C( 126),  INT8_C( 122),  INT8_C(  37),  INT8_C(  52),
       INT8_C(  71),  INT8_C( 112),  INT8_C(  70),  INT8_C(   4),  INT8_C(  46),  INT8_C(  24),  INT8_C(  56),  INT8_C(  78),
       INT8_C(  81),  INT8_C(  40),  INT8_C(  32),  INT8_C(  59),  INT8_C(  61),  INT8_C(  17), -INT8_C( 128),  INT8_C(   5),
       INT8_C(  58),  INT8_C( 120),  INT8_C(  82),  INT8_C(  57),  INT8_C( 106),  INT8_C(  34),  INT8_C(  80),  INT8_C(  24),
       INT8_C(   1),  INT8_C( 122),  INT8_C(  91),  INT8_C(  54),  INT8_C( 104),  INT8_C( 101),  INT8_C(  78),  INT8_C(  65),
       INT8_C(  82),  INT8_C(   0),  INT8_C(  91),  INT8_C(   6),  INT8_C(   9),  INT8_C(  57),  INT8_C(  71),  INT8_C(  99)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vb_vabs_Vb(a);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vabs_Vb_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t r[128];
  } test_vec[] = {
    { {
       INT8_C(  57),  INT8_C(  12), -INT8_C( 116),  INT8_C( 125),  INT8_C( 114),  INT8_C(  71),  INT8_C(  52),  INT8_C(  44),
      -INT8_C(  40),  INT8_C(  16),  INT8_C(  15),  INT8_C(  47),  INT8_C( 111),  INT8_C( 119),  INT8_C(  13),  INT8_C( 101),
      -INT8_C(  42),  INT8_C( 112), -INT8_C(  27), -INT8_C( 114),  INT8_C(   3),  INT8_C(  81), -INT8_C(  40), -INT8_C(  82),
      -INT8_C( 114),  INT8_C(  79),  INT8_C( 110), -INT8_C(  84),  INT8_C(  52),  INT8_C(  47), -INT8_C(  62),  INT8_C(  49),
      -INT8_C(  73), -INT8_C(  80), -INT8_C( 121),  INT8_C(  22), -INT8_C(  21),  INT8_C(  63), -INT8_C(  63),  INT8_C(  40),
      -INT8_C( 106), -INT8_C(  71),  INT8_C(  98),  INT8_C(  35),  INT8_C(  23),  INT8_C( 116), -INT8_C( 108),  INT8_C(  40),
       INT8_C( 119),  INT8_C(  51), -INT8_C(  62), -INT8_C( 114), -INT8_C(  24), -INT8_C(  70),  INT8_C(  83), -INT8_C(  67),
      -INT8_C(  75),  INT8_C( 107), -INT8_C( 120),  INT8_C(  36),  INT8_C(  87),  INT8_C( 125),  INT8_C(  83), -INT8_C(  20),
      -INT8_C(  62), -INT8_C( 118),  INT8_C( 112), -INT8_C(  90),  INT8_C(  28),  INT8_C( 117),  INT8_C(  16), -INT8_C(  95),
      -INT8_C(  51), -INT8_C( 119),  INT8_C(  33),  INT8_C( 108), -INT8_C(  95),  INT8_C( 108), -INT8_C(   1), -INT8_C(  54),
      -INT8_C(  22),  INT8_C(  73), -INT8_C( 121),  INT8_C(  71),  INT8_C( 126), -INT8_C( 122), -INT8_C(  37), -INT8_C(  52),
      -INT8_C(  71),  INT8_C( 112),  INT8_C(  70), -INT8_C(   4),  INT8_C(  46),  INT8_C(  24),  INT8_C(  56),  INT8_C(  78),
       INT8_C(  81), -INT8_C(  40),  INT8_C(  32), -INT8_C(  59), -INT8_C(  61), -INT8_C(  17), -INT8_C( 128),  INT8_C(   5),
       INT8_C(  58), -INT8_C( 120), -INT8_C(  82),  INT8_C(  57), -INT8_C( 106), -INT8_C(  34),  INT8_C(  80), -INT8_C(  24),
       INT8_C(   1), -INT8_C( 122),  INT8_C(  91),  INT8_C(  54), -INT8_C( 104),  INT8_C( 101),  INT8_C(  78), -INT8_C(  65),
       INT8_C(  82),  INT8_C(   0), -INT8_C(  91), -INT8_C(   6),  INT8_C(   9),  INT8_C(  57), -INT8_C(  71), -INT8_C(  99)
      },
      {
       INT8_C(  57),  INT8_C(  12),  INT8_C( 116),  INT8_C( 125),  INT8_C( 114),  INT8_C(  71),  INT8_C(  52),  INT8_C(  44),
       INT8_C(  40),  INT8_C(  16),  INT8_C(  15),  INT8_C(  47),  INT8_C( 111),  INT8_C( 119),  INT8_C(  13),  INT8_C( 101),
       INT8_C(  42),  INT8_C( 112),  INT8_C(  27),  INT8_C( 114),  INT8_C(   3),  INT8_C(  81),  INT8_C(  40),  INT8_C(  82),
       INT8_C( 114),  INT8_C(  79),  INT8_C( 110),  INT8_C(  84),  INT8_C(  52),  INT8_C(  47),  INT8_C(  62),  INT8_C(  49),
       INT8_C(  73),  INT8_C(  80),  INT8_C( 121),  INT8_C(  22),  INT8_C(  21),  INT8_C(  63),  INT8_C(  63),  INT8_C(  40),
       INT8_C( 106),  INT8_C(  71),  INT8_C(  98),  INT8_C(  35),  INT8_C(  23),  INT8_C( 116),  INT8_C( 108),  INT8_C(  40),
       INT8_C( 119),  INT8_C(  51),  INT8_C(  62),  INT8_C( 114),  INT8_C(  24),  INT8_C(  70),  INT8_C(  83),  INT8_C(  67),
       INT8_C(  75),  INT8_C( 107),  INT8_C( 120),  INT8_C(  36),  INT8_C(  87),  INT8_C( 125),  INT8_C(  83),  INT8_C(  20),
       INT8_C(  62),  INT8_C( 118),  INT8_C( 112),  INT8_C(  90),  INT8_C(  28),  INT8_C( 117),  INT8_C(  16),  INT8_C(  95),
       INT8_C(  51),  INT8_C( 119),  INT8_C(  33),  INT8_C( 108),  INT8_C(  95),  INT8_C( 108),  INT8_C(   1),  INT8_C(  54),
       INT8_C(  22),  INT8_C(  73),  INT8_C( 121),  INT8_C(  71),  INT8_C( 126),  INT8_C( 122),  INT8_C(  37),  INT8_C(  52),
       INT8_C(  71),  INT8_C( 112),  INT8_C(  70),  INT8_C(   4),  INT8_C(  46),  INT8_C(  24),  INT8_C(  56),  INT8_C(  78),
       INT8_C(  81),  INT8_C(  40),  INT8_C(  32),  INT8_C(  59),  INT8_C(  61),  INT8_C(  17),  INT8_C( 127),  INT8_C(   5),
       INT8_C(  58),  INT8_C( 120),  INT8_C(  82),  INT8_C(  57),  INT8_C( 106),  INT8_C(  34),  INT8_C(  80),  INT8_C(  24),
       INT8_C(   1),  INT8_C( 122),  INT8_C(  91),  INT8_C(  54),  INT8_C( 104),  INT8_C( 101),  INT8_C(  78),  INT8_C(  65),
       INT8_C(  82),  INT8_C(   0),  INT8_C(  91),  INT8_C(   6),  INT8_C(   9),  INT8_C(  57),  INT8_C(  71),  INT8_C(  99)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vb_vabs_Vb_sat(a);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vabs_Vh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[64];
    int16_t r[64];
  } test_vec[] = {
    { {
       INT16_C(  3129),  INT16_C( 32140),  INT16_C( 18290),  INT16_C( 11316),
       INT16_C(  4312),  INT16_C( 12047),  INT16_C( 30575),  INT16_C( 25869),
       INT16_C( 28886), -INT16_C( 28955),  INT16_C( 20739), -INT16_C( 20776),
       INT16_C( 20366), -INT16_C( 21394),  INT16_C( 12084),  INT16_C( 12738),
      -INT16_C( 20297),  INT16_C(  5767),  INT16_C( 16363),  INT16_C( 10433),
      -INT16_C( 18026),  INT16_C(  9058),  INT16_C( 29719),  INT16_C( 10388),
       INT16_C( 13175), -INT16_C( 28990), -INT16_C( 17688), -INT16_C( 17069),
       INT16_C( 27573),  INT16_C(  9352),  INT16_C( 32087), -INT16_C(  5037),
      -INT16_C( 30014), -INT16_C( 22928),  INT16_C( 29980), -INT16_C( 24304),
      -INT16_C( 30259),  INT16_C( 27681),  INT16_C( 27809), -INT16_C( 13569),
       INT16_C( 18922),  INT16_C( 18311), -INT16_C( 31106), -INT16_C( 13093),
       INT16_C( 28857), -INT16_C(   954),  INT16_C(  6190),  INT16_C( 20024),
      -INT16_C( 10159), -INT16_C( 15072), -INT16_C(  4157),  INT16_C(  1408),
      -INT16_C( 30662),  INT16_C( 14766), -INT16_C(  8554), -INT16_C(  6064),
      -INT16_C( 31231),  INT16_C( 13915),  INT16_C( 26008), -INT16_C( 16562),
       INT16_C(    82), -INT16_C(  1371),  INT16_C( 14601), -INT16_C( 25159)
      },
      {
       INT16_C(  3129),  INT16_C( 32140),  INT16_C( 18290),  INT16_C( 11316),
       INT16_C(  4312),  INT16_C( 12047),  INT16_C( 30575),  INT16_C( 25869),
       INT16_C( 28886),  INT16_C( 28955),  INT16_C( 20739),  INT16_C( 20776),
       INT16_C( 20366),  INT16_C( 21394),  INT16_C( 12084),  INT16_C( 12738),
       INT16_C( 20297),  INT16_C(  5767),  INT16_C( 16363),  INT16_C( 10433),
       INT16_C( 18026),  INT16_C(  9058),  INT16_C( 29719),  INT16_C( 10388),
       INT16_C( 13175),  INT16_C( 28990),  INT16_C( 17688),  INT16_C( 17069),
       INT16_C( 27573),  INT16_C(  9352),  INT16_C( 32087),  INT16_C(  5037),
       INT16_C( 30014),  INT16_C( 22928),  INT16_C( 29980),  INT16_C( 24304),
       INT16_C( 30259),  INT16_C( 27681),  INT16_C( 27809),  INT16_C( 13569),
       INT16_C( 18922),  INT16_C( 18311),  INT16_C( 31106),  INT16_C( 13093),
       INT16_C( 28857),  INT16_C(   954),  INT16_C(  6190),  INT16_C( 20024),
       INT16_C( 10159),  INT16_C( 15072),  INT16_C(  4157),  INT16_C(  1408),
       INT16_C( 30662),  INT16_C( 14766),  INT16_C(  8554),  INT16_C(  6064),
       INT16_C( 31231),  INT16_C( 13915),  INT16_C( 26008),  INT16_C( 16562),
       INT16_C(    82),  INT16_C(  1371),  INT16_C( 14601),  INT16_C( 25159)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vh_vabs_Vh(a);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vabs_Vh_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[64];
    int16_t r[64];
  } test_vec[] = {
    { {
       INT16_C(  3129),  INT16_C( 32140),  INT16_C( 18290),  INT16_C( 11316),
       INT16_C(  4312),  INT16_C( 12047),  INT16_C( 30575),  INT16_C( 25869),
       INT16_C( 28886), -INT16_C( 28955),  INT16_C( 20739), -INT16_C( 20776),
       INT16_C( 20366), -INT16_C( 21394),  INT16_C( 12084),  INT16_C( 12738),
      -INT16_C( 20297),  INT16_C(  5767),  INT16_C( 16363),  INT16_C( 10433),
      -INT16_C( 18026),  INT16_C(  9058),  INT16_C( 29719),  INT16_C( 10388),
       INT16_C( 13175), -INT16_C( 28990), -INT16_C( 17688), -INT16_C( 17069),
       INT16_C( 27573),  INT16_C(  9352),  INT16_C( 32087), -INT16_C(  5037),
      -INT16_C( 30014), -INT16_C( 22928),  INT16_C( 29980), -INT16_C( 24304),
      -INT16_C( 30259),  INT16_C( 27681),  INT16_C( 27809), -INT16_C( 13569),
       INT16_C( 18922),  INT16_C( 18311), -INT16_C( 31106), -INT16_C( 13093),
       INT16_C( 28857), -INT16_C(   954),  INT16_C(  6190),  INT16_C( 20024),
      -INT16_C( 10159), -INT16_C( 15072), -INT16_C(  4157),  INT16_C(  1408),
      -INT16_C( 30662),  INT16_C( 14766), -INT16_C(  8554), -INT16_C(  6064),
      -INT16_C( 31231),  INT16_C( 13915),  INT16_C( 26008), -INT16_C( 16562),
       INT16_C(    82), -INT16_C(  1371),  INT16_C( 14601), -INT16_C( 25159)
      },
      {
       INT16_C(  3129),  INT16_C( 32140),  INT16_C( 18290),  INT16_C( 11316),
       INT16_C(  4312),  INT16_C( 12047),  INT16_C( 30575),  INT16_C( 25869),
       INT16_C( 28886),  INT16_C( 28955),  INT16_C( 20739),  INT16_C( 20776),
       INT16_C( 20366),  INT16_C( 21394),  INT16_C( 12084),  INT16_C( 12738),
       INT16_C( 20297),  INT16_C(  5767),  INT16_C( 16363),  INT16_C( 10433),
       INT16_C( 18026),  INT16_C(  9058),  INT16_C( 29719),  INT16_C( 10388),
       INT16_C( 13175),  INT16_C( 28990),  INT16_C( 17688),  INT16_C( 17069),
       INT16_C( 27573),  INT16_C(  9352),  INT16_C( 32087),  INT16_C(  5037),
       INT16_C( 30014),  INT16_C( 22928),  INT16_C( 29980),  INT16_C( 24304),
       INT16_C( 30259),  INT16_C( 27681),  INT16_C( 27809),  INT16_C( 13569),
       INT16_C( 18922),  INT16_C( 18311),  INT16_C( 31106),  INT16_C( 13093),
       INT16_C( 28857),  INT16_C(   954),  INT16_C(  6190),  INT16_C( 20024),
       INT16_C( 10159),  INT16_C( 15072),  INT16_C(  4157),  INT16_C(  1408),
       INT16_C( 30662),  INT16_C( 14766),  INT16_C(  8554),  INT16_C(  6064),
       INT16_C( 31231),  INT16_C( 13915),  INT16_C( 26008),  INT16_C( 16562),
       INT16_C(    82),  INT16_C(  1371),  INT16_C( 14601),  INT16_C( 25159)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vh_vabs_Vh_sat(a);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vabs_Vw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[32];
    int32_t r[32];
  } test_vec[] = {
    { {
       INT32_C( 2106330169),  INT32_C(  741623666),
       INT32_C(  789516504),  INT32_C( 1695381359),
      -INT32_C( 1897565994), -INT32_C( 1361555197),
      -INT32_C( 1402056818),  INT32_C(  834809652),
       INT32_C(  377991351),  INT32_C(  683753451),
       INT32_C(  593672598),  INT32_C(  680817687),
      -INT32_C( 1899875465), -INT32_C( 1118586136),
       INT32_C(  612920245), -INT32_C(  330072745),
      -INT32_C( 1502573886), -INT32_C( 1592756964),
       INT32_C( 1814137293), -INT32_C(  889230175),
       INT32_C( 1200048618), -INT32_C(  858028418),
      -INT32_C(   62492487),  INT32_C( 1312299054),
      -INT32_C(  987703215),  INT32_C(   92336067),
       INT32_C(  967739450), -INT32_C(  397353322),
       INT32_C(  911967745), -INT32_C( 1085381224),
      -INT32_C(   89849774), -INT32_C( 1648805623)
      },
      {
       INT32_C( 2106330169),  INT32_C(  741623666),
       INT32_C(  789516504),  INT32_C( 1695381359),
       INT32_C( 1897565994),  INT32_C( 1361555197),
       INT32_C( 1402056818),  INT32_C(  834809652),
       INT32_C(  377991351),  INT32_C(  683753451),
       INT32_C(  593672598),  INT32_C(  680817687),
       INT32_C( 1899875465),  INT32_C( 1118586136),
       INT32_C(  612920245),  INT32_C(  330072745),
       INT32_C( 1502573886),  INT32_C( 1592756964),
       INT32_C( 1814137293),  INT32_C(  889230175),
       INT32_C( 1200048618),  INT32_C(  858028418),
       INT32_C(   62492487),  INT32_C( 1312299054),
       INT32_C(  987703215),  INT32_C(   92336067),
       INT32_C(  967739450),  INT32_C(  397353322),
       INT32_C(  911967745),  INT32_C( 1085381224),
       INT32_C(   89849774),  INT32_C( 1648805623)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vw_vabs_Vw(a);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vabs_Vw_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[32];
    int32_t r[32];
  } test_vec[] = {
    { {
       INT32_C( 2106330169),  INT32_C(  741623666),
       INT32_C(  789516504),  INT32_C( 1695381359),
      -INT32_C( 1897565994), -INT32_C( 1361555197),
      -INT32_C( 1402056818),  INT32_C(  834809652),
       INT32_C(  377991351),  INT32_C(  683753451),
       INT32_C(  593672598),  INT32_C(  680817687),
      -INT32_C( 1899875465), -INT32_C( 1118586136),
       INT32_C(  612920245), -INT32_C(  330072745),
      -INT32_C( 1502573886), -INT32_C( 1592756964),
       INT32_C( 1814137293), -INT32_C(  889230175),
       INT32_C( 1200048618), -INT32_C(  858028418),
      -INT32_C(   62492487),  INT32_C( 1312299054),
      -INT32_C(  987703215),  INT32_C(   92336067),
       INT32_C(  967739450), -INT32_C(  397353322),
       INT32_C(  911967745), -INT32_C( 1085381224),
      -INT32_C(   89849774), -INT32_C( 1648805623)
      },
      {
       INT32_C( 2106330169),  INT32_C(  741623666),
       INT32_C(  789516504),  INT32_C( 1695381359),
       INT32_C( 1897565994),  INT32_C( 1361555197),
       INT32_C( 1402056818),  INT32_C(  834809652),
       INT32_C(  377991351),  INT32_C(  683753451),
       INT32_C(  593672598),  INT32_C(  680817687),
       INT32_C( 1899875465),  INT32_C( 1118586136),
       INT32_C(  612920245),  INT32_C(  330072745),
       INT32_C( 1502573886),  INT32_C( 1592756964),
       INT32_C( 1814137293),  INT32_C(  889230175),
       INT32_C( 1200048618),  INT32_C(  858028418),
       INT32_C(   62492487),  INT32_C( 1312299054),
       INT32_C(  987703215),  INT32_C(   92336067),
       INT32_C(  967739450),  INT32_C(  397353322),
       INT32_C(  911967745),  INT32_C( 1085381224),
       INT32_C(   89849774),  INT32_C( 1648805623)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vw_vabs_Vw_sat(a);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vabsdiff_VubVub(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[128];
    uint8_t b[128];
    uint8_t r[128];
  } test_vec[] = {
    { {
      UINT8_C(0x39), UINT8_C(0x0C), UINT8_C(0x8C), UINT8_C(0x7D), UINT8_C(0x72), UINT8_C(0x47), UINT8_C(0x34), UINT8_C(0x2C),
      UINT8_C(0xD8), UINT8_C(0x10), UINT8_C(0x0F), UINT8_C(0x2F), UINT8_C(0x6F), UINT8_C(0x77), UINT8_C(0x0D), UINT8_C(0x65),
      UINT8_C(0xD6), UINT8_C(0x70), UINT8_C(0xE5), UINT8_C(0x8E), UINT8_C(0x03), UINT8_C(0x51), UINT8_C(0xD8), UINT8_C(0xAE),
      UINT8_C(0x8E), UINT8_C(0x4F), UINT8_C(0x6E), UINT8_C(0xAC), UINT8_C(0x34), UINT8_C(0x2F), UINT8_C(0xC2), UINT8_C(0x31),
      UINT8_C(0xB7), UINT8_C(0xB0), UINT8_C(0x87), UINT8_C(0x16), UINT8_C(0xEB), UINT8_C(0x3F), UINT8_C(0xC1), UINT8_C(0x28),
      UINT8_C(0x96), UINT8_C(0xB9), UINT8_C(0x62), UINT8_C(0x23), UINT8_C(0x17), UINT8_C(0x74), UINT8_C(0x94), UINT8_C(0x28),
      UINT8_C(0x77), UINT8_C(0x33), UINT8_C(0xC2), UINT8_C(0x8E), UINT8_C(0xE8), UINT8_C(0xBA), UINT8_C(0x53), UINT8_C(0xBD),
      UINT8_C(0xB5), UINT8_C(0x6B), UINT8_C(0x88), UINT8_C(0x24), UINT8_C(0x57), UINT8_C(0x7D), UINT8_C(0x53), UINT8_C(0xEC),
      UINT8_C(0xC2), UINT8_C(0x8A), UINT8_C(0x70), UINT8_C(0xA6), UINT8_C(0x1C), UINT8_C(0x75), UINT8_C(0x10), UINT8_C(0xA1),
      UINT8_C(0xCD), UINT8_C(0x89), UINT8_C(0x21), UINT8_C(0x6C), UINT8_C(0xA1), UINT8_C(0x6C), UINT8_C(0xFF), UINT8_C(0xCA),
      UINT8_C(0xEA), UINT8_C(0x49), UINT8_C(0x87), UINT8_C(0x47), UINT8_C(0x7E), UINT8_C(0x86), UINT8_C(0xDB), UINT8_C(0xCC),
      UINT8_C(0xB9), UINT8_C(0x70), UINT8_C(0x46), UINT8_C(0xFC), UINT8_C(0x2E), UINT8_C(0x18), UINT8_C(0x38), UINT8_C(0x4E),
      UINT8_C(0x51), UINT8_C(0xD8), UINT8_C(0x20), UINT8_C(0xC5), UINT8_C(0xC3), UINT8_C(0xEF), UINT8_C(0x80), UINT8_C(0x05),
      UINT8_C(0x3A), UINT8_C(0x88), UINT8_C(0xAE), UINT8_C(0x39), UINT8_C(0x96), UINT8_C(0xDE), UINT8_C(0x50), UINT8_C(0xE8),
      UINT8_C(0x01), UINT8_C(0x86), UINT8_C(0x5B), UINT8_C(0x36), UINT8_C(0x98), UINT8_C(0x65), UINT8_C(0x4E), UINT8_C(0xBF),
      UINT8_C(0x52), UINT8_C(0x00), UINT8_C(0xA5), UINT8_C(0xFA), UINT8_C(0x09), UINT8_C(0x39), UINT8_C(0xB9), UINT8_C(0x9D)
      },
      {
      UINT8_C(0x7A), UINT8_C(0x1D), UINT8_C(0x7B), UINT8_C(0x28), UINT8_C(0x2B), UINT8_C(0xF8), UINT8_C(0x23), UINT8_C(0x40),
      UINT8_C(0x41), UINT8_C(0xF3), UINT8_C(0x54), UINT8_C(0x87), UINT8_C(0xD8), UINT8_C(0x6C), UINT8_C(0x66), UINT8_C(0x9F),
      UINT8_C(0xCC), UINT8_C(0xBF), UINT8_C(0xE0), UINT8_C(0xE7), UINT8_C(0x3D), UINT8_C(0x7E), UINT8_C(0x73), UINT8_C(0x20),
      UINT8_C(0xAD), UINT8_C(0x0A), UINT8_C(0x75), UINT8_C(0x70), UINT8_C(0x03), UINT8_C(0x24), UINT8_C(0x1E), UINT8_C(0x75),
      UINT8_C(0x22), UINT8_C(0x10), UINT8_C(0xA9), UINT8_C(0x24), UINT8_C(0x79), UINT8_C(0x8E), UINT8_C(0xF8), UINT8_C(0x6D),
      UINT8_C(0x43), UINT8_C(0xF2), UINT8_C(0x7C), UINT8_C(0xF2), UINT8_C(0xD0), UINT8_C(0x61), UINT8_C(0x30), UINT8_C(0x31),
      UINT8_C(0xDC), UINT8_C(0xB5), UINT8_C(0xD8), UINT8_C(0xD2), UINT8_C(0xEF), UINT8_C(0x1B), UINT8_C(0x32), UINT8_C(0x1F),
      UINT8_C(0xCE), UINT8_C(0xAD), UINT8_C(0x37), UINT8_C(0x7F), UINT8_C(0x62), UINT8_C(0x61), UINT8_C(0xE5), UINT8_C(0x47),
      UINT8_C(0xD8), UINT8_C(0x5D), UINT8_C(0x8E), UINT8_C(0xEC), UINT8_C(0x7F), UINT8_C(0x26), UINT8_C(0xE2), UINT8_C(0x32),
      UINT8_C(0x19), UINT8_C(0x07), UINT8_C(0x2F), UINT8_C(0x79), UINT8_C(0x55), UINT8_C(0xD0), UINT8_C(0xF8), UINT8_C(0xF6),
      UINT8_C(0x6D), UINT8_C(0xCD), UINT8_C(0x1E), UINT8_C(0x54), UINT8_C(0xC2), UINT8_C(0x01), UINT8_C(0xC7), UINT8_C(0x87),
      UINT8_C(0xE8), UINT8_C(0x92), UINT8_C(0xD8), UINT8_C(0xF9), UINT8_C(0x4F), UINT8_C(0x61), UINT8_C(0x97), UINT8_C(0x6F),
      UINT8_C(0x1D), UINT8_C(0x1F), UINT8_C(0xA0), UINT8_C(0x1D), UINT8_C(0x19), UINT8_C(0xF4), UINT8_C(0x50), UINT8_C(0x1D),
      UINT8_C(0x29), UINT8_C(0x5F), UINT8_C(0x23), UINT8_C(0x22), UINT8_C(0x78), UINT8_C(0xCE), UINT8_C(0x3D), UINT8_C(0x7E),
      UINT8_C(0x14), UINT8_C(0x29), UINT8_C(0xD6), UINT8_C(0xA1), UINT8_C(0x85), UINT8_C(0x68), UINT8_C(0xA0), UINT8_C(0x7A),
      UINT8_C(0x87), UINT8_C(0xCA), UINT8_C(0x43), UINT8_C(0x99), UINT8_C(0xEA), UINT8_C(0xA1), UINT8_C(0x25), UINT8_C(0x04)
      },
      {
      UINT8_C(0x41), UINT8_C(0x11), UINT8_C(0x11), UINT8_C(0x55), UINT8_C(0x47), UINT8_C(0xB1), UINT8_C(0x11), UINT8_C(0x14),
      UINT8_C(0x97), UINT8_C(0xE3), UINT8_C(0x45), UINT8_C(0x58), UINT8_C(0x69), UINT8_C(0x0B), UINT8_C(0x59), UINT8_C(0x3A),
      UINT8_C(0x0A), UINT8_C(0x4F), UINT8_C(0x05), UINT8_C(0x59), UINT8_C(0x3A), UINT8_C(0x2D), UINT8_C(0x65), UINT8_C(0x8E),
      UINT8_C(0x1F), UINT8_C(0x45), UINT8_C(0x07), UINT8_C(0x3C), UINT8_C(0x31), UINT8_C(0x0B), UINT8_C(0xA4), UINT8_C(0x44),
      UINT8_C(0x95), UINT8_C(0xA0), UINT8_C(0x22), UINT8_C(0x0E), UINT8_C(0x72), UINT8_C(0x4F), UINT8_C(0x37), UINT8_C(0x45),
      UINT8_C(0x53), UINT8_C(0x39), UINT8_C(0x1A), UINT8_C(0xCF), UINT8_C(0xB9), UINT8_C(0x13), UINT8_C(0x64), UINT8_C(0x09),
      UINT8_C(0x65), UINT8_C(0x82), UINT8_C(0x16), UINT8_C(0x44), UINT8_C(0x07), UINT8_C(0x9F), UINT8_C(0x21), UINT8_C(0x9E),
      UINT8_C(0x19), UINT8_C(0x42), UINT8_C(0x51), UINT8_C(0x5B), UINT8_C(0x0B), UINT8_C(0x1C), UINT8_C(0x92), UINT8_C(0xA5),
      UINT8_C(0x16), UINT8_C(0x2D), UINT8_C(0x1E), UINT8_C(0x46), UINT8_C(0x63), UINT8_C(0x4F), UINT8_C(0xD2), UINT8_C(0x6F),
      UINT8_C(0xB4), UINT8_C(0x82), UINT8_C(0x0E), UINT8_C(0x0D), UINT8_C(0x4C), UINT8_C(0x64), UINT8_C(0x07), UINT8_C(0x2C),
      UINT8_C(0x7D), UINT8_C(0x84), UINT8_C(0x69), UINT8_C(0x0D), UINT8_C(0x44), UINT8_C(0x85), UINT8_C(0x14), UINT8_C(0x45),
      UINT8_C(0x2F), UINT8_C(0x22), UINT8_C(0x92), UINT8_C(0x03), UINT8_C(0x21), UINT8_C(0x49), UINT8_C(0x5F), UINT8_C(0x21),
      UINT8_C(0x34), UINT8_C(0xB9), UINT8_C(0x80), UINT8_C(0xA8), UINT8_C(0xAA), UINT8_C(0x05), UINT8_C(0x30), UINT8_C(0x18),
      UINT8_C(0x11), UINT8_C(0x29), UINT8_C(0x8B), UINT8_C(0x17), UINT8_C(0x1E), UINT8_C(0x10), UINT8_C(0x13), UINT8_C(0x6A),
      UINT8_C(0x13), UINT8_C(0x5D), UINT8_C(0x7B), UINT8_C(0x6B), UINT8_C(0x13), UINT8_C(0x03), UINT8_C(0x52), UINT8_C(0x45),
      UINT8_C(0x35), UINT8_C(0xCA), UINT8_C(0x62), UINT8_C(0x61), UINT8_C(0xE1), UINT8_C(0x68), UINT8_C(0x94), UINT8_C(0x99)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vabsdiff_VubVub(a, b);
    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vabsdiff_VhVh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[64];
    int16_t b[64];
    uint16_t r[64];
  } test_vec[] = {
    { {
       INT16_C(  3129),  INT16_C( 32140),  INT16_C( 18290),  INT16_C( 11316),
       INT16_C(  4312),  INT16_C( 12047),  INT16_C( 30575),  INT16_C( 25869),
       INT16_C( 28886), -INT16_C( 28955),  INT16_C( 20739), -INT16_C( 20776),
       INT16_C( 20366), -INT16_C( 21394),  INT16_C( 12084),  INT16_C( 12738),
      -INT16_C( 20297),  INT16_C(  5767),  INT16_C( 16363),  INT16_C( 10433),
      -INT16_C( 18026),  INT16_C(  9058),  INT16_C( 29719),  INT16_C( 10388),
       INT16_C( 13175), -INT16_C( 28990), -INT16_C( 17688), -INT16_C( 17069),
       INT16_C( 27573),  INT16_C(  9352),  INT16_C( 32087), -INT16_C(  5037),
      -INT16_C( 30014), -INT16_C( 22928),  INT16_C( 29980), -INT16_C( 24304),
      -INT16_C( 30259),  INT16_C( 27681),  INT16_C( 27809), -INT16_C( 13569),
       INT16_C( 18922),  INT16_C( 18311), -INT16_C( 31106), -INT16_C( 13093),
       INT16_C( 28857), -INT16_C(   954),  INT16_C(  6190),  INT16_C( 20024),
      -INT16_C( 10159), -INT16_C( 15072), -INT16_C(  4157),  INT16_C(  1408),
      -INT16_C( 30662),  INT16_C( 14766), -INT16_C(  8554), -INT16_C(  6064),
      -INT16_C( 31231),  INT16_C( 13915),  INT16_C( 26008), -INT16_C( 16562),
       INT16_C(    82), -INT16_C(  1371),  INT16_C( 14601), -INT16_C( 25159)
      },
      {
       INT16_C(  7546),  INT16_C( 10363), -INT16_C(  2005),  INT16_C( 16419),
      -INT16_C(  3263), -INT16_C( 30892),  INT16_C( 27864), -INT16_C( 24730),
      -INT16_C( 16436), -INT16_C(  6176),  INT16_C( 32317),  INT16_C(  8307),
       INT16_C(  2733),  INT16_C( 28789),  INT16_C(  9219),  INT16_C( 29982),
       INT16_C(  4130),  INT16_C(  9385), -INT16_C( 29063),  INT16_C( 28152),
      -INT16_C(  3517), -INT16_C(  3460),  INT16_C( 25040),  INT16_C( 12592),
      -INT16_C( 18980), -INT16_C( 11560),  INT16_C(  7151),  INT16_C(  7986),
      -INT16_C( 21042),  INT16_C( 32567),  INT16_C( 24930),  INT16_C( 18405),
       INT16_C( 24024), -INT16_C(  4978),  INT16_C(  9855),  INT16_C( 13026),
       INT16_C(  1817),  INT16_C( 31023), -INT16_C( 12203), -INT16_C(  2312),
      -INT16_C( 12947),  INT16_C( 21534),  INT16_C(   450), -INT16_C( 30777),
      -INT16_C( 27928), -INT16_C(  1576),  INT16_C( 24911),  INT16_C( 28567),
       INT16_C(  7965),  INT16_C(  7584), -INT16_C(  3047),  INT16_C(  7504),
       INT16_C( 24361),  INT16_C(  8739), -INT16_C( 12680),  INT16_C( 32317),
       INT16_C( 10516), -INT16_C( 24106),  INT16_C( 26757),  INT16_C( 31392),
      -INT16_C( 13689), -INT16_C( 26301), -INT16_C( 24086),  INT16_C(  1061)
      },
      {
      UINT16_C( 4417), UINT16_C(21777), UINT16_C(20295), UINT16_C( 5103),
      UINT16_C( 7575), UINT16_C(42939), UINT16_C( 2711), UINT16_C(50599),
      UINT16_C(45322), UINT16_C(22779), UINT16_C(11578), UINT16_C(29083),
      UINT16_C(17633), UINT16_C(50183), UINT16_C( 2865), UINT16_C(17244),
      UINT16_C(24427), UINT16_C( 3618), UINT16_C(45426), UINT16_C(17719),
      UINT16_C(14509), UINT16_C(12518), UINT16_C( 4679), UINT16_C( 2204),
      UINT16_C(32155), UINT16_C(17430), UINT16_C(24839), UINT16_C(25055),
      UINT16_C(48615), UINT16_C(23215), UINT16_C( 7157), UINT16_C(23442),
      UINT16_C(54038), UINT16_C(17950), UINT16_C(20125), UINT16_C(37330),
      UINT16_C(32076), UINT16_C( 3342), UINT16_C(40012), UINT16_C(11257),
      UINT16_C(31869), UINT16_C( 3223), UINT16_C(31556), UINT16_C(17684),
      UINT16_C(56785), UINT16_C(  622), UINT16_C(18721), UINT16_C( 8543),
      UINT16_C(18124), UINT16_C(22656), UINT16_C( 1110), UINT16_C( 6096),
      UINT16_C(55023), UINT16_C( 6027), UINT16_C( 4126), UINT16_C(38381),
      UINT16_C(41747), UINT16_C(38021), UINT16_C(  749), UINT16_C(47954),
      UINT16_C(13771), UINT16_C(24930), UINT16_C(38687), UINT16_C(26220)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuh_vabsdiff_VhVh(a, b);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vabsdiff_VuhVuh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[64];
    uint16_t b[64];
    uint16_t r[64];
  } test_vec[] = {
    { {
      UINT16_C( 3129), UINT16_C(32140), UINT16_C(18290), UINT16_C(11316),
      UINT16_C( 4312), UINT16_C(12047), UINT16_C(30575), UINT16_C(25869),
      UINT16_C(28886), UINT16_C(36581), UINT16_C(20739), UINT16_C(44760),
      UINT16_C(20366), UINT16_C(44142), UINT16_C(12084), UINT16_C(12738),
      UINT16_C(45239), UINT16_C( 5767), UINT16_C(16363), UINT16_C(10433),
      UINT16_C(47510), UINT16_C( 9058), UINT16_C(29719), UINT16_C(10388),
      UINT16_C(13175), UINT16_C(36546), UINT16_C(47848), UINT16_C(48467),
      UINT16_C(27573), UINT16_C( 9352), UINT16_C(32087), UINT16_C(60499),
      UINT16_C(35522), UINT16_C(42608), UINT16_C(29980), UINT16_C(41232),
      UINT16_C(35277), UINT16_C(27681), UINT16_C(27809), UINT16_C(51967),
      UINT16_C(18922), UINT16_C(18311), UINT16_C(34430), UINT16_C(52443),
      UINT16_C(28857), UINT16_C(64582), UINT16_C( 6190), UINT16_C(20024),
      UINT16_C(55377), UINT16_C(50464), UINT16_C(61379), UINT16_C( 1408),
      UINT16_C(34874), UINT16_C(14766), UINT16_C(56982), UINT16_C(59472),
      UINT16_C(34305), UINT16_C(13915), UINT16_C(26008), UINT16_C(48974),
      UINT16_C(   82), UINT16_C(64165), UINT16_C(14601), UINT16_C(40377)
      },
      {
      UINT16_C( 7546), UINT16_C(10363), UINT16_C(63531), UINT16_C(16419),
      UINT16_C(62273), UINT16_C(34644), UINT16_C(27864), UINT16_C(40806),
      UINT16_C(49100), UINT16_C(59360), UINT16_C(32317), UINT16_C( 8307),
      UINT16_C( 2733), UINT16_C(28789), UINT16_C( 9219), UINT16_C(29982),
      UINT16_C( 4130), UINT16_C( 9385), UINT16_C(36473), UINT16_C(28152),
      UINT16_C(62019), UINT16_C(62076), UINT16_C(25040), UINT16_C(12592),
      UINT16_C(46556), UINT16_C(53976), UINT16_C( 7151), UINT16_C( 7986),
      UINT16_C(44494), UINT16_C(32567), UINT16_C(24930), UINT16_C(18405),
      UINT16_C(24024), UINT16_C(60558), UINT16_C( 9855), UINT16_C(13026),
      UINT16_C( 1817), UINT16_C(31023), UINT16_C(53333), UINT16_C(63224),
      UINT16_C(52589), UINT16_C(21534), UINT16_C(  450), UINT16_C(34759),
      UINT16_C(37608), UINT16_C(63960), UINT16_C(24911), UINT16_C(28567),
      UINT16_C( 7965), UINT16_C( 7584), UINT16_C(62489), UINT16_C( 7504),
      UINT16_C(24361), UINT16_C( 8739), UINT16_C(52856), UINT16_C(32317),
      UINT16_C(10516), UINT16_C(41430), UINT16_C(26757), UINT16_C(31392),
      UINT16_C(51847), UINT16_C(39235), UINT16_C(41450), UINT16_C( 1061)
      },
      {
      UINT16_C( 4417), UINT16_C(21777), UINT16_C(45241), UINT16_C( 5103),
      UINT16_C(57961), UINT16_C(22597), UINT16_C( 2711), UINT16_C(14937),
      UINT16_C(20214), UINT16_C(22779), UINT16_C(11578), UINT16_C(36453),
      UINT16_C(17633), UINT16_C(15353), UINT16_C( 2865), UINT16_C(17244),
      UINT16_C(41109), UINT16_C( 3618), UINT16_C(20110), UINT16_C(17719),
      UINT16_C(14509), UINT16_C(53018), UINT16_C( 4679), UINT16_C( 2204),
      UINT16_C(33381), UINT16_C(17430), UINT16_C(40697), UINT16_C(40481),
      UINT16_C(16921), UINT16_C(23215), UINT16_C( 7157), UINT16_C(42094),
      UINT16_C(11498), UINT16_C(17950), UINT16_C(20125), UINT16_C(28206),
      UINT16_C(33460), UINT16_C( 3342), UINT16_C(25524), UINT16_C(11257),
      UINT16_C(33667), UINT16_C( 3223), UINT16_C(33980), UINT16_C(17684),
      UINT16_C( 8751), UINT16_C(  622), UINT16_C(18721), UINT16_C( 8543),
      UINT16_C(47412), UINT16_C(42880), UINT16_C( 1110), UINT16_C( 6096),
      UINT16_C(10513), UINT16_C( 6027), UINT16_C( 4126), UINT16_C(27155),
      UINT16_C(23789), UINT16_C(27515), UINT16_C(  749), UINT16_C(17582),
      UINT16_C(51765), UINT16_C(24930), UINT16_C(26849), UINT16_C(39316)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuh_vabsdiff_VuhVuh(a, b);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vabsdiff_VwVw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[32];
    int32_t b[32];
    uint32_t r[32];
  } test_vec[] = {
    { {
       INT32_C( 2106330169),  INT32_C(  741623666),
       INT32_C(  789516504),  INT32_C( 1695381359),
      -INT32_C( 1897565994), -INT32_C( 1361555197),
      -INT32_C( 1402056818),  INT32_C(  834809652),
       INT32_C(  377991351),  INT32_C(  683753451),
       INT32_C(  593672598),  INT32_C(  680817687),
      -INT32_C( 1899875465), -INT32_C( 1118586136),
       INT32_C(  612920245), -INT32_C(  330072745),
      -INT32_C( 1502573886), -INT32_C( 1592756964),
       INT32_C( 1814137293), -INT32_C(  889230175),
       INT32_C( 1200048618), -INT32_C(  858028418),
      -INT32_C(   62492487),  INT32_C( 1312299054),
      -INT32_C(  987703215),  INT32_C(   92336067),
       INT32_C(  967739450), -INT32_C(  397353322),
       INT32_C(  911967745), -INT32_C( 1085381224),
      -INT32_C(   89849774), -INT32_C( 1648805623)
      },
      {
       INT32_C(  679157114),  INT32_C( 1076099115),
      -INT32_C( 2024475839), -INT32_C( 1620677416),
      -INT32_C(  404701236),  INT32_C(  544439869),
       INT32_C( 1886718637),  INT32_C( 1964909571),
       INT32_C(  615059490),  INT32_C( 1845005945),
      -INT32_C(  226692541),  INT32_C(  825254352),
      -INT32_C(  757549604),  INT32_C(  523377647),
       INT32_C( 2134355406),  INT32_C( 1206215010),
      -INT32_C(  326214184),  INT32_C(  853681791),
       INT32_C( 2033125145), -INT32_C(  151465899),
       INT32_C( 1411304813), -INT32_C( 2017001022),
      -INT32_C(  103247128),  INT32_C( 1872191823),
       INT32_C(  497032989),  INT32_C(  491844633),
       INT32_C(  572743465),  INT32_C( 2117979768),
      -INT32_C( 1579800300),  INT32_C( 2057332869),
      -INT32_C( 1723610489),  INT32_C(   69575146)
      },
      {
      UINT32_C(1427173055), UINT32_C( 334475449),
      UINT32_C(2813992343), UINT32_C(3316058775),
      UINT32_C(1492864758), UINT32_C(1905995066),
      UINT32_C(3288775455), UINT32_C(1130099919),
      UINT32_C( 237068139), UINT32_C(1161252494),
      UINT32_C( 820365139), UINT32_C( 144436665),
      UINT32_C(1142325861), UINT32_C(1641963783),
      UINT32_C(1521435161), UINT32_C(1536287755),
      UINT32_C(1176359702), UINT32_C(2446438755),
      UINT32_C( 218987852), UINT32_C( 737764276),
      UINT32_C( 211256195), UINT32_C(1158972604),
      UINT32_C(  40754641), UINT32_C( 559892769),
      UINT32_C(1484736204), UINT32_C( 399508566),
      UINT32_C( 394995985), UINT32_C(2515333090),
      UINT32_C(2491768045), UINT32_C(3142714093),
      UINT32_C(1633760715), UINT32_C(1718380769)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuw_vabsdiff_VwVw(a, b);
    simde_test_hvx_vector_u32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_Vb)
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_Vb_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_Vh)
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_Vh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_Vw)
SIMDE_TEST_FUNC_LIST_ENTRY(vabs_Vw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vabsdiff_VubVub)
SIMDE_TEST_FUNC_LIST_ENTRY(vabsdiff_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vabsdiff_VuhVuh)
SIMDE_TEST_FUNC_LIST_ENTRY(vabsdiff_VwVw)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
