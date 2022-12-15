/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:25:40 by znogueir          #+#    #+#             */
/*   Updated: 2022/12/15 18:42:58 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(char	**tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	reset_cmd(t_data *data)
{
	free_cmd(data->cmd);
	data->cmd = NULL;
}

void	free_cmd(t_cmdline *cmd)
{
	t_cmdline	*prev;

	while (cmd)
	{
		prev = cmd;
		cmd = cmd->next;
		free(prev->content);
		free(prev);
	}
}

void	free_env(t_env *loc_env)
{
	t_env	*prev;

	while (loc_env)
	{
		prev = loc_env;
		loc_env = loc_env->next;
		free(prev->name);
		free(prev->content);
		free(prev);
	}
}

void	free_files(t_filelist *filelist)
{
	t_filelist	*prev;

	while (filelist)
	{
		prev = filelist;
		filelist = filelist->next;
		free(prev->filename);
		free(prev);
	}
}

void	free_table(t_cmdtable *table)
{
	t_cmdtable	*prev;

	while (table)
	{
		prev = table;
		table = table->next;
		free_files(prev->infile);
		free_files(prev->outfile);
		free_split(prev->cmd);
		free(prev);
	}
}

void	free_all(t_data *data)
{
	free(data->line);
	free_cmd(data->cmd);
	//if (data->char_env)
	free_split(data->char_env);
	free_env(data->loc_env);
	free_split(data->paths);
	//free_table(data->cmdtable);
	free(data);
}

void	ft_exit_fork(t_data *data, char **command, int ext)
{
	ft_close_fds(data);
	close(data->insave);
	free_table(data->cmdtable);
	free_all(data);
	free_split(command);
	exit(ext);
}
