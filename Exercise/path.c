#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

char *_getenv(const char *env_var)
{
	extern char **environ;
	int i = 0;
	char *tok;

	while (environ[i])
	{
		tok = strtok(environ[i], "=");
		if (strcmp(env_var, tok) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}

char *get_command(char *command)
{
	char *path = _getenv("PATH");
	char *cmd_full;
	struct stat_st;
	char *token;

	token = strtok(path, ":");
	while (token)
	{
		cmd_full = malloc(strlen(token) + strlen(command) + 2);
		strcpy(cmd_full, token);
		strcat(cmd_full, "/");
		strcat(cmd_full, command);

			return (cmd_full);
	token = strtok(NULL, ":");
	}

	return (NULL);
}


int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	ssize_t buffer_size = 0;
	char *cmd;
	char **args;
	pid_t pid;
	int status, n_chars;

	int main(void)
	{
		char *homevalue = _getenv("HOME");

		printf("%s\n", homevalue);
	}
}
