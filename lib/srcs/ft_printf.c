/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:29:37 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/26 13:30:27 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf(char *format, ...)
{
	va_list va;
	size_t	l;

	l = 0;
	va_start(va, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			l += ft_fnscall(&(format), va);
		}
		else
			l += ft_putchar(*format);
		format++;
	}
	va_end(va);
	return (l);
}
