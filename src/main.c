/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharaf- <hsharaf-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:35:00 by hsharaf-          #+#    #+#             */
/*   Updated: 2025/11/01 00:09:49 by hsharaf-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_file_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_config	cfg;

	if (argc != 2)
	{
		write(2, "Error\nusage: ./cub3d file.cub\n", 29);
		return (1);
	}
	if (!validate_file_extension(argv[1]))
	{
		write(2, "Error\nMap file must have .cub extension\n", 41);
		return (1);
	}
	if (parse_cub_file(argv[1], &cfg) != 0)
		return (1);
	if (run_game(&cfg) != 0)
	{
		free_config(&cfg);
		return (1);
	}
	free_config(&cfg);
	return (0);
}
