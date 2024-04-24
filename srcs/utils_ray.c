/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:06:28 by lel-khou          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:51 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	tcheck(t_cube *cube, float y, float x)
{
	if (cube->map[(int)y][(int)x] == ' ' || cube->map[(int)y][(int)x] == '\0')
		return (1);
	return (0);
}

static void	prev_hit(t_cube *cube)
{
	if (cube->hit == 1)
		cube->texts.xtex++;
	if (cube->hit == 2)
		cube->textn.xtex++;
	if (cube->hit == 3)
		cube->texte.xtex++;
	if (cube->hit == 4)
		cube->textw.xtex++;
}

static void	else_if(t_cube *cube, float angle)
{
	if (angle >= PI / 2 && angle <= 3 * PI / 2)
	{
		cube->hit = 3;
		cube->texte.xtex++;
	}
	else
	{
		cube->hit = 4;
		cube->textw.xtex++;
	}
}

static void	find_hit_direc(t_cube *cube, float angle)
{
	if ((int)cube->testx == (int)cube->testxo)
	{
		if ((angle >= 0 && angle <= PI) || (angle >= 2 * PI && angle <= 3 * PI))
		{
			cube->hit = 1;
			cube->texts.xtex++;
		}
		else
		{
			cube->hit = 2;
			cube->textn.xtex++;
		}
	}
	else if ((int)cube->testy == (int)cube->testyo)
		else_if(cube, angle);
	else
		prev_hit(cube);
}

t_data	*find_hit_pt(t_cube *cube, float angle)
{
	find_hit_direc(cube, angle);
	if (cube->hit == 1)
		return (&cube->texts);
	else if (cube->hit == 2)
		return (&cube->textn);
	else if (cube->hit == 3)
		return (&cube->texte);
	else if (cube->hit == 4)
		return (&cube->textw);
	return (&cube->texte);
}
