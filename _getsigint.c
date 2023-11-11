/*
   * File_name: _getsigint.c file
   * Functions: get_sigint
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * get_sigint - Handle the crtl + c call in prompt
  *
  * @sig: The Signal handler
  *
  */

void get_sigint(int sig)
{
	(void)sig;

	write(STDOUT_FILENO, "\n^-^ ", 5);
}
