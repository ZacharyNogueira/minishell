/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:33:02 by znogueir          #+#    #+#             */
/*   Updated: 2022/12/15 18:42:58 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	handle_signals_v2(int sig)
// {
// 	int	fd;

// 	if (sig == SIGINT)
// 	{
// 		ft_printf("\nv2\n");
// 		fd = open("/dev/null", O_RDONLY);
// 		write(0, "\0", 1);
// 		dup2(fd, 0);
// 		close(fd);
// 	}
// 	else if (sig == SIGQUIT)
// 	{
// 		ft_printf("sig quit");
// 	}
// }

void	handle_signals(int sig, siginfo_t *info, void *context)
{
	int	fd;

	(void)context;
	// (void)info;
	if (sig == SIGINT)
	{
		if (info->si_pid)
		{
			ft_printf("\nparent\n");
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		// 	//do smth;
		}
		else
		{
			ft_printf("\nchild\n");
			fd = open("/dev/null", O_RDONLY);
			write(0, "\0", 1);
			dup2(fd, 0);
			close(fd);
		// 	// ft_printf("\n");
		// 	// rl_on_new_line();
		// 	// rl_replace_line("", 0);
		// 	// rl_redisplay();
		// 	// do smth;
		}
	}
	else if (sig == SIGQUIT)
	{
		//do smth;
		ft_printf("sig quit (^\\)\n");
	}
}

void	signal_handler(void)
{
	struct sigaction	s_sig;

	s_sig.sa_sigaction = handle_signals;
	s_sig.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sig.sa_mask);
	sigaction(SIGINT, &s_sig, 0);
	sigaction(SIGQUIT, &s_sig, 0);
}

// fd = open("dev/null", O_RDONLY);
// dup2(fd, 0);
// close(fd);
