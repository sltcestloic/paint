/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:18:37 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/28 10:20:39 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/paint.h"

void	draw_point_out(int x, int y, int rgb, t_view *view)
{
	int	i;

	i = 0;
	for(int ny=-WIDTH; ny<=WIDTH; ny++)
    	for(int nx=-WIDTH; nx<=WIDTH; nx++)
       		if(nx*nx+ny*ny <= WIDTH*WIDTH)
			   	if (ny + y < 750 - 64)
					mlx_pixel_put(view->mlx, view->window, nx + x, ny + y, rgb);
}

void    draw_line_out(t_point p0, t_point p1, t_view *mlx, int rgb)
{
    int     dx;
    int     dy;
    int     e;

	printf("%d %d // %d %d -> %d\n", p0.x, p0.y, p1.x, p1.y, rgb);
    if ((dx = p1.x - p0.x) != 0)
    {
        if (dx > 0)
        {
            if ((dy = p1.y - p0.y) != 0)
            {
                if (dy > 0)
                {
                    if (dx >= dy)
                    {
                        e = dx;
                        dx = e * 2;
                        dy = dy * 2;
                        while (1)
                        {
							draw_point_out(p0.x, p0.y, rgb, mlx);
                            if ((p0.x++) == p1.x)
                                break;
                            if ((e = e - dy) < 0)
                            {
                                p0.y++;
                                e += dx;
                            }
                        }
                    }
                    else
                    {
                        e = dy;
                        dy = e * 2;
                        dx = dx * 2;
                        while (1)
                        {
							draw_point_out(p0.x, p0.y, rgb, mlx);
                            if ((p0.y++) == p1.y)
                                break;
                            if ((e = e - dx) < 0)
                            {
                                p0.x++;
                                e += dy;
                            }
                        }
                    }
                }
                else
                {
                    if (dx >= -dy)
                    {
                        e = dx;
                        dx = e * 2;
                        dy *= 2;
                        while (1)
                        {
							draw_point_out(p0.x, p0.y, rgb, mlx);
                            if ((p0.x++) == p1.x)
                                break;
                            if ((e = e + dy) < 0)
                            {
                                p0.y--;
                                e += dx;
                            }
                        }
                    }
                    else
                    {
                        e = dy;
                        dy = e * 2;
                        dx *= 2;
                        while (1)
                        {
							draw_point_out(p0.x, p0.y, rgb, mlx);
                            if ((p0.y--) == p1.y)
                                break;
                            if ((e = e + dx) > 0)
                            {
                                p0.x++;
                                e += dy;
                            }
                        }
                    }
                }
            }
            else
            {
                while (p0.x++ != p1.x)
					draw_point_out(p0.x, p0.y, rgb, mlx);
            }
        }
        else
        {
            if ((dy = p1.y - p0.y) != 0)
            {
                if (dy > 0)
                {
                    if (-dx >= dy)
                    {
                        e = dx;
                        dx = e * 2;
                        dy = dy * 2;
                        while (1)
                        {
							draw_point_out(p0.x, p0.y, rgb, mlx);
                            if ((p0.x--) == p1.x)
                                break;
                            if ((e = e + dy) >= 0)
                            {
                                p0.y++;
                                e += dx;
                            }
                        }
                    }
                    else
                    {
                        e = dy;
                        dy = e * 2;
                        dx = dx * 2;
                        while (1)
                        {
							draw_point_out(p0.x, p0.y, rgb, mlx);
                            if ((p0.y++) == p1.y)
                                break;
                            if ((e = e + dx) <= 0)
                            {
                                p0.x--;
                                e += dy;
                            }
                        }
                    }
                }
                else
                {
                    if (dx <= dy)
                    {
                        e = dx;
                        dx = e * 2;
                        dy = dy * 2;
                        while (1)
                        {
							draw_point_out(p0.x, p0.y, rgb, mlx);
                            if ((p0.x--) == p1.x)
                                break;
                            if ((e = e - dy) >= 0)
                            {
                                p0.y--;
                                e += dx;
                            }
                        }
                    }
                    else
                    {
                        e = dy;
                        dy = e * 2;
                        dx = dx * 2;
                        while (1)
                        {
							draw_point_out(p0.x, p0.y, rgb, mlx);
                            if ((p0.y--) == p1.y)
                                break;
                            if ((e = e - dx) >= 0)
                            {
                                p0.x--;
                                e += dy;
                            }
                        }
                    }
                }   
            }
            else
            {
                while (p0.x-- != p1.x)
					draw_point_out(p0.x, p0.y, rgb, mlx);
            }
        }
    }
    else
    {
        if ((dy = p1.y - p0.y) != 0)
        {
            if (dy > 0)
            {
                while (p0.y++ != p1.y)
					draw_point_out(p0.x, p0.y, rgb, mlx);
            }
            else
            {
                while (p0.y-- != p1.y)
					draw_point_out(p0.x, p0.y, rgb, mlx);
            }
        }
    }
}