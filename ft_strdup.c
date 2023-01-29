/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:04:20 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/01/04 22:06:02 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!p)
		return (NULL );
	else
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
}