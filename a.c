/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:20:38 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/20 20:58:24 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

void	prints(int i, int *len)
{
	t_vars	vars;
	t_ejes	eje;
	int		x;
	int		y;
	int		aux;

	x = 20;
	y = 500;
	aux = 0;
	i += 500;
	len[aux] += 100;
	printf("lenen0 = %d\n", len[aux]);
	printf ("a");
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "Hello world!");
	// mlx_key_hook(vars.win, key_hook, &vars);
	while (len[aux])
	{
		y = 100;
	while (y < i)
	{
		mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
		y++;
	}
	x = 20;
	while (x < len[aux])
	{
			// len[aux] += 100;
		mlx_pixel_put(vars.mlx, vars.win, x, y, 0x00FF00);
		x++;
	}
		aux ++;
		len[aux] += 100;
		// mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
		// y += 10;
	}


	mlx_loop(vars.mlx);
}
