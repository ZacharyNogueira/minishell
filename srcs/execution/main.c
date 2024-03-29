/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionorb <ionorb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:10:24 by znogueir          #+#    #+#             */
/*   Updated: 2023/02/06 01:43:45 by ionorb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit = 0;

// int	break_malloc_at = 1460;
// int	cur_breakpoint = 0;

void	reset_cmd(t_data *data)
{
	free_cmd(data->cmd);
	data->cmd = NULL;
}

t_data	ft_init(char **env)
{
	t_data	data;

	data.quote = 0;
	data.line = NULL;
	data.paths = NULL;
	data.char_env = NULL;
	data.loc_env = NULL;
	data.cmd = NULL;
	data.cmdtable = NULL;
	data.filelist = NULL;
	data.open_pipe = 0;
	data.hdoc_open = 0;
	data.hdoc_write = 0;
	data.order = 0;
	data.insave = dup(0);
	data.outsave = dup(1);
	data.wc.wc_bin = NULL;
	set_env(env, &data);
	return (data);
}

//	for tester
//	rl_outstream = stderr;

int	launch_normal(char **env)
{
	t_data		data;
	int			exit_status;

	data = ft_init(env);
	while (1)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		clean_memory(&data);
		data.line = readline(PROMPT);
		if (!data.line)
			return (ft_putstr_fd("exit\n", 2), ft_quit(&data), 0);
		ft_add_to_mem(&data, data.line);
		add_history(data.line);
		if (check_errors(data.line))
			continue ;
		ft_lexer(&data);
		exit_status = ft_parser(&data);
		if (!exit_status)
			ft_executor(&data, env);
		else
			g_exit = exit_status;
	}
	return (ft_quit(&data), g_exit);
}

// int	ft_launch_minishell(char *line, char **env)
// {
// 	t_data		data;
// 	int			exit_status;

// 	data = ft_init(env);
// 	signal(SIGINT, handle_sigint);
// 	signal(SIGQUIT, SIG_IGN);
// 	data.line = ft_strdup(&data, line);
// 	add_history(data.line);
// 	if (!check_errors(data.line))
// 	{
// 		ft_lexer(&data);
// 		exit_status = ft_parser(&data);
// 		if (!exit_status)
// 			ft_executor(&data, env);
// 		else
// 			g_exit = exit_status;
// 	}
// 	reset_cmd(&data);
// 	return (g_exit);
// }

int	main(int ac, char **av, char **env)
{
	return ((void)ac, (void)av, launch_normal(env));
}

// int	main(int argc, char **argv, char **env)
// {
// 	char	**cmds;
// 	int		i;

// 	i = 0;
// 	if (argc >= 3 && !ft_strncmp(argv[1], "-c", 3))
// 	{
// 		cmds = ft_split(NULL, argv[2], ";");
// 		while (cmds[i])
// 			ft_launch_minishell(cmds[i++], env);
// 	}
// 	else
// 		launch_normal(env);
// 	exit(g_exit);
// }
