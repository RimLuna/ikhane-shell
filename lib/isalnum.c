#include "charlib.h"

int		_isalnum(int c)
{
    return ((c >= '0' && c <= '9')
            || (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}