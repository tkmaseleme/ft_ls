/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:17:13 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/26 13:28:53 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_output(t_flist *lst, va_list va)
{
	int	r;

	r = 0;
	if (lst->specifier == 37)
		r = (ft_putprcnt(lst, 37));
	else if (lst->specifier == 99 || lst->specifier == 67)
		r = ft_chrhandle(lst, va_arg(va, void *));
	else if (lst->specifier == 's' || lst->specifier == 'S')
		r = ft_strhandle(lst, va_arg(va, void *));
	else if (lst->specifier == 'd' || lst->specifier == 'D')
		r = ft_dgthandle(lst, va_arg(va, void *));
	else if (lst->specifier == 'i')
		r = ft_dgthandle(lst, va_arg(va, void *));
	else if (lst->specifier == 'u' || lst->specifier == 'U')
		r = ft_unshandle(lst, va_arg(va, void *));
	else if (lst->specifier == 'o' || lst->specifier == 'O')
		r = ft_octhandle(lst, va_arg(va, void *));
	else if (lst->specifier == 'x' || lst->specifier == 'X')
		r = ft_hexhandle(lst, va_arg(va, void *));
	else if (lst->specifier == 'p')
		r = ft_ptrhandle(lst, va_arg(va, void *));
	else
		r = ft_chrhandle(lst, va_arg(va, void *));
	ft_strdel(&(lst->flags));
	return (r);
}
