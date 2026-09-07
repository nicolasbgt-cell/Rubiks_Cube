#include "cube.h"
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	t_cube cube;

	cube = cube_init();
	ft_display(&cube);
	usleep(1000000);
	ft_shuffle(&cube);
	ft_solver(&cube);
	ft_display(&cube);
	return (0);
}
