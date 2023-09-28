#include "../../includes/cub3d.h"

void    move_forward(t_game *game)
{
    t_ray_coord *update;

    update = &game->player.pos;
    update->x += cos(game->player.rotAngle) * game->player.moveSpeed;
    update->y += sin(game->player.rotAngle) * game->player.moveSpeed;
    if(game->data->map_data.map[pixel_to_coord(update->y)][pixel_to_coord(update->x)] == '0')
    {
        game->player.pos.x = update->x;
        game->player.pos.y = update->y;
    }
}

void    move_backward(t_game *game)
{
    t_ray_coord *update;

    update = &game->player.pos;
    update->x -= cos(game->player.rotAngle) * game->player.moveSpeed;
    update->y -= sin(game->player.rotAngle) * game->player.moveSpeed;
    if(game->data->map_data.map[pixel_to_coord(update->y)][pixel_to_coord(update->x)] == '0')
    {
        game->player.pos.x = update->x;
        game->player.pos.y = update->y;
    }
}

void move_left(t_game *game)
{
    t_ray_coord *update;

    update = &game->player.pos;
    update->x += cos(game->player.rotAngle + angle_to_rad(-90)) * game->player.moveSpeed;
    update->y += sin(game->player.rotAngle + angle_to_rad(-90)) * game->player.moveSpeed;
    if(game->data->map_data.map[pixel_to_coord(update->y)][pixel_to_coord(update->x)] == '0')
    {
        game->player.pos.x = update->x;
        game->player.pos.y = update->y;
    }
}

void    move_right(t_game *game)
{
    t_ray_coord *update;

    update = &game->player.pos;
    update->x += cos(game->player.rotAngle + angle_to_rad(90)) * game->player.moveSpeed;
    update->y += sin(game->player.rotAngle + angle_to_rad(90)) * game->player.moveSpeed;
    if(game->data->map_data.map[pixel_to_coord(update->y)][pixel_to_coord(update->x)] == '0')
    {
        game->player.pos.x = update->x;
        game->player.pos.y = update->y;
    }
}