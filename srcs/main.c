/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:35:24 by ykulkarn          #+#    #+#             */
/*   Updated: 2024/04/25 02:01:25 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;

	if (argc == 2)
	{
		if (error_check(argv[1]) != 0)
			return (1);
		cube = malloc(sizeof(t_cube));
		if (!cube)
			ft_error_file("Error\nMalloc Failed!", cube);
		initializer(cube);
		file_read(argv[1], cube);
		file_split(cube, cube->file);
		file_check(cube);
		start_game(cube);
	}
	else
		printf("Error\nWrong Number of Arguments!\n");
}
