#include "cube.h"

/*
** corner 1 : blanc-rouge-vert  (cible UFR)
** corner 2 : blanc-rouge-bleu  (cible UFL)
** corner 3 : blanc-orange-vert (cible UBR)
** corner 4 : blanc-orange-bleu (cible UBL)
*/
int	ft_is_corner(int a, int b, int c, int corner)
{
	int	side1;
	int	side2;

	side1 = RED;
	side2 = GREEN;
	if (corner == 2)
		side2 = BLUE;
	else if (corner == 3)
		side1 = ORANGE;
	else if (corner == 4)
	{
		side1 = ORANGE;
		side2 = BLUE;
	}
	if (a != WHITE && b != WHITE && c != WHITE)
		return (0);
	if (a != side1 && b != side1 && c != side1)
		return (0);
	if (a != side2 && b != side2 && c != side2)
		return (0);
	return (1);
}

int	ft_find_corner(t_cube *cube, int corner)
{
	if (ft_is_corner(cube->face[UP][2][2], cube->face[FRONT][0][2],
			cube->face[RIGHT][0][0], corner))
		return (0);
	if (ft_is_corner(cube->face[UP][2][0], cube->face[FRONT][0][0],
			cube->face[LEFT][0][2], corner))
		return (1);
	if (ft_is_corner(cube->face[UP][0][0], cube->face[BACK][0][2],
			cube->face[LEFT][0][0], corner))
		return (2);
	if (ft_is_corner(cube->face[UP][0][2], cube->face[BACK][0][0],
			cube->face[RIGHT][0][2], corner))
		return (3);
	if (ft_is_corner(cube->face[DOWN][0][2], cube->face[FRONT][2][2],
			cube->face[RIGHT][2][0], corner))
		return (4);
	if (ft_is_corner(cube->face[DOWN][0][0], cube->face[FRONT][2][0],
			cube->face[LEFT][2][2], corner))
		return (5);
	if (ft_is_corner(cube->face[DOWN][2][0], cube->face[BACK][2][2],
			cube->face[LEFT][2][0], corner))
		return (6);
	return (7);
}

int	ft_corner_ok(t_cube *cube)
{
	if (cube->face[UP][2][2] == WHITE && cube->face[FRONT][0][2] == RED
		&& cube->face[RIGHT][0][0] == GREEN)
		return (1);
	return (0);
}

/*
** X D X' : X descend le coin, D l'ecarte, X' remonte l'arete de la croix.
*/
void	ft_corner_to_down(t_cube *cube, int slot)
{
	if (slot == 0)
	{
		ft_move_r_prime(cube);
		ft_move_d_prime(cube);
		ft_move_r(cube);
	}
	else if (slot == 1)
	{
		ft_move_l(cube);
		ft_move_d(cube);
		ft_move_l_prime(cube);
	}
	else if (slot == 2)
	{
		ft_move_l_prime(cube);
		ft_move_d(cube);
		ft_move_l(cube);
	}
	else if (slot == 3)
	{
		ft_move_r(cube);
		ft_move_d(cube);
		ft_move_r_prime(cube);
	}
}

void	ft_place_corner(t_cube *cube)
{
	int	slot;
	int	count;

	if (ft_corner_ok(cube))
		return ;
	slot = ft_find_corner(cube, 1);
	if (slot >= 1 && slot <= 3)
	{
		ft_corner_to_down(cube, slot);
		slot = ft_find_corner(cube, 1);
	}
	while (slot-- > 4)
		ft_move_d(cube);
	count = 0;
	while (!ft_corner_ok(cube) && count < 6)
	{
		ft_move_r_prime(cube);
		ft_move_d_prime(cube);
		ft_move_r(cube);
		ft_move_d(cube);
		count++;
	}
}
