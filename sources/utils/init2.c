/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:02:56 by gdelvign          #+#    #+#             */
/*   Updated: 2024/07/05 12:54:46 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_xpm	*ft_init_tex_data(t_data *data)
{
	t_xpm	*xpm;

	xpm = (t_xpm *)malloc(sizeof(t_xpm));
	if (!xpm)
		ft_error(MEM, STR_MEM, data);
	xpm = ft_memset(xpm, 0, sizeof(t_xpm));
	return (xpm);
}

t_textures	*ft_init_textures(t_data *data)
{
	t_textures	*textures;

	textures = (t_textures *)malloc(sizeof(t_textures));
	if (!textures)
		ft_error(MEM, STR_MEM, data);
	textures->tex_north = ft_init_tex_data(data);
	textures->tex_south = ft_init_tex_data(data);
	textures->tex_east = ft_init_tex_data(data);
	textures->tex_west = ft_init_tex_data(data);
	textures->sprite = ft_init_tex_data(data);
	return (textures);
}

t_orientation_att	ft_init_o_attributes(void)
{
	t_orientation_att	attributes;

	attributes.north.dir[X] = DIR_0;
	attributes.north.dir[Y] = DIR_M1;
	attributes.north.fov[X] = FOV_66;
	attributes.north.fov[Y] = FOV_0;
	attributes.south.dir[X] = DIR_0;
	attributes.south.dir[Y] = DIR_1;
	attributes.south.fov[X] = FOV_M66;
	attributes.south.fov[Y] = FOV_0;
	attributes.east.dir[X] = DIR_1;
	attributes.east.dir[Y] = DIR_0;
	attributes.east.fov[X] = FOV_0;
	attributes.east.fov[Y] = FOV_66;
	attributes.west.dir[X] = DIR_M1;
	attributes.west.dir[Y] = DIR_0;
	attributes.west.fov[X] = FOV_0;
	attributes.west.fov[Y] = FOV_M66;
	return (attributes);
}
