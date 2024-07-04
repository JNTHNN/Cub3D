/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:56:27 by jgasparo          #+#    #+#             */
/*   Updated: 2024/07/04 22:00:58 by gdelvign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*  atoi.c  */
u_int8_t		ft_atoi_color(char *s, int *flag);

/*	free.c	*/
void			*ft_free_array(char **arr);
void			ft_free_data(t_data *data);

/*	size.c	*/
int				ft_arrlen(char **tab);


/*  init.c  */
t_info			*ft_init_info(t_data *data);
t_color			ft_init_color(void);
t_map			*ft_init_map(t_data *data, char *file);
t_file			*ft_init_file(t_data *data);

/* init2.c */
t_textures		*ft_init_textures(t_data *data);

#endif