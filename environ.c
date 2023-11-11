/*
   * File_name: environ.c file
   * Functions: cmp_env_name, _getenv, _env
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * cmp_env_name - compares the env variables names
  *                with the name passed.
  *
  * @nenv: The name of the environment variable
  *
  * @name: The name passed
  *
  * Return: 0 if are not equal. Another value if they are.
  */

int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}


/**
  * _getenv - get an environment variable
  *
  * @name: The name of the environment variable
  *
  * @_environ: The environment variable
  *
  * Return: value of the environment variable if is found.
  *         In other case, returns NULL.
  */

char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	ptr_env = NULL;
	mov = 0;

	for (i = 0; _environ[i]; i++)
	{
		mov = cmp_env_name(_environ[i], name);

		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}


/**
  * _env - prints the evironment variables
  *
  * @datash: The data relevant.
  *
  * Return: 1 on success.
  */

int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
