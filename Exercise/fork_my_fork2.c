#include <stdio.h>
#include <unistd.h>

int main(void)
{
	fork();
	fork();
	fork();
	printf("%u This is My pid.\n", getpid());

	return (0);
}
