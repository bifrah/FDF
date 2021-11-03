/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:27:40 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/03 20:33:08 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>

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

# define NUMPAD_1 65436
# define NUMPAD_2 65437
# define NUMPAD_3 65438
# define NUMPAD_4 65439
# define NUMPAD_5 65440

#endif
