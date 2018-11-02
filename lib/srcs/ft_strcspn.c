/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:16:35 by tmaselem          #+#    #+#             */
/*   Updated: 2018/07/14 14:12:55 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t	spn;
	int		i;

	spn = 0;
	i = 0;
	while (s1<:i:> != 0)
	{
		if (ft_strchr(s2, s1<:i:>))
			return (spn);
		i++;
		spn++;
	}
	return (spn);
}
