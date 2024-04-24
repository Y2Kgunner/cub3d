/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:35:37 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:38 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	player_surroundings(char **map, int i, int j)
{
	if ((map[i][j + 1] == '0' || map[i][j + 1] == '1') && \
	(map[i][j - 1] == '0' || map[i][j - 1] == '1') && \
	(map[i + 1][j] == '0' || map[i + 1][j] == '1') && \
	(map[i - 1][j] == '0' || map[i - 1][j] == '1'))
		return (0);
	return (1);
}

static int	player_location(char **map, t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == cube->dire)
			{
				if (player_surroundings(map, i, j))
				{
					printf("Error\nPlayer Outside the Map!");
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	count_players(char **map, t_cube *cube)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' \
			|| map[i][j] == 'S')
			{
				p++;
				cube->x = j;
				cube->y = i;
				cube->dire = map[i][j];
			}
			j++;
		}
		i++;
	}
	return (p);
}

static int	nb_of_players(t_cube *cube)
{
	if (count_players(cube->map, cube) != 1)
	{
		printf("Error\nMore than one player!");
		return (1);
	}
	return (0);
}

int	player_check(t_cube *cube)
{
	if (nb_of_players(cube) || player_location(cube->map, cube))
		return (1);
	return (0);
}
