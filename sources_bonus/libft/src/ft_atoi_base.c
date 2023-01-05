/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mede-sou <mede-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:31:48 by mede-sou          #+#    #+#             */
/*   Updated: 2023/01/02 11:58:56 by mede-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = (n * str_base) + (str[i] - 48);
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = (n * str_base) + (str[i] - 'A' + 10);
		i++;
	}
	return (n);
}
