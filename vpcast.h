/*
 * vpcast: Lots of macros to perform conversions between basic
 *         types and void pointers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Macros for determining endianness (Adam Rosenfield)
// https://stackoverflow.com/questions/4239993/determining-endianness-at-compile-time
#if defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN || \
    defined(__BIG_ENDIAN__) || \
    defined(__ARMEB__) || \
    defined(__THUMBEB__) || \
    defined(__AARCH64EB__) || \
    defined(_MIBSEB) || defined(__MIBSEB) || defined(__MIBSEB__)

#define THIS_IS_BIG_ENDIAN

#elif defined(__BYTE_ORDER) && __BYTE_ORDER == __LITTLE_ENDIAN || \
    defined(__LITTLE_ENDIAN__) || \
    defined(__ARMEL__) || \
    defined(__THUMBEL__) || \
    defined(__AARCH64EL__) || \
    defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__)

#define THIS_IS_LITTLE_ENDIAN

#else
#error "I don't know what architecture this is!"
#endif

/* Integer conversions */

_Static_assert(sizeof(long long) <= sizeof(void *),
        "Long long can't be stored in pointer");

#define ANY_INT_TO_PTR(_arg) (                                      \
    _Generic((_arg),                                                \
            signed char     : SCHR_T_VP,                            \
            unsigned char   : UCHR_T_VP,                            \
            signed short    : SHR_T_VP,                             \
            unsigned short  : USHR_T_VP,                            \
            signed int      : INT_T_VP,                             \
            unsigned int    : UINT_T_VP,                            \
            long int        : LINT_T_VP,                            \
            unsigned long   : ULINT_T_VP,                           \
            long long       : LLINT_T_VP,                           \
            unsigned long long : ULLINT_T_VP)(_arg))

static inline double VP_T_DBL(void *ptr_val);
static inline void *DBL_T_VP(double number);
static inline float VP_T_FLT(void *ptr_val);
static inline void *FLT_T_VP(float number);
static inline uintmax_t VP_T_UINTMAX(void *ptr_val);
static inline void *UINTMAX_T_VP(uintmax_t number);
static inline intmax_t VP_T_INTMAX(void *ptr_val);
static inline void *INTMAX_T_VP(intmax_t number);
static inline uint64_t VP_T_UINT64(void *ptr_val);
static inline void *UINT64_T_VP(uint64_t number);
static inline int64_t VP_T_INT64(void *ptr_val);
static inline void *INT64_T_VP(int64_t number);
static inline uint32_t VP_T_UINT32(void *ptr_val);
static inline void *UINT32_T_VP(uint32_t number);
static inline int32_t VP_T_INT32(void *ptr_val);
static inline void *INT32_T_VP(int32_t number);
static inline uint16_t VP_T_UINT16(void *ptr_val);
static inline void *UINT16_T_VP(uint16_t number);
static inline int16_t VP_T_INT16(void *ptr_val);
static inline void *INT16_T_VP(int16_t number);
static inline uint8_t VP_T_UINT8(void *ptr_val);
static inline void *UINT8_T_VP(uint8_t number);
static inline int8_t VP_T_INT8(void *ptr_val);
static inline void *INT8_T_VP(int8_t number);
static inline unsigned long long VP_T_ULLINT(void *ptr_val);
static inline void *ULLINT_T_VP(unsigned long long number);
static inline long long VP_T_LLINT(void *ptr_val);
static inline void *LLINT_T_VP(long long number);
static inline unsigned long VP_T_ULINT(void *ptr_val);
static inline void *ULINT_T_VP(unsigned long number);
static inline long int VP_T_LINT(void *ptr_val);;
static inline void *LINT_T_VP(long number);
static inline unsigned int VP_T_UINT(void *ptr_val);
static inline void *UINT_T_VP(unsigned int number);
static inline int VP_T_INT(void *ptr_val);
static inline void *INT_T_VP(int number);
static inline unsigned short VP_T_USHR(void *ptr_val);;
static inline void *USHR_T_VP(unsigned short number);
static inline short VP_T_SHR(void *ptr_val);
static inline void *SHR_T_VP(short number);
static inline unsigned char VP_T_UCHR(void *ptr_val);
static inline void *UCHR_T_VP(unsigned char number);
static inline signed char VP_T_SCHR(void *ptr_val);
static inline void *SCHR_T_VP(signed char number);

static inline void *SCHR_T_VP(signed char number)
{ return (void *)(uintptr_t)(unsigned char)number; }

static inline signed char VP_T_SCHR(void *ptr_val)
{ return (signed char)(unsigned char)(uintptr_t)ptr_val; }

#define SIGNED_CHAR(_arg) (                                             \
        _Generic((_arg), void *: VP_T_SCHR, default: SCHR_T_VP)(_arg))

static inline void *UCHR_T_VP(unsigned char number)
{ return (void *)(uintptr_t)number; }

static inline unsigned char VP_T_UCHR(void *ptr_val)
{ return (unsigned char)(uintptr_t)ptr_val; }

