/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:55:59 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/10 20:49:05 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include       <unistd.h>
# include       <stddef.h>
# include       <stdlib.h>
# include       <fcntl.h>
# include       <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_check(char *s);
int		ft_find_target(const char *stock);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif