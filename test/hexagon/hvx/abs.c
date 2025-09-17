#define SIMDE_TEST_HEXAGON_HVX_INSN abs

#include "../../../simde/hexagon/hvx/abs.h"
#include "test-hvx.h"
#include <string.h>

static int test_simde_hvx_abs_vb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t r[128];
  } test_vec[] = {
      {{INT8_C(-42),  INT8_C(17),  INT8_C(-95), INT8_C(33),  INT8_C(-76), INT8_C(84),  INT8_C(-19), INT8_C(56),  INT8_C(-31),
        INT8_C(92),   INT8_C(-63), INT8_C(48),  INT8_C(-87), INT8_C(25),  INT8_C(-74), INT8_C(61),  INT8_C(-28), INT8_C(39),
        INT8_C(-102), INT8_C(73),  INT8_C(-45), INT8_C(18),  INT8_C(-91), INT8_C(34),  INT8_C(-67), INT8_C(85),  INT8_C(-23),
        INT8_C(52),   INT8_C(-78), INT8_C(29),  INT8_C(-64), INT8_C(41),  INT8_C(-35), INT8_C(96),  INT8_C(-59), INT8_C(44),
        INT8_C(-83),  INT8_C(21),  INT8_C(-70), INT8_C(57),  INT8_C(-26), INT8_C(88),  INT8_C(-98), INT8_C(69),  INT8_C(-41),
        INT8_C(14),   INT8_C(-87), INT8_C(30),  INT8_C(-72), INT8_C(81),  INT8_C(-19), INT8_C(48),  INT8_C(-75), INT8_C(25),
        INT8_C(-62),  INT8_C(53),  INT8_C(-39), INT8_C(92),  INT8_C(-55), INT8_C(40),  INT8_C(-79), INT8_C(17),  INT8_C(-66),
        INT8_C(37),   INT8_C(-32), INT8_C(99),  INT8_C(-51), INT8_C(36),  INT8_C(-85), INT8_C(13),  INT8_C(-68), INT8_C(49),
        INT8_C(-24),  INT8_C(90),  INT8_C(-94), INT8_C(61),  INT8_C(-37), INT8_C(10),  INT8_C(-83), INT8_C(26),  INT8_C(-76),
        INT8_C(77),   INT8_C(-15), INT8_C(44),  INT8_C(-71), INT8_C(21),  INT8_C(-58), INT8_C(45),  INT8_C(-29), INT8_C(86),
        INT8_C(-91),  INT8_C(57),  INT8_C(-33), INT8_C(6),   INT8_C(-79), INT8_C(22),  INT8_C(-68), INT8_C(73),  INT8_C(-11),
        INT8_C(40),   INT8_C(-67), INT8_C(17),  INT8_C(-54), INT8_C(41),  INT8_C(-25), INT8_C(82),  INT8_C(-87), INT8_C(53),
        INT8_C(-29),  INT8_C(2),   INT8_C(-75), INT8_C(18),  INT8_C(-64), INT8_C(69),  INT8_C(-7),  INT8_C(36),  INT8_C(-63),
        INT8_C(13),   INT8_C(-50), INT8_C(37),  INT8_C(-21), INT8_C(78),  INT8_C(-83), INT8_C(49),  INT8_C(-25), INT8_C(2),
        INT8_C(-71),  INT8_C(14)},
       {INT8_C(42),  INT8_C(17), INT8_C(95), INT8_C(33), INT8_C(76), INT8_C(84), INT8_C(19), INT8_C(56), INT8_C(31),
        INT8_C(92),  INT8_C(63), INT8_C(48), INT8_C(87), INT8_C(25), INT8_C(74), INT8_C(61), INT8_C(28), INT8_C(39),
        INT8_C(102), INT8_C(73), INT8_C(45), INT8_C(18), INT8_C(91), INT8_C(34), INT8_C(67), INT8_C(85), INT8_C(23),
        INT8_C(52),  INT8_C(78), INT8_C(29), INT8_C(64), INT8_C(41), INT8_C(35), INT8_C(96), INT8_C(59), INT8_C(44),
        INT8_C(83),  INT8_C(21), INT8_C(70), INT8_C(57), INT8_C(26), INT8_C(88), INT8_C(98), INT8_C(69), INT8_C(41),
        INT8_C(14),  INT8_C(87), INT8_C(30), INT8_C(72), INT8_C(81), INT8_C(19), INT8_C(48), INT8_C(75), INT8_C(25),
        INT8_C(62),  INT8_C(53), INT8_C(39), INT8_C(92), INT8_C(55), INT8_C(40), INT8_C(79), INT8_C(17), INT8_C(66),
        INT8_C(37),  INT8_C(32), INT8_C(99), INT8_C(51), INT8_C(36), INT8_C(85), INT8_C(13), INT8_C(68), INT8_C(49),
        INT8_C(24),  INT8_C(90), INT8_C(94), INT8_C(61), INT8_C(37), INT8_C(10), INT8_C(83), INT8_C(26), INT8_C(76),
        INT8_C(77),  INT8_C(15), INT8_C(44), INT8_C(71), INT8_C(21), INT8_C(58), INT8_C(45), INT8_C(29), INT8_C(86),
        INT8_C(91),  INT8_C(57), INT8_C(33), INT8_C(6),  INT8_C(79), INT8_C(22), INT8_C(68), INT8_C(73), INT8_C(11),
        INT8_C(40),  INT8_C(67), INT8_C(17), INT8_C(54), INT8_C(41), INT8_C(25), INT8_C(82), INT8_C(87), INT8_C(53),
        INT8_C(29),  INT8_C(2),  INT8_C(75), INT8_C(18), INT8_C(64), INT8_C(69), INT8_C(7),  INT8_C(36), INT8_C(63),
        INT8_C(13),  INT8_C(50), INT8_C(37), INT8_C(21), INT8_C(78), INT8_C(83), INT8_C(49), INT8_C(25), INT8_C(2),
        INT8_C(71),  INT8_C(14)}},
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_hvx_vector_t a, r;
    simde_hvx_vector_private a_, r_;

    for (size_t j = 0; j < sizeof(a_.i8) / sizeof(a_.i8[0]); j++) {
      a_.i8[j] = test_vec[i].a[j];
      r_.i8[j] = test_vec[i].r[j];
    }

    simde_memcpy(&a, &a_, sizeof(a));
    simde_memcpy(&r, &r_, sizeof(r));

    simde_hvx_vector_t result = simde_hvx_abs_vb(a);

    simde_test_hexagon_hvx_assert_equal_i8(result, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0; i < 1; i++) {
    simde_hvx_vector_t a = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_t r = simde_hvx_abs_vb(a);

    simde_test_hexagon_hvx_write_i8(1, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hexagon_hvx_write_i8(1, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_abs_vb)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
