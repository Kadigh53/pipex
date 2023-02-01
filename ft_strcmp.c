/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:52:27 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/01/31 00:06:58 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(char *s1, char *s2, int n)
{
	size_t	i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = s1;
	p2 = s2;
	(void)n;
	if (!s2 || !s1)
		return (-1);
	while (n-- > 0 && s2[i])
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		if (p1[i] == '\0' && p2[i] == '\0')
			return (0);
		else if (p1[i] != '\0' && p2[i] == '\0')
			return (1);
		i++;
	}
	if (p1[i] != '\0')
		return (p1[i] - p2[i]);
	return (0);
}
