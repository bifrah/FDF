#include "../includes/fdf.h"

void	ft_trace(t_env env, int xi, int yi, int xf, int yf)
{
	int	dx;
	int	dy;
	int	i;
	int	xinc;
	int	yinc;
	int	cumul;
	int	x;
	int	y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	if (dx > 0)
		xinc = 1;
	else
		xinc = -1;
	if (dy > 0)
		yinc = 1;
	else
		yinc = -1;
	dx = abs(dx);
	dy = abs(dy);
	allume_pixel(x,y);
	if (dx > dy)
	{
		cumul = dx / 2;
		i = 0;
		while (++i <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			allume_pixel(x,y);
		}
	}
	else
	{
		cumul = dy / 2;
		i = 0;
		while (++i <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			allume_pixel(x,y);
		}
	}
}