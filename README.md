# FDF_42

Estudiar este code

void alg_bresenham(t_ejes *eje, int x1, int y1, t_vars vars)
{
    t_bress *bress;

    bress = init_bress(eje->pos_x, eje->pos_y, x1, y1);

    mlx_pixel_put(vars.mlx, vars.win, eje->pos_x, eje->pos_y, 0xFFFFFF);

    if (bress->dif_x >= bress->dif_y)  // Si la diferencia en X es mayor o igual a la de Y
    {
        while (eje->pos_x != x1)
        {
            eje->pos_x++;
            if (y1 > eje->pos_y)
                eje->pos_y++;  // Si y1 es mayor que y, incrementar y
            else
                eje->pos_y--;  // Si no, decrementar y

            if (bress->dif_y * (eje->pos_x - eje->pos_x + 1) >= bress->dif_x * (eje->pos_y - eje->pos_y + 1))
            {
                if (y1 > eje->pos_y)
                    eje->pos_y++;  // Si y1 es mayor que y, incrementar y
                else
                    eje->pos_y--;  // Si no, decrementar y
            }
            mlx_pixel_put(vars.mlx, vars.win, eje->pos_x, eje->pos_y, 0xFFFFFF);
        }
    }
    else  // Si la diferencia en Y es mayor
    {
        while (eje->pos_y != y1)
        {
            eje->pos_y++;
            if (x1 > eje->pos_x)
                eje->pos_x++;  // Si x1 es mayor que x, incrementar x
            else
                eje->pos_x--;  // Si no, decrementar x

            if (bress->dif_x * (eje->pos_y - eje->pos_y + 1) >= bress->dif_y * (eje->pos_x - eje->pos_x + 1))
            {
                if (x1 > eje->pos_x)
                    eje->pos_x++;  // Si x1 es mayor que x, incrementar x
                else
                    eje->pos_x--;  // Si no, decrementar x
            }
            mlx_pixel_put(vars.mlx, vars.win, eje->pos_x, eje->pos_y, 0xFFFFFF);
        }
    }

    mlx_loop(vars.mlx);  // Mantiene la ventana abierta
}
