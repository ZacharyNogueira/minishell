/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ionorb <ionorb@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:22:57 by znogueir          #+#    #+#             */
/*   Updated: 2023/01/19 23:21:37 by ionorb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_error(char *str)
{
	ft_putstr_fd("env: ", 2);
	// if (str[0] == '-')
	// {
	// 	ft_putstr_fd("options unavailable -- \'", 2);
	// 	ft_putstr_fd(str + 1, 2);
	// 	ft_putstr_fd("\'\n", 2);
	// 	return (125);
	// }
	ft_putchar_fd('\'', 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\': No such file or directory\n", 2);
	return (127);
}

int	ft_env(t_env *loc_env, char **cmd)
{
	t_env	*print_env;

	print_env = loc_env;
	if (cmd[1])
	{
		return (env_error(cmd[1]));
	}
	while (print_env)
	{
		if (print_env->content)
			ft_printf("%s=%s\n", print_env->name, print_env->content);
		print_env = print_env->next;
	}
	return (0);
}

void	split_env(char **name, char **content, char *env)
{
	int	j;

	j = 0;
	while (env[j] != '=')
		j++;
	*name = ft_substr(env, 0, j);
	*content = ft_substr(env, j + 1, ft_strlen(env + j + 1));
	// i++;
}

void	update_env(char	**env, t_data *data)
{
	int		i;
	char	*name;
	char	*content;

	i = 0;
	name = NULL;
	content = NULL;
	free_split(data->paths);
	// printf("\n\n\n--------\n");
	// for (int i = 0; data->char_env[i]; i++)
	// 	printf("%s\n", data->char_env[i]);
	// printf("--------\n\n\n");
	data->paths = NULL;
	while (env && env[i])
	{
		split_env(&name, &content, env[i]);
		// printf("name: %s, content: %s\n", name, content);
		if (!better_strncmp(name, "PATH", ft_strlen("PATH")))
			data->paths = ft_split(content, ":");
		i++;
		free(name);
		free(content);
	}
	// data->paths[0] = "";
	// data->paths[1] = NULL;
}

void	set_env(char **env, t_data *data)
{
	int		i;
	char	*name;
	char	*content;
	char	*tmp;

	i = 0;
	name = NULL;
	content = NULL;
	while (env[i])
	{
		split_env(&name, &content, env[i]);
		if (!better_strncmp(name, "SHLVL", ft_strlen("SHLVL")))
		{
			tmp = ft_itoa(ft_atoi(content) + 1);
			free(content);
			content = tmp;
		}
		else if (!better_strncmp(name, "PATH", ft_strlen("PATH")))
			data->paths = ft_split(content, ":");
		ft_envadd_back(&(data->loc_env), ft_envnew(name, content, 1));
		i++;
	}
}
