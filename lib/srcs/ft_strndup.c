/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 11:12:45 by tmaselem          #+#    #+#             */
/*   Updated: 2018/08/06 11:15:27 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*duplicate;

	duplicate = ft_strnew(n);
	if (duplicate == NULL)
		return (NULL);
	ft_strncpy(duplicate, s, n);
	duplicate[n] = '\0';
	return (duplicate);
}
