#include "../includes/ft_printf.h"

void	ft_print_num(t_prmim all, va_list args)
{
	if (all.h ||  all.l || all.L || all.H)
	{
		casted_print(all, args);
		return ;
	}
	if (all.type == 'u')
		print_uns_i_d(all, va_arg(args, unsigned int));
	else if (all.type == 'i' || all.type == 'd')
		print_sig_i_d(all, va_arg(args, int));
	else if (all.type == 'c')
		print_char(all, va_arg(args, int));
	else if (all.type == '%')
		print_percent(all);
	else if (all.type == 's')
		print_string(all, va_arg(args, char *));
	else if (all.type == 'x')
		print_hex_num(all, va_arg(args, unsigned int), BASE16LR);
	else if (all.type == 'X')
		print_hex_num(all, va_arg(args, unsigned int), BASE16UP);
	else if (all.type == 'p')
		print_pointer(all, va_arg(args, unsigned long));
	else if (all.type == 'n')
		*(va_arg(args, int *)) = all.written;
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
