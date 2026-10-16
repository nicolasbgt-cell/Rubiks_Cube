#include "cube.h"

static void	ft_twist(t_cube *cube)
{
	ft_move_r(cube);
	ft_move_u(cube);
	ft_move_r_prime(cube);
	ft_move_u_prime(cube);
}

void	ft_orient_yellow_corners(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		while (cube->face[DOWN][0][2] != YELLOW)
			ft_twist(cube);
		ft_move_d(cube);
		i++;
	}
	while (cube->face[FRONT][2][1] != cube->face[FRONT][1][1])
		ft_move_d(cube);
}
