/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:32:48 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/30 15:36:08 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		space_helper(t_space *size, t_data *cur)
{
	size->lsize = (int)ft_strlen(ft_itoa(cur->link)) > \
		size->lsize ? (int)ft_strlen(ft_itoa(cur->link)) \
		: size->lsize;
	size->max = (int)ft_strlen(ft_itoa(MAXX(cur->dev))) > size->max \
		? (int)ft_strlen(ft_itoa(MAXX(cur->dev))) : size->max;
	size->min = (int)ft_strlen(ft_itoa(MINN(cur->dev))) > size->min ? \
		(int)ft_strlen(ft_itoa(MINN(cur->dev))) : size->min;
	size->size = (int)ft_strlen(ft_itoa(cur->size)) > size->size ? \
		(int)ft_strlen(ft_itoa(cur->size)) : size->size;
	size->total += cur->block;
}

t_space			get_size(t_flag opt, t_data *files)
{
	t_data	*cur;
	t_space	size;

	size = (t_space){0, 0, 0, 0, 0, 0, 0};
	cur = files;
	while (cur)
	{
		if (!(opt.opt_a == 0 && cur->file<:0:> == 46))
		{
			space_helper(&size, cur);
			space_errors(&size, cur);
		}
		cur = cur->next;
	}
	return (size);
}
