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

#define SIMDE_TEST_HEXAGON_HVX_INSN vinsert

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vinsert.h"

static int
test_simde_vinsert_VwR(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t x[32]; int32_t rt; int32_t r[32];
  } test_vec[] = {
    {      /* x */ { INT32_C( 1144274802),  INT32_C(  457386730),  INT32_C( 2085387465), -INT32_C( 1608549001)
                ,  INT32_C(  150621812),  INT32_C( 1353206280),  INT32_C(  514916698), -INT32_C(  425672166)
                ,  INT32_C(  453616652),  INT32_C(  510811072),  INT32_C(  418118422), -INT32_C( 1463599548)
                ,  INT32_C( 1610268342), -INT32_C(  305183309), -INT32_C(  851268544),  INT32_C( 1208053478)
                ,  INT32_C( 1954861827), -INT32_C( 1712922565),  INT32_C(  971113186), -INT32_C(  646080381)
                ,  INT32_C(   74946404),  INT32_C( 1041808144),  INT32_C(  508798511),  INT32_C( 1071736470)
                , -INT32_C( 1222257396), -INT32_C( 1796387802),  INT32_C( 1765531957), -INT32_C( 1479070109)
                , -INT32_C(  499393495),  INT32_C(  281625430),  INT32_C(  594072988), -INT32_C(  980056058) },
      /* rt */ INT32_C(-1909462432),
      /* r */ {-INT32_C( 1909462432),  INT32_C(  457386730),  INT32_C( 2085387465), -INT32_C( 1608549001)
                ,  INT32_C(  150621812),  INT32_C( 1353206280),  INT32_C(  514916698), -INT32_C(  425672166)
                ,  INT32_C(  453616652),  INT32_C(  510811072),  INT32_C(  418118422), -INT32_C( 1463599548)
                ,  INT32_C( 1610268342), -INT32_C(  305183309), -INT32_C(  851268544),  INT32_C( 1208053478)
                ,  INT32_C( 1954861827), -INT32_C( 1712922565),  INT32_C(  971113186), -INT32_C(  646080381)
                ,  INT32_C(   74946404),  INT32_C( 1041808144),  INT32_C(  508798511),  INT32_C( 1071736470)
                , -INT32_C( 1222257396), -INT32_C( 1796387802),  INT32_C( 1765531957), -INT32_C( 1479070109)
                , -INT32_C(  499393495),  INT32_C(  281625430),  INT32_C(  594072988), -INT32_C(  980056058) } },
    {      /* x */ { INT32_C(  964862705), -INT32_C(  149082434),  INT32_C(  434128033),  INT32_C(  871197507)
                ,  INT32_C( 1294017416), -INT32_C( 1803328913), -INT32_C( 1058938675), -INT32_C( 1051672637)
                , -INT32_C(  339284940),  INT32_C(  989340417), -INT32_C( 1926954299), -INT32_C( 2023872041)
                ,  INT32_C( 1644123289),  INT32_C( 2096511034), -INT32_C( 1269624601),  INT32_C(  960568755)
                , -INT32_C(   89487393), -INT32_C(  406420010), -INT32_C( 1454839524), -INT32_C(  628673590)
                , -INT32_C( 2122557309),  INT32_C(  601652597),  INT32_C( 1670309873),  INT32_C( 1198897352)
                , -INT32_C(   72198144), -INT32_C(  989447996), -INT32_C( 1350732474),  INT32_C( 1324817908)
                ,  INT32_C( 1030881639), -INT32_C( 1333012030), -INT32_C( 1061593775),  INT32_C(  955954002) },
      /* rt */ INT32_C(-1421844833),
      /* r */ {-INT32_C( 1421844833), -INT32_C(  149082434),  INT32_C(  434128033),  INT32_C(  871197507)
                ,  INT32_C( 1294017416), -INT32_C( 1803328913), -INT32_C( 1058938675), -INT32_C( 1051672637)
                , -INT32_C(  339284940),  INT32_C(  989340417), -INT32_C( 1926954299), -INT32_C( 2023872041)
                ,  INT32_C( 1644123289),  INT32_C( 2096511034), -INT32_C( 1269624601),  INT32_C(  960568755)
                , -INT32_C(   89487393), -INT32_C(  406420010), -INT32_C( 1454839524), -INT32_C(  628673590)
                , -INT32_C( 2122557309),  INT32_C(  601652597),  INT32_C( 1670309873),  INT32_C( 1198897352)
                , -INT32_C(   72198144), -INT32_C(  989447996), -INT32_C( 1350732474),  INT32_C( 1324817908)
                ,  INT32_C( 1030881639), -INT32_C( 1333012030), -INT32_C( 1061593775),  INT32_C(  955954002) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t x = simde_test_hvx_vector_load(test_vec[i].x);
    simde_hvx_vector_t r = simde_Q6_Vw_vinsert_VwR(x, test_vec[i].rt);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vinsert_VwR)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
