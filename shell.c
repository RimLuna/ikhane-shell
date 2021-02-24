#include "shell.h"

void
print_prompt ()
{
	_puts("\e[1m\e[38;5;14m[");
	_puts("\e[38;5;205m");
	_puts("ikhane shell");
	_puts("\e[38;5;14m] ");
	_puts("\e[38;5;226m$ \e[0m");
}

char *
_getenv(env, name)
char **env;
const char *name;
{
	const char	*np;
	char		**p;
	char		*c;
	int			len;
	int			*offset;

	if (name== '\0')
		return (NULL);
	np = name;
	while (*np && *np != '=')
		np++;
	len = np - name;
	p = env;
	while ((c = *p) != NULL)
	{
		if (_strncmp(c, name, len) == 0 && c[len] == '=')
		{
			offset = p - env;
			return (c + len + 1);
		}
		p++;
	}
	return (NULL);
}

int
ikhane_shell(env)
char	**env;
{
	int		status;
	char	**cmds;
	char	*line;

	status = 1;
	while (status)
	{
		print_prompt();
		line = _readline();
		cmds = _strtok(line, ";");
		status = execute_cmds(cmds, env);
		free(cmds);
		free(line);
	}
	return (status);

}
