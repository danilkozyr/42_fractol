/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:42:51 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/22 18:13:15 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define WIN_WIDTH 1900
# define WIN_HEIGHT 1100
# define WIN_NAME "42 FRACTOL"

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
# define UP key == 126
# define DOWN key == 125
# define LEFT key == 123
# define RIGHT key == 124
# define PLUS key == 24
# define PLUSS key == 69
# define MINUS key == 27
# define MINUSS key == 78

# define NAME mlx->filename
# define ID mlx->id
# define PTR mlx->ptr
# define WIN mlx->window
# define IMG mlx->image

typedef struct	s_image
{
	void		*ptr;
	void		*image;
	int			bits_per_pixel;
	int			size_len;
	int			endian;
}				t_image;

typedef struct	s_mlx
{
	int			id;
	char		*filename;
	void		*window;
	char		*ptr;
	t_image		*image;
}				t_mlx;

int				fractol(char *filename);

void			fractol_distirbution(t_mlx *mlx);
void			create_title(char *filename, t_mlx *mlx);
int				exit_fractol(int err_key, char *err_reason, t_mlx *mlx);
int				check_file(char *argv);

void			mandelbrot(t_mlx *mlx);
void			julia(t_mlx *mlx);

int				key_press(int key, t_mlx *mlx);

#endif
