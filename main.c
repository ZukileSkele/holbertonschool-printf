#include "main.h"
#include <stdio.h> // Needed for standard printf

int main(void)
{
	int len;

	len = _printf("Character: %c\n", 'H');
	printf("Length: %d\n", len);

	len = _printf("String: %s\n", "Holberton");
	printf("Length: %d\n", len);

	len = _printf("Percent: %%\n");
	printf("Length: %d\n", len);

	return (0);
}

