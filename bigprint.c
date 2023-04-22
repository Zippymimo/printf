#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_number - prints an integer recursively
 * @n: the integer to print
 * @f: the format string
 * @len: pointer to length variable
 */
void print_number(int n, const char *f, int *len)
{
    if (n < 0)
    {
        _putchar('-');
        *len += 1;
        print_number(-n, f, len);
    }
    else if (n >= 10)
    {
        print_number(n / 10, f, len);
        _putchar((n % 10) + '0');
        *len += 1;
    }
    else
    {
        _putchar(n + '0');
        *len += 1;
    }
    (void)f;
}

/**
 * print_unsigned - prints an unsigned integer recursively
 * @n: the unsigned integer to print
 * @f: the format string
 * @len: pointer to length variable
 */
void print_unsigned(unsigned int n, const char *f, int *len)
{
    if (n >= 10)
    {
        print_unsigned(n / 10, f, len);
        _putchar((n % 10) + '0');
        *len += 1;
    }
    else
    {
        _putchar(n + '0');
        *len += 1;
    }
    (void)f;
}

/**
 * _printf - prints output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed (excluding the null byte used
 * to end output to strings)
 */
int _printf(const char *format, ...)
{
    int i, len = 0;
    char *s;
    va_list arg;
    int plus_flag, space_flag, hash_flag;

    va_start(arg, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            plus_flag = 0;
            space_flag = 0;
            hash_flag = 0;
            i++;

            while (format[i] == '+' || format[i] == ' ' || format[i] == '#')
            {
                if (format[i] == '+')
                    plus_flag = 1;
                else if (format[i] == ' ')
                    space_flag = 1;
                else if (format[i] == '#')
                    hash_flag = 1;
                i++;
            }

            if (format[i] == 'c')
            {
                _putchar(va_arg(arg, int));
                len += 1;
            }
            else if (format[i] == 's')
            {
}
