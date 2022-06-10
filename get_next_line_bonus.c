/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:39:44 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/10 21:11:57 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*ft_line_to_return(char *stock)
{
	int		i;
	int		j;
	char	*line_to_return;

	i = 0;
	j = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	line_to_return = malloc(sizeof(char) * (i + 2));
	if (!line_to_return)
		return (0);
	while (j <= i)
	{
		line_to_return[j] = stock[j];
		j++;
	}
	line_to_return[j] = 0;
	return (line_to_return);
}

char	*ft_get_stock(char *stock)
{
	int		i;
	int		j;
	char	*line_to_return;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
		return (free(stock), NULL);
	line_to_return = malloc (sizeof(char) * (ft_strlen(stock) - i));
	if (!line_to_return)
		return (free(stock), NULL);
	j = i + 1;
	i = 0;
	while (stock[j])
		line_to_return[i++] = stock[j++];
	line_to_return[i] = 0;
	return (free(stock), line_to_return);
}

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*buff;
	int			char_read;
	char		*line_to_return;

	line_to_return = NULL;
	char_read = 1;
	if ((BUFFER_SIZE <= 0) || (fd < 0 && fd > 1024))
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	while (char_read && !ft_check(stock[fd]))
	{
		char_read = read(fd, buff, BUFFER_SIZE);
		if (char_read == -1 || (char_read <= 0 && stock[fd] == 0))
			return (free(buff), NULL);
		buff[char_read] = 0;
		if (stock[fd] != NULL && stock[fd][0] == '\n')
			return (free(stock[fd]), NULL);
		stock[fd] = ft_strjoin(stock[fd], buff);
		if (!stock[fd])
			return (free(buff), NULL);
	}
	free(buff);
	if (*stock[fd])
		line_to_return = ft_line_to_return(stock[fd]);
	stock[fd] = ft_get_stock(stock[fd]);
	return (line_to_return);
}
