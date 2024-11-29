#include <math.h>
#include <riscv_vector.h>
#include <stdio.h>
#include <string.h>

#include "cpucycles.h"
#include "speed_print.h"

#define ARRAY_SIZE 11

float a_array[ARRAY_SIZE] = {1.18869953,  1.55298864,  -0.17365574,
                             -1.86193886, -1.52391526, -0.36566814,
                             0.70753702,  0.73992422,  -0.13493693,
                             1.09563677,  1.03797902};

float b_array[ARRAY_SIZE] = {1.19655525,  0.23393777, -0.11629651,
                             -0.54508896, -1.2424749, -1.54835913,
                             0.86935212,  0.12946646, 0.81831905,
                             -0.42723697, -0.89793257};

float c_array_ref[ARRAY_SIZE];
float c_array_vec[ARRAY_SIZE];

void add(const float *a, const float *b, float *c, size_t length)
{
    for (int i = 0; i < length; i++) {
        c[i] = a[i] + b[i];
    }
}

void add_vec(const float *a, const float *b, float *c, size_t length)
{
    while (length > 0) {
        size_t vl = vsetvl_e32m1(length);
        vfloat32m1_t va = vle32_v_f32m1(a, vl);
        vfloat32m1_t vb = vle32_v_f32m1(b, vl);
        vfloat32m1_t vc = vfadd_vv_f32m1(va, vb, vl);
        vse32_v_f32m1(c, vc, vl);
        a += vl;
        b += vl;
        c += vl;
        length -= vl;
    }
}

int main()
{
    printf("Test add function by rvv intrinsic \n");
    add(a_array, b_array, c_array_ref, ARRAY_SIZE);
    add_vec(a_array, b_array, c_array_vec, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (fabsf(c_array_ref[i] - c_array_vec[i]) > 1e-6) {
            printf("index[%d] failed, %f=!%f\n", i, c_array_ref[i],
                   c_array_vec[i]);
        } else {
            printf("index[%d] successed, %f=%f\n", i, c_array_ref[i],
                   c_array_vec[i]);
        }
    }
    return 0;
}