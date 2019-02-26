/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hints.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:44:02 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/26 14:56:58 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_hints(t_mlx *mlx)
{
	mlx_string_put(PTR, H_WIN, 10, 10, WHITE, "~          :     close hints");
	mlx_string_put(PTR, H_WIN, 10, 30, WHITE, "ESC        :   close fractol");
	mlx_string_put(PTR, H_WIN, 10, 50, WHITE, "ARROWS     :    move fractol");
	mlx_string_put(PTR, H_WIN, 10, 70, WHITE, "'          :           JULIA");
	mlx_string_put(PTR, H_WIN, 10, 90, WHITE, "\\          :      MANDELBROT");
}

void	draw_border(t_mlx *mlx)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++y <= 300)
		mlx_pixel_put(PTR, H_WIN, 0, y, WHITE);
	while (++x < 299)
		mlx_pixel_put(PTR, H_WIN, x, HINT_HEIGHT - 1, WHITE);
	while (--y >= 0)
		mlx_pixel_put(PTR, H_WIN, x, y, WHITE);
}

void	init_hint(t_mlx *mlx)
{
	H_WIN = mlx_new_window(PTR, HINT_WIDTH, HINT_HEIGHT, "hints");
	mlx_clear_window(PTR, H_WIN);
	draw_border(mlx);
	display_hints(mlx);
	mlx_hook(H_WIN, KEYPRESSED, 0, key_press, mlx);
}

void	hints(t_mlx *mlx)
{
	if (HINT->swtch == 0)
	{
		HINT->swtch = 1;
		init_hint(mlx);
	}
	else if (HINT->swtch == 1)
	{
		HINT->swtch = 0;
		mlx_clear_window(PTR, H_WIN);
		mlx_destroy_window(PTR, H_WIN);
	}
}
