#include "cube.h"

void	ft_edge_down(t_cube *cube)
{
	if (cube->face[DOWN][0][1] == WHITE)
	{
		ft_move_f(cube);
		ft_move_f(cube);
	}
	if (cube->face[DOWN][1][0] == WHITE)
	{
		ft_move_l(cube);
		ft_move_l(cube);
	}
	if (cube->face[DOWN][1][2] == WHITE)
	{
		ft_move_r(cube);
		ft_move_r(cube);
	}
	if (cube->face[DOWN][2][1] == WHITE)
	{
		ft_move_b(cube);
		ft_move_b(cube);
	}
}

void	ft_align_down(t_cube *cube)
{
	if (cube->face[DOWN][0][1] == WHITE)
	{
		while (cube->face[FRONT][2][1] != RED)
			ft_move_d(cube);
		ft_move_f(cube);
		ft_move_f(cube);
	}
	if (cube->face[DOWN][1][0] == WHITE)
	{
		while (cube->face[LEFT][2][1] != BLUE)
			ft_move_d(cube);
		ft_move_l(cube);
		ft_move_l(cube);
	}
	if (cube->face[DOWN][1][2] == WHITE)
	{
		while (cube->face[RIGHT][2][1] != GREEN)
			ft_move_d(cube);
		ft_move_r(cube);
		ft_move_r(cube);
	}
	if (cube->face[DOWN][2][1] == WHITE)
	{
		while (cube->face[BACK][2][1] != ORANGE)
			ft_move_d(cube);
		ft_move_b(cube);
		ft_move_b(cube);
	}
}

void	ft_align_front(t_cube *cube)
{

