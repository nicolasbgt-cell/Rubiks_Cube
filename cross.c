#include "cube.h"

int	ft_yellow_count(t_cube *cube)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		if (ft_down_edge(cube, i) == YELLOW)
			count++;
		i++;
	}
	return (count);
}

static int	ft_yellow_at(t_cube *cube, int a, int b)
{
	return (ft_down_edge(cube, a) == YELLOW
		&& ft_down_edge(cube, b) == YELLOW);
}

static void	ft_cross_step(t_cube *cube, int a, int b)
{
	while (!ft_yellow_at(cube, a, b))
		ft_move_d(cube);
	ft_edge_alg(cube, "FLDldf", 0);
}

void	ft_yellow_cross(t_cube *cube)
{
	while (ft_yellow_count(cube) < 4)
	{
		if (ft_yellow_count(cube) == 0)
			ft_edge_alg(cube, "FLDldf", 0);
		else if (ft_yellow_at(cube, 1, 3) || ft_yellow_at(cube, 0, 2))
			ft_cross_step(cube, 1, 3);
		else
			ft_cross_step(cube, 1, 2);
	}
}
