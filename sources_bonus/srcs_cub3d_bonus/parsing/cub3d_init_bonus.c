/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:38:08 by amanasse          #+#    #+#             */
/*   Updated: 2023/01/04 13:33:39 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_check_tab(t_data *data)
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
	d->path.no = mlx_xpm_file_to_image(d->mlx_ptr, d->path.path_no,
			&d->l, &d->h);
	d->path.so = mlx_xpm_file_to_image(d->mlx_ptr, d->path.path_so,
			&d->l, &d->h);
	d->path.ea = mlx_xpm_file_to_image(d->mlx_ptr, d->path.path_ea,
			&d->l, &d->h);
	d->path.we = mlx_xpm_file_to_image(d->mlx_ptr, d->path.path_we,
			&d->l, &d->h);
	if (!d->path.no || !d->path.so || !d->path.ea || !d->path.we)
	{
		write(2, "Error\nProb with img\n", 20);
		ft_close(d);
		return (-1);
	}
	return (0);
}

int	ft_init_struct(t_data *d)
{
	if (ft_init_images(d) == -1)
		return (-1);
	return (0);
}
