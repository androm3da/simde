#define SIMDE_TEST_HEXAGON_HVX_INSN absdiff

#include "../../../simde/hexagon/hvx/absdiff.h"
#include "test-hvx.h"
#include <string.h>

static int test_simde_hvx_vabsdiff_ub(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vabsdiff_h_uh(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vabsdiff_uh(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vabsdiff_w_uw(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vrsad_ub(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vabsdiff_ub)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vabsdiff_h_uh)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vabsdiff_uh)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vabsdiff_w_uw)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vrsad_ub)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
