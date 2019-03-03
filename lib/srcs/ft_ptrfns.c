/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:30:44 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/26 13:31:18 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char	ft_ptrsizer(intmax_t digit)
{
	char		size;

	size = 1;
	digit /= 16;
	while (digit)
	{
		digit /= 16;
		size++;
	}
	return (size);
}

static	char	ft_ptrlen(t_flist *lst, intmax_t digit)
{
	char		r;
	char		t;

	r = ft_ptrsizer(digit);
	t = 0;
	if (lst->prcsn != -1 && lst->prcsn > r)
	{
		t = lst->prcsn - r;
		r = lst->prcsn;
	}
	if (digit != 0)
		r += 2;
	if (t > 0)
		lst->prcsn = t;
	else if (digit == 0 && lst->prcsn == 0)
	{
		lst->prcsn = -2;
		r = 2;
	}
	else
		lst->prcsn = -1;
	return (r);
}

static	char	ft_putptr(uintmax_t digit, t_flist *lst, char *base)
{
	char		l;

	l = 0;
	if (digit == 0 && lst->prcsn == -2)
		return (0);
	if (digit >= 16)
	{
		l += ft_putptr(digit / 16, lst, base);
		l += ft_putchar(base[digit % 16]);
	}
	else
		l += ft_putchar(base[digit % 16]);
	return (l);
}

static	short	ft_pre_ptrhandle(t_flist *lst, uintmax_t digit)
{
	short		l;

	l = 0;
	if ((lst->flags)[2] == '0' && lst->prcsn == -1)
		(lst->flags)[0] = '0';
	lst->size = ft_ptrlen(lst, digit);
	if (lst->flags[0] == '0')
		l += ft_putstrf("0x", -1);
	while ((lst->flags)[1] != '-' && lst->width > (lst->size))
		(l += ft_putchar((lst->flags)[0])) && lst->width--;
	if (lst->flags[4] == ' ')
		l += ft_putstrf("0x", -1);
	while (lst->prcsn != -1 && lst->prcsn > 0)
		(l += ft_putchar('0')) && lst->prcsn--;
	l += ft_putptr(digit, lst, "0123456789abcdef");
	while (lst->width > lst->size && (lst->flags)[1] == '-')
		(l += ft_putchar(' ')) && lst->width--;
	return (l);
}

int				ft_ptrhandle(t_flist *lst, void *digit)
{
	return (ft_pre_ptrhandle(lst, (uintmax_t)digit));
}
