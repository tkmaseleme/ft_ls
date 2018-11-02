/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:46:53 by tmaselem          #+#    #+#             */
/*   Updated: 2018/07/14 13:56:09 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_clear(char **bits_pcs, size_t len)
{
	while (len--)
		ft_strdel(&bits_pcs[len]);
	ft_strdel(bits_pcs);
}
