/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:09:26 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/08 17:57:33 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		ft_get_point_of_impact(&rc, player, data);
		ft_define_corrected_perp_dist(&rc, player);
		ft_define_drawline_values(&rc);
		ft_set_wall_textures(&rc, data);
		ft_draw_walls(&rc, data);
		rc.x++;
	}
}
