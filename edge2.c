#include "cube.h"

int	ft_ring(int i)
{
	i = i % 4;
	if (i == 0)
		return (FRONT);
	if (i == 1)
		return (RIGHT);
	if (i == 2)
		return (BACK);
	return (LEFT);
}

void	ft_turn(t_cube *cube, int face, int prime)
{
	if (face == DOWN && !prime)
		ft_move_d(cube);
	else if (face == DOWN)
		ft_move_d_prime(cube);
	else if (face == FRONT && !prime)
		ft_move_f(cube);
	else if (face == FRONT)
		ft_move_f_prime(cube);
	else if (face == RIGHT && !prime)
		ft_move_r(cube);
	else if (face == RIGHT)
		ft_move_r_prime(cube);
	else if (face == BACK && !prime)
		ft_move_b(cube);
	else if (face == BACK)
		ft_move_b_prime(cube);
	else if (face == LEFT && !prime)
		ft_move_l(cube);
	else if (face == LEFT)
		ft_move_l_prime(cube);
}

void	ft_edge_alg(t_cube *cube, char *alg, int i)
{
	int	face;

	while (*alg)
	{
		face = DOWN;
		if (*alg == 'F' || *alg == 'f')
			face = ft_ring(i);
		else if (*alg == 'R' || *alg == 'r')
			face = ft_ring(i + 1);
		else if (*alg == 'L' || *alg == 'l')
			face = ft_ring(i + 3);
		ft_turn(cube, face, *alg >= 'a');
		alg++;
	}
}

void	ft_edge_insert(t_cube *cube, int edge)
{
	int	i;
	int	face;

	i = ft_find_edge(cube, edge) - 4;
	face = ft_ring(i);
	while (cube->face[face][2][1] != cube->face[face][1][1])
	{
		ft_move_d(cube);
		i = ft_find_edge(cube, edge) - 4;
		face = ft_ring(i);
	}
	if (ft_down_edge(cube, i) == cube->face[ft_ring(i + 1)][1][1])
		ft_edge_alg(cube, "drDRDFdf", i);
	else
		ft_edge_alg(cube, "DLdldfDF", i);
}

void	ft_edge_eject(t_cube *cube, int pos)
{
	int	i;

	i = 3;
	if (pos == 0)
		i = 0;
	else if (pos == 2)
		i = 1;
	else if (pos == 3)
		i = 2;
	ft_edge_alg(cube, "drDRDFdf", i);
}
