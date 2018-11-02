/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:04:32 by tmaselem          #+#    #+#             */
/*   Updated: 2018/11/01 10:25:59 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "pornhub.h"
# define FLAG "1lRafgrtu"

/*
** Mainish
*/

void	get_opt(int nb, char **opts, t_list **path, t_flag *opt);
void	ft_ls_rr_exec(t_flag opt, char *path);
void	ft_ls_rr(t_flag opt, t_data *data);
t_data	*sort_data(t_data *data, t_flag opt);
void	ft_ls_r(t_data **data);

/*
** Output
*/

void	han_col(mode_t mode);
void	ft_ls(t_flag opt, t_data *files);
void	ft_ls_la(t_flag opt, t_data *files, t_bool is_dir);
void	ft_ls_lg(t_flag opt, t_data *data, t_space size);
void	dis_name(t_flag opt, t_data *files, t_bool is_dir);
void	dis_num(int link, int xsze);
void	output(char *str, int xsze);
void	out_rng(t_data *file, t_space size);
void	dis_time(time_t time1);
t_space	get_size(t_flag opt, t_data *files);

/*
** Manage files
*/

t_bool	get_data(t_data **files, t_dir *file, char *path, t_flag opt);
void	get_data_lg(t_data **files, char *file, char *path, t_flag opt);
void	ft_ls_ld(t_flag opt, t_list *path, t_bool is_dirs);
void	eva_names(t_flag opt, t_list *path);

/*
** Misc
*/

void	pro_erro(char opt);
void	space_errors(t_space *size, t_data *cur);
void	swap_data(t_data **a, t_data **b);
void	sort(t_data **data, int (*cmp)(t_data *data1, t_data *data2));
void	del(void *content, size_t content_size);
void	clean_up(t_data **dirt);
#endif
