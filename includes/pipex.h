/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:23:51 by yridgway          #+#    #+#             */
/*   Updated: 2023/02/02 20:52:43 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include "minishell.h"

//finish
void	ft_error(char *extra);
void	ft_close_fds(t_data *data, t_filelist *in, t_filelist *out);

//children
int		ft_pipe(t_data *data, t_cmdtable *table, char **cmd);
void	ft_execute(t_data *data, char **cmd);

//exits
int		ft_permission_denied(char *prog);
int		ft_command_not_found(char *prog);
int		ft_no_such_file(char *prog);
int		ft_is_directory(char *prog);
int		is_directory(char *path);

//paths
char	**ft_get_paths(char **env);
int		check_path(char *prog, char *cmdpath);
char	*ft_join_path(t_data *data, char *path, char *prog);
char	*get_valid_path(t_data *data, char **prog);
char	*get_valid_cmd(t_data *data, char **command, int *ext);

//utils
char	*ft_strjoin_2(char *s1, char *s2);

#endif
