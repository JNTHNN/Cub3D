/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:09:26 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/05 17:02:23 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Sets the entire image to black by iterating over each pixel */
void	ft_set_black(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			ft_img_pix_put(data->img, x, y, 0);
			y++;
		}
		x++;
	}
}

void	ft_img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_draw_background(t_img *img, t_map *map)
{
	int	i;
	int	j;

	i = WIN_HEIGHT - (WIN_HEIGHT / 2);
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			ft_img_pix_put(img, j++, i, map->floor.s_value);
		i++;
	}
	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		j = 0;
		while (j < WIN_WIDTH)
			ft_img_pix_put(img, j++, i, map->ceiling.s_value);
		i++;
	}
}

void	ft_raycasting(t_data *data)
{
	t_player	player;
	t_ray_c		rc;

	rc = (t_ray_c){0};
	player = data->map->player;
	rc.x = 0;
	while (rc.x < WIN_WIDTH)
	{
		ft_set_rc_vars(&rc, player);
		ft_get_point_of_impact(&rc, data);
		if (rc.side == 0)
			rc.perp_wall_dist = (rc.cell[X]
					- player.position[X] + (1 - rc.step[X]) / 2) / rc.raydir_x;
		else
			rc.perp_wall_dist = (rc.cell[Y]
					- player.position[Y] + (1 - rc.step[Y]) / 2) / rc.raydir_y;
		if (rc.perp_wall_dist == 0)
			rc.perp_wall_dist = 0.01;
		rc.line_height = (int)(WIN_HEIGHT) / rc.perp_wall_dist;
		rc.drawline[START] = -rc.line_height / 2 + WIN_HEIGHT / 2;
		if (rc.drawline[START] < 0)
			rc.drawline[START] = 0;
		rc.drawline[END] = rc.line_height / 2 + WIN_HEIGHT / 2;
		if (rc.drawline[END] >= WIN_HEIGHT)
			rc.drawline[END] = WIN_HEIGHT - 1;
		if (rc.side == 0)
		{
			if (rc.raydir_x < 0)
				rc.texture = data->textures->tex_west;
			else
				rc.texture = data->textures->tex_east;
		}
		else
		{
			if (rc.raydir_y > 0)
				rc.texture = data->textures->tex_south;
			else
				rc.texture = data->textures->tex_north;
		}
		if (rc.side == 0)
		{
			rc.impact = player.position[Y] + rc.perp_wall_dist * rc.raydir_y;
			rc.tex_x = (int)(rc.impact * (double)rc.texture->width);
		}
		else
		{
			rc.impact = player.position[X] + rc.perp_wall_dist * rc.raydir_x;
			rc.tex_x = (int)(rc.impact * (double)rc.texture->width);
		}
		rc.tex_x = rc.tex_x % rc.texture->width;
		rc.tex_step = 1.0 * rc.texture->height / rc.line_height;
		rc.tex_pos = (rc.drawline[START]
				- WIN_HEIGHT / 2 + rc.line_height / 2) * rc.tex_step;

		int	i = rc.drawline[START];
		while (i < rc.drawline[END])
		{
			int tex_y = (int)rc.tex_pos & (rc.texture->height - 1);
			rc.tex_pos += rc.tex_step;
			rc.tex_color = *(int *)(rc.texture->addr
					+ (tex_y * rc.texture->line_len
						+ rc.tex_x * (rc.texture->bpp / 8)));
			ft_img_pix_put(data->img, rc.x, i, rc.tex_color);
			i++;
		}
		rc.x++;
	}
}

