/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:33:56 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:00:32 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	hex_color(t_cube *cube, char **color, char *msg)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	if (ft_strncmp(msg, "floor", ft_strlen("floor")) == 0)
		cube->flr = create_trgb(00, r, g, b);
	else
		cube->ceil = create_trgb(00, r, g, b);
	return (1);
}

int	color_error(char **color, char *msg)
{
	if (!color || ft_sizeofarray(color) != 3 || !s_is_digit(color[0]) \
	|| !s_is_digit(color[1]) || !s_is_digit(color[2]))
	{
		free_array(color);
		printf("Error\nWrong %s color!", msg);
		return (1);
	}
	return (0);
}
