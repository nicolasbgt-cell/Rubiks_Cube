#include "cube.h"

static int	ft_aligned(t_cube *cube, int k, int turns)
{
	return (cube->face[ft_ring(k)][2][1]
		== cube->face[ft_ring(k + turns)][1][1]);
}

static int	ft_count_after(t_cube *cube, int turns)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	while (k < 4)
	{
		if (ft_aligned(cube, k, turns))
			count++;
		k++;
	}
	return (count);
}

static void	ft_best_d(t_cube *cube)
{
	int	best;
	int	turns;
	int	i;

	best = 0;
	turns = 0;
	i = 0;
	while (i < 4)
	{
		if (ft_count_after(cube, i) > best)
		{
			best = ft_count_after(cube, i);
			turns = i;
		}
		i++;
	}
	while (turns-- > 0)
		ft_move_d(cube);
}

void	ft_place_yellow_edges(t_cube *cube)
{
	int	k;

	ft_best_d(cube);
	while (ft_count_after(cube, 0) < 4)
	{
		k = 0;
		while (k < 4 && (ft_aligned(cube, k, 0) || ft_aligned(cube, k + 1, 0)))
			k++;
		ft_edge_alg(cube, "LDlDLDDlD", k % 4);
		ft_best_d(cube);
	}
}
