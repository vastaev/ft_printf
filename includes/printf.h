#ifndef PRINTF_PRINTF_H
# define PRINTF_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_printf
{
	char	*format;

	int 	type;
}				t_printf;

int		ft_printf(const char *format, ...);
void	ft_parse(va_list args, char type);
void	ft_conversions(char type, va_list args);

// types
void	ifchar(va_list args);
void	ifintord(va_list args);
void	ifstring(va_list args);
void	ifuint(va_list args);

#endif //PRINTF_PRINTF_H
