/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:38:08 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/20 17:35:54 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_check_tab(t_data *data)
{
	data->check_tab[0] = "NO\0";
	data->check_tab[1] = "SO\0";
	data->check_tab[2] = "WE\0";
	data->check_tab[3] = "EA\0";
	data->check_tab[4] = "F\0";
	data->check_tab[5] = "C\0";
	data->check_tab[6] = NULL;
}

int	ft_init_images(t_data *d)
{
    d->l = 100;
    d->h = 100;
	d->no = mlx_xpm_file_to_image(d->mlx_ptr, d->path_no,
			&d->l, &d->h);
	d->so = mlx_xpm_file_to_image(d->mlx_ptr, d->path_so,
			&d->l, &d->h);
	d->ea = mlx_xpm_file_to_image(d->mlx_ptr, d->path_ea,
			&d->l, &d->h);
	d->we = mlx_xpm_file_to_image(d->mlx_ptr, d->path_we,
			&d->l, &d->h);
	if (!d->no || !d->so || !d->ea || !d->we)
	{
		write(2, "Error\nProb with img\n", 20);
		destroy_mlx(d);
        return (-1);
	}
    return (0);
}

int	ft_init_struct(t_data *d)
{
    d->mlx_ptr = NULL;
	d->win_ptr = NULL;
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr)
	{
		d->win_ptr = mlx_new_window(d->mlx_ptr, 180, 180, "CUB3D");
		if (d->win_ptr)
        {
			if (ft_init_images(d) == -1)
                return (-1);
            return (0);
        }
        else
        {
			destroy_mlx(d);
            return (-1);
        }    
	}
	else
    {
		destroy_mlx(d);
        return (-1);
    }
}