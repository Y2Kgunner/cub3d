/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:35:30 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:28 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_spaces(t_cube *cube)
{
	int	i;

	i = 0;
	while (cube->map[i])
	{
		if (ft_strchr(cube->map[i], '1') == NULL)
		{
			printf("Error\nEmpty Line in Map!");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_top_bottom(char *str)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(str);
	while (str && str[j] == ' ')
		j++;
	while (str)
	{
		if (str[j] != '1' && str[j] != ' ')
			break ;
		j++;
	}
	if (j != len)
	{
		printf("Error\nMap not surrounded by walls from top or bottom!");
		return (1);
	}
	return (0);
}

static int	check_lines(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (i < ft_sizeofarray(map))
	{
		j = 0;
		while (map[i] && map[i][j] == ' ')
			j++;
		if (map[i][j] != '1')
		{
			printf("Error\nMap not surrounded by walls from left side!");
			return (1);
		}
		j = ft_strlen(map[i]) - 1;
		while (j != 0 && map[i][j] == ' ')
			j--;
		if (map[i][j] != '1')
		{
			printf("Error\nMap not surrounded by walls from right side!");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_zeros(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (zero_surroundings(map, i, j))
				{
					printf("Error\nMap not surrounded by walls!");
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_boundaries(t_cube *cube)
{
	int	size;

	size = ft_sizeofarray(cube->map) - 1;
	if (check_top_bottom(cube->map[0]) || check_top_bottom(cube->map[size]) \
	|| check_lines(cube->map) || check_zeros(cube->map))
		return (1);
	return (0);
}
