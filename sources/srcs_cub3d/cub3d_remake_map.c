/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_remake_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:30:43 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/22 15:11:55 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int remake_map(t_data *data)
{
	int j;
	int k;

	data->last_info += 1;
	j = data->last_info;
	while (data->tab[data->last_info])
	{
		if (check_map_caracters(data->tab[data->last_info], &data->map) == -1)
			return (free_tab(data), -1);
		data->last_info++;
	}
	while (data->tab[j])
	{
		k = 0;
		while(data->tab[j][k])
		{
			if (data->tab[j][k] == '1')
			{
				data->map.first_line = j;
				break;
			}
			k++;
		}
		j++;
	}
	printf ("data->map.first_line = %d\n", data->map.first_line);
	return (0);






	
}