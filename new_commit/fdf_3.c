/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:23:39 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/26 20:52:12 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*find_coord_iso(t_ejes *eje)
{
	t_coord	*coord;
	float	coor_x1;
	float	coor_y1;
	int		eje_y;
	int		eje_x;

	printf("entra\n");
	eje_y = 0;
	coord = init_coord(eje);
	printf("sale %d\n", eje->len_y);
	while (eje_y < eje->len_y)
	{
		eje_x = 0;
		printf("vez\n");
		while (eje_x < eje->len_x[eje_y])
		{
			coor_x1 = (eje->len_x[eje_y] - eje_y) * cos(30);
			coor_y1 = (eje_x + eje_y) * sin(30) - eje->matx_z[eje_y][eje_x];
			coord->x1[eje_y][eje_x] = round(coor_x1);
			printf("redondeada x %d\n", coord->x1[eje_y][eje_x]);
			coord->y1[eje_y][eje_x] = round(coor_y1);
			printf("redondeada y %d\n", coord->y1[eje_y][eje_x]);
			eje_x++;
		}
		eje_y++;
	}
	return (coord);
}
