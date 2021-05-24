#include "../includes/ft_printf.h"

static int	digits_count(long long n)
{
	int	counter;

	counter = 1;
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n / 10)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

void	prekol_s_nulem(t_prmim all)
{
	if (all.width == 0)
		return ;
	else
		print_spaces(all.width + 1);
}

void	print_uns_i_d(t_prmim all, unsigned int n)
{
	int					digits;
	unsigned long long	nb;

	nb = (unsigned long long) n;
	digits = digits_count(nb);
	if (nb == 0 && all.precision == 0)
		return (prekol_s_nulem(all));
	if (all.precision != -1)
		all.zero = 0;
	if (digits > all.precision)
		all.precision = digits;
	if (!all.minus)
		print_spaces_or_zeroes(all.width - all.precision + 1, all.zero);
	if (all.plus)
		ft_putchar_count('+', 1);
	else if (all.space)
		ft_putchar_count(' ', 1);
	print_zeroes(all.precision - digits + 1);
	putnb_base(nb, 10, "0123456789");
	if (all.minus)
		print_spaces(all.width - all.precision + 1);
}

void	print_sig_i_d(t_prmim all, int n)
{
	long long	nb;

	nb = (long long) n;
	if (nb >= 0)
		print_uns_i_d(all, nb);
	else
	{
		nb = -nb;
		if (nb == 0 && all.precision == 0)
			return (prekol_s_nulem(all));
		if (all.precision != -1)
			all.zero = 0;
		if (digits_count(nb) > all.precision)
			all.precision = digits_count(nb);
		if (all.zero)
			ft_putchar_count('-', 1);
		if (!all.minus)
			print_spaces_or_zeroes(all.width - all.precision, all.zero);
		if (!all.zero)
			ft_putchar_count('-', 1);
		print_zeroes(all.precision - digits_count(nb) + 1);
		putnb_base(nb, 10, "0123456789");
		if (all.minus)
			print_spaces(all.width - all.precision);
	}
}
