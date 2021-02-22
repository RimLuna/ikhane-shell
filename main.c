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

int
ikhane_shell(ac, av, envp)
int		ac;
char	**av;
char	**envp;
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
		free(cmds);
		free(line);
	}
	return (status);
}

int
main (ac, av, envp)
int		ac;
char	**av;
char	**envp;
{
	return (ikhane_shell(ac, av, envp));

	// env = _getenv("PATH");
	// _puts(env);
	// _puts(envp[0]);

	(void)ac;
}
