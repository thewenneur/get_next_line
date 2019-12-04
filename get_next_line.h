/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:44:05 by tbrouill          #+#    #+#             */
/*   Updated: 2019/12/04 22:39:25 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
# define GET_NEXT_LINE_GET_NEXT_LINE_H
# define ERROR -1
# define OK 0
# define NOT_EOF 1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
char		*strjoin_ft(char const *s1, char const *s2);
char		*strdup_ft(const char *s1);
size_t		strlen_ft(const char *str);
size_t		strlcpy_ft(char *dst, const char *src, unsigned int size);
static char	*substr_ft(char const *s, unsigned int start, size_t len);
#endif
