// Nombre del alumno Víctor Chamizo Rodríguez
// Usuario del Juez TAIS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

struct tTarea {

	int comienzo;
	int fin;
	int periocidad = 0;

	bool operator < (tTarea const& t) const { return comienzo < t.comienzo; }
};

bool encontrarConflicto (PriorityQueue<tTarea> & t, int min) {

	tTarea tarea = t.top();
	t.pop();
	
	while (t.size() > 0 && tarea.comienzo < min) {

		tTarea tareaSiguiente = t.top();

		// Si los tiempo de comienzo y final de tareas consecutivas se solapan --> hay conflicto
		if (tareaSiguiente.comienzo < min && tarea.fin > tareaSiguiente.comienzo) return true;
		else {

			if (tarea.periocidad > 0) { // Si la tarea es periodica, modificamos sus tiempos de cominezo y fin

				tarea.comienzo += tarea.periocidad;
				tarea.fin += tarea.periocidad;

				t.push(tarea);
			}
		}

		tarea = t.top();
		t.pop();
	}

	return false;
}

bool resuelveCaso() {

	int nUnicas;
	std::cin >> nUnicas;

	if (!std::cin) return false;

	int nPeriodicas, minutos;
	std::cin >> nPeriodicas >> minutos;

	tTarea tarea;
	PriorityQueue<tTarea> tareas;

	if (nUnicas != 0) {

		//leemos tareas unicas
		for (int i = 0; i < nUnicas; ++i) {

			std::cin >> tarea.comienzo >> tarea.fin;
			tareas.push(tarea);
		}
	}

	if (nPeriodicas != 0) {

		//leemos tareas periodicas
		for (int i = 0; i < nPeriodicas; ++i) {

			std::cin >> tarea.comienzo >> tarea.fin >> tarea.periocidad;
			tareas.push(tarea);
		}
	}

	if (encontrarConflicto(tareas, minutos)) std::cout << "SI";
	else std::cout << "NO";

	std::cout << std::endl;

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}