/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:39:25 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/16 16:04:16 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../sources/libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	char	**tab;
	char	*line;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*p;
	void	*b;
	int		fichier;
	int		i;
	int		j;
	int		tab_x;
	int		tab_y;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		h;
	int		l;
	int		count;
}				t_data;

//MAKE TAB**
int	ft_read_map(t_data *d, char *str);
int	ft_first_read(t_data *d, char *str);

//CHECK ERRORS
int check_argv(char *str);


//UTILS
int	ft_strlen_cub3d(char *str);
void    ft_memset_cub3d(void *s, int c, size_t n);
int	ft_strcmp(char *s1, char *s2);
void	free_tab(t_data *d);

#endif