#include "Triangulo.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>

Triangulo::Triangulo(int x1, int y1, int x2, int y2, ALLEGRO_COLOR color_centro, ALLEGRO_COLOR color_borde, int grueso)
{
	int x3, y3;
	if (x1 > x2) {
		x3 = x1 - x2;
		x3 = x3 + x2 + x3;
	}
	else {
		x3 = x2 - x1;
		x3 = x2-x3-x3;
	}
	y3 = y2;
	al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, color_centro);
	al_draw_triangle(x1, y1 + 0.5, x2 + 0.5, y2, x3-0.5, y3, color_borde, grueso);
}
