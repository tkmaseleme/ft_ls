/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:31:23 by tmaselem          #+#    #+#             */
/*   Updated: 2018/11/01 10:24:27 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_data	*new_data(char *file, char *path, t_flag opt)
{
	t_data		*elem;
	t_stat		dats;

	elem = ft_memalloc(sizeof(t_data));
	elem->file = ft_strdup(file);
	elem->path = ft_strjoin(path, file);
	if (lstat(elem->path, &dats) == -1)
	{
		nerror("ft_ls: ", elem->file, 1);
		return (NULL);
	}
	elem->mode = dats.st_mode;
	elem->link = dats.st_nlink;
	elem->user = dats.st_uid;
	elem->group = dats.st_gid;
	elem->size = dats.st_size;
	elem->block = dats.st_blocks;
	elem->time = (opt.opt_u == 1 ? dats.st_atime : dats.st_mtime);
	elem->dev = dats.st_rdev;
	elem->next = NULL;
	return (elem);
}

t_bool			get_data(t_data **files, t_dir *file, char *path, t_flag opt)
{
	t_data	*data;

	data = *files;
	if (!file)
		return (false);
	if (data)
	{
		while (data->next)
			data = data->next;
		data->next = new_data(file->d_name, path, opt);
	}
	else
	{
		if (*files)
		{
			ft_strdel(&(*files)->file);
			ft_strdel(&(*files)->path);
			free(*files);
		}
		*files = new_data(file->d_name, path, opt);
	}
	return (true);
}

void			get_data_lg(t_data **files, char *file, char *path, t_flag opt)
{
	t_data *data;

	data = *files;
	if (data)
	{
		while (data->next)
			data = data->next;
		data->next = new_data(file, path, opt);
	}
	else
	{
		if (*files)
		{
			ft_strdel(&(*files)->file);
			ft_strdel(&(*files)->path);
			free(*files);
		}
		*files = new_data(file, path, opt);
	}
}
