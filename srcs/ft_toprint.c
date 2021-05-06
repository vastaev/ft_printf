#include "../includes/printf.h"

void	ft_print_num(t_prmim all, va_list args)
{
	if (all.type == 'u')
		print_unsigned_int_decimal(all, va_arg(args,unsigned int));
	if (all.type == 'i' || all.type == 'd')
		print_signed_int_decimal(all, va_arg(args, int));
	if (all.type == 'c')
		print_char(all, va_arg(args, int));
	if (all.type == '%')
		print_percent(all);
	if (all.type == 's')
		print_string(all, va_arg(args, char *));
	if (all.type == 'x')
		print_hex_num(all, va_arg(args, unsigned int));
}

void	putnb_base(int n, int base)
{
	long long		nb;

	nb = (long long) n;
	if (nb < 0)
	{
		ft_putchar_count('-', 1);
		putnb_base(-nb, base);
	}
	else if (nb >= 10)
	{
		putnb_base(nb / base, base);
		if (nb % base > 9)
			ft_putchar_count(nb % base + 87, 1);
		else
			ft_putchar_count(nb % base + '0', 1);
	}
	else
		ft_putchar_count(nb + '0', 1);
}

void	putnb_16base(unsigned long n)
{
	long long	nb;

	nb = (long long) n;
	if (nb >= 10)
	{
		putnb_16base(nb / 16);
		if (nb % 16 > 9)
			ft_putchar_count(nb % 16 + 87, 1);
		else
			ft_putchar_count(nb % 16 + '0', 1);
	}
	else
		ft_putchar_count(nb, 1);
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
