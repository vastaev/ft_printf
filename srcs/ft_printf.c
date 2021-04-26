#include "includes/printf.h"

int ft_printf(const char *format, ...)
{
	int length;

	length = 0;
	va_list ap;
	va_start(ap, format);
	while (*format)
	{
		write(1, format, 1);
		if (*format++ == '%')
			return (0);
	}
	va_end(ap);
	return (0);
}

int main(void)
{
	ft_printf("pr%iv");
	return (0);
}
