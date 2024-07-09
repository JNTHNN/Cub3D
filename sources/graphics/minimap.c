/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:49:10 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/09 08:29:10 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calculate_cell_size(t_data *data, int *cell_size, int *offsets)
{
	cell_size[Y] = data->minimap->height / data->map->y_size;
	cell_size[X] = data->minimap->width / data->map->x_size;
	offsets[X] = (data->minimap->width
			- (cell_size[X] * data->map->x_size)) / 2;
	offsets[Y] = (data->minimap->height
			- (cell_size[Y] * data->map->y_size)) / 2;
}

static void	ft_define_color(t_data *data, int i, int j, int *color)
{
	if (data->mtx[i][j] >= 1)
		*color = 0x000000;
	else if (i == (int)data->map->player.position[Y]
		&& j == (int)data->map->player.position[X])
		*color = 0xFF0000;
	else if (data->mtx[i][j] == 0)
		*color = 0xA0A0A0;
}

static void	ft_draw_minimap(t_data *data, int *cell_size, int *offsets)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	color;

	i = -1;
	while (++i < data->map->y_size)
	{
		j = -1;
		while (++j < data->map->x_size)
		{
			ft_define_color(data, i, j, &color);
			y = 0;
			while (++y < cell_size[Y])
			{
				x = 0;
				while (++x < cell_size[X])
					ft_img_pix_put(data->minimap->img,
						offsets[X] + j * cell_size[X] + x,
						offsets[Y] + i * cell_size[Y] + y, color);
			}
		}
	}
}

void	ft_create_minimap(t_data *data)
{
	t_img	*img;
	int		cell_size[2];
	int		offsets[2];

	img = data->minimap->img;
	data->minimap->width = WIN_WIDTH / 4;
	data->minimap->height = WIN_HEIGHT / 5;
	img->mlx_img = mlx_new_image(data->mlx, data->minimap->width,
			data->minimap->height);
	if (img->mlx_img == NULL)
		ft_error(IMG, STR_ERR_IMG, data);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
	ft_calculate_cell_size(data, cell_size, offsets);
	ft_draw_minimap(data, cell_size, offsets);
	mlx_put_image_to_window(data->mlx, data->win, img->mlx_img, 10,
		WIN_HEIGHT - data->minimap->height - 10);
	mlx_destroy_image(data->mlx, img->mlx_img);
	img->mlx_img = NULL;
}
