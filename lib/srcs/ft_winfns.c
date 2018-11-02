/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winfns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:34:28 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/26 13:35:15 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char		ft_wtxtsize(unsigned int wc)
{
	if (wc <= 127)
		return (1);
	else if (wc >= 128 && wc <= 2047)
		return (2);
	else if (wc >= 2048 && wc <= 65535)
		return (3);
	else if (wc >= 65536 && wc <= 2097151)
		return (4);
	else
		return (0);
}

int					ft_putwchar(wchar_t wc)
{
	char			rtrn;
	char			size;
	unsigned char	byte;

	rtrn = 0;
	size = ft_wtxtsize(wc);
	if (size == 1)
		return (ft_putchar(wc));
	byte = (260 << (4 - size)) | (wc >> ((size - 1) * 6));
	rtrn += ft_putchar(byte);
	size--;
	while (size--)
	{
		byte = ((wc >> ((size) * 6)) & 63) | 128;
		rtrn += ft_putchar(byte);
	}
	return (rtrn);
}

int					ft_putwstr(wchar_t *ws, int prcsn)
{
	char			rtrn;
	int				indx;

	rtrn = 0;
	indx = 0;
	if (ws == NULL)
		return (ft_putstrf("(null)", prcsn));
	while (ws[indx] != '\0')
		rtrn += ft_putchar(ws[indx++]);
	return (rtrn);
}
