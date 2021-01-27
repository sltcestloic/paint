/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:46:43 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/27 12:38:29 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/paint.h"

int	rgbint(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	return (65536 * r + 256 * g + b);
}

int		randomrgb()
{
	time_t	t;

	srand(time(&t));
	return (rgbint(rand() % 255, rand() % 255, rand() % 255));
}
