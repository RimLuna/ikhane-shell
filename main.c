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
main (ac, av, envp)
int		ac;
char	**av;
char	**envp;
{
	char	*env;

	env = _getenv("TERM_PROGRAM");
	_puts(env);
	// return (minishell(env));
	(void)ac;
}
