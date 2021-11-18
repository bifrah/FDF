#include "../includes/fdf.h"

void	tracer_segment(int x1, int y1, int x2, int y2)
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
					// vecteur oblique dans le 1er cadran
					if (dx >= dy) // vecteur diagonal ou oblique proche de l’horizontale, dans le 1er octant
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;  // e est positif
						while (x1 != x1 + 1 && x1 != x2)// déplacements horizontaux
						{
							ft_draw(x1, y1);
							e -= dy;
							if (e < 0)	// déplacement diagonal
							{
								y1 = y1 + 1;
								e += dx;
							}
						}
					}
					else	// vecteur oblique proche de la verticale, dans le 2d octant
					{
						dy = (e = dy) * 2;
						dx = dx * 2;  // e est positif
						while (y1 != y1 + 1 && y1 != y2) // déplacements verticaux
						{
							ft_draw(x1, y1);
							e -= dx;
							if (e < 0)	// déplacement diagonal
							{
								x1 = x1 + 1;
								e += dy;
							}
						}
					}
					if (dy < 0 && dx > 0)
					// vecteur oblique dans le 4e cadran
					{
						if (dx >= -dy)
						{
							// vecteur diagonal ou oblique proche de l’horizontale, dans le 8e octant
							dx = (e = dx) * 2 ; dy = dy * 2 ;  // e est positif
							while (x1 != x1 + 1 && x1 != x2) // déplacements horizontaux
							{
								ft_draw(x1, y1);
								e += dy;
								if (e < 0)	// déplacement diagonal
								{
									y1 = y1 - 1;
									e += dx;
								}
							}

						}
					}
					else  // vecteur oblique proche de la verticale, dans le 7e octant
					{
						dy = (e = dy) * 2;
						dx = dx * 2 ;  // e est négatif
						while (y1 != y1 - 1 && y1 != y2)  // déplacements verticaux
						{
							ft_draw(x1, y1);
							e += dx;
							if (e > 0)	// déplacement diagonal
							{
								x1 = x1 + 1;
								e += dy;
							}
						}
					}
				}
				if (dy == 0 && dx > 0)
				{
					while (x1 != x1 + 1 && x1 != x2)	// vecteur horizontal vers la droite
						ft_draw(x1, y1);
				}
				if (dx < 0)
				{
					dy = y2 - y1;
					if (dy != 0)
					{
						if (dy > 0)	// vecteur oblique dans le 2d cadran
						{
							if (-dx >= dy)// vecteur diagonal ou oblique proche de l’horizontale, dans le 4e octant
							{
								dx = (e = dx) * 2;
								dy = dy * 2;  // e est négatif
								while (x1 != x1 - 1 && x1 != x2)  // déplacements horizontaux
									ft_draw(x1, y1);
								e += dy;
								if (e >= 0)
								{
									y1 = y1 + 1;  // déplacement diagonal
									e += dx;
								}
							}
						}
					}
				}
				else	// vecteur oblique proche de la verticale, dans le 3e octant
				{
					dy = (e = dy) * 2;
					dx = dx * 2;  // e est positif
					while (y1 != y1 + 1 && y1 != y2) // déplacements verticaux
						ft_draw(x1, y1);
					e += dx;
					if (e <= 0)	// déplacement diagonal
					{
						x1 = x1 - 1;
						e += dy;
					}
				}
				if (dy < 0 && dx < 0)	// vecteur oblique dans le 3e cadran
				{
					if (dx <= dy)	// vecteur diagonal ou oblique proche de l’horizontale, dans le 5e octant
					{
						dx = (e = dx) * 2;
						dy = dy * 2;  // e est négatif
						while (x1 != x1 - 1 && x1 != x2)  // déplacements horizontaux
						{
							ft_draw(x1, y1);
							e -= dy;
							if (e >= 0)
							{
								y1 = y1 - 1;  // déplacement diagonal
								e += dx;
							}
						}
					}
					else  // vecteur oblique proche de la verticale, dans le 6e octant
					{
						dy = (e = dy) * 2;
						dx = dx * 2;  // e est négatif
						while (y1 != y1 - 1 && y1 != y2)  // déplacements verticaux
							tracePixel(x1, y1);
						e -= dx;
						if (e >= 0)
						{
							x1 = x1 - 1;  // déplacement diagonal
							e += dy;
						}
					}
				}
				if (dy == 0 && dx < 0)
				{	
					// vecteur horizontal vers la gauche
					while (x1 != x1 - 1 && x1 != x2)
						tracePixel(x1, y1);
				}
			}
			if (dx == 0)
			{
				dy = y2 - y1;
				if (dy != 0)
				{
					if (dy > 0)
					{
						while (y1 != y1 + 1 && y1 != y2)// vecteur vertical croissant
							tracePixel(x1, y1);
					}
					if (dy < 0 && dx == 0)
					{
						while (y1 != y1 - 1 && y1 != y2)// vecteur vertical décroissant
							tracePixel(x1, y1);
					}
				}
			}
		}
	}
}

// le pixel final (x2, y2) n’est pas tracé.