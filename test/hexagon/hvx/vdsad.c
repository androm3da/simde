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

#define SIMDE_TEST_HEXAGON_HVX_INSN vdsad

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vdsad.h"

static int
test_simde_vdsad_WuhRuh(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[128]; uint32_t rt; uint32_t r[64];
  } test_vec[] = {
    {      /* a */ {UINT16_C( 1092), UINT16_C(56170), UINT16_C(32930), UINT16_C(47139), UINT16_C(50645), UINT16_C(55747), UINT16_C(31781), UINT16_C( 4009)
                , UINT16_C(23767), UINT16_C(29979), UINT16_C(60971), UINT16_C( 1332), UINT16_C(10367), UINT16_C(18043), UINT16_C(19313), UINT16_C(41647)
                , UINT16_C(14579), UINT16_C(63340), UINT16_C(46075), UINT16_C(53923), UINT16_C(  830), UINT16_C(14663), UINT16_C(41056), UINT16_C(53583)
                , UINT16_C(  813), UINT16_C(32551), UINT16_C(  127), UINT16_C(36414), UINT16_C(64292), UINT16_C(45605), UINT16_C(53696), UINT16_C(51681)
                , UINT16_C(18665), UINT16_C(23541), UINT16_C(36651), UINT16_C(59819), UINT16_C(14527), UINT16_C(19265), UINT16_C(61320), UINT16_C(57705)
                , UINT16_C(10626), UINT16_C(41133), UINT16_C(42863), UINT16_C(38903), UINT16_C(38298), UINT16_C(50612), UINT16_C(27772), UINT16_C(46595)
                , UINT16_C(45342), UINT16_C(23970), UINT16_C(47424), UINT16_C(55011), UINT16_C( 7019), UINT16_C(38668), UINT16_C(47493), UINT16_C(41831)
                , UINT16_C(18402), UINT16_C(64972), UINT16_C(13748), UINT16_C(53753), UINT16_C(64673), UINT16_C(14824), UINT16_C(27940), UINT16_C(39582)
                , UINT16_C(25557), UINT16_C(16559), UINT16_C(40324), UINT16_C(59673), UINT16_C(  519), UINT16_C(59450), UINT16_C(48498), UINT16_C( 6536)
                , UINT16_C(56950), UINT16_C( 1867), UINT16_C(39350), UINT16_C(18528), UINT16_C(45747), UINT16_C(52942), UINT16_C(56384), UINT16_C(26561)
                , UINT16_C(56546), UINT16_C( 4584), UINT16_C(44031), UINT16_C(39444), UINT16_C(63063), UINT16_C( 9406), UINT16_C( 9444), UINT16_C( 5706)
                , UINT16_C(25715), UINT16_C(19651), UINT16_C(59865), UINT16_C( 5810), UINT16_C(57484), UINT16_C(18980), UINT16_C(37366), UINT16_C(46314)
                , UINT16_C(36999), UINT16_C(48212), UINT16_C(48331), UINT16_C(25282), UINT16_C(23092), UINT16_C(58270), UINT16_C(31608), UINT16_C(15529)
                , UINT16_C(14448), UINT16_C(32121), UINT16_C(28406), UINT16_C( 5622), UINT16_C(33138), UINT16_C(13060), UINT16_C(53445), UINT16_C(21552)
                , UINT16_C(18990), UINT16_C(54989), UINT16_C(26964), UINT16_C(61647), UINT16_C(27365), UINT16_C(63266), UINT16_C(52104), UINT16_C(60276)
                , UINT16_C(47631), UINT16_C(22920), UINT16_C(32224), UINT16_C(40944), UINT16_C(61387), UINT16_C(46680), UINT16_C( 5205), UINT16_C(58200) },
      /* rt */ UINT32_C(1170269666),
      /* r */ {UINT32_C(     96072), UINT32_C(     55203), UINT32_C(     46096), UINT32_C(     40916)
                , UINT32_C(     47206), UINT32_C(     18645), UINT32_C(     48670), UINT32_C(     63328)
                , UINT32_C(     89755), UINT32_C(     48842), UINT32_C(     61213), UINT32_C(     53521)
                , UINT32_C(     72732), UINT32_C(     77281), UINT32_C(     33191), UINT32_C(     38979)
                , UINT32_C(     45870), UINT32_C(     64162), UINT32_C(     45732), UINT32_C(     42319)
                , UINT32_C(     71501), UINT32_C(     37034), UINT32_C(     53308), UINT32_C(     59817)
                , UINT32_C(     19622), UINT32_C(     48581), UINT32_C(     72643), UINT32_C(     35332)
                , UINT32_C(     87564), UINT32_C(     80999), UINT32_C(      8855), UINT32_C(     52636)
                , UINT32_C(     10381), UINT32_C(     34179), UINT32_C(     20440), UINT32_C(     85483)
                , UINT32_C(     67965), UINT32_C(     79012), UINT32_C(     68698), UINT32_C(     55731)
                , UINT32_C(     43180), UINT32_C(     31102), UINT32_C(     89394), UINT32_C(     13679)
                , UINT32_C(     34158), UINT32_C(     64445), UINT32_C(     52873), UINT32_C(     26679)
                , UINT32_C(     54452), UINT32_C(     31444), UINT32_C(     44821), UINT32_C(     14897)
                , UINT32_C(     21125), UINT32_C(     30497), UINT32_C(     23520), UINT32_C(     47844)
                , UINT32_C(     36014), UINT32_C(     12947), UINT32_C(     29691), UINT32_C(     51267)
                , UINT32_C(     35897), UINT32_C(     19465), UINT32_C(     87557), UINT32_C(     31919) } },
    {      /* a */ {UINT16_C(16321), UINT16_C(16474), UINT16_C( 9828), UINT16_C(43524), UINT16_C(  540), UINT16_C(55582), UINT16_C(38773), UINT16_C(64655)
                , UINT16_C(48816), UINT16_C( 1790), UINT16_C(58314), UINT16_C(17250), UINT16_C(12300), UINT16_C(29314), UINT16_C(34825), UINT16_C(57028)
                , UINT16_C(29915), UINT16_C(29599), UINT16_C( 9195), UINT16_C(51499), UINT16_C(64077), UINT16_C(24445), UINT16_C(41637), UINT16_C(63258)
                , UINT16_C(30120), UINT16_C(45942), UINT16_C(58714), UINT16_C(10273), UINT16_C(51841), UINT16_C(10280), UINT16_C(27653), UINT16_C(18958)
                , UINT16_C(50408), UINT16_C( 6229), UINT16_C(58710), UINT16_C(18853), UINT16_C(46472), UINT16_C(22312), UINT16_C( 8242), UINT16_C(50730)
                , UINT16_C(35901), UINT16_C(15028), UINT16_C(29799), UINT16_C(40150), UINT16_C(21375), UINT16_C(58444), UINT16_C(23991), UINT16_C(30202)
                , UINT16_C( 5381), UINT16_C(33112), UINT16_C(61378), UINT16_C(50522), UINT16_C(40053), UINT16_C(50050), UINT16_C(22680), UINT16_C(24967)
                , UINT16_C(33494), UINT16_C(21516), UINT16_C(56630), UINT16_C(16724), UINT16_C(51218), UINT16_C(56772), UINT16_C(25515), UINT16_C( 2640)
                , UINT16_C(  532), UINT16_C(59152), UINT16_C(49746), UINT16_C(43722), UINT16_C( 9084), UINT16_C(64917), UINT16_C(29311), UINT16_C(11987)
                , UINT16_C(46197), UINT16_C(43458), UINT16_C(20379), UINT16_C(30456), UINT16_C(45670), UINT16_C(48741), UINT16_C(12895), UINT16_C( 9249)
                , UINT16_C( 8459), UINT16_C(61859), UINT16_C(57803), UINT16_C(18998), UINT16_C(18577), UINT16_C(26187), UINT16_C(20020), UINT16_C(42767)
                , UINT16_C(50787), UINT16_C(  407), UINT16_C( 1242), UINT16_C(22551), UINT16_C(46597), UINT16_C(59122), UINT16_C(15731), UINT16_C(64590)
                , UINT16_C(47955), UINT16_C(18529), UINT16_C(23968), UINT16_C(41092), UINT16_C(12795), UINT16_C(37248), UINT16_C(63188), UINT16_C(46334)
                , UINT16_C(37663), UINT16_C(15373), UINT16_C(10895), UINT16_C(57374), UINT16_C(48598), UINT16_C(15322), UINT16_C(32622), UINT16_C(24677)
                , UINT16_C(47787), UINT16_C(48864), UINT16_C(52824), UINT16_C(39211), UINT16_C(11045), UINT16_C(21991), UINT16_C(30073), UINT16_C(17839)
                , UINT16_C(33227), UINT16_C(46187), UINT16_C(51462), UINT16_C( 5283), UINT16_C(36910), UINT16_C(14450), UINT16_C( 3367), UINT16_C(49784) },
      /* rt */ UINT32_C(3254359504),
      /* r */ {UINT32_C(     55214), UINT32_C(     34657), UINT32_C(     43737), UINT32_C(     15419)
                , UINT32_C(     58331), UINT32_C(     52369), UINT32_C(     46395), UINT32_C(     10898)
                , UINT32_C(     28495), UINT32_C(     30999), UINT32_C(     50937), UINT32_C(     16886)
                , UINT32_C(     11947), UINT32_C(     59746), UINT32_C(     52866), UINT32_C(     41398)
                , UINT32_C(     55484), UINT32_C(     51162), UINT32_C(     35465), UINT32_C(     31183)
                , UINT32_C(     37080), UINT32_C(     18060), UINT32_C(     25764), UINT32_C(     33816)
                , UINT32_C(     49516), UINT32_C(     23891), UINT32_C(      2094), UINT32_C(     40362)
                , UINT32_C(     32999), UINT32_C(     51211), UINT32_C(     19981), UINT32_C(     59854)
                , UINT32_C(     71003), UINT32_C(      5261), UINT32_C(     57803), UINT32_C(     46649)
                , UINT32_C(     40022), UINT32_C(     50380), UINT32_C(     13025), UINT32_C(     55438)
                , UINT32_C(     49951), UINT32_C(     21293), UINT32_C(     44987), UINT32_C(     54543)
                , UINT32_C(      8720), UINT32_C(     76494), UINT32_C(     31132), UINT32_C(     53320)
                , UINT32_C(     33825), UINT32_C(     45188), UINT32_C(     52902), UINT32_C(     25909)
                , UINT32_C(     35318), UINT32_C(     40560), UINT32_C(     21151), UINT32_C(     25185)
                , UINT32_C(      7110), UINT32_C(     15337), UINT32_C(     50310), UINT32_C(     32969)
                , UINT32_C(     33266), UINT32_C(     23433), UINT32_C(     31167), UINT32_C(     82002) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    for (size_t base = 0 ; base < 64 ; base += SIMDE_HVX_VECTOR_I16_COUNT) {
      simde_hvx_vectorpair_private a_;
      simde_memcpy(&a_, test_vec[i].a + base, SIMDE_HVX_VECTOR_SIZE);
      simde_memcpy(HEDLEY_REINTERPRET_CAST(uint8_t*, &a_) + SIMDE_HVX_VECTOR_SIZE, test_vec[i].a + 64 + base, SIMDE_HVX_VECTOR_SIZE);
      simde_hvx_vectorpair_t rr = simde_Q6_Wuw_vdsad_WuhRuh(simde_hvx_vectorpair_from_private(a_), (int32_t)test_vec[i].rt);
      simde_hvx_vectorpair_private rr_ = simde_hvx_vectorpair_to_private(rr);
      for (size_t j = 0 ; j < SIMDE_HVX_VECTOR_I32_COUNT ; j++) {
        simde_assert_equal_u32(rr_.u32[j], test_vec[i].r[(base / 2) + j]);
        simde_assert_equal_u32(rr_.u32[SIMDE_HVX_VECTOR_I32_COUNT + j], test_vec[i].r[32 + (base / 2) + j]);
      }
    }
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vdsad_WuhRuh)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
