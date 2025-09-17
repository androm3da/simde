#if !defined(SIMDE_TEST_HEXAGON_HVX_TEST_HVX_H)
#define SIMDE_TEST_HEXAGON_HVX_TEST_HVX_H

#include "../../../simde/hexagon/hvx.h"
#include "../../test.h"

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION

/* Helper functions for generating random HVX vectors */
static simde_hvx_vector_t simde_test_hexagon_hvx_random_vector(void) {
  simde_hvx_vector_t v;
  simde_test_codegen_random_memory(sizeof(v), HEDLEY_REINTERPRET_CAST(uint8_t *, &v));
  return v;
}

static simde_hvx_vector_pair_t simde_test_hexagon_hvx_random_vector_pair(void) {
  simde_hvx_vector_pair_t v;
  simde_test_codegen_random_memory(sizeof(v), HEDLEY_REINTERPRET_CAST(uint8_t *, &v));
  return v;
}

/* Helper functions for writing test vectors */
static void simde_test_hexagon_hvx_write_i8(int indent, simde_hvx_vector_t value, SimdeTestVecPos pos) {
  simde_hvx_vector_private val_ = simde_hvx_vector_to_private(value);
  int8_t buf[128];
  simde_memcpy(buf, &val_.i8, sizeof(buf));
  simde_test_codegen_write_vi8(indent, sizeof(buf) / sizeof(buf[0]), buf, pos);
}

static void simde_test_hexagon_hvx_write_i16(int indent, simde_hvx_vector_t value, SimdeTestVecPos pos) {
  simde_hvx_vector_private val_ = simde_hvx_vector_to_private(value);
  int16_t buf[64];
  simde_memcpy(buf, &val_.i16, sizeof(buf));
  simde_test_codegen_write_vi16(indent, sizeof(buf) / sizeof(buf[0]), buf, pos);
}

static void simde_test_hexagon_hvx_write_i32(int indent, simde_hvx_vector_t value, SimdeTestVecPos pos) {
  simde_hvx_vector_private val_ = simde_hvx_vector_to_private(value);
  int32_t buf[32];
  simde_memcpy(buf, &val_.i32, sizeof(buf));
  simde_test_codegen_write_vi32(indent, sizeof(buf) / sizeof(buf[0]), buf, pos);
}

static void simde_test_hexagon_hvx_write_u8(int indent, simde_hvx_vector_t value, SimdeTestVecPos pos) {
  simde_hvx_vector_private val_ = simde_hvx_vector_to_private(value);
  uint8_t buf[128];
  simde_memcpy(buf, &val_.u8, sizeof(buf));
  simde_test_codegen_write_vu8(indent, sizeof(buf) / sizeof(buf[0]), buf, pos);
}

static void simde_test_hexagon_hvx_write_u16(int indent, simde_hvx_vector_t value, SimdeTestVecPos pos) {
  simde_hvx_vector_private val_ = simde_hvx_vector_to_private(value);
  uint16_t buf[64];
  simde_memcpy(buf, &val_.u16, sizeof(buf));
  simde_test_codegen_write_vu16(indent, sizeof(buf) / sizeof(buf[0]), buf, pos);
}

static void simde_test_hexagon_hvx_write_u32(int indent, simde_hvx_vector_t value, SimdeTestVecPos pos) {
  simde_hvx_vector_private val_ = simde_hvx_vector_to_private(value);
  uint32_t buf[32];
  simde_memcpy(buf, &val_.u32, sizeof(buf));
  simde_test_codegen_write_vu32(indent, sizeof(buf) / sizeof(buf[0]), buf, pos);
}

/* Helper functions for writing vector pairs */
static void simde_test_hexagon_hvx_write_pair_i16(int indent, simde_hvx_vector_pair_t value, SimdeTestVecPos pos) {
  simde_hvx_vector_pair_private val_ = simde_hvx_vector_pair_to_private(value);
  int16_t buf[128];
  simde_memcpy(buf, &val_.i16, sizeof(buf));
  simde_test_codegen_write_vi16(indent, sizeof(buf) / sizeof(buf[0]), buf, pos);
}

