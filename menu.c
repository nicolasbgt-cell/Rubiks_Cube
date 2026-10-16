#include "cube.h"
#include <stdio.h>

static int	ft_choice(char *line)
{
	if (line[0] < '1' || line[0] > '0' + MENU_QUIT)
		return (0);
	if (line[1] != '\n' && line[1] != '\0')
		return (0);
	return (line[0] - '0');
}

void	ft_menu(t_cube *cube)
{
	char	line[16];
	char	buf[MSG_SIZE];
	char	*msg;
	int		choice;

	msg = "";
	while (1)
	{
		ft_frame(cube, msg, 1);
		if (!fgets(line, sizeof(line), stdin))
			return ;
		choice = ft_choice(line);
		if (choice == MENU_QUIT)
			return ;
		msg = ft_action(cube, choice, buf);
	}
}
