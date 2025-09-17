#if !defined(SIMDE_TEST_HEXAGON_RUN_TESTS_H)
#define SIMDE_TEST_HEXAGON_RUN_TESTS_H

#include "../munit/munit.h"

HEDLEY_C_DECL MunitSuite *simde_tests_hexagon_get_suite(void);
HEDLEY_C_DECL MunitSuite *simde_tests_hexagon_hvx_get_suite(void);

#endif /* !defined(SIMDE_TEST_HEXAGON_RUN_TESTS_H) */
