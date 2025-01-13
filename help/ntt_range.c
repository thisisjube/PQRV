#include <stdint.h>
#include <stdio.h>
#include <string.h>

void intt_range()
{
    float r[256], t;
    unsigned int start, len, i, j, k, level = 0;

    for (k = 0; k < 256; k++)
        r[k] = 1;

    for (len = 2; len <= 128; len <<= 1, level++) {
        for (start = 0; start < 256; start = j + len) {
            for (j = start; j < start + len; j++) {
                r[j] += r[j + len];
                r[j + len] = 1;
            }
        }
        if (level == 2)
            // a_{0/1+32j}
            for (k = 0; k < 256; k += 32)
                for (i = k; i < k + 2; i++)
                    r[i] = 0.5;
        if (level == 3)
            // a_{0-3+64j}
            for (k = 0; k < 256; k += 64)
                for (i = k; i < k + 4; i++)
                    r[i] = 0.5;
        if (level == 4)
            // a_{0-7+128j}
            for (k = 0; k < 256; k += 128)
                for (i = k; i < k + 8; i++)
                    r[i] = 0.5;
        if (level == 5)
            // a_{0-15+128j}
            for (k = 0; k < 256; k += 128)
                for (i = k; i < k + 16; i++)
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
    intt_range();
    return 0;
}