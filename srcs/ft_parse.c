#include "../includes/ft_printf.h"

static void	flags_parse(const char *format, t_prmim *all)
{
	int	i;

	i = 0;
	while (1)
	{
		if (format[i] == '-')
			all->minus = true;
		else if (format[i] == ' ')
			all->space = true;
		else if (format[i] == '+')
			all->plus = true;
		else if (format[i] == '0')
			all->zero = true;
		else if (format[i] == '#')
			all->hash = true;
		else
			break ;
		i++;
	}
	while (!ft_strchr(CONVERSIONS, *format))
	{
		if (*format == '-')
			all->minus = 1;
		format++;
	}
	all->to_skip = i;
}

static void	width_parse(const char *format, t_prmim *all, va_list args)
{
	while (!ft_strchr(CONVERSIONS, *format))
	{
		if (ft_isdigit(*format))
			if (*format == '*')
			{
				all->width = va_arg(args, int);
				if (all->width < 0)
				{
					all->minus = 1;
					all->width = -all->width;
				}
				return ;
			}
			else
				all->precision = ft_atoi(format);
		format++;
	}
	if (format[all->to_skip] == '*')
	{
		all->width = va_arg(args, int);
		if (all->width < 0)
		{
			all->minus = 1;
			all->width = -all->width;
		}
		all->to_skip++;
		return ;
	}
	all->width = ft_atoi(format + all->to_skip);
	while (ft_isdigit(format[all->to_skip]))
		all->to_skip++;
}

static void	precision_parse(const char *format, t_prmim *all, va_list args)
{
	while (!ft_strchr(CONVERSIONS, *format))
	{
		if (*format == '.')
			format++;
		if (*format == '*')
		{
			all->precision = va_arg(args, int);
			if (all->precision < 0)
				all->precision = -1;
			return ;
		}
		else
			all->precision = ft_atoi(format);
		format++;
	}
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
