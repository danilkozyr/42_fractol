/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:59:21 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/26 18:54:26 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	julia(t_mlx *mlx)
{
	mlx_clear_window(PTR, WIN);
	mlx_string_put(PTR, WIN, WIN_WIDTH / 2 - 20, WIN_HEIGHT / 2, AQUA, NAME);
}
