#include "cube.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	t_cube	cube;

	setvbuf(stdout, NULL, _IOFBF, 16384);
	srand(time(NULL));
	cube = cube_init();
	ft_term_enter();
	ft_menu(&cube);
	ft_term_leave();
	return (0);
}
