/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:11:04 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/26 11:14:21 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/paint.h"

int		point_is_in_area(t_point point, t_point a, t_point b)
{
	if (a.x < b.x)
	{
		if (a.y < b.y)
			return (point.x >= a.x && point.y >= a.y && point.x <= b.x && point.y <= b.y);
		else
			return (point.x >= a.x && point.y >= b.y && point.x <= b.x && point.y <= a.y);
	}
	else
	{
		if (a.y < b.y)
			return (point.x >= b.x && point.y >= a.y && point.x <= a.x && point.y <= b.y);
		else
			return (point.x >= b.x && point.y >= b.y && point.x <= a.x && point.y <= a.y);
	}
}