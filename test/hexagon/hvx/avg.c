#define SIMDE_TEST_HEXAGON_HVX_INSN avg

#include "../../../simde/hexagon/hvx/avg.h"
#include "test-hvx.h"
#include <string.h>

static int test_simde_hvx_avg_vub(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[128];
    uint8_t b[128];
    uint8_t r[128];
  } test_vec[] = {
      {{UINT8_C(42),  UINT8_C(17), UINT8_C(95), UINT8_C(33), UINT8_C(76), UINT8_C(84), UINT8_C(19), UINT8_C(56), UINT8_C(31),
        UINT8_C(92),  UINT8_C(63), UINT8_C(48), UINT8_C(87), UINT8_C(25), UINT8_C(74), UINT8_C(61), UINT8_C(28), UINT8_C(39),
        UINT8_C(102), UINT8_C(73), UINT8_C(45), UINT8_C(18), UINT8_C(91), UINT8_C(34), UINT8_C(67), UINT8_C(85), UINT8_C(23),
        UINT8_C(52),  UINT8_C(78), UINT8_C(29), UINT8_C(64), UINT8_C(41), UINT8_C(35), UINT8_C(96), UINT8_C(59), UINT8_C(44),
        UINT8_C(83),  UINT8_C(21), UINT8_C(70), UINT8_C(57), UINT8_C(26), UINT8_C(88), UINT8_C(98), UINT8_C(69), UINT8_C(41),
        UINT8_C(14),  UINT8_C(87), UINT8_C(30), UINT8_C(72), UINT8_C(81), UINT8_C(19), UINT8_C(48), UINT8_C(75), UINT8_C(25),
        UINT8_C(62),  UINT8_C(53), UINT8_C(39), UINT8_C(92), UINT8_C(55), UINT8_C(40), UINT8_C(79), UINT8_C(17), UINT8_C(66),
        UINT8_C(37),  UINT8_C(32), UINT8_C(99), UINT8_C(51), UINT8_C(36), UINT8_C(85), UINT8_C(13), UINT8_C(68), UINT8_C(49),
        UINT8_C(24),  UINT8_C(90), UINT8_C(94), UINT8_C(61), UINT8_C(37), UINT8_C(10), UINT8_C(83), UINT8_C(26), UINT8_C(76),
        UINT8_C(77),  UINT8_C(15), UINT8_C(44), UINT8_C(71), UINT8_C(21), UINT8_C(58), UINT8_C(45), UINT8_C(29), UINT8_C(86),
        UINT8_C(91),  UINT8_C(57), UINT8_C(33), UINT8_C(6),  UINT8_C(79), UINT8_C(22), UINT8_C(68), UINT8_C(73), UINT8_C(11),
        UINT8_C(40),  UINT8_C(67), UINT8_C(17), UINT8_C(54), UINT8_C(41), UINT8_C(25), UINT8_C(82), UINT8_C(87), UINT8_C(53),
        UINT8_C(29),  UINT8_C(2),  UINT8_C(75), UINT8_C(18), UINT8_C(64), UINT8_C(69), UINT8_C(7),  UINT8_C(36), UINT8_C(63),
        UINT8_C(13),  UINT8_C(50), UINT8_C(37), UINT8_C(21), UINT8_C(78), UINT8_C(83), UINT8_C(49), UINT8_C(25), UINT8_C(2),
        UINT8_C(71),  UINT8_C(14)},
       {UINT8_C(15), UINT8_C(28), UINT8_C(73), UINT8_C(42), UINT8_C(56), UINT8_C(63), UINT8_C(39), UINT8_C(85), UINT8_C(22),
        UINT8_C(71), UINT8_C(84), UINT8_C(37), UINT8_C(68), UINT8_C(14), UINT8_C(55), UINT8_C(80), UINT8_C(17), UINT8_C(58),
        UINT8_C(81), UINT8_C(52), UINT8_C(64), UINT8_C(37), UINT8_C(70), UINT8_C(53), UINT8_C(46), UINT8_C(64), UINT8_C(42),
        UINT8_C(71), UINT8_C(57), UINT8_C(18), UINT8_C(83), UINT8_C(60), UINT8_C(24), UINT8_C(75), UINT8_C(78), UINT8_C(23),
        UINT8_C(62), UINT8_C(40), UINT8_C(49), UINT8_C(76), UINT8_C(35), UINT8_C(67), UINT8_C(77), UINT8_C(48), UINT8_C(60),
        UINT8_C(33), UINT8_C(66), UINT8_C(49), UINT8_C(51), UINT8_C(60), UINT8_C(38), UINT8_C(67), UINT8_C(54), UINT8_C(44),
        UINT8_C(41), UINT8_C(72), UINT8_C(28), UINT8_C(71), UINT8_C(74), UINT8_C(19), UINT8_C(58), UINT8_C(36), UINT8_C(45),
        UINT8_C(56), UINT8_C(21), UINT8_C(78), UINT8_C(70), UINT8_C(15), UINT8_C(64), UINT8_C(32), UINT8_C(47), UINT8_C(68),
        UINT8_C(13), UINT8_C(69), UINT8_C(73), UINT8_C(40), UINT8_C(56), UINT8_C(29), UINT8_C(62), UINT8_C(45), UINT8_C(55),
        UINT8_C(56), UINT8_C(34), UINT8_C(23), UINT8_C(50), UINT8_C(40), UINT8_C(37), UINT8_C(64), UINT8_C(18), UINT8_C(65),
        UINT8_C(70), UINT8_C(36), UINT8_C(52), UINT8_C(25), UINT8_C(58), UINT8_C(41), UINT8_C(47), UINT8_C(52), UINT8_C(30),
        UINT8_C(19), UINT8_C(46), UINT8_C(36), UINT8_C(33), UINT8_C(60), UINT8_C(14), UINT8_C(61), UINT8_C(66), UINT8_C(32),
        UINT8_C(48), UINT8_C(21), UINT8_C(54), UINT8_C(37), UINT8_C(43), UINT8_C(48), UINT8_C(26), UINT8_C(15), UINT8_C(42),
        UINT8_C(32), UINT8_C(29), UINT8_C(56), UINT8_C(10), UINT8_C(57), UINT8_C(62), UINT8_C(28), UINT8_C(44), UINT8_C(21),
        UINT8_C(50), UINT8_C(33)},
       {UINT8_C(29), UINT8_C(23), UINT8_C(84), UINT8_C(38), UINT8_C(66), UINT8_C(74), UINT8_C(29), UINT8_C(71), UINT8_C(27),
        UINT8_C(82), UINT8_C(74), UINT8_C(43), UINT8_C(78), UINT8_C(20), UINT8_C(65), UINT8_C(71), UINT8_C(23), UINT8_C(49),
        UINT8_C(92), UINT8_C(63), UINT8_C(55), UINT8_C(28), UINT8_C(81), UINT8_C(44), UINT8_C(57), UINT8_C(75), UINT8_C(33),
        UINT8_C(62), UINT8_C(68), UINT8_C(24), UINT8_C(74), UINT8_C(51), UINT8_C(30), UINT8_C(86), UINT8_C(69), UINT8_C(34),
        UINT8_C(73), UINT8_C(31), UINT8_C(60), UINT8_C(67), UINT8_C(31), UINT8_C(78), UINT8_C(88), UINT8_C(59), UINT8_C(51),
        UINT8_C(24), UINT8_C(77), UINT8_C(40), UINT8_C(62), UINT8_C(71), UINT8_C(29), UINT8_C(58), UINT8_C(65), UINT8_C(35),
        UINT8_C(52), UINT8_C(63), UINT8_C(34), UINT8_C(82), UINT8_C(65), UINT8_C(30), UINT8_C(69), UINT8_C(27), UINT8_C(56),
        UINT8_C(47), UINT8_C(27), UINT8_C(89), UINT8_C(61), UINT8_C(26), UINT8_C(75), UINT8_C(23), UINT8_C(58), UINT8_C(59),
        UINT8_C(19), UINT8_C(80), UINT8_C(84), UINT8_C(51), UINT8_C(47), UINT8_C(20), UINT8_C(73), UINT8_C(36), UINT8_C(66),
        UINT8_C(67), UINT8_C(25), UINT8_C(34), UINT8_C(61), UINT8_C(31), UINT8_C(48), UINT8_C(55), UINT8_C(24), UINT8_C(76),
        UINT8_C(81), UINT8_C(47), UINT8_C(43), UINT8_C(16), UINT8_C(69), UINT8_C(32), UINT8_C(58), UINT8_C(63), UINT8_C(21),
        UINT8_C(30), UINT8_C(57), UINT8_C(27), UINT8_C(44), UINT8_C(51), UINT8_C(20), UINT8_C(72), UINT8_C(77), UINT8_C(43),
        UINT8_C(39), UINT8_C(12), UINT8_C(65), UINT8_C(28), UINT8_C(54), UINT8_C(59), UINT8_C(17), UINT8_C(26), UINT8_C(53),
        UINT8_C(23), UINT8_C(40), UINT8_C(47), UINT8_C(16), UINT8_C(68), UINT8_C(73), UINT8_C(39), UINT8_C(35), UINT8_C(12),
        UINT8_C(61), UINT8_C(24)}},
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_hvx_vector_t a, b, r;
    simde_hvx_vector_private a_, b_, r_;

    for (size_t j = 0; j < sizeof(a_.u8) / sizeof(a_.u8[0]); j++) {
      a_.u8[j] = test_vec[i].a[j];
      b_.u8[j] = test_vec[i].b[j];
      r_.u8[j] = test_vec[i].r[j];
    }

    simde_memcpy(&a, &a_, sizeof(a));
    simde_memcpy(&b, &b_, sizeof(b));
    simde_memcpy(&r, &r_, sizeof(r));

    simde_hvx_vector_t result = simde_hvx_avg_vub(a, b);

    simde_test_hexagon_hvx_assert_equal_u8(result, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0; i < 1; i++) {
    simde_hvx_vector_t a = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_t b = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_t r = simde_hvx_avg_vub(a, b);

    simde_test_hexagon_hvx_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hexagon_hvx_write_u8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hexagon_hvx_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_avg_vub)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
