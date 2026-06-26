/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 11:24:53 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/24 11:24:55 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void    rotate_face_cw(t_cube *cube, int face)
{
	int	tmp;

	tmp = cube->face[face][0][0];
	cube->face[face][0][0] = cube->face[face][2][0];
	cube->face[face][2][0] = cube->face[face][2][2];
	cube->face[face][2][2] = cube->face[face][0][2];
	cube->face[face][0][2] = tmp;

	tmp = cube->face[face][0][1];
	cube->face[face][0][1] = cube->face[face][1][0];
	cube->face[face][1][0] = cube->face[face][1][2];
	cube->face[face][1][2] = cube->face[face][2][1];
	cube->face[face][2][1] = tmp;
}

void    rotate_face_ccw(t_cube *cube, int face)
{
	int	tmp;

	tmp = cube->face[face][0][2];
	cube->face[face][0][2] = cube->face[face][2][2];
	cube->face[face][2][2] = cube->face[face][2][0];
	cube->face[face][2][0] = cube->face[face][0][0];
	cube->face[face][0][0] = tmp;

	tmp = cube->face[face][2][1];
	cube->face[face][2][1] = cube->face[face][1][2];
	cube->face[face][1][2] = cube->face[face][1][0];
	cube->face[face][1][0] = cube->face[face][0][1];
	cube->face[face][0][1] = tmp;
}

void    ft_move_u(t_cube *cube)
{
	int	tmp;

	rotate_face_cw(cube, UP);
	tmp = cube->face[FRONT][0][0];
	cube->face[FRONT][0][0] = cube->face[RIGHT][0][0];
	cube->face[RIGHT][0][0] = cube->face[BACK][0][0];
	cube->face[BACK][0][0] = cube->face[LEFT][0][0];
	cube->face[LEFT][0][0] = tmp;

	tmp = cube->face[FRONT][0][1];
	cube->face[FRONT][0][1] = cube->face[RIGHT][0][1];
	cube->face[RIGHT][0][1] = cube->face[BACK][0][1];
	cube->face[BACK][0][1] = cube->face[LEFT][0][1];
	cube->face[LEFT][0][1] = tmp;

	tmp = cube->face[FRONT][0][2];
	cube->face[FRONT][0][2] = cube->face[RIGHT][0][2];
	cube->face[RIGHT][0][2] = cube->face[BACK][0][2];
	cube->face[BACK][0][2] = cube->face[LEFT][0][2];
	cube->face[LEFT][0][2] = tmp;
}


void    ft_move_u_prime(t_cube *cube)
{
	int	tmp;

	rotate_face_ccw(cube, UP);
	tmp = cube->face[LEFT][0][0];
	cube->face[LEFT][0][0] = cube->face[BACK][0][0];
	cube->face[BACK][0][0] = cube->face[RIGHT][0][0];
	cube->face[RIGHT][0][0] = cube->face[FRONT][0][0];
	cube->face[FRONT][0][0] = tmp;

	tmp = cube->face[LEFT][0][1];
	cube->face[LEFT][0][1] = cube->face[BACK][0][1];
	cube->face[BACK][0][1] = cube->face[RIGHT][0][1];
	cube->face[RIGHT][0][1] = cube->face[FRONT][0][1];
	cube->face[FRONT][0][1] = tmp;

	tmp = cube->face[LEFT][0][2];
	cube->face[LEFT][0][2] = cube->face[BACK][0][2];
	cube->face[BACK][0][2] = cube->face[RIGHT][0][2];
	cube->face[RIGHT][0][2] = cube->face[FRONT][0][2];
	cube->face[FRONT][0][2] = tmp;
}

