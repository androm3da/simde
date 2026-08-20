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

#define SIMDE_TEST_HEXAGON_HVX_INSN vror

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vror.h"

#define SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE 128
#define SIMDE_TEST_HVX_FIXTURE_CHUNKS (SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE / SIMDE_HVX_VECTOR_SIZE)

static simde_hvx_vector_t
simde_test_hvx_fixture_vector_load(const void* ptr, size_t chunk) {
  return simde_test_hvx_vector_load(
    HEDLEY_REINTERPRET_CAST(const uint8_t*, ptr) + (chunk * SIMDE_HVX_VECTOR_SIZE));
}

static int
test_simde_vror_VR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int32_t rt;
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
      INT32_C(3),
      {
       INT8_C( 125),  INT8_C( 114),  INT8_C(  71),  INT8_C(  52),  INT8_C(  44), -INT8_C(  40),  INT8_C(  16),  INT8_C(  15),
       INT8_C(  47),  INT8_C( 111),  INT8_C( 119),  INT8_C(  13),  INT8_C( 101), -INT8_C(  42),  INT8_C( 112), -INT8_C(  27),
      -INT8_C( 114),  INT8_C(   3),  INT8_C(  81), -INT8_C(  40), -INT8_C(  82), -INT8_C( 114),  INT8_C(  79),  INT8_C( 110),
      -INT8_C(  84),  INT8_C(  52),  INT8_C(  47), -INT8_C(  62),  INT8_C(  49), -INT8_C(  73), -INT8_C(  80), -INT8_C( 121),
       INT8_C(  22), -INT8_C(  21),  INT8_C(  63), -INT8_C(  63),  INT8_C(  40), -INT8_C( 106), -INT8_C(  71),  INT8_C(  98),
       INT8_C(  35),  INT8_C(  23),  INT8_C( 116), -INT8_C( 108),  INT8_C(  40),  INT8_C( 119),  INT8_C(  51), -INT8_C(  62),
      -INT8_C( 114), -INT8_C(  24), -INT8_C(  70),  INT8_C(  83), -INT8_C(  67), -INT8_C(  75),  INT8_C( 107), -INT8_C( 120),
       INT8_C(  36),  INT8_C(  87),  INT8_C( 125),  INT8_C(  83), -INT8_C(  20), -INT8_C(  62), -INT8_C( 118),  INT8_C( 112),
      -INT8_C(  90),  INT8_C(  28),  INT8_C( 117),  INT8_C(  16), -INT8_C(  95), -INT8_C(  51), -INT8_C( 119),  INT8_C(  33),
       INT8_C( 108), -INT8_C(  95),  INT8_C( 108), -INT8_C(   1), -INT8_C(  54), -INT8_C(  22),  INT8_C(  73), -INT8_C( 121),
       INT8_C(  71),  INT8_C( 126), -INT8_C( 122), -INT8_C(  37), -INT8_C(  52), -INT8_C(  71),  INT8_C( 112),  INT8_C(  70),
      -INT8_C(   4),  INT8_C(  46),  INT8_C(  24),  INT8_C(  56),  INT8_C(  78),  INT8_C(  81), -INT8_C(  40),  INT8_C(  32),
      -INT8_C(  59), -INT8_C(  61), -INT8_C(  17), -INT8_C( 128),  INT8_C(   5),  INT8_C(  58), -INT8_C( 120), -INT8_C(  82),
       INT8_C(  57), -INT8_C( 106), -INT8_C(  34),  INT8_C(  80), -INT8_C(  24),  INT8_C(   1), -INT8_C( 122),  INT8_C(  91),
       INT8_C(  54), -INT8_C( 104),  INT8_C( 101),  INT8_C(  78), -INT8_C(  65),  INT8_C(  82),  INT8_C(   0), -INT8_C(  91),
      -INT8_C(   6),  INT8_C(   9),  INT8_C(  57), -INT8_C(  71), -INT8_C(  99),  INT8_C(  57),  INT8_C(  12), -INT8_C( 116)
      } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t chunk = 0 ; chunk < SIMDE_TEST_HVX_FIXTURE_CHUNKS ; chunk++) {
      simde_hvx_vector_t a = simde_test_hvx_fixture_vector_load(test_vec[i].a, chunk);
      simde_hvx_vector_t expected;
      if (SIMDE_HVX_VECTOR_SIZE == SIMDE_TEST_HVX_FIXTURE_VECTOR_SIZE) {
        expected = simde_test_hvx_vector_load(test_vec[i].r);
      } else {
        int8_t expected_[SIMDE_HVX_VECTOR_SIZE];
        const size_t offset = chunk * SIMDE_HVX_VECTOR_SIZE;
        const size_t rotate = HEDLEY_STATIC_CAST(size_t, test_vec[i].rt) & (SIMDE_HVX_VECTOR_SIZE - 1);
        for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_SIZE ; j++) {
          expected_[j] = test_vec[i].a[offset + ((j + rotate) & (SIMDE_HVX_VECTOR_SIZE - 1))];
        }
        expected = simde_test_hvx_vector_load(expected_);
      }
      simde_test_hvx_vector_i8_assert_equal(simde_Q6_V_vror_VR(a, test_vec[i].rt), expected);
    }
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vror_VR)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
