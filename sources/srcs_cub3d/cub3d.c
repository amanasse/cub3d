/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:33:14 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/16 16:03:14 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    size_map(char *arv)
{
    int        i;
    int        fd;
    char    *line;
    char    *tmp;

    i = 0;
    fd = open(arv, O_RDONLY);
    if (fd == -1)
        return (0);
    tmp = get_next_line(fd);
    if (tmp == NULL)
        return (0);
    line = tmp;
    while (line != NULL)
    {
        i++;
        free (line);
        line = get_next_line(fd);
    }
    close (fd);
    return (i);
}

void    init_tab_line(int fd, char **tab, t_data *d)
{
    char    *tmp;
    char    *line;

    tmp = get_next_line(fd);
    if (tmp == NULL)
        return ;
    line = tmp;
    while (line != NULL)
    {
        d->size_line = ft_strlen(line);
        tab[d->tab_y] = ft_dup_solong(line, d->size_line - 1);
        if (tab[d->tab_y] == NULL)
            return ;
        free (line);
        line = get_next_line(fd);
        d->tab_y++;
    }
}

int    init_tab(char *arv, t_data *d)
{
    char    **tab;
    int        fd;

    d->tab_y = 0;
    d->size_map = size_map(arv);
    if (d->size_map == 0 || d->size_map == 1)
        return (1);
    tab = malloc(sizeof(char **) * (d->size_map));
    if (tab == NULL)
        return (1);
    fd = open(arv, O_RDONLY);
    if (fd == -1)
        return (1);
    init_tab_line(fd, tab, d);
    if (tab == NULL)
    {
        close (fd);
        return (1);
    }
    d->tab = tab;
    close (fd);
    return (0);
}
int	ft_first_read(t_data *d, char *str)
{
	d->fichier = open(str, 0);
	if (d->fichier == -1)
	{
		write (2, "Error\n", 6);
		close (d->fichier);
		return (0);
	}
    printf("%d\n", d->fichier);
	ft_memset_cub3d(d->tab, 0, sizeof(d->tab));
	d->i = 0;
	d->j = 0;
	d->line = get_next_line(d->fichier);
    // printf("%s\n", d->line);

	if (d->line == NULL)
	{
		close (d->fichier);
		free_tab(d);
		write (2, "Error\n", 6);
		return (0);
	}
    // write (2, "LOOOL\n", 6);
	return (1);
}

int	ft_read_map(t_data *d, char *str)
{
	if (ft_first_read(d, str) == 0)
		return (0);
	while (d->line != NULL)
	{
		d->tab[d->i] = d->line;
		// d->j = 0;
		// while (d->tab[d->i][d->j] != '\n' && d->j < ft_strlen_cub3d(d->line))
		// {
		// 	if (d->tab[d->i][d->j] == 'C')
		// 		d->count++;
		// 	d->j++;
		// }
		// d->tab[d->i][d->j] = '\0';
		d->i++;
		d->line = get_next_line(d->fichier);
	}
    write (2, "LOOOL\n", 6);

	d->tab[d->i] = NULL;
	d->tab_y = d->j;
	d->tab_x = d->i;
	close (d->fichier);
	return (1);
}

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
			return (1);
		else
		{
			write (2, "Error\nthe map isn't a '.cub'\n", 29);
			return (0);
		}
	}
	write (2, "Error\nthe map isn't a '.cub'\n", 29);
	return (0);
}

int main(int argc, char **argv)
{
    t_data  data;
    
    ft_memset_cub3d(&data, 0, sizeof(t_data));
    if (argc != 2)
        return (0);
    if (check_argv(argv[1]) == 0)
        return (0);
    if (ft_read_map(&data, argv[1]) == 0)
        return (0);


    return (0);
}