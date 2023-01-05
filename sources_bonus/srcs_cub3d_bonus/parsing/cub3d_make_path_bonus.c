/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_make_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mede-sou <mede-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:44:57 by amanasse          #+#    #+#             */
/*   Updated: 2023/01/02 12:11:25 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	make_path_2(char *compare, t_data *d, int c, int j)
{
	while (d->tab[d->make_i][j] == ' ' && d->tab[d->make_i][j] != '\0')
		j++;
	while (d->tab[d->make_i][j] == compare[c] && compare[c] != '\0')
	{
		c++;
		j++;
	}
	while (d->tab[d->make_i][j] == ' ' && d->tab[d->make_i][j] != '\0')
		j++;
	d->make_k = j;
	while (d->tab[d->make_i][j] != ' ' && d->tab[d->make_i][j] != '\0')
		j++;
	d->make_count = j - d->make_k;
	while (d->tab[d->make_i][j] == ' ' && d->tab[d->make_i][j] != '\0')
		j++;
	if (d->tab[d->make_i][j] != ' ' && d->tab[d->make_i][j] != '\0')
		return (-1);
	return (0);
}

int	make_path(char *str, char *compare, t_data *d)
{
	int	j;
	int	c;

	d->make_count = 0;
	d->make_i = 0;
	j = 0;
	c = 0;
	while (d->tab[d->make_i])
	{
		if (ft_strnstr(d->tab[d->make_i], str, 2) == 0)
		{
			if (make_path_2(compare, d, c, j) == -1)
				return (printf("Error: %s: Too many path\n", str), -1);
			return (0);
		}
		d->make_i++;
	}
	return (0);
}

int	make_path_color(char *str, char *compare, t_data *d, int c)
{
	int	j;

	j = 0;
	while (d->tab[d->make_i])
	{
		if (ft_strnstr(d->tab[d->make_i], str, 2) == 0)
		{
			while (d->tab[d->make_i][j] == ' ' && d->tab[d->make_i][j] != '\0')
				j++;
			while (d->tab[d->make_i][j] == compare[c] && compare[c] != '\0')
			{
				c++;
				j++;
			}
			while (d->tab[d->make_i][j] == ' ' && d->tab[d->make_i][j] != '\0')
				j++;
			d->make_k = j;
			while (d->tab[d->make_i][j] != '\0')
				j++;
			d->make_count = j - d->make_k;
			return (0);
		}
		d->make_i++;
	}
	return (0);
}
