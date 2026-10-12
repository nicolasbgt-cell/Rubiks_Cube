#include "cube.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_frame(t_cube *cube, char *msg)
{
	write(1, "\033[H\033[2J", 7);
	ft_putstr("==== Welcome to Rubik's 2D ====\n\n");
	ft_display(cube);
	fflush(stdout);
	ft_putstr("\n1. Mix\n2. Resolve\n3. Benchmark\n4. Quit\n\n");
	ft_putstr(msg);
	ft_putstr("\n");
}

void	ft_after_move(t_cube *cube)
{
	cube->moves++;
	if (cube->animate == 0)
		return ;
	if (cube->animate == 1)
		ft_frame(cube, "Mixing...");
	else
		ft_frame(cube, "Resolving...");
	usleep(150000);
}
