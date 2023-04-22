#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _printf - produces output according to a format.
 * @format: character string
 * 
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0, buffer_pos = 0;
	char buffer[BUFFER_SIZE];

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					buffer[buffer_pos++] = va_arg(args, int);
					break;
				case 's':
					buffer_pos += _strncpy(buffer + buffer_pos, va_arg(args, char *), BUFFER_SIZE - buffer_pos);
					break;
				case '%':
					buffer[buffer_pos++] = '%';
					break;
				case 'd':
				case 'i':
					buffer_pos += _itoa(buffer + buffer_pos, va_arg(args, int), 10);
					break;
				case 'u':
					buffer_pos += _utoa(buffer + buffer_pos, va_arg(args, unsigned int), 10);
					break;
				case 'o':
					buffer_pos += _utoa(buffer + buffer_pos, va_arg(args, unsigned int), 8);
					break;
				case 'x':
					buffer_pos += _utox(buffer + buffer_pos, va_arg(args, unsigned int), 0);
					break;
				case 'X':
					buffer_pos += _utox(buffer + buffer_pos, va_arg(args, unsigned int), 1);
					break;
				case 'b':
					buffer_pos += _utob(buffer + buffer_pos, va_arg(args, unsigned int));
					break;
				default:
					buffer[buffer_pos++] = '%';
					buffer[buffer_pos++] = *format;
					break;
			}
		}
		else
		{
			buffer[buffer_pos++] = *format;
		}

		format++;

		if (buffer_pos >= BUFFER_SIZE - 1)
		{
			write(1, buffer, buffer_pos);
			printed_chars += buffer_pos;
			buffer_pos = 0;
		}
	}

	va_end(args);

	if (buffer_pos > 0)
	{
		write(1, buffer, buffer_pos);
		printed_chars += buffer_pos;
	}

	return (printed_chars);
}
