/*
   * File_name: char_err.c file
   * Functions: repeated_char, first_char
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * repeated_char - counts the repetitions of a char
  *
  * @input: The input string
  *
  * @i: The index
  *
  * Return: repetitions
  */

int repeated_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (repeated_char(input - 1, i + 1));

	return (i);
}


/**
  * first_char - finds the index of the first char
  *
  * @input: The input string
  *
  * @i: The index
  *
  * Return: 1 if there is an error.
  *         0 in other case.
  */

int first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{

		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}
