/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <yridgway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:58:13 by znogueir          #+#    #+#             */
/*   Updated: 2023/01/29 20:22:12 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*a2;

	if (!s1 || !s2)
		return (1);
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (a1[i] == a2[i] && i < n - 1 && a1[i] && a2[i])
			i++;
	return (a1[i] - a2[i]);
}
