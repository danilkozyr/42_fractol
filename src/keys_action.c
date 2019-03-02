/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:43:51 by dkozyr            #+#    #+#             */
/*   Updated: 2019/03/02 18:25:18 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	change_colors(int key, t_mlx *mlx)
{
	int i;

	i = 0;
	if (Q)
		FRACT.color = 1285;
	if (W)
		FRACT.color = 1677216;
	if (E)
		FRACT.color = 264686;
	if (R)
		FRACT.color = 1444368;
	if (T)
		FRACT.color = 6234656;
	if (Y)
		FRACT.color = -423403200;
	if (U)
		FRACT.color += 5000;
	if (I)
		FRACT.color -= 5000;
}

void	change_fractol(int key, t_mlx *mlx)
{
	if (COLON && ID != 0)
	{
		NAME = "Mandelbrot";
		ID = 0;
		mlx_clear_window(PTR, WIN);
		mandelbrot_init(mlx);
		mandelbrot(mlx);
	}
	else if (QUOTMARK && ID != 1)
	{
		ID = 1;
		NAME = "Julia";
		mlx_clear_window(PTR, WIN);
		julia_init(mlx);
		julia(mlx);
	}
	else if (BACKSLASH && ID != 2)
	{
		ID = 2;
		NAME = "Burningship";
		mlx_clear_window(PTR, WIN);
		burningship_init(mlx);
		burningship(mlx);
	}
}

void	zoom(int key, int x, int y, t_mlx *mlx)
{
	if (FRACT.iter_max == 30)
		return ;
	if (key == 5 || PLUS || PLUSS)
	{
		FRACT.x1 = (x / FRACT.zoom + FRACT.x1) - (x / (FRACT.zoom * 1.2));
		FRACT.y1 = (y / FRACT.zoom + FRACT.y1) - (y / (FRACT.zoom * 1.2));
		FRACT.zoom = FRACT.zoom * 1.2;
		FRACT.iter_max++;
	}
	else if (key == 4 || MINUS || MINUSS)
	{
		FRACT.x1 = (x / FRACT.zoom + FRACT.x1) - (x / (FRACT.zoom / 1.2));
		FRACT.y1 = (y / FRACT.zoom + FRACT.y1) - (y / (FRACT.zoom / 1.2));
		FRACT.zoom = FRACT.zoom / 1.2;
		FRACT.iter_max--;
	}
}

void	move(int key, t_mlx *mlx)
{
	if (UP)
		FRACT.y1 = FRACT.y1 - 15 / FRACT.zoom;
	else if (DOWN)
		FRACT.y1 = FRACT.y1 + 15 / FRACT.zoom;
	else if (LEFT)
		FRACT.x1 = FRACT.x1 - 15 / FRACT.zoom;
	else if (RIGHT)
		FRACT.x1 = FRACT.x1 + 15 / FRACT.zoom;
}

void	reset_fractol(t_mlx *mlx)
{
	if (ID == 0)
		mandelbrot_init(mlx);
	if (ID == 1)
		julia_init(mlx);
	if (ID == 2)
		burningship_init(mlx);
}
