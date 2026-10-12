#include "cube.h"
#include <time.h>

int	ft_solved(t_cube *cube)
{
	int	i;

	if (!ft_white_cross(cube) || !ft_corner_ok(cube) || !ft_corner2_ok(cube)
		|| !ft_corner3_ok(cube) || !ft_corner4_ok(cube))
		return (0);
	i = 1;
	while (i <= 4)
	{
		if (!ft_edge_ok(cube, i))
			return (0);
		i++;
	}
	return (1);
}

double	ft_now(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec + ts.tv_nsec / 1e9);
}

void	ft_bench_init(t_bench *b)
{
	b->ok = 0;
	b->min = 1 << 30;
	b->max = 0;
	b->sum = 0;
	b->solve = 0;
	b->total = 0;
}

void	ft_bench_one(t_cube *cube, t_bench *b)
{
	double	start;

	ft_scramble(cube);
	cube->moves = 0;
	start = ft_now();
	ft_solver(cube);
	b->solve += ft_now() - start;
	b->sum += cube->moves;
	if (cube->moves < b->min)
		b->min = cube->moves;
	if (cube->moves > b->max)
		b->max = cube->moves;
	if (ft_solved(cube))
		b->ok++;
}
