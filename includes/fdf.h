/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:27:40 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/07 16:46:29 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# include "./get_next_line.h"

typedef struct s_param {
	int		fd;
	char	*tmp;
	int		line;
	int		i;
	int		j;
	int		len_ref;
	int		len_tmp;
}				t_param;

typedef struct s_point {
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
	unsigned int	ab;
	unsigned int	or;
	int				xa;
	int				ya;
	int				za;
	int				xb;
	int				yb;
	int				zb;
	int				color;
}				t_point;

typedef struct s_env {
	void			*mlx;
	void			*win_ptr;
	void			*img_data;
	char			*img_ptr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	long int		img_x;
	long int		img_y;
	float			zoom;
	t_dlist			*list;
	t_point			point;
	int				is_iso;
	unsigned int	list_size;
	int				chooseangle;
	int				angle;
}				t_env;

int			key_hook(int keycode, t_env *env);
void		ft_draw(t_env *env, t_dnode **node, t_point point);
void		ft_setenv(t_env *env, t_dlist *list, t_point point);
int			ft_check_input(int argc, char **argv);
int			ft_lineisnum(char **dest);
int			ptrstrlen(char **dest);
void		ft_freetab(char ***dest);
void		ft_free(char **tmp, char ***dest);
int			ft_check_map(int fd);
int			ft_stock_input(char **argv, t_dlist *list);
void		ft_trace(t_env *env, t_point point);
void		iso(int *x, int *y, int z, t_env **env);
void		my_mlx_pixel_put(t_env *env, int x, int y, int color);
void		ft_print_map(t_dnode *node);
void		ft_setpoint(t_point *point);
void		ft_rotation(int *x, int *y, int *z, t_env **env);
void		ft_xrota(int *x, int *y, int *z, t_env *env);
void		ft_yrota(int *x, int *y, int *z, t_env *env);
void		ft_zrota(int *x, int *y, int *z, t_env *env);

# define WHITE		0x00F0F8FF
# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define MAGENTA	0x00FF00FF
# define CYAN		0x0000FFFF

# define KEY_W		119
# define KEY_R		114
# define KEY_G		103
# define KEY_B		98
# define KEY_M		109
# define KEY_C		99

# define KEY_H		104
# define KEY_X		120
# define XAXIS		42120
# define KEY_J		106
# define KEY_Y		121
# define YAXIS		42121
# define KEY_K		107
# define KEY_Z		122
# define ZAXIS		42122

# define LEFT	65361
# define UP		65362
# define RIGHT	65363
# define DOWN	65364

# define ZOOM_IN	65451
# define ZOOM_OUT	65453

# define NUMPAD_1 65436
# define NUMPAD_2 65433
# define NUMPAD_3 65435
# define NUMPAD_4 65430
# define NUMPAD_5 65437

# define KEY_P		112
# define BACKSPACE	32
# define ESC		65307

# define NB_PARAM_ERROR	-2
# define INPUT_ERROR	-3
# define MAP_ERROR		-4
# define MALLOC_ERROR	-5

# define W_WIDTH	2560
# define W_HEIGHT	1440

#endif
