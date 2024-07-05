/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:07:13 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/05 21:19:48 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_wall_textures(t_ray_c *rc, t_data *data)
{
	if (rc->side == 1)
	{
		if (rc->raydir_y < 0)
			rc->texture = data->textures->tex_north;
		else
			rc->texture = data->textures->tex_south;
	}
	else
	{
		if (rc->raydir_x < 0)
			rc->texture = data->textures->tex_west;
		else
			rc->texture = data->textures->tex_east;
	}
	if (rc->side == 0)
		rc->tex_x = (int)(rc->impact * (double)rc->texture->width);
	else
		rc->tex_x = (int)(rc->impact * (double)rc->texture->width);
	rc->tex_x = rc->tex_x % rc->texture->width;
	rc->tex_step = 1.0 * rc->texture->height / rc->line_height;
	rc->tex_pos = (rc->drawline[START] - WIN_HEIGHT / 2
			+ rc->line_height / 2) * rc->tex_step;
}

void	ft_draw_walls(t_ray_c *rc, t_data *data)
{
	int	i;
	int	tex_y;

	i = rc->drawline[START];
	while (i < rc->drawline[END])
	{
		tex_y = (int)rc->tex_pos & (rc->texture->height - 1);
		rc->tex_pos += rc->tex_step;
		rc->tex_color = *(int *)(rc->texture->addr
				+ (tex_y * rc->texture->line_len
					+ rc->tex_x * (rc->texture->bpp / 8)));
		ft_img_pix_put(data->img, rc->x, i, rc->tex_color);
		i++;
	}
}
