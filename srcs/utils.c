/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:36:07 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:56 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	s_is_digit(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != 0)
	{
		if (ft_isdigit(s1[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_sizeofarray(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

int	width_map(char **map)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > width)
			width = j;
		i++;
	}
	return (width);
}

static int	check_value(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'N' \
	|| map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
		return (0);
	return (1);
}

int	zero_surroundings(char **map, int i, int j)
{
	int	len;

	len = ft_strlen(map[i + 1]);
	if (j > len - 1)
		return (1);
	if (!check_value(map, i, j + 1) && !check_value(map, i, j - 1) \
	&& !check_value(map, i + 1, j) && !check_value(map, i - 1, j))
		return (0);
	return (1);
}
