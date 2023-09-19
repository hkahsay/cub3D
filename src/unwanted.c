// 

typedef struct s_game
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	int		texNum;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	wallX;
	double	step;
	double	texPos;
	double	*zBuffer;
	t_player player;
	t_texture *texture;
} t_game;


static void   draw_map(t_sceneData *data)
{
    int y = 0;
    while (y < data->map_data.m_height)
    {
        int x = 0;
        while (x < data->map_data.m_width)
        {
            if (data->map_data.map[y][x] == '1')
            {
                // my_mlx_pixel_put(data->img.img, x, y, 0x00FF0000);
                mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.win_mlx, x, y, 0x00FF0000);
            }
            else if (data->map_data.map[y][x] == '0')
            {
                // my_mlx_pixel_put(data->img.img, x, y, 0x00000000);
                mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.win_mlx, x, y, 0x0000FF00);
            }
            x++;
        }
        
        y++;
    }

}

void init_graphics(t_game *game)
{
    t_img img;
    game->player.posX = 100;
    game->player.posY= 100;
    game->mlx.mlx_ptr = mlx_init();
    game->mlx.win_mlx = mlx_new_window(game->mlx.mlx_ptr, game->data->resolution.width, game->data->resolution.height, "cub3D");

    // Initialize img.img and img.addr here
    img.img = mlx_new_image(game->mlx.mlx_ptr, game->data->resolution.width, game->data->resolution.height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    // get_textures_img(game, &img);
    get_player(game);
    movment(game);
    // my_mlx_pixel_put(&img, game->player.posX, game->player.posY, 0x00FF0000);
    mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, img.img, 0, 0);
    // mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_mlx, img.img, game->player.posX, game->player.posY);
    // draw_player(game->mlx.mlx_ptr, game->mlx.win_mlx, game->player.posX, game->player.posY);
    mlx_do_sync(game->mlx.mlx_ptr);
    mlx_hook(game->mlx.win_mlx, KEY_EXIT, 0, exit_game, game);//key_press
    mlx_hook(game->mlx.win_mlx, 2, 0, key_press, game);//key_press
    mlx_loop(game->mlx.mlx_ptr);
}

//int cpyMap(char *scene, t_sceneData *data)
// {
//     static int i = 0;
//     int j = 0;

//     if (i >= data->map_data.m_height) {
//         fprintf(stderr, "Error: Too many map lines.\n");
//         exit(EXIT_FAILURE);
//     }

//     j = 0;
//     data->map_data.map[i] = malloc(sizeof(char) * (data->map_data.m_width + 1));
//     if (!data->map_data.map[i]) {
//         fprintf(stderr, "Error: Dynamic allocation failed.\n");
//         exit(EXIT_FAILURE);
//     }

//     while (scene[j] != '\0') {
//         if (scene[j] == ' ') {
//             data->map_data.map[i][j] = '1';
//         } else {
//             data->map_data.map[i][j] = scene[j];
//         }
//         j++;
//     }

//     while (j < data->map_data.m_width) {
//         data->map_data.map[i][j] = '1';
//         j++;
//     }

//     data->map_data.map[i][j] = '\0';
//     i++;
//     return (0);
// }



void get_scene(t_sceneData *data)
{
    int i = 0;
    int mapStartedIndex = 0;
    int mapstarted = 0;
	check_map_elm(data);
    while (data->scene[i] != NULL)
    {
        // printf("Loop iteration: %d\n", i);
        if (mapstarted == 0)
        {
            if (is_map(data->scene[i]) == 1)
            {
                mapStartedIndex = i;
                // printf("map is started at index %d\n", mapStartedIndex);
                mapstarted = 1;
            }
        
        }
        if (mapstarted == 1)
        {
            data->map_data.m_height++;
        }
        else
        {
           
            if (data->scene[i][0] != '\0')
            {
                char *identifier = strtok(data->scene[i], " "); // Assuming identifiers are followed by a space
                char *dataLine = strtok(NULL, ""); // Remaining part of the line
                get_file(identifier, dataLine, data);
                data->elm++;
            }
           
            
        }
       
        i++; // Move to the next identifier/data pair
    }
  
    get_map(data, mapStartedIndex);
    
    print_map(&data->map_data);

}


