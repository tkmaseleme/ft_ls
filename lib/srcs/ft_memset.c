/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:35:17 by tmaselem          #+#    #+#             */
/*   Updated: 2018/07/14 14:48:43 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	int				i;

	if (len == 0)
	{
		return (b);
	}
	str = (unsigned char *)b;
	i = 0;
	while (len != 0)
	{
		str[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (b);
}
