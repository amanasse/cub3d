/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:53:33 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/21 15:19:09 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_mlx(t_data	*d)
{
	if (d->mlx_ptr && d->win_ptr)
	{
		if (d->path.no)
			mlx_destroy_image(d->mlx_ptr, d->path.no);
		if (d->path.so)
			mlx_destroy_image(d->mlx_ptr, d->path.so);
		if (d->path.ea)
			mlx_destroy_image(d->mlx_ptr, d->path.ea);
		if (d->path.we)
			mlx_destroy_image(d->mlx_ptr, d->path.we);
	}
	if (d->win_ptr)
		mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	if (d->mlx_ptr)
	{
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
	}
	free_tab(d);
	exit (0);
}

void	free_tab(t_data *d)
{
	int	i;

	i = 0;
	while (d->tab[i])
	{
		free(d->tab[i]);
		i++;
	}
	free (d->tab);
    if (d->path.path_so)
        free (d->path.path_so);
    if (d->path.path_ea)
        free (d->path.path_ea);
    if (d->path.path_we)
        free (d->path.path_we);
    if (d->path.path_no)
        free (d->path.path_no);
    if (d->c.path)
        free (d->c.path);
    if (d->f.path)
        free (d->f.path);
}