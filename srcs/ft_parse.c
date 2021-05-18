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
	while (!ft_strchr(CONVERSIONS, *format) && *format)
	{
		if (*format == '-')
			all->minus = 1;
		format++;
	}
}

static void	precision_parse(const char *format, t_prmim *all, va_list args)
{
	while (!ft_strchr(CONVERSIONS, *format) && *format)
	{
		if (*format == '.')
		{
			all->dot = 1;
			format++;
			if (*format == '*')
			{
				all->precision = va_arg(args, int);
				if (all->precision < 0)
					all->precision = -1;
				return;
			}
			all->precision = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
		format++;
	}
}

static void	width_parse(const char *format, t_prmim *all, va_list args)
{
	while (!ft_strchr(CONVERSIONS, *format) && *format)
	{
		if (*format == '.')
			while (ft_isdigit(*(++format))) {}
		else if (*format == '*')
		{
			all->width = va_arg(args, int);
			if (all->width < 0)
			{
				all->minus = 1;
				all->width = -all->width;
			}
			return;
		}
		if (ft_isdigit(*format) && *format != '0')
		{
			all->width = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
		if (*format != '.' && !ft_strchr(CONVERSIONS, *format))
			format++;
	}
}

static void	type_parse(const char *format, t_prmim *all)
{
	while (!ft_strchr(CONVERSIONS, *format) && *format)
	{
		format++;
		all->to_skip++;
	}
	all->type = (unsigned char)*format;
	if (all->type == 0)
		return ;
}

t_prmim	ft_parse(const char *format, t_prmim all, va_list args)
{
	flags_parse(format, &all);
	width_parse(format, &all, args);
	precision_parse(format, &all, args);
	type_parse(format, &all);
	return (all);
}
