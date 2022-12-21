/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_check_errors_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:30:08 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/21 15:28:04 by amanasse         ###   ########.fr       */
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

int check_colors(t_color *color, t_data *d)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (color->path[i])
    {
        if ((color->path[i] >= '0' && color->path[i] <= '9') || color->path[i] == ',')
        {
            if (color->path[i] == ',')
            {
                if((color->path[i + 1] && color->path[i + 1] == ',') || color->path[0] == ',')
                {
                    printf("error: color: problem whith ','\n");
                    free_tab(d);
                    return(-1);
                }
                count += 1;
            }
            i++;
        }
        else 
        {
            printf("error: color: need to be positive & numeric\n");
            free_tab(d);
            return(-1);        
        }
    }
    if (count != 2)
    {
        {
            printf("error: color: problem whith ','\n");
            free_tab(d);
            return(-1);        
        }
    }
    return (0);
}