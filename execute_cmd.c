#include "shell.h"

char *builtins[] =
{
  "env", "cd", "pwd", "export", "echo", "unset", ".", "exit",
  (char *)NULL
};

void
_execve(path, args, env)
char *path;
char **args;
char **env;
{
	pid_t		pid;

	pid = fork();
	if (pid == 0)
		execve(path, args, env);
	else if (pid < 0)
		_puts("fork error\n");
	else
		wait(&pid);
}

void
_look_for_cmd(args, env)
char **args;
char **env;
{
	char	**paths;
	char	*path;
	int		i;
	struct stat statbuf;

	if (_getenv(env, "PATH"))
		paths = _strtok(_getenv(env, "PATH"), ":");
	else
		paths = NULL;
	path = _strnew(1024);
	i = 0;
	while (paths && paths[i])
	{
		path =  _strnew(1024);
		path = _strjoin(path, paths[i]);
		if (args[0][0] != '/')
			path = _strjoin(path, "/");
		path = _strjoin(path, args[0]);
		if (stat(path, &statbuf) != -1)
		{
			_execve(path, args, env);
			break;
		}
		free(path);
		i++;
	}
}

int is_option(s, c)
char	*s;
int		c;
{
	return (s[0] == '-' && s[1] == c && !s[2]);
}

char **
execute_cmd(args, env)
char	**args;
char	**env;
{
	int		i;
	struct stat statbuf;

	if (!args || !*args || !**args)
		return (0);
	i = 0;
	while (i < 8)
	{
		if (_strcmp(args[0], builtins[i]) == 0)
			return ((*builtin_fnc(i))(args, env));
		i++;
	}
	if (stat(args[0], &statbuf) != -1)
		_execve(args[0], args, env);
	else
		_look_for_cmd(args, env);
	return (env);
	(void)args;
}

void
expand_dollars(args, env)
char ***args;
char **env;
{
	char	*dollar;
	int		i;
	char	*found;

	i = -1;
	while ((*args)[++i])
	{
		if ((dollar = _strchr((*args)[i], '$')))
			dollar++;
		else
			continue;
		if ((found = (_getenv(env, dollar)) ? _strdup(_getenv(env, dollar)) : _strdup("")))
		{

			(*args)[i][dollar - (*args)[i] - 1] = 0;
			(*args)[i] = _strjoin((*args)[i], _strdup(found));
		}
	}
}

int
execute_cmds(cmd, env)
char	**cmd;
char	**env;
{
	char	**args;
	int		i;
	int		status;

	i = 0;
	// if (!_strcmp(cmd[0], ""))
	// 	return (1);
	while (cmd[i])
	{
		args = _strtok(cmd[i], " \n\t\r\"");
		expand_dollars(&args, env);
		env = execute_cmd(args, env);
		status = !!env;
		free(cmd[i]);
		i++;
	}
	return (status);
}
