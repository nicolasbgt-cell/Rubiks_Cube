/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 11:14:32 by nbigot            #+#    #+#             */
/*   Updated: 2026/08/15 00:00:00 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_to_down(t_cube *cube)
{
	if (cube->face[FRONT][0][1] == WHITE)
		ft_move_f(cube);
	else if (cube->face[FRONT][1][0] == WHITE)
		ft_move_l(cube);
	else if (cube->face[FRONT][1][2] == WHITE)
		ft_move_r_prime(cube);
	else if (cube->face[RIGHT][0][1] == WHITE)
		ft_move_r(cube);
	else if (cube->face[RIGHT][1][0] == WHITE)
		ft_move_f(cube);
	else if (cube->face[RIGHT][1][2] == WHITE)
		ft_move_b_prime(cube);
	else if (cube->face[LEFT][0][1] == WHITE)
		ft_move_l_prime(cube);
	else if (cube->face[LEFT][1][0] == WHITE)
		ft_move_b(cube);
	else if (cube->face[LEFT][1][2] == WHITE)
		ft_move_f_prime(cube);
	else if (cube->face[BACK][0][1] == WHITE)
		ft_move_b(cube);
	else if (cube->face[BACK][1][0] == WHITE)
		ft_move_r(cube);
	else if (cube->face[BACK][1][2] == WHITE)
		ft_move_l_prime(cube);
	else if (cube->face[FRONT][2][1] == WHITE
		&& !(cube->face[UP][2][1] == WHITE && cube->face[FRONT][0][1] == RED))
		ft_move_f(cube);
	else if (cube->face[RIGHT][2][1] == WHITE
		&& !(cube->face[UP][1][2] == WHITE && cube->face[RIGHT][0][1] == GREEN))
		ft_move_r(cube);
	else if (cube->face[BACK][2][1] == WHITE
		&& !(cube->face[UP][0][1] == WHITE && cube->face[BACK][0][1] == ORANGE))
		ft_move_b(cube);
	else if (cube->face[LEFT][2][1] == WHITE
		&& !(cube->face[UP][1][0] == WHITE && cube->face[LEFT][0][1] == BLUE))
		ft_move_l(cube);
	else if (cube->face[FRONT][2][1] == WHITE || cube->face[RIGHT][2][1] == WHITE
		|| cube->face[BACK][2][1] == WHITE || cube->face[LEFT][2][1] == WHITE)
		ft_move_d(cube);
	else if (cube->face[UP][2][1] == WHITE && cube->face[FRONT][0][1] != RED)
	{
		ft_move_f(cube);
		ft_move_f(cube);
	}
	else if (cube->face[UP][1][2] == WHITE && cube->face[RIGHT][0][1] != GREEN)
	{
		ft_move_r(cube);
		ft_move_r(cube);
	}
	else if (cube->face[UP][0][1] == WHITE && cube->face[BACK][0][1] != ORANGE)
	{
		ft_move_b(cube);
		ft_move_b(cube);
	}
	else if (cube->face[UP][1][0] == WHITE && cube->face[LEFT][0][1] != BLUE)
	{
		ft_move_l(cube);
		ft_move_l(cube);
	}
}

/*
** Bug fixed: the old code rotated D looking for a specific colour at
** FRONT[2][1], but each D rotation moves the white piece to a different
** DOWN slot (DOWN[0][1]->DOWN[1][2]->...).  Doing F F afterwards then
** operated on DOWN[0][1] which no longer held the white piece.
** When the companion was not RED and UP[2][1] was correctly occupied the
** function did 4 D rotations (returning to the original state) and then
** bailed out without touching anything -> infinite loop (iters > 20000).
**
** Fix: read the companion colour once, compute the exact number of CW D
** rotations needed to bring the piece directly under its matching face
** centre, then do the correct face double-move.
*/
void	ft_align_down(t_cube *cube)
{
	int	companion;
	int	slot;
	int	target;
	int	rotations;

	if (cube->face[DOWN][0][1] == WHITE)
	{
		slot = 0;
		companion = cube->face[FRONT][2][1];
	}
	else if (cube->face[DOWN][1][2] == WHITE)
	{
		slot = 1;
		companion = cube->face[RIGHT][2][1];
	}
	else if (cube->face[DOWN][2][1] == WHITE)
	{
		slot = 2;
		companion = cube->face[BACK][2][1];
	}
	else if (cube->face[DOWN][1][0] == WHITE)
	{
		slot = 3;
		companion = cube->face[LEFT][2][1];
	}
	else
		return ;
	if (companion == RED)
		target = 0;
	else if (companion == GREEN)
		target = 1;
	else if (companion == ORANGE)
		target = 2;
	else
		target = 3;
	rotations = (target - slot + 4) % 4;
	while (rotations-- > 0)
		ft_move_d(cube);
	if (target == 0)
	{
		ft_move_f(cube);
		ft_move_f(cube);
	}
	else if (target == 1)
	{
		ft_move_r(cube);
		ft_move_r(cube);
	}
	else if (target == 2)
	{
		ft_move_b(cube);
		ft_move_b(cube);
	}
	else
	{
		ft_move_l(cube);
		ft_move_l(cube);
	}
}

void	ft_solve_white_cross(t_cube *cube)
{
	ft_to_down(cube);
	ft_align_down(cube);
}
