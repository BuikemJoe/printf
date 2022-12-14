#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - function to return character to stdout
 * @format: the guidelines for th printing characters
 * Return: count
 */

int _printf(const char *format, ...)
{
	int count = 0, i;

	va_list data;

	va_start(data format);

	for (i = 0; format[i] != '\0'; i++)
	{
		/* count the number of characters */
		/* print to the screen each character counted */

		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && format[i] != ' ')
		{
			switch (format[i + 1])
			{
				case 'c':
					/*print the char from the va_arguments*/
					count += _putchar(va_arg(data, char *));
					break;
				case 's':
					/*print the string from the va_arguments*/
					count += print_string(va_arg(data, char *));
					break;
				case '%':
					/*print the char from the va_arguments*/
					count += _putchar('%');
					break;
				default;
					break;
			}
			i += 2;
		}
	}
	return (count);
}
