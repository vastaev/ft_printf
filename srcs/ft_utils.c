#include "../includes/ft_printf.h"

void	print_spaces_or_zeroes(int n, int flag)
{
	while (n-- && n > 0)
	{
		if (flag == 1)
			ft_putchar_count('0', 1);
		else
			ft_putchar_count(' ', 1);
	}
}

void	print_spaces(int n)
{
	while (n-- && n > 0)
	{
		ft_putchar_count(' ', 1);
	}
}

void	print_zeroes(int n)
{
	while (n-- && n > 0)
	{
		ft_putchar_count('0', 1);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = c;
	while (*s != chr)
		if (*s++ == '\0')
			return (0);
	return ((char *)s);
}
