#include "../includes/ft_printf.h"

static t_prmim	init_struct(t_prmim all)
{
	all.precision = -1;
	all.width = 0;
	all.to_skip = 0;
	all.type = 0;
	all.minus = 0;
	all.plus = 0;
	all.zero = 0;
	all.hash = 0;
	all.space = 0;
	all.l = 0;
	all.L = 0;
	all.h = 0;
	all.H = 0;
	return (all);
}

int	ft_printf(const char *format, ...)
{
	t_prmim	all;
	va_list	args;

	all.written = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			all.written += ft_putchar_count(*format, 1) + 1;
		else if (*format++ == '%')
		{
			all = init_struct(all);
			all = ft_parse(format, all, args);
			if (all.type == 0)
				return (-1);
			ft_print_num(all, args);
			format += all.to_skip;
		}
		format++;
	}
	va_end(args);
	return (ft_putchar_count('.', 0));
}


//static size_t	digit_count(long nb, int base)
//{
//	size_t		i;
//
//	i = 0;
//	while (nb)
//	{
//		nb /= base;
//		i++;
//	}
//	return (i);
//}

//char			*ft_itoa_base(int value, int base)
//{
//	char	*ret;
//	char	*tab_base;
//	int		taille;
//	int		i;
//	int		sign;
//
//	if (base < 2 || base > 16)
//		return (0);
//	if (base == 10 && value == -2147483648)
//		return ("-2147483648");
//	sign = 0;
//	if (base == 10 && value < 0)
//		sign = 1;
//	if (value < 0)
//		value = -value;
//	if (value == 0)
//		return ("0");
//	tab_base = (char *)malloc(sizeof(char) * 17);
//	tab_base = "0123456789ABCDEF";
//	taille = digit_count(value, base);
//	taille += (sign ? 1 : 0);
//	ret = (char *)malloc(sizeof(char) * (taille + 1));
//	i = 1;
//	sign ? (ret[0] = '-') : 0;
//	while (value != 0)
//	{
//		ret[taille - i++] = tab_base[value % base];
//		value /= base;
//	}
//	ret[taille] = '\0';
//	return (ret);
//}
//
//
//typedef union s_float
//{
//	long double dnum;
//	#pragma pack(push, 1)
//	struct
//	{
//		unsigned long long	fraction : 64;
//		unsigned int		exponent : 15;
//		unsigned char		sign : 1;
//	} s_bitfield;
//	#pragma pack(pop)
//}			t_float;
//
//#include <stdio.h>
//int main(void)
//{
////	t_float num;
////
////	num.dnum = 5.99;
////	printf("%Lf\n", num.dnum);
////	ft_printf("%i", n);
////	printf("%d\n", num.s_bitfield.sign);
////	printf("%d\n", num.s_bitfield.exponent);
////	printf("%s\n", ft_itoa_base(num.s_bitfield.fraction, 2));
//	ft_printf("%hhd", (char)45);
//
//
//	return 0;
//}