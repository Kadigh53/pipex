/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:14:42 by aaoutem-          #+#    #+#             */
/*   Updated: 2022/12/31 14:20:51 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strstr(char *haystack, char *needle)
{
	size_t		i;
	size_t		j;
	char		*s;

	i = 0;
	s = (char *)haystack;
	while (i < 5)
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return (haystack);
			j++;
		}
		i++;
	}
	return (NULL);
}