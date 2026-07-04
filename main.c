/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:25:58 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/24 11:26:00 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	t_cube cube;

	cube = cube_init();
	ft_display(&cube);
	usleep(1000000);
	ft_shuffle(&cube);
	ft_solver(&cube);
	ft_display(&cube);
	return (0);
}
