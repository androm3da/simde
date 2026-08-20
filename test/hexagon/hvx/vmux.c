/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   Qualcomm Technologies, Inc. and/or its subsidiaries.
 */

#define SIMDE_TEST_HEXAGON_HVX_INSN vmux

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vmux.h"

static int
test_simde_vmux_QVV(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  /* When pred byte is 0xFF, pick from Vu; when 0x00, pick from Vv */
  static const struct {
    uint8_t pred[128];
    int8_t vu[128];
    int8_t vv[128];
    int8_t r[128];
  } test_vec[] = {
    { /* pred - alternating 0xFF/0x00 */
      { 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00,
        0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00 },
      /* vu = all 0x55 */
      {  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),
         INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85),  INT8_C(  85) },
      /* vv = all 0xAA */
      { -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86),
        -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86), -INT8_C(  86) },
            {  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),
         INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86),  INT8_C(  85), -INT8_C(  86) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vectorpred_t pred = simde_test_hvx_vectorpred_load(test_vec[i].pred);
    simde_hvx_vector_t vu = simde_test_hvx_vector_load(test_vec[i].vu);
    simde_hvx_vector_t vv = simde_test_hvx_vector_load(test_vec[i].vv);
    simde_hvx_vector_t r = simde_Q6_V_vmux_QVV(pred, vu, vv);

    simde_test_hvx_vector_i8_assert_equal(r, simde_test_hvx_vector_load(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmux_QVV)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
