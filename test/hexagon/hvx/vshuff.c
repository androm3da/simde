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

#define SIMDE_TEST_HEXAGON_HVX_INSN vshuff

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vshuff.h"

#define SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE 128
#define SIMDE_TEST_HVX_FIXTURE_CHUNKS (SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE / SIMDE_HVX_VECTOR_SIZE)

static simde_hvx_vector_t
simde_test_hvx_fixture_vector_load(const void* ptr, size_t chunk) {
  return simde_test_hvx_vector_load(
    HEDLEY_REINTERPRET_CAST(const uint8_t*, ptr) + (chunk * SIMDE_HVX_VECTOR_SIZE));
}

static simde_hvx_vector_t
simde_test_hvx_fixture_shuffle_load(const int8_t* a, const int8_t* r, size_t chunk, size_t element_size, int deal) {
  if (SIMDE_HVX_VECTOR_SIZE == SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE) {
    return simde_test_hvx_vector_load(r);
  }

  int8_t expected[SIMDE_HVX_VECTOR_SIZE];
  const size_t offset = chunk * SIMDE_HVX_VECTOR_SIZE;
  const size_t elements = SIMDE_HVX_VECTOR_SIZE / element_size;
  for (size_t i = 0 ; i < (elements / 2) ; i++) {
    const size_t x = deal ? i : 2 * i;
    const size_t y = deal ? (elements / 2) + i : (2 * i) + 1;
    const size_t even = deal ? 2 * i : i;
    const size_t odd = deal ? (2 * i) + 1 : (elements / 2) + i;
    simde_memcpy(expected + (x * element_size), a + offset + (even * element_size), element_size);
    simde_memcpy(expected + (y * element_size), a + offset + (odd * element_size), element_size);
  }
  return simde_test_hvx_vector_load(expected);
}

static simde_hvx_vector_t
simde_test_hvx_fixture_deale_load(const int8_t* a, const int8_t* b, const int8_t* r, size_t chunk) {
  if (SIMDE_HVX_VECTOR_SIZE == SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE) {
    return simde_test_hvx_vector_load(r);
  }

  int8_t expected[SIMDE_HVX_VECTOR_SIZE];
  const size_t offset = chunk * SIMDE_HVX_VECTOR_SIZE;
  const size_t quarter = SIMDE_HVX_VECTOR_SIZE / 4;
  for (size_t i = 0 ; i < quarter ; i++) {
    expected[i] = b[offset + (4 * i)];
    expected[quarter + i] = b[offset + (4 * i) + 2];
    expected[(2 * quarter) + i] = a[offset + (4 * i)];
    expected[(3 * quarter) + i] = a[offset + (4 * i) + 2];
  }
  return simde_test_hvx_vector_load(expected);
}

