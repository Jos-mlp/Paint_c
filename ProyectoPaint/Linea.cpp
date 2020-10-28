#include "Linea.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

Linea::Linea(int x1, int y1, int x2, int y2, ALLEGRO_COLOR color_borde, int grueso)
{
	al_draw_line(x1, y1, x2, y2, color_borde, grueso);
}
