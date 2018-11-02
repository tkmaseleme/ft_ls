/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_txtfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:32:20 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/26 13:33:19 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_putstrf(char *str, int prcsn)
{
	int	l;

	l = 0;
	if (str == NULL)
		return (ft_putstrf("(null)", prcsn));
	while (*str != '\0' && prcsn--)
		l += ft_putchar(*str) && str++;
	return (l);
}

int		ft_putprcnt(t_flist *lst, char p)
{
	int	l;

	l = 0;
	if ((lst->flags)[2] == '0')
		(lst->flags)[0] = '0';
	if ((lst->flags)[1] != '-' && lst->width > 1)
	{
		while (((lst->width)-- - 1))
			l += ft_putchar((lst->flags)[0]);
		l += ft_putchar(p);
	}
	else if (lst->width > 1 && (lst->flags)[1] == '-')
	{
		l += ft_putchar(p);
		while ((lst->width)-- - 1)
			l += ft_putchar(' ');
	}
	else
		l += ft_putchar(p);
	return (l);
}

int		ft_chrhandle(t_flist *lst, void *c)
{
	int	l;

	l = 0;
	if ((lst->flags)[2] == '0')
		(lst->flags)[0] = '0';
	if ((lst->flags)[1] != '-' && lst->width > 1)
		while (((lst->width)-- - 1))
			l += ft_putchar((lst->flags)[0]);
	if (lst->specifier == 'c' && !lst->l)
		l += ft_putchar((int)c);
	else if (lst->specifier == 'C' || (lst->specifier == 'c' && lst->l))
		l += ft_putchar((int)c);
	else
		l += ft_putchar(lst->specifier);
	if (lst->width > 1 && (lst->flags)[1] == '-')
		while ((lst->width)-- - 1)
			l += ft_putchar(' ');
	return (l);
}

int		ft_strhandle(t_flist *lst, void *s)
{
	int	l;

	lst->size = (s != NULL) ? ft_strlen((char *)s) : 6;
	l = 0;
	lst->size = !lst->prcsn ? lst->width : lst->size;
	if ((lst->flags)[2] == '0')
		(lst->flags)[0] = '0';
	while ((lst->flags)[1] != '-' && lst->width > lst->size)
		l += ft_putchar((lst->flags)[0]) && (lst->width)--;
	while ((lst->flags)[1] != '-' && lst->width > lst->prcsn &&
			lst->prcsn != -1 && (lst->size > lst->prcsn))
		l += ft_putchar((lst->flags)[0]) && (lst->width)--;
	if (lst->specifier == 's' && !lst->l)
		l += ft_putstrf((char *)s, lst->prcsn);
	else if (lst->specifier == 'S' || (lst->specifier == 's' && lst->l))
		l += ft_putwstr((wchar_t *)s, lst->prcsn);
	while ((lst->flags)[1] == '-' && lst->width > lst->size)
		l += ft_putchar(' ') && lst->width--;
	while ((lst->flags)[1] != '-' && lst->width > lst->prcsn &&
	lst->prcsn != -1 && (lst->size - lst->prcsn))
		l += ft_putchar(' ') && lst->size--;
	return (l);
}
