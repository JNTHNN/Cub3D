/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:36:43 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/03 16:43:59 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_set_tex_img(t_data *data, t_xpm *texture, char *filename)
{
	int	fd;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_errno(OPEN, data);
	close(fd);
	texture->img = mlx_xpm_file_to_image(&data->mlx, filename,
		&texture->width, &texture->height);
	if (!texture->img)
		ft_errno(IMG, data);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
		&texture->line_len, &texture->endian);
    if (!texture->addr)
        ft_errno(ADD, data);
}

void	ft_set_textures(t_data *data)
{
	ft_set_tex_img(data, data->textures->tex_north, data->map->texture_north);
	ft_set_tex_img(data, data->textures->tex_south, data->map->texture_south);
	ft_set_tex_img(data, data->textures->tex_east, data->map->texture_east);
	ft_set_tex_img(data, data->textures->tex_west, data->map->texture_west);
}
