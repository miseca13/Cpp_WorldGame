#pragma once
#include "Aliado.h"

class Agente : public Personaje {
private:
	float vel;
public:
	Agente(float width) {
		srand(time(NULL));

		x = width/2, y = -20;

		dx = dy = 0;

		direc = Ninguno;

		vel = rand() % 4 + 2;

		columna = 0;
	}

	~Agente() {}

	void Mover(Aliado* al) {
		if (y > 10) {
			float difx = al->GetX() - this->x;
			float dify = al->GetY() - this->y;

			this->dx = vel * difx / sqrt(dify * dify + difx * difx);
			this->dy = vel * dify / sqrt(dify * dify + difx * difx);
		}

		else {
			dx = 0;
			dy = vel;
		}

		if (abs(dx) >= abs(dy)) {
			if (dx > 0) direc = Derecha;
			else direc = Izquierda;
		}

		else {
			if (dy > 0) direc = Abajo;
			else direc = Arriba;
		}

		x += dx, y += dy;
		columna = (columna + 1) % 4;
	}
};

class GrupoAgentes {
private:
	vector<Agente*> agentes;
public:
	GrupoAgentes() {}

	~GrupoAgentes(){}

	void Agregar(Agente* a) { agentes.push_back(a); }

	void Eliminar(int indice) { agentes.erase(agentes.begin() + indice); }

	void Limpiar() { agentes.clear(); }

	Agente* GetAgente(int indice) { return agentes[indice]; }

	vector<Agente*> GetGrupo() { return agentes; }

	int Tamanio() { return agentes.size(); }

	void Mostrar(Graphics^ g, Bitmap^ b, GrupoAliados* grupoal) {
		for (int i = 0; i < agentes.size(); i++) {
			agentes[i]->Mostrar(g, b);
			agentes[i]->Mover(grupoal->GetAliado(i));
		}
	}
};
