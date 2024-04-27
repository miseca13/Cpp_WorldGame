#pragma once
#include "Personaje.h"

class Lider : public Personaje {
private:
	const float TIEMPOMAX = 3000;
	float tiempo;
	float inicial=0;
public:
	Lider() {
		x = 50, y = 300;
		dx = dy = 0;
		direc = Abajo;
		columna = 0;
		tiempo = 0;
	}

	~Lider() {}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		Personaje::Mostrar(g, img);
		tiempo = clock();

		SolidBrush^ pincel = gcnew SolidBrush(Color::DarkGreen);

		Rectangle rect(x, y + alto, ancho*(tiempo-inicial<=TIEMPOMAX?tiempo-inicial:TIEMPOMAX)/TIEMPOMAX, 10);

		g->FillRectangle(pincel,rect);
	}

	void Mover(Direccion d,float width,float height) {
		if (d == Abajo) {
			if (y+alto<height-35) dy = 3;
			else dy = 0;
			direc = d;
			columna = (columna + 1) % 4;
		}

		else if (d == Izquierda) {
			if (x > 2) dx = -3;
			else dx = 0;
			direc = d;
			columna = (columna + 1) % 4;
		}

		else if (d == Arriba) {
			if (y > 40) dy = -3;
			else dy = 0;
			direc = d;
			columna = (columna + 1) % 4;
		}

		else if (d == Derecha) {
			if (x+ancho <width-10) dx = 3;
			else dx = 0;
			direc = d;
			columna = (columna + 1) % 4;
		}

		else {
			dx = 0, dy = 0;
		}

		x += dx, y += dy;
	}

	bool Disparar() {
		return (tiempo - inicial) >= TIEMPOMAX;
	}

	void ReiniciarTiempo() { inicial = clock(), tiempo = 0; }
};