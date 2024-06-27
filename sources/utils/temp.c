/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:00:44 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/27 21:10:07 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_raw_map_to_mtx(t_data *data)
{
	int	i;
	int	j;

	data->mtx = (int **)malloc(data->map->y_size * sizeof(int *));
	if (!data->mtx)
		ft_errno(MEM, data);
	i = 0;
	while (data->map->map[i])
	{
		data->mtx[i] = (int *)malloc(data->map->x_size * sizeof(int));
		j = 0;
		while (data->map->map[i][j])
		{
			if (ft_isdigit(data->map->map[i][j]))
				data->mtx[i][j] = data->map->map[i][j] - '0';
			else
				data->mtx[i][j] = 9;
			j++;
		}
		i++;
	}
}	


void	ft_print_struct(t_map *map)
{
	printf("---------------------\n");
	printf("T_MAP %p\n", map);
	printf("FILE : [%s]\n", map->file);
	printf("FLOOR : [%i][%i][%i] [%x]\n", map->floor.s_rgb.r, map->floor.s_rgb.g, map->floor.s_rgb.b, map->floor.s_value);
	printf("CEILING : [%i][%i][%i] [%x]\n", map->ceiling.s_rgb.r, map->ceiling.s_rgb.g, map->ceiling.s_rgb.b, map->ceiling.s_value);
	printf("TEXTURE NORTH : [%s]\n", map->texture_north);
	printf("TEXTURE SOUTH : [%s]\n", map->texture_south);
	printf("TEXTURE WEST : [%s]\n", map->texture_west);
	printf("TEXTURE EAST : [%s]\n", map->texture_east);
	printf("PLAYER POSITION [%f][%f] ORIENTATION [%c] \n AND DIRECTION [%f][%f] AND POV [%f][%f]\n", map->player.position[0], map->player.position[1], map->player.orientation, map->player.direction[0], map->player.direction[1], map->player.pov[0], map->player.pov[1]);
	// printf("DEBUT DE LA MAP : [%p]\n", map->start);
	// printf("C'EST QUOI [%s]\n", "�");
	printf("LA MAP\n");
	int i = 0;
	while (map->map[i])
	{
		for (int j = 0; map->map[i][j]; j++)
			printf("%c", map->map[i][j]);
		i++;
		printf("\n");
	}
	printf("X_SIZE %i, Y_SIZE %i\n", map->x_size, map->y_size);
	
	printf("---------------------\n");
}
