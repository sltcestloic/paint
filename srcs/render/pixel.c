/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:15:10 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/27 13:17:21 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/paint.h"

void	put_pixel(t_image *image, int x, int y, int color)
{
    char    *dst;

    dst = image->addr + (y * image->line_len + x * (image->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int		get_pixel_color(t_image *image, int x, int y)
{
    char    *dst;

    dst = image->addr + (y * image->line_len + x * (image->bits_per_pixel / 8));
    return (*(unsigned int*)dst);
}
