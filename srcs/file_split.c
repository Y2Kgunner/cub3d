/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:34:56 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:13 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	save_color(t_cube *cube, int i, int j)
{
	char	c;
	int		len;

	c = cube->file[i][j];
	len = ft_strlen(cube->file[i]);
	while (cube->file[i][j] != 0 && ft_isdigit(cube->file[i][j]) == 0)
		j++;
	if (j == len)
		ft_error_file("Error\nNo Color Details!", cube);
	if (c == 'F')
		cube->floor = ft_substr(cube->file[i], j, len - j);
	else
		cube->ceiling = ft_substr(cube->file[i], j, len - j);
	if (!cube->floor && !cube->ceiling)
		ft_error_file("Error\nMalloc Failed!", cube);
	return (len);
}

static int	save_texture(t_cube *cube, int i, int j)
{
	char	c;
	int		len;

	c = cube->file[i][j];
	len = ft_strlen(cube->file[i]);
	while (cube->file[i][j] != 0 && cube->file[i][j] != '.')
		j++;
	if (j == len)
		ft_error_file("Error\nNo Texture Path!", cube);
	if (c == 'N')
		cube->north = ft_substr(cube->file[i], j, len - j);
	else if (c == 'S')
		cube->south = ft_substr(cube->file[i], j, len - j);
	else if (c == 'E')
		cube->east = ft_substr(cube->file[i], j, len - j);
	else if (c == 'W')
		cube->west = ft_substr(cube->file[i], j, len - j);
	if (!cube->west && !cube->east && !cube->south && !cube->north)
		ft_error_file("Error\nMalloc Failed!", cube);
	return (len);
}

static void	save_map(t_cube *cube, int i)
{
	int	j;

	j = 0;
	cube->map = malloc(sizeof(char *) * (cube->filesize - i + 2));
	if (!cube->map)
		ft_error_file("Error\nMalloc Failed!", cube);
	while (i < cube->filesize)
	{
		cube->map[j] = ft_strdup(cube->file[i]);
		if (!cube->map[j])
			ft_error_map("Error\nMalloc Failed!", cube);
		i++;
		j++;
	}
	cube->map[j] = NULL;
}

void	file_split(t_cube *cube, char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j] != 0)
		{
			if (s[i][j] == 'F' || s[i][j] == 'C')
				j = save_color(cube, i, j);
			else if ((s[i][j] == 'N' && s[i][j + 1] == 'O') || (s[i][j] == 'S' \
			&& s[i][j + 1] == 'O') || (s[i][j] == 'W' && s[i][j + 1] == 'E') || \
			(s[i][j] == 'E' && s[i][j + 1] == 'A'))
				j = save_texture(cube, i, j);
			else if (s[i][j] == '1' || s[i][j] == '0')
			{
				save_map(cube, i);
				return ;
			}
			else
				j++;
		}
		i++;
	}
}
