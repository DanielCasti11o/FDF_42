/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:23:39 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/24 16:23:48 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*init_coord(t_ejes *eje)
{
	t_coord	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_coord));
	new->x1 = eje->matx_z;
	new->y1 = eje->matx_z;
	while (new->x1[i] && new->y1[i])
	{
		new->x1[i] = 0;
		new->y1[i] = 0;
	}
	return (new);
}

t_coord	*find_coord_iso(t_ejes *eje)
{
	t_coord	*coord;
	float	coor_x1;
	float	coor_y1;
	int		i;
	int		eje_y;

	i = 0;
	eje_y = 0;
	coord = init_coord(eje);
	while (eje_y < eje->len_y)
	{
		while (eje->len_x[i])
		{
			coor_x1 = (eje->len_x[i] - eje_y) * cos(30);
			coor_y1 = (eje->len_x[i] + eje_y) * sin(30) - eje->matx_z[i][eje_y];
			coord->x1[eje_y][i] = round(coor_x1);
			coord->y1[eje_y][i] = round(coor_y1);
			i++;
		}
		eje_y++;
	}
	return (coord);
}
