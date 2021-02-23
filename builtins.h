#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdlib.h>

char **
(*builtin_fnc(int i))(char **args, char **env);

// _alias();

char	**_env(char **args, char **env);

// _cd();

char	**_pwd(char **args, char **env);

char	**_echo(char **args, char **env);

// _set();

// _unset();

char	**_exit2(char **args, char **env);

// _dot();
#endif
