/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:44:17 by tmaselem          #+#    #+#             */
/*   Updated: 2018/07/14 14:33:42 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	if (n == 0)
		return (0);
	i = 0;
	j = 0;
	while (--n && s1<:i:> != 0 && s2<:j:> != 0 && (s1<:i:> == s2<:j:>))
	{
		i++;
		j++;
	}
	return (((unsigned char)s1<:i:>) - ((unsigned char)s2<:i:>));
}
