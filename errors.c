
#include "so_long.h"

void error_filename(void)
{
    ft_printf("Filename should be a BER extension file");
    exit(EXIT_FAILURE);
}

void error_message_for_counter(char *str)
{
    while (*str != '\0')
    {
        write(1, *str, 1);
        str++;
    }
    return(EXIT_FAILURE);
}