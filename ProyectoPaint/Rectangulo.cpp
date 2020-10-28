#include "Rectangulo.h"
#include "allegro5/allegro.h"
#include "Lienzo.h"
#include <allegro5/allegro_primitives.h>

Rectangulo::Rectangulo(int x1, int y1, int x2, int y2, ALLEGRO_COLOR centro, ALLEGRO_COLOR borde, int grueso)
{
	al_draw_rectangle(x1+0.5, y1 + 0.5, x2-0.5, y2-0.5, borde,grueso);
	al_draw_filled_rectangle(x1, y1, x2, y2, centro);
}
