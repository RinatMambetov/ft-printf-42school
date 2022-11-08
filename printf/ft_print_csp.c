/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:34:13 by greita            #+#    #+#             */
/*   Updated: 2021/12/15 16:27:18 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c, t_vars *vars)
{
	ft_checkwidth(vars, 1);
	ft_putchar_fd(c, 1);
	vars->result++;
}

void	ft_print_s(char *str, t_vars *vars)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if ((ssize_t)len > vars->precision && vars->precision >= 0)
		len = vars->precision;
	ft_checkwidth(vars, len);
	write(1, str, len);
	vars->result += len;
}

void	ft_print_p(unsigned long num, t_vars *vars)
{
	char	*numstr;
	size_t	len;

	numstr = ft_itoa_base(num, "0123456789abcdef");
	if (!numstr)
		exit(EXIT_FAILURE);
	len = ft_strlen(numstr) + 2;
	ft_checkwidth(vars, len);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(numstr, 1);
	free(numstr);
	vars->result += len;
}
