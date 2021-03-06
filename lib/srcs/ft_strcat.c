/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:11:45 by tmaselem          #+#    #+#             */
/*   Updated: 2018/07/14 14:09:38 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != 0)
		i++;
	j = 0;
	while (s2[j] != 0)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = 0;
	return (s1);
}
