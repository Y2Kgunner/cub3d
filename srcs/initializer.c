/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:35:07 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:19 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initializer(t_cube *cube)
{
	cube->north = NULL;
	cube->south = NULL;
	cube->east = NULL;
	cube->west = NULL;
	cube->ceiling = NULL;
	cube->floor = NULL;
	cube->inc = FOV / SWIDTH;
}
