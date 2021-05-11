#include "../includes/ft_printf.h"

void	putnb_16base(unsigned long n)
{
	unsigned long long	nb;

	nb = (unsigned long long) n;
	if (nb >= 16)
	{
		putnb_16base(nb / 16);
		if (nb % 16 > 9)
			ft_putchar_count(nb % 16 + 87, 1);
		else
			ft_putchar_count(nb % 16 + '0', 1);
	}
	else
	{
		if (nb > 9)
			ft_putchar_count(nb + 87, 1);
		else
			ft_putchar_count(nb + '0', 1);
	}
}

static void	putnb_16base_upper(unsigned long n)
{
	long long	nb;

	nb = (long long) n;
	if (nb >= 16)
	{
		putnb_16base_upper(nb / 16);
		if (nb % 16 > 9)
			ft_putchar_count(nb % 16 + 'A' - 10, 1);
		else
			ft_putchar_count(nb % 16 + '0', 1);
	}
	else
	{
		if (nb > 9)
			ft_putchar_count(nb + 'A' - 10, 1);
		else
			ft_putchar_count(nb + '0', 1);
	}
}

int	digits16_count(unsigned long n)
{
	int	counter;

	counter = 1;
	while (n / 16)
	{
		n = n / 16;
		counter++;
	}
	return (counter);
}

void	print_hex_num(t_prmim all, unsigned long n)
{
	int	digits;

	digits = digits16_count(n);
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
	if (all.hash)
		ft_putstrn("0x", 2);
	print_zeroes(all.precision - digits + 1);
	putnb_16base(n);
	if (all.minus)
		print_spaces(all.width - all.precision + 1);
}

void	print_upper_hex_num(t_prmim all, unsigned long n)
{
	int	digits;

	digits = digits16_count(n);
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
	if (all.hash)
		ft_putstrn("0X", 2);
	print_zeroes(all.precision - digits + 1);
	putnb_16base_upper(n);
	if (all.minus)
		print_spaces(all.width - all.precision + 1);
}
