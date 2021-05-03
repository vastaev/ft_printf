#ifndef PRINTF_PRINTF_H
# define PRINTF_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_prmim
{
	int		width;
	int		precision;

	int		type;
	int 	minus;
	int 	plus;
	int		hash;
	int		space;
	int		zero;

	int		to_skip;
}				t_prmim;

int			ft_printf(const char *format, ...);
t_prmim 	ft_parse(const char *format, t_prmim all, va_list args);

void		ft_print_num(t_prmim all, va_list args);
int			ft_putchar_count(char c, char flag);
void		print_int_decimal(t_prmim all, va_list args);

int			ft_atoi(const char *str);
int			ft_isdigit(int c);

#endif //PRINTF_PRINTF_H
