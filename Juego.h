#pragma once

#include "Agente.h"
#include "Aliado.h"
#include "Lider.h"
#include "Habitante.h"

using namespace std;
using namespace System;

class Juego {
private:
	float inicio;
	float tiempo;
	int puntos;
	int vidas;
	Lider* lider;
	GrupoAgentes* agentes;
	GrupoAliados* aliados;
	GrupoHabitantes* habitantes;

public:
	Juego(int _tf,int hab) {
		inicio = clock();
		tiempo = _tf+1;
		puntos = 0;
		vidas = 5;
		lider = new Lider();
		agentes = new GrupoAgentes();
		aliados = new GrupoAliados();
		habitantes = new GrupoHabitantes(hab);
	}

	~Juego() {}

	void Mostrar(Graphics^ g,Bitmap^ lid,Bitmap^ ali, Bitmap^ age, Bitmap^ sano, Bitmap^ enf) {
		habitantes->Mostrar(g, sano, enf);
		aliados->Mostrar(g, ali, habitantes);
		agentes->Mostrar(g, age, aliados);
		lider->Mostrar(g, lid);

		tiempo -= (clock()-inicio)/1000;
		inicio = clock();

		g->DrawString("Vidas: " + vidas + "  Puntos: " + puntos + 
			"  Tiempo: "+int(int(tiempo)), gcnew Font("Arial", 19.5,FontStyle::Bold), Brushes::DeepSkyBlue, 5, 5);
		Colapso();
	}

	void MoverLider(Direccion dir,float width,float height) {
		lider->Mover(dir,width,height);
	} 

	void Colapso() {
		for (int i = 0; i < aliados->Tamanio(); i++) {
			float origenx1 = aliados->GetAliado(i)->GetX() + aliados->GetAliado(i)->GetAncho() / 2;
			float origeny1 = aliados->GetAliado(i)->GetY() + aliados->GetAliado(i)->GetAlto() / 2;

			if (agentes->GetAgente(i)->Area().Contains(origenx1, origeny1)) {
				aliados->Eliminar(i);
				agentes->Eliminar(i);
				vidas--;
				i--;
			}

			else if (aliados->GetAliado(i)->HabitanteCurado()) {
				int habactual = aliados->GetAliado(i)->getHabitante();
				habitantes->GetHabitante(habactual)->Sanar();
				habitantes->AgregarSano(habactual);
				for (int j = 0; j < aliados->Tamanio(); j++) {
					if (habactual == aliados->GetAliado(j)->getHabitante()) {
						aliados->Eliminar(j);
						agentes->Eliminar(j);
						j--;
					}
				}
				puntos += 10;
			}
		}
	}

	void LanzarAliado(float width) {
		if (lider->Disparar()) {
			Aliado* al = new Aliado(lider->GetX(), lider->GetY(), habitantes);
			Agente* ag = new Agente(width);

			aliados->Agregar(al);
			agentes->Agregar(ag);
			lider->ReiniciarTiempo();
		}
	}

	bool Ganar() {
		return habitantes->GetSanos().size() == habitantes->GetGrupo().size();
	}

	bool Perder() {
		if (vidas == 0 || tiempo <= 0) return true;

		else return false;
	}
};