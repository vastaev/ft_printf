#include "../includes/ft_printf.h"

void	print_pointer(t_prmim all, unsigned long n)
{
	int					digits;
	unsigned long long	nb;

	nb = (unsigned long long) n;
	if (!nb && all.precision == 0)
	{
		if (all.minus == 0)
			print_spaces(all.width - 1);
		ft_putstrn("0x", 2);
		if (all.minus)
			print_spaces(all.width - 1);
		return ;
	}
	digits = digits16_count(nb);
	if (all.precision == -1 && digits > all.precision)
		all.precision = digits;
	if (!all.minus && all.precision < 1)
		print_spaces_or_zeroes(all.width - 3, all.zero);
	if (all.minus == 0 && all.width > digits)
		print_spaces(all.width - digits - 1);
	ft_putstrn("0x", 2);
	putnb_16base(nb);
	if (all.minus)
		print_spaces(all.width - digits - 1);
}
