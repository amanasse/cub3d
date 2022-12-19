/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:39:25 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/19 16:19:29 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../sources/libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	char	*tab[1000];
	char	*check_tab[7];
	int		int_tab[6];
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
	char	*path_no;
}				t_data;


//MAKE TAB**
int	ft_read_map(t_data *d, char *str);
int	ft_first_read(t_data *d, char *str);

//MAKE PATH
int	save_path(char *str, t_data *data);

//CHECK ERRORS
int		check_argv(char *str);
int		check_if_doublon(char *str, char *check_str);
int		check_tab_doublon(t_data *data);
void	init_check_tab(t_data *data);
int		check_if_tab(char *str, char **tab);

//UTILS
int		ft_strlen_cub3d(char *str);
void	ft_memset_cub3d(void *s, int c, size_t n);
int		ft_strcmp(char *s1, char *s2);
void	free_tab(t_data *d);
void	print_tab(char **tab);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcpy_path(char *dest, char *src);


#endif