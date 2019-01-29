// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez:

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

int partidosJugados(std::vector<std::string> const & v, int r, int ini, int fin, int & nP, int & nR, bool & p) {

	if (ini + 1== fin) {

		// Si ningún jugador se ha presentado.
		if (v[ini] == "NP" && v[fin] == "NP") p = false;

		// Si los dos jugaores se han presentado.
		else if (v[ini] != "NP" && v[fin] != "NP") nP++;
	}
	else {

		bool pIzq = true, pDch = true;

		int m = (ini + fin) / 2;
		partidosJugados(v, r, ini, m, nP, nR, pIzq);
		partidosJugados(v, r, m + 1, fin, nP, nR, pDch);

		if (nR <= r) {

			nR++;
			if (!pIzq && !pDch) p = false;
		}
		else return nP;
	}
}

bool resuelveCaso() {

	int nElem;

	std::cin >> nElem;

	if (!std::cin) return false;

	int ronda;

	std::cin >> ronda;

	std::vector<std::string> jugadores(nElem);

	for (std::string & j : jugadores) std::cin >> j;

	int nPartidos = 0, nRonda = 0;
	bool presentado = true;

	std::cout << partidosJugados(jugadores, ronda, 0, jugadores.size() - 1, nPartidos, nRonda, presentado) << std::endl;

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