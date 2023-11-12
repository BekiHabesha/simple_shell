#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "This is a separated word by spaces";
	char delim[] = " ";
	char *trunks;

	trunks = strtok(str, delim);
	printf("%s\n", trunks);

	trunks = strtok(NULL, delim);
	printf("%s\n", trunks);

	trunks = strtok(NULL, delim);
	printf("%s\n", trunks);

	trunks = strtok(NULL, delim);
	printf("%s\n", trunks);

	trunks = strtok(NULL, delim);
	printf("%s\n", trunks);

	trunks = strtok(NULL, delim);
	printf("%s\n", trunks);

	trunks = strtok(NULL, delim);
	printf("%s\n", trunks);

	trunks = strtok(NULL, delim);
	if (trunks == NULL)
		printf("Last part is NULL\n");
	else
		printf("It is not NULL\n");

	return (0);
}
