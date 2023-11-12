/*
   * fork + wait + execve
   **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid;
	int status;
	int i;
	char *argv[] = {"ls", "-l", "/tmp", NULL};
	char *envv[] = {"NULL"};

	for (i = 1; i <= 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Errorr:\n");
			return (1);
		}
	}

	if (child_pid == 0)
	{
		execve("/usr/bin/ls", argv, envv);
		perror("Errorr:\n");
		exit(1);
	}
	else
	{
		/*parent*/
		wait(&status);

		return (0);
	}
}
