/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:45:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/20 15:30:46 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_struct(t_map *map)
{
	printf("---------------------\n");
	printf("T_MAP %p\n", map);
	printf("FILE : [%s]\n", map->file);
	printf("FLOOR : [%i][%i][%i] [%x]\n", map->floor.s_rgb.r, map->floor.s_rgb.g, map->floor.s_rgb.b, map->floor.s_value);
	printf("CEILING : [%i][%i][%i] [%x]\n", map->ceiling.s_rgb.r, map->ceiling.s_rgb.g, map->ceiling.s_rgb.b, map->ceiling.s_value);
	printf("TEXTURE NORTH : [%s]\n", map->texture_north);
	printf("TEXTURE SOUTH : [%s]\n", map->texture_south);
	printf("TEXTURE WEST : [%s]\n", map->texture_west);
	printf("TEXTURE EAST : [%s]\n", map->texture_east);
	printf("---------------------\n");
	
}

void	ft_init_color(u_color *color)
{
	color->s_rgb.r = 254;
	color->s_rgb.g = 255;
	color->s_rgb.b = 250;
}

void	ft_init_map(t_map *map, char *file)
{
	u_color	color;

	// map = (t_map *)malloc(sizeof(t_map)); // quand j'alloue, les valeurs de color deviennent folles ???
	// if (!map)
	// 	ft_errno(MEM, NULL);
	ft_init_color(&color);
	map->file = file;
	map->floor = color;
	map->ceiling = color;
	map->fd = -1;
}

void	ft_setup_map(char *file)
{
	t_map	map;

	//struct init
	ft_init_map(&map, file);
	// maintenant ouverture de la map
	map.fd = open(map.file, O_RDONLY);
	if (map.fd == -1)
		ft_errno(ERR_FD, &map);
	// commencons par les textures / couleurs
	ft_get_info(&map);
	
	
	ft_print_struct(&map);
}

int	main(int argc, char **argv)
{
	ft_check_arg(argc, argv);
	// now la map est bonne
	ft_setup_map(MAP);
	
}

// pour la longueur -> calculer chaque ligne avec un buff qui sauve la +longue et change si >*