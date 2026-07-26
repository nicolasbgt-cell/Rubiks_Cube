/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 11:17:44 by nbigot            #+#    #+#             */
/*   Updated: 2026/07/26 12:15:00 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <unistd.h>
#include <stdio.h>

int     ft_white_cross(t_cube *cube)
{
    if ((cube->face[UP][0][1] == WHITE && cube->face[FRONT][0][1] == RED) &&
        (cube->face[UP][1][2] == WHITE && cube->face[RIGHT][0][1] == GREEN) &&
        (cube->face[UP][2][1] == WHITE && cube->face[BACK][0][1] == ORANGE) &&
        (cube->face[UP][1][0] == WHITE && cube->face[LEFT][0][1] == BLUE))
        return (1);
    return (0);
}

void	ft_solver(t_cube *cube)
{
	int count;

	count = 0;
	while (!ft_white_cross(cube))
	{
		ft_solve_white_cross(cube);
		count++;
		if (count > 8000)
		{
			printf("boucle infinie\n");
			return ;
		}
	}
	printf("CROIX FAITE en %d iterations\n", count);
}
