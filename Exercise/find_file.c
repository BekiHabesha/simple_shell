/*
 * It finds the file in the directory path
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void check_command(char *command)
{
	if (access(command, F_OK) == 0)
		printf("%s: FOUND THE FILE\n", command);
	else
		printf("%s: FILE DOESN'T EXIST\n", command);
}

int main(void)
{
	size_t buffer_size = 0;
	char *buffer = NULL;
	char *token;

	while (1)
	{
		write(1, "#CISFUN$ ", 8);
		getline(&buffer, &buffer_size, stdin);
		token = strtok(buffer, " \t\n");
		if (strcmp(token, "which") == 0)
		{
			token = strtok(NULL, " \t\n");
			while (token)
			{
				check_command(token);
				token = strtok(NULL, " \t\n");
			}
		}
		else
		{
			write(1, "COMMAND DOESN'T EXIST\n", 23);
		}
	}
	return (0);
}
