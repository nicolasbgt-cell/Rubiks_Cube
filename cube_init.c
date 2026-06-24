/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 08:44:06 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/24 08:44:16 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_cube	cube_init(void)
{
	t_cube cube;
	int	face;
	int	line;
	int	column;

	face = 0;
	while (face < 6)
	{
		line = 0;
		while (line < 3)
		{
			column = 0;
			while (column < 3)
			{
				cube.face[face][line][column] = face;
				column++;
			}
			line++;
		}
		face++;
	}
	return (cube);
}
