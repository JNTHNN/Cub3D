/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:15:41 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/25 11:51:09 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_info_texture(t_map *map, t_info *info)
{
	// texture
	char	**texture;
	
	texture = ft_split(info->texture_north, ' ');
	map->texture_north = ft_strdup(texture[1]);
	ft_memset(map->texture_north + (ft_strlen(map->texture_north) - 1), 0, 1); // remove le \n
	ft_free_array(texture);
	texture = ft_split(info->texture_south, ' ');
	map->texture_south = ft_strdup(texture[1]);
	ft_memset(map->texture_south + (ft_strlen(map->texture_south) - 1), 0, 1); // remove le \n
	ft_free_array(texture);
	texture = ft_split(info->texture_west, ' ');
	map->texture_west = ft_strdup(texture[1]);
	ft_memset(map->texture_west + (ft_strlen(map->texture_west) - 1), 0, 1); // remove le \n
	ft_free_array(texture);
	texture = ft_split(info->texture_east, ' ');
	map->texture_east = ft_strdup(texture[1]);
	ft_memset(map->texture_east + (ft_strlen(map->texture_east) - 1), 0, 1); // remove le \n
	ft_free_array(texture);
}

void	ft_init_info(t_info *info)
{
	info->floor = NULL;
	info->ceiling = NULL;
	info->texture_north = NULL;
	info->texture_south = NULL;
	info->texture_west = NULL;
	info->texture_east = NULL;
}

void	ft_check_data(char *line, t_info *info, int *flag)
{

	if (!ft_strncmp(line, FLOOR, ft_strlen(FLOOR)))
	{
		if (!info->floor)
			info->floor = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
		(*flag)++;
	}
	else if (!ft_strncmp(line, CEILING, ft_strlen(CEILING)))
	{
		if (!info->ceiling)
			info->ceiling = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
		(*flag)++;
	}
	else if (!ft_strncmp(line, NORTH, ft_strlen(NORTH)))
	{
		if (!info->texture_north)
			info->texture_north = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
		(*flag)++;
	}
	else if (!ft_strncmp(line, SOUTH, ft_strlen(SOUTH)))
	{
		if (!info->texture_south)
			info->texture_south = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
		(*flag)++;
	}
	else if (!ft_strncmp(line, WEST, ft_strlen(WEST)))
	{
		if (!info->texture_west)
			info->texture_west = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
		(*flag)++;
	}
	else if (!ft_strncmp(line, EAST, ft_strlen(EAST)))
	{
		if (!info->texture_east)
			info->texture_east = ft_strdup(line);
		else
			ft_errno(DUP_INFO, NULL); // ajouter map a clean
		(*flag)++;
	}
}

