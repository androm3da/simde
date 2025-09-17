#define SIMDE_TEST_HEXAGON_HVX_INSN sub

#include "../../../simde/hexagon/hvx/sub.h"
#include "test-hvx.h"

static int test_simde_hvx_sub_vb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[128];
    int8_t b[128];
    int8_t r[128];
  } test_vec[] = {
      {{INT8_C(50),  INT8_C(-20), INT8_C(80),  INT8_C(-45), INT8_C(60),  INT8_C(-30), INT8_C(90),  INT8_C(-15), INT8_C(40),
        INT8_C(-50), INT8_C(70),  INT8_C(-25), INT8_C(85),  INT8_C(-10), INT8_C(75),  INT8_C(-35), INT8_C(30),  INT8_C(-60),
        INT8_C(95),  INT8_C(-55), INT8_C(45),  INT8_C(-20), INT8_C(65),  INT8_C(-40), INT8_C(55),  INT8_C(-75), INT8_C(25),
        INT8_C(-85), INT8_C(70),  INT8_C(-15), INT8_C(80),  INT8_C(-25), INT8_C(35),  INT8_C(-65), INT8_C(85),  INT8_C(-45),
        INT8_C(50),  INT8_C(-30), INT8_C(75),  INT8_C(-55), INT8_C(40),  INT8_C(-80), INT8_C(60),  INT8_C(-35), INT8_C(90),
        INT8_C(-20), INT8_C(65),  INT8_C(-45), INT8_C(25),  INT8_C(-70), INT8_C(85),  INT8_C(-55), INT8_C(45),  INT8_C(-25),
        INT8_C(70),  INT8_C(-60), INT8_C(50),  INT8_C(-90), INT8_C(30),  INT8_C(-40), INT8_C(75),  INT8_C(-15), INT8_C(85),
        INT8_C(-35), INT8_C(20),  INT8_C(-85), INT8_C(65),  INT8_C(-50), INT8_C(80),  INT8_C(-10), INT8_C(55),  INT8_C(-70),
        INT8_C(45),  INT8_C(-75), INT8_C(90),  INT8_C(-25), INT8_C(35),  INT8_C(-55), INT8_C(70),  INT8_C(-40), INT8_C(60),
        INT8_C(-80), INT8_C(25),  INT8_C(-65), INT8_C(85),  INT8_C(-20), INT8_C(50),  INT8_C(-45), INT8_C(30),  INT8_C(-70),
        INT8_C(75),  INT8_C(-35), INT8_C(40),  INT8_C(-60), INT8_C(85),  INT8_C(-25), INT8_C(55),  INT8_C(-85), INT8_C(20),
        INT8_C(-50), INT8_C(70),  INT8_C(-15), INT8_C(45),  INT8_C(-75), INT8_C(35),  INT8_C(-90), INT8_C(80),  INT8_C(-30),
        INT8_C(25),  INT8_C(-55), INT8_C(65),  INT8_C(-40), INT8_C(50),  INT8_C(-75), INT8_C(40),  INT8_C(-60), INT8_C(85),
        INT8_C(-20), INT8_C(30),  INT8_C(-80), INT8_C(70),  INT8_C(-45), INT8_C(55),  INT8_C(-85), INT8_C(25),  INT8_C(-65),
        INT8_C(90),  INT8_C(-35)},
       {INT8_C(15),  INT8_C(-30), INT8_C(45),  INT8_C(-60), INT8_C(25),  INT8_C(-40), INT8_C(55),  INT8_C(-20), INT8_C(35),
        INT8_C(-25), INT8_C(50),  INT8_C(-45), INT8_C(40),  INT8_C(-15), INT8_C(60),  INT8_C(-55), INT8_C(20),  INT8_C(-50),
        INT8_C(70),  INT8_C(-35), INT8_C(30),  INT8_C(-65), INT8_C(45),  INT8_C(-80), INT8_C(85),  INT8_C(-40), INT8_C(15),
        INT8_C(-70), INT8_C(55),  INT8_C(-25), INT8_C(65),  INT8_C(-50), INT8_C(10),  INT8_C(-75), INT8_C(60),  INT8_C(-35),
        INT8_C(40),  INT8_C(-20), INT8_C(50),  INT8_C(-85), INT8_C(25),  INT8_C(-45), INT8_C(35),  INT8_C(-70), INT8_C(55),
        INT8_C(-10), INT8_C(80),  INT8_C(-60), INT8_C(40),  INT8_C(-85), INT8_C(60),  INT8_C(-25), INT8_C(30),  INT8_C(-50),
        INT8_C(75),  INT8_C(-40), INT8_C(20),  INT8_C(-65), INT8_C(45),  INT8_C(-80), INT8_C(35),  INT8_C(-55), INT8_C(70),
        INT8_C(-15), INT8_C(55),  INT8_C(-30), INT8_C(25),  INT8_C(-75), INT8_C(65),  INT8_C(-40), INT8_C(15),  INT8_C(-85),
        INT8_C(10),  INT8_C(-60), INT8_C(50),  INT8_C(-45), INT8_C(80),  INT8_C(-35), INT8_C(20),  INT8_C(-70), INT8_C(45),
        INT8_C(-25), INT8_C(70),  INT8_C(-55), INT8_C(35),  INT8_C(-80), INT8_C(65),  INT8_C(-20), INT8_C(15),  INT8_C(-85),
        INT8_C(40),  INT8_C(-50), INT8_C(75),  INT8_C(-30), INT8_C(55),  INT8_C(-60), INT8_C(30),  INT8_C(-45), INT8_C(65),
        INT8_C(-20), INT8_C(85),  INT8_C(-75), INT8_C(25),  INT8_C(-40), INT8_C(60),  INT8_C(-35), INT8_C(15),  INT8_C(-80),
        INT8_C(50),  INT8_C(-25), INT8_C(40),  INT8_C(-70), INT8_C(35),  INT8_C(-90), INT8_C(75),  INT8_C(-20), INT8_C(45),
        INT8_C(-55), INT8_C(65),  INT8_C(-30), INT8_C(25),  INT8_C(-70), INT8_C(80),  INT8_C(-45), INT8_C(60),  INT8_C(-35),
        INT8_C(50),  INT8_C(-85)},
       {INT8_C(35),  INT8_C(10),  INT8_C(35),  INT8_C(15),  INT8_C(35),  INT8_C(10),  INT8_C(35),  INT8_C(5),   INT8_C(5),
        INT8_C(-25), INT8_C(20),  INT8_C(20),  INT8_C(45),  INT8_C(5),   INT8_C(15),  INT8_C(20),  INT8_C(10),  INT8_C(-10),
        INT8_C(25),  INT8_C(-20), INT8_C(15),  INT8_C(45),  INT8_C(20),  INT8_C(40),  INT8_C(-30), INT8_C(-35), INT8_C(10),
        INT8_C(-15), INT8_C(15),  INT8_C(10),  INT8_C(15),  INT8_C(25),  INT8_C(25),  INT8_C(10),  INT8_C(25),  INT8_C(-10),
        INT8_C(10),  INT8_C(-10), INT8_C(25),  INT8_C(30),  INT8_C(15),  INT8_C(-35), INT8_C(25),  INT8_C(35),  INT8_C(35),
        INT8_C(-10), INT8_C(-15), INT8_C(15),  INT8_C(-15), INT8_C(15),  INT8_C(25),  INT8_C(-30), INT8_C(15),  INT8_C(25),
        INT8_C(-5),  INT8_C(-20), INT8_C(30),  INT8_C(-25), INT8_C(-15), INT8_C(40),  INT8_C(40),  INT8_C(40),  INT8_C(15),
        INT8_C(-20), INT8_C(-35), INT8_C(-55), INT8_C(40),  INT8_C(25),  INT8_C(15),  INT8_C(30),  INT8_C(40),  INT8_C(15),
        INT8_C(35),  INT8_C(-15), INT8_C(40),  INT8_C(20),  INT8_C(-45), INT8_C(-20), INT8_C(50),  INT8_C(30),  INT8_C(15),
        INT8_C(-55), INT8_C(-45), INT8_C(-10), INT8_C(50),  INT8_C(60),  INT8_C(-15), INT8_C(-25), INT8_C(15),  INT8_C(15),
        INT8_C(35),  INT8_C(15),  INT8_C(-35), INT8_C(-30), INT8_C(30),  INT8_C(35),  INT8_C(25),  INT8_C(-40), INT8_C(-45),
        INT8_C(-30), INT8_C(-15), INT8_C(60),  INT8_C(20),  INT8_C(-35), INT8_C(-25), INT8_C(-55), INT8_C(65),  INT8_C(50),
        INT8_C(-25), INT8_C(-30), INT8_C(25),  INT8_C(30),  INT8_C(15),  INT8_C(15),  INT8_C(-35), INT8_C(-40), INT8_C(40),
        INT8_C(35),  INT8_C(-35), INT8_C(-50), INT8_C(45),  INT8_C(25),  INT8_C(-25), INT8_C(-40), INT8_C(-35), INT8_C(-30),
        INT8_C(40),  INT8_C(50)}},
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

    simde_hvx_vector_t result = simde_hvx_sub_vb(a, b);

    simde_test_hexagon_hvx_assert_equal_i8(result, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0; i < 1; i++) {
    simde_hvx_vector_t a = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_t b = simde_test_hexagon_hvx_random_vector();
    simde_hvx_vector_t r = simde_hvx_sub_vb(a, b);

    simde_test_hexagon_hvx_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_hexagon_hvx_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_hexagon_hvx_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_sub_vb)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
