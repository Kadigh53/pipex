/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:52:27 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/01/29 21:57:31 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	ft_strcmp(char *s1, char *s2)
// {
// 	size_t			i;
// 	char	*p1;
// 	char	*p2;

// 	i = 0;
// 	p1 = s1;
// 	p2 = s2;
// 	if (!s1)
// 		return (-1);
// 	while (s1[i] && s2[i])
// 	{
// 		if (p1[i] != p2[i])
// 			return (p1[i] - p2[i]);
// 		if (p1[i] == '\0' || p2[i] == '\0')
// 			return (p1[i] - p2[i]);
// 		i++;
// 	}
// 	if (!p1[i] && !p2[i])
// 		return (0);
// 	return (p1[i] - p2[i]);
// }
int	ft_strcmp(char *s1, char *s2, int n)
{
	size_t			i;
	char	*p1;
	char	*p2;

	i = 0;
	p1 = s1;
	p2 = s2;
	if (!n || !s1)
		return (-1);
	while (n-- > 0)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		if (p1[i] == p2[i] && p2[i] == '\0')
			return (0); //p1[i] - p2[i]);
		// else if ( )
		i++;
	}
	if (p1[i] != p2[i] || (p1[i] != '\0'))
		return (p1[i] - p2[i]);
	return (0);
}

// int main(int ac, char *av[])
// {	
// 	printf("%d",ft_strcmp("eof",av[1]));
// }