void	ft_get_info(t_data *data)
{
	// recuperer la ligne commencant par l'id F dans le file pour avoir la couleur du sol
	// a voir si error si +de 2 lines F ?
	// pourquoi ne pas faire une struct ayant les données afin de savoir si elles sont toutes là ?
	char	*line;
	char	**rgb;
	t_info	info;
	int		flag = 0;
	
	// checker pour plusieurs lignes -> increment un flag et si >1 == error
	// si 1 data de info not init -> error
	ft_init_info(&info);
	while (data->map.fd)
	{
		// mettre un compteur pour le start de la map
		data->map.start++;
		line = get_next_line(data->map.fd);
		if (!line || !ft_strncmp(line, "1", 1))
			break ;
		ft_check_data(line, &info, &flag);
		free(line);
	}
	// checker si toutes les data de info sont init sinon error
	if (flag != 6)
		ft_errno(MISSING, data); // a voir si je detaille l'erreur data
	if (info.floor || info.ceiling)
	{
		// si ligne -> split pour avoir les 3 valeurs rgb / error si plus ?
		// printf("FLOOR [%s]\nCEILING [%s]\n", info.floor, info.ceiling);
		// printf("TEXTURE NORTH [%s] SOUTH [%s]\nWEST [%s] EAST [%s]\n", info.texture_north, info.texture_south, info.texture_west, info.texture_east);
		// setup les split pour chaque data
		// floor
		rgb = ft_split(info.floor, ',');
		if (!rgb || ft_arrlen(rgb) != 3)
			ft_errno(ERR_COLOR, data);
		for(int j = 0 ; rgb[j]; j++)
			printf("[%i] [%s]\n", j, rgb[j]);
		flag = 0;
		printf("res = %d\n", ft_atoi_color(rgb[0] + 1, &flag));
		data->map.floor.s_rgb.r = ft_atoi_color(rgb[0] + 1, &flag);
		if (flag)
			ft_errno(NOT_NB, data);
		data->map.floor.s_rgb.g = ft_atoi_color(rgb[1], &flag);
		if (flag)
			ft_errno(NOT_NB, data);
		data->map.floor.s_rgb.b = ft_atoi_color(rgb[2], &flag);
		if (flag)
			ft_errno(NOT_NB, data);
		// checker les datas -> error | soit refaire un atoi qui va introduire les datas suivant le flag (R|G|B) + nombre compris entre 0 et 255
		ft_free_array(rgb);
		// ceiling
		rgb = ft_split(info.ceiling, ',');
		if (!rgb || ft_arrlen(rgb) != 3)
			ft_errno(ERR_COLOR, data);
		for(int j = 0 ; rgb[j]; j++)
			printf("[%i] [%s]\n", j, rgb[j]);
		data->map.ceiling.s_rgb.r = ft_atoi_color(rgb[0] + 1, &flag);
		if (flag)
			ft_errno(NOT_NB, data);
		data->map.ceiling.s_rgb.g = ft_atoi_color(rgb[1], &flag);
		printf("ici flag = %d\n", flag);
		if (flag)
			ft_errno(NOT_NB, data);
		data->map.ceiling.s_rgb.b = ft_atoi_color(rgb[2], &flag);
		if (flag)
			ft_errno(NOT_NB, data);
		ft_free_array(rgb);
	}
	ft_get_info_texture(&data->map, &info);
	free(line);
	// close(data->map.fd);
	printf("la map start ligne %d\n", data->map.start);
	// printf("la line sol color = [%s]\n", line);
}

void	ft_get_map(t_data *data)
{
	char	*line;
	int		size = 0;
	int		i = 0;
	int		j = 0;

	while (data->map.fd)
	{
		line = get_next_line(data->map.fd);
		if (!line)
		{
			if (!line && !size)
				ft_errno(NO_MAP_CONTENT, data);
			break ;
		}
		// printf("la reprise [%s]\n", line);
		// break ;
		size++;
		free(line);
	}
	printf("la size est de %d\n", size);
	close(data->map.fd); // a voir si je re-init le fd a -1 car il va etre a 3 la
	data->map.map = (char **)malloc(sizeof(char *) * (size + 1));
	data->map.fd = open(data->map.file, O_RDONLY);
	while (data->map.fd)
	{
		line = get_next_line(data->map.fd);
		if (!line)
			break ;
		if (i++ < data->map.start - 1)
		{
			free(line);
			continue ;
		}
		// if (line[0] == '\n')
		// 	continue;
		data->map.map[j] = ft_strdup(line);
		if (data->map.map[j][(ft_strlen(data->map.map[j]) - 1)] == 10)
			ft_memset(data->map.map[j] + (ft_strlen(data->map.map[j]) - 1), 0, 1); // remove le \n
		j++;
	}
	data->map.map[j] = NULL;
	for (int z = 0; data->map.map[z]; z++)
		printf("la line [%d] [%s]\n", z, data->map.map[z]);
}

int	ft_wall(char c, int flag)
{
	if ((flag == TOP || flag == BOT) && c != 49 && c != 32)
		return (1);
	if ((flag == LEFT || flag == RIGHT) && c != 49)
		return (1);
	return (0);
}

int	ft_position_player(char c)
{
	return (c == N || c == S || c == W || c == E);
}

