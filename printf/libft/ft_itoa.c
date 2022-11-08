/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:32:54 by greita            #+#    #+#             */
/*   Updated: 2021/12/07 15:38:08 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*str;
	long	num;

	i = 0;
	num = n;
	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
		i++;
	}
	while (i < len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
