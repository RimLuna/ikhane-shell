#ifndef SHELL_H
# define SHELL_H

# include "lib/strlib.h"
# include <unistd.h>
# include "builtins.h"

# define BUFFER_SIZE 1024
# define PROMPT "$ "

extern char **environ;

void
print_prompt();

char *
_getenv(const char *name);

int
execute_cmds(char **cmd, char **env);

int
execute_cmd(char **args, char **env);
#endif