#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char *str_arg;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    printed_chars += print_char(va_arg(args, int));
                    break;

                case 's':
                    str_arg = va_arg(args, char *);
                    printed_chars += print_string(str_arg ? str_arg : "(null)");
                    break;

                case '%':
                    printed_chars += print_char('%');
                    break;

                default:
                    printed_chars += print_char('%');
                    printed_chars += print_char(*format);
                    break;
            }
        }
        else
        {
            printed_chars += print_char(*format);
        }

        format++;
    }

    va_end(args);

    return (printed_chars);
}

/**
 * print_char - Prints a character to the standard output.
 * @c: The character to be printed.
 *
 * Return: 1 (success).
 */
int print_char(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - Prints a string to the standard output.
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
    int printed_chars = 0;

    while (*str)
    {
        printed_chars += print_char(*str);
        str++;
    }

    return (printed_chars);
}

