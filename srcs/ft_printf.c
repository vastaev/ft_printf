#include "printf.h"
#include <>

int ft_printf(const char *format, ...)
{
	t_printf	all;
	va_list		args;

	all.fmt = (char *)format;
	va_start(args, format);
	while (all.fmt[all.i])
	{

		if (all.fmt[all.i] == '%')
			ft_parse(args, *format);
		else
			all.i++;
	}
	va_end(args);
	return (0);
}

int main(void)
{
	int a;
	void *p;

	p = &a;
	ft_printf("%%asd %5d", 22);
	return (0);
}