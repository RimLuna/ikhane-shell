#ifndef STRLIB_H
# define STRLIB_H

# include <unistd.h>
# include "charlib.h"

void
_puts (const char *s);

int
_strlen(const char *s);

int
_strncmp(const char	*s1, const char	*s2, size_t		n);

#endif