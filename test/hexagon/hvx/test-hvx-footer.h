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
 *   2026      Brian Cain <brian.cain@oss.qualcomm.com> (Copyright owned by Qualcomm Technologies, Inc. and its subsidiaries)
 */

#if defined(SIMDE_TEST_BARE)
  int main(void) {
    int retval = EXIT_SUCCESS;

    fprintf(stdout, "1..%zu\n", (sizeof(test_suite_tests) / sizeof(test_suite_tests[0])));
    for (size_t i = 0 ; i < (sizeof(test_suite_tests) / sizeof(test_suite_tests[0])) ; i++) {
      int res = test_suite_tests[i].func();
      if (res != 0) {
        retval = EXIT_FAILURE;
        fprintf(stdout, "not ok %zu " HEDLEY_STRINGIFY(SIMDE_TEST_HEXAGON_HVX_INSN) "/%s\n", i + 1, test_suite_tests[i].name);
      } else {
        fprintf(stdout, "ok %zu " HEDLEY_STRINGIFY(SIMDE_TEST_HEXAGON_HVX_INSN) "/%s\n", i + 1, test_suite_tests[i].name);
      }
    }

    return retval;
  }
#else
  #if defined(__cplusplus)
    static MunitSuite suite = { const_cast<char*>("/" HEDLEY_STRINGIFY(SIMDE_TEST_HEXAGON_HVX_INSN)), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };
  #else
    static MunitSuite suite = { (char*) "/" HEDLEY_STRINGIFY(SIMDE_TEST_HEXAGON_HVX_INSN), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };
  #endif

  HEDLEY_C_DECL MunitSuite*
  SIMDE_TEST_GENERATE_VARIANT_SYMBOL_CURRENT(HEDLEY_CONCAT(simde_test_hexagon_hvx_simd_get_suite_,SIMDE_TEST_HEXAGON_HVX_INSN)) (void) {
    return &suite;
  }
#endif
