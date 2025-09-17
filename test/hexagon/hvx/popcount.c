#define SIMDE_TEST_HEXAGON_HVX_INSN popcount

#include "../../../simde/hexagon/hvx/popcount.h"
#include "test-hvx.h"
#include <string.h>

static int test_simde_hvx_vpopcount_h(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vcl0_uh(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vcl0_uw(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vnormamt_h(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vnormamt_w(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vror(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vpopcount_h)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vcl0_uh)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vcl0_uw)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vnormamt_h)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vnormamt_w)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vror)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
