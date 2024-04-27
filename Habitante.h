#pragma once
#include "Personaje.h"

class Habitante : public Personaje {
private:
	bool enfermo;
public:
	Habitante() {
		x = rand() % 900;
		y = rand() %300+200;
		enfermo = true;
	}

	~Habitante(){}

	void Mostrar(Graphics^ g,Bitmap^ sano,Bitmap^ enf) {
		Bitmap^ actual = (enfermo?enf:sano);
		
		ancho = actual->Width;
		alto = actual->Height;

		Rectangle corte = Rectangle(0,0, ancho, alto);

		g->DrawImage(actual, Area(), corte, GraphicsUnit::Pixel);
	}

	bool estaEnfermo() { return enfermo; }

	void Sanar() { enfermo = false; }
};

class GrupoHabitantes {
private:
	vector<Habitante*> habitantes;
	vector<int> sanos;
public:
	GrupoHabitantes(int habit) {
		int num = habit;

		for (int i = 0; i < num; i++) {
			Habitante* hab = new Habitante();

			habitantes.push_back(hab);
		}
	}

	~GrupoHabitantes() {}

	void Agregar(Habitante* a) { habitantes.push_back(a); }

	void AgregarSano(int habit) { sanos.push_back(habit); }

	void Eliminar(int indice) { habitantes.erase(habitantes.begin() + indice); }

	void Limpiar() { habitantes.clear(); }

	Habitante* GetHabitante(int indice) { return habitantes[indice]; }

	vector<int> GetSanos() { return sanos; }

	vector<Habitante*> GetGrupo() { return habitantes; }

	int Tamanio() { return habitantes.size(); }

	void Mostrar(Graphics^ g, Bitmap^ sano, Bitmap^ enfermo) {
		for (int i = 0; i < habitantes.size(); i++) {
			habitantes[i]->Mostrar(g,sano,enfermo);
		}
	}

};