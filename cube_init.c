#include "cube.h"

t_cube	cube_init(void)
{
	t_cube cube;
	int	face;
	int	line;
	int	column;

	face = 0;
	while (face < 6)
	{
		line = 0;
		while (line < 3)
		{
			column = 0;
			while (column < 3)
			{
				cube.face[face][line][column] = face;
				column++;
			}
			line++;
		}
		face++;
	}
	return (cube);
}
