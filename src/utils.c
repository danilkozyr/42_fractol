/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:43:47 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/28 15:33:59 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_file(char *argv)
{
	return (ft_strequ(argv, "Mandelbrot") || ft_strequ(argv, "mandelbrot") ||
			ft_strequ(argv, "0") || ft_strequ(argv, "julia") ||
			ft_strequ(argv, "Julia") || ft_strequ(argv, "1") ||
			ft_strequ(argv, "Burningship") || ft_strequ(argv, "burningship") ||
			ft_strequ(argv, "2"));
}

void	create_title(char *filename, t_mlx *mlx)
{
	if (ft_strequ(filename, "Mandelbrot") ||
		ft_strequ(filename, "mandelbrot") ||
		ft_strequ(filename, "0"))
	{
		NAME = "Mandelbrot";
		ID = 0;
	}
	else if (ft_strequ(filename, "Julia") ||
			ft_strequ(filename, "julia") ||
			ft_strequ(filename, "1"))
	{
		ID = 1;
		NAME = "Julia";
	}
	else if (ft_strequ(filename, "Burningship") ||
			ft_strequ(filename, "burningship") ||
			ft_strequ(filename, "2"))
	{
		ID = 2;
		NAME = "Burningship";
	}
	NAME = ft_strjoin("FRACTAL.  ", NAME);
}

void	fractol_init(t_mlx *mlx)
{
	if (ID == 0)
		mandelbrot_init(mlx);
	if (ID == 1)
		julia_init(mlx);
	if (ID == 2)
		burningship_init(mlx);
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
	{
		(void)mlx;
		ft_putendl(err_reason);
	}
	exit(EXIT_SUCCESS);
}

void	put_pxl_to_img(t_mlx *mlx, int x, int y, int color)
{
	if (mlx->x < WIN_WIDTH && mlx->y < WIN_WIDTH)
	{
		color = mlx_get_color_value(mlx->ptr, color);
		ft_memcpy(IMG->ptr + 4 * WIN_WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}
