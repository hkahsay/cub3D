#include "../../cub3d.h"

int color_ranges_valid(int *r, int *g, int *b)
{
    return (*r >= 0 && *r <= 255 && *g >= 0 && *g <= 255 && *b >= 0 && *b <= 255);

}

void	check_color(t_color *color, char *color_name)
{
	if (color->R == -1)
	{
		printf("Error\nThe %s is not set or poorly "
					"formatted.\n", color_name);
		exit(EXIT_SUCCESS);
	}
	else if (!color_ranges_valid(&color->R, &color->G, &color->B))
    {
        printf(RED"Error\nThe RGB code for the " YELLOW"%s"RED" is "
                    "outof range.\n"RESET, color_name);
        exit(EXIT_SUCCESS);
    }
	color->rgb = create_rgb(color->R, color->G, color->B);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void init_rect_ceiling(t_rect *rect, t_sceneData *data)
{
   rect->x = 0; // X-coordinate of the top-left corner of the rectangle
   rect->y = 0; // Y-coordinate of the top-left corner of the rectangle
   rect->width = MAX_WIDTH; // Width of the rectangle
   rect->height = MAX_HEIGHT; // Height of the rectangle
   rect->border_color = data->ceiling_color.rgb; // Color of the rectangle
}

void init_rect_floor(t_rect *rect, t_sceneData *data)
{
   rect->x = 0; // X-coordinate of the top-left corner of the rectangle
   rect->y = 0; // Y-coordinate of the top-left corner of the rectangle
   rect->width = MAX_WIDTH; // Width of the rectangle
   rect->height = MAX_HEIGHT/ 2; // Height of the rectangle
   rect->border_color = data->floor_color.rgb; // Color of the rectangle
}