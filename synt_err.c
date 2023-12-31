/*
   * File_name: synt_err.c file
   * Functions: error_sep_op, print_syntax_error,
   *          : check_syntax_error
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * error_sep_op - finds the syntax errors
  *
  * @input: The input string
  *
  * @i: The index
  *
  * @last: The last char read
  *
  * Return: index of error.
  *         0 when there are no errors
  */

int error_sep_op(char *input, int i, char last)
{
	int count;

	count = 0;

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, i + 1, last));
	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);
		if (last == '|')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}
	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);
	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);
		if (last == '&')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}
	if (*input == '\0')
		return (0);
	return (error_sep_op(input + 1, i + 1, *input));
}



/**
  * print_syntax_error - prints when a syntax error is found
  *
  * @datash: The data structure
  *
  * @input: The input string
  *
  * @i: The index of the error
  *
  * @bool: To control the msg error
  *
  * Return: no return
  */

void print_syntax_error(data_shell *datash, char *input, int i, int bool)
{
	int length;
	char *msg, *msg2, *msg3, *error, *counter;

	if (input[i] == ';')
	{

		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");

	}
	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");
	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");
	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}


/**
  * check_syntax_error - The intermediate function to
  *                      find and print a syntax error
  *
  * @datash: The data structure
  *
  * @input: The input string
  *
  * Return: 1 if there is an error.
  *         0 in other case
  */

int check_syntax_error(data_shell *datash, char *input)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = first_char(input, &begin);
	if (f_char == -1)
	{
		print_syntax_error(datash, input, begin, 0);
		return (1);
	}

	i = error_sep_op(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		print_syntax_error(datash, input, begin + i, 1);
		return (1);
	}

	return (0);
}
