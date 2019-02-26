/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:00:12 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/26 18:52:46 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_pxl_to_img(t_mlx *mlx, int x, int y, int color)
{
	if (mlx->x < WIN_WIDTH && mlx->y < WIN_WIDTH)
	{
		color = mlx_get_color_value(mlx->ptr, color);
		ft_memcpy(IMG->ptr + 4 * WIN_WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	mandelbrot_init(t_mlx *mlx)
{
	mlx->it_max = 50;
	mlx->zoom = 300;
	mlx->x1 = -2.05;
	mlx->y1 = -1.3;
	mlx->color = 265;
}

void	mandelbrot_calc(t_mlx *mlx)
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

void	*mandelbrot_thr(void *tab)
{
	t_mlx	*mlx;
	int		tmp;

	mlx = (t_mlx *)tab;
	mlx->x = 0;
	tmp = mlx->y;
	while (mlx->x < WIN_WIDTH)
	{
		mlx->y = tmp;
		while (mlx->y < mlx->y_max)
		{
			mandelbrot_calc(mlx);
			mlx->y++;
		}
		mlx->x++;
	}
	return (tab);
}

void	mandelbrot(t_mlx *mlx)
{
	t_mlx		tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)mlx, sizeof(t_mlx));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot_thr, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(mlx->ptr, mlx->window, IMG->image, 0, 0);
}
