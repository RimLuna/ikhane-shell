#include "shell.h"

void
print_prompt ()
{
    _puts(PROMPT);
}

int
main (ac, av, envp)
int     ac;
char    **av;
char    **envp;
{
    print_prompt();
}
