/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_make_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:44:57 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/21 14:18:20 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	make_path(char *str, char *compare, t_data *data)
{
	int j;
	int c;
	
	c = 0;
	data->make_count = 0;
	data->make_i = 0;
	j = 0;
	while (data->tab[data->make_i])
	{
		if (ft_strnstr(data->tab[data->make_i], str, 2) == 0)
		{
			while (data->tab[data->make_i][j] == ' ' && data->tab[data->make_i][j] != '\0')
				j++;
			while (data->tab[data->make_i][j] == compare[c] && compare[c] != '\0')
			{
				c++;
				j++;
			}
			while (data->tab[data->make_i][j] == ' ' && data->tab[data->make_i][j] != '\0')
				j++;
			data->make_k = j;
			while (data->tab[data->make_i][j] != ' ' && data->tab[data->make_i][j] != '\0')
				j++;
			data->make_count = j - data->make_k;
			while (data->tab[data->make_i][j] == ' ' && data->tab[data->make_i][j] != '\0')
				j++;
			if (data->tab[data->make_i][j] != ' ' && data->tab[data->make_i][j] != '\0')
				return (printf("Error: %s: Too many path\n", str), -1);
			return (0);
		}
		data->make_i++;
	}
	return (0);
}

int	save_path_no_so_we(char *str, t_data *data)
{
    if (ft_strcmp(str, "NO") == 0)
    {
	    if (make_path(str, "NO", data) == -1)
			return (-1);
	    data->path.path_no = malloc(sizeof(char) * data->make_count + 1);
	    data->path.path_no = ft_strcpy_path(data->path.path_no, data->tab[data->make_i] + data->make_k);
	}
	else if (ft_strcmp(str, "SO") == 0)
	{	
		if (make_path(str, "SO", data) == -1)
			return (-1);
		data->path.path_so = malloc(sizeof(char) * data->make_count + 1);
		data->path.path_so = ft_strcpy_path(data->path.path_so, data->tab[data->make_i] + data->make_k);
	}
	else if (ft_strcmp(str, "WE") == 0)
	{
		if (make_path(str, "WE", data) == -1)
			return (-1);
		data->path.path_we = malloc(sizeof(char) * data->make_count + 1);
		data->path.path_we = ft_strcpy_path(data->path.path_we, data->tab[data->make_i] + data->make_k);
	}
    return (0);
}
int	save_path_ea_c_f(char *str, t_data *data)
{
	if (ft_strcmp(str, "EA") == 0)
	{
		if (make_path(str, "EA", data) == -1)
			return (-1);
		data->path.path_ea = malloc(sizeof(char) * data->make_count + 1);
		data->path.path_ea = ft_strcpy_path(data->path.path_ea, data->tab[data->make_i] + data->make_k);
	}
	else if (ft_strcmp(str, "C") == 0)
	{
		if (make_path(str, "C", data) == -1)
			return (-1);
		data->c.path = malloc(sizeof(char) * data->make_count + 1);
		data->c.path = ft_strcpy_path(data->c.path, data->tab[data->make_i] + data->make_k);
	}
	else if (ft_strcmp(str, "F") == 0)
	{
		if (make_path(str, "F", data) == -1)
			return (-1);
		data->f.path = malloc(sizeof(char) * data->make_count + 1);
		data->f.path = ft_strcpy_path(data->f.path, data->tab[data->make_i] + data->make_k);
	}
    return (0);
}


int	save_path(char *str, t_data *data)
{
	if (ft_strcmp(str, "NO") == 0 || ft_strcmp(str, "SO") == 0 || ft_strcmp(str, "WE") == 0)
	{
        if (save_path_no_so_we(str, data) == -1)
            return (-1);
    }
    else if (ft_strcmp(str, "EA") == 0 || ft_strcmp(str, "C") == 0 || ft_strcmp(str, "F") == 0)
    {
        if (save_path_ea_c_f(str, data) == -1)
            return (-1);
    }
	return (0);
}