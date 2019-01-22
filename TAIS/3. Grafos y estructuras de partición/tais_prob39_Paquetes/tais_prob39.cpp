// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>

#include "GrafoDirigidoValorado.h"
#include "Reparto.h"

bool resuelveCaso() {

	int N;
	std::cin >> N;

	if (!std::cin) return false;

	int C;
	std::cin >> C;

	GrafoDirigidoValorado<int> grafo(N);

	int v, w, valor, i;

	for (i = 0; i < C; ++i) {

		std::cin >> v >> w >> valor;
		grafo.ponArista({ v - 1, w - 1, valor });
	}

	int O, P;
	std::cin >> O >> P;

	std::vector<int> casas(P);
	int casa;

	for (i = 0; i < P; ++i) {

		std::cin >> casa;
		casas[i] = casa - 1;
	}

	Reparto reparto(grafo, O - 1); // Realizamos el calculo de distancias desde la oficina a las casas.

	bool posible = true;
	int esfuerzoTotal = 0, esfuerzoParcial;
	i = 0;

	while (i < casas.size() && posible) {

		esfuerzoParcial = reparto.getEsfuerzo(casas[i]);

		if (esfuerzoParcial == INT_MAX) posible = false;
		else esfuerzoTotal += esfuerzoParcial;

		++i;
	}

	if (posible) {

		GrafoDirigidoValorado<int> grafoInverso = grafo.inverso();
		Reparto repartoIverso(grafoInverso, O - 1); // Realizamos el calculo desde cada una de las casas a la oficina;

		i = 0;

		while (i < casas.size() && posible) {

			esfuerzoParcial = repartoIverso.getEsfuerzo(casas[i]);

			if (esfuerzoParcial == INT_MAX) posible = false;
			else esfuerzoTotal += esfuerzoParcial;

			++i;
		}

		if (posible) std::cout << esfuerzoTotal;
		else std::cout << "Imposible";
	}
	else std::cout << "Imposible";

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