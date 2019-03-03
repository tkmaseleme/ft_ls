/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:47:58 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/30 15:56:24 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		cmp_alp(t_data *data1, t_data *data2)
{
	return (ft_strcmp(data1->file, data2->file));
}

static int		cmp_time(t_data *data1, t_data *data2)
{
	return (data1->time < data2->time);
}

t_data			*sort_data(t_data *data, t_flag opt)
{
	t_data	*data1;

	if (!data)
		return (NULL);
	data1 = data;
	if (opt.opt_f == false)
	{
		sort(&data1, cmp_alp);
		(opt.opt_t == true || opt.opt_u == true) ? sort(&data1, cmp_time) \
					: NULL;
		opt.opt_r == true ? ft_ls_r(&data1) : NULL;
	}
	return (data1);
}

void			sort(t_data **data, int (*cmp)(t_data *data1, t_data *data2))
{
	t_data	*a;
	t_data	*b;

	a = *data;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (cmp(a, b) > 0)
				swap_data(&a, &b);
			b = b->next;
		}
		a = a->next;
	}
}

void			ft_ls_r(t_data **data)
{
	t_data	*data1;
	t_data	*data2;
	t_data	*data3;

	data1 = *data;
	data2 = NULL;
	while (data1)
	{
		data3 = data2;
		data2 = data1;
		data1 = data1->next;
		data2->next = data3;
	}
	*data = data2;
}
