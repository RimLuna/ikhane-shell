#include "shell.h"

char **
_env(args, env)
char **args;
char **env;
{
	int		i;

	i = 0;
	if (args[1])
	{
		_puts("env: too many arguments\n");
		return (env);
	}
	while (env[i])
	{
		_puts(env[i++]);
		_puts("\n");
	}
	return (env);
}

char **
_echo(args, env)
char **args;
char **env;
{
	int				allow_options;
	int				display_return;
	int				i;

	display_return = 1;
	allow_options = !!(args[1] && is_option(args[1], 'n'));
	i = allow_options ? 2 : 1;
	while (args[i])
	{
		_puts(args[i]);
		args[i + 1] == NULL ? _puts("") : _puts(" ");
		i++;
	}
	allow_options ? _puts("\e[7m%\e[0m") : _puts("\n");
	return (env);
}

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
	(void)env;
}

char **
(*builtin_fnc(int i))(char **args, char **env)
{
	char ** (*builtin_fnc[9])(char **args, char **env);

	builtin_fnc[0] = &_env;
	// builtin_fnc[1] = &_cd;
	builtin_fnc[2] = &_pwd;
	builtin_fnc[3] = &_echo;
	// builtin_fnc[4] = &_set;
	// builtin_fnc[5] = &_unset;
	builtin_fnc[6] = &_exit2;
	// builtin_fnc[7] = &_alias;
	// builtin_fnc[8] = &_dot;
	return (builtin_fnc[i]);
}
