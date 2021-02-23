#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdlib.h>

char **
(*builtin_fnc(int i))(char **args, char **env);

// _alias();

// _cd();

char	**_pwd(char **args, char **env);

// _echo();

// _set();

// _unset();

char	**_exit2(char **args, char **env);

// _dot();
#endif
