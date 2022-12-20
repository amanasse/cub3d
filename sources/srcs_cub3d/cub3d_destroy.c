/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:53:33 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/20 16:40:20 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_mlx(t_data	*d)
{
	if (d->mlx_ptr && d->win_ptr)
	{
		if (d->no)
			mlx_destroy_image(d->mlx_ptr, d->no);
		if (d->so)
			mlx_destroy_image(d->mlx_ptr, d->so);
		if (d->ea)
			mlx_destroy_image(d->mlx_ptr, d->ea);
		if (d->we)
			mlx_destroy_image(d->mlx_ptr, d->we);
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
    if (d->path_so)
        free (d->path_so);
    if (d->path_ea)
        free (d->path_ea);
    if (d->path_we)
        free (d->path_we);
    if (d->path_no)
        free (d->path_no);
    if (d->path_c)
        free (d->path_c);
    if (d->path_f)
        free (d->path_f);
}