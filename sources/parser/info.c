/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:15:41 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/26 12:24:06 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_data(char **type, char *line, int *flag, t_data *data)
{
	if (!*type)
		*type = ft_strdup(line);
	else
		ft_errno(DUP_INFO, data);
	(*flag)++;
}

void	ft_check_data(char *line, t_data *data, int *flag)
{
	t_info	*info;

	info = data->info;
	if (!ft_strncmp(line, FLOOR, ft_strlen(FLOOR)))
		ft_fill_data(&(info->floor), line, flag, data);
	else if (!ft_strncmp(line, CEILING, ft_strlen(CEILING)))
		ft_fill_data(&(info->ceiling), line, flag, data);
	else if (!ft_strncmp(line, NORTH, ft_strlen(NORTH)))
		ft_fill_data(&(info->texture_north), line, flag, data);
	else if (!ft_strncmp(line, SOUTH, ft_strlen(SOUTH)))
		ft_fill_data(&(info->texture_south), line, flag, data);
	else if (!ft_strncmp(line, WEST, ft_strlen(WEST)))
		ft_fill_data(&(info->texture_west), line, flag, data);
	else if (!ft_strncmp(line, EAST, ft_strlen(EAST)))
		ft_fill_data(&(info->texture_east), line, flag, data);
}

void	ft_get_info(t_data *data)
{	
	ft_search_map_content(data);
	ft_fill_color(data);
	ft_get_info_texture(data);
	printf("la map start ligne %d\n", data->map->start);
	// printf("la line sol color = [%s]\n", line);
}

// void	ft_remap(t_data *data)
// {
// 	char	**new_map;
// 	char	**map;
// 	int		y;
// 	int		x;
	
// 	printf("LA SIZE = y[%d] x[%d]\n", data->map->y_size, data->map->x_size);
// 	map = data->map->map;
// 	new_map = (char **)malloc(sizeof(char *) * (data->map->y_size + 1));
// 	if (!new_map)
// 		printf("error\n");
// 	y = -1;
// 	while (++y < data->map->y_size)
// 	{
// 		x = -1;
// 		new_map[y] = (char *)malloc(sizeof(char) * (data->map->x_size + 1));
// 		ft_memset(new_map[y], '2', data->map->x_size + 1);
// 		new_map[y][data->map->x_size + 1] = '\0';
// 		// ft_memcpy(new_map[y], map[y], data->map.y_size + 1);
// 		printf("NEW AV [%c]\n", new_map[y][34]);
// 		while (++x < data->map->x_size)
// 		{

// 			if (map[y][x] == SPACE || !map[y][x])
// 				new_map[y][x] = EMPTY;
// 			else if (map[y][x])
// 				new_map[y][x] = map[y][x];
// 			else
// 				new_map[y][x] = EMPTY;
// 			// printf("ici map = [%c][%d] | ici new_map = [%c]\n",map[y][x], x, new_map[y][x]);
			
// 		}
// 		printf("NEW AP [%c]\n", new_map[y][32]);
// 		new_map[y][x] = '\0';
// 		printf ("len = %zu\n", ft_strlen(new_map[y]));
// 		// printf("%s\n", new_map[y]);
// 		// // printf("map [%s] | new_map [%s]\n", map[y], new_map[y]);
// 	}
// 	new_map[y] = NULL;
// 	printf("LA SIZE = y[%d] x[%d]\n", y, x);
// 	for(int u = 0; new_map[u]; u++)
// 		printf("%s\n", new_map[u]);
// 	// ft_free_array(data->map.map);
// 	data->map->map = new_map;
// }

void	ft_check_map(t_data *data)
{
	// data->map.map
	int		x;
	int		y;
	char	**map;

	x = 0;
	ft_basic_check(data);
	map = data->map->map;
	ft_get_size_map(data);
	printf("le y_size [%d] et x_size [%d]\n", data->map->y_size, data->map->x_size);
	ft_check_walls(data);
	x = 0;
	printf("la ligne en question [%s]\n", map[ft_arrlen(map) - 1]);
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
		// printf("checker res [%d][%d] line [%d] strlen [%zu]\n", ft_wall(map[y][0], LEFT), ft_wall(map[y][ft_strlen(map[y]) - 1], RIGHT), y, ft_strlen(map[y]));
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

	// connaitre la + grande ligne map->x_size a faire en amont -> DONE
	// maintenant on va modifier la map pour remplacer les espaces par des 2
	// ft_remap(data);
	// for(int u = 0; data->map.map[u]; u++)
	// 	printf("NEW MAP [%s]\n", data->map.map[u]);
}

