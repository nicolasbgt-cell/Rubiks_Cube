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

typedef struct	s_cube
{
	int face[6][3][3];
}				t_cube;

t_cube	cube_init(void);
#endif
