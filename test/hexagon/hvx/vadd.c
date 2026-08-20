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

#define SIMDE_TEST_HEXAGON_HVX_INSN vadd

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vadd.h"

static int
test_simde_vadd_VbVb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int8_t r[128];
  } test_vec[] = {
    { /* a */ { -INT8_C(  84), -INT8_C(  32),  INT8_C(  37),  INT8_C(  71),  INT8_C(  52),  INT8_C(  89), -INT8_C( 124),  INT8_C(  78),
                INT8_C( 120),  INT8_C(   6),  INT8_C(  85),  INT8_C(  88),  INT8_C(  20),  INT8_C(  13), -INT8_C(   9), -INT8_C(  97),
               -INT8_C(  10),  INT8_C(  50),  INT8_C(  33),  INT8_C(  44), -INT8_C(  55),  INT8_C(  12),  INT8_C(  99),  INT8_C( 100),
                INT8_C(  27),  INT8_C(  63), -INT8_C( 120),  INT8_C(  55), -INT8_C(  33),  INT8_C(  14),  INT8_C(  70),  INT8_C(  18),
                INT8_C(   3),  INT8_C(  90), -INT8_C(  50),  INT8_C(  80), -INT8_C(  44),  INT8_C( 125),  INT8_C(  56),  INT8_C(  22),
                INT8_C(  38), -INT8_C(  93), -INT8_C( 120),  INT8_C(  75),  INT8_C(  40), -INT8_C(  26),  INT8_C(  11),  INT8_C(  83),
               -INT8_C(  67),  INT8_C(  88), -INT8_C( 111), -INT8_C( 115),  INT8_C( 108),  INT8_C(   5),  INT8_C(  63),  INT8_C(  99),
                INT8_C(  67), -INT8_C(  89),  INT8_C(  46), -INT8_C(  57), -INT8_C( 109), -INT8_C(  43), -INT8_C(  56),  INT8_C(  34),
               -INT8_C(  78),  INT8_C(  29), -INT8_C(  91),  INT8_C(  62),  INT8_C(  15), -INT8_C(   3),  INT8_C(  54), -INT8_C(  18),
               -INT8_C( 113),  INT8_C( 101),  INT8_C(  39), -INT8_C( 100), -INT8_C(  28),  INT8_C(  74),  INT8_C(  60),  INT8_C(  93),
                INT8_C( 117),  INT8_C(  45), -INT8_C(  91),  INT8_C(  57),  INT8_C(  22),  INT8_C( 120),  INT8_C(  69),  INT8_C(  31),
                INT8_C(  58),  INT8_C(  14), -INT8_C(  87), -INT8_C(  45), -INT8_C(  62),  INT8_C(   9),  INT8_C( 115),  INT8_C(  60),
                INT8_C(  52),  INT8_C( 104), -INT8_C(  50),  INT8_C(  72), -INT8_C(  91),  INT8_C( 116),  INT8_C(  35),  INT8_C(  64),
               -INT8_C(  30),  INT8_C(  44),  INT8_C(  76), -INT8_C(  25),  INT8_C( 118), -INT8_C(  83), -INT8_C(  22),  INT8_C(  81),
                INT8_C(  95), -INT8_C( 112),  INT8_C(  87), -INT8_C(  60), -INT8_C(  40),  INT8_C(  89), -INT8_C( 119),  INT8_C(  40),
                INT8_C(  75),  INT8_C(   8), -INT8_C(  80),  INT8_C(  51),  INT8_C( 100), -INT8_C(  37), -INT8_C(  49),  INT8_C(  11) },
      /* b */ { -INT8_C(  96), -INT8_C( 120),  INT8_C(  98), -INT8_C(  45),  INT8_C(   2),  INT8_C(  20),  INT8_C( 115), -INT8_C(   7),
                INT8_C(  61),  INT8_C(  95),  INT8_C(  52), -INT8_C(  19),  INT8_C(   0),  INT8_C(  96),  INT8_C(  90), -INT8_C(  83),
                INT8_C(  63), -INT8_C(  22),  INT8_C(  81),  INT8_C(  35),  INT8_C(  77), -INT8_C( 100),  INT8_C(  55), -INT8_C(  91),
               -INT8_C(  14),  INT8_C(  72),  INT8_C(  33), -INT8_C(  33),  INT8_C(  89),  INT8_C(  55), -INT8_C(  41),  INT8_C(  97),
               -INT8_C(  83),  INT8_C(  32),  INT8_C(  59), -INT8_C(  47),  INT8_C(  98), -INT8_C(  67),  INT8_C(  10), -INT8_C(  95),
                INT8_C(  12),  INT8_C( 110), -INT8_C(  50), -INT8_C(  33),  INT8_C( 108), -INT8_C(  18),  INT8_C(  44),  INT8_C(  92),
                INT8_C(  33), -INT8_C( 101), -INT8_C(   2),  INT8_C(  70), -INT8_C(  73),  INT8_C( 126), -INT8_C(  95), -INT8_C(  35),
               -INT8_C(  12),  INT8_C(  19),  INT8_C( 113),  INT8_C( 113),  INT8_C(  49),  INT8_C(   8), -INT8_C(  86),  INT8_C(  72),
                INT8_C(  16),  INT8_C( 107),  INT8_C(  63),  INT8_C(  29), -INT8_C(  55),  INT8_C(  99),  INT8_C(  22), -INT8_C(  40),
                INT8_C(  58), -INT8_C(  82),  INT8_C(  17), -INT8_C(   4),  INT8_C(  87),  INT8_C(  37), -INT8_C(  76), -INT8_C(  20),
               -INT8_C(  70), -INT8_C(  89),  INT8_C( 101), -INT8_C(  20), -INT8_C(  67), -INT8_C(  59),  INT8_C( 114),  INT8_C(  43),
                INT8_C(  17), -INT8_C(  77),  INT8_C(  35), -INT8_C(  85),  INT8_C( 124), -INT8_C(  91), -INT8_C( 103), -INT8_C( 114),
               -INT8_C(  81),  INT8_C(  35), -INT8_C(  34),  INT8_C(  27), -INT8_C( 115),  INT8_C(  75), -INT8_C(  41), -INT8_C(  49),
                INT8_C(  72), -INT8_C(  31), -INT8_C(  56),  INT8_C( 103),  INT8_C(  66),  INT8_C(  24), -INT8_C(  90),  INT8_C(  16),
               -INT8_C(  45), -INT8_C(  39), -INT8_C( 109), -INT8_C(  77),  INT8_C(  23),  INT8_C(  71), -INT8_C(  53),  INT8_C(  19),
               -INT8_C(  21),  INT8_C( 101), -INT8_C(  93),  INT8_C(  22),  INT8_C(  39),  INT8_C(  47), -INT8_C(  54),  INT8_C(  88) },
      /* r */ {  INT8_C(  76),  INT8_C( 104), -INT8_C( 121),  INT8_C(  26),  INT8_C(  54),  INT8_C( 109), -INT8_C(   9),  INT8_C(  71),
               -INT8_C(  75),  INT8_C( 101), -INT8_C( 119),  INT8_C(  69),  INT8_C(  20),  INT8_C( 109),  INT8_C(  81),  INT8_C(  76),
                INT8_C(  53),  INT8_C(  28),  INT8_C( 114),  INT8_C(  79),  INT8_C(  22), -INT8_C(  88), -INT8_C( 102),  INT8_C(   9),
                INT8_C(  13), -INT8_C( 121), -INT8_C(  87),  INT8_C(  22),  INT8_C(  56),  INT8_C(  69),  INT8_C(  29),  INT8_C( 115),
               -INT8_C(  80),  INT8_C( 122),  INT8_C(   9),  INT8_C(  33),  INT8_C(  54),  INT8_C(  58),  INT8_C(  66), -INT8_C(  73),
                INT8_C(  50),  INT8_C(  17),  INT8_C(  86),  INT8_C(  42), -INT8_C( 108), -INT8_C(  44),  INT8_C(  55), -INT8_C(  81),
               -INT8_C(  34), -INT8_C(  13), -INT8_C( 113), -INT8_C(  45),  INT8_C(  35), -INT8_C( 125), -INT8_C(  32),  INT8_C(  64),
                INT8_C(  55), -INT8_C(  70), -INT8_C(  97),  INT8_C(  56), -INT8_C(  60), -INT8_C(  35),  INT8_C( 114),  INT8_C( 106),
               -INT8_C(  62), -INT8_C( 120), -INT8_C(  28),  INT8_C(  91), -INT8_C(  40),  INT8_C(  96),  INT8_C(  76), -INT8_C(  58),
               -INT8_C(  55),  INT8_C(  19),  INT8_C(  56), -INT8_C( 104),  INT8_C(  59),  INT8_C( 111), -INT8_C(  16),  INT8_C(  73),
                INT8_C(  47), -INT8_C(  44),  INT8_C(  10),  INT8_C(  37), -INT8_C(  45),  INT8_C(  61), -INT8_C(  73),  INT8_C(  74),
                INT8_C(  75), -INT8_C(  63), -INT8_C(  52),  INT8_C( 126),  INT8_C(  62), -INT8_C(  82),  INT8_C(  12), -INT8_C(  54),
               -INT8_C(  29), -INT8_C( 117), -INT8_C(  84),  INT8_C(  99),  INT8_C(  50), -INT8_C(  65), -INT8_C(   6),  INT8_C(  15),
                INT8_C(  42),  INT8_C(  13),  INT8_C(  20),  INT8_C(  78), -INT8_C(  72), -INT8_C(  59), -INT8_C( 112),  INT8_C(  97),
                INT8_C(  50),  INT8_C( 105), -INT8_C(  22),  INT8_C( 119), -INT8_C(  17), -INT8_C(  96),  INT8_C(  84),  INT8_C(  59),
                INT8_C(  54),  INT8_C( 109),  INT8_C(  83),  INT8_C(  73), -INT8_C( 117),  INT8_C(  10), -INT8_C( 103),  INT8_C(  99) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vb_vadd_VbVb(a, b);

    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_random();
    simde_hvx_vector_t b = simde_test_hvx_vector_random();
    simde_hvx_vector_t r = simde_Q6_Vb_vadd_VbVb(a, b);

    simde_test_hvx_vector_i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VhVh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[64];
    int16_t b[64];
    int16_t r[64];
  } test_vec[] = {
    { /* a */ { -INT16_C( 30997), -INT16_C(  1599), -INT16_C( 12412), -INT16_C(   899), -INT16_C(  5872), -INT16_C( 18922),  INT16_C(  5928), -INT16_C( 31405),
                INT16_C( 13372), -INT16_C( 16268), -INT16_C(  3837),  INT16_C(  5052), -INT16_C( 11301),  INT16_C(   969),  INT16_C(  7402), -INT16_C( 21368),
               -INT16_C(   110), -INT16_C( 27189), -INT16_C( 30480), -INT16_C( 13400),  INT16_C( 29019),  INT16_C( 17871),  INT16_C( 22414),  INT16_C( 23026),
                INT16_C( 13192),  INT16_C( 30817),  INT16_C(  2491),  INT16_C(  5700),  INT16_C(  4987),  INT16_C(  2395),  INT16_C( 19818),  INT16_C( 15202),
                INT16_C( 26096), -INT16_C( 21518),  INT16_C( 13934), -INT16_C(  5695),  INT16_C(  7241), -INT16_C( 19214),  INT16_C( 21610),  INT16_C( 31215),
                INT16_C( 10732),  INT16_C( 23131),  INT16_C(  7263), -INT16_C( 22204),  INT16_C( 13880), -INT16_C( 23971),  INT16_C( 19595), -INT16_C( 11236),
                INT16_C(  1114), -INT16_C( 17832), -INT16_C( 25568),  INT16_C( 22883), -INT16_C( 16173),  INT16_C( 24315),  INT16_C(  5900),  INT16_C( 32562),
                INT16_C( 14547), -INT16_C(  3299), -INT16_C( 32556), -INT16_C( 22708),  INT16_C( 18496),  INT16_C( 19717),  INT16_C( 14431), -INT16_C( 30260) },
      /* b */ { -INT16_C( 20798),  INT16_C(  9201), -INT16_C( 20369), -INT16_C( 22053), -INT16_C( 10807), -INT16_C(  1995), -INT16_C( 18801),  INT16_C( 31602),
                INT16_C( 31179),  INT16_C( 15056), -INT16_C( 21718), -INT16_C(  3101),  INT16_C(  6272),  INT16_C(  4332),  INT16_C( 24270),  INT16_C(  2955),
               -INT16_C( 15663), -INT16_C(  1133),  INT16_C( 30317), -INT16_C(  4370), -INT16_C(  9586),  INT16_C( 23806), -INT16_C( 30407), -INT16_C( 13465),
               -INT16_C(  2801),  INT16_C( 32054),  INT16_C(  9579), -INT16_C(  1685),  INT16_C( 27135),  INT16_C( 14421), -INT16_C( 16910),  INT16_C( 31236),
                INT16_C(  9801), -INT16_C( 19210),  INT16_C( 24907),  INT16_C( 19117),  INT16_C(   970), -INT16_C( 17277), -INT16_C( 30784), -INT16_C( 20426),
                INT16_C(  4722), -INT16_C( 17015),  INT16_C( 13940),  INT16_C( 15880), -INT16_C( 29895), -INT16_C(  1541),  INT16_C( 12562), -INT16_C(   343),
               -INT16_C( 17622), -INT16_C( 25028),  INT16_C( 17650),  INT16_C( 11228), -INT16_C( 10289), -INT16_C(  7899), -INT16_C( 12791),  INT16_C( 25567),
                INT16_C(  2291), -INT16_C(  6873),  INT16_C(  1101),  INT16_C(  7185),  INT16_C( 14043), -INT16_C(  6914), -INT16_C(  8956), -INT16_C( 10424) },
      /* r */ {  INT16_C( 13741),  INT16_C(  7602),  INT16_C( 32755), -INT16_C( 22952), -INT16_C( 16679), -INT16_C( 20917), -INT16_C( 12873),  INT16_C(   197),
               -INT16_C( 20985), -INT16_C(  1212), -INT16_C( 25555),  INT16_C(  1951), -INT16_C(  5029),  INT16_C(  5301),  INT16_C( 31672), -INT16_C( 18413),
               -INT16_C( 15773), -INT16_C( 28322), -INT16_C(   163), -INT16_C( 17770),  INT16_C( 19433), -INT16_C( 23859), -INT16_C(  7993),  INT16_C(  9561),
                INT16_C( 10391), -INT16_C(  2665),  INT16_C( 12070),  INT16_C(  4015),  INT16_C( 32122),  INT16_C( 16816),  INT16_C(  2908), -INT16_C( 19098),
               -INT16_C( 29639),  INT16_C( 24808), -INT16_C( 26695),  INT16_C( 13422),  INT16_C(  8211),  INT16_C( 29045), -INT16_C(  9174),  INT16_C( 10789),
                INT16_C( 15454),  INT16_C(  6116),  INT16_C( 21203), -INT16_C(  6324), -INT16_C( 16015), -INT16_C( 25512),  INT16_C( 32157), -INT16_C( 11579),
               -INT16_C( 16508),  INT16_C( 22676), -INT16_C(  7918), -INT16_C( 31425), -INT16_C( 26462),  INT16_C( 16416), -INT16_C(  6891), -INT16_C(  7407),
                INT16_C( 16838), -INT16_C( 10172), -INT16_C( 31455), -INT16_C( 15523),  INT16_C( 32539),  INT16_C( 12803),  INT16_C(  5475),  INT16_C( 24852) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vh_vadd_VhVh(a, b);

    simde_test_hvx_vector_i16_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_random();
    simde_hvx_vector_t b = simde_test_hvx_vector_random();
    simde_hvx_vector_t r = simde_Q6_Vh_vadd_VhVh(a, b);

    simde_test_hvx_vector_i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VwVw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[32];
    int32_t b[32];
    int32_t r[32];
  } test_vec[] = {
    { /* a */ {  INT32_C(  1971869139),  INT32_C(  1122487640), -INT32_C(   505886277),  INT32_C(   974474570),
                 INT32_C(  1972210716),  INT32_C(   347567193), -INT32_C(  2013884611),  INT32_C(  1824590813),
                 INT32_C(  2143379493),  INT32_C(   294877396), -INT32_C(   459699961),  INT32_C(  1162893972),
                -INT32_C(  1175916315),  INT32_C(  1875606632), -INT32_C(  1705745403), -INT32_C(    35674946),
                 INT32_C(   349359276),  INT32_C(  1300536648), -INT32_C(  1058547711),  INT32_C(   129877884),
                 INT32_C(  1679809820),  INT32_C(  2092082043), -INT32_C(   147023493), -INT32_C(   738264480),
                 INT32_C(   807041461), -INT32_C(  1750217700), -INT32_C(   963647130),  INT32_C(   261721571),
                 INT32_C(  1495238460), -INT32_C(  1158624172), -INT32_C(  1719631947), -INT32_C(  1448601075) },
      /* b */ {  INT32_C(   690202255), -INT32_C(   117222443), -INT32_C(   169288089),  INT32_C(   402966340),
                -INT32_C(  2036996943), -INT32_C(  1619027912), -INT32_C(  1147901833),  INT32_C(  1288935727),
                 INT32_C(  2009916991), -INT32_C(   183088258), -INT32_C(   474895437),  INT32_C(  1764721732),
                 INT32_C(   158641034), -INT32_C(  1426158601),  INT32_C(  2056105782),  INT32_C(   434355252),
                 INT32_C(  1762669170), -INT32_C(   216789315), -INT32_C(   227696194),  INT32_C(   168513630),
                -INT32_C(   381940180), -INT32_C(   606318563),  INT32_C(  1355631090), -INT32_C(  1235560295),
                -INT32_C(  1174874468),  INT32_C(   412406822), -INT32_C(  1217896163), -INT32_C(   294796487),
                 INT32_C(   375562736), -INT32_C(  1825573259), -INT32_C(  1874159785), -INT32_C(  1753303206) },
      /* r */ { -INT32_C(  1632895902),  INT32_C(  1005265197), -INT32_C(   675174366),  INT32_C(  1377440910),
                -INT32_C(    64786227), -INT32_C(  1271460719),  INT32_C(  1133180852), -INT32_C(  1181440756),
                -INT32_C(   141670812),  INT32_C(   111789138), -INT32_C(   934595398), -INT32_C(  1367351592),
                -INT32_C(  1017275281),  INT32_C(   449448031),  INT32_C(   350360379),  INT32_C(   398680306),
                 INT32_C(  2112028446),  INT32_C(  1083747333), -INT32_C(  1286243905),  INT32_C(   298391514),
                 INT32_C(  1297869640),  INT32_C(  1485763480),  INT32_C(  1208607597), -INT32_C(  1973824775),
                -INT32_C(   367833007), -INT32_C(  1337810878),  INT32_C(  2113424003), -INT32_C(    33074916),
                 INT32_C(  1870801196),  INT32_C(  1310769865),  INT32_C(   701175564),  INT32_C(  1093063015) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_VwVw(a, b);

    simde_test_hvx_vector_i32_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_random();
    simde_hvx_vector_t b = simde_test_hvx_vector_random();
    simde_hvx_vector_t r = simde_Q6_Vw_vadd_VwVw(a, b);

    simde_test_hvx_vector_i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_VubVub_sat(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[128];
    uint8_t b[128];
    uint8_t r[128];
  } test_vec[] = {
    { /* a */ { UINT8_C(200), UINT8_C(100), UINT8_C(  0), UINT8_C(255), UINT8_C(128), UINT8_C( 50), UINT8_C(200), UINT8_C(127),
                UINT8_C(  1), UINT8_C(254), UINT8_C(127), UINT8_C( 64), UINT8_C(192), UINT8_C( 33), UINT8_C(250), UINT8_C(  5),
                UINT8_C(200), UINT8_C(100), UINT8_C(  0), UINT8_C(255), UINT8_C(128), UINT8_C( 50), UINT8_C(200), UINT8_C(127),
                UINT8_C(  1), UINT8_C(254), UINT8_C(127), UINT8_C( 64), UINT8_C(192), UINT8_C( 33), UINT8_C(250), UINT8_C(  5),
                UINT8_C(200), UINT8_C(100), UINT8_C(  0), UINT8_C(255), UINT8_C(128), UINT8_C( 50), UINT8_C(200), UINT8_C(127),
                UINT8_C(  1), UINT8_C(254), UINT8_C(127), UINT8_C( 64), UINT8_C(192), UINT8_C( 33), UINT8_C(250), UINT8_C(  5),
                UINT8_C(200), UINT8_C(100), UINT8_C(  0), UINT8_C(255), UINT8_C(128), UINT8_C( 50), UINT8_C(200), UINT8_C(127),
                UINT8_C(  1), UINT8_C(254), UINT8_C(127), UINT8_C( 64), UINT8_C(192), UINT8_C( 33), UINT8_C(250), UINT8_C(  5),
                UINT8_C(200), UINT8_C(100), UINT8_C(  0), UINT8_C(255), UINT8_C(128), UINT8_C( 50), UINT8_C(200), UINT8_C(127),
                UINT8_C(  1), UINT8_C(254), UINT8_C(127), UINT8_C( 64), UINT8_C(192), UINT8_C( 33), UINT8_C(250), UINT8_C(  5),
                UINT8_C(200), UINT8_C(100), UINT8_C(  0), UINT8_C(255), UINT8_C(128), UINT8_C( 50), UINT8_C(200), UINT8_C(127),
                UINT8_C(  1), UINT8_C(254), UINT8_C(127), UINT8_C( 64), UINT8_C(192), UINT8_C( 33), UINT8_C(250), UINT8_C(  5),
                UINT8_C(200), UINT8_C(100), UINT8_C(  0), UINT8_C(255), UINT8_C(128), UINT8_C( 50), UINT8_C(200), UINT8_C(127),
                UINT8_C(  1), UINT8_C(254), UINT8_C(127), UINT8_C( 64), UINT8_C(192), UINT8_C( 33), UINT8_C(250), UINT8_C(  5),
                UINT8_C(200), UINT8_C(100), UINT8_C(  0), UINT8_C(255), UINT8_C(128), UINT8_C( 50), UINT8_C(200), UINT8_C(127),
                UINT8_C(  1), UINT8_C(254), UINT8_C(127), UINT8_C( 64), UINT8_C(192), UINT8_C( 33), UINT8_C(250), UINT8_C(  5) },
      /* b */ { UINT8_C(100), UINT8_C(200), UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(200), UINT8_C( 56), UINT8_C(128),
                UINT8_C(  0), UINT8_C(  2), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(222), UINT8_C(  6), UINT8_C(250),
                UINT8_C(100), UINT8_C(200), UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(200), UINT8_C( 56), UINT8_C(128),
                UINT8_C(  0), UINT8_C(  2), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(222), UINT8_C(  6), UINT8_C(250),
                UINT8_C(100), UINT8_C(200), UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(200), UINT8_C( 56), UINT8_C(128),
                UINT8_C(  0), UINT8_C(  2), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(222), UINT8_C(  6), UINT8_C(250),
                UINT8_C(100), UINT8_C(200), UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(200), UINT8_C( 56), UINT8_C(128),
                UINT8_C(  0), UINT8_C(  2), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(222), UINT8_C(  6), UINT8_C(250),
                UINT8_C(100), UINT8_C(200), UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(200), UINT8_C( 56), UINT8_C(128),
                UINT8_C(  0), UINT8_C(  2), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(222), UINT8_C(  6), UINT8_C(250),
                UINT8_C(100), UINT8_C(200), UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(200), UINT8_C( 56), UINT8_C(128),
                UINT8_C(  0), UINT8_C(  2), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(222), UINT8_C(  6), UINT8_C(250),
                UINT8_C(100), UINT8_C(200), UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(200), UINT8_C( 56), UINT8_C(128),
                UINT8_C(  0), UINT8_C(  2), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(222), UINT8_C(  6), UINT8_C(250),
                UINT8_C(100), UINT8_C(200), UINT8_C(  0), UINT8_C(  1), UINT8_C(128), UINT8_C(200), UINT8_C( 56), UINT8_C(128),
                UINT8_C(  0), UINT8_C(  2), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(222), UINT8_C(  6), UINT8_C(250) },
      /* r */ { UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(250), UINT8_C(255), UINT8_C(255),
                UINT8_C(  1), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(250), UINT8_C(255), UINT8_C(255),
                UINT8_C(  1), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(250), UINT8_C(255), UINT8_C(255),
                UINT8_C(  1), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(250), UINT8_C(255), UINT8_C(255),
                UINT8_C(  1), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(250), UINT8_C(255), UINT8_C(255),
                UINT8_C(  1), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(250), UINT8_C(255), UINT8_C(255),
                UINT8_C(  1), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(250), UINT8_C(255), UINT8_C(255),
                UINT8_C(  1), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255),
                UINT8_C(255), UINT8_C(255), UINT8_C(  0), UINT8_C(255), UINT8_C(255), UINT8_C(250), UINT8_C(255), UINT8_C(255),
                UINT8_C(  1), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255), UINT8_C(255) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_load(test_vec[i].a);
    simde_hvx_vector_t b = simde_test_hvx_vector_load(test_vec[i].b);
    simde_hvx_vector_t r = simde_Q6_Vub_vadd_VubVub_sat(a, b);

    simde_test_hvx_vector_u8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_hvx_vector_t a = simde_test_hvx_vector_random();
    simde_hvx_vector_t b = simde_test_hvx_vector_random();
    simde_hvx_vector_t r = simde_Q6_Vub_vadd_VubVub_sat(a, b);

    simde_test_hvx_vector_u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hvx_vector_u8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hvx_vector_u8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vadd_high_risk(SIMDE_MUNIT_TEST_ARGS) {
  const int8_t sat_a[SIMDE_HVX_VECTOR_SIZE] = { 120, -120, 100, -100, 1, -1 };
  const int8_t sat_b[SIMDE_HVX_VECTOR_SIZE] = { 20, -20, 27, -28, -2, 2 };
  const int8_t sat_r[SIMDE_HVX_VECTOR_SIZE] = { 127, -128, 127, -128, -1, 1 };
  simde_test_hvx_vector_i8_assert_equal(
    simde_Q6_Vb_vadd_VbVb_sat(simde_test_hvx_vector_load(sat_a), simde_test_hvx_vector_load(sat_b)),
    simde_test_hvx_vector_load(sat_r));

  const uint32_t usat_a[SIMDE_HVX_VECTOR_I32_COUNT] = { UINT32_MAX, UINT32_MAX - 1, 100 };
  const uint32_t usat_b[SIMDE_HVX_VECTOR_I32_COUNT] = { 1, 1, UINT32_MAX };
  const uint32_t usat_r[SIMDE_HVX_VECTOR_I32_COUNT] = { UINT32_MAX, UINT32_MAX, UINT32_MAX };
  simde_test_hvx_vector_u32_assert_equal(
    simde_Q6_Vuw_vadd_VuwVuw_sat(simde_test_hvx_vector_load(usat_a), simde_test_hvx_vector_load(usat_b)),
    simde_test_hvx_vector_load(usat_r));

  const uint32_t carry_a[SIMDE_HVX_VECTOR_I32_COUNT] = { UINT32_MAX, UINT32_MAX, 16, 0 };
  const uint32_t carry_b[SIMDE_HVX_VECTOR_I32_COUNT] = { 0, 1, UINT32_MAX - 15, UINT32_MAX };
  const uint32_t carry_r[SIMDE_HVX_VECTOR_I32_COUNT] = { 0, 0, 0, UINT32_MAX };
  const uint8_t carry_in[SIMDE_HVX_VECTOR_SIZE] = { 0xff, 0xff, 0xff, 0xff };
  const uint8_t carry_out[SIMDE_HVX_VECTOR_SIZE] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff
  };
  simde_hvx_vectorpred_t q = simde_test_hvx_vectorpred_load(carry_in);
  simde_hvx_vector_t carry = simde_Q6_Vw_vadd_VwVwQ_carry(
    simde_test_hvx_vector_load(carry_a), simde_test_hvx_vector_load(carry_b), &q);
  simde_test_hvx_vector_u32_assert_equal(carry, simde_test_hvx_vector_load(carry_r));
  simde_test_hvx_vectorpred_u8_assert_equal(q, simde_test_hvx_vectorpred_load(carry_out));

  const uint16_t acc_lo[SIMDE_HVX_VECTOR_I16_COUNT] = { 100, 200 };
  const uint16_t acc_hi[SIMDE_HVX_VECTOR_I16_COUNT] = { 300, 400 };
  const uint8_t add_a[SIMDE_HVX_VECTOR_SIZE] = { 1, 2, 250, 4 };
  const uint8_t add_b[SIMDE_HVX_VECTOR_SIZE] = { 10, 20, 10, 40 };
  const uint16_t acc_lo_r[SIMDE_HVX_VECTOR_I16_COUNT] = { 111, 460 };
  const uint16_t acc_hi_r[SIMDE_HVX_VECTOR_I16_COUNT] = { 322, 444 };
  simde_hvx_vectorpair_t acc = simde_Q6_W_vcombine_VV(
    simde_test_hvx_vector_load(acc_hi), simde_test_hvx_vector_load(acc_lo));
  simde_hvx_vectorpair_t acc_r = simde_Q6_Wh_vaddacc_WhVubVub(
    acc, simde_test_hvx_vector_load(add_a), simde_test_hvx_vector_load(add_b));
  simde_test_hvx_vector_u16_assert_equal(simde_Q6_V_lo_W(acc_r), simde_test_hvx_vector_load(acc_lo_r));
  simde_test_hvx_vector_u16_assert_equal(simde_Q6_V_hi_W(acc_r), simde_test_hvx_vector_load(acc_hi_r));

  const uint16_t bf_a[SIMDE_HVX_VECTOR_I16_COUNT] = { 0x3fc0, 0xc000, 0x4040, 0x4080 };
  const uint16_t bf_b[SIMDE_HVX_VECTOR_I16_COUNT] = { 0x3f00, 0x3f00, 0x4120, 0xc000 };
  const float bf_lo_r[SIMDE_HVX_VECTOR_F32_COUNT] = { 2.0f, 13.0f };
  const float bf_hi_r[SIMDE_HVX_VECTOR_F32_COUNT] = { -1.5f, 2.0f };
  simde_hvx_vectorpair_t bf_r = simde_Q6_Wsf_vadd_VbfVbf(
    simde_test_hvx_vector_load(bf_a), simde_test_hvx_vector_load(bf_b));
  simde_test_hvx_vector_u32_assert_equal(simde_Q6_V_lo_W(bf_r), simde_test_hvx_vector_load(bf_lo_r));
  simde_test_hvx_vector_u32_assert_equal(simde_Q6_V_hi_W(bf_r), simde_test_hvx_vector_load(bf_hi_r));

  return 0;
}

static int
test_simde_vadd_VwVwQ_carry_sat(SIMDE_MUNIT_TEST_ARGS) {
  const int32_t a[SIMDE_HVX_VECTOR_I32_COUNT] = {
    INT32_MAX, INT32_MAX, INT32_MIN, INT32_MIN, INT32_MAX, INT32_MAX, 100, 100
  };
  const int32_t b[SIMDE_HVX_VECTOR_I32_COUNT] = {
    0, 0, -1, -1, INT32_MIN, INT32_MIN, -101, -101
  };
  const int32_t expected[SIMDE_HVX_VECTOR_I32_COUNT] = {
    INT32_MAX, INT32_MAX, INT32_MIN, INT32_MIN, -1, 0, -1, 0
  };
  uint8_t carry[SIMDE_HVX_VECTOR_SIZE] = { 0 };
  carry[4] = carry[12] = carry[20] = carry[28] = UINT8_MAX;

  simde_test_hvx_vector_i32_assert_equal(
    simde_Q6_Vw_vadd_VwVwQ_carry_sat(
      simde_test_hvx_vector_load(a), simde_test_hvx_vector_load(b),
      simde_test_hvx_vectorpred_load(carry)),
    simde_test_hvx_vector_load(expected));

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VbVb)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VhVh)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VwVw)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VubVub_sat)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_high_risk)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_VwVwQ_carry_sat)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
