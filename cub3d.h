/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykulkarn <ykulkarn@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:34:08 by ykulkarn          #+#    #+#             */
/*   Updated: 2023/04/07 22:07:23 by ykulkarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "libft/libft.h"
# include <X11/keysym.h>
# define W 13
# define A 0
# define S 1
# define D 2
# define RARROW 124
# define LARROW 123
# define ESC 53
# define WIDTH 310	
# define HEIGHT 180
# define SWIDTH 1920
# define SHEIGHT 1080
# define A30 0.523599
# define A60 1.0472
# define A120 2.0944
# define A150 2.61799
# define A210 3.66519
# define A240 4.18879
# define A300 5.23599
# define A330 5.75959
# define DEPTH 100
# define FOV 1.0471975512
# define PI 3.14159265359

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		h;
	int		w;
	int		endian;
	int		xtex;
}				t_data;

typedef struct s_cube
{
	char	**map;
	char	**file;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*floor;
	char	*ceiling;
	int		flr;
	int		ceil;
	int		fd;
	int		filesize;
	int		x;
	int		y;
	char	dire;
	float	a;
	int		width;
	int		height;
	float	inc;
	float	testx;
	float	testy;
	float	testxo;
	float	testyo;
	int		color;
	int		ceiheight;
	int		flrheight;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	img1;
	t_data	textn;
	t_data	texts;
	t_data	texte;
	t_data	textw;
	int		hit;
	int		square_size;
}				t_cube;

int		error_check(char *str);
void	initializer(t_cube *cube);
int		file_read(char *str, t_cube *cube);
void	initial_check(t_cube *cube, char **file);
void	file_split(t_cube *cube, char **file);
void	file_check(t_cube *cube);
int		hex_color(t_cube *cube, char **color, char *msg);
int		color_error(char **color, char *msg);
int		check_spaces(t_cube *cube);
int		check_boundaries(t_cube *cube);
int		player_check(t_cube *cube);

//-----------------------------GAME------------------------------------------//

void	start_game(t_cube *cube);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_pix(t_data texture, int x, int y);
void	draw_minimap(t_cube *cube);
void	ray_casting(t_cube *cube);
t_data	*find_hit_pt(t_cube *cube, float angle);
int		key_hook(int keycode, t_cube *cube);
int		destroy_game(t_cube *cube);
void	w_move(t_cube *c);
void	s_move(t_cube *c);
void	d_move(t_cube *c);
void	a_move(t_cube *c);
void	w_diag(t_cube *c);
void	s_diag(t_cube *c);
void	d_diag(t_cube *c);
void	a_diag(t_cube *c);

//-----------------------------FREE/EXIT-------------------------------------//

void	ft_error_file(char *str, t_cube *cube);
void	ft_error_map(char *str, t_cube *cube);
void	free_array(char **str);
void	exit_game(t_cube *cube);

//-----------------------------UTILS-----------------------------------------//

int		s_is_digit(char *s1);
int		ft_sizeofarray(char **s);
int		width_map(char **map);
int		zero_surroundings(char **map, int i, int j);
int		check_ext(char *str, char *ext);
int		tcheck(t_cube *cube, float y, float x);
int		texture_ext(t_cube *cube);

#endif
