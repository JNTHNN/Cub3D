/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:56:27 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/29 03:08:44 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*	free.c	*/
void	    *ft_free_array(char **arr);

/*	info.c	*/
void	    ft_save_map(t_data *data);
void	    ft_get_map(t_data *data);
void        ft_check_map(t_data *data);
void		ft_check_player(t_data *data);

/*	size.c	*/
int	        ft_arrlen(char **tab);

/*  atoi.c  */
u_int8_t    ft_atoi_color(char *s, int *flag);

/*  init.c  */
t_data	    *ft_init_data(char *file);

/*  temp.c  */
void	    ft_print_struct(t_data *data);

#endif