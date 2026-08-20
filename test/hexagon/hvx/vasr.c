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

#define SIMDE_TEST_HEXAGON_HVX_INSN vasr

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vasr.h"

/* Input vector a (shared across tests) */
#define TEST_VEC_A \
       INT8_C(   3),  INT8_C(  10),  INT8_C(  17),  INT8_C(  24),  INT8_C(  31),  INT8_C(  38),  INT8_C(  45),  INT8_C(  52), \
       INT8_C(  59),  INT8_C(  66),  INT8_C(  73),  INT8_C(  80),  INT8_C(  87),  INT8_C(  94),  INT8_C( 101),  INT8_C( 108), \
       INT8_C( 115),  INT8_C( 122), -INT8_C( 127), -INT8_C( 120), -INT8_C( 113), -INT8_C( 106), -INT8_C(  99), -INT8_C(  92), \
      -INT8_C(  85), -INT8_C(  78), -INT8_C(  71), -INT8_C(  64), -INT8_C(  57), -INT8_C(  50), -INT8_C(  43), -INT8_C(  36), \
      -INT8_C(  29), -INT8_C(  22), -INT8_C(  15), -INT8_C(   8), -INT8_C(   1),  INT8_C(   6),  INT8_C(  13),  INT8_C(  20), \
       INT8_C(  27),  INT8_C(  34),  INT8_C(  41),  INT8_C(  48),  INT8_C(  55),  INT8_C(  62),  INT8_C(  69),  INT8_C(  76), \
       INT8_C(  83),  INT8_C(  90),  INT8_C(  97),  INT8_C( 104),  INT8_C( 111),  INT8_C( 118),  INT8_C( 125), -INT8_C( 124), \
      -INT8_C( 117), -INT8_C( 110), -INT8_C( 103), -INT8_C(  96), -INT8_C(  89), -INT8_C(  82), -INT8_C(  75), -INT8_C(  68), \
      -INT8_C(  61), -INT8_C(  54), -INT8_C(  47), -INT8_C(  40), -INT8_C(  33), -INT8_C(  26), -INT8_C(  19), -INT8_C(  12), \
      -INT8_C(   5),  INT8_C(   2),  INT8_C(   9),  INT8_C(  16),  INT8_C(  23),  INT8_C(  30),  INT8_C(  37),  INT8_C(  44), \
       INT8_C(  51),  INT8_C(  58),  INT8_C(  65),  INT8_C(  72),  INT8_C(  79),  INT8_C(  86),  INT8_C(  93),  INT8_C( 100), \
       INT8_C( 107),  INT8_C( 114),  INT8_C( 121), -INT8_C( 128), -INT8_C( 121), -INT8_C( 114), -INT8_C( 107), -INT8_C( 100), \
      -INT8_C(  93), -INT8_C(  86), -INT8_C(  79), -INT8_C(  72), -INT8_C(  65), -INT8_C(  58), -INT8_C(  51), -INT8_C(  44), \
      -INT8_C(  37), -INT8_C(  30), -INT8_C(  23), -INT8_C(  16), -INT8_C(   9), -INT8_C(   2),  INT8_C(   5),  INT8_C(  12), \
       INT8_C(  19),  INT8_C(  26),  INT8_C(  33),  INT8_C(  40),  INT8_C(  47),  INT8_C(  54),  INT8_C(  61),  INT8_C(  68), \
       INT8_C(  75),  INT8_C(  82),  INT8_C(  89),  INT8_C(  96),  INT8_C( 103),  INT8_C( 110),  INT8_C( 117),  INT8_C( 124)

