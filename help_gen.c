/*
   * File_name: help_gen.c file
   * Functions: aux_help_general, aux_help, aux_help_alias,
   *          : aux_help_cd, and aux_help_exit
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * aux_help_general - The entry point for the help information
  *                    for the help builtin
  *
  * Return: no return
  */

void aux_help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "These commands are defined internally.Type 'help' to see the list";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";

	write(STDOUT_FILENO, help, _strlen(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "unsetenv [variable]\n";

	write(STDOUT_FILENO, help, _strlen(help));
}


/**
  * aux_help - The Help information for
  *            the builtin help.
  *
  * Return: no return
  */

void aux_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n ";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";

	write(STDOUT_FILENO, help, _strlen(help));
}


/**
  * aux_help_alias - The Help information for
  *                  the builtin alias.
  *
  * Return: no return
  */

void aux_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n ";

	write(STDOUT_FILENO, help, _strlen(help));
}


/**
  * aux_help_cd - The Help information for
  *               the builtin alias.
  *
  * Return: no return
  */

void aux_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";

	write(STDOUT_FILENO, help, _strlen(help));
}


/**
  * aux_help_exit - The Help information for
  *                 the builint exit
  *
  * Return: no return
  */

void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "status is that of the last command executed\n";

	write(STDOUT_FILENO, help, _strlen(help));
}
