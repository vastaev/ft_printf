#include "../includes/printf.h"

void	print_pointer(t_prmim all, unsigned long n)
{
	if (all.width)
		print_spaces(all.width - digits16_count(n));
	ft_putstrn("0x", 2);
	if (n)
		putnb_16base(n);
	else
		return ;
}
