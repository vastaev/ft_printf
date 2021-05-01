#include "../includes/printf.h"

void	ft_parse(va_list args, char type)
{
	int arg;

	ft_conversions(type, args);
//	arg = va_arg(args, int);
//	write(1, &arg, 1);
}

void	ft_conversions(char type, va_list args)
{
	if (type == '%')
		write(1, "%", 1);
	else if (type == 'c')
		ifchar(args);
	else if (type == 'd' || type == 'i')
		ifintord(args);
	else if (type == 's')
		ifstring(args);
	else if (type == 'u')
		ifuint(args);
}