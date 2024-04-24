/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:34:48 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:10 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	splittemp(char *str, t_cube *cube)
{
	int	j;

	j = 0;
	cube->file = ft_split_special(str, '\n');
	free (str);
	if (!cube->file)
		ft_error_file("Error\nMalloc Failed!", cube);
	while (cube->file[j] != 0)
		j++;
	cube->filesize = j;
}

static int	sizeofmap(char *str, t_cube *cube)
{
	int		fd;
	int		i;
	char	buff;

	i = 0;
	fd = open(str, O_RDONLY);
	if (cube->fd == -1)
		ft_error_file("Error\nMap can't be accessed!", cube);
	while ((read(fd, &buff, 1)) > 0)
		i++;
	if (i == 0)
	{
		ft_error_file("Error\nNo Map!", cube);
		return (0);
	}
	else
		return (i);
}

int	file_read(char *str, t_cube *cube)
{
	char	*temp;
	int		i;
	char	buff;
	ssize_t	byte;

	byte = 1;
	i = 0;
	cube->fd = open(str, O_RDONLY);
	temp = malloc (sizeof(char) * (sizeofmap(str, cube) + 1));
	if (!temp)
		ft_error_file("Error\nMalloc Failed!", cube);
	while (byte > 0)
	{
		byte = read(cube->fd, &buff, 1);
		if (byte == 0)
			break ;
		temp[i++] = buff;
	}
	temp[i] = '\0';
	splittemp(temp, cube);
	initial_check(cube, cube->file);
	return (0);
}
