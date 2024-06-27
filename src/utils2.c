/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:49:25 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 13:41:54 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fractol.h"

void	display_usage(void)
{
	const char	*usage = "Usage: ./fractol <fractal_type> [parameter]\n"
		"       fractal_type:\n"
		"           1: Mandelbrot\n"
		"           2: Julia\n"
		"               parameter:\n"
		"                   1: c = -1.3 + 0.00525*i\n"
		"                   2: c = -0.72 - 0.196*i\n"
		"                   3: c = -0.1 + 0.87*i\n"
		"                   4: c = -0.51 - 0.601*i\n"
		"           3: Tricorn\n";

	write(1, usage, ft_strlen(usage));
}

void	display_info(void)
{
	const char	*info = "Program Controls:\n"
		"  Up Arrow       - Move view up\n"
		"  Down Arrow     - Move view down\n"
		"  Left Arrow     - Move view left\n"
		"  Right Arrow    - Move view right\n"
		"  Mouse Scroll   - Zoom in and Zoom out\n"
		"  ESC Key        - Exit the program\n"
		"  Key '/'        - Next color scheme (KeyPad)\n"
		"  Key '*'        - Previous color scheme (KeyPad)\n";

	write(1, info, ft_strlen(info));
}

void	set_color(t_data *data, int x, int y, int iteration)
{
	int	color;
	int	index;

	color = get_color(iteration, 300, data->color_scheme);
	index = (x + y * WIDTH) * 4;
	data->img_data[index + 0] = color;
	data->img_data[index + 1] = color >> 8;
	data->img_data[index + 2] = color >> 16;
}
