#include <stdint.h>
#include <stdio.h>
#include <string.h>

void intt_range_vlen128()
{
    float r[256], t;
    unsigned int start, len, i, j, k, level = 0;

    // Through exhaustive testing, it is found that for any 16-bit signed
    // number, after using Montgomery modular multiplication to multiply
    // the mont^2/128 constant, the coefficient range is [-1999,1999]. Note
    // that 2^15/1999 is approximately 16.392, and 1999/3329 is
    // approximately 0.6005.
    for (k = 0; k < 256; k++)
        r[k] = 0.6005;

    for (len = 2; len <= 128; len <<= 1, level++) {
        for (start = 0; start < 256; start = j + len) {
            for (j = start; j < start + len; j++) {
                r[j] += r[j + len];
                r[j + len] = 1;
            }
        }
        if (level == 3)
            // a_{0-3+32j}
            for (k = 0; k < 256; k += 32)
                for (i = k; i < k + 4; i++)
                    r[i] = 0.5;
        if (level == 4)
            // a_{4-7+64j}
            for (k = 0; k < 256; k += 64)
                for (i = k + 4; i < k + 8; i++)
                    r[i] = 0.5;
        if (level == 5)
            // a_{8-15+128j}
            for (k = 0; k < 256; k += 128)
                for (i = k + 8; i < k + 16; i++)
                    r[i] = 0.5;
        printf("level %d:\n", level);
        for (k = 0; k < 256; k++) {
            if (k % 16 == 0 && k != 0)
                printf("\n");
            if (r[k] == 1.0)
                continue;
            printf("a[%d]: %.1f, ", k, r[k]);
        }
        printf("\n\n");
    }
}

void intt_range_vlen256()
{
    float r[256], t;
    unsigned int start, len, i, j, k, level = 0;

    // Through exhaustive testing, it is found that for any 16-bit signed
    // number, after using Montgomery modular multiplication to multiply
    // the mont^2/128 constant, the coefficient range is [-1999,1999]. Note
    // that 2^15/1999 is approximately 16.392, and 1999/3329 is
    // approximately 0.6005.
    for (k = 0; k < 256; k++)
        r[k] = 0.6005;

    for (len = 2; len <= 128; len <<= 1, level++) {
        for (start = 0; start < 256; start = j + len) {
            for (j = start; j < start + len; j++) {
                r[j] += r[j + len];
                r[j + len] = 1;
            }
        }
        if (level == 3)
            // a_{0-3+32j}
            for (k = 0; k < 256; k += 32)
                for (i = k; i < k + 4; i++)
                    r[i] = 0.5;
        if (level == 4)
            // a_{4-7+64j}
            for (k = 0; k < 256; k += 64)
                for (i = k + 4; i < k + 8; i++)
                    r[i] = 0.5;
        if (level == 5)
            // a_{8-15+128j}
            for (k = 0; k < 256; k += 128)
                for (i = k + 8; i < k + 16; i++)
                    r[i] = 0.5;
        printf("level %d:\n", level);
        for (k = 0; k < 256; k++) {
            if (k % 16 == 0 && k != 0)
                printf("\n");
            if (r[k] == 1.0)
                continue;
            printf("a[%d]: %.1f, ", k, r[k]);
        }
        printf("\n\n");
    }
}

int main()
{
    intt_range_vlen128();
    // intt_range_vlen256();
    return 0;
}