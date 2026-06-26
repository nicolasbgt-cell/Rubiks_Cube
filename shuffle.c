/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shuffle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:25:07 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/24 11:25:09 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void	ft_shuffle(t_cube *cube)
{
	int	i;
	int	move;

	srand(time(NULL));
	i = 0;
	while (i < 20)
	{
		move = rand() % 12;
		if (move == 0)
			ft_move_u(cube);
		else if (move == 1)
			ft_move_u_prime(cube);
		else if (move == 2)
			ft_move_d(cube);
		else if (move == 3)
			ft_move_d_prime(cube);
		else if (move == 4)
			ft_move_f(cube);
		else if (move == 5)
			ft_move_f_prime(cube);
		else if (move == 6)
			ft_move_b(cube);
		else if (move == 7)
			ft_move_b_prime(cube);
		else if (move == 8)
			ft_move_l(cube);
		else if (move == 9)
			ft_move_l_prime(cube);
		else if (move == 10)
			ft_move_r(cube);
		else if (move == 11)
			ft_move_r_prime(cube);
		system("clear");
		ft_display(cube);
		usleep(400000);
		i++;
	}
}
