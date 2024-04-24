/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:35:44 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:41 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static float	get_distance(t_cube *cube, float angle)
{
	int		flag;
	float	dist;

	flag = 0;
	dist = 0;
	while (flag == 0)
	{
		dist = dist + 0.01;
		cube->testx = cube->x + 0.5 + cosf(angle) * dist;
		cube->testy = cube->y + 0.5 + sinf(angle) * dist;
		if (dist > DEPTH || tcheck(cube, cube->testy, cube->testx) == 1)
		{
			flag = 1;
			break ;
		}
		if (cube->testx < 0 || cube->testy < 0 || \
		cube->map[(int)cube->testy][(int)cube->testx] == '1')
		{
			flag = 1;
			break ;
		}
		cube->testxo = cube->testx;
		cube->testyo = cube->testy;
	}
	return (dist);
}

static void	draw_slice(t_cube *cube, int x, t_data *texture)
{
	int	y;
	int	ytex;

	y = 0;
	ytex = 0;
	if (texture->xtex == texture->w - 1)
		texture->xtex = 0;
	while (y < SHEIGHT)
	{
		if (ytex == texture->h - 1)
			ytex = 0;
		if (y <= cube->ceiheight)
			my_mlx_pixel_put(&cube->img1, x, y, cube->ceil);
		else if (y > cube->ceiheight && y < cube->flrheight)
		{
			cube->color = get_pix(*texture, texture->xtex, ytex);
			my_mlx_pixel_put(&cube->img1, x, y, cube->color);
		}
		else
			my_mlx_pixel_put(&cube->img1, x, y, cube->flr);
		y++;
		ytex++;
	}
}

static void	initiate_image(t_cube *cube)
{
	cube->img1.img = mlx_new_image(cube->mlx, SWIDTH, SHEIGHT);
	cube->img1.addr = mlx_get_data_addr(cube->img1.img, \
	&cube->img1.bits_per_pixel, &cube->img1.line_length, \
	&cube->img1.endian);
	cube->textn.img = mlx_xpm_file_to_image(cube->mlx, cube->north, \
	&cube->textn.w, &cube->textn.h);
	cube->textn.addr = mlx_get_data_addr(cube->textn.img, \
	&cube->textn.bits_per_pixel, &cube->textn.line_length, &cube->textn.endian);
	cube->textn.xtex = 0;
	cube->texts.img = mlx_xpm_file_to_image(cube->mlx, cube->south, \
	&cube->texts.w, &cube->texts.h);
	cube->texts.addr = mlx_get_data_addr(cube->texts.img, \
	&cube->texts.bits_per_pixel, &cube->texts.line_length, &cube->texts.endian);
	cube->texts.xtex = 0;
	cube->texte.img = mlx_xpm_file_to_image(cube->mlx, cube->east, \
	&cube->texte.w, &cube->texte.h);
	cube->texte.addr = mlx_get_data_addr(cube->texte.img, \
	&cube->texte.bits_per_pixel, &cube->texte.line_length, &cube->texte.endian);
	cube->texte.xtex = 0;
	cube->textw.img = mlx_xpm_file_to_image(cube->mlx, cube->west, \
	&cube->textw.w, &cube->textw.h);
	cube->textw.addr = mlx_get_data_addr(cube->textw.img, \
	&cube->textw.bits_per_pixel, &cube->textw.line_length, &cube->textw.endian);
	cube->textw.xtex = 0;
}

static void	reset_xtex(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, \
	cube->img1.img, 0, 0);
	cube->textn.xtex = 0;
	cube->texts.xtex = 0;
	cube->texte.xtex = 0;
	cube->textw.xtex = 0;
}

void	ray_casting(t_cube *cube)
{
	int		x;
	float	angle;
	float	dist;
	t_data	*texture;

	x = 0;
	initiate_image(cube);
	angle = cube->a - FOV / 2;
	while (x < SWIDTH)
	{
		dist = get_distance(cube, angle + (x * cube->inc));
		if (dist < DEPTH)
		{
			dist = dist * cosf(angle + (x * cube->inc) - cube->a) * 1.5;
			texture = find_hit_pt(cube, angle + (x * cube->inc));
			cube->ceiheight = SHEIGHT / 2 - SHEIGHT / dist;
		}
		else
			cube->ceiheight = SHEIGHT / 2;
		cube->flrheight = SHEIGHT - cube->ceiheight;
		draw_slice(cube, x, texture);
		x++;
	}
	reset_xtex(cube);
}
