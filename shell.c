/*
   * File_name: shell.c file
   * Functions: free_data, set_data, main
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * free_data - frees the data structure
  *
  * @datash: The data structure
  *
  * Return: no return
  */

void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}

	free(datash->_environ);
	free(datash->pid);
}


/**
  * set_data - Initialize the data structure
  *
  * @datash: The data structure
  *
  * @av: The argument vector
  *
  * Return: no return
  */

void set_data(data_shell *datash, char **av)
{
	unsigned int i;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}

	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}


/**
  * main - The entry point
  *
  * @ac: The argument count
  *
  * @av: The argument vector
  *
  * Return: 0 on success.
  */

int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);

	if (datash.status < 0)
		return (255);

	return (datash.status);
}
