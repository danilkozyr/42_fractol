/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:43:47 by dkozyr            #+#    #+#             */
/*   Updated: 2019/03/02 18:28:16 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_file(char *argv)
{
	return (ft_strequ(argv, "Mandelbrot") || ft_strequ(argv, "mandelbrot") ||
			ft_strequ(argv, "julia") || ft_strequ(argv, "Julia") ||
			ft_strequ(argv, "Burningship") || ft_strequ(argv, "burningship"));
}

int		fractol_dist(t_mlx *mlx)
{
	if (ft_strequ(mlx->filename, "Mandelbrot"))
		ID = 0;
	else if (ft_strequ(mlx->filename, "julia"))
		ID = 1;
	else if (ft_strequ(mlx->filename, "burningship"))
		ID = 2;
	return (ID);
}

void	free_memory(t_mlx *mlx)
{
	if (mlx)
	{
		if (HINT)
			free(HINT);
		if (IMG->image)
			mlx_destroy_image(PTR, IMG->image);
		if (IMG)
			free(IMG);
		free(mlx);
	}
}

int		exit_fractol(int err_key, char *err_reason, t_mlx *mlx)
{
	if (err_key == 1)
	{
		ft_putstr_fd("usage: ", STDERR_FILENO);
		ft_putstr_fd("42_fractol", STDERR_FILENO);
		ft_putstr_fd(" [fractals]\n", STDERR_FILENO);
		ft_putstr_fd("Fractals :\n--> Mandelbrot\n", STDERR_FILENO);
		ft_putstr_fd("--> Julia\n--> Burningship\n", STDERR_FILENO);
	}
	else if (err_key == 10)
		ft_putendl(err_reason);
	free_memory(mlx);
	exit(EXIT_SUCCESS);
}

void	put_pxl_to_img(t_mlx *mlx, int x, int y, int color)
{
	if (FRACT.x < WIN_WIDTH && FRACT.y < WIN_WIDTH)
	{
		color = mlx_get_color_value(mlx->ptr, color);
		ft_memcpy(IMG->ptr + 4 * WIN_WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}
