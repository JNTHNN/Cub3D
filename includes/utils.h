/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:56:27 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/10 11:05:59 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*  atoi.c  */
int				ft_space_letter(char c);
u_int8_t		ft_atoi_color(char *s, int *flag);

/*	free.c	*/
void			*ft_free_array(void **arr);
void			ft_free_info(t_info *info);
void			ft_free_data(t_data *data);

/* free2.c */
void			ft_free_int_array(int **arr, int y);
void			ft_free_minimap(t_data *data);
void			ft_free_textures(t_data *data);

/*	size.c	*/
int				ft_arrlen(char **tab);
size_t			ft_strlen_cub3d(char *s);

/*  init.c  */
t_info			*ft_init_info(t_data *data);
t_color			ft_init_color(void);
t_map			*ft_init_map(t_data *data, char *file);
t_file			*ft_init_file(t_data *data);

/* init2.c */
t_textures		*ft_init_textures(t_data *data);
t_img			*ft_init_img(t_data *data);
t_minimap		*ft_init_minimap(t_data *data);

#endif