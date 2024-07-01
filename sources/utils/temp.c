/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:00:44 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/01 16:28:49 by gdelvign         ###   ########.fr       */
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
				data->mtx[i][j] = 0;
			j++;
		}
		i++;
	}
}	


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
	printf("PLAYER POSITION [%f][%f] ORIENTATION [%c]\n", map->player.position[0], map->player.position[1], map->player.orientation);
	printf("MAP START : [%d] END : [%d] TOTAL : [%d]\n", data->file->start, data->file->end, data->file->end - data->file->start);
	printf("SIZE MAX Y [%d] MAX X [%d]\n", data->map->y_size, data->map->x_size);
	// printf("DEBUT DE LA MAP : [%p]\n", map->start);
	// printf("C'EST QUOI [%s]\n", "�");
	printf("---------------------\n");
}


// SAVE POUR LES PRINTF HIHI
// void	ft_square_map(t_data *data)
// {
// 	int		x_max;
// 	int		y_max;
// 	int		x;
// 	int		y;
// 	char	**square_map;
	
// 	y = 0;
// 	x_max = data->map->x_size;
// 	y_max = data->map->y_size;
// 	data->map->square_map = (char **)malloc(sizeof(char *) * y_max + 1); // a proteger
// 	square_map = data->map->square_map;
// 	while (y < y_max)
// 	{
// 		square_map[y] = (char *)malloc(sizeof(char) * x_max + 1); // a proteger
// 		ft_memset(square_map[y], EMPTY, x_max);
// 		ft_memset(square_map[y] + (x_max), 0, 1);
// 		printf("SQUARE [%d]\t[%s]\n",y, square_map[y]);
// 		y++;
// 	}
// 	y = 0;
// 	while (y < y_max && data->map->map[y])
// 	{
// 		x = 0;
// 		while (x < x_max && data->map->map[y][x])
// 		{
// 			if (data->map->map[y][x] != '\0' && data->map->map[y][x] != SPACE)
// 				square_map[y][x] = data->map->map[y][x];
// 			x++;
// 		}
// 		printf("SQUARE2[%d]\t[%s]\n", y, square_map[y]);
// 		y++;
// 	}
// 	square_map[y] = NULL;
// 	for(int u=0 ; square_map[u]; u++)
// 		printf("OK [%s]\n",square_map[u]);
// }