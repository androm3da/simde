#define SIMDE_TEST_HEXAGON_HVX_INSN lut

#include "../../../simde/hexagon/hvx/lut.h"
#include "test-hvx.h"
#include <string.h>

static int test_simde_hvx_vlut32_bbb(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_valign_vvr(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vdeal_b(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vlut4_uh_ph(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vdelta_vv(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vlut32_bbb)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_valign_vvr)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vdeal_b)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vlut4_uh_ph)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vdelta_vv)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
