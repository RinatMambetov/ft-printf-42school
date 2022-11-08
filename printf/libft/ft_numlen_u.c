/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:05:49 by greita            #+#    #+#             */
/*   Updated: 2021/12/07 17:06:48 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen_u(unsigned long num, size_t radix)
{
	size_t	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num)
	{
		num /= radix;
		len++;
	}
	return (len);
}
