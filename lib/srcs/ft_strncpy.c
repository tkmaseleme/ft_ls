/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:46:44 by tmaselem          #+#    #+#             */
/*   Updated: 2018/07/16 15:32:42 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		if (src<:i:>)
		{
			dst<:i:> = src<:i:>;
			i++;
		}
		else
			while (i < len)
			{
				dst<:i:> = 0;
				i++;
			}
	return (dst);
}
