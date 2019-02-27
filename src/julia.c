/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:59:21 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/27 18:01:14 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	julia_init(t_mlx *mlx)
{
	mlx->it_max = 50;
	mlx->zoom = 200;
	mlx->x1 = -2.0;
	mlx->y1 = -1.9;
	mlx->color = 265;
	mlx->c_r = 0.285;
	mlx->c_i = 0.01;
}

void	julia(t_mlx *mlx)
{
	double	tmp;

	mlx->z_r = mlx->x / mlx->zoom + mlx->x1;
	mlx->z_i = mlx->y / mlx->zoom + mlx->y1;
	mlx->it = 0;
	while (mlx->z_r * mlx->z_r + mlx->z_i
			* mlx->z_i < 4 && mlx->it < mlx->it_max)
	{
		tmp = mlx->z_r;
		mlx->z_r = mlx->z_r * mlx->z_r -
			mlx->z_i * mlx->z_i - 0.8 + (mlx->c_r / WIN_WIDTH);
		mlx->z_i = 2 * mlx->z_i * tmp + mlx->c_i / WIN_WIDTH;
		mlx->it++;
	}
	if (mlx->it == mlx->it_max)
		put_pxl_to_img(mlx, mlx->x, mlx->y, 0x000000);
	else
		put_pxl_to_img(mlx, mlx->x, mlx->y, (mlx->color * mlx->it));
}
