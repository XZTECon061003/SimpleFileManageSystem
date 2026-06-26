//
// Created by 20593 on 2026/6/6.
//

#ifndef _STDC_H
#define _STDC_H

/* bits/stdc.h
 * C23 Universal Header
 */

/*  ANSI C  */
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*  C99  */
#include <complex.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
#include <wchar.h>
#include <wctype.h>

/*  C11  */
#include <stdalign.h>
#include <stdatomic.h>
#include <stdnoreturn.h>
#include <threads.h>
#include <uchar.h>

/*  C23  */
#include <stdbit.h>
#include <stdckdint.h>

/*  POSIX  */
#ifdef __unix__
#include <dirent.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#endif

/* Extension */
#include "cpp_string.h"
#include "vector.h"
#include "list.h"
#include "deque.h"
#include "stack.h"
#include "queue.h"
#include "hashmap.h"
#include "set.h"
#include "algorithm.h"
#include "filesystem.h"

#endif