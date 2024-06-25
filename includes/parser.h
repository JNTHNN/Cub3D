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

/*  parsing.c   */
void	ft_setup_map(t_data *data);

/*  colors.c    */
void	ft_fill_color(t_data *data);
void	ft_fill_rgb(char *color, u_color *rgb, t_data *data);

/*  textures.c   */
void	ft_fill_info_texture(char *raw_texture, char **texture);
void	ft_get_info_texture(t_data *data);

/*  map.c   */
void	ft_get_map(t_data *data);

/*  player.c    */
void	ft_check_player(t_data *data);

/*  info.c  */
void	ft_check_data(char *line, t_data *data, int *flag);

/*  utils/map_utils.c   */
int	    ft_wall(char c, int flag);
int	    ft_position_player(char c);
void	ft_get_size_map(t_data *data, char **map);
void	ft_basic_check(t_data *data);
void	ft_search_map_content(t_data *data);

#endif