void    ft_move_d(t_cube *cube)
{
	int tmp;

	rotate_face_cw(cube, DOWN);
	tmp = cube->face[FRONT][2][0];
	cube->face[FRONT][2][0] = cube->face[LEFT][2][0];
	cube->face[LEFT][2][0] = cube->face[BACK][2][0];
	cube->face[BACK][2][0] = cube->face[RIGHT][2][0];
	cube->face[RIGHT][2][0] = tmp;

	tmp = cube->face[FRONT][2][1];
	cube->face[FRONT][2][1] = cube->face[LEFT][2][1];
	cube->face[LEFT][2][1] = cube->face[BACK][2][1];
	cube->face[BACK][2][1] = cube->face[RIGHT][2][1];
	cube->face[RIGHT][2][1] = tmp;

	tmp = cube->face[FRONT][2][2];
	cube->face[FRONT][2][2] = cube->face[LEFT][2][2];
	cube->face[LEFT][2][2] = cube->face[BACK][2][2];
	cube->face[BACK][2][2] = cube->face[RIGHT][2][2];
	cube->face[RIGHT][2][2] = tmp;
}

void    ft_move_d_prime(t_cube *cube)
{
	int tmp;

	rotate_face_ccw(cube, DOWN);
	tmp = cube->face[RIGHT][2][0];
	cube->face[RIGHT][2][0] = cube->face[BACK][2][0];
	cube->face[BACK][2][0] = cube->face[LEFT][2][0];
	cube->face[LEFT][2][0] = cube->face[FRONT][2][0];
	cube->face[FRONT][2][0] = tmp;

	tmp = cube->face[RIGHT][2][1];
	cube->face[RIGHT][2][1] = cube->face[BACK][2][1];
	cube->face[BACK][2][1] = cube->face[LEFT][2][1];
	cube->face[LEFT][2][1] = cube->face[FRONT][2][1];
	cube->face[FRONT][2][1] = tmp;

	tmp = cube->face[RIGHT][2][2];
	cube->face[RIGHT][2][2] = cube->face[BACK][2][2];
	cube->face[BACK][2][2] = cube->face[LEFT][2][2];
	cube->face[LEFT][2][2] = cube->face[FRONT][2][2];
	cube->face[FRONT][2][2] = tmp;
}
void    ft_move_f(t_cube *cube)
{
	rotate_face_cw(cube, FRONT);
	tmp = cube->face[UP][2][0];
	cube->face[UP][2][0] = cube->face[RIGHT][0][0];
	cube->face[RIGHT][0][0] = cube->face[DOWN][0][2];
	cube->face[DOWN][0][2] = cube->face[LEFT][2][2];
	cube->face[LEFT][2][2] = tmp;

	tmp = cube->face[UP][2][1];
	cube->face[UP][2][1] = cube->face[RIGHT][1][0];
	cube->face[RIGHT][1][0] = cube->face[DOWN][0][1];
	cube->face[DOWN][0][1] = cube->face[LEFT][1][2];
	cube->face[LEFT][1][2] = tmp;

	tmp = cube->face[UP][2][2];
	cube->face[UP][2][2] = cube->face[RIGHT][2][0];
	cube->face[RIGHT][2][0] = cube->face[DOWN][0][0];
	cube->face[DOWN][0][0] = cube->face[LEFT][0][2];
	cube->face[LEFT][0][2] = tmp;
}

void    ft_move_f_prime(t_cube *cube)
{
	int	tmp;

	rotate_face_ccw(cube, FRONT);
	tmp = cube->face[LEFT][2][2];
	cube->face[LEFT][2][2] = cube->face[DOWN][0][2];
	cube->face[DOWN][0][2] = cube->face[RIGHT][0][0];
	cube->face[RIGHT][0][0] = cube->face[UP][2][0];
	cube->face[UP][2][0] = tmp;

	tmp = cube->face[LEFT][1][2];
	cube->face[LEFT][1][2] = cube->face[DOWN][0][1];
	cube->face[DOWN][0][1] = cube->face[RIGHT][1][0];
	cube->face[RIGHT][1][0] = cube->face[UP][2][1];
	cube->face[UP][2][1] = tmp;

	tmp = cube->face[LEFT][0][2];
	cube->face[LEFT][0][2] = cube->face[DOWN][0][0];
	cube->face[DOWN][0][0] = cube->face[RIGHT][2][0];
	cube->face[RIGHT][2][0] = cube->face[UP][2][2];
	cube->face[UP][2][2] = tmp;
}

