#include "../../cub3d.h"
static int is_delimiter(const char *str, const char *delimiters) {
    while (*delimiters) {
        const char *s = str;
        while (*delimiters && *s && *delimiters == *s) {
            delimiters++;
            printf("delimiters: %s\n", delimiters);
            s++;
        }
        if (!*delimiters) {
            return 1; // Found a delimiter match
        }
        delimiters++;
    }
    return 0; // No delimiter match found
}


// Function to trim whitespace and newline characters from both ends of a string
char *trim(char *str)
{
    while (isspace(*str)) {
        str++;
    }
    
    char *end = str + ft_strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }
    
    *(end + 1) = '\0';
    
    return str;
}

static void skip_delimeters(const char **str, const char *delimiters) {
    // Skip leading delimiters
    while (**str && is_delimiter(*str, delimiters))
        (*str)++;
}

static char *find_end_token(char *str, const char *delimiters) {
    char *token;
    ptrdiff_t length;


    token = str;
    while (*str && !is_delimiter(str, delimiters)) {
        printf("str from find: %s\n", str);
        str++;
    }
    // printf("value of token: %s\n", token);
    length = str - token;
    printf("value of length: %ld\n", length);
    printf("value of str: %s\n", str);
    printf("value of token: %s\n", token);
    return (token);
}

char *ft_strtok(const char *str) {
    static const char *next;
    char *token;
    ptrdiff_t length = 0;
    char *result;

    if (str != NULL) {
        next = str;
    }

    // Use non_map_delimiters for non-map lines
    static const char *non_map_delimiters = " \t\v\f\r";

    // Skip leading delimiters
    skip_delimeters(&next, non_map_delimiters);

    if (!*next) {
        return NULL;
    }

    token = (char *)next;
    str = find_end_token(token, non_map_delimiters);
    length = str - token;  // Use 'str' instead of 'next' here to calculate length

    printf("token: %s\n", token);
    printf("str: %s\n", str);
    printf("length: %ld\n", length);

    // If we found a token, null-terminate it and save the next position
    if (*str) {
        next = str + 1;
        printf("next: %s\n", next);
    } else {
        next = NULL;
    }

    result = (char *)malloc(length + 1);
    if (!result) {
        return NULL;
    }

    ft_strncpy(result, token, length);
    result[length] = '\0';
    return result;
}
