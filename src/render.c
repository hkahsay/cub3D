#include "../cub3d.h"

void    rendering(t_sceneData *data)
{
    data->mlx_ptr = mlx_init();
    data->win_mlx = mlx_new_window(data->mlx_ptr, data->resolution.width, data->resolution.height, "cub3D");
    mlx_loop(data->mlx_ptr);
}