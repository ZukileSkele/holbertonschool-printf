#include "main.h"
#include <stdio.h>

int main(void)
{
	int len;

	len = _printf("Integer: %d\n", 123);
	printf("Length: %d\n", len);

	len = _printf("Negative: %i\n", -456);
	printf("Length: %d\n", len);

	len = _printf("Mix: %c %s %d%%\n", 'A', "Test", 42);
	printf("Length: %d\n", len);

	return (0);
}

