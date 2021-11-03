/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:27:40 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/03 20:46:55 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"

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

# define RED		0x00FF0000
# define GREEN		0x0000FF00
# define BLUE		0x000000FF
# define MAGENTA	0x00FF00FF

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

# define ESC	65307

#endif
