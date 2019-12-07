/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:44:20 by tbrouill          #+#    #+#             */
/*   Updated: 2019/12/07 15:18:49 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (start >= (unsigned int)ft_strlen((char *)s))
		len = 0;
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_init(char ***line, int fd, char **tmp, char **buff)
{
	if (!*line || fd == -1 || read(fd, NULL, 0) < 0)
	{
		*line = NULL;
		return (ERROR);
	}
	if (!(*buff = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (ERROR);
	if (!*tmp)
	{
		if (!(*tmp = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (ERROR);
		else
			return (OK);
	}
	if (!(**line = malloc(sizeof(char) * ft_strlen(*tmp))))
		return (ERROR);
	ft_strlcpy(**line, *tmp, ft_strlen(*tmp));
	return (OK);
}

static int	output_to_line(char **tmp, int i, char ***line)
{
	int	t;

	t = 0;
	if (*tmp[i])
	{
		while ((*tmp)[i] && (*tmp)[i] != '\n')
			i++;
		if ((*tmp)[i] == '\n')
			t = 1;
		if (!i)
			**line = ft_strdup("");
		else
			**line = ft_substr(*tmp, 0, i);
		*tmp = *tmp + i + 1;
		return (!(**tmp) && !t ? OK : NOT_EOF);
	}
	else
		**line = ft_strdup("");
	return (OK);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*buff;
	int			return_value;
	int			i;

	i = 0;
	if (ft_init(&line, fd, &tmp, &buff) == ERROR)
		return (ERROR);
	while ((return_value = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[return_value] = '\0';
		tmp = ft_strjoin(tmp, buff);
	}
	free(buff);
	buff = NULL;
	if (return_value == ERROR)
	{
		line = NULL;
		return (ERROR);
	}
	if (output_to_line(&tmp, i, &line) == NOT_EOF)
		return (NOT_EOF);
	return (OK);
}
