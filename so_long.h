
#ifndef SO_LONG
#define SO_LONG

#include "srcs/libft/get_next_line/get_next_line.h"
#include "srcs/minilibx-linux/mlx.h"
#include "srcs/libft/libft.h"
#include "srcs/ft_printf/ft_printf.h"

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	//s_data		*map; // Map pointer (contains map details - preferably kept on the stack)
	char		**map_details;
	char		*filename;
	int			column_len;
	int			row_len;
}	t_data;

typedef struct  s_point
{
	int           x;
	int           y;
}	t_point;

void	map_checker(char *map, t_data *my_map);
void	flood_fill(char **tab, t_data size, t_data begin);
void	read_map(char *map, t_data *my_map);
void map_error();

#endif