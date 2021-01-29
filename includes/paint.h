/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:13:47 by lbertran          #+#    #+#             */
/*   Updated: 2021/01/29 11:32:58 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <time.h>
# include <math.h>

typedef enum		s_mode
{
					FREE = 0,
					LINE = 1,
					FILL = 2,
					ERASER = 3,
					CIRCLE = 4
}					t_mode;

typedef struct		s_settings
{
	int				width;
	int				height;
	t_mode			mode;
}					t_settings;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_mouse
{
	int				pressed;
	int				x;
	int				y;
	t_point			point_a;
	t_point			point_b;
}					t_mouse;

typedef struct		s_icon
{
	void			*img;
	int				width;
	int				height;
	t_point			point_a;
	t_point			point_b;
}					t_icon;

typedef struct		s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}					t_image;

typedef struct		s_view
{
	void			*mlx;
	void			*window;
	t_mouse			*mouse;
	t_settings		*settings;
	t_icon			icons[5];
	t_mode			mode;
	t_image			*image;
	int				draw;
	int				width;
}					t_view;

void				init_window(t_settings settings);

int					print_error(char *message);
int					rgbint(int r, int g, int b);
int					randomrgb();
int					point_is_in_area(t_point point, t_point a, t_point b);

int					handle_click(int button, int x, int y, t_view *view);
int					handle_click_release(int button, int x, int y, t_view *view);
int					handle_mouse_motion(int x, int y, t_view *view);

void				draw_point(int x, int y, int rgb, t_view *view);
void				draw_point_out(int x, int y, int rgb, t_view *view);
void				draw_line(t_point p0, t_point p1, t_view *mlx, int rgb);
void				draw_line_out(t_point p0, t_point p1, t_view *mlx, int rgb);
void				draw_icons_line(t_view *view);
void 				draw_circle(t_view *view, t_point center, t_point ext, int rgb);
void 				flood_fill(t_view *view, int x, int y, int oldcolor, int newcolor);
void				clean_window(t_view *view);

int					render_frame(t_view *view);

void				switch_mode(t_view *view, int mode);

void				put_pixel(t_image *image, int x, int y, int color);
int					get_pixel_color(t_image *image, int x, int y);

#endif
