/*
   * File_name: help_env.c file
   * Functions: aux_help_env, aux_help_setenv,
   *          : aux_help_unsetenv
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * aux_help_env - Help the information for
  *                the builtin env
  *
  * Return: no return
  */

void aux_help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Print the enviroment of the shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));

}


/**
  * aux_help_setenv - Help the information for
  *                   the builtin setenv
  *
  * Return: no return
  */

void aux_help_setenv(void)
{

	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "int replace)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Add a new definition to the environment\n";

	write(STDOUT_FILENO, help, _strlen(help));
}


/**
  * aux_help_unsetenv - Help the information for
  *                     the builtin unsetenv
  *
  * Return: no return
  */

void aux_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Remove an entry completely from the environment\n";

	write(STDOUT_FILENO, help, _strlen(help));
}
