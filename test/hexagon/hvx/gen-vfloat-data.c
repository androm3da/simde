/* Test data generator for HVX vfloat intrinsics.
 * Cross-compile for Hexagon and run on hardware to produce native reference data.
 *
 * hexagon-linux-musl-clang -mv79 -mhvx=v79 -mhvx-ieee-fp -O2 -o gen-vfloat-data gen-vfloat-data.c
 * ./gen-vfloat-data > vfloat-data.txt
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <hexagon_types.h>
#include <hvx_hexagon_protos.h>

static void print_u8(const char *label, const uint8_t *v, int n) {
  printf("      /* %s */ {", label);
  for (int i = 0; i < n; i++) {
    if (i % 16 == 0 && i > 0) printf("\n                ");
    if (i > 0) printf(", ");
    printf("UINT8_C(%3d)", v[i]);
  }
  printf(" }");
}

/* ---- sf (float32) lanes, 32 lanes of 128 bytes ---- */
static void build_sf(uint32_t *bits, int variant) {
  static const uint32_t base[32] = {
    0x3f800000u, /* 1.0 */
    0xbf800000u, /* -1.0 */
    0x40490fdbu, /* pi */
    0xc0490fdbu, /* -pi */
    0x00000000u, /* +0 */
    0x80000000u, /* -0 */
    0x7f800000u, /* +inf */
    0xff800000u, /* -inf */
    0x7fc00000u, /* qnan */
    0xffc00000u, /* -qnan */
    0x7fa00000u, /* snan-ish (still nan) */
    0x00000001u, /* smallest denormal */
    0x007fffffu, /* largest denormal */
    0x00800000u, /* smallest normal */
    0x7f7fffffu, /* largest normal */
    0x3f000000u, /* 0.5 */
    0xbf000000u, /* -0.5 */
    0x41200000u, /* 10.0 */
    0xc1200000u, /* -10.0 */
    0x3dcccccdu, /* 0.1 */
    0x42f6e979u, /* 123.456 */
    0xc2f6e979u, /* -123.456 */
    0x3f800000u, /* 1.0 (tie with lane 0) */
    0x40000000u, /* 2.0 */
    0xc0000000u, /* -2.0 */
    0x3fc00000u, /* 1.5 */
    0xbfc00000u, /* -1.5 */
    0x3f333333u, /* 0.7 */
    0xbf333333u, /* -0.7 */
    0x4b000000u, /* 8388608.0 */
    0xcb000000u, /* -8388608.0 */
    0x34000000u  /* small normal */
  };
  for (int i = 0; i < 32; i++) {
    uint32_t v = base[i];
    if (variant) {
      /* rotate slightly so B differs from A but shares edge cases shifted */
      v = base[(i + 7) % 32];
    }
    bits[i] = v;
  }
}

/* ---- hf (float16) lanes, 64 lanes of 128 bytes ---- */
static void build_hf(uint16_t *bits, int variant) {
  static const uint16_t base[64] = {
    0x3c00, 0xbc00, 0x4248, 0xc248, 0x0000, 0x8000, 0x7c00, 0xfc00,
    0x7e00, 0xfe00, 0x7d00, 0x0001, 0x03ff, 0x0400, 0x7bff, 0x3800,
    0xb800, 0x4900, 0xc900, 0x2e66, 0x57b7, 0xd7b7, 0x3c00, 0x4000,
    0xc000, 0x3e00, 0xbe00, 0x399a, 0xb99a, 0x6800, 0xe800, 0x1000,
    0x3555, 0xb555, 0x4700, 0xc700, 0x0100, 0x8100, 0x7a00, 0xfa00,
    0x7c80, 0xfc80, 0x7c40, 0x0002, 0x02ff, 0x0500, 0x7aff, 0x3900,
    0xb900, 0x4a00, 0xca00, 0x2f00, 0x5000, 0xd000, 0x3d00, 0x4100,
    0xc100, 0x3f00, 0xbf00, 0x3a00, 0xba00, 0x6000, 0xe000, 0x1100
  };
  for (int i = 0; i < 64; i++) {
    uint16_t v = base[i];
    if (variant) {
      v = base[(i + 11) % 64];
    }
    bits[i] = v;
  }
}

/* ---- f8 (e4m3) lanes, 128 lanes of 128 bytes ----
 * e4m3: sign(1) exp(4, bias 7) mant(3). exp=0xF mant=0x7 is NaN (no inf). */
static void build_f8(uint8_t *bits, int variant) {
  static const uint8_t base[128] = {
    0x38, 0xb8, 0x40, 0xc0, 0x00, 0x80, 0x78, 0xf8, /* 1,-1,2,-2,+0,-0,max,-max */
    0x7f, 0xff, 0x77, 0x01, 0x07, 0x08, 0x7e, 0x30,
    0xb0, 0x44, 0xc4, 0x2e, 0x50, 0xd0, 0x38, 0x48,
    0xc8, 0x34, 0xb4, 0x2c, 0xac, 0x60, 0xe0, 0x10
  };
  for (int i = 0; i < 128; i++) {
    uint8_t v = base[i % 32];
    if (variant) {
      v = base[(i + 5) % 32];
    }
    bits[i] = v;
  }
}

