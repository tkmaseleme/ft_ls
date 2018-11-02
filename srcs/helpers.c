/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:35:58 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/30 11:21:14 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		copy_data(t_data **src, t_data *cpy)
{
	(*src)->file = cpy->file;
	(*src)->path = cpy->path;
	(*src)->time = cpy->time;
	(*src)->mode = cpy->mode;
	(*src)->link = cpy->link;
	(*src)->user = cpy->user;
	(*src)->group = cpy->group;
	(*src)->size = cpy->size;
	(*src)->block = cpy->block;
}

void			swap_data(t_data **dst, t_data **dst1)
{
	t_data	tmp;

	tmp = **dst;
	copy_data(dst, *dst1);
	copy_data(dst1, &tmp);
}

void			dis_time(time_t time1)
{
	time_t	curtime;
	char	*buf;
	char	*buf1;

	curtime = time(0);
	buf = ctime(&time1);
	if ((curtime - 21990863) > time1 || curtime < time1)
	{
		buf1 = ft_strnew(6);
		buf1 = ft_strsub(buf, 20, 4);
		buf = ft_strsub(buf, 4, 6);
		buf = ft_strjoin(buf, "  ");
		buf = ft_strjoin(buf, buf1);
		ft_strdel(&buf1);
	}
	else
		buf = ft_strsub(buf, 4, 12);
	buf<:12:> = 0;
	ft_putstr(buf);
	ft_putchar(32);
	ft_strdel(&buf);
}

void			dis_num(int link, int xsze)
{
	int		num;

	num = xsze - ft_strlen(ft_itoa(link));
	while (num-- > 0)
		ft_putchar(32);
	ft_putnbr(link);
	ft_putstr(" ");
}
