#pragma once
#include <allegro5/allegro.h>
#include<string>
using namespace std;

class Lienzo
{
private:
	int ancho_lienzo;
	int alto_lienzo;
	ALLEGRO_COLOR color2 = al_map_rgb(0,0,0);
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR colordefault = al_map_rgb(255, 255, 255);
	int funcion_activa = NULL;
	int grueso_de_linea = 10;
public:
	Lienzo(int, int);
	void ModificarColor(int,int,int);
	ALLEGRO_COLOR ObtenerColor();
	ALLEGRO_COLOR ObtenerColor2();
	void ModificarFuncionActiva(int);
	int ObtenerFuncionActiva();
	ALLEGRO_COLOR ObtenerDefault();
	void ModificarGruesoLinea(int);
	int ObtenerGruesoLinea();
};

