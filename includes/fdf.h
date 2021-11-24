/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:27:40 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/22 18:47:15 by bifrah           ###   ########.fr       */
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

typedef struct s_env {
	void	*mlx;
	void	*win_ptr;
	void	*img_data;
	char	*img_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_x;
	int		img_y;
}				t_env;

typedef struct s_check {
	char	*tmp;
	int		len_ref;
	int		len_tmp;
	int		line;
}				t_check;

typedef struct s_index {
	int		i;
	int		j;
	int		k;
}				t_index;

typedef struct s_trace {
	int		dx;
	int		dy;
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;
	int		x;
	int		y;
}				t_trace;

typedef struct s_point {
	int		xa;
	int		ya;
	int		za;
	int		xb;
	int		yb;
	int		zb;
}				t_point;

int		key_hook(int keycode, t_env *env, t_point point, t_trace trace);
void	ft_draw(t_env *env, t_point point, t_trace trace);
void	my_mlx_pixel_put(t_env *env, int x, int y, int color);
void	ft_setenv(t_env *env);
int		ft_check_input(int argc, char **argv);
int		ft_lineisnum(char **dest);
int		ptrstrlen(char **dest);
void	ft_freetab(char ***dest);
void	ft_free(char **tmp, char ***dest);
int		ft_check_map(int fd);
void    ft_stock_input(int fd, t_dlist *list);
void	ft_trace(t_env env, t_point point, t_trace trace);

# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define MAGENTA	0x00FF00FF
# define CYAN		0x00000FFF

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

# define BACKSPACE	65288
# define ESC		65307

# define NB_PARAM_ERROR	-2
# define INPUT_ERROR	-3
# define MAP_ERROR		-4
# define MALLOC_ERROR	-5

#endif
