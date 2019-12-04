/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrouill <tbrouill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:05:10 by tbrouill          #+#    #+#             */
/*   Updated: 2019/12/04 23:08:13 by tbrouill         ###   ########.fr       */
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
	i_max = ft_strlen((char *) s1) + 1;
	if (!(s2 = malloc(sizeof(char) * i_max)))
		return (NULL);
	while (++i < i_max)
		s2[i] = s1[i];
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*dest;

	i = -1;
	s1_len = ft_strlen((char *) s1) - 1;
	s2_len = ft_strlen((char *) s2) - 1;
	if (s1 && s2)
	{
		if (!(dest = malloc(sizeof(char) * (s1_len + s2_len + 3))))
			return (NULL);
		while (++i <= (s1_len + s2_len + 1))
			dest[i] = i <= s1_len ? s1[i] : s2[i - (s1_len + 1)];
		dest[i] = '\0';
	}
	else if (s1)
		dest = ft_strdup(s1);
	else if (s2)
		dest = ft_strdup(s2);
	else
		return ("\0");
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int i;
	unsigned int length;

	length = 0;
	i = 0;
	while (i < size - 1 && src[i] != '\0' && size != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	while (*src != '\0')
	{
		length++;
		src++;
	}
	return (length);
}
