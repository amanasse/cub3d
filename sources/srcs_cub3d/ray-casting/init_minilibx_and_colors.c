/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx_and_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:17:28 by mede-sou          #+#    #+#             */
/*   Updated: 2023/01/04 13:23:45 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_color(char *s, int nb)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (nb < 10)
		s[i] = nb + 48;
	else
		s[i] = nb + 55;
}

void	ft_putnbr_base_x(int nb, char *color)
{
	if (nb >= 16)
	{
		ft_putnbr_base_x(nb / 16, color);
		ft_putnbr_base_x(nb % 16, color);
	}
	else
		ft_print_color(color, nb);
}

void	conversion_colors(t_color *color)
{
	char	*temp;

	temp = NULL;
	if (color->r < 16)
		color->r_hex[0] = '0';
	ft_putnbr_base_x(color->r, color->r_hex);
	if (color->g < 16)
		color->g_hex[0] = '0';
	ft_putnbr_base_x(color->g, color->g_hex);
	if (color->b < 16)
		color->b_hex[0] = '0';
	ft_putnbr_base_x(color->b, color->b_hex);
	temp = ft_strjoin(color->r_hex, color->g_hex);
	color->color_hex = ft_strjoin(temp, color->b_hex);
	color->color_int = ft_atoi_base(color->color_hex, 16);
	free(color->color_hex);
	free(temp);
}

void	init_minilibx(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		return ;
	if (ft_init_struct(d) == -1)
		return ;
	d->rx = 800;
	d->ry = 600;
	mlx_get_screen_size(d->mlx_ptr, &d->sizex, &d->sizey);
	if (d->rx > d->sizex)
		d->rx = d->sizex;
	if (d->ry > d->sizey)
		d->ry = d->sizey;
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->rx, d->ry, "cub3D");
	if (!d->win_ptr)
		return ;
	set_player_info(d);
	conversion_colors(&d->c);
	conversion_colors(&d->f);
	init_vectors(d);
	draw_ceiling_floor(d, -1, -1);
	get_textures1(d);
	ray_casting(d);
}
