/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:43:51 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/26 17:05:47 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	change_fractol(int key, t_mlx *mlx)
{
	if (QUOTMARK && ID != 0)
	{
		mlx_clear_window(PTR, WIN);
		NAME = "Mandelbrot";
		ID = 0;
		mandelbrot(mlx);
	}
	else if (BACKSLASH && ID != 1)
	{
		ID = 1;
		NAME = "Julia";
		mlx_clear_window(PTR, WIN);
		julia(mlx);
	}
	else
	{
		printf("colon");
	}
}
