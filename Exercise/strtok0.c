#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "Jesus loves you";
	char delim[] = " ";
	char *token;

	token = strtok(str, delim);
	printf("%s\n", token);

	return (0);
}
