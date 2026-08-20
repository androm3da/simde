/* SPDX-License-Identifier: MIT
 *
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 */

#define SIMDE_TEST_HEXAGON_HVX_INSN types

#include "test-hvx.h"
#include "../../../simde/hexagon/hvx/types.h"

static int
test_simde_types_f8e4m3(SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 value;
    uint8_t encoded;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(0.0009765625), UINT8_C(0x00) },
    { SIMDE_FLOAT32_C(0.0029296875), UINT8_C(0x02) },
    { SIMDE_FLOAT32_C(0.0146484375), UINT8_C(0x08) },
    { SIMDE_FLOAT32_C(1.0625), UINT8_C(0x38) },
    { SIMDE_FLOAT32_C(1.1875), UINT8_C(0x3A) },
    { SIMDE_FLOAT32_C(248.0), UINT8_C(0x78) },
    { SIMDE_FLOAT32_C(256.0), UINT8_C(0x78) },
    { SIMDE_FLOAT32_C(288.0), UINT8_C(0x79) },
    { SIMDE_FLOAT32_C(320.0), UINT8_C(0x7A) },
    { SIMDE_FLOAT32_C(352.0), UINT8_C(0x7B) },
    { SIMDE_FLOAT32_C(384.0), UINT8_C(0x7C) },
    { SIMDE_FLOAT32_C(416.0), UINT8_C(0x7D) },
    { SIMDE_FLOAT32_C(448.0), UINT8_C(0x7E) },
    { SIMDE_FLOAT32_C(-1.0625), UINT8_C(0xB8) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_assert_equal_u8(simde_float32_to_f8e4m3(test_vec[i].value), test_vec[i].encoded);
  }
  simde_assert_equal_f32(simde_f8e4m3_to_float32(UINT8_C(0x78)), SIMDE_FLOAT32_C(256.0), 0);
  simde_assert_equal_f32(simde_f8e4m3_to_float32(UINT8_C(0x7E)), SIMDE_FLOAT32_C(448.0), 0);
  for (uint16_t i = 0 ; i < UINT16_C(256) ; i++) {
    uint8_t encoded = HEDLEY_STATIC_CAST(uint8_t, i);
    simde_assert_equal_u8(simde_float32_to_f8e4m3(simde_f8e4m3_to_float32(encoded)), encoded);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(types_f8e4m3)
SIMDE_TEST_FUNC_LIST_END

#include "test-hvx-footer.h"
