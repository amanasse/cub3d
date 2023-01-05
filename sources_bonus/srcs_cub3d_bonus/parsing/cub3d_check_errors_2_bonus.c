/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_errors_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mede-sou <mede-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:30:08 by amanasse          #+#    #+#             */
/*   Updated: 2023/01/02 11:59:38 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_caracters(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1' && str[i] != '0' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
		{
			printf("error\nwrong map");
			return (-1);
		}
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			map->count += 1;
		if (map->count > 1)
		{
			printf("error\nwrong map");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (str[i] != '.' && i > 0)
		i--;
	if (str[i] == '.')
	{
		if (ft_strcmp (&str[i], ".cub\0") == 0)
			return (0);
		else
		{
			write (2, "Error\nthe map isn't a '.cub'\n", 29);
			return (-1);
		}
	}
	write (2, "Error\nthe map isn't a '.cub'\n", 29);
	return (-1);
}

int	check_colors(t_color *c, t_data *d)
{
	c->i = 0;
	c->count = 0;
	while (c->p[c->i])
	{
		if ((c->p[c->i] >= '0' && c->p[c->i] <= '9')
			|| c->p[c->i] == ',' || c->p[c->i] == ' ')
		{
			if (c->p[c->i] == ',')
			{
				if ((c->p[c->i + 1] && c->p[c->i + 1] == ',') || c->p[0] == ',')
					return (printf("error: color: problem whith ','\n"),
						free_tab(d), -1);
				c->count += 1;
			}
			c->i++;
		}
		else
			return (printf("error: color: need to be positive & numeric\n"),
				free_tab(d), -1);
	}
	if (c->count != 2)
		return (printf("error: color: problem whith ','\n"), free_tab(d), -1);
	return (0);
}
