/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:56:27 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/17 15:26:05 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_map	t_map; // a regler - déjà typee dabs cub3d.h

/*	free.c	*/
void	*ft_free_array(char **arr);

/*	info.c	*/
void	ft_get_info(t_map *map);

#endif