/* Input vector b (shared across tests) */
#define TEST_VEC_B \
       INT8_C(  11),  INT8_C(  24),  INT8_C(  37),  INT8_C(  50),  INT8_C(  63),  INT8_C(  76),  INT8_C(  89),  INT8_C( 102), \
       INT8_C( 115), -INT8_C( 128), -INT8_C( 115), -INT8_C( 102), -INT8_C(  89), -INT8_C(  76), -INT8_C(  63), -INT8_C(  50), \
      -INT8_C(  37), -INT8_C(  24), -INT8_C(  11),  INT8_C(   2),  INT8_C(  15),  INT8_C(  28),  INT8_C(  41),  INT8_C(  54), \
       INT8_C(  67),  INT8_C(  80),  INT8_C(  93),  INT8_C( 106),  INT8_C( 119), -INT8_C( 124), -INT8_C( 111), -INT8_C(  98), \
      -INT8_C(  85), -INT8_C(  72), -INT8_C(  59), -INT8_C(  46), -INT8_C(  33), -INT8_C(  20), -INT8_C(   7),  INT8_C(   6), \
       INT8_C(  19),  INT8_C(  32),  INT8_C(  45),  INT8_C(  58),  INT8_C(  71),  INT8_C(  84),  INT8_C(  97),  INT8_C( 110), \
       INT8_C( 123), -INT8_C( 120), -INT8_C( 107), -INT8_C(  94), -INT8_C(  81), -INT8_C(  68), -INT8_C(  55), -INT8_C(  42), \
      -INT8_C(  29), -INT8_C(  16), -INT8_C(   3),  INT8_C(  10),  INT8_C(  23),  INT8_C(  36),  INT8_C(  49),  INT8_C(  62), \
       INT8_C(  75),  INT8_C(  88),  INT8_C( 101),  INT8_C( 114),  INT8_C( 127), -INT8_C( 116), -INT8_C( 103), -INT8_C(  90), \
      -INT8_C(  77), -INT8_C(  64), -INT8_C(  51), -INT8_C(  38), -INT8_C(  25), -INT8_C(  12),  INT8_C(   1),  INT8_C(  14), \
       INT8_C(  27),  INT8_C(  40),  INT8_C(  53),  INT8_C(  66),  INT8_C(  79),  INT8_C(  92),  INT8_C( 105),  INT8_C( 118), \
      -INT8_C( 125), -INT8_C( 112), -INT8_C(  99), -INT8_C(  86), -INT8_C(  73), -INT8_C(  60), -INT8_C(  47), -INT8_C(  34), \
      -INT8_C(  21), -INT8_C(   8),  INT8_C(   5),  INT8_C(  18),  INT8_C(  31),  INT8_C(  44),  INT8_C(  57),  INT8_C(  70), \
       INT8_C(  83),  INT8_C(  96),  INT8_C( 109),  INT8_C( 122), -INT8_C( 121), -INT8_C( 108), -INT8_C(  95), -INT8_C(  82), \
      -INT8_C(  69), -INT8_C(  56), -INT8_C(  43), -INT8_C(  30), -INT8_C(  17), -INT8_C(   4),  INT8_C(   9),  INT8_C(  22), \
       INT8_C(  35),  INT8_C(  48),  INT8_C(  61),  INT8_C(  74),  INT8_C(  87),  INT8_C( 100),  INT8_C( 113),  INT8_C( 126)

