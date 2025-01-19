#include <stdint.h>
#include <stdio.h>

#define Q 3329
#define QINV -3327  // Q * QINV = 1 mod 2^16
#define MONT -1044  // 2^16 mod Q

int16_t root = 17;

int32_t treeNTT_7layer[] = {
    64, 32, 96,  16, 80, 48, 112, 8,  72, 40, 104, 24, 88, 56, 120, 4,
    68, 36, 100, 20, 84, 52, 116, 12, 76, 44, 108, 28, 92, 60, 124, 2,
    66, 34, 98,  18, 82, 50, 114, 10, 74, 42, 106, 26, 90, 58, 122, 6,
    70, 38, 102, 22, 86, 54, 118, 14, 78, 46, 110, 30, 94, 62, 126, 1,
    65, 33, 97,  17, 81, 49, 113, 9,  73, 41, 105, 25, 89, 57, 121, 5,
    69, 37, 101, 21, 85, 53, 117, 13, 77, 45, 109, 29, 93, 61, 125, 3,
    67, 35, 99,  19, 83, 51, 115, 11, 75, 43, 107, 27, 91, 59, 123, 7,
    71, 39, 103, 23, 87, 55, 119, 15, 79, 47, 111, 31, 95, 63, 127};

int32_t treeINTT_7layer[] = {
    1, 65, 33, 97,  17, 81, 49, 113, 9,  73, 41, 105, 25, 89, 57, 121,
    5, 69, 37, 101, 21, 85, 53, 117, 13, 77, 45, 109, 29, 93, 61, 125,
    3, 67, 35, 99,  19, 83, 51, 115, 11, 75, 43, 107, 27, 91, 59, 123,
    7, 71, 39, 103, 23, 87, 55, 119, 15, 79, 47, 111, 31, 95, 63, 127,
    2, 66, 34, 98,  18, 82, 50, 114, 10, 74, 42, 106, 26, 90, 58, 122,
    6, 70, 38, 102, 22, 86, 54, 118, 14, 78, 46, 110, 30, 94, 62, 126,
    4, 68, 36, 100, 20, 84, 52, 116, 12, 76, 44, 108, 28, 92, 60, 124,
    8, 72, 40, 104, 24, 88, 56, 120, 16, 80, 48, 112, 32, 96, 64};

// 1+6 layer merging
int32_t treeNTTMerged_7layer[] = {
    64, 32, 16,  80,  8,  72, 40,  104, 4,  68, 36,  100, 20, 84, 52,  116,
    2,  66, 34,  98,  18, 82, 50,  114, 10, 74, 42,  106, 26, 90, 58,  122,
    1,  65, 33,  97,  17, 81, 49,  113, 9,  73, 41,  105, 25, 89, 57,  121,
    5,  69, 37,  101, 21, 85, 53,  117, 13, 77, 45,  109, 29, 93, 61,  125,
    96, 48, 112, 24,  88, 56, 120, 12,  76, 44, 108, 28,  92, 60, 124, 6,
    70, 38, 102, 22,  86, 54, 118, 14,  78, 46, 110, 30,  94, 62, 126, 3,
    67, 35, 99,  19,  83, 51, 115, 11,  75, 43, 107, 27,  91, 59, 123, 7,
    71, 39, 103, 23,  87, 55, 119, 15,  79, 47, 111, 31,  95, 63, 127};

int32_t treeINTTMerged_7layer[] = {
    1,   65,  33,  97,  17,  81,  49,  113, 9,   73,  41,  105, 25,
    89,  57,  121, 5,   69,  37,  101, 21,  85,  53,  117, 13,  77,
    45,  109, 29,  93,  61,  125, 2,   66,  34,  98,  18,  82,  50,
    114, 10,  74,  42,  106, 26,  90,  58,  122, 4,   68,  36,  100,
    20,  84,  52,  116, 8,   72,  40,  104, 16,  80,  32,  3,   67,
    35,  99,  19,  83,  51,  115, 11,  75,  43,  107, 27,  91,  59,
    123, 7,   71,  39,  103, 23,  87,  55,  119, 15,  79,  47,  111,
    31,  95,  63,  127, 6,   70,  38,  102, 22,  86,  54,  118, 14,
    78,  46,  110, 30,  94,  62,  126, 12,  76,  44,  108, 28,  92,
    60,  124, 24,  88,  56,  120, 48,  112, 96,  64};

