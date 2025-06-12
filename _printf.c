#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_number - prints an integer using write
 * @n: integer to print
 * Return: number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	char digit;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n / 10)
		count += print_number(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
	count++;
	return (count);
}

/**
 * _printf - Custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char c;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				int j = 0;

				if (!str)
					str = "(null)";
				while (str[j])
					count += write(1, &str[j++], 1);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				count += print_number(va_arg(args, int));
			}
			else if (format[i] == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				count += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

