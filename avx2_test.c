/*
 * Copyright 6WIND 2018. Vincent Jardin.
 */

/* test it with gcc -Wall -mavx2 -o avx2_test avx2_test.c */

/*
 * It is an example to leverage builtin vectorized method of the
 * compiler:
 * See https://gcc.gnu.org/onlinedocs/gcc-6.4.0/gcc/x86-Built-in-Functions.html
 * Theory: https://gcc.gnu.org/onlinedocs/gcc-6.4.0/gcc/Vector-Extensions.html#Vector-Extensions
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <immintrin.h>

__v16hi feq_avx2(const __v16hi va, const __v16hi vb)
{
   // equal uint16_t / unsigned word
   //__v16hi res = __builtin_ia32_pcmpeqw256(va, vb);
   __v16hi res = va == vb;

   return res;
}

__v16hi fgt_avx2(const __v16hi va, const __v16hi vb)
{
   // greater than uint16_t / unsigned word
   //__v16hi res = __builtin_ia32_pcmpgtw256(va, vb);
   __v16hi res = va > vb;

   return res;
}

__v16hi fadd_avx2(const __v16hi va, const __v16hi vb)
{
   // add uint16_t / unsigned word
   //__v16hi res = __builtin_ia32_paddw256(va, vb);
   __v16hi res = va + vb;

   return res;
}

__v16hi fxor_avx2(const __v16hi va, const __v16hi vb)
{
   // xor
   __v16hi res = va ^ vb;

   return res;
}

__v16hi fmin_avx2(const __v16hi va, const __v16hi vb)
{
   // min uint16_t / unsigned word
   __v16hi res = __builtin_ia32_pminuw256(va, vb);

   return res;
}

__v16hi fmax_avx2(const __v16hi va, const __v16hi vb)
{
   // max uint16_t / unsigned word
   __v16hi res = __builtin_ia32_pmaxuw256(va, vb);

   return res;
}

void ftest_out(const char *f, const __v16hi va, const __v16hi vb, const __v16hi vres)
{
    uint16_t i;
    const uint16_t *pa, *pb, *pres;

    pa = (uint16_t*)&va;
    pb = (uint16_t*)&vb;
    pres = (uint16_t*)&vres;

    for (i = 0; i < 16; i++) {
        printf("%s: a[%d]=%d b[%d]=%d res[%d]=%d\n", f, i, pa[i], i, pb[i], i, pres[i]);
    }
}

/*
 * test _mm256_min_epu16
 */
int main(void)
{
    __v16hi va, vb;
    __v16hi vres;
    const __v16hi vzero = (__v16hi) { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    __builtin_cpu_init();

    /* misc examples */
    if (__builtin_cpu_is("intel")) {
        printf("intel\n");
    }
    if (__builtin_cpu_is("core2")) {
        printf(" core2\n");
    }
    if (__builtin_cpu_is("corei7")) {
        printf(" corei7\n");
    }
    if (__builtin_cpu_is("nehalem")) {
        printf(" nehalem\n");
    }
    if (__builtin_cpu_is("westmere")) {
        printf(" westmere\n");
    }
    if (__builtin_cpu_is("sandybridge")) {
        printf(" sandybridge\n");
    }

    if (__builtin_cpu_supports("popcnt")) {
        printf(" popcnt supported\n");
    }

    if (__builtin_cpu_supports("avx")) {
        printf(" avx supported\n");
    }

    if (__builtin_cpu_supports("avx2")) {
        printf(" avx2 supported\n");
    }

    if (__builtin_cpu_supports("avx512f")) {
        printf(" avx512f supported\n");
    }

#if 0
    a = (__v16hi) _mm256_set_epi16(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    b = (__v16hi) _mm256_set_epi16(0, 1, 4, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
#else
    va = (__v16hi) { 31, 31, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16 };
    vb = (__v16hi) { 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16 };
#endif

    vres = vzero;

    vres = feq_avx2(va, vb);
    ftest_out("eq", va, vb, vres);

    vres = fgt_avx2(va, vb);
    ftest_out("gt", va, vb, vres);

    vres = fadd_avx2(va, vb);
    ftest_out("add", va, vb, vres);

    vres = fxor_avx2(va, vb);
    ftest_out("xor", va, vb, vres);

    vres = fmin_avx2(va, vb);
    ftest_out("min", va, vb, vres);

    vres = fmax_avx2(va, vb);
    ftest_out("max", va, vb, vres);

    return 0;
}
