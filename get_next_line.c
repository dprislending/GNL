/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:39:44 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/10 21:11:21 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*stock;
	char		*buff;
	int			char_read;
	char		*line_to_return;

	line_to_return = NULL;
	char_read = 1;
	if ((BUFFER_SIZE <= 0))
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	while (char_read && !ft_check(stock))
	{
		char_read = read(fd, buff, BUFFER_SIZE);
		if (char_read == -1 || (char_read <= 0 && stock == 0))
			return (free(buff), NULL);
		buff[char_read] = 0;
		if (stock != NULL && stock[0] == '\n')
			return (free(stock), NULL);
		stock = ft_strjoin(stock, buff);
	}
	if (*stock)
		line_to_return = ft_line_to_return(stock);
	stock = ft_get_stock(stock);
	return (free(buff), line_to_return);
}

// int    main()
// {
//     int	fd;
// 	int	fd1;
// 	int	fd2;
//     char    *s;
// 	char	*s1;
// 	char	*s2;
//     int        count;

//     count = 10;
//     fd = open("text", O_RDONLY);
//     while (count--)
//     {
//         s = get_next_line(fd);
//         printf("GNL : %s", s);
//         free(s);
//     }
//     close(fd);

// 	fd1 = open("text1", O_RDONLY);
//     while (count--)
//     {
//         s1 = get_next_line(fd1);
//         printf("GNL : %s", s1);
//         free(s1);
//     }
//     close(fd1);

// 	fd2 = open("text2", O_RDONLY);
//     while (count--)
//     {
//         s2 = NULL;
//         printf("GNL : %s", s2);
//         free(s2);
//     }
//     close(fd2);
// }