/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:01:45 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/28 10:25:36 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/paint.h"

int		render_frame(t_view *view)
{
	mlx_put_image_to_window(view->mlx, view->window, view->image->img, 0, 0);
	return (SUCCESS);
}
