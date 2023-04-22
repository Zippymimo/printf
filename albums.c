#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: pointer to the string to print
 *
 * Return: void
 */
void _puts(char *str)
{
    int i = 0;

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }
}

/**
 * _printf - prints output according to a format.
 * @format: character string
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            int zero_flag = 0;

            // Check for zero flag
            if (format[i] == '0')
            {
                zero_flag = 1;
                i++;
            }

            // Handle field width
            int field_width = 0;
            while (format[i] >= '0' && format[i] <= '9')
            {
                field_width = field_width * 10 + (format[i] - '0');
                i++;
            }

            // Handle precision
            int precision = -1;
            if (format[i] == '.')
            {
                precision = 0;
                i++;
                while (format[i] >= '0' && format[i] <= '9')
                {
                    precision = precision * 10 + (format[i] - '0');
                    i++;
                }
            }

            // Handle length modifiers
            int length_modifier = 0;
            if (format[i] == 'l')
            {
                length_modifier = 1;
                i++;
            }
            else if (format[i] == 'h')
            {
                length_modifier = -1;
                i++;
            }

            // Handle conversion specifier
            if (format[i] == 'd' || format[i] == 'i')
            {
                int value = va_arg(args, int);
                char str[32];
                sprintf(str, "%d", value);
                count += _puts(str);
            }
            else if (format[i] == 'u')
            {
                unsigned int value = va_arg(args, unsigned int);
                char str[32];
                sprintf(str, "%u", value);
                count += _puts(str);
            }
            else if (format[i] == 'o')
            {
                unsigned int value = va_arg(args, unsigned int);
                char str[32];
                sprintf(str, "%o", value);
                count += _puts(str);
            }
            else if (format[i] == 'x' || format[i] == 'X')
            {
                unsigned int value = va_arg(args, unsigned int);
                char str[32];
                if (format[i] == 'x')
                    sprintf(str, "%x", value);
                else
                    sprintf(str, "%X", value);
                count += _puts(str);
            }
            else if (format[i] == 'c')
            {
                char value = (char);
	    }