int32_t treeMulTable_7layer[] = {
    1,   129, 65,  193, 33,  161, 97,  225, 17,  145, 81,  209, 49,
    177, 113, 241, 9,   137, 73,  201, 41,  169, 105, 233, 25,  153,
    89,  217, 57,  185, 121, 249, 5,   133, 69,  197, 37,  165, 101,
    229, 21,  149, 85,  213, 53,  181, 117, 245, 13,  141, 77,  205,
    45,  173, 109, 237, 29,  157, 93,  221, 61,  189, 125, 253, 3,
    131, 67,  195, 35,  163, 99,  227, 19,  147, 83,  211, 51,  179,
    115, 243, 11,  139, 75,  203, 43,  171, 107, 235, 27,  155, 91,
    219, 59,  187, 123, 251, 7,   135, 71,  199, 39,  167, 103, 231,
    23,  151, 87,  215, 55,  183, 119, 247, 15,  143, 79,  207, 47,
    175, 111, 239, 31,  159, 95,  223, 63,  191, 127, 255};

int16_t MontReduce(int32_t a)
{
    int16_t t;

    t = (int16_t)a * QINV;
    t = (a - (int32_t)t * Q) >> 16;
    return t;
}

int16_t FqMul(int16_t a, int16_t b)
{
    return MontReduce((int32_t)a * b);
}

int16_t Pow(int16_t root, int32_t n)
{
    int16_t t = 1;
    for (int i = 0; i < n; i++) {
        t = FqMul(t, ((int32_t)root * MONT) % Q);
    }
    return t;
}

