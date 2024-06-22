/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:45:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/22 11:52:44 by jgasparo         ###   ########.fr       */
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

void	ft_fill_map(t_map *map, char *file)
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

void	ft_setup_map(t_data *data, char *file)
{

	//struct init
	ft_fill_map(&data->map, file);
	// maintenant ouverture de la map
	data->map.fd = open(data->map.file, O_RDONLY);
	if (data->map.fd == -1)
		ft_errno(ERR_FD, data);
	// commencons par les textures / couleurs
	ft_get_info(data);
	
	
	ft_print_struct(&data->map);
}

void	ft_init_map(t_map *map)
{
	map->file = NULL;
	map->fd = 0;
	map->floor.s_value = 0;
	map->floor.s_rgb.b = 0;
	map->floor.s_rgb.g = 0;
	map->floor.s_rgb.r = 0;
	map->texture_north = NULL;
    map->texture_south = NULL;
    map->texture_west = NULL;
    map->texture_east = NULL;
	map->ceiling.s_value = 0;
	map->ceiling.s_rgb.b = 0;
	map->ceiling.s_rgb.g = 0;
	map->ceiling.s_rgb.r = 0;
}

t_data	*ft_init_data(void)
{
	t_data *data;
	
	data = (t_data *)malloc(sizeof(t_data));
    if (data == NULL)
		ft_errno(MEM, data);
	data->mlx = NULL;
    data->win = NULL;
    data->img.mlx_img = NULL;
    data->img.addr = NULL;
    data->img.bpp = 0;
    data->img.line_len = 0;
    data->img.endian = 0;
	ft_init_map(&data->map);
	return (data);
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_errno(MLX, data);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	if (data->win == NULL)
		ft_errno(WIN, data);
}

int	ft_mlx_settings(t_data *data)
{
	mlx_hook(data->win, ON_KEYDOWN, 0, ft_handle_key_events, data);
	mlx_hook(data->win, ON_MOUSEDOWN, 0, ft_handle_mouse_events, data);
	mlx_hook(data->win, ON_DESTROY, 0, ft_close_window, data);
	if (mlx_loop_hook(data->mlx, &ft_play, data))
		return (ft_close_window(data));
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data *data;
	
	data = ft_init_data();
	ft_check_arg(argc, argv);
	// now la map est bonne
	ft_setup_map(data, MAP);
	// ft_init_mlx(data);
	// ft_mlx_settings(data);
	return (EXIT_SUCCESS);
}

// pour la longueur -> calculer chaque ligne avec un buff qui sauve la +longue et change si >*