// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez:


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#include "PriorityQueue.h"


struct tActividad {

	int comienzo;
	int fin;

	bool operator < (tActividad const & a) const { return comienzo < a.comienzo || (comienzo == a.comienzo && fin < a.fin); }
};

int minimoCompaneros(std::vector<tActividad> const & a, PriorityQueue<int> & fC) {

	int nCompaneros = 0;
	fC.push(a[0].fin);

	for (auto i = 1; i < a.size(); ++i) {

		int fin_aux = fC.top();

		if (a[i].comienzo < fin_aux) { //Si el que antes acaba su actividad no llega al inicio de la siguiente --> +1 companero

			nCompaneros++;
			fC.push(a[i].fin);
		}
		else { //Si el que antes acaba, llega al incio de la siguiente actvidad --> actualizamos su final

			fin_aux = a[i].fin;
			fC.pop();
			fC.push(fin_aux);
		}
	}

	return nCompaneros;
}

bool resuelveCaso() {

	int nActividades;
	std::cin >> nActividades;

	if (nActividades == 0) return false;

	std::vector<tActividad> actividades(nActividades);

	for (auto i = 0; i < nActividades; ++i)
		std::cin >> actividades[i].comienzo >> actividades[i].fin;

	std::sort(actividades.begin(), actividades.end());

	PriorityQueue<int> finalCompanero;

	std::cout << minimoCompaneros(actividades, finalCompanero) << std::endl;

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