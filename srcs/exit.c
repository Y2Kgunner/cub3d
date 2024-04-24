/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:34:34 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:03 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_file(char *str, t_cube *cube)
{
	printf("%s\n", str);
	if (cube)
	{
		free(cube);
	}
	exit(1);
}

void	ft_error_map(char *str, t_cube *cube)
{
	printf("%s\n", str);
	if (cube)
	{
		if (cube->file)
			free_array(cube->file);
		if (cube->map)
			free_array(cube->map);
		if (cube->floor)
			free(cube->floor);
		if (cube->ceiling)
			free(cube->ceiling);
		if (cube->north)
			free(cube->north);
		if (cube->south)
			free(cube->south);
		if (cube->east)
			free(cube->east);
		if (cube->west)
			free(cube->west);
		free(cube);
	}
	exit(1);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		free (str);
		str = NULL;
	}
}

void	exit_game(t_cube *cube)
{
	if (cube)
	{
		if (cube->map)
			free_array(cube->map);
		if (cube->north)
			free(cube->north);
		if (cube->south)
			free(cube->south);
		if (cube->east)
			free(cube->east);
		if (cube->west)
			free(cube->west);
		free(cube);
	}
	exit(0);
}
