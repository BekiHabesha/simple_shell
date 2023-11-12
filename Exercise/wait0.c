#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;

	/* child process is created */
	pid = fork();

	/* if fork fails */
	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}

	/* in child process */
	if (pid == 0)
	{
		printf("Child Process\n");
	}

	/* in parent process */
	else
	{
		wait(NULL);
		sleep(30);
		printf("Parent Process\n");
	}
	return (0);
}
