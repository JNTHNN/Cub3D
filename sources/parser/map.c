/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:12:46 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 00:14:49 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_map(t_data *data)
{
	char	*line;
	int		size = 0;
	int		i = 0;
	int		j = 0;

	while (data->map->fd)
	{
		line = get_next_line(data->map->fd);
		if (!line)
		{
			if (!line && !size)
				ft_errno(NO_MAP_CONTENT, data);
			break ;
		}
		// printf("la reprise [%s]\n", line);
		// break ;
		size++;
		free(line);
	}
	printf("la size est de %d\n", size);
	close(data->map->fd); // a voir si je re-init le fd a -1 car il va etre a 3 la
	data->map->map = (char **)malloc(sizeof(char *) * (size + 1));
	data->map->fd = open(data->map->file, O_RDONLY);
	while (data->map->fd)
	{
		line = get_next_line(data->map->fd);
		if (!line)
			break ;
		if (i++ < data->map->start - 1)
		{
			free(line);
			continue ;
		}
		// if (line[0] == '\n'->
		// 	continue;
		data->map->map[j] = ft_strdup(line);
		if (data->map->map[j][(ft_strlen(data->map->map[j]) - 1)] == 10)
			ft_memset(data->map->map[j] + (ft_strlen(data->map->map[j]) - 1), 0, 1); // remove le \n
		j++;
	}
	data->map->map[j] = NULL;
	for (int z = 0; data->map->map[z]; z++)
		printf("la line [%d] [%s]\n", z, data->map->map[z]);
}