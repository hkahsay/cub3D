#include "../../includes/cub3d.h"
#include "../../includes/parser.h"

void	get_identifier_parsers(t_identifier_parser *parsers)
{
	parsers[0] = (t_identifier_parser){"NO", parse_texture};
	parsers[1] = (t_identifier_parser){"SO", parse_texture};
	parsers[2] = (t_identifier_parser){"WE", parse_texture};
	parsers[3] = (t_identifier_parser){"EA", parse_texture};
	parsers[4] = (t_identifier_parser){"F", parse_color};
	parsers[5] = (t_identifier_parser){"C", parse_color};

}

// static int	error_identifier(char *message)
// {
// 	printf("Error\n");
// 	printf("Unknown identifier: %s\n", message);
// 	exit(EXIT_FAILURE);
// }

void	get_file(char *identifier, char *str, t_sceneData *data,
t_identifier_parser *parsers)
{

	size_t	i;

	i = -1;
	printf("before loop identifier from getfile (%s)\n", identifier);
	while (++i < 6)
	{
		if (!ft_strcmp(identifier, parsers[i].identifier))
		{
			printf("identifier from getfile (%s)\n", identifier);
			if (!ft_strcmp(parsers[i].identifier, "NO"))
				parse_texture(str, &data->north_texture);
			else if (!ft_strcmp(parsers[i].identifier, "SO"))
				parse_texture(str, &data->south_texture);
			else if (!ft_strcmp(parsers[i].identifier, "WE"))
				parse_texture(str, &data->west_texture);
			else if (!ft_strcmp(parsers[i].identifier, "EA"))
				parse_texture(str, &data->east_texture);
			else if (!ft_strcmp(parsers[i].identifier, "F"))
				parse_color(str, &data->floor_color);
			else if (!ft_strcmp(parsers[i].identifier, "C"))
				parse_color(str, &data->ceiling_color);
			else
			{
				printf("enter when the identifiers not matchs\n");
				printf("Error\n");
				printf("Unknown identifier: %s\n", identifier);
				exit(EXIT_FAILURE);
			}
				// error_identifier(identifier);
		}
		// else
		// {
		// 	printf("Error\n");
		// 	printf("Unknown identifier: %s\n", identifier);
		// 	exit(EXIT_FAILURE);
		// }

	}
}

void	parse_texture(const char *str, void *data)
{
	t_texture	*texture;

	texture = (t_texture *)data;
	if (str == NULL)
	{
		printf("Error\n");
		printf(RED"Texture path is NULL.\n"RESET);
		exit(EXIT_FAILURE);
	}
	if (!texture->path)
	{
		texture->path = ft_strdup_const(str);
		texture->path = ft_strtrim(texture->path, " ");
		// texture->tex_height = 64;
		// texture->tex_width = 64;
		if (!texture->path)
		{
			printf("Error\nCould not allocate memory for texture path.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
		texture->path = 0;
}

static void	color_split(char **strs_split, t_color *color)
{
	if (strs_split[0] && strs_split[1] && strs_split[2]
		&& ft_isdigit_strict(strs_split[0])
		&& ft_isdigit_strict(strs_split[1])
		&& ft_isdigit_strict(strs_split[2]))
	{
		color->R = ft_atoi(strs_split[0]);
		color->G = ft_atoi(strs_split[1]);
		color->B = ft_atoi(strs_split[2]);
	}
	else
	{
		printf(RED"Error\n Invalid color format.\n"RESET);
		exit(EXIT_FAILURE);
	}
}

void	parse_color(const char *str, void *data)
{
	t_color	*color;
	char	**strs_split;

	color = (t_color *)data;
	empty_color((char *)str);
	strs_split = ft_split(str, ',');
	if (strs_split == NULL)
	{
		ft_error_msg("Error: could not split color components.");
		free_strs_array(strs_split);
	}
	color_split(strs_split, color);
	free_strs_array(strs_split);
}
