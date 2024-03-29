/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:48:23 by znogueir          #+#    #+#             */
/*   Updated: 2023/02/01 20:39:05 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(t_data *data, const char *s)
{
	char	*result;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	result = ft_malloc(NULL, data, sizeof(char) * len);
	if (!result)
		return (0);
	i = 0;
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
