/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:18:36 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/27 18:07:23 by dkozyr           ###   ########.fr       */
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
		zoom(key, WIN_WIDTH / 2, WIN_HEIGHT / 2, mlx);
	if (QUOTMARK || BACKSLASH || COLON)
		change_fractol(key, mlx);
	if (TILDA)
		hints(mlx);
	if (ENTER)
		reset_fractol(mlx);
	if (Q || W || E || R || T || Y || U || I)
		change_colors(key, mlx);
	fractol_go(mlx);
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	if (ID == 1 && mlx->mouse_sw == 1)
	{
		mlx->c_r = x * 2;
		mlx->c_i = y * 2 - 800;
	}
	fractol_go(mlx);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (SCROLL_UP || SCROLL_DOWN)
		zoom(button, x, y, mlx);
	if ((button == 1 || button == 2) && ID == 1)
	{
		if (mlx->mouse_sw == 1)
			mlx->mouse_sw = 0;
		else if (mlx->mouse_sw == 0)
			mlx->mouse_sw = 1;
	}
	fractol_go(mlx);
	return (0);
}
