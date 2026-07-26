/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 11:14:32 by nbigot            #+#    #+#             */
/*   Updated: 2026/07/26 11:14:53 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_to_down(t_cube *cube)
{
	if (cube->face[FRONT][0][1] == WHITE)
		ft_move_f(cube);
	else if (cube->face[FRONT][1][0] == WHITE)
		ft_move_l_prime(cube);
	else if (cube->face[FRONT][1][2] == WHITE)
		ft_move_r(cube);
	else if (cube->face[RIGHT][0][1] == WHITE)
		ft_move_r(cube);
	else if (cube->face[RIGHT][1][0] == WHITE)
		ft_move_f_prime(cube);
	else if (cube->face[RIGHT][1][2] == WHITE)
		ft_move_b(cube);
	else if (cube->face[LEFT][0][1] == WHITE)
		ft_move_l_prime(cube);
	else if (cube->face[LEFT][1][0] == WHITE)
		ft_move_b_prime(cube);
	else if (cube->face[LEFT][1][2] == WHITE)
		ft_move_f(cube);
	else if (cube->face[BACK][0][1] == WHITE)
		ft_move_b(cube);
	else if (cube->face[BACK][1][0] == WHITE)
		ft_move_r_prime(cube);
	else if (cube->face[BACK][1][2] == WHITE)
		ft_move_l(cube);
	else if (cube->face[UP][0][1] == WHITE && cube->face[FRONT][0][1] != RED)
	{
		ft_move_f(cube);
		ft_move_f(cube);
	}
	else if(cube->face[UP][1][2] == WHITE && cube->face[RIGHT][0][1] != GREEN)
	{
		ft_move_r(cube);
		ft_move_r(cube);
	}
	else if (cube->face[UP][2][1] == WHITE && cube->face[BACK][0][1] != ORANGE)
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

void	ft_align_down(t_cube *cube)
{
	if (cube->face[DOWN][0][1] == WHITE)
	{
		int safe = 0;
		while (cube->face[FRONT][2][1] != RED && safe < 4)
		{
			ft_move_d(cube);
			safe++;
		}
		if (!(cube->face[UP][0][1] == WHITE && cube->face[FRONT][0][1] == RED))
		{
			ft_move_f(cube);
			ft_move_f(cube);
			return ;
		}
	}
	else if (cube->face[DOWN][1][2] == WHITE)
	{
		int	safe = 0;
		while (cube->face[RIGHT][2][1] != GREEN && safe < 4)
		{
			ft_move_d(cube);
			safe++;
		}
		if (!(cube->face[UP][1][2] == WHITE && cube->face[RIGHT][0][1] == GREEN))
		{
			ft_move_r(cube);
			ft_move_r(cube);
			return ;
		}
	}
	else if (cube->face[DOWN][2][1] == WHITE)
	{
		int safe = 0;
		while (cube->face[BACK][2][1] != ORANGE && safe < 4)
		{
			ft_move_d(cube);
			safe++;
		}
		if (!(cube->face[UP][2][1] == WHITE && cube->face[BACK][0][1] == ORANGE))
		{
			ft_move_b(cube);
			ft_move_b(cube);
			return ;
		}
	}
	else if (cube->face[DOWN][1][0] == WHITE)
	{
		int	safe = 0;
		while (cube->face[LEFT][2][1] != BLUE && safe < 4)
		{
			ft_move_d(cube);
			safe++;
		}
		if (!(cube->face[UP][1][0] == WHITE && cube->face[LEFT][0][1] == BLUE))
		{
			ft_move_l(cube);
			ft_move_l(cube);
			return ;
		}
	}
}

void	ft_solve_white_cross(t_cube *cube)
{
	ft_to_down(cube);
	ft_align_down(cube);
	ft_move_u(cube);
}
