/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:13:54 by greita            #+#    #+#             */
/*   Updated: 2021/12/15 16:40:53 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_setnumstr(t_vars *vars, long num, char **numstr,
	const char *format)
{
	if (num == 2147483648
		&& (format[vars->item] == 'd' || format[vars->item] == 'i'))
		*numstr = ft_strdup("2147483648");
	else if (!num && !vars->precision)
	{
		*numstr = ft_strdup("");
		vars->result--;
	}
	else if (format[vars->item] == 'd' || format[vars->item] == 'i')
		*numstr = ft_itoa(num);
	else if (format[vars->item] == 'x')
		*numstr = ft_itoa_base(num, "0123456789abcdef");
	else if (format[vars->item] == 'X')
		*numstr = ft_itoa_base(num, "0123456789ABCDEF");
	else
		*numstr = ft_itoa_base(num, "0123456789");
	if (!*numstr)
		exit(EXIT_FAILURE);
}

void	ft_print_di(int num, t_vars *vars, const char *format)
{
	char	*numstr;
	size_t	len;
	size_t	temp;
	long	n;

	n = num;
	temp = 0;
	len = ft_numlen(num);
	if (vars->precision >= (ssize_t)len && n < 0)
	{
		temp += vars->precision - (len - 1);
		ft_checkwidth(vars, len + temp);
		n *= -1;
		ft_putchar_fd('-', 1);
		ft_printchars(vars->precision - (len - 1), '0');
	}
	else
		ft_checkprecision(vars, len, &temp);
	ft_setnumstr(vars, n, &numstr, format);
	ft_putstr_fd(numstr, 1);
	free(numstr);
	vars->result += len + temp;
}

void	ft_print_u(unsigned int num, t_vars *vars, const char *format)
{
	char	*numstr;
	size_t	len;
	size_t	temp;

	temp = 0;
	len = ft_numlen_u(num, 10);
	ft_checkprecision(vars, len, &temp);
	ft_setnumstr(vars, num, &numstr, format);
	ft_putstr_fd(numstr, 1);
	free(numstr);
	vars->result += len + temp;
}

void	ft_print_x(unsigned int num, t_vars *vars, const char *format)
{
	char	*numstr;
	size_t	len;
	size_t	temp;

	temp = 0;
	len = ft_numlen_u(num, 16);
	ft_checkprecision(vars, len, &temp);
	ft_setnumstr(vars, num, &numstr, format);
	ft_putstr_fd(numstr, 1);
	free(numstr);
	vars->result += len + temp;
}
