#define SIMDE_TEST_HEXAGON_HVX_INSN mul

#include "../../../simde/hexagon/hvx/mul.h"
#include "test-hvx.h"

static int test_simde_hvx_mul_vb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int16_t r[128];
  } test_vec[] = {
      {{INT8_C(5), INT8_C(-3), INT8_C(7), INT8_C(-2), INT8_C(4), INT8_C(-6), INT8_C(8), INT8_C(-1), INT8_C(3), INT8_C(-5),
        INT8_C(6), INT8_C(-4), INT8_C(9), INT8_C(-2), INT8_C(7), INT8_C(-3), INT8_C(2), INT8_C(-7), INT8_C(5), INT8_C(-1),
        INT8_C(8), INT8_C(-4), INT8_C(6), INT8_C(-2), INT8_C(4), INT8_C(-8), INT8_C(3), INT8_C(-5), INT8_C(7), INT8_C(-1),
        INT8_C(9), INT8_C(-3), INT8_C(1), INT8_C(-6), INT8_C(4), INT8_C(-2), INT8_C(8), INT8_C(-5), INT8_C(7), INT8_C(-3),
        INT8_C(2), INT8_C(-9), INT8_C(5), INT8_C(-1), INT8_C(6), INT8_C(-4), INT8_C(8), INT8_C(-2), INT8_C(3), INT8_C(-7),
        INT8_C(4), INT8_C(-6), INT8_C(9), INT8_C(-1), INT8_C(5), INT8_C(-8), INT8_C(7), INT8_C(-2), INT8_C(3), INT8_C(-4),
        INT8_C(6), INT8_C(-5), INT8_C(8), INT8_C(-1), INT8_C(2), INT8_C(-6), INT8_C(9), INT8_C(-3), INT8_C(4), INT8_C(-7),
        INT8_C(5), INT8_C(-2), INT8_C(8), INT8_C(-1), INT8_C(3), INT8_C(-5), INT8_C(7), INT8_C(-4), INT8_C(6), INT8_C(-8),
        INT8_C(1), INT8_C(-9), INT8_C(4), INT8_C(-2), INT8_C(5), INT8_C(-6), INT8_C(8), INT8_C(-3), INT8_C(7), INT8_C(-1),
        INT8_C(2), INT8_C(-4), INT8_C(9), INT8_C(-5), INT8_C(3), INT8_C(-7), INT8_C(6), INT8_C(-8), INT8_C(1), INT8_C(-2),
        INT8_C(4), INT8_C(-9), INT8_C(7), INT8_C(-3), INT8_C(5), INT8_C(-1), INT8_C(8), INT8_C(-6), INT8_C(2), INT8_C(-4),
        INT8_C(9), INT8_C(-7), INT8_C(3), INT8_C(-5), INT8_C(6), INT8_C(-2), INT8_C(8), INT8_C(-1), INT8_C(4), INT8_C(-9),
        INT8_C(7), INT8_C(-3), INT8_C(1), INT8_C(-6), INT8_C(5), INT8_C(-8), INT8_C(2), INT8_C(-4)},
       {INT8_C(2),  INT8_C(4),  INT8_C(-1), INT8_C(5),  INT8_C(3),  INT8_C(-2), INT8_C(6),  INT8_C(7),  INT8_C(4),
        INT8_C(-1), INT8_C(2),  INT8_C(3),  INT8_C(-5), INT8_C(6),  INT8_C(1),  INT8_C(4),  INT8_C(5),  INT8_C(2),
        INT8_C(-3), INT8_C(6),  INT8_C(1),  INT8_C(4),  INT8_C(-2), INT8_C(5),  INT8_C(3),  INT8_C(-1), INT8_C(4),
        INT8_C(2),  INT8_C(-6), INT8_C(5),  INT8_C(1),  INT8_C(3),  INT8_C(6),  INT8_C(2),  INT8_C(-4), INT8_C(5),
        INT8_C(1),  INT8_C(3),  INT8_C(-2), INT8_C(4),  INT8_C(7),  INT8_C(-1), INT8_C(3),  INT8_C(5),  INT8_C(-2),
        INT8_C(4),  INT8_C(1),  INT8_C(6),  INT8_C(2),  INT8_C(5),  INT8_C(-3), INT8_C(1),  INT8_C(4),  INT8_C(6),
        INT8_C(-2), INT8_C(3),  INT8_C(1),  INT8_C(4),  INT8_C(-5), INT8_C(2),  INT8_C(3),  INT8_C(6),  INT8_C(-1),
        INT8_C(5),  INT8_C(4),  INT8_C(-2), INT8_C(1),  INT8_C(5),  INT8_C(-3), INT8_C(2),  INT8_C(6),  INT8_C(4),
        INT8_C(-1), INT8_C(3),  INT8_C(5),  INT8_C(2),  INT8_C(4),  INT8_C(-3), INT8_C(1),  INT8_C(6),  INT8_C(5),
        INT8_C(2),  INT8_C(-1), INT8_C(4),  INT8_C(3),  INT8_C(6),  INT8_C(-2), INT8_C(1),  INT8_C(2),  INT8_C(5),
        INT8_C(-4), INT8_C(3),  INT8_C(1),  INT8_C(6),  INT8_C(-5), INT8_C(2),  INT8_C(3),  INT8_C(-1), INT8_C(5),
        INT8_C(4),  INT8_C(-2), INT8_C(1),  INT8_C(6),  INT8_C(3),  INT8_C(4),  INT8_C(6),  INT8_C(-1), INT8_C(2),
        INT8_C(5),  INT8_C(3),  INT8_C(-4), INT8_C(1),  INT8_C(2),  INT8_C(4),  INT8_C(-3), INT8_C(5),  INT8_C(1),
        INT8_C(6),  INT8_C(-2), INT8_C(3),  INT8_C(1),  INT8_C(5),  INT8_C(-4), INT8_C(2),  INT8_C(3),  INT8_C(6),
        INT8_C(-1), INT8_C(4)},
       {INT16_C(10), INT16_C(-12), INT16_C(-7),  INT16_C(-10), INT16_C(12),  INT16_C(12),  INT16_C(48),  INT16_C(-7),
        INT16_C(12), INT16_C(5),   INT16_C(12),  INT16_C(-12), INT16_C(-45), INT16_C(-12), INT16_C(7),   INT16_C(-12),
        INT16_C(10), INT16_C(-14), INT16_C(-15), INT16_C(-6),  INT16_C(8),   INT16_C(-16), INT16_C(-12), INT16_C(-10),
        INT16_C(12), INT16_C(8),   INT16_C(12),  INT16_C(-10), INT16_C(-42), INT16_C(-5),  INT16_C(9),   INT16_C(-9),
        INT16_C(6),  INT16_C(-12), INT16_C(-16), INT16_C(-10), INT16_C(8),   INT16_C(-15), INT16_C(-14), INT16_C(-12),
        INT16_C(14), INT16_C(9),   INT16_C(15),  INT16_C(-5),  INT16_C(-12), INT16_C(-16), INT16_C(8),   INT16_C(-12),
        INT16_C(6),  INT16_C(-35), INT16_C(-12), INT16_C(-6),  INT16_C(36),  INT16_C(-6),  INT16_C(-10), INT16_C(-24),
        INT16_C(7),  INT16_C(-8),  INT16_C(-15), INT16_C(-8),  INT16_C(18),  INT16_C(-30), INT16_C(-8),  INT16_C(-5),
        INT16_C(8),  INT16_C(12),  INT16_C(9),   INT16_C(-15), INT16_C(-12), INT16_C(-14), INT16_C(30),  INT16_C(-8),
        INT16_C(-8), INT16_C(-3),  INT16_C(15),  INT16_C(-10), INT16_C(28),  INT16_C(12),  INT16_C(6),   INT16_C(-48),
        INT16_C(5),  INT16_C(-18), INT16_C(-4),  INT16_C(-8),  INT16_C(15),  INT16_C(-36), INT16_C(-16), INT16_C(-3),
        INT16_C(14), INT16_C(-5),  INT16_C(-8),  INT16_C(-12), INT16_C(9),   INT16_C(-30), INT16_C(-15), INT16_C(-14),
        INT16_C(18), INT16_C(8),   INT16_C(5),   INT16_C(-8),  INT16_C(-8),  INT16_C(-9),  INT16_C(42),  INT16_C(-9),
        INT16_C(20), INT16_C(-6),  INT16_C(-8),  INT16_C(-12), INT16_C(10),  INT16_C(-12), INT16_C(-36), INT16_C(-7),
        INT16_C(6),  INT16_C(-20), INT16_C(-18), INT16_C(-10), INT16_C(8),   INT16_C(-6),  INT16_C(-8),  INT16_C(-27),
        INT16_C(7),  INT16_C(-15), INT16_C(-4),  INT16_C(-12), INT16_C(15),  INT16_C(-48), INT16_C(-2),  INT16_C(-16)}},
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_hvx_vector_t a, b;
    simde_hvx_vector_pair_t r_expected, r_actual;
    simde_hvx_vector_private a_, b_;
    simde_hvx_vector_pair_private r_;

    for (size_t j = 0; j < sizeof(a_.i8) / sizeof(a_.i8[0]); j++) {
      a_.i8[j] = test_vec[i].a[j];
      b_.i8[j] = test_vec[i].b[j];
      r_.i16[j] = test_vec[i].r[j];
    }

    simde_memcpy(&a, &a_, sizeof(a));
    simde_memcpy(&b, &b_, sizeof(b));
    simde_memcpy(&r_expected, &r_, sizeof(r_expected));

    r_actual = simde_hvx_mul_vb(a, b);

    simde_test_hexagon_hvx_assert_equal_pair_i16(r_actual, r_expected);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0; i < 1; i++) {
    simde_hvx_vector_t a = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_t b = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_pair_t r = simde_hvx_mul_vb(a, b);

    simde_test_hexagon_hvx_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hexagon_hvx_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hexagon_hvx_write_pair_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_mul_vb)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
