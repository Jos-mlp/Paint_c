#include "Circulo.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>

Circulo::Circulo(int x1, int y1, int x2,int y2, ALLEGRO_COLOR color_centro, ALLEGRO_COLOR color_borde,int grueso)
{
	float cx, cy, r;
	cx = (x1 + x2) / 2;
	cy = (y1 + y2) / 2;
	r = pow((x1 - cx), 2) + pow((y1 - cy), 2);
	r = sqrt(r);
	al_draw_filled_circle(cx, cy, r, color_centro);
	al_draw_circle(cx,  cy, r + 0.5, color_borde,grueso);
}