static void simde_test_hexagon_hvx_write_pair_i32(int indent, simde_hvx_vector_pair_t value, SimdeTestVecPos pos) {
  simde_hvx_vector_pair_private val_ = simde_hvx_vector_pair_to_private(value);
  int32_t buf[64];
  simde_memcpy(buf, &val_.i32, sizeof(buf));
  simde_test_codegen_write_vi32(indent, sizeof(buf) / sizeof(buf[0]), buf, pos);
}

/* Comparison functions for vectors */
static int simde_test_hexagon_hvx_assert_equal_i8(simde_hvx_vector_t a, simde_hvx_vector_t b, const char *filename, int line,
                                                  const char *astr, const char *bstr) {
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < sizeof(a_.i8) / sizeof(a_.i8[0]); i++) {
    if (a_.i8[i] != b_.i8[i]) {
      simde_test_debug_printf_("assertion failed: %s == %s (%s:%d)\n", astr, bstr, filename, line);
      simde_test_debug_printf_("  [%3zu]: %" PRIi8 " != %" PRIi8 "\n", i, a_.i8[i], b_.i8[i]);
      return 1;
    }
  }
  return 0;
}

static int simde_test_hexagon_hvx_assert_equal_i16(simde_hvx_vector_t a, simde_hvx_vector_t b, const char *filename,
                                                   int line, const char *astr, const char *bstr) {
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < sizeof(a_.i16) / sizeof(a_.i16[0]); i++) {
    if (a_.i16[i] != b_.i16[i]) {
      simde_test_debug_printf_("assertion failed: %s == %s (%s:%d)\n", astr, bstr, filename, line);
      simde_test_debug_printf_("  [%3zu]: %" PRIi16 " != %" PRIi16 "\n", i, a_.i16[i], b_.i16[i]);
      return 1;
    }
  }
  return 0;
}

static int simde_test_hexagon_hvx_assert_equal_i32(simde_hvx_vector_t a, simde_hvx_vector_t b, const char *filename,
                                                   int line, const char *astr, const char *bstr) {
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < sizeof(a_.i32) / sizeof(a_.i32[0]); i++) {
    if (a_.i32[i] != b_.i32[i]) {
      simde_test_debug_printf_("assertion failed: %s == %s (%s:%d)\n", astr, bstr, filename, line);
      simde_test_debug_printf_("  [%3zu]: %" PRIi32 " != %" PRIi32 "\n", i, a_.i32[i], b_.i32[i]);
      return 1;
    }
  }
  return 0;
}

static int simde_test_hexagon_hvx_assert_equal_u8(simde_hvx_vector_t a, simde_hvx_vector_t b, const char *filename, int line,
                                                  const char *astr, const char *bstr) {
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < sizeof(a_.u8) / sizeof(a_.u8[0]); i++) {
    if (a_.u8[i] != b_.u8[i]) {
      simde_test_debug_printf_("assertion failed: %s == %s (%s:%d)\n", astr, bstr, filename, line);
      simde_test_debug_printf_("  [%3zu]: %" PRIu8 " != %" PRIu8 "\n", i, a_.u8[i], b_.u8[i]);
      return 1;
    }
  }
  return 0;
}

static int simde_test_hexagon_hvx_assert_equal_u16(simde_hvx_vector_t a, simde_hvx_vector_t b, const char *filename,
                                                   int line, const char *astr, const char *bstr) {
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < sizeof(a_.u16) / sizeof(a_.u16[0]); i++) {
    if (a_.u16[i] != b_.u16[i]) {
      simde_test_debug_printf_("assertion failed: %s == %s (%s:%d)\n", astr, bstr, filename, line);
      simde_test_debug_printf_("  [%3zu]: %" PRIu16 " != %" PRIu16 "\n", i, a_.u16[i], b_.u16[i]);
      return 1;
    }
  }
  return 0;
}

