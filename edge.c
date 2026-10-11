#include "cube.h"

int	ft_is_edge(int a, int b, int edge)
{
	int	c1;
	int	c2;

	c1 = RED;
	c2 = GREEN;
	if (edge == 2)
		c2 = BLUE;
	else if (edge == 3)
		c1 = ORANGE;
	else if (edge == 4)
	{
		c1 = ORANGE;
		c2 = BLUE;
	}
	if ((a == c1 && b == c2) || (a == c2 && b == c1))
		return (1);
	return (0);
}

int	ft_find_edge(t_cube *cube, int edge)
{
	if (ft_is_edge(cube->face[FRONT][1][2], cube->face[RIGHT][1][0], edge))
		return (0);
	if (ft_is_edge(cube->face[FRONT][1][0], cube->face[LEFT][1][2], edge))
		return (1);
	if (ft_is_edge(cube->face[BACK][1][0], cube->face[RIGHT][1][2], edge))
		return (2);
	if (ft_is_edge(cube->face[BACK][1][2], cube->face[LEFT][1][0], edge))
		return (3);
	if (ft_is_edge(cube->face[DOWN][0][1], cube->face[FRONT][2][1], edge))
		return (4);
	if (ft_is_edge(cube->face[DOWN][1][2], cube->face[RIGHT][2][1], edge))
		return (5);
	if (ft_is_edge(cube->face[DOWN][2][1], cube->face[BACK][2][1], edge))
		return (6);
	return (7);
}

int	ft_edge_ok(t_cube *cube, int edge)
{
	if (edge == 1)
		return (cube->face[FRONT][1][2] == RED
			&& cube->face[RIGHT][1][0] == GREEN);
	if (edge == 2)
		return (cube->face[FRONT][1][0] == RED
			&& cube->face[LEFT][1][2] == BLUE);
	if (edge == 3)
		return (cube->face[BACK][1][0] == ORANGE
			&& cube->face[RIGHT][1][2] == GREEN);
	return (cube->face[BACK][1][2] == ORANGE
		&& cube->face[LEFT][1][0] == BLUE);
}

int	ft_down_edge(t_cube *cube, int i)
{
	if (i == 0)
		return (cube->face[DOWN][0][1]);
	if (i == 1)
		return (cube->face[DOWN][1][2]);
	if (i == 2)
		return (cube->face[DOWN][2][1]);
	return (cube->face[DOWN][1][0]);
}
