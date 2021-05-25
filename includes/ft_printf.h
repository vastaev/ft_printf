#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSIONS "cspdiuxX%n"
# define BASE16LR "0123456789abcdef"
# define BASE16UP "0123456789ABCDEF"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_prmim
{
	int		width;
	int		precision;

	int		type;
	int		minus;
	int		plus;
	int		hash;
	int		space;
	int		zero;
	int		l;
	int		L;
	int		h;
	int		H;

	int		to_skip;
	int		written;
}				t_prmim;

int			ft_printf(const char *format, ...);
t_prmim		ft_parse(const char *format, t_prmim all, va_list args);
void		ft_print_num(t_prmim all, va_list args);

int			ft_putchar_count(char c, char flag);
int			putnb_base(long long n, size_t baselen, char *base);
int			putnb_base_hex(unsigned long long n, size_t baselen, char *base);
int			digits16_count(unsigned long long n);
void		prekol_s_nulem(t_prmim all);

void		print_uns_i_d(t_prmim all, unsigned long long n);
void		print_sig_i_d(t_prmim all, long long int n);
void		print_char(t_prmim all, int c);
void		print_percent(t_prmim all);
void		print_string(t_prmim all, char *str);
void		print_hex_num(t_prmim all, unsigned long long n, char *base);
void		print_pointer(t_prmim all, unsigned long n);
void		casted_print(t_prmim all, va_list args);

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
