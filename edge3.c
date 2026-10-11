#include "cube.h"

static void	ft_place_edge(t_cube *cube, int edge)
{
	int	pos;

	if (ft_edge_ok(cube, edge))
		return ;
	pos = ft_find_edge(cube, edge);
	if (pos < 4)
		ft_edge_eject(cube, pos);
	ft_edge_insert(cube, edge);
}

void	ft_place_edge1(t_cube *cube)
{
	ft_place_edge(cube, 1);
}

void	ft_place_edge2(t_cube *cube)
{
	ft_place_edge(cube, 2);
}

void	ft_place_edge3(t_cube *cube)
{
	ft_place_edge(cube, 3);
}

void	ft_place_edge4(t_cube *cube)
{
	ft_place_edge(cube, 4);
}
