#include "../includes/ft_printf.h"

static t_prmim	init_struct(t_prmim all)
{
	all.type = 0;
	all.width = 0;
	all.minus = 0;
	all.plus = 0;
	all.zero = 0;
	all.hash = 0;
	all.space = 0;
	all.precision = -1;
	return (all);
}

int	ft_printf(const char *format, ...)
{
	t_prmim	all;
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			all.written += ft_putchar_count(*format, 1);
		else if (*format++ == '%')
		{
			all = init_struct(all);
			all = ft_parse(format, all, args);
			if (all.type == 0)
				return (-1);
			ft_print_num(all, args);
			format = format + all.to_skip - 1;
		}
		format++;
	}
	va_end(args);
	return (ft_putchar_count('.', 0));
}
