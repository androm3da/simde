#define SIMDE_TEST_HEXAGON_HVX_INSN add

#include "../../../simde/hexagon/hvx/add.h"
#include "test-hvx.h"
#include <string.h>

static int test_simde_hvx_add_vb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int8_t r[128];
  } test_vec[] = {
      {{INT8_C(42),  INT8_C(-17), INT8_C(95),  INT8_C(-33), INT8_C(76),  INT8_C(-84), INT8_C(19),  INT8_C(-56), INT8_C(31),
        INT8_C(-92), INT8_C(63),  INT8_C(-48), INT8_C(87),  INT8_C(-25), INT8_C(74),  INT8_C(-61), INT8_C(28),  INT8_C(-39),
        INT8_C(102), INT8_C(-73), INT8_C(45),  INT8_C(-18), INT8_C(91),  INT8_C(-34), INT8_C(67),  INT8_C(-85), INT8_C(23),
        INT8_C(-52), INT8_C(78),  INT8_C(-29), INT8_C(64),  INT8_C(-41), INT8_C(35),  INT8_C(-96), INT8_C(59),  INT8_C(-44),
        INT8_C(83),  INT8_C(-21), INT8_C(70),  INT8_C(-57), INT8_C(26),  INT8_C(-88), INT8_C(98),  INT8_C(-69), INT8_C(41),
        INT8_C(-14), INT8_C(87),  INT8_C(-30), INT8_C(72),  INT8_C(-81), INT8_C(19),  INT8_C(-48), INT8_C(75),  INT8_C(-25),
        INT8_C(62),  INT8_C(-53), INT8_C(39),  INT8_C(-92), INT8_C(55),  INT8_C(-40), INT8_C(79),  INT8_C(-17), INT8_C(66),
        INT8_C(-37), INT8_C(32),  INT8_C(-99), INT8_C(51),  INT8_C(-36), INT8_C(85),  INT8_C(-13), INT8_C(68),  INT8_C(-49),
        INT8_C(24),  INT8_C(-90), INT8_C(94),  INT8_C(-61), INT8_C(37),  INT8_C(-10), INT8_C(83),  INT8_C(-26), INT8_C(76),
        INT8_C(-77), INT8_C(15),  INT8_C(-44), INT8_C(71),  INT8_C(-21), INT8_C(58),  INT8_C(-45), INT8_C(29),  INT8_C(-86),
        INT8_C(91),  INT8_C(-57), INT8_C(33),  INT8_C(-6),  INT8_C(79),  INT8_C(-22), INT8_C(68),  INT8_C(-73), INT8_C(11),
        INT8_C(-40), INT8_C(67),  INT8_C(-17), INT8_C(54),  INT8_C(-41), INT8_C(25),  INT8_C(-82), INT8_C(87),  INT8_C(-53),
        INT8_C(29),  INT8_C(-2),  INT8_C(75),  INT8_C(-18), INT8_C(64),  INT8_C(-69), INT8_C(7),   INT8_C(-36), INT8_C(63),
        INT8_C(-13), INT8_C(50),  INT8_C(-37), INT8_C(21),  INT8_C(-78), INT8_C(83),  INT8_C(-49), INT8_C(25),  INT8_C(-2),
        INT8_C(71),  INT8_C(-14)},
       {INT8_C(15),  INT8_C(-28), INT8_C(73),  INT8_C(-42), INT8_C(56),  INT8_C(-63), INT8_C(39),  INT8_C(-85), INT8_C(22),
        INT8_C(-71), INT8_C(84),  INT8_C(-37), INT8_C(68),  INT8_C(-14), INT8_C(55),  INT8_C(-80), INT8_C(17),  INT8_C(-58),
        INT8_C(81),  INT8_C(-52), INT8_C(64),  INT8_C(-37), INT8_C(70),  INT8_C(-53), INT8_C(46),  INT8_C(-64), INT8_C(42),
        INT8_C(-71), INT8_C(57),  INT8_C(-18), INT8_C(83),  INT8_C(-60), INT8_C(24),  INT8_C(-75), INT8_C(78),  INT8_C(-23),
        INT8_C(62),  INT8_C(-40), INT8_C(49),  INT8_C(-76), INT8_C(35),  INT8_C(-67), INT8_C(77),  INT8_C(-48), INT8_C(60),
        INT8_C(-33), INT8_C(66),  INT8_C(-49), INT8_C(51),  INT8_C(-60), INT8_C(38),  INT8_C(-67), INT8_C(54),  INT8_C(-44),
        INT8_C(41),  INT8_C(-72), INT8_C(28),  INT8_C(-71), INT8_C(74),  INT8_C(-19), INT8_C(58),  INT8_C(-36), INT8_C(45),
        INT8_C(-56), INT8_C(21),  INT8_C(-78), INT8_C(70),  INT8_C(-15), INT8_C(64),  INT8_C(-32), INT8_C(47),  INT8_C(-68),
        INT8_C(13),  INT8_C(-69), INT8_C(73),  INT8_C(-40), INT8_C(56),  INT8_C(-29), INT8_C(62),  INT8_C(-45), INT8_C(55),
        INT8_C(-56), INT8_C(34),  INT8_C(-23), INT8_C(50),  INT8_C(-40), INT8_C(37),  INT8_C(-64), INT8_C(18),  INT8_C(-65),
        INT8_C(70),  INT8_C(-36), INT8_C(52),  INT8_C(-25), INT8_C(58),  INT8_C(-41), INT8_C(47),  INT8_C(-52), INT8_C(30),
        INT8_C(-19), INT8_C(46),  INT8_C(-36), INT8_C(33),  INT8_C(-60), INT8_C(14),  INT8_C(-61), INT8_C(66),  INT8_C(-32),
        INT8_C(48),  INT8_C(-21), INT8_C(54),  INT8_C(-37), INT8_C(43),  INT8_C(-48), INT8_C(26),  INT8_C(-15), INT8_C(42),
        INT8_C(-32), INT8_C(29),  INT8_C(-56), INT8_C(10),  INT8_C(-57), INT8_C(62),  INT8_C(-28), INT8_C(44),  INT8_C(-21),
        INT8_C(50),  INT8_C(-33)},
       {INT8_C(57),   INT8_C(-45),  INT8_C(-88),  INT8_C(-75),  INT8_C(-124), INT8_C(109), INT8_C(58),   INT8_C(115),
        INT8_C(53),   INT8_C(93),   INT8_C(-109), INT8_C(-85),  INT8_C(-101), INT8_C(-39), INT8_C(-127), INT8_C(115),
        INT8_C(45),   INT8_C(-97),  INT8_C(-73),  INT8_C(-125), INT8_C(109),  INT8_C(-55), INT8_C(-95),  INT8_C(-87),
        INT8_C(113),  INT8_C(107),  INT8_C(65),   INT8_C(-123), INT8_C(-121), INT8_C(-47), INT8_C(-109), INT8_C(-101),
        INT8_C(59),   INT8_C(85),   INT8_C(-119), INT8_C(-67),  INT8_C(-111), INT8_C(-61), INT8_C(119),  INT8_C(123),
        INT8_C(61),   INT8_C(101),  INT8_C(-81),  INT8_C(-117), INT8_C(101),  INT8_C(-47), INT8_C(-103), INT8_C(-79),
        INT8_C(123),  INT8_C(115),  INT8_C(57),   INT8_C(-115), INT8_C(-127), INT8_C(-69), INT8_C(103),  INT8_C(-125),
        INT8_C(67),   INT8_C(93),   INT8_C(-127), INT8_C(-59),  INT8_C(-119), INT8_C(-53), INT8_C(111),  INT8_C(-93),
        INT8_C(53),   INT8_C(79),   INT8_C(121),  INT8_C(-51),  INT8_C(-107), INT8_C(-45), INT8_C(115),  INT8_C(-117),
        INT8_C(37),   INT8_C(97),   INT8_C(-89),  INT8_C(-101), INT8_C(93),   INT8_C(-39), INT8_C(-111), INT8_C(-71),
        INT8_C(-125), INT8_C(123),  INT8_C(49),   INT8_C(-67),  INT8_C(121),  INT8_C(-61), INT8_C(95),   INT8_C(-109),
        INT8_C(47),   INT8_C(105),  INT8_C(-95),  INT8_C(-93),  INT8_C(85),   INT8_C(-31), INT8_C(-119), INT8_C(-63),
        INT8_C(115),  INT8_C(-125), INT8_C(41),   INT8_C(-59),  INT8_C(113),  INT8_C(-53), INT8_C(87),   INT8_C(-101),
        INT8_C(39),   INT8_C(113),  INT8_C(-103), INT8_C(-85),  INT8_C(77),   INT8_C(-23), INT8_C(-127), INT8_C(-55),
        INT8_C(107),  INT8_C(-117), INT8_C(33),   INT8_C(-51),  INT8_C(105),  INT8_C(-45), INT8_C(79),   INT8_C(-93),
        INT8_C(31),   INT8_C(121),  INT8_C(-111), INT8_C(-77),  INT8_C(69),   INT8_C(-23), INT8_C(121),  INT8_C(-47)}},
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_hvx_vector_t a, b, r;
    simde_hvx_vector_private a_, b_, r_;

    for (size_t j = 0; j < sizeof(a_.i8) / sizeof(a_.i8[0]); j++) {
      a_.i8[j] = test_vec[i].a[j];
      b_.i8[j] = test_vec[i].b[j];
      r_.i8[j] = test_vec[i].r[j];
    }

    simde_memcpy(&a, &a_, sizeof(a));
    simde_memcpy(&b, &b_, sizeof(b));
    simde_memcpy(&r, &r_, sizeof(r));

    simde_hvx_vector_t result = simde_hvx_add_vb(a, b);

    simde_test_hexagon_hvx_assert_equal_i8(result, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0; i < 1; i++) {
    simde_hvx_vector_t a = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_t b = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_t r = simde_hvx_add_vb(a, b);

    simde_test_hexagon_hvx_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hexagon_hvx_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hexagon_hvx_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int test_simde_hvx_add_vh(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[64];
    int16_t b[64];
    int16_t r[64];
  } test_vec[] = {
      {{INT16_C(1042),  INT16_C(-1717), INT16_C(3095),  INT16_C(-2033), INT16_C(4176),  INT16_C(-1584), INT16_C(2819),
        INT16_C(-3356), INT16_C(1531),  INT16_C(-2892), INT16_C(3263),  INT16_C(-1748), INT16_C(4187),  INT16_C(-1025),
        INT16_C(2974),  INT16_C(-3261), INT16_C(1228),  INT16_C(-2539), INT16_C(3502),  INT16_C(-1473), INT16_C(4345),
        INT16_C(-918),  INT16_C(3091),  INT16_C(-3134), INT16_C(1467),  INT16_C(-2685), INT16_C(3123),  INT16_C(-1652),
        INT16_C(4278),  INT16_C(-829),  INT16_C(2964),  INT16_C(-3241), INT16_C(1335),  INT16_C(-2796), INT16_C(3359),
        INT16_C(-1544), INT16_C(4283),  INT16_C(-721),  INT16_C(3070),  INT16_C(-3157), INT16_C(1226),  INT16_C(-2688),
        INT16_C(3498),  INT16_C(-1369), INT16_C(4341),  INT16_C(-614),  INT16_C(3187),  INT16_C(-3030), INT16_C(1472),
        INT16_C(-2581), INT16_C(3219),  INT16_C(-1548), INT16_C(4175),  INT16_C(-725),  INT16_C(2962),  INT16_C(-3153),
        INT16_C(1339),  INT16_C(-2692), INT16_C(3355),  INT16_C(-1440), INT16_C(4279),  INT16_C(-617),  INT16_C(3066),
        INT16_C(-3037)},
       {INT16_C(515),   INT16_C(-828),  INT16_C(1573),  INT16_C(-942),  INT16_C(2156),  INT16_C(-663),  INT16_C(1239),
        INT16_C(-1685), INT16_C(422),   INT16_C(-771),  INT16_C(1684),  INT16_C(-837),  INT16_C(2268),  INT16_C(-514),
        INT16_C(1355),  INT16_C(-1580), INT16_C(317),   INT16_C(-658),  INT16_C(1781),  INT16_C(-752),  INT16_C(2364),
        INT16_C(-437),  INT16_C(1470),  INT16_C(-1453), INT16_C(446),   INT16_C(-764),  INT16_C(1642),  INT16_C(-871),
        INT16_C(2257),  INT16_C(-518),  INT16_C(1342),  INT16_C(-1572), INT16_C(324),   INT16_C(-675),  INT16_C(1778),
        INT16_C(-723),  INT16_C(2362),  INT16_C(-440),  INT16_C(1469),  INT16_C(-1476), INT16_C(435),   INT16_C(-767),
        INT16_C(1677),  INT16_C(-848),  INT16_C(2270),  INT16_C(-525),  INT16_C(1387),  INT16_C(-1549), INT16_C(351),
        INT16_C(-660),  INT16_C(1742),  INT16_C(-767),  INT16_C(2354),  INT16_C(-444),  INT16_C(1441),  INT16_C(-1472),
        INT16_C(428),   INT16_C(-671),  INT16_C(1674),  INT16_C(-740),  INT16_C(2279),  INT16_C(-417),  INT16_C(1366),
        INT16_C(-1456)},
       {INT16_C(1557),  INT16_C(-2545), INT16_C(4668),  INT16_C(-2975), INT16_C(6332),  INT16_C(-2247), INT16_C(4058),
        INT16_C(-5041), INT16_C(1953),  INT16_C(-3663), INT16_C(4947),  INT16_C(-2585), INT16_C(6455),  INT16_C(-1539),
        INT16_C(4329),  INT16_C(-4841), INT16_C(1545),  INT16_C(-3197), INT16_C(5283),  INT16_C(-2225), INT16_C(6709),
        INT16_C(-1355), INT16_C(4561),  INT16_C(-4587), INT16_C(1913),  INT16_C(-3449), INT16_C(4765),  INT16_C(-2523),
        INT16_C(6535),  INT16_C(-1347), INT16_C(4306),  INT16_C(-4813), INT16_C(1659),  INT16_C(-3471), INT16_C(5137),
        INT16_C(-2267), INT16_C(6645),  INT16_C(-1161), INT16_C(4539),  INT16_C(-4633), INT16_C(1661),  INT16_C(-3455),
        INT16_C(5175),  INT16_C(-2217), INT16_C(6611),  INT16_C(-1139), INT16_C(4574),  INT16_C(-4579), INT16_C(1823),
        INT16_C(-3241), INT16_C(4961),  INT16_C(-2315), INT16_C(6529),  INT16_C(-1169), INT16_C(4403),  INT16_C(-4625),
        INT16_C(1767),  INT16_C(-3363), INT16_C(5029),  INT16_C(-2180), INT16_C(6558),  INT16_C(-1034), INT16_C(4432),
        INT16_C(-4493)}},
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_hvx_vector_t a, b, r;
    simde_hvx_vector_private a_, b_, r_;

    /* Initialize private vectors to zero */
    memset(&a_, 0, sizeof(a_));
    memset(&b_, 0, sizeof(b_));
    memset(&r_, 0, sizeof(r_));

    for (size_t j = 0; j < sizeof(a_.i16) / sizeof(a_.i16[0]); j++) {
      a_.i16[j] = test_vec[i].a[j];
      b_.i16[j] = test_vec[i].b[j];
      r_.i16[j] = test_vec[i].r[j];
    }

    /* Convert from private to public types */
    simde_memcpy(&a, &a_, sizeof(a));
    simde_memcpy(&b, &b_, sizeof(b));
    simde_memcpy(&r, &r_, sizeof(r));

    simde_hvx_vector_t result = simde_hvx_add_vh(a, b);

    simde_test_hexagon_hvx_assert_equal_i16(result, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0; i < 1; i++) {
    simde_hvx_vector_t a = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_t b = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_t r = simde_hvx_add_vh(a, b);

    simde_test_hexagon_hvx_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hexagon_hvx_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hexagon_hvx_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_add_vb)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_add_vh)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
