#include "shell.h"

char **
_pwd(args, env)
char **args;
char **env;
{
	char	path[1024];
	int		i;

	i = 0;
	while (args[i])
		i++;
	if (i > 1)
		_puts("pwd: too many arguments\n");
	else
	{
		_puts(getcwd(path, 1024));
		_puts("\n");
	}
	return (env);
}

char **
_exit2(args, env)
char **args;
char **env;
{
	_puts("EXIT\n");
    return (NULL);
    (void)args;
}

char **
(*builtin_fnc(int i))(char **args, char **env)
{
	char ** (*builtin_fnc[9])(char **args, char **env);

	_puts("BUILTIN\n");
	// builtin_fnc[0] = &_alias;
	// builtin_fnc[1] = &_cd;
	builtin_fnc[2] = &_pwd;
	// builtin_fnc[3] = &_echo;
	// builtin_fnc[4] = &_set;
	// builtin_fnc[5] = &_unset;
	builtin_fnc[6] = &_exit2;
	// builtin_fnc[7] = &_alias;
	// builtin_fnc[8] = &_dot;
	return (builtin_fnc[i]);
}
