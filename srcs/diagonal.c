/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diagonal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:36:42 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:00:35 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	w_diag(t_cube *c)
{
	if (c->a >= A300 && c->a <= A330 && c->map[c->y - 1][c->x + 1] != '1' \
		&& c->map[c->y][c->x + 1] != '1' && c->map[c->y - 1][c->x] != '1')
	{
		c->x++;
		c->y--;
	}
	else if (c->a >= A210 && c->a <= A240 && c->map[c->y - 1][c->x - 1] != '1' \
			&& c->map[c->y - 1][c->x] != '1' && c->map[c->y][c->x - 1] != '1')
	{
		c->x--;
		c->y--;
	}
	else if (c->a >= A120 && c->a <= A150 && c->map[c->y + 1][c->x - 1] != '1' \
			&& c->map[c->y][c->x - 1] != '1' && c->map[c->y + 1][c->x] != '1' )
	{
		c->x--;
		c->y++;
	}
	else if (c->a >= A30 && c->a <= A60 && c->map[c->y + 1][c->x + 1] != '1' \
			&& c->map[c->y][c->x + 1] != '1' && c->map[c->y + 1][c->x] != '1')
	{
		c->x++;
		c->y++;
	}
}

void	s_diag(t_cube *c)
{
	if (c->a >= A300 && c->a <= A330 && c->map[c->y + 1][c->x - 1] != '1' \
		&& c->map[c->y + 1][c->x] != '1' && c->map[c->y + 1][c->x - 1] != '1')
	{
		c->x--;
		c->y++;
	}
	else if (c->a >= A210 && c->a <= A240 && c->map[c->y + 1][c->x + 1] != '1' \
			&& c->map[c->y + 1][c->x] != '1' && c->map[c->y][c->x + 1] != '1')
	{
		c->x++;
		c->y++;
	}
	else if (c->a >= A120 && c->a <= A150 && c->map[c->y - 1][c->x + 1] != '1' \
			&& c->map[c->y - 1][c->x] != '1' && c->map[c->y][c->x + 1] != '1')
	{
		c->x++;
		c->y--;
	}
	else if (c->a >= A30 && c->a <= A60 && c->map[c->y - 1][c->x - 1] != '1' \
			&& c->map[c->y - 1][c->x] != '1' && c->map[c->y][c->x - 1] != '1')
	{
		c->x--;
		c->y--;
	}
}

void	d_diag(t_cube *c)
{
	if (c->a >= A300 && c->a <= A330 && c->map[c->y + 1][c->x + 1] != \
		'1' && c->map[c->y + 1][c->x] != '1' && c->map[c->y][c->x + 1] != '1')
	{
		c->x++;
		c->y++;
	}
	else if (c->a >= A210 && c->a <= A240 && c->map[c->y - 1][c->x + 1] != '1' \
			&& c->map[c->y - 1][c->x] != '1' && c->map[c->y][c->x + 1] != '1')
	{
		c->x++;
		c->y--;
	}
	else if (c->a >= A120 && c->a <= A150 && c->map[c->y - 1][c->x - 1] != '1' \
			&& c->map[c->y - 1][c->x] != '1' && c->map[c->y][c->x - 1] != '1')
	{
		c->x--;
		c->y--;
	}
	else if (c->a >= A30 && c->a <= A60 && c->map[c->y + 1][c->x - 1] != '1' \
			&& c->map[c->y + 1][c->x] != '1' && c->map[c->y][c->x - 1] != '1')
	{
		c->x--;
		c->y++;
	}
}

void	a_diag(t_cube *c)
{
	if (c->a >= A300 && c->a <= A330 && c->map[c->y - 1][c->x - 1] != '1' \
		&& c->map[c->y - 1][c->x] != '1' && c->map[c->y][c->x - 1] != '1')
	{
		c->x--;
		c->y--;
	}
	else if (c->a >= A210 && c->a <= A240 && c->map[c->y + 1][c->x - 1] != '1' \
			&& c->map[c->y + 1][c->x] != '1' && c->map[c->y][c->x - 1] != '1')
	{
		c->x--;
		c->y++;
	}
	else if (c->a >= A120 && c->a <= A150 && c->map[c->y + 1][c->x + 1] != '1' \
			&& c->map[c->y + 1][c->x] != '1' && c->map[c->y][c->x + 1] != '1')
	{
		c->x++;
		c->y++;
	}
	else if (c->a >= A30 && c->a <= A60 && c->map[c->y - 1][c->x + 1] != '1' \
			&& c->map[c->y - 1][c->x] != '1' && c->map[c->y][c->x + 1] != '1')
	{
		c->x++;
		c->y--;
	}
}
