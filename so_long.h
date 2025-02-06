
#ifndef SO_LONG
#define SO_LONG

#include "srcs/libft/get_next_line/get_next_line.h"
#include "srcs/minilibx-linux/mlx.h"
#include "srcs/libft/libft.h"
#include "srcs/ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

// typedef struct s_data
// {
// 	void		*mlx_ptr; // MLX pointer
// 	void		*win_ptr; // MLX window pointer
// 	void		*textures[5]; // MLX image pointers (on the stack)
// 	//s_data		*map; // Map pointer (contains map details - preferably kept on the stack)
// 	char		**map_details;
// 	char		*filename;
// 	int			column_len;
// 	int			row_len;
// }	t_data;

// typedef struct  s_point
// {
// 	int           x;
// 	int           y;
// }	t_point;

typedef struct s_map
{
	char	*path;
	int		width;
	int		height;
	char	**board;
	char	*filename;
}				t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}			t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}			t_exit;

typedef struct s_imgs
{
	void	*e;
	void	*p;
	void	*c;
	void	*w;
	void	*f;


}			t_imgs;

// typedef struct s_state
// {
// 	void		*mlx;
// 	void		*win;
// 	t_map		*map;
// 	t_player	player;
// 	t_imgs		imgs;
// 	int			collectibles;
// 	t_exit		exit;
// }	t_state;
typedef struct s_state
{
    void        *mlx;
    void        *win;
    t_map       map; // Pointer yerine doğrudan struct
    t_player    player;
    t_imgs      imgs;
    int         collectibles;
    t_exit      exit;
}   t_state;

void	map_checker(char *map, t_state *my_map);
void	flood_fill(char **tab, t_state size, t_state begin);
void	read_map(char *map, t_state *my_map);
void map_error();
void error_filename(void);
char **copy_map(char **original, int height);
void free_map(char **map, int height);
void	put_image(t_state *state);
void	put_screen(t_state *state);

#endif