/* date = March 25th 2026 10:14 am */

#ifndef BASE_CORE_H
#define BASE_CORE_H

#include <stdint.h>
#include <stdbool.h>

#define BIT_SET(v, n) ((v) | (1<<(n)))
#define BIT_UNSET(v, n) ((v) & ~(1<<(n)))

#endif //BASE_CORE_H
