#include "shell.h"

// char *
// _(sigmsg)
// const char *sigmsg;
// {
// 	_puts(sigmsg);
// }

/**
 * @brief  
 * @note   Ctrl+\ --> SIGQUIT
 * 			Ctrl+C --> SIGINT
 * 			Ctrl+D --> not a signal, it's EOF (End-Of-File),
 * 						closes the stdin pipe
 * @retval 
 */

void
initialize_siglist ()
{
	int		i;
	char	*siglist[NSIG];

	i = -1;
	while (++i < NSIG)
		siglist[i] = (char *)0x0;
	#if defined (SIGINT)
		siglist[SIGINT] = _("Interrupt");
	#endif
	#if defined (SIGQUIT)
		siglist[SIGQUIT] = _("Quit");
	#endif
}
