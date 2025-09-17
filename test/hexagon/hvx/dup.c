#define SIMDE_TEST_HEXAGON_HVX_INSN dup

#include "../../../simde/hexagon/hvx/dup.h"
#include "test-hvx.h"
#include <string.h>

static int test_simde_hvx_vsplat_w(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vsplat_h(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vsplat_b(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

static int test_simde_hvx_vzero(SIMDE_MUNIT_TEST_ARGS) { return 0; /* Basic stub test - implement later */ }

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vsplat_w)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vsplat_h)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vsplat_b)
SIMDE_TEST_FUNC_LIST_ENTRY(hvx_vzero)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
