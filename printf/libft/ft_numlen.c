/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:35:52 by greita            #+#    #+#             */
/*   Updated: 2021/12/07 15:40:01 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(long num)
{
	size_t	len;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}
