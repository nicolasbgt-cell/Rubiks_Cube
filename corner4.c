#include "cube.h"

int	ft_corner4_ok(t_cube *cube)
{
	if (cube->face[UP][0][0] == WHITE && cube->face[BACK][0][2] == ORANGE
		&& cube->face[LEFT][0][0] == BLUE)
		return (1);
	return (0);
}

void	ft_place_corner4(t_cube *cube)
{
	int	slot;
	int	rotations;
	int	count;

	if (ft_corner4_ok(cube))
		return ;
	slot = ft_find_corner(cube, 4);
	if (slot <= 3)
	{
		ft_corner_to_down(cube, slot);
		slot = ft_find_corner(cube, 4);
	}
	if (slot >= 4)
	{
		rotations = (slot - 6 + 4) % 4;
		while (rotations-- > 0)
			ft_move_d(cube);
	}
	count = 0;
	while (!ft_corner4_ok(cube) && count < 6)
	{
		ft_move_l_prime(cube);
		ft_move_d_prime(cube);
		ft_move_l(cube);
		ft_move_d(cube);
		count++;
	}
}
