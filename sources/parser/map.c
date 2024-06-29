/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:12:46 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/29 20:07:53 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
**	Create square map with (2) in place of empty cells
*/
static char	**ft_fill_square_map(t_data *data)
{
	int		y;
	int		y_max;
	int		x_max;
	char	**square_map;

	y = 0;
	y_max = data->map->y_size;
	x_max = data->map->x_size;
	square_map = (char **)malloc(sizeof(char *) * y_max + 1);
	if (!square_map)
		ft_errno(MEM, data);
	while (y < y_max)
	{
		square_map[y] = (char *)malloc(sizeof(char) * x_max + 1);
		if (!square_map[y])
			ft_errno(MEM, data); // voir si je rajoute ft_free_array(square_map)
		ft_memset(square_map[y], EMPTY, x_max);
		ft_memset(square_map[y] + (x_max), 0, 1);
		y++;
	}
	return (square_map);
}	

/*
**	Duplicates the original map to make one,
**	that is square and empty cells are replaced by (2)
*/
void	ft_square_map(t_data *data)
{
	int		x_max;
	int		y_max;
	int		x;
	int		y;
	char	**square_map; // surement a enlever a cause de la norme
	
	y = 0;
	x_max = data->map->x_size;
	y_max = data->map->y_size;
	data->map->square_map = ft_fill_square_map(data);
	square_map = data->map->square_map;
	y = 0;
	while (y < y_max && data->map->map[y])
	{
		x = 0;
		while (x < x_max && data->map->map[y][x])
		{
			if (data->map->map[y][x] != '\0' && data->map->map[y][x] != SPACE)
				square_map[y][x] = data->map->map[y][x];
			x++;
		}
		y++;
	}
	square_map[y] = NULL;
}

/*
**	Calculates max length / width
*/
void	ft_get_y_x_max(t_data *data)
{
	int	y;
	int	temp;

	y = 0;
	temp = 0;
	while (data->map->map[y])
	{
		if ((int)ft_strlen(data->map->map[y]) > temp)
			temp = ft_strlen(data->map->map[y]);
		y++;
	}
	data->map->y_size = y;
	data->map->x_size = temp;
}

/*
**	Check the map with these steps:
**	- Check that there are no other inaccurate characters.
**	- Check map walls
**	- Transform the map into a square
**	- Check that ground squares (0) are not surrounded by empty squares (2)
**	- Check the same for the player square
*/
void	ft_check_map(t_data *data)
{
	ft_basic_check(data);
	ft_check_walls(data);
	ft_square_map(data);
	ft_backtrack_wall(data);
	ft_backtrack_player(data);
}
