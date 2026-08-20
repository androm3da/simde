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

#define SIMDE_TEST_HEXAGON_HVX_INSN vextract

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/vextract.h"

static int
test_simde_vextract_VR(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t v[32];
    int32_t offset;
    int32_t r;
  } test_vec[] = {
    { { INT32_C(0x12345678), -INT32_C(0x65432110), INT32_C(0x11223344), INT32_C(0x55667788),
        -INT32_C(0x55443323), -INT32_C(0x1100FFEF), INT32_C(0x22334455), INT32_C(0x66778899),
        INT32_C(0x01020304), INT32_C(0x05060708), INT32_C(0x090A0B0C), INT32_C(0x0D0E0F10),
        INT32_C(0x11121314), INT32_C(0x15161718), INT32_C(0x191A1B1C), INT32_C(0x1D1E1F20),
        INT32_C(0x21222324), INT32_C(0x25262728), INT32_C(0x292A2B2C), INT32_C(0x2D2E2F30),
        INT32_C(0x31323334), INT32_C(0x35363738), INT32_C(0x393A3B3C), INT32_C(0x3D3E3F40),
        INT32_C(0x41424344), INT32_C(0x45464748), INT32_C(0x494A4B4C), INT32_C(0x4D4E4F50),
        INT32_C(0x51525354), INT32_C(0x55565758), INT32_C(0x595A5B5C), INT32_C(0x5D5E5F60) },
      INT32_C(0), INT32_C(0x12345678) },
    { { INT32_C(0x12345678), -INT32_C(0x65432110), INT32_C(0x11223344), INT32_C(0x55667788),
        -INT32_C(0x55443323), -INT32_C(0x1100FFEF), INT32_C(0x22334455), INT32_C(0x66778899),
        INT32_C(0x01020304), INT32_C(0x05060708), INT32_C(0x090A0B0C), INT32_C(0x0D0E0F10),
        INT32_C(0x11121314), INT32_C(0x15161718), INT32_C(0x191A1B1C), INT32_C(0x1D1E1F20),
        INT32_C(0x21222324), INT32_C(0x25262728), INT32_C(0x292A2B2C), INT32_C(0x2D2E2F30),
        INT32_C(0x31323334), INT32_C(0x35363738), INT32_C(0x393A3B3C), INT32_C(0x3D3E3F40),
        INT32_C(0x41424344), INT32_C(0x45464748), INT32_C(0x494A4B4C), INT32_C(0x4D4E4F50),
        INT32_C(0x51525354), INT32_C(0x55565758), INT32_C(0x595A5B5C), INT32_C(0x5D5E5F60) },
      INT32_C(4), -INT32_C(0x65432110) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_hvx_vector_t v = simde_test_hvx_vector_load(test_vec[i].v);
    int32_t r = simde_Q6_R_vextract_VR(v, test_vec[i].offset);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  simde_hvx_vector_t v = simde_test_hvx_vector_load(test_vec[0].v);
  simde_assert_equal_i32(simde_Q6_R_vextract_VR(v, SIMDE_HVX_VECTOR_SIZE), test_vec[0].v[0]);
  simde_assert_equal_i32(simde_Q6_R_vextract_VR(v, -4), test_vec[0].v[SIMDE_HVX_VECTOR_I32_COUNT - 1]);

  return 0;
#else
  fputc('\n', stdout);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vextract_VR)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
