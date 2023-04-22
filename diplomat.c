#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int count;
	static char buf[1024];

	if (count == 1024)
	{
		write(1, buf, count);
		count = 0;
	}
	buf[count++] = c;
	return (1);
}

/**
 * _print_hex - prints a number in hexadecimal recursively
 * @n: The number to print
 * @lc: A flag to indicate whether to print lowercase or uppercase letters
 *
 * Return: The number of digits printed
 */
int _print_hex(unsigned long int n, int lc)
{
	static char *hex_uc = "0123456789ABCDEF";
	static char *hex_lc = "0123456789abcdef";
	char *hex = lc ? hex_lc : hex_uc;
	int count = 0;

	if (n >= 16)
		count += _print_hex(n / 16, lc);
	_putchar(hex[n % 16]);
	count++;
	return (count);
}

/**
 * _printf - prints output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str_arg;
	void *p_arg;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					str_arg = va_arg(args, char *);
					if (!str_arg)
						str_arg = "(null)";
					while (*str_arg)
					{
						_putchar(*str_arg);
						count++;
						str_arg++;
					}
					break;
				case 'd':
				case 'i':
					count += print_number(va_arg(args, int));
					break;
				case 'b':
					count += print_binary(va_arg(args, unsigned int));
					break;
				case 'u':
					count += print_unsigned(va_arg(args, unsigned int), 10, 0);
					break;
				case 'o':
					count += print_unsigned(va_arg(args, unsigned int), 8, 0);
					break;
				case 'x':
					count += print_unsigned(va_arg(args, unsigned int), 16, 0);
					break;
				case 'X':
					count += print_unsigned(va_arg(args, unsigned int), 16, 1);
					break;
				case 'p':
					p_arg = va_arg(args, void *);
					_putchar('0');
					_putchar('x');
					count += 2;
					count += _print_hex((unsigned long int)p_arg, 1);
					break;
				case 'S':
					str_arg = va_arg(args, char *);
					if (!str_arg)
						str_arg = "(null)";
					while (*str_arg)
					{
						if (*str_arg >= 32 && *str_arg < 127)
						{
							_putchar(*str_arg);
							count++;
						}
						else
						{
							_putchar('\\');
							_putchar('x');
							count += 2;
							count += _print_hex((unsigned char

