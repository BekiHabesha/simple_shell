#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int a = 3;
	int b = 5;
	int sum = a + b;
	pid_t pid;

	pid = getpid();

	printf("sum is %d\n", sum);
	printf("pid is %u\n", pid);

	return (0);
}
