#include "shell.h"

char **
choldpwd(env, newdir)
char **env;
char *newdir;
{
	int		i;

	i = 0;
	// _puts("inside\n");
	while (env[i])
	{
		// _puts(env[i] + 7);
		// _puts("\n");
		if (!_strcmp(env[i] + 7, _getenv("OLDPWD")))
			env[i] = _strjoin("OLDPWD=", newdir);
		i++;
	}
	return (env);
}

char **
chpwd(env, pwd)
char **env;
char *pwd;
{
	int		i;

	i = 0;
	// _puts("inside\n");
	while (env[i])
	{
		// _puts(env[i] + 7);
		// _puts("\n");
		if (!_strcmp(env[i] + 4, _getenv("PWD")))
			env[i] = _strjoin("PWD=", pwd);
		i++;
	}
	return (env);
}

char **
_unset(args, env)
char **args;
char **env;
{
	return (env);
	(void)args;
}

char **
_export(args, env)
char **args;
char **env;
{
	return (env);
	(void)args;
}

char **
_dot(args, env)
char **args;
char **env;
{
	return (env);
	(void)args;
}

char **
_cd(args, env)
char **args;
char **env;
{
	int		i;
	char	*path;
	char	*oldpwd;

	i = 0;
	
	// ((!_strcmp(args[1], "-")) && (path = _getenv("OLDPWD"))) ? chdir(path) : _puts("cd: OLDPWD not set\n");
	oldpwd = _getenv("PWD");
	if (!args[1] || !_strcmp(args[1], "~"))
	{
		if ((path = _getenv("HOME")))
		{
			env = choldpwd(env, oldpwd);
			chdir(path);
			env = chpwd(env, path);
		}
		else
			_puts("cd: HOME not set\n");
	}
	else if (!_strcmp(args[1], "-"))
	{
		if ((_strcmp(path = _getenv("OLDPWD"), "")))
		{
			chdir(path);
			env = choldpwd(env, oldpwd);
			env = chpwd(env, path);
			_puts(path);
			_puts("\n");
		}
		else
			_puts("cd: OLDPWD not set\n");
	}
	else
	{
		env = choldpwd(env, oldpwd);
		chdir(args[1]);
		env = chpwd(env, args[1]);
	}
	return (env);
}

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
	(allow_options && args[2]) ? _puts("\e[7m%\e[0m\n") : _puts("\n");
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
    return (NULL);
    (void)args;
	(void)env;
}

char **
(*builtin_fnc(int i))(char **args, char **env)
{
	char ** (*builtin_fnc[9])(char **args, char **env);

	builtin_fnc[0] = &_env;
	builtin_fnc[1] = &_cd;
	builtin_fnc[2] = &_pwd;
	builtin_fnc[3] = &_export;
	builtin_fnc[4] = &_echo;
	builtin_fnc[5] = &_unset;
	builtin_fnc[6] = &_dot;
	builtin_fnc[7] = &_exit2;
	// builtin_fnc[8] = &_alias;
	return (builtin_fnc[i]);
}
