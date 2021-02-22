#ifndef SHELL_H
# define SHELL_H

# include "lib/strlib.h"
# include <unistd.h>
# include <stdlib.h>

# define PROMPT "$ "

extern char **environ;

void
print_prompt();

char *
_getenv(const char *name);

#endif