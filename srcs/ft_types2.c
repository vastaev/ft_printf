#include "../includes/printf.h"
#include "../includes/libft.h"

void	ifbigx16(va_list args)
{
	char	*s;
	int 	i;

	i = 0;
	s = ft_itoa_base(va_arg(args, unsigned int), 16);
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	ft_putstr_fd(s, 1);
	free(s);
}

void	ifpointer(va_list args)
{
	char *s;

	s = ft_itoa_base(va_arg(args, void *), 16);
	ft_putstr_fd(s, 1);
	free(s);
}