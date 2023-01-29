/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:58:08 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/01/04 21:59:57 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	j;
	size_t			k;

	j = 0;
	k = ft_strlen_gnl(s) - start + 1;
	if (len < (size_t)(ft_strlen_gnl(s) - start))
		k = len + 1;
	if (start < (size_t)ft_strlen_gnl(s) && *s != 0)
	{
		p = malloc(k * sizeof(char));
		if (!p)
			return (NULL);
		while ((s + start)[j] && j < len)
		{
			p[j] = (s + start)[j];
			j++;
		}
		p[j] = '\0';
		return (p);
	}
	else
		return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*p;
	size_t	i;

	i = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	if (!s1 && !s2)
		return (NULL);
	p = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	else
	{
		ft_memcpy(p, s1, ft_strlen_gnl(s1) * sizeof(char));
		ft_memcpy(p + ft_strlen_gnl(s1), s2, ft_strlen_gnl(s2) * sizeof(char));
		p[i] = '\0';
		free(s1);
		return (p);
	}
}
