/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:59:21 by dkozyr            #+#    #+#             */
/*   Updated: 2019/03/02 18:25:07 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	julia_init(t_mlx *mlx)
{
	FRACT.iter_max = 50;
	FRACT.zoom = 204;
	FRACT.x1 = -1.51;
	FRACT.y1 = -1.47;
	FRACT.color = 1285;
	FRACT.c_r = 0.285;
	FRACT.c_i = 0.01;
}

void	julia(t_mlx *mlx)
{
	double	tmp;

	FRACT.z_r = FRACT.x / FRACT.zoom + FRACT.x1;
	FRACT.z_i = FRACT.y / FRACT.zoom + FRACT.y1;
	FRACT.iter = 0;
	while (FRACT.z_r * FRACT.z_r + FRACT.z_i
			* FRACT.z_i < 4 && FRACT.iter < FRACT.iter_max)
	{
		tmp = FRACT.z_r;
		FRACT.z_r = FRACT.z_r * FRACT.z_r -
			FRACT.z_i * FRACT.z_i - 0.8 + (FRACT.c_r / WIN_WIDTH);
		FRACT.z_i = 2 * FRACT.z_i * tmp + FRACT.c_i / WIN_WIDTH;
		FRACT.iter++;
	}
	if (FRACT.iter == FRACT.iter_max)
		put_pxl_to_img(mlx, FRACT.x, FRACT.y, 0x000000);
	else
		put_pxl_to_img(mlx, FRACT.x, FRACT.y, (FRACT.color * FRACT.iter));
}
