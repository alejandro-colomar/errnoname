/*****************************************************************************\
 * Copyright 2019 Alexander Kozhevnikov <mentalisttraceur@gmail.com>
 * Copyright 2021 Alejandro Colomar <alx.manpages@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
\*****************************************************************************/

#ifndef ERRNONAME_C
#define ERRNONAME_C

#include <errno.h>

char const * errnoname(int errno_)
{
#ifdef ERRNONAME_SAFE_TO_USE_ARRAY
    static char const * const names[] =
    {
        [0] = 0,
#include "errnoname_array.c.inc"
    };
    if(errno_ >= 0 && errno_ < (sizeof(names) / sizeof(*names)))
    {
        return names[errno_];
    }
    return 0;
#else /* ERRNONAME_SAFE_TO_USE_ARRAY */
    switch(errno_)
    {
        case 0: return 0;
#include "errnoname_switch.c.inc"
    }
    return 0;
#endif /* ERRNONAME_SAFE_TO_USE_ARRAY */
}

#endif /* ERRNONAME_C */
