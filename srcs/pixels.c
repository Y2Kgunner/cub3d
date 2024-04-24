/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:06:16 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:35 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pix(t_data texture, int x, int y)
{
	int		color;
	char	*pixel;

	pixel = texture.addr + (y * texture.line_length + \
	x * (texture.bits_per_pixel / 8));
	color = *(int *)pixel;
	return (color);
}
