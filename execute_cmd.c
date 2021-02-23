#include "shell.h"

char *builtins[] =
{
  "env", "cd", "pwd", "export", "echo", "unset", ".", "exit",
  (char *)NULL
};

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

	if (!args || !*args || !**args)
		return (0);
	i = 0;
	while (i < 8)
	{
		if (_strcmp(args[0], builtins[i]) == 0)
			return ((*builtin_fnc(i))(args, env));
		i++;
	}
	return (env);
	(void)args;
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
	while (cmd[i])
	{
		args = _strtok(cmd[i], " \n\t\r\"");
		env = execute_cmd(args, env);
		status = !!env;
		free(cmd[i]);
		i++;
	}
	return (status);
}
