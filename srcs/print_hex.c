#include "../includes/ft_printf.h"

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
	putnb_base((long long)n, 16, "0123456789abcdef");
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
	putnb_base((long long)n, 16, "0123456789ABCDEF");
	if (all.minus)
		print_spaces(all.width - all.precision + 1);
}


int	putnb_base(long long n, size_t baselen, char *base)
{
	if (n < (long long)baselen)
		return (ft_putchar_count(base[n], 1));
	return	(putnb_base(n / (long long)baselen, baselen, base) +
	ft_putchar_count(base[(n % baselen)], 1));
}