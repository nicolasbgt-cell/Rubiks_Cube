#include "cube.h"
#include <unistd.h>
#include <stdio.h>

int     ft_white_cross(t_cube *cube)
{
    if ((cube->face[UP][2][1] == WHITE && cube->face[FRONT][0][1] == RED) &&
        (cube->face[UP][1][2] == WHITE && cube->face[RIGHT][0][1] == GREEN) &&
        (cube->face[UP][0][1] == WHITE && cube->face[BACK][0][1] == ORANGE) &&
        (cube->face[UP][1][0] == WHITE && cube->face[LEFT][0][1] == BLUE))
        return (1);
    return (0);
}

void	ft_solver(t_cube *cube)
{
	while (!ft_white_cross(cube))
		ft_solve_white_cross(cube);
}
