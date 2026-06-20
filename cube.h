#ifndef CUBE_H
# define CUBE_H

#define WHITE 0
#define YELLOW 1
#define RED 2
#define ORANGE 3
#define BLUE 4
#define GREEN 5

typedef struct	s_cube
{
	int face[6][3][3];
}				t_cube;

#endif
