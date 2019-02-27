/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:00:12 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/27 18:00:31 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mandelbrot_init(t_mlx *mlx)
{
	mlx->it_max = 50;
	mlx->zoom = 300;
	mlx->x1 = -2.05;
	mlx->y1 = -1.3;
	mlx->color = 265;
}

void	mandelbrot(t_mlx *mlx)
{
	double	tmp;

	mlx->c_r = mlx->x / mlx->zoom + mlx->x1;
	mlx->c_i = mlx->y / mlx->zoom + mlx->y1;
	mlx->z_r = 0;
	mlx->z_i = 0;
	mlx->it = 0;
	while (mlx->z_r * mlx->z_r + mlx->z_i *
			mlx->z_i < 4 && mlx->it < mlx->it_max)
	{
		tmp = mlx->z_r;
		mlx->z_r = mlx->z_r * mlx->z_r -
			mlx->z_i * mlx->z_i + mlx->c_r;
		mlx->z_i = 2 * mlx->z_i * tmp + mlx->c_i;
		mlx->it++;
	}
	if (mlx->it == mlx->it_max)
		put_pxl_to_img(mlx, mlx->x, mlx->y, 0x000000);
	else
		put_pxl_to_img(mlx, mlx->x, mlx->y, (mlx->color * mlx->it));
}
