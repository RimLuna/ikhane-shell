#include "shell.c"

char **
(*builtin_fnc(int i))(char **args, char **env)
{
	char ** (*builtin_fnc[9])(char **args, char **env);

	builtin_fnc[0] = &_alias;
	builtin_fnc[1] = &_cd;
	builtin_fnc[2] = &_pwd;
	builtin_fnc[3] = &_echo;
	builtin_fnc[4] = &_set;
	builtin_fnc[5] = &_unset;
	builtin_fnc[6] = &_exit;
	builtin_fnc[7] = &_alias;
	builtin_fnc[8] = &_dot;
}
