#include <stdio.h>
#include <string.h>

#include "cpucycles.h"
#include "speed_print.h"

void print_bytes(uint8_t *buf, size_t len)
{
    int i;
    for (i = 0; i < len - 1; i++)
        printf("%u, ", buf[i]);
    printf("%u\n", buf[i]);
}

void print_u16(uint16_t *buf, size_t len)
{
    int i;
    uint16_t *p = (uint16_t *)buf;
    for (i = 0; i < len - 1; i++)
        printf("%u, ", p[i]);
    printf("%u\n", p[i]);
}
void print_poly(int16_t *a, size_t n)
{
    int i;
    for (i = 0; i < n; i++) {
        if (i != 0 && i % 16 == 0)
            printf("\n");
        printf("%d, ", a[i]);
    }
    printf("\n\n");
}

void print_i16(int16_t *buf, size_t len)
{
    int i;
    int16_t *p = buf;
    for (i = 0; i < len - 1; i++)
        printf("%d, ", p[i]);
    printf("%d\n", p[i]);
}

#define KYBER_Q 3329
#define KYBER_N 256
#define REJ_UNIFORM_BUFLEN 504

int poly_equal(int16_t *a, int16_t *b, size_t n)
{
    size_t i;
    int ok = 1;
    for (i = 0; i < n; i++) {
        if (((a[i] + KYBER_Q * 10) % KYBER_Q) !=
            ((b[i] + KYBER_Q * 10) % KYBER_Q)) {
            ok = 0;
            break;
        }
    }
    return ok;
}

unsigned int rej_uniform(int16_t *r, unsigned int len, const uint8_t *buf,
                         unsigned int buflen)
{
    unsigned int ctr, pos;
    uint16_t val0, val1;

    ctr = pos = 0;
    while (ctr < len && pos + 3 <= buflen) {
        val0 =
            ((buf[pos + 0] >> 0) | ((uint16_t)buf[pos + 1] << 8)) & 0xFFF;
        val1 =
            ((buf[pos + 1] >> 4) | ((uint16_t)buf[pos + 2] << 4)) & 0xFFF;
        pos += 3;

        if (val0 < KYBER_Q)
            r[ctr++] = val0;
        if (ctr < len && val1 < KYBER_Q)
            r[ctr++] = val1;
    }

    return ctr;
}

static uint32_t load32_littleendian(const uint8_t x[4])
{
    uint32_t r;
    r = (uint32_t)x[0];
    r |= (uint32_t)x[1] << 8;
    r |= (uint32_t)x[2] << 16;
    r |= (uint32_t)x[3] << 24;
    return r;
}

static void cbd2(int16_t *r, const uint8_t buf[2 * KYBER_N / 4])
{
    unsigned int i, j;
    uint32_t t, d;
    int16_t a, b;

    for (i = 0; i < KYBER_N / 8; i++) {
        t = load32_littleendian(buf + 4 * i);
        d = t & 0x55555555;
        d += (t >> 1) & 0x55555555;

        for (j = 0; j < 8; j++) {
            a = (d >> (4 * j + 0)) & 0x3;
            b = (d >> (4 * j + 2)) & 0x3;
            r[8 * i + j] = a - b;
        }
    }
}

static uint32_t load24_littleendian(const uint8_t x[3])
{
    uint32_t r;
    r = (uint32_t)x[0];
    r |= (uint32_t)x[1] << 8;
    r |= (uint32_t)x[2] << 16;
    return r;
}

static void cbd3(int16_t *r, const uint8_t buf[3 * KYBER_N / 4])
{
    unsigned int i, j;
    uint32_t t, d;
    int16_t a, b;

    for (i = 0; i < KYBER_N / 4; i++) {
        t = load24_littleendian(buf + 3 * i);
        d = t & 0x00249249;
        d += (t >> 1) & 0x00249249;
        d += (t >> 2) & 0x00249249;

        for (j = 0; j < 4; j++) {
            a = (d >> (6 * j + 0)) & 0x7;
            b = (d >> (6 * j + 3)) & 0x7;
            r[4 * i + j] = a - b;
        }
    }
}

extern const int16_t qdata_vlen128[1472];
extern int16_t *rej_uniform_rvv_vlen128(int16_t *r, const uint8_t *buf,
                                const int16_t *table, uint32_t *ctr_p,
                                uint32_t *pos_p);
extern void cbd2_rvv_vlen128(int16_t *r, const uint8_t *buf, const int16_t *table);
extern void cbd3_rvv_vlen128(int16_t *r, const uint8_t *buf, const int16_t *table);

#define NTESTS 1000
uint64_t t[NTESTS];

int main()
{
    int32_t ctr = 0, pos = 0;
    int16_t r0[256], r1[256];
    int i;
    uint8_t buf[REJ_UNIFORM_BUFLEN + 32 - 24];

    for (i = 0; i < REJ_UNIFORM_BUFLEN + 32 - 24; i++)
        buf[i] = i;
    int16_t *p = rej_uniform_rvv_vlen128(r0, buf, qdata_vlen128, &ctr, &pos);
    printf("ctr is %d\n", ctr);
    rej_uniform(r1, 256, buf, REJ_UNIFORM_BUFLEN);
    if (poly_equal(r0, r1, ctr) != 1) {
        printf("rej_uniform_rvv_vlen128\n");
        print_poly(r0, ctr);
        print_poly(r1, ctr);
    }

    cbd2_rvv_vlen128(r0, buf, qdata_vlen128);
    cbd2(r1, buf);
    if (poly_equal(r0, r1, KYBER_N) != 1) {
        printf("cbd2_rvv_vlen128\n");
        print_poly(r0, KYBER_N);
        print_poly(r1, KYBER_N);
    }

    cbd3_rvv_vlen128(r0, buf, qdata_vlen128);
    cbd3(r1, buf);
    if (poly_equal(r0, r1, KYBER_N) != 1) {
        printf("cbd3_rvv_vlen128\n");
        print_poly(r0, KYBER_N);
        print_poly(r1, KYBER_N);
    }

    PERF(rej_uniform_rvv_vlen128(r0, buf, qdata_vlen128, &ctr, &pos), rej_uniform_rvv_vlen128);
    PERF(rej_uniform(r0, 256, buf, REJ_UNIFORM_BUFLEN), rej_uniform);
    PERF(cbd2_rvv_vlen128(r0, buf, qdata_vlen128), cbd2_rvv_vlen128);
    PERF(cbd2(r1, buf), cbd2);
    PERF(cbd3_rvv_vlen128(r0, buf, qdata_vlen128), cbd3_rvv_vlen128);
    PERF(cbd3(r1, buf), cbd3);

    return 0;
}