/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:20:45 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/22 18:38:47 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strcpy_path(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && src[i] != ' ')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*ft_strcpy_map(char *dest, char *src, int len)
{
	int	i;
	
	i = 0;
	while (i < (int)ft_strlen(src))
	{
		if (src[i] == ' ')
			dest[i] = 'X';
		else
			dest[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = 'X';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy_color(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
