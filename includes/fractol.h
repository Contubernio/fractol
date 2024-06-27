/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:42:56 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 15:08:44 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>

// Constants
# define WIDTH 880
# define HEIGHT 660
# define COLOR_SCHEMES 8
# define FRACTAL_TRICORN 3

// Structs
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	double	zoom;
	double	move_x;
	double	move_y;
	int		fractal_type;
	double	c_re;
	double	c_im;
	int		color_scheme;
}	t_data;
typedef struct s_fractal_params
{
	double	param1;
	double	param2;
	double	c1;
	double	c2;
	int		max_iter;
}	t_fractal_params;

typedef struct s_mouse_params
{
	double	x;
	double	y;
	double	zoom;
	double	move_x;
	double	move_y;
	int		win_x;
	int		win_y;
}	t_mouse_params;

// Functions
void	display_msg(const char *msg);
void	draw_mandelbrot(t_data *data);
void	draw_julia(t_data *data);
void	draw_tricorn(t_data *data);
void	draw_man_col(t_data *data, int x, double x_s, double y_s);
void	draw_jul_col(t_data *data, int y, double s_x, double s_y);
void	draw_tri_col(t_data *data, int x, double x_s, double y_s);
void	init_colors(int colors[COLOR_SCHEMES][3]);
void	hooks(t_data *data);
void	move_handle(int keycode, t_data *data);
void	color_scheme(int keycode, t_data *data);
void	calc_mouse(t_mouse_params *params, double *mouse_x, double *mouse_y);
void	zoom_handle(int button, t_data *data, t_mouse_params *params);
void	julia_view(t_data *data);
void	select_fractal(t_data *data);
void	display_info(void);
void	display_usage(void);
int		calc_mandel(t_fractal_params *params);
int		calc_julia(t_fractal_params *params);
int		calc_tricorn(t_fractal_params *params);
void	set_color(t_data *data, int x, int y, int iteration);
void	init_data(t_data *data);
void	set_julia_params(t_data *data, int param);
void	validate_julia_param(int param);
void	assign_julia_values(t_data *data, int param);
void	validate_params(t_data *data);
int		initial_validation(int argc, char **argv, t_data *data);
int		final_validation(int argc, char **argv, t_data *data, int *julia_param);
int		validate_args(int argc, char **argv, t_data *data, int *julia_param);
int		check_fractal_type(int argc, char **argv, t_data *data);
int		check_mandelbrot(int argc);
int		check_julia(int argc, char **argv);
int		check_tricorn(int argc);
int		validate_params_2(int argc, t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int		get_color(int iteration, int max_iteration, int color_scheme);

#endif
