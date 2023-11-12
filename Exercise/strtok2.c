#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "This is a separated word by spaces";
	char delim[] = " ";
	char *trunks;
	int i;

	trunks = strtok(str, delim);
	/*printf("%p\n %p\n", str, trunks);*/

	while (trunks != NULL)
	{
		printf("%s\n", trunks);
		trunks = strtok(NULL, delim);
	}

	for (i = 0; i < 40; i++)
	{
		if (str[i] == '\0')
			printf(" ");
		else
			printf("%c", str[i]);
	}
	return (0);
}
