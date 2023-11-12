#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int a = 10;
	int b = 4;
	int diff = a - b;
	pid_t ppid;

	printf("difference is %d\n", diff);

	ppid = getppid();

	printf("My ppid is %u\n", ppid);

	return (0);
}
