/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:44:20 by tbrouill          #+#    #+#             */
/*   Updated: 2020/01/04 17:34:13 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_is_eol(char *tmp)
{
	char	*ptr;

	ptr = tmp;
	if (!tmp)
		return (ERROR);
	tmp--;
	while (*(++tmp))
		if (*tmp == '\n')
			return ((int)(tmp - ptr));
	return (ERROR);
}

static int	ft_init(int fd, char ***line, char **buff)
{
	if (!*line || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
	{
		*line = NULL;
		return (ERROR);
	}
	if (!(*buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (ERROR);
	return (OK);
}

static int	ft_set_line(char **line, char **tmp, int ret)
{
	int		i;
	char	*old;

	if ((i = ft_is_eol(*tmp)) != ERROR)
	{
		*line = ft_substr(*tmp, 0, i);
		old = *tmp;
		*tmp = *tmp + i + 1;
		*tmp = ft_strdup(*tmp);
		free(old);
		return (NOT_EOF);
	}
	*line = ft_strdup(*tmp ? *tmp : "");
	ft_destroy(tmp);
	return (ret ? NOT_EOF : OK);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp = NULL;
	char		*buff;
	int			ret;
	int			a;

	if (ft_init(fd, &line, &buff) == ERROR)
		return (ERROR);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(&tmp, buff);
		if (ft_is_eol(tmp) != ERROR)
			break ;
	}
	ft_destroy(&buff);
	if ((a = ft_set_line(line, &tmp, ret)) == OK)
		tmp = 0;
	return (a);
}
