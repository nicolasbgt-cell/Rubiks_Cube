/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 08:44:27 by nbigot            #+#    #+#             */
/*   Updated: 2026/06/24 11:27:37 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#define WHITE 0
#define YELLOW 1
#define RED 2
#define ORANGE 3
#define BLUE 4
#define GREEN 5

#define UP 0
#define DOWN 1
#define FRONT 2
#define BACK 3
#define LEFT 4
#define RIGHT 5

typedef struct	s_cube
{
	int face[6][3][3];
}				t_cube;

t_cube	cube_init(void);

void	ft_display(t_cube *cube);

void	rotate_face_cw(t_cube *cube, int face);
void	rotate_face_ccw(t_cube *cube, int face);
void	ft_move_u(t_cube *cube);
void	ft_move_u_prime(t_cube *cube);
void	ft_move_d(t_cube *cube);
void	ft_move_d_prime(t_cube *cube);
void	ft_move_f(t_cube *cube);
void	ft_move_f_prime(t_cube *cube);
void	ft_move_b(t_cube *cube);
void	ft_move_b_prime(t_cube *cube);
void	ft_move_l(t_cube *cube);
void	ft_move_l_prime(t_cube *cube);
void	ft_move_r(t_cube *cube);
void	ft_move_r_prime(t_cube *cube);

void	ft_shuffle(t_cube *cube);

int	ft_white_cross(t_cube *cube);
void	ft_solve_white_cross(t_cube *cube);
int	is_goal(t_cube *cube);
t_cube	apply_move(t_cube *cube, int move);

#endif
