/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:00:12 by dkozyr            #+#    #+#             */
/*   Updated: 2019/03/02 16:51:39 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mandelbrot_init(t_mlx *mlx)
{
	FRACT.it_max = 50;
	FRACT.zoom = 225;
	FRACT.x1 = -2.11;
	FRACT.y1 = -1.36;
	FRACT.color = 1285;
}

void	mandelbrot(t_mlx *mlx)
{
	double	tmp;

	FRACT.c_r = FRACT.x / FRACT.zoom + FRACT.x1;
	FRACT.c_i = FRACT.y / FRACT.zoom + FRACT.y1;
	FRACT.z_r = 0;
	FRACT.z_i = 0;
	FRACT.it = 0;
	while (FRACT.z_r * FRACT.z_r + FRACT.z_i *
			FRACT.z_i < 4 && FRACT.it < FRACT.it_max)
	{
		tmp = FRACT.z_r;
		FRACT.z_r = FRACT.z_r * FRACT.z_r -
			FRACT.z_i * FRACT.z_i + FRACT.c_r;
		FRACT.z_i = 2 * FRACT.z_i * tmp + FRACT.c_i;
		FRACT.it++;
	}
	if (FRACT.it == FRACT.it_max)
		put_pxl_to_img(mlx, FRACT.x, FRACT.y, 0x000000);
	else
		put_pxl_to_img(mlx, FRACT.x, FRACT.y, (FRACT.color * FRACT.it));
}
