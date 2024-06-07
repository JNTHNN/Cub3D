/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:13:42 by gdelvign          #+#    #+#             */
/*   Updated: 2024/01/16 10:23:11 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*clean_bucket(char *bucket)
{
	size_t	i;
	size_t	j;
	char	*new_bucket;

	i = 0;
	while (bucket[i] && bucket[i] != '\n')
		i++;
	if (bucket[i] == '\n')
		i++;
	j = 0;
	if (!bucket[i])
		return (free_elem(&bucket, NULL));
	while (bucket[i + j])
		j++;
	new_bucket = malloc(sizeof(char) * (j + 1));
	if (!new_bucket)
		return (free_elem(&bucket, NULL));
	j = 0;
	while (bucket[i + ++j - 1])
		new_bucket[j - 1] = bucket[i + j - 1];
	new_bucket[j - 1] = '\0';
	free(bucket);
	return (new_bucket);
}

static char	*get_current_line(char *bucket)
{
	int		i;
	int		j;
	char	*line;

	if (!bucket)
		return (NULL);
	i = 0;
	while (bucket[i] != '\n' && bucket[i])
		i++;
	if (bucket[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = bucket[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*read_and_save(int fd, char *bucket)
{
	char	*buffer;
	size_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_elem(&bucket, NULL));
	if (!bucket)
	{
		bucket = malloc(sizeof(char));
		if (!bucket)
			return (free_elem(&bucket, &buffer));
		bucket[0] = '\0';
	}
	bytes_read = 1;
	while (!ft_find_endline(bucket) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((int)bytes_read == -1)
			return (free_elem(&bucket, &buffer));
		buffer[bytes_read] = '\0';
		bucket = ft_strjoin_gnl(bucket, buffer);
		if (!bucket)
			return (free_elem(&buffer, NULL));
	}
	return (free(buffer), buffer = NULL, bucket);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*bucket;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &bucket, 0) < 0)
		return (free_elem(&bucket, NULL));
	bucket = read_and_save(fd, bucket);
	line = get_current_line(bucket);
	if (!line)
		return (free_elem(&bucket, NULL));
	bucket = clean_bucket(bucket);
	return (line);
}
