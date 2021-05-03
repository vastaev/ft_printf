#include "../includes/printf.h"

void ft_print_num(t_prmim all, va_list args)
{
	if (all.type == 'i' || all.type == 'd')
		print_intOrD(all, args);
}

int	ft_putchar_count(char c, char flag)
{
	static int	counter;

	counter = 0;
	if (flag)
	{
		counter++;
		write(1, &c, 1);
		return (0);
	}
	else
		return (counter);
}