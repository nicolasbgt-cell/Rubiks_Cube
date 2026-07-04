/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slover.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:25:22 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/24 11:25:24 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>
#include <unistd.h>

int	ft_white_cross(t_cube *cube)
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
	int	count;

	count = 0;
	while (!ft_white_cross(cube))
	{
		ft_solve_white_cross(cube);
		count++;
		if (count > 1000)
		{
			printf("boucle infinie");
			return ;
		}
	}
}

void    ft_solve_white_cross(t_cube *cube)
{
	int	f;
	int	i;
	int	j;

	i = 0;
	j = 0;
	f = 0;
	while (f < 6)
	{
		while (i < 3)
		{
			while (j < 3)
			{
				if (cube->face[f][i][j] == WHITE &&
					(i + j) % 2 == 1)
				{
					if (f == FRONT)
					{
						ft_align_front(cube);
						return ;
					}
					else if (f == RIGHT)
					{
						ft_align_right(cube);
						return ;
					}
					else if (f == LEFT)
					{
						ft_align_left(cube);
						return ;
					}
					else if (f == BACK)
					{
						ft_align_back(cube);
						return ;
					}
					else if (f == DOWN)
					{
						ft_align_down(cube);
						return ;
					}
					else if (f == UP)
					{
						if (i == 0 && j == 1 && cube->face[FRONT][0][1] != RED)
						{
							ft_move_f(cube);
							ft_move_f(cube);
							return ;
						}
						else if (i == 1 && j == 2 && cube->face[RIGHT][0][1] != GREEN)
						{
							ft_move_r(cube);
							ft_move_r(cube);
							return ;
						}
						else if (i == 2 && j == 1 && cube->face[BACK][0][1] != ORANGE)
						{
							ft_move_b(cube);
							ft_move_b(cube);
							return ;
						}
						else if (i == 1 && j == 0 && cube->face[LEFT][0][1] != BLUE)
						{
							ft_move_l(cube);
							ft_move_l(cube);
							return ;
						}
					}
				}
				j++;
			}
			i++;
			j = 0;
		}
		f++;
		i = 0;
	}
}

int	is_goal(t_cube *cube)
{
	int	f;
	int	i;
	int	j;
	int	ref;

	f = 0;
	i = 0;
	j = 0;
	while (f < 6)
	{
		ref =cube->face[f][0][0];
		while (i < 3)
		{
			while (j < 3)
			{
				if (cube->face[f][i][j] != ref)
					return (0);
				j++;
			}
			i++;
			j = 0;
		}
		f++;
		i = 0;
	}
	return (1);
}

t_cube	apply_move(t_cube *cube, int move)
{
	t_cube	new_cube;

	new_cube = *cube;
	if (move == 0)
		ft_move_u(&new_cube);
	else if (move == 1)
		ft_move_u_prime(&new_cube);
	else if (move == 2)
		ft_move_d(&new_cube);
	else if (move == 3)
		ft_move_d_prime(&new_cube);
	else if (move == 4)
		ft_move_f(&new_cube);
	else if (move == 5)
		ft_move_f_prime(&new_cube);
	else if (move == 6)
		ft_move_b(&new_cube);
	else if (move == 7)
		ft_move_b_prime(&new_cube);
	else if (move == 8)
		ft_move_l(&new_cube);
	else if (move == 9)
		ft_move_l_prime(&new_cube);
	else if (move == 10)
		ft_move_r(&new_cube);
	else if (move == 11)
		ft_move_r_prime(&new_cube);
	return (new_cube);
}
