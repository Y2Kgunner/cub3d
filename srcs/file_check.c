/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:34:41 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:07 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_path(t_cube *cube)
{
	if (open(cube->north, O_DIRECTORY) != -1 || open(cube->south, O_DIRECTORY) \
	!= -1 || open(cube->east, O_DIRECTORY) != -1 || open(cube->west, \
	O_DIRECTORY) != -1)
	{
		printf("Error\nTexture path is a directory!");
		return (1);
	}
	if (open(cube->north, O_RDONLY) == -1 || open(cube->south, O_RDONLY) \
	== -1 || open(cube->east, O_RDONLY) == -1 || open(cube->west, \
	O_RDONLY) == -1)
	{
		printf("Error\nTexture path can't be accessed!");
		return (1);
	}
	if (texture_ext(cube) == 1)
	{
		printf("Texture is not xpm file");
		return (1);
	}
	return (0);
}

static int	check_color_ceiling(t_cube *cube)
{
	char	**ceiling;

	ceiling = ft_split(cube->ceiling, ',');
	if (color_error(ceiling, "Ceiling") == 1)
		return (1);
	if (!hex_color(cube, ceiling, "ceiling"))
	{
		printf("Error\nWrong ceiling color!");
		return (1);
	}
	free_array(ceiling);
	return (0);
}

static int	check_color_floor(t_cube *cube)
{
	char	**floor;

	floor = ft_split(cube->floor, ',');
	if (color_error(floor, "Floor") == 1)
		return (1);
	if (!hex_color(cube, floor, "floor"))
	{
		printf("Error\nWrong floor color!");
		return (1);
	}
	free_array(floor);
	return (0);
}

static int	check_map(t_cube *cube)
{
	if (check_spaces(cube) || check_boundaries(cube))
		return (1);
	return (0);
}

void	file_check(t_cube *cube)
{
	if (!cube->north || !cube->south || !cube->east || !cube->west || \
	!cube->ceiling || !cube->floor || !cube->map)
		ft_error_map("Error\nMissing Data from file!", cube);
	if (check_map(cube) || check_path(cube) || check_color_ceiling(cube) || \
	check_color_floor(cube) || player_check(cube))
		ft_error_map("", cube);
	free_array(cube->file);
	free(cube->floor);
	free(cube->ceiling);
}
