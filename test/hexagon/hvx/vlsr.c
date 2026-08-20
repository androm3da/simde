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

#define SIMDE_TEST_HEXAGON_HVX_INSN vlsr

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vlsr.h"

static int
test_simde_vlsr_VuhR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t rt;
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
      INT32_C(3),
      {
      UINT16_C(  320), UINT16_C(  770), UINT16_C( 1219), UINT16_C( 1669), UINT16_C( 2119), UINT16_C( 2569), UINT16_C( 3018), UINT16_C( 3468),
      UINT16_C( 3918), UINT16_C( 4368), UINT16_C( 4817), UINT16_C( 5267), UINT16_C( 5717), UINT16_C( 6167), UINT16_C( 6616), UINT16_C( 7066),
      UINT16_C( 7516), UINT16_C( 7966), UINT16_C(  223), UINT16_C(  641), UINT16_C( 1091), UINT16_C( 1541), UINT16_C( 1990), UINT16_C( 2440),
      UINT16_C( 2890), UINT16_C( 3340), UINT16_C( 3789), UINT16_C( 4239), UINT16_C( 4689), UINT16_C( 5139), UINT16_C( 5588), UINT16_C( 6038),
      UINT16_C( 6488), UINT16_C( 6938), UINT16_C( 7387), UINT16_C( 7837), UINT16_C(   95), UINT16_C(  513), UINT16_C(  962), UINT16_C( 1412),
      UINT16_C( 1862), UINT16_C( 2312), UINT16_C( 2761), UINT16_C( 3211), UINT16_C( 3661), UINT16_C( 4111), UINT16_C( 4560), UINT16_C( 5010),
      UINT16_C( 5460), UINT16_C( 5910), UINT16_C( 6359), UINT16_C( 6809), UINT16_C( 7259), UINT16_C( 7709), UINT16_C( 8158), UINT16_C(  384),
      UINT16_C(  834), UINT16_C( 1284), UINT16_C( 1733), UINT16_C( 2183), UINT16_C( 2633), UINT16_C( 3083), UINT16_C( 3532), UINT16_C( 3982)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vuh_vlsr_VuhR(a, test_vec[i].rt);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlsr_VuwR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t rt;
    uint32_t r[32];
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
      INT32_C(7),
      {
      UINT32_C(  3154452), UINT32_C(  6838860), UINT32_C( 10523268), UINT32_C( 14207676),
      UINT32_C( 17892084), UINT32_C( 21576493), UINT32_C( 25260901), UINT32_C( 28945309),
      UINT32_C( 32629717), UINT32_C(  2628109), UINT32_C(  6312516), UINT32_C(  9996924),
      UINT32_C( 13681332), UINT32_C( 17365740), UINT32_C( 21050149), UINT32_C( 24734557),
      UINT32_C( 28418965), UINT32_C( 32103373), UINT32_C(  2101765), UINT32_C(  5786172),
      UINT32_C(  9470580), UINT32_C( 13154988), UINT32_C( 16839396), UINT32_C( 20523805),
      UINT32_C( 24208213), UINT32_C( 27892621), UINT32_C( 31577029), UINT32_C(  1575933),
      UINT32_C(  5259828), UINT32_C(  8944236), UINT32_C( 12628644), UINT32_C( 16313052)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vuw_vlsr_VuwR(a, test_vec[i].rt);
    simde_test_hvx_vector_u32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlsr_VubR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t rt;
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
      INT32_C(2),
      {
      UINT8_C(  0), UINT8_C(  2), UINT8_C(  4), UINT8_C(  6), UINT8_C(  7), UINT8_C(  9), UINT8_C( 11), UINT8_C( 13),
      UINT8_C( 14), UINT8_C( 16), UINT8_C( 18), UINT8_C( 20), UINT8_C( 21), UINT8_C( 23), UINT8_C( 25), UINT8_C( 27),
      UINT8_C( 28), UINT8_C( 30), UINT8_C( 32), UINT8_C( 34), UINT8_C( 35), UINT8_C( 37), UINT8_C( 39), UINT8_C( 41),
      UINT8_C( 42), UINT8_C( 44), UINT8_C( 46), UINT8_C( 48), UINT8_C( 49), UINT8_C( 51), UINT8_C( 53), UINT8_C( 55),
      UINT8_C( 56), UINT8_C( 58), UINT8_C( 60), UINT8_C( 62), UINT8_C( 63), UINT8_C(  1), UINT8_C(  3), UINT8_C(  5),
      UINT8_C(  6), UINT8_C(  8), UINT8_C( 10), UINT8_C( 12), UINT8_C( 13), UINT8_C( 15), UINT8_C( 17), UINT8_C( 19),
      UINT8_C( 20), UINT8_C( 22), UINT8_C( 24), UINT8_C( 26), UINT8_C( 27), UINT8_C( 29), UINT8_C( 31), UINT8_C( 33),
      UINT8_C( 34), UINT8_C( 36), UINT8_C( 38), UINT8_C( 40), UINT8_C( 41), UINT8_C( 43), UINT8_C( 45), UINT8_C( 47),
      UINT8_C( 48), UINT8_C( 50), UINT8_C( 52), UINT8_C( 54), UINT8_C( 55), UINT8_C( 57), UINT8_C( 59), UINT8_C( 61),
      UINT8_C( 62), UINT8_C(  0), UINT8_C(  2), UINT8_C(  4), UINT8_C(  5), UINT8_C(  7), UINT8_C(  9), UINT8_C( 11),
      UINT8_C( 12), UINT8_C( 14), UINT8_C( 16), UINT8_C( 18), UINT8_C( 19), UINT8_C( 21), UINT8_C( 23), UINT8_C( 25),
      UINT8_C( 26), UINT8_C( 28), UINT8_C( 30), UINT8_C( 32), UINT8_C( 33), UINT8_C( 35), UINT8_C( 37), UINT8_C( 39),
      UINT8_C( 40), UINT8_C( 42), UINT8_C( 44), UINT8_C( 46), UINT8_C( 47), UINT8_C( 49), UINT8_C( 51), UINT8_C( 53),
      UINT8_C( 54), UINT8_C( 56), UINT8_C( 58), UINT8_C( 60), UINT8_C( 61), UINT8_C( 63), UINT8_C(  1), UINT8_C(  3),
      UINT8_C(  4), UINT8_C(  6), UINT8_C(  8), UINT8_C( 10), UINT8_C( 11), UINT8_C( 13), UINT8_C( 15), UINT8_C( 17),
      UINT8_C( 18), UINT8_C( 20), UINT8_C( 22), UINT8_C( 24), UINT8_C( 25), UINT8_C( 27), UINT8_C( 29), UINT8_C( 31)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vub_vlsr_VubR(a, test_vec[i].rt);
    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlsr_VhVh(SIMDE_MUNIT_TEST_ARGS) {
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
      UINT16_C(    1), UINT16_C(  192), UINT16_C(19518), UINT16_C( 5760), UINT16_C(24576), UINT16_C(    2), UINT16_C(  188), UINT16_C(13874),
      UINT16_C(20064), UINT16_C( 2048), UINT16_C(    1), UINT16_C(   82), UINT16_C( 5717), UINT16_C( 1480), UINT16_C(36352), UINT16_C(32768),
      UINT16_C(   29), UINT16_C( 1991), UINT16_C( 3582), UINT16_C( 1664), UINT16_C(24576), UINT16_C(    1), UINT16_C(  124), UINT16_C( 9762),
      UINT16_C(19040), UINT16_C( 2048), UINT16_C(    0), UINT16_C(   66), UINT16_C( 4689), UINT16_C( 1224), UINT16_C(19968), UINT16_C(32768),
      UINT16_C(   25), UINT16_C( 1734), UINT16_C(52670), UINT16_C(30336), UINT16_C(24576), UINT16_C(    0), UINT16_C(   60), UINT16_C( 5650),
      UINT16_C(18016), UINT16_C( 2048), UINT16_C(    0), UINT16_C(   50), UINT16_C( 3661), UINT16_C(  968), UINT16_C( 3584), UINT16_C(32768),
      UINT16_C(   21), UINT16_C( 1477), UINT16_C(36222), UINT16_C(26240), UINT16_C(24576), UINT16_C(    7), UINT16_C(  509), UINT16_C( 1538),
      UINT16_C(16992), UINT16_C( 2048), UINT16_C(    0), UINT16_C(   34), UINT16_C( 2633), UINT16_C(  712), UINT16_C(52736), UINT16_C(32768)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vlsr_VhVh(a, b);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vlsr_VwVw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    uint32_t r[32];
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
      UINT32_C(   197153), UINT32_C(1750748222), UINT32_C( 675766272), UINT32_C(2919235584),
      UINT32_C(       17), UINT32_C(     84283), UINT32_C( 404174421), UINT32_C(2879229440),
      UINT32_C(1549795328), UINT32_C(         0), UINT32_C(      1541), UINT32_C(   9996924),
      UINT32_C( 204163680), UINT32_C(3973971968), UINT32_C(1610612736), UINT32_C(       377),
      UINT32_C(   1776185), UINT32_C(3923496382), UINT32_C( 543121408), UINT32_C( 771751936),
      UINT32_C(         9), UINT32_C(     51386), UINT32_C( 269430349), UINT32_C( 723324416),
      UINT32_C(1415577600), UINT32_C(         1), UINT32_C(      7709), UINT32_C(   1575933),
      UINT32_C(  69419616), UINT32_C(1818099712), UINT32_C(1610612736), UINT32_C(       248)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vlsr_VwVw(a, b);
    simde_test_hvx_vector_u32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vlsr_VuhR)
SIMDE_TEST_FUNC_LIST_ENTRY(vlsr_VuwR)
SIMDE_TEST_FUNC_LIST_ENTRY(vlsr_VubR)
SIMDE_TEST_FUNC_LIST_ENTRY(vlsr_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vlsr_VwVw)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
