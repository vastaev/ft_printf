//part2
//receive int, return string
#include "libft.h"

static int	nlen(long n, int base)
{
	int		counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n)
	{
		n = n / base;
		counter++;
	}
	return (counter);
}

char	*ft_itoa_base(long nb, int base)
{
	char	*str;
	int		numlen;

	numlen = nlen(nb, base);
	str = (char *)malloc(sizeof(char) * numlen + 1);
	if (str == NULL)
		return (NULL);
	str[numlen--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb)
	{
		if ((nb % base) > 9)
			str[numlen] = (nb % base) + 87;
		else
			str[numlen] = (nb % base) + '0';
		nb = nb / base;
		numlen--;
	}
	return (str);
}
