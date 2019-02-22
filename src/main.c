/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:49:47 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/22 17:47:13 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	if (argc == 2 && check_file(argv[1]))
		return (fractol(argv[1]));
	return (exit_fractol(1, NULL, NULL));
}
