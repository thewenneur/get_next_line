/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:44:20 by tbrouill          #+#    #+#             */
/*   Updated: 2019/12/19 18:29:24 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_is_eol(char *tmp, int check_line)
{
	char	*ptr;

	ptr = tmp;
	if (!tmp)
		return (ERROR);
	tmp--;
	while (*(++tmp))
		if (check_line && *tmp == '\n')
			return (int)((tmp - ptr));
	return (!check_line ? (int)(tmp - ptr) : ERROR);
}

static int	ft_init(int fd, char ***line, char **tmp, char **buff)
{
	if (!*line || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
	{
		*line = NULL;
		return (ERROR);
	}
	if (!(*buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (ERROR);
	if (!*tmp)
		if (!(*tmp = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (ERROR);
	return (OK);
}

static int	ft_set_line(char **line, char **tmp, int ret)
{
	int	i;

	if ((i = ft_is_eol(*tmp, 1)) != ERROR)
	{
		*line = ft_substr(*tmp, 0, i);
		*tmp = *tmp + i + 1;
		return (NOT_EOF);
	}
	*line = ft_strdup(*tmp ? *tmp : "");
	return (ret ? NOT_EOF : OK);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*buff;
	int			ret;

	if (ft_init(fd, &line, &tmp, &buff) == ERROR)
		return (ERROR);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (ft_is_eol(tmp, 1) != ERROR)
			break ;
	}
	ft_destroy(&buff);
	if (ret == -1)
	{
		line = NULL;
		return (ERROR);
	}
	if (ft_set_line(line, &tmp, ret) == OK)
	{
		ret = 42;
		tmp = 0;
		//free(tmp);
	}
	return (ret == 42 ? OK : NOT_EOF);
}
