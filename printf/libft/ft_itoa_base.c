/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greita <greita@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:52:40 by greita            #+#    #+#             */
/*   Updated: 2021/12/08 11:51:13 by greita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(unsigned long n, char *base)
{
	size_t	len;
	size_t	i;
	size_t	radix;
	char	*str;

	i = 0;
	radix = ft_strlen(base);
	len = ft_numlen_u(n, radix);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (i < len--)
	{
		str[len] = base[(n % radix)];
		n /= radix;
	}
	return (str);
}
