/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:44:20 by tbrouill          #+#    #+#             */
/*   Updated: 2019/12/04 22:42:44 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*substr_ft(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (start >= (unsigned int) strlen_ft((char *)s))
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

static int	ft_init(char ***line, int fd, char **tmp)
{
	if (!*line || fd == -1)
		return (ERROR);
	if (!*tmp)
	{
		if (!(*tmp = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (ERROR);
	}
	else
		strlcpy_ft(**line, *tmp, strlen_ft(*tmp));
	return (OK);
}

static int	output_to_line(char **tmp, int i, char ***line)
{
	if (*tmp[i])
	{
		while ((*tmp)[i] && (*tmp)[i] != '\n')
			i++;
		if (!i)
			**line = strdup_ft("");
		else
			**line = substr_ft(*tmp, 0, i);
		*tmp = *tmp + i + 1;
		return (NOT_EOF);
	}
	else
		**line = strdup_ft("");
	return (OK);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		buff[BUFFER_SIZE + 1];
	int			return_value;
	int			i;

	i = 0;
	if (ft_init(&line, fd, &tmp) == ERROR)
		return (ERROR);
	while ((return_value = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[return_value] = '\0';
		tmp = strjoin_ft(tmp, buff);
	}
	if (output_to_line(&tmp, i, &line) == NOT_EOF)
		return (NOT_EOF);
	return (OK);
}
