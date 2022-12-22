/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_errors_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:30:08 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/22 13:08:41 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
