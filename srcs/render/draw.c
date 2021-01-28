/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:26:11 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/28 14:03:13 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/paint.h"

void	clean_window(t_view *view)
{
	t_settings settings = *view->settings;
	for (int i = 0; i < settings.width; i++)
		for (int j = 0; j < settings.height - 66; j++)
			put_pixel(view->image, i, j, 0x0FFFFFF);
	render_frame(view);
}

void	draw_point(int x, int y, int rgb, t_view *view)
{
	int	i;
	int width = view->width;

	i = 0;
	for(int ny=-width; ny<=width; ny++)
    	for(int nx=-width; nx<=width; nx++)
       		if(nx*nx+ny*ny <= width*width)
			   	if (ny + y < 750 - 64)
					put_pixel(view->image, nx + x, ny + y, rgb);
}

void    draw_line(t_point p0, t_point p1, t_view *mlx, int rgb)
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
							draw_point(p0.x, p0.y, rgb, mlx);
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
							draw_point(p0.x, p0.y, rgb, mlx);
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
							draw_point(p0.x, p0.y, rgb, mlx);
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
							draw_point(p0.x, p0.y, rgb, mlx);
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
					draw_point(p0.x, p0.y, rgb, mlx);
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
							draw_point(p0.x, p0.y, rgb, mlx);
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
							draw_point(p0.x, p0.y, rgb, mlx);
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
							draw_point(p0.x, p0.y, rgb, mlx);
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
							draw_point(p0.x, p0.y, rgb, mlx);
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
					draw_point(p0.x, p0.y, rgb, mlx);
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
					draw_point(p0.x, p0.y, rgb, mlx);
            }
            else
            {
                while (p0.y-- != p1.y)
					draw_point(p0.x, p0.y, rgb, mlx);
            }
        }
    }
	render_frame(mlx);
}

void	draw_icons_line(t_view *view)
{
	t_point	point_a;
	t_point	point_b;

	point_a.x = 0;
	point_a.y = 750 - 64;
	point_b.x = view->settings->width;
	point_b.y = 750 - 64;
	draw_line_out(point_a, point_b, view, 0x0000000);
}

void flood_fill(t_view *view, int x, int y, int oldcolor, int newcolor)
{
	if (oldcolor == newcolor) return ;
	//printf("test %d %d\n", x, y);
	if (get_pixel_color(view->image, x, y) == oldcolor)
	{
		//printf("color %d %d = %d\n", x, y, oldcolor);
		put_pixel(view->image, x, y, newcolor);
		if (x < view->settings->width - 1)
			flood_fill(view, x + 1, y, oldcolor, newcolor);
		if (y < view->settings->height - 66)
			flood_fill(view, x, y + 1, oldcolor, newcolor);
		if (x > 0)
			flood_fill(view, x - 1, y, oldcolor, newcolor);
		if (y > 0)
			flood_fill(view, x, y - 1, oldcolor, newcolor);
	}
}
