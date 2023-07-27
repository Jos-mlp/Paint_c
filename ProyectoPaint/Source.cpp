#include <iostream>
#include <allegro5/allegro.h>
#include "Lienzo.h"
#include <allegro5/allegro_image.h> 
#include <allegro5/allegro_primitives.h>
#include "Rectangulo.h"
#include "Circulo.h"
#include "Linea.h"
#include "Triangulo.h"
#include"LineaCurva.h"

using namespace std;

bool presionado = false;
bool ejecucion = true;

void Activar() {
	presionado = true;
}

void Desactivar() {
	presionado = false;
}


int main(){
	int opcion,x,y,a,l,x1,y1,x2,y2;
	cout << "Escoga un lienzo" << endl;
	cout << "1. Pequeño" << endl;
	cout << "2. Mediano" << endl;
	cout << "3. Grande" << endl;
	cin >> opcion;
	//inicia el interfza visual, el mouse, las imagenes,las figuras primitivas, el teclado
	al_init();
	al_install_mouse();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	//elige el tamanio del lienzo
	if (opcion == 1) {
		a = 1000; l = 600;
	}
	else if (opcion == 2) {
		a = 1240; l = 750;
	}
	else{
		a = 1440; l = 900;
	}
	//Crea el lienzo y lo genera de color blanco
		Lienzo nuevo = Lienzo(a,l);
	//Eventos del mouse y teclado
		ALLEGRO_EVENT evento;
		ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
		al_register_event_source(event_queue, al_get_mouse_event_source());
		al_register_event_source(event_queue, al_get_keyboard_event_source());
	//carga las imagenes
		ALLEGRO_BITMAP* colores24 = al_load_bitmap("Recursos/PaletaColores.jfif");
		ALLEGRO_BITMAP* lapiz = al_load_bitmap("Recursos/lapiz.jpg");
		ALLEGRO_BITMAP* borrador = al_load_bitmap("Recursos/Borrador.jpg");
		ALLEGRO_BITMAP* selector = al_load_bitmap("Recursos/selector.jpg");
		ALLEGRO_BITMAP* clear = al_load_bitmap("Recursos/clear.jpg");
		ALLEGRO_BITMAP* bote = al_load_bitmap("Recursos/botepintura.jpg");
		ALLEGRO_BITMAP* circulo = al_load_bitmap("Recursos/circulo.jpg");
		ALLEGRO_BITMAP* curva = al_load_bitmap("Recursos/curva.jpg");
		ALLEGRO_BITMAP* triangulo = al_load_bitmap("Recursos/triangulo.jpg");
		ALLEGRO_BITMAP* rectangulo = al_load_bitmap("Recursos/Rectangulo.jpg");
		ALLEGRO_BITMAP* poligono = al_load_bitmap("Recursos/Poligono.jpg");
		ALLEGRO_BITMAP* linea = al_load_bitmap("Recursos/linea.jpg");
		ALLEGRO_BITMAP* lineaDivisora = al_load_bitmap("Recursos/Lid.png");
		ALLEGRO_BITMAP* grosor_lineas = al_load_bitmap("Recursos/GrosorLineas.png");
		//mantiene en ejecucion el programa
	while (ejecucion==true) {
		//imprime las imagenes
		al_draw_bitmap(colores24,0,0,0);
		al_draw_bitmap(lapiz, 502, 8, 0);
		al_draw_bitmap(borrador, 502, 70, 0);
		al_draw_bitmap(selector, 562, 8, 0);
		al_draw_bitmap(clear, 562, 70, 0);
		al_draw_bitmap(bote, 622, 8, 0);
		al_draw_bitmap(curva, 622, 70, 0);
		al_draw_bitmap(linea, 682, 8, 0);
		al_draw_bitmap(triangulo, 682, 70, 0);
		al_draw_bitmap(rectangulo, 742, 8, 0);
		al_draw_bitmap(poligono, 742, 70, 0);
		al_draw_bitmap(circulo, 802, 8, 0);
		al_draw_bitmap(lineaDivisora, 0, 95, 0);
		al_draw_bitmap(grosor_lineas, 868, 9, 0);
		//Coloca los colores seleccionados

			//color del borde
			al_draw_filled_rectangle(802, 70, 857, 127, nuevo.ObtenerColor());
			//color del fondo
			al_draw_filled_rectangle(815.75, 84.25, 843.25, 112.5, nuevo.ObtenerColor2());

		//Inicializa la variable evento y le pasa el evento generado
		al_wait_for_event(event_queue, &evento);

		//sirve para detectar cuando se mueve el mouse y cuando es presionado
		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			

			x = evento.mouse.x;
			y = evento.mouse.y;
			//si el boton izquierdo del mouse es presionado se ejecuta el if
			if (evento.mouse.button & 1) {
				cout << "x:" << x << "  y:" << y << endl;
				//Configuracio de que opcion se ejecuta segun donde toca el boton
				//color Blanco
				if (x > 10 && y > 81 && x < 37 && y < 136) {
					cout << "Blanco" << endl;
					nuevo.ModificarColor(255, 255, 255);
					Desactivar();
				}
				//color Negro
				if (x > 10 && y > 11 && x < 37 && y < 70) {
					cout << "Negro" << endl;
					nuevo.ModificarColor(0, 0, 0);
					Desactivar();
				}
				//color gris oscuro
				if (x > 44 && y > 11 && x < 70 && y < 70) {
					cout << "Gris Oscuro" << endl;
					nuevo.ModificarColor(72, 69, 69);
					Desactivar();
				}
				//color gris palido
				if (x > 44 && y > 80 && x < 70 && y < 138) {
					cout << "Gris palido" << endl;
					nuevo.ModificarColor(208, 208, 208);
					Desactivar();
				}
				//color gris 
				if (x > 78 && y > 11 && x < 101 && y < 70) {
					cout << "Gris" << endl;
					nuevo.ModificarColor(124, 123, 123);
					Desactivar();
				}
				//color rojo oscuro 
				if (x > 112 && y > 11 && x < 137 && y < 70) {
					cout << "Rojo Oscuro" << endl;
					nuevo.ModificarColor(111, 2, 2);
					Desactivar();
				}
				//color rojo 
				if (x > 146 && y > 11 && x < 170 && y < 70) {
					cout << "Rojo" << endl;
					nuevo.ModificarColor(212, 17, 17);
					Desactivar();
				}
				//color Naranja 
				if (x > 179 && y > 11 && x < 206 && y < 70) {
					cout << "Naranja" << endl;
					nuevo.ModificarColor(251, 89, 24);
					Desactivar();
				}
				//color Mostaza 
				if (x > 212 && y > 11 && x < 239 && y < 70) {
					cout << "Mostaza" << endl;
					nuevo.ModificarColor(251, 155, 0);
					Desactivar();
				}
				//color amarillo 
				if (x > 246 && y > 11 && x < 273 && y < 70) {
					cout << "Amarillo" << endl;
					nuevo.ModificarColor(251, 231, 0);
					Desactivar();
				}
				//color Verde claro
				if (x > 281 && y > 11 && x < 306 && y < 70) {
					cout << "Verde Claro" << endl;
					nuevo.ModificarColor(71, 251, 0);
					Desactivar();
				}
				//color Verde Oscuro
				if (x > 314 && y > 11 && x < 341 && y < 70) {
					cout << "Verde Oscuro" << endl;
					nuevo.ModificarColor(40, 138, 1);
					Desactivar();
				}
				//color Celeste
				if (x > 349 && y > 11 && x < 374 && y < 70) {
					cout << "Celeste" << endl;
					nuevo.ModificarColor(16, 235, 247);
					Desactivar();
				}
				//color Azul Claro
				if (x > 383 && y > 11 && x < 409 && y < 70) {
					cout << "Azul Claro" << endl;
					nuevo.ModificarColor(96, 97, 181);
					Desactivar();
				}
				//color Azul
				if (x > 417 && y > 11 && x < 442 && y < 70) {
					cout << "Azul" << endl;
					nuevo.ModificarColor(5, 7, 141);
					Desactivar();
				}
				//color Morado
				if (x > 452 && y > 11 && x < 476 && y < 70) {
					cout << "Morado" << endl;
					nuevo.ModificarColor(108, 1, 157);
					Desactivar();
				}
				//color gris claro
				if (x > 77 && y > 81 && x < 102 && y < 137) {
					cout << "gris claro" << endl;
					nuevo.ModificarColor(173, 172, 174);
					Desactivar();
				}
				//color cafe
				if (x > 111 && y > 81 && x < 138 && y < 137) {
					cout << "Cafe" << endl;
					nuevo.ModificarColor(98, 59, 37);
					Desactivar();
				}
				//color rosado
				if (x > 147 && y > 81 && x < 172 && y < 137) {
					cout << "Rosado" << endl;
					nuevo.ModificarColor(247, 143, 219);
					Desactivar();
				}
				//color cafe claro
				if (x > 180 && y > 81 && x < 205 && y < 137) {
					cout << "Cafe claro" << endl;
					nuevo.ModificarColor(178, 129, 102);
					Desactivar();
				}
				//color piel oscuro
				if (x > 214 && y > 81 && x < 242 && y < 137) {
					cout << "Piel oscuro" << endl;
					nuevo.ModificarColor(230, 216, 124);
					Desactivar();
				}
				//color piel
				if (x > 246 && y > 81 && x < 273 && y < 137) {
					cout << "Piel" << endl;
					nuevo.ModificarColor(255, 239, 141);
					Desactivar();
				}
				//color Verde Palido
				if (x > 280 && y > 81 && x < 309 && y < 137) {
					cout << "Verde Palido" << endl;
					nuevo.ModificarColor(216, 243, 193);
					Desactivar();
				}
				//color Verde Monte
				if (x > 315 && y > 81 && x < 341 && y < 137) {
					cout << "Verde Monte" << endl;
					nuevo.ModificarColor(137, 172, 106);
					Desactivar();
				}
				//color Celeste Palido
				if (x > 350 && y > 81 && x < 375 && y < 137) {
					cout << "Celeste Palido" << endl;
					nuevo.ModificarColor(144, 244, 241);
					Desactivar();
				}
				//color Azul Aqua
				if (x > 382 && y > 81 && x < 408 && y < 137) {
					cout << "Azul aqua" << endl;
					nuevo.ModificarColor(62, 135, 184);
					Desactivar();
				}
				//Azul raro
				if (x > 416 && y > 81 && x < 444 && y < 137) {
					cout << "Azul raro" << endl;
					nuevo.ModificarColor(87, 119, 140);
					Desactivar();
				}
				//color lila
				if (x > 449 && y > 81 && x < 476 && y < 137) {
					cout << "Lila" << endl;
					nuevo.ModificarColor(184, 138, 215);
					Desactivar();
				}
				//Herramientas
				//Lapiz
				if (x > 502 && y > 9 && x < 552 && y < 59) {
					cout << "Lapiz" << endl;
					nuevo.ModificarFuncionActiva(1);
					Desactivar();
				}
				//Mover
				if (x > 561 && y > 9 && x < 612 && y < 59) {
					cout << "Mover" << endl;
					nuevo.ModificarFuncionActiva(2);
					Desactivar();
				}
				//Cubeta
				if (x > 621 && y > 9 && x < 672 && y < 59) {
					cout << "Cubeta" << endl;
					nuevo.ModificarFuncionActiva(3);
					Desactivar();
				}
				//Linea
				if (x > 681 && y > 9 && x < 732 && y < 59) {
					cout << "Linea" << endl;
					nuevo.ModificarFuncionActiva(4);
					Desactivar();
				}
				//Rectangulo
				if (x > 741 && y > 9 && x < 792 && y < 59) {
					cout << "Rectangulo" << endl;
					nuevo.ModificarFuncionActiva(5);
					Desactivar();
				}
				//Circulo
				if (x > 801 && y > 9 && x < 852 && y < 59) {
					cout << "Circulo" << endl;
					nuevo.ModificarFuncionActiva(6);
					Desactivar();
				}
				//Borrador
				if (x > 502 && y > 70 && x < 552 && y < 122) {
					cout << "Borrador" << endl;
					nuevo.ModificarFuncionActiva(7);
					Desactivar();
				}
				//Clear
				if (x > 561 && y > 70 && x < 612 && y < 122) {
					cout << "Clear" << endl;
					nuevo.ModificarFuncionActiva(8);
					Desactivar();
				}
				//Curva
				if (x > 621 && y > 70 && x < 671 && y < 122) {
					cout << "Curva" << endl;
					nuevo.ModificarFuncionActiva(9);
					Desactivar();
				}
				//triangulo
				if (x > 680 && y > 70 && x < 731 && y < 122) {
					cout << "triangulo" << endl;
					nuevo.ModificarFuncionActiva(10);
					Desactivar();
				}
				//Poligono
				if (x > 739 && y > 70 && x < 792 && y < 122) {
					cout << "Poligono" << endl;
					nuevo.ModificarFuncionActiva(11);
					Desactivar();
				}
				//aca terminan herramientas

				//empieza el grosor de lineas
				//Linea mas delgada
				if (x > 868 && y > 16 && x < 993 && y < 22) {
					cout << "Linea mas delgada" << endl;
					nuevo.ModificarGruesoLinea(5);
					Desactivar();
				}
				//Linea 2
				if (x > 867 && y > 32 && x < 992 && y < 45) {
					cout << "Linea 2" << endl;
					nuevo.ModificarGruesoLinea(10);
					Desactivar();
				}
				//Linea 3
				if (x > 869 && y > 54 && x < 993 && y < 75) {
					cout << "Linea 3" << endl;
					nuevo.ModificarGruesoLinea(20);
					Desactivar();
				}
				//Linea mas gruesa
				if (x > 869 && y > 83 && x < 992 && y < 125) {
					cout << "Linea mas gruesa" << endl;
					nuevo.ModificarGruesoLinea(40);
					Desactivar();
				}

			}
		
			//Funciones sobre el lienzo
			if (x > 0 && y > 188) {
				//pintar
				if (nuevo.ObtenerFuncionActiva() == 1) {
					if (evento.mouse.button & 1) {
						Activar();
					}
					if (evento.mouse.button & 2) {
						Desactivar();
					}
					if (presionado == true) {
						al_draw_filled_rectangle(x, y, x + nuevo.ObtenerGruesoLinea(), y + nuevo.ObtenerGruesoLinea(), nuevo.ObtenerColor());
					}
				}
				//termina pintar
				//Borrar Pantalla
				if (nuevo.ObtenerFuncionActiva() == 7) {
					if (evento.mouse.button & 1) {
						Activar();
					}
					if (evento.mouse.button & 2) {
						Desactivar();
					}
					if (presionado == true) {
						al_draw_filled_rectangle(x, y, x + nuevo.ObtenerGruesoLinea(), y + nuevo.ObtenerGruesoLinea(), nuevo.ObtenerDefault());
					}
				}
				//termina borrar
				//LimpiarPantalla
				if (nuevo.ObtenerFuncionActiva() == 8) {
					if (evento.mouse.button & 1) {
						Activar();
					}
					if (evento.mouse.button & 2) {
						Desactivar();
					}
					if (presionado == true) {
						for (int i = 0; i < 1600; i=i+20) {
							for (int j = 187; j < 1800; j = j + 20) {
								al_draw_filled_rectangle(i, j, i + 100, j + 100, nuevo.ObtenerDefault());
							}
						}
					}
					
				}
				//Termina limpiar pantalla
				//Insertar Rectangulo
				if(nuevo.ObtenerFuncionActiva() == 5) {
					if (evento.mouse.button & 1) {
						Activar();
						x1 = evento.mouse.x;
						y1 = evento.mouse.y;
					}

					if (presionado == true && evento.mouse.button & 2) {
						x2 = evento.mouse.x;
						y2 = evento.mouse.y;
						Rectangulo* forma = new Rectangulo(x1,y1,x2,y2, nuevo.ObtenerColor2(), nuevo.ObtenerColor(), nuevo.ObtenerGruesoLinea());
						Desactivar();
					}

				}
				//termina insertar rectangulo
				//Insertar Circulo
				if (nuevo.ObtenerFuncionActiva() == 6) {
					if (evento.mouse.button & 1) {
						Activar();
						x1 = evento.mouse.x;
						y1 = evento.mouse.y;
					}
					if (presionado == true && evento.mouse.button & 2) {
						x2 = evento.mouse.x;
						y2 = evento.mouse.y;
						Circulo* forma = new Circulo(x1, y1, x2, y2,  nuevo.ObtenerColor2(), nuevo.ObtenerColor(), nuevo.ObtenerGruesoLinea());
						Desactivar();
					}

				}
				//Termina insertar circulo

				//Insertar Lineas
				if (nuevo.ObtenerFuncionActiva() == 4) {
					if (evento.mouse.button & 1) {
						Activar();
						x1 = evento.mouse.x;
						y1 = evento.mouse.y;
					}
					if (presionado == true && evento.mouse.button & 2) {
						x2 = evento.mouse.x;
						y2 = evento.mouse.y;
						Linea* forma = new Linea(x1, y1, x2, y2, nuevo.ObtenerColor(), nuevo.ObtenerGruesoLinea());
						Desactivar();
					}

				}
				//termina insertar lineas

				//insertar triangulo
				if (nuevo.ObtenerFuncionActiva() == 10) {
					if (evento.mouse.button & 1) {
						Activar();
						x1 = evento.mouse.x;
						y1 = evento.mouse.y;
					}
					if (presionado == true && evento.mouse.button & 2) {
						x2 = evento.mouse.x;
						y2 = evento.mouse.y;
						Triangulo* forma = new Triangulo(x1, y1, x2, y2,  nuevo.ObtenerColor2(), nuevo.ObtenerColor(), nuevo.ObtenerGruesoLinea());
						Desactivar();
					}
				}
				//termina insertar triangulo

				//insertar linea curva
				if (nuevo.ObtenerFuncionActiva() == 9) {
					if (evento.mouse.button & 1) {
						Activar();
						x1 = evento.mouse.x;
						y1 = evento.mouse.y;
					}
					if (presionado == true && evento.mouse.button & 2) {
						x2 = evento.mouse.x;
						y2 = evento.mouse.y;
						LineaCurva* forma = new LineaCurva (x1, y1, x2, y2, nuevo.ObtenerColor(), nuevo.ObtenerGruesoLinea());
						Desactivar();
					}
				}
				//termina insertar linea curva
			}
		}
		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			ejecucion = false; // Salir del bucle cuando se presione la "X" de la ventana
		}
		else if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (evento.keyboard.modifiers & ALLEGRO_KEYMOD_CTRL && evento.keyboard.keycode == ALLEGRO_KEY_Y) {
				ejecucion = false; // Salir del bucle cuando se presione "Ctrl + Y"
			}
		}
		al_flip_display();
	}
	return 0;
}
