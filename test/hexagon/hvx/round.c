#define SIMDE_TEST_HEXAGON_HVX_INSN round

#include "../../../simde/hexagon/hvx/round.h"
#include "test-hvx.h"
#include <string.h>

static int test_simde_hvx_vpack_hh_sat_b(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vpack_hh_sat_ub(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vpack_ww_sat_h(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vround_hh_sat_ub(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vadd_h_sat(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vpack_hh_sat_b)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vpack_hh_sat_ub)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vpack_ww_sat_h)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vround_hh_sat_ub)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vadd_h_sat)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
