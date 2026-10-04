#include "cube.h"

int	ft_corner2_ok(t_cube *cube)
{
	if (cube->face[UP][2][0] == WHITE && cube->face[FRONT][0][0] == RED
		&& cube->face[LEFT][0][2] == BLUE)
		return (1);
	return (0);
}

void	ft_place_corner2(t_cube *cube)
{
	int	slot;
	int	rotations;
	int	count;

	if (ft_corner2_ok(cube))
		return ;
	slot = ft_find_corner(cube, 2);
	if (slot == 0 || slot == 2 || slot == 3)
	{
		ft_corner_to_down(cube, slot);
		slot = ft_find_corner(cube, 2);
	}
	if (slot >= 4)
	{
		rotations = (slot - 5 + 4) % 4;
		while (rotations-- > 0)
			ft_move_d(cube);
	}
	count = 0;
	while (!ft_corner2_ok(cube) && count < 6)
	{
		ft_move_l(cube);
		ft_move_d(cube);
		ft_move_l_prime(cube);
		ft_move_d_prime(cube);
		count++;
	}
}
