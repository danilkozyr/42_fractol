/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:00:12 by dkozyr            #+#    #+#             */
/*   Updated: 2019/03/02 16:56:08 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	mlx_hook(WIN, KEYRELEASED, 0, key_release, mlx);ml
**	mlx_hook(WIN, MOUSEPRESSED, 0, mouse_press, mlx);
**	mlx_hook(WIN, MOSUERELEASED, 0, mouse_release, mlx);
**	mlx_hook(WIN, MOUSEMOVED, 0, mouse_move, mlx);
*/

#include "header.h"

void	fractol_init(t_mlx *mlx)
{
	if (ID == 0)
		mandelbrot_init(mlx);
	if (ID == 1)
		julia_init(mlx);
	if (ID == 2)
		burningship_init(mlx);
}

void	*fractol_thr(void *tab)
{
	t_mlx	*mlx;
	int		tmp;

	mlx = (t_mlx *)tab;
	FRACT.x = 0;
	tmp = FRACT.y;
	while (FRACT.x < WIN_WIDTH)
	{
		FRACT.y = tmp;
		while (FRACT.y < FRACT.y_max)
		{
			(ID == 0) ? mandelbrot(mlx) : 0;
			(ID == 1) ? julia(mlx) : 0;
			(ID == 2) ? burningship(mlx) : 0;
			FRACT.y++;
		}
		FRACT.x++;
	}
	return (tab);
}

void	fractol_go(t_mlx *mlx)
{
	t_mlx		tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)mlx, sizeof(t_mlx));
		tab[i].fract.y = THREAD_WIDTH * i;
		tab[i].fract.y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, fractol_thr, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(mlx->ptr, mlx->window, IMG->image, 0, 0);
}

void	allocate_memory(t_mlx *mlx)
{
	PTR = mlx_init();
	WIN = mlx_new_window(PTR, WIN_WIDTH, WIN_HEIGHT, NAME);
	IMG = malloc(sizeof(t_image));
	IMG->image = mlx_new_image(PTR, WIN_WIDTH, WIN_HEIGHT);
	IMG->ptr = mlx_get_data_addr(IMG->image, &IMG->bits_per_pixel,
								&IMG->size_len, &IMG->endian);
	HINT = malloc(sizeof(t_hint));
	HINT->swtch = 0;
	HINT->it_sw = 0;
	FRACT.mouse_sw = 1;
}

int		fractol(char *filename)
{
	t_mlx *mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->filename = filename;
	allocate_memory(mlx);
	fractol_init(mlx);
	fractol_go(mlx);
	mlx_hook(WIN, KEYPRESSED, 0, key_press, mlx);
	mlx_hook(WIN, MOUSEPRESSED, 0, mouse_press, mlx);
	mlx_hook(WIN, MOUSEMOVED, 0, mouse_move, mlx);
	mlx_hook(WIN, REDBUTTONPRESSED, 0, exit_fractol, (void *)0);
	mlx_loop(PTR);
	return (1);
}
