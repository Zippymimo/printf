#include "main.h"
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */
#include <unistd.h> /* write */
#include <stdlib.h> /* malloc, free */

/**
 * print_char - Print a character to stdout.
 * @c: The character to print.
 *
 * Return: Always 1.
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - Print a string to stdout.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_str(char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (write(1, str, len));
}

/**
 * print_hex - Print a number in hexadecimal format.
 * @num: The number to print.
 * @uppercase: Flag to print in uppercase.
 *
 * Return: The number of characters printed.
 */
int print_hex(unsigned int num, int uppercase)
{
	char hex[100];
	int i, len = 0;

	if (num == 0)
		return (print_char('0'));

	while (num)
	{
		int temp = 0;

		temp = num % 16;

		if (temp < 10)
			hex[len] = temp + 48;
		else
			hex[len] = temp + (uppercase ? 55 : 87);

		num /= 16;
		len++;
	}

	for (i = len - 1; i >= 0; i--)
		print_char(hex[i]);

	return (len);
}

/**
 * print_S - Print a string and non-printable characters in ASCII code.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_S(char *str)
{
	int i, len = 0;
	char *hex;

	for (i = 0; str[i]; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			len += print_str("\\x");
			hex = convert_to_hex(str[i], 2);
			len += print_str(hex);
			free(hex);
		}
		else
			len += print_char(str[i]);
	}

	return (len);
}

/**
 * _printf - Print a formatted string to stdout.
 * @format: The format string.
 * @...: Additional arguments to print.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, len = 0;
	char *str_arg;
	int int_arg;
	unsigned int uint_arg;
	char *bin_arg;

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
				case 'c':
					len += print_char(va_arg(args, int));
					break;
				case 's':
					str_arg = va_arg(args, char *);
					if (str_arg == NULL)
						str_arg = "(null)";
					len += print_str(str_arg);
					break;
				case 'd':
				case 'i':
					int_arg = va_arg(args, int);
					if (int_arg < 0)
					{
						len += print_char('-');
						uint_arg = -int_arg;
					}
					else
						uint_arg = int_arg;
					len += print_hex(uint_arg, 0);
					break;
				case '

