/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:10:48 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/22 12:48:26 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi_color(char *str)
{
	long int	i;
	int			j;
	long int	nb;

	j = 0;
	i = 0;
	nb = 0;
	while (str[j] != '\0')
		j++;
	if (str[j - 1] == ' ')
		j--;
	while (str[j] == ' ')
		j--;
	while (i <= j && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (ft_str_is_numeric(&str[i]) == 0)
		return (-1);
	while (i <= j && ((str[i] >= 48 && str[i] <= 57) || str[i] == ' '))
	{
		if (str[i] == ' ')
			return (-1);
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}	
	return (nb);
}
