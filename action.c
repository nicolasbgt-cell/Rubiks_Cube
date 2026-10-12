#include "cube.h"
#include <stdio.h>

static char	*ft_mix(t_cube *cube)
{
	cube->animate = 1;
	ft_shuffle(cube);
	cube->animate = 0;
	return ("Mix terminé");
}

static char	*ft_resolve(t_cube *cube, char *buf)
{
	cube->moves = 0;
	cube->animate = 2;
	ft_solver(cube);
	cube->animate = 0;
	snprintf(buf, MSG_SIZE, "Cube résolu en %d mouvements", cube->moves);
	return (buf);
}

char	*ft_action(t_cube *cube, int choice, char *buf)
{
	if (choice == 1)
		return (ft_mix(cube));
	if (choice == 2)
		return (ft_resolve(cube, buf));
	if (choice == 3)
	{
		ft_bench(cube, buf);
		return (buf);
	}
	return ("Choix invalide");
}
