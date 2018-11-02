/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 13:35:20 by tmaselem          #+#    #+#             */
/*   Updated: 2018/07/14 14:05:10 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*buf1;
	const char	*buf2;

	i = 0;
	buf1 = (char *)dst;
	buf2 = (const char *)src;
	if (dst < src)
	{
		while (i < len)
		{
			buf1[i] = buf2[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			buf1[len - i - 1] = buf2[len - i - 1];
			i++;
		}
	}
	return (dst);
}
