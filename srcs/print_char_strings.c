#include "../includes/printf.h"

void	print_char(t_prmim all, int c)
{
	if (all.zero && all.width > 1 && !all.minus)
		print_zeroes(all.width);
	if (!all.zero && all.width > 1 && !all.minus)
		print_spaces(all.width);
	ft_putchar_count(c, 1);
	if (!all.zero && all.width > 1 && all.minus)
		print_spaces(all.width);
}

void	print_percent(t_prmim all)
{
	if (all.precision != -1)
		all.zero = 0;
	if (all.precision < 1)
		all.precision = 1;
	if (!all.minus)
		print_spaces_or_zeroes(all.width - all.precision + 1, all.zero);
	ft_putchar_count('%', 1);
	if (all.minus)
		print_spaces(all.width - all.precision + 1);
}

void	ft_putstrn(char *str, int n)
{
	int i;

	if (!str)
		return ;
	i = 0;
	if (n)
		while (i < n)
		{
			ft_putchar_count(str[i], 1);
			i++;
		}
	else if (!n)
		while (str[i] != '\0')
		{
			ft_putchar_count(str[i], 1);
			i++;
		}
}

void	print_string(t_prmim all, char *str)
{
	int strlen;

	if (!str)
		return (print_string(all, "(null)"));
	if (all.precision < 0 && all.precision != -1)
	{
		print_spaces(-all.precision + 1);
		return ;
	}
	strlen = ft_strlen(str);
	if (all.zero && !all.minus)
		print_zeroes(all.width - strlen);
	if (all.precision > 0)
		ft_putstrn(str, all.precision);
	else
		ft_putstrn(str, 0);
	if (all.minus)
		print_spaces(all.width - strlen + 1);
}
