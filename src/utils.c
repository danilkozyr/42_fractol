/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:43:47 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/26 17:05:35 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_file(char *argv)
{
	return (ft_strequ(argv, "Mandelbrot") || ft_strequ(argv, "mandelbrot") ||
			ft_strequ(argv, "0") || ft_strequ(argv, "julia") ||
			ft_strequ(argv, "Julia") || ft_strequ(argv, "1") ||
			ft_strequ(argv, "Smth") || ft_strequ(argv, "smth"));
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
	NAME = ft_strjoin("FRACTAL.  ", NAME);
}

void	fractol_distirbution(t_mlx *mlx)
{
	if (mlx->it_max < 0)
		mlx->it_max = 0;
	if (ID == 0)
	{
		mandelbrot_init(mlx);
		mandelbrot(mlx);
	}
	else if (ID == 1)
		julia(mlx);
}

int		exit_fractol(int err_key, char *err_reason, t_mlx *mlx)
{
	if (err_key == 1)
	{
		ft_putstr_fd("usage: ", STDERR_FILENO);
		ft_putstr_fd("42_fractol", STDERR_FILENO);
		ft_putstr_fd(" [fractals]\n", STDERR_FILENO);
		ft_putstr_fd("Fractals :\n--> Mandelbrot\n", STDERR_FILENO);
		ft_putstr_fd("--> Julia\n--> smth else\n", STDERR_FILENO);
	}
	else if (err_key == 10)
	{
		(void)mlx;
		ft_putendl(err_reason);
	}
	exit(EXIT_SUCCESS);
}
