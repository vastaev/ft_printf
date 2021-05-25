#include "../includes/ft_printf.h"

static void casted_print_hex_and_n(t_prmim all, va_list args);

void casted_print(t_prmim all, va_list args)
{
	if (all.type == 'u' && all.l == 1)
		print_uns_i_d(all, va_arg(args, unsigned long int));
	else if (all.type == 'u' && all.L == 1)
		print_uns_i_d(all, va_arg(args, unsigned long long int));
	else if (all.type == 'u' && all.h == 1)
		print_uns_i_d(all, (unsigned short int) va_arg(args,unsigned int));
	else if (all.type == 'u' && all.H == 1)
		print_uns_i_d(all, (unsigned char) va_arg(args,unsigned int));
	else if ((all.type == 'i' || all.type == 'd') && all.l == 1)
		print_sig_i_d(all, va_arg(args, long int));
	else if ((all.type == 'i' || all.type == 'd') && all.L == 1)
		print_sig_i_d(all, va_arg(args, long long int));
	else if ((all.type == 'i' || all.type == 'd') && all.h == 1)
		print_sig_i_d(all, (short int) va_arg(args, int));
	else if ((all.type == 'i' || all.type == 'd') && all.H == 1)
		print_sig_i_d(all, (signed char) va_arg(args, int));
	else
		casted_print_hex_and_n(all, args);
}

static void casted_print_hex_and_n(t_prmim all, va_list args)
{
	if (all.type == 'x' && all.l)
		print_hex_num(all, va_arg(args, unsigned long int), BASE16LR);
	else if (all.type == 'x' && all.L)
		print_hex_num(all, va_arg(args, unsigned long long int), BASE16LR);
	else if (all.type == 'x' && all.h)
		print_hex_num(all, (unsigned short int) va_arg(args, int), BASE16LR);
	else if (all.type == 'x' && all.H)
		print_hex_num(all, (unsigned char) va_arg(args, int), BASE16LR);
	else if (all.type == 'X' && all.l)
		print_hex_num(all, va_arg(args, unsigned long int), BASE16UP);
	else if (all.type == 'X' && all.L)
		print_hex_num(all, va_arg(args, unsigned long long int), BASE16UP);
	else if (all.type == 'X' && all.h)
		print_hex_num(all, (unsigned short int) va_arg(args, int), BASE16UP);
	else if (all.type == 'X' && all.H)
		print_hex_num(all, (unsigned char) va_arg(args, int), BASE16UP);
	else if (all.type == 'n' && all.l)
		*(va_arg(args, long int *)) = all.written;
	else if (all.type == 'n' && all.L)
		*(va_arg(args, long long int *)) = all.written;
	else if (all.type == 'n' && all.h)
		*(va_arg(args, short int *)) = (short)all.written;
	else if (all.type == 'n' && all.H)
		*(va_arg(args, signed char *)) = (signed char)all.written;
}