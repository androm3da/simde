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

#define SIMDE_TEST_HEXAGON_HVX_INSN vpack

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vpack.h"

#define SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE 128
#define SIMDE_TEST_HVX_FIXTURE_CHUNKS (SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE / SIMDE_HVX_VECTOR_SIZE)

static simde_hvx_vector_t
simde_test_hvx_fixture_vector_load(const void* ptr, size_t chunk) {
  return simde_test_hvx_vector_load(
    HEDLEY_REINTERPRET_CAST(const uint8_t*, ptr) + (chunk * SIMDE_HVX_VECTOR_SIZE));
}

static simde_hvx_vector_t
simde_test_hvx_fixture_packed_load(const void* ptr, size_t chunk) {
  simde_hvx_vector_t r;
  uint8_t* r_ = HEDLEY_REINTERPRET_CAST(uint8_t*, &r);
  const uint8_t* ptr_ = HEDLEY_REINTERPRET_CAST(const uint8_t*, ptr);
  const size_t half = SIMDE_HVX_VECTOR_SIZE / 2;

  simde_memcpy(r_, ptr_ + (chunk * half), half);
  simde_memcpy(r_ + half,
               ptr_ + (SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE / 2) + (chunk * half), half);
  return r;
}

static int
test_simde_vpacke_VhVh(SIMDE_MUNIT_TEST_ARGS) {
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
       INT8_C(  11),  INT8_C(  37),  INT8_C(  63),  INT8_C(  89),  INT8_C( 115), -INT8_C( 115), -INT8_C(  89), -INT8_C(  63),
      -INT8_C(  37), -INT8_C(  11),  INT8_C(  15),  INT8_C(  41),  INT8_C(  67),  INT8_C(  93),  INT8_C( 119), -INT8_C( 111),
      -INT8_C(  85), -INT8_C(  59), -INT8_C(  33), -INT8_C(   7),  INT8_C(  19),  INT8_C(  45),  INT8_C(  71),  INT8_C(  97),
       INT8_C( 123), -INT8_C( 107), -INT8_C(  81), -INT8_C(  55), -INT8_C(  29), -INT8_C(   3),  INT8_C(  23),  INT8_C(  49),
       INT8_C(  75),  INT8_C( 101),  INT8_C( 127), -INT8_C( 103), -INT8_C(  77), -INT8_C(  51), -INT8_C(  25),  INT8_C(   1),
       INT8_C(  27),  INT8_C(  53),  INT8_C(  79),  INT8_C( 105), -INT8_C( 125), -INT8_C(  99), -INT8_C(  73), -INT8_C(  47),
      -INT8_C(  21),  INT8_C(   5),  INT8_C(  31),  INT8_C(  57),  INT8_C(  83),  INT8_C( 109), -INT8_C( 121), -INT8_C(  95),
      -INT8_C(  69), -INT8_C(  43), -INT8_C(  17),  INT8_C(   9),  INT8_C(  35),  INT8_C(  61),  INT8_C(  87),  INT8_C( 113),
       INT8_C(   3),  INT8_C(  17),  INT8_C(  31),  INT8_C(  45),  INT8_C(  59),  INT8_C(  73),  INT8_C(  87),  INT8_C( 101),
       INT8_C( 115), -INT8_C( 127), -INT8_C( 113), -INT8_C(  99), -INT8_C(  85), -INT8_C(  71), -INT8_C(  57), -INT8_C(  43),
      -INT8_C(  29), -INT8_C(  15), -INT8_C(   1),  INT8_C(  13),  INT8_C(  27),  INT8_C(  41),  INT8_C(  55),  INT8_C(  69),
       INT8_C(  83),  INT8_C(  97),  INT8_C( 111),  INT8_C( 125), -INT8_C( 117), -INT8_C( 103), -INT8_C(  89), -INT8_C(  75),
      -INT8_C(  61), -INT8_C(  47), -INT8_C(  33), -INT8_C(  19), -INT8_C(   5),  INT8_C(   9),  INT8_C(  23),  INT8_C(  37),
       INT8_C(  51),  INT8_C(  65),  INT8_C(  79),  INT8_C(  93),  INT8_C( 107),  INT8_C( 121), -INT8_C( 121), -INT8_C( 107),
      -INT8_C(  93), -INT8_C(  79), -INT8_C(  65), -INT8_C(  51), -INT8_C(  37), -INT8_C(  23), -INT8_C(   9),  INT8_C(   5),
       INT8_C(  19),  INT8_C(  33),  INT8_C(  47),  INT8_C(  61),  INT8_C(  75),  INT8_C(  89),  INT8_C( 103),  INT8_C( 117)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vector_t a = simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk);
      simde_hvx_vector_t b = simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk);
      simde_hvx_vector_t r = simde_Q6_Vb_vpacke_VhVh(a, b);
      simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_fixture_packed_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vpacko_VhVh(SIMDE_MUNIT_TEST_ARGS) {
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
       INT8_C(  24),  INT8_C(  50),  INT8_C(  76),  INT8_C( 102), -INT8_C( 128), -INT8_C( 102), -INT8_C(  76), -INT8_C(  50),
      -INT8_C(  24),  INT8_C(   2),  INT8_C(  28),  INT8_C(  54),  INT8_C(  80),  INT8_C( 106), -INT8_C( 124), -INT8_C(  98),
      -INT8_C(  72), -INT8_C(  46), -INT8_C(  20),  INT8_C(   6),  INT8_C(  32),  INT8_C(  58),  INT8_C(  84),  INT8_C( 110),
      -INT8_C( 120), -INT8_C(  94), -INT8_C(  68), -INT8_C(  42), -INT8_C(  16),  INT8_C(  10),  INT8_C(  36),  INT8_C(  62),
       INT8_C(  88),  INT8_C( 114), -INT8_C( 116), -INT8_C(  90), -INT8_C(  64), -INT8_C(  38), -INT8_C(  12),  INT8_C(  14),
       INT8_C(  40),  INT8_C(  66),  INT8_C(  92),  INT8_C( 118), -INT8_C( 112), -INT8_C(  86), -INT8_C(  60), -INT8_C(  34),
      -INT8_C(   8),  INT8_C(  18),  INT8_C(  44),  INT8_C(  70),  INT8_C(  96),  INT8_C( 122), -INT8_C( 108), -INT8_C(  82),
      -INT8_C(  56), -INT8_C(  30), -INT8_C(   4),  INT8_C(  22),  INT8_C(  48),  INT8_C(  74),  INT8_C( 100),  INT8_C( 126),
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
      simde_hvx_vector_t a = simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk);
      simde_hvx_vector_t b = simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk);
      simde_hvx_vector_t r = simde_Q6_Vb_vpacko_VhVh(a, b);
      simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_fixture_packed_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vpacke_VwVw(SIMDE_MUNIT_TEST_ARGS) {
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
       INT16_C(  6155),  INT16_C( 19519), -INT16_C( 32653), -INT16_C( 19289),
      -INT16_C(  5925),  INT16_C(  7183),  INT16_C( 20547), -INT16_C( 31625),
      -INT16_C( 18261), -INT16_C(  4897),  INT16_C(  8211),  INT16_C( 21575),
      -INT16_C( 30597), -INT16_C( 17233), -INT16_C(  3869),  INT16_C(  9239),
       INT16_C( 22603), -INT16_C( 29569), -INT16_C( 16205), -INT16_C(  2841),
       INT16_C( 10267),  INT16_C( 23631), -INT16_C( 28541), -INT16_C( 15177),
      -INT16_C(  1813),  INT16_C( 11295),  INT16_C( 24659), -INT16_C( 27513),
      -INT16_C( 14149), -INT16_C(   785),  INT16_C( 12323),  INT16_C( 25687),
       INT16_C(  2563),  INT16_C(  9759),  INT16_C( 16955),  INT16_C( 24151),
       INT16_C( 31347), -INT16_C( 26993), -INT16_C( 19797), -INT16_C( 12601),
      -INT16_C(  5405),  INT16_C(  1791),  INT16_C(  8731),  INT16_C( 15927),
       INT16_C( 23123),  INT16_C( 30319), -INT16_C( 28021), -INT16_C( 20825),
      -INT16_C( 13629), -INT16_C(  6433),  INT16_C(   763),  INT16_C(  7703),
       INT16_C( 14899),  INT16_C( 22095),  INT16_C( 29291), -INT16_C( 29049),
      -INT16_C( 21853), -INT16_C( 14657), -INT16_C(  7461), -INT16_C(   265),
       INT16_C(  6675),  INT16_C( 13871),  INT16_C( 21067),  INT16_C( 28263)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vector_t a = simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk);
      simde_hvx_vector_t b = simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk);
      simde_hvx_vector_t r = simde_Q6_Vh_vpacke_VwVw(a, b);
      simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_fixture_packed_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vpacko_VwVw(SIMDE_MUNIT_TEST_ARGS) {
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
       INT16_C( 12837),  INT16_C( 26201), -INT16_C( 25971), -INT16_C( 12607),
       INT16_C(   757),  INT16_C( 13865),  INT16_C( 27229), -INT16_C( 24943),
      -INT16_C( 11579),  INT16_C(  1785),  INT16_C( 14893),  INT16_C( 28257),
      -INT16_C( 23915), -INT16_C( 10551),  INT16_C(  2813),  INT16_C( 15921),
       INT16_C( 29285), -INT16_C( 22887), -INT16_C(  9523),  INT16_C(  3585),
       INT16_C( 16949),  INT16_C( 30313), -INT16_C( 21859), -INT16_C(  8495),
       INT16_C(  4613),  INT16_C( 17977),  INT16_C( 31341), -INT16_C( 20831),
      -INT16_C(  7467),  INT16_C(  5641),  INT16_C( 19005),  INT16_C( 32369),
       INT16_C(  6161),  INT16_C( 13357),  INT16_C( 20553),  INT16_C( 27749),
      -INT16_C( 30591), -INT16_C( 23395), -INT16_C( 16199), -INT16_C(  9003),
      -INT16_C(  1807),  INT16_C(  5133),  INT16_C( 12329),  INT16_C( 19525),
       INT16_C( 26721), -INT16_C( 31619), -INT16_C( 24423), -INT16_C( 17227),
      -INT16_C( 10031), -INT16_C(  2835),  INT16_C(  4105),  INT16_C( 11301),
       INT16_C( 18497),  INT16_C( 25693), -INT16_C( 32647), -INT16_C( 25451),
      -INT16_C( 18255), -INT16_C( 11059), -INT16_C(  3863),  INT16_C(  3077),
       INT16_C( 10273),  INT16_C( 17469),  INT16_C( 24665),  INT16_C( 31861)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vector_t a = simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk);
      simde_hvx_vector_t b = simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk);
      simde_hvx_vector_t r = simde_Q6_Vh_vpacko_VwVw(a, b);
      simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_fixture_packed_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vpack_VhVh_sat(SIMDE_MUNIT_TEST_ARGS) {
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
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
      -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),
      -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128), -INT8_C( 128),  INT8_C( 127),
       INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127),  INT8_C( 127)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vector_t a = simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk);
      simde_hvx_vector_t b = simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk);
      simde_hvx_vector_t r = simde_Q6_Vb_vpack_VhVh_sat(a, b);
      simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_fixture_packed_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vpack_VhVh_sat_u(SIMDE_MUNIT_TEST_ARGS) {
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
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(255),
      UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vector_t a = simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk);
      simde_hvx_vector_t b = simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk);
      simde_hvx_vector_t r = simde_Q6_Vub_vpack_VhVh_sat(a, b);
      simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_fixture_packed_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vpack_VwVw_sat(SIMDE_MUNIT_TEST_ARGS) {
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
       INT16_C( 32767),  INT16_C( 32767), -INT16_C( 32768), -INT16_C( 32768),
       INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767), -INT16_C( 32768),
      -INT16_C( 32768),  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),
      -INT16_C( 32768), -INT16_C( 32768),  INT16_C( 32767),  INT16_C( 32767),
       INT16_C( 32767), -INT16_C( 32768), -INT16_C( 32768),  INT16_C( 32767),
       INT16_C( 32767),  INT16_C( 32767), -INT16_C( 32768), -INT16_C( 32768),
       INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767), -INT16_C( 32768),
      -INT16_C( 32768),  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),
       INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),
      -INT16_C( 32768), -INT16_C( 32768), -INT16_C( 32768), -INT16_C( 32768),
      -INT16_C( 32768),  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),
       INT16_C( 32767), -INT16_C( 32768), -INT16_C( 32768), -INT16_C( 32768),
      -INT16_C( 32768), -INT16_C( 32768),  INT16_C( 32767),  INT16_C( 32767),
       INT16_C( 32767),  INT16_C( 32767), -INT16_C( 32768), -INT16_C( 32768),
      -INT16_C( 32768), -INT16_C( 32768), -INT16_C( 32768),  INT16_C( 32767),
       INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767),  INT16_C( 32767)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vector_t a = simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk);
      simde_hvx_vector_t b = simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk);
      simde_hvx_vector_t r = simde_Q6_Vh_vpack_VwVw_sat(a, b);
      simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_fixture_packed_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

static int
test_simde_vpack_VwVw_sat_u(SIMDE_MUNIT_TEST_ARGS) {
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
      UINT16_C(65535), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(65535), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(65535),
      UINT16_C(65535), UINT16_C(65535), UINT16_C(65535), UINT16_C(65535)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vector_t a = simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk);
      simde_hvx_vector_t b = simde_test_hvx_fixture_vector_load(test_vec[i].b, chunk);
      simde_hvx_vector_t r = simde_Q6_Vuh_vpack_VwVw_sat(a, b);
      simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_fixture_packed_load(test_vec[i].r, chunk));
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vpacke_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vpacko_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vpacke_VwVw)
SIMDE_TEST_FUNC_LIST_ENTRY(vpacko_VwVw)
SIMDE_TEST_FUNC_LIST_ENTRY(vpack_VhVh_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vpack_VhVh_sat_u)
SIMDE_TEST_FUNC_LIST_ENTRY(vpack_VwVw_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vpack_VwVw_sat_u)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
