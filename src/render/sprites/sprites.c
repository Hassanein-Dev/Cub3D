/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharaf- <hsharaf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:08:49 by hsharaf-          #+#    #+#             */
/*   Updated: 2025/09/17 16:08:58 by hsharaf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/render.h"

int	iabs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	check_transparency(char *tex_pixel)
{
	unsigned char	b;
	unsigned char	gch;
	unsigned char	r;

	b = (unsigned char)tex_pixel[0];
	gch = (unsigned char)tex_pixel[1];
	r = (unsigned char)tex_pixel[2];
	if (gch > 200 && r < 50 && b < 50)
		return (1);
	if (r == 0 && gch == 0 && b == 0)
		return (1);
	return (0);
}
