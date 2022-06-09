/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:39:44 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/09 13:58:56 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char*	ft_line_to_return(char *stock)
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
	char			buff[BUFFER_SIZE + 1];
	static char 	*stock;
	int				char_read;
	char			*line_to_return;

	line_to_return = 0;
	char_read = 1;
	while (char_read && !ft_check(stock)) // tant quon ai pas a la fin du fichier, et quil ny a pas de \0 dans la static
	{
		char_read = read(fd, buff, BUFFER_SIZE);
		if (char_read <= 0 && stock == 0) // si on donne un fd foireux a read, il va return -1
			return (0);
		buff[char_read] = '\0';
		stock = ft_strjoin(stock, buff);
		if (!stock)
			return (NULL);
	}
	line_to_return = ft_line_to_return(stock);
	stock = ft_get_stock(stock);
	return (line_to_return);
}

// // // #ifdef MAIN
// int	main(void)
// {
// 	int	fd;

// 	fd = open ("fdtest.txt", O_RDONLY);
// 	char	*line;

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);

// 	close(fd);
// }
// // // #endif