#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	ssize_t n = 10;
	char *buf;

	buf = malloc(sizeof(char) * 10);
	printf("Enter your name : ");
	getline(&buf, &n, stdin);
	printf("Your name is : %s", buf);
	printf("Buffer size : %zu\n", n);

	free(buf);

	return (0);
}
