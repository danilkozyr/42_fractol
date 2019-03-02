/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:06:32 by dkozyr            #+#    #+#             */
/*   Updated: 2019/03/02 18:25:29 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	burningship_init(t_mlx *mlx)
{
	FRACT.iter_max = 50;
	FRACT.zoom = 180;
	FRACT.x1 = -2.07;
	FRACT.y1 = -2.21;
	FRACT.color = 1285;
}

void	burningship(t_mlx *mlx)
{
	double tmp;

	FRACT.c_r = FRACT.x / FRACT.zoom + FRACT.x1;
	FRACT.c_i = FRACT.y / FRACT.zoom + FRACT.y1;
	FRACT.z_r = 0;
	FRACT.z_i = 0;
	FRACT.iter = 0;
	while (FRACT.z_r * FRACT.z_r + FRACT.z_i * FRACT.z_i < 4
			&& FRACT.iter < FRACT.iter_max)
	{
		tmp = FRACT.z_r * FRACT.z_r - FRACT.z_i * FRACT.z_i + FRACT.c_r;
		FRACT.z_i = fabs(2 * FRACT.z_r * FRACT.z_i) + FRACT.c_i;
		FRACT.z_r = tmp;
		FRACT.iter++;
	}
	if (FRACT.iter == FRACT.iter_max)
		put_pxl_to_img(mlx, FRACT.x, FRACT.y, 0x000000);
	else
		put_pxl_to_img(mlx, FRACT.x, FRACT.y, (FRACT.color * FRACT.iter));
}
