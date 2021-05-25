#include "../includes/ft_printf.h"

static int	ft_strcmp(const char *s1, const char *s2);

int	digits16_count(unsigned long long n)
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

void	print_hex_num(t_prmim all, unsigned long long n, char *base)
{
	int	digits;

	digits = digits16_count(n);
	if (n == 0 && all.precision == 0)
		return (prekol_s_nulem(all));
	if (all.precision != -1)
		all.zero = 0;
	if (digits > all.precision)
		all.precision = digits;
	if (all.hash)
		all.width -= 2;
	if (all.hash && ft_strcmp(base, BASE16LR) == 0)
		ft_putstrn("0x", 2);
	else if (all.hash && ft_strcmp(base, BASE16UP) == 0)
		ft_putstrn("0X", 2);
	if (!all.minus)
		print_spaces_or_zeroes(all.width - all.precision + 1, all.zero);
	if (all.plus)
		ft_putchar_count('+', 1);
	else if (all.space)
		ft_putchar_count(' ', 1);
	print_zeroes(all.precision - digits + 1);
	putnb_base((long long)n, 16, base);
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

static int	ft_charcmp(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	else
		return (0);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	step;

	step = 0;
	while (s1[step] && s2[step])
	{
		if (!ft_charcmp(s1[step], s2[step]))
			return ((unsigned char)s1[step] - (unsigned char)s2[step]);
		if ((s1[step] == 0) || (s2[step] == 0))
			break ;
		step++;
	}
	return (0);
}
