/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgasparo <jgasparo@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:34:58 by gdelvign          #+#    #+#             */
/*   Updated: 2024/03/30 23:42:08 by jgasparo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (j < n_len && haystack[i + j] == needle[j])
				j++;
			if (j == n_len && i + j <= len)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
