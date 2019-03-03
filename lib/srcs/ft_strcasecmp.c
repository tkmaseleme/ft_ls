/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 08:35:25 by tmaselem          #+#    #+#             */
/*   Updated: 2018/08/31 13:17:40 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (ft_tolower(s1[i]) != 0 && ft_tolower(s2[i]) != 0 &&
		ft_tolower(s1[i]) == ft_tolower(s2[i]))
		i++;
	return ((unsigned char)ft_tolower(s1[i]) -
			(unsigned char)ft_tolower(s2[i]));
}
