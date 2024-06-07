/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:07:38 by jgasparo          #+#    #+#             */
/*   Updated: 2024/06/07 16:04:29 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define STR_MEM "Error\nMemory allocation goes wrong"
# define STR_TOO_MANY "Error\nToo many arguments"
# define STR_NO_MAP	"Error\nNo Map, No Game"
# define STR_WRONG_EXT "Error\nWrong file extension"
# define CUB ".cub"
# define DOT 46
# define MAP argv[1]

/*	error.c	*/
void	ft_check_arg(int argc, char **argv);

#endif