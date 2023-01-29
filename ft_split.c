/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:07:04 by aaoutem-          #+#    #+#             */
/*   Updated: 2022/12/31 14:15:10 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_free(char **p, int i)
{
	while (i >= 0)
	{
		free(p[i]);
		i--;
	}
	free(p);
	return (NULL);
}

static int	return_value(char *s, char c, int a, int i)
{
	if (s[i - 1] == c)
		return (a);
	return (a + 1);
}

static int	ft_strsnbr(char *s, char c, int para, int mode)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			a++;
			if (para == a && mode == 2)
				return (i - 1);
			i--;
		}
		i++;
	}
	if (para == (int)ft_strlen(s) && mode == 1)
		return (return_value(s, c, a, i));
	return (i - 1);
}

static char	*word_return(char *s, char c, int para)
{
	int	i;
	int	j;

	i = ft_strsnbr(s, c, para, 2);
	while (s[i] == c)
		i--;
	j = i;
	while (s[j] != c && j)
		j--;
	if (s[j] == c)
		j++;
	return (ft_substr(s, j, i - j + 1));
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	n = ft_strsnbr(s, c, ft_strlen(s), 1);
	p = malloc((n + 1) * sizeof(char *));
	if (!p || !s)
		return (NULL);
	i = 1;
	while (i <= n && *s)
	{
		p[i - 1] = word_return(s, c, i);
		if (!p[i - 1])
			return (ft_free(p, i));
		i++;
	}
	p[i - 1] = NULL;
	return (p);
}
