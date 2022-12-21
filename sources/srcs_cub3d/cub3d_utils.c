/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanasse <amanasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:45:17 by amanasse          #+#    #+#             */
/*   Updated: 2022/12/21 13:36:37 by amanasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void print_tab(char **tab)
{
    int i;

    i = 0;
	if (tab)
	{
    	while (tab[i] != NULL)
    	{
    	    printf ("tab[%d] = %s\n", i, tab[i]);
    	    i++;
    	}
	}    
}

char    *ft_dup_solong(char *s, int len)
{
    int        j;
    char    *dup;

    j = 0;
    dup = malloc(sizeof(char) * (len + 1));
    if (dup == NULL)
        return (0);
    while (s[j] && s[j] != '\n')
    {
        dup[j] = s[j];
        j++;
    }
    if (s[j] == '\n' || s[j] == '\0')
        dup[j] = '\0';
    return (dup);
}

void	ft_memset_cub3d(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

    if (s)
    {
	    i = 0;
	    str = s;
	    while (i < n)
	    {
	    	str[i] = c;
	    	i++;
	    }
    }
}

int	ft_strlen_cub3d(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] < s2[i])
		return (-1);
	else
		return (1);
}
