# ifndef PARSER_H
# define PARSER_H

# include "structure.h"
// Define the parsers array here
typedef void				(*t_parser)(const char *, void *);
typedef struct s_identifier_parser
{
	const char	*identifier;
	t_parser	parser;
} t_identifier_parser;

void	get_identifier_parsers(char **parsers);
// void parse_resolution(const char *str, t_resolution *resolution);
void				parse_texture(const char *str, void *data);
void				parse_color(const char *str, void *data);
// Define the parsers array getter function

#endif // PARSERS_H
