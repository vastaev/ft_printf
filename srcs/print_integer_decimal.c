#include "../includes/printf.h"

int	digits_count(int n)
{
	int	counter;

	counter = 1;
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n /= 10)
		counter++;
	return (counter);
}

void	prekol_s_nulem(t_prmim all)
{
	if (all.width == 0)
		return ;
	else
		print_spaces(all.width + 1);
}

void	print_unsigned_int_decimal(t_prmim all, unsigned int n)
{
	int	digits;

	digits = digits_count(n);
	if (n == 0 && all.precision == 0)
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
	putnb_base(n, 10);
	if (all.minus)
		print_spaces(all.width - all.precision + 1);
}

void	print_signed_int_decimal(t_prmim all, int n)
{
	int digits;

	digits = digits_count(n);
	if (n >= 0)
		print_unsigned_int_decimal(all, n);
	else
	{
		n = -n;
		if (n == 0 && all.precision == 0)
			return (prekol_s_nulem(all));
		if (all.precision != -1)
			all.zero = 0;
		if (digits > all.precision)
			all.precision = digits;
		if (all.zero)
			ft_putchar_count('-', 1);
		if (!all.minus)
			print_spaces_or_zeroes(all.width - all.precision, all.zero);
		if (!all.zero)
			ft_putchar_count('-', 1);
		print_zeroes(all.precision - digits + 1);
		putnb_base(n, 10);
		if (all.minus)
			print_spaces(all.width - all.precision);
	}
}
