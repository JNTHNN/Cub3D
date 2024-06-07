/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:45:35 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/07 18:28:18 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_free_array(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		free(arr);
		arr = NULL;
	}
	return (NULL);
}

void	ft_print_struct(t_map *map)
{
	printf("---------------------\n");
	printf("T_MAP %p\n", map);
	printf("FILE : [%s]\n", map->file);
	printf("FLOOR : [%i][%i][%i] [%x]\n", map->floor.s_rgb.r, map->floor.s_rgb.g, map->floor.s_rgb.b, map->floor.s_value);
	printf("CEILING : [%i][%i][%i]\n", map->ceiling.s_rgb.r, map->ceiling.s_rgb.g, map->ceiling.s_rgb.b);
	printf("---------------------\n");
	
}

void	ft_init_color(u_color *color)
{
	color->s_rgb.r = 255;
	color->s_rgb.g = 255;
	color->s_rgb.b = 255;
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

void	ft_get_floor_color(t_map *map)
{
	// recuperer la ligne commencant par l'id F dans le file pour avoir la couleur du sol
	// a voir si error si +de 2 lines F ?
	char	*line;
	char	**rgb;
	// int		i;
	
	while (map->fd)
	{
		line = get_next_line(map->fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, "F ", ft_strlen("F ")))
			break ;
		free(line);
	}
	if (line)
	{
		// si ligne -> split pour avoir les 3 valeurs rgb / error si plus ?
		rgb = ft_split(line, ',');
		for(int j = 0 ; rgb[j]; j++)
			printf("[%i] [%s]\n", j, rgb[j]);
		// i = 0;
		map->floor.s_rgb.r = ft_atoi(rgb[0] + 1);
		map->floor.s_rgb.g = ft_atoi(rgb[1]);
		map->floor.s_rgb.b = ft_atoi(rgb[2]);
		ft_free_array(rgb);
		
	}
	free(line);
	// printf("la line sol color = [%s]\n", line);
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
	ft_get_floor_color(&map);
	
	
	ft_print_struct(&map);
}

int	main(int argc, char **argv)
{
	ft_check_arg(argc, argv);
	// now la map est bonne
	ft_setup_map(MAP);
	
}

// pour la longueur -> calculer chaque ligne avec un buff qui sauve la +longue et change si >*