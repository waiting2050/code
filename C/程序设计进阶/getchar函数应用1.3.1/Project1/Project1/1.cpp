#include <stdio.h>

int main()
{
	int ch;
	while ((ch = getchar()) != (-1)) {
		putchar(ch);
	}
	printf("EOF\n");

	return 0;
}