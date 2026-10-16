#include "cube.h"
#include <stdio.h>

void	ft_bench_text(char *buf, int *steps, double ms, double sec)
{
	int	len;

	len = snprintf(buf, MSG_SIZE, "Total: %d moves\n",
			steps[0] + steps[1] + steps[2] + steps[3] + steps[4]
			+ steps[5] + steps[6]);
	len += snprintf(buf + len, MSG_SIZE - len,
			"White cross: %d | White corners: %d | Middle edges: %d\n",
			steps[0], steps[1], steps[2]);
	len += snprintf(buf + len, MSG_SIZE - len,
			"Yellow cross: %d | Yellow edges: %d\n", steps[3], steps[4]);
	len += snprintf(buf + len, MSG_SIZE - len,
			"Yellow corners: place %d | orient %d\n", steps[5], steps[6]);
	len += snprintf(buf + len, MSG_SIZE - len,
			"Compute time: %.3f ms\n", ms);
	snprintf(buf + len, MSG_SIZE - len,
		"Total time with animation: %.1f s", sec);
}

char	*ft_bench(t_cube *cube, char *buf)
{
	t_cube	copy;
	int		steps[STEPS];
	int		total;
	double	ms;
	double	start;

	if (ft_solved(cube))
		return ("Cube already solved, Mix first");
	copy = *cube;
	total = ft_measure(&copy, steps, &ms);
	cube->moves = 0;
	cube->animate = 2;
	start = ft_now();
	ft_solver(cube);
	cube->animate = 0;
	if (cube->moves != total)
		return ("Error: benchmark mismatch");
	ft_bench_text(buf, steps, ms, ft_now() - start);
	return (buf);
}
