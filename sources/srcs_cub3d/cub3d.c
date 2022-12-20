/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:33:14 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/20 17:14:04 by amanasse         ###   ########.fr       */
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
    if (ft_read_map(&data, argv[1]) == -1)
        return (0);
    print_tab(data.tab);
    if (check_tab_doublon(&data) == -1)
        return (0);
    // if (ft_init_struct(&data) == -1)
    //     return (0);
    return (0);
}