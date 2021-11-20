#include "../includes/fdf.h"

void	tracer_segment(t_env *env, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	e;

	dx = x2 - x1;
	if (dx != 0)
	{
		if (dx > 0)
		{
			dy = y2 - y1;
			if (dx != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (x1 != x1 + 1 && x1 != x2)
						{
							my_mlx_pixel_put(env, x1, y1, RED);
							e -= dy;
							if (e < 0)
							{
								y1 = y1 + 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (y1 != y1 + 1 && y1 != y2)
						{
							my_mlx_pixel_put(env, x1, y1, RED);
							e -= dx;
							if (e < 0)
							{
								x1 = x1 + 1;
								e += dy;
							}
						}
					}
					if (dy < 0 && dx > 0)
					{
						if (dx >= -dy)
						{
							e = dx;
							dx = e * 2;
							dy = dy * 2;
							while (x1 != x1 + 1 && x1 != x2)
							{
								my_mlx_pixel_put(env, x1, y1, RED);
								e += dy;
								if (e < 0)
								{
									y1 = y1 - 1;
									e += dx;
								}
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (y1 != y1 - 1 && y1 != y2)
						{
							my_mlx_pixel_put(env, x1, y1, RED);
							e += dx;
							if (e > 0)
							{
								x1 = x1 + 1;
								e += dy;
							}
						}
					}
				}
				if (dy == 0 && dx > 0)
				{
					while (x1 != x1 + 1 && x1 != x2)
						my_mlx_pixel_put(env, x1, y1, RED);
				}
				if (dx < 0)
				{
					dy = y2 - y1;
					if (dy != 0)
					{
						if (dy > 0)
						{
							if (-dx >= dy)
							{
								e = dx;
								dx = e * 2;
								dy = dy * 2;
								while (x1 != x1 - 1 && x1 != x2)
									my_mlx_pixel_put(env, x1, y1, RED);
								e += dy;
								if (e >= 0)
								{
									y1 = y1 + 1;
									e += dx;
								}
							}
						}
					}
				}
				else
				{
					e = dy;
					dy = e * 2;
					dx = dx * 2;
					while (y1 != y1 + 1 && y1 != y2)
						my_mlx_pixel_put(env, x1, y1, RED);
					e += dx;
					if (e <= 0)
					{
						x1 = x1 - 1;
						e += dy;
					}
				}
				if (dy < 0 && dx < 0)
				{
					if (dx <= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (x1 != x1 - 1 && x1 != x2)
						{
							my_mlx_pixel_put(env, x1, y1, RED);
							e -= dy;
							if (e >= 0)
							{
								y1 = y1 - 1;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (y1 != y1 - 1 && y1 != y2)
							my_mlx_pixel_put(env, x1, y1, RED);
						e -= dx;
						if (e >= 0)
						{
							x1 = x1 - 1;
							e += dy;
						}
					}
				}
				if (dy == 0 && dx < 0)
				{	
					while (x1 != x1 - 1 && x1 != x2)
						my_mlx_pixel_put(env, x1, y1, RED);
				}
			}
			if (dx == 0)
			{
				dy = y2 - y1;
				if (dy != 0)
				{
					if (dy > 0)
					{
						while (y1 != y1 + 1 && y1 != y2)
							my_mlx_pixel_put(env, x1, y1, RED);
					}
					if (dy < 0 && dx == 0)
					{
						while (y1 != y1 - 1 && y1 != y2)
							my_mlx_pixel_put(env, x1, y1, RED);
					}
				}
			}
		}
	}
}
