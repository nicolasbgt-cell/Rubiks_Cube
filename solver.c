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

int	heuristic(t_cube *cube)
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
		}
		f++;
		i = 0;
		j = 0;
	}
	return (1);
}

t_cube	apply_move(t_cube *cube, int move)
int	search(t_cube *path[], int g, int limit, int depth)
void	ida_star(t_cube cube)
