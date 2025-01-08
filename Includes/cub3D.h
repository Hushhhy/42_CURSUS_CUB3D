/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:14:51 by acarpent          #+#    #+#             */
/*   Updated: 2025/01/08 13:09:05 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*---------------------------INCLUDES-------------------------------*/

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

/*-----------------------------KEYS---------------------------------*/

enum    e_keys {
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_UP = 65362,
	KEY_S = 115,
	KEY_DOWN = 65364,
	KEY_A = 97,
	KEY_LEFT = 65361,
	KEY_D = 100,
	KEY_RIGHT = 65363, 
};

/*-------------------------WINDOW DETAILS---------------------------*/

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

/*--------------------------GAME DETAILS----------------------------*/

# define TILE_SIZE 30
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 4

/*----------------------------COLORS--------------------------------*/

# define RED "\e[31m"
# define RESET	"\e[0m"

/*--------------------------ERROR DEF-------------------------------*/

# define ERR_ARG "./cub3d <path/to/map.cub>"
# define ERR_NAME "Has to be a .cub file"
# define ERR_IS_DIR "Is a directory"
# define ERR_ENV "Environment not found"
# define ERR_GET_FILE "File doesn't exist"
# define ERR_EMPTY "Empty file"
# define ERR_CHAR "Invalid character in map"
# define ERR_NORTH "Too many north textures"
# define ERR_SOUTH "Too many south textures"
# define ERR_EAST "Too many east textures"
# define ERR_WEST "Too many west textures"
# define ERR_FLOOR "Too many floor colors"
# define ERR_CEILING "Too many ceiling colors"
# define ERR_FORMAT "Invalid map format"
# define ERR_AFTER "Invalid characters after map"
# define ERR_NO_MAP "No map found"
# define ERR_SMALL_MAP "Map too small"
# define ERR_PLAYER "Invalid number of players"
# define ERR_CLOSED "Map not closed"
# define ERR_COLOR_FORMAT "Invalid color format"
# define ERR_COLOR_RANGE "Color out of range"
# define ERR_COMA "Coma number must be 2"
# define ERR_MLX_INIT "Could not init mlx"
# define ERR_MLX_WIN "Could not create window"
# define ERR_XPM "Not a .xpm texture"

/*------------------------MAIN FUNCTIONS----------------------------*/

int		main(int ac, char **av);

/*-----------------------------INIT---------------------------------*/

void	_data_init(t_game *game);
void	_player_init(t_game *game);
void	_ray_init(t_game *game);
void	_mlx_struct_init(t_game *game);
void	_init_mlx(t_game *game);

/*----------------------------PARSING-------------------------------*/

/*---------------------------------*/
/*--ERROR--*/

int		_error_msg_free(char *det, char *str, int code, t_game *game);
int		_err_msg_val(int detail, char *str, int code, t_game *game);
void	_free_texture(char *no, char *so, char *ea, char *we);
int		_error_msg(char *det, char *str, int code);
void	_free_colors(char *ceiling, char *floor);
void	_has_to_free(t_game *game);

/*---------------------------------*/
/*--NAME OR DIR--*/

void	_checkname(char *name);
bool	_is_directory(char *name);

/*---------------------------------*/
/*--GET FILE--*/

int		_getfile(t_game *game, char *file);
char	**_gnl_in_file(t_game *game, int lc);
char	*_new_alloc(int start, char *line);

/*---------------------------------*/
/*--FILE PARSING--*/

void	_parse_file(t_game *game);
int		_get_size(t_game *game);
void	_char_check(char *line, t_game *game);
void	_emptyfile(t_game *game);

/*---------------------------------*/
/*--TEXTURES && COLORS--*/

void	_north_check(t_game *game, char *line);
void	_south_check(t_game *game, char *line);
void	_east_check(t_game *game, char *line);
void	_west_check(t_game *game, char *line);
void	_check_texname(char *name, t_game *game);
void	_ceiling_check(t_game *game, char *line);
void	_floor_check(t_game *game, char *line);
void	_get_ceiling(char *color, t_game *game);
void	_get_floor(char *color, t_game *game);
void	_coma_check(char *color, t_game *game);

/*---------------------------------*/
/*--GET MAP--*/

void	_getmap(t_game *game, int i);
void	_map_realloc(t_game *game);
void	_verify(t_game *game, int start);
int		_is_invalid(char *line, t_game *game);
void	_after_map(t_game *game, int last);
int		_emptylines(t_game *game, int start);
int		_line_empty(char *line);
int		_get_map_size(t_game *game, int i);

/*---------------------------------*/
/*--MAP PARSING--*/

int		_get_map_width(char **map);
int		_get_map_height(char **map);
void	_check_the_map(t_game *game);
bool	_check_nb_player(char **map, t_game *game);
void	_player_pos(t_game *game, int i, int j);
bool	_there_is_walls(char **map, int row, int col);
bool	_check_closed_map(t_game *game);
bool	_check_top_bot(char *line);
bool	_check_rows(char **map, int y, int x);
bool	_check_cols(char **map, int y, int x);
bool	_check_left(char **map, int y, int i);
bool	_check_right(char **map, int y, int i);
bool	_check_up(char **map, int i, int x);
bool	_check_down(char **map, int i, int x);
bool	_check_spaces(char **map, int y, int x);
bool	_check_space_row(char **map, int y, int x);
bool	_check_space_col(char **map, int y, int x);
bool	_check_space_left(char **map, int y, int i);
bool	_check_space_up(char **map, int i, int x);

/*-----------------------------GAME---------------------------------*/

/*---------------------------------*/
/*--IMAGES--*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*---------------------------------*/
/*--GAME CLEARING--*/

int		_close_game(t_game *game);

void	_gaming(t_game *game);
int		_key_press(int key, t_game *game);

#endif
