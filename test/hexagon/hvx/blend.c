#define SIMDE_TEST_HEXAGON_HVX_INSN blend

#include "../../../simde/hexagon/hvx/blend.h"
#include "test-hvx.h"
#include <string.h>

static int test_simde_hvx_vmux(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vand_pred(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vand_pred_not(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vcmp_eq_b(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vcmp_gt_b(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vmux)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vand_pred)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vand_pred_not)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vcmp_eq_b)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vcmp_gt_b)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
