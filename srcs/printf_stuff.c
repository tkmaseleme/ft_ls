/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:42:00 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/25 14:42:54 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	output(char *str, int xsze)
{
	int		num;

	num = xsze - ft_strlen(str);
	ft_putstr(str);
	while (num-- > 0)
		ft_putchar(32);
	ft_putstr("  ");
}

void	out_rng(t_data *file, t_space size)
{
	int		min;
	int		max;

	min = (int)ft_strlen(ft_itoa(MINN(file->dev)));
	max = (int)ft_strlen(ft_itoa(MAXX(file->dev)));
	ft_putnbr(MAXX(file->dev));
	while (max < size.max--)
		ft_putchar(32);
	ft_putstr(", ");
	ft_putnbr(MINN(file->dev));
	while (min < size.min--)
		ft_putchar(32);
	ft_putchar(32);
}
