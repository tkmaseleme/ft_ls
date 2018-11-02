/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:36:39 by tmaselem          #+#    #+#             */
/*   Updated: 2018/07/14 14:26:12 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!(s1) && !(s2))
		return (NULL);
	i = 0;
	j = 0;
	while (s1<:i:> != 0)
		i++;
	while (s2<:j:> != 0)
	{
		s1<:i + j:> = s2<:j:>;
		j++;
		if (j == n)
			return (s1);
	}
	s1<:i + j:> = 0;
	return (s1);
}
