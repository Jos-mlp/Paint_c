#include "LineaCurva.h"
#include <math.h>
#include <allegro5/allegro_primitives.h>
LineaCurva::LineaCurva(int x1, int y1, int x2, int y2, ALLEGRO_COLOR color, int grueso)
{
	float cx, cy, r, start_theta=1, delta_theta=1,aux;
	//radio
	cx = (x1 + x2) / 2;
	cy = (y1 + y2) / 2;
	r = pow((x1 - cx), 2) + pow((y1 - cy), 2);
	r = sqrt(r);

	aux = x1 + 30;
	//centro
	if (x1 > x2 && y1 > y2) {
		cx = cx - (r / 2);
		cy = cy - (r / 2);
		start_theta = 270;
		delta_theta = 2;
	}
	else if (y2>y1 && aux>x2 || aux<x2){
		cx = cx + r;
		start_theta = 270;
		delta_theta = 2;
	}


	al_draw_arc(cx, cy, r, start_theta, delta_theta, color, grueso);
}
