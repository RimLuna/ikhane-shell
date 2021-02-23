#ifndef SHELL_H
# define SHELL_H

# include "lib/strlib.h"
# include <unistd.h>

# define BUFFER_SIZE 1024
# define PROMPT "$ "
# include "builtins.h"

extern char **environ;
extern char *builtins[9];
int
is_option(char *s, char c);

void
print_prompt();

char *
_getenv(const char *name);

char **
execute_cmd(char **args, char **env);

int
execute_cmds(char **cmd, char **env);

int
ikhane_shell(char **env);
#endif