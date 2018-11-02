/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:31:23 by tmaselem          #+#    #+#             */
/*   Updated: 2018/07/14 14:44:20 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack<:i:> != 0)
	{
		j = 0;
		while (needle<:j:> == haystack<:i + j:> &&
				haystack<:i + j:> != 0 && needle<:j:> != 0)
		{
			if (needle<:j + 1:> == 0)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
