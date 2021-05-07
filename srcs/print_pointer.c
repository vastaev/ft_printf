#include "../includes/printf.h"

void	print_pointer(t_prmim all, unsigned long n)
{
	int digits;

	digits = digits16_count(n);
	if (all.precision == -1 && digits > all.precision)
		all.precision = digits;
	if (!all.minus && all.precision > 1)
		print_spaces_or_zeroes(all.width - all.precision - 1, all.zero);
	else if (!all.minus && all.precision < 1)
		print_spaces_or_zeroes(all.width - all.precision - 3, all.zero);
	print_zeroes(all.precision - digits - 3);
	ft_putstrn("0x", 2);
	if (n)
		putnb_16base(n);
	else if (!n && all.precision)
		ft_putstrn("0", 1);
	if (all.minus)
		print_spaces(all.width - all.precision - 1);
}
