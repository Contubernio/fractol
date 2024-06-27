/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albealva <albealva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:24:38 by albealva          #+#    #+#             */
/*   Updated: 2024/06/27 14:48:53 by albealva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

void	init_colors(int colors[COLOR_SCHEMES][3])
{
	colors[0][0] = 66;
	colors[0][1] = 30;
	colors[0][2] = 15;
	colors[1][0] = 25;
	colors[1][1] = 7;
	colors[1][2] = 26;
	colors[2][0] = 9;
	colors[2][1] = 1;
	colors[2][2] = 47;
	colors[3][0] = 4;
	colors[3][1] = 4;
	colors[3][2] = 73;
	colors[4][0] = 0;
	colors[4][1] = 7;
	colors[4][2] = 100;
	colors[5][0] = 12;
	colors[5][1] = 44;
	colors[5][2] = 138;
	colors[6][0] = 24;
	colors[6][1] = 82;
	colors[6][2] = 177;
	colors[7][0] = 57;
	colors[7][1] = 125;
	colors[7][2] = 209;
}

int	get_color(int iteration, int max_iteration, int color_scheme)
{
	int		colors[COLOR_SCHEMES][3];
	int		color_index;
	int		red;
	int		green;
	int		blue;

	if (iteration == max_iteration)
	{
		return (0x000000);
	}
	init_colors(colors);
	color_index = color_scheme % COLOR_SCHEMES;
	red = (colors[color_index][0] * iteration) % 256;
	green = (colors[color_index][1] * iteration) % 256;
	blue = (colors[color_index][2] * iteration) % 256;
	return ((red << 16) | (green << 8) | blue);
}

void	display_msg(const char *msg)
{
	write(1, msg, ft_strlen(msg));
}
