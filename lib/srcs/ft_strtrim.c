/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:49:25 by tmaselem          #+#    #+#             */
/*   Updated: 2018/08/05 11:14:07 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			i;
	size_t			len;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (ft_iswhitespace(s<:i:>))
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && ft_iswhitespace(s<:len:>))
		len--;
	return (len < i) ? (ft_strdup("")) : (ft_strsub(s, i, len - i + 1));
}
