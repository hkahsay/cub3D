#include "../cub3d.h"

int color_ranges_valid(int *r, int *g, int *b)
{
    return (*r >= 0 && *r <= 255 && *g >= 0 && *g <= 255 && *b >= 0 && *b <= 255);

}
