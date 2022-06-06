/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:39:47 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/06 19:58:17 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include       <unistd.h>
# include       <stddef.h>
# include       <stdlib.h>
# include       <fcntl.h>
# include       <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char * s);
int		ft_strchr(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memset(void *s, int c, size_t n);


#endif
