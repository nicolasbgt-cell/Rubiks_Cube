/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:24:40 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/24 11:24:42 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <unistd.h>
#include <string.h>

void	ft_print_cell(char *letter, char *color)
{
	write(1, color, strlen(color));
	write(1, letter, 3);
	write(1, "\033[0m", 4);
}

void	ft_display(t_cube *cube)
{
	int	row;
	int	col;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 12)
		{
			if ((col < 3 || col > 5) && (row < 3 || row > 5))
				write(1, "   ", 3);
			else
			{
				if (row < 3)
					ft_print_cell("[R]", "\033[31m");
				else if (row > 5)
					ft_print_cell("[O]", "\033[38;5;208m");
				else if (col < 3)
					ft_print_cell("[B]", "\033[34m");
				else if (col < 6)
					ft_print_cell("[W]", "\033[37m");
				else if (col < 9)
					ft_print_cell("[G]", "\033[32m");
				else
					ft_print_cell("[Y]", "\033[33m");
			}
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
