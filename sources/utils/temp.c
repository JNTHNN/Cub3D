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

void	ft_get_map_real_width( t_data *data)
{
	int	i;
	int	j;

	data->row_widths = (int *)malloc(data->map->y_size * sizeof(int));
	i = 0;
	while (i < data->map->y_size)
	{
		data->row_widths[i] = 0;
		j = 0;
		while (j < data->map->x_size)
		{
			if (data->mtx[i][j] != 2)
				data->row_widths[i]++;
			j++;
		}
		fprintf(data->fd, "ROW_WIDTH [%i]= %i\n", i, data->row_widths[i]);
		fflush(data->fd);
		i++;
	}
}

void ft_raw_map_to_mtx(t_data *data)
{
	int	i;
	int	j;

	fprintf(data->fd, "----- THE MATRIX ----\n");
	fflush(data->fd);
	data->mtx = (int **)malloc(data->map->y_size * sizeof(int *));
	if (!data->mtx)
		ft_errno(MEM, data);
	i = 0;
	while (i < data->map->y_size)
	{
		data->mtx[i] = (int *)malloc(data->map->x_size * sizeof(int));
		j = 0;
		while (j < data->map->x_size)
		{
			if (ft_isdigit(data->map->square_map[i][j]))
				data->mtx[i][j] = data->map->square_map[i][j] - '0';
			else
				data->mtx[i][j] = 0;
			fprintf(data->fd, "%i", data->mtx[i][j]);
			fflush(data->fd);
			j++;
		}
		fprintf(data->fd, "\n");
		fflush(data->fd);
		i++;
	}
	ft_get_map_real_width(data);
}



void	ft_print_struct(t_data *data)
{
	t_map *map;
	

	data->fd = fopen("cub3d.log", "w+");
	if (data->fd == NULL)
		printf("Erreur d'ouverture du fichier: %s\n", strerror(errno));
	map = data->map;
	for(int i = 0; map->map[i]; i++)
	{
		fprintf(data->fd, "[%d]\t[%s]\n", i, map->map[i]);
		fflush(data->fd);
	}
	fprintf(data->fd, "---------------------\n");
	fflush(data->fd);
	fprintf(data->fd, "T_MAP %p\n", map);
	fflush(data->fd);
	fprintf(data->fd, "FILE : [%s]\n", map->file);
	fflush(data->fd);
	fprintf(data->fd, "FLOOR : [%i][%i][%i] [%x]\n", map->floor.s_rgb.r, map->floor.s_rgb.g, map->floor.s_rgb.b, map->floor.s_value);
	fflush(data->fd);
	fprintf(data->fd, "CEILING : [%i][%i][%i] [%x]\n", map->ceiling.s_rgb.r, map->ceiling.s_rgb.g, map->ceiling.s_rgb.b, map->ceiling.s_value);
	fflush(data->fd);
	fprintf(data->fd, "TEXTURE NORTH : [%s]\n", map->texture_north);
	fflush(data->fd);
	fprintf(data->fd, "TEXTURE SOUTH : [%s]\n", map->texture_south);
	fflush(data->fd);
	fprintf(data->fd, "TEXTURE WEST : [%s]\n", map->texture_west);
	fflush(data->fd);
	fprintf(data->fd, "TEXTURE EAST : [%s]\n", map->texture_east);
	fflush(data->fd);
	fprintf(data->fd, "PLAYER POSITION [%f][%f] ORIENTATION [%c]\n", map->player.position[0], map->player.position[1], map->player.orientation);
	fflush(data->fd);
	fprintf(data->fd, "MAP START : [%d] END : [%d] TOTAL : [%d]\n", data->file->start, data->file->end, data->file->end - data->file->start);
	fflush(data->fd);
	fprintf(data->fd, "SIZE MAX Y [%d] MAX X [%d]\n", data->map->y_size, data->map->x_size);
	fflush(data->fd);
	// printf("DEBUT DE LA MAP : [%p]\n", map->start);
	// printf("C'EST QUOI [%s]\n", "�");
	fprintf(data->fd, "---------------------\n");
	fflush(data->fd);
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