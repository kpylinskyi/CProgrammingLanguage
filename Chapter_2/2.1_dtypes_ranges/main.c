#include <stdio.h>
#include <limits.h>
#include <float.h>



int main(void){
    // char
    printf("signed char range\t: %d\tto %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char range\t: 0\tto %u\n", UCHAR_MAX);

    // short
    printf("signed short range\t: %d\tto %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short range\t: 0\tto %u\n", USHRT_MAX);

    // int
    printf("signed int range\t: %d\tto %d\n", INT_MIN, INT_MAX);
    printf("unsigned int range\t: 0\tto %u\n", UINT_MAX);

    // long
    printf("signed long range\t: %ld\tto %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long range\t: 0 to\t%lu\n", ULONG_MAX);

    // long long
    printf("signed long long range\t: %lld\tto %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long range\t: 0 to\t%llu\n", ULLONG_MAX);
    
    // float
    printf("float range\t: %e\tto %e\n", FLT_MIN, FLT_MAX);
    printf("double range\t: %e\tto %e\n", DBL_MIN, DBL_MAX);
    printf("long double range\t: %Le\tto %Le\n", LDBL_MIN, LDBL_MAX);
}