int		is_map_enclosed(char **map, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ')
			{
				if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
                {
                    printf("map[i][j]: %c\n", map[i][j]);
					return (0);
                }
				else if (map[i - 1][j - 1] == ' ' || map[i - 1][j] == ' '
					|| map[i - 1][j + 1] == ' ' || map[i][j + 1] == ' '
					|| map[i + 1][j + 1] == ' ' || map[i + 1][j] == ' '
					|| map[i + 1][j - 1] == ' ' || map[i][j - 1] == ' ')
                    {
                        printf("map[i - 1][j + 1]: %c\n", map[i - 1][j + 1]);
                    }
					return (0);
			}
		}
	}
	return (1);
}


// void get_map(t_sceneData *data, int mapStartedIndex)
// {
//     int i;
//     data->map_data.m_width = get_width(&data->scene[mapStartedIndex]);
    
//     // Allocate memory for the entire map_data.map array
//     data->map_data.map = malloc(sizeof(char *) * data->map_data.m_height);
//     if (!data->map_data.map)
//     {
//         printf(RED "Dynamic allocation failed\n" RESET);
//         free_map_data(&data->map_data);
//         exit(EXIT_FAILURE);
//     }
//     i = 0;
//     while (i < data->map_data.m_height) 
//     {
//         // Allocate memory for each row in map_data.map
//         data->map_data.map[i] = malloc(sizeof(char) * (data->map_data.m_width + 1));
//         if (!data->map_data.map[i])
//         {
//             printf(RED "Dynamic allocation failed\n" RESET);
//             free_map_data(&data->map_data);
//             exit(EXIT_FAILURE);
//         }

//         // Copy data from scene to map_data.map[i]
//         strcpy(data->map_data.map[i], data->scene[mapStartedIndex + i]);
//         printf("data->map_data.map[%d]: %s\n", i, data->map_data.map[i]);
//         i++;
//     }
// }


// void get_scene(int fd, t_sceneData *data)
// {
//     int i = 0;
//     (void)fd;
//     int mapstarted = 0;
    
//     while (data->scene[i] != NULL)
//     {
//         if (mapstarted == 0)
//         {
//             if (is_map(data->scene[i]) == 1)
//             {
//                 printf("map is started\n");
//                 mapstarted = 1;
//             }
        
//         }
//         if (mapstarted == 1)
//         {
//             data->map_data_height++;
//         }
//         else
//         {
           
//             if (is_map(data->scene[i]) == 0)
//             {
//                 // Extract identifier and data
//                 if (data->scene[i][0] != '\0')
//                 {
//                     char *identifier = strtok(data->scene[i], " "); // Assuming identifiers are followed by a space
//                     char *dataLine = strtok(NULL, ""); // Remaining part of the line
                    
//                     get_file(identifier, dataLine, data);
//                     printf("data->scene[i]: %s\n", data->scene[i]); 
//                     data->elm++;
//                 }
//             }
//             else if(is_map(data->scene[i]) == 1)
//             {
//                 printf("map is started\n");
//                 mapstarted = 1;
//                 break;
//             }
            
//         }
//         i++; // Move to the next identifier/data pair
//     }
//     extract_map_lines(data);

// }

void get_scene(t_sceneData *data)
{
    int i = 0;
    int mapStartedIndex = 0;
    int mapstarted = 0;
    int shouldIncrementHeight = 1; // Flag to control height incrementing

	check_map_elm(data);
    while (data->scene[i] != NULL)
    {
        if (mapstarted == 0)
        {
            if (is_map(data->scene[i]) == 1)
            {
                mapStartedIndex = i;
                mapstarted = 1;
            }
        
        }
        if (mapstarted == 1 && shouldIncrementHeight == 1)
        {
            data->map_data.m_height++;
        }
        else if (mapstarted == 1)
        {
            if (lineContainsNonWhitespace(data->scene[i]) == 0)
            {
                shouldIncrementHeight = 0;
            }
        }
        else
        {

            if (data->scene[i][0] != '\0')
            {
                char *identifier = strtok(data->scene[i], " "); // Assuming identifiers are followed by a space
                char *dataLine = strtok(NULL, ""); // Remaining part of the line
              
                
                get_file(identifier, dataLine, data);
                data->elm++;
            }
        }
        i++; // Move to the next identifier/data pair
    }
  
    get_map(data, mapStartedIndex);
    
    print_map(&data->map_data);
}