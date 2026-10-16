#include "cube.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	fputs(str, stdout);
}

static void	ft_putmsg(char *msg)
{
	while (*msg)
	{
		if (*msg == '\n')
			ft_putstr("\033[K");
		putc(*msg++, stdout);
	}
}

void	ft_frame(t_cube *cube, char *msg, int prompt)
{
	ft_putstr("\033[H");
	ft_putstr("==== Welcome to Rubik's 2D ====\033[K\n\033[K\n");
	ft_display(cube);
	ft_putstr("\033[K\n1. Mix\033[K\n2. Resolve\033[K\n3. Benchmark\033[K\n4. Quit\033[K\n");
	ft_putstr("\033[K\n");
	ft_putmsg(msg);
	ft_putstr("\033[K\n");
	if (prompt)
		ft_putstr("Enter your choice: ");
	ft_putstr("\033[J");
	if (prompt)
		ft_putstr("\033[?25h");
	else
		ft_putstr("\033[?25l");
	fflush(stdout);
}

void	ft_after_move(t_cube *cube)
{
	cube->moves++;
	if (cube->animate == 0)
		return ;
	if (cube->animate == 1)
		ft_frame(cube, "Mixing...", 0);
	else
		ft_frame(cube, "Resolving...", 0);
	usleep(150000);
}
