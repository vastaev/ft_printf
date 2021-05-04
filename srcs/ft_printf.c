#include "../includes/printf.h"

static t_prmim init_struct(t_prmim all)
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
	t_prmim all;
	va_list args;

	all = init_struct(all);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			write(1, format, 1);
		else if (*format++ == '%')
		{
			all = ft_parse(format, all, args);
			ft_print_num(all, args);
			format = format + all.to_skip;
		}
		format++;
	}
	va_end(args);
	return (ft_putchar_count('.', 0));
}


#include <stdio.h>
int main()
{
	printf("\n%d\n", ft_printf("%5.3d", 42));
	return 0;
}