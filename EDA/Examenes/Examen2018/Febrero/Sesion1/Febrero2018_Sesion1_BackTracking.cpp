// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

bool esValida (int k, int i, tMatriz const & puntuaciones, int puntuacionMin, 
			   int presupuesto, int  presupuestoAux) {

	if (presupuesto < presupuestoAux) return false;
	else if (puntuacionMin > puntuaciones[k][i]) return false;

	return true;
}

bool esSolucion(int nPapeles, int k) { return k == nPapeles - 1; }

void resolver(int nPapeles, int nActores, int presupuesto, int puntuacionMin, 
	std::vector<int> const & sueldoActores, std::vector<bool> & actorOcupado, tMatriz const & puntuaciones, int k,
	int & puntuacionTotal, int puntuacionAux, int & presupuestoTotal, int presupuestoAux, std::vector<int> & actorPapel, std::vector<int> & actorPapelAux) {

	/*
		k --> papeles
		i --> actores
	*/
	for (int i = 0; i < nActores; ++i) {

		if (!actorOcupado[i]) {

			actorPapelAux[k] = i;
			puntuacionAux += puntuaciones[k][i];
			presupuestoAux += sueldoActores[i];
			actorOcupado[i] = true;

			if (esValida(k, i, puntuaciones, puntuacionMin, presupuesto, presupuestoAux)) {

				if (!esSolucion(nPapeles, k)) resolver(nPapeles, nActores, presupuesto, puntuacionMin, sueldoActores, actorOcupado, puntuaciones, k + 1, puntuacionTotal, puntuacionAux, presupuestoTotal, presupuestoAux, actorPapel, actorPapelAux);
				else if (puntuacionAux > puntuacionTotal) {

					puntuacionTotal = puntuacionAux;
					presupuestoTotal = presupuestoAux;
					actorPapel = actorPapelAux;
				}
			}

			puntuacionAux -= puntuaciones[k][i];
			presupuestoAux -= sueldoActores[i];
			actorOcupado[i] = false;
		}
		
	}
}

bool resuelveCaso() {

	int nPapeles = 0;

	std::cin >> nPapeles;

	if (nPapeles == 0) return false;

	int nActores, presupuesto, puntuacionMin;

	std::cin >> nActores >> presupuesto >> puntuacionMin;

	std::vector<int> sueldoActores(nActores);

	for (int & sA : sueldoActores) std::cin >> sA;

	tMatriz puntuaciones(nPapeles, std::vector<int>(nActores));

	for (int i = 0; i < nPapeles; ++i)
		for (int j = 0; j < nActores; ++j)
			std::cin >> puntuaciones[i][j];

	int puntuacionMaxima = 0, presupuestoTotal = 0;
	std::vector<bool> actorOcupado(nActores, false);
	std::vector<int> actorPapel(nPapeles);
	std::vector<int> actorPapelAux(nPapeles);

	resolver(nPapeles, nActores, presupuesto, puntuacionMin, sueldoActores, actorOcupado, puntuaciones, 0,
		puntuacionMaxima, 0, presupuestoTotal, 0, actorPapel, actorPapelAux);

	std::cout << puntuacionMaxima << " " << presupuestoTotal << std::endl;
	for (int j = 0; j < nPapeles; ++j)
		std::cout << j << " " << actorPapel[j] << std::endl;

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