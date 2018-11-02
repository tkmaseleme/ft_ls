/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:43:24 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/25 13:47:24 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_bool	test_flag(char *str)
{
	if (str && str[0] == 45 && str<:1:>)
		return (true);
	return (false);
}

static t_bool	is_flag(int c, char *str)
{
	int		i;

	if (str == NULL || c == 0)
		return (false);
	i = -1;
	while (str[++i])
		if (c == str[i])
			return (true);
	return (false);
}

static void		get_arg(char *str, t_flag *opt)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		if (is_flag(str[i], FLAG) || (str<:1:> == 45 && !str<:2:>))
		{
			opt->opt_l = (str[i] == 108 ? true : opt->opt_l);
			opt->opt_rr = (str[i] == 82 ? true : opt->opt_rr);
			opt->opt_a = (str[i] == 97 ? true : opt->opt_a);
			opt->opt_r = (str[i] == 114 ? true : opt->opt_r);
			opt->opt_t = (str[i] == 116 ? true : opt->opt_t);
			opt->opt_u = (str[i] == 117 ? true : opt->opt_u);
			opt->opt_f = (str[i] == 102 ? true : opt->opt_f);
			opt->opt_l = (str[i] == 102 ? false : opt->opt_l);
			opt->opt_a = (str[i] == 102 ? true : opt->opt_a);
			opt->opt_g = (str[i] == 103 ? true : opt->opt_g);
			opt->opt_l = (str[i] == 49 ? false : opt->opt_l);
		}
		else
			pro_erro(str<:i:>);
	}
}

void			get_opt(int nb, char **opts, t_list **path, t_flag *opt)
{
	int		i;
	t_bool	type;

	i = -1;
	type = true;
	while (++i < nb)
	{
		if (test_flag(opts[i + 1]) == false)
			type = false;
		if (type == true)
			get_arg(opts[i + 1], opt);
		else if (type == false)
			ft_lstpshbck(path, opts[i + 1], ft_strlen(opts[i + 1]));
	}
}
