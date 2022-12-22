/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:39:25 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/22 18:53:02 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../sources/libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"


typedef struct s_map
{
	int		count;
	int		first_line;
	int		last_line;
}				t_map;


typedef struct s_path
{
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	void	*no;
	void	*ea;
	void	*so;
	void	*we;
}				t_path;

typedef struct s_color
{
	int		i;
	int		count;
	char	*p;
	int		r;
	int		g;
	int		b;
	char	*color_hex;
    int		color_int;
}				t_color;

typedef struct s_data
{
	t_path  path;
	t_color c;
	t_color f;
	t_map	map;
	char	**tab;
	char	*check_tab[7];
	int		int_tab[6];
	char	*line;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*p;
	void	*b;
	int		size_line;
	int		size_map;
	int		last_info;
	int		make_i;
	int		make_k;
	int		make_count;
	int		fichier;
	int		i;
	int		error;
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
int		ft_read_map(t_data *d, char *str);
int		ft_first_read(t_data *d, char *str);
int		init_tab(char *arv, t_data *d);
void	init_tab_line(int fd, char **tab, t_data *d);
int		size_map(char *arv);


//MAKE PATH
int	make_path(char *str, char *compare, t_data *d);
int make_path_2(char *compare, t_data *d, int c, int j);
int ft_pass_path (char *str, char *compare);
int check_all_path(t_data *data);
int	save_path(char *str, t_data *data);
int	save_path_no_so_we(char *str, t_data *data);
int	save_path_ea_c_f(char *str, t_data *data);

//CHECK ERRORS
int		check_argv(char *str);
int		check_if_doublon(char *str, char *check_str);
int		check_doublon_path(t_data *data);
int		check_tab_doublon(t_data *data);
void	init_check_tab(t_data *data);
int		check_if_tab(char *str, char **tab);

int 	check_colors(t_color *color, t_data *d);


//COLORS
int		make_colors(t_color *color, t_data *data);
void    free_split_tab(char **tab);

//MAP
int		count_largest_line(t_data *data);
int		remake_map(t_data *data);
int		check_first_line(t_data *data, int j);
int		check_last_line(t_data *data, int j);
int		check_map_caracters(char *str, t_map *map);
int		check_borders(t_data *data);

//INIT
int		ft_init_images(t_data *d);
int		ft_init_struct(t_data *d);


//UTILS
int		ft_strlen_cub3d(char *str);
char    *ft_dup_solong(char *s, int len);
void	ft_memset_cub3d(void *s, int c, size_t n);
int		ft_strcmp(char *s1, char *s2);
void	free_tab(t_data *d);
void	print_tab(t_data *data);
void	print_tab_def(t_data *data);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcpy_path(char *dest, char *src);
char	*ft_strcpy_color(char *dest, char *src);
char	*ft_strcpy_map(char *dest, char *src, int len);

//DESTROY & FREE
int		destroy_mlx(t_data	*d);
void	free_tab(t_data *d);


#endif