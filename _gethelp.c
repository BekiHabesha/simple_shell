/*
   * File_name: _gethelp.c file
   * Functions: get_help
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * get_help - The function that retrieves help messages
  *            according to the builtin
  *
  * @datash: data structure (args and input)
  *
  * Return: Return 0
  */

int get_help(data_shell *datash)
{

	if (datash->args[1] == 0)
		aux_help_general();

	else if (_strcmp(datash->args[1], "env") == 0)
		aux_help_env();

	else if (_strcmp(datash->args[1], "setenv") == 0)
		aux_help_setenv();

	else if (_strcmp(datash->args[1], "unsetenv") == 0)
		aux_help_unsetenv();

	else if (_strcmp(datash->args[1], "help") == 0)
		aux_help();

	else if (_strcmp(datash->args[1], "cd") == 0)
		aux_help_cd();

	else if (_strcmp(datash->args[1], "alias") == 0)
		aux_help_alias();

	else if (_strcmp(datash->args[1], "exit") == 0)
		aux_help_exit();

	else
		write(STDERR_FILENO, datash->args[0],
				_strlen(datash->args[0]));

	datash->status = 0;
	return (1);
}
