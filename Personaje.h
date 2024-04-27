#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

enum Direccion { Abajo, Izquierda, Derecha, Arriba, Ninguno };

using namespace std;
using namespace System;
using namespace System::Drawing;

class Personaje
{
protected:
	float x, y;
	float dx, dy;
	float ancho, alto;
	int fila, columna;
	Direccion direc;

public:
	void SetD(float _dx, float _dy) { dx = _dx, dy = _dy; }
	void SetPos(float _x, float _y) { x = _x, y = _y; }

	float GetX() { return x; }
	float GetY() { return y; }

	float GetAncho() { return ancho; }
	float GetAlto() { return alto; }

	virtual Rectangle Area() { return Rectangle(x, y, ancho, alto ); }

	virtual void Mover() {}

	virtual void Mostrar(Graphics^ g, Bitmap^ img) {
		ancho = img->Width / 4;
		alto = img->Height / 4;

		Rectangle corte = Rectangle(columna * ancho, direc * alto, ancho, alto);

		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
	}
};