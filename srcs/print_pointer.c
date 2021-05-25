#include "../includes/ft_printf.h"

int	putnb_base_hex(unsigned long long n, size_t baselen, char *base)
{
	if (n < (unsigned long long) baselen)
		return (ft_putchar_count(base[n], 1));
	return (putnb_base_hex(n / (unsigned long long) baselen, baselen, base) + \
	ft_putchar_count(base[(n % baselen)], 1));
}

void	print_pointer(t_prmim all, unsigned long n)
{
	int					digits;

	if (!n && all.precision == 0)
	{
		if (all.minus == 0)
			print_spaces(all.width - 1);
		ft_putstrn("0x", 2);
		if (all.minus)
			print_spaces(all.width - 1);
		return ;
	}
	digits = digits16_count(n);
	if (all.precision == -1 && digits > all.precision)
		all.precision = digits;
	if (!all.minus && all.precision < 1)
		print_spaces_or_zeroes(all.width - 3, all.zero);
	if (all.minus == 0 && all.width > digits)
		print_spaces(all.width - digits - 1);
	ft_putstrn("0x", 2);
	putnb_base_hex(n, 16, "0123456789abcdef");
	if (all.minus)
		print_spaces(all.width - digits - 1);
}
