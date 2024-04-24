/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:35:15 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:22 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	destroy_frame(t_cube *cube)
{
	if (cube->height < HEIGHT / 4 && cube->width < WIDTH / 4)
		mlx_destroy_image(cube->mlx, cube->img.img);
	mlx_destroy_image(cube->mlx, cube->img1.img);
	mlx_destroy_image(cube->mlx, cube->textn.img);
	mlx_destroy_image(cube->mlx, cube->texts.img);
	mlx_destroy_image(cube->mlx, cube->texte.img);
	mlx_destroy_image(cube->mlx, cube->textw.img);
}

int	destroy_game(t_cube *cube)
{
	destroy_frame(cube);
	mlx_clear_window(cube->mlx, cube->mlx_win);
	mlx_destroy_window(cube->mlx, cube->mlx_win);
	exit_game(cube);
	return (0);
}

void	key_move_hook(int keycode, t_cube *cube)
{
	if (keycode == XK_w)
		if (cube->y - 1 >= 0)
			w_move(cube);
	if (keycode == XK_s)
	{
		if (cube->y + 1 <= cube->height)
			s_move(cube);
	}
	if (keycode == XK_a)
	{
		if (cube->x - 1 >= 0)
			a_move(cube);
	}
	if (keycode == XK_d)
	{
		if (cube->x + 1 <= cube->width)
			d_move(cube);
	}
}

int	key_hook(int keycode, t_cube *cube)
{
	if (keycode == XK_Escape)
		destroy_game(cube);
	if (keycode == XK_Right)
	{
		cube->a += 11.25 * PI / 180;
		if (cube->a >= 2 * PI)
			cube->a = 0;
	}
	if (keycode == XK_Left)
	{
		cube->a -= 11.25 * PI / 180;
		if (cube->a < 0)
			cube->a = 2 * PI - 11.25 * PI / 180;
	}
	else
		key_move_hook(keycode, cube);
	destroy_frame(cube);
	ray_casting(cube);
	if (cube->height < HEIGHT / 4 && cube->width < WIDTH / 4)
		draw_minimap(cube);
	return (0);
}
