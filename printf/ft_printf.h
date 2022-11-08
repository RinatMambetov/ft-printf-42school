/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:55:06 by greita            #+#    #+#             */
/*   Updated: 2021/12/15 16:41:17 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_vars
{
	size_t			item;
	char			*types;
	size_t			width;
	ssize_t			precision;
	size_t			result;
}	t_vars;

int		ft_printf(const char *format, ...);
void	ft_printchars(int n, char c);
void	ft_readflags(const char *format, t_vars *vars);
void	ft_checkwidth(t_vars *vars, size_t len);
void	ft_checkprecision(t_vars *vars, size_t len, size_t *temp);
void	ft_print_c(char c, t_vars *vars);
void	ft_print_s(char *str, t_vars *vars);
void	ft_print_p(unsigned long num, t_vars *vars);
void	ft_print_di(int num, t_vars *vars, const char *format);
void	ft_print_u(unsigned int num, t_vars *vars, const char *format);
void	ft_print_x(unsigned int num, t_vars *vars, const char *format);

#endif
