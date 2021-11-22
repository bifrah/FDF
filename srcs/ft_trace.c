#include "../includes/fdf.h"

void	ligne(t_env env, int xi, int yi, int xf, int yf)
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
	xinc = ( dx > 0 ) ? 1 : -1;
	yinc = ( dy > 0 ) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	allume_pixel(x,y);
	if (dx > dy)
	{
		cumul = dx / 2;
		for ( i = 1 ; i <= dx ; i++ )
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
		for (i = 1 ; i <= dy ; i++)
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