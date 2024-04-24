/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:35:02 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:16 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	count_elements(char **file, char *s)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	while (file[i] != 0)
	{
		len = ft_strlen(file[i]) - 1;
		if (ft_strnstr(file[i], s, len) != NULL)
			count++;
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

static int	check_extralines(char **file)
{
	int	i;
	int	len;

	i = 0;
	while (file[i])
	{
		len = ft_strlen(file[i]);
		if (len == 0 || ft_strnstr(file[i], "NO", len) != NULL || \
		ft_strnstr(file[i], "SO", len) != NULL || \
		ft_strnstr(file[i], "EA", len) != NULL || \
		ft_strnstr(file[i], "WE", len) != NULL || \
		ft_strnstr(file[i], "F", len) != NULL || \
		ft_strnstr(file[i], "C", len) != NULL || \
		ft_strnstr(file[i], "1", len) != NULL)
			i++;
		else
			return (1);
	}
	return (0);
}

void	initial_check(t_cube *cube, char **file)
{
	if (count_elements(file, "NO") || count_elements(file, "SO") || \
	count_elements(file, "EA") || count_elements(file, "WE") || \
	count_elements(file, "F") || count_elements(file, "C") || \
	check_extralines(file))
	{
		free_array(cube->file);
		ft_error_file("Error\nWrong File Details", cube);
	}
}
