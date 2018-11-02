/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pornhub.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:11:24 by tmaselem          #+#    #+#             */
/*   Updated: 2018/10/31 10:38:51 by tmaselem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PORNHUB_H
# define PORNHUB_H

# include "../lib/includes/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <time.h>

# define MAXX(x)((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define MINN(x)(int32_t)((x) & 0xffffff)

typedef struct			s_flag
{
	t_bool	opt_rr;
	t_bool	opt_l;
	t_bool	opt_a;
	t_bool	opt_r;
	t_bool	opt_t;
	t_bool	opt_u;
	t_bool	opt_f;
	t_bool	opt_g;
}						t_flag;

typedef struct			s_data
{
	char			*file;
	char			*path;
	time_t			time;
	mode_t			mode;
	uid_t			user;
	gid_t			group;
	quad_t			block;
	dev_t			dev;
	nlink_t			link;
	off_t			size;
	struct s_data	*next;
}						t_data;

typedef struct stat		t_stat;
typedef struct dirent	t_dir;
#endif
