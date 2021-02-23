#include "shell.c"

int
is_option(s, c)
char	*s;
char	c;
{
	return (s[0] == '-' && s[1] == c && !s[2]);
}

int
execute_cmd(args, env)
char	**args;
char	**env;
{
	int		i;

	if (!args || !*args || !**args)
		return (0);
	i = 0;
	while (i < 9)
	{
		if (_strcmp(args[0], builtins[i]) == 0)
			return (builtin(i, args, env));
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
	while (cmd[i])
	{
		args = _strtok(cmd[i], " \n\t\r\"");
		status = execute_cmd(args, env);
		free(cmd[i]);
		i++;
	}
	return (status);
}
