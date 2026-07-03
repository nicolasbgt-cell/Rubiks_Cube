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

int	main(void)
{
	t_cube cube;

	cube = cube_init();
	usleep(1000000);
	ft_shuffle(&cube);
	ida_star(&cube);
	return (0);
}
