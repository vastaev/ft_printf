#include "../includes/printf.h"

static void	flags_parse(const char *format,  t_prmim *all)
{
	int	i;

	i = 0;
	while (1)
	{
		if (format[i] == '-')
			all->minus = 1;
		else if (format[i] == ' ')
			all->space = 1;
		else if (format[i] == '+')
			all->plus = 1;
		else if (format[i] == '0')
			all->zero = 1;
		else if (format[i] == '#')
			all->hash = 1;
		else
			break ;
		i++;
	}
	all->to_skip = i;
}

static void width_parse(const char *format,  t_prmim *all, va_list args)
{
	if (format[all->to_skip] == '*')
	{
		all->width = va_arg(args, int);
		if (all->width < 0)
		{
			all->minus = 1;
			all->width *= -1;
		}
		all->to_skip++;
		return ;
	}
	all->width = ft_atoi(format + all->to_skip);
	while (ft_isdigit(format[all->to_skip]))
		all->to_skip++;
}

static void precision_parse(const char *format, t_prmim *all, va_list args)
{
	if (format[all->to_skip] == '.')
		all->to_skip++;
	else
		return ;
	if (format[all->to_skip] == '*')
	{
		all->precision = va_arg(args, int);
		all->to_skip++;
		return ;
	}
	all->precision = ft_atoi(format + all->to_skip);
//	if (format[all->to_skip] == '-' || format[all->to_skip] == '+')
//		all->to_skip++;
	while (ft_isdigit(format[all->to_skip]))
		all->to_skip++;
}

static void	type_parse(const char *format, t_prmim *all)
{
	all->type = (unsigned char)format[all->to_skip];
	if (all->type == 0)
		return ;
	all->to_skip++;
}

t_prmim	ft_parse(const char *format, t_prmim all, va_list args)
{
	flags_parse(format, &all);
	width_parse(format, &all, args);
	precision_parse(format, &all, args);
	type_parse(format, &all);
	return (all);
}
