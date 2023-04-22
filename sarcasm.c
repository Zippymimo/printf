#include "main.h"
#include <stdarg.h>

/**
 * _abs - computes the absolute value of an integer
 * @n: the integer to compute the absolute value of
 *
 * Return: the absolute value of n
 */
int _abs(int n)
{
    return (n < 0 ? -n : n);
}

/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _puts - writes a string to stdout
 * @s: the string to print
 *
 * Return: the number of characters printed
 */
int _puts(char *s)
{
    int i = 0;

    while (s[i])
        _putchar(s[i++]);
    return (i);
}

/**
 * print_number - prints an integer
 * @n: the integer to print
 * @sign: the sign of the integer (+ or -)
 * @base: the base to print the integer in (e.g. 10 for decimal)
 * @is_unsigned: 1 if the integer is unsigned, 0 otherwise
 *
 * Return: the number of characters printed
 */
int print_number(long int n, char sign, int base, int is_unsigned)
{
    char buffer[32] = {0};
    int i = 30, neg = 0;
    unsigned long int un = n;

    if (!n)
        return (_putchar('0'));
    if (n < 0)
    {
        un = -n;
        neg = 1;
    }
    while (un)
    {
        buffer[i--] = (un % base) + '0';
        un /= base;
    }
    if (neg)
        buffer[i--] = '-';
    else if (sign)
        buffer[i--] = sign;
    if (is_unsigned && base == 8)
        buffer[i--] = '0';
    else if (is_unsigned && (base == 16 || base == 2))
    {
        buffer[i--] = 'x';
        buffer[i--] = '0';
    }
    return (_puts(&buffer[i + 1]));
}

/**
 * _printf - produces output according to a format
 * @format: a character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                _putchar(va_arg(args, int));
                count++;
            }
            else if (*format == 's')
            {
                count += _puts(va_arg(args, char *));
            }
            else if (*format == 'd' || *format == 'i')
            {
                count += print_number(va_arg(args, int), '+', 10, 0);
            }
            else if (*format == 'u')
            {
                count += print_number(va_arg(args, unsigned int), '\0', 10, 1);
            }
            else if (*format == 'o')
            {
                count += print_number(va_arg(args,
/**
 * print_unsigned - Print an unsigned integer
 *
 * @n: Unsigned integer to print
 * @base: Base to use for the conversion
 * @uc: Whether to use uppercase for the letters in base 16
 *
 * Return: Number of digits printed
 */
int print_unsigned(unsigned int n, int base, int uc)
{
	char buffer[32];
	int i = 0, len = 0;

	do {
		buffer[i++] = (n % base) + (n % base > 9 ? (uc ? 'A' : 'a') - 10 : '0');
		n /= base;
	} while (n);

	len = i;

	while (i--)
		_putchar(buffer[i]);

	return (len);
}

/**
 * print_decimal - Print a decimal integer
 *
 * @n: Decimal integer to print
 *
 * Return: Number of digits printed
 */
int print_decimal(int n)
{
	unsigned int un = ABS(n);
	int len = 0;

	if (n < 0)
		_putchar('-'), len++;

	len += print_unsigned(un, 10, 0);

	return (len);
}

/**
 * print_octal - Print an octal integer
 *
 * @n: Octal integer to print
 *
 * Return: Number of digits printed
 */
int print_octal(unsigned int n)
{
	return (print_unsigned(n, 8, 0));
}

/**
 * print_hex - Print a hexadecimal integer (lowercase)
 *
 * @n: Hexadecimal integer to print
 *
 * Return: Number of digits printed
 */
int print_hex(unsigned int n)
{
	return (print_unsigned(n, 16, 0));
}

/**
 * print_hex_uc - Print a hexadecimal integer (uppercase)
 *
 * @n: Hexadecimal integer to print
 *
 * Return: Number of digits printed
 */
int print_hex_uc(unsigned int n)
{
	return (print_unsigned(n, 16, 1));
}
