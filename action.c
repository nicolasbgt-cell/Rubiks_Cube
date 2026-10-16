#include "cube.h"
#include <stdio.h>

static char	*ft_mix(t_cube *cube)
{
	cube->animate = 1;
	ft_shuffle(cube);
	cube->animate = 0;
	return ("Mix done");
}

static char	*ft_resolve(t_cube *cube, char *buf)
{
	cube->moves = 0;
	cube->animate = 2;
	ft_solver(cube);
	cube->animate = 0;
	snprintf(buf, MSG_SIZE, "Cube solved in %d moves", cube->moves);
	return (buf);
}

char	*ft_action(t_cube *cube, int choice, char *buf)
{
	if (choice == MENU_MIX)
		return (ft_mix(cube));
	if (choice == MENU_RESOLVE)
		return (ft_resolve(cube, buf));
	if (choice == MENU_BENCH)
		return (ft_bench(cube, buf));
	return ("Invalid choice");
}
