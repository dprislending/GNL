/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:39:40 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/10 20:17:49 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_check(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != '\n')
			i++;
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*dest;
	int			i;
	int			j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)(malloc(sizeof(char) * 1));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	if (!s2 || !s1)
		return (NULL);
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = 0;
	return (free(s1), dest);
}
