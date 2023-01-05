/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:33:14 by amanasse          #+#    #+#             */
/*   Updated: 2023/01/04 13:13:40 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	d;

	ft_memset_cub3d(&d, 0, sizeof(t_data));
	if (argc != 2)
		return (0);
	if (check_argv(argv[1]) == -1)
		return (0);
	if (init_tab(argv[1], &d) == -1)
		return (0);
	if (check_tab_doublon(&d) == -1)
		return (0);
	if (check_colors(&d.c, &d) == -1 || check_colors(&d.f, &d) == -1)
		return (0);
	if (make_colors(&d.c, &d) == -1 || make_colors(&d.f, &d) == -1)
		return (0);
	if (remake_map(&d) == -1)
		return (0);
	init_minilibx(&d);
	mlx_hook(d.win_ptr, 02, 1L << 0, deal_key, &d);
	mlx_hook(d.win_ptr, X, 1L << 2, ft_close, &d);
	mlx_loop(d.mlx_ptr);
	free_tab(&d);
	return (0);
}
