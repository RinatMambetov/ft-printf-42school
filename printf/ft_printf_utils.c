/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:10:12 by greita            #+#    #+#             */
/*   Updated: 2021/12/15 16:41:09 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchars(int n, char c)
{
	while (n--)
		ft_putchar_fd(c, 1);
}

static int	ft_getnum(const char *format, t_vars *vars)
{
	int	num;

	num = 0;
	while (ft_isdigit(format[vars->item]))
	{
		num = num * 10 + (format[vars->item] - '0');
		vars->item++;
	}
	return (num);
}

void	ft_readflags(const char *format, t_vars *vars)
{
	if (ft_isdigit(format[vars->item]))
		vars->width = ft_getnum(format, vars);
	if (format[vars->item] == '.')
	{
		vars->item++;
		vars->precision = ft_getnum(format, vars);
	}
}

void	ft_checkwidth(t_vars *vars, size_t len)
{
	if (vars->width > len)
	{
		ft_printchars(vars->width - len, ' ');
		vars->result += vars->width - len;
	}
}

void	ft_checkprecision(t_vars *vars, size_t len, size_t *temp)
{
	if (vars->precision >= (ssize_t)len)
	{
		*temp += vars->precision - len;
		ft_checkwidth(vars, *temp + len);
		ft_printchars(vars->precision - len, '0');
	}
	else
		ft_checkwidth(vars, len);
}
