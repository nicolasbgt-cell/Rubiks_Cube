#include "cube.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_bench_msg(char *buf, t_bench *b, int n)
{
	int	len;

	len = snprintf(buf, MSG_SIZE, "Benchmark terminé : %d/%d résolus",
			b->ok, n);
	if (b->ok < n)
		len += snprintf(buf + len, MSG_SIZE - len, " (%d échecs)",
				n - b->ok);
	len += snprintf(buf + len, MSG_SIZE - len,
			"\nMouvements : min %d / max %d / moyenne %.1f",
			b->min, b->max, (double)b->sum / n);
	snprintf(buf + len, MSG_SIZE - len,
		"\nTemps : %.3f ms / résolution, total %.2f s",
		b->solve * 1000 / n, b->total);
}

void	ft_bench(t_cube *cube, char *buf)
{
	t_bench	b;
	double	start;
	int		i;

	ft_bench_init(&b);
	srand(time(NULL));
	cube->animate = 0;
	start = ft_now();
	i = 0;
	while (i < BENCH_N)
	{
		ft_bench_one(cube, &b);
		i++;
		if (i % 10 == 0)
		{
			snprintf(buf, MSG_SIZE, "Benchmark %d/%d...", i, BENCH_N);
			ft_frame(cube, buf);
		}
	}
	b.total = ft_now() - start;
	ft_bench_msg(buf, &b, BENCH_N);
}
