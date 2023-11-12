#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buf = NULL;
	ssize_t n = 0;

	printf("$ ");
	getline(&buf, &n, stdin);
	printf("%s", buf);
	printf("Buffer size : %zu\n", n);

	free(buf);

	return (0);
}
