#ifndef Prof_INC_PROF_WIN32_H
#define Prof_INC_PROF_WIN32_H

typedef __int64 Prof_Int64;

#if defined(_MSC_VER)
  #include <intrin.h>
#else
  #include <x86intrin.h>
#endif

#ifdef __cplusplus
  inline
#elif _MSC_VER >= 1200
  __forceinline
#else
  static
#endif
void Prof_get_timestamp(Prof_Int64 *result)
{
    *result = (Prof_Int64) __rdtsc();
}
#endif
