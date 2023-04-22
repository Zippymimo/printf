#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Custom printf function
 * @format: Input string containing format specifier
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, len = 0, n = 0;
	char *str;
	char c;
	int num;
	unsigned int u;
	int negative = 0;

	va_start(args, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '-')
			{
				j = i;
				while (format[j] == '-')
					j++;
				if (format[j] == 'd' || format[j] == 'i')
				{
					num = va_arg(args, int);
					if (num < 0)
					{
						negative = 1;
						num = -num;
					}
					len += _putchar('-');
					len += print_number(num);
					for (; i <= j; i++)
						len += _putchar(format[i]);
					continue;
				}
				else if (format[j] == 'u' || format[j] == 'o'
					 || format[j] == 'x' || format[j] == 'X')
				{
					u = va_arg(args, unsigned int);
					len += _putchar('-');
					len += print_unsigned(u, format[j]);
					for (; i <= j; i++)
						len += _putchar(format[i]);
					continue;
				}
				else if (format[j] == 'c')
				{
					c = va_arg(args, int);
					len += _putchar(c);
					for (; i <= j; i++)
						len += _putchar(format[i]);
					continue;
				}
				else if (format[j] == 's')
				{
					str = va_arg(args, char *);
					if (!str)
						str = "(null)";
					len += _puts(str);
					for (; i <= j; i++)
						len += _putchar(format[i]);
					continue;
				}
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				num = va_arg(args, int);
				if (num < 0)
				{
					negative = 1;
					num = -num;
				}
				len += print_number(num);
			}
			else if (format[i] == 'u' || format[i] == 'o'
				 || format[i] == 'x' || format[i] == 'X')
			{
				u = va_arg(args, unsigned int);
				len += print_unsigned(u, format[i]);
			}
			else if (format[i] == 'c')
			{
				c = va_arg(args, int);
				len += _putchar(c);
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				len += _puts(str);
			}
			else if (format[i] == '%')
			{
				len += _putchar('%');
			}
		}
		else
		{
			len += _putchar(format[i]);
		}
	}

	va_end(args);

	return (len);
}
