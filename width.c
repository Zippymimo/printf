#include "main.h"

/**
 * _print_u - Print an unsigned integer
 * @n: The unsigned integer to print
 * @count: A pointer to the character count
 *
 * Return: Always void
 */
void _print_u(unsigned int n, int *count)
{
	if (n / 10)
		_print_u(n / 10, count);
	*count += _putchar((n % 10) + '0');
}

/**
 * _print_o - Print an integer in base 8 (octal)
 * @n: The integer to print
 * @count: A pointer to the character count
 *
 * Return: Always void
 */
void _print_o(unsigned int n, int *count)
{
	if (n / 8)
		_print_o(n / 8, count);
	*count += _putchar((n % 8) + '0');
}

/**
 * _print_x - Print an integer in base 16 (lowercase)
 * @n: The integer to print
 * @count: A pointer to the character count
 *
 * Return: Always void
 */
void _print_x(unsigned int n, int *count)
{
	if (n / 16)
		_print_x(n / 16, count);
	*count += _putchar("0123456789abcdef"[n % 16]);
}

/**
 * _print_X - Print an integer in base 16 (uppercase)
 * @n: The integer to print
 * @count: A pointer to the character count
 *
 * Return: Always void
 */
void _print_X(unsigned int n, int *count)
{
	if (n / 16)
		_print_X(n / 16, count);
	*count += _putchar("0123456789ABCDEF"[n % 16]);
}

/**
 * _printf - Print formatted output to stdout
 * @format: A pointer to a string of characters to print
 *
 * Return: The number of characters printed, excluding the null byte used to
 *         end output to strings, or -1 if an error occurs
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += _print_s(va_arg(args, char *));
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				case 'd':
				case 'i':
					count += _print_i(va_arg(args, int));
					break;
				case 'u':
					_print_u(va_arg(args, unsigned int), &count);
					break;
				case 'o':
					_print_o(va_arg(args, unsigned int), &count);
					break;
				case 'x':
					_print_x(va_arg(args, unsigned int), &count);
					break;
				case 'X':
					_print_X(va_arg(args, unsigned int), &count);
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
			}
			format++;
		}
		else
		{
			_putchar(*format);
			count++;
			format++;
		}
	}

	va_end(args);

	return (count);
}