static int
test_simde_vasr_VhR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t rt;
    int16_t r[64];
  } test_vec[] = {
    { { TEST_VEC_A },
      INT32_C(3),
      {
       INT16_C(  320),  INT16_C(  770),  INT16_C( 1219),  INT16_C( 1669),  INT16_C( 2119),  INT16_C( 2569),  INT16_C( 3018),  INT16_C( 3468),
       INT16_C( 3918), -INT16_C( 3824), -INT16_C( 3375), -INT16_C( 2925), -INT16_C( 2475), -INT16_C( 2025), -INT16_C( 1576), -INT16_C( 1126),
      -INT16_C(  676), -INT16_C(  226),  INT16_C(  223),  INT16_C(  641),  INT16_C( 1091),  INT16_C( 1541),  INT16_C( 1990),  INT16_C( 2440),
       INT16_C( 2890),  INT16_C( 3340),  INT16_C( 3789), -INT16_C( 3953), -INT16_C( 3503), -INT16_C( 3053), -INT16_C( 2604), -INT16_C( 2154),
      -INT16_C( 1704), -INT16_C( 1254), -INT16_C(  805), -INT16_C(  355),  INT16_C(   95),  INT16_C(  513),  INT16_C(  962),  INT16_C( 1412),
       INT16_C( 1862),  INT16_C( 2312),  INT16_C( 2761),  INT16_C( 3211),  INT16_C( 3661), -INT16_C( 4081), -INT16_C( 3632), -INT16_C( 3182),
      -INT16_C( 2732), -INT16_C( 2282), -INT16_C( 1833), -INT16_C( 1383), -INT16_C(  933), -INT16_C(  483), -INT16_C(   34),  INT16_C(  384),
       INT16_C(  834),  INT16_C( 1284),  INT16_C( 1733),  INT16_C( 2183),  INT16_C( 2633),  INT16_C( 3083),  INT16_C( 3532),  INT16_C( 3982)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vh_vasr_VhR(a, test_vec[i].rt);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VwR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t rt;
    int32_t r[32];
  } test_vec[] = {
    { { TEST_VEC_A },
      INT32_C(7),
      {
       INT32_C(  3154452),  INT32_C(  6838860),  INT32_C( 10523268),  INT32_C( 14207676),
      -INT32_C( 15662348), -INT32_C( 11977939), -INT32_C(  8293531), -INT32_C(  4609123),
      -INT32_C(   924715),  INT32_C(  2628109),  INT32_C(  6312516),  INT32_C(  9996924),
       INT32_C( 13681332), -INT32_C( 16188692), -INT32_C( 12504283), -INT32_C(  8819875),
      -INT32_C(  5135467), -INT32_C(  1451059),  INT32_C(  2101765),  INT32_C(  5786172),
       INT32_C(  9470580),  INT32_C( 13154988), -INT32_C( 16715036), -INT32_C( 13030627),
      -INT32_C(  9346219), -INT32_C(  5661811), -INT32_C(  1977403),  INT32_C(  1575933),
       INT32_C(  5259828),  INT32_C(  8944236),  INT32_C( 12628644),  INT32_C( 16313052)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vw_vasr_VwR(a, test_vec[i].rt);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VhVh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int16_t r[64];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      {
       INT16_C(    1),  INT16_C(  192),  INT16_C(19518),  INT16_C( 5760),  INT16_C(24576),  INT16_C(    2),  INT16_C(  188),  INT16_C(13874),
       INT16_C(20064),  INT16_C( 2048), -INT16_C(    1), -INT16_C(   46), -INT16_C( 2475),  INT16_C( 1480), -INT16_C(29184), -INT16_C(32768),
      -INT16_C(    3), -INT16_C(   57),  INT16_C( 3582),  INT16_C( 1664),  INT16_C(24576),  INT16_C(    1),  INT16_C(  124),  INT16_C( 9762),
       INT16_C(19040),  INT16_C( 2048),  INT16_C(    0), -INT16_C(   62), -INT16_C( 3503),  INT16_C( 1224),  INT16_C(19968), -INT16_C(32768),
      -INT16_C(    7), -INT16_C(  314), -INT16_C(12866),  INT16_C(30336),  INT16_C(24576),  INT16_C(    0),  INT16_C(   60),  INT16_C( 5650),
       INT16_C(18016),  INT16_C( 2048),  INT16_C(    0),  INT16_C(   50),  INT16_C( 3661),  INT16_C(  968),  INT16_C( 3584), -INT16_C(32768),
      -INT16_C(   11), -INT16_C(  571), -INT16_C(29314),  INT16_C(26240),  INT16_C(24576), -INT16_C(    1), -INT16_C(    3),  INT16_C( 1538),
       INT16_C(16992),  INT16_C( 2048),  INT16_C(    0),  INT16_C(   34),  INT16_C( 2633),  INT16_C(  712), -INT16_C(12800), -INT16_C(32768)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vasr_VhVh(a, b);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VwVw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t r[32];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      {
       INT32_C(   197153),  INT32_C(1750748222),  INT32_C( 675766272), -INT32_C(1375731712),
      -INT32_C(       15), -INT32_C(     46789), -INT32_C( 132696491), -INT32_C(1415737856),
       INT32_C(1549795328),  INT32_C(         0),  INT32_C(      1541),  INT32_C(  9996924),
       INT32_C( 204163680), -INT32_C( 320995328),  INT32_C(1610612736), -INT32_C(      135),
      -INT32_C(   320967), -INT32_C( 371470914),  INT32_C( 543121408),  INT32_C( 771751936),
       INT32_C(         9),  INT32_C(     51386), -INT32_C( 267440563),  INT32_C( 723324416),
       INT32_C(1415577600), -INT32_C(         1), -INT32_C(      483),  INT32_C(  1575933),
       INT32_C( 69419616),  INT32_C(1818099712),  INT32_C(1610612736),  INT32_C(       248)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vasr_VwVw(a, b);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VwVwR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    int16_t r[64];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(5),
      {
       INT16_C(10432), -INT16_C(30640), -INT16_C(13727),  INT16_C(26928),  INT16_C(27651),  INT16_C(18961),  INT16_C( 3493),  INT16_C(10994),
      -INT16_C(20666),  INT16_C( 3027),  INT16_C(18656), -INT16_C( 4940), -INT16_C( 5502), -INT16_C(12907), -INT16_C(29661), -INT16_C(20874),
       INT16_C(11717), -INT16_C(28841), -INT16_C(12442),  INT16_C(26679),  INT16_C(26880),  INT16_C(18704),  INT16_C( 2722),  INT16_C(10737),
      -INT16_C(21437),  INT16_C( 2770),  INT16_C(19941), -INT16_C( 5197), -INT16_C( 4217), -INT16_C(13164), -INT16_C(30432), -INT16_C(21131),
       INT16_C(10946), -INT16_C(29098), -INT16_C(13213),  INT16_C(28470),  INT16_C(28165),  INT16_C(18455),  INT16_C( 4007),  INT16_C(10480),
      -INT16_C(22208),  INT16_C( 2513),  INT16_C(19170), -INT16_C( 5454), -INT16_C( 4988), -INT16_C(13421), -INT16_C(29147), -INT16_C(21388),
       INT16_C(12231), -INT16_C(29355), -INT16_C(13984),  INT16_C(28213),  INT16_C(27394),  INT16_C(20246),  INT16_C( 3236),  INT16_C(12279),
      -INT16_C(20923),  INT16_C( 2256),  INT16_C(20455), -INT16_C( 5711), -INT16_C( 5759), -INT16_C(13678), -INT16_C(29918), -INT16_C(21645)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vasr_VwVwR(a, b, test_vec[i].rt);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VwVwR_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    int16_t r[64];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(5),
      {
       INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768),  INT16_C(32767),
       INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768), -INT16_C(32768), -INT16_C(32768),
      -INT16_C(32768), -INT16_C(32768),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),
      -INT16_C(32768),  INT16_C(32767), -INT16_C(32768), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768),
       INT16_C(32767), -INT16_C(32768), -INT16_C(32768), -INT16_C(32768), -INT16_C(32768),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),
       INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767), -INT16_C(32768), -INT16_C(32768), -INT16_C(32768), -INT16_C(32768),
       INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768), -INT16_C(32768),  INT16_C(32767),
      -INT16_C(32768),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vasr_VwVwR_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VwVwR_rnd_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    int16_t r[64];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(5),
      {
       INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768),  INT16_C(32767),
       INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768), -INT16_C(32768), -INT16_C(32768),
      -INT16_C(32768), -INT16_C(32768),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),
      -INT16_C(32768),  INT16_C(32767), -INT16_C(32768), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768),
       INT16_C(32767), -INT16_C(32768), -INT16_C(32768), -INT16_C(32768), -INT16_C(32768),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),
       INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767), -INT16_C(32768), -INT16_C(32768), -INT16_C(32768), -INT16_C(32768),
       INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768),  INT16_C(32767), -INT16_C(32768), -INT16_C(32768),  INT16_C(32767),
      -INT16_C(32768),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767),  INT16_C(32767)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vasr_VwVwR_rnd_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VwVwR_sat_u(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    uint16_t r[64];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(5),
      {
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0),
      UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(65535),
      UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuh_vasr_VwVwR_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VwVwR_rnd_sat_u(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    uint16_t r[64];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(5),
      {
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0),
      UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(65535),
      UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuh_vasr_VwVwR_rnd_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VhVhR_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    int8_t r[128];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(3),
      {
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
      -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127),
      -INT8_C( 128),  INT8_C( 127),  INT8_C(  94), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),
       INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
      -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),
       INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128),  INT8_C(  95), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
      -INT8_C( 128),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),
       INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C(  34), -INT8_C( 128),  INT8_C( 127),
      -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C(  99),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vb_vasr_VhVhR_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VhVhR_rnd_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    int8_t r[128];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(3),
      {
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
      -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127),
      -INT8_C( 128),  INT8_C( 127),  INT8_C(  95), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),
       INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
      -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),
       INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128),  INT8_C(  95), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
      -INT8_C( 128),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),
       INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C(  33), -INT8_C( 128),  INT8_C( 127),
      -INT8_C( 128),  INT8_C( 127), -INT8_C( 128),  INT8_C( 127), -INT8_C(  98),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vb_vasr_VhVhR_rnd_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VhVhR_sat_u(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(3),
      {
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255),
      UINT8_C(  0), UINT8_C(255), UINT8_C( 94), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0),
      UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(223), UINT8_C(223), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0),
      UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 95), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0),
      UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255),
      UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vasr_VhVhR_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VhVhR_rnd_sat_u(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(3),
      {
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255),
      UINT8_C(  0), UINT8_C(255), UINT8_C( 95), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0),
      UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(224), UINT8_C(223), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0),
      UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C( 95), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0),
      UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255),
      UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vasr_VhVhR_rnd_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VuwVuwR_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    uint16_t r[64];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(5),
      {
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuh_vasr_VuwVuwR_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VuwVuwR_rnd_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    uint16_t r[64];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(5),
      {
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vuh_vasr_VuwVuwR_rnd_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VuhVuhR_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(3),
      {
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C( 94), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(223), UINT8_C(223), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C( 95), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vasr_VuhVuhR_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasr_VuhVuhR_rnd_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    uint8_t r[128];
  } test_vec[] = {
    { { TEST_VEC_A },
      { TEST_VEC_B },
      INT32_C(3),
      {
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C( 95), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(224), UINT8_C(223), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C( 95), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vasr_VuhVuhR_rnd_sat(a, b, test_vec[i].rt);
    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasracc_VwVwR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t x[128];
    int8_t a[128];
    int32_t rt;
    int32_t r[32];
  } test_vec[] = {
    { { TEST_VEC_B },
      { TEST_VEC_A },
      INT32_C(5),
      {
       INT32_C( 853909595),  INT32_C(1744483695), -INT32_C(1659909500), -INT32_C( 769335399),
      -INT32_C(  12979026),  INT32_C( 860752067),  INT32_C(1751326168), -INT32_C(1653067027),
      -INT32_C( 762492926),  INT32_C( 127554838),  INT32_C(1001285923),  INT32_C(1891860024),
      -INT32_C(1512533171), -INT32_C( 756176798),  INT32_C( 134397303),  INT32_C(1008128396),
       INT32_C(1898702497), -INT32_C(1505690699), -INT32_C( 615642934),  INT32_C( 258153943),
       INT32_C(1148662252),  INT32_C(2039236353), -INT32_C(1499374570), -INT32_C( 608800469),
       INT32_C( 264996416),  INT32_C(1155504724),  INT32_C(2046078825), -INT32_C(1358838658),
      -INT32_C( 468266613),  INT32_C( 405530272),  INT32_C(1296038581), -INT32_C(2108354614)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vw_vasracc_VwVwR(x, a, test_vec[i].rt);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vasracc_VhVhR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t x[128];
    int8_t a[128];
    int32_t rt;
    int16_t r[64];
  } test_vec[] = {
    { { TEST_VEC_B },
      { TEST_VEC_A },
      INT32_C(4),
      {
       INT16_C( 6315),  INT16_C(13222),  INT16_C(20128),  INT16_C(27035), -INT16_C(31594), -INT16_C(24687), -INT16_C(17780), -INT16_C(10873),
      -INT16_C( 3966), -INT16_C( 1155),  INT16_C( 5495),  INT16_C(12402),  INT16_C(19309),  INT16_C(26216), -INT16_C(32413), -INT16_C(25506),
      -INT16_C(18599), -INT16_C(11692), -INT16_C( 4786),  INT16_C( 2105),  INT16_C( 8756),  INT16_C(15663),  INT16_C(22570),  INT16_C(29477),
      -INT16_C(29152), -INT16_C(22245), -INT16_C(15339), -INT16_C(12528), -INT16_C( 5621),  INT16_C( 1286),  INT16_C( 7937),  INT16_C(14844),
       INT16_C(21751),  INT16_C(28658), -INT16_C(29972), -INT16_C(23065), -INT16_C(16158), -INT16_C( 9267), -INT16_C( 2360),  INT16_C( 4291),
       INT16_C(11198),  INT16_C(18105),  INT16_C(25011),  INT16_C(31918), -INT16_C(26711), -INT16_C(23900), -INT16_C(16993), -INT16_C(10086),
      -INT16_C( 3179),  INT16_C( 3472),  INT16_C(10378),  INT16_C(17285),  INT16_C(24192),  INT16_C(31099), -INT16_C(27530), -INT16_C(20639),
      -INT16_C(13732), -INT16_C( 6825),  INT16_C(   81),  INT16_C( 6732),  INT16_C(13639),  INT16_C(20546),  INT16_C(27453), -INT16_C(31176)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vh_vasracc_VhVhR(x, a, test_vec[i].rt);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VhR)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VwR)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VwVw)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VwVwR)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VwVwR_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VwVwR_rnd_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VwVwR_sat_u)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VwVwR_rnd_sat_u)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VhVhR_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VhVhR_rnd_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VhVhR_sat_u)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VhVhR_rnd_sat_u)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VuwVuwR_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VuwVuwR_rnd_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VuhVuhR_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vasr_VuhVuhR_rnd_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vasracc_VwVwR)
SIMDE_TEST_FUNC_LIST_ENTRY(vasracc_VhVhR)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
