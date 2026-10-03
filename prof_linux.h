#ifndef PROF_LINUX_H_
#define PROF_LINUX_H_

#include <stdint.h>
#include <string.h>

typedef int64_t Prof_Int64;

#define _strdup strdup

static void Prof_get_timestamp(Prof_Int64 *result)
{
    *result = __rdtsc();
}

#endif // PROF_LINUX_H_
