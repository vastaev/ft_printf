//part2
//receive int, return string
#include "libft.h"

static int	nlen(long n)
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
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(long nb)
{
	char	*str;
	int		numlen;

	numlen = nlen(nb);
	str = (char *)malloc(sizeof(char) * numlen + 1);
	if (str == NULL)
		return (NULL);
	str[numlen--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb / 10)
	{
		str[numlen] = (nb % 10) + 48;
		nb = nb / 10;
		numlen--;
	}
	str[numlen] = nb + '0';
	return (str);
}