static int simde_test_hexagon_hvx_assert_equal_u32(simde_hvx_vector_t a, simde_hvx_vector_t b, const char *filename,
                                                   int line, const char *astr, const char *bstr) {
  simde_hvx_vector_private a_ = simde_hvx_vector_to_private(a), b_ = simde_hvx_vector_to_private(b);

  for (size_t i = 0; i < sizeof(a_.u32) / sizeof(a_.u32[0]); i++) {
    if (a_.u32[i] != b_.u32[i]) {
      simde_test_debug_printf_("assertion failed: %s == %s (%s:%d)\n", astr, bstr, filename, line);
      simde_test_debug_printf_("  [%3zu]: %" PRIu32 " != %" PRIu32 "\n", i, a_.u32[i], b_.u32[i]);
      return 1;
    }
  }
  return 0;
}

/* Comparison functions for vector pairs */
static int simde_test_hexagon_hvx_assert_equal_pair_i16(simde_hvx_vector_pair_t a, simde_hvx_vector_pair_t b,
                                                        const char *filename, int line, const char *astr, const char *bstr) {
  simde_hvx_vector_pair_private a_ = a, b_ = b;

  for (size_t i = 0; i < sizeof(a_.i16) / sizeof(a_.i16[0]); i++) {
    if (a_.i16[i] != b_.i16[i]) {
      simde_test_debug_printf_("assertion failed: %s == %s (%s:%d)\n", astr, bstr, filename, line);
      simde_test_debug_printf_("  [%3zu]: %" PRIi16 " != %" PRIi16 "\n", i, a_.i16[i], b_.i16[i]);
      return 1;
    }
  }
  return 0;
}

static int simde_test_hexagon_hvx_assert_equal_pair_i32(simde_hvx_vector_pair_t a, simde_hvx_vector_pair_t b,
                                                        const char *filename, int line, const char *astr, const char *bstr) {
  simde_hvx_vector_pair_private a_ = a, b_ = b;

  for (size_t i = 0; i < sizeof(a_.i32) / sizeof(a_.i32[0]); i++) {
    if (a_.i32[i] != b_.i32[i]) {
      simde_test_debug_printf_("assertion failed: %s == %s (%s:%d)\n", astr, bstr, filename, line);
      simde_test_debug_printf_("  [%3zu]: %" PRIi32 " != %" PRIi32 "\n", i, a_.i32[i], b_.i32[i]);
      return 1;
    }
  }
  return 0;
}

/* Macros for easier testing */
#define simde_test_hexagon_hvx_assert_equal_i8(a, b) simde_test_hexagon_hvx_assert_equal_i8(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_hexagon_hvx_assert_equal_i16(a, b)                                                                       \
  simde_test_hexagon_hvx_assert_equal_i16(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_hexagon_hvx_assert_equal_i32(a, b)                                                                       \
  simde_test_hexagon_hvx_assert_equal_i32(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_hexagon_hvx_assert_equal_u8(a, b) simde_test_hexagon_hvx_assert_equal_u8(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_hexagon_hvx_assert_equal_u16(a, b)                                                                       \
  simde_test_hexagon_hvx_assert_equal_u16(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_hexagon_hvx_assert_equal_u32(a, b)                                                                       \
  simde_test_hexagon_hvx_assert_equal_u32(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_hexagon_hvx_assert_equal_pair_i16(a, b)                                                                  \
  simde_test_hexagon_hvx_assert_equal_pair_i16(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_hexagon_hvx_assert_equal_pair_i32(a, b)                                                                  \
  simde_test_hexagon_hvx_assert_equal_pair_i32(a, b, __FILE__, __LINE__, #a, #b)

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_TEST_HEXAGON_HVX_TEST_HVX_H) */