#define UNSIGNED_CHAR(_arg) (                                           \
        _Generic((_arg), void *: VP_T_UCHR, default: UCHR_T_VP)(_arg))

static inline void *SHR_T_VP(short number)
{ return (void *)(uintptr_t)number; }

static inline short VP_T_SHR(void *ptr_val)
{ return (short)(unsigned short)(uintptr_t)ptr_val; }

#define SHORT(_arg) (                                                   \
        _Generic((_arg), void *: VP_T_SHR, default: SHR_T_VP)(_arg))

static inline void *USHR_T_VP(unsigned short number)
{ return (void *)(uintptr_t)number; }

static inline unsigned short VP_T_USHR(void *ptr_val)
{ return (unsigned short)(uintptr_t)(ptr_val); }

#define UNSIGNED_SHORT(_arg) (                                          \
        _Generic((_arg), void *: VP_T_USHR, default: USHR_T_VP)(_arg))

static inline void *INT_T_VP(int number)
{ return (void *)(uintptr_t)(unsigned)number; }

static inline int VP_T_INT(void *ptr_val)
{ return (int)(unsigned)(uintptr_t)ptr_val; }

#define INT(_arg) (                                                     \
        _Generic((_arg), void *: VP_T_INT, default: INT_T_VP)(_arg))

static inline void *UINT_T_VP(unsigned int number)
{ return (void *)(uintptr_t)number; }

static inline unsigned int VP_T_UINT(void *ptr_val)
{ return (unsigned)(uintptr_t)ptr_val; }

#define UNSIGNED_INT(_arg) (                                            \
        _Generic((_arg), void *: VP_T_UINT, default: UINT_T_VP)(_arg))

static inline void *LINT_T_VP(long number)
{ return (void *)(uintptr_t)(unsigned long)number; }

static inline long int VP_T_LINT(void *ptr_val)
{ return (long)(unsigned long)(uintptr_t)ptr_val; }

#define LONG(_arg) (                                                    \
        _Generic((_arg), void *: VP_T_LINT, default: LINT_T_VP)(_arg))

static inline void *ULINT_T_VP(unsigned long number)
{ return (void *)(uintptr_t)number; }

static inline unsigned long VP_T_ULINT(void *ptr_val)
{ return (unsigned long)(uintptr_t)ptr_val; }

#define UNSIGNED_LONG(_arg) (                                           \
        _Generic((_arg), void *: VP_T_ULINT, default: ULINT_T_VP)(_arg))

static inline void *LLINT_T_VP(long long number)
{ return (void *)(uintptr_t)(unsigned long long)number; }

static inline long long VP_T_LLINT(void *ptr_val)
{ return (long long)(unsigned long long)(uintptr_t)ptr_val; }

#define LONG_LONG(_arg) (                                               \
        _Generic((_arg), void *: VP_T_LLINT, default: LLINT_T_VP)(_arg))

static inline void *ULLINT_T_VP(unsigned long long number)
{ return (void *)(uintptr_t)number; }

static inline unsigned long long VP_T_ULLINT(void *ptr_val)
{ return (unsigned long long)(uintptr_t)ptr_val; }

#define UNSIGNED_LONG_LONG(_arg) (                                      \
        _Generic((_arg), void *: VP_T_ULLINT, default: ULLINT_T_VP)(_arg))

static inline void *INT8_T_VP(int8_t number)
{ return (void *)(uintptr_t)(uint8_t)number; }

static inline int8_t VP_T_INT8(void *ptr_val)
{ return (int8_t)(uint8_t)(uintptr_t)ptr_val; }

#define INT8(_arg) (                                                    \
        _Generic((_arg), void *: VP_T_INT8, default: INT8_T_VP)(_arg))

static inline void *UINT8_T_VP(uint8_t number)
{ return (void *)(uintptr_t)number; }

static inline uint8_t VP_T_UINT8(void *ptr_val)
{ return (uint8_t)(uintptr_t)ptr_val; }

#define UINT8(_arg) (                                                   \
        _Generic((_arg), void *: VP_T_UINT8, default: UINT8_T_VP)(_arg))

static inline void *INT16_T_VP(int16_t number)
{ return (void *)(uintptr_t)(uint16_t)number; }

static inline int16_t VP_T_INT16(void *ptr_val)
{ return (int16_t)(uint16_t)(uintptr_t)ptr_val; }

#define INT16(_arg) (                                                   \
        _Generic((_arg), void *: VP_T_INT16, default: INT16_T_VP)(_arg))

static inline void *UINT16_T_VP(uint16_t number)
{ return (void *)(uintptr_t)number; }

static inline uint16_t VP_T_UINT16(void *ptr_val)
{ return (uint16_t)(uintptr_t)ptr_val; }

#define UINT16(_arg) (                                                  \
        _Generic((_arg), void *: VP_T_UINT16, default: UINT16_T_VP)(_arg))

static inline void *INT32_T_VP(int32_t number)
{ return (void *)(uintptr_t)(uint32_t)number; }

