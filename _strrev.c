/*
   * File_name: _strrev.c
   * Functions: rev_string
   * Created: 12th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * rev_string - reverses a string.
  *
  * @s: input string.
  *
  * Return: no return.
  */

void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
