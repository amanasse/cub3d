/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_remake_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:30:43 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/22 18:17:46 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_first_line(t_data *data, int j)
{	
	int k;
	while (data->tab[j])
	{
		k = 0;
		while(data->tab[j][k])
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
	int k;
	
	while (data->tab[j])
		j++;
	j--;
	while (data->tab[j])
	{
		k = 0;
		while (data->tab[j][k] == '1')
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
	int i;
	int k;
	
	i = data->map.last_line + 1;
	while (data->tab[i])
	{
		k = 0;
		while (data->tab[i][k])
		{
			if (data->tab[i][k] != '1' || data->tab[i][k] != ' ' || data->tab[i][k] != '\0')
				return (printf("error\nwrong map2"), free_tab(data), -1);
			k++;
		}
		i++;
	}
	return (0);
}
int	count_largest_line(t_data *data)
{
	int i;
	int k;
	int count;
	
	count = 0;
	i = data->map.first_line;
	k = data->map.last_line;
	while (i <= k)
	{
		if (count < (int)ft_strlen(data->tab[i]))
			count = (int)ft_strlen(data->tab[i]);
		i++;
	}
	return (count);	
}

int	new_map(t_data *data, int j)
{
	int i;
	int k;
	char *tmp;

	i = data->map.first_line;
	k = data->map.last_line;
	// while (i <= k)
	// {
		if ((int)ft_strlen(data->tab[i]) < j)
		{
			tmp = malloc(sizeof(char) * (j + 1));
			if (tmp == NULL)
				return (printf("error: malloc"), -1);
			tmp = ft_strcpy_map(tmp, data->tab[i]);
			// i++;
		// }
		
	// }	

	return (0);
}

int remake_map(t_data *data)
{
	int j;

	data->last_info += 1;
	j = data->last_info;
	while (data->tab[data->last_info])
	{
		if (check_map_caracters(data->tab[data->last_info], &data->map) == -1)
			return (free_tab(data), -1);
		data->last_info++;
	}
	if (check_first_line(data, j) == -1)
		return (-1);
	if (check_last_line(data, j) == -1)
		return (-1);
	if (check_after_last_line(data) == -1)
		return (-1);
	j = count_largest_line(data);
	printf ("data->map.first_line = %d\n", data->map.first_line);
	printf ("data->map.last_line = %d\n", data->map.last_line);
	printf ("j = %d\n", j);
	if (new_map(data, j) == -1)
		return (-1);
	
	return (0);






	
}