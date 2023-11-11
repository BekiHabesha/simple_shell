/*
   * File_name: _geterror.c file
   * Functions: get_error
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * get_error - calls the error according to the
  *             builtin, the syntax or the permission.
  *
  * @datash: The data structure that contains arguments.
  *
  * @eval: The error value.
  *
  * Return: error
  */

int get_error(data_shell *datash, int eval)
{
	char *error;

	switch (eval)
	{

		case 127:
			error = error_not_found(datash);
			break;

		case -1:
			error = error_env(datash);
			break;

		case 126:
			error = error_path_126(datash);
			break;

		case 2:
			if (_strcmp("exit", datash->args[0]) == 0)
				error = error_exit_shell(datash);

			else if (_strcmp("cd", datash->args[0]) == 0)
				error = error_get_cd(datash);

			break;

	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	datash->status = eval;

	return (eval);
}
