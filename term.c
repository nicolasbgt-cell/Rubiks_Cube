#include "cube.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void	ft_sigint(int sig)
{
	(void)sig;
	write(1, "\033[?25h\033[?1049l", 14);
	_exit(130);
}

void	ft_term_enter(void)
{
	signal(SIGINT, ft_sigint);
	ft_putstr("\033[?1049h\033[?25l");
	fflush(stdout);
}

void	ft_term_leave(void)
{
	ft_putstr("\033[?25h\033[?1049l");
	fflush(stdout);
}
