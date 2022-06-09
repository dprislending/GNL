/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:39:44 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/09 22:42:49 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*ft_line_to_return(char *stock)
{
	int	i;
	int	j;
	char *line_to_return;

	i = 0;
	j = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	line_to_return = malloc(sizeof(char) * (i + 2))	;
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

char *get_next_line(int fd)
{
	static char 	*stock;
	char			*buff[1024];
	int				char_read;
	char			*line_to_return;

	line_to_return = NULL;
	char_read = 1;
	buff[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff[fd])
		return (0);
	buff[fd] = 0;
	while (char_read && !ft_check(stock))
	{
		char_read = read(fd, buff[fd], BUFFER_SIZE);
		if (char_read == -1)
			return (free(buff[fd]), NULL);
		buff[fd][char_read] = 0;
		// if (stock != NULL && stock[0] == '\n')
		// 	return (free(stock), NULL);
		if (char_read <= 0 && stock == 0)
			return (free(buff[fd]), NULL);
		stock = ft_strjoin(stock, buff[fd]);
		if (!stock)
			return (free(buff[fd]), NULL);
	}
	free(buff[fd]);
	if (*stock)
		line_to_return = ft_line_to_return(stock);
	stock = ft_get_stock(stock);
	return (line_to_return);
}