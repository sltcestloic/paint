/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:30:00 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/28 14:05:54 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/paint.h"

void	switch_mode(t_view *view, int mode)
{
	t_point	a;
	
	if (mode > 3) return ;
	view->mode = mode;
	a = view->icons[mode].point_a;
	a.y -= 64;
	view->width = 2;
	draw_icons_line(view);
	printf("mode: %d\n", mode);
	draw_line_out(a, view->icons[mode].point_b, view->mlx, rgbint(255, 0, 0));
	if (mode == 3)
		view->width = 10;
}
