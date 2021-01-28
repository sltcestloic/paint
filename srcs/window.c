/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:57:02 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/28 14:09:09 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/paint.h"

int		handle_keypress(int keycode, t_view *view)
{
	if (keycode == 53)
	{
   		mlx_destroy_window(view->mlx, view->window);
		exit(0);
	}
	else if (keycode == 49)
		clean_window(view);
	return (0);
}

int		handle_close_button()
{
	exit(0);
	return (0);
}

void	add_icon(t_view *view, char *path)
{
	static int	total_width = 0;
	static int	icon_count = 0;
	t_icon		icon;
	t_point		a;
	t_point		b;

	icon.img = mlx_xpm_file_to_image(view->mlx, path, &icon.width, &icon.height);
	mlx_put_image_to_window(view->mlx, view->window, icon.img, total_width + 2, view->settings->height - icon.height);
	a.x = total_width;
	a.y = view->settings->height;
	icon.point_a = a;
	total_width += icon.width + 2;
	b.x = total_width - 2;
	b.y = view->settings->height - icon.height;
	icon.point_b = b;
	view->icons[icon_count] = icon;
	icon_count++;
}

void	init_window(t_settings settings)
{
	t_view	view;
	t_mouse	mouse;
	t_image	img;

	view.mlx = mlx_init();
	view.window = mlx_new_window(view.mlx, settings.width, settings.height, "Paint");
	img.img = mlx_new_image(view.mlx, settings.width, settings.height - 66);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	mouse.x = -1;
	mouse.y = -1;
	mouse.pressed = 0;
	view.settings = &settings;
	view.mouse = &mouse;
	view.draw = 0;
	mlx_hook(view.window, 4, 1L<<2, handle_click, &view);
	mlx_hook(view.window, 5, 1L<<3, handle_click_release, &view);
	mlx_hook(view.window, 2, 1L<<0, handle_keypress, &view);
	mlx_hook(view.window, 17, 1L<<17, handle_close_button, 0);
	mlx_hook(view.window, 6, 1L<<6, handle_mouse_motion, &view);
	for (int i = 0; i < settings.width; i++)
		for (int j = 0; j < settings.height - 66; j++)
			put_pixel(&img, i, j, 0x0FFFFFF);
	for (int i = 0; i < settings.width; i++)
		for (int j = settings.height - 66; j < settings.height; j++)
			mlx_pixel_put(view.mlx, view.window, i, j, 0x0FFFFFF);
	view.image = &img;
	view.width = 2;
	add_icon(&view, "/Users/lbertran/Desktop/work/paint/textures/pinceau.xpm");
	add_icon(&view, "/Users/lbertran/Desktop/work/paint/textures/crayon.xpm");
	add_icon(&view, "/Users/lbertran/Desktop/work/paint/textures/bucket.xpm");
	add_icon(&view, "/Users/lbertran/Desktop/work/paint/textures/eraser.xpm");
	switch_mode(&view, FREE);
	render_frame(&view);
	mlx_loop(view.mlx);
}
