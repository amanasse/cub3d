/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:33:14 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/21 15:22:33 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
    t_data  data;
    
    ft_memset_cub3d(&data, 0, sizeof(t_data));
    if (argc != 2)
        return (0);
    if (check_argv(argv[1]) == -1)
        return (0);
    if (init_tab(argv[1], &data) == -1)
        return (0);
    print_tab(data.tab);
    if (check_tab_doublon(&data) == -1)
        return (0);
    if (check_colors(&data.c, &data) == -1 || check_colors(&data.f, &data) == -1)
        return (0);
    if (make_colors(&data.c, &data) == -1 || make_colors(&data.f, &data) == -1)
        return (0);
    printf("data.c.r = %d\n", data.c.r);
    printf("data.c.g = %d\n", data.c.g);
    printf("data.c.b = %d\n", data.c.b);
    printf("data.f.r = %d\n", data.f.r);
    printf("data.f.g = %d\n", data.f.g);
    printf("data.f.b = %d\n", data.f.b);
    // if (ft_init_struct(&data) == -1)
    //     return (0);
    free_tab(&data);
    return (0);
}