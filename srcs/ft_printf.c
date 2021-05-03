#include "../includes/printf.h"

static t_prmim init_struct(t_prmim all)
{
	all.type = 0;
	all.width = 0;
	all.minus = 0;
	all.plus = 0;
	all.zero = 0;
	all.precision = -1;
	return (all);
}

int	ft_printf(const char *format, ...)
{
	t_prmim all;
	va_list args;

	all = init_struct(all);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
		else if (*format == '%')
		{
			format++;
			ft_parse(format, all, args);
		}
		format++;
	}
	va_end(args);
	return (0);
}

int main()
{
	ft_printf("Hello, %# World!\n");
	return 0;
}