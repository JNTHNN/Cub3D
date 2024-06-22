/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:56:27 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/22 20:22:15 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*	free.c	*/
void	*ft_free_array(char **arr);

/*	info.c	*/
void	ft_get_info(t_data *data);

/*	size.c	*/
int	ft_arrlen(char **tab);

/*  atoi.c  */
u_int8_t ft_atoi_color(char *s, int *flag);

#endif