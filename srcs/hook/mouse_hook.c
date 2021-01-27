/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:23:32 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/27 15:02:12 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/paint.h"

int		handle_click(int button, int x, int y, t_view *view)
{
	t_point	point;

	point.x = x;
	point.y = y;

	printf("press %d %d %d color: %d\n", button, x, y, get_pixel_color(view->image,x,y));
	if (button == 1)
	{
		view->mouse->pressed = 1;
		if (view->mode == FREE)
		{
			view->mouse->point_a.x = x;
			view->mouse->point_a.y = y;
			view->draw = 1;
			draw_point(x, y, 0x0000000, view);
		}
		for (int i = 0; i < 3; i++)
			if (point_is_in_area(point, view->icons[i].point_a, view->icons[i].point_b))
			{
				view->draw = 0;
				switch_mode(view, i);
				return (0);
			}
		if (view->mode == LINE)
		{
			printf("%d\n", view->draw);
			if (view->draw == 0)
			{
				draw_point(x, y, 0x0000000, view);
				view->mouse->point_a.x = x;
				view->mouse->point_a.y = y;
				view->draw = 1;
				printf("%d\n", view->draw);
				
			}
			else
			{
				view->mouse->point_b.x = x;
				view->mouse->point_b.y = y;
				view->draw = 0;
				draw_line(view->mouse->point_a, view->mouse->point_b, view, 0x0000000); //pas lui
			}
		}
		else if (view->mode == FILL)
		{
			flood_fill(view, x, y, get_pixel_color(view->image, x, y), 0x0000000);
		}
	}
	else if (button == 2)
	{
		if (view->draw == 1)
		{
			draw_point(view->mouse->point_a.x, view->mouse->point_a.y, 0x0FFFFFF, view);
			view->draw = 0;
		}
	}
	return (0);
}

int		handle_click_release(int button, int x, int y, t_view *view)
{
	(void)x;
	(void)y;
	if (button == 1)
		view->mouse->pressed = 0;
	return (0);
}

int		handle_mouse_motion(int x, int y, t_view *view)
{
	if (view->mouse->pressed && view->mode == FREE)
	{
		if (view->draw == 0)
		{
			view->mouse->point_a.x = x;
			view->mouse->point_a.y = y;
			view->draw = 1;
		}
		else
		{
			view->mouse->point_b.x = x;
			view->mouse->point_b.y = y;
			view->draw = 0;
			draw_line(view->mouse->point_a, view->mouse->point_b, view, 0x0000000); //pas lui
			handle_mouse_motion(x, y, view);
		}
	}
	return (0);
}
