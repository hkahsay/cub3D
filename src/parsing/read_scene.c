/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:02:52 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/25 10:44:20 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_msg2(RED"Error\n"RESET, RED"No file to read"RESET);
	return (fd);
}

// Allocate memory for a string to store the file contents,
// initialize with an empty string.
// Exit the loop if no more lines can be read from the file.
// Concatenate the new line to the existing file contents.
	// char	*combined_map = NULL;
	// char	*temp_map = NULL;
static char	*read_and_combine_lines(int fd)
{
	char	*combined_map;
	char	*current_line;
	char	*temp_map;

	current_line = NULL;
	combined_map = NULL;
	combined_map = ft_strdup("");
	if (!combined_map)
		return (NULL);
	while (1)
	{
		current_line = get_next_line(fd);
		if (current_line == NULL)
			break ;
		temp_map = combined_map;
		combined_map = ft_strjoin(temp_map, current_line);
		free(temp_map);
		free(current_line);
	}
	return (combined_map);
}

static void	parse_scene_data(const char *combined_map, t_sceneData *data)
{
	data->scene = ft_split(combined_map, '\n');
}

void	read_scene(char *file, t_sceneData *data)
{
	char	*combined_map;
	int		fd;

	fd = open_file(file);
	combined_map = read_and_combine_lines(fd);
	if (combined_map)
		parse_scene_data(combined_map, data);
	free(combined_map);
	close_file(fd);
}

int	close_file(int fd)
{
	if (close(fd) == -1)
		ft_error_msg(RED"Error\nCould not close file.\n"RESET);
	return (0);
}
