/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:32:46 by tmaselem          #+#    #+#             */
/*   Updated: 2018/08/06 11:04:27 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	parse_arg(const char *arg, const char *options, char *asciitab,
		char **res)
{
	int	u;

	u = 0;
	while (arg[u])
	{
		if ((!options && ft_isalnum(arg[u])) || ft_strchr(options, arg[u]))
			asciitab[(int)arg[u]] = 1;
		else
		{
			if (!(*res = ft_strndup(arg + u, 1)))
				exit(EXIT_FAILURE);
			return (0);
		}
		++u;
	}
	return (1);
}

static void	save_res(const char *asciitab, char **res)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (i < 128)
	{
		if (asciitab[i++])
			++u;
	}
	if (!(*res = ft_strnew(u)))
		exit(EXIT_FAILURE);
	i = 0;
	u = 0;
	while (i < 128)
	{
		if (asciitab[i])
			(*res)[u++] = i;
		++i;
	}
}

int			ft_getopt(int argc, char **argv, const char *options,
		char **res)
{
	int		i;
	char	asciitab[128];

	ft_bzero(asciitab, 128);
	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "--"))
		{
			++i;
			break ;
		}
		else if (argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
		{
			if (!parse_arg(argv[i] + 1, options, asciitab, res))
				return (-1);
		}
		else
			break ;
		++i;
	}
	save_res(asciitab, res);
	return (i);
}
