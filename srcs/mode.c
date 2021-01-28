/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:30:00 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/28 10:22:02 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/paint.h"

void	switch_mode(t_view *view, int mode)
{
	t_point	a;
	
	if (mode > 2) return ;
	view->mode = mode;
	a = view->icons[mode].point_a;
	a.y -= 64;
	draw_icons_line(view);
	printf("mode: %d\n", mode);
	draw_line_out(a, view->icons[mode].point_b, view->mlx, rgbint(255, 0, 0));
}
