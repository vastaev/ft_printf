#include "printf.h"

int ft_printf(const char *format, ...)
{
	t_printf	govno;
	va_list		args;

	govno.format = (char *)format;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
		else if (*format++ == '%')
		{
			ft_parse(args, *format);
		}
		format++;
	}
	va_end(args);
	return (0);
}

int main(void)
{
	ft_printf("%%asd%u", 10000000);
	return (0);
}