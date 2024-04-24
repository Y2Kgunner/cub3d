/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:35:50 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:44 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_square(t_cube *cube, int x, int y, int color)
{
	int	i;
	int	j;

	i = x * cube->square_size;
	while (i < cube->square_size + x * cube->square_size - 1)
	{
		j = y * cube->square_size;
		while (j < cube->square_size + y * cube->square_size - 1)
		{
			my_mlx_pixel_put(&cube->img, j, i, color);
			j++;
		}
		i++;
	}
}

static void	draw_player(t_cube *cube, int x, int y, int color)
{
	float	x1;
	float	y1;
	float	l;

	l = 0;
	draw_square(cube, y, x, color);
	x = x * cube->square_size + cube->square_size / 2 - 1;
	y = y * cube->square_size + cube->square_size / 2 - 1;
	while (l <= cube->square_size * 1.3)
	{
		x1 = x + l * cosf(cube->a);
		y1 = y + l * sinf(cube->a);
		my_mlx_pixel_put(&cube->img, x1, y1, color);
		l = l + 0.2;
	}
}

static void	draw_blocks(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i])
	{
		j = 0;
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == '1')
				draw_square(cube, i, j, 0X00FFFFFF);
			j++;
		}
		i++;
	}
	draw_player(cube, cube->x, cube->y, 0X00FF0000);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, \
	cube->img.img, 0, 0);
}

void	draw_minimap(t_cube *cube)
{
	if (WIDTH / cube->width > HEIGHT / cube->height)
		cube->square_size = HEIGHT / cube->height;
	else
		cube->square_size = WIDTH / cube->width;
	cube->img.img = mlx_new_image(cube->mlx, WIDTH, HEIGHT);
	cube->img.addr = mlx_get_data_addr(cube->img.img, \
	&cube->img.bits_per_pixel, &cube->img.line_length, \
	&cube->img.endian);
	draw_blocks(cube);
}
