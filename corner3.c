#include "cube.h"

int	ft_corner3_ok(t_cube *cube)
{
	if (cube->face[UP][0][2] == WHITE && cube->face[BACK][0][0] == ORANGE
		&& cube->face[RIGHT][0][2] == GREEN)
		return (1);
	return (0);
}

/*
** Meme principe que ft_place_corner, vu depuis la face RIGHT :
** on amene le coin en DBR puis on repete B' D' B D.
** B et D ne touchent ni la croix ni les coins 1 et 2 (UFR, UFL).
*/
void	ft_place_corner3(t_cube *cube)
{
	int	slot;
	int	rotations;
	int	count;

	if (ft_corner3_ok(cube))
		return ;
	slot = ft_find_corner(cube, 3);
	if (slot <= 2)
	{
		ft_corner_to_down(cube, slot);
		slot = ft_find_corner(cube, 3);
	}
	if (slot >= 4)
	{
		rotations = (slot - 7 + 4) % 4;
		while (rotations-- > 0)
			ft_move_d(cube);
	}
	count = 0;
	while (!ft_corner3_ok(cube) && count < 6)
	{
		ft_move_b_prime(cube);
		ft_move_d_prime(cube);
		ft_move_b(cube);
		ft_move_d(cube);
		count++;
	}
}
