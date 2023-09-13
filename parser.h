#ifndef PARSERS_H
#define PARSERS_H

#include "cub3d.h"
// Define the parsers array here

void parse_resolution(const char *str, t_resolution *resolution);
void parse_texture(const char *str, t_texture *texture);
void parse_color(const char *str, t_color *color);
typedef struct
{
    const char *identifier;
    void (*parser)(const char *, void *); // This is correct for second argument type
} IdentifierParser;

extern IdentifierParser parsers[];

// IdentifierParser parsers[] = {
//     {"R", parse_resolution},
//     {"NO", parse_texture},
//     {"SO", parse_texture},
//     {"WE", parse_texture},
//     {"EA", parse_texture},
//     {"F", parse_color},
//     {"C", parse_color},
// };

#endif // PARSERS_H
