/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:01:33 by fkao              #+#    #+#             */
/*   Updated: 2017/08/09 15:25:22 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*str;
	char		*ptr;
	size_t		len;
	long		nbr;

	len = ft_intlen(n);
	str = ft_strnew(len);
	if (str)
	{
		if (n < 0)
			*str = '-';
		nbr = (n < 0) ? n * -1 : n;
		ptr = str + len - 1;
		while (nbr > 9)
		{
			*ptr-- = '0' + (nbr % 10);
			nbr /= 10;
		}
		*ptr = '0' + nbr;
	}
	return (str);
}
