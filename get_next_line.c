/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:39:44 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/06 20:47:41 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int	ft_find_target(const char *stock)
{
	int	i;

	i = 0;
	while(stock[i] != '\n')
		i++;
	return (i);
}

char*	ft_line_to_return(char **stock)
{
	char	*line;
	char	*rest;
	int		lenl;
	int		lens;

	rest = 0;
	lens = ft_strlen(*stock);
	if (ft_strchr(*stock))
	{
		lenl = ft_find_target(*stock);
		line = ft_substr(*stock, 0, lenl);
		rest = ft_substr(*stock, lenl + 1, lens - lenl);
		free(*stock);
		*stock = rest;
		return (line);
	}
	if (!rest)
		return (free(*stock), NULL);
	free(*stock); //bizzare
	return (rest);
}

char *get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char 	*stock;
	int				char_read;
	// char			*line_to_return;

	char_read = 1;
	if (fd <= 0)
		return (0);
	while (char_read && !ft_strchr(stock)) // tant quon ai pas a la fin du fichier, et quil ny a pas de \0 dans la static
	{
		char_read = read(fd, buff, BUFFER_SIZE);
		if (char_read == -1) // si on donne un fd foireux a read, il va return -1
			return (0);
		buff[char_read] = '\0';
		if (char_read == 0)
			return (free(stock), NULL);
		stock = ft_strjoin(stock, buff);
		if (!stock)
			return (0);
	}
	return (ft_line_to_return(&stock));
}

#ifdef MAIN
int	main(void)
{
	int	fd;

	fd = open ("fdtest.txt", O_RDONLY);
	char * line;

	line = get_next_line(fd);
	// char *str = NULL;
	// while ((str = get_next_line(fd)))
	// 	printf("ret: [%s]", str);
	printf("->%s| \n", line);
	printf("->%s| \n", line);
	printf("->%s| \n", line);
	// printf("%s", get_next_line(fd));
	free(line);
	close(fd);
}
#endif