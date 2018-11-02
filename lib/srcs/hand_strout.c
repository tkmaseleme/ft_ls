/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_strout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:40:26 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/26 13:41:37 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_atoif(char **str1)
{
	int			r;
	int			i;
	int			s;

	r = 0;
	i = 0;
	s = 1;
	while ('0' <= (*str1)[i] && (*str1)[i] <= '9')
	{
		r = r * 10 + (*str1)[i] - '0';
		i++;
	}
	(*str1) = &(*str1)[i];
	return (r * s);
}

char		ft_strchrf(char *str0, int form00)
{
	char		*tmp;

	tmp = str0;
	while (*tmp != '\0')
	{
		if (*tmp == form00)
			return (1);
		tmp++;
	}
	if (*tmp == '\0' && form00 == '\0')
		return (0);
	return (0);
}
