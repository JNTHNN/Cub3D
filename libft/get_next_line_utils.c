/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:17:13 by gdelvign          #+#    #+#             */
/*   Updated: 2024/01/16 10:23:11 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_find_endline(char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_strjoin_gnl(char *bucket, char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*str;

	size = ft_strlen(bucket) + ft_strlen(buffer);
	if (!size)
		return (free_elem(&bucket, NULL));
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (free_elem(&bucket, NULL));
	i = 0;
	j = 0;
	while (bucket[i] && j < size)
		str[j++] = bucket[i++];
	i = 0;
	while (buffer[i] && j < size)
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(bucket);
	return (str);
}

char	*free_elem(char **elem1, char **elem2)
{
	if (elem1 && *elem1)
	{
		free(*elem1);
		*elem1 = NULL;
	}
	if (elem2 && *elem2)
	{
		free(*elem2);
		*elem2 = NULL;
	}
	return (NULL);
}
