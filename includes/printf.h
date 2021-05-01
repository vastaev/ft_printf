#ifndef PRINTF_PRINTF_H
# define PRINTF_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_printf
{
	char	*fmt;
	int		i;

	int		type;
	int		width;
}				t_printf;

int		ft_printf(const char *format, ...);
void	ft_parse(va_list args, char type);
void	ft_conversions(char type, va_list args);

// types
void	ifchar(va_list args);
void	ifintord(va_list args);
void	ifstring(va_list args);
void	ifuint(va_list args);
void	ifx16(va_list args);
void	ifbigx16(va_list args);
void	ifpointer(va_list args);

#endif //PRINTF_PRINTF_H