void    ft_move_b(t_cube *cube)
{
	int	tmp;

	rotate_face_cw(cube, BACK);
	tmp = cube->face[UP][0][0];
	cube->face[UP][0][0] = cube->face[RIGHT][0][2];
	cube->face[RIGHT][0][2] = cube->face[DOWN][2][2];
	cube->face[DOWN][2][2] = cube->face[LEFT][2][0];
	cube->face[LEFT][2][0] =tmp;

	tmp = cube->face[UP][0][1];
	cube->face[UP][0][1] = cube->face[RIGHT][1][2];
	cube->face[RIGHT][1][2] = cube->face[DOWN][2][1];
	cube->face[DOWN][2][1] = cube->face[LEFT][1][0];
	cube->face[LEFT][1][0] = tmp;

	tmp = cube->face[UP][0][2];
	cube->face[UP][0][2] = cube->face[RIGHT][2][2];
	cube->face[RIGHT][2][2] = cube->face[DOWN][2][0];
	cube->face[DOWN][2][0] = cube->face[LEFT][0][0];
	cube->face[LEFT][0][0] = tmp;
}

void    ft_move_b_prime(t_cube *cube)
{
	int	tmp;

	rotate_face_ccw(cube, BACK);
	tmp = cube->face[LEFT][2][0];
	cube->face[LEFT][2][0] = cube->face[DOWN][2][2];
	cube->face[DOWN][2][2] = cube->face[RIGH][0][2];
	cube->face[RIGHT][0][2] = cube->face[UP][0][0];
	cube->face[UP][0][0] = tmp;

	tmp = cube->face[LEFT][1][0]:
	cube->face[LEFT][1][0] = cube->face[DOWN][2][1];
	cube->face[DOWN][2][1] = cube->face[RIGHT][1][2];
	cube->face[RIGHT][1][2] = cube->face[UP][0][1];
	cube->face[UP][0][1] = tmp;

	tmp = cube->face[LEFT][0][0];
	cube->face[LEFT][0][0] = cube->face[DOWN][2][0];
	cube->face[DOWN][2][0] = cube->face[RIGHT][2][2];
	cube->face[RIGHT][2][2] = cube->face[UP][0][2];
	cube->face[UP][0][2] = tmp;
}

void    ft_move_l(t_cube *cube)
{
	int	tmp;

	rotate_face_cw(cube, LEFT);
	tmp = cube->face[UP][0][0];
	cube->face[UP][0][0] = cube->face[FRONT][0][0];
	cube->face[FRONT][0][0] = cube->face[DOWN][0][0];
	cube->face[DOWN][0][0] = cube->face[BACK][2][2];
	cube->face[BACK][2][2] = tmp;

	tmp = cube->face[UP][1][0];
	cube->face[UP][1][0] = cube->face[FRONT][1][0];
	cube->face[FRONT][1][0] = cube->face[DOWN][1][0];
	cube->face[DOWN][1][0] = cube->face[BACK][1][2];
	cube->face[BACK][1][2] = tmp;

	tmp = cube->face[UP][2][0];
	cube->face[UP][2][0] = cube->face[FRONT][2][0];
	cube->face[FRONT][2][0] = cube->face[DOWN][2][0];
	cube->face[DOWN][2][0] = cube->face[BACK][0][2];
	cube->face[BACK][0][2] = tmp;
}
void    ft_move_l_prime(t_cube *cube)
void    ft_move_r(t_cube *cube)
void    ft_move_r_prime(t_cube *cube)