void	ft_check_player(t_data *data)
{
	int		x;
	int		y;
	char	**map;
	
	map = data->map.map;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_position_player(map[y][x]))
			{
				if (data->map.player != NONE)
					ft_errno(MANY_PLAYERS, data);
				else
					data->map.player = map[y][x];
			}
		}
	}
	if (data->map.player == NONE)
		ft_errno(NO_PLAYER, data);
	else
		printf("PLAYER IS %c\n", data->map.player);
}

void	ft_basic_check(t_data *data)
{
	int		y;
	int		x;
	char	**map;
	
	y = -1;
	map = data->map.map;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != WALL && map[y][x] != GROUND && map[y][x] != SPACE && map[y][x] != N && map[y][x] != S && map[y][x] != W && map[y][x] != E)
				ft_errno(WRONG_CHAR, data);
		}
	}
}

void	ft_info_size_map(t_data *data, char **map)
{
	int	y;

	// ligne la plus longue -> x_size
	y = -1;
	while (map[++y])
	{
		if (ft_strlen(map[y]) > (size_t)data->map.x_size)
			data->map.x_size = ft_strlen(map[y]);
	}
	printf("laligne ici est [%s]\n", map[y]);
	while (!map[y] || (!ft_strchr(map[y], WALL) && !ft_strchr(map[y], GROUND)))
		y--;
	data->map.y_size = y;
}

void	ft_check_map(t_data *data)
{
	// data->map.map
	int		x;
	int		y;
	char	**map;

	x = 0;
	ft_basic_check(data);
	map = data->map.map;
	ft_info_size_map(data, map);
	printf("le y_size [%d] et x_size [%d]\n", data->map.y_size, data->map.x_size);
	while (map[0][x] && map[0][++x])
	{
		// printf("le char est [%d][%d]\n", ft_wall(map[0][x], TOP), x);
		if (ft_wall(map[0][x], TOP))
				ft_errno(MAP_NOT_CLOSE, data);
	}
	x = 0;
	while (map[ft_arrlen(map) - 1][x] && map[ft_arrlen(map) - 1][++x])
	{
		// printf("le char est [%c][%d][%d]\n", map[ft_arrlen(map) - 1][x], ft_wall(map[ft_arrlen(map) - 1][x], BOT), x);
		if (ft_wall(map[ft_arrlen(map) - 1][x], BOT))
				ft_errno(MAP_NOT_CLOSE, data);
	}
	// probleme avec la derniere ligne avec le premier/dernier caractere -> DONE
	y = 0;
	while (map[y] && map[++y])
	{
		// printf("le char est [%s][%d][%d]\n", map[y], ft_wall(map[y][ft_strlen(map[y]) - 1], RIGHT), x);
		// printf("le char checker est [%c][%c]\n", map[y][0], map[y][ft_strlen(map[y]) - 1]);
		printf("checker res [%d][%d] line [%d] strlen [%zu]\n", ft_wall(map[y][0], LEFT), ft_wall(map[y][ft_strlen(map[y]) - 1], RIGHT), y, ft_strlen(map[y]));
		if (ft_wall(map[y][0], LEFT) || ft_wall(map[y][ft_strlen(map[y]) - 1], RIGHT))
			ft_errno(MAP_NOT_CLOSE, data);
	}
	//	les contours/murs sont checker -> il faut checker les murs dessus/dessous
	//	trouver la ligne la plus grande -> reverse parcourt la ligne dessus/dessous checker murs si pos actuelle est 0 ou PERSO(N,S,W,E)
	//	pour cela, je dois trouver la ligne la + grande -> reallouer toutes les lignes - grandes && remplacer les espaces par 2
	//	ligne 3 = 24 - ligne 4 = 30 - ligne 5 = 28 -> ligne [4][30] = 1 OK / ligne [4][29] = 0 ERROR
	//	faire pareil pour le dbut de ligne (flag LEFT RIGHT)
	//		1		2		0
	//	   101	   101     100

	// connaitre la + grande ligne map->x_size a faire en amont
}

