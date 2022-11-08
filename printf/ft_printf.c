/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:00:14 by greita            #+#    #+#             */
/*   Updated: 2021/12/15 16:39:36 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_vars	ft_initvars(void)
{
	t_vars	vars;

	vars.item = 0;
	vars.types = "cspdiuxX%";
	vars.width = 0;
	vars.precision = -1;
	vars.result = 0;
	return (vars);
}

static void	ft_selecttype(const char *format, va_list ap, t_vars *vars)
{
	if (format[vars->item] == 'c')
		ft_print_c(va_arg(ap, int), vars);
	else if (format[vars->item] == 's')
		ft_print_s(va_arg(ap, char *), vars);
	else if (format[vars->item] == 'p')
		ft_print_p(va_arg(ap, unsigned long), vars);
	else if (format[vars->item] == 'd' || format[vars->item] == 'i')
		ft_print_di(va_arg(ap, int), vars, format);
	else if (format[vars->item] == 'u')
		ft_print_u(va_arg(ap, unsigned int), vars, format);
	else if (format[vars->item] == 'x' || format[vars->item] == 'X')
		ft_print_x(va_arg(ap, unsigned int), vars, format);
	else if (format[vars->item] == '%')
	{
		ft_putchar_fd('%', 1);
		vars->result++;
	}
	vars->width = 0;
	vars->precision = -1;
}

static int	ft_parser(const char *format, va_list ap)
{
	t_vars	vars;

	vars = ft_initvars();
	while (format[vars.item] != '\0')
	{
		if (format[vars.item] == '%')
		{
			if (format[vars.item + 1] == '\0')
				return (vars.result);
			vars.item++;
			ft_readflags(format, &vars);
			if (ft_strchr(vars.types, format[vars.item]))
			{
				ft_selecttype(format, ap, &vars);
				vars.item++;
			}
		}
		else
		{
			ft_putchar_fd(format[vars.item], 1);
			vars.item++;
			vars.result++;
		}
	}
	return (vars.result);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			result;

	va_start(ap, format);
	result = ft_parser(format, ap);
	va_end(ap);
	return (result);
}
