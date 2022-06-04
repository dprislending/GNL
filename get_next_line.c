/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:39:44 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/04 22:04:28 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char *get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char 	*stock;
	size_t			i;
	int				char_readed;

	i = 0;
	char_readed = 1;
	while (char_readed && !ft_strchr(stock)) // tant quon ai pas a la fin du fichier, et quil ny a pas de \0 dans la static
	{
		char_readed = read(fd, buff, BUFFER_SIZE);
		if (char_readed == -1) // si on donne un fd foireux a read, il va return -1
			return (0);
		buff[char_readed] = '\0';
		stock = ft_strjoin(stock, buff);
		if (!stock)
			return (0);
	}
	// cree une fonction qui va recuperer tout ce qui se trouve avant le \n, (\n conpris si il y'a) || line_to_return = ft_coucou(static);
	// cree une fonction qui va suprimmer definitevement de notre static ce quil se trouvais avant le \n (\n compris si il ya) || static = ft_get_rest(static)
	// return (line_to_return);
















	// if (ft_strchr(stock, 10))
	// {
	// 	while (stock[i] != 10)
	// 	{
	// 		line = ft_strdup(stock);
	// 		return (line);
	// 	}
	// 	dest = ft_strrchr(sotck, 10);
	// }










	return (ft_strdup(*line));
}