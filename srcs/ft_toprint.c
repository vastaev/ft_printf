#include "../includes/printf.h"

void	ft_print_num(t_prmim all, va_list args)
{
	if (all.type == 'u')
		print_unsigned_int_decimal(all, va_arg(args,unsigned int));
	else if (all.type == 'i' || all.type == 'd')
		print_signed_int_decimal(all, va_arg(args, int));
	else if (all.type == 'c')
		print_char(all, va_arg(args, int));
	else if (all.type == '%')
		print_percent(all);
	else if (all.type == 's')
		print_string(all, va_arg(args, char *));
	else if (all.type == 'x')
		print_hex_num(all, va_arg(args, unsigned int));
	else if (all.type == 'X')
		print_upper_hex_num(all, va_arg(args, unsigned int));
	else if (all.type == 'p')
		print_pointer(all, va_arg(args, unsigned long));

}

int	ft_putchar_count(char c, char flag)
{
	static int	counter;
	int			save;

	if (flag)
	{
		counter++;
		write(1, &c, 1);
		return (0);
	}
	else
	{
		save = counter;
		counter = 0;
		return (save);
	}
}
