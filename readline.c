/*
   * File_name: readline.c
   * Functions: read_line
   * Created: 12th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * read_line - reads the input string.
  *
  * @i_eof: The return value of getline function
  *
  * Return: input string
  */

char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
