/*
   * File_name: error.c file
   * Functions: error_env, error_path_126
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * error_env - The error message for env in get_env.
  *
  * @datash: The data relevant (counter, arguments)
  *
  * Return: error message.
  */

char *error_env(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);

		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}


/**
  * error_path_126 - The error message for the path and
  *                  the failure denied permission.
  *
  * @datash: The data relevant (counter, arguments).
  *
  * Return: The error string.
  */

char *error_path_126(data_shell *datash)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 24;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);

		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