static inline int32_t VP_T_INT32(void *ptr_val)
{ return (int32_t)(uint32_t)(uintptr_t)ptr_val; }

#define INT32(_arg) (                                                   \
        _Generic((_arg), void *: VP_T_INT32, default: INT32_T_VP)(_arg))

static inline void *UINT32_T_VP(uint32_t number)
{ return (void *)(uintptr_t)number; }

static inline uint32_t VP_T_UINT32(void *ptr_val)
{ return (uint32_t)(uintptr_t)ptr_val; }

#define UINT32(_arg) (                                                  \
        _Generic((_arg), void *: VP_T_UINT32, default: UINT32_T_VP)(_arg))

static inline void *INT64_T_VP(int64_t number)
{ return (void *)(uintptr_t)(uint64_t)number; }

static inline int64_t VP_T_INT64(void *ptr_val)
{ return (uint64_t)(int64_t)(uintptr_t)ptr_val; }

#define INT64(_arg) (                                                   \
        _Generic((_arg), void *: VP_T_INT64, default: INT64_T_VP)(_arg))

static inline void *UINT64_T_VP(uint64_t number)
{ return (void *)(uintptr_t)number; }

static inline uint64_t VP_T_UINT64(void *ptr_val)
{ return (uint64_t)(uintptr_t)ptr_val; }

#define UINT64(_arg) (                                                  \
        _Generic((_arg), void *: VP_T_UINT64, default: UINT64_T_VP)(_arg))

static inline void *INTMAX_T_VP(intmax_t number)
{ return (void *)(uintptr_t)number; }

static inline intmax_t VP_T_INTMAX(void *ptr_val)
{ return (intmax_t)(uintptr_t)ptr_val; }

#define INTMAX(_arg) (                                                  \
        _Generic((_arg), void *: VP_T_INTMAX, default: INTMAX_T_VP)(_arg))

static inline void *UINTMAX_T_VP(uintmax_t number)
{ return (void *)(uintptr_t)number; }

static inline uintmax_t VP_T_UINTMAX(void *ptr_val)
{ return (uintmax_t)ptr_val; }

#define UINTMAX(_arg) (                                                 \
        _Generic((_arg), void *: VP_T_UINTMAX, default: UINTMAX_T_VP)(_arg))

/* Floating point conversions */

_Static_assert(sizeof(double) <= sizeof(void *),
        "Double can't be stored in pointer");

static inline void *FLT_T_VP(float number) {
    if (sizeof(uint32_t) == sizeof(float))
        return (void *)(uintptr_t)*(uint32_t *)&number;
    else if (sizeof(uint16_t) == sizeof(float))
        return (void *)(uintptr_t)*(uint16_t *)&number;
    else if (sizeof(uint64_t) == sizeof(float))
        return (void *)(uintptr_t)*(uint64_t *)&number;

    fprintf(stderr, "Unespected size of float\n");
    exit(EXIT_FAILURE);
    return NULL;
}

static inline float VP_T_FLT(void *ptr_val) {
    uintptr_t int_vp = (uintptr_t)ptr_val;
    float val;

#ifdef THIS_IS_LITTLE_ENDIAN
    val = *(float *)&int_vp;
#elif  THIS_IS_BIG_ENDIAN
    if ( sizeof(float) == sizeof(void *) )
        val = *(float *)&int_vp;
    else if ( sizeof(float) == 2 * sizeof(void *) )
        val = *((float *)&int_vp + 1);
    else if ( sizeof(float) == 4 * sizeof(void *) )
        val = *((float *)&int_vp + 3);
#endif
    return val;
}

#define FLOAT(_arg) (                                                   \
        _Generic((_arg), void *: VP_T_FLT, default: FLT_T_VP)(_arg))

static inline void *DBL_T_VP(double number) {
    if (sizeof(uint64_t) == sizeof(double))
        return (void *)(uintptr_t)*(uint64_t*)&number;
    else if (sizeof(uint32_t) == sizeof(double))
        return (void *)(uintptr_t)*(uint32_t *)&number;

    fprintf(stderr, "Unespected size of double\n");
    exit(EXIT_FAILURE);
    return NULL;
}

static inline double VP_T_DBL(void *ptr_val) {
    uintptr_t int_vp = (uintptr_t)ptr_val;
    double val;
#ifdef THIS_IS_LITTLE_ENDIAN
    val = *(double *)&int_vp;
#elif THIS_IS_BIG_ENDIAN
    if ( sizeof(double) == sizeof(void *) )
        val = *(double *)&int_vp;
    else if ( sizeof(double) == 2 * sizeof(void *) )
        val = *((double *)&int_vp + 1)
    else {
        fprintf(stderr, "Unespected size of double\n");
        exit(EXIT_FAILURE);
    }
#endif
    return val;
}

#define DOUBLE(_arg) (                                                  \
        _Generic((_arg), void *: VP_T_DBL, default: DBL_T_VP)(_arg))
