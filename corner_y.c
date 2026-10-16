#include "cube.h"

static int	ft_has(int a, int b, int c, int color)
{
	return (a == color || b == color || c == color);
}

static int	ft_ycorner_ok(t_cube *cube, int k)
{
	int	a;
	int	b;
	int	c;

	if (k == 0)
		a = cube->face[DOWN][0][2];
	else if (k == 1)
		a = cube->face[DOWN][2][2];
	else if (k == 2)
		a = cube->face[DOWN][2][0];
	else
		a = cube->face[DOWN][0][0];
	b = cube->face[ft_ring(k)][2][2];
	c = cube->face[ft_ring(k + 1)][2][0];
	return (ft_has(a, b, c, YELLOW)
		&& ft_has(a, b, c, cube->face[ft_ring(k)][1][1])
		&& ft_has(a, b, c, cube->face[ft_ring(k + 1)][1][1]));
}

static int	ft_ycorner_count(t_cube *cube)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	while (k < 4)
	{
		count += ft_ycorner_ok(cube, k);
		k++;
	}
	return (count);
}

void	ft_place_yellow_corners(t_cube *cube)
{
	int	k;

	while (ft_ycorner_count(cube) < 4)
	{
		k = 0;
		while (k < 3 && !ft_ycorner_ok(cube, k))
			k++;
		ft_edge_alg(cube, "drDLdRDl", k);
	}
}
