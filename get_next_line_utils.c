/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:39:40 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/06 20:23:52 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

size_t	ft_strlen(const char * s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lens;
	size_t	lenf;
	char	*dest;

	i = 0;
	lens = ft_strlen(s);
	if (len + start <= lens)
		lenf = len;
	else
		lenf = lens - start;
	dest = malloc((lenf + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (i < lenf)
	{
		dest[i] = s[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		len1;
	size_t		len2;
	char		*dest;
	int			i;
	int			j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = (char *)malloc((len1 + len2 + 1) * sizeof (char));
	if (!dest)
		return (0);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
	}
	j = -1;
	while (s2[++j])
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	return (dest);
}
