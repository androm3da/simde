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

#define SIMDE_TEST_HEXAGON_HVX_INSN vcl0

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vcl0.h"

static int
test_simde_vcl0_Vuh(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[64]; uint16_t r[64];
  } test_vec[] = {
    {      /* a */ {UINT16_C(27947), UINT16_C(17921), UINT16_C(48556), UINT16_C(63876), UINT16_C(57959), UINT16_C(57248), UINT16_C(30338), UINT16_C(18822)
                , UINT16_C(47474), UINT16_C(43564), UINT16_C(54062), UINT16_C( 4086), UINT16_C( 9208), UINT16_C(20737), UINT16_C(14842), UINT16_C( 1612)
                , UINT16_C(33344), UINT16_C(20444), UINT16_C(17165), UINT16_C(43318), UINT16_C(44817), UINT16_C(41851), UINT16_C(54684), UINT16_C(19251)
                , UINT16_C( 6834), UINT16_C(60889), UINT16_C(55015), UINT16_C(63883), UINT16_C(58263), UINT16_C(35106), UINT16_C(30392), UINT16_C(51574)
                , UINT16_C(10174), UINT16_C(27496), UINT16_C(64839), UINT16_C(62710), UINT16_C(16588), UINT16_C(20648), UINT16_C(52328), UINT16_C(55216)
                , UINT16_C(63995), UINT16_C(36237), UINT16_C( 9155), UINT16_C( 9920), UINT16_C(38616), UINT16_C(14824), UINT16_C(15228), UINT16_C(17844)
                , UINT16_C(30582), UINT16_C(59773), UINT16_C( 5032), UINT16_C(49936), UINT16_C(50787), UINT16_C(54303), UINT16_C(18908), UINT16_C(40642)
                , UINT16_C(15108), UINT16_C(26348), UINT16_C(34529), UINT16_C(56047), UINT16_C(37456), UINT16_C(62159), UINT16_C(17907), UINT16_C(60001) },
      /* r */ {UINT16_C(    1), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1)
                , UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    4), UINT16_C(    2), UINT16_C(    1), UINT16_C(    2), UINT16_C(    5)
                , UINT16_C(    0), UINT16_C(    1), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1)
                , UINT16_C(    3), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0)
                , UINT16_C(    2), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0)
                , UINT16_C(    0), UINT16_C(    0), UINT16_C(    2), UINT16_C(    2), UINT16_C(    0), UINT16_C(    2), UINT16_C(    2), UINT16_C(    1)
                , UINT16_C(    1), UINT16_C(    0), UINT16_C(    3), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0)
                , UINT16_C(    2), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0) } },
    {      /* a */ {UINT16_C(13098), UINT16_C( 9921), UINT16_C(47621), UINT16_C(60176), UINT16_C(54454), UINT16_C(17520), UINT16_C(37468), UINT16_C(38747)
                , UINT16_C(42649), UINT16_C( 1845), UINT16_C(57263), UINT16_C( 5620), UINT16_C(17879), UINT16_C(64487), UINT16_C(44509), UINT16_C(36315)
                , UINT16_C( 4294), UINT16_C(31642), UINT16_C(39289), UINT16_C(38960), UINT16_C(  899), UINT16_C( 4001), UINT16_C(23943), UINT16_C(42795)
                , UINT16_C(11887), UINT16_C(57084), UINT16_C(29877), UINT16_C(32498), UINT16_C( 5827), UINT16_C( 2435), UINT16_C(24544), UINT16_C(14116)
                , UINT16_C(61620), UINT16_C(41924), UINT16_C( 3210), UINT16_C(37872), UINT16_C(62505), UINT16_C( 6496), UINT16_C( 2957), UINT16_C(49739)
                , UINT16_C(16777), UINT16_C(53300), UINT16_C(44732), UINT16_C(16532), UINT16_C(60287), UINT16_C(24927), UINT16_C(60699), UINT16_C(49749)
                , UINT16_C(10894), UINT16_C( 5674), UINT16_C(11755), UINT16_C(39495), UINT16_C(41172), UINT16_C(49069), UINT16_C(11511), UINT16_C(55323)
                , UINT16_C(44977), UINT16_C(61315), UINT16_C(25526), UINT16_C(55415), UINT16_C(40884), UINT16_C( 1044), UINT16_C(43775), UINT16_C(51285) },
      /* r */ {UINT16_C(    2), UINT16_C(    2), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0)
                , UINT16_C(    0), UINT16_C(    5), UINT16_C(    0), UINT16_C(    3), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0)
                , UINT16_C(    3), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    6), UINT16_C(    4), UINT16_C(    1), UINT16_C(    0)
                , UINT16_C(    2), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1), UINT16_C(    3), UINT16_C(    4), UINT16_C(    1), UINT16_C(    2)
                , UINT16_C(    0), UINT16_C(    0), UINT16_C(    4), UINT16_C(    0), UINT16_C(    0), UINT16_C(    3), UINT16_C(    4), UINT16_C(    0)
                , UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0)
                , UINT16_C(    2), UINT16_C(    3), UINT16_C(    2), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    2), UINT16_C(    0)
                , UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    5), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vuh_vcl0_Vuh(a);
    simde_test_hvx_vector_u16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcl0_Vuw(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[32]; uint32_t r[32];
  } test_vec[] = {
    {      /* a */ {UINT32_C(2747972284), UINT32_C(3613278433), UINT32_C(1494517525), UINT32_C(2122784310)
                , UINT32_C(3267264950), UINT32_C( 971603770), UINT32_C(2870066480), UINT32_C(1971210472)
                , UINT32_C(2296799524), UINT32_C( 912075445), UINT32_C(3253545572), UINT32_C(2574966347)
                , UINT32_C(2149340281), UINT32_C( 197091074), UINT32_C(3074736087), UINT32_C( 742442264)
                , UINT32_C(2668045349), UINT32_C(4064447385), UINT32_C(4168752495), UINT32_C(2484806739)
                , UINT32_C(3376470715), UINT32_C(2174424658), UINT32_C( 780986347), UINT32_C(1293950428)
                , UINT32_C(4268152290), UINT32_C(2465098062), UINT32_C(1434902576), UINT32_C(3052124384)
                , UINT32_C( 706161088), UINT32_C( 448561822), UINT32_C( 353570313), UINT32_C( 231020559) },
      /* r */ {UINT32_C(         0), UINT32_C(         0), UINT32_C(         1), UINT32_C(         1)
                , UINT32_C(         0), UINT32_C(         2), UINT32_C(         0), UINT32_C(         1)
                , UINT32_C(         0), UINT32_C(         2), UINT32_C(         0), UINT32_C(         0)
                , UINT32_C(         0), UINT32_C(         4), UINT32_C(         0), UINT32_C(         2)
                , UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0)
                , UINT32_C(         0), UINT32_C(         0), UINT32_C(         2), UINT32_C(         1)
                , UINT32_C(         0), UINT32_C(         0), UINT32_C(         1), UINT32_C(         0)
                , UINT32_C(         2), UINT32_C(         3), UINT32_C(         3), UINT32_C(         4) } },
    {      /* a */ {UINT32_C(1937385914), UINT32_C(3669807470), UINT32_C(2594276683), UINT32_C( 401544496)
                , UINT32_C(3929185573), UINT32_C( 271468261), UINT32_C(2387810584), UINT32_C(3894611914)
                , UINT32_C(3965990301), UINT32_C(2499069819), UINT32_C(1005556486), UINT32_C(1041732341)
                , UINT32_C(2990304216), UINT32_C(  90531331), UINT32_C( 717398862), UINT32_C(2460516277)
                , UINT32_C(2522687059), UINT32_C(1834620259), UINT32_C(2444382363), UINT32_C( 486000759)
                , UINT32_C( 100305599), UINT32_C(4189151132), UINT32_C(1711927611), UINT32_C(1976529352)
                , UINT32_C(1911346948), UINT32_C(2578342203), UINT32_C(2024238473), UINT32_C(3004192677)
                , UINT32_C(3815268949), UINT32_C(3723806923), UINT32_C(1152468308), UINT32_C(2911932249) },
      /* r */ {UINT32_C(         1), UINT32_C(         0), UINT32_C(         0), UINT32_C(         3)
                , UINT32_C(         0), UINT32_C(         3), UINT32_C(         0), UINT32_C(         0)
                , UINT32_C(         0), UINT32_C(         0), UINT32_C(         2), UINT32_C(         2)
                , UINT32_C(         0), UINT32_C(         5), UINT32_C(         2), UINT32_C(         0)
                , UINT32_C(         0), UINT32_C(         1), UINT32_C(         0), UINT32_C(         3)
                , UINT32_C(         5), UINT32_C(         0), UINT32_C(         1), UINT32_C(         1)
                , UINT32_C(         1), UINT32_C(         0), UINT32_C(         1), UINT32_C(         0)
                , UINT32_C(         0), UINT32_C(         0), UINT32_C(         1), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vuw_vcl0_Vuw(a);
    simde_test_hvx_vector_u32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcl0_Vuh)
SIMDE_TEST_FUNC_LIST_ENTRY(vcl0_Vuw)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
