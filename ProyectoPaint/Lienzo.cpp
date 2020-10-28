#include "Lienzo.h"
#include <allegro5/allegro.h>

//Construye el lienzo
Lienzo::Lienzo(int ancho, int alto)
{
	this->ancho_lienzo = ancho;
	this->alto_lienzo = alto;
	ALLEGRO_DISPLAY* ventana = al_create_display(this->ancho_lienzo, this->alto_lienzo);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_set_window_title(ventana, "Paint c++");
}

void Lienzo::ModificarColor(int a,int b,int c)
{
	this->color2 = this->color;
	this->color = al_map_rgb(a, b, c);
}



ALLEGRO_COLOR Lienzo::ObtenerColor()
{
	return this->color;
}

ALLEGRO_COLOR Lienzo::ObtenerColor2()
{
	return this->color2;
}

void Lienzo::ModificarFuncionActiva(int a)
{
	/*1:lapiz
	2: mover
	3:pintura
	4:linea
	5:rectangulo
	6: circulo
	7: borrar
	8: clear
	9:curva
	10: triangulo
	11:poligono*/
	this->funcion_activa = a;
}

int Lienzo::ObtenerFuncionActiva()
{
	return this->funcion_activa;
}

ALLEGRO_COLOR Lienzo::ObtenerDefault()
{
	return this->colordefault;
}

void Lienzo::ModificarGruesoLinea(int l)
{
	this->grueso_de_linea = l;
}

int Lienzo::ObtenerGruesoLinea()
{
	return this->grueso_de_linea;
}



