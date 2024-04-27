#pragma once
#include "Personaje.h"
#include "Habitante.h"

class Aliado : public Personaje {
private:
	const float TIEMPOMAX = 2000;
	int habit;
	float vel;
	float tiempo;
	float inicial;
public:
	Aliado(float _x, float _y,GrupoHabitantes* gh) {
		srand(time(NULL));

		x = _x, y = _y;
		
		if (gh->Tamanio() != 0) {
			vel = 8;
			
			do { habit = rand() % gh->Tamanio(); } while (habitSanado(habit, gh));

			Habitante* hab=gh->GetHabitante(habit);

			float difx = hab->GetX() - this->x;
			float dify = hab->GetY() - this->y;

			this->dx = vel * difx / sqrt(dify * dify + difx * difx);
			this->dy = vel * dify / sqrt(dify * dify + difx * difx);
		}
		
		if (abs(dx) >= abs(dy)) {
			if (dx > 0) direc = Derecha;
			else direc = Izquierda;
		}

		else {
			if (dy > 0) direc = Abajo;
			else direc = Arriba;
		}

		columna = 0;

		tiempo = inicial = 0;
	}

	~Aliado() {}

	void Mostrar(Graphics^ g, Bitmap^ img) {
		Personaje::Mostrar(g, img);

		SolidBrush^ pincel = gcnew SolidBrush(Color::DarkGreen);

		Rectangle rect(x, y + alto, ancho * (tiempo-inicial) / TIEMPOMAX, 10);

		g->FillRectangle(pincel, rect);
	}

	bool habitSanado(int habit,GrupoHabitantes* gh) {
		for (int i = 0; i < gh->GetSanos().size(); i++) {
			if (gh->GetSanos()[i] == habit) return true;
		}

		return false;
	}

	void Mover(GrupoHabitantes* gh) {
		float origenx = x + ancho / 2;
		float origeny = y + alto / 2;

		if (!gh->GetHabitante(habit)->Area().Contains(origenx, origeny)) {
			x += dx, y += dy;
			columna = (columna + 1) % 4;
		}

		else {
			columna = 1;
			
			if (inicial==0) inicial = clock();

			else tiempo = clock();
		}
	}

	bool HabitanteCurado() {
		return (tiempo - inicial) >= TIEMPOMAX;
	}

	int getHabitante() { return habit; }
};

class GrupoAliados {
private:
	vector<Aliado*> aliados;
public:
	GrupoAliados() {}

	~GrupoAliados() {}

	void Agregar(Aliado* a) { aliados.push_back(a); }

	void Eliminar(int indice) { aliados.erase(aliados.begin() + indice); }

	void Limpiar() { aliados.clear(); }

	Aliado* GetAliado(int indice) { return aliados[indice]; }

	vector<Aliado*> GetGrupo() { return aliados; }

	int Tamanio() { return aliados.size(); }

	void Mostrar(Graphics^ g, Bitmap^ b,GrupoHabitantes* grupohab) {
		for (int i = 0; i < aliados.size(); i++) {
			aliados[i]->Mostrar(g, b);
			aliados[i]->Mover(grupohab);
		}
	}
};