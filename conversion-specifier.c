#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * rot13 - Encode a string using rot13
 * @str: The string to encode
 *
 * Return: A pointer to the encoded string
 */
char *rot13(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'm')
            str[i] += 13;
        else if (str[i] >= 'n' && str[i] <= 'z')
            str[i] -= 13;
        else if (str[i] >= 'A' && str[i] <= 'M')
            str[i] += 13;
        else if (str[i] >= 'N' && str[i] <= 'Z')
            str[i] -= 13;
    }

    return str;
}

/**
 * print_rot13 - Print a rot13'ed string
 * @args: The arguments list
 *
 * Return: The number of characters printed
 */
int print_rot13(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
        str = "(null)";

    str = rot13(str);

    while (*str)
    {
        putchar(*str);
        count++;
        str++;
    }

    return count;
}
