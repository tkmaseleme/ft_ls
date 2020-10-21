/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:56:17 by tmaselem          #+#    #+#             */
/*   Updated: 2018/11/01 10:37:21 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		resolve(t_list *path, t_bool is_dirs, t_flag opt)
{
	DIR		*dir;
	t_list	*lst[3];

	lst[0] = NULL;
	lst[1] = NULL;
	lst[2] = path;
	while (lst[2])
	{
		if ((dir = opendir(lst[2]->content)) == NULL)
			errno != ENOTDIR ? nerror("ft_ls: ", lst[2]->content, 0) : \
				 ft_lstpshbck(&lst[0], lst[2]->content, lst[2]->content_size);
		else
		{
			ft_lstpshbck(&lst[1], lst[2]->content, lst[2]->content_size);
			if (closedir(dir) == -1)
				nerror("ft_ls: ", lst[2]->content, 0);
		}
		lst[2] = lst[2]->next;
	}
	lst[0] ? eva_names(opt, lst[0]) : NULL;
	lst[0] && lst[1] ? (void)ft_putchar(10) : NULL;
	lst[1] ? ft_ls_ld(opt, lst[1], is_dirs) : NULL;
	ft_lstdel(&lst[0], &del);
	ft_lstdel(&lst[1], &del);
}

int				main(int ac, char **av)
{
	t_flag	opt;
	t_list	*path;

	opt = (t_flag){false, false, false, false, false, false, false, false};
	path = NULL;
	if (ac > 1)
	{
		if (strcmp(av[1],"help") == 0 )
		{
			ft_putendl("Only Raltrugf1 flags can be processed\nPlease try again with the right flags\n");
			return (0);
		}
		get_opt(ac - 1, av, &path, &opt);
	}
	if (path == NULL)
		path = ft_lstnew(".", ft_strlen("."));
	resolve(path, path->next != NULL ? true : false, opt);
	ft_lstdel(&path, &del);
	return (0);
}
