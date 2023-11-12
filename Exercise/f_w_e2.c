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
	pid_t parent_ppid;
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
		child_pid = getpid();
		printf("My pid is %u\n", child_pid);
	}
	else
	{
		/*parent*/
		wait(&status);
		parent_ppid = getppid();
		printf("My ppid is %u\n", parent_ppid);
	}
	return (0);
}
