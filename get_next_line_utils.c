/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:05:10 by tbrouill          #+#    #+#             */
/*   Updated: 2019/12/20 21:53:48 by tbrouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		i_max;

	i = -1;
	i_max = ft_strlen((char *)s1) + 1;
	if (!(s2 = malloc(sizeof(char) * i_max)))
		return (NULL);
	while (++i < i_max)
		s2[i] = s1[i];
	return (s2);
}

void	ft_destroy(char **trash)
{
	free(*trash);
	*trash = NULL;
}

char	*ft_strjoin(char **s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*dest;

	i = -1;
	s1_len = ft_strlen((char *)(*s1)) - 1;
	s2_len = ft_strlen((char *)s2) - 1;
	if (*s1 && s2)
	{
		if (!(dest = malloc(sizeof(char) * (s1_len + s2_len + 3))))
			return (NULL);
		while (++i <= (s1_len + s2_len + 1))
			dest[i] = i <= s1_len ? (*s1)[i] : s2[i - (s1_len + 1)];
		dest[i] = '\0';
		free(*s1);
	}
	else if (*s1)
	{
		dest = ft_strdup(*s1);
		free(*s1);
	}
	else
		dest = ft_strdup(s2);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