void GenTables_7layer_VLEN128(void)
{
    int32_t t;
    int16_t t0;
    int32_t table_zeta[128], table_zetaqinv[128];
    size_t index;
    for (int j = 0, index = 0; j < 127; j++, index++) {
        t = Pow(root, treeNTT_7layer[j]);
        t = FqMul(t, ((int32_t)MONT * MONT) % Q);
        t0 = (t * QINV) & 0xffff;
        table_zeta[index] = t;
        table_zetaqinv[index] = t0;
    }

    /**
     * index:                  P0 | P1
     * l0: 0
     * l1: 1,2          1         | 2
     * l2: 3,4,5,6      3,4       | 5,6
     * l3: 7,...,14     7,...,10  | 11,...,14
     * l4: 15,...,30    15,...,22 | 23,...,30
     * l5: 31,...,62    31,...,46 | 47,...,62
     * l6: 63,...,126   63,...,94 | 95,...,126
     */
    printf("NTT & RVV & VLEN=128\n");
    printf("\n#define _ZETAS_EXP\n");
    printf("%d, ", table_zetaqinv[0]);
    printf("%d, ", table_zeta[0]);
    // PART 0
    printf("\n#define _ZETAS_EXP_1TO6_P0_L1\n");
    printf("%d, ", table_zetaqinv[1]);
    printf("%d, ", table_zeta[1]);
    printf("\n#define _ZETAS_EXP_1TO6_P0_L2\n");
    for (index = 3; index <= 4; index++) {
        printf("%d, ", table_zetaqinv[index]);
        printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETAS_EXP_1TO6_P0_L3\n");
    for (index = 7; index <= 10; index++) {
        for (int k = 0; k < 2; k++)
            printf("%d, ", table_zetaqinv[index]);
    }
    for (index = 7; index <= 10; index++) {
        for (int k = 0; k < 2; k++)
            printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETAS_EXP_1TO6_P0_L4\n");
    for (index = 15; index <= 22; index++) {
        printf("%d, ", table_zetaqinv[index]);
    }
    for (index = 15; index <= 22; index++) {
        printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETAS_EXP_1TO6_P0_L5\n");
    index = 31;
    for (int k = 0; k <= 7; k++)
        printf("%d, ", table_zetaqinv[index + k * 2]);
    for (int k = 0; k <= 7; k++)
        printf("%d, ", table_zeta[index + k * 2]);
    index = 32;
    for (int k = 0; k <= 7; k++)
        printf("%d, ", table_zetaqinv[index + k * 2]);
    for (int k = 0; k <= 7; k++)
        printf("%d, ", table_zeta[index + k * 2]);
    printf("\n#define _ZETAS_EXP_1TO6_P0_L6\n");
    for (index = 63; index <= 66; index++) {
        for (int j = 0; j <= 7; j++)
            printf("%d, ", table_zeta[index + j * 4]);
    }
    // PART 1
    printf("\n#define _ZETAS_EXP_1TO6_P1_L1\n");
    printf("%d, ", table_zetaqinv[2]);
    printf("%d, ", table_zeta[2]);
    printf("\n#define _ZETAS_EXP_1TO6_P1_L2\n");
    for (index = 5; index <= 6; index++) {
        printf("%d, ", table_zetaqinv[index]);
        printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETAS_EXP_1TO6_P1_L3\n");
    for (index = 11; index <= 14; index++) {
        for (int k = 0; k < 2; k++)
            printf("%d, ", table_zetaqinv[index]);
    }
    for (index = 11; index <= 14; index++) {
        for (int k = 0; k < 2; k++)
            printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETAS_EXP_1TO6_P1_L4\n");
    for (index = 23; index <= 30; index++) {
        printf("%d, ", table_zetaqinv[index]);
    }
    for (index = 23; index <= 30; index++) {
        printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETAS_EXP_1TO6_P1_L5\n");
    index = 47;
    for (int k = 0; k <= 7; k++)
        printf("%d, ", table_zetaqinv[index + k * 2]);
    for (int k = 0; k <= 7; k++)
        printf("%d, ", table_zeta[index + k * 2]);
    index = 48;
    for (int k = 0; k <= 7; k++)
        printf("%d, ", table_zetaqinv[index + k * 2]);
    for (int k = 0; k <= 7; k++)
        printf("%d, ", table_zeta[index + k * 2]);
    printf("\n#define _ZETAS_EXP_1TO6_P1_L6\n");
    for (index = 95; index <= 98; index++) {
        for (int j = 0; j <= 7; j++)
            printf("%d, ", table_zeta[index + j * 4]);
    }

    printf("\n\nPoint-wise multiplication\n");
    for (int j = 0, index = 0; j < 128; j++, index++) {
        t = Pow(root, treeMulTable_7layer[j]);
        t = FqMul(t, ((int32_t)MONT * MONT) % Q);
        t0 = (t * QINV) & 0xffff;
        table_zeta[index] = t;
        table_zetaqinv[index] = t0;
    }
    for (int i = 0; i <= 7; i++)
        for (int k = 0; k <= 7; k++)
            printf("%d, ", table_zeta[i + k * 8]);
    printf("\n");
    for (int i = 64; i <= 64 + 7; i++)
        for (int k = 0; k <= 7; k++)
            printf("%d, ", table_zeta[i + k * 8]);
    printf("\n\n");

    printf("INTT & RVV & VLEN=128\n");
    for (int j = 0, index = 0; j < 127; j++, index++) {
        t = Pow(root, 256 - treeINTTMerged_7layer[j]);
        t = FqMul(t, ((int32_t)MONT * MONT) % Q);
        t0 = (t * QINV) & 0xffff;
        table_zeta[index] = t;
        table_zetaqinv[index] = t0;
    }
    /**
     * index:     P0 | P1
     * l0: 0, ...,31 | 63,...,94
     * l1: 32,...,47 | 95,...,110
     * l2: 48,...,55 | 111,..,118
     * l3: 56,...,59 | 119,..,122
     * l4: 60,61     | 123,124
     * l5: 62        | 125
     * l6: 126
     */
    // PART 0
    printf("\n#define _ZETA_EXP_INTT_0TO5_P0_L0\n");
    for (index = 0; index <= 3; index++) {
        for (int j = 0; j <= 7; j++)
            printf("%d, ", table_zeta[index + j * 4]);
    }
    printf("\n#define _ZETA_EXP_INTT_0TO5_P0_L1\n");
    for (index = 32; index <= 33; index++) {
        for (int j = 0; j <= 7; j++)
            printf("%d, ", table_zetaqinv[index + j * 2]);
        for (int j = 0; j <= 7; j++)
            printf("%d, ", table_zeta[index + j * 2]);
    }
    printf("\n#define _ZETA_EXP_INTT_0TO5_P0_L2\n");
    for (index = 48; index <= 55; index++) {
        printf("%d, ", table_zetaqinv[index]);
    }
    for (index = 48; index <= 55; index++) {
        printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETA_EXP_INTT_0TO5_P0_L3\n");
    for (index = 56; index <= 59; index++) {
        for (int k = 0; k < 2; k++)
            printf("%d, ", table_zetaqinv[index]);
    }
    for (index = 56; index <= 59; index++) {
        for (int k = 0; k < 2; k++)
            printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETA_EXP_INTT_0TO5_P0_L4\n");
    for (index = 60; index <= 61; index++) {
        for (int k = 0; k < 4; k++)
            printf("%d, ", table_zetaqinv[index]);
    }
    for (index = 60; index <= 61; index++) {
        for (int k = 0; k < 4; k++)
            printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETA_EXP_INTT_0TO5_P0_L5\n");
    for (index = 62; index <= 62; index++) {
        printf("%d, ", table_zetaqinv[index]);
        printf("%d, ", table_zeta[index]);
    }
    // PART 1
    printf("\n#define _ZETA_EXP_INTT_0TO5_P1_L0\n");
    for (index = 63; index <= 66; index++) {
        for (int j = 0; j <= 7; j++)
            printf("%d, ", table_zeta[index + j * 4]);
    }
    printf("\n#define _ZETA_EXP_INTT_0TO5_P1_L1\n");
    for (index = 95; index <= 96; index++) {
        for (int j = 0; j <= 7; j++)
            printf("%d, ", table_zetaqinv[index + j * 2]);
        for (int j = 0; j <= 7; j++)
            printf("%d, ", table_zeta[index + j * 2]);
    }
    printf("\n#define _ZETA_EXP_INTT_0TO5_P1_L2\n");
    for (index = 111; index <= 118; index++) {
        printf("%d, ", table_zetaqinv[index]);
    }
    for (index = 111; index <= 118; index++) {
        printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETA_EXP_INTT_0TO5_P1_L3\n");
    for (index = 119; index <= 122; index++) {
        for (int k = 0; k < 2; k++)
            printf("%d, ", table_zetaqinv[index]);
    }
    for (index = 119; index <= 122; index++) {
        for (int k = 0; k < 2; k++)
            printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETA_EXP_INTT_0TO5_P1_L4\n");
    for (index = 123; index <= 124; index++) {
        for (int k = 0; k < 4; k++)
            printf("%d, ", table_zetaqinv[index]);
    }
    for (index = 123; index <= 124; index++) {
        for (int k = 0; k < 4; k++)
            printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETA_EXP_INTT_0TO5_P1_L5\n");
    for (index = 125; index <= 125; index++) {
        printf("%d, ", table_zetaqinv[index]);
        printf("%d, ", table_zeta[index]);
    }
    printf("\n#define _ZETA_EXP_INTT_L6\n");
    for (index = 126; index <= 126; index++) {
        printf("%d, ", table_zetaqinv[index]);
        printf("%d, ", table_zeta[index]);
    }
    printf("\n");
}

int main(void)
{
    GenTables_7layer_VLEN128();
    return 0;
}