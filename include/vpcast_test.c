/*
 * vpcast_text.c: Test file for vp_cast macros
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>
#include <assert.h>
#include "vpcast.h"

int main(void)
{
    /*void *ptr;  // Void pointer for testing values*/

    // ##### Normal integer tests #####
    assert(SCHAR_MAX == SIGNED_CHAR(SIGNED_CHAR(SCHAR_MAX)));
    assert(SCHAR_MIN == SIGNED_CHAR(SIGNED_CHAR(SCHAR_MIN)));

    assert(UCHAR_MAX == UNSIGNED_CHAR(UNSIGNED_CHAR(UCHAR_MAX)));


    assert(SHRT_MAX == SHORT(SHORT(SHRT_MAX)));
    assert(SHRT_MIN == SHORT(SHORT(SHRT_MIN)));

    assert(USHRT_MAX == UNSIGNED_SHORT(UNSIGNED_SHORT(USHRT_MAX)));


    assert(INT_MAX == INT(INT(INT_MAX)));
    assert(INT_MIN == INT(INT(INT_MIN)));

    assert(UINT_MAX == UNSIGNED_INT(UNSIGNED_INT(UINT_MAX)));


    assert(LONG_MAX == LONG(LONG(LONG_MAX)));
    assert(LONG_MIN == LONG(LONG(LONG_MIN)));

    assert(ULONG_MAX == UNSIGNED_LONG(UNSIGNED_LONG(ULONG_MAX)));


    assert(LLONG_MAX == LONG_LONG(LONG_LONG(LLONG_MAX)));
    assert(LLONG_MIN == LONG_LONG(LONG_LONG(LLONG_MIN)));

    assert(ULLONG_MAX == UNSIGNED_LONG_LONG(UNSIGNED_LONG_LONG(ULLONG_MAX)));


    // ##### Fixed width integer tests #####
    assert(INT8_MAX == INT8(INT8(INT8_MAX)));
    assert(INT8_MIN == INT8(INT8(INT8_MIN)));

    assert(UINT8_MAX == UINT8(UINT8(UINT8_MAX)));


    assert(INT16_MAX == INT16(INT16(INT16_MAX)));
    assert(INT16_MIN == INT16(INT16(INT16_MIN)));

    assert(UINT16_MAX == UINT16(UINT16(UINT16_MAX)));


    assert(INT32_MAX == INT32(INT32(INT32_MAX)));
    assert(INT32_MIN == INT32(INT32(INT32_MIN)));

    assert(UINT32_MAX == UINT32(UINT32(UINT32_MAX)));


    assert(INT64_MAX == INT64(INT64(INT64_MAX)));
    assert(INT64_MIN == INT64(INT64(INT64_MIN)));

    assert(UINT64_MAX == UINT64(UINT64(UINT64_MAX)));


    // ##### Floating point tests #####
    assert(FLT_MAX == FLOAT(FLOAT(FLT_MAX)));

    assert(FLT_MIN == FLOAT(FLOAT(FLT_MIN)));

    assert(FLT_EPSILON == FLOAT(FLOAT(FLT_EPSILON)));


    assert(DBL_MAX == DOUBLE(DOUBLE(DBL_MAX)));
    assert(DBL_MIN == DOUBLE(DOUBLE(DBL_MIN)));

    assert(DBL_EPSILON == DOUBLE(DOUBLE(DBL_EPSILON)));


    printf("Everyghint is okay\n");
    return EXIT_SUCCESS;
}
