#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdlib.h>

char *builtins[] =
{
  "alias", "cd", "pwd", "unalias", "echo", "set", "unset", ".", "exit",
  (char *)NULL
};

char **
(*builtin_fnc(int i))(char **args, char **env);

_alias();

_cd();

_pwd();

_echo();

_set();

_unset();

_exit();

_dot();
#endif
