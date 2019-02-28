/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:43:51 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/28 16:45:09 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	change_colors(int key, t_mlx *mlx)
{
	int i;

	i = 0;
	if (Q)
		mlx->color = 1285;
	if (W)
		mlx->color = 1677216;
	if (E)
		mlx->color = 264686;
	if (R)
		mlx->color = 1444368;
	if (T)
		mlx->color = 6234656;
	if (Y)
		mlx->color = -423403200;
	if (U)
		mlx->color += 5000;
	if (I)
		mlx->color -= 5000;
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
	if (key == 5 || PLUS || PLUSS)
	{
		mlx->x1 = (x / mlx->zoom + mlx->x1) - (x / (mlx->zoom * 1.2));
		mlx->y1 = (y / mlx->zoom + mlx->y1) - (y / (mlx->zoom * 1.2));
		mlx->zoom = mlx->zoom * 1.2;
		mlx->it_max++;
	}
	else if (key == 4 || MINUS || MINUSS)
	{
		mlx->x1 = (x / mlx->zoom + mlx->x1) - (x / (mlx->zoom / 1.2));
		mlx->y1 = (y / mlx->zoom + mlx->y1) - (y / (mlx->zoom / 1.2));
		mlx->zoom = mlx->zoom / 1.2;
		mlx->it_max--;
	}
}

void	move(int key, t_mlx *mlx)
{
	if (DOWN)
		mlx->y1 = mlx->y1 - 15 / mlx->zoom;
	else if (UP)
		mlx->y1 = mlx->y1 + 15 / mlx->zoom;
	else if (RIGHT)
		mlx->x1 = mlx->x1 - 15 / mlx->zoom;
	else if (LEFT)
		mlx->x1 = mlx->x1 + 15 / mlx->zoom;
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
