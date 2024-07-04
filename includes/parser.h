/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:56:55 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/25 21:57:57 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define Y 0
# define X 1
# define START 0
# define END 1
# define OFFSET 0.5

/*  utils/map_utils.c   */
int		ft_wall(char c, int flag);
int		ft_orientation_player(char c);
void	ft_parsing_raw_map(t_data *data);

/*  utils/fd_utils.c    */
void	ft_open_fd(t_data *data);
void	ft_close_fd(t_data *data);

/*  colors.c    */
void	ft_fill_color(t_data *data);

/*  data.c  */
void	ft_check_data(char *line, t_data *data, int *flag);

/*  map.c   */
void	ft_get_y_x_max(t_data *data);
void	ft_check_map(t_data *data);

/*  parsing.c   */
void	ft_setup_map(t_data *data);

/*  player.c    */
void	ft_check_player(t_data *data);

/*  textures.c   */
void	ft_get_info_texture(t_data *data);

/*	wall.c	*/
void	ft_check_walls(t_data *data);
void	ft_backtrack_wall(t_data *data);
void	ft_backtrack_player(t_data *data);

#endif