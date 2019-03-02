/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hints.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:44:02 by dkozyr            #+#    #+#             */
/*   Updated: 2019/03/02 17:36:21 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_hints(t_mlx *mlx)
{
	int y;

	y = -10;
	mlx_string_put(PTR, H_WIN, 10, y += 20, WHITE,
					"~          :     close hints");
	mlx_string_put(PTR, H_WIN, 10, y += 20, WHITE,
					";          :      mandelbrot");
	mlx_string_put(PTR, H_WIN, 10, y += 20, WHITE,
					"'          :           julia");
	mlx_string_put(PTR, H_WIN, 10, y += 20, WHITE,
					"\\          :     burningship");
	mlx_string_put(PTR, H_WIN, 10, y += 20, WHITE,
					"esc        :   close fractol");
	mlx_string_put(PTR, H_WIN, 10, y += 20, WHITE,
					"q - i      :   change colors");
	mlx_string_put(PTR, H_WIN, 10, y += 20, WHITE,
					"enter      :   reset fractol");
	mlx_string_put(PTR, H_WIN, 10, y += 20, WHITE,
					"arrows     :    move fractol");
	mlx_string_put(PTR, H_WIN, 10, y += 20, WHITE,
					"mouseclick :      mouse mode");
	mlx_string_put(PTR, H_WIN, 10, y += 20, WHITE,
					"scroll  +\\-:    zoom fractol");
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
