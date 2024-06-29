/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:00:44 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/29 01:24:11 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_print_struct(t_data *data)
{
	t_map *map;

	map = data->map;
	for(int i = 0; map->map[i]; i++)
		printf("[%d]\t[%s]\n", i, map->map[i]);
	printf("---------------------\n");
	printf("T_MAP %p\n", map);
	printf("FILE : [%s]\n", map->file);
	printf("FLOOR : [%i][%i][%i] [%x]\n", map->floor.s_rgb.r, map->floor.s_rgb.g, map->floor.s_rgb.b, map->floor.s_value);
	printf("CEILING : [%i][%i][%i] [%x]\n", map->ceiling.s_rgb.r, map->ceiling.s_rgb.g, map->ceiling.s_rgb.b, map->ceiling.s_value);
	printf("TEXTURE NORTH : [%s]\n", map->texture_north);
	printf("TEXTURE SOUTH : [%s]\n", map->texture_south);
	printf("TEXTURE WEST : [%s]\n", map->texture_west);
	printf("TEXTURE EAST : [%s]\n", map->texture_east);
	printf("PLAYER POSITION [%d][%d] ORIENTATION [%c]\n", map->player.position[0], map->player.position[1], map->player.orientation);
	printf("MAP START : [%d] END : [%d] TOTAL : [%d]\n", data->file->start, data->file->end, data->file->end - data->file->start);
	printf("SIZE MAX Y [%d] MAX X [%d]\n", data->map->y_size, data->map->x_size);
	// printf("DEBUT DE LA MAP : [%p]\n", map->start);
	// printf("C'EST QUOI [%s]\n", "�");
	printf("---------------------\n");
}
