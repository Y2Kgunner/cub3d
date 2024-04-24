/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:34:16 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:00:39 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_ext(char *str, char *ext)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = malloc (sizeof(char) * 5);
	if (!ptr)
	{
		free (ptr);
		printf("Error\nMalloc Failed!\n");
		return (1);
	}
	j = ft_strlen(str) - 4;
	i = 0;
	while (str[j] != 0)
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	if (ft_strncmp(ptr, ext, 5) != 0)
	{
		free (ptr);
		printf("Error\nWrong extension!\n");
		return (1);
	}
	free(ptr);
	return (0);
}

int	texture_ext(t_cube *c)
{
	if (check_ext(c->north, ".xpm\0") == 1 || \
	check_ext(c->south, ".xpm\0") == 1 || \
	check_ext(c->east, ".xpm\0") == 1 || \
	check_ext(c->west, ".xpm\0") == 1)
		return (1);
	return (0);
}

static int	check_dir(char *str)
{
	if (open(str, O_DIRECTORY) != -1)
	{
		printf("Error\nMap file is a directory!\n");
		return (1);
	}
	return (0);
}

int	error_check(char *str)
{
	if (!check_ext(str, ".cub\0") && !check_dir(str))
		return (0);
	else
		return (1);
}
