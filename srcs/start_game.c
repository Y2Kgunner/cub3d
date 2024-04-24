/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:36:01 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:48 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_angle(t_cube *cube)
{
	if (cube->dire == 'N')
		cube->a = PI / 2;
	else if (cube->dire == 'S')
		cube->a = 3 * PI / 2;
	else if (cube->dire == 'E')
		cube->a = 0;
	else if (cube->dire == 'W')
		cube->a = PI;
}

void	start_game(t_cube *cube)
{
	cube->width = width_map(cube->map);
	cube->height = ft_sizeofarray(cube->map);
	cube->mlx = mlx_init();
	cube->mlx_win = mlx_new_window(cube->mlx, SWIDTH, SHEIGHT, "Cub3D");
	cube->texte.img = mlx_xpm_file_to_image(cube->mlx, "./images/brick.xpm", \
	&(cube->texte.w), &(cube->texte.h));
	cube->texte.addr = mlx_get_data_addr(cube->texte.img, \
	&cube->texte.bits_per_pixel, &cube->texte.line_length, &cube->texte.endian);
	get_angle(cube);
	ray_casting(cube);
	if (cube->height < HEIGHT / 4 && cube->width < WIDTH / 4)
		draw_minimap(cube);
	mlx_hook(cube->mlx_win, 02, 1L << 0, key_hook, cube);
	mlx_hook(cube->mlx_win, 17, 0, destroy_game, cube);
	mlx_loop(cube->mlx);
}
