/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:44:05 by tbrouill          #+#    #+#             */
/*   Updated: 2019/12/20 21:53:48 by tbrouill         ###   ########.fr       */
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

typedef struct		s_list
{
	int				*fd;
	char			*tmp;
	struct s_list	*next;
}					t_list;
int					get_next_line(int fd, char **line);
void				ft_destroy(char **trash);
char				*ft_strjoin(char **s1, char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
#endif