#define BEGIN(name) printf("=== BEGIN vfloat %s ===\n", name)
#define END(name) printf("=== END vfloat %s ===\n", name)

int main(void) {
  /* sf family */
  {
    uint32_t abits[32], bbits[32];
    build_sf(abits, 0);
    build_sf(bbits, 1);
    HVX_Vector a, b, r;
    memcpy(&a, abits, 128);
    memcpy(&b, bbits, 128);

    BEGIN("Q6_Vsf_vfmax_VsfVsf");
    r = Q6_Vsf_vfmax_VsfVsf(a, b);
    printf("    {\n");
    print_u8("a", (uint8_t*)&a, 128); printf(",\n");
    print_u8("b", (uint8_t*)&b, 128); printf(",\n");
    print_u8("r", (uint8_t*)&r, 128); printf("\n");
    printf("    },\n");
    END("Q6_Vsf_vfmax_VsfVsf");

    BEGIN("Q6_Vsf_vfmin_VsfVsf");
    r = Q6_Vsf_vfmin_VsfVsf(a, b);
    printf("    {\n");
    print_u8("a", (uint8_t*)&a, 128); printf(",\n");
    print_u8("b", (uint8_t*)&b, 128); printf(",\n");
    print_u8("r", (uint8_t*)&r, 128); printf("\n");
    printf("    },\n");
    END("Q6_Vsf_vfmin_VsfVsf");

    BEGIN("Q6_Vsf_vfneg_Vsf");
    r = Q6_Vsf_vfneg_Vsf(a);
    printf("    {\n");
    print_u8("a", (uint8_t*)&a, 128); printf(",\n");
    print_u8("r", (uint8_t*)&r, 128); printf("\n");
    printf("    },\n");
    END("Q6_Vsf_vfneg_Vsf");
  }

  /* hf family */
  {
    uint16_t abits[64], bbits[64];
    build_hf(abits, 0);
    build_hf(bbits, 1);
    HVX_Vector a, b, r;
    memcpy(&a, abits, 128);
    memcpy(&b, bbits, 128);

    BEGIN("Q6_Vhf_vfmax_VhfVhf");
    r = Q6_Vhf_vfmax_VhfVhf(a, b);
    printf("    {\n");
    print_u8("a", (uint8_t*)&a, 128); printf(",\n");
    print_u8("b", (uint8_t*)&b, 128); printf(",\n");
    print_u8("r", (uint8_t*)&r, 128); printf("\n");
    printf("    },\n");
    END("Q6_Vhf_vfmax_VhfVhf");

    BEGIN("Q6_Vhf_vfmin_VhfVhf");
    r = Q6_Vhf_vfmin_VhfVhf(a, b);
    printf("    {\n");
    print_u8("a", (uint8_t*)&a, 128); printf(",\n");
    print_u8("b", (uint8_t*)&b, 128); printf(",\n");
    print_u8("r", (uint8_t*)&r, 128); printf("\n");
    printf("    },\n");
    END("Q6_Vhf_vfmin_VhfVhf");

    BEGIN("Q6_Vhf_vfneg_Vhf");
    r = Q6_Vhf_vfneg_Vhf(a);
    printf("    {\n");
    print_u8("a", (uint8_t*)&a, 128); printf(",\n");
    print_u8("r", (uint8_t*)&r, 128); printf("\n");
    printf("    },\n");
    END("Q6_Vhf_vfneg_Vhf");
  }

  /* f8 family */
  {
    uint8_t abits[128], bbits[128];
    build_f8(abits, 0);
    build_f8(bbits, 1);
    HVX_Vector a, b, r;
    memcpy(&a, abits, 128);
    memcpy(&b, bbits, 128);

    BEGIN("Q6_V_vfmax_VV");
    r = Q6_V_vfmax_VV(a, b);
    printf("    {\n");
    print_u8("a", (uint8_t*)&a, 128); printf(",\n");
    print_u8("b", (uint8_t*)&b, 128); printf(",\n");
    print_u8("r", (uint8_t*)&r, 128); printf("\n");
    printf("    },\n");
    END("Q6_V_vfmax_VV");

    BEGIN("Q6_V_vfmin_VV");
    r = Q6_V_vfmin_VV(a, b);
    printf("    {\n");
    print_u8("a", (uint8_t*)&a, 128); printf(",\n");
    print_u8("b", (uint8_t*)&b, 128); printf(",\n");
    print_u8("r", (uint8_t*)&r, 128); printf("\n");
    printf("    },\n");
    END("Q6_V_vfmin_VV");

    BEGIN("Q6_V_vfneg_V");
    r = Q6_V_vfneg_V(a);
    printf("    {\n");
    print_u8("a", (uint8_t*)&a, 128); printf(",\n");
    print_u8("r", (uint8_t*)&r, 128); printf("\n");
    printf("    },\n");
    END("Q6_V_vfneg_V");
  }

  return 0;
}
