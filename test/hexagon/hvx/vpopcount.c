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

#define SIMDE_TEST_HEXAGON_HVX_INSN vpopcount

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vpopcount.h"

static int
test_simde_vpopcount_Vh(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[64]; int16_t r[64];
  } test_vec[] = {
    {      /* a */ { INT16_C(  2110),  INT16_C( 32736), -INT16_C( 12607),  INT16_C( 27839), -INT16_C( 32061), -INT16_C( 32217),  INT16_C( 24534),  INT16_C( 20051)
                ,  INT16_C( 13384), -INT16_C( 21965),  INT16_C( 26174), -INT16_C(  5989),  INT16_C( 20449),  INT16_C( 26977), -INT16_C(  4600),  INT16_C( 13037)
                ,  INT16_C(  8171), -INT16_C(  6564),  INT16_C( 14235),  INT16_C( 10289), -INT16_C(  2698),  INT16_C( 29755),  INT16_C( 30798),  INT16_C(  7967)
                ,  INT16_C( 17226),  INT16_C( 27932),  INT16_C( 16038),  INT16_C( 27113),  INT16_C(  6534),  INT16_C( 24493),  INT16_C(  5725), -INT16_C( 13809)
                ,  INT16_C( 22917), -INT16_C( 25566),  INT16_C(  9608), -INT16_C(   516), -INT16_C( 20726),  INT16_C( 11858), -INT16_C( 14959),  INT16_C( 21555)
                ,  INT16_C( 10037), -INT16_C(  3031), -INT16_C( 29662),  INT16_C( 27639),  INT16_C(  7510),  INT16_C( 29964), -INT16_C( 27242), -INT16_C(   331)
                ,  INT16_C(  5093), -INT16_C( 14126),  INT16_C( 13721), -INT16_C( 11570),  INT16_C(  8421), -INT16_C( 26651),  INT16_C( 19045), -INT16_C(  9365)
                ,  INT16_C(  9009), -INT16_C(  5244),  INT16_C(  8525),  INT16_C( 12886),  INT16_C( 12433), -INT16_C( 27412),  INT16_C( 18411),  INT16_C( 16247) },
      /* r */ { INT16_C(     6),  INT16_C(    10),  INT16_C(     8),  INT16_C(    11),  INT16_C(     6),  INT16_C(     6),  INT16_C(    11),  INT16_C(     8)
                ,  INT16_C(     5),  INT16_C(     8),  INT16_C(     9),  INT16_C(     9),  INT16_C(     9),  INT16_C(     7),  INT16_C(     7),  INT16_C(     9)
                ,  INT16_C(    11),  INT16_C(     9),  INT16_C(    10),  INT16_C(     5),  INT16_C(    11),  INT16_C(     9),  INT16_C(     8),  INT16_C(    10)
                ,  INT16_C(     6),  INT16_C(     8),  INT16_C(     9),  INT16_C(     9),  INT16_C(     6),  INT16_C(    11),  INT16_C(     8),  INT16_C(     8)
                ,  INT16_C(     7),  INT16_C(     6),  INT16_C(     5),  INT16_C(    13),  INT16_C(     8),  INT16_C(     7),  INT16_C(     7),  INT16_C(     7)
                ,  INT16_C(     8),  INT16_C(     8),  INT16_C(     5),  INT16_C(    12),  INT16_C(     8),  INT16_C(     7),  INT16_C(     8),  INT16_C(    12)
                ,  INT16_C(     8),  INT16_C(     7),  INT16_C(     8),  INT16_C(     9),  INT16_C(     6),  INT16_C(    10),  INT16_C(     7),  INT16_C(    11)
                ,  INT16_C(     6),  INT16_C(     8),  INT16_C(     6),  INT16_C(     7),  INT16_C(     5),  INT16_C(     8),  INT16_C(    10),  INT16_C(    12) } },
    {      /* a */ {-INT16_C( 25701), -INT16_C( 19631),  INT16_C( 18109), -INT16_C(  4873),  INT16_C( 32557),  INT16_C( 23278), -INT16_C( 28233),  INT16_C(  1125)
                , -INT16_C( 18531),  INT16_C( 14290),  INT16_C( 27403),  INT16_C(  3699),  INT16_C( 26763), -INT16_C(  1653),  INT16_C( 30610),  INT16_C( 25803)
                , -INT16_C(  2496), -INT16_C( 30682),  INT16_C( 20690), -INT16_C(  1093),  INT16_C( 28797),  INT16_C(  3860), -INT16_C( 32494), -INT16_C( 27911)
                , -INT16_C( 32269), -INT16_C( 23972),  INT16_C( 23108), -INT16_C( 10518), -INT16_C(  8946), -INT16_C( 19783),  INT16_C(  7271), -INT16_C(  1681)
                ,  INT16_C( 29313),  INT16_C(  7078),  INT16_C(  5644), -INT16_C( 31189),  INT16_C( 31124), -INT16_C( 15671), -INT16_C(  8346), -INT16_C(  2137)
                ,  INT16_C(  6791), -INT16_C(  4161),  INT16_C(  6410), -INT16_C(  2546), -INT16_C( 31371),  INT16_C(  4837), -INT16_C(  1330), -INT16_C( 15258)
                ,  INT16_C(   218),  INT16_C( 16233),  INT16_C( 31579),  INT16_C(    88),  INT16_C(  6039), -INT16_C(   299), -INT16_C(  3147), -INT16_C( 12249)
                ,  INT16_C( 14808),  INT16_C(  8773),  INT16_C(  1248), -INT16_C(  5233), -INT16_C(  2767), -INT16_C(  7473), -INT16_C( 31470), -INT16_C( 26067) },
      /* r */ { INT16_C(    10),  INT16_C(     8),  INT16_C(     9),  INT16_C(    12),  INT16_C(    11),  INT16_C(    10),  INT16_C(     9),  INT16_C(     5)
                ,  INT16_C(    11),  INT16_C(     9),  INT16_C(     8),  INT16_C(     8),  INT16_C(     7),  INT16_C(    10),  INT16_C(     9),  INT16_C(     8)
                ,  INT16_C(     7),  INT16_C(     5),  INT16_C(     6),  INT16_C(    13),  INT16_C(     9),  INT16_C(     6),  INT16_C(     4),  INT16_C(     9)
                ,  INT16_C(     8),  INT16_C(     7),  INT16_C(     6),  INT16_C(    10),  INT16_C(     9),  INT16_C(     9),  INT16_C(     8),  INT16_C(    12)
                ,  INT16_C(     6),  INT16_C(     8),  INT16_C(     5),  INT16_C(     7),  INT16_C(     8),  INT16_C(     7),  INT16_C(    11),  INT16_C(    12)
                ,  INT16_C(     7),  INT16_C(    14),  INT16_C(     5),  INT16_C(     9),  INT16_C(     8),  INT16_C(     7),  INT16_C(    11),  INT16_C(     7)
                ,  INT16_C(     5),  INT16_C(    10),  INT16_C(    11),  INT16_C(     3),  INT16_C(     9),  INT16_C(    12),  INT16_C(    11),  INT16_C(     7)
                ,  INT16_C(     8),  INT16_C(     5),  INT16_C(     4),  INT16_C(    11),  INT16_C(     9),  INT16_C(    10),  INT16_C(     5),  INT16_C(     8) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vh_vpopcount_Vh(a);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vpopcount_Vh)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
