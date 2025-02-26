/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:20:38 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/26 22:38:43 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }

int	max(int difx, int dify)
{
	if (difx < dify)
		return (dify);
	else
		return (difx);
}

int	Vabs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

// void	printlines(int x, int y, int x1, int y1)
// {
// 	int		p;
// 	t_vars	vars;

// 	// x += 10;
// 	// y += 10;
// 	// x1 += 10;
// 	// y1 += 10;
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 2000, 1000, "Hello world!");
// 	while(1)
// 	{
// 		if (x1 > y1)
// 		{
// 			mlx_pixel_put(vars.mlx, vars.win, x + 1, y, 0xFFFFFF);
// 			x++;
// 		}
// 		else
// 		{
// 			mlx_pixel_put(vars.mlx, vars.win, x, y + 1, 0xFFFFFF);
// 			y++;
// 		}
// 		if (x == x1 && y == y1)
// 			break ;
// 		mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
// 		x++;
// 		y++;
// 	}
// 	mlx_loop(vars.mlx);
// }


void	draw(t_ejes *eje)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, EJE_X_W, EJE_X_W, "Hello world!");
	alg_bressenham(eje, 800, 200, vars);
	mlx_loop(vars.mlx);

}

void	slop_x(t_ejes *eje, int x1, int y1, t_vars	vars)
{
	int	error;

	if (bress->dif_x >= bress->dif_y)
		{
			error = (bress->dif_y * 2) - bress->dif_x;
			while (eje->pos_x != x1)
			{
				eje->pos_x++;
				if (error > 0)
				{
					if (y1 > eje->pos_y)
						eje->pos_y++;
					else
						eje->pos_y--;
					error -= bress->dif_x * 2;
				}
				error += bress->dif_y * 2;
				mlx_pixel_put(vars.mlx, vars.win, eje->pos_x, eje->pos_y, 0xFFFFFF);
				}

		}
	}

void	alg_bressenham(t_ejes *eje, int x1, int y1, t_vars	vars)
{
	t_bress	*bress;
	int		error;

	bress = init_bress(eje->pos_x, eje->pos_y, x1, y1);
	while (1)
	{
		mlx_pixel_put(vars.mlx, vars.win, eje->pos_x, eje->pos_y, 0xFFFFFF);
		if (bress->dif_x >= bress->dif_y)
		{
			error = (bress->dif_y * 2) - bress->dif_x;
			while (eje->pos_x != x1)
			{
				eje->pos_x++;
				if (error > 0)
				{
					if (y1 > eje->pos_y)
						eje->pos_y++;
					else
						eje->pos_y--;
					error -= bress->dif_x * 2;
				}
				error += bress->dif_y * 2;
				mlx_pixel_put(vars.mlx, vars.win, eje->pos_x, eje->pos_y, 0xFFFFFF);
			}
		}
		else
		{
			error = (bress->dif_x * 2) - bress->dif_y;
			while (eje->pos_y != y1)
			{
				eje->pos_y++;
				if (error >= 0)
				{
					if (x1 > eje->pos_x)
						eje->pos_x++;
					else
						eje->pos_x--;
					error -= bress->dif_y * 2;
				}
				error += bress->dif_x * 2;
				mlx_pixel_put(vars.mlx, vars.win, eje->pos_x, eje->pos_y, 0xFFFFFF);
			}
		}
		if (eje->pos_x == x1 || eje->pos_y == y1)
			break ;
	}
	mlx_loop(vars.mlx);
}

// void	key_hook(int keycode, t_vars vars)
// {

// }

// void	prints(int i, int *len, t_coord *coord)
// {
// 	t_vars	vars;
// 	t_ejes	eje;
// 	int		pix;
// 	int		x;
// 	int		y;
// 	int		aux;
// 	int		pt = 0;
// 	int		pt_peq = 0;
// 	int		ref;

// 	x = 100;
// 	pix = 0;
// 	ref = 0;
// 	y = 500;
// 	aux = 0;
// 	i += 500;
// 	len[aux] += 100;
// 	printf("lenen0 = %d\n", len[aux]);
// 	printf ("ostras = %d\n", i);
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 2000, 1000, "Hello world!");
// 	while (ref < len[aux])
// 	{
// 		mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
// 		mlx_pixel_put(vars.mlx, vars.win, (coord->y1[pt][pt_peq] + x), (y), 0xFFFFFF);
// 		x++;
// 		while (pix != 15)
// 		{
// 			mlx_pixel_put(vars.mlx, vars.win, x, y, 0x000000);
// 			mlx_pixel_put(vars.mlx, vars.win, x, (coord->y1[pt][pt_peq] + y), 0xFFFFFF);
// 			y++;
// 			pix++;
// 			pt_peq++;
// 		}
// 		pt_peq = 0;
// 		y -= 15;
// 		pix = 0;
// 		mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
// 		mlx_pixel_put(vars.mlx, vars.win, (coord->y1[pt][pt_peq] + x), (y), 0xFFFFFF);
// 		x++;
// 		ref++;
// 		while (pix != 15)
// 		{
// 			mlx_pixel_put(vars.mlx, vars.win, x, y, 0x000000);
// 			x++;
// 			pix++;
// 		}
// 		pix = 0;
// 		if (ref == (len[aux] - 100))
// 		{
// 			printf("aguacate\n");
// 			y++;
// 			pt++;
// 			if (y == i)
// 				break ;
// 			ref = 0;
// 			aux++;
// 			len[aux] += 100;
// 			x = 100;
// 		}
// 		if (y == i)
// 			break ;
// 	}
// 	mlx_loop(vars.mlx);
// }












// mlx_key_hook(vars.win, key_hook, &vars);
	// while (len[aux])
	// {
	// 	y = 100;
	// while (y < i)
	// {
	// 	mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
	// 	y++;
	// }
	// x = 20;
	// while (x < len[aux])
	// {
	// 		// len[aux] += 100;
	// 	mlx_pixel_put(vars.mlx, vars.win, x, y, 0x00FF00);
	// 	x++;
	// }
	// 	aux ++;
	// 	len[aux] += 100;
	// 	// mlx_pixel_put(vars.mlx, vars.win, x, y, 0xFFFFFF);
	// 	// y += 10;
	// }
