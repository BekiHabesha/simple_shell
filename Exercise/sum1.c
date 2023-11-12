#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int i;

	printf("argv content is argv[]\n");

	for (i = 0; i < ac; i++)
	{
		printf("argv[%d] = %s\n", i, av[i]);
	}
	return (0);
}
