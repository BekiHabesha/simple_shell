#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	pid_t ppid;

	/*Written before fork was called*/
	/*printf("Before fork I was one\n");*/

	/* called fork */
	pid = fork();

	if (pid == -1)
	{
		perror("Unsuccessful\n");
		return (1);
	}

	if (pid == 0)
	{
		sleep(40);
		printf("I am the child\n");
	}
	else
	{
		ppid = getpid();
		printf("Parent pid is: %u\n", ppid);
	}

	return (0);
}
