/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_errors_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:23:28 by mede-sou          #+#    #+#             */
/*   Updated: 2023/01/04 17:06:01 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_first_line(t_data *data, int j)
{	
	int	k;

	while (data->tab[j])
	{
		k = 0;
		while (data->tab[j][k])
		{
			if (data->tab[j][k] == '1')
			{
				data->map.first_line = j;
				return (0);
			}
			k++;
		}
		j++;
	}
	printf ("error\nno map\n");
	free_tab(data);
	return (-1);
}

int	check_last_line(t_data *data, int j)
{	
	int	k;

	while (data->tab[j])
		j++;
	j--;
	while (data->tab[j])
	{
		k = 0;
		while (data->tab[j][k] == ' ')
			k++;
		if (data->tab[j][k] == '1')
		{
			data->map.last_line = j;
			return (0);
		}
		j--;
	}
	return (0);
}

int	check_after_last_line(t_data *data)
{
	int	i;
	int	k;

	i = data->map.last_line + 1;
	while (data->tab[i])
	{
		k = 0;
		while (data->tab[i][k])
		{
			if (data->tab[i][k] != '1' || data->tab[i][k] != ' '
					|| data->tab[i][k] != '\0')
				return (printf("error\nwrong map2"), free_tab(data), -1);
			k++;
		}
		i++;
	}
	return (0);
}

int	check_borders(t_data *data, int i, int j, int k)
{
	while (k <= data->map.last_line && data->tab[i][k])
	{
		if (data->tab[i][k] == '0' || data->tab[i][k] == 'N'
			|| data->tab[i][k] == 'W' || data->tab[i][k] == 'E'
				|| data->tab[i][k] == 'S')
			return ((printf("error\nwrong map: borders"), -1));
		k++;
	}
	k = -1;
	while (++k <= data->map.last_line && data->tab[j][k])
	{
		if (data->tab[j][k] == '0' || data->tab[j][k] == 'N'
			|| data->tab[j][k] == 'W' || data->tab[j][k] == 'E'
				|| data->tab[j][k] == 'S')
			return ((printf("error\nwrong map: borders"), -1));
	}
	while (i <= j && data->tab[i][0])
	{
		if (data->tab[i][0] == '0' || data->tab[i][0] == 'N'
			|| data->tab[i][0] == 'W' || data->tab[i][0] == 'E'
				|| data->tab[i][0] == 'S')
			return ((printf("error\nwrong map: borders"), -1));
		i++;
	}
	return (0);
}
