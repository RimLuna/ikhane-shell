#include "shell.h"

char *
_getenv(name)
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
	p = environ;
	while ((c = *p) != NULL)
	{
		if (_strncmp(c, name, len) == 0 && c[len] == '=')
		{
			offset = p - environ;
			return (c + len + 1);
		}
		p++;
	}
	return (NULL);
}
