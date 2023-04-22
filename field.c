#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char *str_arg;
    int int_arg;
    unsigned int uint_arg;

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

                case 'd':
                case 'i':
                    int_arg = va_arg(args, int);
                    printed_chars += print_int(int_arg);
                    break;

                case 'b':
                    uint_arg = va_arg(args, unsigned int);
                    printed_chars += print_binary(uint_arg);
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

/**
 * print_int - Prints an integer to the standard output.
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_int(int n)
{
    int printed_chars = 0;
    int reversed = 0;
    int sign = 1;

    if (n < 0)
    {
        sign = -1;
        n = -n;
    }

    while (n)
    {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }

    if (sign == -1)
    {
        printed_chars += print_char('-');
    }

    if (reversed == 0)
    {
        printed_chars += print_char('0');
    }
    else
    {
        while (reversed)
        {
            printed_chars += print_char((reversed % 10) + '0');
            reversed /= 10;
        }
    }

    return (printed_chars);
}

/**
 * print_binary - Prints an unsigned integer in binary to the standard output.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int n)
{
    int printed_chars = 0;
    int bits[32];
    int i;

    if (n == 0)
    {
        printed_chars += print
 }
