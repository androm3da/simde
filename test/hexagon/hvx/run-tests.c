#include "run-tests.h"

#include "../../../simde/hedley.h"

#include "add.c"
#include "mul.c"
#include "sub.c"

static MunitSuite suites[] = {
#define SIMDE_TEST_HEXAGON_HVX_INSN add
    {"/add", simde_test_hexagon_hvx_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE},
#undef SIMDE_TEST_HEXAGON_HVX_INSN

#define SIMDE_TEST_HEXAGON_HVX_INSN mul
    {"/mul", simde_test_hexagon_hvx_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE},
#undef SIMDE_TEST_HEXAGON_HVX_INSN

#define SIMDE_TEST_HEXAGON_HVX_INSN sub
    {"/sub", simde_test_hexagon_hvx_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE},
#undef SIMDE_TEST_HEXAGON_HVX_INSN

    {NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE}};

static MunitSuite suite = {"/hvx", NULL, suites, 1, MUNIT_SUITE_OPTION_NONE};

MunitSuite *simde_tests_hexagon_hvx_get_suite(void) { return &suite; }
