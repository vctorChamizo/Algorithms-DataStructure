// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


void contarRacha(std::vector<int> const & v, int & maxP, int & nV, int & nPJ) {

	int partidosGanados = 0;
	int posicionUltimaRacha = 0;

	for (int i = 0; i < v.size(); ++i) {

		if (v[i] > 0) partidosGanados++;
		else partidosGanados = 0;

		if (maxP == partidosGanados) {
			nV++;
			posicionUltimaRacha = i;
		}

		if (maxP < partidosGanados) {
			maxP = partidosGanados;
			posicionUltimaRacha = i;
			nV = 1;
		}
	}

	if (maxP == 0) {
		nPJ = v.size();
		nV = 0;
	}
	else nPJ = (v.size() - 1) - posicionUltimaRacha;
}

bool resuelveCaso() {

	int nPartidos;

	std::cin >> nPartidos;

	if (!std::cin) return false;

	std::vector<int> partidos(nPartidos);

	for (int & n : partidos) std::cin >> n;

	int nPartidosJugados;
	int maxPartidos = 0;
	int nVeces = 0;

	contarRacha(partidos, maxPartidos, nVeces, nPartidosJugados);

	std::cout << maxPartidos << " " << nVeces << " " << nPartidosJugados << std::endl;

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