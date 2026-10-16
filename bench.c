#include "cube.h"
#include <time.h>

int	ft_solved(t_cube *cube)
{
	int	face;
	int	i;

	face = 0;
	while (face < 6)
	{
		i = 0;
		while (i < 9)
		{
			if (cube->face[face][i / 3][i % 3] != cube->face[face][1][1])
				return (0);
			i++;
		}
		face++;
	}
	return (1);
}

double	ft_now(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec + ts.tv_nsec / 1e9);
}

int	ft_measure(t_cube *copy, int *steps, double *ms)
{
	int		step;
	int		before;
	double	start;

	copy->animate = 0;
	copy->moves = 0;
	start = ft_now();
	step = 0;
	while (step < STEPS)
	{
		before = copy->moves;
		ft_solver_step(copy, step);
		steps[step] = copy->moves - before;
		step++;
	}
	*ms = (ft_now() - start) * 1000.0;
	return (copy->moves);
}
