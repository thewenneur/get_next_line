/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:44:20 by tbrouill          #+#    #+#             */
/*   Updated: 2019/12/11 22:31:18 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_is_eol(char *tmp, int check_line)
{
	char	*ptr;

	ptr = tmp;
	if (!tmp)
		return (-1);
	tmp--;
	while (*(++tmp))
	{
		if (check_line && *tmp == '\n')
			return (int)((tmp - ptr));
	}
	return (!check_line ? (int)(tmp - ptr) : -1);
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

static int	ft_set_line(char **line, char **tmp)
{
	if (ft_is_eol(*tmp, 1) != -1)
	{
		*line = ft_substr(*tmp, 0, ft_is_eol(*tmp, 1));
		*tmp = *tmp + ft_is_eol(*tmp, 1) + 1;
		return (NOT_EOF);
	}
	*line = ft_strdup(*tmp ? *tmp : "");
	*tmp = *tmp + ft_is_eol(*tmp, 0) + 1;
	return (OK);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*buff;
	int			ret;

	if (ft_init(fd, &line, &buff) == ERROR)
		return (ERROR);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (ft_is_eol(tmp, 1) != -1 && ret < BUFFER_SIZE)
			break ;
	}
	ft_destroy(&buff);
	if (ret == -1)
	{
		line = NULL;
		return (ERROR);
	}
	return (ft_set_line(line, &tmp) == NOT_EOF ? NOT_EOF : OK);
}
