/*
   * File_name: shell_loop.c file
   * Functions: without_comment, shell_loop
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * without_comment - deletes the comments from the input
  *
  * @in: The input string
  *
  * Return: input without comments
  */

char *without_comment(char *in)
{
	int i, up_to;

	up_to = 0;

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);

				return (NULL);
			}
			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')

				up_to = i;
		}
	}
	if (up_to != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[up_to] = '\0';

	}

	return (in);
}


/**
  * shell_loop - Loop of the shell
  *
  * @datash: The data relevant (av, input, args)
  *
  * Return: no return.
  */

void shell_loop(data_shell *datash)
{
	int loop, i_eof;
	char *input;

	loop = 1;

	while (loop == 1)
	{
		write(STDIN_FILENO, "$ ", 3);
		input = read_line(&i_eof);

		if (i_eof != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);

				continue;
			}
			input = rep_var(input, datash);

			loop = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;

			free(input);
		}
	}
}
