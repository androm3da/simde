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

#define SIMDE_TEST_HEXAGON_HVX_INSN vnormamt

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vnormamt.h"

static int
test_simde_vnormamt_Vh(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[64]; int16_t r[64];
  } test_vec[] = {
    {      /* a */ { INT16_C( 29582), -INT16_C( 12829), -INT16_C( 22352),  INT16_C(  6786), -INT16_C( 29516),  INT16_C( 16559),  INT16_C( 32447),  INT16_C( 21422)
                , -INT16_C( 26212),  INT16_C( 23496),  INT16_C( 28371), -INT16_C( 24875),  INT16_C(  9613),  INT16_C(  1206),  INT16_C(  3963),  INT16_C(  9278)
                , -INT16_C(  3382), -INT16_C( 11073), -INT16_C( 25729),  INT16_C(  8791), -INT16_C(   981),  INT16_C( 15786),  INT16_C(  4742), -INT16_C( 21024)
                , -INT16_C( 30965), -INT16_C(  3524), -INT16_C(  2248),  INT16_C( 20748),  INT16_C( 21707),  INT16_C(  3483), -INT16_C( 13797),  INT16_C(  7192)
                , -INT16_C( 11862),  INT16_C( 19525), -INT16_C( 10948), -INT16_C( 11541), -INT16_C( 22526),  INT16_C( 12820), -INT16_C( 16274),  INT16_C(  3382)
                , -INT16_C(  3994), -INT16_C(  1251),  INT16_C(  5414), -INT16_C(  4676),  INT16_C( 25371), -INT16_C( 20624), -INT16_C( 32320),  INT16_C( 27429)
                ,  INT16_C(  5623),  INT16_C(  7802),  INT16_C( 21810), -INT16_C( 17679), -INT16_C(  2712),  INT16_C(  3921),  INT16_C( 16020),  INT16_C(  4945)
                ,  INT16_C(   993),  INT16_C( 29561),  INT16_C( 13360),  INT16_C( 26633),  INT16_C(  1377),  INT16_C(  9699),  INT16_C( 11311), -INT16_C(  7684) },
      /* r */ { INT16_C(     0),  INT16_C(     1),  INT16_C(     0),  INT16_C(     2),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0)
                ,  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     1),  INT16_C(     4),  INT16_C(     3),  INT16_C(     1)
                ,  INT16_C(     3),  INT16_C(     1),  INT16_C(     0),  INT16_C(     1),  INT16_C(     5),  INT16_C(     1),  INT16_C(     2),  INT16_C(     0)
                ,  INT16_C(     0),  INT16_C(     3),  INT16_C(     3),  INT16_C(     0),  INT16_C(     0),  INT16_C(     3),  INT16_C(     1),  INT16_C(     2)
                ,  INT16_C(     1),  INT16_C(     0),  INT16_C(     1),  INT16_C(     1),  INT16_C(     0),  INT16_C(     1),  INT16_C(     1),  INT16_C(     3)
                ,  INT16_C(     3),  INT16_C(     4),  INT16_C(     2),  INT16_C(     2),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0)
                ,  INT16_C(     2),  INT16_C(     2),  INT16_C(     0),  INT16_C(     0),  INT16_C(     3),  INT16_C(     3),  INT16_C(     1),  INT16_C(     2)
                ,  INT16_C(     5),  INT16_C(     0),  INT16_C(     1),  INT16_C(     0),  INT16_C(     4),  INT16_C(     1),  INT16_C(     1),  INT16_C(     2) } },
    {      /* a */ { INT16_C(  3004),  INT16_C(   489), -INT16_C( 20890), -INT16_C( 10824), -INT16_C( 20581),  INT16_C( 30876),  INT16_C(  3481), -INT16_C( 20556)
                ,  INT16_C( 19931), -INT16_C( 31442),  INT16_C( 20448), -INT16_C( 22774), -INT16_C( 30940),  INT16_C( 12189), -INT16_C( 10484), -INT16_C( 20407)
                ,  INT16_C( 14585),  INT16_C( 29211), -INT16_C( 27619),  INT16_C( 23447), -INT16_C( 29407),  INT16_C(  5228), -INT16_C( 32091), -INT16_C(  4304)
                ,  INT16_C( 18807),  INT16_C( 18899),  INT16_C( 18999), -INT16_C(  1104),  INT16_C( 14667),  INT16_C( 25686), -INT16_C( 20072),  INT16_C(  9315)
                , -INT16_C( 16238), -INT16_C( 17041), -INT16_C( 24294), -INT16_C( 29669),  INT16_C( 31025), -INT16_C(  1750), -INT16_C(   598), -INT16_C( 22927)
                ,  INT16_C(  8208),  INT16_C( 23103),  INT16_C(  8060),  INT16_C( 21408),  INT16_C( 14978),  INT16_C( 32072), -INT16_C( 25441),  INT16_C(  4433)
                ,  INT16_C( 30209),  INT16_C( 25437),  INT16_C(  3324), -INT16_C( 13142),  INT16_C( 22175), -INT16_C( 27162), -INT16_C( 28908),  INT16_C( 17157)
                ,  INT16_C( 20338), -INT16_C(  8894), -INT16_C(  6859), -INT16_C( 14680), -INT16_C( 14211), -INT16_C(  5973), -INT16_C(  4791), -INT16_C( 24805) },
      /* r */ { INT16_C(     3),  INT16_C(     6),  INT16_C(     0),  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     3),  INT16_C(     0)
                ,  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     1),  INT16_C(     1),  INT16_C(     0)
                ,  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     2),  INT16_C(     0),  INT16_C(     2)
                ,  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     4),  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     1)
                ,  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     4),  INT16_C(     5),  INT16_C(     0)
                ,  INT16_C(     1),  INT16_C(     0),  INT16_C(     2),  INT16_C(     0),  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     2)
                ,  INT16_C(     0),  INT16_C(     0),  INT16_C(     3),  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0)
                ,  INT16_C(     0),  INT16_C(     1),  INT16_C(     2),  INT16_C(     1),  INT16_C(     1),  INT16_C(     2),  INT16_C(     2),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vh_vnormamt_Vh(a);
    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vnormamt_Vw(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[32]; int32_t r[32];
  } test_vec[] = {
    {      /* a */ {-INT32_C(  284587333), -INT32_C( 1021508556),  INT32_C(  389288084), -INT32_C(  837097560)
                , -INT32_C( 1511535158), -INT32_C( 2044025909),  INT32_C(  603422542),  INT32_C( 2083034195)
                , -INT32_C(  135497339), -INT32_C(  781185637), -INT32_C( 1881486717), -INT32_C(  485794812)
                , -INT32_C( 1464420289), -INT32_C(  228657578),  INT32_C( 1593031545),  INT32_C( 1782596052)
                ,  INT32_C( 1120095953), -INT32_C( 1582634341),  INT32_C( 1198418975), -INT32_C(  397519331)
                ,  INT32_C(  792090702),  INT32_C( 1701455863),  INT32_C(  716800114),  INT32_C( 2144761138)
                , -INT32_C(  260209632), -INT32_C( 1484030112),  INT32_C(  523872082),  INT32_C( 1473084391)
                ,  INT32_C(   84525595), -INT32_C(  263410928),  INT32_C( 1300561937),  INT32_C(  554679342) },
      /* r */ { INT32_C(          2),  INT32_C(          1),  INT32_C(          2),  INT32_C(          1)
                ,  INT32_C(          0),  INT32_C(          0),  INT32_C(          1),  INT32_C(          0)
                ,  INT32_C(          3),  INT32_C(          1),  INT32_C(          0),  INT32_C(          2)
                ,  INT32_C(          0),  INT32_C(          3),  INT32_C(          0),  INT32_C(          0)
                ,  INT32_C(          0),  INT32_C(          0),  INT32_C(          0),  INT32_C(          2)
                ,  INT32_C(          1),  INT32_C(          0),  INT32_C(          1),  INT32_C(          0)
                ,  INT32_C(          3),  INT32_C(          0),  INT32_C(          2),  INT32_C(          0)
                ,  INT32_C(          4),  INT32_C(          3),  INT32_C(          0),  INT32_C(          1) } },
    {      /* a */ { INT32_C( 1844162019), -INT32_C(  676753368),  INT32_C(  398937531), -INT32_C( 1101604271)
                ,  INT32_C(  280027882), -INT32_C(  519380041), -INT32_C(  880170021), -INT32_C( 1720881473)
                ,  INT32_C( 1205868537), -INT32_C( 2084477715), -INT32_C( 1130133540),  INT32_C(  553733684)
                , -INT32_C(  457046650), -INT32_C( 1553836662), -INT32_C(  913643263),  INT32_C( 1107100105)
                ,  INT32_C(  754518883),  INT32_C(  503518298),  INT32_C( 1200926843),  INT32_C( 1847387445)
                ,  INT32_C(  505255457), -INT32_C(   73247466),  INT32_C( 1072376665),  INT32_C( 1974699223)
                ,  INT32_C( 1635134580),  INT32_C( 1548126038), -INT32_C(  428649212),  INT32_C( 1285052851)
                ,  INT32_C( 2005469060), -INT32_C( 1119234398), -INT32_C(  646473738), -INT32_C(  396220227) },
      /* r */ { INT32_C(          0),  INT32_C(          1),  INT32_C(          2),  INT32_C(          0)
                ,  INT32_C(          2),  INT32_C(          2),  INT32_C(          1),  INT32_C(          0)
                ,  INT32_C(          0),  INT32_C(          0),  INT32_C(          0),  INT32_C(          1)
                ,  INT32_C(          2),  INT32_C(          0),  INT32_C(          1),  INT32_C(          0)
                ,  INT32_C(          1),  INT32_C(          2),  INT32_C(          0),  INT32_C(          0)
                ,  INT32_C(          2),  INT32_C(          4),  INT32_C(          1),  INT32_C(          0)
                ,  INT32_C(          0),  INT32_C(          0),  INT32_C(          2),  INT32_C(          0)
                ,  INT32_C(          0),  INT32_C(          0),  INT32_C(          1),  INT32_C(          2) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t r = simde_Q6_Vw_vnormamt_Vw(a);
    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vnormamt_Vh)
SIMDE_TEST_FUNC_LIST_ENTRY(vnormamt_Vw)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
