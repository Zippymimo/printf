#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/**
 * _reverse - Reverses a string.
 * @str: The string to be reversed.
 *
 * Return: A pointer to the reversed string.
 */
char *_reverse(char *str)
{
    int len, i;
    char temp;

    if (!str)
        return (NULL);

    len = strlen(str);
    for (i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    return (str);
}

/**
 * print_custom_specifier - Prints a custom conversion specifier.
 * @specifier: The custom conversion specifier to print.
 * @args: A va_list of arguments.
 *
 * Return: The number of characters printed.
 */
int print_custom_specifier(const char *specifier, va_list args)
{
    char *str;
    int len;

    if (specifier[0] == '%' && specifier[1] == 'r')
    {
        str = va_arg(args, char *);
        str = _reverse(str);
        len = _strlen(str);
        _write(str, len);
        return (len);
    }

    _write("%", 1);
    if (*specifier)
        _write(specifier, 1);

    return (*specifier != '\0' ? 2 : 1);
}
