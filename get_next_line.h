/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roumbare <roumbare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:39:47 by roumbare          #+#    #+#             */
/*   Updated: 2022/06/03 17:32:59 by roumbare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include       <unistd.h>
# include       <stddef.h>
# include       <stdio.h>

char *get_next_line(int fd);

#endif