static int
test_simde_vshuff_Vb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
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
         INT8_C(   3), -INT8_C(  61),  INT8_C(  10), -INT8_C(  54),  INT8_C(  17), -INT8_C(  47),  INT8_C(  24), -INT8_C(  40),
         INT8_C(  31), -INT8_C(  33),  INT8_C(  38), -INT8_C(  26),  INT8_C(  45), -INT8_C(  19),  INT8_C(  52), -INT8_C(  12),
         INT8_C(  59), -INT8_C(   5),  INT8_C(  66),  INT8_C(   2),  INT8_C(  73),  INT8_C(   9),  INT8_C(  80),  INT8_C(  16),
         INT8_C(  87),  INT8_C(  23),  INT8_C(  94),  INT8_C(  30),  INT8_C( 101),  INT8_C(  37),  INT8_C( 108),  INT8_C(  44),
         INT8_C( 115),  INT8_C(  51),  INT8_C( 122),  INT8_C(  58), -INT8_C( 127),  INT8_C(  65), -INT8_C( 120),  INT8_C(  72),
        -INT8_C( 113),  INT8_C(  79), -INT8_C( 106),  INT8_C(  86), -INT8_C(  99),  INT8_C(  93), -INT8_C(  92),  INT8_C( 100),
        -INT8_C(  85),  INT8_C( 107), -INT8_C(  78),  INT8_C( 114), -INT8_C(  71),  INT8_C( 121), -INT8_C(  64), -INT8_C( 128),
        -INT8_C(  57), -INT8_C( 121), -INT8_C(  50), -INT8_C( 114), -INT8_C(  43), -INT8_C( 107), -INT8_C(  36), -INT8_C( 100),
        -INT8_C(  29), -INT8_C(  93), -INT8_C(  22), -INT8_C(  86), -INT8_C(  15), -INT8_C(  79), -INT8_C(   8), -INT8_C(  72),
        -INT8_C(   1), -INT8_C(  65),  INT8_C(   6), -INT8_C(  58),  INT8_C(  13), -INT8_C(  51),  INT8_C(  20), -INT8_C(  44),
         INT8_C(  27), -INT8_C(  37),  INT8_C(  34), -INT8_C(  30),  INT8_C(  41), -INT8_C(  23),  INT8_C(  48), -INT8_C(  16),
         INT8_C(  55), -INT8_C(   9),  INT8_C(  62), -INT8_C(   2),  INT8_C(  69),  INT8_C(   5),  INT8_C(  76),  INT8_C(  12),
         INT8_C(  83),  INT8_C(  19),  INT8_C(  90),  INT8_C(  26),  INT8_C(  97),  INT8_C(  33),  INT8_C( 104),  INT8_C(  40),
         INT8_C( 111),  INT8_C(  47),  INT8_C( 118),  INT8_C(  54),  INT8_C( 125),  INT8_C(  61), -INT8_C( 124),  INT8_C(  68),
        -INT8_C( 117),  INT8_C(  75), -INT8_C( 110),  INT8_C(  82), -INT8_C( 103),  INT8_C(  89), -INT8_C(  96),  INT8_C(  96),
        -INT8_C(  89),  INT8_C( 103), -INT8_C(  82),  INT8_C( 110), -INT8_C(  75),  INT8_C( 117), -INT8_C(  68),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_test_hvx_vector_i8_assert_equal(
        simde_Q6_Vb_vshuff_Vb(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk)),
        simde_test_hvx_fixture_shuffle_load(test_vec[i].a, test_vec[i].r, chunk, 1, 0));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vshuff_Vh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
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
         INT8_C(   3),  INT8_C(  10), -INT8_C(  61), -INT8_C(  54),  INT8_C(  17),  INT8_C(  24), -INT8_C(  47), -INT8_C(  40),
         INT8_C(  31),  INT8_C(  38), -INT8_C(  33), -INT8_C(  26),  INT8_C(  45),  INT8_C(  52), -INT8_C(  19), -INT8_C(  12),
         INT8_C(  59),  INT8_C(  66), -INT8_C(   5),  INT8_C(   2),  INT8_C(  73),  INT8_C(  80),  INT8_C(   9),  INT8_C(  16),
         INT8_C(  87),  INT8_C(  94),  INT8_C(  23),  INT8_C(  30),  INT8_C( 101),  INT8_C( 108),  INT8_C(  37),  INT8_C(  44),
         INT8_C( 115),  INT8_C( 122),  INT8_C(  51),  INT8_C(  58), -INT8_C( 127), -INT8_C( 120),  INT8_C(  65),  INT8_C(  72),
        -INT8_C( 113), -INT8_C( 106),  INT8_C(  79),  INT8_C(  86), -INT8_C(  99), -INT8_C(  92),  INT8_C(  93),  INT8_C( 100),
        -INT8_C(  85), -INT8_C(  78),  INT8_C( 107),  INT8_C( 114), -INT8_C(  71), -INT8_C(  64),  INT8_C( 121), -INT8_C( 128),
        -INT8_C(  57), -INT8_C(  50), -INT8_C( 121), -INT8_C( 114), -INT8_C(  43), -INT8_C(  36), -INT8_C( 107), -INT8_C( 100),
        -INT8_C(  29), -INT8_C(  22), -INT8_C(  93), -INT8_C(  86), -INT8_C(  15), -INT8_C(   8), -INT8_C(  79), -INT8_C(  72),
        -INT8_C(   1),  INT8_C(   6), -INT8_C(  65), -INT8_C(  58),  INT8_C(  13),  INT8_C(  20), -INT8_C(  51), -INT8_C(  44),
         INT8_C(  27),  INT8_C(  34), -INT8_C(  37), -INT8_C(  30),  INT8_C(  41),  INT8_C(  48), -INT8_C(  23), -INT8_C(  16),
         INT8_C(  55),  INT8_C(  62), -INT8_C(   9), -INT8_C(   2),  INT8_C(  69),  INT8_C(  76),  INT8_C(   5),  INT8_C(  12),
         INT8_C(  83),  INT8_C(  90),  INT8_C(  19),  INT8_C(  26),  INT8_C(  97),  INT8_C( 104),  INT8_C(  33),  INT8_C(  40),
         INT8_C( 111),  INT8_C( 118),  INT8_C(  47),  INT8_C(  54),  INT8_C( 125), -INT8_C( 124),  INT8_C(  61),  INT8_C(  68),
        -INT8_C( 117), -INT8_C( 110),  INT8_C(  75),  INT8_C(  82), -INT8_C( 103), -INT8_C(  96),  INT8_C(  89),  INT8_C(  96),
        -INT8_C(  89), -INT8_C(  82),  INT8_C( 103),  INT8_C( 110), -INT8_C(  75), -INT8_C(  68),  INT8_C( 117),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_test_hvx_vector_i8_assert_equal(
        simde_Q6_Vh_vshuff_Vh(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk)),
        simde_test_hvx_fixture_shuffle_load(test_vec[i].a, test_vec[i].r, chunk, 2, 0));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vdeal_Vb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
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
         INT8_C(   3),  INT8_C(  17),  INT8_C(  31),  INT8_C(  45),  INT8_C(  59),  INT8_C(  73),  INT8_C(  87),  INT8_C( 101),
         INT8_C( 115), -INT8_C( 127), -INT8_C( 113), -INT8_C(  99), -INT8_C(  85), -INT8_C(  71), -INT8_C(  57), -INT8_C(  43),
        -INT8_C(  29), -INT8_C(  15), -INT8_C(   1),  INT8_C(  13),  INT8_C(  27),  INT8_C(  41),  INT8_C(  55),  INT8_C(  69),
         INT8_C(  83),  INT8_C(  97),  INT8_C( 111),  INT8_C( 125), -INT8_C( 117), -INT8_C( 103), -INT8_C(  89), -INT8_C(  75),
        -INT8_C(  61), -INT8_C(  47), -INT8_C(  33), -INT8_C(  19), -INT8_C(   5),  INT8_C(   9),  INT8_C(  23),  INT8_C(  37),
         INT8_C(  51),  INT8_C(  65),  INT8_C(  79),  INT8_C(  93),  INT8_C( 107),  INT8_C( 121), -INT8_C( 121), -INT8_C( 107),
        -INT8_C(  93), -INT8_C(  79), -INT8_C(  65), -INT8_C(  51), -INT8_C(  37), -INT8_C(  23), -INT8_C(   9),  INT8_C(   5),
         INT8_C(  19),  INT8_C(  33),  INT8_C(  47),  INT8_C(  61),  INT8_C(  75),  INT8_C(  89),  INT8_C( 103),  INT8_C( 117),
         INT8_C(  10),  INT8_C(  24),  INT8_C(  38),  INT8_C(  52),  INT8_C(  66),  INT8_C(  80),  INT8_C(  94),  INT8_C( 108),
         INT8_C( 122), -INT8_C( 120), -INT8_C( 106), -INT8_C(  92), -INT8_C(  78), -INT8_C(  64), -INT8_C(  50), -INT8_C(  36),
        -INT8_C(  22), -INT8_C(   8),  INT8_C(   6),  INT8_C(  20),  INT8_C(  34),  INT8_C(  48),  INT8_C(  62),  INT8_C(  76),
         INT8_C(  90),  INT8_C( 104),  INT8_C( 118), -INT8_C( 124), -INT8_C( 110), -INT8_C(  96), -INT8_C(  82), -INT8_C(  68),
        -INT8_C(  54), -INT8_C(  40), -INT8_C(  26), -INT8_C(  12),  INT8_C(   2),  INT8_C(  16),  INT8_C(  30),  INT8_C(  44),
         INT8_C(  58),  INT8_C(  72),  INT8_C(  86),  INT8_C( 100),  INT8_C( 114), -INT8_C( 128), -INT8_C( 114), -INT8_C( 100),
        -INT8_C(  86), -INT8_C(  72), -INT8_C(  58), -INT8_C(  44), -INT8_C(  30), -INT8_C(  16), -INT8_C(   2),  INT8_C(  12),
         INT8_C(  26),  INT8_C(  40),  INT8_C(  54),  INT8_C(  68),  INT8_C(  82),  INT8_C(  96),  INT8_C( 110),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_test_hvx_vector_i8_assert_equal(
        simde_Q6_Vb_vdeal_Vb(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk)),
        simde_test_hvx_fixture_shuffle_load(test_vec[i].a, test_vec[i].r, chunk, 1, 1));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vdeal_Vh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
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
         INT8_C(   3),  INT8_C(  10),  INT8_C(  31),  INT8_C(  38),  INT8_C(  59),  INT8_C(  66),  INT8_C(  87),  INT8_C(  94),
         INT8_C( 115),  INT8_C( 122), -INT8_C( 113), -INT8_C( 106), -INT8_C(  85), -INT8_C(  78), -INT8_C(  57), -INT8_C(  50),
        -INT8_C(  29), -INT8_C(  22), -INT8_C(   1),  INT8_C(   6),  INT8_C(  27),  INT8_C(  34),  INT8_C(  55),  INT8_C(  62),
         INT8_C(  83),  INT8_C(  90),  INT8_C( 111),  INT8_C( 118), -INT8_C( 117), -INT8_C( 110), -INT8_C(  89), -INT8_C(  82),
        -INT8_C(  61), -INT8_C(  54), -INT8_C(  33), -INT8_C(  26), -INT8_C(   5),  INT8_C(   2),  INT8_C(  23),  INT8_C(  30),
         INT8_C(  51),  INT8_C(  58),  INT8_C(  79),  INT8_C(  86),  INT8_C( 107),  INT8_C( 114), -INT8_C( 121), -INT8_C( 114),
        -INT8_C(  93), -INT8_C(  86), -INT8_C(  65), -INT8_C(  58), -INT8_C(  37), -INT8_C(  30), -INT8_C(   9), -INT8_C(   2),
         INT8_C(  19),  INT8_C(  26),  INT8_C(  47),  INT8_C(  54),  INT8_C(  75),  INT8_C(  82),  INT8_C( 103),  INT8_C( 110),
         INT8_C(  17),  INT8_C(  24),  INT8_C(  45),  INT8_C(  52),  INT8_C(  73),  INT8_C(  80),  INT8_C( 101),  INT8_C( 108),
        -INT8_C( 127), -INT8_C( 120), -INT8_C(  99), -INT8_C(  92), -INT8_C(  71), -INT8_C(  64), -INT8_C(  43), -INT8_C(  36),
        -INT8_C(  15), -INT8_C(   8),  INT8_C(  13),  INT8_C(  20),  INT8_C(  41),  INT8_C(  48),  INT8_C(  69),  INT8_C(  76),
         INT8_C(  97),  INT8_C( 104),  INT8_C( 125), -INT8_C( 124), -INT8_C( 103), -INT8_C(  96), -INT8_C(  75), -INT8_C(  68),
        -INT8_C(  47), -INT8_C(  40), -INT8_C(  19), -INT8_C(  12),  INT8_C(   9),  INT8_C(  16),  INT8_C(  37),  INT8_C(  44),
         INT8_C(  65),  INT8_C(  72),  INT8_C(  93),  INT8_C( 100),  INT8_C( 121), -INT8_C( 128), -INT8_C( 107), -INT8_C( 100),
        -INT8_C(  79), -INT8_C(  72), -INT8_C(  51), -INT8_C(  44), -INT8_C(  23), -INT8_C(  16),  INT8_C(   5),  INT8_C(  12),
         INT8_C(  33),  INT8_C(  40),  INT8_C(  61),  INT8_C(  68),  INT8_C(  89),  INT8_C(  96),  INT8_C( 117),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_test_hvx_vector_i8_assert_equal(
        simde_Q6_Vh_vdeal_Vh(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk)),
        simde_test_hvx_fixture_shuffle_load(test_vec[i].a, test_vec[i].r, chunk, 2, 1));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vshuffe_VbVb(SIMDE_MUNIT_TEST_ARGS) {
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
         INT8_C(  11),  INT8_C(   3),  INT8_C(  37),  INT8_C(  17),  INT8_C(  63),  INT8_C(  31),  INT8_C(  89),  INT8_C(  45),
         INT8_C( 115),  INT8_C(  59), -INT8_C( 115),  INT8_C(  73), -INT8_C(  89),  INT8_C(  87), -INT8_C(  63),  INT8_C( 101),
        -INT8_C(  37),  INT8_C( 115), -INT8_C(  11), -INT8_C( 127),  INT8_C(  15), -INT8_C( 113),  INT8_C(  41), -INT8_C(  99),
         INT8_C(  67), -INT8_C(  85),  INT8_C(  93), -INT8_C(  71),  INT8_C( 119), -INT8_C(  57), -INT8_C( 111), -INT8_C(  43),
        -INT8_C(  85), -INT8_C(  29), -INT8_C(  59), -INT8_C(  15), -INT8_C(  33), -INT8_C(   1), -INT8_C(   7),  INT8_C(  13),
         INT8_C(  19),  INT8_C(  27),  INT8_C(  45),  INT8_C(  41),  INT8_C(  71),  INT8_C(  55),  INT8_C(  97),  INT8_C(  69),
         INT8_C( 123),  INT8_C(  83), -INT8_C( 107),  INT8_C(  97), -INT8_C(  81),  INT8_C( 111), -INT8_C(  55),  INT8_C( 125),
        -INT8_C(  29), -INT8_C( 117), -INT8_C(   3), -INT8_C( 103),  INT8_C(  23), -INT8_C(  89),  INT8_C(  49), -INT8_C(  75),
         INT8_C(  75), -INT8_C(  61),  INT8_C( 101), -INT8_C(  47),  INT8_C( 127), -INT8_C(  33), -INT8_C( 103), -INT8_C(  19),
        -INT8_C(  77), -INT8_C(   5), -INT8_C(  51),  INT8_C(   9), -INT8_C(  25),  INT8_C(  23),  INT8_C(   1),  INT8_C(  37),
         INT8_C(  27),  INT8_C(  51),  INT8_C(  53),  INT8_C(  65),  INT8_C(  79),  INT8_C(  79),  INT8_C( 105),  INT8_C(  93),
        -INT8_C( 125),  INT8_C( 107), -INT8_C(  99),  INT8_C( 121), -INT8_C(  73), -INT8_C( 121), -INT8_C(  47), -INT8_C( 107),
        -INT8_C(  21), -INT8_C(  93),  INT8_C(   5), -INT8_C(  79),  INT8_C(  31), -INT8_C(  65),  INT8_C(  57), -INT8_C(  51),
         INT8_C(  83), -INT8_C(  37),  INT8_C( 109), -INT8_C(  23), -INT8_C( 121), -INT8_C(   9), -INT8_C(  95),  INT8_C(   5),
        -INT8_C(  69),  INT8_C(  19), -INT8_C(  43),  INT8_C(  33), -INT8_C(  17),  INT8_C(  47),  INT8_C(   9),  INT8_C(  61),
         INT8_C(  35),  INT8_C(  75),  INT8_C(  61),  INT8_C(  89),  INT8_C(  87),  INT8_C( 103),  INT8_C( 113),  INT8_C( 117)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_test_hvx_vector_i8_assert_equal(
        simde_Q6_Vb_vshuffe_VbVb(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk),
                                 simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk)),
        simde_test_hvx_fixture_vector_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vshuffo_VbVb(SIMDE_MUNIT_TEST_ARGS) {
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
        -INT8_C( 128),  INT8_C(  66), -INT8_C( 102),  INT8_C(  80), -INT8_C(  76),  INT8_C(  94), -INT8_C(  50),  INT8_C( 108),
        -INT8_C(  24),  INT8_C( 122),  INT8_C(   2), -INT8_C( 120),  INT8_C(  28), -INT8_C( 106),  INT8_C(  54), -INT8_C(  92),
         INT8_C(  80), -INT8_C(  78),  INT8_C( 106), -INT8_C(  64), -INT8_C( 124), -INT8_C(  50), -INT8_C(  98), -INT8_C(  36),
        -INT8_C(  72), -INT8_C(  22), -INT8_C(  46), -INT8_C(   8), -INT8_C(  20),  INT8_C(   6),  INT8_C(   6),  INT8_C(  20),
         INT8_C(  32),  INT8_C(  34),  INT8_C(  58),  INT8_C(  48),  INT8_C(  84),  INT8_C(  62),  INT8_C( 110),  INT8_C(  76),
        -INT8_C( 120),  INT8_C(  90), -INT8_C(  94),  INT8_C( 104), -INT8_C(  68),  INT8_C( 118), -INT8_C(  42), -INT8_C( 124),
        -INT8_C(  16), -INT8_C( 110),  INT8_C(  10), -INT8_C(  96),  INT8_C(  36), -INT8_C(  82),  INT8_C(  62), -INT8_C(  68),
         INT8_C(  88), -INT8_C(  54),  INT8_C( 114), -INT8_C(  40), -INT8_C( 116), -INT8_C(  26), -INT8_C(  90), -INT8_C(  12),
        -INT8_C(  64),  INT8_C(   2), -INT8_C(  38),  INT8_C(  16), -INT8_C(  12),  INT8_C(  30),  INT8_C(  14),  INT8_C(  44),
         INT8_C(  40),  INT8_C(  58),  INT8_C(  66),  INT8_C(  72),  INT8_C(  92),  INT8_C(  86),  INT8_C( 118),  INT8_C( 100),
        -INT8_C( 112),  INT8_C( 114), -INT8_C(  86), -INT8_C( 128), -INT8_C(  60), -INT8_C( 114), -INT8_C(  34), -INT8_C( 100),
        -INT8_C(   8), -INT8_C(  86),  INT8_C(  18), -INT8_C(  72),  INT8_C(  44), -INT8_C(  58),  INT8_C(  70), -INT8_C(  44),
         INT8_C(  96), -INT8_C(  30),  INT8_C( 122), -INT8_C(  16), -INT8_C( 108), -INT8_C(   2), -INT8_C(  82),  INT8_C(  12),
        -INT8_C(  56),  INT8_C(  26), -INT8_C(  30),  INT8_C(  40), -INT8_C(   4),  INT8_C(  54),  INT8_C(  22),  INT8_C(  68),
         INT8_C(  48),  INT8_C(  82),  INT8_C(  74),  INT8_C(  96),  INT8_C( 100),  INT8_C( 110),  INT8_C( 126),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_test_hvx_vector_i8_assert_equal(
        simde_Q6_Vb_vshuffo_VbVb(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk),
                                 simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk)),
        simde_test_hvx_fixture_vector_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vshuffe_VhVh(SIMDE_MUNIT_TEST_ARGS) {
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
         INT8_C(  11),  INT8_C(  24),  INT8_C(   3),  INT8_C(  10),  INT8_C(  63),  INT8_C(  76),  INT8_C(  31),  INT8_C(  38),
         INT8_C( 115), -INT8_C( 128),  INT8_C(  59),  INT8_C(  66), -INT8_C(  89), -INT8_C(  76),  INT8_C(  87),  INT8_C(  94),
        -INT8_C(  37), -INT8_C(  24),  INT8_C( 115),  INT8_C( 122),  INT8_C(  15),  INT8_C(  28), -INT8_C( 113), -INT8_C( 106),
         INT8_C(  67),  INT8_C(  80), -INT8_C(  85), -INT8_C(  78),  INT8_C( 119), -INT8_C( 124), -INT8_C(  57), -INT8_C(  50),
        -INT8_C(  85), -INT8_C(  72), -INT8_C(  29), -INT8_C(  22), -INT8_C(  33), -INT8_C(  20), -INT8_C(   1),  INT8_C(   6),
         INT8_C(  19),  INT8_C(  32),  INT8_C(  27),  INT8_C(  34),  INT8_C(  71),  INT8_C(  84),  INT8_C(  55),  INT8_C(  62),
         INT8_C( 123), -INT8_C( 120),  INT8_C(  83),  INT8_C(  90), -INT8_C(  81), -INT8_C(  68),  INT8_C( 111),  INT8_C( 118),
        -INT8_C(  29), -INT8_C(  16), -INT8_C( 117), -INT8_C( 110),  INT8_C(  23),  INT8_C(  36), -INT8_C(  89), -INT8_C(  82),
         INT8_C(  75),  INT8_C(  88), -INT8_C(  61), -INT8_C(  54),  INT8_C( 127), -INT8_C( 116), -INT8_C(  33), -INT8_C(  26),
        -INT8_C(  77), -INT8_C(  64), -INT8_C(   5),  INT8_C(   2), -INT8_C(  25), -INT8_C(  12),  INT8_C(  23),  INT8_C(  30),
         INT8_C(  27),  INT8_C(  40),  INT8_C(  51),  INT8_C(  58),  INT8_C(  79),  INT8_C(  92),  INT8_C(  79),  INT8_C(  86),
        -INT8_C( 125), -INT8_C( 112),  INT8_C( 107),  INT8_C( 114), -INT8_C(  73), -INT8_C(  60), -INT8_C( 121), -INT8_C( 114),
        -INT8_C(  21), -INT8_C(   8), -INT8_C(  93), -INT8_C(  86),  INT8_C(  31),  INT8_C(  44), -INT8_C(  65), -INT8_C(  58),
         INT8_C(  83),  INT8_C(  96), -INT8_C(  37), -INT8_C(  30), -INT8_C( 121), -INT8_C( 108), -INT8_C(   9), -INT8_C(   2),
        -INT8_C(  69), -INT8_C(  56),  INT8_C(  19),  INT8_C(  26), -INT8_C(  17), -INT8_C(   4),  INT8_C(  47),  INT8_C(  54),
         INT8_C(  35),  INT8_C(  48),  INT8_C(  75),  INT8_C(  82),  INT8_C(  87),  INT8_C( 100),  INT8_C( 103),  INT8_C( 110)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_test_hvx_vector_i8_assert_equal(
        simde_Q6_Vh_vshuffe_VhVh(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk),
                                 simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk)),
        simde_test_hvx_fixture_vector_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vshuffo_VhVh(SIMDE_MUNIT_TEST_ARGS) {
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
         INT8_C(  37),  INT8_C(  50),  INT8_C(  17),  INT8_C(  24),  INT8_C(  89),  INT8_C( 102),  INT8_C(  45),  INT8_C(  52),
        -INT8_C( 115), -INT8_C( 102),  INT8_C(  73),  INT8_C(  80), -INT8_C(  63), -INT8_C(  50),  INT8_C( 101),  INT8_C( 108),
        -INT8_C(  11),  INT8_C(   2), -INT8_C( 127), -INT8_C( 120),  INT8_C(  41),  INT8_C(  54), -INT8_C(  99), -INT8_C(  92),
         INT8_C(  93),  INT8_C( 106), -INT8_C(  71), -INT8_C(  64), -INT8_C( 111), -INT8_C(  98), -INT8_C(  43), -INT8_C(  36),
        -INT8_C(  59), -INT8_C(  46), -INT8_C(  15), -INT8_C(   8), -INT8_C(   7),  INT8_C(   6),  INT8_C(  13),  INT8_C(  20),
         INT8_C(  45),  INT8_C(  58),  INT8_C(  41),  INT8_C(  48),  INT8_C(  97),  INT8_C( 110),  INT8_C(  69),  INT8_C(  76),
        -INT8_C( 107), -INT8_C(  94),  INT8_C(  97),  INT8_C( 104), -INT8_C(  55), -INT8_C(  42),  INT8_C( 125), -INT8_C( 124),
        -INT8_C(   3),  INT8_C(  10), -INT8_C( 103), -INT8_C(  96),  INT8_C(  49),  INT8_C(  62), -INT8_C(  75), -INT8_C(  68),
         INT8_C( 101),  INT8_C( 114), -INT8_C(  47), -INT8_C(  40), -INT8_C( 103), -INT8_C(  90), -INT8_C(  19), -INT8_C(  12),
        -INT8_C(  51), -INT8_C(  38),  INT8_C(   9),  INT8_C(  16),  INT8_C(   1),  INT8_C(  14),  INT8_C(  37),  INT8_C(  44),
         INT8_C(  53),  INT8_C(  66),  INT8_C(  65),  INT8_C(  72),  INT8_C( 105),  INT8_C( 118),  INT8_C(  93),  INT8_C( 100),
        -INT8_C(  99), -INT8_C(  86),  INT8_C( 121), -INT8_C( 128), -INT8_C(  47), -INT8_C(  34), -INT8_C( 107), -INT8_C( 100),
         INT8_C(   5),  INT8_C(  18), -INT8_C(  79), -INT8_C(  72),  INT8_C(  57),  INT8_C(  70), -INT8_C(  51), -INT8_C(  44),
         INT8_C( 109),  INT8_C( 122), -INT8_C(  23), -INT8_C(  16), -INT8_C(  95), -INT8_C(  82),  INT8_C(   5),  INT8_C(  12),
        -INT8_C(  43), -INT8_C(  30),  INT8_C(  33),  INT8_C(  40),  INT8_C(   9),  INT8_C(  22),  INT8_C(  61),  INT8_C(  68),
         INT8_C(  61),  INT8_C(  74),  INT8_C(  89),  INT8_C(  96),  INT8_C( 113),  INT8_C( 126),  INT8_C( 117),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_test_hvx_vector_i8_assert_equal(
        simde_Q6_Vh_vshuffo_VhVh(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk),
                                 simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk)),
        simde_test_hvx_fixture_vector_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vdeale_VbVb(SIMDE_MUNIT_TEST_ARGS) {
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
         INT8_C(  11),  INT8_C(  63),  INT8_C( 115), -INT8_C(  89), -INT8_C(  37),  INT8_C(  15),  INT8_C(  67),  INT8_C( 119),
        -INT8_C(  85), -INT8_C(  33),  INT8_C(  19),  INT8_C(  71),  INT8_C( 123), -INT8_C(  81), -INT8_C(  29),  INT8_C(  23),
         INT8_C(  75),  INT8_C( 127), -INT8_C(  77), -INT8_C(  25),  INT8_C(  27),  INT8_C(  79), -INT8_C( 125), -INT8_C(  73),
        -INT8_C(  21),  INT8_C(  31),  INT8_C(  83), -INT8_C( 121), -INT8_C(  69), -INT8_C(  17),  INT8_C(  35),  INT8_C(  87),
         INT8_C(  37),  INT8_C(  89), -INT8_C( 115), -INT8_C(  63), -INT8_C(  11),  INT8_C(  41),  INT8_C(  93), -INT8_C( 111),
        -INT8_C(  59), -INT8_C(   7),  INT8_C(  45),  INT8_C(  97), -INT8_C( 107), -INT8_C(  55), -INT8_C(   3),  INT8_C(  49),
         INT8_C( 101), -INT8_C( 103), -INT8_C(  51),  INT8_C(   1),  INT8_C(  53),  INT8_C( 105), -INT8_C(  99), -INT8_C(  47),
         INT8_C(   5),  INT8_C(  57),  INT8_C( 109), -INT8_C(  95), -INT8_C(  43),  INT8_C(   9),  INT8_C(  61),  INT8_C( 113),
         INT8_C(   3),  INT8_C(  31),  INT8_C(  59),  INT8_C(  87),  INT8_C( 115), -INT8_C( 113), -INT8_C(  85), -INT8_C(  57),
        -INT8_C(  29), -INT8_C(   1),  INT8_C(  27),  INT8_C(  55),  INT8_C(  83),  INT8_C( 111), -INT8_C( 117), -INT8_C(  89),
        -INT8_C(  61), -INT8_C(  33), -INT8_C(   5),  INT8_C(  23),  INT8_C(  51),  INT8_C(  79),  INT8_C( 107), -INT8_C( 121),
        -INT8_C(  93), -INT8_C(  65), -INT8_C(  37), -INT8_C(   9),  INT8_C(  19),  INT8_C(  47),  INT8_C(  75),  INT8_C( 103),
         INT8_C(  17),  INT8_C(  45),  INT8_C(  73),  INT8_C( 101), -INT8_C( 127), -INT8_C(  99), -INT8_C(  71), -INT8_C(  43),
        -INT8_C(  15),  INT8_C(  13),  INT8_C(  41),  INT8_C(  69),  INT8_C(  97),  INT8_C( 125), -INT8_C( 103), -INT8_C(  75),
        -INT8_C(  47), -INT8_C(  19),  INT8_C(   9),  INT8_C(  37),  INT8_C(  65),  INT8_C(  93),  INT8_C( 121), -INT8_C( 107),
        -INT8_C(  79), -INT8_C(  51), -INT8_C(  23),  INT8_C(   5),  INT8_C(  33),  INT8_C(  61),  INT8_C(  89),  INT8_C( 117)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_test_hvx_vector_i8_assert_equal(
        simde_Q6_Vb_vdeale_VbVb(simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk),
                                simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk)),
        simde_test_hvx_fixture_deale_load(test_vec[i].a, test_vec[i].b, test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vshuffoe_VbVb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int8_t r_lo[128];
    int8_t r_hi[128];
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
         INT8_C(  11),  INT8_C(   3),  INT8_C(  37),  INT8_C(  17),  INT8_C(  63),  INT8_C(  31),  INT8_C(  89),  INT8_C(  45),
         INT8_C( 115),  INT8_C(  59), -INT8_C( 115),  INT8_C(  73), -INT8_C(  89),  INT8_C(  87), -INT8_C(  63),  INT8_C( 101),
        -INT8_C(  37),  INT8_C( 115), -INT8_C(  11), -INT8_C( 127),  INT8_C(  15), -INT8_C( 113),  INT8_C(  41), -INT8_C(  99),
         INT8_C(  67), -INT8_C(  85),  INT8_C(  93), -INT8_C(  71),  INT8_C( 119), -INT8_C(  57), -INT8_C( 111), -INT8_C(  43),
        -INT8_C(  85), -INT8_C(  29), -INT8_C(  59), -INT8_C(  15), -INT8_C(  33), -INT8_C(   1), -INT8_C(   7),  INT8_C(  13),
         INT8_C(  19),  INT8_C(  27),  INT8_C(  45),  INT8_C(  41),  INT8_C(  71),  INT8_C(  55),  INT8_C(  97),  INT8_C(  69),
         INT8_C( 123),  INT8_C(  83), -INT8_C( 107),  INT8_C(  97), -INT8_C(  81),  INT8_C( 111), -INT8_C(  55),  INT8_C( 125),
        -INT8_C(  29), -INT8_C( 117), -INT8_C(   3), -INT8_C( 103),  INT8_C(  23), -INT8_C(  89),  INT8_C(  49), -INT8_C(  75),
         INT8_C(  75), -INT8_C(  61),  INT8_C( 101), -INT8_C(  47),  INT8_C( 127), -INT8_C(  33), -INT8_C( 103), -INT8_C(  19),
        -INT8_C(  77), -INT8_C(   5), -INT8_C(  51),  INT8_C(   9), -INT8_C(  25),  INT8_C(  23),  INT8_C(   1),  INT8_C(  37),
         INT8_C(  27),  INT8_C(  51),  INT8_C(  53),  INT8_C(  65),  INT8_C(  79),  INT8_C(  79),  INT8_C( 105),  INT8_C(  93),
        -INT8_C( 125),  INT8_C( 107), -INT8_C(  99),  INT8_C( 121), -INT8_C(  73), -INT8_C( 121), -INT8_C(  47), -INT8_C( 107),
        -INT8_C(  21), -INT8_C(  93),  INT8_C(   5), -INT8_C(  79),  INT8_C(  31), -INT8_C(  65),  INT8_C(  57), -INT8_C(  51),
         INT8_C(  83), -INT8_C(  37),  INT8_C( 109), -INT8_C(  23), -INT8_C( 121), -INT8_C(   9), -INT8_C(  95),  INT8_C(   5),
        -INT8_C(  69),  INT8_C(  19), -INT8_C(  43),  INT8_C(  33), -INT8_C(  17),  INT8_C(  47),  INT8_C(   9),  INT8_C(  61),
         INT8_C(  35),  INT8_C(  75),  INT8_C(  61),  INT8_C(  89),  INT8_C(  87),  INT8_C( 103),  INT8_C( 113),  INT8_C( 117)
      },
      {
         INT8_C(  24),  INT8_C(  10),  INT8_C(  50),  INT8_C(  24),  INT8_C(  76),  INT8_C(  38),  INT8_C( 102),  INT8_C(  52),
        -INT8_C( 128),  INT8_C(  66), -INT8_C( 102),  INT8_C(  80), -INT8_C(  76),  INT8_C(  94), -INT8_C(  50),  INT8_C( 108),
        -INT8_C(  24),  INT8_C( 122),  INT8_C(   2), -INT8_C( 120),  INT8_C(  28), -INT8_C( 106),  INT8_C(  54), -INT8_C(  92),
         INT8_C(  80), -INT8_C(  78),  INT8_C( 106), -INT8_C(  64), -INT8_C( 124), -INT8_C(  50), -INT8_C(  98), -INT8_C(  36),
        -INT8_C(  72), -INT8_C(  22), -INT8_C(  46), -INT8_C(   8), -INT8_C(  20),  INT8_C(   6),  INT8_C(   6),  INT8_C(  20),
         INT8_C(  32),  INT8_C(  34),  INT8_C(  58),  INT8_C(  48),  INT8_C(  84),  INT8_C(  62),  INT8_C( 110),  INT8_C(  76),
        -INT8_C( 120),  INT8_C(  90), -INT8_C(  94),  INT8_C( 104), -INT8_C(  68),  INT8_C( 118), -INT8_C(  42), -INT8_C( 124),
        -INT8_C(  16), -INT8_C( 110),  INT8_C(  10), -INT8_C(  96),  INT8_C(  36), -INT8_C(  82),  INT8_C(  62), -INT8_C(  68),
         INT8_C(  88), -INT8_C(  54),  INT8_C( 114), -INT8_C(  40), -INT8_C( 116), -INT8_C(  26), -INT8_C(  90), -INT8_C(  12),
        -INT8_C(  64),  INT8_C(   2), -INT8_C(  38),  INT8_C(  16), -INT8_C(  12),  INT8_C(  30),  INT8_C(  14),  INT8_C(  44),
         INT8_C(  40),  INT8_C(  58),  INT8_C(  66),  INT8_C(  72),  INT8_C(  92),  INT8_C(  86),  INT8_C( 118),  INT8_C( 100),
        -INT8_C( 112),  INT8_C( 114), -INT8_C(  86), -INT8_C( 128), -INT8_C(  60), -INT8_C( 114), -INT8_C(  34), -INT8_C( 100),
        -INT8_C(   8), -INT8_C(  86),  INT8_C(  18), -INT8_C(  72),  INT8_C(  44), -INT8_C(  58),  INT8_C(  70), -INT8_C(  44),
         INT8_C(  96), -INT8_C(  30),  INT8_C( 122), -INT8_C(  16), -INT8_C( 108), -INT8_C(   2), -INT8_C(  82),  INT8_C(  12),
        -INT8_C(  56),  INT8_C(  26), -INT8_C(  30),  INT8_C(  40), -INT8_C(   4),  INT8_C(  54),  INT8_C(  22),  INT8_C(  68),
         INT8_C(  48),  INT8_C(  82),  INT8_C(  74),  INT8_C(  96),  INT8_C( 100),  INT8_C( 110),  INT8_C( 126),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t r = simde_Q6_Wb_vshuffoe_VbVb(
        simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk),
        simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk));
      simde_test_hvx_vector_i8_assert_equal(simde_Q6_V_lo_W(r), simde_test_hvx_fixture_vector_load(test_vec[i].r_lo, chunk));
      simde_test_hvx_vector_i8_assert_equal(simde_Q6_V_hi_W(r), simde_test_hvx_fixture_vector_load(test_vec[i].r_hi, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vshuffoe_VhVh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int8_t r_lo[128];
    int8_t r_hi[128];
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
         INT8_C(  11),  INT8_C(  24),  INT8_C(   3),  INT8_C(  10),  INT8_C(  63),  INT8_C(  76),  INT8_C(  31),  INT8_C(  38),
         INT8_C( 115), -INT8_C( 128),  INT8_C(  59),  INT8_C(  66), -INT8_C(  89), -INT8_C(  76),  INT8_C(  87),  INT8_C(  94),
        -INT8_C(  37), -INT8_C(  24),  INT8_C( 115),  INT8_C( 122),  INT8_C(  15),  INT8_C(  28), -INT8_C( 113), -INT8_C( 106),
         INT8_C(  67),  INT8_C(  80), -INT8_C(  85), -INT8_C(  78),  INT8_C( 119), -INT8_C( 124), -INT8_C(  57), -INT8_C(  50),
        -INT8_C(  85), -INT8_C(  72), -INT8_C(  29), -INT8_C(  22), -INT8_C(  33), -INT8_C(  20), -INT8_C(   1),  INT8_C(   6),
         INT8_C(  19),  INT8_C(  32),  INT8_C(  27),  INT8_C(  34),  INT8_C(  71),  INT8_C(  84),  INT8_C(  55),  INT8_C(  62),
         INT8_C( 123), -INT8_C( 120),  INT8_C(  83),  INT8_C(  90), -INT8_C(  81), -INT8_C(  68),  INT8_C( 111),  INT8_C( 118),
        -INT8_C(  29), -INT8_C(  16), -INT8_C( 117), -INT8_C( 110),  INT8_C(  23),  INT8_C(  36), -INT8_C(  89), -INT8_C(  82),
         INT8_C(  75),  INT8_C(  88), -INT8_C(  61), -INT8_C(  54),  INT8_C( 127), -INT8_C( 116), -INT8_C(  33), -INT8_C(  26),
        -INT8_C(  77), -INT8_C(  64), -INT8_C(   5),  INT8_C(   2), -INT8_C(  25), -INT8_C(  12),  INT8_C(  23),  INT8_C(  30),
         INT8_C(  27),  INT8_C(  40),  INT8_C(  51),  INT8_C(  58),  INT8_C(  79),  INT8_C(  92),  INT8_C(  79),  INT8_C(  86),
        -INT8_C( 125), -INT8_C( 112),  INT8_C( 107),  INT8_C( 114), -INT8_C(  73), -INT8_C(  60), -INT8_C( 121), -INT8_C( 114),
        -INT8_C(  21), -INT8_C(   8), -INT8_C(  93), -INT8_C(  86),  INT8_C(  31),  INT8_C(  44), -INT8_C(  65), -INT8_C(  58),
         INT8_C(  83),  INT8_C(  96), -INT8_C(  37), -INT8_C(  30), -INT8_C( 121), -INT8_C( 108), -INT8_C(   9), -INT8_C(   2),
        -INT8_C(  69), -INT8_C(  56),  INT8_C(  19),  INT8_C(  26), -INT8_C(  17), -INT8_C(   4),  INT8_C(  47),  INT8_C(  54),
         INT8_C(  35),  INT8_C(  48),  INT8_C(  75),  INT8_C(  82),  INT8_C(  87),  INT8_C( 100),  INT8_C( 103),  INT8_C( 110)
      },
      {
         INT8_C(  37),  INT8_C(  50),  INT8_C(  17),  INT8_C(  24),  INT8_C(  89),  INT8_C( 102),  INT8_C(  45),  INT8_C(  52),
        -INT8_C( 115), -INT8_C( 102),  INT8_C(  73),  INT8_C(  80), -INT8_C(  63), -INT8_C(  50),  INT8_C( 101),  INT8_C( 108),
        -INT8_C(  11),  INT8_C(   2), -INT8_C( 127), -INT8_C( 120),  INT8_C(  41),  INT8_C(  54), -INT8_C(  99), -INT8_C(  92),
         INT8_C(  93),  INT8_C( 106), -INT8_C(  71), -INT8_C(  64), -INT8_C( 111), -INT8_C(  98), -INT8_C(  43), -INT8_C(  36),
        -INT8_C(  59), -INT8_C(  46), -INT8_C(  15), -INT8_C(   8), -INT8_C(   7),  INT8_C(   6),  INT8_C(  13),  INT8_C(  20),
         INT8_C(  45),  INT8_C(  58),  INT8_C(  41),  INT8_C(  48),  INT8_C(  97),  INT8_C( 110),  INT8_C(  69),  INT8_C(  76),
        -INT8_C( 107), -INT8_C(  94),  INT8_C(  97),  INT8_C( 104), -INT8_C(  55), -INT8_C(  42),  INT8_C( 125), -INT8_C( 124),
        -INT8_C(   3),  INT8_C(  10), -INT8_C( 103), -INT8_C(  96),  INT8_C(  49),  INT8_C(  62), -INT8_C(  75), -INT8_C(  68),
         INT8_C( 101),  INT8_C( 114), -INT8_C(  47), -INT8_C(  40), -INT8_C( 103), -INT8_C(  90), -INT8_C(  19), -INT8_C(  12),
        -INT8_C(  51), -INT8_C(  38),  INT8_C(   9),  INT8_C(  16),  INT8_C(   1),  INT8_C(  14),  INT8_C(  37),  INT8_C(  44),
         INT8_C(  53),  INT8_C(  66),  INT8_C(  65),  INT8_C(  72),  INT8_C( 105),  INT8_C( 118),  INT8_C(  93),  INT8_C( 100),
        -INT8_C(  99), -INT8_C(  86),  INT8_C( 121), -INT8_C( 128), -INT8_C(  47), -INT8_C(  34), -INT8_C( 107), -INT8_C( 100),
         INT8_C(   5),  INT8_C(  18), -INT8_C(  79), -INT8_C(  72),  INT8_C(  57),  INT8_C(  70), -INT8_C(  51), -INT8_C(  44),
         INT8_C( 109),  INT8_C( 122), -INT8_C(  23), -INT8_C(  16), -INT8_C(  95), -INT8_C(  82),  INT8_C(   5),  INT8_C(  12),
        -INT8_C(  43), -INT8_C(  30),  INT8_C(  33),  INT8_C(  40),  INT8_C(   9),  INT8_C(  22),  INT8_C(  61),  INT8_C(  68),
         INT8_C(  61),  INT8_C(  74),  INT8_C(  89),  INT8_C(  96),  INT8_C( 113),  INT8_C( 126),  INT8_C( 117),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t r = simde_Q6_Wh_vshuffoe_VhVh(
        simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk),
        simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk));
      simde_test_hvx_vector_i8_assert_equal(simde_Q6_V_lo_W(r), simde_test_hvx_fixture_vector_load(test_vec[i].r_lo, chunk));
      simde_test_hvx_vector_i8_assert_equal(simde_Q6_V_hi_W(r), simde_test_hvx_fixture_vector_load(test_vec[i].r_hi, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vshuff_VVR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    int8_t r_lo[128];
    int8_t r_hi[128];
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
      INT32_C(1),
      {
         INT8_C(  11),  INT8_C(   3),  INT8_C(  37),  INT8_C(  17),  INT8_C(  63),  INT8_C(  31),  INT8_C(  89),  INT8_C(  45),
         INT8_C( 115),  INT8_C(  59), -INT8_C( 115),  INT8_C(  73), -INT8_C(  89),  INT8_C(  87), -INT8_C(  63),  INT8_C( 101),
        -INT8_C(  37),  INT8_C( 115), -INT8_C(  11), -INT8_C( 127),  INT8_C(  15), -INT8_C( 113),  INT8_C(  41), -INT8_C(  99),
         INT8_C(  67), -INT8_C(  85),  INT8_C(  93), -INT8_C(  71),  INT8_C( 119), -INT8_C(  57), -INT8_C( 111), -INT8_C(  43),
        -INT8_C(  85), -INT8_C(  29), -INT8_C(  59), -INT8_C(  15), -INT8_C(  33), -INT8_C(   1), -INT8_C(   7),  INT8_C(  13),
         INT8_C(  19),  INT8_C(  27),  INT8_C(  45),  INT8_C(  41),  INT8_C(  71),  INT8_C(  55),  INT8_C(  97),  INT8_C(  69),
         INT8_C( 123),  INT8_C(  83), -INT8_C( 107),  INT8_C(  97), -INT8_C(  81),  INT8_C( 111), -INT8_C(  55),  INT8_C( 125),
        -INT8_C(  29), -INT8_C( 117), -INT8_C(   3), -INT8_C( 103),  INT8_C(  23), -INT8_C(  89),  INT8_C(  49), -INT8_C(  75),
         INT8_C(  75), -INT8_C(  61),  INT8_C( 101), -INT8_C(  47),  INT8_C( 127), -INT8_C(  33), -INT8_C( 103), -INT8_C(  19),
        -INT8_C(  77), -INT8_C(   5), -INT8_C(  51),  INT8_C(   9), -INT8_C(  25),  INT8_C(  23),  INT8_C(   1),  INT8_C(  37),
         INT8_C(  27),  INT8_C(  51),  INT8_C(  53),  INT8_C(  65),  INT8_C(  79),  INT8_C(  79),  INT8_C( 105),  INT8_C(  93),
        -INT8_C( 125),  INT8_C( 107), -INT8_C(  99),  INT8_C( 121), -INT8_C(  73), -INT8_C( 121), -INT8_C(  47), -INT8_C( 107),
        -INT8_C(  21), -INT8_C(  93),  INT8_C(   5), -INT8_C(  79),  INT8_C(  31), -INT8_C(  65),  INT8_C(  57), -INT8_C(  51),
         INT8_C(  83), -INT8_C(  37),  INT8_C( 109), -INT8_C(  23), -INT8_C( 121), -INT8_C(   9), -INT8_C(  95),  INT8_C(   5),
        -INT8_C(  69),  INT8_C(  19), -INT8_C(  43),  INT8_C(  33), -INT8_C(  17),  INT8_C(  47),  INT8_C(   9),  INT8_C(  61),
         INT8_C(  35),  INT8_C(  75),  INT8_C(  61),  INT8_C(  89),  INT8_C(  87),  INT8_C( 103),  INT8_C( 113),  INT8_C( 117)
      },
      {
         INT8_C(  24),  INT8_C(  10),  INT8_C(  50),  INT8_C(  24),  INT8_C(  76),  INT8_C(  38),  INT8_C( 102),  INT8_C(  52),
        -INT8_C( 128),  INT8_C(  66), -INT8_C( 102),  INT8_C(  80), -INT8_C(  76),  INT8_C(  94), -INT8_C(  50),  INT8_C( 108),
        -INT8_C(  24),  INT8_C( 122),  INT8_C(   2), -INT8_C( 120),  INT8_C(  28), -INT8_C( 106),  INT8_C(  54), -INT8_C(  92),
         INT8_C(  80), -INT8_C(  78),  INT8_C( 106), -INT8_C(  64), -INT8_C( 124), -INT8_C(  50), -INT8_C(  98), -INT8_C(  36),
        -INT8_C(  72), -INT8_C(  22), -INT8_C(  46), -INT8_C(   8), -INT8_C(  20),  INT8_C(   6),  INT8_C(   6),  INT8_C(  20),
         INT8_C(  32),  INT8_C(  34),  INT8_C(  58),  INT8_C(  48),  INT8_C(  84),  INT8_C(  62),  INT8_C( 110),  INT8_C(  76),
        -INT8_C( 120),  INT8_C(  90), -INT8_C(  94),  INT8_C( 104), -INT8_C(  68),  INT8_C( 118), -INT8_C(  42), -INT8_C( 124),
        -INT8_C(  16), -INT8_C( 110),  INT8_C(  10), -INT8_C(  96),  INT8_C(  36), -INT8_C(  82),  INT8_C(  62), -INT8_C(  68),
         INT8_C(  88), -INT8_C(  54),  INT8_C( 114), -INT8_C(  40), -INT8_C( 116), -INT8_C(  26), -INT8_C(  90), -INT8_C(  12),
        -INT8_C(  64),  INT8_C(   2), -INT8_C(  38),  INT8_C(  16), -INT8_C(  12),  INT8_C(  30),  INT8_C(  14),  INT8_C(  44),
         INT8_C(  40),  INT8_C(  58),  INT8_C(  66),  INT8_C(  72),  INT8_C(  92),  INT8_C(  86),  INT8_C( 118),  INT8_C( 100),
        -INT8_C( 112),  INT8_C( 114), -INT8_C(  86), -INT8_C( 128), -INT8_C(  60), -INT8_C( 114), -INT8_C(  34), -INT8_C( 100),
        -INT8_C(   8), -INT8_C(  86),  INT8_C(  18), -INT8_C(  72),  INT8_C(  44), -INT8_C(  58),  INT8_C(  70), -INT8_C(  44),
         INT8_C(  96), -INT8_C(  30),  INT8_C( 122), -INT8_C(  16), -INT8_C( 108), -INT8_C(   2), -INT8_C(  82),  INT8_C(  12),
        -INT8_C(  56),  INT8_C(  26), -INT8_C(  30),  INT8_C(  40), -INT8_C(   4),  INT8_C(  54),  INT8_C(  22),  INT8_C(  68),
         INT8_C(  48),  INT8_C(  82),  INT8_C(  74),  INT8_C(  96),  INT8_C( 100),  INT8_C( 110),  INT8_C( 126),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t r = simde_Q6_W_vshuff_VVR(
        simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk),
        simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk), test_vec[i].rt);
      simde_test_hvx_vector_i8_assert_equal(simde_Q6_V_lo_W(r), simde_test_hvx_fixture_vector_load(test_vec[i].r_lo, chunk));
      simde_test_hvx_vector_i8_assert_equal(simde_Q6_V_hi_W(r), simde_test_hvx_fixture_vector_load(test_vec[i].r_hi, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vdeal_VVR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int32_t rt;
    int8_t r_lo[128];
    int8_t r_hi[128];
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
      INT32_C(1),
      {
         INT8_C(  11),  INT8_C(   3),  INT8_C(  37),  INT8_C(  17),  INT8_C(  63),  INT8_C(  31),  INT8_C(  89),  INT8_C(  45),
         INT8_C( 115),  INT8_C(  59), -INT8_C( 115),  INT8_C(  73), -INT8_C(  89),  INT8_C(  87), -INT8_C(  63),  INT8_C( 101),
        -INT8_C(  37),  INT8_C( 115), -INT8_C(  11), -INT8_C( 127),  INT8_C(  15), -INT8_C( 113),  INT8_C(  41), -INT8_C(  99),
         INT8_C(  67), -INT8_C(  85),  INT8_C(  93), -INT8_C(  71),  INT8_C( 119), -INT8_C(  57), -INT8_C( 111), -INT8_C(  43),
        -INT8_C(  85), -INT8_C(  29), -INT8_C(  59), -INT8_C(  15), -INT8_C(  33), -INT8_C(   1), -INT8_C(   7),  INT8_C(  13),
         INT8_C(  19),  INT8_C(  27),  INT8_C(  45),  INT8_C(  41),  INT8_C(  71),  INT8_C(  55),  INT8_C(  97),  INT8_C(  69),
         INT8_C( 123),  INT8_C(  83), -INT8_C( 107),  INT8_C(  97), -INT8_C(  81),  INT8_C( 111), -INT8_C(  55),  INT8_C( 125),
        -INT8_C(  29), -INT8_C( 117), -INT8_C(   3), -INT8_C( 103),  INT8_C(  23), -INT8_C(  89),  INT8_C(  49), -INT8_C(  75),
         INT8_C(  75), -INT8_C(  61),  INT8_C( 101), -INT8_C(  47),  INT8_C( 127), -INT8_C(  33), -INT8_C( 103), -INT8_C(  19),
        -INT8_C(  77), -INT8_C(   5), -INT8_C(  51),  INT8_C(   9), -INT8_C(  25),  INT8_C(  23),  INT8_C(   1),  INT8_C(  37),
         INT8_C(  27),  INT8_C(  51),  INT8_C(  53),  INT8_C(  65),  INT8_C(  79),  INT8_C(  79),  INT8_C( 105),  INT8_C(  93),
        -INT8_C( 125),  INT8_C( 107), -INT8_C(  99),  INT8_C( 121), -INT8_C(  73), -INT8_C( 121), -INT8_C(  47), -INT8_C( 107),
        -INT8_C(  21), -INT8_C(  93),  INT8_C(   5), -INT8_C(  79),  INT8_C(  31), -INT8_C(  65),  INT8_C(  57), -INT8_C(  51),
         INT8_C(  83), -INT8_C(  37),  INT8_C( 109), -INT8_C(  23), -INT8_C( 121), -INT8_C(   9), -INT8_C(  95),  INT8_C(   5),
        -INT8_C(  69),  INT8_C(  19), -INT8_C(  43),  INT8_C(  33), -INT8_C(  17),  INT8_C(  47),  INT8_C(   9),  INT8_C(  61),
         INT8_C(  35),  INT8_C(  75),  INT8_C(  61),  INT8_C(  89),  INT8_C(  87),  INT8_C( 103),  INT8_C( 113),  INT8_C( 117)
      },
      {
         INT8_C(  24),  INT8_C(  10),  INT8_C(  50),  INT8_C(  24),  INT8_C(  76),  INT8_C(  38),  INT8_C( 102),  INT8_C(  52),
        -INT8_C( 128),  INT8_C(  66), -INT8_C( 102),  INT8_C(  80), -INT8_C(  76),  INT8_C(  94), -INT8_C(  50),  INT8_C( 108),
        -INT8_C(  24),  INT8_C( 122),  INT8_C(   2), -INT8_C( 120),  INT8_C(  28), -INT8_C( 106),  INT8_C(  54), -INT8_C(  92),
         INT8_C(  80), -INT8_C(  78),  INT8_C( 106), -INT8_C(  64), -INT8_C( 124), -INT8_C(  50), -INT8_C(  98), -INT8_C(  36),
        -INT8_C(  72), -INT8_C(  22), -INT8_C(  46), -INT8_C(   8), -INT8_C(  20),  INT8_C(   6),  INT8_C(   6),  INT8_C(  20),
         INT8_C(  32),  INT8_C(  34),  INT8_C(  58),  INT8_C(  48),  INT8_C(  84),  INT8_C(  62),  INT8_C( 110),  INT8_C(  76),
        -INT8_C( 120),  INT8_C(  90), -INT8_C(  94),  INT8_C( 104), -INT8_C(  68),  INT8_C( 118), -INT8_C(  42), -INT8_C( 124),
        -INT8_C(  16), -INT8_C( 110),  INT8_C(  10), -INT8_C(  96),  INT8_C(  36), -INT8_C(  82),  INT8_C(  62), -INT8_C(  68),
         INT8_C(  88), -INT8_C(  54),  INT8_C( 114), -INT8_C(  40), -INT8_C( 116), -INT8_C(  26), -INT8_C(  90), -INT8_C(  12),
        -INT8_C(  64),  INT8_C(   2), -INT8_C(  38),  INT8_C(  16), -INT8_C(  12),  INT8_C(  30),  INT8_C(  14),  INT8_C(  44),
         INT8_C(  40),  INT8_C(  58),  INT8_C(  66),  INT8_C(  72),  INT8_C(  92),  INT8_C(  86),  INT8_C( 118),  INT8_C( 100),
        -INT8_C( 112),  INT8_C( 114), -INT8_C(  86), -INT8_C( 128), -INT8_C(  60), -INT8_C( 114), -INT8_C(  34), -INT8_C( 100),
        -INT8_C(   8), -INT8_C(  86),  INT8_C(  18), -INT8_C(  72),  INT8_C(  44), -INT8_C(  58),  INT8_C(  70), -INT8_C(  44),
         INT8_C(  96), -INT8_C(  30),  INT8_C( 122), -INT8_C(  16), -INT8_C( 108), -INT8_C(   2), -INT8_C(  82),  INT8_C(  12),
        -INT8_C(  56),  INT8_C(  26), -INT8_C(  30),  INT8_C(  40), -INT8_C(   4),  INT8_C(  54),  INT8_C(  22),  INT8_C(  68),
         INT8_C(  48),  INT8_C(  82),  INT8_C(  74),  INT8_C(  96),  INT8_C( 100),  INT8_C( 110),  INT8_C( 126),  INT8_C( 124)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vectorpair_t r = simde_Q6_W_vdeal_VVR(
        simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk),
        simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk), test_vec[i].rt);
      simde_test_hvx_vector_i8_assert_equal(simde_Q6_V_lo_W(r), simde_test_hvx_fixture_vector_load(test_vec[i].r_lo, chunk));
      simde_test_hvx_vector_i8_assert_equal(simde_Q6_V_hi_W(r), simde_test_hvx_fixture_vector_load(test_vec[i].r_hi, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vshuff_Vb)
SIMDE_TEST_FUNC_LIST_ENTRY(vshuff_Vh)
SIMDE_TEST_FUNC_LIST_ENTRY(vdeal_Vb)
SIMDE_TEST_FUNC_LIST_ENTRY(vdeal_Vh)
SIMDE_TEST_FUNC_LIST_ENTRY(vshuffe_VbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vshuffo_VbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vshuffe_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vshuffo_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vdeale_VbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vshuffoe_VbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vshuffoe_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vshuff_VVR)
SIMDE_TEST_FUNC_LIST_ENTRY(vdeal_VVR)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
