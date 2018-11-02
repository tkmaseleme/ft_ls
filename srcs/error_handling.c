/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:30:42 by tmaselem          #+#    #+#             */
/*   Updated: 2018/11/01 10:29:26 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	pro_erro(char opt)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(opt, 2);
	ft_putstr_fd("\nusage: ft_ls [-Rafglrtu1] [file ...]\n", 2);
	exit(1);
}

void	space_errors(t_space *size, t_data *cur)
{
	if (getpwuid(cur->user))
		size->usize = (int)ft_strlen(getpwuid(cur->user)->pw_name) \
			> size->usize ? (int)ft_strlen(getpwuid(cur->user)->pw_name) \
			: size->usize;
	else
		size->usize = (int)ft_strlen(ft_itoa(cur->user)) \
			> size->usize ? (int)ft_strlen(ft_itoa(cur->user)) \
			: size->usize;
	if (getgrgid(cur->group))
		size->gsize = (int)ft_strlen(getgrgid(cur->group)->gr_name) \
			> size->gsize ? \
			(int)ft_strlen(getgrgid(cur->group)->gr_name) : size->gsize;
	else
		size->gsize = (int)ft_strlen(ft_itoa(cur->group)) \
			> size->gsize ? (int)ft_strlen(ft_itoa(cur->group)) \
			: size->gsize;
}

void	clean_up(t_data **dirt)
{
	while (*dirt)
	{
		ft_strdel(&((*dirt)->file));
		ft_strdel(&((*dirt)->path));
		free(*dirt);
		*dirt = (*dirt)->next;
	}
}
