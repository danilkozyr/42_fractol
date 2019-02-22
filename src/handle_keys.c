/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:18:36 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/22 18:00:48 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		key_press(int key, t_mlx *mlx)
{
	if (ESC)
		exit_fractol(10, "ESC is pressed", mlx);
	if (UP || DOWN || LEFT || RIGHT)
		mlx_string_put(PTR, WIN, 20, 20, AQUA, "UP/DOWN/LEFT/RIGHT");
	if (PLUS || MINUS || PLUSS || MINUSS)
		mlx_string_put(PTR, WIN, 20, 40, AQUA, "MINUS || PLUS");
	return (0);
}
