/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:42:51 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/26 19:01:06 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include "pthread.h"

# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define HINT_WIDTH 300
# define HINT_HEIGHT 300
# define WIN_NAME "42 FRACTOL"

# define THREAD_WIDTH 5
# define THREAD_NUMBER 120

# define KEYPRESSED 2
# define KEYRELEASED 3
# define MOUSEPRESSED 4
# define MOSUERELEASED 5
# define MOUSEMOVED 6
# define REDBUTTONPRESSED 17

# define WHITE 0xFFFFFF
# define RED 0xCA2300
# define YELLOW 0xDED80C
# define BLUE 0x1A71D5
# define GREEN 0x11AD22
# define AQUA 0x00FFFF
# define BLACK 0x000000

# define ESC key == 53
# define TILDA key == 10
# define ENTER key == 36

# define UP key == 126
# define DOWN key == 125
# define LEFT key == 123
# define RIGHT key == 124

# define PLUS key == 24
# define PLUSS key == 69
# define MINUS key == 27
# define MINUSS key == 78

# define QUOTMARK key == 39
# define BACKSLASH key == 42
# define COLON key == 41

# define SCROLL_UP button == 4
# define SCROLL_DOWN button == 5

# define Q key == 12
# define W key == 13
# define E key == 14
# define R key == 15
# define T key == 17
# define Y key == 16
# define U key == 32
# define I key == 34

# define NAME mlx->filename
# define ID mlx->id
# define PTR mlx->ptr

# define HINT mlx->hint
# define H_WIN mlx->hint->window

# define WIN mlx->window
# define IMG mlx->image

# define FRACT mlx->fract

typedef struct	s_image
{
	void		*ptr;
	void		*image;
	int			bits_per_pixel;
	int			size_len;
	int			endian;
	char		*color;
}				t_image;

typedef struct	s_hint
{
	void		*window;
	char		*ptr;
	int			swtch;
}				t_hint;

typedef struct	s_mlx
{
	int			id;
	char		*filename;
	void		*window;
	char		*ptr;
	t_hint		*hint;
	t_image		*image;

	int			color;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	double		zoom;
	double		x1;
	double		y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
}				t_mlx;

int				fractol(char *filename);

void			fractol_distirbution(t_mlx *mlx);
void			create_title(char *filename, t_mlx *mlx);
int				exit_fractol(int err_key, char *err_reason, t_mlx *mlx);
int				check_file(char *argv);
void			hints(t_mlx *mlx);

void			change_fractol(int key, t_mlx *mlx);

void			mandelbrot(t_mlx *mlx);
void			mandelbrot_init(t_mlx *mlx);

void			julia(t_mlx *mlx);

int				key_press(int key, t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);

void			reset_fractol(t_mlx *mlx);
void			move(int key, t_mlx *mlx);
void			zoom(int key, int x, int y, t_mlx *mlx);
void			change_colors(int key, t_mlx *mlx);

#endif
