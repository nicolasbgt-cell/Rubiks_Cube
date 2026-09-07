#include "cube.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	ft_print_cell(int color)
{
	if (color == WHITE)
		printf("\033[37m[W]\033[0m");
	else if (color == YELLOW)
		printf("\033[33m[Y]\033[0m");
	else if (color == RED)
		printf("\033[31m[R]\033[0m");
	else if (color == ORANGE)
		printf("\033[38;5;208m[O]\033[0m");
	else if (color == BLUE)
		printf("\033[34m[B]\033[0m");
	else if (color == GREEN)
		printf("\033[32m[G]\033[0m");
}

void	ft_display(t_cube *cube)
{
	int row;
	int col;

	row = 0;
	while (row < 3)
	{
		write(1, "         ", 9);
		col = 0;
		while (col < 3)
		{
			ft_print_cell(cube->face[UP][row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			ft_print_cell(cube->face[LEFT][row][col]);
			col++;
		}
		col = 0;
		while (col < 3)
		{
			ft_print_cell(cube->face[FRONT][row][col]);
			col++;
		}
		col = 0;
		while (col < 3)
		{
			ft_print_cell(cube->face[RIGHT][row][col]);
			col++;
		}
		col = 0;
		while (col < 3)
		{
			ft_print_cell(cube->face[BACK][row][col]);
			col++;
			}
		printf("\n");
		row++;
	}
	row = 0;
	while (row < 3)
	{
		write(1, "         ", 9);
		col = 0;
		while (col < 3)
		{
			ft_print_cell(cube->face[DOWN][row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}
