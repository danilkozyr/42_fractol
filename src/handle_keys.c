/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:18:36 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/26 18:58:43 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		key_press(int key, t_mlx *mlx)
{
	if (ESC)
		exit_fractol(10, "ESC is pressed", mlx);
	if (UP || DOWN || LEFT || RIGHT)
		move(key, mlx);
	if (PLUS || MINUS || PLUSS || MINUSS)
		mlx_string_put(PTR, WIN, 20, 40, AQUA, "MINUS || PLUS");
	if (QUOTMARK || BACKSLASH || COLON)
		change_fractol(key, mlx);
	if (TILDA)
		hints(mlx);
	if (ENTER)
		reset_fractol(mlx);
	if (Q || W || E || R || T || Y || U || I)
		change_colors(key, mlx);
	mandelbrot(mlx);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (SCROLL_UP || SCROLL_DOWN)
		zoom(button, x, y, mlx);
	mandelbrot(mlx);
	return (0);
}
