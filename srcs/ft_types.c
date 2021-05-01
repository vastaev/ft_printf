#include "../includes/printf.h"
#include "../includes/libft.h"

void	ifchar(va_list args)
{
	char	c;
	c = va_arg(args, int);
	write(1, &c, 1);
}

void	ifintord(va_list args)
{
	char *s;

	s = ft_itoa(va_arg(args, int));
	write(1, s, ft_strlen(s));
	free(s);
}

void	ifstring(va_list args)
{
	char *s;

	s = va_arg(args, char *);
	ft_putstr_fd(s, 1);
}

void	ifuint(va_list args)
{
	char *s;

	s = ft_itoa(va_arg(args, unsigned int));
	ft_putstr_fd(s, 1);
	free(s);
}

void	ifx16(va_list args)
{
	char *s;

	s = ft_itoa_base(va_arg(args, unsigned int), 16);
	ft_putstr_fd(s, 1);
	free(s);
}