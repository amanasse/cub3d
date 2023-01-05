/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_remake_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:30:43 by amanasse          #+#    #+#             */
/*   Updated: 2023/01/05 12:27:46 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_largest_line(t_data *data)
{
	int	i;
	int	k;
	int	count;

	count = 0;
	i = data->map.first_line;
	k = data->map.last_line;
	while (i <= k)
	{
		if (count < (int)ft_strlen(data->tab[i]))
		{
			count = (int)ft_strlen(data->tab[i]);
			data->largest_line = i;
		}
		i++;
	}
	data->map.largest_line = count;
	return (count);
}

int	new_map(t_data *data, int j)
{
	int		i;
	int		k;
	char	*tmp;

	i = data->map.first_line;
	k = data->map.last_line;
	if (data->tab[data->largest_line][j - 1] == '1')
	{
		j += 1;
		data->map.largest_line += 1;
	}
	while (i <= k)
	{
		if ((int)ft_strlen(data->tab[i]) <= j)
		{
			tmp = malloc(sizeof(char) * (j + 2));
			if (tmp == NULL)
				return (printf("error: malloc"), -1);
			tmp = ft_strcpy_map(tmp, data->tab[i], j);
			free (data->tab[i]);
			data->tab[i] = tmp;
		}
		i++;
	}
	return (0);
}

int correct_map(t_data *data, int first, int last)
{
	char	**tab;
	char 	*tmp;
	int 	i;
	int 	k;

	k = 0;
	i = 0;
	tab = malloc(sizeof(char *) * (last - first + 4));
	if (tab == NULL)
		return(free_tab(data), -1);
	printf("data->map.largest_line = %d\n", data->map.largest_line);
	tab[0] = malloc(sizeof(char) * data->map.largest_line + 3);
	if (tab[0] == NULL)
		return (free_tab(data), -1);
	while (i < data->map.largest_line + 1)
	{
		tab[0][k] = 'X';
		i++;
		k++;
	}
	tab[0][k] = '\0';
	i = 1;
	while (first <= last)
	{
		tmp = malloc(sizeof(char) * data->map.largest_line + 3);
		if (tmp == NULL)
			return (free_tab(data), -1);
		tmp = ft_strcpy_color(tmp, data->tab[first]);
		tab[i] = tmp;
		i++;
		first++;
	}
	tab[i] = malloc(sizeof(char) * data->map.largest_line + 3);
	if (tab[i] == NULL)
		return (free_tab(data), -1);
	k = 0;
	while (k < data->map.largest_line + 1)
	{
		tab[i][k] = 'X';
		k++;
	}
	tab[i][k] = '\0';
	tab[++i] = NULL;
	i = 0;
	while (data->tab[i])
	{
		free(data->tab[i]);
		i++;
	}
	free(data->tab);
	data->tab = tab;
	return (0);
}

int	remake_map(t_data *data)
{
	int	j;

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
	if (new_map(data, j) == -1)
		return (free_tab(data), -1);
	if (check_borders(data, data->map.first_line, data->map.last_line, 0) == -1)
		return (free_tab(data), -1);
	if (correct_map(data, data->map.first_line, data->map.last_line) == -1)
		return (free_tab(data), -1);
	if (check_zero(data) == -1)
		return (free_tab(data), -1);
	print_tab(data);
	return (0);
}
