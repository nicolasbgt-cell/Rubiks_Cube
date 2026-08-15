/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_solver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 00:00:00 by nbigot            #+#    #+#             */
/*   Updated: 2026/08/15 00:00:00 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

static void	shuffle_silent(t_cube *cube, int n)
{
	int	move;

	while (n--)
	{
		move = rand() % 12;
		if (move == 0) ft_move_u(cube);
		else if (move == 1) ft_move_u_prime(cube);
		else if (move == 2) ft_move_d(cube);
		else if (move == 3) ft_move_d_prime(cube);
		else if (move == 4) ft_move_f(cube);
		else if (move == 5) ft_move_f_prime(cube);
		else if (move == 6) ft_move_b(cube);
		else if (move == 7) ft_move_b_prime(cube);
		else if (move == 8) ft_move_l(cube);
		else if (move == 9) ft_move_l_prime(cube);
		else if (move == 10) ft_move_r(cube);
		else if (move == 11) ft_move_r_prime(cube);
	}
}

int	is_solved(t_cube *cube)
{
	int	f;
	int	r;
	int	c;

	f = 0;
	while (f < 6)
	{
		r = 0;
		while (r < 3)
		{
			c = 0;
			while (c < 3)
			{
				if (cube->face[f][r][c] != f)
					return (0);
				c++;
			}
			r++;
		}
		f++;
	}
	return (1);
}

static void	solve_white_cross_loop(t_cube *cube, int *iters)
{
	int	count;

	count = 0;
	while (!ft_white_cross(cube))
	{
		ft_solve_white_cross(cube);
		count++;
		if (count > 20000)
			break ;
	}
	if (iters)
		*iters = count;
}

int	main(void)
{
	int		total;
	int		cross_ok;
	int		lens[] = {5, 10, 20, 50, 100};
	int		i;
	int		iters;
	int		max_iters;
	t_cube	cube;
	int		len;

	srand(time(NULL));
	total = 1000;
	cross_ok = 0;
	max_iters = 0;
	i = 0;
	printf("=== Testing white cross on %d cubes ===\n", total);
	while (i < total)
	{
		cube = cube_init();
		len = lens[rand() % 5];
		shuffle_silent(&cube, len);
		solve_white_cross_loop(&cube, &iters);
		if (iters > max_iters)
			max_iters = iters;
		if (ft_white_cross(&cube))
			cross_ok++;
		else
			printf("FAIL (len=%d, iters=%d)\n", len, iters);
		i++;
	}
	printf("White cross: %d/%d   max_iters=%d\n", cross_ok, total, max_iters);
	return (cross_ok == total ? 0 : 1);
}
