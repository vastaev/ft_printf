#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSIONS "cspdiuxX%"
# define FLAGS "0-"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_prmim
{
	int		width;
	int		precision;
	int		dot;

	int		type;
	int		minus;
	int		plus;
	int		hash;
	int		space;
	int		zero;

	int		to_skip;
	int		written;
}				t_prmim;

int			ft_printf(const char *format, ...);
t_prmim		ft_parse(const char *format, t_prmim all, va_list args);
void		ft_print_num(t_prmim all, va_list args);

int			ft_putchar_count(char c, char flag);
int			putnb_base(long long n, size_t baselen, char *base);
int			digits16_count(unsigned long n);
void		prekol_s_nulem(t_prmim all);

void		print_unsigned_int_decimal(t_prmim all, unsigned int n);
void		print_signed_int_decimal(t_prmim all, int n);
void		print_char(t_prmim all, int c);
void		print_percent(t_prmim all);
void		print_string(t_prmim all, char *str);
void		print_hex_num(t_prmim all, unsigned long n);
void		print_upper_hex_num(t_prmim all, unsigned long n);
void		print_pointer(t_prmim all, unsigned long n);

void		print_spaces(int n);
void		print_zeroes(int n);
void		print_spaces_or_zeroes(int n, int flag);
int			ft_strlen(char *str);
void		ft_putstrn(char *str, int n);
void		ft_putstr(char *str);

int			ft_atoi(const char *str);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);

#endif
