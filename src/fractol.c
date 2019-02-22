/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:00:12 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/22 18:13:56 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	mlx_hook(WIN, KEYRELEASED, 0, key_release, mlx);ml
**	mlx_hook(WIN, MOUSEPRESSED, 0, mouse_press, mlx);
**	mlx_hook(WIN, MOSUERELEASED, 0, mouse_release, mlx);
**	mlx_hook(WIN, MOUSEMOVED, 0, mouse_move, mlx);
*/

#include "header.h"

void	allocate_memory(t_mlx *mlx)
{
	PTR = mlx_init();
	WIN = mlx_new_window(PTR, WIN_WIDTH, WIN_HEIGHT, NAME);
	IMG = malloc(sizeof(t_image));
	IMG->image = mlx_new_image(PTR, WIN_WIDTH, WIN_HEIGHT);
	IMG->ptr = mlx_get_data_addr(IMG->image, &IMG->bits_per_pixel,
								&IMG->size_len, &IMG->endian);
	IMG->bits_per_pixel /= 8;
}

int		fractol(char *filename)
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx));
	create_title(filename, mlx);
	allocate_memory(mlx);
	fractol_distirbution(mlx);
	mlx_hook(WIN, KEYPRESSED, 0, key_press, mlx);
	mlx_hook(WIN, REDBUTTONPRESSED, 0, exit_fractol, (void *)0);
	mlx_loop(PTR);
	return (1);
}
