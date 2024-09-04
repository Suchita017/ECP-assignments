#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("char:\n");
    printf("signed char:   %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 to %u\n", UCHAR_MAX);

    printf("short:\n");
    printf("signed short:  %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:%u to %u\n", 0, USHRT_MAX);

    printf("int:\n");
    printf("signed int:    %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:  %u to %u\n", 0, UINT_MAX);

    printf("long:\n");
    printf("signed long:   %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);

    printf("float:\n");
    printf("float min:     %e\n", FLT_MIN);
    printf("float max:     %e\n", FLT_MAX);
    printf("float epsilon: %e\n", FLT_EPSILON);

    printf("double:\n");
    printf("double min:    %e\n", DBL_MIN);
    printf("double max:    %e\n", DBL_MAX);
    printf("double epsilon:%e\n", DBL_EPSILON);

    printf("long double:\n");
    printf("long double min:     %Le\n", LDBL_MIN);
    printf("long double max:     %Le\n", LDBL_MAX);
    printf("long double epsilon: %Le\n", LDBL_EPSILON);

    return 0;
}

